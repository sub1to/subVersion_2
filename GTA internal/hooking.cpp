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
std::vector<LPVOID>		CHooking::m_hookedNative;
eGameState* 			CHooking::m_gameState;
CBlipList*				CHooking::m_blipList;
NativeRegistration**	CHooking::m_regTable;
CReplayInterface*		CHooking::m_replayIntf;
handlerCache			CHooking::m_handlerCache;
__int64**				CHooking::m_globalBase;
MemoryPool**			CHooking::m_entityPool;
CRITICAL_SECTION		CHooking::m_critSec;
threeBytes*				CHooking::m_infAmmo;
threeBytes*				CHooking::m_noReload;
CViewPort*				CHooking::m_viewPort;
screenReso*				CHooking::m_resolution;

/*
	//Private declarations
*/
bool	initHooks();
void	antiCheatBypass(bool);
bool	hookNatives();
void	findPatterns();

static void*				g_eventPtr[REVENT_END]		= { nullptr };
static unsigned char		g_eventRestore[REVENT_END]	= { 0 };

/*
	//threeBytes public functions
*/

bool	threeBytes::empty()
{
	bool	r = true;
	for(int i = 0; i < 3; ++i)
		if(this->byte[i] != 0)
		{
			r = false;
			break;
		}
	return r;
}

/*
	//Hooking public functions
*/
void CHooking::init()
{
	CLog::msg("Initializing hooks");

	InitializeCriticalSection(&m_critSec);
	CCrossMap::init();
	findPatterns();
	//set max menu padding
	//this can only be done after this point, because it requires the resolution
	static_cast<CFeatActionValueMenu*>(CMenu::getFeature(FEATURE_I_MENU_PADDING_X))->m_fMax	= round((m_resolution->w - 320.f) / 25) * 25;
	static_cast<CFeatActionValueMenu*>(CMenu::getFeature(FEATURE_I_MENU_PADDING_Y))->m_fMax	= round((m_resolution->h - 310.f) / 25) * 25;

	while(*CHooking::m_gameState != GameStatePlaying)
		Sleep(100);

	if(!initHooks())
		killProcess();

	antiCheatBypass(true);

	CLog::msg("Hooks ready");
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
	antiCheatBypass(false);
	DeleteCriticalSection(&m_critSec);
	CLog::msg("Cleaning up hooks");
	for(int i = 0; i < m_hookedNative.size(); i++)
		if(MH_DisableHook(m_hookedNative[i]) != MH_OK && MH_RemoveHook(m_hookedNative[i]) != MH_OK)
			CLog::error("Failed to unhook %p", (void*) m_hookedNative[i]);
	MH_Uninitialize();
}

NativeHandler CHooking::getNativeHandler(uint64_t origHash)
{
	NativeHandler handler =	nullptr;
	handlerCache::iterator it	= m_handlerCache.find(origHash);
	if(it != m_handlerCache.end())
	{
		handler	= it->second;
		goto LABEL_RET_HANDLER;
	}

	uint64_t newHash = CCrossMap::get(origHash);
	if(newHash == NULL)
		goto LABEL_RET_HANDLER;

	NativeRegistration*	table	= CHooking::m_regTable[newHash & 0xFF];

	for(; table; table = table->nextRegistration)
		for (uint32_t i = 0; i < table->numEntries; i++)
			if (newHash == table->hashes[i])
			{
				handler = table->handlers[i];
				break;
			}

	m_handlerCache[origHash] = handler;

	//CLog::msg("Native 0x%016llx 0x%p", origHash, handler);

LABEL_RET_HANDLER:
	return handler;
}

__int64* CHooking::getGlobalPtr(int index)
{
    return &m_globalBase[index >> 0x12 & 0x3F][index & 0x3FFFF];
}

void CHooking::defuseEvent(eRockstarEvent e, bool b)
{
	static const BYTE	ret	= 0xC3;
	BYTE*				ptr	= (BYTE*) g_eventPtr[e];
	if(b)
	{
		if(g_eventRestore[e] == 0)
			g_eventRestore[e] = ptr[0];
		*ptr = ret;
	}
	else if(g_eventRestore[e] != 0)
		*ptr = g_eventRestore[e];
}

/*
	//Hooking private functions
*/
bool initHooks()
{
	if(MH_Initialize() != MH_OK)
	{
		CLog::fatal("MinHook failed to initialize");
		return false;
	}
	if(!hookNatives())
	{
		CLog::fatal("Failed to initialize hooks");
 		return false;
 	}
	return true;
}

void antiCheatBypass(bool b = true)
{
	CHooking::defuseEvent(REVENT_REQUEST_PICKUP_EVENT, b);
	CHooking::defuseEvent(REVENT_REPORT_MYSELF_EVENT, b);
	CHooking::defuseEvent(REVENT_REPORT_CASH_SPAWN_EVENT, b);
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

/*NativeHandler ORIG_NATIVE = nullptr;
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
}*/

//static BOOL IS_PLAYER_ONLINE() { return invoke<BOOL>(0xF25D331DC2627BBC); } // 0xF25D331DC2627BBC 0x9FAB6729
BOOL (__cdecl *OG_IS_PLAYER_ONLINE)(scrNativeCallContext* context)	= nullptr;
BOOL __cdecl HK_IS_PLAYER_ONLINE(NativeContext* cxt)
{
	if(TryEnterCriticalSection(&CHooking::m_critSec))
	{
		static int	last = 0;
		int			cur = GAMEPLAY::GET_FRAME_COUNT();
		if (last != cur)
		{
			last = cur;
			CHooking::onTick();
		}
		LeaveCriticalSection(&CHooking::m_critSec);
	}
	return OG_IS_PLAYER_ONLINE(cxt);
}

//static BOOL GET_EVENT_DATA(BOOL p0, int p1, int* p2, int p3) { return invoke<BOOL>(0x2902843FCD2B2D79, p0, p1, p2, p3); } // 0x2902843FCD2B2D79 0x4280F92F
BOOL (__cdecl *OG_GET_EVENT_DATA)(scrNativeCallContext* context)	= nullptr;
BOOL __cdecl HK_GET_EVENT_DATA(NativeContext *cxt)
{
	int	p1	= cxt->GetArgument<int>(1);

	//if(CMenu::getFeature(feature::map["FEATURE_U_REMOTE_PROT_MONEY"])->m_bOn		&& (p1 == 0x127 || p1 == 0x230))
	//	CLog::msg("Remote money attempt blocked.");
	//if(CMenu::getFeature(feature::map["FEATURE_U_REMOTE_PROT_RP"])->m_bOn		&& p1 == 0x124)
	//	CLog::msg("Remote rp attempt blocked.");
	//if(CMenu::getFeature(feature::map["FEATURE_D_FRAUD"])->m_bOn		&& p1 == 0x186)
	//	CLog::msg("Remote fraud attempt blocked.");
	if(CMenu::getFeature(FEATURE_D_KICK)->m_bOn	&& p1 == 0x38)
		CLog::msg("Remote kick attempt blocked.");
	else
		return OG_GET_EVENT_DATA(cxt);

    return FALSE;
}

bool hookNatives()
{
	return true
		&& hook(0xF25D331DC2627BBC, &HK_IS_PLAYER_ONLINE, &OG_IS_PLAYER_ONLINE)
		&& hook(0x2902843FCD2B2D79, &HK_GET_EVENT_DATA, &OG_GET_EVENT_DATA)
		;
}

void findPatterns()
{
	CPattern pattern_gameState	("\x83\x3D\x00\x00\x00\x00\x00\x8A\xD9\x74\x0A",													"xx?????xxxx");
	//CPattern pattern_world		("\x48\x8B\x05\x00\x00\x00\x00\x45\x00\x00\x00\x00\x48\x8B\x48\x08\x48\x85\xC9\x74\x07",			"xxx????x????xxxxxxxxx");
	CPattern pattern_world		("\x48\x8B\x05\x00\x00\x00\x00\x4C\x8B\x68\x08\x4C\x89\xAD\xD8\x03\x00\x00\x4D\x85\xED\x0F\x84\x93\x04\x00\x00\x8D\x4B\x0F\x48\x8D",	"xxx????xxxxxxxxxxxxxxxxxxxxxxxxx");
	CPattern pattern_blip		("\x4C\x8D\x05\x00\x00\x00\x00\x0F\xB7\xC1",														"xxx????xxx");
	CPattern pattern_native		("\x76\x61\x49\x8B\x7A\x40\x48\x8D\x0D",															"xxxxxxxxx");
	CPattern pattern_modelCheck	("\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50",												"xxxxx????xxx");
	CPattern pattern_modelSpawn	("\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05\x48",													"xxxxxxxxxxx");
	CPattern pattern_replay		("\x48\x8D\x0D\x00\x00\x00\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8A\xD8\xE8\x00\x00\x00\x00\x84\xDB\x75\x13\x48\x8D\x0D\x00\x00\x00\x00",	"xxx????xxxx????xxx????xxx????xxxxxxx????");
	CPattern pattern_global		("\x4C\x8D\x05\x00\x00\x00\x00\x4D\x8B\x08\x4D\x85\xC9\x74\x11",									"xxx????xxxxxxxx");
	CPattern pattern_playerList	("\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\xCF",	"xxx????x????xxxx????xxx");
	CPattern pattern_entityPool	("\x4C\x8B\x0D\x00\x00\x00\x00\x44\x8B\xC1\x49\x8B\x41\x08",										"xxx????xxxxxxx");
	CPattern pattern_eventHook	("\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\x4C\x8D\x0D\x00\x00\x00\x00\x4C\x8D\x05\x00\x00\x00\x00\xBA\x03",	"xxxxx????xxx????xxx????xxx????xx");
	CPattern pattern_ammo		("\x41\x2B\xD1\xE8",																				"xxxx");
	CPattern pattern_magazine	("\x41\x2B\xC9\x3B\xC8\x0F",																		"xxxxxx");
	CPattern pattern_viewport	("\x48\x8B\x15\x00\x00\x00\x00\x48\x8D\x2D\x00\x00\x00\x00\x48\x8B\xCD",							"xxx????xxx????xxx");
	CPattern pattern_resolution	("\x8B\x0D\x00\x00\x00\x00\x49\x8D\x56\x28",														"xx????xxxx");

	constexpr char	pattern_event[]	= "\x4C\x8D\x05";

	        //    address = FindPattern("\x48\x8B\x05\x00\x00\x00\x00\x41\x0F\xBF\xC8\x0F\xBF\x40\x10", "xxx????xxxxxxxx");
           // PedPoolAddress = reinterpret_cast<uintptr_t *>(*reinterpret_cast<int *>(address + 3) + address + 7);

	char*	ptr			= nullptr;

	ptr	= pattern_gameState.find(0).get(0).get<char>(2);
	ptr == nullptr ?	killProcess("Failed find game state pattern")				: CHooking::m_gameState		= (eGameState*)				(ptr + *(uint32_t*) ptr + 5);

	ptr	= pattern_native.find(0).get(0).get<char>(9);
	ptr == nullptr ?	killProcess("Failed to find native registration pattern")	: CHooking::m_regTable		= (NativeRegistration**)	(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_world.find(0).get(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find world pattern")					: CHack::m_pCWorld			= ((CWorld_Wrap*)			(ptr + *(uint32_t*) ptr + 4))->CWorld;
	
	ptr	= pattern_blip.find(0).get(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find blip pattern")					: CHooking::m_blipList		= (CBlipList*)				(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_replay.find(0).get(0).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find replay interface pattern")		: CHooking::m_replayIntf	= *(CReplayInterface**)		(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_global.find(0).get(0).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find global pattern")				: CHooking::m_globalBase	= (__int64**)				(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_playerList.find(1).get(0).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find player list pattern")			: CHack::m_pCPlayers		= (CPlayers*)				(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_entityPool.find(1).get(0).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find entity pool pattern")			: CHooking::m_entityPool	= (MemoryPool**)			(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_ammo.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find infinite ammo pattern")			: CHooking::m_infAmmo		= (threeBytes*)				ptr;

	ptr	= pattern_magazine.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find no reload pattern")				: CHooking::m_noReload		= (threeBytes*)				ptr;

	ptr	= pattern_viewport.find(1).get(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find viewport pattern")				: CHooking::m_viewPort		= *(CViewPort**)			(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_resolution.find(1).get(0).get<char>(2);
	ptr == nullptr ?	killProcess("Failed to find resolution pattern")			: CHooking::m_resolution	= (screenReso*)				(ptr + *(uint32_t*) ptr + 4);

	ptr	= pattern_modelCheck.find(0).get(0).get<char>(0);
	ptr == nullptr ? CLog::error("Failed to find online model requests bypass pattern")				: mem_nop(ptr, 24);

	ptr	= pattern_modelSpawn.find(0).get(0).get<char>(8);
	ptr == nullptr ? CLog::error("Failed to find is player model allowed to spawn bypass pattern")	: mem_nop(ptr, 2);

	ptr	= pattern_eventHook.find(0).get(0).get<char>(0);
	if(ptr == nullptr)
		killProcess("Failed to find event hook pattern");

	for(uint32_t i = 0, match = 0, found = 0; found < REVENT_END; ++ptr)
	{
		char*	eventPtr;

		if(*ptr != pattern_event[i])
			goto LABEL_RESET;

		if(++match < 3)
		{
			++i;
			continue;
		}

		eventPtr			= ptr + 1;
		g_eventPtr[found]	= (void*) (eventPtr + *(int32_t*) eventPtr + 4);
		++found;

	LABEL_RESET:
		i	= match	= 0;
	}
}