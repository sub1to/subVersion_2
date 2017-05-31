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

enum ePedSpawn : unsigned
{
	PEDSPAWN_NORMAL		= 0,
	PEDSPAWN_BODYGUARD	= 1,
	PEDSPAWN_ARMY		= 2,
};

enum eVehSpawn : unsigned
{
	VEHSPAWN_WARP		= 1 << 0,
	VEHSPAWN_MP_BYPASS	= 1 << 1,
	VEHSPAWN_UPGRADE	= 1 << 2,
	VEHSPAWN_LICENSE	= 1 << 3,
};

enum eNoclipAction : unsigned
{
	NOCLIP_FORWARD		= 1 << 0,
	NOCLIP_BACK			= 1 << 1,
	NOCLIP_LEFT			= 1 << 2,
	NOCLIP_RIGHT		= 1 << 3,
	NOCLIP_UP			= 1 << 4,
	NOCLIP_DOWN			= 1 << 5,
};

enum eChaosAction : unsigned
{
	CHAOSMODE_BOUNCE		= 0,
	CHAOSMODE_ASCENTION		= 1,
	CHAOSMODE_ARMAGEDDON	= 2,
	CHAOSMODE_MAYHEM		= 3,
	CHAOSMODE_FORCEFIELD	= 4,
	CHAOSMODE_GRAVITYFIELD	= 5,
	CHAOSMODE_SMASH			= 6,
	CHAOSMODE_MASSACRE		= 7,
	CHAOSMODE_ENERGYFIELD	= 8,
};

enum eEspFlag : unsigned
{
	ESP_BOX			= 1 << 0,
	ESP_HEALTHBAR	= 1 << 1,
	ESP_TEXT_DIST	= 1 << 2,
	ESP_TEXT_HEALTH	= 1 << 3,
	ESP_TEXT_GOD	= 1 << 4,
	ESP_WORLD_LINE	= 1 << 5,
};

enum eTrgBot : unsigned
{
	TRGBOT_PEDS		= 1 << 0,
	TRGBOT_PLAYERS	= 1 << 1,
};

enum eEditorAction : unsigned
{
	EDIT_ACTION_RESET	= 1 << 0,
	EDIT_ACTION_LOCK	= 1 << 1,
	EDIT_ACTION_DELETE	= 1 << 2,
};

enum eEditorFlag : unsigned
{
	EDITOR_FLAG_TEXT_TYPE	= 1 << 0,
	EDITOR_FLAG_TEXT_POS	= 1 << 1,
	EDITOR_FLAG_COLLISION	= 1 << 2,
	EDITOR_FLAG_FREEZE		= 1 << 3,
	EDITOR_FLAG_THROW		= 1 << 4,
	EDITOR_FLAG_REL_ROT		= 1 << 5,
	EDITOR_FLAG_INVISIBLE	= 1 << 6,
	EDITOR_FLAG_ROT			= 1 << 7,
};

enum eXHair : unsigned
{
	XHAIR_PEDS_ONLY		= 1 << 0,
	XHAIR_ALIVE_ONLY	= 1 << 1,
};

namespace util
{
	float	deg_to_rad(float deg);
	int		random_int(int start, int end);
	bool	to_clipboard(char* str);
	bool	world_to_screen(v3 pos, v2& out);
	Hash	$(std::string str);
	float	pixel_to_rel(uint32_t in, bool height);
	uint32_t rel_to_pixel(float in, bool height);

	uintptr_t	get_address_of_item_in_pool(MemoryPool* pool, int handle);

	template <typename rT>
	rT*	handle_to_ptr(int handle)
	{
		uintptr_t	ptr	= get_address_of_item_in_pool(*CHooking::m_entityPool, handle);
		if(ptr == 0)
			return nullptr;
		return *reinterpret_cast<rT**>(ptr + 8);
	}

	template <class T>
	void	clear_queue(std::queue<T>& q)
	{
		std::queue<T>	tmp;
		std::swap(q, tmp);
	}
}

namespace script
{
	bool	is_ped_in_any_vehicle(Ped ped);
	v3		get_entity_coords(Entity e);
	bool	is_player_ped_female(Ped ped);
	bool	is_an_entity(Entity e);
	bool	is_entity_dead(Entity ped);
	bool	is_entity_a_ped(Entity entity);
	bool	is_entity_a_vehicle(Entity entity);
	bool	is_entity_an_object(Entity entity);
	bool	is_entity_visible(Entity entity);
	void	set_vehicle_tire_smoke(Vehicle vehicle, int r = -1, int g = -1, int b = -1);

	void	apply_force_to_entity(Ped ped, int forceType, float x, float y, float z, float rx, float ry, float rz, bool isRel, bool highForce);
	void	add_explosion(Vector3 pos, int type, float damage, bool isAudible, bool isInvis, float shake);

	void	apply_clothing(Ped playerPed, int group, int var = -1, int texture = -1);
	void	apply_outfit(eCustomOutfit type);

	bool	apply_model(Hash skin, bool random = false);

	bool	request_control_of_entity(Entity entity);

	void	update_nearby_ped(bool alive = true, queue_int* out = &CHack::m_nearbyPed);
	void	update_nearby_vehicle(bool driveable = true, queue_int* out = &CHack::m_nearbyVehicle);

	bool	teleport_to_waypoint();
	void	teleport_to_objective();
	void	teleport_to_personal_vehicle();
	void	teleport_to_coords(v3 coords);
	void	teleport_entity_to_coords(Entity e, v3 coords, bool particleFX = true);
	int		get_free_seat(Vehicle v);
	void	teleport_to_ped_car(Ped p);
	void	get_in_closest_car();
	void	teleport_to_entity(Entity e);
	bool	teleport_player_to_me(Player player);
	bool	teleport_player_to_sea(Player player);
	void	teleport_player_to_air(Player player);
	v3		get_coords_infront_player(float dist);
	v3		get_coords_above_player(float dist);
	v3		get_coords_infront_of_cam(float dist);

	void	notify_above_map(std::string msg, bool blink);

	void	show_ingame_keyboard(char* title, char* default_text = nullptr);
	bool	get_ingame_keyboard_result(std::string& str);
	bool	ingame_keyboard(std::string& out, eKeyboardOwner owner, bool reset = false);

	void	draw_text(char* text, float x, float y, int font, float scale, CColor color);
	void	draw_esp_on_player(Player player, char* text, int flag = 0, float fMaxDist = 5000.f);
	Object	trap_player_in_cage(Player player);

	void	attach_entities(Entity e, Entity t, int bone = -1, Vector3 pos = {0.f, -.26f, .1f}, Vector3 rot = {0.f, 0.f, 0.f});
	void	detach_entity(Entity e);

	void	clean_ped(Ped p);
	void	fix_vehicle(Vehicle v);

	Ped		clone_ped_bodyguard(Ped p);

	bool	ped_give_all_weapons(Ped p, Player player = -1);
	bool	ped_weapon(Ped p, DWORD weapon, bool give = true);

	void	no_reload_toggle(bool);
	void	infinite_ammo_toggle(bool);
	void	explosive_ammo(int explosionType);

	bool	spawn_ped(Hash model, ePedType pedType = PedTypeHuman, v3 pos = {}, Ped* pedOut = nullptr, bool random = false, int flag = 0);
	bool	spawn_vehicle(Hash model, Vehicle* vehOut = nullptr, BYTE flags = 0, int64_t colours = -1);
	void	vehicle_bypass(Vehicle vehicle);
	bool	spawn_object(Hash model, Object* objOut = nullptr);
	void	vehicle_sp_bypass(bool b);
	void	vehicle_mp_bypass(bool b);
	bool	upgrade_car(Vehicle v, bool car = true, int64_t colours = -1);
	bool	set_vehicle_color(Vehicle v, int p = -1, int s = -1, int pearl = -1, int wheel = -1);

	void	teleport_player_on_foot(Ped p, float X, float Y, float Z);

	//void	clear_badsports();

	void	set_radio_station(std::string station);

	void	set_entity_invisible(Entity e, bool invis, bool local = false);

	int		super_run(float force, bool stop = false, bool keyState = false);

	void	chaos_mode(int action = 0);
	bool	smash_vehicles();
	bool	black_hole(int sec);

	bool	drop_money_on_player(Player player, int amount = 2000, const DWORD hash = 0x113FD533);
	void	ped_money_drop(Player player, clock_t* tmr);
	void	stealth_money(int mils, bool remove = false);

	void	trigger_script_event(eScriptEvent id, Player player, uint64_t arg2 = 0, uint64_t arg3 = 0);

	void	set_time(int h, int m);
	void	set_weather(std::string w);
	void	freeze_time(bool b);

	void	draw_speedometer(Vehicle v, bool mph = false);
	void	draw_fps();
	void	draw_crosshair(CColor color, int flag, int size = 20, int thickness = 2);

	void	noclip(Entity e, int action, float speed = 1.f, bool freeCam = false, bool restore = false);

	bool	trigger_bot(uint32_t flag);

	Entity	get_entity_crosshair(int flag = 0);
	bool	entity_editor(int action, float dist = 20.f, int flag = 0x01, Vector3 rot = {0.f, 0}, Entity ent = NULL);

	//void	ped_scenario(Ped p, char* anim, bool r);

	bool	send_assasins_after_player(Player p);

	void	shoot_ped(Ped ped, DWORD bone = hash::ped_bone_hash[0], bool owned = false);
	void	explode_ped(Ped ped, int type);
	void	explode_nearby_players(Player source);

	void	lester_offradar_toggle(bool b);
	void	lester_offradar_add(int ms);

	void	spectate_player(Ped p, bool b = false);

	bool	animate_player(Player player, std::string dict, std::string anim, bool freeze = false, bool restore = false);
	bool	animate_local_player(Ped playerPed, std::string dict, std::string anim, bool restore = false);

	bool	player_dead_clone(Player player, bool erase = false);

	bool	give_player_wanted_level(Player player);

	bool	clean_session();
	bool	crash_player(Player player);

	int		get_online_player_index();
	void	unlocks_stats();
	void	unlocks_tattoos();
	void	unlocks_parachutes();
	void	unlocks_chrome_rims();
	void	unlocks_vehicles();
	void	unlocks_trophies();
	void	unlocks_hairstyles();
	void	unlocks_weapons();
	void	unlocks_clothes();
}

#endif
