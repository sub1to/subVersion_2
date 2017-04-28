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

LRESULT	__stdcall	WindowProc(	HWND	hWnd,
								UINT	message,
								WPARAM	wParam,
								LPARAM	lParam);
DWORD __stdcall		mainThread	(LPVOID);
DWORD __stdcall		threadRender(LPVOID lpParam);

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

	//init renderer and create thread
	CRender::initialze(g_hModule, "subVersion 2.0.5 | by sub1to");
	g_hThreadRender	= CreateThread(	NULL,
									0,
									threadRender,
									NULL,
									0,
									nullptr);

	//init hooking
	CHooking::init();

	//msg handler loop
	MSG		msg;
	bool	restoreActive = true;
	HWND	hWndTarget		= FindWindowA("grcWindow", "Grand Theft Auto V");
	while(!g_bKillProcess)
	{
		//window message
		while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Check to see if any messages are waiting in the queue
		{
			TranslateMessage(&msg);		//Translate the message and dispatch it to WindowProc()
			DispatchMessage(&msg);
		}

		if(msg.message == WM_QUIT)
			break;

		//exit
		if(CMenu::checkKeyState(CMenu::m_keyIndex[KEY_EXIT]) || !CLog::m_fatal.empty())
		{
			killProcess();
			break;
		}

		HWND	hWnd	= CRender::getHWnd();
		HWND	hFgWnd	= GetForegroundWindow();
	
		//attach render window to gta window
		RECT rectWnd;
		GetWindowRect(hWndTarget, &rectWnd);
		int	x	= rectWnd.left	+ CRender::m_screen.x,
			y	= rectWnd.top	+ CRender::m_screen.y;
		SetWindowPos(hWnd, 0, x, y, CRender::m_screen.w, CRender::m_screen.h, SWP_NOREDRAW | SWP_NOZORDER);

		//remove from topmost if gta is not active
		if(hFgWnd != hWndTarget && hFgWnd != hWnd)
		{
			if(CMenu::isMenuActive())
			{
				CMenu::toggleMenu();
				restoreActive = true;
			}
			CMenu::m_bFgWnd	= false;
		}
		else if(hWnd == hFgWnd)
		{
			ShowWindow(hWndTarget, SW_SHOW);
			SetForegroundWindow(hWndTarget);
		}
		else if(hWndTarget == hFgWnd)
		{
			if(!CMenu::isMenuActive() && restoreActive == true)
				CMenu::toggleMenu();
			restoreActive = false;
			CMenu::m_bFgWnd	= true;
		}
		Sleep(0x60);
	}
	return S_OK;
}

DWORD __stdcall threadRender(LPVOID lpParam)
{
	while(!g_bKillProcess)
	{
		CFeat* feat;

		//set scale
		feat = CMenu::getFeature(FEATURE_I_MENU_SCALE);
		if(feat->m_bOn && (CRender::m_screen.w != LAYOUT_WIDTH * feat->getValue() || CRender::m_screen.h != LAYOUT_HEIGHT * feat->getValue()))
		{
			CRender::m_screen.w	= (int) (LAYOUT_WIDTH * feat->getValue());
			CRender::m_screen.h	= (int) (LAYOUT_HEIGHT * feat->getValue());
		}

		//set padding
		feat = CMenu::getFeature(FEATURE_I_MENU_PADDING_X);
		if(feat->m_bOn && CRender::m_screen.x != (int) feat->getValue())
			CRender::m_screen.x = (int) feat->getValue();
		feat = CMenu::getFeature(FEATURE_I_MENU_PADDING_Y);
		if(feat->m_bOn && CRender::m_screen.y != (int) feat->getValue())
			CRender::m_screen.y = (int) feat->getValue();

		//save settings
		feat = CMenu::getFeature(FEATURE_I_SAVE_INI);
		if(feat->m_bOn && !feat->m_bSet)
		{
			CMenu::m_iniParser.write();
			feat->m_bSet = true;
		}

		//disable parents queue
		if(CMenu::m_disableParent.size() > 0)
		{
			CMenu::getFeature(CMenu::m_disableParent[0])->disableChildren();
			CMenu::m_disableParent.erase(CMenu::m_disableParent.begin());
		}

		//check if parent of active feature is disabled
		while(CMenu::getActiveParent() != -1 && !CMenu::getFeature(CMenu::getActiveParent())->m_bOn)
			CMenu::menuBack();

		CMenu::checkKeys();
		CRender::render();
		Sleep(0x10);
	}
	return 0;
}

void killProcess()
{
	g_bKillProcess = true;

	while(WaitForSingleObject(g_hThreadRender, 0) == WAIT_TIMEOUT)
		Sleep(1); 

	CMenu::m_iniParser.write();

	for(int i = 0; i < CMenu::getFeatureCount(); i++)
	{
		CMenu::getFeature(i)->m_bOn		= false;
		CMenu::getFeature(i)->m_bSet	= false;
	}

	Sleep(0xFF);

	CHooking::cleanup();
	CRender::uninitialze();
	CMenu::uninitialze();

	FreeLibraryAndExitThread(g_hModule, 0);
}

void killProcess(std::string msg)
{
	CLog::fatal(&msg[0]);
	killProcess();
}