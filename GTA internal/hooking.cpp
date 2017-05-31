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
std::vector<LPVOID>		CHooking::m_hooks;
eGameState* 			CHooking::m_gameState;
CBlipList*				CHooking::m_blipList;
CReplayInterface*		CHooking::m_replayIntf;
__int64**				CHooking::m_globalBase;
MemoryPool**			CHooking::m_entityPool;
//CRITICAL_SECTION		CHooking::m_critSec;
threeBytes*				CHooking::m_infAmmo;
threeBytes*				CHooking::m_noReload;
CViewPort*				CHooking::m_viewPort;
screenReso*				CHooking::m_resolution;
void*					CHooking::m_objectHashTable;
void*					CHooking::m_objectHashTableSectionEnd;
void*					CHooking::m_onlineName;
twoBytes*				CHooking::m_ownedExplosionBypass;
uint64_t*				CHooking::m_frameCount;
CTextInfo*				CHooking::m_textInfo;
char*					CHooking::m_onscreenKeyboardResult;
clockTime*				CHooking::m_clockTime;
uint64_t*				CHooking::m_networkTime;
MemoryPool**			CHooking::m_pedPool;
void*					CHooking::m_gameInfo;
CPlayers*				CHooking::m_players;


fpIsPlayerOnline					CHooking::IS_PLAYER_ONLINE;
fpIsPlayerPlaying					CHooking::is_player_playing;
fpPlayerId							CHooking::player_id;
fpGetPlayerPed						CHooking::get_player_ped;
fpGetPlayerTeam						CHooking::get_player_team;
fpGetVehiclePedIsUsing				CHooking::get_vehicle_ped_is_using;
fpGetPedInVehicleSeat				CHooking::get_ped_in_vehicle_seat;
fpIsAimCamActive					CHooking::is_aim_cam_active;
fpGetEntityPlayerIsFreeAimingAt		CHooking::get_entity_player_is_free_aiming_at;
fpNetworkIsSessionStarted			CHooking::network_is_session_started;
fpGetEntitySpeed					CHooking::get_entity_speed;
fpGetPlayerName						CHooking::get_player_name;
fpDrawRect							CHooking::draw_rect;
fpDrawLine							CHooking::draw_line;
fpGetGroundZFor3dCoord				CHooking::get_ground_z_for_3d_coord;
fpCreateVehicle						CHooking::create_vehicle;
fpSetEntityCoordsNoOffset			CHooking::set_entity_coords_no_offset;
fpGetEntityHeading					CHooking::get_entity_heading;
fpGetGameplayCamRot					CHooking::get_gameplay_cam_rot;
fpGetGameplayCamCoord				CHooking::get_gameplay_cam_coord;
fpGetPlayerGroup					CHooking::get_player_group;
fpSetPlayerModel					CHooking::set_player_model;
fpSetPedRandomComponentVariatian	CHooking::set_ped_random_component_variation;
fpSetPedDefaultComponentVariation	CHooking::set_ped_default_component_variation;
fpIsPedInAnyVehicle					CHooking::is_ped_in_any_vehicle;
fpCreatePed							CHooking::create_ped;
fpSetPedIntoVehicle					CHooking::set_ped_into_vehicle;
fpSetPedConfigFlag					CHooking::set_ped_config_flag;
fpClearPedBloodDamage				CHooking::clear_ped_blood_damage;
fpClearPedWetness					CHooking::clear_ped_wetness;
fpCreateObject						CHooking::create_object;
//fpGetPedNearbyVehicles				CHooking::get_ped_nearby_vehicles;
//fpGetPedNearbyPeds					CHooking::get_ped_nearby_peds;
fpGetPedGroupIndex					CHooking::get_ped_group_index;
fpClonePed							CHooking::clone_ped;
fpNetworkShopBeginService			CHooking::network_shop_begin_service;
fpNetworkShopCheckoutStart			CHooking::network_shop_checkout_start;
fpStatSetInt						CHooking::stat_set_int;
fpStatSetFloat						CHooking::stat_set_float;
fpStatSetBool						CHooking::stat_set_bool;
fpStatSetDate						CHooking::stat_set_date;
fpStatGetInt						CHooking::stat_get_int;
fpAddExplosion						CHooking::add_explosion;
fpGiveDelayedWeaponToPed			CHooking::give_delayed_weapon_to_ped;
fpRemoveAllPedWeapons				CHooking::remove_all_ped_weapons;
fpRemoveWeaponFromPed				CHooking::remove_weapon_from_ped;
fpSetMobileRadio					CHooking::set_mobile_radio;
fpGetPlayerRadioStationIndex		CHooking::get_player_radio_station_index;
fpGetRadioStationName				CHooking::get_radio_station_name;
fpNetworkHasControlOfEntity			CHooking::network_has_control_of_entity;
fpAddOwnedExplosion					CHooking::add_owned_explosion;
fpNetworkRequestControlOfEntity		CHooking::network_request_control_of_entity;
fpNetworkGetNetworkIdFromEntity		CHooking::network_get_network_id_from_entity;
fpNetworkHasControlOfNetworkId		CHooking::network_has_control_of_network_id;
fpNetworkRequestControlOfNetworkId	CHooking::network_request_control_of_network_id;
fpSetNetworkIdCanMigrate			CHooking::set_network_id_can_migrate;
fpNetworkCreateSynchronisedScene	CHooking::network_create_synchronised_scene;
fpNetworkAddPedToSynchronisedScene	CHooking::network_add_ped_to_synchronised_scene;
fpNetworkStartSynchronisedScene		CHooking::network_start_synchronised_scene;
fpClearPedTasksImmediately			CHooking::clear_ped_tasks_immediately;
fpSetEntityVisible					CHooking::set_entity_visible;
fpSetPedAsGroupMember				CHooking::set_ped_as_group_member;
fpIsPedGroupMember					CHooking::is_ped_group_member;
fpSetPedGravity						CHooking::set_ped_gravity;
fpSetEntityHasGravity				CHooking::set_entity_has_gravity;
fpIsVehicleDrivable					CHooking::is_vehicle_drivable;
fpIsModelAHeli						CHooking::is_model_a_heli;
fpIsModelAPlane						CHooking::is_model_a_plane;
fpIsModelACar						CHooking::is_model_a_car;
fpSetHeliBladesFullSpeed			CHooking::set_heli_blades_full_speed;
fpSetVehicleForwardSpeed			CHooking::set_vehicle_forward_speed;
fpSetVehicleNumberPlateText			CHooking::set_vehicle_number_plate_text;
fpSetPedToRagdoll					CHooking::set_ped_to_ragdoll;
fpGetPedBoneCoords					CHooking::get_ped_bone_coords;
fpSetEntityAsMissionEntity			CHooking::set_entity_as_mission_entity;
fpApplyForceToEntity				CHooking::apply_force_to_entity;
fpSetEntityRotation					CHooking::set_entity_rotation;
fpSetEntityHeading					CHooking::set_entity_heading;
fpFreezeEntityPosition				CHooking::freeze_entity_position;
fpShootSingleBulletBetweenCoords	CHooking::shoot_single_bullet_between_coords;
fpSetPedNeverLeavesGroup			CHooking::set_ped_never_leaves_group;
fpSetGroupFormation					CHooking::set_group_formation;
fpGetPedBoneIndex					CHooking::get_ped_bone_index;
fpSetPedComponentVariation			CHooking::set_ped_component_variation;
fpClearAllPedProps					CHooking::clear_add_ped_props;
fpSetPedPropIndex					CHooking::set_ped_prop_index;
fpIsEntityInAir						CHooking::is_entity_in_air;
fpSetEntityVelocity					CHooking::set_entity_velocity;
fpGetEntityAttachedTo				CHooking::get_entity_attached_to;
fpDetachEntity						CHooking::detach_entity;
fpDeleteEntity						CHooking::delete_entity;
fpIsEntityAttached					CHooking::is_entity_attached;
fpSetEntityAsNoLongerNeeded			CHooking::set_entity_as_no_longer_needed;
fpGetEntityVelocity					CHooking::get_entity_velocity;
fpGetEntityRotation					CHooking::get_entity_rotation;
fpGetEntityModel					CHooking::get_entity_model;
fpSetVehicleOnGroundProperly		CHooking::set_vehicle_on_ground_properly;
fpSetVehicleUndriveable				CHooking::set_vehicle_undriveable;
fpSetVehicleFixed					CHooking::set_vehicle_fixed;
fpSetVehicleDeformationFixed		CHooking::set_vehicle_deformation_fixed;
fpIsVehicleSeatFree					CHooking::is_vehicle_seat_free;
fpSetVehicleModKit					CHooking::set_vehicle_mod_kit;
fpSetVehicleNumberPlateIndex		CHooking::set_vehicle_number_plate_index;
fpToggleVehicleMod					CHooking::toggle_vehicle_mod;
fpSetVehicleMod						CHooking::set_vehicle_mod;
fpSetVehicleWheelType				CHooking::set_vehicle_wheel_type;
fpGetNumVehicleMod					CHooking::get_num_vehicle_mod;
fpAddTextCompSubstrPlayerName		CHooking::add_text_comp_substr_playername;
fpEndTextCmdDisplayText				CHooking::end_text_cmd_display_text;
fpBeginTextCmdDisplayText			CHooking::begin_text_cmd_display_text;
fpSetNotificationTextEntiry			CHooking::set_notification_text_entry;
fpDrawNotification					CHooking::draw_notification;
fpSetWeatherTypeNowPersist			CHooking::set_weather_type_now_persist;
fpDisplayOnscreenKeyboard			CHooking::display_onscreen_keyboard;
fpUpdateOnscreenKeyboard			CHooking::update_onscreen_keyboard;
fpSetLocalPlayerVisibleLocally		CHooking::set_local_player_visible_locally;
fpNetworkOverrideClockTime			CHooking::network_override_clock_time;
fpGetNetworkTime					CHooking::get_network_time;
fpAiTaskWanderStandard				CHooking::ai_task_wander_standard;
fpAiTaskPlayAnim					CHooking::ai_task_play_anim;
fpIsModelInCdimage					CHooking::is_model_in_cdimage;
fpIsModelValid						CHooking::is_model_valid;
fpIsModelAVehicle					CHooking::is_model_a_vehicle;
fpRequestModel						CHooking::request_model;
fpHasModelLoaded					CHooking::has_model_loaded;
fpRequestAnimDict					CHooking::request_anim_dict;
fpHasAnimDictLoaded					CHooking::has_anim_dict_loaded;
fpDecorRegister						CHooking::decor_register;
fpDecorSetInt						CHooking::decor_set_int;
fpCreateAmbientDrop					CHooking::create_ambient_pickup;
fpIsPlayerFreeAiming				CHooking::is_player_free_aiming;
fpGetPedLastWeaponImpactCoord		CHooking::get_ped_last_weapon_impact;
fpStartRayCast						CHooking::start_ray_cast;
fpGetRayCast						CHooking::get_ray_cast;
fpPtrToHandle						CHooking::ptr_to_handle;
fpNetworkSetInSpectatorMode			CHooking::network_set_in_spectator_mode;
fpSetPedCombatAbility				CHooking::set_ped_combat_ability;
fpAiTaskCombatPed					CHooking::ai_task_combat_ped;
fpTriggerScriptEvent				CHooking::trigger_script_event;
fpApplyVehicleColors				CHooking::apply_vehicle_colors;
fpSetPedRelationshipGroupHash		CHooking::set_ped_relationship_group_hash;
fpSetPlayerVisibleLocally			CHooking::set_player_visible_locally;
fpSetModelAsNoLongerNeeded			CHooking::set_model_as_no_longer_needed;
fpSetRadioToStationName				CHooking::set_radio_to_station_name;
fpSetVehicleEngineOn				CHooking::set_vehicle_engine_on;
fpAttachEntityToEntity				CHooking::attach_entity_to_entity;
fpSetEntityCollision				CHooking::set_entity_collision;


/*
	//Private declarations
*/
bool	initHooks();
void	antiCheatBypass(bool);
bool	hookNatives();
void	findPatterns();

static void*					g_eventPtr[REVENT_END]		= { nullptr };
static unsigned char			g_eventRestore[REVENT_END]	= { 0 };
static std::vector<objectHash>	g_antiCrash;

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

bool	twoBytes::empty()
{
	bool	r = true;
	for(int i = 0; i < 2; ++i)
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

//	InitializeCriticalSection(&m_critSec);
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
	CLog::msg("Cleaning up hooks");
	for(int i = 0; i < m_hooks.size(); i++)
		if(MH_DisableHook(m_hooks[i]) != MH_OK && MH_RemoveHook(m_hooks[i]) != MH_OK)
			CLog::error("Failed to unhook %p", (void*) m_hooks[i]);
	MH_Uninitialize();
	//DeleteCriticalSection(&m_critSec);
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

DWORD __stdcall antiCrashSearch(LPVOID lpParam)
{
	Hash*	hashptr	= (Hash*) CHooking::m_objectHashTable;
	char*	end		= (char*) CHooking::m_objectHashTableSectionEnd - 0x20;

	for(; (char*) hashptr < end; ++hashptr)
	{
		if(*hashptr == 0)
			continue;
		for(int i = 0; i < get_array_size(hash::forbidden_object); ++i)
		{
			if(*hashptr != hash::forbidden_object[i])
				continue;
			g_antiCrash.push_back( { hashptr, *hashptr } );
		}
	}
	return S_OK;
}

bool CHooking::antiCrash(bool toggle)
{
	static HANDLE	hAntiCrash	= 0;
	constexpr Hash	dildo			= 0xe6cb661e;
	Hash*	hashptr		= nullptr;
	char*		end		= nullptr;

	if(!g_antiCrash.empty() || hAntiCrash)
		goto LABEL_SET_VALUE;

	if(!toggle)
		return true;

	hAntiCrash	= CreateThread(	NULL,
								0,
								antiCrashSearch,
								NULL,
								0,
								nullptr);

LABEL_SET_VALUE:

	if(WaitForSingleObject(hAntiCrash, 0) != WAIT_OBJECT_0)	//if the thread is still alive, return; it's still searching
		return false;
	if(hAntiCrash)
		CloseHandle(hAntiCrash);

	if(!toggle)
	{
		for(std::vector<objectHash>::iterator it = g_antiCrash.begin(); it != g_antiCrash.end(); ++it)
		{
			if(*it->ptr != dildo && *it->ptr != it->hash)
			{
				g_antiCrash.erase(it);
				continue;
			}
			*it->ptr	= it->hash;
		}
		return true;
	}

	for(std::vector<objectHash>::iterator it = g_antiCrash.begin(); it != g_antiCrash.end(); ++it)
		*it->ptr	= dildo;
	return true;
}

bool CHooking::setPlayerName(std::string& name)
{
	size_t newLen	= name.size() + 1;
	if(newLen <= 1 || newLen > 20)
		return false;

	char	buffer[0x20]	= {};
	char*	pSearch			= (char*) CHooking::m_onlineName + 0x5C;
	size_t	curLen			= strlen(pSearch) + 1;
	
	strncpy_s(buffer, pSearch, curLen);

	for(uint32_t i = 0, found = 0, match = 0; found < 4; ++pSearch)
	{
		if(*pSearch != buffer[i])
			goto LABEL_RESET;

		if(++match < curLen)
		{
			++i;
			continue;
		}

		strncpy_s(pSearch - i, newLen, &name[0], newLen);
		++found;

	LABEL_RESET:
		i = match = 0;
	}

	strncpy_s(CPlayerMem::get_player_cped(CPlayerMem::player_id())->pCPlayerInfo->sName, &name[0], newLen);

	return true;
}

void CHooking::ownedExplosionBypass(bool toggle)
{
	constexpr twoBytes patched	= { 0x39, 0xDB };
	constexpr twoBytes restore	= { 0x3B, 0xD8 };
	if(m_ownedExplosionBypass == nullptr)
		return;
	*m_ownedExplosionBypass		= toggle ? patched : restore;
}

/*
	//Hooking private functions
*/
bool initHooks()
{
	if(MH_Initialize() != MH_OK)
		killProcess("MinHook failed to initialize");
	if(!hookNatives())
		killProcess("Failed to initialize hooks");
	return true;
}

void antiCheatBypass(bool b = true)
{
	CHooking::defuseEvent(REVENT_REQUEST_PICKUP_EVENT, b);		//bypass pickup detection
	CHooking::ownedExplosionBypass(b);
	//CHooking::defuseEvent(REVENT_REPORT_MYSELF_EVENT, b);
	//CHooking::defuseEvent(REVENT_REPORT_CASH_SPAWN_EVENT, b);
}

fpIsPlayerOnline	OG_IS_PLAYER_ONLINE	= nullptr;
BOOL __cdecl HK_IS_PLAYER_ONLINE(void* pContext)
{
	static uint64_t	last = 0;
	uint64_t		cur = *CHooking::m_frameCount;
	if (last != cur)
	{
		last = cur;
		CHooking::onTick();
	}
	return OG_IS_PLAYER_ONLINE(pContext);
}

/*fpTriggerScriptEvent OG_TRIGGER_SCRIPT_EVENT	= nullptr;
BOOL	__cdecl HK_TRIGGER_SCRIPT_EVENT(bool unk0, uint64_t* args, int argCount, int bitFlags)
{
	CLog::msg("SCRIPT_EVENT unk0: 0x%016llx", unk0);
	for(int i = 0; i < argCount; ++i)
		CLog::msg("SCRIPT_EVENT p2[%i]: 0x%016llx", i, args[i]);
	CLog::msg("SCRIPT_EVENT bitFlags: 0x%016llx", bitFlags);
	return OG_TRIGGER_SCRIPT_EVENT(unk0, args, argCount, bitFlags);
}*/

bool hookNatives()
{
	MH_STATUS status = MH_CreateHook(CHooking::IS_PLAYER_ONLINE, HK_IS_PLAYER_ONLINE, (void**) &OG_IS_PLAYER_ONLINE);
	if((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(CHooking::IS_PLAYER_ONLINE) != MH_OK)
		return false;
	CHooking::m_hooks.push_back(CHooking::IS_PLAYER_ONLINE);

	//status = MH_CreateHook(CHooking::trigger_script_event, HK_TRIGGER_SCRIPT_EVENT, (void**) &OG_TRIGGER_SCRIPT_EVENT);
	//if((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(CHooking::trigger_script_event) != MH_OK)
	//	return false;
	//CHooking::m_hooks.push_back(CHooking::trigger_script_event);

	return true;
}

void	failPat(const char* name)
{
	CLog::fatal("Failed to find %s pattern.", name);
	killProcess();
}

template <typename T>
void	setPat
(
	const char*	name,
	char*		pat,
	char*		mask, 
	T**			out, 
	bool		rel, 
	int			offset	= 0, 
	int			deref	= 0, 
	int			skip	= 0
)
{
	T*	ptr		= nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	if(rel)
		ptr			= pattern.get(skip).get_rel<T>(offset);
	else
		ptr			= pattern.get(skip).get<T>(offset);

	while(true)
	{
		if(ptr == nullptr)
			failPat(name);

		if(deref <= 0)
			break;
		ptr		= *(T**) ptr;
		--deref;
	}

	*out		= ptr;
	return;
}

template <typename T>
void	setFn
(
	const char*	name, 
	char*		pat, 
	char*		mask, 
	T*			out, 
	int			skip	= 0
)
{
	char*	ptr		= nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	ptr	= pattern.get(skip).get<char>(0);

	if(ptr == nullptr)
		failPat(name);

	*out		= (T) ptr;
	return;
}

void findPatterns()
{
	char*	ptr			= nullptr;
	constexpr char	pattern_event[]	= "\x4C\x8D\x05";
	HANDLE steam	= GetModuleHandleA("steam_api64.dll");

	//game state
	setPat<eGameState>(	"game state",
						"\x8B\x05\x00\x00\x00\x00\x33\xED\x8B\xF2",
						"xx????xxxx",
						&CHooking::m_gameState,
						true,
						2);

	//world
	setPat<CWorld>(		"world",
						"\x48\x8B\x05\x00\x00\x00\x00\x4C\x8B\x68\x08\x4C\x89\xAD\xD8\x03\x00\x00\x4D\x85\xED\x0F\x84\x93\x04\x00\x00\x8D\x4B\x0F\x48\x8D",
						"xxx????xxxxxxxxxxxxxxxxxxxxxxxxx",
						&CHack::m_pCWorld,
						true,
						3,
						1);

	//blips
	setPat<CBlipList>(	"blip list",
						"\x4C\x8D\x05\x00\x00\x00\x00\x0F\xB7\xC1",
						"xxx????xxx",
						&CHooking::m_blipList,
						true,
						3);

	//replay interface
	setPat<CReplayInterface>(	"replay interface",
								"\x48\x8D\x0D\x00\x00\x00\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8A\xD8\xE8\x00\x00\x00\x00\x84\xDB\x75\x13\x48\x8D\x0D\x00\x00\x00\x00",
								"xxx????xxxx????xxx????xxx????xxxxxxx????",
								&CHooking::m_replayIntf,
								true,	
								3,
								1);

	//global
	setPat<__int64*>(	"global",
						"\x4C\x8D\x05\x00\x00\x00\x00\x4D\x8B\x08\x4D\x85\xC9\x74\x11",
						"xxx????xxxxxxxx",
						&CHooking::m_globalBase,
						true,
						3);

	//player list
	setPat<CPlayers>(	"player list",
						"\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\xCF",
						"xxx????x????xxxx????xxx",
						&CHooking::m_players,
						true,
						3);

	//entity pool
	setPat<MemoryPool*>(	"entity pool",
							"\x4C\x8B\x0D\x00\x00\x00\x00\x44\x8B\xC1\x49\x8B\x41\x08",
							"xxx????xxxxxxx",
							&CHooking::m_entityPool,
							true,
							3);

	//ped pool
	setPat<MemoryPool*>(	"ped pool",
							"\x48\x8B\x05\x00\x00\x00\x00\x41\x0F\xBF\xC8\x0F\xBF\x40\x10",
							"xxx????xxxxxxxx",
							&CHooking::m_pedPool,
							true,
							3);
	
	//viewport
	setPat<CViewPort>(	"viewport",
						"\x48\x8B\x15\x00\x00\x00\x00\x48\x8D\x2D\x00\x00\x00\x00\x48\x8B\xCD",
						"xxx????xxx????xxx",
						&CHooking::m_viewPort,
						true,
						3,
						1);

	//resolution
	setPat<screenReso>(	"resolution",
						"\x8B\x0D\x00\x00\x00\x00\x49\x8D\x56\x28",
						"xx????xxxx",
						&CHooking::m_resolution,
						true,
						2);

	//player name
	setPat<void>(		"name changer",
						"\x48\x8B\x05\x00\x00\x00\x00\xC3\x8A\xD1",
						"xxx????xxx",
						&CHooking::m_onlineName,
						true,
						3,
						1);

	//frame count
	setPat<uint64_t>(	"frame count",
						"\x8B\x15\x00\x00\x00\x00\x41\xFF\xCF",
						"xx????xxx",
						&CHooking::m_frameCount,
						true,
						2);

	//text color
	setPat<CTextInfo>(	"text info",
						"\x48\x8D\x05\x00\x00\x00\x00\x48\x89\x44\x24\x00\x8B\x05\x00\x00\x00\x00\x89\x44\x24\x28",
						"xxx????xxxx?xx????xxxx",
						&CHooking::m_textInfo,
						true,
						3);

	//clock time
	setPat<clockTime>(	"clock time",
						"\x48\x8D\x0D\x00\x00\x00\x00\x8B\xFA\xE8\x00\x00\x00\x00\x44\x8D\x0C\x5B",
						"xxx????xxx????xxxx",
						&CHooking::m_clockTime,
						true,
						3);

	//network time
	setPat<uint64_t>(	"network time",
						"\x8B\x0D\x00\x00\x00\x00\x3B\xCB\x0F\x47\xCB",
						"xx????xxxxx",
						&CHooking::m_networkTime,
						true,
						2);

	//game info (p0 for set_radio_to_station_name)
	setPat<void>(		"game info",
						"\x48\x8D\x0D\x00\x00\x00\x00\x41\xB0\x01\x33\xD2\x88\x1D",
						"xxx????xxxxxxx",
						&CHooking::m_gameInfo,
						true,
						3);

	//inf ammo
	setPat<threeBytes>(	"infinite ammo",
						"\x41\x2B\xD1\xE8",
						"xxxx",
						&CHooking::m_infAmmo,
						false);

	//no reload
	setPat<threeBytes>(	"no reload",
						"\x41\x2B\xC9\x3B\xC8\x0F",
						"xxxxxx",
						&CHooking::m_noReload,
						false);

	//owned explosion bypass
	setPat<twoBytes>(	"owned explosion bypass",
						"\x3B\xD8\x0F\x94\xC3",
						"xxxxx",
						&CHooking::m_ownedExplosionBypass,
						false);


	if(!steam)
	{
		//onscreen keyboard result
		setPat<char>(		"onscreen keyboard result",
							"\x48\x8D\x0D\x00\x00\x00\x00\x41\x3B\xC0",
							"xxx????xxx",
							&CHooking::m_onscreenKeyboardResult,
							true,
							3);
	}
	else
	{
		//onscreen keyboard result
		setPat<char>(		"onscreen keyboard result",
							"\x48\x8D\x0D\x00\x00\x00\x00\x41\xB9\x00\x00\x00\x00\x41\x3B\xC0",
							"xxx????xx????xxx",
							&CHooking::m_onscreenKeyboardResult,
							true,
							3);
	}


	/*
		//functions
	*/
	//is_player_playing
	setFn<fpIsPlayerPlaying>(	"is_player_playing",
								"\x48\x83\xEC\x28\x33\xD2\xE8\x00\x00\x00\x00\x48\x85\xC0",
								"xxxxxxx????xxx",
								&CHooking::is_player_playing);

	//player_id
	setFn<fpPlayerId>(			"player_id",
								"\x48\x83\xEC\x28\x80\x3D\x00\x00\x00\x00\x00\x74\x12\x48\x8B\x0D\x00\x00\x00\x00\xE8",
								"xxxxxx?????xxxxx????x",
								&CHooking::player_id);

	//get_player_ped
	setFn<fpGetPlayerPed>(		"get_player_ped",
								"\x40\x53\x48\x83\xEC\x20\x33\xDB\x83\xF9\xFF\x74\x09\xB2\x01\xE8\x00\x00\x00\x00\xEB\x16",
								"xxxxxxxxxxxxxxxx????xx",
								&CHooking::get_player_ped);

	//get_player_team
	setFn<fpGetPlayerTeam>(			"get_player_team",
									"\x48\x83\xEC\x28\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0C\x48\x8B\xC8\x48\x83\xC4\x28\xE9\x00\x00\x00\x00\x83\xC8\xFF",
									"xxxxxxx????xxxxxxxxxxxxx????xxx",
									&CHooking::get_player_team);

	//get_vehicle_ped_is_using
	setFn<fpGetVehiclePedIsUsing>(	"get_vehicle_ped_is_using",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xF9\x33\xDB\xE8\x00\x00\x00\x00\x48\x8B\xD0",
									"xxxx?xxxxxxxxxx????xxx",
									&CHooking::get_vehicle_ped_is_using);

	//get_ped_in_vehicle_seat
	setFn<fpGetPedInVehicleSeat>(	"get_ped_in_vehicle_seat",
									"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xE8\x8D\x72\x01",
									"xxxx?xxxx?xxxx?xxxxxxxxxxx",
									&CHooking::get_ped_in_vehicle_seat);

	//is_aim_cam_active
	setFn<fpIsAimCamActive>(		"is_aim_cam_active",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x33\xD2\x48\x8B\xC8\x48\x8B\xF8",
									"xxxx?xxxxxx????xxxxxxxx",
									&CHooking::is_aim_cam_active);

	//get_entity_player_is_free_aiming_at
	setFn<fpGetEntityPlayerIsFreeAimingAt>(	"get_entity_player_is_free_aiming_at",
											"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xFA\xB2\x01\x33\xDB\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x3F",
											"xxxx?xxxxxxxxxxxxx????xxxxx",
											&CHooking::get_entity_player_is_free_aiming_at);

	//network_is_session_started
	setFn<fpNetworkIsSessionStarted>(	"network_is_session_started",
										"\x48\x8B\x0D\x00\x00\x00\x00\x33\xC0\x48\x85\xC9\x74\x0E\x83\xB9\x00\x00\x00\x00\x00\x75\x05",
										"xxx????xxxxxxxxx?????xx",
										&CHooking::network_is_session_started);

	//get_entity_speed
	setFn<fpGetEntitySpeed>(		"get_entity_speed",
									"\x48\x83\xEC\x38\x0F\x29\x74\x24\x00\x0F\x57\xF6\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x3E",
									"xxxxxxxx?xxxx????xxxxx",
									&CHooking::get_entity_speed);

	//get_player_name
	setFn<fpGetPlayerName>(			"get_player_name",
									"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8B\xD9\x74\x22",
									"xxxxxxxx?????xxxx",
									&CHooking::get_player_name);

	//draw_rect
	setFn<fpDrawRect>(				"draw_rect",
									"\x48\x8B\xC4\x48\x89\x58\x08\x57\x48\x83\xEC\x70\x48\x63\x0D\x00\x00\x00\x00\x0F",
									"xxxxxxxxxxxxxxx????x",
									&CHooking::draw_rect);

	//draw_line
	setFn<fpDrawLine>(				"draw_line",
									"\x40\x53\x48\x83\xEC\x40\xF3\x0F\x10\x09\xF3\x0F\x10\x41\x00\xF3\x0F\x10\x51\x00\x45\x8B\xD0\xBB",
									"xxxxxxxxxxxxxx?xxxx?xxxx",
									&CHooking::draw_line,
									1);	//skip 1, first one is draw_box

	//get_ground_z_for_3d_coord
	setFn<fpGetGroundZFor3dCoord>(	"get_ground_z_for_3d_coord",
									"\x4C\x8B\xDC\x49\x89\x5B\x10\x49\x89\x7B\x20",
									"xxxxxxxxxxx",
									&CHooking::get_ground_z_for_3d_coord);

	//create_vehicle
	setFn<fpCreateVehicle>(			"create_vehicle",
									"\x48\x89\x5C\x24\x00\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x50\xF3\x0F\x10\x02",
									"xxxx?xxxxxxxxxxxxxxxxxxxxxx",
									&CHooking::create_vehicle);

	//set_entity_coords_no_offset
	setFn<fpSetEntityCoordsNoOffset>(	"set_entity_coords_no_offset",
										"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x57\x48\x81\xEC\x00\x00\x00\x00\xF3\x0F\x10\x15",
										"xxxxxxxxxxxxxxx????xxxx",
										&CHooking::set_entity_coords_no_offset);

	//get_entity_heading
	setFn<fpGetEntityHeading>(		"get_entity_heading",
									"\x48\x83\xEC\x38\x0F\x29\x74\x24\x00\xE8\x00\x00\x00\x00\x0F",
									"xxxxxxxx?x????x",
									&CHooking::get_entity_heading);

	//get_gameplay_cam_rot
	setFn<fpGetGameplayCamRot>(		"get_gameplay_cam_rot",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x8B\xDA\x48\x8B\xF9\xE8\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\x48\x8D\x90\x00\x00\x00\x00",
									"xxxx?xxxxxxxxxxx????xxxx?xxx????",
									&CHooking::get_gameplay_cam_rot);

	//get_gameplay_cam_coord
	setFn<fpGetGameplayCamCoord>(	"get_gameplay_cam_coord",
									"\x40\x53\x48\x83\xEC\x20\x48\x8B\xD9\xE8\x00\x00\x00\x00\x8B\x90\x00\x00\x00\x00",
									"xxxxxxxxxx????xx????",
									&CHooking::get_gameplay_cam_coord);

	//get_player_group
	setFn<fpGetPlayerGroup>(		"get_player_group",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x50\xB2\x01",
									"xxxx?xxxxxxx",
									&CHooking::get_player_group);

	//set_player_model
	setFn<fpSetPlayerModel>(		"set_player_model",
									"\x40\x55\x53\x57\x48\x8B\xEC\x48\x83\xEC\x30\x8B\xF9",
									"xxxxxxxxxxxxx",
									&CHooking::set_player_model);

	//set_ped_random_component_variation
	setFn<fpSetPedRandomComponentVariatian>(	"set_ped_random_component_variation",
												"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x40\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8",
												"xxxx?xxxxxxxx????xxx",
												&CHooking::set_ped_random_component_variation);

	//set_ped_default_component_variation
	setFn<fpSetPedDefaultComponentVariation>(	"set_ped_default_component_variation",
												"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x2F",
												"xxxxxxx????xxxxxxxx",
												&CHooking::set_ped_default_component_variation);

	//set_ped_default_component_variation
	setFn<fpIsPedInAnyVehicle>(		"is_ped_in_any_vehicle",
									"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xFA\xE8\x00\x00\x00\x00\x32\xDB",
									"xxxx?xxxx?xxxxxxxxx????xx",
									&CHooking::is_ped_in_any_vehicle);

	//create_ped
	setFn<fpCreatePed>(				"create_ped",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x55\x57\x41\x56\x48\x8D\x68\xB1\x48\x81\xEC\x00\x00\x00\x00\x40\x8A\x75\x77",
									"xxxxxxxxxxxxxxxxxxxxxx????xxxx",
									&CHooking::create_ped);

	//set_ped_into_vehicle
	setFn<fpSetPedIntoVehicle>(		"set_ped_into_vehicle",
									"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x56\x57\x41\x56\x48\x83\xEC\x30\x41\x8B\xE8\x8B\xFA",
									"xxxx?xxxx?xxxxxxxxxxxxx",
									&CHooking::set_ped_into_vehicle);

	//set_ped_config_flag
	setFn<fpSetPedConfigFlag>(		"set_ped_config_flag",
									"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF0\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x53",
									"xxxx?xxxx?xxxxxxxxxxx????xxxxxxxx",
									&CHooking::set_ped_config_flag);

	//clear_ped_blood_damage
	setFn<fpClearPedBloodDamage>(	"clear_ped_blood_damage",
									"\x40\x53\x48\x83\xEC\x20\x8A\x91\x00\x00\x00\x00\x48\x8B\xD9\x80\xFA\xFF\x74\x51",
									"xxxxxxxx????xxxxxxxx",
									&CHooking::clear_ped_blood_damage);

	//clear_ped_wetness
	setFn<fpClearPedWetness>(		"clear_ped_wetness",
									"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x23\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\x8B\x00\x00\x00\x00",
									"xxxxxxx????xxxxxxxxxxxx????xxx????",
									&CHooking::clear_ped_wetness);

	//create_object
	setFn<fpCreateObject>(			"create_object",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x41\x54\x41\x57\x48\x8D\x68\xD9",
									"xxxxxxxxxxxxxxxxxxxxxxxx",
									&CHooking::create_object);

	//get_ped_nearby_vehicles
	//CPattern pattern_get_ped_nearby_vehicles	(	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x40\x48\x8B\xDA\xE8\x00\x00\x00\x00\x33\xFF",
	//												"xxxx?xxxx?xxxxxxxxx????xx");
	//ptr	= pattern_get_ped_nearby_vehicles.find(1).get(0).get<char>(0);
	//ptr == nullptr ?	killProcess("Failed to find get_ped_nearby_vehicles pattern")	: CHooking::get_ped_nearby_vehicles	= (fpGetPedNearbyVehicles)	ptr;

	//get_ped_nearby_peds
	//CPattern pattern_get_ped_nearby_peds	(	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x20\x45\x8B\xF8\x48\x8B\xDA",
	//											"xxxx?xxxx?xxxx?xxxxxxxxxxxxxxx");
	//ptr	= pattern_get_ped_nearby_peds.find(1).get(0).get<char>(0);
	//ptr == nullptr ?	killProcess("Failed to find get_ped_nearby_peds pattern")	: CHooking::get_ped_nearby_peds	= (fpGetPedNearbyPeds)	ptr;

	//get_ped_group_index
	setFn<fpGetPedGroupIndex>(		"get_ped_group_index",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x50\xE8\x00\x00\x00\x00\x48\x85",
									"xxxx?xxxxxx????xx",
									&CHooking::get_ped_group_index);

	//clone_ped
	setFn<fpClonePed>(				"clone_ped",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x30\x33\xDB\x41\x8A\xF1",
									"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
									&CHooking::clone_ped);

	//network_shop_begin_service
	setFn<fpNetworkShopBeginService>(	"network_shop_begin_service",
										"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x50\x45\x8B\xF1",
										"xxxx?xxxx?xxxx?xxxxxxxxxxxx",
										&CHooking::network_shop_begin_service);

	//network_shop_checkout_start
	setFn<fpNetworkShopCheckoutStart>(	"network_shop_checkout_start",
										"\x40\x53\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x84\xC0\x75\x06",
										"xxxxxxxxx????xxxx",
										&CHooking::network_shop_checkout_start);

	//stat_set_int
	setFn<fpStatSetInt>(			"stat_set_int",
									"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x89\x54\x24\x10\x55\x57\x41\x57",
									"xxxx?xxxx?xxxxxxxx",
									&CHooking::stat_set_int);

	//stat_set_float
	setFn<fpStatSetFloat>(			"stat_set_float",
									"\x48\x89\x5C\x24\x00\xF3\x0F\x11\x4C\x24\x00\x57\x48\x83\xEC\x40",
									"xxxx?xxxxx?xxxxx",
									&CHooking::stat_set_float);

	//stat_set_bool
	setFn<fpStatSetBool>(			"stat_set_bool",
									"\x48\x89\x5C\x24\x00\x88\x54\x24\x10\x57\x48\x83\xEC\x40",
									"xxxx?xxxxxxxxx",
									&CHooking::stat_set_bool);

	//stat_set_date
	setFn<fpStatSetDate>(			"stat_set_date",
									"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x60\x48\x8B\xDA\x8B\xF9",
									"xxxx?xxxx?xxxxxxxxxx",
									&CHooking::stat_set_date);

	//stat_get_int
	setFn<fpStatGetInt>(			"stat_get_int",
									"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x57\x48\x83\xEC\x30\x48\x8B\xF2",
									"xxxxxxxxxxxxxxxxxxx",
									&CHooking::stat_get_int);

	//give_delayed_weapon_to_ped
	setFn<fpGiveDelayedWeaponToPed>(	"give_delayed_weapon_to_ped",
										"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x41\x8A\xE9\x41\x8B\xF0\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x63",
										"xxxx?xxxx?xxxx?xxxxxxxxxxxxxx????xxxxxxxx",
										&CHooking::give_delayed_weapon_to_ped);

	//remove_all_ped_weapons
	setFn<fpRemoveAllPedWeapons>(	"remove_all_ped_weapons",
									"\x48\x83\xEC\x28\x8B\x05\x00\x00\x00\x00\x89\x05\x00\x00\x00\x00\xE8",
									"xxxxxx????xx????x",
									&CHooking::remove_all_ped_weapons);

	//remove_weapon_from_ped
	setFn<fpRemoveWeaponFromPed>(	"remove_weapon_from_ped",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xFA\xE8\x00\x00\x00\x00\x33\xDB",
									"xxxx?xxxxxxxx????xx",
									&CHooking::remove_weapon_from_ped);

	//set_mobile_radio
	setFn<fpSetMobileRadio>(		"set_mobile_radio",
									"\x40\x53\x48\x83\xEC\x20\x8A\xD9\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8B\xD0\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x10",
									"xxxxxxxxxxx????x????xxx????xxx????xxxxx",
									&CHooking::set_mobile_radio);

	//get_player_radio_station_index
	setFn<fpGetPlayerRadioStationIndex>(	"get_player_radio_station_index",
											"\x48\x83\xEC\x28\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0C",
											"xxxxxxx????x????xxxxx",
											&CHooking::get_player_radio_station_index);

	//get_radio_station_name
	setFn<fpGetRadioStationName>(	"get_radio_station_name",
									"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0D\x48\x8B\x80",
									"xxxxx????xxxxxxxx",
									&CHooking::get_radio_station_name);

	//network_has_control_of_entity
	setFn<fpNetworkHasControlOfEntity>(	"network_has_control_of_entity",
										"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1F\x48\x8B\x88\x00\x00\x00\x00\x48\x85\xC9\x74\x0F",
										"xxxxx????xxxxxxxx????xxxxx",
										&CHooking::network_has_control_of_entity);

	//add_owned_explosion
	setFn<fpAddOwnedExplosion>(		"add_owned_explosion",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x70\x20\x55\x48\x8D\x68\xB9\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x41\x8B\xF0",
									"xxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxx",
									&CHooking::add_owned_explosion);

	//network_request_control_of_entity
	setFn<fpNetworkHasControlOfEntity>(	"network_request_control_of_entity",
										"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x84\xC0",
										"xxxx?xxxxxxxx????xx",
										&CHooking::network_request_control_of_entity);

	//network_request_control_of_entity
	setFn<fpNetworkGetNetworkIdFromEntity>(	"network_get_network_id_from_entity",
											"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x33\xDB\x48\x8B\xF8\x48\x85\xC0\x74\x16",
											"xxxx?xxxxxx????xxxxxxxxxx",
											&CHooking::network_get_network_id_from_entity);

	//network_has_control_of_network_id
	setFn<fpNetworkHasControlOfNetworkId>(	"network_has_control_of_network_id",
											"\x40\x53\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x8B\xD3\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1F",
											"xxxxxxxxx????xxxxxx????xxxxx",
											&CHooking::network_has_control_of_network_id);

	//network_request_control_of_network_id
	setFn<fpNetworkRequestControlOfNetworkId>(	"network_request_control_of_network_id",
												"\x40\x53\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x8B\xD3\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x2C",
												"xxxxxxxxx????xxxxxx????xxxxx",
												&CHooking::network_request_control_of_network_id);

	//set_network_id_can_migrate
	setFn<fpSetNetworkIdCanMigrate>(	"set_network_id_can_migrate",
										"\x85\xC9\x0F\x8E\x00\x00\x00\x00\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8A\xDA",
										"xxxx????xxxx?xxxxxxx",
										&CHooking::set_network_id_can_migrate);

	//network_create_synchronised_scene
	setFn<fpNetworkCreateSynchronisedScene>(	"network_create_synchronised_scene",
												"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x48\x8D\x68\xC1",
												"xxxxxxxxxxxxxxxxxxxx",
												&CHooking::network_create_synchronised_scene);

	//network_add_ped_to_synchronised_scene
	setFn<fpNetworkAddPedToSynchronisedScene>(	"network_add_ped_to_synchronised_scene",
												"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x50\x49\x8B\xD9",
												"xxxx?xxxx?xxxxxxxx",
												&CHooking::network_add_ped_to_synchronised_scene);

	//network_start_synchronised_scene
	setFn<fpNetworkStartSynchronisedScene>(	"network_start_synchronised_scene",
											"\x40\x53\x48\x81\xEC\x00\x00\x00\x00\x8B\xD9\x44\x8B\xC1\x48\x8D\x15\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\xE8\x00\x00\x00\x00\x85\xDB\x78\x12",
											"xxxxx????xxxxxxxx????xxxx?x????xxxx",
											&CHooking::network_start_synchronised_scene);

	//clear_ped_tasks_immediately
	setFn<fpClearPedTasksImmediately>(	"clear_ped_tasks_immediately",
										"\x40\x53\x48\x83\xEC\x30\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x0F\x84",
										"xxxxxxx????xxxxxxxx",
										&CHooking::clear_ped_tasks_immediately);

	//set_entity_visible
	setFn<fpSetEntityVisible>(		"set_entity_visible",
									"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF0\x40\x8A\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8",
									"xxxx?xxxx?xxxxxxxxxxxx????xxx",
									&CHooking::set_entity_visible);

	//set_ped_as_group_member
	setFn<fpSetPedAsGroupMember>(	"set_ped_as_group_member",
									"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x48\x8B\xF8\xE8",
									"xxxx?xxxx?xxxx?xxxxxxxx????xxxx",
									&CHooking::set_ped_as_group_member);

	//is_ped_group_member
	setFn<fpIsPedGroupMember>(		"is_ped_group_member",
									"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\xFA\xE8\x00\x00\x00\x00\x33\xDB\x48\x8B\xF0\x48\x85\xC0\x74\x63",
									"xxxx?xxxx?xxxxxxxx????xxxxxxxxxx",
									&CHooking::is_ped_group_member);

	//set_ped_gravity
	setFn<fpSetPedGravity>(			"set_ped_gravity",
									"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8A\xDA\x75\x2E",
									"xxxxxxxx?????xxxx",
									&CHooking::set_ped_gravity);

	//set_entity_has_gravity
	setFn<fpSetEntityHasGravity>(	"set_entity_has_gravity",
									"\x40\x53\x48\x83\xEC\x20\x8A\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x19\x48\x8B\x48\x30",
									"xxxxxxxxx????xxxxxxxxx",
									&CHooking::set_entity_has_gravity);

	//is_vehicle_drivable
	setFn<fpIsVehicleDrivable>(		"is_vehicle_drivable",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x36",
									"xxxx?xxxxxxxxx????xxxxxxxx",
									&CHooking::is_vehicle_drivable);

	//is_model_a_heli
	setFn<fpIsModelAHeli>(			"is_model_a_heli",
									"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1E\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x12\x83\xB9\x00\x00\x00\x00\x08",
									"xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxxx????x",
									&CHooking::is_model_a_heli);

	//is_model_a_plane
	setFn<fpIsModelAPlane>(			"is_model_a_plane",
									"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1D\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x11\xBA",
									"xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxx",
									&CHooking::is_model_a_plane);

	//is_model_a_car
	setFn<fpIsModelAPlane>(			"is_model_a_car",
									"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1D\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x11\x8B\x81",
									"xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxxx",
									&CHooking::is_model_a_car);


	//is_model_a_boat
	//\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1E\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x12\x83\xB9\x00\x00\x00\x00\x00\x0F\xB6\xDB\xBA\x00\x00\x00\x00\x0F\x44\xDA xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxxx?????xxxx????xxx

	//is_model_an_emergency_boat
	//\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x29 xxxxxxxxxx?xxxxx?????x????xxxxxxxx

	//is_model_a_train
	//\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1E\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x12\x83\xB9\x00\x00\x00\x00\x0E xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxxx????x

	//is_model_a_bike
	//\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x22 xxxxxxxxxx?xxxxx?????x????xxxxxxxx

	//is_model_a_bicycle
	//\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1E\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x12\x83\xB9\x00\x00\x00\x00\x0C xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxxx????x

	//is_model_a_quadbike
	//\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x25 xxxxxxxxxx?xxxxx?????x????xxxxxxxx

	//set_heli_blades_full_speed
	setFn<fpSetHeliBladesFullSpeed>(	"set_heli_blades_full_speed",
										"\x40\x53\x48\x83\xEC\x30\x0F\x29\x74\x24\x00\x0F\x28\xF1\x0F\x2F\x35",
										"xxxxxxxxxx?xxxxxx",
										&CHooking::set_heli_blades_full_speed);

	//set_vehicle_forward_speed
	setFn<fpSetVehicleForwardSpeed>(	"set_vehicle_forward_speed",
										"\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x48\x8B\xD9\x0F\x28\xF1\xE8\x00\x00\x00\x00\x48\x8B\x03",
										"xxxxxxxxxx?xxxxxxx????xxx",
										&CHooking::set_vehicle_forward_speed);

	//set_vehicle_number_plate_text
	setFn<fpSetVehicleNumberPlateText>(	"set_vehicle_number_plate_text",
										"\x40\x53\x48\x83\xEC\x20\x48\x8B\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x10\x48\x8B\x48\x48",
										"xxxxxxxxxx????xxxxxxxxx",
										&CHooking::set_vehicle_number_plate_text);

	//set_ped_to_ragdoll
	setFn<fpSetPedToRagdoll>(		"set_ped_to_ragdoll",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x50\x41\x8B\xF9",
									"xxxxxxxxxxxxxxxxxxxxxxxxxxxx",
									&CHooking::set_ped_to_ragdoll);

	//get_ped_bone_coords
	setFn<fpGetPedBoneCoords>(		"get_ped_bone_coords",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x48\x8D\x68\xA1\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x0F\x29\x78\xD8\x44\x0F\x29\x40\x00\x0F\x57\xF6",
									"xxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxxxxx?xxx",
									&CHooking::get_ped_bone_coords);

	//set_entity_as_mission_entity
	setFn<fpSetEntityAsMissionEntity>(	"set_entity_as_mission_entity",
										"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x54\x41\x56\x41\x57\x48\x81\xEC\x00\x00\x00\x00\x45\x8A\xE0",
										"xxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxx",
										&CHooking::set_entity_as_mission_entity);

	//apply_force_to_entity
	setFn<fpApplyForceToEntity>(	"apply_force_to_entity",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x20\x55\x41\x54\x41\x56\x48\x8D\x6C\x24",
									"xxxxxxxxxxxxxxxxxxxxxxxx",
									&CHooking::apply_force_to_entity);

	//set_entity_rotation
	setFn<fpSetEntityRotation>(		"set_entity_rotation",
									"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8D\x6C\x24\x00\x48\x81\xEC\x00\x00\x00\x00\xF3\x0F\x10\x02",
									"xxxx?xxxx?xxxxx?xxx????xxxx",
									&CHooking::set_entity_rotation);

	//set_entity_heading
	setFn<fpSetEntityHeading>(		"set_entity_heading",
									"\x48\x89\x5C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x70\x0F\x29\x74\x24\x00\x0F\x28\xF1",
									"xxxx?xxxxxxxxxxxx?xxx",
									&CHooking::set_entity_heading);

	//freeze_entity_position
	setFn<fpFreezeEntityPosition>(	"freeze_entity_position",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x20\x40\x8A\xF2\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x69",
									"xxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxx",
									&CHooking::freeze_entity_position);

	//shoot_single_bullet_between_coords
	setFn<fpShootSingleBulletBetweenCoords>(	"shoot_single_bullet_between_coords",
												"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x48\x8D\xA8\x00\x00\x00\x00\x48\x81\xEC\x00\x00\x00\x00\xF3\x0F\x10\x01\xF3\x0F\x10\x49\x00\xF3\x0F\x10\x51",
												"xxxxxxxxxxxxxxxxxxx????xxx????xxxxxxxx?xxxx",
												&CHooking::shoot_single_bullet_between_coords);

	//set_ped_never_leaves_group
	setFn<fpSetPedNeverLeavesGroup>(	"set_ped_never_leaves_group",
										"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8A\xDA\x75\x21\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x17\x0F\xB6\xCB\xF7\xD9\x33\x88\x00\x00\x00\x00\x81\xE1\x00\x00\x00\x00\x31\x88\x00\x00\x00\x00\x48\x83\xC4\x20\x5B\xC3\x48\x8B\xC4",
										"xxxxxxxx?????xxxxx????xxxxxxxxxxxx????xx????xx????xxxxxxxxx",
										&CHooking::set_ped_never_leaves_group);

	//set_group_formation
	setFn<fpSetGroupFormation>(		"set_group_formation",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xFA\x8B\xD9\xE8\x00\x00\x00\x00\x48\x8B\xC8\x8B\xD3\xE8\x00\x00\x00\x00\x85\xC0",
									"xxxx?xxxxxxxxxx????xxxxxx????xx",
									&CHooking::set_group_formation);

	//get_ped_bone_index
	setFn<fpGetPedBoneIndex>(		"get_ped_bone_index",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xFA\x83\xCB\xFF",
									"xxxx?xxxxxxxxxx",
									&CHooking::get_ped_bone_index);

	//set_ped_component_variation
	setFn<fpSetPedComponentVariation>(	"set_ped_component_variation",
										"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x50\x41\x8B\xF9",
										"xxxx?xxxx?xxxx?xxxxxxxx",
										&CHooking::set_ped_component_variation);

	//clear_add_ped_props
	setFn<fpClearAllPedProps>(		"clear_add_ped_props",
									"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x23\x48\x8B\xC8\xE8\x00\x00\x00\x00\x8B\x8B",
									"xxxxxxx????xxxxxxxxxxxx????xx",
									&CHooking::clear_add_ped_props);

	//set_ped_prop_index
	setFn<fpSetPedPropIndex>(		"set_ped_prop_index",
									"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x50\x41\x8B\xE9",
									"xxxx?xxxx?xxxx?xxxxxxxx",
									&CHooking::set_ped_prop_index);

	//is_entity_in_air
	setFn<fpIsEntityInAir>(			"is_entity_in_air",
									"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x80\x78\x28\x04",
									"xxxxxxx????xxxxxxxx????xxxx",
									&CHooking::is_entity_in_air);

	//set_entity_velocity
	setFn<fpSetEntityVelocity>(		"set_entity_velocity",
									"\x48\x8B\xC4\x48\x83\xEC\x38\xF3\x0F\x10\x02\xF3\x0F\x10\x4A\x00\xF3\x0F\x10\x52\x00\xF3\x0F\x11\x40\x00\xF3\x0F\x11\x48\x00\xF3\x0F\x11\x50\x00\xF3\x0F\x10\x44\x24\x00\xF3\x0F\x11\x40\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x12",
									"xxxxxxxxxxxxxxx?xxxx?xxxx?xxxx?xxxx?xxxxx?xxxx?x????xxxxx",
									&CHooking::set_entity_velocity);

	//get_entity_attached_to
	setFn<fpGetEntityAttachedTo>(	"get_entity_attached_to",
									"\x40\x53\x48\x83\xEC\x20\x33\xDB\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x17",
									"xxxxxxxxx????xxxxx",
									&CHooking::get_entity_attached_to);

	//detach_entity
	setFn<fpDetachEntity>(			"detach_entity",
									"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF0\x40\x8A\xEA\xE8",
									"xxxx?xxxx?xxxx?xxxxxxxxxxxx",
									&CHooking::detach_entity);

	//delete_entity
	setFn<fpDeleteEntity>(			"delete_entity",
									"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xF1\x8B\x09\xE8\x00\x00\x00\x00\x48\x8B\xF8\x48\x85\xC0\x74\x56",
									"xxxx?xxxx?xxxxxxxxxxx????xxxxxxxx",
									&CHooking::delete_entity);

	//is_entity_attached
	setFn<fpIsEntityAttached>(		"is_entity_attached",
									"\x40\x53\x48\x83\xEC\x20\x32\xDB\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x37",
									"xxxxxxxxx????xxxxxxxx",
									&CHooking::is_entity_attached);

	//set_vehicle_as_no_longer_needed
	setFn<fpSetEntityAsNoLongerNeeded>(	"set_entity_as_no_longer_needed",
										"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xF1\x8B\x09\xE8\x00\x00\x00\x00\x48\x8B\xF8\x48\x85\xC0\x74\x77",
										"xxxx?xxxx?xxxxxxxxxxx????xxxxxxxx",
										&CHooking::set_entity_as_no_longer_needed);

	//get_entity_velocity
	setFn<fpGetEntityVelocity>(		"get_entity_velocity",
									"\x40\x53\x48\x83\xEC\x50\x0F\x29\x74\x24\x00\xF3\x0F\x10\x35\x00\x00\x00\x00\x48\x8B\xD9\x0F\x29\x7C\x24\x00\xF3\x0F\x10\x3D\x00\x00\x00\x00\x8B\xCA\x44\x0F\x29\x44\x24\x00\xF3\x44\x0F\x10\x05\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x28",
									"xxxxxxxxxx?xxxx????xxxxxxx?xxxx????xxxxxxx?xxxxx????x????xxxxx",
									&CHooking::get_entity_velocity);

	//get_entity_rotation
	setFn<fpGetEntityRotation>(		"get_entity_rotation",
									"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x70\xF3\x0F\x10\x05",
									"xxxx?xxxx?xxxxxxxxxxxx",
									&CHooking::get_entity_rotation);

	//get_entity_model
	setFn<fpGetEntityModel>(		"get_entity_model",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x33\xFF\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x58",
									"xxxx?xxxxxxxx????xxxxx",
									&CHooking::get_entity_model);

	//set_vehicle_on_ground_properly
	setFn<fpSetVehicleOnGroundProperly>(	"set_vehicle_on_ground_properly",
											"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x0F\x29\x74\x24\x00\x0F\x28\xF1\xE8\x00\x00\x00\x00\x48\x8B\xD8",
											"xxxx?xxxxxxxxx?xxxx????xxx",
											&CHooking::set_vehicle_on_ground_properly);

	//set_vehicle_undriveable
	setFn<fpSetVehicleUndriveable>(	"set_vehicle_undriveable",
									"\x40\x53\x48\x83\xEC\x20\x8A\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x20\x84\xDB",
									"xxxxxxxxx????xxxxxxx",
									&CHooking::set_vehicle_undriveable);

	//set_vehicle_fixed
	setFn<fpSetVehicleFixed>(		"set_vehicle_fixed",
									"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x28\x4C\x8B\x10",
									"xxxxxxx????xxxxxxxxxxx",
									&CHooking::set_vehicle_fixed);

	//set_vehicle_deformation_fixed
	setFn<fpSetVehicleDeformationFixed>(	"set_vehicle_deformation_fixed",
											"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x40\x48\x83\xB9\x00\x00\x00\x00\x00\x48\x8B\xD9",
											"xxxx?xxxxxxxx?????xxx",
											&CHooking::set_vehicle_deformation_fixed);

	//is_vehicle_seat_free
	setFn<fpIsVehicleSeatFree>(		"is_vehicle_seat_free",
									"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x20\x45\x8A\xF8",
									"xxxx?xxxx?xxxx?xxxxxxxxxxxx",
									&CHooking::is_vehicle_seat_free);

	//set_vehicle_mod_kit
	setFn<fpSetVehicleModKit>(		"set_vehicle_mod_kit",
									"\x40\x53\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x27",
									"xxxxxxxxx????xxxxx",
									&CHooking::set_vehicle_mod_kit);

	//set_vehicle_number_plate_index
	setFn<fpSetVehicleNumberPlateIndex>(	"set_vehicle_number_plate_index",
											"\x83\xFA\xFF\x0F\x8C\x00\x00\x00\x00\x48\x8B",
											"xxxxx????xx",
											&CHooking::set_vehicle_number_plate_index);

	//toggle_vehicle_mod
	setFn<fpToggleVehicleMod>(		"toggle_vehicle_mod",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF8\x8B\xDA\x83\xFA\x0A",
									"xxxx?xxxxxxxxxxxxx",
									&CHooking::toggle_vehicle_mod);

	//set_vehicle_mod
	setFn<fpSetVehicleMod>(			"set_vehicle_mod",
									"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x56\x57\x41\x56\x48\x83\xEC\x30\x41\x8A\xE9",
									"xxxx?xxxx?xxxxxxxxxxx",
									&CHooking::set_vehicle_mod);

	//set_vehicle_wheel_type
	setFn<fpSetVehicleWheelType>(	"set_vehicle_wheel_type",
									"\x40\x53\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x4C\x8B\xC0",
									"xxxxxxxxx????xxx",
									&CHooking::set_vehicle_wheel_type);

	//get_num_vehicle_mod
	setFn<fpGetNumVehicleMod>(		"get_num_vehicle_mod",
									"\x40\x53\x48\x83\xEC\x20\x8B\xDA\x83\xFA\x0A\x7E\x10\x8D\x42\xF5\x83\xF8\x0D\x77\x05\x83\xC3\x19\xEB\x03\x83\xEB\x0E\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x2C",
									"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxx",
									&CHooking::get_num_vehicle_mod);

	//add_text_comp_substr_playername
	setFn<fpAddTextCompSubstrPlayerName>(	"add_text_comp_substr_playername",
											"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x05\x00\x00\x00\x00\x4C\x8B\xD1",
											"xxxx?xxxx?xxxx?xxxxxxx????xxx",
											&CHooking::add_text_comp_substr_playername);

	//end_text_cmd_display_text
	setFn<fpEndTextCmdDisplayText>(	"end_text_cmd_display_text",
									"\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x0F\x29\x7C\x24\x00\x41\x8B\xD8",
									"xxxxxxxxxx?xxxx?xxx",
									&CHooking::end_text_cmd_display_text);

	//begin_text_cmd_display_text
	setFn<fpBeginTextCmdDisplayText>(	"begin_text_cmd_display_text",
										"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0",
										"xxxxx????x????xxxxx",
										&CHooking::begin_text_cmd_display_text);

	//draw_notification
	setFn<fpDrawNotification>(		"draw_notification",
									"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x81\xEC\x00\x00\x00\x00\x83\x3D\x00\x00\x00\x00\x00\x41\x8A\xD8",
									"xxxx?xxxx?xxxx????xx?????xxx",
									&CHooking::draw_notification);

	//set_weather_type_now_persist
	setFn<fpSetWeatherTypeNowPersist>(	"set_weather_type_now_persist",
										"\x48\x83\xEC\x28\x48\x8B\xD1\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x85\xC0\x78\x1C",
										"xxxxxxxxxx????x????xxxx",
										&CHooking::set_weather_type_now_persist);

	//display_onscreen_keyboard
	setFn<fpDisplayOnscreenKeyboard>(	"display_onscreen_keyboard",
										"\x4C\x8B\xDC\x48\x83\xEC\x68\x8B\x84\x24",
										"xxxxxxxxxx",
										&CHooking::display_onscreen_keyboard);

	//set_local_player_visible_locally
	setFn<fpSetLocalPlayerVisibleLocally>(	"set_local_player_visible_locally",
											"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xF9\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x6D",
											"xxxx?xxxxxxxxx????xxxxxxxx",
											&CHooking::set_local_player_visible_locally);

	//network_override_clock_time
	setFn<fpNetworkOverrideClockTime>(	"network_override_clock_time",
										"\x80\x3D\x00\x00\x00\x00\x00\x75\x37\x8B\x05\x00\x00\x00\x00\xC6",
										"xx?????xxxx????x",
										&CHooking::network_override_clock_time);

	//get_network_time
	setFn<fpGetNetworkTime>(		"get_network_time",
									"\x40\x53\x48\x83\xEC\x20\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x74\x19",
									"xxxxxxxxx????x????xxxx",
									&CHooking::get_network_time);

	//ai_task_wander_standard
	setFn<fpAiTaskWanderStandard>(	"ai_task_wander_standard",
									"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x60\x0F\x28\xC1",
									"xxxx?xxxx?xxxxxxxx",
									&CHooking::ai_task_wander_standard);

	//ai_task_play_anim
	setFn<fpAiTaskPlayAnim>(		"ai_task_play_anim",
									"\x48\x81\xEC\x00\x00\x00\x00\x44\x8B\x8C\x24",
									"xxx????xxxx",
									&CHooking::ai_task_play_anim);

	//is_model_in_cdimage
	setFn<fpIsModelInCdimage>(		"is_model_in_cdimage",
									"\x48\x83\xEC\x28\x8B\x44\x24\x38\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x25\x00\x00\x00\x00\x89\x44\x24\x38\xE8\x00\x00\x00\x00\x0F\xB7\x44\x24\x00\x66\x89\x44\x24\x00\x8B\x44\x24\x38\x0D\x00\x00\x00\x00\x0F\xBA\xF0\x1C\x89\x44\x24\x38",
									"xxxxxxxxxxxx?xxx?????x????x????xxxxx????xxxx?xxxx?xxxxx????xxxxxxxx",
									&CHooking::is_model_in_cdimage);

	//is_model_valid
	setFn<fpIsModelValid>(			"is_model_valid",
									"\x48\x83\xEC\x28\x8B\x44\x24\x38\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x25\x00\x00\x00\x00\x89\x44\x24\x38\xE8\x00\x00\x00\x00\x0F\xB7\x44\x24\x00\x66\x89\x44\x24\x00\x8B\x44\x24\x38\x0D\x00\x00\x00\x00\x0F\xBA\xF0\x1C\x0F\xB7\xC8",
									"xxxxxxxxxxxx?xxx?????x????x????xxxxx????xxxx?xxxx?xxxxx????xxxxxxx",
									&CHooking::is_model_valid);

	//is_model_a_vehicle
	setFn<fpIsModelAVehicle>(		"is_model_a_vehicle",
									"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0",
									"xxxxxxxxxx?xxxxx?????x????xxx",
									&CHooking::is_model_a_vehicle);

	//request_model
	setFn<fpRequestModel>(			"request_model",
									"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x50\x8B\x45\x18",
									"xxxx?xxxx?xxxxxxxxxxx",
									&CHooking::request_model);

	//has_model_loaded
	setFn<fpHasModelLoaded>(		"has_model_loaded",
									"\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x20\x8B\x45\x18\xBF",
									"xxxx?xxxxxxxxxxxx",
									&CHooking::has_model_loaded);

	//request_anim_dict
	setFn<fpRequestAnimDict>(		"request_anim_dict",
									"\x48\x83\xEC\x58\x48\x8B\xD1\x33\xC9",
									"xxxxxxxxx",
									&CHooking::request_anim_dict);

	//has_anim_dict_loaded
	setFn<fpHasAnimDictLoaded>(		"has_anim_dict_loaded",
									"\x48\x83\xEC\x28\x48\x8B\xD1\x33\xC9\xE8\x00\x00\x00\x00\x48\x8D\x54\x24\x00\x48\x8D\x4C\x24\x00\x89\x44\x24\x40",
									"xxxxxxxxxx????xxxx?xxxx?xxxx",
									&CHooking::has_anim_dict_loaded);

	//decor_register
	setFn<fpDecorRegister>(			"decor_register",
									"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8B\xDA\x75\x29",
									"xxxxxxxx?????xxxx",
									&CHooking::decor_register);

	//decor_set_int
	setFn<fpDecorSetInt>(			"decor_set_int",
									"\x48\x89\x5C\x24\x00\x44\x89\x44\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x22\x48\x8B\xD7\x33\xC9\xE8\x00\x00\x00\x00\x4C\x8D\x44\x24\x00\x48\x8D\x54\x24\x00\x48\x8B\xCB\x89\x44\x24\x48\xE8\x00\x00\x00\x00\xB0\x01",
									"xxxx?xxxx?xxxxxxxxx????xxxxxxxxxxxxxx????xxxx?xxxx?xxxxxxxx????xx",
									&CHooking::decor_set_int);

	//create_ambient_pickup
	setFn<fpCreateAmbientDrop>(		"create_ambient_pickup",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x60\x80\x3D",
									"xxxxxxxxxxxxxxxxxxxxxxxxxxx",
									&CHooking::create_ambient_pickup);

	//is_player_free_aiming
	setFn<fpIsPlayerFreeAiming>(	"is_player_free_aiming",
									"\x48\x83\xEC\x28\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x14\x48\x8B\x80\x00\x00\x00\x00\x0F\xB6\x80",
									"xxxxxxx????xxxxxxxx????xxx",
									&CHooking::is_player_free_aiming);

	//get_ped_last_weapon_impact
	setFn<fpGetPedLastWeaponImpactCoord>(	"get_ped_last_weapon_impact",
											"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x33\xDB\x48\x8B\xFA\x48\x89\x5A\x04",
											"xxxx?xxxxxxxxxxxxxx",
											&CHooking::get_ped_last_weapon_impact);

	//start_ray_cast
	setFn<fpStartRayCast>(			"start_ray_cast",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x70\x20\x55\x48\x8D\xA8\x00\x00\x00\x00\x48\x81\xEC\x00\x00\x00\x00\x33\xDB\x45\x8B\xF0\x48\x8B\xFA\x48\x8B\xF1\x8B\xC3\x45\x85\xC9\x74\x08\x41\x8B\xC9\xE8\x00\x00\x00\x00\xF3\x0F\x10\x1F",
									"xxxxxxxxxxxxxxxxxxxxxxx????xxx????xxxxxxxxxxxxxxxxxxxxxx????xxxx",
									&CHooking::start_ray_cast);

	//get_ray_cast
	setFn<fpGetRayCast>(			"get_ray_cast",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x41\x56\x41\x57\x48\x8D\x68\xB1\x48\x81\xEC\x00\x00\x00\x00\x33\xDB",
									"xxxxxxxxxxxxxxxxxxxxxxxxxxx????xx",
									&CHooking::get_ray_cast);

	//ptr_to_handle
	setFn<fpPtrToHandle>(			"ptr_to_handle",
									"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x15\x00\x00\x00\x00\x48\x8B\xF9\x48\x83\xC1\x10\x33\xDB",
									"xxxx?xxxx?xxxxxxx????xxxxxxxxx",
									&CHooking::ptr_to_handle);

	//network_set_in_spectator_mode
	setFn<fpNetworkSetInSpectatorMode>(	"network_set_in_spectator_mode",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF8\x84\xC9",
									"xxxx?xxxxxxxxxx",
									&CHooking::network_set_in_spectator_mode);

	//set_ped_combat_ability
	setFn<fpSetPedCombatAbility>(	"set_ped_combat_ability",
									"\x48\x81\xC1\x00\x00\x00\x00\x41\xB8\x00\x00\x00\x00\x48\x8B\x01\x48\x85\xC0\x74\x06",
									"xxx????xx????xxxxxxxx",
									&CHooking::set_ped_combat_ability);

	//ai_task_combat_ped
	setFn<fpAiTaskCombatPed>(		"ai_task_combat_ped",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x30\x8B\xF9",
									"xxxxxxxxxxxxxxxxxxxxxxxxxxx",
									&CHooking::ai_task_combat_ped);

	//trigger_script_event
	setFn<fpTriggerScriptEvent>(	"trigger_script_event",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF0\x41\x8B\xF9",
									"xxxxxxxxxxxxxxxxxxxxxxxx????xxxxxx",
									&CHooking::trigger_script_event);

	//apply_vehicle_colors
	setFn<fpApplyVehicleColors>(	"apply_vehicle_colors",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\x41\x48\x48\x8B\xD9\x40\x8A\xFA",
									"xxxx?xxxxxxxxxxxxxxx",
									&CHooking::apply_vehicle_colors);

	//set_ped_relationship_group_hash
	setFn<fpSetPedRelationshipGroupHash>(	"set_ped_relationship_group_hash",
											"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x8B\xF2\xE8",
											"xxxx?xxxx?xxxxxxxx",
											&CHooking::set_ped_relationship_group_hash);

	//set_ped_relationship_group_hash
	setFn<fpSetPlayerVisibleLocally>(	"set_player_visible_locally",
										"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xFA\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0D\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\xD8\xEB\x02\x33\xDB\x48\x85\xDB\x74\x64",
										"xxxx?xxxxxxxxxxx????xxxxxxxxx????xxxxxxxxxxxx",
										&CHooking::set_player_visible_locally);

	//set_model_as_no_longer_needed
	setFn<fpSetModelAsNoLongerNeeded>(	"set_model_as_no_longer_needed",
										"\x40\x53\x48\x83\xEC\x30\x48\x8D\x54\x24\x00\x8B\xD9",
										"xxxxxxxxxx?xx",
										&CHooking::set_model_as_no_longer_needed);

	//set_radio_to_station_name
	setFn<fpSetRadioToStationName>(	"set_radio_to_station_name",
									"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xFA\x48\x8B\xD9\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\xCF\xE8\x00\x00\x00\x00\x85\xC0\x75\x43",
									"xxxx?xxxxxxxxxxxxxx????xxxx????xxxx",
									&CHooking::set_radio_to_station_name);

	//set_vehicle_engine_on
	setFn<fpSetVehicleEngineOn>(	"set_vehicle_engine_on",
									"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xE9\x41\x8A\xF8",
									"xxxx?xxxx?xxxx?xxxxxxxxxxx",
									&CHooking::set_vehicle_engine_on);

	//attach_entity_to_entity
	setFn<fpAttachEntityToEntity>(	"attach_entity_to_entity",
									"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x57\x48\x81\xEC\x00\x00\x00\x00\xF3\x41\x0F\x10\x01",
									"xxxxxxxxxxxxxxx????xxxxx",
									&CHooking::attach_entity_to_entity);

	//set_entity_collision
	setFn<fpSetEntityCollision>(	"set_entity_collision",
									"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF1\x41\x8A\xE8\x40\x8A\xFA",
									"xxxx?xxxx?xxxx?xxxxxxxxxxxxxx",
									&CHooking::set_entity_collision);

	if(!steam)
	{
		//is_player_online
		setFn<fpIsPlayerOnline>(	"IS_PLAYER_ONLINE",
									"\xE9\x00\x00\x00\x00\xC3\xCC\x48\x8B\xC4",		//"\x33\xC0\x38\x05\x00\x00\x00\x00\x0F\x95\xC0\xC3\x33\xC0"
									"x????xxxxx",									//"xxxx????xxxxxx"
									&CHooking::IS_PLAYER_ONLINE);

		//update_onscreen_keyboard
		setFn<fpUpdateOnscreenKeyboard>(	"update_onscreen_keyboard",
											"\x40\x53\x48\x83\xEC\x30\x48\x8B\x0D\x00\x00\x00\x00\x8B\x99",
											"xxxxxxxxx????xx",
											&CHooking::update_onscreen_keyboard);

		//add_explosion
		setFn<fpAddExplosion>(	"add_explosion",
								"\xE9\x00\x00\x00\x00\x8B\x85\x00\x00\x00\x00\xA8\x40\x48\x8D\x64\x24\x00\x48\x89\x2C\x24\x48\xBD\x00\x00\x00\x00\x00\x00\x00\x00\x48\x87\x2C\x24\x48\x89\x4C\x24",
								"x????xx????xxxxxx?xxxxxx????????xxxxxxxx",
								&CHooking::add_explosion);

		//set_notification_text_entry
		setFn<fpSetNotificationTextEntiry>(	"set_notification_text_entry",
											"\x40\x53\x48\x83\xEC\x20\x83\x3D\x00\x00\x00\x00\x00\x48\x8B\xD9\x75\x16\xC7\x05\x00\x00\x00\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x1D\x00\x00\x00\x00\x48\x83\xC4\x20\x5B\xC3\x90\x48\x48\x83\xEC\x28",
											"xxxxxxxx?????xxxxxxx????????x????xxx????xxxxxxxxxxxx",
											&CHooking::set_notification_text_entry);
	}
	else
	{
		//is_player_online
		setFn<fpIsPlayerOnline>(	"IS_PLAYER_ONLINE",
									"\xE9\x00\x00\x00\x00\xC3\xE9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x90\xE9\x00\x00\x00\x00\x39\x80\x9C\x3E\xD9\x70",		//"\x33\xC0\x38\x05\x00\x00\x00\x00\x0F\x95\xC0\xC3\x33\xC0"
									"x????xx????x????xx????xxxxxx",									//"xxxx????xxxxxx"
									&CHooking::IS_PLAYER_ONLINE);

		//update_onscreen_keyboard
		setFn<fpUpdateOnscreenKeyboard>(	"update_onscreen_keyboard",
											"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x33\xDB\x38\x1D",
											"xxxx?xxxxxxxxx",
											&CHooking::update_onscreen_keyboard);

		//add_explosion
		setFn<fpAddExplosion>(	"add_explosion",
								"\xE9\x00\x00\x00\x00\x48\x8B\x45\x60\x48\x8B\x00\xE9\x00\x00\x00\x00\x48\x89\x6C\x24",
								"x????xxxxxxxx????xxxx",
								&CHooking::add_explosion);

		//set_notification_text_entry
		setFn<fpSetNotificationTextEntiry>(	"set_notification_text_entry",
											"\x40\x53\x48\x83\xEC\x20\x83\x3D\x00\x00\x00\x00\x00\x48\x8B\xD9\x75\x16\xC7\x05\x00\x00\x00\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x1D\x00\x00\x00\x00\x48\x83\xC4\x20\x5B\xC3\xCC\x69\x48\x83\xEC\x28\x80\x3D",
											"xxxxxxxx?????xxxxxxx????????x????xxx????xxxxxxxxxxxxxx",
											&CHooking::set_notification_text_entry);
	}





	//model bypass
	CPattern pattern_modelCheck		(	"\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50",
										"xxxxx????xxx");
	ptr	= pattern_modelCheck.find(0).get(0).get<char>(0);
	ptr == nullptr ? CLog::error("Failed to find online model requests bypass pattern")				: mem_nop(ptr, 24);

	CPattern pattern_modelSpawn		(	"\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05\x48",
										"xxxxxxxxxxx");
	ptr	= pattern_modelSpawn.find(0).get(0).get<char>(8);
	ptr == nullptr ? CLog::error("Failed to find is player model allowed to spawn bypass pattern")	: mem_nop(ptr, 2);


	//hash table
	CPattern pattern_obj_table		(	"\x01\x00\x00\x08\x43\x7f\x2e\x27\x00\x00\xFF\x0F\x00",
										"xxxxxxxxxxxxx");
	ptr	= pattern_obj_table.virtual_find(1).get(0).get<char>(4);
	ptr == nullptr ?	killProcess("Failed to find object hash table pattern")		: CHooking::m_objectHashTable	= (void*)	ptr;
	CHooking::m_objectHashTableSectionEnd	= pattern_obj_table.get(0).section_end<void>();



	//event pointers
	CPattern pattern_eventHook		(	"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\x4C\x8D\x0D\x00\x00\x00\x00\x4C\x8D\x05\x00\x00\x00\x00\xBA\x03",
										"xxxxx????xxx????xxx????xxx????xx");
	ptr	= pattern_eventHook.find(0).get(0).get<char>(0);
	if(ptr == nullptr)
		killProcess("Failed to find event hook pattern");

	//find events
	for(uint32_t i = 0, match = 0, found = 0; found < REVENT_END; ++ptr)
	{
		if(*ptr != pattern_event[i])
			goto LABEL_RESET;

		if(++match < 3)
		{
			++i;
			continue;
		}

		++ptr;
		g_eventPtr[found]	= (void*) (ptr + *(int32_t*) ptr + 4);
		++found;

	LABEL_RESET:
		i	= match	= 0;
	}

	CloseHandle(steam);
}
