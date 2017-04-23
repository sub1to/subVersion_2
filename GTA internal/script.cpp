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

namespace util
{
	float deg_to_rad(float deg)
	{
		return deg * 3.141592653589793f / 180.f;
	}

	int random_int(int start, int end)
	{
		static bool seed	= false;
		if(!seed)
		{
			srand((unsigned int) time(0));
			seed = true;
		}
		return rand() % end + start;
		//return GAMEPLAY::GET_RANDOM_INT_IN_RANGE(start, end);
	}

	uintptr_t	get_address_of_item_in_pool(MemoryPool* pool, int handle)
	{
		if(pool == nullptr)
			return 0;

		int index	= handle >> 8;
		int flag	= pool->BoolAdr[index];

		if(flag & 0x80 || flag != (handle & 0xFF))
			return 0;

		return pool->ListAddr + index * pool->ItemSize;
	}

	CPed*	ped_handle_to_ptr(Ped ped)
	{
		uintptr_t	ptr	= get_address_of_item_in_pool(*CHooking::m_entityPool, ped);
		if(ptr == 0)
			return nullptr;
		return *reinterpret_cast<CPed**>(ptr + 8);
	}

	CVehicle*	vehicle_handle_to_ptr(Vehicle veh)
	{
		uintptr_t	ptr	= get_address_of_item_in_pool(*CHooking::m_entityPool, veh);
		if(ptr == 0)
			return nullptr;
		return *reinterpret_cast<CVehicle**>(ptr + 8);
	}

	bool	to_clipboard(char* str)
	{
		size_t	len		= strlen(str) + 1;
		HGLOBAL	hMem	= GlobalAlloc(GMEM_MOVEABLE, len);
		if(hMem == nullptr)
			return false;
		memcpy(GlobalLock(hMem), &str[0], len);
		GlobalUnlock(hMem);
		OpenClipboard(0);
		EmptyClipboard();
		SetClipboardData(CF_TEXT, hMem);
		CloseClipboard();
		return true;
	}
}

namespace script
{
	bool is_ped_in_any_vehicle(Ped ped)
	{
		CPed* pPed	= util::ped_handle_to_ptr(ped);
		if(pPed == nullptr || !pPed->isInVehicle())
			return false;
		return true;
	}

	v3	get_entity_coords(Entity e)
	{
		CPed* pPed	= util::ped_handle_to_ptr(e);
		if(pPed == nullptr || pPed->pCNavigation == nullptr)
			return {};
		return pPed->pCNavigation->v3Pos;
	}

	float	get_ped_health(Ped ped)
	{
		CPed* pPed	= util::ped_handle_to_ptr(ped);
		if(pPed == nullptr)
			return {};
		return pPed->fHealth;
	}

	bool	set_ped_health(Ped ped, float value)
	{
		CPed* pPed	= util::ped_handle_to_ptr(ped);
		if(pPed == nullptr)
			return false;
		pPed->fHealth	= value;
		return true;
	}

	float	get_ped_max_health(Ped ped)
	{
		CPed* pPed	= util::ped_handle_to_ptr(ped);
		if(pPed == nullptr)
			return {};
		return pPed->fHealthMax;
	}

	float	get_ped_armor(Ped ped)
	{
		CPed* pPed	= util::ped_handle_to_ptr(ped);
		if(pPed == nullptr)
			return {};
		return pPed->fArmor;
	}

	float	get_vehicle_health(Vehicle veh)
	{
		CVehicle* pVeh	= util::vehicle_handle_to_ptr(veh);
		if(pVeh == nullptr)
			return {};
		return pVeh->fHealth;
	}

	bool is_player_ped_female(Ped ped)
	{
		return ENTITY::GET_ENTITY_MODEL(ped)	== 0x9C9EFFD8;
	}

	void apply_clothing(Ped playerPed, int group, int var, int texture)
	{
		PED::SET_PED_COMPONENT_VARIATION(playerPed, group, var == -1 ? PED::GET_PED_DRAWABLE_VARIATION(playerPed, group) : var, texture == -1 ? PED::GET_PED_TEXTURE_VARIATION(playerPed, group) : texture, PED::GET_PED_PALETTE_VARIATION(playerPed, group));
	}

	void	apply_outfit_santa()
	{
		Ped playerPed	= PLAYER::PLAYER_PED_ID();
		bool female	= is_player_ped_female(playerPed);
		PED::CLEAR_ALL_PED_PROPS(playerPed);
		apply_clothing(playerPed,	0x01,	0x08,					0x00);
		apply_clothing(playerPed,	0x03,	female ? 0x34 : 0x32,	0x00);
		apply_clothing(playerPed,	0x04,	female ? 0x3B : 0x39,	0x00);
		apply_clothing(playerPed,	0x05,	0x00,					0x00);
		apply_clothing(playerPed,	0x06,	female ? 0x28 : 0x27,	0x00);
		apply_clothing(playerPed,	0x07,	0x00,					0x00);
		apply_clothing(playerPed,	0x08,	female ? 0x01 : 0x0F,	female ? 0x02 : 0x00);
		apply_clothing(playerPed,	0x09,	0x00,					0x00);
		apply_clothing(playerPed,	0x0A,	0x00,					0x00);
		apply_clothing(playerPed,	0x0B,	female ? 0x6C : 0x74,	0x00);
	}

	void	apply_outfit_trashman_orange()
	{
		Ped playerPed	= PLAYER::PLAYER_PED_ID();
		bool female	= is_player_ped_female(playerPed);
		PED::CLEAR_ALL_PED_PROPS(playerPed);
		apply_clothing(playerPed,	0x01,	0x00,					0x00);
		apply_clothing(playerPed,	0x03,	female ? 0x0E : 0x00,	0x00);
		apply_clothing(playerPed,	0x04,	female ? 0x23 : 0x24,	0x00);
		apply_clothing(playerPed,	0x05,	0x00,					0x00);
		apply_clothing(playerPed,	0x06,	0x19,					0x00);
		apply_clothing(playerPed,	0x07,	0x00,					0x00);
		apply_clothing(playerPed,	0x08,	female ? 0x24 : 0x3B,	0x01);
		apply_clothing(playerPed,	0x09,	0x00,					0x00);
		apply_clothing(playerPed,	0x0A,	0x00,					0x00);
		apply_clothing(playerPed,	0x0B,	female ? 0x31 : 0x38,	0x00);
	}

	void	apply_outfit_trashman_green()
	{
		Ped playerPed	= PLAYER::PLAYER_PED_ID();
		bool female	= is_player_ped_female(playerPed);
		PED::CLEAR_ALL_PED_PROPS(playerPed);
		apply_clothing(playerPed,	0x01,	0x00,					0x00);
		apply_clothing(playerPed,	0x03,	female ? 0x03 : 0x04,	0x00);
		apply_clothing(playerPed,	0x04,	female ? 0x23 : 0x24,	0x00);
		apply_clothing(playerPed,	0x05,	0x00,					0x00);
		apply_clothing(playerPed,	0x06,	0x19,					0x00);
		apply_clothing(playerPed,	0x07,	0x00,					0x00);
		apply_clothing(playerPed,	0x08,	female ? 0x24 : 0x3B,	0x00);
		apply_clothing(playerPed,	0x09,	0x00,					0x00);
		apply_clothing(playerPed,	0x0A,	0x00,					0x00);
		apply_clothing(playerPed,	0x0B,	female ? 0x32 : 0x39,	0x00);
	}

	void	apply_outfit_police()
	{
		Ped playerPed	= PLAYER::PLAYER_PED_ID();
		bool female	= is_player_ped_female(playerPed);
		PED::CLEAR_ALL_PED_PROPS(playerPed);
		PED::SET_PED_PROP_INDEX(playerPed,	0,	female ? 45 : 46,	0,	2);
		PED::SET_PED_PROP_INDEX(playerPed,	1,	female ? 11 : 13,	0,	2);
		apply_clothing(playerPed,	0x01,	0x00,					0x00);
		apply_clothing(playerPed,	0x03,	female ? 0x0E : 0x00,	0x00);
		apply_clothing(playerPed,	0x04,	female ? 0x22 : 0x23,	0x00);
		apply_clothing(playerPed,	0x05,	0x00,					0x00);
		apply_clothing(playerPed,	0x06,	0x19,					0x00);
		apply_clothing(playerPed,	0x07,	0x00,					0x00);
		apply_clothing(playerPed,	0x08,	female ? 0x23 : 0x3A,	0x00);
		apply_clothing(playerPed,	0x09,	0x00,					0x00);
		apply_clothing(playerPed,	0x0A,	0x00,					0x00);
		apply_clothing(playerPed,	0x0B,	female ? 0x30 : 0x37,	0x00);
	}

	bool apply_model(DWORD model, bool random)
	{
		if(!STREAMING::IS_MODEL_IN_CDIMAGE(model) && !STREAMING::IS_MODEL_VALID(model))
			return true;

		STREAMING::REQUEST_MODEL(model);
		if(!STREAMING::HAS_MODEL_LOADED(model))
			return false;

		Ped		playerPed = PLAYER::PLAYER_PED_ID();
		Vehicle v	= NULL;
		if(is_ped_in_any_vehicle(playerPed))
			v = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);

		//random ? PED::SET_PED_RANDOM_COMPONENT_VARIATION(playerPed, true) : PED::SET_PED_DEFAULT_COMPONENT_VARIATION(playerPed);

		if (v != NULL)
			PED::SET_PED_INTO_VEHICLE(playerPed, v, get_free_seat(v));

		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

		return true;
	}

	bool can_model_random(std::string model)
	{
		std::regex		regexCS("^(cs_|player_).*$");
		std::smatch		regexMatch; 
		if(std::regex_search(model, regexMatch, regexCS))
			return false;
		return true;
	}

	bool apply_model(std::string skinName, bool random)
	{
		if(!can_model_random(skinName))
			random = false;
		DWORD model = $(&skinName[0]);
		return apply_model(model, random);
	}

	bool request_control_of_id(Entity netid)
	{
		if(!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid))
			NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		return true && NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid);
	}

	bool request_control_of_entity(Entity entity)
	{
		if(!NETWORK::NETWORK_IS_SESSION_STARTED())
			return true;
		//if(ENTITY::IS_ENTITY_A_PED(entity))
		//	for(int i = 0; i < MAX_PLAYERS; i++)
		//		if(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == entity)
		//			return false;

		if(!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity))
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);

		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
		request_control_of_id(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
		return true && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity);
	}

	bool is_ped_a_player(Ped ped)
	{
		for(int i = 0; i < MAX_PLAYERS; i++)
			if(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == (ped))
				return true;
		return false;
	}

	void update_nearby_ped(Ped origin, int c)
	{
		Ped* ped	= new Ped[c * 2 + 2];
		*ped		= (const int) c;
		c			= PED::GET_PED_NEARBY_PEDS(origin, ped, -1);

		for(int i = 0; i < c; i++)
		{
			int	id	= i * 2 + 2;
			if(!ENTITY::IS_AN_ENTITY(ped[id]) || PED::IS_PED_DEAD_OR_DYING(ped[id], false) || is_ped_a_player(ped[id]))
				continue;
			CHack::m_nearbyPed.push_back(ped[id]);
		}
		delete ped;
	}

	void update_nearby_vehicle(Ped origin, int c, bool driveable)
	{
		Vehicle* veh	= new Vehicle[c * 2 + 2];
		*veh			= (const int) c;
		c				= PED::GET_PED_NEARBY_VEHICLES(origin, veh);

		for(int i = 0; i < c; i++)
		{
			int	id	= i * 2 + 2;
			if(!ENTITY::IS_AN_ENTITY(veh[id]) || (driveable && !VEHICLE::IS_VEHICLE_DRIVEABLE(veh[id], false)) || CHack::m_lastVehicle == veh[id])
				continue;
			CHack::m_nearbyVehicle.push_back(veh[id]);
		}
		delete veh;
	}

	//Hash $(std::string str)
	//{
	//	return GAMEPLAY::GET_HASH_KEY(&str[0]);
	//}

	Hash $(std::string str)
	{
		size_t len = str.size();
		unsigned int hash, i;
		for(hash = i = 0; i < len; ++i)
		{
			hash += tolower(str[i]);
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}
		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);
		return hash;
	}

	void teleport_entity_to_coords(Entity e, v3 pos, bool particleFX)
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, pos.x, pos.y, pos.z, 0, 0, 1);
		if(particleFX)
			clown_particle_effect_on_entity(e);
	}

	void teleport_to_coords(v3 coords)
	{
		Entity e	= PLAYER::PLAYER_PED_ID();
		if (is_ped_in_any_vehicle(e))
			e = PED::GET_VEHICLE_PED_IS_USING(e);
		teleport_entity_to_coords(e, coords);
	}

	CBlip*	get_blip_waypoint()
	{
		for(int i = 0; i < 0x400; i++)
		{
			CBlip*	blip	= CHooking::m_blipList->m_Blips[i];
			if(blip == nullptr)
				continue;

			if(blip->dwColor == ColorWaypoint && blip->iIcon == SpriteWaypoint)
				return blip;
		}
		return nullptr;
	}

	static int iHeight = 0;
	bool teleport_to_waypoint()
	{
		static v3	pos;
		if(pos.empty())
		{
			CBlip*	blip	= get_blip_waypoint();
			if(blip == nullptr)
			{
				notify_above_map("Waypoint not found.", 0);
				return true;
			}
			pos		= blip->v3Pos;
		}

		static float heightArray[] =
		{ 200.f, 150.f, 100.f, 50.f, 0.f, 250.f, 300.f, 350.f, 400.f, 450.f, 500.f, 550.f, 600.f, 650.f, 700.f, 750.f, 800.f };

		teleport_to_coords({pos.x, pos.y, heightArray[iHeight]});
		if(!GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(pos.x, pos.y, heightArray[iHeight], &pos.z, 0) && iHeight < sizeof(heightArray) / sizeof(*heightArray))
		{
			iHeight++;
			return false;
		}

		iHeight = 0;
		pos.z += 2.5f;
		teleport_to_coords(pos);
		pos	= {};
		return true;
	}

	CBlip*	get_blip_objective()
	{
		for(int i = 0; i < 0x400; i++)
		{
			CBlip*	blip	= CHooking::m_blipList->m_Blips[i];
			if(blip == nullptr)
				continue;
			if
			(
				(blip->dwColor	== ColorYellowMission	&& blip->iIcon == SpriteStandard)	||
				(blip->dwColor	== ColorYellow			&& blip->iIcon == SpriteStandard)	||
				(blip->dwColor	== ColorWhite			&& blip->iIcon == SpriteRaceFinish)	||
				(blip->dwColor	== ColorGreen			&& blip->iIcon == SpriteStandard)	||
				(blip->iIcon	== SpriteCrateDrop)
			)
				return blip;
		}
		return nullptr;
	}

	void teleport_to_objective()
	{
		CBlip* blip = get_blip_objective();
		blip == nullptr ? notify_above_map("Objective not found.", 0) : teleport_to_coords({ blip->v3Pos.x, blip->v3Pos.y, blip->v3Pos.z + 1.f });
	}

	void teleport_to_entity(Entity e)
	{
		v3 remotePos = get_entity_coords(e);
		remotePos.z += 2.5f;
		teleport_to_coords(remotePos);
	}

	bool teleport_player_to_me(Ped ped)
	{
		v3 playerPos	= script::get_coords_infront_player(6.f);
		v3 remotePos	= get_entity_coords(ped);
		playerPos.z += 1.f;
		if(playerPos.getDist(remotePos) < 10.f)
		{
			clown_particle_effect_on_entity(ped);
			return true;
		}
		script::teleport_player_on_foot(ped, playerPos.x, playerPos.y, playerPos.z);
		return false;
	}

	bool teleport_player_to_sea(Ped ped)
	{
		v3 seaPos		= {-3735.f, -4400.f, 10.f};
		v3 remotePos	= get_entity_coords(ped);
		if(seaPos.getDist(remotePos) < 10.f)
		{
			clown_particle_effect_on_entity(ped);
			return true;
		}
		script::teleport_player_on_foot(ped, seaPos.x, seaPos.y, seaPos.z);
		return false;
	}

	void teleport_player_to_air(Ped ped)
	{
		v3 remotePos = get_entity_coords(ped);
		script::teleport_player_on_foot(ped, remotePos.x, remotePos.y, remotePos.z + 100.f);
		script::clown_particle_effect_on_entity(ped);
	}

	void notify_above_map(std::string msg, bool blink)
	{
		UI::SET_TEXT_OUTLINE();
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(&msg[0u]);
		UI::_DRAW_NOTIFICATION(blink, FALSE);
	}

	void	show_ingame_keyboard(char* title, char* default_text)
	{
		GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, (title == nullptr ? "subVersion" : title), "", (default_text == nullptr ? "" : default_text), "", "", "", 64);
	}

	std::string	get_ingame_keyboard_result()
	{
		std::string	r	= "!!INVALID!!";
		if(GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD())
		{
			char* pCh = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
			if(pCh != nullptr)
				r = pCh;
		}
		return r;
	}

	void draw_text(std::string text, float x, float y, int font, float scale, CColor color)
	{
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(scale, scale);
		UI::SET_TEXT_COLOUR(color.r, color.g, color.b, color.a);
		UI::SET_TEXT_WRAP(0.0, 1.0); //
		UI::SET_TEXT_CENTRE(false);
		UI::SET_TEXT_DROPSHADOW(2, 0, 0, 0, 175);
		UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING"); //
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(&text[0]);
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
	}

	void draw_esp_on_entity(Entity e, std::string text, bool bBox, bool bHealth, bool bDist, float fMaxDist)
	{
		v3 pos			= get_entity_coords(e);
		v3 playerPos	= get_entity_coords(PLAYER::PLAYER_PED_ID());
		float	dist		= pos.getDist(playerPos);
		float	x, x2, y, y2;
		if(dist < fMaxDist && GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(pos.x, pos.y, pos.z -1.f, &x, &y) && GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(pos.x, pos.y, pos.z + .8f, &x2, &y2))
		{
			float	w, h;
			h	= y - y2;
			if(h < 0.f)
				h	*= -1.f;
			w	= h / 4;

			float d = dist > 500.f ? 500.f : dist;
			float textScale	= 0.25f - (0.1f * (d / 500));

			draw_text(text, x2 - (w / 2), y2 - 0.02f, 0, textScale, {255, 255, 255, 255});

			if(bDist)
			{
				std::string str		= std::to_string((int) dist);
				draw_text(str, x2 - (w / 2), y2 - 0.03f, 0, textScale, {255, 255, 255, 255});
			}

			if(dist < 500.f)		// more than 500 distance, the boxes are too small
			{
				if(bBox)
				{
					GRAPHICS::DRAW_RECT(x2, y2, w, .001f, 0, 255, 0, 255);		//top
					GRAPHICS::DRAW_RECT(x2, y, w, .001f, 0, 255, 0, 255);		//bottom
					GRAPHICS::DRAW_RECT(x2 - (w / 2), y2 + (h / 2), .0006f, h, 0, 255, 0, 255);		//left
					GRAPHICS::DRAW_RECT(x2 + (w / 2), y2 + (h / 2), .0006f, h, 0, 255, 0, 255);		//right
				}

				if(bHealth)
				{
					float maxHealth	= (float) get_ped_max_health(e) + 50.f;
					float health	= (float) get_ped_health(e) + get_ped_armor(e);
					GRAPHICS::DRAW_RECT(x2 - (w / 2) - 0.006f,  y2 + (h / 2), .004f, h, 0, 255, 0, 255);
					GRAPHICS::DRAW_RECT(x2 - (w / 2) - 0.006f,  y2 + (h / 2) + (h * (1 - (health / maxHealth)) / 2), .002f, h * (health / maxHealth) - 0.004f, 255, 0, 0, 255);
				}
			}
		}
	}

	/*
	flag
		0	= normal ped
		1	= bodyguard
		2	= army
	*/

	bool spawn_ped(char* model, ePedType pedType, v3 pos, Ped* pedOut, bool random, int flag)
	{
		Hash	pedHash	= $(model);
		if(!STREAMING::IS_MODEL_IN_CDIMAGE(pedHash) || !STREAMING::IS_MODEL_VALID(pedHash))
			return true;
		STREAMING::REQUEST_MODEL(pedHash);
		if(!STREAMING::HAS_MODEL_LOADED(pedHash))
			return false;

		if(!can_model_random(model))
			random = false;

		if(pos.empty())
			pos	= get_coords_infront_player(6.f);
		pos.x += util::random_int(-2, 2);
		pos.y += util::random_int(-2, 2);

		Ped		ped	= PED::CREATE_PED(pedType, pedHash, pos.x, pos.y, pos.z, 0.f, true, true);
		random ? PED::SET_PED_RANDOM_COMPONENT_VARIATION(ped, true) : PED::SET_PED_DEFAULT_COMPONENT_VARIATION(ped);

		if(pedOut != nullptr)
			*pedOut = ped;

		if(flag > 0)
		{
			if(flag == 1)
			{
				int grp		= PLAYER::GET_PLAYER_GROUP(PLAYER::PLAYER_ID());
				PED::SET_PED_AS_GROUP_MEMBER(ped, grp);
				PED::SET_PED_NEVER_LEAVES_GROUP(ped, grp);
				PED::SET_GROUP_FORMATION(ped, FormationIndexCircle);
			}
			if(flag == 2)
			{
				PED::SET_PED_RELATIONSHIP_GROUP_HASH(ped, $("army"));
				AI::TASK_WANDER_STANDARD(ped, 10.f, 10);
			}
			PED::SET_PED_CAN_SWITCH_WEAPON(ped, false);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(ped, $(hash::weapon_hash[0x8]), 9999, 0);
			PED::SET_PED_COMBAT_ABILITY(ped, 2); //0 poor, 1 average, 2 prof

			CHack::m_pedCleanup.push_back(ped);
		}
		else
			ENTITY::SET_PED_AS_NO_LONGER_NEEDED(&ped);

		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(pedHash);
		return true;
	}

	/*
		flags
			1 << 0	warp
			1 << 1	mp bitset bypass
			1 << 2	upgrade
			1 << 3	license
	*/
	bool spawn_vehicle(const char* model, Vehicle* vehOut, BYTE flags, int colours)//bool warp, bool bypass, bool upgrade)
	{
		v3		pos	= get_coords_infront_player(6.f);
		Ped		playerPed	= PLAYER::PLAYER_PED_ID();
		Hash	vehHash		= $(model);
	
		if(!STREAMING::IS_MODEL_IN_CDIMAGE(vehHash) || !STREAMING::IS_MODEL_A_VEHICLE(vehHash))
			return true;
		STREAMING::REQUEST_MODEL(vehHash);
		if(!STREAMING::HAS_MODEL_LOADED(vehHash))
			return false;

		bool	bFly	= (flags & 0x01) && (VEHICLE::IS_THIS_MODEL_A_HELI(vehHash) || VEHICLE::IS_THIS_MODEL_A_PLANE(vehHash)) ? true : false;
		if(bFly)
			pos.z += 100.f;
		Vehicle	veh	= VEHICLE::CREATE_VEHICLE(vehHash, pos.x, pos.y, pos.z + 1.f, ENTITY::GET_ENTITY_HEADING(playerPed), true, false);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, false);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(vehHash);

		if(bFly)
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 100.0f);
			VEHICLE::SET_HELI_BLADES_FULL_SPEED(veh);
		}
		else
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		if(flags & 0x01)
			PED::SET_PED_INTO_VEHICLE(playerPed, veh, -1);
		if(flags & 0x08)
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "YO MOMMA");
		if(vehOut != nullptr)
			*vehOut = veh;
		if(flags & 0x04)
			upgrade_car(veh, VEHICLE::IS_THIS_MODEL_A_CAR(vehHash) != 0, colours);
		else if(flags & 0x02)
			vehicle_bypass(veh);	//mp bypass

		//ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
		return true;
	}

	void vehicle_bypass(Vehicle v)
	{
		DECORATOR::DECOR_SET_INT(v, "MPBitset", (1 << 10));
	}

	void vehicle_mp_bypass(bool b)
	{
		//GAMEPLAY::SET_BIT((int*)CHooking::getGlobalPtr(1591201 + (1 * (PLAYER::GET_PLAYER_INDEX() + 602)) + 258 + 13), 3);
		if(b)
			*(int*)	CHooking::getGlobalPtr(0x184B0A + PLAYER::GET_PLAYER_INDEX())	|= (1 << 3);
			//GAMEPLAY::SET_BIT((int*)CHooking::getGlobalPtr(0x184B0A + PLAYER::GET_PLAYER_INDEX()), 3);
		else
			*(int*)	CHooking::getGlobalPtr(0x184B0A + PLAYER::GET_PLAYER_INDEX())	&= ~(1 << 3);
			//GAMEPLAY::CLEAR_BIT((int*)CHooking::getGlobalPtr(0x184B0A + PLAYER::GET_PLAYER_INDEX()), 3);
	}

	void vehicle_sp_bypass(bool b)
	{
		*CHooking::getGlobalPtr(0x2794B2) = b;
	}

	bool	upgrade_car(Vehicle v, bool wheels, int colours)
	{
		if(!request_control_of_entity(v))
			return false;

		vehicle_bypass(v);

		VEHICLE::SET_VEHICLE_MOD_KIT(v, 0);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(v, PLATE_YELLOWONBLACK);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(v, WHEEL_TYPE_HIGHEND);
		VEHICLE::TOGGLE_VEHICLE_MOD(v, MOD_TURBO, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(v, MOD_XENONLIGHTS, 1);
		VEHICLE::SET_VEHICLE_MOD(v, 0, VEHICLE::GET_NUM_VEHICLE_MODS(v, 0) - 2, false);		//biggest spoiler = ugly
		VEHICLE::SET_VEHICLE_WINDOW_TINT(v, 1);
		if(colours != -1)
			VEHICLE::SET_VEHICLE_COLOURS(v, colours & 0xFF, (colours >> 0x08) & 0xFF);
		for(int i = 1; i < 0x30; ++i)
		{
			if(!wheels && i > 22 && i < 25)
				continue;
			VEHICLE::SET_VEHICLE_MOD(v, i, VEHICLE::GET_NUM_VEHICLE_MODS(v, i) - 1, false);
		}
		return true;
	}

	bool spawn_object(const char* model, Object* objOut)
	{
		v3		pos	= get_coords_infront_player(10.f);
		Ped		playerPed	= PLAYER::PLAYER_PED_ID();
		Hash	objHash		= $(model);
	
		if(!STREAMING::IS_MODEL_IN_CDIMAGE(objHash))
			return true;
		STREAMING::REQUEST_MODEL(objHash);
		if(!STREAMING::HAS_MODEL_LOADED(objHash))
			return false;
		Object	obj	= OBJECT::CREATE_OBJECT(objHash, pos.x, pos.y, pos.z, true, false, false);

		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(objHash);

		if(objOut != nullptr)
			*objOut = obj;
		return true;
	}

	void ped_give_all_weapons(Ped p)
	{
		for(int i = 0; i < sizeof(hash::weapon_hash) / sizeof(hash::weapon_hash[0]); i++)
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(p, $(hash::weapon_hash[i]), 9999, 0);
	}

	void ped_weapon(Ped p, std::string weapon, bool give)
	{
		if(weapon == "ALL")
		{
			if(give)
				script::ped_give_all_weapons(p);
			else
				WEAPON::REMOVE_ALL_PED_WEAPONS(p, true);
		}
		else
		{
			if(give)
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(p, script::$(weapon), 9999, 0);
			else
				WEAPON::REMOVE_WEAPON_FROM_PED(p, script::$(weapon));
		}
	}

	void get_in_closest_car()
	{
		v3 pos = get_entity_coords(PLAYER::PLAYER_PED_ID());
		update_nearby_vehicle(PLAYER::PLAYER_PED_ID(), 0x1);
		Vehicle veh = CHack::m_nearbyVehicle[0];
		if(get_free_seat(veh) != -1)
		{
			Ped pDriver = VEHICLE::GET_PED_IN_VEHICLE_SEAT(veh, -1);
			AI::CLEAR_PED_TASKS_IMMEDIATELY(pDriver);
		}
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		CHack::m_nearbyVehicle.clear();
	}

	Ped clone_ped_bodyguard(Ped p)
	{
		int group = PED::GET_PED_GROUP_INDEX(p);
		Ped	ped = PED::CLONE_PED(p, ENTITY::GET_ENTITY_HEADING(p), 1, 1);
		PED::SET_PED_AS_GROUP_MEMBER(ped, group);
		PED::SET_PED_CAN_SWITCH_WEAPON(ped, false);
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(ped, $(hash::weapon_hash[0x8]), 9999, 0);
		PED::SET_PED_COMBAT_ABILITY(ped, 2); //0 poor, 1 average, 2 prof
		//ENTITY::SET_ENTITY_INVINCIBLE(ped, false);
		return ped;
	}

	void fix_vehicle(Vehicle v)
	{
		VEHICLE::SET_VEHICLE_FIXED(v);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(v);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(v, 0);
		VEHICLE::SET_VEHICLE_UNDRIVEABLE(v, false);
		clown_particle_effect_on_entity(v);
	}

	void clean_ped(Ped p)
	{
		PED::CLEAR_PED_BLOOD_DAMAGE(p);
		PED::RESET_PED_VISIBLE_DAMAGE(p);
		PED::CLEAR_PED_WETNESS(p);
		clown_particle_effect_on_entity(p);
	}

	int get_free_seat(Vehicle v)
	{
		int n = VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(v);
		for(int i = -1; i < n; i++)	// 0 = first passenger seat
			if(VEHICLE::IS_VEHICLE_SEAT_FREE(v, i))
				return i;
		return -2;
	}

	void teleport_to_ped_car(Ped ped) 
	{
		if(!is_ped_in_any_vehicle(ped))
			return;
		Vehicle v	= PED::GET_VEHICLE_PED_IS_USING(ped);
		int		s	= get_free_seat(v);
		if(s > -1)
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), v, s);
	}

	void attach_entities(Entity e, Entity t, int bone, v3 pos, v3 rot)
	{
		if(bone != -1 && pos.y == -.26f)
			pos.y = 0.f;
		bone == -1 ? bone = 0 : bone = PED::GET_PED_BONE_INDEX(e, bone);
		v3		pos2	= get_coords_infront_player(6.f);
		Object	obj		= OBJECT::CREATE_OBJECT($("prop_cs_dildo_01"), pos2.x, pos2.y, pos2.z, true, false, false);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(e, obj, 0, pos.x, pos.y, pos.z, rot.x, rot.y, rot.z, false, false, false, true, 2, true);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(obj, t, bone, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, false, false, false, true, 2, true);
		return;
	}

	void detach_entity(Entity e)
	{
		Object obj = ENTITY::GET_ENTITY_ATTACHED_TO(e);
		ENTITY::DETACH_ENTITY(e, false, true);
		ENTITY::PROCESS_ENTITY_ATTACHMENTS(e);
		if(ENTITY::IS_ENTITY_A_PED(e))
			AI::CLEAR_PED_TASKS_IMMEDIATELY(e);
		if(!ENTITY::IS_ENTITY_AN_OBJECT(obj))
			return;
		CHack::m_entityCleanup.push_back(obj);
		return;
	}

	Object attach_object_to_entity(Entity e, char* object, int bone)
	{
		bone == -1 ? bone = 0 : bone = PED::GET_PED_BONE_INDEX(e, bone);
		v3 pos	= get_coords_infront_player(6.f);
		Object obj	= OBJECT::CREATE_OBJECT($(object), pos.x, pos.y, pos.z, true, false, false);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(obj, e, bone, 0.f, bone != 0 ? 0.f : -.25f, 0.f, 0.f, bone != 0 ? 90.f : 0.f, 0.f, false, false, false, true, 2, true);
		return obj;
	}

	Object trap_player_in_cage(Ped ped)
	{
		v3 remotePos	= get_entity_coords(ped);
		Object obj	= OBJECT::CREATE_OBJECT($("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z -1.f, true, false, false);
		return obj;
	}

	void set_player_clothing(int group, int value, bool texture)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		if (texture)
			PED::SET_PED_COMPONENT_VARIATION(playerPed, group, PED::GET_PED_DRAWABLE_VARIATION(playerPed, group), value, PED::GET_PED_PALETTE_VARIATION(playerPed, group));
		else
			PED::SET_PED_COMPONENT_VARIATION(playerPed, group, value, 0, PED::GET_PED_PALETTE_VARIATION(playerPed, group));
	}

	void remove_nearby_objects()
	{
		v3 playerPosition = get_entity_coords(PLAYER::PLAYER_PED_ID());
		for(int j = 0; j < sizeof(hash::object_prop_spawn_hash) / sizeof(hash::object_prop_spawn_hash[0]); j++)
		{
			Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(playerPosition.x, playerPosition.y, playerPosition.z, 20.0f, $(hash::object_prop_spawn_hash[j]), false, false, false);
			if(!ENTITY::IS_AN_ENTITY(obj))
				continue;
			if(request_control_of_entity(obj))
				ENTITY::DELETE_ENTITY(&obj);
		}
	}

	void clown_particle_effect_on_entity(Entity e)
	{
		return;
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_rcbarry2");
		//GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_clown_appears", pos.x, pos.y, pos.z, 0.f, 0.f, 0.f, 1.f, false, false, false);
		GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE("scr_clown_appears", e, 0.f, 0.f, -.3f, 0.f, 0.f, 0.f, 0, 1.f, false, false, false);
		//GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_ENTITY_2("scr_clown_appears", e, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 1.f, false, false, false);
	}

	void clear_badsports()
	{
		STATS::STAT_SET_INT($("MPPLY_GRIEFING"), 0, 1);
		STATS::STAT_SET_INT($("MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
		STATS::STAT_SET_INT($("MPPLY_OFFENSIVE_TAGPLATE"), 0, 1);
		STATS::STAT_SET_INT($("MPPLY_OFFENSIVE_UGC"), 0, 1);
		STATS::STAT_SET_INT($("MPPLY_BAD_CREW_NAME"), 0, 1);
		STATS::STAT_SET_INT($("MPPLY_BAD_CREW_MOTTO"), 0, 1);
		STATS::STAT_SET_INT($("MPPLY_BAD_CREW_STATUS"), 0, 1);
		STATS::STAT_SET_INT($("MPPLY_BAD_CREW_EMBLEM"), 0, 1);
		STATS::STAT_SET_INT($("MPPLY_GAME_EXPLOITS"), 0, 1);
		STATS::STAT_SET_INT($("MPPLY_EXPLOITS"), 0, 1);
		STATS::STAT_SET_INT($("MPPLY_ISPUNISHED"), 0, 1);

		STATS::STAT_SET_INT($("MP0_CHEAT_BITSET"), 0, TRUE);
		STATS::STAT_SET_INT($("MP0_BAD_SPORT_BITSET"), 0, TRUE);
		STATS::STAT_SET_BOOL($("MPPLY_IS_HIGH_EARNER"), FALSE, TRUE);
		STATS::STAT_SET_BOOL($("MPPLY_IS_CHEATER"), FALSE, TRUE);
		STATS::STAT_SET_INT($("MPPLY_IS_CHEATER_TIME"), 0, TRUE);
		STATS::STAT_SET_INT($("MPPLY_WAS_I_BAD_SPORT"), 0, TRUE);
		STATS::STAT_SET_FLOAT($("MPPLY_OVERALL_BADSPORT"), 0, TRUE);
		STATS::STAT_SET_FLOAT($("MPPLY_OVERALL_CHEAT"), 0, TRUE);
		STATS::STAT_SET_BOOL($("MPPLY_CHAR_IS_BADSPORT"), FALSE, TRUE);
		STATS::STAT_SET_INT($("MPPLY_BECAME_BADSPORT_NUM"), 0, TRUE);
		STATS::STAT_SET_INT($("MPPLY_BECAME_CHEATER_NUM"), 0, TRUE);
		Any date[12];
		memset(&date, 0, sizeof(date));
		STATS::STAT_SET_DATE($("MPPLY_BECAME_CHEATER_DT"), &date[0], 7, TRUE);
		STATS::STAT_SET_DATE($("MPPLY_BECAME_BADSPORT_DT"), &date[0], 7, TRUE);
		STATS::STAT_SET_INT($("MPPLY_DESTROYED_PVEHICLES"), 0, TRUE);
		STATS::STAT_SET_INT($("MPPLY_BADSPORT_MESSAGE"), 0, TRUE);
		STATS::STAT_SET_INT($("MPPLY_KILLS_PLAYERS_CHEATER"), 69, TRUE);
		STATS::STAT_SET_INT($("MPPLY_DEATHS_PLAYERS_CHEATER"), 420, TRUE);
		STATS::STAT_SET_INT($("MPPLY_LAST_REPORT_PENALTY"), 0, TRUE);
		STATS::STAT_SET_INT($("MPPLY_LAST_COMMEND_PENALTY"), 0, TRUE);
		STATS::STAT_SET_INT($("MPPLY_LAST_REPORT_RESTORE"), 0, TRUE);
		STATS::STAT_SET_INT($("MPPLY_LAST_COMMEND_RESTORE"), 0, TRUE);
		STATS::STAT_SET_INT($("MPPLY_REPORT_STRENGTH"), 32, TRUE);
		STATS::STAT_SET_INT($("MPPLY_COMMEND_STRENGTH"), 32, TRUE);
		STATS::STAT_SET_INT($("MPPLY_VOTED_OUT"), 0, TRUE);
		STATS::STAT_SET_INT($("MPPLY_VOTED_OUT_DELTA"), 0, TRUE);
		STATS::STAT_SET_INT($("MPPLY_VOTED_OUT_QUIT"), 0, TRUE);
		STATS::STAT_SET_BOOL($("MPPLY_WAS_I_BAD_SPORT"), FALSE, TRUE);
		STATS::STAT_SET_BOOL($("MPPLY_WAS_I_CHEATER"), FALSE, TRUE);

		notify_above_map("Reports have been cleared. GL HF", 0);
	}

	void teleport_player_on_foot(Ped ped, float X, float Y, float Z)
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(ped);
		int scene = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(X, Y, Z, 0.0, 0.0, 0.0, 2, 0, 0, 0, 0, 0);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(ped, scene, "mini@strip_club@private_dance@part3", "priv_dance_p3", 8.0f, -8.0, 5, 0, 30, 0);
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(scene);
	}

	/*void teleport_all_players_to_me()
	{
		v3 pos = get_coords_infront_player(6.f);
		for (int i = 0; i < 32; i++)
		{
			int playerid = PLAYER::GET_PLAYER_PED(i);
			if (playerid > 0 && playerid != PLAYER::PLAYER_PED_ID())
				teleport_player_on_foot(playerid, pos.x, pos.y, pos.z + 1.f);
		}
	}*/

	v3 get_coords_infront_player(float dist)
	{
		v3 r = get_entity_coords(PLAYER::PLAYER_PED_ID());
		float	heading	= ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
				r.x		+= dist * sin(util::deg_to_rad(heading)) * -1,
				r.y		+= dist * cos(util::deg_to_rad(heading));
		return r;
	}

	v3 get_coords_above_player(float dist)
	{
		v3 r	= get_entity_coords(PLAYER::PLAYER_PED_ID());
				r.z	+= dist;
		return r;
	}

	v3	get_coords_infront_of_cam(float dist)
	{
		return CAM::GET_GAMEPLAY_CAM_COORD() + (v3(CAM::GET_GAMEPLAY_CAM_ROT(0)).transformRotToDir() * dist);
	}

	v3	get_coords_infront_of_coords(v3 pos, v3 rot, float dist)
	{
		return pos + (rot.transformRotToDir() * dist);
	}

	v3 get_coords_above_coords(v3 pos, float dist)
	{
		pos.z	+= dist;
		return pos;
	}

	void set_radio_station(std::string station)
	{
		BYTE		stIdx	= (BYTE)AUDIO::GET_PLAYER_RADIO_STATION_INDEX();
		if(stIdx == 0xFF || (std::string) AUDIO::GET_RADIO_STATION_NAME(stIdx) != station)
			AUDIO::SET_RADIO_TO_STATION_NAME(&station[0]);
	}

	void	set_entity_invisible(Entity e, bool invis, bool local)
	{
		ENTITY::SET_ENTITY_VISIBLE(e, invis, false);
		if(local)
		{
			NETWORK::SET_LOCAL_PLAYER_VISIBLE_LOCALLY(true);
			NETWORK::SET_PLAYER_VISIBLE_LOCALLY(PLAYER::PLAYER_ID(), true);
		}
	}

	int super_run(float force, bool stop)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		if(CMenu::checkKeyState(CMenu::m_keyMap["SuperRun"]))
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(playerPed, 1, 0, force, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1);
			return 1;
		}
		else if(stop && !ENTITY::IS_ENTITY_IN_AIR(playerPed))
		{
			ENTITY::SET_ENTITY_VELOCITY(playerPed, 0.f, 0.f, 0.f);
			return 0;
		}
		return -1;
	}

	bool set_entity_gravity(Entity e, bool gravity)
	{
		ENTITY::SET_ENTITY_HAS_GRAVITY(e, gravity);
		if(ENTITY::IS_ENTITY_A_PED(e))
			PED::SET_PED_GRAVITY(e, gravity);
		else if(ENTITY::IS_ENTITY_A_VEHICLE(e))
			VEHICLE::SET_VEHICLE_GRAVITY(e, gravity);
		else
			return false;
		return true;
	}

	void chaos_mode(clock_t* tmr, int action)
	{
		Ped playerPed		= PLAYER::PLAYER_PED_ID();
		Entity	ent			= NULL;
		clock_t	delay		= 0x200;
		bool	driveable	= true;

		if(action == 0)	//bounce
			delay			= 0x400;
		if(action == 4)	//forcefield
		{
			clock_t	delay	= 0x60;
			driveable		= false;
		}
		if(action == 2)
			driveable		= false;

		if(clock() - *tmr > delay && CHack::m_nearbyPed.empty() && CHack::m_nearbyVehicle.empty())
		{
			script::update_nearby_ped(playerPed, 0x80);
			script::update_nearby_vehicle(playerPed, 0x80, driveable);
			*tmr = clock();
		}
		else if(!CHack::m_nearbyPed.empty())
		{
			ent	= CHack::m_nearbyPed[0];
			CHack::m_nearbyPed.erase(CHack::m_nearbyPed.begin());
		}
		else if(!CHack::m_nearbyVehicle.empty())
		{
			ent	= CHack::m_nearbyVehicle[0];
			CHack::m_nearbyVehicle.erase(CHack::m_nearbyVehicle.begin());
		}

		if(ent != NULL && ENTITY::IS_AN_ENTITY(ent))
		{
			v3 pos = get_entity_coords(ent);
			if(action == 0 && request_control_of_entity(ent))	//bounce
				ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, 0, 0, ENTITY::IS_ENTITY_A_PED(ent) ? 10.f : 5.f, 0, 0, 0, 0, 1, 1, 1, 0, 1);
			else if(action == 1 && request_control_of_entity(ent))	//ascention
				ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, 0.f, 0.f, 50.f, 0.f, 0.f, 0.f, 0, false, true, true, false, true);
			else if(action == 2 && request_control_of_entity(ent))	//armageddon
				ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, (float) util::random_int(-25, 25), (float) util::random_int(-25, 25), (float) util::random_int(-15, 15), (float) util::random_int(-10, 10), (float) util::random_int(-10, 10), (float) util::random_int(-10, 10), 0, 1, 1, 1, 0, 1); 
			else if(action == 3)	//mayhem
				FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 29, 1, false, false, 0);
			else if(action == 4 && request_control_of_entity(ent))	//forcefield
			{
				v3 playerPos		= get_entity_coords(PLAYER::PLAYER_PED_ID());
				v3 playerPos_pos	= pos - playerPos;
				float	x				= playerPos_pos.x < 0.f ? playerPos_pos.x * -1.f : playerPos_pos.x,
						y				= playerPos_pos.y < 0.f ? playerPos_pos.y * -1.f : playerPos_pos.y;
				float	ratio			= 50.f	/ (x > y ? x : y);
				ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, playerPos_pos.x * ratio, playerPos_pos.y * ratio, ENTITY::IS_ENTITY_A_PED(ent) ? 20.f : 5.f, (float) util::random_int(-5, 5), (float) util::random_int(-5, 5), (float) util::random_int(-5, 5), 0, false, true, true, false, true);
			}
			else if(action == 5 && request_control_of_entity(ent))	//gravity field
			{
				float v = 2.f;
				set_entity_gravity(ent, false);
				if(ENTITY::IS_ENTITY_A_PED(ent) && !PED::IS_PED_RAGDOLL(ent))
				{
					PED::SET_PED_TO_RAGDOLL(ent, 2000, 0, 2, false, false, false);
					v = 5.f;
				}
				v3 velocity	= ENTITY::GET_ENTITY_VELOCITY(ent);
				ENTITY::SET_ENTITY_VELOCITY(ent, velocity.x, velocity.y, v);
			}
			else if(action == 6 && request_control_of_entity(ent))	//smash
			{
				teleport_entity_to_coords(ent, {pos.x, pos.y, pos.z + 10.f}, false);
				if(ENTITY::IS_ENTITY_A_PED(ent))
					set_ped_health(ent, 0);
					//ENTITY::SET_ENTITY_HEALTH(ent, 0);
				else
					ENTITY::SET_ENTITY_ROTATION(ent, 0.f, 180.f, 0.f, 0, false);
				ENTITY::SET_ENTITY_VELOCITY(ent, 0.f, 0.f, -150.f);
			}
			else if(action == 7)	//massacre
			{
				if(ENTITY::IS_ENTITY_A_PED(ent))
					shoot_ped(ent);
				else if(ENTITY::IS_ENTITY_A_VEHICLE(ent))
					VEHICLE::SET_VEHICLE_UNDRIVEABLE(ent, true);
			}
		}
	}

	static std::vector<Vehicle>	smash_vehicle;
	bool	smash_vehicles(clock_t* tmr)
	{
		static int	i;
		Ped playerPed		= PLAYER::PLAYER_PED_ID();
		if(smash_vehicle.empty())
		{
			script::update_nearby_vehicle(playerPed, 0x80);
			smash_vehicle = CHack::m_nearbyVehicle;
			CHack::m_nearbyVehicle.clear();
			*tmr	= clock();
			i		= 0;
		}
		if(clock() - *tmr > 500 && i < smash_vehicle.size())
		{
			if(!request_control_of_entity(smash_vehicle[i]))
				return false;
			set_entity_gravity(smash_vehicle[i], false);
			ENTITY::SET_ENTITY_VELOCITY(smash_vehicle[i], 0.f, 0.f, 2.f);
			i++;
		}
		else if(clock() - *tmr > 5000 && !smash_vehicle.empty())
		{
			set_entity_gravity(smash_vehicle[0], true);
			ENTITY::SET_ENTITY_ROTATION(smash_vehicle[0], 0.f, 180.f, 0.f, 0, false);
			ENTITY::SET_ENTITY_VELOCITY(smash_vehicle[0], 0.f, 0.f, -150.f);
			smash_vehicle.erase(smash_vehicle.begin());
		}

		return smash_vehicle.empty();
	}

	bool	black_hole(int sec)
	{
		Ped		playerPed	= PLAYER::PLAYER_PED_ID();
		Entity	ent			= NULL;
		static Object	bh	= NULL;
		static clock_t	refreshTmr	= clock();
		static clock_t	bhTmr	= NULL;
		if(bh == NULL)
			if(!spawn_object("prop_alien_egg_01", &bh))
				return false;
			else
			{
				bhTmr	= clock();
				ENTITY::FREEZE_ENTITY_POSITION(bh, true);
			}
		if(clock() - refreshTmr > 0x100 && CHack::m_nearbyPed.empty() && CHack::m_nearbyVehicle.empty())
		{
			script::update_nearby_ped(playerPed, 0x80);
			script::update_nearby_vehicle(playerPed, 0x80, false);
			refreshTmr = clock();
		}
		else if(!CHack::m_nearbyPed.empty())
		{
			ent	= CHack::m_nearbyPed[CHack::m_nearbyPed.size() - 1];
			CHack::m_nearbyPed.pop_back();
		}
		else if(!CHack::m_nearbyVehicle.empty())
		{
			ent	= CHack::m_nearbyVehicle[CHack::m_nearbyVehicle.size() - 1];
			CHack::m_nearbyVehicle.pop_back();

		}

		if(ent != NULL && ENTITY::IS_AN_ENTITY(ent))
		{
			v3 pos		= get_entity_coords(ent);
			v3 bhPos	= get_entity_coords(bh);

			if(bhPos.getDist(pos) < 5.f)
				teleport_entity_to_coords(ent, { -3735.f, -4400.f, 10.f }, false);
			else
			{
				v3 pos_bhPos	= bhPos - pos;
				float	x				= pos_bhPos.x < 0.f ? pos_bhPos.x * -1.f : pos_bhPos.x,
						y				= pos_bhPos.y < 0.f ? pos_bhPos.y * -1.f : pos_bhPos.y;
				float	ratio			= 20.f	/ (x > y ? x : y);
				ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, pos_bhPos.x * ratio, pos_bhPos.y * ratio, ENTITY::IS_ENTITY_A_PED(ent) ? 1.f : .5f, (float) util::random_int(-2, 2), (float) util::random_int(-2, 2), (float) util::random_int(-2, 2), 0, false, true, true, false, true);
			}
		}

		if(clock() - bhTmr > sec * 1000)
		{
			CHack::m_entityCleanup.push_back(bh);
			bh	= NULL;
			return true;
		}
		return false;
	}

	void	drop_money_on_entity(Entity e, int amount, char* prop)
	{
		if(NETWORK::NETWORK_IS_SESSION_STARTED())
			return;
		v3 pos = get_entity_coords(e);
		Hash	modelHash = $(prop);
		STREAMING::REQUEST_MODEL(modelHash);
		if(!STREAMING::HAS_MODEL_LOADED(modelHash))
			return;
		Pickup pickup	= OBJECT::CREATE_AMBIENT_PICKUP($("PICKUP_MONEY_MED_BAG"), pos.x, pos.y, pos.z + 2.5f, 0, 40000, modelHash, 0, 1);
		ENTITY::SET_ENTITY_HAS_GRAVITY(pickup, true);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(modelHash);
	}

	void set_time(int h, int m)
	{
		if(h == -1)
			h = TIME::GET_CLOCK_HOURS();
		if(m == -1)
			m = TIME::GET_CLOCK_MINUTES();
		TIME::SET_CLOCK_TIME(h, m, 0);
		NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(h, m, 0);
	}

	void set_weather(char* w)
	{
		GAMEPLAY::CLEAR_OVERRIDE_WEATHER();
		GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST(w);
	}

	void draw_speedometer(Vehicle v, bool mph)
	{
		float	speed	= ENTITY::GET_ENTITY_SPEED(v) * 3.6f;
		if(mph)
			speed	= speed * .621f;
		draw_text(std::to_string((int) speed), .97f, .97f, 7, .5f, {255, 0, 0, 255});
	}

	static int		iFrames		= 0;
	static clock_t	clockFrames	= clock();
	float	get_fps()
	{
		static float iFps;
		iFrames++;
		clock_t dif = clock() - clockFrames;
		if(dif > 500)
		{
			iFps		= iFrames / (dif / 1000.f);
			iFrames		= 0;
			clockFrames	= clock();
		}
		return iFps;
	}

	void draw_fps()
	{
		std::string str = std::to_string(get_fps());
		while(str.size() > str.find(".") + 3)
			str.pop_back();
		draw_text(str, .005f, .005f, 7, .5f, { 0, 255, 0, 255});
	}

	void noclip(Entity e, int action, float speed, bool freeCam, bool restore)
	{
		if(!ENTITY::IS_ENTITY_A_PED(e) && !ENTITY::IS_ENTITY_A_VEHICLE(e))
			return;
		ENTITY::FREEZE_ENTITY_POSITION(e, !restore);
		ENTITY::SET_ENTITY_COLLISION(e, restore, restore);
		if(restore)
			return;
		float turnSpeed = speed > 5 ? 1.5f : ((speed / 10) + 1.f);

		if(!freeCam)
		{
			if(action & 0x01)	//forward
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), ENTITY::GET_ENTITY_ROTATION(e, 0), .25f * speed), false);
			if(action & 0x02)	//back
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), ENTITY::GET_ENTITY_ROTATION(e, 0), -.25f * speed), false);
			if(action & 0x04)	//left
				ENTITY::SET_ENTITY_HEADING(e, ENTITY::GET_ENTITY_HEADING(e) + 2.5f * turnSpeed);
			if(action & 0x08)	//right
				ENTITY::SET_ENTITY_HEADING(e, ENTITY::GET_ENTITY_HEADING(e) - 2.5f * turnSpeed);
		}
		else
		{
			v3	camRot	= CAM::GET_GAMEPLAY_CAM_ROT(0);
			ENTITY::SET_ENTITY_ROTATION(e, camRot.x, camRot.y, camRot.z, 0, false);
			if(action & 0x01)	//forward
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), camRot, .25f * speed), false);
			if(action & 0x02)	//back
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), camRot, -.25f * speed), false);
			if(action & 0x04)	//left
			{
				camRot = { 0.f, 0.f, camRot.z + 90.f };
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), camRot, .25f * speed), false);
			}
			if(action & 0x08)	//right
			{
				camRot = { 0.f, 0.f, camRot.z - 90.f };
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), camRot, .25f * speed), false);
			}
		}
		if(action & 0x10)	//up
			teleport_entity_to_coords(e, get_coords_above_coords(get_entity_coords(e), .2f * speed), false);
		if(action & 0x20)	//down
			teleport_entity_to_coords(e, get_coords_above_coords(get_entity_coords(e), -.2f * speed), false);
	}


	Entity	get_entity_crosshair()
	{
		Entity e	= NULL;
		Player player = PLAYER::PLAYER_ID();
		//if(PLAYER::IS_PLAYER_FREE_AIMING(player) && PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(player, &e) && ENTITY::DOES_ENTITY_EXIST(e))
		if(PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(player, &e) && ENTITY::DOES_ENTITY_EXIST(e))
		{
			if(ENTITY::IS_ENTITY_A_PED(e) && is_ped_in_any_vehicle(e))
			{
				Vehicle v = PED::GET_VEHICLE_PED_IS_IN(e, false);
				if(ENTITY::IS_ENTITY_A_VEHICLE(v))
					e = v;
			}
			return e;
		}
		return NULL;
	}

	/*
	action
		0x01	reset target
		0x02	lock target
		0x04	delete target
	*/

	/*
	flags
		0x01	display text type
		0x02	display text pos
		0x04	disable collision
		0x08	freeze entity
		0x10	throw mode
		0x20	relative rotation
		0x40	invisible
		0x80	rotation enable
	*/
	static Entity editor_locked_entity	= NULL;

	void	editor_reset_target(int flag = 0, float dist = 0.f)
	{
		if(editor_locked_entity	!= NULL && ENTITY::IS_AN_ENTITY(editor_locked_entity))
		{
			if(flag & 0x10)
			{
				v3 dir	= get_coords_infront_of_cam(dist + 100.f) - get_entity_coords(editor_locked_entity);
				ENTITY::FREEZE_ENTITY_POSITION(editor_locked_entity, false);
				ENTITY::APPLY_FORCE_TO_ENTITY(editor_locked_entity, 1, dir.x, dir.y, dir.z, 0.f, 0.f, 0.f, 0, false, true, true, false, true);
			}
			if(flag & 0x40)
				ENTITY::SET_ENTITY_VISIBLE(editor_locked_entity, false, false);
		}
		editor_locked_entity = NULL;
	}

	bool	entity_editor(int action, float dist, int flag, v3 rot, Entity ent)
	{
		if(action & 0x01 || (ent != NULL && editor_locked_entity != ent))
			editor_reset_target(flag, dist);

		if(ent != NULL && editor_locked_entity != ent)
			editor_locked_entity	= ent;
		Entity e		= editor_locked_entity == NULL ? NULL : editor_locked_entity;

		//find target
		if(e == NULL)
		{
			e	= get_entity_crosshair();

			if(action & 0x02)
				editor_locked_entity	= e;
		}	
		if(!ENTITY::DOES_ENTITY_EXIST(e))
		{
			editor_locked_entity	= NULL;
			return false;
		}

		//delete entity
		if(action & 0x04)
		{
			CHack::m_entityCleanup.push_back(e);	//push entity to the cleanup script
			editor_reset_target();
		}

		if(flag & 0x01)
		{
			std::string str	= "Entity";
			if(ENTITY::IS_ENTITY_A_PED(e))
				str	= "Ped";
			else if(ENTITY::IS_ENTITY_A_VEHICLE(e))
				str = "Vehicle";
			else if(ENTITY::IS_ENTITY_AN_OBJECT(e))
				str = "Object";

			CColor	color = { 255, 255, 255, 255 };
			if(editor_locked_entity != NULL)
				color = { 0, 255, 0, 255 };

			draw_text(str, .5f, .5f, 7, .5f, color);
		}

		if(flag & 0x02)
		{
			v3 pos		= get_entity_coords(e);
			std::string	str		= std::to_string(pos.x);
			str.append(", ");
			str.append(std::to_string(pos.y));
			str.append(", ");
			str.append(std::to_string(pos.y));
			draw_text(str, .5f, .525f, 0, .3f, { 255, 255, 255, 255 });
		}

		if(editor_locked_entity == NULL)	//not locked in yet, return
			return false;

		v3 coords		= get_coords_infront_of_cam(dist);

		request_control_of_entity(e);
		if(flag & 0x80)
		{
			if(flag & 0x20)
				rot.z += CAM::GET_GAMEPLAY_CAM_ROT(0).z;
			ENTITY::SET_ENTITY_ROTATION(e, rot.x, rot.y, rot.z, 0, false);
		}
		ENTITY::SET_ENTITY_VISIBLE(e, true, false);
		ENTITY::FREEZE_ENTITY_POSITION(e, (flag & 0x08));
		ENTITY::SET_ENTITY_COLLISION(e, !(flag & 0x04), true);
		teleport_entity_to_coords(e, coords, false);
		return true;
	}

	void ped_scenario(Ped p, char* anim, bool r)
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(p);
		if(!r)
			AI::TASK_START_SCENARIO_IN_PLACE(p, anim, 0, true);
	}

	bool send_assasins_after_player(Player p, Ped remotePed)
	{
		static std::unordered_map<int, int>	count;
		v3	pos			= get_entity_coords(remotePed);
		if(count.find(p) == count.end())
			count.emplace(p, 0);
		if(count[p] < 0xF)
		{
			Ped ped;
			spawn_ped(	"cs_chrisformage",
						PedTypeHuman,
						{pos.x + util::random_int(-20, 20), pos.y + util::random_int(-20, 20), pos.z},
						&ped,
						false,
						2);
			AI::TASK_COMBAT_PED(ped, remotePed, 0, 0);
			count[p]++;
			return false;
		}

		count.erase(count.find(p));
		return true;
	}

	void	shoot_ped(Ped ped, DWORD bone, bool owned)
	{
		v3 dir		= v3(ENTITY::GET_ENTITY_ROTATION(ped, 0)).transformRotToDir();
		v3 pos1		= PED::GET_PED_BONE_COORDS(ped, bone, 0.f, 0.f, 0.f) + dir;
		v3 pos2		= pos1 - (dir * 1.5f);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(pos1.x, pos1.y, pos1.z, pos2.x, pos2.y, pos2.z, 500, false, script::$(hash::weapon_hash[0x19]), owned ? PLAYER::PLAYER_PED_ID() : NULL, true, false, 200.f);
	}

	void	explode_ped(Ped ped, int type)
	{
		Vector3 remotePos = get_entity_coords(ped);
		FIRE::ADD_EXPLOSION(remotePos.x, remotePos.y, remotePos.z, type, 1, true, false, 0);
	}

	void	lester_offradar_toggle(bool b)
	{
		__int64*	ptr	= CHooking::getGlobalPtr(0x24F46C + (PLAYER::PLAYER_ID() * 358));
		if((b && !(*ptr & 1)) || (!b && *ptr & 1))
			*ptr ^= 1;
	}

	void	lester_offradar_add(int ms)
	{
		ULONGLONG	time	= NETWORK::GET_NETWORK_TIME(); //GetTickCount64(); //synced from host
		ULONGLONG*	ptr		= reinterpret_cast<ULONGLONG*>(CHooking::getGlobalPtr(0x2520AA));
		if(*ptr < time + (ms / 2))
			*ptr = time + ms;
	}

	void	spectate_player(Ped p, bool b)
	{
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(b, p);
	}

	void	ped_money_drop(Ped playerPed, clock_t* tmr)
	{
		v3 playerPos	= get_entity_coords(playerPed);

		if(clock() - *tmr > 0x60)
		{
			if(CHack::m_nearbyPed.empty())
				script::update_nearby_ped(PLAYER::PLAYER_PED_ID(), 0x80);
			else
			{
				if(CHack::m_nearbyPed[0] > 0 && ENTITY::DOES_ENTITY_EXIST(CHack::m_nearbyPed[0]))
				{
					if(!request_control_of_entity(CHack::m_nearbyPed[0]))
						return;
					CPed* cped = util::ped_handle_to_ptr(CHack::m_nearbyPed[0]);
					if(cped != nullptr && cped != CHack::m_pCPedPlayer && cped->fHealth > 100.f && cped->fHealth < 250)
					{
						cped->iCash = 2000;
						AI::CLEAR_PED_TASKS_IMMEDIATELY(CHack::m_nearbyPed[0]);
						teleport_entity_to_coords(CHack::m_nearbyPed[0], {playerPos.x, playerPos.y, playerPos.z + 2.5f}, false);
						cped->fHealth = 0;
					}
				}
				CHack::m_nearbyPed.erase(CHack::m_nearbyPed.begin());
				*tmr	= clock();
			}
		}

		if(CHooking::m_replayIntf->pickup_interface->number_of_pickups > 0)
		{
			int max	= CHooking::m_replayIntf->pickup_interface->max_pickups;
			for(int i = 0; i < max; ++i)
			{
				CPickup*	pickup	= CHooking::m_replayIntf->pickup_interface->get_pickup(i);
				if(pickup == nullptr || pickup->Navigation == nullptr || pickup->iMoney < 100)
					continue;
				pickup->Navigation->v3Pos	= playerPos;
				pickup->VisualPosition		= playerPos;
			}
		}
	}

	void	stealth_money(int mils, bool remove)
	{
		if(!NETWORK::NETWORK_IS_SESSION_STARTED())
			return;

		int	max		= remove ? 2000 : 90;
		int	loops	= 0;
		int	rest	= mils;
		if(mils > max)
		{
			loops	= mils / max;
			rest	= mils - (max * loops);
		}
		rest	*= 1000000;
		
		while(loops > 0 || rest > 0)
		{
			int	amount;
			if(rest > 0)
			{
				amount = rest;
				rest = 0;
			}
			else
			{
				amount	= 90000000;
				--loops;
			}
			Any transactionID	= INT_MAX;
			if(UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&transactionID, 1474183246, remove	? -1359375127 : 1982688246, remove ? 537254313 : 1445302971, amount, 4))
				UNK3::_NETWORK_SHOP_CHECKOUT_START(transactionID);
		}
	}

	bool	animate_player(Ped remotePed, char* dict, char* anim, bool freeze, bool restore)
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(remotePed);
		if(restore)
			return true;
		STREAMING::REQUEST_ANIM_DICT(dict);
		if(!STREAMING::HAS_ANIM_DICT_LOADED(dict))
			return false;
		v3	remotePos	= get_entity_coords(remotePed);
		int	scene		= NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(remotePos.x, remotePos.y, remotePos.z, 0, 0, 0, 2, 0, 1, 1, 0.f, freeze ? 0.f : 1.f);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(remotePed, scene, dict, anim, 8.f, 1.f, -1, 1, 1.f, 1);
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(scene);
		return true;
	}

	bool	animate_local_player(Ped playerPed, char* dict, char* anim, bool restore)
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
		if(restore)
			return true;
		STREAMING::REQUEST_ANIM_DICT(dict);
		if(!STREAMING::HAS_ANIM_DICT_LOADED(dict))
			return false;
		AI::TASK_PLAY_ANIM(playerPed, dict, anim, 8.f, 1.f, -1, 1, 1.f, 0, 0, 0);
		return true;
	}

	bool player_dead_clone(Player player, Ped p, bool erase)
	{
		static Ped		tar[0x20]	= { 0 };
		static Ped		ped[0x20]	= { 0 };
		static vec_int	clones[0x20];
		if(erase)
		{
			while(!clones[player].empty())
			{
				CHack::m_entityCleanup.push_back(clones[player][clones[player].size() - 1]);
				clones[player].pop_back();
			}
			return true;
		}
		if(!ped[player] || !tar[player])
		{
			tar[player] = p;
			ped[player]	= PED::CLONE_PED(tar[player], ENTITY::GET_ENTITY_HEADING(tar[player]), 1, 1);
			if(clones[player].size() > 8)
			{
				CHack::m_entityCleanup.push_back(clones[player][0]);
				clones[player].erase(clones[player].begin());
			}
			clones[player].push_back(ped[player]);
		}
		CPed*	cped	= util::ped_handle_to_ptr(ped[player]);
		v3		pos		= cped->v3VisualPos;
		teleport_entity_to_coords(ped[player], { pos.x, pos.y, pos.z + 2.f }, false);
		cped->fHealth	= 0.f;
		ped[player]		= 0;
		tar[player]		= 0;
		return true;
	}

	bool give_player_wanted_level(Player player, int reportCount)
	{
		static int		c[MAX_PLAYERS]	= { 0 };
		static clock_t	t[MAX_PLAYERS]	= { 0 };

		if(c[player] < reportCount)
		{
			if(clock() - t[player] > 0x400)
			{
				PLAYER::REPORT_CRIME(player, 14, PLAYER::GET_WANTED_LEVEL_THRESHOLD(5));
				++c[player];
				t[player]	= clock();
			}
			return false;
		}
		c[player]	= 0;
		return true;
	}

	bool clean_session()
	{
		static clock_t    tmr    = { 0 };
		if(!tmr)
		{
			ShellExecute(0, "open", "cmd.exe", "/C ipconfig -release", 0, SW_HIDE);
			tmr    = clock();
		}
		else if(clock() - tmr > 0x2000)
		{
			ShellExecute(0, "open", "cmd.exe", "/C ipconfig -renew", 0, SW_HIDE);
			tmr    = 0;
			return true;
		}
		return false;
	}
};