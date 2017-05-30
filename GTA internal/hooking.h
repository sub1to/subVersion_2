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

#pragma once

#ifndef HOOKING_H
#define HOOKING_H

typedef BOOL	(__cdecl*	fpIsPlayerOnline)(void*);
typedef BOOL	(__cdecl*	fpIsPlayerPlaying)(Player player);
typedef Player	(__cdecl*	fpPlayerId)();
typedef Ped		(__cdecl*	fpGetPlayerPed)(Player player);
typedef int		(__cdecl*	fpGetPlayerTeam)(Player player);
typedef Vehicle	(__cdecl*	fpGetVehiclePedIsUsing)(Ped ped);
typedef Ped		(__cdecl*	fpGetPedInVehicleSeat)(Vehicle vehicle, int index);
typedef BOOL	(__cdecl*	fpIsAimCamActive)();
typedef BOOL	(__cdecl*	fpGetEntityPlayerIsFreeAimingAt)(Player player, Entity* entity);
typedef BOOL	(__cdecl*	fpNetworkIsSessionStarted)();
typedef float	(__cdecl*	fpGetEntitySpeed)(Vehicle vehicle);
typedef char*	(__cdecl*	fpGetPlayerName)(Player player);
typedef void	(__cdecl*	fpDrawRect)(float x, float y, float width, float height, int r, int g, int b, int a);
typedef void	(__cdecl*	fpDrawLine)(Vector3* pos1, Vector3* pos2, int r, int g, int b, int a);
typedef BOOL	(__cdecl*	fpGetGroundZFor3dCoord)(Vector3* pos, float* out, int64_t unk1, BOOL unk2);
typedef Vehicle	(__cdecl*	fpCreateVehicle)(Hash model, Vector3* pos, float heading, BOOL networked, BOOL unk2);
typedef void	(__cdecl*	fpSetEntityCoordsNoOffset)(Entity entity, Vector3* pos, BOOL x, BOOL y, BOOL z);
typedef float	(__cdecl*	fpGetEntityHeading)(Entity entity);
typedef Vector3*(__cdecl*	fpGetGameplayCamRot)(Vector3* out, uint32_t unk1);
typedef Vector3*(__cdecl*	fpGetGameplayCamCoord)(Vector3* out);
typedef int		(__cdecl*	fpGetPlayerGroup)(Player player);
typedef int		(__cdecl*	fpSetPlayerModel)(Player player, Hash model);
typedef int		(__cdecl*	fpSetPedRandomComponentVariatian)(Ped ped);
typedef int		(__cdecl*	fpSetPedDefaultComponentVariation)(Ped ped);
typedef bool	(__cdecl*	fpIsPedInAnyVehicle)(Ped ped, BOOL atGetIn);
typedef Ped		(__cdecl*	fpCreatePed)(int type, Hash model, Vector3* pos, float heading, bool isNetworked, bool unk1);
typedef int		(__cdecl*	fpSetPedIntoVehicle)(Ped ped, Vehicle vehicle, int seat);
typedef BOOL	(__cdecl*	fpSetPedConfigFlag)(Ped ped, int flag, bool value);
typedef int		(__cdecl*	fpClearPedBloodDamage)(CPed* ped);
typedef int		(__cdecl*	fpClearPedWetness)(Ped ped);
typedef BOOL	(__cdecl*	fpCreateObject)(Hash model, float x, float y, float z, bool offset, int unk0, int unk1, Object* out, bool isNetworked, bool unk2, bool dynamic);	//unk0 = 1; unk1 = -1
//typedef uint32_t(__cdecl*	fpGetPedNearbyVehicles)(Ped ped, int* sizeAndVehs);
//typedef uint32_t(__cdecl*	fpGetPedNearbyPeds)(Ped ped, int* sizeAndPeds, int ignore);
typedef int		(__cdecl*	fpGetPedGroupIndex)(Ped ped);
typedef Ped		(__cdecl*	fpClonePed)(Ped ped, float heading, BOOL isNetworked, BOOL unk0);
typedef BOOL	(__cdecl*	fpNetworkShopBeginService)(DWORD* transID, int p1, int p2, int p3, int p4, int p5);
typedef BOOL	(__cdecl*	fpNetworkShopCheckoutStart)(DWORD transID);
typedef BOOL	(__cdecl*	fpStatSetInt)(DWORD hash, int value, BOOL save);
typedef BOOL	(__cdecl*	fpStatSetFloat)(DWORD hash, float value, BOOL save);
typedef BOOL	(__cdecl*	fpStatSetBool)(DWORD hash, BOOL value, BOOL save);
typedef BOOL	(__cdecl*	fpStatSetDate)(DWORD hash, DWORD* value, int size, BOOL save);
typedef BOOL	(__cdecl*	fpStatGetInt)(DWORD hash, int* out, int unk0);
typedef void	(__cdecl*	fpAddExplosion)(Vector3* pos, int type, float damage, bool audible, bool invis, float shake, bool nodmg);
typedef void	(__cdecl*	fpGiveDelayedWeaponToPed)(Ped ped, DWORD hash, int time, BOOL equipNow);
typedef BOOL	(__cdecl*	fpRemoveAllPedWeapons)(Ped ped);
typedef BOOL	(__cdecl*	fpRemoveWeaponFromPed)(Ped ped, DWORD hash);
typedef BOOL	(__cdecl*	fpSetMobileRadio)(BOOL toggle);	//SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY
typedef int		(__cdecl*	fpGetPlayerRadioStationIndex)();
typedef char*	(__cdecl*	fpGetRadioStationName)(int id);
typedef bool	(__cdecl*	fpNetworkHasControlOfEntity)(Entity entity);
typedef BOOL	(__cdecl*	fpAddOwnedExplosion)(Ped ped, Vector3* pos, int type, float dmgScale, bool isAudible, bool isInvis, float fCamShake);
typedef bool	(__cdecl*	fpNetworkRequestControlOfEntity)(Entity entity);
typedef int		(__cdecl*	fpNetworkGetNetworkIdFromEntity)(Entity entity);
typedef bool	(__cdecl*	fpNetworkHasControlOfNetworkId)(int netId);
typedef bool	(__cdecl*	fpNetworkRequestControlOfNetworkId)(int netId);
typedef void	(__cdecl*	fpSetNetworkIdCanMigrate)(int netId, bool toggle);
typedef int		(__cdecl*	fpNetworkCreateSynchronisedScene)(Vector3* pos, Vector3* rot, int unk0, int unk1, int unk2, float unk3, float unk4, float unk5);
typedef int		(__cdecl*	fpNetworkAddPedToSynchronisedScene)(Ped ped, int scene, char* dict, char* anim, float speed, float speedMult, int duration, int flag, float playRate, int unk1, int unk2);
typedef int		(__cdecl*	fpNetworkStartSynchronisedScene)(int scene);
typedef int		(__cdecl*	fpClearPedTasksImmediately)(Ped ped);
typedef int		(__cdecl*	fpSetEntityVisible)(Entity e, bool toggle, bool unk0);
typedef bool	(__cdecl*	fpSetPedAsGroupMember)(Ped ped, int group);
typedef bool	(__cdecl*	fpIsPedGroupMember)(Ped ped, int group);
typedef BOOL	(__cdecl*	fpSetPedCanSwitchWeapon)(Ped ped, bool toggle);
typedef void	(__cdecl*	fpSetPedGravity)(Ped ped, bool toggle);
typedef BOOL	(__cdecl*	fpSetEntityHasGravity)(Entity entity, bool toggle);
typedef bool	(__cdecl*	fpIsVehicleDrivable)(Vehicle vehicle, bool unk0);
typedef bool	(__cdecl*	fpIsModelAHeli)(DWORD hash);
typedef bool	(__cdecl*	fpIsModelAPlane)(DWORD hash);
typedef bool	(__cdecl*	fpIsModelACar)(DWORD hash);
typedef BOOL	(__cdecl*	fpSetHeliBladesFullSpeed)(Vehicle vehicle, float speed);	//speed 0.f - 1.f
typedef BOOL	(__cdecl*	fpSetVehicleForwardSpeed)(CVehicle* pVeh, float speed);
typedef bool	(__cdecl*	fpSetVehicleNumberPlateText)(Vehicle vehicle, char* text);
typedef bool	(__cdecl*	fpSetPedToRagdoll)(Ped ped, int time1, int time2, int type, bool unk0, bool unk1, bool unk2);
typedef void	(__cdecl*	fpGetPedBoneCoords)(Vector3* out, Ped ped, DWORD boneId, Vector3* offset);
typedef bool	(__cdecl*	fpSetEntityAsMissionEntity)(Entity entity, bool unk0, bool owned);
typedef bool	(__cdecl*	fpApplyForceToEntity)(Entity entity, int forceType, Vector3* pos, Vector3* rot, int unk0, bool isRel, bool unk2, bool highForce, bool unk3, bool unk4);
typedef BOOL	(__cdecl*	fpSetEntityRotation)(Entity entity, Vector3* rot, int unk0);
typedef bool	(__cdecl*	fpSetEntityHeading)(Entity entity, float heading);
typedef BOOL	(__cdecl*	fpFreezeEntityPosition)(Entity entity, bool toggle);
typedef BOOL	(__cdecl*	fpShootSingleBulletBetweenCoords)(Vector3* pos1, Vector3* pos2, int damage, bool unk0, DWORD hash, Ped owner, bool isAudible, bool isVisible, float speed, int unk1, bool unk2, bool unk3, int unk4);
typedef void	(__cdecl*	fpSetPedNeverLeavesGroup)(Ped ped, bool toggle);
typedef BOOL	(__cdecl*	fpSetGroupFormation)(int group, int formation);
typedef int		(__cdecl*	fpGetPedBoneIndex)(Ped ped, int boneId);
typedef BOOL	(__cdecl*	fpSetPedComponentVariation)(Ped ped, int componentId, int drawableId, int textureId, int paletteId);
typedef int		(__cdecl*	fpGetPedDrawableVariation)(Ped ped, int componentId);
typedef int		(__cdecl*	fpGetPedTextureVariation)(Ped ped, int componentId);
typedef int		(__cdecl*	fpGetPedPaletteVariation)(CPed* pPed, int componentId);
typedef BOOL	(__cdecl*	fpClearAllPedProps)(Ped ped);
typedef BOOL	(__cdecl*	fpSetPedPropIndex)(Ped ped, int componentId, int drawableId, int textureId, bool attach);
typedef bool	(__cdecl*	fpIsEntityInAir)(Entity entity);
typedef BOOL	(__cdecl*	fpSetEntityVelocity)(Entity entity, Vector3* velocity);
typedef Entity	(__cdecl*	fpGetEntityAttachedTo)(Entity entity);
typedef bool	(__cdecl*	fpDetachEntity)(Entity entity, bool unk0, bool collision);
typedef bool	(__cdecl*	fpDeleteEntity)(Entity* entity);
typedef bool	(__cdecl*	fpIsEntityAttached)(Entity entity);
typedef BOOL	(__cdecl*	fpSetEntityAsNoLongerNeeded)(Entity* entity);
typedef BOOL	(__cdecl*	fpGetEntityVelocity)(Vector3* out, Entity entity);
typedef BOOL	(__cdecl*	fpGetEntityRotation)(Vector3* out, Entity entity, int rotationOrder);
typedef DWORD	(__cdecl*	fpGetEntityModel)(Entity entity);
typedef bool	(__cdecl*	fpSetVehicleOnGroundProperly)(Vehicle vehicle, int unk0);
typedef void	(__cdecl*	fpSetVehicleUndriveable)(Vehicle vehicle, bool toggle);
typedef void	(__cdecl*	fpSetVehicleFixed)(Vehicle vehicle);
typedef void	(__cdecl*	fpSetVehicleDeformationFixed)(CVehicle* pVehicle);
typedef bool	(__cdecl*	fpIsVehicleSeatFree)(Vehicle vehicle, int seatId, bool unk0);
typedef bool	(__cdecl*	fpSetVehicleModKit)(Vehicle vehicle, int modKit);
typedef void	(__cdecl*	fpSetVehicleNumberPlateIndex)(CVehicle* vehicle, int plateId);
typedef BOOL	(__cdecl*	fpToggleVehicleMod)(Vehicle vehicle, int modType, bool toggle);
typedef BOOL	(__cdecl*	fpSetVehicleMod)(Vehicle vehicle, int modType, int modIndex, bool customTires);
typedef BOOL	(__cdecl*	fpSetVehicleWheelType)(Vehicle vehicle, int wheelType);
typedef int		(__cdecl*	fpGetNumVehicleMod)(Vehicle vehicle, int modType);
typedef BOOL	(__cdecl*	fpAddTextCompSubstrPlayerName)(char* text);
typedef BOOL	(__cdecl*	fpEndTextCmdDisplayText)(float x, float y, int unk1);
typedef BOOL	(__cdecl*	fpBeginTextCmdDisplayText)(char* text);
typedef BOOL	(__cdecl*	fpSetNotificationTextEntiry)(char* text);
typedef BOOL	(__cdecl*	fpDrawNotification)(bool blink, bool unk0, bool unk1);
typedef BOOL	(__cdecl*	fpSetWeatherTypeNowPersist)(char* weather);
typedef BOOL	(__cdecl*	fpDisplayOnscreenKeyboard)(int64_t unk0, char* title, char* unk1, char* defaultText, char* defConcat, char* defConCat2, char* defConcat3, int maxLength);
typedef BOOL	(__cdecl*	fpUpdateOnscreenKeyboard)();
typedef BOOL	(__cdecl*	fpSetLocalPlayerVisibleLocally)(bool unk0);
typedef BOOL	(__cdecl*	fpNetworkOverrideClockTime)(int hour, int minute, int second, bool unk0);
typedef uint64_t(__cdecl*	fpGetNetworkTime)();
typedef BOOL	(__cdecl*	fpAiTaskWanderStandard)(Ped ped, float unk0, bool unk1);
typedef BOOL	(__cdecl*	fpAiTaskPlayAnim)(Ped ped, char* dict, char* anim, float speed, float speedMult, int duration, int flg, float playRate, bool unk0, BOOL lockX, BOOL lockY, BOOL lockZ, bool unk1);
typedef bool	(__cdecl*	fpIsModelInCdimage)(DWORD hash);
typedef bool	(__cdecl*	fpIsModelValid)(DWORD hash);
typedef bool	(__cdecl*	fpIsModelAVehicle)(DWORD hash);
typedef BOOL	(__cdecl*	fpRequestModel)(DWORD hash);
typedef bool	(__cdecl*	fpHasModelLoaded)(DWORD hash);
typedef BOOL	(__cdecl*	fpRequestAnimDict)(char* dict);
typedef bool	(__cdecl*	fpHasAnimDictLoaded)(char* dict);
typedef void	(__cdecl*	fpDecorRegister)(char* name, int type);
typedef bool	(__cdecl*	fpDecorSetInt)(Entity entity, char* name, int value);
typedef BOOL	(__cdecl*	fpCreateAmbientDrop)(DWORD pickupHash, Vector3* pos, int unk0, int value, DWORD modelHash, bool unk1, bool unk2);
typedef	BOOL	(__cdecl*	fpIsPlayerFreeAiming)(Player player);
typedef bool	(__cdecl*	fpGetPedLastWeaponImpactCoord)(Ped ped, v3* out);
typedef int		(__cdecl*	fpStartRayCast)(Vector3* pos1, Vector3* pos2, int flags, Entity entity, bool unk0);	//_START_SHAPE_TEST_RAY
typedef int		(__cdecl*	fpGetRayCast)(int handle, BOOL* hit, Vector3* end, Vector3* surface, Hash* material, Entity* entity);
typedef Entity	(__cdecl*	fpPtrToHandle)(void* entity);
typedef BOOL	(__cdecl*	fpNetworkSetInSpectatorMode)(bool toggle, Ped ped);
typedef BOOL	(__cdecl*	fpSetPedCombatAbility)(CPed* pPed, BYTE ability);
typedef BOOL	(__cdecl*	fpAiTaskCombatPed)(Ped ped, Ped target, int unk0, int unk1);
typedef int		(__cdecl*	fpTriggerScriptEvent)(bool unk0, uint64_t* args, int argCount, int bitFlags);
typedef BOOL	(__cdecl*	fpApplyVehicleColors)(CVehicle* vehicle, bool unk0);	//unk0 = 1;
typedef BOOL	(__cdecl*	fpSetPedRelationshipGroupHash)(Ped ped, DWORD hash);
typedef BOOL	(__cdecl*	fpSetPlayerVisibleLocally)(Player player, bool toggle);
typedef BOOL	(__cdecl*	fpSetModelAsNoLongerNeeded)(DWORD hash);
typedef BOOL	(__cdecl*	fpSetRadioToStationName)(void* gameInfo, char* station);
typedef void	(__cdecl*	fpSetVehicleEngineOn)(Vehicle vehicle, bool unk0, bool instant, bool unk1);
typedef BOOL	(__cdecl*	fpAttachEntityToEntity)(Entity subject, Entity target, int boneIndex, Vector3* offset, Vector3* rot, bool unk0, bool softPinning, bool collision, bool isPed, int vertexIndex, bool fixedRot, bool unk1);
typedef BOOL	(__cdecl*	fpSetEntityCollision)(Entity entity, bool toggle, bool physics, bool unk0);


#pragma pack(push, 1)
struct threeBytes
{
	BYTE	byte[3];

	bool	empty();
};

struct twoBytes
{
	BYTE	byte[2];

	bool	empty();
};

struct screenReso
{
	uint32_t	w,
				h;
};

struct objectHash
{
	DWORD*	ptr;
	DWORD	hash;
};

struct clockTime
{
	int hour;
	int minute;
	int second;
};
#pragma pack(pop)

class CHooking
{
	public:
		static std::vector<LPVOID>		m_hooks;
		static eGameState* 				m_gameState;
		static CBlipList*				m_blipList;
		static CReplayInterface*		m_replayIntf;
		static __int64**				m_globalBase;
		static MemoryPool**				m_entityPool;
		static MemoryPool**				m_pedPool;
		//static CRITICAL_SECTION			m_critSec;
		static threeBytes*				m_infAmmo;
		static threeBytes*				m_noReload;
		static CViewPort*				m_viewPort;
		static screenReso*				m_resolution;
		static void*					m_objectHashTable;
		static void*					m_objectHashTableSectionEnd;
		static void*					m_onlineName;
		static twoBytes*				m_ownedExplosionBypass;
		static uint64_t*				m_frameCount;
		static CTextInfo*				m_textInfo;
		static char*					m_onscreenKeyboardResult;
		static clockTime*				m_clockTime;
		static uint64_t*				m_networkTime;
		static void*					m_gameInfo;
		static CPlayers*				m_players;


		static fpIsPlayerOnline						IS_PLAYER_ONLINE;
		static fpIsPlayerPlaying					is_player_playing;
		static fpPlayerId							player_id;
		static fpGetPlayerPed						get_player_ped;
		static fpGetPlayerTeam						get_player_team;
		static fpGetVehiclePedIsUsing				get_vehicle_ped_is_using;
		static fpGetPedInVehicleSeat				get_ped_in_vehicle_seat;
		static fpIsAimCamActive						is_aim_cam_active;
		static fpGetEntityPlayerIsFreeAimingAt		get_entity_player_is_free_aiming_at;
		static fpNetworkIsSessionStarted			network_is_session_started;
		static fpGetEntitySpeed						get_entity_speed;
		static fpGetPlayerName						get_player_name;
		static fpDrawRect							draw_rect;
		static fpDrawLine							draw_line;
		static fpGetGroundZFor3dCoord				get_ground_z_for_3d_coord;
		static fpCreateVehicle						create_vehicle;
		static fpSetEntityCoordsNoOffset			set_entity_coords_no_offset;
		static fpGetEntityHeading					get_entity_heading;
		static fpGetGameplayCamRot					get_gameplay_cam_rot;
		static fpGetGameplayCamCoord				get_gameplay_cam_coord;
		static fpGetPlayerGroup						get_player_group;
		static fpSetPlayerModel						set_player_model;
		static fpSetPedRandomComponentVariatian		set_ped_random_component_variation;
		static fpSetPedDefaultComponentVariation	set_ped_default_component_variation;
		static fpIsPedInAnyVehicle					is_ped_in_any_vehicle;
		static fpCreatePed							create_ped;
		static fpSetPedIntoVehicle					set_ped_into_vehicle;
		static fpSetPedConfigFlag					set_ped_config_flag;
		static fpClearPedBloodDamage				clear_ped_blood_damage;
		static fpClearPedWetness					clear_ped_wetness;
		static fpCreateObject						create_object;
		//static fpGetPedNearbyVehicles				get_ped_nearby_vehicles;
		//static fpGetPedNearbyPeds					get_ped_nearby_peds;
		static fpGetPedGroupIndex					get_ped_group_index;
		static fpClonePed							clone_ped;
		static fpNetworkShopBeginService			network_shop_begin_service;
		static fpNetworkShopCheckoutStart			network_shop_checkout_start;
		static fpStatSetInt							stat_set_int;
		static fpStatSetFloat						stat_set_float;
		static fpStatSetBool						stat_set_bool;
		static fpStatSetDate						stat_set_date;
		static fpStatGetInt							stat_get_int;
		static fpAddExplosion						add_explosion;
		static fpGiveDelayedWeaponToPed				give_delayed_weapon_to_ped;
		static fpRemoveAllPedWeapons				remove_all_ped_weapons;
		static fpRemoveWeaponFromPed				remove_weapon_from_ped;
		static fpSetMobileRadio						set_mobile_radio;
		static fpGetPlayerRadioStationIndex			get_player_radio_station_index;
		static fpGetRadioStationName				get_radio_station_name;
		static fpNetworkHasControlOfEntity			network_has_control_of_entity;
		static fpAddOwnedExplosion					add_owned_explosion;
		static fpNetworkRequestControlOfEntity		network_request_control_of_entity;
		static fpNetworkGetNetworkIdFromEntity		network_get_network_id_from_entity;
		static fpNetworkHasControlOfNetworkId		network_has_control_of_network_id;
		static fpNetworkRequestControlOfNetworkId	network_request_control_of_network_id;
		static fpSetNetworkIdCanMigrate				set_network_id_can_migrate;
		static fpNetworkCreateSynchronisedScene		network_create_synchronised_scene;
		static fpNetworkAddPedToSynchronisedScene	network_add_ped_to_synchronised_scene;
		static fpNetworkStartSynchronisedScene		network_start_synchronised_scene;
		static fpClearPedTasksImmediately			clear_ped_tasks_immediately;
		static fpSetEntityVisible					set_entity_visible;
		static fpSetPedAsGroupMember				set_ped_as_group_member;
		static fpIsPedGroupMember					is_ped_group_member;
		static fpSetPedCanSwitchWeapon				set_ped_can_switch_weapon;
		static fpSetPedGravity						set_ped_gravity;
		static fpSetEntityHasGravity				set_entity_has_gravity;
		static fpIsVehicleDrivable					is_vehicle_drivable;
		static fpIsModelAHeli						is_model_a_heli;
		static fpIsModelAPlane						is_model_a_plane;
		static fpIsModelACar						is_model_a_car;
		static fpSetHeliBladesFullSpeed				set_heli_blades_full_speed;
		static fpSetVehicleForwardSpeed				set_vehicle_forward_speed;
		static fpSetVehicleNumberPlateText			set_vehicle_number_plate_text;
		static fpSetPedToRagdoll					set_ped_to_ragdoll;
		static fpGetPedBoneCoords					get_ped_bone_coords;
		static fpSetEntityAsMissionEntity			set_entity_as_mission_entity;
		static fpApplyForceToEntity					apply_force_to_entity;
		static fpSetEntityRotation					set_entity_rotation;
		static fpSetEntityHeading					set_entity_heading;
		static fpFreezeEntityPosition				freeze_entity_position;
		static fpShootSingleBulletBetweenCoords		shoot_single_bullet_between_coords;
		static fpSetPedNeverLeavesGroup				set_ped_never_leaves_group;
		static fpSetGroupFormation					set_group_formation;
		static fpGetPedBoneIndex					get_ped_bone_index;
		static fpSetPedComponentVariation			set_ped_component_variation;
		static fpGetPedDrawableVariation			get_ped_drawable_varation;
		static fpGetPedTextureVariation				get_ped_texture_variation;
		static fpGetPedPaletteVariation				get_ped_palette_variation;
		static fpClearAllPedProps					clear_add_ped_props;
		static fpSetPedPropIndex					set_ped_prop_index;
		static fpIsEntityInAir						is_entity_in_air;
		static fpSetEntityVelocity					set_entity_velocity;
		static fpGetEntityAttachedTo				get_entity_attached_to;
		static fpDetachEntity						detach_entity;
		static fpDeleteEntity						delete_entity;
		static fpIsEntityAttached					is_entity_attached;
		static fpSetEntityAsNoLongerNeeded			set_entity_as_no_longer_needed;
		static fpGetEntityVelocity					get_entity_velocity;
		static fpGetEntityRotation					get_entity_rotation;
		static fpGetEntityModel						get_entity_model;
		static fpSetVehicleOnGroundProperly			set_vehicle_on_ground_properly;
		static fpSetVehicleUndriveable				set_vehicle_undriveable;
		static fpSetVehicleFixed					set_vehicle_fixed;
		static fpSetVehicleDeformationFixed			set_vehicle_deformation_fixed;
		static fpIsVehicleSeatFree					is_vehicle_seat_free;
		static fpSetVehicleModKit					set_vehicle_mod_kit;
		static fpSetVehicleNumberPlateIndex			set_vehicle_number_plate_index;
		static fpToggleVehicleMod					toggle_vehicle_mod;
		static fpSetVehicleMod						set_vehicle_mod;
		static fpSetVehicleWheelType				set_vehicle_wheel_type;
		static fpGetNumVehicleMod					get_num_vehicle_mod;
		static fpAddTextCompSubstrPlayerName		add_text_comp_substr_playername;
		static fpEndTextCmdDisplayText				end_text_cmd_display_text;
		static fpBeginTextCmdDisplayText			begin_text_cmd_display_text;
		static fpSetNotificationTextEntiry			set_notification_text_entry;
		static fpDrawNotification					draw_notification;
		static fpSetWeatherTypeNowPersist			set_weather_type_now_persist;
		static fpDisplayOnscreenKeyboard			display_onscreen_keyboard;
		static fpUpdateOnscreenKeyboard				update_onscreen_keyboard;
		static fpSetLocalPlayerVisibleLocally		set_local_player_visible_locally;
		static fpNetworkOverrideClockTime			network_override_clock_time;
		static fpGetNetworkTime						get_network_time;
		static fpAiTaskWanderStandard				ai_task_wander_standard;
		static fpAiTaskPlayAnim						ai_task_play_anim;
		static fpIsModelInCdimage					is_model_in_cdimage;
		static fpIsModelValid						is_model_valid;
		static fpIsModelAVehicle					is_model_a_vehicle;
		static fpRequestModel						request_model;
		static fpHasModelLoaded						has_model_loaded;
		static fpRequestAnimDict					request_anim_dict;
		static fpHasAnimDictLoaded					has_anim_dict_loaded;
		static fpDecorRegister						decor_register;
		static fpDecorSetInt						decor_set_int;
		static fpCreateAmbientDrop					create_ambient_pickup;
		static fpIsPlayerFreeAiming					is_player_free_aiming;
		static fpGetPedLastWeaponImpactCoord		get_ped_last_weapon_impact;
		static fpStartRayCast						start_ray_cast;
		static fpGetRayCast							get_ray_cast;
		static fpPtrToHandle						ptr_to_handle;
		static fpNetworkSetInSpectatorMode			network_set_in_spectator_mode;
		static fpSetPedCombatAbility				set_ped_combat_ability;
		static fpAiTaskCombatPed					ai_task_combat_ped;
		static fpTriggerScriptEvent					trigger_script_event;
		static fpApplyVehicleColors					apply_vehicle_colors;
		static fpSetPedRelationshipGroupHash		set_ped_relationship_group_hash;
		static fpSetPlayerVisibleLocally			set_player_visible_locally;
		static fpSetModelAsNoLongerNeeded			set_model_as_no_longer_needed;
		static fpSetRadioToStationName				set_radio_to_station_name;
		static fpSetVehicleEngineOn					set_vehicle_engine_on;
		static fpAttachEntityToEntity				attach_entity_to_entity;
		static fpSetEntityCollision					set_entity_collision;





		static void				init();
		static void				cleanup();
		static void				onTick();
		static __int64*			getGlobalPtr(int index);
		static void				defuseEvent(eRockstarEvent e, bool toggle);
		static bool				antiCrash(bool toggle);
		static bool				setPlayerName(std::string& name);
		static void				ownedExplosionBypass(bool toggle);

		template <typename T>
		static void nop_bytes(T* address, T& restore, bool toggle)
		{
			if(toggle)
			{
				if(restore.empty())
					restore	= *address;
				mem_nop(address, sizeof(T));
			}
			else if(!restore.empty())
				memcpy_s(address, sizeof(address), restore.byte, sizeof(T));
		}
};

#endif