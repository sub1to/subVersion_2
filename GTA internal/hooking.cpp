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

/*
	//Init static public members
*/
std::vector<LPVOID>							CHooking::m_hookedNative;
eGameState* 								CHooking::m_gameState;
CBlipList*									CHooking::m_blipList;
NativeRegistration**						CHooking::m_regTable;
CReplayInterface*							CHooking::m_replayIntf;
std::unordered_map<uint64_t,NativeHandler>	CHooking::m_handlerCache;
__int64**									CHooking::m_globalBase;
MemoryPool**								CHooking::m_entityPool;

/*
	//Private function declarations
*/
bool			initHooks();
bool			hookNatives();
void			findPatterns();

/*
	//Hooking public functions
*/
void CHooking::init()
{
	CLog::msg("Initializing");
	CCrossMap::init();
	findPatterns();

	while(*CHooking::m_gameState != GameStatePlaying)
		Sleep(100);

	if (!initHooks())
		killProcess();

	CLog::msg("Ready");
}

void CHooking::onTick()
{
	try
	{
		CHack::refresh();
	}
	catch (const std::exception& e)
	{
		CLog::error((char*) e.what());
	}
	catch (...)
	{
		CLog::error("Unknown exception");
	}
}

void CHooking::cleanup()
{
	CLog::msg("Unloading");
	for(int i = 0; i < m_hookedNative.size(); i++)
		if(MH_DisableHook(m_hookedNative[i]) != MH_OK && MH_RemoveHook(m_hookedNative[i]) != MH_OK)
			CLog::msg("Failed to unhook");
	MH_Uninitialize();
}

NativeHandler CHooking::getNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];
	if(handler == nullptr)
	{
		uint64_t newHash = CCrossMap::get(origHash);
		if(newHash == 0)
			return nullptr;

		NativeRegistration*	table	= CHooking::m_regTable[newHash & 0xFF];

		for(; table; table = table->nextRegistration)
			for (uint32_t i = 0; i < table->numEntries; i++)
				if (newHash == table->hashes[i])
				{
					handler = table->handlers[i];
					break;
				}


		m_handlerCache[origHash] = handler;
	}
	return handler;
}

__int64* CHooking::getGlobalPtr(int index)
{
    return &m_globalBase[index >> 18 & 0x3F][index & 0x3FFFF];
}

/*
	//Hooking private functions
*/
bool initHooks()
{
	if (MH_Initialize() != MH_OK)
	{
		CLog::error("MinHook failed to initialize");
		return false;
	}
	if (!hookNatives())
	{
		CLog::error("Failed to initialize hooks");
 		return false;
 	}
	return true;
}

template <typename T>
bool hook(uint64_t hash, void* hkFn, T** trampoline)
{
	void**	trFn		= (void**) trampoline;
	if(*trFn != nullptr)
		return true;
	NativeHandler orgFn	= CHooking::getNativeHandler(hash);
	if(orgFn == nullptr)
		return false;
	MH_STATUS status = MH_CreateHook(orgFn, hkFn, trFn);
	if((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(orgFn) != MH_OK)
		return false;
	CHooking::m_hookedNative.push_back((void*) orgFn);
	return true;
}

NativeHandler ORIG_NATIVE = NULL;
void* __cdecl HK_NATIVE(NativeContext* cxt)
{
	static int	last = 0;
	int			cur = GAMEPLAY::GET_FRAME_COUNT();
	if (last != cur)
	{
		last = cur;
		CHooking::onTick();
	}
	ORIG_NATIVE(cxt);
	return cxt;
}

bool hookNatives()
{
	return true
		&& hook(0xF25D331DC2627BBC, &HK_NATIVE, &ORIG_NATIVE);		//is_player_online
		//&& hook(0x5E9564D8246B909A, &HK_NATIVE, &ORIG_NATIVE);		//is_player_playing
		//&& hook(0x4EDE34FBADD967A6, &HK_NATIVE, &ORIG_NATIVE);		//wait
}

void findPatterns()
{
	CPattern pattern_gameState	("\x83\x3D\x00\x00\x00\x00\x00\x8A\xD9\x74\x0A",													"xx?????xxxx");
	CPattern pattern_world		("\x48\x8B\x05\x00\x00\x00\x00\x45\x00\x00\x00\x00\x48\x8B\x48\x08\x48\x85\xC9\x74\x07",			"xxx????x????xxxxxxxxx");
	CPattern pattern_blip		("\x4C\x8D\x05\x00\x00\x00\x00\x0F\xB7\xC1",														"xxx????xxx");
	CPattern pattern_native		("\x76\x61\x49\x8B\x7A\x40\x48\x8D\x0D",															"xxxxxxxxx");
	CPattern pattern_modelCheck	("\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50",												"xxxxx????xxx");
	CPattern pattern_modelSpawn	("\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05\x48",													"xxxxxxxxxxx");
	CPattern pattern_replay		("\x48\x8D\x0D\x00\x00\x00\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8A\xD8\xE8\x00\x00\x00\x00\x84\xDB\x75\x13\x48\x8D\x0D\x00\x00\x00\x00",	"xxx????xxxx????xxx????xxx????xxxxxxx????");
	CPattern pattern_global		("\x4C\x8D\x05\x00\x00\x00\x00\x4D\x8B\x08\x4D\x85\xC9\x74\x11",									"xxx????xxxxxxxx");
	CPattern pattern_playerList	("\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\xCF",	"xxx????x????xxxx????xxx");
	CPattern pattern_entityPool	("\x4C\x8B\x0D\x00\x00\x00\x00\x44\x8B\xC1\x49\x8B\x41\x08",										"xxx????xxxxxxx");

	char* ptr	= nullptr;

	ptr	= pattern_gameState.find(0).get<char>(2);
	ptr == nullptr ?	killProcess("Failed find game state pattern")				: CHooking::m_gameState		= (eGameState*)				(ptr + *(uint32_t*) ptr + 5);

	ptr	= pattern_native.find(0).get<char>(9);
	ptr == nullptr ?	killProcess("Failed to find native registration pattern")	: CHooking::m_regTable		= (NativeRegistration**)	(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_world.find(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find world pattern")					: CHack::m_pCWorld			= ((CWorld_Wrap*)			(ptr + *(uint32_t*) ptr + 4))->CWorld;
	
	ptr	= pattern_blip.find(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find blip pattern")					: CHooking::m_blipList		= (CBlipList*)				(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_replay.find(0).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find replay interface pattern")		: CHooking::m_replayIntf	= *(CReplayInterface**)		(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_global.find(0).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find global pattern")				: CHooking::m_globalBase	= (__int64**)				(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_playerList.find(1).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find player list pattern")			: CHack::m_pCPlayers		= (CPlayers*)				(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_entityPool.find(1).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find entity pool pattern")			: CHooking::m_entityPool	= (MemoryPool**)			(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_modelCheck.find(0).get<char>(0);
	ptr == nullptr ? CLog::error("Failed to find online model requests bypass pattern") : mem_nop(ptr, 24);

	ptr	= pattern_modelSpawn.find(0).get<char>(8);
	ptr == nullptr ? CLog::error("Failed to find is player model allowed to spawn bypass pattern") : mem_nop(ptr, 2);
}