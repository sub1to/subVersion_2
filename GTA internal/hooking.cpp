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
CRITICAL_SECTION		CHooking::m_critSec;
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


fpIsPlayerOnline					CHooking::is_player_online;
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
fpSetPedCanSwitchWeapon				CHooking::set_ped_can_switch_weapon;
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
fpGetPedDrawableVariation			CHooking::get_ped_drawable_varation;
fpGetPedTextureVariation			CHooking::get_ped_texture_variation;
fpGetPedPaletteVariation			CHooking::get_ped_palette_variation;
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

	InitializeCriticalSection(&m_critSec);
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
	ownedExplosionBypass(true);

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
	ownedExplosionBypass(false);
	antiCheatBypass(false);
	CLog::msg("Cleaning up hooks");
	for(int i = 0; i < m_hooks.size(); i++)
		if(MH_DisableHook(m_hooks[i]) != MH_OK && MH_RemoveHook(m_hooks[i]) != MH_OK)
			CLog::error("Failed to unhook %p", (void*) m_hooks[i]);
	MH_Uninitialize();
	DeleteCriticalSection(&m_critSec);
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
	//CHooking::defuseEvent(REVENT_REPORT_MYSELF_EVENT, b);
	//CHooking::defuseEvent(REVENT_REPORT_CASH_SPAWN_EVENT, b);
}

fpIsPlayerPlaying	OG_IS_PLAYER_PLAYING	= nullptr;
BOOL __cdecl HK_IS_PLAYER_PLAYING(Player player)
{
	if(TryEnterCriticalSection(&CHooking::m_critSec))
	{
		static uint64_t	last = 0;
		uint64_t		cur = *CHooking::m_frameCount;
		if (last != cur)
		{
			last = cur;
			CHooking::onTick();
		}
		LeaveCriticalSection(&CHooking::m_critSec);
	}
	return OG_IS_PLAYER_PLAYING(player);
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
	MH_STATUS status = MH_CreateHook(CHooking::is_player_playing, HK_IS_PLAYER_PLAYING, (void**) &OG_IS_PLAYER_PLAYING);
	if((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(CHooking::is_player_playing) != MH_OK)
		return false;
	CHooking::m_hooks.push_back(CHooking::is_player_playing);

	//status = MH_CreateHook(CHooking::trigger_script_event, HK_TRIGGER_SCRIPT_EVENT, (void**) &OG_TRIGGER_SCRIPT_EVENT);
	//if((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(CHooking::trigger_script_event) != MH_OK)
	//	return false;
	//CHooking::m_hooks.push_back(CHooking::trigger_script_event);

	return true;
}

void findPatterns()
{
	char*	ptr			= nullptr;
	constexpr char	pattern_event[]	= "\x4C\x8D\x05";

	//game state
	CPattern pattern_gameState		(	"\x83\x3D\x00\x00\x00\x00\x00\x8A\xD9\x74\x0A",
										"xx?????xxxx");
	ptr	= pattern_gameState.find(0).get(0).get<char>(2);
	ptr == nullptr ?	killProcess("Failed find game state pattern")				: CHooking::m_gameState			= (eGameState*)				(ptr + *(int32_t*) ptr + 5);

	//world
	CPattern pattern_world			(	"\x48\x8B\x05\x00\x00\x00\x00\x4C\x8B\x68\x08\x4C\x89\xAD\xD8\x03\x00\x00\x4D\x85\xED\x0F\x84\x93\x04\x00\x00\x8D\x4B\x0F\x48\x8D",
										"xxx????xxxxxxxxxxxxxxxxxxxxxxxxx");
	ptr	= pattern_world.find(0).get(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find world pattern")					: CHack::m_pCWorld				= ((CWorld_Wrap*)			(ptr + *(int32_t*) ptr + 4))->CWorld;

	//blips
	CPattern pattern_blip			(	"\x4C\x8D\x05\x00\x00\x00\x00\x0F\xB7\xC1",
										"xxx????xxx");
	ptr	= pattern_blip.find(0).get(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find blip pattern")					: CHooking::m_blipList			= (CBlipList*)				(ptr + *(int32_t*) ptr + 4);

	//replay interface
	CPattern pattern_replay			(	"\x48\x8D\x0D\x00\x00\x00\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8A\xD8\xE8\x00\x00\x00\x00\x84\xDB\x75\x13\x48\x8D\x0D\x00\x00\x00\x00",
										"xxx????xxxx????xxx????xxx????xxxxxxx????");
	ptr	= pattern_replay.find(0).get(0).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find replay interface pattern")		: CHooking::m_replayIntf		= *(CReplayInterface**)		(ptr + *(int32_t*) ptr + 4);

	//global
	CPattern pattern_global			(	"\x4C\x8D\x05\x00\x00\x00\x00\x4D\x8B\x08\x4D\x85\xC9\x74\x11",
										"xxx????xxxxxxxx");
	ptr	= pattern_global.find(0).get(0).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find global pattern")				: CHooking::m_globalBase		= (__int64**)				(ptr + *(int32_t*) ptr + 4);

	//player list
	CPattern pattern_playerList		(	"\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\xCF",
										"xxx????x????xxxx????xxx");
	ptr	= pattern_playerList.find(1).get(0).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find player list pattern")			: CHack::m_pCPlayers			= (CPlayers*)				(ptr + *(int32_t*) ptr + 4);

	//entity pool
	CPattern pattern_entityPool		(	"\x4C\x8B\x0D\x00\x00\x00\x00\x44\x8B\xC1\x49\x8B\x41\x08",
										"xxx????xxxxxxx");
	ptr	= pattern_entityPool.find(1).get(0).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find entity pool pattern")			: CHooking::m_entityPool		= (MemoryPool**)			(ptr + *(int32_t*) ptr + 4);

	//ped pool
	CPattern pattern_pedPool		(	"\x48\x8B\x05\x00\x00\x00\x00\x41\x0F\xBF\xC8\x0F\xBF\x40\x10",
										"xxx????xxxxxxxx");
	ptr	= pattern_pedPool.find(1).get(0).get<char>(3);
	ptr	== nullptr ?	killProcess("Failed to find ped pool pattern")				: CHooking::m_pedPool			= (MemoryPool**)			(ptr + *(int32_t*) ptr + 4);

	//inf ammo
	CPattern pattern_ammo			(	"\x41\x2B\xD1\xE8",
										"xxxx");
	ptr	= pattern_ammo.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find infinite ammo pattern")			: CHooking::m_infAmmo			= (threeBytes*)				ptr;

	//no reload
	CPattern pattern_magazine		(	"\x41\x2B\xC9\x3B\xC8\x0F",
										"xxxxxx");
	ptr	= pattern_magazine.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find no reload pattern")				: CHooking::m_noReload			= (threeBytes*)				ptr;

	//viewport
	CPattern pattern_viewport		(	"\x48\x8B\x15\x00\x00\x00\x00\x48\x8D\x2D\x00\x00\x00\x00\x48\x8B\xCD",
										"xxx????xxx????xxx");
	ptr	= pattern_viewport.find(1).get(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find viewport pattern")				: CHooking::m_viewPort			= *(CViewPort**)			(ptr + *(int32_t*) ptr + 4);

	//resolution
	CPattern pattern_resolution		(	"\x8B\x0D\x00\x00\x00\x00\x49\x8D\x56\x28",
										"xx????xxxx");
	ptr	= pattern_resolution.find(1).get(0).get<char>(2);
	ptr == nullptr ?	killProcess("Failed to find resolution pattern")			: CHooking::m_resolution		= (screenReso*)				(ptr + *(int32_t*) ptr + 4);

	//hash table
	CPattern pattern_obj_table		(	"\x01\x00\x00\x08\x43\x7f\x2e\x27\x00\x00\xFF\x0F\x00",
										"xxxxxxxxxxxxx");
	ptr	= pattern_obj_table.virtual_find(1).get(0).get<char>(4);
	ptr == nullptr ?	killProcess("Failed to find object hash table pattern")		: CHooking::m_objectHashTable	= (void*)					ptr;
	CHooking::m_objectHashTableSectionEnd	= pattern_obj_table.get(0).section_end<void>();

	//player name
	CPattern pattern_online_name	(	"\x48\x8B\x05\x00\x00\x00\x00\xC3\x8A\xD1",
										"xxx????xxx");
	ptr	= pattern_online_name.find(1).get(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find name changer pattern")			: CHooking::m_onlineName		= *(void**)					(ptr + *(int32_t*) ptr + 4);

	//owned explosion bypass
	CPattern pattern_owned_explosion_bypass		(	"\x3B\xD8\x0F\x94\xC3",
													"xxxxx");
	ptr	= pattern_owned_explosion_bypass.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find owned explosion bypass pattern"): CHooking::m_ownedExplosionBypass	= (twoBytes*)			ptr;

	//frame count
	CPattern pattern_frame_count	(	"\x8B\x15\x00\x00\x00\x00\x41\xFF\xCF",
										"xx????xxx");
	ptr	= pattern_frame_count.find(1).get(0).get<char>(2);
	ptr == nullptr ?	killProcess("Failed to find frame count pattern")			: CHooking::m_frameCount		= (uint64_t*)				(ptr + *(int32_t*) ptr + 4);

	//text color
	CPattern pattern_text_info	(	"\x48\x8D\x05\x00\x00\x00\x00\x48\x89\x44\x24\x00\x8B\x05\x00\x00\x00\x00\x89\x44\x24\x28",
										"xxx????xxxx?xx????xxxx");
	ptr	= pattern_text_info.find(1).get(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find text info pattern")				: CHooking::m_textInfo		= (CTextInfo*)				(ptr + *(int32_t*) ptr + 4);

	//onscreen keyboard result
	CPattern pattern_keyboard_result	(	"\x48\x8D\x0D\x00\x00\x00\x00\x41\x3B\xC0",
											"xxx????xxx");
	ptr	= pattern_keyboard_result.find(1).get(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find onscreen keyboard result pattern")	: CHooking::m_onscreenKeyboardResult	= (char*)				(ptr + *(int32_t*) ptr + 4);

	//clock time
	CPattern pattern_clock_time	(	"\x48\x8D\x0D\x00\x00\x00\x00\x8B\xFA\xE8\x00\x00\x00\x00\x44\x8D\x0C\x5B",
									"xxx????xxx????xxxx");
	ptr	= pattern_clock_time.find(1).get(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find clock time pattern")	: CHooking::m_clockTime	= (clockTime*)				(ptr + *(int32_t*) ptr + 4);

	//network time
	CPattern pattern_network_time	(	"\x8B\x0D\x00\x00\x00\x00\x3B\xCB\x0F\x47\xCB",
										"xx????xxxxx");
	ptr	= pattern_network_time.find(1).get(0).get<char>(2);
	ptr == nullptr ?	killProcess("Failed to find network time pattern")	: CHooking::m_networkTime	= (uint64_t*)			(ptr + *(int32_t*) ptr + 4);

	//game info (p0 for set_radio_to_station_name)
	CPattern pattern_game_info	(	"\x48\x8D\x0D\x00\x00\x00\x00\x41\xB0\x01\x33\xD2\x88\x1D",
										"xxx????xxxxxxx");
	ptr	= pattern_game_info.find(1).get(0).get<char>(3);
	ptr == nullptr ?	killProcess("Failed to find game info pattern")	: CHooking::m_gameInfo	= (void*)						(ptr + *(int32_t*) ptr + 4);



	/*
		//functions
	*/
	//is_player_online
	CPattern pattern_is_player_online	(	"\x33\xC0\x38\x05\x00\x00\x00\x00\x0F\x95\xC0\xC3\x33\xC0",
											"xxxx????xxxxxx");
	ptr	= pattern_is_player_online.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_player_online pattern")			: CHooking::is_player_online	= (fpIsPlayerOnline)	ptr;

	//is_player_playing
	CPattern pattern_is_player_playing	(	"\x48\x83\xEC\x28\x33\xD2\xE8\x00\x00\x00\x00\x48\x85\xC0",
											"xxxxxxx????xxx");
	ptr	= pattern_is_player_playing.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_player_playing pattern")			: CHooking::is_player_playing	= (fpIsPlayerPlaying)		ptr;

	//player_id
	CPattern pattern_player_id			(	"\x48\x83\xEC\x28\x80\x3D\x00\x00\x00\x00\x00\x74\x12\x48\x8B\x0D\x00\x00\x00\x00\xE8",
											"xxxxxx?????xxxxx????x");
	ptr	= pattern_player_id.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find player_id pattern")					: CHooking::player_id			= (fpPlayerId)				ptr;

	//get_player_ped
	CPattern pattern_get_player_ped		(	"\x40\x53\x48\x83\xEC\x20\x33\xDB\x83\xF9\xFF\x74\x09\xB2\x01\xE8\x00\x00\x00\x00\xEB\x16",
											"xxxxxxxxxxxxxxxx????xx");
	ptr	= pattern_get_player_ped.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_player_ped pattern")			: CHooking::get_player_ped		= (fpGetPlayerPed)			ptr;

	//get_player_team
	CPattern pattern_get_player_team	(	"\x48\x83\xEC\x28\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0C\x48\x8B\xC8\x48\x83\xC4\x28\xE9\x00\x00\x00\x00\x83\xC8\xFF",
											"xxxxxxx????xxxxxxxxxxxxx????xxx");
	ptr	= pattern_get_player_team.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_player_team pattern")			: CHooking::get_player_team		= (fpGetPlayerTeam)			ptr;

	//get_vehicle_ped_is_using
	CPattern pattern_get_vehicle_ped_is_using	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xF9\x33\xDB\xE8\x00\x00\x00\x00\x48\x8B\xD0",
													"xxxx?xxxxxxxxxx????xxx");
	ptr	= pattern_get_vehicle_ped_is_using.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_vehicle_ped_is_using pattern")	: CHooking::get_vehicle_ped_is_using	= (fpGetVehiclePedIsUsing)	ptr;

	//get_ped_in_vehicle_seat
	CPattern pattern_get_ped_in_vehicle_seat	(	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xE8\x8D\x72\x01",
													"xxxx?xxxx?xxxx?xxxxxxxxxxx");
	ptr	= pattern_get_ped_in_vehicle_seat.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_ped_in_vehicle_seat pattern")	: CHooking::get_ped_in_vehicle_seat		= (fpGetPedInVehicleSeat)	ptr;

	//is_aim_cam_active
	CPattern pattern_is_aim_cam_active	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x33\xD2\x48\x8B\xC8\x48\x8B\xF8",
											"xxxx?xxxxxx????xxxxxxxx");
	ptr	= pattern_is_aim_cam_active.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_aim_cam_active pattern")			: CHooking::is_aim_cam_active	= (fpIsAimCamActive)		ptr;

	//get_entity_player_is_free_aiming_at
	CPattern pattern_get_entity_player_is_free_aiming_at	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xFA\xB2\x01\x33\xDB\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x3F",
																"xxxx?xxxxxxxxxxxxx????xxxxx");
	ptr	= pattern_get_entity_player_is_free_aiming_at.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_entity_player_is_free_aiming_at pattern")	: CHooking::get_entity_player_is_free_aiming_at	= (fpGetEntityPlayerIsFreeAimingAt)	ptr;

	//network_is_session_started
	CPattern pattern_network_is_session_started	(	"\x48\x8B\x0D\x00\x00\x00\x00\x33\xC0\x48\x85\xC9\x74\x0E\x83\xB9\x00\x00\x00\x00\x00\x75\x05",
													"xxx????xxxxxxxxx?????xx");
	ptr	= pattern_network_is_session_started.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_is_session_started pattern")	: CHooking::network_is_session_started	= (fpNetworkIsSessionStarted)	ptr;

	//get_entity_speed
	CPattern pattern_get_entity_speed	(	"\x48\x83\xEC\x38\x0F\x29\x74\x24\x00\x0F\x57\xF6\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x3E",
											"xxxxxxxx?xxxx????xxxxx");
	ptr	= pattern_get_entity_speed.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_entity_speed pattern")			: CHooking::get_entity_speed	= (fpGetEntitySpeed)	ptr;

	//get_player_name
	CPattern pattern_get_player_name	(	"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8B\xD9\x74\x22",
											"xxxxxxxx?????xxxx");
	ptr	= pattern_get_player_name.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_player_name pattern")			: CHooking::get_player_name	= (fpGetPlayerName)	ptr;

	//draw_rect
	CPattern pattern_draw_rect	(	"\x48\x8B\xC4\x48\x89\x58\x08\x57\x48\x83\xEC\x70\x48\x63\x0D\x00\x00\x00\x00\x0F",
									"xxxxxxxxxxxxxxx????x");
	ptr	= pattern_draw_rect.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find draw_rect pattern")					: CHooking::draw_rect	= (fpDrawRect)	ptr;

	//draw_line
	CPattern pattern_draw_line	(	"\x40\x53\x48\x83\xEC\x40\xF3\x0F\x10\x09\xF3\x0F\x10\x41\x00\xF3\x0F\x10\x51\x00\x45\x8B\xD0\xBB",
									"xxxxxxxxxxxxxx?xxxx?xxxx");
	ptr	= pattern_draw_line.find(2).get(1).get<char>(0);	//first one is draw_box
	ptr == nullptr ?	killProcess("Failed to find draw_line pattern")					: CHooking::draw_line	= (fpDrawLine)	ptr;

	//get_ground_z_for_3d_coord
	CPattern pattern_get_ground_z_for_3d_coord	(	"\x4C\x8B\xDC\x49\x89\x5B\x10\x49\x89\x7B\x20",
													"xxxxxxxxxxx");
	ptr	= pattern_get_ground_z_for_3d_coord.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_ground_z_for_3d_coord pattern")	: CHooking::get_ground_z_for_3d_coord	= (fpGetGroundZFor3dCoord)	ptr;

	//create_vehicle
	CPattern pattern_create_vehicle	(	"\x48\x89\x5C\x24\x00\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x50\xF3\x0F\x10\x02",
										"xxxx?xxxxxxxxxxxxxxxxxxxxxx");
	ptr	= pattern_create_vehicle.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find create_vehicle pattern")			: CHooking::create_vehicle	= (fpCreateVehicle)	ptr;

	//set_entity_coords_no_offset
	CPattern pattern_set_entity_coords_no_offset	(	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x57\x48\x81\xEC\x00\x00\x00\x00\xF3\x0F\x10\x15",
														"xxxxxxxxxxxxxxx????xxxx");
	ptr	= pattern_set_entity_coords_no_offset.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_entity_coords_no_offset pattern")	: CHooking::set_entity_coords_no_offset	= (fpSetEntityCoordsNoOffset)	ptr;

	//get_entity_heading
	CPattern pattern_get_entity_heading	(	"\x48\x83\xEC\x38\x0F\x29\x74\x24\x00\xE8\x00\x00\x00\x00\x0F",
											"xxxxxxxx?x????x");
	ptr	= pattern_get_entity_heading.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_entity_heading pattern")			: CHooking::get_entity_heading	= (fpGetEntityHeading)	ptr;

	//get_gameplay_cam_rot
	CPattern pattern_get_gameplay_cam_rot	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x8B\xDA\x48\x8B\xF9\xE8\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\x48\x8D\x90\x00\x00\x00\x00",
											"xxxx?xxxxxxxxxxx????xxxx?xxx????");
	ptr	= pattern_get_gameplay_cam_rot.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_gameplay_cam_rot pattern")			: CHooking::get_gameplay_cam_rot	= (fpGetGameplayCamRot)	ptr;

	//get_gameplay_cam_coord
	CPattern pattern_get_gameplay_cam_coord	(	"\x40\x53\x48\x83\xEC\x20\x48\x8B\xD9\xE8\x00\x00\x00\x00\x8B\x90\x00\x00\x00\x00",
												"xxxxxxxxxx????xx????");
	ptr	= pattern_get_gameplay_cam_coord.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_gameplay_cam_coord pattern")		: CHooking::get_gameplay_cam_coord	= (fpGetGameplayCamCoord)	ptr;

	//get_player_group
	CPattern pattern_get_player_group	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x50\xB2\x01",
											"xxxx?xxxxxxx");
	ptr	= pattern_get_player_group.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_player_group pattern")	: CHooking::get_player_group	= (fpGetPlayerGroup)	ptr;

	//set_player_model
	CPattern pattern_set_player_model	(	"\x40\x55\x53\x57\x48\x8B\xEC\x48\x83\xEC\x30\x8B\xF9",
											"xxxxxxxxxxxxx");
	ptr	= pattern_set_player_model.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_player_model pattern")	: CHooking::set_player_model	= (fpSetPlayerModel)	ptr;

	//set_ped_random_component_variation
	CPattern pattern_set_ped_random_component_variation	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x40\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8",
															"xxxx?xxxxxxxx????xxx");
	ptr	= pattern_set_ped_random_component_variation.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_random_component_variation pattern")	: CHooking::set_ped_random_component_variation	= (fpSetPedRandomComponentVariatian)	ptr;

	//set_ped_default_component_variation
	CPattern pattern_set_ped_default_component_variation	(	"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x2F",
																"xxxxxxx????xxxxxxxx");
	ptr	= pattern_set_ped_default_component_variation.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_default_component_variation pattern")	: CHooking::set_ped_default_component_variation	= (fpSetPedDefaultComponentVariation)	ptr;

	//set_ped_default_component_variation
	CPattern pattern_is_ped_in_any_vehicle	(	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xFA\xE8\x00\x00\x00\x00\x32\xDB",
												"xxxx?xxxx?xxxxxxxxx????xx");
	ptr	= pattern_is_ped_in_any_vehicle.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_ped_in_any_vehicle pattern")	: CHooking::is_ped_in_any_vehicle	= (fpIsPedInAnyVehicle)	ptr;

	//create_ped
	CPattern pattern_create_ped	(	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x55\x57\x41\x56\x48\x8D\x68\xB1\x48\x81\xEC\x00\x00\x00\x00\x40\x8A\x75\x77",
									"xxxxxxxxxxxxxxxxxxxxxx????xxxx");
	ptr	= pattern_create_ped.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find create_ped pattern")			: CHooking::create_ped	= (fpCreatePed)	ptr;

	//set_ped_into_vehicle
	CPattern pattern_set_ped_into_vehicle	(	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x56\x57\x41\x56\x48\x83\xEC\x30\x41\x8B\xE8\x8B\xFA",
												"xxxx?xxxx?xxxxxxxxxxxxx");
	ptr	= pattern_set_ped_into_vehicle.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_into_vehicle pattern")	: CHooking::set_ped_into_vehicle	= (fpSetPedIntoVehicle)	ptr;

	//set_ped_config_flag
	CPattern pattern_set_ped_config_flag	(	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF0\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x53",
												"xxxx?xxxx?xxxxxxxxxxx????xxxxxxxx");
	ptr	= pattern_set_ped_config_flag.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_config_flag pattern")	: CHooking::set_ped_config_flag	= (fpSetPedConfigFlag)	ptr;

	//clear_ped_blood_damage
	CPattern pattern_clear_ped_blood_damage	(	"\x40\x53\x48\x83\xEC\x20\x8A\x91\x00\x00\x00\x00\x48\x8B\xD9\x80\xFA\xFF\x74\x51",
												"xxxxxxxx????xxxxxxxx");
	ptr	= pattern_clear_ped_blood_damage.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find clear_ped_blood_damage pattern")	: CHooking::clear_ped_blood_damage	= (fpClearPedBloodDamage)	ptr;

	//clear_ped_wetness
	CPattern pattern_clear_ped_wetness	(	"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x23\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\x8B\x00\x00\x00\x00",
											"xxxxxxx????xxxxxxxxxxxx????xxx????");
	ptr	= pattern_clear_ped_wetness.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find clear_ped_wetness pattern")	: CHooking::clear_ped_wetness	= (fpClearPedWetness)	ptr;

	//create_object
	CPattern pattern_create_object	(	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x41\x54\x41\x57\x48\x8D\x68\xD9",
										"xxxxxxxxxxxxxxxxxxxxxxxx");
	ptr	= pattern_create_object.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find create_object pattern")	: CHooking::create_object	= (fpCreateObject)	ptr;

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
	CPattern pattern_get_ped_group_index	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x50\xE8\x00\x00\x00\x00\x48\x85",
												"xxxx?xxxxxx????xx");
	ptr	= pattern_get_ped_group_index.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_ped_group_index pattern")	: CHooking::get_ped_group_index	= (fpGetPedGroupIndex)	ptr;

	//clone_ped
	CPattern pattern_clone_ped	(	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x30\x33\xDB\x41\x8A\xF1",
									"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	ptr	= pattern_clone_ped.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find clone_ped pattern")	: CHooking::clone_ped	= (fpClonePed)	ptr;

	//network_shop_begin_service
	CPattern pattern_network_shop_begin_service	(	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x50\x45\x8B\xF1",
													"xxxx?xxxx?xxxx?xxxxxxxxxxxx");
	ptr	= pattern_network_shop_begin_service.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_shop_begin_service pattern")	: CHooking::network_shop_begin_service	= (fpNetworkShopBeginService)	ptr;

	//network_shop_checkout_start
	CPattern pattern_network_shop_checkout_start	(	"\x40\x53\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x84\xC0\x75\x06",
														"xxxxxxxxx????xxxx");
	ptr	= pattern_network_shop_checkout_start.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_shop_checkout_start pattern")	: CHooking::network_shop_checkout_start	= (fpNetworkShopCheckoutStart)	ptr;

	//stat_set_int
	CPattern pattern_stat_set_int	(	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x89\x54\x24\x10\x55\x57\x41\x57",
										"xxxx?xxxx?xxxxxxxx");
	ptr	= pattern_stat_set_int.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find stat_set_int pattern")	: CHooking::stat_set_int	= (fpStatSetInt)	ptr;

	//stat_set_float
	CPattern pattern_stat_set_float	(	"\x48\x89\x5C\x24\x00\xF3\x0F\x11\x4C\x24\x00\x57\x48\x83\xEC\x40",
										"xxxx?xxxxx?xxxxx");
	ptr	= pattern_stat_set_float.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find stat_set_float pattern")	: CHooking::stat_set_float	= (fpStatSetFloat)	ptr;

	//stat_set_bool
	CPattern pattern_stat_set_bool	(	"\x48\x89\x5C\x24\x00\x88\x54\x24\x10\x57\x48\x83\xEC\x40",
										"xxxx?xxxxxxxxx");
	ptr	= pattern_stat_set_bool.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find stat_set_bool pattern")	: CHooking::stat_set_bool	= (fpStatSetBool)	ptr;

	//stat_set_date
	CPattern pattern_stat_set_date	(	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x60\x48\x8B\xDA\x8B\xF9",
										"xxxx?xxxx?xxxxxxxxxx");
	ptr	= pattern_stat_set_date.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find stat_set_date pattern")	: CHooking::stat_set_date	= (fpStatSetDate)	ptr;

	//stat_get_int
	CPattern pattern_stat_get_int	(	"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x57\x48\x83\xEC\x30\x48\x8B\xF2",
										"xxxxxxxxxxxxxxxxxxx");
	ptr	= pattern_stat_get_int.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find stat_get_int pattern")	: CHooking::stat_get_int	= (fpStatGetInt)	ptr;

	//add_explosion
	CPattern pattern_add_explosion	(	"\xE9\x00\x00\x00\x00\x8B\x85\x00\x00\x00\x00\xA8\x40\x48\x8D\x64\x24\x00\x48\x89\x2C\x24\x48\xBD\x00\x00\x00\x00\x00\x00\x00\x00\x48\x87\x2C\x24\x48\x89\x4C\x24",
										"x????xx????xxxxxx?xxxxxx????????xxxxxxxx");
	ptr	= pattern_add_explosion.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find add_explosion pattern")	: CHooking::add_explosion	= (fpAddExplosion)	ptr;

	//give_delayed_weapon_to_ped
	CPattern pattern_give_delayed_weapon_to_ped	(	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x41\x8A\xE9\x41\x8B\xF0\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x63",
													"xxxx?xxxx?xxxx?xxxxxxxxxxxxxx????xxxxxxxx");
	ptr	= pattern_give_delayed_weapon_to_ped.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find give_delayed_weapon_to_ped pattern")	: CHooking::give_delayed_weapon_to_ped	= (fpGiveDelayedWeaponToPed)	ptr;

	//remove_all_ped_weapons
	CPattern pattern_remove_all_ped_weapons	(	"\x48\x83\xEC\x28\x8B\x05\x00\x00\x00\x00\x89\x05\x00\x00\x00\x00\xE8",
												"xxxxxx????xx????x");
	ptr	= pattern_remove_all_ped_weapons.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find remove_all_ped_weapons pattern")	: CHooking::remove_all_ped_weapons	= (fpRemoveAllPedWeapons)	ptr;

	//remove_weapon_from_ped
	CPattern pattern_remove_weapon_from_ped	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xFA\xE8\x00\x00\x00\x00\x33\xDB",
												"xxxx?xxxxxxxx????xx");
	ptr	= pattern_remove_weapon_from_ped.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find remove_weapon_from_ped pattern")	: CHooking::remove_weapon_from_ped	= (fpRemoveWeaponFromPed)	ptr;

	//set_mobile_radio
	CPattern pattern_set_mobile_radio (	"\x40\x53\x48\x83\xEC\x20\x8A\xD9\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8B\xD0\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x10",
										"xxxxxxxxxxx????x????xxx????xxx????xxxxx");
	ptr	= pattern_set_mobile_radio.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_mobile_radio pattern")	: CHooking::set_mobile_radio	= (fpSetMobileRadio)	ptr;

	//get_player_radio_station_index
	CPattern pattern_get_player_radio_station_index (	"\x48\x83\xEC\x28\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0C",
														"xxxxxxx????x????xxxxx");
	ptr	= pattern_get_player_radio_station_index.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_player_radio_station_index pattern")	: CHooking::get_player_radio_station_index	= (fpGetPlayerRadioStationIndex)	ptr;

	//get_radio_station_name
	CPattern pattern_get_radio_station_name (	"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0D\x48\x8B\x80",
												"xxxxx????xxxxxxxx");
	ptr	= pattern_get_radio_station_name.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_radio_station_name pattern")	: CHooking::get_radio_station_name	= (fpGetRadioStationName)	ptr;

	//network_has_control_of_entity
	CPattern pattern_network_has_control_of_entity (	"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1F\x48\x8B\x88\x00\x00\x00\x00\x48\x85\xC9\x74\x0F",
														"xxxxx????xxxxxxxx????xxxxx");
	ptr	= pattern_network_has_control_of_entity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_has_control_of_entity pattern")	: CHooking::network_has_control_of_entity	= (fpNetworkHasControlOfEntity)	ptr;

	//add_owned_explosion
	CPattern pattern_add_owned_explosion (	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x70\x20\x55\x48\x8D\x68\xB9\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x41\x8B\xF0",
											"xxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxx");
	ptr	= pattern_add_owned_explosion.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find add_owned_explosion pattern")	: CHooking::add_owned_explosion	= (fpAddOwnedExplosion)	ptr;

	//network_request_control_of_entity
	CPattern pattern_network_request_control_of_entity (	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x84\xC0",
															"xxxx?xxxxxxxx????xx");
	ptr	= pattern_network_request_control_of_entity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_request_control_of_entity pattern")	: CHooking::network_request_control_of_entity	= (fpNetworkHasControlOfEntity)	ptr;

	//network_request_control_of_entity
	CPattern pattern_network_get_network_id_from_entity (	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x33\xDB\x48\x8B\xF8\x48\x85\xC0\x74\x16",
															"xxxx?xxxxxx????xxxxxxxxxx");
	ptr	= pattern_network_get_network_id_from_entity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_get_network_id_from_entity pattern")	: CHooking::network_get_network_id_from_entity	= (fpNetworkGetNetworkIdFromEntity)	ptr;

	//network_has_control_of_network_id
	CPattern pattern_network_has_control_of_network_id (	"\x40\x53\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x8B\xD3\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1F",
															"xxxxxxxxx????xxxxxx????xxxxx");
	ptr	= pattern_network_has_control_of_network_id.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_has_control_of_network_id pattern")	: CHooking::network_has_control_of_network_id	= (fpNetworkHasControlOfNetworkId)	ptr;

	//network_request_control_of_network_id
	CPattern pattern_network_request_control_of_network_id (	"\x40\x53\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x8B\xD3\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x2C",
																"xxxxxxxxx????xxxxxx????xxxxx");
	ptr	= pattern_network_request_control_of_network_id.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_request_control_of_network_id pattern")	: CHooking::network_request_control_of_network_id	= (fpNetworkRequestControlOfNetworkId)	ptr;

	//set_network_id_can_migrate
	CPattern pattern_set_network_id_can_migrate (	"\x85\xC9\x0F\x8E\x00\x00\x00\x00\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8A\xDA",
													"xxxx????xxxx?xxxxxxx");
	ptr	= pattern_set_network_id_can_migrate.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_network_id_can_migrate pattern")	: CHooking::set_network_id_can_migrate	= (fpSetNetworkIdCanMigrate)	ptr;

	//network_create_synchronised_scene
	CPattern pattern_network_create_synchronised_scene (	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x48\x8D\x68\xC1",
															"xxxxxxxxxxxxxxxxxxxx");
	ptr	= pattern_network_create_synchronised_scene.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_create_synchronised_scene pattern")	: CHooking::network_create_synchronised_scene	= (fpNetworkCreateSynchronisedScene)	ptr;

	//network_add_ped_to_synchronised_scene
	CPattern pattern_network_add_ped_to_synchronised_scene (	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x50\x49\x8B\xD9",
																"xxxx?xxxx?xxxxxxxx");
	ptr	= pattern_network_add_ped_to_synchronised_scene.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_add_ped_to_synchronised_scene pattern")	: CHooking::network_add_ped_to_synchronised_scene	= (fpNetworkAddPedToSynchronisedScene)	ptr;

	//network_start_synchronised_scene
	CPattern pattern_network_start_synchronised_scene (	"\x40\x53\x48\x81\xEC\x00\x00\x00\x00\x8B\xD9\x44\x8B\xC1\x48\x8D\x15\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\xE8\x00\x00\x00\x00\x85\xDB\x78\x12",
														"xxxxx????xxxxxxxx????xxxx?x????xxxx");
	ptr	= pattern_network_start_synchronised_scene.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_start_synchronised_scene pattern")	: CHooking::network_start_synchronised_scene	= (fpNetworkStartSynchronisedScene)	ptr;

	//clear_ped_tasks_immediately
	CPattern pattern_clear_ped_tasks_immediately (	"\x40\x53\x48\x83\xEC\x30\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x0F\x84",
													"xxxxxxx????xxxxxxxx");
	ptr	= pattern_clear_ped_tasks_immediately.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find clear_ped_tasks_immediately pattern")	: CHooking::clear_ped_tasks_immediately	= (fpClearPedTasksImmediately)	ptr;

	//set_entity_visible
	CPattern pattern_set_entity_visible (	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF0\x40\x8A\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8",
											"xxxx?xxxx?xxxxxxxxxxxx????xxx");
	ptr	= pattern_set_entity_visible.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_entity_visible pattern")	: CHooking::set_entity_visible	= (fpSetEntityVisible)	ptr;

	//set_ped_as_group_member
	CPattern pattern_set_ped_as_group_member (	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x48\x8B\xF8\xE8",
												"xxxx?xxxx?xxxx?xxxxxxxx????xxxx");
	ptr	= pattern_set_ped_as_group_member.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_as_group_member pattern")	: CHooking::set_ped_as_group_member	= (fpSetPedAsGroupMember)	ptr;

	//is_ped_group_member
	CPattern pattern_is_ped_group_member (	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\xFA\xE8\x00\x00\x00\x00\x33\xDB\x48\x8B\xF0\x48\x85\xC0\x74\x63",
											"xxxx?xxxx?xxxxxxxx????xxxxxxxxxx");
	ptr	= pattern_is_ped_group_member.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_ped_group_member pattern")	: CHooking::is_ped_group_member	= (fpIsPedGroupMember)	ptr;

	//set_ped_can_switch_weapon
	CPattern pattern_set_ped_can_switch_weapon (	"\x40\x53\x48\x83\xEC\x20\x8A\xDA\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0\x74\x19\x84\xDB\x0F\x94\xC1\xF7\xD9\x33\x88\x00\x00\x00\x00\x81\xE1\x00\x00\x00\x00\x31\x88\x00\x00\x00\x00\x48\x83\xC4\x20\x5B\xC3\xCC\x48\x89\x5C\x24\x00\x48\x89\x74\x24",
													"xxxxxxxxx????xxxxxxxxxxxxxxxx????xx????xx????xxxxxxxxxxx?xxxx");
	ptr	= pattern_set_ped_can_switch_weapon.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_can_switch_weapon pattern")	: CHooking::set_ped_can_switch_weapon	= (fpSetPedCanSwitchWeapon)	ptr;

	//set_ped_gravity
	CPattern pattern_set_ped_gravity (	"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8A\xDA\x75\x2E",
										"xxxxxxxx?????xxxx");
	ptr	= pattern_set_ped_gravity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_gravity pattern")	: CHooking::set_ped_gravity	= (fpSetPedGravity)	ptr;

	//set_entity_has_gravity
	CPattern pattern_set_entity_has_gravity (	"\x40\x53\x48\x83\xEC\x20\x8A\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x19\x48\x8B\x48\x30",
												"xxxxxxxxx????xxxxxxxxx");
	ptr	= pattern_set_entity_has_gravity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_entity_has_gravity pattern")	: CHooking::set_entity_has_gravity	= (fpSetEntityHasGravity)	ptr;

	//is_vehicle_drivable
	CPattern pattern_is_vehicle_drivable (	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x36",
											"xxxx?xxxxxxxxx????xxxxxxxx");
	ptr	= pattern_is_vehicle_drivable.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_vehicle_drivable pattern")	: CHooking::is_vehicle_drivable	= (fpIsVehicleDrivable)	ptr;

	//is_model_a_heli
	CPattern pattern_is_model_a_heli (	"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1E\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x12\x83\xB9\x00\x00\x00\x00\x08",
										"xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxxx????x");
	ptr	= pattern_is_model_a_heli.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_model_a_heli pattern")	: CHooking::is_model_a_heli	= (fpIsModelAHeli)	ptr;
	
	//is_model_a_plane
	CPattern pattern_is_model_a_plane (	"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1D\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x11\xBA",
										"xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxx");
	ptr	= pattern_is_model_a_plane.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_model_a_plane pattern")	: CHooking::is_model_a_plane	= (fpIsModelAPlane)	ptr;

	//is_model_a_car
	CPattern pattern_is_model_a_car (	"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1D\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x11\x8B\x81",
										"xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxxx");
	ptr	= pattern_is_model_a_car.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_model_a_car pattern")	: CHooking::is_model_a_car	= (fpIsModelAPlane)	ptr;

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
	CPattern pattern_set_heli_blades_full_speed (	"\x40\x53\x48\x83\xEC\x30\x0F\x29\x74\x24\x00\x0F\x28\xF1\x0F\x2F\x35",
													"xxxxxxxxxx?xxxxxx");
	ptr	= pattern_set_heli_blades_full_speed.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_heli_blades_full_speed pattern")	: CHooking::set_heli_blades_full_speed	= (fpSetHeliBladesFullSpeed)	ptr;

	//set_vehicle_forward_speed
	CPattern pattern_set_vehicle_forward_speed (	"\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x48\x8B\xD9\x0F\x28\xF1\xE8\x00\x00\x00\x00\x48\x8B\x03",
													"xxxxxxxxxx?xxxxxxx????xxx");
	ptr	= pattern_set_vehicle_forward_speed.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_vehicle_forward_speed pattern")	: CHooking::set_vehicle_forward_speed	= (fpSetVehicleForwardSpeed)	ptr;

	//set_vehicle_number_plate_text
	CPattern pattern_set_vehicle_number_plate_text (	"\x40\x53\x48\x83\xEC\x20\x48\x8B\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x10\x48\x8B\x48\x48",
														"xxxxxxxxxx????xxxxxxxxx");
	ptr	= pattern_set_vehicle_number_plate_text.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_vehicle_number_plate_text pattern")	: CHooking::set_vehicle_number_plate_text	= (fpSetVehicleNumberPlateText)	ptr;

	//set_ped_to_ragdoll
	CPattern pattern_set_ped_to_ragdoll (	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x50\x41\x8B\xF9",
											"xxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	ptr	= pattern_set_ped_to_ragdoll.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_to_ragdoll pattern")	: CHooking::set_ped_to_ragdoll	= (fpSetPedToRagdoll)	ptr;

	//get_ped_bone_coords
	CPattern pattern_get_ped_bone_coords (	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x48\x8D\x68\xA1\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x0F\x29\x78\xD8\x44\x0F\x29\x40\x00\x0F\x57\xF6",
											"xxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxxxxx?xxx");
	ptr	= pattern_get_ped_bone_coords.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_ped_bone_coords pattern")	: CHooking::get_ped_bone_coords	= (fpGetPedBoneCoords)	ptr;

	//set_entity_as_mission_entity
	CPattern pattern_set_entity_as_mission_entity (	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x54\x41\x56\x41\x57\x48\x81\xEC\x00\x00\x00\x00\x45\x8A\xE0",
													"xxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxx");
	ptr	= pattern_set_entity_as_mission_entity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_entity_as_mission_entity pattern")	: CHooking::set_entity_as_mission_entity	= (fpSetEntityAsMissionEntity)	ptr;

	//apply_force_to_entity
	CPattern pattern_apply_force_to_entity (	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x20\x55\x41\x54\x41\x56\x48\x8D\x6C\x24",
												"xxxxxxxxxxxxxxxxxxxxxxxx");
	ptr	= pattern_apply_force_to_entity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find apply_force_to_entity pattern")	: CHooking::apply_force_to_entity	= (fpApplyForceToEntity)	ptr;

	//set_entity_rotation
	CPattern pattern_set_entity_rotation (	"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8D\x6C\x24\x00\x48\x81\xEC\x00\x00\x00\x00\xF3\x0F\x10\x02",
											"xxxx?xxxx?xxxxx?xxx????xxxx");
	ptr	= pattern_set_entity_rotation.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_entity_rotation pattern")	: CHooking::set_entity_rotation	= (fpSetEntityRotation)	ptr;

	//set_entity_heading
	CPattern pattern_set_entity_heading (	"\x48\x89\x5C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x70\x0F\x29\x74\x24\x00\x0F\x28\xF1",
											"xxxx?xxxxxxxxxxxx?xxx");
	ptr	= pattern_set_entity_heading.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_entity_heading pattern")	: CHooking::set_entity_heading	= (fpSetEntityHeading)	ptr;

	//freeze_entity_position
	CPattern pattern_freeze_entity_position (	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x20\x40\x8A\xF2\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x69",
												"xxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxx");
	ptr	= pattern_freeze_entity_position.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find freeze_entity_position pattern")	: CHooking::freeze_entity_position	= (fpFreezeEntityPosition)	ptr;

	//shoot_single_bullet_between_coords
	CPattern pattern_shoot_single_bullet_between_coords (	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x48\x8D\xA8\x00\x00\x00\x00\x48\x81\xEC\x00\x00\x00\x00\xF3\x0F\x10\x01\xF3\x0F\x10\x49\x00\xF3\x0F\x10\x51",
															"xxxxxxxxxxxxxxxxxxx????xxx????xxxxxxxx?xxxx");
	ptr	= pattern_shoot_single_bullet_between_coords.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find shoot_single_bullet_between_coords pattern")	: CHooking::shoot_single_bullet_between_coords	= (fpShootSingleBulletBetweenCoords)	ptr;

	//set_ped_never_leaves_group
	CPattern pattern_set_ped_never_leaves_group (	"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8A\xDA\x75\x21\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x17\x0F\xB6\xCB\xF7\xD9\x33\x88\x00\x00\x00\x00\x81\xE1\x00\x00\x00\x00\x31\x88\x00\x00\x00\x00\x48\x83\xC4\x20\x5B\xC3\x48\x8B\xC4",
													"xxxxxxxx?????xxxxx????xxxxxxxxxxxx????xx????xx????xxxxxxxxx");
	ptr	= pattern_set_ped_never_leaves_group.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_never_leaves_group pattern")	: CHooking::set_ped_never_leaves_group	= (fpSetPedNeverLeavesGroup)	ptr;

	//set_group_formation
	CPattern pattern_set_group_formation (	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xFA\x8B\xD9\xE8\x00\x00\x00\x00\x48\x8B\xC8\x8B\xD3\xE8\x00\x00\x00\x00\x85\xC0",
											"xxxx?xxxxxxxxxx????xxxxxx????xx");
	ptr	= pattern_set_group_formation.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_group_formation pattern")	: CHooking::set_group_formation	= (fpSetGroupFormation)	ptr;

	//get_ped_bone_index
	CPattern pattern_get_ped_bone_index (	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xFA\x83\xCB\xFF",
											"xxxx?xxxxxxxxxx");
	ptr	= pattern_get_ped_bone_index.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_ped_bone_index pattern")	: CHooking::get_ped_bone_index	= (fpGetPedBoneIndex)	ptr;

	//set_ped_component_variation
	CPattern pattern_set_ped_component_variation (	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x50\x41\x8B\xF9",
													"xxxx?xxxx?xxxx?xxxxxxxx");
	ptr	= pattern_set_ped_component_variation.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_component_variation pattern")	: CHooking::set_ped_component_variation	= (fpSetPedComponentVariation)	ptr;

	//get_ped_drawable_varation
	CPattern pattern_get_ped_drawable_varation (	"\x40\x53\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0F\x8B\xD3\x48\x8B\xC8\xE8\x00\x00\x00\x00\x0F\xB6\xC0\xEB\x03\x83\xC8\xFF\x48\x83\xC4\x20\x5B\xC3\x90",
													"xxxxxxxxx????xxxxxxxxxxx????xxxxxxxxxxxxxxx");
	ptr	= pattern_get_ped_drawable_varation.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_ped_drawable_varation pattern")	: CHooking::get_ped_drawable_varation	= (fpGetPedDrawableVariation)	ptr;

	//get_ped_texture_variation
	CPattern pattern_get_ped_texture_variation (	"\x40\x53\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0F\x8B\xD3\x48\x8B\xC8\xE8\x00\x00\x00\x00\x0F\xB6\xC0\xEB\x03\x83\xC8\xFF\x48\x83\xC4\x20\x5B\xC3\xCC",
													"xxxxxxxxx????xxxxxxxxxxx????xxxxxxxxxxxxxxx");
	ptr	= pattern_get_ped_texture_variation.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_ped_texture_variation pattern")	: CHooking::get_ped_texture_variation	= (fpGetPedTextureVariation)	ptr;

	//get_ped_palette_variation
	CPattern pattern_get_ped_palette_variation (	"\x48\x8B\x41\x48\x48\x63\xD2\x8A\x84\x10\x00\x00\x00\x00\xC3\x90\x40\x55",
													"xxxxxxxxxx????xxxx");
	ptr	= pattern_get_ped_palette_variation.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_ped_palette_variation pattern")	: CHooking::get_ped_palette_variation	= (fpGetPedPaletteVariation)	ptr;

	//clear_add_ped_props
	CPattern pattern_clear_add_ped_props (	"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x23\x48\x8B\xC8\xE8\x00\x00\x00\x00\x8B\x8B",
											"xxxxxxx????xxxxxxxxxxxx????xx");
	ptr	= pattern_clear_add_ped_props.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find clear_add_ped_props pattern")	: CHooking::clear_add_ped_props	= (fpClearAllPedProps)	ptr;

	//set_ped_prop_index
	CPattern pattern_set_ped_prop_index (	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x50\x41\x8B\xE9",
											"xxxx?xxxx?xxxx?xxxxxxxx");
	ptr	= pattern_set_ped_prop_index.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_prop_index pattern")	: CHooking::set_ped_prop_index	= (fpSetPedPropIndex)	ptr;

	//is_entity_in_air
	CPattern pattern_is_entity_in_air (	"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x80\x78\x28\x04",
										"xxxxxxx????xxxxxxxx????xxxx");
	ptr	= pattern_is_entity_in_air.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_entity_in_air pattern")	: CHooking::is_entity_in_air	= (fpIsEntityInAir)	ptr;

	//set_entity_velocity
	CPattern pattern_set_entity_velocity (	"\x48\x8B\xC4\x48\x83\xEC\x38\xF3\x0F\x10\x02\xF3\x0F\x10\x4A\x00\xF3\x0F\x10\x52\x00\xF3\x0F\x11\x40\x00\xF3\x0F\x11\x48\x00\xF3\x0F\x11\x50\x00\xF3\x0F\x10\x44\x24\x00\xF3\x0F\x11\x40\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x12",
										"xxxxxxxxxxxxxxx?xxxx?xxxx?xxxx?xxxx?xxxxx?xxxx?x????xxxxx");
	ptr	= pattern_set_entity_velocity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_entity_velocity pattern")	: CHooking::set_entity_velocity	= (fpSetEntityVelocity)	ptr;

	//get_entity_attached_to
	CPattern pattern_get_entity_attached_to (	"\x40\x53\x48\x83\xEC\x20\x33\xDB\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x17",
												"xxxxxxxxx????xxxxx");
	ptr	= pattern_get_entity_attached_to.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_entity_attached_to pattern")	: CHooking::get_entity_attached_to	= (fpGetEntityAttachedTo)	ptr;

	//detach_entity
	CPattern pattern_detach_entity (	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF0\x40\x8A\xEA\xE8",
										"xxxx?xxxx?xxxx?xxxxxxxxxxxx");
	ptr	= pattern_detach_entity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find detach_entity pattern")	: CHooking::detach_entity	= (fpDetachEntity)	ptr;

	//delete_entity
	CPattern pattern_delete_entity (	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xF1\x8B\x09\xE8\x00\x00\x00\x00\x48\x8B\xF8\x48\x85\xC0\x74\x56",
										"xxxx?xxxx?xxxxxxxxxxx????xxxxxxxx");
	ptr	= pattern_delete_entity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find delete_entity pattern")	: CHooking::delete_entity	= (fpDeleteEntity)	ptr;

	//is_entity_attached
	CPattern pattern_is_entity_attached (	"\x40\x53\x48\x83\xEC\x20\x32\xDB\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x37",
											"xxxxxxxxx????xxxxxxxx");
	ptr	= pattern_is_entity_attached.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_entity_attached pattern")	: CHooking::is_entity_attached	= (fpIsEntityAttached)	ptr;

	//set_vehicle_as_no_longer_needed
	CPattern pattern_set_entity_as_no_longer_needed (	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xF1\x8B\x09\xE8\x00\x00\x00\x00\x48\x8B\xF8\x48\x85\xC0\x74\x77",
														"xxxx?xxxx?xxxxxxxxxxx????xxxxxxxx");
	ptr	= pattern_set_entity_as_no_longer_needed.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_entity_as_no_longer_needed pattern")	: CHooking::set_entity_as_no_longer_needed	= (fpSetEntityAsNoLongerNeeded)	ptr;

	//get_entity_velocity
	CPattern pattern_get_entity_velocity (	"\x40\x53\x48\x83\xEC\x50\x0F\x29\x74\x24\x00\xF3\x0F\x10\x35\x00\x00\x00\x00\x48\x8B\xD9\x0F\x29\x7C\x24\x00\xF3\x0F\x10\x3D\x00\x00\x00\x00\x8B\xCA\x44\x0F\x29\x44\x24\x00\xF3\x44\x0F\x10\x05\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x28",
											"xxxxxxxxxx?xxxx????xxxxxxx?xxxx????xxxxxxx?xxxxx????x????xxxxx");
	ptr	= pattern_get_entity_velocity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_entity_velocity pattern")	: CHooking::get_entity_velocity	= (fpGetEntityVelocity)	ptr;

	//get_entity_rotation
	CPattern pattern_get_entity_rotation (	"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x70\xF3\x0F\x10\x05",
											"xxxx?xxxx?xxxxxxxxxxxx");
	ptr	= pattern_get_entity_rotation.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_entity_rotation pattern")	: CHooking::get_entity_rotation	= (fpGetEntityRotation)	ptr;

	//get_entity_model
	CPattern pattern_get_entity_model (	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x33\xFF\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x58",
										"xxxx?xxxxxxxx????xxxxx");
	ptr	= pattern_get_entity_model.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_entity_model pattern")	: CHooking::get_entity_model	= (fpGetEntityModel)	ptr;

	//set_vehicle_on_ground_properly
	CPattern pattern_set_vehicle_on_ground_properly (	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x0F\x29\x74\x24\x00\x0F\x28\xF1\xE8\x00\x00\x00\x00\x48\x8B\xD8",
														"xxxx?xxxxxxxxx?xxxx????xxx");
	ptr	= pattern_set_vehicle_on_ground_properly.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_vehicle_on_ground_properly pattern")	: CHooking::set_vehicle_on_ground_properly	= (fpSetVehicleOnGroundProperly)	ptr;

	//set_vehicle_undriveable
	CPattern pattern_set_vehicle_undriveable (	"\x40\x53\x48\x83\xEC\x20\x8A\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x20\x84\xDB",
												"xxxxxxxxx????xxxxxxx");
	ptr	= pattern_set_vehicle_undriveable.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_vehicle_undriveable pattern")	: CHooking::set_vehicle_undriveable	= (fpSetVehicleUndriveable)	ptr;

	//set_vehicle_fixed
	CPattern pattern_set_vehicle_fixed (	"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x28\x4C\x8B\x10",
											"xxxxxxx????xxxxxxxxxxx");
	ptr	= pattern_set_vehicle_fixed.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_vehicle_fixed pattern")	: CHooking::set_vehicle_fixed	= (fpSetVehicleFixed)	ptr;

	//set_vehicle_deformation_fixed
	CPattern pattern_set_vehicle_deformation_fixed (	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x40\x48\x83\xB9\x00\x00\x00\x00\x00\x48\x8B\xD9",
														"xxxx?xxxxxxxx?????xxx");
	ptr	= pattern_set_vehicle_deformation_fixed.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_vehicle_deformation_fixed pattern")	: CHooking::set_vehicle_deformation_fixed	= (fpSetVehicleDeformationFixed)	ptr;

	//is_vehicle_seat_free
	CPattern pattern_is_vehicle_seat_free (	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x20\x45\x8A\xF8",
											"xxxx?xxxx?xxxx?xxxxxxxxxxxx");
	ptr	= pattern_is_vehicle_seat_free.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_vehicle_seat_free pattern")	: CHooking::is_vehicle_seat_free	= (fpIsVehicleSeatFree)	ptr;

	//set_vehicle_mod_kit
	CPattern pattern_set_vehicle_mod_kit (	"\x40\x53\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x27",
											"xxxxxxxxx????xxxxx");
	ptr	= pattern_set_vehicle_mod_kit.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_vehicle_mod_kit pattern")	: CHooking::set_vehicle_mod_kit	= (fpSetVehicleModKit)	ptr;

	//set_vehicle_number_plate_index
	CPattern pattern_set_vehicle_number_plate_index (	"\x83\xFA\xFF\x0F\x8C\x00\x00\x00\x00\x48\x8B",
														"xxxxx????xx");
	ptr	= pattern_set_vehicle_number_plate_index.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_vehicle_number_plate_index pattern")	: CHooking::set_vehicle_number_plate_index	= (fpSetVehicleNumberPlateIndex)	ptr;

	//toggle_vehicle_mod
	CPattern pattern_toggle_vehicle_mod (	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF8\x8B\xDA\x83\xFA\x0A",
											"xxxx?xxxxxxxxxxxxx");
	ptr	= pattern_toggle_vehicle_mod.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find toggle_vehicle_mod pattern")	: CHooking::toggle_vehicle_mod	= (fpToggleVehicleMod)	ptr;

	//set_vehicle_mod
	CPattern pattern_set_vehicle_mod (	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x56\x57\x41\x56\x48\x83\xEC\x30\x41\x8A\xE9",
										"xxxx?xxxx?xxxxxxxxxxx");
	ptr	= pattern_set_vehicle_mod.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_vehicle_mod pattern")	: CHooking::set_vehicle_mod	= (fpSetVehicleMod)	ptr;

	//set_vehicle_wheel_type
	CPattern pattern_set_vehicle_wheel_type (	"\x40\x53\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x4C\x8B\xC0",
												"xxxxxxxxx????xxx");
	ptr	= pattern_set_vehicle_wheel_type.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_vehicle_wheel_type pattern")	: CHooking::set_vehicle_wheel_type	= (fpSetVehicleWheelType)	ptr;

	//get_num_vehicle_mod
	CPattern pattern_get_num_vehicle_mod (	"\x40\x53\x48\x83\xEC\x20\x8B\xDA\x83\xFA\x0A\x7E\x10\x8D\x42\xF5\x83\xF8\x0D\x77\x05\x83\xC3\x19\xEB\x03\x83\xEB\x0E\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x2C",
											"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxx");
	ptr	= pattern_get_num_vehicle_mod.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_num_vehicle_mod pattern")	: CHooking::get_num_vehicle_mod	= (fpGetNumVehicleMod)	ptr;

	//add_text_comp_substr_playername
	CPattern pattern_add_text_comp_substr_playername (	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x05\x00\x00\x00\x00\x4C\x8B\xD1",
														"xxxx?xxxx?xxxx?xxxxxxx????xxx");
	ptr	= pattern_add_text_comp_substr_playername.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find add_text_comp_substr_playername pattern")	: CHooking::add_text_comp_substr_playername	= (fpAddTextCompSubstrPlayerName)	ptr;

	//end_text_cmd_display_text
	CPattern pattern_end_text_cmd_display_text (	"\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x0F\x29\x7C\x24\x00\x41\x8B\xD8",
													"xxxxxxxxxx?xxxx?xxx");
	ptr	= pattern_end_text_cmd_display_text.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find end_text_cmd_display_text pattern")	: CHooking::end_text_cmd_display_text	= (fpEndTextCmdDisplayText)	ptr;

	//begin_text_cmd_display_text
	CPattern pattern_begin_text_cmd_display_text (	"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0",
													"xxxxx????x????xxxxx");
	ptr	= pattern_begin_text_cmd_display_text.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find begin_text_cmd_display_text pattern")	: CHooking::begin_text_cmd_display_text	= (fpBeginTextCmdDisplayText)	ptr;

	//set_notification_text_entry
	CPattern pattern_set_notification_text_entry (	"\x40\x53\x48\x83\xEC\x20\x83\x3D\x00\x00\x00\x00\x00\x48\x8B\xD9\x75\x16\xC7\x05\x00\x00\x00\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x1D\x00\x00\x00\x00\x48\x83\xC4\x20\x5B\xC3\x90\x48\x48\x83\xEC\x28",
													"xxxxxxxx?????xxxxxxx????????x????xxx????xxxxxxxxxxxx");
	ptr	= pattern_set_notification_text_entry.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_notification_text_entry pattern")	: CHooking::set_notification_text_entry	= (fpSetNotificationTextEntiry)	ptr;

	//draw_notification
	CPattern pattern_draw_notification (	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x81\xEC\x00\x00\x00\x00\x83\x3D\x00\x00\x00\x00\x00\x41\x8A\xD8",
											"xxxx?xxxx?xxxx????xx?????xxx");
	ptr	= pattern_draw_notification.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find draw_notification pattern")	: CHooking::draw_notification	= (fpDrawNotification)	ptr;

	//set_weather_type_now_persist
	CPattern pattern_set_weather_type_now_persist (	"\x48\x83\xEC\x28\x48\x8B\xD1\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x85\xC0\x78\x1C",
													"xxxxxxxxxx????x????xxxx");
	ptr	= pattern_set_weather_type_now_persist.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_weather_type_now_persist pattern")	: CHooking::set_weather_type_now_persist	= (fpSetWeatherTypeNowPersist)	ptr;

	//display_onscreen_keyboard
	CPattern pattern_display_onscreen_keyboard (	"\x4C\x8B\xDC\x48\x83\xEC\x68\x8B\x84\x24",
													"xxxxxxxxxx");
	ptr	= pattern_display_onscreen_keyboard.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find display_onscreen_keyboard pattern")	: CHooking::display_onscreen_keyboard	= (fpDisplayOnscreenKeyboard)	ptr;

	//update_onscreen_keyboard
	CPattern pattern_update_onscreen_keyboard (	"\x40\x53\x48\x83\xEC\x30\x48\x8B\x0D\x00\x00\x00\x00\x8B\x99",
												"xxxxxxxxx????xx");
	ptr	= pattern_update_onscreen_keyboard.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find update_onscreen_keyboard pattern")	: CHooking::update_onscreen_keyboard	= (fpUpdateOnscreenKeyboard)	ptr;

	//set_local_player_visible_locally
	CPattern pattern_set_local_player_visible_locally (	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xF9\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x6D",
														"xxxx?xxxxxxxxx????xxxxxxxx");
	ptr	= pattern_set_local_player_visible_locally.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_local_player_visible_locally pattern")	: CHooking::set_local_player_visible_locally	= (fpSetLocalPlayerVisibleLocally)	ptr;

	//network_override_clock_time
	CPattern pattern_network_override_clock_time (	"\x80\x3D\x00\x00\x00\x00\x00\x75\x37\x8B\x05\x00\x00\x00\x00\xC6",
													"xx?????xxxx????x");
	ptr	= pattern_network_override_clock_time.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_override_clock_time pattern")	: CHooking::network_override_clock_time	= (fpNetworkOverrideClockTime)	ptr;

	//get_network_time
	CPattern pattern_get_network_time (	"\x40\x53\x48\x83\xEC\x20\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x74\x19",
										"xxxxxxxxx????x????xxxx");
	ptr	= pattern_get_network_time.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_network_time pattern")	: CHooking::get_network_time	= (fpGetNetworkTime)	ptr;

	//ai_task_wander_standard
	CPattern pattern_ai_task_wander_standard (	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x60\x0F\x28\xC1",
												"xxxx?xxxx?xxxxxxxx");
	ptr	= pattern_ai_task_wander_standard.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find ai_task_wander_standard pattern")	: CHooking::ai_task_wander_standard	= (fpAiTaskWanderStandard)	ptr;

	//ai_task_play_anim
	CPattern pattern_ai_task_play_anim (	"\x48\x81\xEC\x00\x00\x00\x00\x44\x8B\x8C\x24",
											"xxx????xxxx");
	ptr	= pattern_ai_task_play_anim.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find ai_task_play_anim pattern")	: CHooking::ai_task_play_anim	= (fpAiTaskPlayAnim)	ptr;

	//is_model_in_cdimage
	CPattern pattern_is_model_in_cdimage (	"\x48\x83\xEC\x28\x8B\x44\x24\x38\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x25\x00\x00\x00\x00\x89\x44\x24\x38\xE8\x00\x00\x00\x00\x0F\xB7\x44\x24\x00\x66\x89\x44\x24\x00\x8B\x44\x24\x38\x0D\x00\x00\x00\x00\x0F\xBA\xF0\x1C\x89\x44\x24\x38",
											"xxxxxxxxxxxx?xxx?????x????x????xxxxx????xxxx?xxxx?xxxxx????xxxxxxxx");
	ptr	= pattern_is_model_in_cdimage.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_model_in_cdimage pattern")	: CHooking::is_model_in_cdimage	= (fpIsModelInCdimage)	ptr;

	//is_model_valid
	CPattern pattern_is_model_valid (	"\x48\x83\xEC\x28\x8B\x44\x24\x38\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x25\x00\x00\x00\x00\x89\x44\x24\x38\xE8\x00\x00\x00\x00\x0F\xB7\x44\x24\x00\x66\x89\x44\x24\x00\x8B\x44\x24\x38\x0D\x00\x00\x00\x00\x0F\xBA\xF0\x1C\x0F\xB7\xC8",
										"xxxxxxxxxxxx?xxx?????x????x????xxxxx????xxxx?xxxx?xxxxx????xxxxxxx");
	ptr	= pattern_is_model_valid.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_model_valid pattern")	: CHooking::is_model_valid	= (fpIsModelValid)	ptr;

	//is_model_a_vehicle
	CPattern pattern_is_model_a_vehicle (	"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0",
											"xxxxxxxxxx?xxxxx?????x????xxx");
	ptr	= pattern_is_model_a_vehicle.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_model_a_vehicle pattern")	: CHooking::is_model_a_vehicle	= (fpIsModelAVehicle)	ptr;

	//request_model
	CPattern pattern_request_model (	"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x50\x8B\x45\x18",
										"xxxx?xxxx?xxxxxxxxxxx");
	ptr	= pattern_request_model.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find request_model pattern")	: CHooking::request_model	= (fpRequestModel)	ptr;

	//has_model_loaded
	CPattern pattern_has_model_loaded (	"\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x20\x8B\x45\x18\xBF",
										"xxxx?xxxxxxxxxxxx");
	ptr	= pattern_has_model_loaded.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find has_model_loaded pattern")	: CHooking::has_model_loaded	= (fpHasModelLoaded)	ptr;

	//request_anim_dict
	CPattern pattern_request_anim_dict (	"\x48\x83\xEC\x58\x48\x8B\xD1\x33\xC9",
											"xxxxxxxxx");
	ptr	= pattern_request_anim_dict.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find request_anim_dict pattern")	: CHooking::request_anim_dict	= (fpRequestAnimDict)	ptr;

	//has_anim_dict_loaded
	CPattern pattern_has_anim_dict_loaded (	"\x48\x83\xEC\x28\x48\x8B\xD1\x33\xC9\xE8\x00\x00\x00\x00\x48\x8D\x54\x24\x00\x48\x8D\x4C\x24\x00\x89\x44\x24\x40",
											"xxxxxxxxxx????xxxx?xxxx?xxxx");
	ptr	= pattern_has_anim_dict_loaded.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find has_anim_dict_loaded pattern")	: CHooking::has_anim_dict_loaded	= (fpHasAnimDictLoaded)	ptr;

	//decor_register
	CPattern pattern_decor_register (	"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8B\xDA\x75\x29",
										"xxxxxxxx?????xxxx");
	ptr	= pattern_decor_register.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find decor_register pattern")	: CHooking::decor_register	= (fpDecorRegister)	ptr;

	//decor_set_int
	CPattern pattern_decor_set_int (	"\x48\x89\x5C\x24\x00\x44\x89\x44\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x22\x48\x8B\xD7\x33\xC9\xE8\x00\x00\x00\x00\x4C\x8D\x44\x24\x00\x48\x8D\x54\x24\x00\x48\x8B\xCB\x89\x44\x24\x48\xE8\x00\x00\x00\x00\xB0\x01",
										"xxxx?xxxx?xxxxxxxxx????xxxxxxxxxxxxxx????xxxx?xxxx?xxxxxxxx????xx");
	ptr	= pattern_decor_set_int.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find decor_set_int pattern")	: CHooking::decor_set_int	= (fpDecorSetInt)	ptr;

	//create_ambient_pickup
	CPattern pattern_create_ambient_pickup (	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x60\x80\x3D",
												"xxxxxxxxxxxxxxxxxxxxxxxxxxx");
	ptr	= pattern_create_ambient_pickup.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find create_ambient_pickup pattern")	: CHooking::create_ambient_pickup	= (fpCreateAmbientDrop)	ptr;

	//is_player_free_aiming
	CPattern pattern_is_player_free_aiming	(	"\x48\x83\xEC\x28\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x14\x48\x8B\x80\x00\x00\x00\x00\x0F\xB6\x80",
												"xxxxxxx????xxxxxxxx????xxx");
	ptr	= pattern_is_player_free_aiming.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find is_player_free_aiming pattern")	: CHooking::is_player_free_aiming	= (fpIsPlayerFreeAiming)	ptr;

	//get_ped_last_weapon_impact
	CPattern pattern_get_ped_last_weapon_impact	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x33\xDB\x48\x8B\xFA\x48\x89\x5A\x04",
													"xxxx?xxxxxxxxxxxxxx");
	ptr	= pattern_get_ped_last_weapon_impact.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_ped_last_weapon_impact pattern")	: CHooking::get_ped_last_weapon_impact	= (fpGetPedLastWeaponImpactCoord)	ptr;

	//start_ray_cast
	CPattern pattern_start_ray_cast	(	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x70\x20\x55\x48\x8D\xA8\x00\x00\x00\x00\x48\x81\xEC\x00\x00\x00\x00\x33\xDB\x45\x8B\xF0\x48\x8B\xFA\x48\x8B\xF1\x8B\xC3\x45\x85\xC9\x74\x08\x41\x8B\xC9\xE8\x00\x00\x00\x00\xF3\x0F\x10\x1F",
										"xxxxxxxxxxxxxxxxxxxxxxx????xxx????xxxxxxxxxxxxxxxxxxxxxx????xxxx");
	ptr	= pattern_start_ray_cast.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find start_ray_cast pattern")	: CHooking::start_ray_cast	= (fpStartRayCast)	ptr;

	//get_ray_cast
	CPattern pattern_get_ray_cast	(	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x41\x56\x41\x57\x48\x8D\x68\xB1\x48\x81\xEC\x00\x00\x00\x00\x33\xDB",
										"xxxxxxxxxxxxxxxxxxxxxxxxxxx????xx");
	ptr	= pattern_get_ray_cast.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find get_ray_cast pattern")	: CHooking::get_ray_cast	= (fpGetRayCast)	ptr;

	//ptr_to_handle
	CPattern pattern_ptr_to_handle	(	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x15\x00\x00\x00\x00\x48\x8B\xF9\x48\x83\xC1\x10\x33\xDB",
										"xxxx?xxxx?xxxxxxx????xxxxxxxxx");
	ptr	= pattern_ptr_to_handle.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find ptr_to_handle pattern")	: CHooking::ptr_to_handle	= (fpPtrToHandle)	ptr;

	//network_set_in_spectator_mode
	CPattern pattern_network_set_in_spectator_mode	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF8\x84\xC9",
														"xxxx?xxxxxxxxxx");
	ptr	= pattern_network_set_in_spectator_mode.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find network_set_in_spectator_mode pattern")	: CHooking::network_set_in_spectator_mode	= (fpNetworkSetInSpectatorMode)	ptr;

	//set_ped_combat_ability
	CPattern pattern_set_ped_combat_ability	(	"\x48\x81\xC1\x00\x00\x00\x00\x41\xB8\x00\x00\x00\x00\x48\x8B\x01\x48\x85\xC0\x74\x06",
												"xxx????xx????xxxxxxxx");
	ptr	= pattern_set_ped_combat_ability.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_combat_ability pattern")	: CHooking::set_ped_combat_ability	= (fpSetPedCombatAbility)	ptr;

	//ai_task_combat_ped
	CPattern pattern_ai_task_combat_ped	(	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x30\x8B\xF9",
											"xxxxxxxxxxxxxxxxxxxxxxxxxxx");
	ptr	= pattern_ai_task_combat_ped.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find ai_task_combat_ped pattern")	: CHooking::ai_task_combat_ped	= (fpAiTaskCombatPed)	ptr;

	//trigger_script_event
	CPattern pattern_trigger_script_event	(	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF0\x41\x8B\xF9",
												"xxxxxxxxxxxxxxxxxxxxxxxx????xxxxxx");
	ptr	= pattern_trigger_script_event.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find trigger_script_event pattern")	: CHooking::trigger_script_event	= (fpTriggerScriptEvent)	ptr;

	//apply_vehicle_colors
	CPattern pattern_apply_vehicle_colors	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\x41\x48\x48\x8B\xD9\x40\x8A\xFA",
												"xxxx?xxxxxxxxxxxxxxx");
	ptr	= pattern_apply_vehicle_colors.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find apply_vehicle_colors pattern")	: CHooking::apply_vehicle_colors	= (fpApplyVehicleColors)	ptr;

	//set_ped_relationship_group_hash
	CPattern pattern_set_ped_relationship_group_hash	(	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x8B\xF2\xE8",
															"xxxx?xxxx?xxxxxxxx");
	ptr	= pattern_set_ped_relationship_group_hash.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_ped_relationship_group_hash pattern")	: CHooking::set_ped_relationship_group_hash	= (fpSetPedRelationshipGroupHash)	ptr;

	//set_ped_relationship_group_hash
	CPattern pattern_set_player_visible_locally	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xFA\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0D\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\xD8\xEB\x02\x33\xDB\x48\x85\xDB\x74\x64",
													"xxxx?xxxxxxxxxxx????xxxxxxxxx????xxxxxxxxxxxx");
	ptr	= pattern_set_player_visible_locally.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_player_visible_locally pattern")	: CHooking::set_player_visible_locally	= (fpSetPlayerVisibleLocally)	ptr;

	//set_model_as_no_longer_needed
	CPattern pattern_set_model_as_no_longer_needed	(	"\x40\x53\x48\x83\xEC\x30\x48\x8D\x54\x24\x00\x8B\xD9",
														"xxxxxxxxxx?xx");
	ptr	= pattern_set_model_as_no_longer_needed.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_model_as_no_longer_needed pattern")	: CHooking::set_model_as_no_longer_needed	= (fpSetModelAsNoLongerNeeded)	ptr;

	//set_radio_to_station_name
	CPattern pattern_set_radio_to_station_name	(	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xFA\x48\x8B\xD9\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\xCF\xE8\x00\x00\x00\x00\x85\xC0\x75\x43",
													"xxxx?xxxxxxxxxxxxxx????xxxx????xxxx");
	ptr	= pattern_set_radio_to_station_name.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_radio_to_station_name pattern")	: CHooking::set_radio_to_station_name	= (fpSetRadioToStationName)	ptr;

	//set_vehicle_engine_on
	CPattern pattern_set_vehicle_engine_on	(	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xE9\x41\x8A\xF8",
												"xxxx?xxxx?xxxx?xxxxxxxxxxx");
	ptr	= pattern_set_vehicle_engine_on.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_vehicle_engine_on pattern")	: CHooking::set_vehicle_engine_on	= (fpSetVehicleEngineOn)	ptr;

	//attach_entity_to_entity
	CPattern pattern_attach_entity_to_entity	(	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x57\x48\x81\xEC\x00\x00\x00\x00\xF3\x41\x0F\x10\x01",
													"xxxxxxxxxxxxxxx????xxxxx");
	ptr	= pattern_attach_entity_to_entity.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find attach_entity_to_entity pattern")	: CHooking::attach_entity_to_entity	= (fpAttachEntityToEntity)	ptr;

	//set_entity_collision
	CPattern pattern_set_entity_collision	(	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF1\x41\x8A\xE8\x40\x8A\xFA",
												"xxxx?xxxx?xxxx?xxxxxxxxxxxxxx");
	ptr	= pattern_set_entity_collision.find(1).get(0).get<char>(0);
	ptr == nullptr ?	killProcess("Failed to find set_entity_collision pattern")	: CHooking::set_entity_collision	= (fpSetEntityCollision)	ptr;



	//model bypass
	CPattern pattern_modelCheck		(	"\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50",
										"xxxxx????xxx");
	ptr	= pattern_modelCheck.find(0).get(0).get<char>(0);
	ptr == nullptr ? CLog::error("Failed to find online model requests bypass pattern")				: mem_nop(ptr, 24);

	CPattern pattern_modelSpawn		(	"\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05\x48",
										"xxxxxxxxxxx");
	ptr	= pattern_modelSpawn.find(0).get(0).get<char>(8);
	ptr == nullptr ? CLog::error("Failed to find is player model allowed to spawn bypass pattern")	: mem_nop(ptr, 2);


	




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
}
