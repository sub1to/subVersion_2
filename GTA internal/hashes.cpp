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
	const char* const weapon_hash[] =
	{
		"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_HEAVYPISTOL", "WEAPON_MARKSMANPISTOL",
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

	const char* const radio_station_hash[] = {
	"RADIO_01_CLASS_ROCK", "RADIO_02_POP", "RADIO_03_HIPHOP_NEW",
	"RADIO_04_PUNK", "RADIO_05_TALK_01", "RADIO_06_COUNTRY",
	"RADIO_07_DANCE_01", "RADIO_08_MEXICAN", "RADIO_09_HIPHOP_OLD",
	"RADIO_12_REGGAE", "RADIO_13_JAZZ", "RADIO_14_DANCE_02",
	"RADIO_15_MOTOWN", "RADIO_20_THELAB", "RADIO_16_SILVERLAKE",
	"RADIO_17_FUNK", "RADIO_18_90S_ROCK", "RADIO_19_USER",
	"RADIO_11_TALK_02", "OFF"
	};

	const char* const radio_station_name[] = {
	"Rock Radio", "24/7 Pop", "Los Santos",
	"Channel X", "WCTR", "Rebel Radio",
	"Soulwax", "East Los", "West Coast",
	"Blue Ark", "Worldwide", "FlyLo",
	"Low Down", "The Lab", "Mirror Park",
	"Space", "Vinewood", "Self",
	"Blaine", "Off"
	};

	const char* const object_prop_money_hash[] = {
	"prop_alien_egg_01", "p_v_43_safe_s", "prop_wheelchair_01", "prop_coke_block_01",
	"prop_xmas_tree_int", "prop_beer_neon_01", "prop_space_rifle",
	"prop_dj_deck_01", "prop_micro_01",
	"p_ld_soc_ball_01", "prop_rub_trolley01a",
	"prop_dummy_01", "prop_large_gold", "prop_cs_dildo_01", "prop_fan_01", "prop_golf_bag_01",
	"prop_armchair_01", "prop_armour_pickup", "prop_big_shit_01", "prop_bin_04a", 
	"prop_chair_01a", "prop_chip_fryer", "prop_chickencoop_a", "prop_dog_cage_01",
	"prop_coffin_02", "prop_coffin_02b", "prop_cs_dumpster_01a"
	};

	const char* const object_prop_money_name[] = {
	"Alien Egg", "Safe", "Wheelchair", "Coke Brick",
	"Xmas Tree", "Neon Liquor Sign", "Space Rifle",
	"DJ Deck", "Microwave",
	"Soccer Ball", "Shopping Cart",
	"Mannequin", "Gold Cart", "Dildo", "Fan", "Golf Bag",
	"Arm Chair", "Armour Pickup", "Turd", "Garbage Bin", 
	"Chair", "Fryer", "Chicken Coop", "Dog Cage",
	"Coffin Broken", "Coffin", "Dumpster"
	};

	const char* const object_prop_spawn_misc_hash[] = {
		"prop_xmas_tree_int",  "prop_beer_neon_01", "prop_ld_toilet_01", "prop_space_rifle",
		"prop_food_van_01", "prop_crashed_heli", "prop_dj_deck_01", "prop_portacabin01",
		"prop_micro_01", "prop_tv_flat_01", "prop_wheelchair_01",
		"p_v_43_safe_s", "prop_swiss_ball_01", "p_ld_soc_ball_01", "prop_rub_trolley01a",
		"prop_large_gold", "prop_cs_dildo_01", "prop_fan_01", "prop_golf_bag_01",
		"prop_armchair_01", "prop_armour_pickup", "prop_big_shit_01", "prop_bin_04a", 
		"prop_chair_01a", "prop_chip_fryer", "prop_chickencoop_a", "prop_dog_cage_01",
		"prop_gold_cont_01", "p_cablecar_s", "prop_alien_egg_01",
		"prop_prop_tree_01", "prop_prop_tree_02", "prop_coffin_02", "prop_coffin_02b",
		"prop_cs_dumpster_01a", "prop_pizza_box_01", "prop_pizza_box_02", 
		"prop_cs_panties", "prop_cs_panties_02", "prop_cs_panties_03",
	};

	const char* const object_prop_spawn_misc_name[] = {
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

	const char* const object_prop_spawn_large_hash[] = {
		"p_spinning_anus_s", "prop_air_bigradar", "prop_ld_ferris_wheel", "prop_xmas_ext",
		"prop_windmill_01", "prop_lev_des_barge_01", "prop_lev_des_barge_02", "p_cs_mp_jet_01_s", 
		"prop_pylon_01", "prop_pylon_02", "prop_pylon_03", "prop_pylon_04",
	};

	const char* const object_prop_spawn_large_name[] = {
		"UFO", "Radar Dish", "Ferris Wheel", "Huge Xmas Tree", 
		"Windmill", "Barge 01", "Barge 02", "Plane", 
		"Electricity Pylon 1", "Electricity Pylon 2", "Electricity Pylon 3", "Electricity Pylon 4",
	};

	const char* const object_prop_spawn_drugs_hash[] = {
		"prop_meth_bag_01", "prop_weed_pallet", "Prop_weed_01", "prop_coke_block_01",
		"prop_cs_crackpipe", "prop_cs_meth_pipe", 
	};

	const char* const object_prop_spawn_drugs_name[] = {
		
		"Meth Bag", "Pallet of Weed", "Weed Plant", "Coke Brick",
		"Crack pipe", "Meth Pipe", 
	};

	const char* const object_prop_spawn_music_hash[] = {
		"prop_el_guitar_01", "prop_el_guitar_02", "prop_el_guitar_03",
		"prop_jukebox_01", "prop_jukebox_02", "prop_ghettoblast_02",
	};

	const char* const object_prop_spawn_music_name[] = {
		
		"Electric Guitar 1", "Electric Guitar 2", "Acoustic Guitar",
		"Jukebox 1", "Jukebox 2", "Boombox",
	};

	const char* const object_prop_spawn_commericial_hash[] = {
		"prop_bikini_disp_01", "prop_bikini_disp_02", "prop_bikini_disp_03", "prop_bikini_disp_04", "prop_bikini_disp_05", "prop_bikini_disp_06",
		"prop_dummy_01", "prop_fleeca_atm", "prop_atm_02", "prop_atm_03", "prop_arcade_01", "prop_arcade_02", 
	};

	const char* const object_prop_spawn_commericial_name[] = {
		
		"Bikini Mannequin Blue", "Bikini Mannequin Red", "Bikini Mannequin Green", "Bikini Mannequin Pink", "Bikini Mannequin Yellow", "Bikini Mannequin Orange",
		"Mannequin", "ATM Fleeca", "ATM 2", "ATM 3", "Arcade", "Arcade 2", 
	};

	const char* const object_prop_spawn_construction_hash[] = {
		"prop_metal_plates01", "prop_metal_plates02", 
		"prop_generator_02a", "prop_generator_03a", "prop_generator_04",
		"prop_byard_bench01", "prop_byard_bench02", "prop_hydro_platform_01",
	};

	const char* const object_prop_spawn_construction_name[] = {
		"Metal Construction Plate", "Metal Construction Plates",
		"Generator 1", "Generator 2", "Generator 3",
		"Construction Trestle 1", "Construction Trestle 2", "Scissor Lift",
	};

	const char* const object_prop_spawn_stunt_misc_hash[] = {
		"stt_prop_corner_sign_01", "stt_prop_corner_sign_02", "stt_prop_corner_sign_03",
		"stt_prop_corner_sign_04", "stt_prop_corner_sign_05", "stt_prop_corner_sign_06", "stt_prop_corner_sign_07",
		"stt_prop_corner_sign_08", "stt_prop_corner_sign_09", "stt_prop_corner_sign_10", "stt_prop_corner_sign_11",
		"stt_prop_corner_sign_12", "stt_prop_corner_sign_13", "stt_prop_corner_sign_14",
		"stt_prop_hoop_constraction_01a", "stt_prop_hoop_small_01", "stt_prop_hoop_tyre_01a",
		"stt_prop_stunt_bowling_ball", "stt_prop_stunt_bowling_pin", "stt_prop_stunt_bowlpin_stand", "stt_prop_stunt_domino",
		"stt_prop_stunt_soccer_ball", "stt_prop_stunt_soccer_goal", "stt_prop_stunt_soccer_lball", "stt_prop_stunt_soccer_sball",
		"prop_skate_flatramp", "prop_skate_funbox", "prop_skate_halfpipe", "prop_skate_kickers", "prop_skate_quartpipe", "prop_skate_rail", "prop_skate_spiner",
		
	};

	const char* const object_prop_spawn_stunt_misc_name[] = {
		"Sign 5", "Sign 10", "Sign 50",
		"Sign 100", "Sign Caution Slow", "Sign U-Turn Left", "Sign U-Turn Right",
		"Sign Turn Left", "Sign Turn Right", "Sign Chicane Right", "Sign Chicane Left",
		"Sign Exclaimation", "Sign Arrow Right", "Sign Arrow Left",
		"Hoop Big Metal", "Hoop Small", "Hoop Big Tyre",
		"Bowling Ball", "Bowling Pin", "Bowling Pin Stand", "Domino",
		"Soccer Ball M", "Soccer Goal", "Soccer Ball L", "Soccer Ball S",
		"Skate Flat Ramp", "Skate Funbox", "Skate Halfpipe", "Skate Kickers", "Skate Quarterpipe", "Skate Rail", "Skate Spine",
	};

	const char* const object_prop_spawn_stunt_ramp_hash[] = {
		"stt_prop_ramp_adj_flip_m", "stt_prop_ramp_adj_flip_mb", "stt_prop_ramp_adj_flip_s", 
		"stt_prop_ramp_adj_flip_sb", "stt_prop_ramp_adj_hloop", "stt_prop_ramp_adj_loop", "stt_prop_ramp_multi_loop_rb", "stt_prop_ramp_jump_l", 
		"stt_prop_ramp_jump_m", "stt_prop_ramp_jump_s", "stt_prop_ramp_jump_xl", "stt_prop_ramp_jump_xs", "stt_prop_ramp_jump_xxl",
		"stt_prop_stunt_jump_l", "stt_prop_stunt_jump_lb", "stt_prop_stunt_jump_s", "stt_prop_stunt_jump_sb", 
		"stt_prop_stunt_jump_loop", "stt_prop_stunt_jump_m", "stt_prop_stunt_jump_mb",
		//"stt_prop_stunt_ramp","stt_prop_stunt_wideramp",
		"stt_prop_ramp_spiral_l_l", "stt_prop_ramp_spiral_l_m", "stt_prop_ramp_spiral_l_s", "stt_prop_ramp_spiral_l_xxl",
		"stt_prop_ramp_spiral_l",  "stt_prop_ramp_spiral_m", "stt_prop_ramp_spiral_s", "stt_prop_ramp_spiral_xxl",
		"prop_jetski_ramp_01", "prop_mp_ramp_01", "prop_mp_ramp_02", "prop_mp_ramp_03",
	};

	const char* const object_prop_spawn_stunt_ramp_name[] = {
		"Stunt Flip Medium Right", "Stunt Flip Medium Left", "Stunt Flip Small Right", 
		"Stunt Flip Small Left", "Half Loop", "Loop", "Multi Loop", "Stunt Ramp Curve L", 
		"Stunt Ramp Curve M", "Stunt Ramp Curve S", "Stunt Ramp Curve XL", "Stunt Ramp Curve XS", "Stunt Ramp Curve XXL",
		"Stunt Ramp L", "Stunt Ramp XL", "Stunt Ramp S", "Stunt Ramp S2", 
		"Ramp + Loop", "Stunt Ramp M", "Stunt Ramp M2",
		//"Huge Stunt Ramp", "Huge Stunt Ramp Wide",
		"Spiral Right", "Spiral Right Medium", "Spiral Right Small", "Spiral Right XXL",
		"Spiral Left Large",  "Spiral Left Medium", "Spiral Left Small", "Spiral Left XXL",
		"Jetski Ramp", "Ramp 1", "Ramp 2", "Ramp 3",
	};

	const char* const object_prop_spawn_stunt_platform_hash[] = {
		"stt_prop_stunt_bblock_huge_01", "stt_prop_stunt_bblock_huge_02", "stt_prop_stunt_bblock_huge_03", "stt_prop_stunt_bblock_huge_04", 
		"stt_prop_stunt_bblock_huge_05", "stt_prop_stunt_bblock_hump_01", "stt_prop_stunt_bblock_hump_02", 
		"stt_prop_stunt_bblock_lrg1", "stt_prop_stunt_bblock_lrg2", "stt_prop_stunt_bblock_lrg3", "stt_prop_stunt_bblock_mdm1", 
		"stt_prop_stunt_bblock_mdm2", "stt_prop_stunt_bblock_mdm3",
		"stt_prop_stunt_bblock_sml1", "stt_prop_stunt_bblock_sml2", "stt_prop_stunt_bblock_sml3", 
		"stt_prop_stunt_bblock_xl1", "stt_prop_stunt_bblock_xl2", "stt_prop_stunt_bblock_xl3", "stt_prop_stunt_landing_zone_01",
		"stt_prop_stunt_bblock_qp", "stt_prop_stunt_bblock_qp2", "stt_prop_stunt_bblock_qp3", 
	};

	const char* const object_prop_spawn_stunt_platform_name[] = {
		"Huge Platform Square", "Huge Platform Rectangle", "Huge Platform Square L", "Huge Platform Squre XL", 
		"Huge Platform Rectangle XL", "Huge Platform Hump", "Huge Platform Hump 2", 
		"Platform L1", "Platform L2", "Platform L3", "Platform M1", 
		"Platform M2", "Platform M3",  "Platform S1", "Platform S2", "Platform S3", 
		"Platform Long 1", "Platform Long 2", "Platform Long 3", "Huge Platform Landingzone",
		"Huge Quarter Pipe 1", "Huge Quarter Pipe 2", "Huge Quarter Pipe 3",
	};

	const char* const object_prop_spawn_stunt_tube_hash[] = {
		"stt_prop_stunt_tube_s", "stt_prop_stunt_tube_xs", "stt_prop_stunt_tube_xxs", "stt_prop_stunt_tube_speed",
		"stt_prop_stunt_tube_crn_30d", "stt_prop_stunt_tube_crn_5d", "stt_prop_stunt_tube_crn", "stt_prop_stunt_tube_crn2", 
		"stt_prop_stunt_tube_crn_15d", "stt_prop_stunt_tube_cross", 
		"stt_prop_stunt_tube_end", "stt_prop_stunt_tube_ent", "stt_prop_stunt_tube_fn_01", "stt_prop_stunt_tube_fn_02", 
		"stt_prop_stunt_tube_fn_03", "stt_prop_stunt_tube_fn_04", "stt_prop_stunt_tube_fn_05", "stt_prop_stunt_tube_fork", 
		"stt_prop_stunt_tube_gap_01", "stt_prop_stunt_tube_gap_02", "stt_prop_stunt_tube_gap_03", "stt_prop_stunt_tube_hg", 
		"stt_prop_stunt_tube_jmp", "stt_prop_stunt_tube_jmp2", "stt_prop_stunt_tube_l", "stt_prop_stunt_tube_m", "stt_prop_stunt_tube_qg", 
	};

	const char* const object_prop_spawn_stunt_tube_name[] = {
		"Stunt Tube S", "Stunt Tube XS", "Stunt Tube XXS", "Stunt Tube Speed Boost",
		"Stunt Tube Turn 30 Degrees", "Stunt Turn Tube 5 Degrees", "Stunt Turn Tube 90 Degrees", "Stunt Turn Tube 45 Degrees", 
		"Stunt Tube Turn 15 Degrees", "Stunt Turn Tube Cross", 
		"Stunt Tube End", "Stunt Tube Entrance", "Stunt Tube Spinner", "Stunt Tube Double Spinner", 
		"Stunt Tube Spinner Closed 1/2", "Stunt Tube Spinner Closed 3/4", "Stunt Tube Double Spinner Closed 1/2", "Stunt Tube Fork", 
		"Stunt Tube Gap", "Stunt Tube Gap 2", "Stunt Tube Gap 3", "Stunt Tube Closed 1/2", 
		"Stunt Tube Ramp 1", "Stunt Tube Jump", "Stunt Tube XL", "Stunt Tube M", "Stunt Tube Closed 3/4", 
	};

	const char* const object_prop_spawn_stunt_track_hash[] = {
		"stt_prop_track_straight_bar_l", "stt_prop_track_straight_lm_bar", "stt_prop_track_straight_bar_m", "stt_prop_track_straight_bar_s",
		"stt_prop_track_straight_l", "stt_prop_track_straight_lm", "stt_prop_track_straight_m", "stt_prop_track_straight_s",
		"stt_prop_race_start_line_01", "stt_prop_race_start_line_01b", "stt_prop_race_start_line_02", 
		"stt_prop_race_start_line_02b", "stt_prop_race_start_line_03", "stt_prop_race_start_line_03b",
		"stt_prop_track_bend2_bar_l", 
		"stt_prop_track_bend2_bar_l_b", "stt_prop_track_bend2_l", "stt_prop_track_bend2_l_b", "stt_prop_track_bend_15d", 
		"stt_prop_track_bend_15d_bar", "stt_prop_track_bend_180d", "stt_prop_track_bend_180d_bar", "stt_prop_track_bend_30d", 
		"stt_prop_track_bend_30d_bar", "stt_prop_track_bend_5d", "stt_prop_track_bend_5d_bar", "stt_prop_track_bend_bar_l", 
		"stt_prop_track_bend_bar_l_b", "stt_prop_track_bend_bar_m", "stt_prop_track_bend_l", "stt_prop_track_bend_l_b", 
		"stt_prop_track_bend_m", "stt_prop_track_block_01", "stt_prop_track_block_02", "stt_prop_track_block_03", 
		"stt_prop_track_chicane_l", "stt_prop_track_chicane_l_02", "stt_prop_track_chicane_r", "stt_prop_track_chicane_r_02", 
		"stt_prop_track_cross", "stt_prop_track_cross_bar", "stt_prop_track_fork",
	};

	const char* const object_prop_spawn_stunt_track_name[] = {
		"Track Barrier XL", "Track Barrier L", "Track Barrier M", "Track Barrier S",
		"Track XL", "Track L", "Track M", "Track S", 
		"Track Start 1 Short", "Track Start 1 Long", "Track Start 2 Short", 
		"Track Start 2 Long", "Track Start 3 Short", "Track Start 3 Long",
		"Track Turn 90 Degrees Barrier", 
		"Track Turn 90 Degrees Barrier 2", "Track Turn 90 Degrees 1", "Track Turn 90 Degrees 2", "Track Turn 15 Degrees", 
		"Track Turn 15 Degrees Barrier", "Track Turn 180 Degrees", "Track Turn 180 Degrees Barrier", "Track Turn 30 Degrees", 
		"Track Turn 30 Degrees Barrier", "Track Turn 15 Degrees", "Track Turn 15 Degrees Barrier", "Track Turn 90 Degrees Barrier Small 1", 
		"Track Turn 90 Degrees Barrier Small 2", "Track Turn 45 Degrees Barrier Small", "Track Turn 90 Degrees Small 1", "Track Turn 90 Degrees Small 2", 
		"Track Turn 45 Degrees Small", "Track Narrowing", "Track Narrowing 2", "Track Narrowing 3", 
		"Track Chicane Left L", "Track Chicane Left S", "Track Chicane Right L", "Track Chicane Right S", 
		"Track Cross", "Track Cross Barrier", "Track Fork",
	};

	const char* const object_prop_spawn_traffic_hash[] = {
		"prop_mp_barrier_01", "prop_mp_barrier_01b", "prop_barrier_wat_01a", "prop_barriercrash_03", "prop_barriercrash_04",
		"prop_barier_conc_01b", "prop_barier_conc_01c", "prop_barier_conc_02b", "prop_barier_conc_02c", "prop_barier_conc_03a", "prop_barier_conc_04a", "prop_barier_conc_05a", "prop_barier_conc_05b",
		"prop_mp_barrier_02", "prop_mp_barrier_02b", "prop_mp_arrow_barrier_01",
		"prop_roadcone01a", "prop_roadcone01b", "prop_roadcone01c", "prop_roadcone02a", "prop_roadcone02b", "prop_roadcone02c",  "prop_mp_cone_04", "prop_barrier_wat_03b",
	};

	const char* const object_prop_spawn_traffic_name[] = {
		"Road Barrier 1", "Road Barrier 2", "Road Barrier 3", "Crash Barrier 1", "Crash Barrier 2",
		"Concrete Barrier Small 1", "Concrete Barrier Small 2", "Concrete Barrier Medium 1", "Concrete Barrier Medium 2", "Concrete Barrier End 1", "Concrete Barrier End 2", "Concrete Barrier Large 1", "Concrete Barrier Large 2", 
		"Roadblock 1", "Roadblock 2", "Roadblock Arrow",
		"Traffic Cone 1", "Traffic Cone 1b", "Traffic Cone 1c", "Traffic Cone 2a", "Traffic Cone 2b", "Traffic Cone 2c",  "Traffic Cone 3", "Traffic Cone 4",
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

	const char* const weather_enum[] = {
	"CLEAR", "EXTRASUNNY", "CLOUDS",
	"OVERCAST", "RAIN", "CLEARING",
	"THUNDER", "SMOG", "FOGGY",
	"XMAS", "SNOWLIGHT", "BLIZZARD"
	};

	const char* const ped_animal_hash[] = {
	"a_c_boar", "a_c_chickenhawk", "a_c_chimp", "a_c_chop", 
	"a_c_cormorant", "a_c_cow", "a_c_coyote", "a_c_crow", 
	"a_c_deer", "a_c_fish", "a_c_hen", "a_c_husky", 
	"a_c_mtlion", "a_c_pig", "a_c_pigeon", "a_c_rat", 
	"a_c_retriever", "a_c_rhesus", "a_c_rottweiler", 
	"a_c_seagull", "a_c_sharktiger", "a_c_shepherd"
	};

	const char* const ped_animal_name[] = {
	"Boar", "Chicken Hawk", "Chimp", "Chop", 
	"Cormorant", "Cow", "Coyote", "Crow", 
	"Deer", "Fish (!)", "Hen", "Husky", 
	"Mountain Lion", "Pig", "Pigeon", "Rat", 
	"Retriever", "Rhesus", "Rottweiler", 
	"Seagull", "Tiger Shark (!)", "Shephard"
	};

	const char* const ped_emergency_hash[] = {
	"s_f_y_cop_01", "s_m_y_cop_01", "s_f_y_sheriff_01",
	"s_m_y_sheriff_01", "s_m_m_security_01", "s_m_m_snowcop_01", 
	"s_m_m_prisguard_01", "s_m_m_paramedic_01", "s_m_m_doctor_01"
	};

	const char* const ped_emergency_name[] = {
	"Female Cop", "Male Cop", "Female Sheriff",
	"Male Sheriff", "Security Guard", "Snow Cop", 
	"Prison Guard", "Paramedic", "Docter"
	};

	const char* const ped_sex_hash[] = {
	"s_f_y_hooker_01", "s_f_y_hooker_02", "s_f_y_hooker_03",
	"s_f_y_stripperlite", "s_f_y_stripper_01", "s_f_y_stripper_02",
	"a_f_y_topless_01"
	};

	const char* const ped_sex_name[] = {
	"Hooker 1", "Hooker 2", "Hooker 3",
	"Stripper 1", "Stripper 2", "Stripper 3",
	"Topless Female"
	};

	const char* const ped_story_hash[] = {
	"player_zero", "player_one", "player_two", "cs_wade",
	"cs_terry", "cs_stretch", "cs_solomon", "cs_stevehains",
	"cs_omega", "cs_nervousron", "cs_lestercrest","cs_lifeinvad_01",
	"cs_lazlow", "cs_lamardavis", "cs_jimmydisanto", "cs_floyd",
	"cs_fabien", "cs_dom", "cs_devin", "cs_chrisformage", 
	"cs_clay", "cs_brad"
	};

	const char* const ped_story_name[] = {
	"Michael", "Franklin", "Trevor", "Wade",
	"Terry", "Stretch", "Solomon", "Steve Hains",
	"Omega", "Ron", "Lester","Ricky",
	"Lazlow", "Lamar", "Jimmy", "Floyd",
	"Fabien", "Dom", "Devin", "Chris Formage", 
	"Clay", "Brad"
	};

	const char* const ped_misc_hash[] = {
	"u_m_y_imporage", "u_m_y_zombie_01", "u_f_y_corpse_01",
	"u_f_y_corpse_02", "mp_f_deadhooker", "cs_priest",
	"u_m_m_jesus_01", "s_m_y_clown_01", "s_m_m_movalien_01"
	};

	const char* const ped_misc_name[] = {
	"Impotent Rage", "Zombie", "Corpse 1",
	"Corpse 2", "Dead Hooker", "Priest",
	"Jesus", "Clown", "Alien"
	};

	const char* const vehicle_boat_hash[] = {
	"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG"
	};

	const char* const vehicle_boat_name[] = {
	"Dinghy", "Dinghy 2", "Dinghy 3", "Dinghy 4", "Jetmax",
	"Marquis", "Predator (police)", "Seashark", "Seashark 2", "Seashark 3",
	"Speeder", "Speeder 2", "Squalo", "Submarine", "Submarine 2",
	"Suntrap", "Toro", "Toro 2", "Tropic", "Tropic 2",
	"Tug"
	};
 
	const char* const vehicle_commercial_hash[] = {
	"BENSON", "BIFF", "HAULER", "MULE", "MULE2",
	"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
	"STOCKADE3"
	};

	const char* const vehicle_commercial_name[] = {
	"Vapid Benson", "HVY Biff", "JoBuilt Hauler", "Maibatsu Mule", "Maibatsu Mule 2",
	"Maibatsu Mule 3", "MTL Packer", "JoBuilt Phantom", "MTL Pounder", "Brute Stockade",
	"Brute Stockade (Snow)"
	};
 
	const char* const vehicle_compact_hash[] = {
	"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
	"PANTO", "PRAIRIE", "RHAPSODY"
	};

	const char* const vehicle_compact_name[] = {
	"Dinka Blista", "Grotti Brioso R/A", "Karin Dilettante", "Karin Dilettante (Patrol)", "Weeny Issi",
	"Benefactor Panto", "Bollokan Prairie", "Declasse Rhapsody"
	};
 
	const char* const vehicle_coupe_hash[] = {
	"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
	"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
	"WINDSOR", "WINDSOR2", "ZION", "ZION2"
	};

	const char* const vehicle_coupe_name[] = {
	"Enus Cognoscenti Cabrio", "Dewbauchee Exemplar", "Ocelot F620", "Lampadati Felon", "Lampadati Felon GT",
	"Ocelot Jackal", "Ubermacht Oracle XS", "Ubermacht Oracle", "Ubermacht Sentinel XS", "Ubermacht Sentinel",
	"Enus Windsor", "Enus Windsor Drop", "Ubermacht Zion", "Ubermacht Zion Cabrio"
	};
 
	const char* const vehicle_cycle_hash[] = {
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3"
	};

	const char* const vehicle_cycle_name[] = {
	"Bmx", "Cruiser", "Fixter", "Scorcher", "Whippet Race Bike",
	"Endurex Race Bike", "Tri-Cycles Race Bike"
	};
 
	const char* const vehicle_emergency_hash[] = {
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
	"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
	"SHERIFF", "SHERIFF2", "RIOT"
	};

	const char* const vehicle_emergency_name[] = {
	"Ambulance", "FIB Buffalo", "FIB Granger", "Fire Truck", "Lifeguard Granger",
	"Prison Bus", "Park Ranger Granger", "Police Cruiser", "Police Cruiser 2", "Police Cruiser 3",
	"Unmarked Cruiser", "Police Bike", "Police Cruiser Snow", "Police Cruiser Snow 2", "Police Transporter",
	"Sheriff Cruiser", "Sheriff SUV", "Police Riot"
	};
 
	const char* const vehicle_helicopter_hash[] = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS"
	};

	const char* const vehicle_helicopter_name[] = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS"
	};
 
	const char* const vehicle_industrial_hash[] = {
	"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
	"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2"
	};

	const char* const vehicle_industrial_name[] = {
	"HVY Dozer", "HVY Cutter", "HVY Dump", "MTL Flatbed", "Vapid Guardian",
	"Dock Handler", "HVY Mixer", "HVY Mixer 2", "JoBuilt Rubble", "Brute Tipper",
	"Tipper"
	};
 
	const char* const vehicle_military_hash[] = {
	"BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO"
	};

	const char* const vehicle_military_name[] = {
	"Barracks", "HVY Barracks Semi", "Barracks 3", "Canis Crusader", "Rhino Tank"
	};
 
	const char* const vehicle_motorcycle_hash[] = {
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

	const char* const vehicle_motorcycle_name[] = {
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
 
	const char* const vehicle_muscle_hash[] = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
	};

	const char* const vehicle_muscle_name[] = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
	};
 
	const char* const vehicle_offroad_hash[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2"
	};

	const char* const vehicle_offroad_name[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2"
	};
 
	const char* const vehicle_plane_hash[] = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA"
	};

	const char* const vehicle_plane_name[] = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA"
	};
 
	const char* const vehicle_sedan_hash[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
	"WASHINGTON"
	};

	const char* const vehicle_sedan_name[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
	"WASHINGTON"
	};
 
	const char* const vehicle_service_hash[] = {
	"AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
	"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2"
	};

	const char* const vehicle_service_name[] = {
	"Airport Bus", "MTL Brickade", "Bus", "Dashound", "MTL Dune",
	"Rental Shuttle Bus", "Taxi", "Tourbus", "Trashmaster", "Trashmaster 2"
	};
 
	const char* const vehicle_sport_hash[] = {
	"ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
	"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "RUSTON", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
	"SULTAN", "SURANO", "TAMPA2", "TROPOS", "VERLIERER2"
	};

	const char* const vehicle_sport_name[] = {
	"Albany Alpha", "Bravado Banshee", "Grotti Bestia GTS", "Dinka Blista Compact", "Dinka Blista Go GO Monkey",
	"Bravado Buffalo", "Bravado Buffalo S", "Bravado Buffalo Spunk", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "RUSTON", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER",	"SEVEN70",
	"SULTAN", "SURANO", "TAMPA2", "TROPOS", "VERLIERER2"
	};
 
	const char* const vehicle_sport_classic_hash[] = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "INFERNUS2", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"TURISMO2", "ZTYPE"
	};

	const char* const vehicle_sport_classic_name[] = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "INFERNUS2", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"TURISMO2", "ZTYPE"
	};
 
	const char* const vehicle_super_hash[] = {
	"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
	"FMJ", "GP1", "SHEAVA", "INFERNUS", "OSIRIS", "LE7B",
	"PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO"
	};

	const char* const vehicle_super_name[] = {
	"Adder", "Banshee Super", "Bullet", "Cheetah", "ENTITYXF",
	"FMJ", "GP1", "SHEAVA", "INFERNUS", "OSIRIS", "LE7B",
	"PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO"
	};
 
	const char* const vehicle_suv_hash[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2"
	};

	const char* const vehicle_suv_name[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2"
	};
 
	const char* const vehicle_trailer_hash[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER"
	};

	const char* const vehicle_trailer_name[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER"
	};
 
	const char* const vehicle_train_hash[] = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
	};

	const char* const vehicle_train_name[] = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
	};
 
	const char* const vehicle_utility_hash[] = {
	"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
	};

	const char* const vehicle_utility_name[] = {
	"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
	};
 
	const char* const vehicle_van_hash[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
	};

	const char* const vehicle_van_name[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
	};

	const char* const vehicle_importexport_hash[] = {
	"blazer5", "boxville5", "comet3", "diablous", "diablous2",
	"dune4", "dune5", "elegy", "fcr", "fcr2", "italigtb",
	"italigtb2", "nero", "nero2", "penetrator", "phantom2",
	"ruiner2", "ruiner3", "specter", "specter2", "technical2",
	"tempesta", "voltic2", "wastelander"
	};

	const char* const vehicle_importexport_name[] = {
	"blazer5", "boxville5", "comet3", "diablous", "diablous2",
	"dune4", "dune5", "elegy", "fcr", "fcr2", "italigtb",
	"italigtb2", "nero", "nero2", "penetrator", "phantom2",
	"ruiner2", "ruiner3", "specter", "specter2", "technical2",
	"tempesta", "voltic2", "wastelander"
	};

	const DWORD ped_bone_hash[] = {
	0x796E, 0x9995, 0x60F2, 0x60F1,
	0x60F0, 0x5C01, 0xFCD9, 0x29D2,
	0xB1C5, 0x9D4D, 0xEEEB, 0x6E5C,
	0x49D9, 0xDEAD, 0xE39F, 0xCA72,
	0xF9BB, 0x9000, 0x3779, 0xCC4D
	};

	const char* const ped_bone_name[] = {
	"Head", "Neck", "Spine 1", "Spine 2",
	"Spine 3", "Spine 4", "L Clavicle", "R Clavicle",
	"L Shoulder", "R Shoulder", "L Elbow", "R Elbow",
	"L Hand", "R Hand", "L Thigh", "R Thigh",
	"L Knee", "R Knee", "L Foot", "R Foot"
	};
	


	const char* const explosion_enum[] = {
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

	const char* const triggerbot_enum[] = {
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

	const char* const ped_spawn_type[] = {
	"Ped", "Bodyguard", "Hostile"
	};

	const char* const chaos_mode_type[] = {
	"Bounce", "Ascention", "Armageddon", "Mayhem", "Forcefield",
	"Gravity Field", "Smash", "Massacre", "Energy Field"
	};

	const char* const noclip_type[] = {
	"Keyboard", "Cam"
	};

	const char* const crosshair_type[] = {
	"Always", "Aiming"
	};


/*	const char* const anti_afk_hash[] = {
	"world_human_smoking", "world_human_yoga", "world_human_sit_ups"
	};

	const char* const anti_afk_name[] = {
	"Smoking", "Yoga", "Sit-Ups"
	};
*/

	const char* const ped_anim_dict[] = {
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

	const char* const ped_anim_name[] = {
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