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
	//Init static private members
*/
static hashMap	m_nativeHashMap;

/*
	//Map Data
*/
uint64_t __HASHMAPDATA[] = {
	0xF25D331DC2627BBC, 0x9B0FAF2C1DE9BB5A, //player::is_player_online
	0x4F8644AF03D0E0D6, 0xBE369BE1BC57A796, //player::player_id
	0xD80958FC74E988A6, 0x17B5CC8A8615737D, //player::player_ped_id
	0x5E9564D8246B909A, 0xCF7855B965948E97, //player::is_player_playing
	0x6D0DE6A7B5DA71F8, 0x592E5DF66777D40F, //player::get_player_name
	0x0D127585F77030AF, 0xDC8370280C455166, //player::get_player_group
	0x00A1CADD00108836, 0x90B0C9C83043B8C4, //player::set_player_model
	0x2E397FD2ECD37C87, 0xE58A1B5558D2DC66, //player::is_player_free_aiming
	0x2975C866E6713290, 0x7940476800F126AE, //player::get_entity_player_is_free_aiming_at
	0x43A66C31C68491C0, 0xDF7CE83326F434E9, //player::get_player_ped
	0xF25D331DC2627BBC, 0x9B0FAF2C1DE9BB5A, //player::is_player_online
	0x50FAC3A3E030A6E1, 0xD560851477A3D4CA, //player::get_player_ped_script_index
	0x13EDE1A5DBF797C9, 0x41B9773A1CCDC74C, //player::get_player_target_entity
	0x997ABD671D25CA0B, 0xFD0FE723227D5AB6, //ped::is_ped_in_any_vehicle
	0x9A9112A0FE9A4713, 0x60604E51E30D25B8, //ped::get_vehicle_ped_is_in
	0x6094AD011A2EA87D, 0xFD05A5AA90984873, //ped::get_vehicle_ped_is_using
	0x8FE22675A5A45817, 0x266CE9B8FB237C77, //ped::clear_ped_blood_damage
	0x3AC1F7B898F30C05, 0xDE659F99B7BE0F71, //ped::reset_visible_damage
	0x9C720776DAA43E7E, 0x76956C8D11F030FD, //ped::clear_ped_wetness
	0xCFF869CBFA210D82, 0xCF84F5E773EE8DF3, //ped::get_ped_nearby_vehicles
	0xF75B0D629E1C063D, 0xFCB4AA590A0D6A59, //ped::set_ped_into_vehicle
	0xF162E133B4E7A675, 0xBC4F82F0863D3F60, //ped::get_ped_group_index
	0xEF29A16337FACADB, 0x3E0339625D0649A5, //ped::clone_ped
	0x9F3480FE65DB31B5, 0xD25D00F8613DE69F, //ped::set_ped_as_group_member
	0x9BB01E3834671191, 0x143230304C45DBF3, //ped::is_ped_group_member
	0xED7F7EFE9FABF340, 0x6F2C1CD778FB751C, //ped::set_ped_can_switch_weapon
	0xC7622C0D36B2FDA8, 0x8B54B100C5719325, //ped::set_ped_combat_ability
	0xD49F9B0955C367DE, 0x2AD5F4170F4ACBEB, //ped::create_ped
	0xC8A9481A01E63C28, 0x38FF4F54BBF14419, //ped::set_ped_random_component_variation
	0x45EEE61580806D63, 0x7F73E2B58861632F, //ped::set_ped_default_component_variation
	0x3DBFC55D5C9BB447, 0xE4FFBEDDCAF2776A, //ped::set_ped_never_leaves_group
	0xCE2F5FC3AF7E8C1E, 0xD80C7E92F2CAB25C, //ped::set_group_formation
	0x1D9D45004C28C916, 0x59B89354BBE1A4E7, //ped::set_group_formation_spacing
	0xC80A74AC829DDD92, 0x3BB70315907D9456, //ped::set_ped_relationship_group_hash
	0x3F428D08BE5AAE31, 0x0FC45085FB4E85B8, //ped::get_ped_bone_index
	0x9FF447B6B6AD960A, 0xC591BE13F389CFA7, //ped::set_ped_gravity
	0x23F8F5FC7E8C4A6B, 0x537143BA63A7EEFE, //ped::get_ped_nearby_peds
	0x3317DEDB88C95038, 0xE34CF180A5429DEA, //ped::is_ped_dead_or_dying
	0xAE99FB955581844A, 0xE9062A1E9EC059E7, //ped::set_ped_to_ragdoll
	0x47E4E977581C5B55, 0x7F4AE93855973529, //ped::is_ped_ragdoll
	0x17C07FC640E86B4E, 0x425DAA25CBB7EDE2, //ped::get_ped_bone_coords
	0x4700A416E8324EF3, 0x5D709FE87FA3B4C5, //ped::get_ped_max_health
	0x9483AF821605B1D8, 0x55C72967EFB9CECF, //ped::get_ped_armour
	0x7239B21A38F536BA, 0x23E9113C762466ED, //entity::does_entity_exist
	0x731EC8A916BD11A1, 0x2032470B7EE4912E, //entity::is_an_entity
	0x524AC5ECEA15343E, 0x80E9CA64E9C8E070, //entity::is_entity_a_ped
	0x6AC7003FA6E5575E, 0x3983CCB0D958159C, //entity::is_entity_a_vehicle
	0x8D68C8FD0FACA94E, 0x1461B0B259D86067, //entity::is_entity_an_object
	0xEA1C610A04DB6BBB, 0x027DB6817AB239EB, //entity::set_entity_visible
	0x239A3351AC1DA385, 0x394AE1BE8F25AC5B, //entity::set_entity_coords_no_offset
	0x428CA6DBD1094446, 0x98F0FA127445E343, //entity::freeze_entity_position
	0x1A9205C1B9EE827F, 0xCEDF2A713644AEDA, //entity::set_entity_collision
	0x3FEF770D40960D5A, 0x57240623C1BC6E88, //entity::get_entity_coords
	0xE83D4F9BA2A38914, 0x638527C9799F2AE4, //entity::get_entity_heading
	0x8E2530AA8ADA980E, 0x0608D50823C6AA6D, //entity::set_entity_heading
	0x8524A8B0171D5E07, 0x04A5FAE5B1EB8E28, //entity::set_entity_rotation
	0xC5F68BE9613E2D18, 0x5C9883713FC5A923, //entity::apply_force_to_entity
	0x886E37EC497200B6, 0x14E01C4EC4170496, //entity::is_entity_in_air
	0x1C99BB7B6E96D16F, 0x7B846714372D2EEF, //entity::set_entity_velocity
	0x3882114BDE571AD4, 0xC6042F55A6EA17B2, //entity::set_entity_invincible
	0x48C2BED9180FE123, 0xE0614756D21445A5, //entity::get_entity_attached_to
	0x961AC54BF0613F5D, 0xB2E72B5CFE1EC372, //entity::detach_entity
	0xF4080490ADC51C6F, 0x4647402DC8FF2646, //entity::process_entity_attachments
	0xAD738C3085FE7E11, 0xF0F77C99098F999B, //entity::set_entity_as_mission_entity
	0xAE3CBE5BF394C9C9, 0x31D01D6DEF4B35AD, //entity::delete_entity
	0x5F9532F3B5CC2551, 0xA929B2923D14E2F8, //entity::is_entity_dead
	0xB346476EF1A64897, 0xDDBA7A42B9B819EE, //entity::is_entity_attached
	0x629BFA74418D6239, 0x921CF98C637B0043, //entity::set_vehicle_as_no_longer_needed
	0x2595DD4236549CE3, 0x6500ADB01E821BC0, //entity::set_ped_as_no_longer_needed
	0x6B9BBD38AB0796DF, 0x593C85206F061E3E, //entity::attach_entity_to_entity
	0x4A4722448F18EEF5, 0xEE71EA1985CE0622, //entity::set_entity_has_gravity
	0x4805D2B1D8CF94A9, 0xACA666C39EA49E82, //entity::get_entity_velocity
	0x6B76DC1F3AE6E6A3, 0x4B04B4FAE554FA03, //entity::set_entity_health
	0xD5037BA82E12416F, 0x13B7ACE69D27E3E4, //entity::get_entity_speed
	0x47D6F43D77935C75, 0xADA6DD2D53C59AF0, //entity::is_entity_visible
	0xEEF059FAD016D209, 0xB5DF060B138CD2EA, //entity::get_entity_health
	0xAFBD61CC738D9EB9, 0xED13B51A133E020F, //entity::get_entity_rotation
	0x4C241E39B23DF959, 0x45CD66F0A131E554, //vehicle::is_vehicle_driveable
	0xBB40DD2270B65366, 0x17206B315923243C, //vehicle::get_ped_in_vehicle_seat
	0xDCE4334788AF94EA, 0xC5082382D5482C0C, //vehicle::is_this_model_a_heli
	0xA0948AB42D7BA0DE, 0x8432EA469FDB418D, //vehicle::is_this_model_a_plane
	0xAF35D0D2583051B0, 0x692A2891A2BA7352, //vehicle::create_vehicle
	0x95A88F0B409CDA47, 0xBFA6D869BA395202, //vehicle::set_vehicle_number_plate_text
	0x2497C4717C8B881E, 0x524A422B74847594, //vehicle::set_vehicle_engine_on
	0xAB54A438726D25D5, 0xFAC43F40071FC184, //vehicle::set_vehicle_forward_speed
	0xA178472EBB8AE60D, 0x85E61E88835AE7F5, //vehicle::set_heli_blades_full_speed
	0x49733E92263139D1, 0x482AE8C0EAF5AE07, //vehicle::set_vehicle_on_ground_properly
	0x67B2C79AA7FF5738, 0xBE993A95A7771E1E, //vehicle::set_vehicle_is_stolen
	0x89F149B6131E57DA, 0x6A8E2E86A006F4F2, //vehicle::set_vehicle_gravity
	0x8ABA6AF54B942B95, 0xC1B95D5AC645957D, //vehicle::set_vehicle_undriveable
	0x115722B1B9C14C1C, 0x31589F3476134C55, //vehicle::set_vehicle_fixed
	0x953DA1E1B12C0491, 0xBC02E92AEB20336A, //vehicle::set_vehicle_deformation_fixed
	0x79D3B596FE44EE8B, 0xC2BFC2AEE65D5595, //vehicle::set_vehicle_dirt_level
	0xAB54A438726D25D5, 0xFAC43F40071FC184, //vehicle::set_vehicle_forward_speed
	0xA19435F193E081AC, 0x3C5D9FD265196560, //vehicle::get_vehicle_colours
	0x4F1D4BE3A7F24601, 0x357EE036FE09513D, //vehicle::set_vehicle_colours
	0xA7C4F2C6E744A550, 0x58060A1B26EA2597, //vehicle::get_vehicle_max_number_of_passengers
	0x22AC59A870E6A669, 0xC0FA8EEF6413F866, //vehicle::is_vehicle_seat_free
	0x1F2AA07F00B3217A, 0x5991FAEA924B5EE0, //vehicle::set_vehicle_mod_kit
	0x9088EB5A43FFB0A1, 0xE0B7A718D08DF2B6, //vehicle::set_number_plate_text_index
	0x2A1F4F37F95BAD08, 0xA6EBC11A2C89D4A1, //vehicle::toggle_vehicle_mod
	0x6AF0636DDEDCB6DD, 0xE8BE9EFA248A9414, //vehicle::set_vehicle_mod
	0x57C51E6BAD752696, 0xA3C6B7F3E39994ED, //vehicle::set_vehicle_window_tint
	0x487EB21CC7295BA1, 0xE8356B7E1B731437, //vehicle::set_vehicle_wheel_type
	0x7F6DB52EEFC96DF8, 0xC2AFD5CFEDC8F22A, //vehicle::is_this_model_a_car
	0x509D5878EB39E842, 0x521A82CF998EDB21, //object::create_object
	0xE143FA2249364369, 0x29280EF6724677F5, //object::get_closest_object_of_type
	0x673966A0C0FD7171, 0xAB96B96F513DBFC2, //object::create_ambient_pickup
	0xFC8202EFC642E6F2, 0x0385EDD8AAEC86F4, //gameplay::get_frame_count
	0xC906A7DAB05C8D2B, 0x4F34E573D7F5024B, //gameplay::get_ground_z_for_3d_coord
	0x933D6A9EEC1BACD0, 0xEB79FECD9022AAF0, //gameplay::set_bit
	0xD53343AA4FB7DD28, 0x0E29C61F26D96FDB, //gameplay::get_random_int_in_range
	0x867654CBC7606F2C, 0x85E1976B9B8DADE8, //gameplay::shoot_single_bullet_between_coords
	0x338D2E3477711050, 0xB392F182B2E2F596, //gameplay::clear_override_weather
	0xED712CA327900C8A, 0xA40F9C430C6F7D6A, //gameplay::set_weather_type_now_persist
	0x00DC833F2568DBF6, 0xBD3B904ED0023B7F, //gameplay::display_onscreen_keyboard
	0x0CF2B696BBF945AE, 0x8F013F929677E75D, //gameplay::update_onscreen_keyboard
	0x8362B09B91893647, 0xE26771A3D90DD1DF, //gameplay::get_onscreen_keyboard_result
	0x6C188BE134E074AA, 0xBAB00B98D1E61BEE, //ui::add_text_component_substring_player_name
	0xBE6B23FFA53FB442, 0x95F5FAE83A0364F7, //ui::set_text_colour
	0x07C837F9A01C34C9, 0xF52EFF0C6EF215CB, //ui::set_text_scale
	0x66E0276CC5F6B9DA, 0x6C65E322B18B5D28, //ui::set_text_font
	0xC02F4DBFB51D988B, 0xD9DDC2582B7C61C4, //ui::set_text_centre
	0x465C84BC39F1C351, 0x403F622BEAB190B9, //ui::set_text_dropshadow
	0x441603240D202FA6, 0x815C87228CF5C384, //ui::set_text_edge
	0xCD015E5BB0D96A57, 0x30122BDF124C9221, //ui::end_text_command_diplay_text
	0x63145D9C883A1A70, 0x71D93F31C9937FC7, //ui::set_text_wrap
	0x25FBB336DF1804CB, 0x169EAB5A8FBE845B, //ui::begin_text_command_display_text
	0x2513DFB0FB8400FE, 0x32DAC6D3F4E23D5D, //ui::set_text_outline
	0x202709F4C58A0424, 0xBD18006F0815A298, //ui::_set_notification_text_entry
	0x2ED7843F8F801023, 0x23048DD0C6E21613, //ui::_draw_notification
	0x5CDE92C702A8FCE7, 0xF1FE04D602EA392E, //ui::add_blip_for_entity
	0x6F6F290102C02AB4, 0xB8F5F7438C07CC5E, //ui::set_blip_as_friendly
	0xDF735600A4696DAF, 0xA0BCCD5C2B5FC84F, //ui::set_blip_sprite
	0x1098355A16064BB3, 0xF1C11B6A9E7E70CC, //audio::set_mobile_radio_enabled_during_gameplay
	0xE8AF77C4C06ADC93, 0x04F0F99162081258, //audio::get_player_radio_station_index
	0xB28ECA15046CA8B9, 0xE0A4834569DED46F, //audio::get_radio_station_name
	0x1B9C0099CB942AC6, 0x2F40A4997A9C988D, //audio::set_veh_radio_station
	0xC69EDA28699D5107, 0xF216A70B97EEFD1C, //audio::set_radio_to_station_name
	0x183DADC6AA953186, 0x0CFD29F9D2B7942B, //weapon::set_ped_infinite_ammo_clip
	0xB282DC6EBD803C75, 0xBA8CA9172F194131, //weapon::give_delayed_weapon_to_ped
	0xF25DF915FA38C5F3, 0x39DF32F630CC12A7, //weapon::remove_all_ped_weapons
	0x4899CB088EDF59B8, 0x9CA872E9BF4DF131, //weapon::remove_weapon_from_ped
	0x7619364C82D3BF14, 0x1544E69732785146, //network::set_local_player_visible_locally
	0xFAA10F1FAFB11AF2, 0xB7966FAEB0FF7270, //network::set_player_visible_locally
	0xBDCD95FC216A8B3E, 0xDE2767751C03729D, //network::net_to_ped
	0x9DE624D2FC4B603F, 0xC5930AF404BD7048, //network::network_is_session_started
	0x8DB296B814EDDA07, 0xB07624F7A9F16680, //network::network_is_host
	0x01BF60A500E28887, 0xC38F0FBE1914783C, //network::network_has_control_of_entity
	0xB69317BF5E782347, 0xE647AA9998A1123E, //network::network_request_controL_of_entity
	0xA11700682F3AD45C, 0x3D9BACD0411D4A4E, //network::network_get_network_id_from_entity
	0x4D36070FE0215186, 0x093776FE2E6B4BAC, //network::network_has_control_of_network_id
	0xA670B3662FAFFBD0, 0x4EDACF77CDD9CFEB, //network::network_request_control_of_network_id
	0x299EEB23175895FC, 0x73E0878A3E31819C, //network::set_network_id_can_migrate
	0xE679E3E06E363892, 0x8A2AB944595BC051, //network::network_override_clock_time
	0x388EB2B86C73B6B3, 0xF3EE72618DF96AF7, //network::network_handle_from_player
	0x24FB80D107371267, 0xD878F413B7BB4895, //network::network_get_player_index
	0x7A5487FE9FAA6B48, 0xCB150A8B81012128, //network::get_network_time
	0x7CD6BC4C2BBDD526, 0xEFC1A93F65285B77, //network::network_create_synchronised_scene
	0x742A637471BCECD9, 0x477EC31C5BA5FAD8, //network::network_add_ped_to_synchronised_scene
	0x9A1B3FCDB36C8697, 0xD299F9D47AAE6209, //network_network_start_synchronised_scene
	0x6C0E2E0125610278, 0xDE881A032F5BA110, //network::network_get_player_index_from_ped
	0xBC1D768F2F5D6C05, 0x7081D1CF61F5A498, //network::_network_hash_from_player_handle
	0x837765A25378F0BB, 0xBEBA2DED4C4C66BD, //cam::get_gameplay_cam_rot
	0x14D6F5678D8F1B37, 0x667FF09580838E25, //cam::get_gameplay_cam_coord
	0xAAA34F8A7CB32098, 0xBC8C26E1CC191108, //ai::clear_ped_tasks_immediately
	0xBB9CE077274F6A1B, 0x401B18D8E7BEEC86, //ai::task_wander_standard
	0x142A02425FF02BD9, 0xBD415ADB0A08F6EF, //ai::task_start_scenario_in_place
	0xEA47FE3719165B94, 0xEB1EFACA68933402, //ai::task_play_anim
	0xF166E48407BAC484, 0x7DD7196E1A0C1D43, //ai::task_combat_ped
	0xF2EAB31979A7F910, 0xD3C1FC2A6E8F1095, //ai::task_hands_up
	0x35B9E0803292B641, 0x021538A59EA44D7A, //streaming::is_model_in_cdimage
	0x19AAC8F07BFEC53E, 0x2ED6701376DBCF71, //streaming::is_model_a_vehicle
	0x963D27A58DF860AC, 0xE1324F59713746FA, //streaming::request_model
	0x98A4EB5D89A0C952, 0x9F746898F7881612, //streaming::has_model_loaded
	0xE532F5D78798DAAB, 0x924CDE68BA2ED3BA, //streaming::set_model_as_no_longer_needed
	0xC0296A2EDF545E92, 0x152BAD1BB44F2768, //streaming::is_model_valid
	0xB80D8756B4668AB6, 0x7F6F941DACAF4C08, //streaming::request_named_ptfx_asset
	0xD3BD40951412FEF6, 0xA0E7D0E8FE126EE8, //streaming::request_anim_dict
	0xD031A9162D01088C, 0xF4F8AE8DD0F08C1E, //streaming::has_anim_dict_loaded
	0x9FD90732F56403CE, 0x1A45C300A76EF1CB, //decorator::decor_register
	0x0CE3AA5E1CA19E10, 0x25E9B908B35A0675, //decorator::decor_set_int
	0x05661B80A8C9165F, 0x44748DA5CF34DA5E, //decorator::decor_exists_on
	0xA06C969B02A97298, 0x83CA0CEAC60F17F6, //decorator::decor_get_int
	0x6B1E8E2ED1335B71, 0x6717F72244C0D24C, //decorator::decor_set_bool
	0xDACE671663F2F5DB, 0x12D059B73664565A, //decorator::decor_get_bool
	0xE3AD2BDBAEE269AC, 0x3F46E145DB7AB5E4, //fire::add_explosion
	0x4055E40BD2DBEC1D, 0xD1FDEE4A40BFBA76, //time::pause_clock
	0x25223CA6B4D20B7F, 0x80BC37C67CB292E5, //time::get_clock_hours
	0x13D2B8ADD79640F2, 0x32883EAC7DC86C40, //time::get_clock_minutes
	0x47C3B5848C3E45D8, 0x673705D8148968BD, //time::set_clock_time
	0x34E82F05DF2974F5, 0x28FABF021DDC68FC, //graphics::get_screen_coord_from_world_coord
	0x3A618A217E5154F0, 0x2F8697C8670CAD58, //graphics::draw_rect
	0x6C38AF3693A69A91, 0x6A8D4CCECC6DB79B, //graphics::_use_particle_fx_asset_next_call
	0xDDE23F30CC5A0F03, 0xEAB2A9346EED6163, //graphics::_start_particle_fx_looped_on_entity_bone_2
	0xB3271D7AB655B441, 0x731753D8494ABECD, //stats::stat_set_int
	0x4851997F37FE9B3C, 0x098CDAAE6268B0D0, //stats::stat_set_float
	0x4B33C4243DE0C432, 0xCE46AC18A4A47E2D, //stats::stat_set_bool
	0x2C29BFB64F4FCBE4, 0xC43DC246FFFC2C87, //stats::stat_set_date
};

/*
	//Crossmapping functions
*/

void	CCrossMap::init()
{
	if(!m_nativeHashMap.empty())
		return;

	hashEntry*	pHash	= reinterpret_cast<hashEntry*>(__HASHMAPDATA);
	for(; pHash->x ; pHash++)
		m_nativeHashMap.emplace(pHash->x, pHash->y);
}

uint64_t CCrossMap::get(uint64_t native)
{
	uint64_t	result	= NULL;

	hashMap::iterator it	= m_nativeHashMap.find(native);
	if(it != m_nativeHashMap.end())
		result	= it->second;
	else
	{
		char	msg[0x60];
		sprintf_s(msg, "Finding native 0x%016llx", native);
		CLog::error(msg);
	}

	return result;
}