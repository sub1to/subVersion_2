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
#ifndef HASHES_H
#define HASHES_H

namespace hash
{
	extern const char* const weapon_hash[71];
	extern const char* const weapon_name[71];

	extern const char* const radio_station_hash[20];
	extern const char* const radio_station_name[20];

	extern const char* const object_prop_money_hash[27];
	extern const char* const object_prop_money_name[27];

	extern const char* const object_prop_spawn_misc_hash[40];
	extern const char* const object_prop_spawn_misc_name[40];

	extern const char* const object_prop_spawn_large_hash[12];
	extern const char* const object_prop_spawn_large_name[12];

	extern const char* const object_prop_spawn_drugs_hash[6];
	extern const char* const object_prop_spawn_drugs_name[6];

	extern const char* const object_prop_spawn_music_hash[6];
	extern const char* const object_prop_spawn_music_name[6];

	extern const char* const object_prop_spawn_commericial_hash[12];
	extern const char* const object_prop_spawn_commericial_name[12];

	extern const char* const object_prop_spawn_construction_hash[8];
	extern const char* const object_prop_spawn_construction_name[8];

	extern const char* const object_prop_spawn_stunt_misc_hash[32];
	extern const char* const object_prop_spawn_stunt_misc_name[32];

	extern const char* const object_prop_spawn_stunt_ramp_hash[32];
	extern const char* const object_prop_spawn_stunt_ramp_name[32];

	extern const char* const object_prop_spawn_stunt_platform_hash[23];
	extern const char* const object_prop_spawn_stunt_platform_name[23];

	extern const char* const object_prop_spawn_stunt_track_hash[42];
	extern const char* const object_prop_spawn_stunt_track_name[42];

	extern const char* const object_prop_spawn_stunt_tube_hash[27];
	extern const char* const object_prop_spawn_stunt_tube_name[27];

	extern const char* const object_prop_spawn_traffic_hash[24];
	extern const char* const object_prop_spawn_traffic_name[24];

	//extern const char* const object_prop_spawn_stunt_test[129];

	extern const char* const weather_enum[12];

	extern const char* const ped_animal_hash[22];
	extern const char* const ped_animal_name[22];

	extern const char* const ped_emergency_hash[9];
	extern const char* const ped_emergency_name[9];

	extern const char* const ped_sex_hash[7];
	extern const char* const ped_sex_name[7];

	extern const char* const ped_story_hash[22];
	extern const char* const ped_story_name[22];

	extern const char* const ped_misc_hash[9];
	extern const char* const ped_misc_name[9];

	extern const char* const vehicle_boat_hash[21];
	extern const char* const vehicle_boat_name[21];
 
	extern const char* const vehicle_commercial_hash[11];
	extern const char* const vehicle_commercial_name[11];
 
	extern const char* const vehicle_compact_hash[8];
	extern const char* const vehicle_compact_name[8];
 
	extern const char* const vehicle_coupe_hash[14];
	extern const char* const vehicle_coupe_name[14];
 
	extern const char* const vehicle_cycle_hash[7];
	extern const char* const vehicle_cycle_name[7];
 
	extern const char* const vehicle_emergency_hash[18];
	extern const char* const vehicle_emergency_name[18];
 
	extern const char* const vehicle_helicopter_hash[22];
	extern const char* const vehicle_helicopter_name[22];
 
	extern const char* const vehicle_industrial_hash[11];
	extern const char* const vehicle_industrial_name[11];
 
	extern const char* const vehicle_military_hash[5];
	extern const char* const vehicle_military_name[5];
 
	extern const char* const vehicle_motorcycle_hash[42];
	extern const char* const vehicle_motorcycle_name[42];
 
	extern const char* const vehicle_muscle_hash[39];
	extern const char* const vehicle_muscle_name[39];
 
	extern const char* const vehicle_offroad_hash[27];
	extern const char* const vehicle_offroad_name[27];
 
	extern const char* const vehicle_plane_hash[19];
	extern const char* const vehicle_plane_name[19];
 
	extern const char* const vehicle_sedan_hash[31];
	extern const char* const vehicle_sedan_name[31];
 
	extern const char* const vehicle_service_hash[10];
	extern const char* const vehicle_service_name[10];
 
	extern const char* const vehicle_sport_hash[41];
	extern const char* const vehicle_sport_name[41];
 
	extern const char* const vehicle_sport_classic_hash[23];
	extern const char* const vehicle_sport_classic_name[23];

	extern const char* const vehicle_super_hash[21];
	extern const char* const vehicle_super_name[21];
 
	extern const char* const vehicle_suv_hash[27];
	extern const char* const vehicle_suv_name[27];
 
	extern const char* const vehicle_trailer_hash[22];
	extern const char* const vehicle_trailer_name[22];
 
	extern const char* const vehicle_train_hash[8];
	extern const char* const vehicle_train_name[8];
 
	extern const char* const vehicle_utility_hash[18];
	extern const char* const vehicle_utility_name[18];
 
	extern const char* const vehicle_van_hash[32];
	extern const char* const vehicle_van_name[32];

	extern const char* const vehicle_importexport_hash[24];
	extern const char* const vehicle_importexport_name[24];

	extern const DWORD ped_bone_hash[20];
	extern const char* const ped_bone_name[20];


	extern const char* const explosion_enum[35];
	extern const char* const triggerbot_enum[2];
	extern const char* const veh_color_enum[161];

	extern const char* const ped_spawn_type[3];
	extern const char* const chaos_mode_type[9];
	extern const char* const noclip_type[2];
	extern const char* const crosshair_type[2];

	//extern const char* const anti_afk_hash[3];
	//extern const char* const anti_afk_name[3];

	extern const char* const ped_anim_dict[0x40];
	extern const char* const ped_anim_name[0x20];


	/*
		//outfits
	*/
	extern const BYTE	outfit_santa_female[0xA][0x3];
	extern const BYTE	outfit_santa_male[0xA][0x3];

	extern const BYTE	outfit_trash_orange_female[0xA][0x3];
	extern const BYTE	outfit_trash_orange_male[0xA][0x3];

	extern const BYTE	outfit_trash_green_female[0xA][0x3];
	extern const BYTE	outfit_trash_green_male[0xA][0x3];

	extern const BYTE	outfit_police_female[0xA][0x3];
	extern const BYTE	outfit_police_male[0xA][0x3];
};

#endif