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
	char* weapon_hash[] = {
	"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
	"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
	"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
	"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
	"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_COMBATPDW", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
	"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
	"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN", "WEAPON_KNUCKLE", "WEAPON_MARKSMANPISTOL",
	"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
	"WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
	"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLASHLIGHT", "WEAPON_MACHINEPISTOL", "WEAPON_MACHETE"
	};

	char* weapon_name[] = {
	"Knife", "Nightstick", "Hammer", "Baseball Bat", "Golf Club", "Crowbar",
	"Pistol", "Combat Pistol", "AP Pistol", ".50 Pistol", "Micro SMG", "SMG",
	"Assault SMG", "Assault Rifle", "Carbine Rifle", "Advanced Rifle", "MG",
	"Combat MG", "Pump Shotgun", "Sawed Off Shotgun", "Assault Shotgun", "Bullpup Shotgun",
	"Stungun", "Sniper Rifle", "Combat PDW", "Heavy Sniper", "Grenade Launcher", "Flare Gun",
	"RPG", "Minigun", "Grenade", "Sticky Bomb", "Smoke Grenade", "BZ Gas",
	"Molotov", "Fire Extinguisher", "Petrol Can", "Knuckle", "Marksman Pistol",
	"SNS Pistol", "Special Carbine", "Heavy Pistol", "Bullpup Rifle", "Homing Launcher",
	"Prox Mine", "Snowball", "Vintage Pistol", "Dagger", "Firework Launcher", "Musket",
	"Marksman Rifle", "Heavy Shotgun", "Gusenberg", "Hatchet", "Railgun", "Flashlight", "Machine Pistol", "Machete"
	};

	char* radio_station_hash[] = {
	"RADIO_01_CLASS_ROCK", "RADIO_02_POP", "RADIO_03_HIPHOP_NEW",
	"RADIO_04_PUNK", "RADIO_05_TALK_01", "RADIO_06_COUNTRY",
	"RADIO_07_DANCE_01", "RADIO_08_MEXICAN", "RADIO_09_HIPHOP_OLD",
	"RADIO_12_REGGAE", "RADIO_13_JAZZ", "RADIO_14_DANCE_02",
	"RADIO_15_MOTOWN", "RADIO_20_THELAB", "RADIO_16_SILVERLAKE",
	"RADIO_17_FUNK", "RADIO_18_90S_ROCK", "RADIO_19_USER",
	"RADIO_11_TALK_02", "OFF"
	};

	char* radio_station_name[] = {
	"Rock Radio", "24/7 Pop", "Los Santos",
	"Channel X", "WCTR", "Rebel Radio",
	"Soulwax", "East Los", "West Coast",
	"Blue Ark", "Worldwide", "FlyLo",
	"Low Down", "The Lab", "Mirror Park",
	"Space", "Vinewood", "Self",
	"Blaine", "Off"
	};

	char* object_prop_attach_hash[] = {
	"prop_xmas_tree_int",  "p_spinning_anus_s", "prop_beer_neon_01", "prop_ld_toilet_01", "prop_space_rifle",
	"prop_food_van_01", "prop_crashed_heli", "prop_dj_deck_01", "prop_portacabin01",
	"prop_micro_01", "prop_ld_ferris_wheel", "prop_lev_des_barge_01", "prop_lev_des_barge_02",
	"prop_tv_flat_01", "prop_coke_block_01", "Prop_weed_01", "prop_wheelchair_01",
	"p_v_43_safe_s", "prop_swiss_ball_01", "p_ld_soc_ball_01", "prop_rub_trolley01a",
	"prop_dummy_01", "prop_large_gold", "prop_cs_dildo_01", "prop_fan_01", "prop_golf_bag_01",
	"prop_armchair_01", "prop_armour_pickup", "prop_big_shit_01", "prop_bin_04a", 
	"prop_chair_01a", "prop_chip_fryer", "prop_chickencoop_a", "prop_dog_cage_01",
	"prop_windmill_01", "prop_gold_cont_01", "prop_xmas_ext", "prop_weed_pallet",
	"p_cablecar_s", "prop_air_bigradar", "p_cs_mp_jet_01_s", "prop_alien_egg_01",
	"prop_prop_tree_01", "prop_prop_tree_02", "prop_coffin_02", "prop_coffin_02b",
	"prop_cs_dumpster_01a"
	};

	char* object_prop_attach_name[] = {
	"Xmas Tree", "UFO", "Neon Liquor Sign", "Toilet", "Space Rifle",
	"Food Van", "Crashed Helicopter", "DJ Deck", "Portable Cabin",
	"Microwave", "Ferris Wheel", "Barge 01", "Barge 02",
	"Flatscreen TV", "Coke Brick", "Weed Plant", "Wheelchair",
	"Safe", "Swiss Ball", "Soccer Ball", "Shopping Cart",
	"Mannequin", "Gold Cart", "Dildo", "Fan", "Golf Bag",
	"Arm Chair", "Armour Pickup", "Turd", "Garbage Bin", 
	"Chair", "Fryer", "Chicken Coop", "Dog Cage",
	"Windmill", "Cage", "Huge Xmas Tree", "Pallet of Weed",
	"Cablecar", "Big Radar Dish", "Plane", "Alien Egg",
	"Tree", "Tree 2", "Coffin Broken", "Coffin",
	"Dumpster"
	};

	char* object_prop_money_hash[] = {
	"prop_xmas_tree_int",  "p_spinning_anus_s", "prop_beer_neon_01", "prop_space_rifle",
	"prop_crashed_heli", "prop_dj_deck_01",
	"prop_micro_01", "prop_ld_ferris_wheel", "prop_lev_des_barge_01", "prop_lev_des_barge_02",
	"prop_coke_block_01", "prop_wheelchair_01",
	"p_v_43_safe_s", "p_ld_soc_ball_01", "prop_rub_trolley01a",
	"prop_dummy_01", "prop_large_gold", "prop_cs_dildo_01", "prop_fan_01", "prop_golf_bag_01",
	"prop_armchair_01", "prop_armour_pickup", "prop_big_shit_01", "prop_bin_04a", 
	"prop_chair_01a", "prop_chip_fryer", "prop_chickencoop_a", "prop_dog_cage_01",
	"prop_gold_cont_01", "prop_xmas_ext",
	"p_cablecar_s", "p_cs_mp_jet_01_s", "prop_alien_egg_01",
	"prop_prop_tree_01", "prop_prop_tree_02", "prop_coffin_02", "prop_coffin_02b",
	"prop_cs_dumpster_01a"
	};

	char* object_prop_money_name[] = {
	"Xmas Tree", "UFO", "Neon Liquor Sign", "Space Rifle",
	"Crashed Helicopter", "DJ Deck", 
	"Microwave", "Ferris Wheel", "Barge 01", "Barge 02",
	"Coke Brick", "Wheelchair",
	"Safe", "Soccer Ball", "Shopping Cart",
	"Mannequin", "Gold Cart", "Dildo", "Fan", "Golf Bag",
	"Arm Chair", "Armour Pickup", "Turd", "Garbage Bin", 
	"Chair", "Fryer", "Chicken Coop", "Dog Cage",
	"Cage", "Huge Xmas Tree",
	"Cablecar", "Plane", "Alien Egg",
	"Tree", "Tree 2", "Coffin Broken", "Coffin",
	"Dumpster"
	};

	char* object_prop_spawn_hash[] = {
	"prop_xmas_tree_int",  "p_spinning_anus_s", "prop_beer_neon_01", "prop_ld_toilet_01", "prop_space_rifle",
	"prop_food_van_01", "prop_crashed_heli", "prop_dj_deck_01", "prop_portacabin01",
	"prop_micro_01", "prop_ld_ferris_wheel", "prop_lev_des_barge_01", "prop_lev_des_barge_02",
	"prop_tv_flat_01", "prop_coke_block_01", "Prop_weed_01", "prop_wheelchair_01",
	"p_v_43_safe_s", "prop_swiss_ball_01", "p_ld_soc_ball_01", "prop_rub_trolley01a",
	"prop_dummy_01", "prop_large_gold", "prop_cs_dildo_01", "prop_fan_01", "prop_golf_bag_01",
	"prop_armchair_01", "prop_armour_pickup", "prop_big_shit_01", "prop_bin_04a", 
	"prop_chair_01a", "prop_chip_fryer", "prop_chickencoop_a", "prop_dog_cage_01",
	"prop_windmill_01", "prop_gold_cont_01", "prop_xmas_ext", "prop_weed_pallet",
	"p_cablecar_s", "prop_air_bigradar", "p_cs_mp_jet_01_s", "prop_alien_egg_01",
	"prop_prop_tree_01", "prop_prop_tree_02", "prop_coffin_02", "prop_coffin_02b",
	"prop_cs_dumpster_01a"
	};

	char* object_prop_spawn_name[] = {
	"Xmas Tree", "UFO", "Neon Liquor Sign", "Toilet", "Space Rifle",
	"Food Van", "Crashed Helicopter", "DJ Deck", "Portable Cabin",
	"Microwave", "Ferris Wheel", "Barge 01", "Barge 02",
	"Flatscreen TV", "Coke Brick", "Weed Plant", "Wheelchair",
	"Safe", "Swiss Ball", "Soccer Ball", "Shopping Cart",
	"Mannequin", "Gold Cart", "Dildo", "Fan", "Golf Bag",
	"Arm Chair", "Armour Pickup", "Turd", "Garbage Bin", 
	"Chair", "Fryer", "Chicken Coop", "Dog Cage",
	"Windmill", "Cage", "Huge Xmas Tree", "Pallet of Weed",
	"Cablecar", "Big Radar Dish", "Plane", "Alien Egg",
	"Tree", "Tree 2", "Coffin Broken", "Coffin",
	"Dumpster"
	};

	char* weather_enum[] = {
	"CLEAR", "EXTRASUNNY", "CLOUDS",
	"OVERCAST", "RAIN", "CLEARING",
	"THUNDER", "SMOG", "FOGGY",
	"XMAS", "SNOWLIGHT", "BLIZZARD"
	};

	char* ped_animal_hash[] = {
	"a_c_boar", "a_c_chickenhawk", "a_c_chimp", "a_c_chop", 
	"a_c_cormorant", "a_c_cow", "a_c_coyote", "a_c_crow", 
	"a_c_deer", "a_c_fish", "a_c_hen", "a_c_husky", 
	"a_c_mtlion", "a_c_pig", "a_c_pigeon", "a_c_rat", 
	"a_c_retriever", "a_c_rhesus", "a_c_rottweiler", 
	"a_c_seagull", "a_c_sharktiger", "a_c_shepherd"
	};

	char* ped_animal_name[] = {
	"Boar", "Chicken Hawk", "Chimp", "Chop", 
	"Cormorant", "Cow", "Coyote", "Crow", 
	"Deer", "Fish (!)", "Hen", "Husky", 
	"Mountain Lion", "Pig", "Pigeon", "Rat", 
	"Retriever", "Rhesus", "Rottweiler", 
	"Seagull", "Tiger Shark (!)", "Shephard"
	};

	char* ped_emergency_hash[] = {
	"s_f_y_cop_01", "s_m_y_cop_01", "s_f_y_sheriff_01",
	"s_m_y_sheriff_01", "s_m_m_security_01", "s_m_m_snowcop_01", 
	"s_m_m_prisguard_01", "s_m_m_paramedic_01", "s_m_m_doctor_01"
	};

	char* ped_emergency_name[] = {
	"Female Cop", "Male Cop", "Female Sheriff",
	"Male Sheriff", "Security Guard", "Snow Cop", 
	"Prison Guard", "Paramedic", "Docter"
	};

	char* ped_sex_hash[] = {
	"s_f_y_hooker_01", "s_f_y_hooker_02", "s_f_y_hooker_03",
	"s_f_y_stripperlite", "s_f_y_stripper_01", "s_f_y_stripper_02",
	"a_f_y_topless_01"
	};

	char* ped_sex_name[] = {
	"Hooker 1", "Hooker 2", "Hooker 3",
	"Stripper 1", "Stripper 2", "Stripper 3",
	"Topless Female"
	};

	char* ped_story_hash[] = {
	"player_zero", "player_one", "player_two", "cs_wade",
	"cs_terry", "cs_stretch", "cs_solomon", "cs_stevehains",
	"cs_omega", "cs_nervousron", "cs_lestercrest","cs_lifeinvad_01",
	"cs_lazlow", "cs_lamardavis", "cs_jimmydisanto", "cs_floyd",
	"cs_fabien", "cs_dom", "cs_devin", "cs_chrisformage", 
	"cs_clay", "cs_brad"
	};

	char* ped_story_name[] = {
	"Michael", "Franklin", "Trevor", "Wade",
	"Terry", "Stretch", "Solomon", "Steve Hains",
	"Omega", "Ron", "Lester","Ricky",
	"Lazlow", "Lamar", "Jimmy", "Floyd",
	"Fabien", "Dom", "Devin", "Chris Formage", 
	"Clay", "Brad"
	};

	char* ped_misc_hash[] = {
	"u_m_y_imporage", "u_m_y_zombie_01", "u_f_y_corpse_01",
	"u_f_y_corpse_02", "mp_f_deadhooker", "cs_priest",
	"u_m_m_jesus_01", "s_m_y_clown_01", "s_m_m_movalien_01"
	};

	char* ped_misc_name[] = {
	"Impotent Rage", "Zombie", "Corpse 1",
	"Corpse 2", "Dead Hooker", "Priest",
	"Jesus", "Clown", "Alien"
	};

	char* vehicle_boat_hash[] = {
	"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG"
	};

	char* vehicle_boat_name[] = {
	"Dinghy", "Dinghy 2", "Dinghy 3", "Dinghy 4", "Jetmax",
	"Marquis", "Predator (police)", "Seashark", "Seashark 2", "Seashark 3",
	"Speeder", "Speeder 2", "Squalo", "Submarine", "Submarine 2",
	"Suntrap", "Toro", "Toro 2", "Tropic", "Tropic 2",
	"Tug"
	};
 
	char* vehicle_commercial_hash[] = {
	"BENSON", "BIFF", "HAULER", "MULE", "MULE2",
	"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
	"STOCKADE3"
	};

	char* vehicle_commercial_name[] = {
	"Vapid Benson", "HVY Biff", "JoBuilt Hauler", "Maibatsu Mule", "Maibatsu Mule 2",
	"Maibatsu Mule 3", "MTL Packer", "JoBuilt Phantom", "MTL Pounder", "Brute Stockade",
	"Brute Stockade (Snow)"
	};
 
	char* vehicle_compact_hash[] = {
	"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
	"PANTO", "PRAIRIE", "RHAPSODY"
	};

	char* vehicle_compact_name[] = {
	"Dinka Blista", "Grotti Brioso R/A", "Karin Dilettante", "Karin Dilettante (Patrol)", "Weeny Issi",
	"Benefactor Panto", "Bollokan Prairie", "Declasse Rhapsody"
	};
 
	char* vehicle_coupe_hash[] = {
	"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
	"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
	"WINDSOR", "WINDSOR2", "ZION", "ZION2"
	};

	char* vehicle_coupe_name[] = {
	"Enus Cognoscenti Cabrio", "Dewbauchee Exemplar", "Ocelot F620", "Lampadati Felon", "Lampadati Felon GT",
	"Ocelot Jackal", "Ubermacht Oracle XS", "Ubermacht Oracle", "Ubermacht Sentinel XS", "Ubermacht Sentinel",
	"Enus Windsor", "Enus Windsor Drop", "Ubermacht Zion", "Ubermacht Zion Cabrio"
	};
 
	char* vehicle_cycle_hash[] = {
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3"
	};

	char* vehicle_cycle_name[] = {
	"Bmx", "Cruiser", "Fixter", "Scorcher", "Whippet Race Bike",
	"Endurex Race Bike", "Tri-Cycles Race Bike"
	};
 
	char* vehicle_emergency_hash[] = {
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
	"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
	"SHERIFF", "SHERIFF2", "RIOT"
	};

	char* vehicle_emergency_name[] = {
	"Ambulance", "FIB Buffalo", "FIB Granger", "Fire Truck", "Lifeguard Granger",
	"Prison Bus", "Park Ranger Granger", "Police Cruiser", "Police Cruiser 2", "Police Cruiser 3",
	"Unmarked Cruiser", "Police Bike", "Police Cruiser Snow", "Police Cruiser Snow 2", "Police Transporter",
	"Sheriff Cruiser", "Sheriff SUV", "Police Riot"
	};
 
	char* vehicle_helicopter_hash[] = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS"
	};

	char* vehicle_helicopter_name[] = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS"
	};
 
	char* vehicle_industrial_hash[] = {
	"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
	"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2"
	};

	char* vehicle_industrial_name[] = {
	"HVY Dozer", "HVY Cutter", "HVY Dump", "MTL Flatbed", "Vapid Guardian",
	"Dock Handler", "HVY Mixer", "HVY Mixer 2", "JoBuilt Rubble", "Brute Tipper",
	"Tipper"
	};
 
	char* vehicle_military_hash[] = {
	"BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO"
	};

	char* vehicle_military_name[] = {
	"Barracks", "HVY Barracks Semi", "Barracks 3", "Canis Crusader", "Rhino Tank"
	};
 
	char* vehicle_motorcycle_hash[] = {
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

	char* vehicle_motorcycle_name[] = {
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
 
	char* vehicle_muscle_hash[] = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
	};

	char* vehicle_muscle_name[] = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
	};
 
	char* vehicle_offroad_hash[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2"
	};

	char* vehicle_offroad_name[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2"
	};
 
	char* vehicle_plane_hash[] = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA"
	};

	char* vehicle_plane_name[] = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA"
	};
 
	char* vehicle_sedan_hash[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
	"WASHINGTON"
	};

	char* vehicle_sedan_name[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
	"WASHINGTON"
	};
 
	char* vehicle_service_hash[] = {
	"AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
	"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2"
	};

	char* vehicle_service_name[] = {
	"Airport Bus", "MTL Brickade", "Bus", "Dashound", "MTL Dune",
	"Rental Shuttle Bus", "Taxi", "Tourbus", "Trashmaster", "Trashmaster 2"
	};
 
	char* vehicle_sport_hash[] = {
	"ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
	"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
	"SULTAN", "SURANO", "TAMPA2", "TROPOS", "VERLIERER2", "RUSTON"
	};

	char* vehicle_sport_name[] = {
	"Albany Alpha", "Bravado Banshee", "Grotti Bestia GTS", "Dinka Blista Compact", "Dinka Blista Go GO Monkey",
	"Bravado Buffalo", "Bravado Buffalo S", "Bravado Buffalo Spunk", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
	"SULTAN", "SURANO", "TAMPA2", "TROPOS", "VERLIERER2", "RUSTON"
	};
 
	char* vehicle_sport_classic_hash[] = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"ZTYPE", "TURISMO2", "INFERNUS2"
	};

	char* vehicle_sport_classic_name[] = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"ZTYPE", "TURISMO2", "INFERNUS2"
	};
 
	char* vehicle_super_hash[] = {
	"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
	"FMJ", "SHEAVA", "INFERNUS", "OSIRIS", "LE7B",
	"PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "GP1"
	};

	char* vehicle_super_name[] = {
	"Adder", "Banshee Super", "Bullet", "Cheetah", "ENTITYXF",
	"FMJ", "SHEAVA", "INFERNUS", "OSIRIS", "LE7B",
	"PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "GP1"
	};
 
	char* vehicle_suv_hash[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2"
	};

	char* vehicle_suv_name[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2"
	};
 
	char* vehicle_trailer_hash[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER"
	};

	char* vehicle_trailer_name[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER"
	};
 
	char* vehicle_train_hash[] = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
	};

	char* vehicle_train_name[] = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
	};
 
	char* vehicle_utility_hash[] = {
	"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
	};

	char* vehicle_utility_name[] = {
	"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
	};
 
	char* vehicle_van_hash[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
	};

	char* vehicle_van_name[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
	};

	char* vehicle_importexport_hash[] = {
	"blazer5", "boxville5", "comet3", "diablous", "diablous2",
	"dune4", "dune5", "elegy", "fcr", "fcr2", "italigtb",
	"italigtb2", "nero", "nero2", "penetrator", "phantom2",
	"ruiner2", "ruiner3", "specter", "specter2", "technical2",
	"tempesta", "voltic2", "wastelander"
	};

	char* vehicle_importexport_name[] = {
	"blazer5", "boxville5", "comet3", "diablous", "diablous2",
	"dune4", "dune5", "elegy", "fcr", "fcr2", "italigtb",
	"italigtb2", "nero", "nero2", "penetrator", "phantom2",
	"ruiner2", "ruiner3", "specter", "specter2", "technical2",
	"tempesta", "voltic2", "wastelander"
	};

	DWORD ped_bone_hash[] = {
	0x796E, 0x9995, 0x60F2, 0x60F1,
	0x60F0, 0x5C01, 0xFCD9, 0x29D2,
	0xB1C5, 0x9D4D, 0xEEEB, 0x6E5C,
	0x49D9, 0xDEAD, 0xE39F, 0xCA72,
	0xF9BB, 0x9000, 0x3779, 0xCC4D
	};

	char* ped_bone_name[] = {
	"Head", "Neck", "Spine 1", "Spine 2",
	"Spine 3", "Spine 4", "L Clavicle", "R Clavicle",
	"L Shoulder", "R Shoulder", "L Elbow", "R Elbow",
	"L Hand", "R Hand", "L Thigh", "R Thigh",
	"L Knee", "R Knee", "L Foot", "R Foot"
	};
	


	char* explosion_enum[] = {
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

	char* ped_spawn_type[] = {
	"Ped", "Bodyguard", "Hostile"
	};

	char* chaos_mode_type[] = {
	"Bounce", "Ascention", "Armageddon", "Mayhem", "Forcefield",
	"Gravity Field", "Smash", "Massacre"
	};

	char* noclip_type[] = {
	"Keyboard", "Cam"
	};


	char* anti_afk_hash[] = {
	"world_human_smoking", "world_human_yoga"
	};

	char* anti_afk_name[] = {
	"Smoking", "Yoga"
	};

};