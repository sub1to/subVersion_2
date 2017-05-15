/*
	Copyright 2016-2017 sub1to

	This file is part of subVersion 2 GTA:O Hack.

    subVersion 2 GTA:O Hack is free software: you can redistribute
	it and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation, either version 3 of the
	License, or (at your option) any later version.

    subVersion 2 GTA:O Hack is distributed in the hope that it
	will be useful, but WITHOUT ANY WARRANTY; without even the implied
	warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
	the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with subVersion 2 GTA:O Hack.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <psapi.h>
#include <TlHelp32.h>
#include <string>
#include <fstream>

#define get_array_size(array)	(sizeof(array) / sizeof(array[0]))
typedef LPTHREAD_START_ROUTINE LPTHREAD;

BOOL	inject(DWORD, const char*);

int main()
{
	constexpr char	szWindowClass[]	= "grcWindow";
	constexpr char	szTitle[]		= "Grand Theft Auto V";
	constexpr char	szConfig[]		= "subVersionInject.cfg";
	DWORD			procId			= 0;
	HWND			hWndTarget		= 0;
	std::string		szDllName		= "subVersion.dll";

	std::ifstream file;
	file.open(szConfig, std::ios::in);
	if(!file.is_open())
	{
		std::ofstream file;
		file.open(szConfig, std::ios::out | std::ios::trunc);
		file << szDllName << "\n";
	}
	else
		std::getline(file, szDllName, '\n');

	printf("Looking for %s.\n", szTitle);

	hWndTarget	= FindWindowA(szWindowClass, nullptr);
	if(!hWndTarget || !GetWindowThreadProcessId(hWndTarget, &procId) || !procId)
	{
		printf("Failed to find %s.\nMake sure %s is running before injecting.\n", szTitle, szTitle);
		goto LABEL_CLOSE;
	}

	printf("Found %s\nProcess ID: %u.\n", szTitle, procId);

	if(!inject(procId, &szDllName[0]))
	{
		printf("Failed to inject %s.\n", &szDllName[0]);
		goto LABEL_CLOSE;
	}

	Sleep(0x400);
	SetForegroundWindow(hWndTarget);

LABEL_CLOSE:

	printf("Closing injector in 5 seconds.\n");
	Sleep(0x1400);

	return S_OK;
}

HMODULE get_module_address(HANDLE hProc, const char* moduleName)
{
	HMODULE	hModBuf[0xFF];
	DWORD	bN;
	UINT	i;
	HMODULE	r	= nullptr;
	
	if(!K32EnumProcessModulesEx(hProc, hModBuf, sizeof(hModBuf), &bN, LIST_MODULES_64BIT))
		return r;

	for(i = 0; i < (bN / sizeof(HMODULE)); i++)
	{
		TCHAR szPath[MAX_PATH];
		if(!K32GetModuleFileNameExA(hProc, hModBuf[i], szPath, sizeof(szPath) / sizeof(TCHAR)))
			continue;
		std::string szName = szPath;
		if(szName.find(moduleName) != std::string::npos)
		{
			r = hModBuf[i];
			break;
		}
	}
	return r;
}

uint32_t find_last_of(char* szBuffer, char find)
{
	uint32_t	r = 0;
	for(uint32_t i = 0; *szBuffer != '\0'; ++i, ++szBuffer)
		if(*szBuffer == find)
			r	= i;
	return r;
}

char* substr(char* szBuffer, uint32_t start, uint32_t length)
{
	uint32_t	end		= start + length + 1;
	uint32_t	size	= 1;
	char*		r		= szBuffer;
	for(; *szBuffer != '\0'; ++size, ++szBuffer)
		continue;
	if(size >= end)
	{
		r[end]	= '\0';
		r		+= start;
	}
	return r;
}

BOOL inject(DWORD dwProcID, const char* file)
{
	constexpr char	kernel32[]		= "KERNEL32";
	constexpr char	loadlib[]		= "LoadLibraryA";
	HANDLE			hProc			= 0;

	hProc = OpenProcess(PROCESS_ALL_ACCESS, false, dwProcID);
	if(!hProc)
		return FALSE;

	if(get_module_address(hProc, file))
	{
		printf("Already injected.\n");
		return FALSE;
	}

	LPVOID			param				= nullptr;
	HINSTANCE		hDll				= LoadLibraryA(kernel32);
	LPTHREAD		threadStart			= (LPTHREAD) GetProcAddress(hDll, loadlib);
	HANDLE			hThread				= nullptr;
	DWORD			threadID			= 0;
	char			path[MAX_PATH];

	GetModuleFileNameA(nullptr, path, sizeof(path));
	substr(path, 0, find_last_of(path, '\\'));
	strcat_s(path, file);
	printf("Injecting %s.\n", path);

	param = VirtualAllocEx(hProc, 0, strlen(path) + 1, MEM_COMMIT, PAGE_READWRITE);
	if(!param)
		return FALSE;
	if(!WriteProcessMemory(hProc, param, path, strlen(path) + 1, nullptr))
		return FALSE;
	hThread = CreateRemoteThread(hProc, nullptr, 0, threadStart, param, 0, &threadID);
	if(!hThread)
		return FALSE;

	Sleep(0x100);
	CloseHandle(hThread);
	VirtualFreeEx(hProc, param, 0, MEM_RELEASE);
	CloseHandle(hProc);
	printf("Injecting %s successful.\n", file);
	return TRUE;
}
