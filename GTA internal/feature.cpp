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

namespace feature
{
	featMap	map;
	plrMap	player_map;

	void populate()
	{
		CMenu::addFeatureCategory("Local");		//0
		CMenu::addFeatureCategory("Online");	//1
		CMenu::addFeatureCategory("Spawn");		//2

		int parent[0x10];
	
		/*
		P	Player
		W	Weapon
		V	Vehicle
		TP	Teleport
		O	Online
		A	All Online
		C	Clothing
		M	Model
		T	Time/Weather
		S	Spawn
		I	Interface
		U	Misc
		E	Editor
		*/

		*parent	= CMenu::addFeature(0, -1, "Player Options", feat_parent);
			feature::map.emplace("FEATURE_P_TRUEGOD", CMenu::addFeature(-1, *parent, "God", feat_toggle, "trueGodMode"));
			feature::map.emplace("FEATURE_P_GOD",	 CMenu::addFeature(-1, *parent, "Demi-God", feat_toggle, "godMode"));
			feature::map.emplace("FEATURE_P_INVISIBLE",	 CMenu::addFeature(-1, *parent, "Invisible", feat_toggle, "playerInvis"));
			feature::map.emplace("FEATURE_P_VISIBLE_LOCAL",	 CMenu::addFeature(-1, *parent, "Player Visible Locally", feat_toggle, "playerVisLoc"));
			feature::map.emplace("FEATURE_P_OFFRADAR",	 CMenu::addFeature(-1, *parent, "Off Radar", feat_toggle));
			feature::map.emplace("FEATURE_P_CLEAN_PLAYER",	 CMenu::addFeature(-1, *parent, "Clean", feat_action));
			feature::map.emplace("FEATURE_P_WANTED",	 CMenu::addFeature(-1, *parent, "Wanted", feat_slider, "wanted", 0.f, 5.f, .2f));
			feature::map.emplace("FEATURE_P_NEVERWANTED",	 CMenu::addFeature(-1, *parent, "Never Wanted", feat_toggle, "neverWanted"));
			feature::map.emplace("FEATURE_P_ANTINPC",	 CMenu::addFeature(-1, *parent, "Anti NPC", feat_toggle, "antiNpc"));
			feature::map.emplace("FEATURE_P_SUPER_RUN",	 CMenu::addFeature(-1, *parent, "Super Run", feat_slider, "superRun", 1.f, 2.f));
			feature::map.emplace("FEATURE_P_RUNSPD",	 CMenu::addFeature(-1, *parent, "Run Speed", feat_slider, "runSpd", 1.f, 5.f));
			feature::map.emplace("FEATURE_P_SWIMSPD",	 CMenu::addFeature(-1, *parent, "Swim Speed", feat_slider, "swimSpd", 1.f, 5.f));
			feature::map.emplace("FEATURE_P_SUPERJUMP",	 CMenu::addFeature(-1, *parent, "Super Jump", feat_toggle, "superJump"));
			feature::map.emplace("FEATURE_P_EXPLOSIVEMELEE",	 CMenu::addFeature(-1, *parent, "Explosive Melee", feat_toggle, "explMelee"));
			feature::map.emplace("FEATURE_P_SEATBELT",	 CMenu::addFeature(-1, *parent, "Seatbelt", feat_toggle, "seatbelt"));
			feature::map.emplace("FEATURE_P_NORAGDOLL",	 CMenu::addFeature(-1, *parent, "No Ragdoll", feat_toggle, "noRagdoll"));
			feature::map.emplace("FEATURE_P_STAMINA",	 CMenu::addFeature(-1, *parent, "Infinite Stamina", feat_toggle, "infStam"));
			feature::map.emplace("FEATURE_P_MOBILE_RADIO",	 CMenu::addFeature(-1, *parent, "Mobile Radio", feat_toggle, "mobileRadio"));
			feature::map.emplace("FEATURE_P_FREEZE_RADIO",	 CMenu::addFeature(-1, *parent, "Freeze Radio", feat_value_str, "freezeRadio", 0.f, 19.f, 1.f, hash::radio_station_name));
			feature::map.emplace("FEATURE_P_CLEAR_REPORTS",	 CMenu::addFeature(-1, *parent, "Clear Reports", feat_action));
			feature::map.emplace("FEATURE_P_MONEY_DROP",	 CMenu::addFeature(-1, *parent, "Money Drop", feat_value_str, "", 0.f, (float) (sizeof(hash::object_prop_money_name) / sizeof(*hash::object_prop_money_name)) - 1, 1.f, hash::object_prop_money_name));
			feature::map.emplace("FEATURE_P_CLONE_BODYGUARD",	 CMenu::addFeature(-1, *parent, "Clone Bodyguard", feat_action));
			//feature::map.emplace("FEATURE_P_CLEANUP_OBJECTS",	 CMenu::addFeature(-1, *parent, "Cleanup Objects", feat_action));
			feature::map.emplace("FEATURE_P_ANTI_AFK",	 CMenu::addFeature(-1, *parent, "Anti AFK", feat_value_str, "", 0.f, (float) (sizeof(hash::anti_afk_name) / sizeof(*hash::anti_afk_name)) - 1, 1.f, hash::anti_afk_name));

		*parent	= CMenu::addFeature(0, -1, "Vehicle Options", feat_parent);
			feature::map.emplace("FEATURE_V_TRUEGOD",	 CMenu::addFeature(-1, *parent, "God", feat_toggle, "vehTrueGodMode"));
			feature::map.emplace("FEATURE_V_GOD",	 CMenu::addFeature(-1, *parent, "Demi-God", feat_toggle, "vehGodMode"));
			feature::map.emplace("FEATURE_V_REPAIR",	 CMenu::addFeature(-1, *parent, "Repair", feat_action));
			feature::map.emplace("FEATURE_V_UPGRADE",	 CMenu::addFeature(-1, *parent, "Upgrade", feat_action));
			feature::map.emplace("FEATURE_V_FLIP",	 CMenu::addFeature(-1, *parent, "Flip", feat_action));
			feature::map.emplace("FEATURE_V_STICK_TO_GROUND",	 CMenu::addFeature(-1, *parent, "Stick to Ground", feat_toggle, "vehStickGround"));
			feature::map.emplace("FEATURE_V_BOOST",	 CMenu::addFeature(-1, *parent, "Boost", feat_action_value, "vehImpulse", 0.f, 200.f, 20.f));
			feature::map.emplace("FEATURE_V_STOP",	 CMenu::addFeature(-1, *parent, "Stop", feat_action));
			feature::map.emplace("FEATURE_V_INVISIBLE",	 CMenu::addFeature(-1, *parent, "Invisible", feat_toggle, "vehicleInvis"));
			feature::map.emplace("FEATURE_V_RAINBOW",	 CMenu::addFeature(-1, *parent, "Rainbow Car", feat_toggle, "vehRainbow"));
			feature::map.emplace("FEATURE_V_COLOR_PRESET",	 CMenu::addFeature(-1, *parent, "Preset Colors Primary", feat_action_value, "vehPresetColor", 0.f, 160.f, 1.f));
			feature::map.emplace("FEATURE_V_COLOR_PRESET2",	 CMenu::addFeature(-1, *parent, "Preset Colors Secondary", feat_action_value, "vehPresetColor2", 0.f, 160.f, 1.f));
			feature::map.emplace("FEATURE_V_BULLETPROOFTIRES",	 CMenu::addFeature(-1, *parent, "Bulletproof Tires", feat_toggle, "vehBulletproofTires"));
			feature::map.emplace("FEATURE_V_DEFORMATION",	 CMenu::addFeature(-1, *parent, "Deformation", feat_slider, "vehDeform", 0.f, 1.f));
			feature::map.emplace("FEATURE_V_ACCELERATION",	 CMenu::addFeature(-1, *parent, "Acceleration", feat_slider, "vehAccel", 1.f, 10.f));
			feature::map.emplace("FEATURE_V_UPSHIFT",	 CMenu::addFeature(-1, *parent, "Up-Shift Rate", feat_slider, "vehUpShift", 1.f, 25.f));
			feature::map.emplace("FEATURE_V_BRAKEFORCE",	 CMenu::addFeature(-1, *parent, "Brake force", feat_slider, "vehBrakeForce", 1.f, 10.f));
			feature::map.emplace("FEATURE_V_TRACTION",	 CMenu::addFeature(-1, *parent, "Traction", feat_slider, "vehTraction", 1.f, 2.f));
			feature::map.emplace("FEATURE_V_GRAVITY",	 CMenu::addFeature(-1, *parent, "Gravity", feat_slider, "vehGravity", 0.f, 25.f));
			feature::map.emplace("FEATURE_V_SUSPENSION_FORCE",	 CMenu::addFeature(-1, *parent, "Suspension Force", feat_slider, "vehSuspensionForce", 0.f, 2.f));
			feature::map.emplace("FEATURE_V_INF_CAR_ALARM",	 CMenu::addFeature(-1, *parent, "Infinite Alarm", feat_toggle, "vehInfAlarm"));
			feature::map.emplace("FEATURE_V_LICENSE",	 CMenu::addFeature(-1, *parent, "Change License", feat_action));

		*parent		= CMenu::addFeature(0, -1, "Model Changer", feat_parent);
			//feature::map.emplace("FEATURE_M_RANDOMIZE_PED",	 CMenu::addFeature(-1, *parent, "Randomize Peds", feat_toggle, "randomModel"));
			CMenu::addFeature(-1, *parent, "MP Female", feat_spawn, "MP_F_Freemode_01", spwn_model);
			CMenu::addFeature(-1, *parent, "MP Male", feat_spawn, "MP_M_Freemode_01", spwn_model);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Animals", feat_parent);
			for(int i = 0; i < sizeof(hash::ped_animal_hash) / sizeof(hash::ped_animal_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::ped_animal_name[i], feat_spawn, hash::ped_animal_hash[i], spwn_model);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Emergency", feat_parent);
			for(int i = 0; i < sizeof(hash::ped_emergency_hash) / sizeof(hash::ped_emergency_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::ped_emergency_name[i], feat_spawn, hash::ped_emergency_hash[i], spwn_model);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Sex Workers", feat_parent);
			for(int i = 0; i < sizeof(hash::ped_sex_hash) / sizeof(hash::ped_sex_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::ped_sex_name[i], feat_spawn, hash::ped_sex_hash[i], spwn_model);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Story", feat_parent);
			for(int i = 0; i < sizeof(hash::ped_story_hash) / sizeof(hash::ped_story_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::ped_story_name[i], feat_spawn, hash::ped_story_hash[i], spwn_model);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Misc", feat_parent);
			for(int i = 0; i < sizeof(hash::ped_misc_hash) / sizeof(hash::ped_misc_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::ped_misc_name[i], feat_spawn, hash::ped_misc_hash[i], spwn_model);

		*parent	= CMenu::addFeature(0, -1, "Teleport", feat_parent);
			feature::map.emplace("FEATURE_TP_WAYPOINT",	 CMenu::addFeature(-1, *parent, "Waypoint", feat_action));
			feature::map.emplace("FEATURE_TP_OBJECTIVE",	 CMenu::addFeature(-1, *parent, "Objective", feat_action));
			feature::map.emplace("FEATURE_TP_NEARBY_CAR",	 CMenu::addFeature(-1, *parent, "Nearby car", feat_action));

			*(parent + 1) = CMenu::addFeature(-1, *parent, "Interiors", feat_parent);
				CMenu::addFeature(-1, *(parent + 1), "FIB Building Top", feat_teleport, tp_static, 136.0f, -750.f, 262.f);
				CMenu::addFeature(-1, *(parent + 1), "Garment Factory", feat_teleport, tp_static, 712.716f, -962.906f, 30.6f);
				CMenu::addFeature(-1, *(parent + 1), "Franklin's House", feat_teleport, tp_static, 7.119f, 536.615f, 176.2f);
				CMenu::addFeature(-1, *(parent + 1), "Michael's House", feat_teleport, tp_static, -813.603f, 179.474f, 72.5f);
				CMenu::addFeature(-1, *(parent + 1), "Trevor's House", feat_teleport, tp_static, 1972.610f, 3817.040f, 33.65f);
				CMenu::addFeature(-1, *(parent + 1), "Aunt Denise's House", feat_teleport, tp_static, -14.380f, -1438.510f, 31.3f);
				CMenu::addFeature(-1, *(parent + 1), "Floyd's House", feat_teleport, tp_static, -1151.770f, -1518.138f, 10.85f);
				CMenu::addFeature(-1, *(parent + 1), "Lester's House", feat_teleport, tp_static, 1273.898f, -1719.304f, 54.8f);
				CMenu::addFeature(-1, *(parent + 1), "Vanilla Unicorn Office", feat_teleport, tp_static, 97.271f, -1290.994f, 29.45f);
				CMenu::addFeature(-1, *(parent + 1), "Bank Vault (Pacific Standard)", feat_teleport, tp_static, 255.85f, 217.f, 101.9f);
				CMenu::addFeature(-1, *(parent + 1), "Comedy Club", feat_teleport, tp_static, 378.100f, -999.964f, -98.6f);
				CMenu::addFeature(-1, *(parent + 1), "Humane Labs", feat_teleport, tp_static, 3614.394f, 3744.803f, 28.9f);
				CMenu::addFeature(-1, *(parent + 1), "Humane Labs Tunnel", feat_teleport, tp_static, 3525.201f, 3709.625f, 21.2f);
				CMenu::addFeature(-1, *(parent + 1), "IAA Office", feat_teleport, tp_static, 113.568f, -619.001f, 206.25f);
				CMenu::addFeature(-1, *(parent + 1), "Torture Room", feat_teleport, tp_static, 142.746f, -2201.189f, 4.9f);
				CMenu::addFeature(-1, *(parent + 1), "Fort Zancudo Tower", feat_teleport, tp_static, -2358.132f, 3249.754f, 101.65f);
				CMenu::addFeature(-1, *(parent + 1), "Mine Shaft", feat_teleport, tp_static, -595.342f, 2086.008f, 131.6f);

			*(parent + 1)	= CMenu::addFeature(-1, *parent, "Saved Locations", feat_parent);
				CMenu::addFeature(-1, *(parent + 1), "Saved 1", feat_teleport, "pos0", tp_saved);
				CMenu::addFeature(-1, *(parent + 1), "Saved 2", feat_teleport, "pos1", tp_saved);
				CMenu::addFeature(-1, *(parent + 1), "Saved 3", feat_teleport, "pos2", tp_saved);
				CMenu::addFeature(-1, *(parent + 1), "Saved 4", feat_teleport, "pos3", tp_saved);
				CMenu::addFeature(-1, *(parent + 1), "Saved 5", feat_teleport, "pos4", tp_saved);
				CMenu::addFeature(-1, *(parent + 1), "Saved 6", feat_teleport, "pos5", tp_saved);
			CMenu::addFeature(-1, *parent, "LS Customs", feat_teleport, tp_static, -365.425f, -131.809f, 38.9f);
			CMenu::addFeature(-1, *parent, "Mors Mutual Insurance", feat_teleport, tp_static, -232.74f, -1163.556f, 24.95f);
			CMenu::addFeature(-1, *parent, "LSIA Runway", feat_teleport, tp_static, -1336.f, -3044.f, 14.15f);
			CMenu::addFeature(-1, *parent, "Sandy Shores Airfield", feat_teleport, tp_static, 1747.f, 3273.f, 41.35f);
			CMenu::addFeature(-1, *parent, "Mount Chiliad", feat_teleport, tp_static, 489.979f, 5587.527f, 794.3f);

		*parent	= CMenu::addFeature(0, -1, "Weapons", feat_parent);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Weapon Modifiers", feat_parent);
			feature::map.emplace("FEATURE_W_SPREAD", CMenu::addFeature(-1, *(parent + 1), "No Spread", feat_toggle, "noSpread"));	
			feature::map.emplace("FEATURE_W_RECOIL", CMenu::addFeature(-1, *(parent + 1), "No Recoil", feat_toggle, "noRecoil"));	
			feature::map.emplace("FEATURE_W_RELOAD",	 CMenu::addFeature(-1, *(parent + 1), "Quick Reload", feat_slider, "quickReload", 1.f, 10.f));
			feature::map.emplace("FEATURE_W_DAMAGE",	 CMenu::addFeature(-1, *(parent + 1), "Bullet Damage", feat_slider, "bulletDamage", 1.f, 10.f));
			feature::map.emplace("FEATURE_W_AMMO",	 CMenu::addFeature(-1, *(parent + 1), "Infinite Ammo", feat_toggle, "infAmmo"));
			//feature::map.emplace("FEATURE_W_RANGE",	 CMenu::addFeature(-1, *(parent + 1), "Range", feat_slider, "weapRange", 1.f, 10.f));
			feature::map.emplace("FEATURE_W_SPINUP",	 CMenu::addFeature(-1, *(parent + 1), "No Spin-Up", feat_toggle, "weapSpin"));
			feature::map.emplace("FEATURE_W_EXPLOSIVEAMMO",	 CMenu::addFeature(-1, *(parent + 1), "Explosive Ammo", feat_toggle, "explAmmo"));
			feature::map.emplace("FEATURE_W_FIREAMMO",	 CMenu::addFeature(-1, *(parent + 1), "Fire Ammo", feat_toggle, "fireAmmo"));
			//feature::map.emplace("FEATURE_W_BULLET_BATCH",	 CMenu::addFeature(-1, *(parent + 1), "Bullet Batch", feat_slider, "bulletBatch", 1.f, 10.f, (float) 1.f / 9.f));
			//feature::map.emplace("FEATURE_W_BATCH_SPREAD",	 CMenu::addFeature(-1, *(parent + 1), "Batch Spread", feat_slider, "batchSpread", 0.f, 0.12f));
			//feature::map.emplace("FEATURE_W_MUZZLE_VELOCITY",	 CMenu::addFeature(-1, *(parent + 1), "Muzzle Velocity", feat_slider, "muzzleVelo", 1.f, 10.f));

			*(parent + 1) = CMenu::addFeature(-1, *parent, "Give Weapons", feat_parent);
				CMenu::addFeature(-1, *(parent + 1), "Give All", feat_spawn, "", spwn_weapon_all);
				for(int i = 0; i < sizeof(hash::weapon_hash) / sizeof(hash::weapon_hash[0]); i++)
					CMenu::addFeature(-1, *(parent + 1), hash::weapon_name[i], feat_spawn, hash::weapon_hash[i], spwn_weapon);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Remove Weapons", feat_parent);
				CMenu::addFeature(-1, *(parent + 1), "Remove All", feat_spawn, "", dspwn_weapon_all);
				for(int i = 0; i < sizeof(hash::weapon_hash) / sizeof(hash::weapon_hash[0]); i++)
					CMenu::addFeature(-1, *(parent + 1), hash::weapon_name[i], feat_spawn, hash::weapon_hash[i], dspwn_weapon);

		*parent	= CMenu::addFeature(0, -1, "Weather & Time", feat_parent);
			feature::map.emplace("FEATURE_T_PAUSE_CLOCK",	 CMenu::addFeature(-1, *parent, "Pause Clock (SP Only)", feat_toggle, "timePause"));
			feature::map.emplace("FEATURE_T_SET_HOUR",	 CMenu::addFeature(-1, *parent, "Set Hour", feat_action_value, "timeHour", 0.f, 23.f, 1.f));
			feature::map.emplace("FEATURE_T_SET_MIN",	 CMenu::addFeature(-1, *parent, "Set Minute", feat_action_value, "timeMin", 0.f, 55.f, 5.f));
			feature::map.emplace("FEATURE_T_WEATHER",	 CMenu::addFeature(-1, *parent, "Weather", feat_action_value_str, "", 0.f, 11.f, 1.f, hash::weather_enum));

		*parent	= CMenu::addFeature(0, -1, "Misc", feat_parent);
			feature::map.emplace("FEATURE_U_NOCLIP",	 CMenu::addFeature(-1, *parent, "No Clip", feat_value_str, "noclip", 0.f, 1.f, 1.f, hash::noclip_type));
			feature::map.emplace("FEATURE_U_NOCLIP_SPEED",	 CMenu::addFeature(-1, *parent, "No Clip Speed", feat_action_value, "noclipSpeed", 1.f, 10.f, 1.f));
			feature::map.emplace("FEATURE_U_CHAOS_MODE",	 CMenu::addFeature(-1, *parent, "Chaos Mode", feat_value_str, "", 0.f, (float) (sizeof(hash::chaos_mode_type) / sizeof(*hash::chaos_mode_type)) - 1, 1.f, hash::chaos_mode_type));
			feature::map.emplace("FEATURE_U_SMASH_VEHICLES",	 CMenu::addFeature(-1, *parent, "Smash Vehicles", feat_action));

		*parent	= CMenu::addFeature(0, -1, "Interface", feat_parent);
			feature::map.emplace("FEATURE_I_FPS_COUNTER",	 CMenu::addFeature(-1, *parent, "Fps Counter", feat_toggle, "uiFps"));
			feature::map.emplace("FEATURE_I_SPEED_O_METER",	 CMenu::addFeature(-1, *parent, "Speed-O-Meter", feat_toggle, "uiSpeedo"));
			feature::map.emplace("FEATURE_I_MENU_SCALE",	 CMenu::addFeature(-1, *parent, "Menu Scale", feat_slider, "uiScale", 1.f, 2.f, 1.f));
			feature::map.emplace("FEATURE_I_MENU_PADDING_X",	 CMenu::addFeature(-1, *parent, "Padding X", feat_value, "uiPaddingX", 0.f, 4000.f, 50.f));
			feature::map.emplace("FEATURE_I_MENU_PADDING_Y",	 CMenu::addFeature(-1, *parent, "Padding Y", feat_value, "uiPaddingY", 0.f, 4000.f, 50.f));
			feature::map.emplace("FEATURE_I_SAVE_INI",	 CMenu::addFeature(-1, *parent, "Save settings to ini", feat_action));


		*parent	= CMenu::addFeature(1, -1, "Online Players", feat_parent);
		for(int i = 0; i < MAX_PLAYERS; i++)
		{
			featMap map;
		
			map.emplace("PLRFEAT_PARENT", CMenu::addFeature(-1, *parent, "!Invalid!", feat_parent));
				map.emplace("PLRFEAT_TRACK", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Track Player", feat_toggle));
				map.emplace("PLRFEAT_SPECTATE", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Spectate Player", feat_toggle));
				map.emplace("PLRFEAT_TP_TO", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Teleport to player", feat_action));
				map.emplace("PLRFEAT_TP_TO_CAR", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Teleport to vehicle", feat_action));
				map.emplace("PLRFEAT_TP_TO_ME", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Teleport to me", feat_action));
				map.emplace("PLRFEAT_TP_TO_SEA", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Teleport to sea", feat_action));
				map.emplace("PLRFEAT_TP_TO_AIR", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Teleport in the air", feat_action));
				map.emplace("PLRFEAT_EXPLODE", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Explode", feat_action_value_str, "", 0.f, (float) (sizeof(hash::explosion_enum) / sizeof(*hash::explosion_enum)) - 1, 1.f, hash::explosion_enum));
				map.emplace("PLRFEAT_GIVE_WEAPON", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Give Weapon", feat_action_value_str, "", 0.f, (float) (sizeof(hash::weapon_name) / sizeof(*hash::weapon_name)) - 1, 1.f, hash::weapon_name));
				map.emplace("PLRFEAT_GIVE_WEAPONS", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Give All Weapons", feat_action));
				map.emplace("PLRFEAT_REMOVE_WEAPONS", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Remove All Weapons", feat_action));
				map.emplace("PLRFEAT_CLONE_BODYGUARD", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Clone Bodyguard", feat_action));
				map.emplace("PLRFEAT_ATTACH_TO", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Attach To Player", feat_toggle));
				map.emplace("PLRFEAT_ATTACH_PIGGY_BACK", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Attach Piggy Back", feat_toggle));
				map.emplace("PLRFEAT_ATTACH_69", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Attach 69", feat_toggle));
				map.emplace("PLRFEAT_ATTACH_VIOLATE", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Attach Violate", feat_toggle));
				map.emplace("PLRFEAT_DETACH_ALL", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Detach All", feat_action));
				map.emplace("PLRFEAT_ATTACH_CLONE", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Attach Clone", feat_action_value, "", 1.f, 10.f, 1.f));
				map.emplace("PLRFEAT_ATTACH_CLONE_69", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Attach Clone 69", feat_action));
				map.emplace("PLRFEAT_ATTACH_OBJ_PARENT", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Attach Object", feat_parent));
				for(int j = 0; j < sizeof(hash::object_prop_attach_hash) / sizeof(hash::object_prop_attach_hash[0]); j++)
					CMenu::addFeature(-1, map["PLRFEAT_ATTACH_OBJ_PARENT"], hash::object_prop_attach_name[j], feat_attach, hash::object_prop_attach_hash[j], i);
				map.emplace("PLRFEAT_TRAP_IN_CAGE", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Trap In Cage", feat_action));
				map.emplace("PLRFEAT_CLEAR_TASKS", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Clear Tasks", feat_action));
				map.emplace("PLRFEAT_SHOOT", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Shoot", feat_action));
				map.emplace("PLRFEAT_CHRISFORMAGE", CMenu::addFeature(-1, map["PLRFEAT_PARENT"], "Send Chris Formage", feat_action));
			feature::player_map.emplace(i, map);
		}
	
		*parent	= CMenu::addFeature(1, -1, "All Players", feat_parent);
			feature::map.emplace("FEATURE_A_TRACK",	 CMenu::addFeature(-1, *parent, "Track", feat_toggle));
			feature::map.emplace("FEATURE_A_TP_TO_ME",	 CMenu::addFeature(-1, *parent, "Teleport to me", feat_action));
			feature::map.emplace("FEATURE_A_TP_TO_SEA",	 CMenu::addFeature(-1, *parent, "Teleport to sea", feat_action));
			feature::map.emplace("FEATURE_A_TP_TO_AIR",	 CMenu::addFeature(-1, *parent, "Teleport in the air", feat_action));
			feature::map.emplace("FEATURE_A_EXPLODE",	 CMenu::addFeature(-1, *parent, "Explode", feat_action_value_str, "", 0.f, (float) (sizeof(hash::explosion_enum) / sizeof(*hash::explosion_enum)) - 1, 1.f, hash::explosion_enum));
			feature::map.emplace("FEATURE_A_GIVE_WEAPON",	 CMenu::addFeature(-1, *parent, "Give Weapon", feat_action_value_str, "", 0.f, (float) (sizeof(hash::weapon_name) / sizeof(*hash::weapon_name)) - 1, 1.f, hash::weapon_name));
			feature::map.emplace("FEATURE_A_GIVE_WEAPONS",	 CMenu::addFeature(-1, *parent, "Give All Weapons", feat_action));
			feature::map.emplace("FEATURE_A_REMOVE_WEAPONS",	 CMenu::addFeature(-1, *parent, "Remove All Weapons", feat_action));
			feature::map.emplace("FEATURE_A_TRAP_IN_CAGE",	 CMenu::addFeature(-1, *parent, "Trap In Cage", feat_action));

		*parent	= CMenu::addFeature(1, -1, "ESP Options", feat_parent);
			feature::map.emplace("FEATURE_O_ESP_MAX_DIST",	 CMenu::addFeature(-1, *parent, "Max Distance", feat_action_value, "espMaxDist", 500.f, 10000.f, 500.f));
			feature::map.emplace("FEATURE_O_ESP_DIST",	 CMenu::addFeature(-1, *parent, "Display Distance", feat_toggle, "espDist"));
			feature::map.emplace("FEATURE_O_ESP_HEALTH",	 CMenu::addFeature(-1, *parent, "Display Health Bar", feat_toggle, "espHealth"));
			feature::map.emplace("FEATURE_O_ESP_BOX",	 CMenu::addFeature(-1, *parent, "Display Box", feat_toggle, "espBox"));

		feature::map.emplace("FEATURE_O_ATTACH_BONE", CMenu::addFeature(1, -1, "Attach Bone Index", feat_value_str, "boneAttach", 0.f, (float) (sizeof(hash::ped_bone_name) / sizeof(*hash::ped_bone_name)) - 1, 1.f, hash::ped_bone_name));
	
		*parent		= CMenu::addFeature(2, -1, "Vehicles", feat_parent);
			feature::map.emplace("FEATURE_S_VEH_MOD",	 CMenu::addFeature(-1, *parent, "Spawn Upgraded", feat_toggle, "spawnVehUpgrade"));
			feature::map.emplace("FEATURE_S_IN_VEHICLE",	 CMenu::addFeature(-1, *parent, "Spawn in Vehicle", feat_toggle, "spawnInVeh"));
			feature::map.emplace("FEATURE_S_SP_BYPASS",	 CMenu::addFeature(-1, *parent, "Allow MP vehicles in SP", feat_toggle, "spawnSPBypass"));
			feature::map.emplace("FEATURE_S_MP_BYPASS",	 CMenu::addFeature(-1, *parent, "Bypass MP vehicle kick", feat_toggle, "spawnMPBypass"));
			*(parent + 1)		= CMenu::addFeature(-1, *parent, "Sports", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_sport_hash) / sizeof(hash::vehicle_sport_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_sport_name[i], feat_spawn, hash::vehicle_sport_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Sports Classics", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_sport_classic_hash) / sizeof(hash::vehicle_sport_classic_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_sport_classic_name[i], feat_spawn, hash::vehicle_sport_classic_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Super", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_super_hash) / sizeof(hash::vehicle_super_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_super_name[i], feat_spawn, hash::vehicle_super_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Motorcyle", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_motorcycle_hash) / sizeof(hash::vehicle_motorcycle_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_motorcycle_name[i], feat_spawn, hash::vehicle_motorcycle_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "SUV", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_suv_hash) / sizeof(hash::vehicle_suv_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_suv_name[i], feat_spawn, hash::vehicle_suv_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Coupe", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_coupe_hash) / sizeof(hash::vehicle_coupe_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_coupe_name[i], feat_spawn, hash::vehicle_coupe_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Muscle", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_muscle_hash) / sizeof(hash::vehicle_muscle_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_muscle_name[i], feat_spawn, hash::vehicle_muscle_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Sedan", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_sedan_hash) / sizeof(hash::vehicle_sedan_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_sedan_name[i], feat_spawn, hash::vehicle_sedan_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Offroad", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_offroad_hash) / sizeof(hash::vehicle_offroad_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_offroad_name[i], feat_spawn, hash::vehicle_offroad_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Military", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_military_hash) / sizeof(hash::vehicle_military_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_military_name[i], feat_spawn, hash::vehicle_military_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Van", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_van_hash) / sizeof(hash::vehicle_van_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_van_name[i], feat_spawn, hash::vehicle_van_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Compact", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_compact_hash) / sizeof(hash::vehicle_compact_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_compact_name[i], feat_spawn, hash::vehicle_compact_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Service", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_service_hash) / sizeof(hash::vehicle_service_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_service_name[i], feat_spawn, hash::vehicle_service_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Commercial", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_commercial_hash) / sizeof(hash::vehicle_commercial_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_commercial_name[i], feat_spawn, hash::vehicle_commercial_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Utility", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_utility_hash) / sizeof(hash::vehicle_utility_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_utility_name[i], feat_spawn, hash::vehicle_utility_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Emergency", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_emergency_hash) / sizeof(hash::vehicle_emergency_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_emergency_name[i], feat_spawn, hash::vehicle_emergency_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Industrial", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_industrial_hash) / sizeof(hash::vehicle_industrial_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_industrial_name[i], feat_spawn, hash::vehicle_industrial_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Boats", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_boat_hash) / sizeof(hash::vehicle_boat_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_boat_name[i], feat_spawn, hash::vehicle_boat_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Plane", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_plane_hash) / sizeof(hash::vehicle_plane_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_plane_name[i], feat_spawn, hash::vehicle_plane_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Helicopter", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_helicopter_hash) / sizeof(hash::vehicle_helicopter_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_helicopter_name[i], feat_spawn, hash::vehicle_helicopter_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Trailer", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_trailer_hash) / sizeof(hash::vehicle_trailer_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_trailer_name[i], feat_spawn, hash::vehicle_trailer_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Train", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_train_hash) / sizeof(hash::vehicle_train_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_train_name[i], feat_spawn, hash::vehicle_train_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Cycle", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_cycle_hash) / sizeof(hash::vehicle_cycle_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_cycle_name[i], feat_spawn, hash::vehicle_cycle_hash[i], spwn_vehicle);

			*(parent + 1)			= CMenu::addFeature(-1, *parent, "Import/Export", feat_parent);
			for(int i = 0; i < sizeof(hash::vehicle_importexport_hash) / sizeof(hash::vehicle_importexport_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::vehicle_importexport_name[i], feat_spawn, hash::vehicle_importexport_hash[i], spwn_vehicle);

		*parent		= CMenu::addFeature(2, -1, "Peds", feat_parent);
			feature::map.emplace("FEATURE_S_PED_RANDOMIZE",	 CMenu::addFeature(-1, *parent, "Randomize Peds", feat_toggle, "spawnPedRandom"));
			feature::map.emplace("FEATURE_S_PED_TYPE",	 CMenu::addFeature(-1, *parent, "Type", feat_action_value_str, "spawnPedType", 0.f, 2.f, 1.f, hash::ped_spawn_type));
			feature::map.emplace("FEATURE_S_PED_CLEANUP",	 CMenu::addFeature(-1, *parent, "Cleanup", feat_toggle, "spawnPedCleanup"));
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Animals", feat_parent);
			for(int i = 0; i < sizeof(hash::ped_animal_hash) / sizeof(hash::ped_animal_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::ped_animal_name[i], feat_spawn, hash::ped_animal_hash[i], spwn_ped);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Emergency", feat_parent);
			for(int i = 0; i < sizeof(hash::ped_emergency_hash) / sizeof(hash::ped_emergency_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::ped_emergency_name[i], feat_spawn, hash::ped_emergency_hash[i], spwn_ped);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Sex Workers", feat_parent);
			for(int i = 0; i < sizeof(hash::ped_sex_hash) / sizeof(hash::ped_sex_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::ped_sex_name[i], feat_spawn, hash::ped_sex_hash[i], spwn_ped);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Story", feat_parent);
			for(int i = 0; i < sizeof(hash::ped_story_hash) / sizeof(hash::ped_story_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::ped_story_name[i], feat_spawn, hash::ped_story_hash[i], spwn_ped);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Misc", feat_parent);
			for(int i = 0; i < sizeof(hash::ped_misc_hash) / sizeof(hash::ped_misc_hash[0]); i++)
				CMenu::addFeature(-1, *(parent + 1), hash::ped_misc_name[i], feat_spawn, hash::ped_misc_hash[i], spwn_ped);

		*parent = CMenu::addFeature(2, -1, "Objects", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_hash) / sizeof(hash::object_prop_spawn_hash[0]); j++)
				CMenu::addFeature(-1, *parent, hash::object_prop_spawn_name[j], feat_spawn, hash::object_prop_spawn_hash[j], spwn_object);

		*parent	= CMenu::addFeature(2, -1, "Editor", feat_parent);
			feature::map.emplace("FEATURE_E_EDITOR_MODE",	 CMenu::addFeature(-1, *parent, "Editor Mode", feat_toggle, "editorEnable"));
			feature::map.emplace("FEATURE_E_DELETE",	 CMenu::addFeature(-1, *parent, "Delete", feat_action));
			feature::map.emplace("FEATURE_E_DISTANCE",	 CMenu::addFeature(-1, *parent, "Distance", feat_action_value, "editorDist", 10.f, 50.f, 5.f));
			feature::map.emplace("FEATURE_E_TEXT_TYPE",	 CMenu::addFeature(-1, *parent, "Display Type", feat_toggle, "editorTxtType"));
			feature::map.emplace("FEATURE_E_TEXT_POS",	 CMenu::addFeature(-1, *parent, "Display Coords", feat_toggle, "editorTxtPos"));
			feature::map.emplace("FEATURE_E_FREEZE",	 CMenu::addFeature(-1, *parent, "Freeze Position", feat_toggle, "editorFreeze"));
			feature::map.emplace("FEATURE_E_INVISIBLE",	 CMenu::addFeature(-1, *parent, "Invisible", feat_toggle, "editorInvis"));
			feature::map.emplace("FEATURE_E_COLLISION",	 CMenu::addFeature(-1, *parent, "Disable Collision", feat_toggle, "editorCollision"));
			feature::map.emplace("FEATURE_E_ROTATION_ENABLE",	 CMenu::addFeature(-1, *parent, "Enable Rotation", feat_toggle, "editorRotEnable"));
			feature::map.emplace("FEATURE_E_ROTATION_RELATIVE",	 CMenu::addFeature(-1, *parent, "Relative Rotation ", feat_toggle, "editorRotRelative"));
			feature::map.emplace("FEATURE_E_ROTATION_X",	 CMenu::addFeature(-1, *parent, "Rotation X", feat_action_value, "editorRotX", 0.f, 355.f, 5.f));
			feature::map.emplace("FEATURE_E_ROTATION_Y",	 CMenu::addFeature(-1, *parent, "Rotation Y", feat_action_value, "editorRotY", 0.f, 355.f, 5.f));
			feature::map.emplace("FEATURE_E_ROTATION_Z",	 CMenu::addFeature(-1, *parent, "Rotation Z", feat_action_value, "editorRotZ", 0.f, 355.f, 5.f));
			feature::map.emplace("FEATURE_E_THROW_MODE",	 CMenu::addFeature(-1, *parent, "Enable Trow Mode", feat_toggle, "editorThrow"));


		CMenu::setActiveCat(0);
	}
};