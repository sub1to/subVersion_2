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
		R	Recovery
		D	Protection (defense)
		*/

		*parent	= CMenu::addFeature(0, -1, "Player Options", feat_parent);
			//CMenu::indexFeature(FEATURE_P_TRUEGOD, CMenu::addFeature(-1, *parent, "God", feat_toggle, "trueGodMode"));
			CMenu::indexFeature(FEATURE_P_TRUEGOD, CMenu::addFeature(-1, *parent, "God", feat_toggle, "trueGodMode"));
			CMenu::indexFeature(FEATURE_P_GOD, CMenu::addFeature(-1, *parent, "Demi-God", feat_toggle, "godMode"));
			CMenu::indexFeature(FEATURE_P_QUICK_REGEN, CMenu::addFeature(-1, *parent, "Quick Regen", feat_value, "quickRegen", 1.f, 25.f, 2.f));
			CMenu::indexFeature(FEATURE_P_INVISIBLE, CMenu::addFeature(-1, *parent, "Invisible", feat_toggle, "playerInvis"));
			CMenu::indexFeature(FEATURE_P_VISIBLE_LOCAL, CMenu::addFeature(-1, *parent, "Player Visible Locally", feat_toggle, "playerVisLoc"));
			CMenu::indexFeature(FEATURE_P_OFFRADAR, CMenu::addFeature(-1, *parent, "Off Radar", feat_toggle));
			CMenu::indexFeature(FEATURE_P_GIVE_HEALTH, CMenu::addFeature(-1, *parent, "Give Health", feat_action));
			CMenu::indexFeature(FEATURE_P_CLEAN_PLAYER, CMenu::addFeature(-1, *parent, "Clean", feat_action));
			CMenu::indexFeature(FEATURE_P_WANTED, CMenu::addFeature(-1, *parent, "Wanted", feat_slider, "wanted", 0.f, 5.f, .2f));
			CMenu::indexFeature(FEATURE_P_NEVERWANTED, CMenu::addFeature(-1, *parent, "Never Wanted", feat_toggle, "neverWanted"));
			CMenu::indexFeature(FEATURE_P_ANTINPC, CMenu::addFeature(-1, *parent, "Anti NPC", feat_toggle, "antiNpc"));
			CMenu::indexFeature(FEATURE_P_SUPER_RUN, CMenu::addFeature(-1, *parent, "Super Run", feat_slider, "superRun", 1.f, 2.f));
			CMenu::indexFeature(FEATURE_P_RUNSPD, CMenu::addFeature(-1, *parent, "Run Speed", feat_slider, "runSpd", 1.f, 5.f));
			CMenu::indexFeature(FEATURE_P_SWIMSPD, CMenu::addFeature(-1, *parent, "Swim Speed", feat_slider, "swimSpd", 1.f, 5.f));
			CMenu::indexFeature(FEATURE_P_SUPERJUMP, CMenu::addFeature(-1, *parent, "Super Jump", feat_toggle, "superJump"));
			CMenu::indexFeature(FEATURE_P_EXPLOSIVEMELEE, CMenu::addFeature(-1, *parent, "Explosive Melee", feat_toggle, "explMelee"));
			CMenu::indexFeature(FEATURE_P_SEATBELT, CMenu::addFeature(-1, *parent, "Seatbelt", feat_toggle, "seatbelt"));
			CMenu::indexFeature(FEATURE_P_NORAGDOLL, CMenu::addFeature(-1, *parent, "No Ragdoll", feat_toggle, "noRagdoll"));
			CMenu::indexFeature(FEATURE_P_STAMINA, CMenu::addFeature(-1, *parent, "Infinite Stamina", feat_toggle, "infStam"));
			CMenu::indexFeature(FEATURE_P_MOBILE_RADIO, CMenu::addFeature(-1, *parent, "Mobile Radio", feat_toggle, "mobileRadio"));
			CMenu::indexFeature(FEATURE_P_FREEZE_RADIO, CMenu::addFeature(-1, *parent, "Freeze Radio", feat_value_str, "freezeRadio", 0.f, 19.f, 1.f, hash::radio_station_name));
			//CMenu::indexFeature(FEATURE_P_CLEAR_REPORTS, CMenu::addFeature(-1, *parent, "Clear Reports", feat_action));
			CMenu::indexFeature(FEATURE_P_CLONE_BODYGUARD, CMenu::addFeature(-1, *parent, "Clone Bodyguard", feat_action));
			//CMenu::indexFeature(FEATURE_P_CLEANUP_OBJECTS, CMenu::addFeature(-1, *parent, "Cleanup Objects", feat_action));
			//CMenu::indexFeature(FEATURE_P_ANTI_AFK, CMenu::addFeature(-1, *parent, "Anti AFK", feat_value_str, "", 0.f, (float) (sizeof(hash::anti_afk_name) / sizeof(*hash::anti_afk_name)) - 1, 1.f, hash::anti_afk_name));
			CMenu::indexFeature(FEATURE_P_TINY, CMenu::addFeature(-1, *parent, "Tiny Player", feat_toggle));
			//CMenu::indexFeature(FEATURE_P_TEST, CMenu::addFeature(-1, *parent, "TEST!!@", feat_action));
			//CMenu::indexFeature(FEATURE_P_TEST2, CMenu::addFeature(-1, *parent, "TEST2!!@", feat_toggle));

		*parent	= CMenu::addFeature(0, -1, "Vehicle Options", feat_parent);
			CMenu::indexFeature(FEATURE_V_TRUEGOD, CMenu::addFeature(-1, *parent, "God", feat_toggle, "vehTrueGodMode"));
			CMenu::indexFeature(FEATURE_V_GOD, CMenu::addFeature(-1, *parent, "Demi-God", feat_toggle, "vehGodMode"));
			CMenu::indexFeature(FEATURE_V_REPAIR, CMenu::addFeature(-1, *parent, "Repair", feat_action));
			CMenu::indexFeature(FEATURE_V_UPGRADE, CMenu::addFeature(-1, *parent, "Upgrade", feat_action));
			CMenu::indexFeature(FEATURE_V_FLIP, CMenu::addFeature(-1, *parent, "Flip", feat_action));
			CMenu::indexFeature(FEATURE_V_STICK_TO_GROUND, CMenu::addFeature(-1, *parent, "Stick to Ground", feat_toggle, "vehStickGround"));
			CMenu::indexFeature(FEATURE_V_BOOST, CMenu::addFeature(-1, *parent, "Boost", feat_action_value, "vehImpulse", 0.f, 200.f, 20.f));
			CMenu::indexFeature(FEATURE_V_STOP, CMenu::addFeature(-1, *parent, "Stop", feat_action));
			CMenu::indexFeature(FEATURE_V_INVISIBLE, CMenu::addFeature(-1, *parent, "Invisible", feat_toggle, "vehicleInvis"));
			CMenu::indexFeature(FEATURE_V_RAINBOW, CMenu::addFeature(-1, *parent, "Rainbow Car", feat_toggle, "vehRainbow"));
			CMenu::indexFeature(FEATURE_V_COLOR_PRESET, CMenu::addFeature(-1, *parent, "Colors Primary", feat_action_value_str, "vehPresetColor", 0.f, (float) get_array_size(hash::veh_color_enum) - 1, 1.f, hash::veh_color_enum));
			CMenu::indexFeature(FEATURE_V_COLOR_PRESET2, CMenu::addFeature(-1, *parent, "Colors Secondary", feat_action_value_str, "vehPresetColor2", 0.f, (float) get_array_size(hash::veh_color_enum) - 1, 1.f, hash::veh_color_enum));
			CMenu::indexFeature(FEATURE_V_BULLETPROOFTIRES, CMenu::addFeature(-1, *parent, "Bulletproof Tires", feat_toggle, "vehBulletproofTires"));
			CMenu::indexFeature(FEATURE_V_DEFORMATION, CMenu::addFeature(-1, *parent, "Deformation", feat_slider, "vehDeform", 0.f, 1.f));
			CMenu::indexFeature(FEATURE_V_ACCELERATION, CMenu::addFeature(-1, *parent, "Acceleration", feat_slider, "vehAccel", 1.f, 10.f, .05f));
			CMenu::indexFeature(FEATURE_V_UPSHIFT, CMenu::addFeature(-1, *parent, "Up-Shift Rate", feat_slider, "vehUpShift", 1.f, 25.f, .05f));
			CMenu::indexFeature(FEATURE_V_BRAKEFORCE, CMenu::addFeature(-1, *parent, "Brake force", feat_slider, "vehBrakeForce", 1.f, 10.f, .05f));
			CMenu::indexFeature(FEATURE_V_TRACTION, CMenu::addFeature(-1, *parent, "Traction", feat_slider, "vehTraction", 1.f, 2.f, .05f));
			CMenu::indexFeature(FEATURE_V_GRAVITY, CMenu::addFeature(-1, *parent, "Gravity", feat_slider, "vehGravity", 0.f, 25.f));
			CMenu::indexFeature(FEATURE_V_SUSPENSION_FORCE, CMenu::addFeature(-1, *parent, "Suspension Force", feat_slider, "vehSuspensionForce", 0.f, 2.f, .05f));
			CMenu::indexFeature(FEATURE_V_VOLTIC_BOOST, CMenu::addFeature(-1, *parent, "Infinite Voltic Boost", feat_toggle));
			CMenu::indexFeature(FEATURE_V_INF_CAR_ALARM, CMenu::addFeature(-1, *parent, "Infinite Alarm", feat_toggle, "vehInfAlarm"));
			CMenu::indexFeature(FEATURE_V_LICENSE, CMenu::addFeature(-1, *parent, "Change License", feat_action));

		*parent		= CMenu::addFeature(0, -1, "Model Changer", feat_parent);
			//CMenu::indexFeature(FEATURE_M_RANDOMIZE_PED, CMenu::addFeature(-1, *parent, "Randomize Peds", feat_toggle, "randomModel"));
			CMenu::addFeature(-1, *parent, "MP Female", feat_spawn, 0x9c9effd8, spwn_model); //"MP_F_Freemode_01"
			CMenu::addFeature(-1, *parent, "MP Male", feat_spawn, 0x705e61f2, spwn_model); //"MP_M_Freemode_01"
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

		*parent		= CMenu::addFeature(0, -1, "Outfits", feat_parent);
			CMenu::indexFeature(FEATURE_C_SANTA, CMenu::addFeature(-1, *parent, "Santa", feat_action));
			CMenu::indexFeature(FEATURE_C_TRASH_ORANGE, CMenu::addFeature(-1, *parent, "Trash Orange", feat_action));
			CMenu::indexFeature(FEATURE_C_TRASH_GREEN, CMenu::addFeature(-1, *parent, "Trash Green", feat_action));
			CMenu::indexFeature(FEATURE_C_POLICE, CMenu::addFeature(-1, *parent, "Police", feat_action));

		*parent		= CMenu::addFeature(0, -1, "Animations", feat_parent);
			CMenu::indexFeature(FEATURE_U_STOP_ANIM, CMenu::addFeature(-1, *parent, "Stop", feat_action));
			for(int i = 0; i < sizeof(hash::ped_anim_name) / sizeof(hash::ped_anim_name[0]); i++)
				CMenu::addFeature(-1, *parent, hash::ped_anim_name[i], feat_anim, hash::ped_anim_dict[i * 2], hash::ped_anim_dict[i * 2 + 1]);

		*parent	= CMenu::addFeature(0, -1, "Teleport", feat_parent);
			CMenu::indexFeature(FEATURE_TP_WAYPOINT, CMenu::addFeature(-1, *parent, "Waypoint", feat_action));
			CMenu::indexFeature(FEATURE_TP_OBJECTIVE, CMenu::addFeature(-1, *parent, "Objective", feat_action));
			CMenu::indexFeature(FEATURE_TP_PERSONAL_VEH, CMenu::addFeature(-1, *parent, "Personal Vehicle", feat_action));
			CMenu::indexFeature(FEATURE_TP_NEARBY_CAR, CMenu::addFeature(-1, *parent, "Nearby car", feat_action));

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
			CMenu::addFeature(-1, *parent, "Maze Bank Top", feat_teleport, tp_static, -75.3923f, -819.27044f, 327.17520f);
			CMenu::addFeature(-1, *parent, "Vinewood Sign", feat_teleport, tp_static, 735.02979f, 1195.03259f, 348.38156f);
			CMenu::addFeature(-1, *parent, "Military Base", feat_teleport, tp_static, -2177.79102f, 3236.65381f, 33.81028f);
			CMenu::addFeature(-1, *parent, "High in the air", feat_teleport, tp_static, 1273.44470f, 3084.96997f, 1845.83130f);

		*parent	= CMenu::addFeature(0, -1, "Weapons", feat_parent);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Weapon Modifiers", feat_parent);
			CMenu::indexFeature(FEATURE_W_SPREAD, CMenu::addFeature(-1, *(parent + 1), "No Spread", feat_toggle, "noSpread"));	
			CMenu::indexFeature(FEATURE_W_RECOIL, CMenu::addFeature(-1, *(parent + 1), "No Recoil", feat_toggle, "noRecoil"));	
			CMenu::indexFeature(FEATURE_W_RELOAD, CMenu::addFeature(-1, *(parent + 1), "Quick Reload", feat_slider, "quickReload", 1.f, 10.f, .05f));
			CMenu::indexFeature(FEATURE_W_DAMAGE, CMenu::addFeature(-1, *(parent + 1), "Bullet Damage", feat_slider, "bulletDamage", 1.f, 10.f, .05f));
			CMenu::indexFeature(FEATURE_W_AMMO, CMenu::addFeature(-1, *(parent + 1), "Infinite Ammo", feat_toggle, "infAmmo"));
			CMenu::indexFeature(FEATURE_W_NO_RELOAD, CMenu::addFeature(-1, *(parent + 1), "No Reload", feat_toggle, "noReload"));
			//CMenu::indexFeature(FEATURE_W_RANGE, CMenu::addFeature(-1, *(parent + 1), "Range", feat_slider, "weapRange", 1.f, 10.f));
			CMenu::indexFeature(FEATURE_W_SPINUP, CMenu::addFeature(-1, *(parent + 1), "No Spin-Up", feat_toggle, "weapSpin"));
			//CMenu::indexFeature(FEATURE_W_EXPLOSIVEAMMO, CMenu::addFeature(-1, *(parent + 1), "Explosive Ammo", feat_toggle, "explAmmo"));
			CMenu::indexFeature(FEATURE_W_EXPLOSIVEAMMO, CMenu::addFeature(-1, *(parent + 1), "Explosive Ammo", feat_value_str, "", 0.f, (float) get_array_size(hash::explosion_enum) - 1, 1.f, hash::explosion_enum));
			CMenu::indexFeature(FEATURE_W_FIREAMMO, CMenu::addFeature(-1, *(parent + 1), "Fire Ammo", feat_toggle, "fireAmmo"));
			//CMenu::indexFeature(FEATURE_W_BULLET_BATCH, CMenu::addFeature(-1, *(parent + 1), "Bullet Batch", feat_slider, "bulletBatch", 1.f, 10.f, (float) 1.f / 9.f));
			//CMenu::indexFeature(FEATURE_W_BATCH_SPREAD, CMenu::addFeature(-1, *(parent + 1), "Batch Spread", feat_slider, "batchSpread", 0.f, 0.12f));
			//CMenu::indexFeature(FEATURE_W_MUZZLE_VELOCITY, CMenu::addFeature(-1, *(parent + 1), "Muzzle Velocity", feat_slider, "muzzleVelo", 1.f, 10.f));

			*(parent + 1) = CMenu::addFeature(-1, *parent, "Give Weapons", feat_parent);
				CMenu::addFeature(-1, *(parent + 1), "Give All", feat_spawn, 0, spwn_weapon_all);
				for(int i = 0; i < get_array_size(hash::weapon_hash); i++)
					CMenu::addFeature(-1, *(parent + 1), hash::weapon_name[i], feat_spawn, hash::weapon_hash[i], spwn_weapon);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Remove Weapons", feat_parent);
				CMenu::addFeature(-1, *(parent + 1), "Remove All", feat_spawn, 0, dspwn_weapon_all);
				for(int i = 0; i < get_array_size(hash::weapon_hash); i++)
					CMenu::addFeature(-1, *(parent + 1), hash::weapon_name[i], feat_spawn, hash::weapon_hash[i], dspwn_weapon);

			CMenu::indexFeature(FEATURE_W_TRIGGERBOT, CMenu::addFeature(-1, *parent, "Trigger Bot", feat_value_str, "trgBot", 0.f, 1.f, 1.f, hash::triggerbot_enum));

		*parent	= CMenu::addFeature(0, -1, "Weather & Time", feat_parent);
			CMenu::indexFeature(FEATURE_T_PAUSE_CLOCK, CMenu::addFeature(-1, *parent, "Pause Clock", feat_toggle, "timePause"));
			CMenu::indexFeature(FEATURE_T_SET_HOUR, CMenu::addFeature(-1, *parent, "Set Hour", feat_action_value, "timeHour", 0.f, 23.f, 1.f));
			CMenu::indexFeature(FEATURE_T_SET_MIN, CMenu::addFeature(-1, *parent, "Set Minute", feat_action_value, "timeMin", 0.f, 55.f, 5.f));
			CMenu::indexFeature(FEATURE_T_WEATHER, CMenu::addFeature(-1, *parent, "Weather", feat_action_value_str, "", 0.f, 11.f, 1.f, hash::weather_enum));

		*parent	= CMenu::addFeature(0, -1, "Recovery", feat_parent);
			CMenu::indexFeature(FEATURE_R_RP_LOOP, CMenu::addFeature(-1, *parent, "RP Loop", feat_toggle));
			CMenu::indexFeature(FEATURE_R_STEALTH_MONEY, CMenu::addFeature(-1, *parent, "Stealth Give Money", feat_action_value, "stealthMoney", 5.f, 50.f, 5.f));
			CMenu::indexFeature(FEATURE_R_STEALTH_MONEY_REMOVE, CMenu::addFeature(-1, *parent, "Stealth Remove Money", feat_action_value, "stealthMoneyRemove", 5.f, 50.f, 5.f));
			CMenu::indexFeature(FEATURE_R_UNLOCK_STAT, CMenu::addFeature(-1, *parent, "Stat Unlocks", feat_action));
			CMenu::indexFeature(FEATURE_R_UNLOCK_TATTOO, CMenu::addFeature(-1, *parent, "Tattoo Unlocks", feat_action));
			CMenu::indexFeature(FEATURE_R_UNLOCK_PARACHUTE, CMenu::addFeature(-1, *parent, "Parachute Unlocks", feat_action));
			CMenu::indexFeature(FEATURE_R_UNLOCK_RIMS, CMenu::addFeature(-1, *parent, "Rims Unlocks", feat_action));
			CMenu::indexFeature(FEATURE_R_UNLOCK_VEHICLE, CMenu::addFeature(-1, *parent, "Vehicle Unlocks", feat_action));
			CMenu::indexFeature(FEATURE_R_UNLOCK_TROPHY, CMenu::addFeature(-1, *parent, "Trophy Unlocks", feat_action));
			CMenu::indexFeature(FEATURE_R_UNLOCK_HAIRSTYLE, CMenu::addFeature(-1, *parent, "Hairstyle Unlocks", feat_action));
			CMenu::indexFeature(FEATURE_R_UNLOCK_WEAPON, CMenu::addFeature(-1, *parent, "Weapon Unlocks", feat_action));
			CMenu::indexFeature(FEATURE_R_UNLOCK_CLOTHING, CMenu::addFeature(-1, *parent, "Clothing Unlocks", feat_action));

		*parent	= CMenu::addFeature(0, -1, "Protections", feat_parent);
			CMenu::indexFeature(FEATURE_D_CRASH, CMenu::addFeature(-1, *parent, "Crash", feat_toggle, "protCrash"));
			CMenu::indexFeature(FEATURE_D_REQUEST_CONTROL, CMenu::addFeature(-1, *parent, "Request Control", feat_toggle, "protRequestControl"));
			CMenu::indexFeature(FEATURE_D_KICK, CMenu::addFeature(-1, *parent, "Kick", feat_toggle, "protKick"));
			CMenu::indexFeature(FEATURE_D_TELEPORT, CMenu::addFeature(-1, *parent, "Teleport", feat_toggle, "protTele"));
			CMenu::indexFeature(FEATURE_D_CLEAR_TASKS, CMenu::addFeature(-1, *parent, "Clear Ped Tasks", feat_toggle, "protClearTasks"));
			CMenu::indexFeature(FEATURE_D_EXPLOSION, CMenu::addFeature(-1, *parent, "Explosion", feat_toggle, "protExplosion"));
			CMenu::indexFeature(FEATURE_D_FIRE, CMenu::addFeature(-1, *parent, "Fire", feat_toggle, "protFire"));
			CMenu::indexFeature(FEATURE_D_REMOVE_WEAPONS, CMenu::addFeature(-1, *parent, "Remove Weapons", feat_toggle, "protRemoveWeapons"));

		*parent	= CMenu::addFeature(0, -1, "Misc", feat_parent);
			CMenu::indexFeature(FEATURE_U_NAME_CHANGER, CMenu::addFeature(-1, *parent, "Name Changer", feat_action));
			CMenu::indexFeature(FEATURE_U_NOCLIP, CMenu::addFeature(-1, *parent, "No Clip", feat_value_str, "noclip", 0.f, 1.f, 1.f, hash::noclip_type));
			CMenu::indexFeature(FEATURE_U_NOCLIP_SPEED, CMenu::addFeature(-1, *parent, "No Clip Speed", feat_action_value, "noclipSpeed", 1.f, 10.f, 1.f));
			CMenu::indexFeature(FEATURE_U_CHAOS_MODE, CMenu::addFeature(-1, *parent, "Chaos Mode", feat_value_str, "", 0.f, (float) get_array_size(hash::chaos_mode_type) - 1, 1.f, hash::chaos_mode_type));
			CMenu::indexFeature(FEATURE_U_SMASH_VEHICLES, CMenu::addFeature(-1, *parent, "Smash Vehicles", feat_action));
			CMenu::indexFeature(FEATURE_U_BLACK_HOLE, CMenu::addFeature(-1, *parent, "Black Hole", feat_action_value, "blackHole", 30.f, 120.f, 10.f));
			CMenu::indexFeature(FEATURE_U_PED_DROP, CMenu::addFeature(-1, *parent, "Ped Drop", feat_toggle));
			CMenu::indexFeature(FEATURE_U_MONEY_DROP_2K, CMenu::addFeature(-1, *parent, "2K Drops", feat_value_str, "", 0.f, (float) get_array_size(hash::object_prop_money_name) - 1, 1.f, hash::object_prop_money_name));
			CMenu::indexFeature(FEATURE_U_MONEY_DROP_40K, CMenu::addFeature(-1, *parent, "40K Drops", feat_toggle));
			CMenu::indexFeature(FEATURE_U_CLEAN_SESSION, CMenu::addFeature(-1, *parent, "Clean Session (Lag switch)", feat_action));

		*parent	= CMenu::addFeature(0, -1, "Interface", feat_parent);
			CMenu::indexFeature(FEATURE_I_FPS_COUNTER, CMenu::addFeature(-1, *parent, "Fps Counter", feat_toggle, "uiFps"));
			CMenu::indexFeature(FEATURE_I_SPEED_O_METER, CMenu::addFeature(-1, *parent, "Speed-O-Meter", feat_toggle, "uiSpeedo"));
			//CMenu::indexFeature(FEATURE_I_MENU_SCALE, CMenu::addFeature(-1, *parent, "Menu Scale", feat_slider, "uiScale", 1.f, 2.f, 1.f));
			CMenu::indexFeature(FEATURE_I_MENU_PADDING_X, CMenu::addFeature(-1, *parent, "Padding X", feat_menu_option, menu_padding, "uiPaddingX", 25.f, 2000.f, 25.f, &CRender::m_screen.x));
			CMenu::indexFeature(FEATURE_I_MENU_PADDING_Y, CMenu::addFeature(-1, *parent, "Padding Y", feat_menu_option, menu_padding, "uiPaddingY", 25.f, 1000.f, 25.f, &CRender::m_screen.y));
			CMenu::indexFeature(FEATURE_I_SAVE_INI, CMenu::addFeature(-1, *parent, "Save settings to ini", feat_action));
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Custom Crosshair", feat_parent);
				CMenu::indexFeature(FEATURE_I_CUSTOM_XHAIR, CMenu::addFeature(-1, *(parent + 1), "Crosshair Enable", feat_value_str, "uiXHairEnable", 0.f, (float) get_array_size(hash::crosshair_type) - 1, 1.f, hash::crosshair_type));
				CMenu::indexFeature(FEATURE_I_CUSTOM_XHAIR_SIZE, CMenu::addFeature(-1, *(parent + 1), "Crosshair Size", feat_action_value, "uiXHairSize", 5.f, 45.f, 2.f));
				CMenu::indexFeature(FEATURE_I_CUSTOM_XHAIR_THICKNESS, CMenu::addFeature(-1, *(parent + 1), "Crosshair Thickness", feat_action_value, "uiXHairThickness", 1.f, 10.f, 1.f));
				CMenu::indexFeature(FEATURE_I_CUSTOM_XHAIR_COL_R, CMenu::addFeature(-1, *(parent + 1), "Crosshair Color Red", feat_action_value, "uiXHairColR", 0.f, 255.f, 5.f));
				CMenu::indexFeature(FEATURE_I_CUSTOM_XHAIR_COL_G, CMenu::addFeature(-1, *(parent + 1), "Crosshair Color Green", feat_action_value, "uiXHairColG", 0.f, 255.f, 5.f));
				CMenu::indexFeature(FEATURE_I_CUSTOM_XHAIR_COL_B, CMenu::addFeature(-1, *(parent + 1), "Crosshair Color Blue", feat_action_value, "uiXHairColB", 0.f, 255.f, 5.f));
				CMenu::indexFeature(FEATURE_I_CUSTOM_XHAIR_COL_A, CMenu::addFeature(-1, *(parent + 1), "Crosshair Color Alpha", feat_action_value, "uiXHairColA", 0.f, 255.f, 5.f));
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Menu Colors", feat_parent);
				CMenu::indexFeature(FEATURE_I_MENU_COLOR1_R, CMenu::addFeature(-1, *(parent + 1), "Color 1 Red", feat_menu_option, menu_color, "uiMenuColor1R", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_BACKGROUND.r));
				CMenu::indexFeature(FEATURE_I_MENU_COLOR1_G, CMenu::addFeature(-1, *(parent + 1), "Color 1 Green", feat_menu_option, menu_color, "uiMenuColor1G", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_BACKGROUND.g));
				CMenu::indexFeature(FEATURE_I_MENU_COLOR1_B, CMenu::addFeature(-1, *(parent + 1), "Color 1 Blue", feat_menu_option, menu_color, "uiMenuColor1B", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_BACKGROUND.b));
				CMenu::indexFeature(FEATURE_I_MENU_COLOR2_R, CMenu::addFeature(-1, *(parent + 1), "Color 2 Red", feat_menu_option, menu_color, "uiMenuColor2R", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_BORDER.r));
				CMenu::indexFeature(FEATURE_I_MENU_COLOR2_G, CMenu::addFeature(-1, *(parent + 1), "Color 2 Green", feat_menu_option, menu_color, "uiMenuColor2G", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_BORDER.g));
				CMenu::indexFeature(FEATURE_I_MENU_COLOR2_B, CMenu::addFeature(-1, *(parent + 1), "Color 2 Blue", feat_menu_option, menu_color, "uiMenuColor2B", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_BORDER.b));
				CMenu::indexFeature(FEATURE_I_MENU_SEL_COLOR1_R, CMenu::addFeature(-1, *(parent + 1), "Color Selected 1 Red", feat_menu_option, menu_color, "uiMenuSelColor1R", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_ACTIVE_BG.r));
				CMenu::indexFeature(FEATURE_I_MENU_SEL_COLOR1_G, CMenu::addFeature(-1, *(parent + 1), "Color Selected 1 Green", feat_menu_option, menu_color, "uiMenuSelColor1G", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_ACTIVE_BG.g));
				CMenu::indexFeature(FEATURE_I_MENU_SEL_COLOR1_B, CMenu::addFeature(-1, *(parent + 1), "Color Selected 1 Blue", feat_menu_option, menu_color, "uiMenuSelColor1B", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_ACTIVE_BG.b));
				CMenu::indexFeature(FEATURE_I_MENU_SEL_COLOR2_R, CMenu::addFeature(-1, *(parent + 1), "Color Selected 2 Red", feat_menu_option, menu_color, "uiMenuSelColor2R", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_SELECTED.r));
				CMenu::indexFeature(FEATURE_I_MENU_SEL_COLOR2_G, CMenu::addFeature(-1, *(parent + 1), "Color Selected 2 Green", feat_menu_option, menu_color, "uiMenuSelColor2G", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_SELECTED.g));
				CMenu::indexFeature(FEATURE_I_MENU_SEL_COLOR2_B, CMenu::addFeature(-1, *(parent + 1), "Color Selected 2 Blue", feat_menu_option, menu_color, "uiMenuSelColor2B", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_SELECTED.b));
				CMenu::indexFeature(FEATURE_I_MENU_SLDR_COLOR1_R, CMenu::addFeature(-1, *(parent + 1), "Color Slider 1 Red", feat_menu_option, menu_color, "uiMenuSldrColor1R", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_SLIDER_BG.r));
				CMenu::indexFeature(FEATURE_I_MENU_SLDR_COLOR1_G, CMenu::addFeature(-1, *(parent + 1), "Color Slider 1 Green", feat_menu_option, menu_color, "uiMenuSldrColor1G", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_SLIDER_BG.g));
				CMenu::indexFeature(FEATURE_I_MENU_SLDR_COLOR1_B, CMenu::addFeature(-1, *(parent + 1), "Color Slider 1 Blue", feat_menu_option, menu_color, "uiMenuSldrColor1B", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_SLIDER_BG.b));
				CMenu::indexFeature(FEATURE_I_MENU_SLDR_COLOR2_R, CMenu::addFeature(-1, *(parent + 1), "Color Slider 2 Red", feat_menu_option, menu_color, "uiMenuSldrColor2R", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_SLIDER_BTN.r));
				CMenu::indexFeature(FEATURE_I_MENU_SLDR_COLOR2_G, CMenu::addFeature(-1, *(parent + 1), "Color Slider 2 Green", feat_menu_option, menu_color, "uiMenuSldrColor2G", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_SLIDER_BTN.g));
				CMenu::indexFeature(FEATURE_I_MENU_SLDR_COLOR2_B, CMenu::addFeature(-1, *(parent + 1), "Color Slider 2 Blue", feat_menu_option, menu_color, "uiMenuSldrColor2B", 0.f, 255.f, 5.f, &CRender::LAYOUT_COLOR_SLIDER_BTN.b));


		*parent	= CMenu::addFeature(1, -1, "Online Players", feat_parent);
		for(int i = 0; i < MAX_PLAYERS; i++)
		{
			*(parent + 1)	= CMenu::addFeature(-1, *parent, "!Invalid!", feat_parent);
			CMenu::indexPlrFeature(PLRFEAT_PARENT, i, *(parent + 1));
				*(parent + 2)	= CMenu::addFeature(-1, *(parent + 1), "Player Info", feat_parent);
				CMenu::indexPlrFeature(PLRFEAT_INFO, i, *(parent + 2));
					CMenu::indexPlrFeature(PLRFEAT_INFO_NAME, i, CMenu::addFeature(-1, *(parent + 2), "Name: ", feat_action));
					CMenu::indexPlrFeature(PLRFEAT_INFO_IP, i, CMenu::addFeature(-1, *(parent + 2), "IP: ", feat_action));
					CMenu::indexPlrFeature(PLRFEAT_INFO_PORT, i, CMenu::addFeature(-1, *(parent + 2), "Port: ", feat_action));
					CMenu::indexPlrFeature(PLRFEAT_INFO_COORDS, i, CMenu::addFeature(-1, *(parent + 2), "Coords: ", feat_action));
					CMenu::indexPlrFeature(PLRFEAT_INFO_DISTANCE, i, CMenu::addFeature(-1, *(parent + 2), "Distance: ", feat_action));
					CMenu::indexPlrFeature(PLRFEAT_INFO_HEALTH, i, CMenu::addFeature(-1, *(parent + 2), "Hp/Armor: ", feat_action));
					CMenu::indexPlrFeature(PLRFEAT_INFO_IS_IN_VEH, i, CMenu::addFeature(-1, *(parent + 2), "In Vehicle: ", feat_action));
					CMenu::indexPlrFeature(PLRFEAT_INFO_IS_GOD, i, CMenu::addFeature(-1, *(parent + 2), "Is God: ", feat_action));
					CMenu::indexPlrFeature(PLRFEAT_INFO_WANTED, i, CMenu::addFeature(-1, *(parent + 2), "Wanted Level: ", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_TRACK, i, CMenu::addFeature(-1, *(parent + 1), "Track Player", feat_toggle));
				CMenu::indexPlrFeature(PLRFEAT_SPECTATE, i, CMenu::addFeature(-1, *(parent + 1), "Spectate Player", feat_toggle));
				CMenu::indexPlrFeature(PLRFEAT_PED_DROP, i, CMenu::addFeature(-1, *(parent + 1), "Ped Drop", feat_toggle));
				CMenu::indexPlrFeature(PLRFEAT_MONEY_DROP_2K, i, CMenu::addFeature(-1, *(parent + 1), "2K Drops", feat_value_str, "", 0.f, (float) get_array_size(hash::object_prop_money_name) - 1, 1.f, hash::object_prop_money_name));
				CMenu::indexPlrFeature(PLRFEAT_MONEY_DROP_40K, i, CMenu::addFeature(-1, *(parent + 1), "40K Drops", feat_toggle));
				CMenu::indexPlrFeature(PLRFEAT_SECURO_50K, i, CMenu::addFeature(-1, *(parent + 1), "SecuroServ 50K/s", feat_toggle));
				CMenu::indexPlrFeature(PLRFEAT_TP_TO, i, CMenu::addFeature(-1, *(parent + 1), "Teleport to player", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_TP_TO_CAR, i, CMenu::addFeature(-1, *(parent + 1), "Teleport to vehicle", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_TP_TO_ME, i, CMenu::addFeature(-1, *(parent + 1), "Teleport to me", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_TP_TO_SEA, i, CMenu::addFeature(-1, *(parent + 1), "Teleport to sea", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_TP_TO_AIR, i, CMenu::addFeature(-1, *(parent + 1), "Teleport in the air", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_EXPLODE, i, CMenu::addFeature(-1, *(parent + 1), "Explode", feat_action_value_str, "", 0.f, (float) get_array_size(hash::explosion_enum) - 1, 1.f, hash::explosion_enum));
				CMenu::indexPlrFeature(PLRFEAT_EXPLODE_OWNED, i, CMenu::addFeature(-1, *(parent + 1), "Explode Nearby Blamed", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_EXPLODE_LOOP, i, CMenu::addFeature(-1, *(parent + 1), "Explode", feat_value_str, "", 0.f, (float) get_array_size(hash::explosion_enum) - 1, 1.f, hash::explosion_enum));
				CMenu::indexPlrFeature(PLRFEAT_GIVE_WEAPON, i, CMenu::addFeature(-1, *(parent + 1), "Give Weapon", feat_action_value_str, "", 0.f, (float) get_array_size(hash::weapon_name) - 1, 1.f, hash::weapon_name));
				CMenu::indexPlrFeature(PLRFEAT_GIVE_WEAPONS, i, CMenu::addFeature(-1, *(parent + 1), "Give All Weapons", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_REMOVE_WEAPONS, i, CMenu::addFeature(-1, *(parent + 1), "Remove All Weapons", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_CLONE_BODYGUARD, i, CMenu::addFeature(-1, *(parent + 1), "Clone Bodyguard", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_ATTACH_TO, i, CMenu::addFeature(-1, *(parent + 1), "Attach To Player", feat_toggle));
				CMenu::indexPlrFeature(PLRFEAT_ATTACH_PIGGY_BACK, i, CMenu::addFeature(-1, *(parent + 1), "Attach Piggy Back", feat_toggle));
				CMenu::indexPlrFeature(PLRFEAT_ATTACH_69, i, CMenu::addFeature(-1, *(parent + 1), "Attach 69", feat_toggle));
				CMenu::indexPlrFeature(PLRFEAT_ATTACH_VIOLATE, i, CMenu::addFeature(-1, *(parent + 1), "Attach Violate", feat_toggle));
				CMenu::indexPlrFeature(PLRFEAT_DETACH_ALL, i, CMenu::addFeature(-1, *(parent + 1), "Detach All", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_ATTACH_CLONE, i, CMenu::addFeature(-1, *(parent + 1), "Attach Clone", feat_action_value, "", 1.f, 10.f, 1.f));
				CMenu::indexPlrFeature(PLRFEAT_ATTACH_CLONE_69, i, CMenu::addFeature(-1, *(parent + 1), "Attach Clone 69", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_CLEAR_TASKS, i, CMenu::addFeature(-1, *(parent + 1), "Clear Tasks", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_FREEZE, i, CMenu::addFeature(-1, *(parent + 1), "Freeze in Animation", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_ANIMATE, i, CMenu::addFeature(-1, *(parent + 1), "Animate", feat_action_value_str, "", 0.f, (float) (sizeof(hash::ped_anim_name) / sizeof(*hash::ped_anim_name)) - 1, 1.f, hash::ped_anim_name));
				CMenu::indexPlrFeature(PLRFEAT_TRAP_IN_CAGE, i, CMenu::addFeature(-1, *(parent + 1), "Trap In Cage", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_CHRISFORMAGE, i, CMenu::addFeature(-1, *(parent + 1), "Send Chris Formage", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_DEAD_CLONES, i, CMenu::addFeature(-1, *(parent + 1), "Dead Clones", feat_toggle));
				CMenu::indexPlrFeature(PLRFEAT_GIVE_WANTED, i, CMenu::addFeature(-1, *(parent + 1), "Give Wanted Level", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_CRASH, i, CMenu::addFeature(-1, *(parent + 1), "Crash", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_KICK, i, CMenu::addFeature(-1, *(parent + 1), "Kick", feat_action));
				CMenu::indexPlrFeature(PLRFEAT_FREEZE_INV_SCREEN, i, CMenu::addFeature(-1, *(parent + 1), "Permanent Apartment Invite Screen", feat_action));
		}
	
		*parent	= CMenu::addFeature(1, -1, "All Players", feat_parent);
			CMenu::indexFeature(FEATURE_A_TRACK, CMenu::addFeature(-1, *parent, "Track", feat_toggle, "allTrack"));
			CMenu::indexFeature(FEATURE_A_MONEY_DROP_2K, CMenu::addFeature(-1, *parent, "2K Drops", feat_value_str, "", 0.f, (float) (sizeof(hash::object_prop_money_name) / sizeof(*hash::object_prop_money_name)) - 1, 1.f, hash::object_prop_money_name));
			CMenu::indexFeature(FEATURE_A_MONEY_DROP_40K, CMenu::addFeature(-1, *parent, "40K Drops", feat_toggle));
			CMenu::indexFeature(FEATURE_A_SECURO_50K, CMenu::addFeature(-1, *parent, "SecuroServ 50K/s", feat_toggle));
			CMenu::indexFeature(FEATURE_A_TP_TO_ME, CMenu::addFeature(-1, *parent, "Teleport to me", feat_action));
			CMenu::indexFeature(FEATURE_A_TP_TO_SEA, CMenu::addFeature(-1, *parent, "Teleport to sea", feat_action));
			CMenu::indexFeature(FEATURE_A_TP_TO_AIR, CMenu::addFeature(-1, *parent, "Teleport in the air", feat_action));
			CMenu::indexFeature(FEATURE_A_EXPLODE, CMenu::addFeature(-1, *parent, "Explode", feat_action_value_str, "", 0.f, (float) (sizeof(hash::explosion_enum) / sizeof(*hash::explosion_enum)) - 1, 1.f, hash::explosion_enum));
			CMenu::indexFeature(FEATURE_A_GIVE_WEAPON, CMenu::addFeature(-1, *parent, "Give Weapon", feat_action_value_str, "", 0.f, (float) (sizeof(hash::weapon_name) / sizeof(*hash::weapon_name)) - 1, 1.f, hash::weapon_name));
			CMenu::indexFeature(FEATURE_A_GIVE_WEAPONS, CMenu::addFeature(-1, *parent, "Give All Weapons", feat_action));
			CMenu::indexFeature(FEATURE_A_REMOVE_WEAPONS, CMenu::addFeature(-1, *parent, "Remove All Weapons", feat_action));
			CMenu::indexFeature(FEATURE_A_TRAP_IN_CAGE, CMenu::addFeature(-1, *parent, "Trap In Cage", feat_action));
			CMenu::indexFeature(FEATURE_A_CLEAR_TASKS, CMenu::addFeature(-1, *parent, "Clear Tasks", feat_action));
			CMenu::indexFeature(FEATURE_A_FREEZE, CMenu::addFeature(-1, *parent, "Freeze in Animation", feat_action));
			CMenu::indexFeature(FEATURE_A_ANIMATE, CMenu::addFeature(-1, *parent, "Animate", feat_action_value_str, "", 0.f, (float) (sizeof(hash::ped_anim_name) / sizeof(*hash::ped_anim_name)) - 1, 1.f, hash::ped_anim_name));
			CMenu::indexFeature(FEATURE_A_GIVE_WANTED, CMenu::addFeature(-1, *parent, "Give Wanted Level", feat_action));
			CMenu::indexFeature(FEATURE_A_KICK, CMenu::addFeature(-1, *parent, "Kick", feat_action));
			CMenu::indexFeature(FEATURE_A_FREEZE_INV_SCREEN, CMenu::addFeature(-1, *parent, "Permanent Apartment Invite Screen", feat_action));

		*parent	= CMenu::addFeature(1, -1, "ESP Options", feat_parent);
			CMenu::indexFeature(FEATURE_O_ESP_MAX_DIST, CMenu::addFeature(-1, *parent, "Max Distance", feat_action_value, "espMaxDist", 500.f, 10000.f, 500.f));
			CMenu::indexFeature(FEATURE_O_ESP_HEALTH, CMenu::addFeature(-1, *parent, "Display Health Bar", feat_toggle, "espHealth"));
			CMenu::indexFeature(FEATURE_O_ESP_BOX, CMenu::addFeature(-1, *parent, "Display Box", feat_toggle, "espBox"));
			CMenu::indexFeature(FEATURE_O_ESP_WORLD_LINE, CMenu::addFeature(-1, *parent, "Display World Line", feat_toggle, "espWorldLine"));
			CMenu::indexFeature(FEATURE_O_ESP_DIST, CMenu::addFeature(-1, *parent, "Display Distance Text", feat_toggle, "espDist"));
			CMenu::indexFeature(FEATURE_O_ESP_HEALTH_TEXT, CMenu::addFeature(-1, *parent, "Display Health Text", feat_toggle, "espHealthText"));
			CMenu::indexFeature(FEATURE_O_ESP_GOD, CMenu::addFeature(-1, *parent, "Display God Text", feat_toggle, "espGod"));

		CMenu::indexFeature(FEATURE_O_ATTACH_BONE, CMenu::addFeature(1, -1, "Attach Bone Index", feat_value_str, "boneAttach", 0.f, (float) (sizeof(hash::ped_bone_name) / sizeof(*hash::ped_bone_name)) - 1, 1.f, hash::ped_bone_name));

		*parent		= CMenu::addFeature(2, -1, "Vehicles", feat_parent);
			*(parent + 1)		= CMenu::addFeature(-1, *parent, "Options", feat_parent);
				CMenu::indexFeature(FEATURE_S_VEH_MOD, CMenu::addFeature(-1, *(parent + 1), "Spawn Upgraded", feat_toggle, "spawnVehUpgrade"));
				CMenu::indexFeature(FEATURE_S_IN_VEHICLE, CMenu::addFeature(-1, *(parent + 1), "Spawn in Vehicle", feat_toggle, "spawnInVeh"));
				CMenu::indexFeature(FEATURE_S_SP_BYPASS, CMenu::addFeature(-1, *(parent + 1), "Allow MP vehicles in SP", feat_toggle, "spawnSPBypass"));
				CMenu::indexFeature(FEATURE_S_MP_BYPASS, CMenu::addFeature(-1, *(parent + 1), "Bypass MP vehicle kick", feat_toggle, "spawnMPBypass"));
				CMenu::indexFeature(FEATURE_S_LICENSE, CMenu::addFeature(-1, *(parent + 1), "Custom License", feat_toggle, "spawnLicense"));
				CMenu::indexFeature(FEATURE_S_COLOR_1, CMenu::addFeature(-1, *(parent + 1), "Primary Color", feat_value_str, "spawnColor", 0.f, (float) get_array_size(hash::veh_color_enum) - 1, 1.f, hash::veh_color_enum));
				CMenu::indexFeature(FEATURE_S_COLOR_2, CMenu::addFeature(-1, *(parent + 1), "Secondary Color", feat_value_str, "spawnColor2", 0.f, (float) get_array_size(hash::veh_color_enum) - 1, 1.f, hash::veh_color_enum));

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
			CMenu::indexFeature(FEATURE_S_PED_RANDOMIZE, CMenu::addFeature(-1, *parent, "Randomize Peds", feat_toggle, "spawnPedRandom"));
			CMenu::indexFeature(FEATURE_S_PED_TYPE, CMenu::addFeature(-1, *parent, "Type", feat_action_value_str, "spawnPedType", 0.f, 2.f, 1.f, hash::ped_spawn_type));
			CMenu::indexFeature(FEATURE_S_PED_CLEANUP, CMenu::addFeature(-1, *parent, "Cleanup", feat_toggle, "spawnPedCleanup"));
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
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Stunt Track", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_stunt_track_hash) / sizeof(hash::object_prop_spawn_stunt_track_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_stunt_track_name[j], feat_spawn, hash::object_prop_spawn_stunt_track_hash[j], spwn_object);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Stunt Tube", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_stunt_tube_hash) / sizeof(hash::object_prop_spawn_stunt_tube_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_stunt_tube_name[j], feat_spawn, hash::object_prop_spawn_stunt_tube_hash[j], spwn_object);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Stunt Ramp", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_stunt_ramp_hash) / sizeof(hash::object_prop_spawn_stunt_ramp_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_stunt_ramp_name[j], feat_spawn, hash::object_prop_spawn_stunt_ramp_hash[j], spwn_object);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Stunt Platform", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_stunt_platform_hash) / sizeof(hash::object_prop_spawn_stunt_platform_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_stunt_platform_name[j], feat_spawn, hash::object_prop_spawn_stunt_platform_hash[j], spwn_object);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Stunt Misc", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_stunt_misc_hash) / sizeof(hash::object_prop_spawn_stunt_misc_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_stunt_misc_name[j], feat_spawn, hash::object_prop_spawn_stunt_misc_hash[j], spwn_object);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Traffic", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_traffic_hash) / sizeof(hash::object_prop_spawn_traffic_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_traffic_name[j], feat_spawn, hash::object_prop_spawn_traffic_hash[j], spwn_object);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Construction", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_construction_hash) / sizeof(hash::object_prop_spawn_construction_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_construction_name[j], feat_spawn, hash::object_prop_spawn_construction_hash[j], spwn_object);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Large", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_large_hash) / sizeof(hash::object_prop_spawn_large_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_large_name[j], feat_spawn, hash::object_prop_spawn_large_hash[j], spwn_object);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Misc", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_misc_hash) / sizeof(hash::object_prop_spawn_misc_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_misc_name[j], feat_spawn, hash::object_prop_spawn_misc_hash[j], spwn_object);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Drugs", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_drugs_hash) / sizeof(hash::object_prop_spawn_drugs_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_drugs_name[j], feat_spawn, hash::object_prop_spawn_drugs_hash[j], spwn_object);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Music", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_music_hash) / sizeof(hash::object_prop_spawn_music_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_music_name[j], feat_spawn, hash::object_prop_spawn_music_hash[j], spwn_object);
			*(parent + 1) = CMenu::addFeature(-1, *parent, "Commericial", feat_parent);
			for(int j = 0; j < sizeof(hash::object_prop_spawn_commericial_hash) / sizeof(hash::object_prop_spawn_commericial_hash[0]); j++)
				CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_commericial_name[j], feat_spawn, hash::object_prop_spawn_commericial_hash[j], spwn_object);
			//*(parent + 1) = CMenu::addFeature(-1, *parent, "Test", feat_parent);
			//for(int j = 0; j < sizeof(hash::object_prop_spawn_stunt_test) / sizeof(hash::object_prop_spawn_stunt_test[0]); j++)
			//	CMenu::addFeature(-1, *(parent + 1), hash::object_prop_spawn_stunt_test[j], feat_spawn, hash::object_prop_spawn_stunt_test[j], spwn_object);

		*parent	= CMenu::addFeature(2, -1, "Editor", feat_parent);
			CMenu::indexFeature(FEATURE_E_EDITOR_MODE, CMenu::addFeature(-1, *parent, "Editor Mode", feat_toggle, "editorEnable"));
			CMenu::indexFeature(FEATURE_E_DELETE, CMenu::addFeature(-1, *parent, "Delete", feat_action));
			CMenu::indexFeature(FEATURE_E_DISTANCE, CMenu::addFeature(-1, *parent, "Distance", feat_action_value, "editorDist", 5.f, 50.f, 5.f));
			CMenu::indexFeature(FEATURE_E_TEXT_TYPE, CMenu::addFeature(-1, *parent, "Display Type", feat_toggle, "editorTxtType"));
			CMenu::indexFeature(FEATURE_E_TEXT_POS, CMenu::addFeature(-1, *parent, "Display Coords", feat_toggle, "editorTxtPos"));
			CMenu::indexFeature(FEATURE_E_FREEZE, CMenu::addFeature(-1, *parent, "Freeze Position", feat_toggle, "editorFreeze"));
			CMenu::indexFeature(FEATURE_E_INVISIBLE, CMenu::addFeature(-1, *parent, "Invisible", feat_toggle, "editorInvis"));
			CMenu::indexFeature(FEATURE_E_COLLISION, CMenu::addFeature(-1, *parent, "Disable Collision", feat_toggle, "editorCollision"));
			CMenu::indexFeature(FEATURE_E_ROTATION_ENABLE, CMenu::addFeature(-1, *parent, "Enable Rotation", feat_toggle, "editorRotEnable"));
			CMenu::indexFeature(FEATURE_E_ROTATION_RELATIVE, CMenu::addFeature(-1, *parent, "Relative Rotation ", feat_toggle, "editorRotRelative"));
			CMenu::indexFeature(FEATURE_E_ROTATION_X, CMenu::addFeature(-1, *parent, "Rotation X", feat_action_value, "editorRotX", 0.f, 355.f, 5.f));
			CMenu::indexFeature(FEATURE_E_ROTATION_Y, CMenu::addFeature(-1, *parent, "Rotation Y", feat_action_value, "editorRotY", 0.f, 355.f, 5.f));
			CMenu::indexFeature(FEATURE_E_ROTATION_Z, CMenu::addFeature(-1, *parent, "Rotation Z", feat_action_value, "editorRotZ", 0.f, 355.f, 5.f));
			CMenu::indexFeature(FEATURE_E_THROW_MODE, CMenu::addFeature(-1, *parent, "Enable Trow Mode", feat_toggle, "editorThrow"));


		CMenu::setActiveCat(0);
	}
};