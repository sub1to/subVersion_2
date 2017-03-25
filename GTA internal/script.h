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
#ifndef SCRIPT_H
#define SCRIPT_H

namespace util
{
	float	deg_to_rad(float deg);
	int		random_int(int start, int end);
}

namespace script
{
	bool	apply_model(std::string skinName, bool random = false);
	void	set_player_clothing(int group, int value, bool texture);

	bool	request_control_of_entity(Entity entity);

	void	update_nearby_ped(Ped origin, int c);
	void	update_nearby_vehicle(Ped origin, int c, bool driveable = true);

	Hash	$(std::string str);

	bool	teleport_to_waypoint();
	void	teleport_to_objective();
	void	teleport_to_coords(v3 coords);
	void	teleport_entity_to_coords(Entity e, v3 coords, bool particleFX = true);
	int		get_free_seat(Vehicle v);
	void	teleport_to_ped_car(Ped p);
	void	get_in_closest_car();
	void	teleport_to_entity(Entity e);
	bool	teleport_player_to_me(Ped p);
	bool	teleport_player_to_sea(Ped p);
	void	teleport_player_to_air(Ped p);
	v3		get_coords_infront_player(float dist);
	v3		get_coords_above_player(float dist);
	v3		get_coords_infront_of_cam(float dist);

	void	notify_above_map(std::string msg, bool blink);

	void		show_ingame_keyboard(char* title, char* default_text = nullptr);
	std::string	get_ingame_keyboard_result();

	void	draw_esp_on_entity(Entity e, std::string text, bool bBox = true, bool bHealth = false, bool bDist = false, float fMaxDist = 5000.f);
	Object	trap_player_in_cage(Ped ped);

	void	remove_nearby_objects();
	Object	attach_object_to_entity(Entity e, char* object, int bone = -1);
	void	attach_entities(Entity e, Entity t, int bone = -1, v3 pos = {0.f, -.26f, .1f}, v3 rot = {0.f, 0.f, 0.f});
	void	detach_entity(Entity e);

	void	clean_ped(Ped p);
	void	fix_vehicle(Vehicle v);

	Ped		clone_ped_bodyguard(Ped p);

	void	ped_give_all_weapons(Ped p);
	void	ped_weapon(Ped p, std::string weapon, bool give = true);

	bool	spawn_ped(char* model, ePedType pedType = PedTypeHuman, v3 pos = {}, Ped* pedOut = nullptr, bool random = false, int flag = 0);
	bool	spawn_vehicle(const char* model, Vehicle* vehOut = nullptr, bool warp = false, bool bypass = false, bool upgrade = false);
	void	vehicle_bypass(Vehicle vehicle);
	bool	spawn_object(const char* model, Object* objOut = nullptr);
	void	vehicle_sp_bypass(bool b);
	bool	upgrade_car(Vehicle v, bool car);

	void	teleport_player_on_foot(Ped p, float X, float Y, float Z);

	void	clown_particle_effect_on_entity(Entity e);

	void	clear_badsports();

	void	set_radio_station(std::string station);

	void	set_entity_invisible(Entity e, bool invis, bool local = false);

	int		super_run(float force, bool stop = false);

	void	chaos_mode(clock_t* tmr, int action = 0);
	bool	smash_vehicles(clock_t* tmr);

	void	drop_money_on_entity(Entity e, int amount = 2000, char* prop = "prop_money_bag_01");

	void	set_time(int h, int m);
	void	set_weather(char* w);

	void	draw_speedometer(Vehicle v, bool mph = false);
	void	draw_fps();

	void	noclip(Entity e, int action, float speed = 1.f, bool freeCam = false, bool restore = false);

	bool	entity_editor(int action, float dist = 20.f, int flag = 0x01, v3 rot = {0.f, 0.f, 0.f}, Entity ent = NULL);

	void	anti_afk(Ped p, char* anim, bool r);

	bool	send_assasins_after_player(Player p, Ped ped);

	void	shoot_ped(Ped ped, DWORD bone = hash::ped_bone_hash[0], bool owned = false);
	void	explode_ped(Ped ped, int type);

	void	lester_offradar_toggle(bool b);
	void	lester_offradar_add(int ms);
}

#endif