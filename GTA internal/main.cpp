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

const char	g_szVersion[]	= "2.1.0";

//handles
HMODULE		g_hModule;
HANDLE		g_hThreadMain;

DWORD __stdcall		mainThread	(LPVOID);

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
		g_hThreadMain = CreateThread
		(
			nullptr,
			0,
			mainThread,
			nullptr,
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
	char msg[0xFF]	= {};
	sprintf_s(msg, "subVersion %s | by sub1to", g_szVersion);
	CRender::initialze(g_hModule, msg);

	//init hooking
	CHooking::init();

	return S_OK;
}

DWORD __stdcall _killProcess(LPVOID pParam)
{
	CLog::msg("Cleanup started");

	CMenu::m_iniParser.write();

	for(int i = 0; i < CMenu::getFeatureCount(); i++)
	{
		CMenu::getFeature(i)->m_bOn		= false;
		CMenu::getFeature(i)->m_bSet	= false;
	}

	Sleep(0x400);

	CHooking::cleanup();
	CMenu::uninitialze();

	CLog::msg("Cleanup finished\n");

	FreeLibraryAndExitThread(g_hModule, 0);
}

void killProcess()
{
	if(GetThreadId(GetCurrentThread()) == GetThreadId(g_hThreadMain))
		_killProcess(nullptr);

	CreateThread(	nullptr,
					0,
					_killProcess,
					nullptr,
					0,
					nullptr);
}

void killProcess(char* msg)
{
	CLog::fatal(&msg[0]);
	killProcess();
}
