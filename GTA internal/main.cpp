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

#include "stdafx.h"

//handles
HMODULE		g_hModule;
HANDLE		g_hThreadMain,
			g_hThreadRender;

bool		g_bKillProcess;

/*LRESULT	__stdcall	WindowProc(	HWND	hWnd,
								UINT	message,
								WPARAM	wParam,
								LPARAM	lParam);*/
DWORD __stdcall		mainThread	(LPVOID);
//DWORD __stdcall		threadRender(LPVOID lpParam);

int __stdcall DllMain
(
	HMODULE	hModule,
	DWORD	fdwReason,
	LPVOID	lpReserved
)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		g_hModule = hModule;
		//AllocConsole();
		//freopen("CONOUT$", "w", stdout);
		g_hThreadMain = CreateThread
		(
			NULL,
			0,
			mainThread,
			NULL,
			0,
			nullptr
		);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return true;
}

DWORD __stdcall mainThread(LPVOID lpParam)
{
	//init logger
	if(!CLog::initialize("subVersion", "subVersion.log"))
		return 0;

	//init menu
	if(!CMenu::initialze("subVersion", "subVersion.ini"))
		return 0;
	feature::populate();	//add the features

	//init renderer
	CRender::initialze(g_hModule, "subVersion 2.0.6 | by sub1to");

	//init hooking
	CHooking::init();

	HWND	hWndTarget		= FindWindowA("grcWindow", nullptr);
	while(!g_bKillProcess)
	{
		//exit
		if(CMenu::checkKeyState(CMenu::m_keyIndex[KEY_EXIT]) || !CLog::m_fatal.empty())
		{
			killProcess();
			break;
		}
		HWND	hFgWnd	= GetForegroundWindow();
		if(hFgWnd != hWndTarget)
			CMenu::m_bFgWnd	= false;
		else if(hWndTarget == hFgWnd)
			CMenu::m_bFgWnd	= true;
		Sleep(0x60);
		
	}
	return S_OK;
}

void killProcess()
{
	g_bKillProcess = true;

	CLog::msg("Cleanup started");

	CMenu::m_iniParser.write();

	for(int i = 0; i < CMenu::getFeatureCount(); i++)
	{
		CMenu::getFeature(i)->m_bOn		= false;
		CMenu::getFeature(i)->m_bSet	= false;
	}

	Sleep(0xFF);

	CHooking::cleanup();
	CMenu::uninitialze();

	CLog::msg("Cleanup finished");

	FreeLibraryAndExitThread(g_hModule, 0);
}

void killProcess(std::string msg)
{
	CLog::fatal(&msg[0]);
	killProcess();
}