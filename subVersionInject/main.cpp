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
#include <psapi.h>
#include <string>
#include <fstream>
#include <ctime>


#define	TEXTCOL_DEFAULT		15
#define TEXTCOL_GREEN		10
#define TEXTCOL_RED			12
#define get_array_size(array)	(sizeof(array) / sizeof(array[0]))

typedef LPTHREAD_START_ROUTINE	LPTHREAD;
typedef	HMODULE					(__stdcall *LOAD_LIB)(LPCSTR);
typedef FARPROC					(__stdcall *PROC_ADDR)(HINSTANCE, LPCSTR);

typedef struct remoteInject
{
	char		szPath[MAX_PATH];
	LOAD_LIB	fpLoadLibray;
} REMOTE_INJECT;

BOOL	inject(DWORD, char*);
void	random_str(char* str, uint32_t len);
void	write_to_config(std::string str);
bool	does_file_exist(const char* fileName);
void	printf_color(char* format, BYTE color, ...);

constexpr char	g_szConfig[]		= "subVersionInject.cfg";
constexpr char	g_szTitle[]			= "Grand Theft Auto V";

int main()
{
	constexpr char	szDefaultName[]	= "subVersion.dll";
	constexpr char	szWindowClass[]	= "grcWindow";
	DWORD			procId			= 0;
	HWND			hWndTarget		= 0;
	std::string		szDllName		= szDefaultName;

	if(!does_file_exist(g_szConfig))
		write_to_config(szDllName);

	std::ifstream file;
	file.open(g_szConfig, std::ios::in);
	if(!file.is_open())
	{
		printf_color("Failed to read config file.", TEXTCOL_RED);
		goto LABEL_CLOSE;
	}
	std::getline(file, szDllName, '\n');
	file.close();

	if(!does_file_exist(&szDllName[0]))
	{
		printf_color("%s not found!\nRename the dll to '%s' and delete the injector config.\n", TEXTCOL_RED, &szDllName[0], szDefaultName);
		goto LABEL_CLOSE;
	}

	printf_color("Looking for %s.\n", TEXTCOL_DEFAULT, g_szTitle);

	hWndTarget	= FindWindowA(szWindowClass, nullptr);
	if(!hWndTarget || !GetWindowThreadProcessId(hWndTarget, &procId) || !procId)
	{
		printf_color("Failed to find %s.\nMake sure %s is running before injecting.\n", TEXTCOL_RED, g_szTitle, g_szTitle);
		goto LABEL_CLOSE;
	}

	printf_color("Found %s\nProcess ID: %u.\n", TEXTCOL_GREEN, g_szTitle, procId);

	if(!inject(procId, &szDllName[0]))
	{
		printf_color("Failed to inject dll.\n", TEXTCOL_RED);
		goto LABEL_CLOSE;
	}

	Sleep(0x400);
	SetForegroundWindow(hWndTarget);

LABEL_CLOSE:

	printf_color("Closing injector in 10 seconds.\n", TEXTCOL_DEFAULT);
	Sleep(0x2800);

	return S_OK;
}

void	printf_color(char* format, BYTE color, ...)
{
	static HANDLE	hConsole	= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	va_list	args;
	va_start(args, color);
	vprintf(format, args);
	va_end(args);

}

bool	does_file_exist(const char* fileName)
{
	std::ifstream	file(fileName);
	bool	r	= false;
	r			= file.good();
	file.close();
	return r;
}


void	write_to_config(std::string str)
{
	std::ofstream file(g_szConfig, std::ios::out | std::ios::trunc);
	file << str << "\n";
	file.close();
}

void random_str(char* str, uint32_t len)
{
	constexpr char	charset[]	=
	{
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
	};
	static bool seed	= false;
	if(!seed)
	{
		srand((uint32_t) time(0));
		seed = true;
	}

	for(uint32_t i = 0; i < len; ++str, ++i)
		*str	= charset[rand() % (get_array_size(charset) - 1)];
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

uint32_t __stdcall load_dll(void* context)
{
	REMOTE_INJECT*	injectParams	= (REMOTE_INJECT*) context;
	injectParams->fpLoadLibray(injectParams->szPath);
	return 1;
}

uint32_t __stdcall load_dll_end()	//used to get end of load_dll
{
	return 1;
}

BOOL inject(DWORD dwProcID, char* file)
{
	HANDLE			hProc				= nullptr,
					hThread				= nullptr;
	LPVOID			pInjBase			= nullptr,
					pInjLoader			= nullptr;
	DWORD			dwThreadID			= 0,
					dwProtOut			= 0;
	char			szPath[MAX_PATH]	= { 0 };
	char			szRandName[0x20]	= { 0 };
	BOOL			ret					= FALSE;
	REMOTE_INJECT	injectParams		= {};
	uint64_t		loadDllSize			= (uint64_t) load_dll_end - (uint64_t) load_dll;

	hProc = OpenProcess(PROCESS_ALL_ACCESS, false, dwProcID);
	if(!hProc)
	{
		printf_color("Failed to open target process\n", TEXTCOL_RED);
		goto LABEL_CLEANUP;
	}

	if(get_module_address(hProc, file))
	{
		printf_color("%s is already injected.\n", TEXTCOL_RED, file);
		goto LABEL_CLEANUP;
	}

	//generate random name
	random_str(szRandName, 0x1A);
	strcat_s(szRandName, ".dll");
	rename(file, szRandName);
	write_to_config(szRandName);
	printf_color("Generated random name %s.\n", TEXTCOL_DEFAULT, szRandName);

	//find path
	GetModuleFileNameA(nullptr, szPath, sizeof(szPath));
	substr(szPath, 0, find_last_of(szPath, '\\'));
	strcat_s(szPath, szRandName);
	printf_color("Injecting %s.\n", TEXTCOL_DEFAULT, szPath);

	//set injection params
	injectParams.fpLoadLibray		= LoadLibraryA;
	strcpy_s(injectParams.szPath, szPath);

	//allocate memory for function and params
	pInjBase	= VirtualAllocEx(hProc, 0, loadDllSize + sizeof(injectParams), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	if(!pInjBase)
	{
		printf_color("Failed to allocate memory in %s.\n", TEXTCOL_RED, g_szTitle);
		goto LABEL_CLEANUP;
	}
	pInjLoader	= (REMOTE_INJECT*) pInjBase + 1;

	//write loader params
	if(!WriteProcessMemory(hProc, pInjBase, &injectParams, sizeof(injectParams), nullptr))
	{
		printf_color("Failed to write loader params to %s\n", TEXTCOL_RED, g_szTitle);
		goto LABEL_CLEANUP;
	}

	//write loader
	if(!WriteProcessMemory(hProc, pInjLoader, load_dll, loadDllSize, nullptr))
	{
		printf_color("Failed to write loader to %s.\n", TEXTCOL_RED, g_szTitle);
		goto LABEL_CLEANUP;
	}

	//set execute permission
	if(!VirtualProtectEx(hProc, pInjLoader, loadDllSize, PAGE_EXECUTE_READWRITE, &dwProtOut))
	{
		printf_color("Failed to set permissions on loader in %s\n", TEXTCOL_RED, g_szTitle);
		goto LABEL_CLEANUP;
	}

	//execute loader
	hThread = CreateRemoteThread(hProc, nullptr, 0, (LPTHREAD_START_ROUTINE) pInjLoader, pInjBase, 0, &dwThreadID);
	if(!hThread)
	{
		printf_color("Failed to create a thread in %s\n", TEXTCOL_RED, g_szTitle);
		goto LABEL_CLEANUP;
	}

	ret	= TRUE;
	printf_color("Injecting %s successful.\n", TEXTCOL_GREEN, szRandName);

	//clean up
LABEL_CLEANUP:

	if(hThread != nullptr)
	{
		WaitForSingleObject(hThread, INFINITE);
		CloseHandle(hThread);
	}
	if(hProc != nullptr)
	{
		if(pInjBase != nullptr)
			VirtualFreeEx(hProc, pInjBase, 0, MEM_RELEASE);
		CloseHandle(hProc);
	}
	
	return ret;
}
