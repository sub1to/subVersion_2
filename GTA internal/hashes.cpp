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

namespace hash
{
	const DWORD weapon_hash[] = 
	{
		/*
		"WEAPON_REVOLVER", "WEAPON_SNSPISTOL", "WEAPON_VINTAGEPISTOL", "WEAPON_STUNGUN", "WEAPON_FLAREGUN", 
		
		"WEAPON_MICROSMG", "WEAPON_SMG", "WEAPON_ASSAULTSMG", "WEAPON_MG", "WEAPON_COMBATMG", "WEAPON_COMBATPDW",
		"WEAPON_GUSENBERG", "WEAPON_MACHINEPISTOL", "WEAPON_MINISMG", 
		
		"WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_SPECIALCARBINE", "WEAPON_BULLPUPRIFLE",
		"WEAPON_COMPACTRIFLE", 

		"WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
		"WEAPON_HEAVYSHOTGUN", "WEAPON_AUTOSHOTGUN", "WEAPON_DBSHOTGUN", "WEAPON_MUSKET",
		
		"WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_MARKSMANRIFLE",
		
		"WEAPON_GRENADELAUNCHER", "WEAPON_RPG", "WEAPON_HOMINGLAUNCHER", "WEAPON_MINIGUN",
		"WEAPON_RAILGUN", "WEAPON_FIREWORK", "WEAPON_COMPACTLAUNCHER",
		
		"WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_PROXMINE", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
		"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN", "WEAPON_PIPEBOMB",

		"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
		"WEAPON_POOLCUE", "WEAPON_WRENCH", "WEAPON_FLASHLIGHT", "WEAPON_SWITCHBLADE", "WEAPON_BATTLEAXE", "WEAPON_BOTTLE",
		"WEAPON_DAGGER", "WEAPON_HATCHET", "WEAPON_MACHETE", "WEAPON_SNOWBALL", "WEAPON_KNUCKLE",

		"GADGET_PARACHUTE",
		*/
		0x1b06d571, 0x5ef9fec4, 0x22d8fe39, 0x99aeeb3b, 0xd205520e, 0xdc4db296,
		0xc1b3c3d1, 0xbfd21232, 0x83839c4, 0x3656c8c1, 0x47757124,
		
		0x13532244, 0x2be6766b, 0xefe7e2df, 0x9d07f764, 0x7fd62962, 0xa3d4d34,
		0x61012683, 0xdb1aa450, 0xbd248b55,
		
		0xbfefff6d, 0x83bf0278, 0xaf113f99, 0xc0a3098d, 0x7f229f94,
		0x624fe830,
		
		0x1d073a89, 0x7846a318, 0xe284c527, 0x9d61e50f,
		0x3aabbbaa, 0x12e82d3d, 0xef951fbb, 0xa89cb99e,

		0x5fc3c11, 0xc472fe2, 0xc734385a,
		
		0xa284510b, 0xb1ca77b1, 0x63ab0442, 0x42bf8a85,
		0x6d544c99, 0x7f7497e5, 0x781fe4a,
		
		0x93e220bd, 0x2c3731d9, 0xab564b93, 0xfdbc8a50, 0xa0973d5e,
		0x24b17070, 0x60ec506, 0x34a67b97, 0xba45e8b8,
		
		0x99b507ea, 0x678b81b1, 0x4e875f73, 0x958a4a8f, 0x440e4788, 0x84bd7bfd,
		0x94117305, 0x19044ee0, 0x8bb05fd7, 0xdfe37640, 0xcd274149, 0xf9e6aa4b,
		0x92a27487, 0xf9dcbf2d, 0xdd5df8d9, 0x787f0bb, 0xd8df3c3c,
		
		0xfbab5776, 
	};

	const char* const weapon_name[] =
	{
		"Pistol", "Combat Pistol", "AP Pistol", ".50 Pistol", "Heavy Pistol", "Marksman Pistol",
		"Revolver", "SNS Pistol", "Vintage Pistol", "Stungun", "Flare Gun",
		
		"Micro SMG", "SMG", "Assault SMG", "MG", "Combat MG", "Combat PDW",
		"Gusenberg", "Machine Pistol", "Mini SMG",
		
		"Assault Rifle", "Carbine Rifle", "Advanced Rifle", "Special Carbine", "Bullpup Rifle",
		"Compact Rifle",

		"Pump Shotgun", "Sawed Off Shotgun", "Assault Shotgun", "Bullpup Shotgun",
		"Heavy Shotgun", "Auto Shotgun", "DB Shotgun", "Musket",
		
		"Sniper Rifle", "Heavy Sniper", "Marksman Rifle",
		
		"Grenade Launcher", "RPG", "Homing Launcher", "Minigun",
		"Railgun", "Firework Launcher", "Compact Launcher", 

		"Grenade", "Sticky Bomb", "Prox Mine", "Smoke Grenade", "BZ Gas",
		"Molotov", "Fire Extinguisher", "Petrol Can", "Pipe Bomb",

		"Knife", "Nightstick", "Hammer", "Baseball Bat", "Golf Club", "Crowbar",
		"Pool Cue", "Wrench", "Flashlight", "Switch Blade", "Battle Axe", "Bottle",
		"Dagger", "Hatchet", "Machete", "Snowball", "Knuckle",

		"Parachute",
	};

	const char* const radio_station_hash[] =
	{
		"RADIO_01_CLASS_ROCK", "RADIO_02_POP", "RADIO_03_HIPHOP_NEW",
		"RADIO_04_PUNK", "RADIO_05_TALK_01", "RADIO_06_COUNTRY",
		"RADIO_07_DANCE_01", "RADIO_08_MEXICAN", "RADIO_09_HIPHOP_OLD",
		"RADIO_12_REGGAE", "RADIO_13_JAZZ", "RADIO_14_DANCE_02",
		"RADIO_15_MOTOWN", "RADIO_20_THELAB", "RADIO_16_SILVERLAKE",
		"RADIO_17_FUNK", "RADIO_18_90S_ROCK", "RADIO_19_USER",
		"RADIO_11_TALK_02", "OFF"
	};

	const char* const radio_station_name[] =
	{
		"Rock Radio", "24/7 Pop", "Los Santos",
		"Channel X", "WCTR", "Rebel Radio",
		"Soulwax", "East Los", "West Coast",
		"Blue Ark", "Worldwide", "FlyLo",
		"Low Down", "The Lab", "Mirror Park",
		"Space", "Vinewood", "Self",
		"Blaine", "Off"
	};

	const DWORD object_prop_money_hash[] =
	{
		0x6b795ebc, 0x40f52369, 0x4b3d240f, 0xa9bd0d16, 0xe3ba450,	//"prop_alien_egg_01", "p_v_43_safe_s", "prop_wheelchair_01", "prop_coke_block_01", "prop_xmas_tree_int",
		0x5571173d, 0x6ad326c2, 0x456aa864, 0x58d3b4ea, 0xd541462d,	//"prop_beer_neon_01", "prop_space_rifle", "prop_dj_deck_01", "prop_micro_01", "p_ld_soc_ball_01", 
		0x532b1dd1, 0x7ffbc1e2, 0x5869a8f8, 0xe6cb661e, 0x927a5723,	//"prop_rub_trolley01a", "prop_dummy_01", "prop_large_gold", "prop_cs_dildo_01", "prop_fan_01",
		0x34d5d3fd, 0x2ae13dfa, 0x29cb0f3c, 0x922c2a43, 0xfa686c0e,	//"prop_golf_bag_01", "prop_armchair_01", "prop_armour_pickup", "prop_big_shit_01", "prop_bin_04a", 
		0x1f550c17, 0x5b5c4263, 0x39885bb5, 0x16a39a90, 0x1b6ed610,	//"prop_chair_01a", "prop_chip_fryer", "prop_chickencoop_a", "prop_dog_cage_01", "prop_coffin_02", 
		0x82bac591, 0x28cdf74c,										//"prop_coffin_02b", "prop_cs_dumpster_01a"
	};

	const char* const object_prop_money_name[] =
	{
		"Alien Egg", "Safe", "Wheelchair", "Coke Brick", "Xmas Tree",
		"Neon Liquor Sign", "Space Rifle", "DJ Deck", "Microwave", "Soccer Ball",
		"Shopping Cart", "Mannequin", "Gold Cart", "Dildo", "Fan",
		"Golf Bag", "Arm Chair", "Armour Pickup", "Turd", "Garbage Bin", 
		"Chair", "Fryer", "Chicken Coop", "Dog Cage", "Coffin Broken",
		"Coffin", "Dumpster",
	};

	const DWORD object_prop_spawn_misc_hash[] =
	{
		0xe3ba450, 0x5571173d, 0x6f9939c7, 0x6ad326c2,	//"prop_xmas_tree_int",  "prop_beer_neon_01", "prop_ld_toilet_01", "prop_space_rifle",
		0xefc4165a, 0x8e8c7a5b, 0x456aa864, 0xbe862050,	//"prop_food_van_01", "prop_crashed_heli", "prop_dj_deck_01", "prop_portacabin01",
		0x58d3b4ea, 0x3dc31836, 0x4b3d240f,				//"prop_micro_01", "prop_tv_flat_01", "prop_wheelchair_01",
		0x40f52369, 0xf830b63e, 0xd541462d, 0x532b1dd1,	//"p_v_43_safe_s", "prop_swiss_ball_01", "p_ld_soc_ball_01", "prop_rub_trolley01a",
		0x5869a8f8, 0xe6cb661e, 0x927a5723, 0x34d5d3fd,	//"prop_large_gold", "prop_cs_dildo_01", "prop_fan_01", "prop_golf_bag_01",
		0x2ae13dfa, 0x29cb0f3c, 0x922c2a43, 0xfa686c0e,	//"prop_armchair_01", "prop_armour_pickup", "prop_big_shit_01", "prop_bin_04a", 
		0x1f550c17, 0x5b5c4263, 0x39885bb5, 0x16a39a90,	//"prop_chair_01a", "prop_chip_fryer", "prop_chickencoop_a", "prop_dog_cage_01",
		0x392d62aa, 0xd44295dd, 0x6b795ebc,				//"prop_gold_cont_01", "p_cablecar_s", "prop_alien_egg_01",
		0xfb50d934, 0x2d80bd93, 0x1b6ed610, 0x82bac591,	//"prop_prop_tree_01", "prop_prop_tree_02", "prop_coffin_02", "prop_coffin_02b",
		0x28cdf74c, 0x240d3e4b, 0xccf19015,				//"prop_cs_dumpster_01a", "prop_pizza_box_01", "prop_pizza_box_02", 
		0xf9980bc3, 0x1762b038, 0xaf11755,				//"prop_cs_panties", "prop_cs_panties_02", "prop_cs_panties_03",
	};

	const char* const object_prop_spawn_misc_name[] =
	{
		"Xmas Tree", "Neon Liquor Sign", "Toilet", "Space Rifle",
		"Food Van", "Crashed Helicopter", "DJ Deck", "Portable Cabin",
		"Microwave", "Flatscreen TV", "Wheelchair",
		"Safe", "Swiss Ball", "Soccer Ball", "Shopping Cart",
		"Gold Cart", "Dildo", "Fan", "Golf Bag",
		"Arm Chair", "Armour Pickup", "Turd", "Garbage Bin", 
		"Chair", "Fryer", "Chicken Coop", "Dog Cage",
		"Cage", "Cablecar", "Alien Egg",
		"Tree", "Tree 2", "Coffin Broken", "Coffin",
		"Dumpster", "Pizza Box 1", "Pizza Box 2", 
		"Panties 1", "Panties 2", "Panties 3",
	};

	const DWORD object_prop_spawn_large_hash[] =
	{
		0xb467c540, 0x8973a868, 0xc42c019a, 0x7121ac4,	//"p_spinning_anus_s", "prop_air_bigradar", "prop_ld_ferris_wheel", "prop_xmas_ext",
		0x745f3383, 0x8af58425, 0x9c762726, 0xc2bc19cd,	//"prop_windmill_01", "prop_lev_des_barge_01", "prop_lev_des_barge_02", "p_cs_mp_jet_01_s", 
		0xfd17bd49, 0x43a4b8e, 0x118b6630, 0x58a9746b,	//"prop_pylon_01", "prop_pylon_02", "prop_pylon_03", "prop_pylon_04",
	};

	const char* const object_prop_spawn_large_name[] =
	{
		"UFO", "Radar Dish", "Ferris Wheel", "Huge Xmas Tree", 
		"Windmill", "Barge 01", "Barge 02", "Plane", 
		"Electricity Pylon 1", "Electricity Pylon 2", "Electricity Pylon 3", "Electricity Pylon 4",
	};

	const DWORD object_prop_spawn_drugs_hash[] =
	{
		0x110ac104, 0xe8032e4, 0x1afa6a0a, 0xa9bd0d16,	//"prop_meth_bag_01", "prop_weed_pallet", "Prop_weed_01", "prop_coke_block_01",
		0xd6aa6804, 0xf3565180,							//"prop_cs_crackpipe", "prop_cs_meth_pipe", 
	};

	const char* const object_prop_spawn_drugs_name[] =
	{
		
		"Meth Bag", "Pallet of Weed", "Weed Plant", "Coke Brick",
		"Crack pipe", "Meth Pipe", 
	};

	const DWORD object_prop_spawn_music_hash[] =
	{
		0xa4e7e0a7, 0x369d8410, 0x3a41e1a,	//"prop_el_guitar_01", "prop_el_guitar_02", "prop_el_guitar_03",
		0x3e90e8ca, 0x73f55396, 0x3f2ec2b6,	//"prop_jukebox_01", "prop_jukebox_02", "prop_ghettoblast_02",
	};

	const char* const object_prop_spawn_music_name[] =
	{
		
		"Electric Guitar 1", "Electric Guitar 2", "Acoustic Guitar",
		"Jukebox 1", "Jukebox 2", "Boombox",
	};

	const DWORD object_prop_spawn_commericial_hash[] =
	{
		0x69ad49fb, 0xfd6964f, 0xdb60ad20,	//"prop_bikini_disp_01", "prop_bikini_disp_02", "prop_bikini_disp_03",
		0xe513c086, 0x42b3fc09, 0xce1f129d,	//"prop_bikini_disp_04", "prop_bikini_disp_05", "prop_bikini_disp_06",
		0x7ffbc1e2, 0x1e34b5c2, 0xbcdefab5,	//"prop_dummy_01", "prop_fleeca_atm", "prop_atm_02",
		0xaea85e48, 0x894e3b16, 0x38c419eb,	//"prop_atm_03", "prop_arcade_01", "prop_arcade_02", 
	};

	const char* const object_prop_spawn_commericial_name[] =
	{
		"Bikini Mannequin Blue", "Bikini Mannequin Red", "Bikini Mannequin Green",
		"Bikini Mannequin Pink", "Bikini Mannequin Yellow", "Bikini Mannequin Orange",
		"Mannequin", "ATM Fleeca", "ATM 2",
		"ATM 3", "Arcade", "Arcade 2", 
	};

	const DWORD object_prop_spawn_construction_hash[] =
	{
		0x7b37c437, 0x68c79f57, 0x963025ed,	//"prop_metal_plates01", "prop_metal_plates02", "prop_generator_02a",
		0x8250b39, 0xc4495033, 0x5dec10b0,	//"prop_generator_03a", "prop_generator_04", "prop_byard_bench01",
		0x8fa6f425, 0x64a6680,				//"prop_byard_bench02", "prop_hydro_platform_01",
	};

	const char* const object_prop_spawn_construction_name[] =
	{
		"Metal Construction Plate", "Metal Construction Plates", "Generator 1",
		"Generator 2", "Generator 3", "Construction Trestle 1",
		"Construction Trestle 2", "Scissor Lift",
	};

	const DWORD object_prop_spawn_stunt_misc_hash[] =
	{
		0x493f5f6f, 0x56f7fae0, 0x5a990226,				//"stt_prop_corner_sign_01", "stt_prop_corner_sign_02", "stt_prop_corner_sign_03",
		0x6a20a135, 0x7fdeccb1, 0x8d8d680e, 0xb1eeb0dc,	//"stt_prop_corner_sign_04", "stt_prop_corner_sign_05", "stt_prop_corner_sign_06", "stt_prop_corner_sign_07",
		0x912c6f58, 0xd7627bc3, 0x2aff21a7, 0x64c7153a,	//"stt_prop_corner_sign_08", "stt_prop_corner_sign_09", "stt_prop_corner_sign_10", "stt_prop_corner_sign_11",
		0x8e8068ac, 0xc69958dd, 0x784e3c48,				//"stt_prop_corner_sign_12", "stt_prop_corner_sign_13", "stt_prop_corner_sign_14",
		0x2bf6bbcf, 0xdf7b1b6e, 0xf275df37,				//"stt_prop_hoop_constraction_01a", "stt_prop_hoop_small_01", "stt_prop_hoop_tyre_01a",
		0x53724bb0, 0x5779131a, 0x827092e6, 0x2519c421,	//"stt_prop_stunt_bowling_ball", "stt_prop_stunt_bowling_pin", "stt_prop_stunt_bowlpin_stand", "stt_prop_stunt_domino",
		0xc00c3530, 0xf1fd3cff, 0xdb2c3e38, 0x286f5f0,	//"stt_prop_stunt_soccer_ball", "stt_prop_stunt_soccer_goal", "stt_prop_stunt_soccer_lball", "stt_prop_stunt_soccer_sball",
		0x7dbdb93c, 0x4efa1782, 0xf66f582f,				//"prop_skate_flatramp", "prop_skate_funbox", "prop_skate_halfpipe",
		0x731f4403, 0x326d3db1, 0x3154ddc, 0x8ae73fd0,	//"prop_skate_kickers", "prop_skate_quartpipe", "prop_skate_rail", "prop_skate_spiner",
	};

	const char* const object_prop_spawn_stunt_misc_name[] =
	{
		"Sign 5", "Sign 10", "Sign 50",
		"Sign 100", "Sign Caution Slow", "Sign U-Turn Left", "Sign U-Turn Right",
		"Sign Turn Left", "Sign Turn Right", "Sign Chicane Right", "Sign Chicane Left",
		"Sign Exclaimation", "Sign Arrow Right", "Sign Arrow Left",
		"Hoop Big Metal", "Hoop Small", "Hoop Big Tyre",
		"Bowling Ball", "Bowling Pin", "Bowling Pin Stand", "Domino",
		"Soccer Ball M", "Soccer Goal", "Soccer Ball L", "Soccer Ball S",
		"Skate Flat Ramp", "Skate Funbox", "Skate Halfpipe", "Skate Kickers",
		"Skate Quarterpipe", "Skate Rail", "Skate Spine",
	};

	const DWORD object_prop_spawn_stunt_ramp_hash[] =
	{
		0xdf7f5979, 0x99cbded8, 0xf4bd03ec,	//"stt_prop_ramp_adj_flip_m", "stt_prop_ramp_adj_flip_mb", "stt_prop_ramp_adj_flip_s", 
		0x84b09bf2, 0xd7ade0b8, 0x69702115,	//"stt_prop_ramp_adj_flip_sb", "stt_prop_ramp_adj_hloop", "stt_prop_ramp_adj_loop",
		0x8978ace1, 0x8810df5e, 0xb1ca32d4,	//"stt_prop_ramp_multi_loop_rb", "stt_prop_ramp_jump_l", "stt_prop_ramp_jump_m",
		0x285a9fe7, 0x6373eef4, 0xbf18a65c,	//"stt_prop_ramp_jump_s", "stt_prop_ramp_jump_xl", "stt_prop_ramp_jump_xs",
		0x162a902d, 0x748eb5ee, 0xa857dd30,	//"stt_prop_ramp_jump_xxl", "stt_prop_stunt_jump_l", "stt_prop_stunt_jump_lb",
		0x5a5c0189, 0xa4723a5, 0xf590c75e,	//"stt_prop_stunt_jump_s", "stt_prop_stunt_jump_sb", "stt_prop_stunt_jump_loop",
		0x4259d185, 0x6d8066a2, 0x76138c75,	//"stt_prop_stunt_jump_m", "stt_prop_stunt_jump_mb", "stt_prop_stunt_ramp",
		0xeb8754fb, 0xcc526c0b, 0x974101e9,	//"stt_prop_stunt_wideramp", "stt_prop_ramp_spiral_l_l", "stt_prop_ramp_spiral_l_m",
		0x4d02ed6a, 0xefa2443e, 0x6dd3c362,	//"stt_prop_ramp_spiral_l_s", "stt_prop_ramp_spiral_l_xxl", "stt_prop_ramp_spiral_l",
		0x5f2d2615, 0x289ab86d, 0x70f9805a,	//"stt_prop_ramp_spiral_m", "stt_prop_ramp_spiral_s", "stt_prop_ramp_spiral_xxl",
		0xbf8918de, 0xb157c9e4, 0xf4f1511e,	//"prop_jetski_ramp_01", "prop_mp_ramp_01", "prop_mp_ramp_02",
		0x93948e5e,							//"prop_mp_ramp_03",
	};

	const char* const object_prop_spawn_stunt_ramp_name[] =
	{
		"Stunt Flip Medium Right", "Stunt Flip Medium Left", "Stunt Flip Small Right", 
		"Stunt Flip Small Left", "Half Loop", "Loop",
		"Multi Loop", "Stunt Ramp Curve L", "Stunt Ramp Curve M",
		"Stunt Ramp Curve S", "Stunt Ramp Curve XL", "Stunt Ramp Curve XS",
		"Stunt Ramp Curve XXL", "Stunt Ramp L", "Stunt Ramp XL",
		"Stunt Ramp S", "Stunt Ramp S2", "Ramp + Loop",
		"Stunt Ramp M", "Stunt Ramp M2", "Huge Stunt Ramp",
		"Huge Stunt Ramp Wide", "Spiral Right", "Spiral Right Medium",
		"Spiral Right Small", "Spiral Right XXL", "Spiral Left Large",
		"Spiral Left Medium", "Spiral Left Small", "Spiral Left XXL",
		"Jetski Ramp", "Ramp 1", "Ramp 2",
		"Ramp 3",
	};

	const DWORD object_prop_spawn_stunt_platform_hash[] =
	{
		0xbb5b8306, 0x21e1d015, 0x4f762b3d,	//"stt_prop_stunt_bblock_huge_01", "stt_prop_stunt_bblock_huge_02", "stt_prop_stunt_bblock_huge_03",
		0x6901972, 0x38d1fdf5, 0x2b862da0,	//"stt_prop_stunt_bblock_huge_04", "stt_prop_stunt_bblock_huge_05", "stt_prop_stunt_bblock_hump_01",
		0x38b8c805, 0x56e458b3, 0xa1736ddc,	//"stt_prop_stunt_bblock_hump_02", "stt_prop_stunt_bblock_lrg1", "stt_prop_stunt_bblock_lrg2",
		0x82b3305c, 0x8057d1cd, 0x5d7d8c19,	//"stt_prop_stunt_bblock_lrg3", "stt_prop_stunt_bblock_mdm1", "stt_prop_stunt_bblock_mdm2",
		0x4e8cee2c, 0x27f13ba6, 0x15bb173a,	//"stt_prop_stunt_bblock_mdm3", "stt_prop_stunt_bblock_sml1", "stt_prop_stunt_bblock_sml2",
		0x4b2e021f, 0x112321d8, 0x26654c5c,	//"stt_prop_stunt_bblock_sml3", "stt_prop_stunt_bblock_xl1", "stt_prop_stunt_bblock_xl2",
		0xef675e51, 0x3edd1dc3, 0x946bddf0,	//"stt_prop_stunt_bblock_xl3", "stt_prop_stunt_landing_zone_01", "stt_prop_stunt_bblock_qp",
		0x3cb2cb42, 0x2ef52fc7,				//"stt_prop_stunt_bblock_qp2", "stt_prop_stunt_bblock_qp3", 
	};

	const char* const object_prop_spawn_stunt_platform_name[] =
	{
		"Huge Platform Square", "Huge Platform Rectangle", "Huge Platform Square L",
		"Huge Platform Squre XL", "Huge Platform Rectangle XL", "Huge Platform Hump",
		"Huge Platform Hump 2", "Platform L1", "Platform L2",
		"Platform L3", "Platform M1", "Platform M2",
		"Platform M3", "Platform S1", "Platform S2",
		"Platform S3", "Platform Long 1", "Platform Long 2",
		"Platform Long 3", "Huge Platform Landingzone", "Huge Quarter Pipe 1",
		"Huge Quarter Pipe 2", "Huge Quarter Pipe 3",
	};

	const DWORD object_prop_spawn_stunt_tube_hash[] =
	{
		0x7c17d532, 0x42ffa24e, 0x431b529e,	//"stt_prop_stunt_tube_s", "stt_prop_stunt_tube_xs", "stt_prop_stunt_tube_xxs", 
		0xba3c2825, 0x7f71fa19, 0x4fbee77f,	//"stt_prop_stunt_tube_speed", "stt_prop_stunt_tube_crn_30d", "stt_prop_stunt_tube_crn_5d", 
		0xd187a7b4, 0x83df517, 0x5b6835e7,	//"stt_prop_stunt_tube_crn", "stt_prop_stunt_tube_crn2", "stt_prop_stunt_tube_crn_15d", 
		0x5213d35, 0x2e72d572, 0xc41b8039,	//"stt_prop_stunt_tube_cross", "stt_prop_stunt_tube_end", "stt_prop_stunt_tube_ent", 
		0x64a8a51f, 0xb66f48ab, 0xc885ecd8,	//"stt_prop_stunt_tube_fn_01", "stt_prop_stunt_tube_fn_02", "stt_prop_stunt_tube_fn_03", 
		0x9ac0914e, 0x893c6e3a, 0x5f911f1d,	//"stt_prop_stunt_tube_fn_04", "stt_prop_stunt_tube_fn_05", "stt_prop_stunt_tube_fork", 
		0x88525ae3, 0xa21de74, 0x9ce203f6,	//"stt_prop_stunt_tube_gap_01", "stt_prop_stunt_tube_gap_02", "stt_prop_stunt_tube_gap_03", 
		0x3551d083, 0x3d2730d1, 0x4f120520,	//"stt_prop_stunt_tube_hg", "stt_prop_stunt_tube_jmp", "stt_prop_stunt_tube_jmp2", 
		0xe07c9dfa, 0xe26794d, 0xb65e519a,	//"stt_prop_stunt_tube_l", "stt_prop_stunt_tube_m", "stt_prop_stunt_tube_qg", 
	};

	const char* const object_prop_spawn_stunt_tube_name[] =
	{
		"Stunt Tube S", "Stunt Tube XS", "Stunt Tube XXS", 
		"Stunt Tube Speed Boost", "Stunt Tube Turn 30 Degrees", "Stunt Turn Tube 5 Degrees", 
		"Stunt Turn Tube 90 Degrees", "Stunt Turn Tube 45 Degrees", "Stunt Tube Turn 15 Degrees", 
		"Stunt Turn Tube Cross", "Stunt Tube End", "Stunt Tube Entrance", 
		"Stunt Tube Spinner", "Stunt Tube Double Spinner", "Stunt Tube Spinner Closed 1/2", 
		"Stunt Tube Spinner Closed 3/4", "Stunt Tube Double Spinner Closed 1/2", "Stunt Tube Fork", 
		"Stunt Tube Gap", "Stunt Tube Gap 2", "Stunt Tube Gap 3", 
		"Stunt Tube Closed 1/2", "Stunt Tube Ramp 1", "Stunt Tube Jump", 
		"Stunt Tube XL", "Stunt Tube M", "Stunt Tube Closed 3/4", 
	};

	const DWORD object_prop_spawn_stunt_track_hash[] =
	{
		0xd17a9461, 0x2a667310, 0xdf90308c,	//"stt_prop_track_straight_bar_l", "stt_prop_track_straight_lm_bar", "stt_prop_track_straight_bar_m", 
		0xad8c4c69, 0x23c8e97a, 0xff79b311,	//"stt_prop_track_straight_bar_s", "stt_prop_track_straight_l", "stt_prop_track_straight_lm", 
		0x6393e913, 0x9ee25faf, 0x808a8d98,	//"stt_prop_track_straight_m", "stt_prop_track_straight_s", "stt_prop_race_start_line_01", 
		0xb6b7ab45, 0xfcad85e0, 0xf2099c08,	//"stt_prop_race_start_line_01b", "stt_prop_race_start_line_02", "stt_prop_race_start_line_02b", 
		0x15f3b86c, 0xf8e728ab, 0x2e5f6892,	//"stt_prop_race_start_line_03", "stt_prop_race_start_line_03b", "stt_prop_track_bend2_bar_l", 
		0x87a67d61, 0xa51962, 0x370c2079,	//"stt_prop_track_bend2_bar_l_b", "stt_prop_track_bend2_l", "stt_prop_track_bend2_l_b", 
		0xe5cff3d4, 0x7e1928fc, 0x3c04c081,	//"stt_prop_track_bend_15d", "stt_prop_track_bend_15d_bar", "stt_prop_track_bend_180d", 
		0x8a85af58, 0x7bd571d9, 0x644bcb4c,	//"stt_prop_track_bend_180d_bar", "stt_prop_track_bend_30d", "stt_prop_track_bend_30d_bar", 
		0x5a666558, 0xc779fff6, 0x161aa7d5,	//"stt_prop_track_bend_5d", "stt_prop_track_bend_5d_bar", "stt_prop_track_bend_bar_l", 
		0x8035dc01, 0x3da676e8, 0x31ba3b53,	//"stt_prop_track_bend_bar_l_b", "stt_prop_track_bend_bar_m", "stt_prop_track_bend_l", 
		0x2e03ed1d, 0x89696ad0, 0x7b5ab510,	//"stt_prop_track_bend_l_b", "stt_prop_track_bend_m", "stt_prop_track_block_01", 
		0x188fef7c, 0x6924b81, 0x60c1123,	//"stt_prop_track_block_02", "stt_prop_track_block_03", "stt_prop_track_chicane_l", 
		0xe794e24d, 0x6bb55c74, 0xf5dda35d,	//"stt_prop_track_chicane_l_02", "stt_prop_track_chicane_r", "stt_prop_track_chicane_r_02", 
		0x11105a79, 0xa325f1cf, 0xbe7fcc0f,	//"stt_prop_track_cross", "stt_prop_track_cross_bar", "stt_prop_track_fork",
	};

	const char* const object_prop_spawn_stunt_track_name[] =
	{
		"Track Barrier XL", "Track Barrier L", "Track Barrier M", 
		"Track Barrier S", "Track XL", "Track L", 
		"Track M", "Track S", "Track Start 1 Short", 
		"Track Start 1 Long", "Track Start 2 Short", "Track Start 2 Long", 
		"Track Start 3 Short", "Track Start 3 Long", "Track Turn 90 Degrees Barrier", 
		"Track Turn 90 Degrees Barrier 2", "Track Turn 90 Degrees 1", "Track Turn 90 Degrees 2", 
		"Track Turn 15 Degrees", "Track Turn 15 Degrees Barrier", "Track Turn 180 Degrees", 
		"Track Turn 180 Degrees Barrier", "Track Turn 30 Degrees", "Track Turn 30 Degrees Barrier", 
		"Track Turn 15 Degrees", "Track Turn 15 Degrees Barrier", "Track Turn 90 Degrees Barrier Small 1", 
		"Track Turn 90 Degrees Barrier Small 2", "Track Turn 45 Degrees Barrier Small", "Track Turn 90 Degrees Small 1", 
		"Track Turn 90 Degrees Small 2", "Track Turn 45 Degrees Small", "Track Narrowing", 
		"Track Narrowing 2", "Track Narrowing 3", "Track Chicane Left L", 
		"Track Chicane Left S", "Track Chicane Right L", "Track Chicane Right S", 
		"Track Cross", "Track Cross Barrier", "Track Fork", 
	};

	const DWORD object_prop_spawn_traffic_hash[] =
	{
		0x33bee4be, 0x5f8f8668, 0xcdd8fe00,	//"prop_mp_barrier_01", "prop_mp_barrier_01b", "prop_barrier_wat_01a", 
		0x223c581b, 0x6f8df2d9, 0xc5ac6a0a,	//"prop_barriercrash_03", "prop_barriercrash_04", "prop_barier_conc_01b", 
		0xeb4eb54e, 0xe15ca04a, 0xd7ca8d26,	//"prop_barier_conc_01c", "prop_barier_conc_02b", "prop_barier_conc_02c", 
		0x19cb150e, 0x94110818, 0x295b365e,	//"prop_barier_conc_03a", "prop_barier_conc_04a", "prop_barier_conc_05a", 
		0x18c49531, 0x17d003b, 0xf3c33285,	//"prop_barier_conc_05b", "prop_mp_barrier_02", "prop_mp_barrier_02b", 
		0x6f5592c2, 0xe0264f5d, 0xc0d710bf,	//"prop_mp_arrow_barrier_01", "prop_roadcone01a", "prop_roadcone01b", 
		0xfba10656, 0xc2339364, 0x6da666cf,	//"prop_roadcone01c", "prop_roadcone02a", "prop_roadcone02b", 
		0x3c1b83ba, 0x5985d75, 0x208f25b3,	//"prop_roadcone02c", "prop_mp_cone_04", "prop_barrier_wat_03b", 
	};

	const char* const object_prop_spawn_traffic_name[] =
	{
		"Road Barrier 1", "Road Barrier 2", "Road Barrier 3", 
		"Crash Barrier 1", "Crash Barrier 2", "Concrete Barrier Small 1", 
		"Concrete Barrier Small 2", "Concrete Barrier Medium 1", "Concrete Barrier Medium 2", 
		"Concrete Barrier End 1", "Concrete Barrier End 2", "Concrete Barrier Large 1", 
		"Concrete Barrier Large 2", "Roadblock 1", "Roadblock 2", 
		"Roadblock Arrow", "Traffic Cone 1", "Traffic Cone 1b", 
		"Traffic Cone 1c", "Traffic Cone 2a", "Traffic Cone 2b", 
		"Traffic Cone 2c", "Traffic Cone 3", "Traffic Cone 4", 
	};

	/*const char* const object_prop_spawn_stunt_test[] = {
		"stt_prop_stunt_target", 
		"stt_prop_stunt_target_small", "stt_prop_stunt_track_bumps", "stt_prop_stunt_track_cutout", "stt_prop_stunt_track_dwlink", 
		"stt_prop_stunt_track_dwlink_02", "stt_prop_stunt_track_dwsh15", "stt_prop_stunt_track_dwshort", "stt_prop_stunt_track_dwslope15", 
		"stt_prop_stunt_track_dwslope30", "stt_prop_stunt_track_dwslope45", "stt_prop_stunt_track_dwturn", "stt_prop_stunt_track_dwuturn", 
		"stt_prop_stunt_track_exshort", "stt_prop_stunt_track_fork", "stt_prop_stunt_track_funlng", "stt_prop_stunt_track_funnel", 
		"stt_prop_stunt_track_hill", "stt_prop_stunt_track_hill2", "stt_prop_stunt_track_jump", "stt_prop_stunt_track_link", 
		"stt_prop_stunt_track_otake", "stt_prop_stunt_track_sh15", "stt_prop_stunt_track_sh30", "stt_prop_stunt_track_sh45", 
		"stt_prop_stunt_track_sh45_a", "stt_prop_stunt_track_short", "stt_prop_stunt_track_slope15", "stt_prop_stunt_track_slope30", 
		"stt_prop_stunt_track_slope45", "stt_prop_stunt_track_start", "stt_prop_stunt_track_start_02", "stt_prop_stunt_track_straight", 
		"stt_prop_stunt_track_straightice", "stt_prop_stunt_track_st_01", "stt_prop_stunt_track_st_02", "stt_prop_stunt_track_turn", 
		"stt_prop_stunt_track_turnice", "stt_prop_stunt_track_uturn", "stt_prop_track_fork_bar", "stt_prop_track_funnel", 
		"stt_prop_track_funnel_ads_01a", "stt_prop_track_funnel_ads_01b", "stt_prop_track_funnel_ads_01c", "stt_prop_track_jump_01a", 
		"stt_prop_track_jump_01b", "stt_prop_track_jump_01c", "stt_prop_track_jump_02a", "stt_prop_track_jump_02b", "stt_prop_track_jump_02c", 
		"stt_prop_track_link", "stt_prop_track_slowdown", "stt_prop_track_slowdown_t1", "stt_prop_track_slowdown_t2", "stt_prop_track_speedup", 
		"stt_prop_track_speedup_t1", "stt_prop_track_speedup_t2", "stt_prop_track_start", "stt_prop_track_start_02", "stt_prop_track_stop_sign", 
		"stt_prop_track_tube_01", "stt_prop_track_tube_02", "stt_prop_tyre_wall_01", "stt_prop_tyre_wall_010", "stt_prop_tyre_wall_011", 
		"stt_prop_tyre_wall_012", "stt_prop_tyre_wall_013", "stt_prop_tyre_wall_014", "stt_prop_tyre_wall_015", "stt_prop_tyre_wall_02", 
		"stt_prop_tyre_wall_03", "stt_prop_tyre_wall_04", "stt_prop_tyre_wall_05", "stt_prop_tyre_wall_06", "stt_prop_tyre_wall_07", 
		"stt_prop_tyre_wall_08", "stt_prop_tyre_wall_09", "stt_prop_tyre_wall_0l010", "stt_prop_tyre_wall_0l012", "stt_prop_tyre_wall_0l013", 
		"stt_prop_tyre_wall_0l014", "stt_prop_tyre_wall_0l015", "stt_prop_tyre_wall_0l018", "stt_prop_tyre_wall_0l019", "stt_prop_tyre_wall_0l020", 
		"stt_prop_tyre_wall_0l04", "stt_prop_tyre_wall_0l05", "stt_prop_tyre_wall_0l06", "stt_prop_tyre_wall_0l07", "stt_prop_tyre_wall_0l08", 
		"stt_prop_tyre_wall_0l1", "stt_prop_tyre_wall_0l16", "stt_prop_tyre_wall_0l17", "stt_prop_tyre_wall_0l2", "stt_prop_tyre_wall_0l3", 
		"stt_prop_tyre_wall_0r010", "stt_prop_tyre_wall_0r011", "stt_prop_tyre_wall_0r012", "stt_prop_tyre_wall_0r013", "stt_prop_tyre_wall_0r014", 
		"stt_prop_tyre_wall_0r015", "stt_prop_tyre_wall_0r016", "stt_prop_tyre_wall_0r017", "stt_prop_tyre_wall_0r018", "stt_prop_tyre_wall_0r019", 
		"stt_prop_tyre_wall_0r04", "stt_prop_tyre_wall_0r05", "stt_prop_tyre_wall_0r06", "stt_prop_tyre_wall_0r07", "stt_prop_tyre_wall_0r08",
		"stt_prop_tyre_wall_0r09", "stt_prop_tyre_wall_0r1", "stt_prop_tyre_wall_0r2", "stt_prop_tyre_wall_0r3", "stt_prop_wallride_01",
		"stt_prop_wallride_01b", "stt_prop_wallride_02", "stt_prop_wallride_02b", "stt_prop_wallride_04", "stt_prop_wallride_05",
		"stt_prop_wallride_05b", "stt_prop_wallride_45l", "stt_prop_wallride_45la", "stt_prop_wallride_45r", "stt_prop_wallride_45ra", 
		"stt_prop_wallride_90l", "stt_prop_wallride_90lb", "stt_prop_wallride_90r", "stt_prop_wallride_90rb"
	};*/

	const char* const weather_enum[] =
	{
		"CLEAR", "EXTRASUNNY", "CLOUDS",
		"OVERCAST", "RAIN", "CLEARING",
		"THUNDER", "SMOG", "FOGGY",
		"XMAS", "SNOWLIGHT", "BLIZZARD"
	};

	const DWORD ped_animal_hash[] =
	{
		0xce5ff074, 0xaab71f62, 0xa8683715, 0x14ec17ea,	//"a_c_boar", "a_c_chickenhawk", "a_c_chimp", "a_c_chop", 
		0x56e29962, 0xfcfa9e1e, 0x644ac75e, 0x18012a9f, //"a_c_cormorant", "a_c_cow", "a_c_coyote", "a_c_crow", 
		0xd86b5a95, 0x2fd800b7, 0x6af51faf, 0x4e8f95a2,	//"a_c_deer", "a_c_fish", "a_c_hen", "a_c_husky", 
		0x1250d7ba, 0xb11bab56, 0x6a20728, 0xc3b52966,	//"a_c_mtlion", "a_c_pig", "a_c_pigeon", "a_c_rat", 
		0x349f33e1, 0xc2d06f53, 0x9563221d,				//"a_c_retriever", "a_c_rhesus", "a_c_rottweiler", 
		0xd3939dfd, 0x6c3f072, 0x431fc24c,				//"a_c_seagull", "a_c_sharktiger", "a_c_shepherd"
	};

	const char* const ped_animal_name[] = {
		"Boar", "Chicken Hawk", "Chimp", "Chop", 
		"Cormorant", "Cow", "Coyote", "Crow", 
		"Deer", "Fish (!)", "Hen", "Husky", 
		"Mountain Lion", "Pig", "Pigeon", "Rat", 
		"Retriever", "Rhesus", "Rottweiler", 
		"Seagull", "Tiger Shark (!)", "Shephard"
	};

	const DWORD ped_emergency_hash[] =
	{
		0x15f8700d, 0x5e3da4a4, 0x4161d042,	//"s_f_y_cop_01", "s_m_y_cop_01", "s_f_y_sheriff_01",
		0xb144f9b9, 0xd768b228, 0x1ae8bb58,	//"s_m_y_sheriff_01", "s_m_m_security_01", "s_m_m_snowcop_01", 
		0x56c96fc6, 0xb353629e, 0xd47303ac,	//"s_m_m_prisguard_01", "s_m_m_paramedic_01", "s_m_m_doctor_01"
	};

	const char* const ped_emergency_name[] =
	{
		"Female Cop", "Male Cop", "Female Sheriff",
		"Male Sheriff", "Security Guard", "Snow Cop", 
		"Prison Guard", "Paramedic", "Docter"
	};

	const DWORD ped_sex_hash[] =
	{
		0x28abf95, 0x14c3e407, 0x31640ac,	//"s_f_y_hooker_01", "s_f_y_hooker_02", "s_f_y_hooker_03",
		0x5c14edfa, 0x52580019, 0x6e0fb794,	//"s_f_y_stripperlite", "s_f_y_stripper_01", "s_f_y_stripper_02",
		0x9cf26183,							//"a_f_y_topless_01"
	};

	const char* const ped_sex_name[] =
	{
		"Hooker 1", "Hooker 2", "Hooker 3",
		"Stripper 1", "Stripper 2", "Stripper 3",
		"Topless Female"
	};

	const DWORD ped_story_hash[] =
	{
		0xd7114c9, 0x9b22dbaf, 0x9b810fa2, 0xd266d9d6,	//"player_zero", "player_one", "player_two", "cs_wade",
		0x3a5201c5, 0x893d6805, 0xf6d1e04e, 0xa4e0a1fe,	//"cs_terry", "cs_stretch", "cs_solomon", "cs_stevehains",
		0x8b70b405, 0x7896da94, 0xb594f5c3, 0x72551375,	//"cs_omega", "cs_nervousron", "cs_lestercrest","cs_lifeinvad_01",
		0x38951a1b, 0x45463a0d, 0xb8cc92b4, 0x62547e7,	//"cs_lazlow", "cs_lamardavis", "cs_jimmydisanto", "cs_floyd",
		0x47035ec1, 0x4772af42, 0x2f016d02, 0xc1f380e6,	//"cs_fabien", "cs_dom", "cs_devin", "cs_chrisformage", 
		0xdbcb9834, 0xefe5afe6,							//"cs_clay", "cs_brad"
	};

	const char* const ped_story_name[] =
	{
		"Michael", "Franklin", "Trevor", "Wade",
		"Terry", "Stretch", "Solomon", "Steve Hains",
		"Omega", "Ron", "Lester","Ricky",
		"Lazlow", "Lamar", "Jimmy", "Floyd",
		"Fabien", "Dom", "Devin", "Chris Formage", 
		"Clay", "Brad"
	};

	const DWORD ped_misc_hash[] =
	{
		0x348065f5, 0xac4b4506, 0x9c70109d,	//"u_m_y_imporage", "u_m_y_zombie_01", "u_f_y_corpse_01",
		0xd9c72f8, 0x73dea88b, 0x4d6de57e,	//"u_f_y_corpse_02", "mp_f_deadhooker", "cs_priest",
		0xce2cb751, 0x4498dde, 0x64611296,	//"u_m_m_jesus_01", "s_m_y_clown_01", "s_m_m_movalien_01"
	};

	const char* const ped_misc_name[] =
	{
		"Impotent Rage", "Zombie", "Corpse 1",
		"Corpse 2", "Dead Hooker", "Priest",
		"Jesus", "Clown", "Alien"
	};

	const DWORD vehicle_boat_hash[] =
	{
		0x3d961290, 0x107f392c, 0x1e5e54ea, 0x33b47f96, 0x33581161,	//"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
		0xc1ce1183, 0xe2e7d4ab, 0xc2974024, 0xdb4388e4, 0xed762d49,	//"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
		0xdc60d2b, 0x1a144f2a, 0x17df5ec2, 0x2dff622f, 0xc07107ee,	//"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
		0xef2295c9, 0x3fd5aa2f, 0x362cac6d, 0x1149422f, 0x56590fe9,	//"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
		0x82cac433,													//"TUG"
	};

	const char* const vehicle_boat_name[] =
	{
		"Dinghy", "Dinghy 2", "Dinghy 3", "Dinghy 4", "Jetmax",
		"Marquis", "Predator (police)", "Seashark", "Seashark 2", "Seashark 3",
		"Speeder", "Speeder 2", "Squalo", "Submarine", "Submarine 2",
		"Suntrap", "Toro", "Toro 2", "Tropic", "Tropic 2",
		"Tug"
	};
 
	const DWORD vehicle_commercial_hash[] =
	{
		0x7a61b330, 0x32b91ae8, 0x5a82f9ae, 0x35ed670b, 0xc1632beb,	//"BENSON", "BIFF", "HAULER", "MULE", "MULE2",
		0x85a5b471, 0x21eee87d, 0x809aa4cb, 0x7de35e7d, 0x6827cf72,	//"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
		0xf337ab36,													//"STOCKADE3"
	};

	const char* const vehicle_commercial_name[] =
	{
		"Vapid Benson", "HVY Biff", "JoBuilt Hauler", "Maibatsu Mule", "Maibatsu Mule 2",
		"Maibatsu Mule 3", "MTL Packer", "JoBuilt Phantom", "MTL Pounder", "Brute Stockade",
		"Brute Stockade (Snow)"
	};
 
	const DWORD vehicle_compact_hash[] =
	{
		0xeb70965f, 0x5c55cb39, 0xbc993509, 0x64430650, 0xb9cb3b69,	//"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
		0xe644e480, 0xa988d3a2, 0x322cf98f,							//"PANTO", "PRAIRIE", "RHAPSODY"
	};

	const char* const vehicle_compact_name[] =
	{
		"Dinka Blista", "Grotti Brioso R/A", "Karin Dilettante", "Karin Dilettante (Patrol)", "Weeny Issi",
		"Benefactor Panto", "Bollokan Prairie", "Declasse Rhapsody"
	};
 
	const DWORD vehicle_coupe_hash[] =
	{
		0x13b57d8a, 0xffb15b5e, 0xdcbcbe48, 0xe8a8bda8, 0xfaad85ee,	//"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
		0xdac67112, 0x506434f6, 0xe18195b2, 0x50732c82, 0x3412ae2d,	//"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
		0x5e4327c8, 0x8cf5cae1, 0xbd1b39c3, 0xb8e2ae18,				//"WINDSOR", "WINDSOR2", "ZION", "ZION2"
	};

	const char* const vehicle_coupe_name[] =
	{
		"Enus Cognoscenti Cabrio", "Dewbauchee Exemplar", "Ocelot F620", "Lampadati Felon", "Lampadati Felon GT",
		"Ocelot Jackal", "Ubermacht Oracle XS", "Ubermacht Oracle", "Ubermacht Sentinel XS", "Ubermacht Sentinel",
		"Enus Windsor", "Enus Windsor Drop", "Ubermacht Zion", "Ubermacht Zion Cabrio"
	};
 
	const DWORD vehicle_cycle_hash[] =
	{
		0x43779c54, 0x1aba13b5, 0xce23d3bf, 0xf4e1aa15, 0x4339cd69,	//"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
		0xb67597ec, 0xe823fb48,										//"TRIBIKE2", "TRIBIKE3"
	};

	const char* const vehicle_cycle_name[] =
	{
		"Bmx", "Cruiser", "Fixter", "Scorcher", "Whippet Race Bike",
		"Endurex Race Bike", "Tri-Cycles Race Bike"
	};
 
	const DWORD vehicle_emergency_hash[] =
	{
		0x45d56ada, 0x432ea949, 0x9dc66994, 0x73920f8e, 0x1bf8d381,	//"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
		0x885f3671, 0x2c33b46e, 0x79fbb0c5, 0x9f05f101, 0x71fa16ea,	//"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
		0x8a63c7b9, 0xfdefaec3, 0xa46462f7, 0x95f4c618, 0x1b38e955,	//"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
		0x9baa707c, 0x72935408, 0xb822a1aa,							//"SHERIFF", "SHERIFF2", "RIOT"
	};

	const char* const vehicle_emergency_name[] =
	{
		"Ambulance", "FIB Buffalo", "FIB Granger", "Fire Truck", "Lifeguard Granger",
		"Prison Bus", "Park Ranger Granger", "Police Cruiser", "Police Cruiser 2", "Police Cruiser 3",
		"Unmarked Cruiser", "Police Bike", "Police Cruiser Snow", "Police Cruiser Snow 2", "Police Transporter",
		"Sheriff Cruiser", "Sheriff SUV", "Police Riot"
	};
 
	const DWORD vehicle_helicopter_hash[] =
	{
		0x31f0b376, 0xf7004c86, 0xdb6b4924, 0x2f03547b, 0x2c75f0dd,	//"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
		0xfcfcb68b, 0x60a7ea10, 0x53174eef, 0x78bc1a3c, 0x2c634fbd,	//"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
		0x742e9ac0, 0x9d0450ca, 0x1517d4d9, 0xfb133a17, 0x3e48bf23,	//"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
		0x2a54c47d, 0x9c5e5644, 0xebc24df2, 0x4019cb4c, 0xa09e15fd,	//"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
		0x5bfa5c4b, 0x920016f1,										//"VALKYRIE2", "VOLATUS"
	};

	const char* const vehicle_helicopter_name[] =
	{
		"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
		"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
		"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
		"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
		"VALKYRIE2", "VOLATUS"
	};
 
	const DWORD vehicle_industrial_hash[] =
	{
		0x7074f39d, 0xc3fba120, 0x810369e2, 0x50b0215a, 0x825a9f4c,	//"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
		0x1a7fcefa, 0xd138a6bb, 0x1c534995, 0x9a5b1dcc, 0x2e19879,	//"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
		0xc7824e5e,													//"TIPTRUCK2"
	};

	const char* const vehicle_industrial_name[] =
	{
		"HVY Dozer", "HVY Cutter", "HVY Dump", "MTL Flatbed", "Vapid Guardian",
		"Dock Handler", "HVY Mixer", "HVY Mixer 2", "JoBuilt Rubble", "Brute Tipper",
		"Tipper"
	};
 
	const DWORD vehicle_military_hash[] =
	{
		0xceea3f4b, 0x4008eabb, 0x2592b5cf, 0x132d5a1a, 0x2ea68690,	//"BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO"
	};

	const char* const vehicle_military_name[] =
	{
		"Barracks", "HVY Barracks Semi", "Barracks 3", "Canis Crusader", "Rhino Tank"
	};
 
	const DWORD vehicle_motorcycle_hash[] =
	{
		0x63abade7, 0x81e38f7f, 0x806b9cc3, 0xf9300cc5, 0xcadd5d2d,	//"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
		0x5283265, 0xabb0c0, 0x675ed7, 0x17420102, 0x77934cee,		//"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
		0xac4e93c9, 0x30ff0190, 0x9c669788, 0x6882fa73, 0x794cb30c,	//"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
		0x9229e4eb, 0x350d1ab, 0xb328b188, 0x2c2c2324, 0x4b6c568a,	//"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
		0xf0c2a91f, 0x11f76c14, 0xf683eaca, 0x26321e67, 0xa5325278,	//"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
		0xda288376, 0xa0438767, 0xc9ceaf06, 0x6facdf31, 0xcabd11e8,	//"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
		0x2ef89e46, 0xa960b13e, 0x58e316c7, 0xe7d2a16e, 0x2c509634,	//"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
		0x6d6f8f43, 0xf79a00f7, 0xaf599f01, 0xdba9dbfc, 0xdb20a373,	//"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
		0xc3d7c72b, 0xde05fb87,										//"ZOMBIEA", "ZOMBIEB"
	};

	const char* const vehicle_motorcycle_name[] =
	{
		"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
		"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
		"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
		"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
		"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
		"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
		"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
		"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
		"ZOMBIEA", "ZOMBIEB"
	};
 
	const DWORD vehicle_muscle_hash[] =
	{
		0xb820ed5e, 0xd756460c, 0xc397f748, 0x14d69010, 0xaed64a63,	//"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
		0x2ec385fe, 0x4ce68ac, 0xc96b73d9, 0x2b26f456, 0xec8f7094,	//"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
		0x94b395c5, 0x14d22159, 0x81a9cddf, 0x95466bdb, 0x866bce26,	//"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
		0x239e390, 0x7b47a6a7, 0x1f52a43f, 0x710a2b9b, 0x8c2bd0dc,	//"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
		0x831a21d5, 0x59e0fbf3, 0xd83c13ce, 0xdce1d9f7, 0xf26ceff9,	//"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER",
		0x9b909c94, 0xd4ea603, 0x2b7f9de3, 0x31adbbfc, 0x42bc5e19,	//"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
		0x72a4c31e, 0xe80f67ee, 0x39f9c898, 0xcec6b9b7, 0xe2504942,	//"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
		0xca62927a, 0xfdffb0, 0x779b4f2d, 0x1f3766e3,				//"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
	};

	const char* const vehicle_muscle_name[] =
	{
		"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
		"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
		"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
		"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
		"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER",
		"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
		"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
		"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
	};
 
	const DWORD vehicle_offroad_hash[] =
	{
		0x432aa566, 0xeb298297, 0x8125bcf9, 0xfd231729, 0xb44f0582,	//"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
		0xe5ba6858, 0xaa699bb6, 0xa7ce1bc5, 0x698521e3, 0xb6410173,	//"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
		0x9cf21e0f, 0x1fd824af, 0x9114eada, 0x7b7e56f0, 0x5852838,	//"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
		0x49863e9c, 0x84f42e51, 0xcd93a7db, 0x6210cbb0, 0x7341576b,	//"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
		0xb802dd46, 0x8612b64b, 0xb9210fd0, 0x3af8c345, 0x83051506,	//"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
		0x612f4b6, 0xd876dbe2,										//"TROPHYTRUCK", "TROPHYTRUCK2"
	};

	const char* const vehicle_offroad_name[] =
	{
		"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
		"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
		"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
		"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
		"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
		"TROPHYTRUCK", "TROPHYTRUCK2"
	};
 
	const DWORD vehicle_plane_hash[] =
	{
		0x6cbd1d6d, 0x15f27762, 0xd9927fe3, 0xca495705, 0x39d6779e,	//"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
		0x39d6e83f, 0x3f119114, 0xb39b0ae6, 0x250b0c5e, 0xb79f589e,	//"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
		0x97e55d11, 0x9d80f93, 0xb2cf7250, 0xb79c1bf5, 0x81794c70,	//"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
		0x761e2ad3, 0x9c429b6a, 0x403820e8, 0x4ff77e37,				//"TITAN", "VELUM", "VELUM2", "VESTRA"
	};

	const char* const vehicle_plane_name[] =
	{
		"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
		"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
		"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
		"TITAN", "VELUM", "VELUM2", "VESTRA"
	};
 
	const DWORD vehicle_sedan_hash[] =
	{
		0x94204d89, 0x9441d8d5, 0x8e9254fb, 0x360a438e, 0x29fcd3e4,	//"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
		0x86fe0b60, 0xdbf2d57a, 0xd7278283, 0x8fc3aadc, 0xb5fcf74e,	//"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
		0x71cb2ffb, 0x47a6bc1, 0xb3206692, 0x34dd8aa1, 0xf92aec4d,	//"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
		0x8fb66f9b, 0xbb6b404f, 0x86618eda, 0xff22d208, 0x2560b2fc,	//"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
		0xb52b5113, 0xcb0e7cd9, 0x72934be4, 0xa7ede74d, 0x66b4fc45,	//"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
		0x8b13f083, 0x42f2ed16, 0x8f0e3594, 0xc3ddfdce, 0x51d83328,	//"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
		0x69f06b57,													//"WASHINGTON"
	};

	const char* const vehicle_sedan_name[] =
	{
		"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
		"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
		"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
		"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
		"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
		"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
		"WASHINGTON"
	};
 
	const DWORD vehicle_service_hash[] =
	{
		0x4c80eb0e, 0xedc6f847, 0xd577c962, 0x84718d34, 0x829a3c44,	//"AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
		0xbe819c63, 0xc703db5f, 0x73b1c3cb, 0x72435a19, 0xb527915c,	//"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2"
	};

	const char* const vehicle_service_name[] =
	{
		"Airport Bus", "MTL Brickade", "Bus", "Dashound", "MTL Dune",
		"Rental Shuttle Bus", "Taxi", "Tourbus", "Trashmaster", "Trashmaster 2"
	};
 
	const DWORD vehicle_sport_hash[] =
	{
		0x2db8d1aa, 0xc1e908d2, 0x4bfcf28b, 0x3dee5eda, 0xdcbc1c3b,	//"ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
		0xedd516c6, 0x2bec3cbe, 0xe2c013e, 0x7b8ab45f, 0xc1ae4d16,	//"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
		0x67bc037, 0xde3d9d22, 0x8911b9f5, 0xbf1691e0, 0x1dc0ba53,	//"COQUETTE", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
		0x7836ce2f, 0xb2a716a3, 0xbe0e6126, 0x206d1b68, 0xae2bfe94,	//"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
		0x187d938d, 0x1cbdc10b, 0xf77ade32, 0xda5819a3, 0x3d8fa25c,	//"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
		0xa8e38b01, 0xd1ad4937, 0xe9805550, 0x8cb29a14, 0x679450af,	//"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
		0xd7c56d39, 0x2ae524a8, 0xa774b5a6, 0x58cf185c, 0x2b122c82,	//"RAPTOR", "RUSTON", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER",
		0x97398a4b, 0x39da2754, 0x16e478c1, 0xc0240885, 0x707e63a4,	//"SEVEN70", "SULTAN", "SURANO", "TAMPA2", "TROPOS",
		0x41b77fa4,													//"VERLIERER2"
	};

	const char* const vehicle_sport_name[] =
	{
		"Albany Alpha", "Bravado Banshee", "Grotti Bestia GTS", "Dinka Blista Compact", "Dinka Blista Go GO Monkey",
		"Bravado Buffalo", "Bravado Buffalo S", "Bravado Buffalo Spunk", "CARBONIZZARE", "COMET2",
		"COQUETTE", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
		"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
		"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
		"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
		"RAPTOR", "RUSTON", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER",
		"SEVEN70", "SULTAN", "SURANO", "TAMPA2", "TROPOS",
		"VERLIERER2"
	};
 
	const DWORD vehicle_sport_classic_hash[] =
	{
		0x6ff6914, 0xce6b35a4, 0xdc19d101, 0x3822bdfe, 0x3c4e2113,	//"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
		0xa29d6d10, 0xac33179c, 0x3eab5555, 0x9cfffc56, 0x81634188,	//"FELTZER3", "INFERNUS2", "JB700", "MAMBA", "MANANA",
		0xe62b361b, 0x6d19ccbc, 0x404b6381, 0x5c23af9b, 0x82e499fa,	//"MONROE", "PEYOTE", "PIGALLE", "STINGER", "STINGERGT",
		0x1bb290bc, 0x5b42a5c4, 0x690a4153, 0x86cf7cdd, 0x94da98ef,	//"TORNADO", "TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5",
		0xa31cb573, 0xc575df11, 0x2d3bd401,							//"TORNADO6", "TURISMO2", "ZTYPE"
	};

	const char* const vehicle_sport_classic_name[] =
	{
		"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
		"FELTZER3", "INFERNUS2", "JB700", "MAMBA", "MANANA",
		"MONROE", "PEYOTE", "PIGALLE", "STINGER", "STINGERGT",
		"TORNADO", "TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5",
		"TORNADO6", "TURISMO2", "ZTYPE"
	};
 
	const DWORD vehicle_super_hash[] =
	{
		0xb779a091, 0x25c5af13, 0x9ae6dda1, 0xb1d95da0, 0xb2fe5cf9,	//"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
		0x5502626c, 0x4992196c, 0x30d3f6d8, 0x18f25ac7, 0x767164d6,	//"FMJ", "GP1", "SHEAVA", "INFERNUS", "OSIRIS",
		0xb6846a55, 0x92ef6e04, 0x7e8f677f, 0xdf381e5, 0xee6024bc,	//"LE7B", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS",
		0x6322b39a, 0x185484e1, 0x7b406efb, 0x142e0dc3, 0x9f4b77be,	//"T20", "TURISMOR", "TYRUS", "VACCA", "VOLTIC",
		0xac5df515,													//"ZENTORNO"
	};

	const char* const vehicle_super_name[] =
	{
		"Adder", "Banshee Super", "Bullet", "Cheetah", "ENTITYXF",
		"FMJ", "GP1", "SHEAVA", "INFERNUS", "OSIRIS",
		"LE7B", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS",
		"T20", "TURISMOR", "TYRUS", "VACCA", "VOLTIC",
		"ZENTORNO"
	};
 
	const DWORD vehicle_suv_hash[] =
	{
		0xcfca3668, 0x8852855, 0x6ff0f727, 0x25cbe2e2, 0x1c09cf5e,	//"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
		0x27b4e6b0, 0x32b29a4b, 0x779f23aa, 0xd0eb2be5, 0x28b67aca,	//"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
		0x462fe277, 0xe882e5f6, 0xbc32a33b, 0x9628879c, 0xa3fc0f4d,	//"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
		0x34b7390f, 0x1d06d681, 0x4ba4e8dc, 0x36848602, 0xd36a4b44,	//"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
		0xcfcfeb3b, 0x9d96b45b, 0x7f5c91f1, 0x48ceced3, 0x4fb1a214,	//"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
		0x47bbcf2e, 0xe6401328,										//"XLS", "XLS2"
	};

	const char* const vehicle_suv_name[] =
	{
		"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
		"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
		"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
		"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
		"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
		"XLS", "XLS2"
	};
 
	const DWORD vehicle_trailer_hash[] =
	{
		0xb8081009, 0xa7ff33f5, 0x9e6b14d6, 0xe82ae656, 0x1f3d44b5,	//"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
		0x806efbee, 0xd1abb666, 0x3cc7f596, 0x153e1b0a, 0x174cb172,	//"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
		0xd46f4737, 0x74998082, 0x7be032c6, 0x6a59902d, 0x7cab34d0,	//"TANKER", "TANKER2", "TR2", "TR3", "TR4",
		0x782a236d, 0xcbb2be0e, 0xa1da3c91, 0x8548036d, 0x2a72beab,	//"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
		0xaf62f6b2, 0x967620be,										//"TRFLAT", "TVTRAILER"
	};

	const char* const vehicle_trailer_name[] =
	{
		"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
		"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
		"TANKER", "TANKER2", "TR2", "TR3", "TR4",
		"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
		"TRFLAT", "TVTRAILER"
	};
 
	const DWORD vehicle_train_hash[] =
	{
		0xc6c3242d, 0x3d6aaa9b, 0xafd22a6, 0x36dcff98, 0xe512e79,	//"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
		0x264d9262, 0x33c9e158, 0x22eddc30,							//"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
	};

	const char* const vehicle_train_name[] =
	{
		"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
		"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
	};
 
	const DWORD vehicle_utility_hash[] =
	{
		0x5d0aac8f, 0x44623884, 0xdff0594c, 0xcb44b1ca, 0x58e49664,	//"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
		0x6a4bd8f6, 0xcd935ef9, 0xdc434e51, 0x2bc345d1, 0x9a9fd3df,	//"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
		0xb12314e0, 0xe5a2d6c6, 0x61d6ba8c, 0x843b73de, 0x562a97bd,	//"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
		0x1ed0a534, 0x34e6bf6b, 0x7f2153df,							//"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
	};

	const char* const vehicle_utility_name[] =
	{
		"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
		"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
		"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
		"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
	};
 
	const DWORD vehicle_van_hash[] =
	{
		0xfefd644f, 0x7b8297c5, 0x67b3f020, 0x3fc5d440, 0x898eccea,	//"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
		0xf21b33be, 0x7405e08, 0x1a79847a, 0xafbb2ca4, 0xc9e8ff76,	//"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
		0x98171bd3, 0x353b561d, 0x437cf2a0, 0x6fd95f68, 0x97fa4f36,	//"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
		0x11aa0e14, 0xf8d48e7a, 0xed7eada4, 0xbcde91f0, 0x58b3979c,	//"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
		0xf8de29a8, 0x38408341, 0x4543b74d, 0x961afef7, 0x57f682af,	//"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
		0xcfb3870c, 0x2b6dc64a, 0x29b0da97, 0xb1d80e06, 0x744ca80d,	//"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
		0x3e5f6b8, 0x3d29cd2b,										//"YOUGA", "YOUGA2"
	};

	const char* const vehicle_van_name[] =
	{
		"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
		"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
		"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
		"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
		"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
		"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
		"YOUGA", "YOUGA2"
	};

	const DWORD vehicle_importexport_hash[] =
	{
		0xa1355f67, 0x28ad20e1, 0x877358ad, 0xf1b44f44, 0x6abdf65e,	//"blazer5", "boxville5", "comet3", "diablous", "diablous2",
		0xceb28249, 0xed62bfa9, 0xbba2261, 0x25676eaf, 0xd2d5e00e,	//"dune4", "dune5", "elegy", "fcr", "fcr2",
		0x85e8e76b, 0xe33a477b, 0x3da47243, 0x4131f378, 0x9734f3ea,	//"italigtb", "italigtb2", "nero", "nero2", "penetrator",
		0x9dae1398, 0x381e10bd, 0x2e5afd37, 0x706e2b40, 0x400f5147,	//"phantom2", "ruiner2", "ruiner3", "specter", "specter2",
		0x4662bcbb, 0x1044926f, 0x3af76f4a, 0x8e08ec82,				//"technical2","tempesta", "voltic2", "wastelander"
	};

	const char* const vehicle_importexport_name[] =
	{
		"blazer5", "boxville5", "comet3", "diablous", "diablous2",
		"dune4", "dune5", "elegy", "fcr", "fcr2",
		"italigtb", "italigtb2", "nero", "nero2", "penetrator",
		"phantom2", "ruiner2", "ruiner3", "specter", "specter2",
		"technical2","tempesta", "voltic2", "wastelander",
	};

	const DWORD ped_bone_hash[] =
	{
		0x796E, 0x9995, 0x60F2, 0x60F1,
		0x60F0, 0x5C01, 0xFCD9, 0x29D2,
		0xB1C5, 0x9D4D, 0xEEEB, 0x6E5C,
		0x49D9, 0xDEAD, 0xE39F, 0xCA72,
		0xF9BB, 0x9000, 0x3779, 0xCC4D,
	};

	const char* const ped_bone_name[] =
	{
		"Head", "Neck", "Spine 1", "Spine 2",
		"Spine 3", "Spine 4", "L Clavicle", "R Clavicle",
		"L Shoulder", "R Shoulder", "L Elbow", "R Elbow",
		"L Hand", "R Hand", "L Thigh", "R Thigh",
		"L Knee", "R Knee", "L Foot", "R Foot"
	};
	


	const char* const explosion_enum[] =
	{
		"Grenade", "Grenade Launcher", "Sticky Bomb",
		"Molotov", "Rocket", "Tank Shell", "Octane",
		"Car", "Plane", "Petrol Pump", "Bike", "Water",
		"Flame", "Water Hydrant", "Flame Canister",
		"Boat", "Ship", "Truck", "Bullet", "Smoke Launcher",
		"Smoke Grenade", "BZ Gas", "Flare", "Gas Canister",
		"Extinguisher", "Programmable AR", "Train",
		"Barrel", "Propane", "Blimp", "Flame 2", "Tanker",
		"Plane Rocket", "Vehicle Bullet", "Gas Tank"
	};

	const char* const triggerbot_enum[] =
	{
		"Peds", "Players"
	};

	const char* const veh_color_enum[] = 
	{
		"Mtlc Black",
		"Mtlc Graphite Black", "Mtlc Black Steal", "Mtlc Dark Silver", "Mtlc Silver", "Mtlc Blue Silver",
		"Mtlc Steel Gray", "Mtlc Shadow Silver", "Mtlc Stone Silver", "Mtlc Midnight Silver", "Mtlc Gun Metal",
		"Mtlc Antrct Grey", "Matte Black", "Matte Gray", "Matte Light Grey", "Util Black",
		"Util Black Poly", "Util Dark silver", "Util Silver", "Util Gun Metal", "Util ShadowSilver",
		"Worn Black", "Worn Graphite", "Worn Silver Grey", "Worn Silver", "Worn Blue Silver",
		"Worn ShadowSilver", "Mtlc Red", "Mtlc Torino Red", "Mtlc Formula Red", "Mtlc Blaze Red",
		"Mtlc Graceful Red", "Mtlc Garnet Red", "Mtlc Desert Red", "Mtlc Cabernet Red", "Mtlc Candy Red", 
		"Mtlc Snrs Orange", "Mtlc Classic Gold", "Mtlc Orange", "Matte Red", "Matte Dark Red", 
		"Matte Orange", "Matte Yellow", "Util Red", "Util Bright Red", "Util Garnet Red", 
		"Worn Red", "Worn Golden Red", "Worn Dark Red", "Mtlc Dark Green", "Mtlc Racing Green", 
		"Mtlc Sea Green", "Mtlc Olive Green", "Mtlc Green", "Mtlc Gas BlueGreen", "Matte Lime Green", 
		"Util Dark Green", "Util Green", "Worn Dark Green ", "Worn Green", "Worn Sea Wash", 
		"Mtlc Midnight Blue", "Mtlc Dark Blue", "Mtlc Saxony Blue", "Mtlc Blue", "Mtlc Mariner Blue", 
		"Mtlc Harbor Blue", "Mtlc Diamond Blue", "Mtlc Surf Blue", "Mtlc Nautical Blue", "Mtlc Bright Blue", 
		"Mtlc Purple Blue", "Mtlc Spinnaker Blue", "Mtlc Ultra Blue", "Mtlc Bright Blue", "Util Dark Blue", 
		"Util Midnight Blue", "Util Blue", "Util Sea Foam Blue", "Uil Lightning blue", "Util Maui Blue Poly", 
		"Util Bright Blue", "Matte Dark Blue", "Matte Blue", "Matte MidnightBlue", "Worn Dark Blue", 
		"Worn Blue", "Worn Light Blue", "Mtlc Taxi Yellow", "Mtlc Race Yellow", "Mtlc Bronze", 
		"Mtlc Yellow Bird", "Mtlc Lime", "Mtlc Champagne", "Mtlc Pueblo Beige", "Mtlc Dark Ivory", 
		"Mtlc Choco Brown", "Mtlc Golden Brown", "Mtlc Light Brown", "Mtlc Straw Beige", "Mtlc Moss Brown", 
		"Mtlc Biston Brown", "Mtlc Beechwood", "Mtlc Dark Wood", "Mtlc Choco Orange", "Mtlc Beach Sand", 
		"Mtlc Sun Blch Sand", "Mtlc Cream", "Util Brown", "Util Medium Brown", "Util Light Brown", 
		"Mtlc White", "Mtlc Frost White", "Worn Honey Beige", "Worn Brown", "Worn Dark Brown", 
		"Worn Straw Beige", "Brushed Steel", "Brushed Black Steel", "Brushed Aluminium", "Chrome", 
		"Worn Off White", "Util Off White", "Worn Orange", "Worn Light Orange", "Mtlc Scurcr Green", 
		"Worn Taxi Yellow", "Police Blue", "Matte Green", "Matte Brown", "Worn Orange", 
		"Matte White", "Worn White", "Worn Olive Green", "Pure White", "Hot Pink", 
		"Salmon pink", "Mtlc Vermillion Pink", "Orange", "Green", "Blue", 
		"Mtlc Black Blue", "Mtlc Black Purple", "Mtlc Black Red", "Hunter Green", "Mtlc Purple", 
		"Mtlc V Dark Blue", "Modshop Black", "Matte Purple", "Matte Dark Purple", "Mtlc Lava Red", 
		"Matte Forest Green", "Matte Olive Drab", "Matte Dsrt Brown", "Matte Dsrt Tan", "Matte Flg Green", 
		"Default Alloy", "Epsilon Blue", "Gold", "Gold Satin", "Gold Spec", 
	};

	const char* const ped_spawn_type[] =
	{
		"Ped", "Bodyguard", "Hostile"
	};

	const char* const chaos_mode_type[] =
	{
		"Bounce", "Ascention", "Armageddon", "Mayhem", "Forcefield",
		"Gravity Field", "Smash", "Massacre", "Energy Field"
	};

	const char* const noclip_type[] =
	{
		"Keyboard", "Cam"
	};

	const char* const crosshair_type[] =
	{
		"Always", "Aiming"
	};

	const char* const ped_anim_dict[] =
	{
		"priv_dance_p1", "mini@strip_club@private_dance@part1",
		"priv_dance_p2", "mini@strip_club@private_dance@part2",
		"priv_dance_p3", "mini@strip_club@private_dance@part3",
		"pd_dance_01", "mini@strip_club@pole_dance@pole_dance1",
		"pd_dance_02", "mini@strip_club@pole_dance@pole_dance2",
		"pd_dance_03", "mini@strip_club@pole_dance@pole_dance3",
		"ld_2g_intro_s2", "mini@strip_club@lap_dance_2g@ld_2g_intro",
		"shag_loop_a", "rcmpaparazzo_2",
		"shag_loop_poppy", "rcmpaparazzo_2",
		"trev_jerking_off_loop", "switch@trevor@jerking_off",
		"peeing_intro", "misscarsteal2peeing",
		"middle_finger", "nm@hands",
		"idle_2_hands_up", "random@getawaydriver",
		"handsup", "ped",
		"f_cower_01", "random@robbery", 
		"m_cower_01", "mp_bank_heist_1",
		"m_cower_02", "mp_bank_heist_1",
		"base", "amb@world_human_push_ups@male@base",
		"base", "amb@world_human_sit_ups@male@base",
		"base", "amb@world_human_smoking@female@base",
		"base", "amb@world_human_smoking@male@male_a@base",
		"base", "amb@world_human_smoking@male@male_b@base",
		"pistol", "mp_suicide",
		"pill", "mp_suicide",
		"toss_many_player", "mini@strip_club@leaning@toss_many",
		"thanks_ps", "random@thanks",
		"thanks_low_ps", "random@thanks",
		"base_b", "amb@world_human_yoga@female@base",
		"base_a", "amb@world_human_yoga@male@base",
		"shots_player_a", "mini@drinking",
		"shots_player_b", "mini@drinking",
		"shots_player_c", "mini@drinking",
	};

	const char* const ped_anim_name[] =
	{
		"Private Dance 1",
		"Private Dance 2",
		"Private Dance 3",
		"Pole Dance 1",
		"Pole Dance 2",
		"Pole Dance 3",
		"Wiggle",
		"Shag Male",
		"Shag Female",
		"Jerk Off",
		"Peeing",
		"Middle Finger",
		"Busted",
		"Hands Up",
		"Cower 1",
		"Cower 2",
		"Cower 3",
		"Push Ups",
		"Sit Ups",
		"Smoking Female",
		"Smoking Male 1",
		"Smoking Male 2",
		"Suicide Gun",
		"Suicide Pill",
		"Toss Money",
		"Thanks",
		"Thanks Low",
		"Yoga Female",
		"Yoga Male",
		"Drinking 1",
		"Drinking 2",
		"Drinking 3",
	};




	//
		//outfits
	//
	const BYTE	outfit_santa_female[0xA][0x3]	= {
		{0x01,	0x08,	0x00},
		{0x03,	0x34,	0x00},
		{0x04,	0x3B,	0x00},
		{0x05,	0x00,	0x00},
		{0x06,	0x28,	0x00},
		{0x07,	0x00,	0x00},
		{0x08,	0x01,	0x02},
		{0x09,	0x00,	0x00},
		{0x0A,	0x00,	0x00},
		{0x0B,	0x6C,	0x00},
	};
	const BYTE	outfit_santa_male[0xA][0x3]	= {
		{0x01,	0x08,	0x00},
		{0x03,	0x32,	0x00},
		{0x04,	0x39,	0x00},
		{0x05,	0x00,	0x00},
		{0x06,	0x27,	0x00},
		{0x07,	0x00,	0x00},
		{0x08,	0x0F,	0x00},
		{0x09,	0x00,	0x00},
		{0x0A,	0x00,	0x00},
		{0x0B,	0x74,	0x00},
	};

	const BYTE	outfit_trash_orange_female[0xA][0x3]	= {
		{0x01,	0x00,	0x00},
		{0x03,	0x0E,	0x00},
		{0x04,	0x23,	0x00},
		{0x05,	0x00,	0x00},
		{0x06,	0x19,	0x00},
		{0x07,	0x00,	0x00},
		{0x08,	0x24,	0x01},
		{0x09,	0x00,	0x00},
		{0x0A,	0x00,	0x00},
		{0x0B,	0x31,	0x00},
	};
	const BYTE	outfit_trash_orange_male[0xA][0x3]	= {
		{0x01,	0x00,	0x00},
		{0x03,	0x00,	0x00},
		{0x04,	0x24,	0x00},
		{0x05,	0x00,	0x00},
		{0x06,	0x19,	0x00},
		{0x07,	0x00,	0x00},
		{0x08,	0x3B,	0x01},
		{0x09,	0x00,	0x00},
		{0x0A,	0x00,	0x00},
		{0x0B,	0x38,	0x00},
	};

	const BYTE	outfit_trash_green_female[0xA][0x3]	= {
		{0x01,	0x00,	0x00},
		{0x03,	0x03,	0x00},
		{0x04,	0x23,	0x00},
		{0x05,	0x00,	0x00},
		{0x06,	0x19,	0x00},
		{0x07,	0x00,	0x00},
		{0x08,	0x24,	0x00},
		{0x09,	0x00,	0x00},
		{0x0A,	0x00,	0x00},
		{0x0B,	0x32,	0x00},
	};
	const BYTE	outfit_trash_green_male[0xA][0x3]	= {
		{0x01,	0x00,	0x00},
		{0x03,	0x04,	0x00},
		{0x04,	0x24,	0x00},
		{0x05,	0x00,	0x00},
		{0x06,	0x19,	0x00},
		{0x07,	0x00,	0x00},
		{0x08,	0x3B,	0x00},
		{0x09,	0x00,	0x00},
		{0x0A,	0x00,	0x00},
		{0x0B,	0x39,	0x00},
	};

	const BYTE	outfit_police_female[0xA][0x3]	= {
		{0x01,	0x00,	0x00},
		{0x03,	0x0E,	0x00},
		{0x04,	0x22,	0x00},
		{0x05,	0x00,	0x00},
		{0x06,	0x19,	0x00},
		{0x07,	0x00,	0x00},
		{0x08,	0x23,	0x00},
		{0x09,	0x00,	0x00},
		{0x0A,	0x00,	0x00},
		{0x0B,	0x30,	0x00},
	};
	const BYTE	outfit_police_male[0xA][0x3]	= {
		{0x01,	0x00,	0x00},
		{0x03,	0x00,	0x00},
		{0x04,	0x23,	0x00},
		{0x05,	0x00,	0x00},
		{0x06,	0x19,	0x00},
		{0x07,	0x00,	0x00},
		{0x08,	0x3A,	0x00},
		{0x09,	0x00,	0x00},
		{0x0A,	0x00,	0x00},
		{0x0B,	0x37,	0x00},
	};
};