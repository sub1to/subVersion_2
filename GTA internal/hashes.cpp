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
	const char* const weapon_hash[] = {
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

	const char* const weapon_name[] = {
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
	"prop_xmas_tree_int", "p_spinning_anus_s", "prop_beer_neon_01", "prop_space_rifle",
	"prop_crashed_heli", "prop_dj_deck_01", "prop_micro_01", "prop_ld_ferris_wheel",
	"prop_lev_des_barge_01", "prop_lev_des_barge_02", "p_ld_soc_ball_01", "prop_rub_trolley01a",
	"prop_dummy_01", "prop_large_gold", "prop_cs_dildo_01", "prop_fan_01", "prop_golf_bag_01",
	"prop_armchair_01", "prop_armour_pickup", "prop_big_shit_01", "prop_bin_04a", 
	"prop_chair_01a", "prop_chip_fryer", "prop_chickencoop_a", "prop_dog_cage_01",
	"prop_gold_cont_01", "prop_xmas_ext", "p_cablecar_s", "p_cs_mp_jet_01_s",
	"prop_prop_tree_01", "prop_prop_tree_02", "prop_coffin_02", "prop_coffin_02b",
	"prop_cs_dumpster_01a"
	};

	const char* const object_prop_money_name[] = {
	"Alien Egg", "Safe", "Wheelchair", "Coke Brick",
	"Xmas Tree", "UFO", "Neon Liquor Sign", "Space Rifle",
	"Crashed Helicopter", "DJ Deck", "Microwave", "Ferris Wheel",
	"Barge 01", "Barge 02", "Soccer Ball", "Shopping Cart",
	"Mannequin", "Gold Cart", "Dildo", "Fan", "Golf Bag",
	"Arm Chair", "Armour Pickup", "Turd", "Garbage Bin", 
	"Chair", "Fryer", "Chicken Coop", "Dog Cage",
	"Cage", "Huge Xmas Tree", "Cablecar", "Plane",
	"Tree", "Tree 2", "Coffin Broken", "Coffin",
	"Dumpster"
	};

	const char* const object_prop_spawn_hash[] = {
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

	const char* const object_prop_spawn_name[] = {
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

	const char* const ped_spawn_type[] = {
	"Ped", "Bodyguard", "Hostile"
	};

	const char* const chaos_mode_type[] = {
	"Bounce", "Ascention", "Armageddon", "Mayhem", "Forcefield",
	"Gravity Field", "Smash", "Massacre"
	};

	const char* const noclip_type[] = {
	"Keyboard", "Cam"
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