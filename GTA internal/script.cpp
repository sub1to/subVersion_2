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
		int offset = 0;

		if(seed)
			goto LABEL_SEEDED;

		srand((unsigned int) time(0));
		seed = true;

	LABEL_SEEDED:
		if(start >= 0)
			goto LABEL_RETURN;

		offset	= start;
		start	= 0;
		end		+= -offset;

	LABEL_RETURN:
		return (rand() % end + start) + offset;
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

	bool	world_to_screen(v3 pos, v2& out)
	{
		v3	tmp;

		float*		viewMatrix	= CHooking::m_viewPort->fViewMatrix;

		tmp.x	= (viewMatrix[1] * pos.x) + (viewMatrix[5] * pos.y) + (viewMatrix[9] * pos.z) + viewMatrix[13];		//row 2
		tmp.y	= (viewMatrix[2] * pos.x) + (viewMatrix[6] * pos.y) + (viewMatrix[10] * pos.z) + viewMatrix[14];	//row 3
		tmp.z	= (viewMatrix[3] * pos.x) + (viewMatrix[7] * pos.y) + (viewMatrix[11] * pos.z) + viewMatrix[15];	//row 4

		if(tmp.z < 0.001f)
			return false;

		tmp.z = 1.0f / tmp.z;

		tmp.x *= tmp.z;
		tmp.y *= tmp.z;

		uint32_t	w	= CHooking::m_resolution->w,
					h	= CHooking::m_resolution->h;

		out.x	= ((w / 2.f) + (.5f * tmp.x * w + 1.f)) / w;
		out.y	= ((h / 2.f) - (.5f * tmp.y * h + 1.f)) / h;

		if(out.x > 1.f || out.x < 0.f || out.y > 1.f || out.y < 0.f)
			return false;
		return true;
	}

	float	pixel_to_rel(uint32_t in, bool height)
	{
		return (float) (1.0 / (height ? CHooking::m_resolution->h : CHooking::m_resolution->w)) * in;
	}

	uint32_t	rel_to_pixel(float in, bool height)
	{
		return (uint32_t) ((height ? CHooking::m_resolution->h : CHooking::m_resolution->w) * in);
	}

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
}

namespace script
{
	constexpr uint32_t	GLOBALPTR_MP_VEH_BYPASS	= 0x184B0A;	//(int*)CHooking::getGlobalPtr(1591201 + (1 * (PLAYER::GET_PLAYER_INDEX() + 602)) + 258 + 13);
	constexpr uint32_t	GLOBALPTR_SP_VEH_BYPASS	= 0x2794B2;
	constexpr uint32_t	GLOBALPTR_OTR_TOGGLE	= 0x24F46C;	//2421664 + (1 + (PLAYER::PLAYER_ID() * 358)) + 203
	constexpr uint32_t	GLOBALPTR_OTR_TIME		= 0x2520AA;	//2433125 + 69
	static	Vector3		UPSIDE_DOWN				= { 0.f, 180.f, 0.f };

	bool is_ped_in_any_vehicle(Ped ped)
	{
		CPed* pPed	= util::handle_to_ptr<CPed>(ped);
		if(pPed == nullptr || !pPed->isInVehicle())
			return false;
		return true;
	}

	v3	get_entity_coords(Entity e)
	{
		CPed* pPed	= util::handle_to_ptr<CPed>(e);
		if(pPed == nullptr || pPed->pCNavigation == nullptr)
			return {};
		return pPed->pCNavigation->v3Pos;
	}

	float	get_ped_health(Ped ped)
	{
		CPed* pPed	= util::handle_to_ptr<CPed>(ped);
		if(pPed == nullptr)
			return {};
		return pPed->fHealth;
	}

	bool	set_ped_health(Ped ped, float value)
	{
		CPed* pPed	= util::handle_to_ptr<CPed>(ped);
		if(pPed == nullptr)
			return false;
		pPed->fHealth	= value;
		return true;
	}

	float	get_ped_max_health(Ped ped)
	{
		CPed* pPed	= util::handle_to_ptr<CPed>(ped);
		if(pPed == nullptr)
			return {};
		return pPed->fHealthMax;
	}

	float	get_ped_armor(Ped ped)
	{
		CPed* pPed	= util::handle_to_ptr<CPed>(ped);
		if(pPed == nullptr)
			return {};
		return pPed->fArmor;
	}

	float	get_vehicle_health(Vehicle veh)
	{
		CVehicle* pVeh	= util::handle_to_ptr<CVehicle>(veh);
		if(pVeh == nullptr)
			return {};
		return pVeh->fHealth;
	}

	bool is_player_ped_female(Ped ped)
	{
		return CHooking::get_entity_model(ped)	== 0x9C9EFFD8;
	}

	bool is_an_entity(Entity entity)
    {
		CPed*    pPed    = util::handle_to_ptr<CPed>(entity);
		return pPed != nullptr;
    }

	bool is_entity_a_ped(Entity entity)
	{
		CPed*    pPed    = util::handle_to_ptr<CPed>(entity);
        return pPed != nullptr && pPed->btEntityType == ENTITY_PED;
	}

	bool is_entity_a_vehicle(Entity entity)
	{
		CPed*    pPed    = util::handle_to_ptr<CPed>(entity);
        return pPed != nullptr && pPed->btEntityType == ENTITY_VEHICLE;
	}

	bool is_entity_an_object(Entity entity)
	{
		CPed*    pPed    = util::handle_to_ptr<CPed>(entity);
        return pPed != nullptr && pPed->btEntityType == ENTITY_OBJECT;
	}

	bool is_entity_dead(Entity ped)
    {
		bool	res = false;
        CPed*    pPed    = util::handle_to_ptr<CPed>(ped);
		if(pPed == nullptr)
			return true;
		if(pPed->btEntityType == ENTITY_VEHICLE)
		{
			CVehicle*	vehicle = (CVehicle*) pPed;
			if(vehicle->isVehicleDestroyed())
				res = true;
		}
		else
			res	= pPed->fHealth < .001f;
        return res;
    }

	bool is_ped_ragdoll(Ped ped)
	{
        CPed*    pPed    = util::handle_to_ptr<CPed>(ped);
		return pPed != nullptr && (pPed->btNoRagdoll & 0xF0) == 80;
	}

	bool is_entity_visible(Entity entity)
	{
        CPed*    pEntity    = util::handle_to_ptr<CPed>(entity);
		return pEntity != nullptr && pEntity->isInvisible();
	}

	int get_ped_drawable_variation(Ped ped, int group)
	{
		int res = -1;
		if (group > -1 && group < 13)
		{
			CPed* cped = util::handle_to_ptr<CPed>(ped);
			if (cped != nullptr && cped->pCPedStyle->propIndex[group] != 255)
				res = (int)cped->pCPedStyle->propIndex[group];
		}
		return -1;
	}

	int get_ped_texture_variation(Ped ped, int group)
	{
		int res = -1;
		if (group > -1 && group < 13)
		{
			CPed* cped = util::handle_to_ptr<CPed>(ped);
			if (cped != nullptr && cped->pCPedStyle->textureIndex[group] != 255)
				res = (int)cped->pCPedStyle->textureIndex[group];
		}
		return res;
	}

	int get_ped_palette_variation(Ped ped, int group)
	{
		int res = -1;
		if (group > -1 && group < 13)
		{
			CPed* cped = util::handle_to_ptr<CPed>(ped);
			if (cped != nullptr && cped->pCPedStyle->paletteIndex[group] != 255)
				res = (int)cped->pCPedStyle->paletteIndex[group];
		}
		return res;
	}

	void set_ped_can_switch_weapons(Ped ped, bool toggle)
	{
		CPed*	pPed	= util::handle_to_ptr<CPed>(ped);
		if(pPed == nullptr)
			return;
		pPed->btCanSwitchWeapons	= toggle;
	}

	void set_vehicle_stolen(Vehicle vehicle, bool toggle)
	{
		CVehicle*	pVeh	= util::handle_to_ptr<CVehicle>(vehicle);
		pVeh->set_stolen(toggle);
	}

	void set_vehicle_tire_smoke(Vehicle vehicle, int r, int g, int b)
	{
		CVehicle*	pVeh	= util::handle_to_ptr<CVehicle>(vehicle);
		if(pVeh == nullptr || pVeh->pCVehicleMods == nullptr)
			return;
		pVeh->pCVehicleMods->btTireSmoke	= 0;
		if(r != -1)
			pVeh->pCVehicleMods->btTireColorR	= r & 0xFF;
		if(g != -1)
			pVeh->pCVehicleMods->btTireColorG	= g & 0xFF;
		if(b != -1)
			pVeh->pCVehicleMods->btTireColorB	= b & 0xFF;
	}

	void apply_force_to_entity(Ped ped, int forceType, float x, float y, float z, float rx, float ry, float rz, bool isRel, bool highForce)
	{
		Vector3 dir	= { x, y, z };
		Vector3 rot	= { rx, ry, rz };
		CHooking::apply_force_to_entity(ped, forceType, &dir, &rot, 0, isRel, 1, highForce, 0, 1);
	}

	void add_explosion(Vector3 pos, int type, float damage, bool isAudible, bool isInvis, float shake)
	{
		CHooking::add_explosion(&pos, type, damage, isAudible, isInvis, shake, false);
	}

	void apply_clothing(Ped playerPed, int group, int var, int texture)
	{
		CPed* pPed = util::handle_to_ptr<CPed>(playerPed);
		CHooking::set_ped_component_variation(	playerPed,
												group,
												var == -1		? get_ped_drawable_variation(playerPed, group)	: var,
												texture == -1	? get_ped_texture_variation(playerPed, group)	: texture,
												get_ped_palette_variation(playerPed, group)	);
	}

	void	apply_outfit(eCustomOutfit type)
	{
		Ped		playerPed		= CPlayerMem::player_ped_id();
		bool	female			= is_player_ped_female(playerPed);
		const BYTE	(*outfit)[3];

		CHooking::clear_add_ped_props(playerPed);

		switch(type)
		{
			case OUTFIT_SANTA:
				outfit	= female ? hash::outfit_santa_female : hash::outfit_santa_male;
			break;
			case OUTFIT_TRASH_ORANGE:
				outfit	= female ? hash::outfit_trash_orange_female : hash::outfit_trash_orange_male;
			break;
			case OUTFIT_TRASH_GREEN:
				outfit	= female ? hash::outfit_trash_green_female : hash::outfit_trash_green_male;
			break;
			case OUTFIT_POLICE:
				outfit	= female ? hash::outfit_police_female : hash::outfit_police_male;
				CHooking::set_ped_prop_index(playerPed,	0,	female ? 45 : 46,	0,	1);
				CHooking::set_ped_prop_index(playerPed,	1,	female ? 11 : 13,	0,	1);
			break;
		}

		for(int i = 0; i < 10; ++i)
			apply_clothing(playerPed, outfit[i][0],	outfit[i][1], outfit[i][2]);
	}

	bool apply_model(Hash model, bool random)
	{
		if(!CHooking::is_model_in_cdimage(model) || !CHooking::is_model_valid)
			return true;

		CHooking::request_model(model);
		if(!CHooking::has_model_loaded(model))
			return false;

		Ped		playerPed = CPlayerMem::player_ped_id();
		Vehicle v	= NULL;
		if(CPlayerMem::is_player_in_any_vehicle(CPlayerMem::player_id()))
			v = CHooking::get_vehicle_ped_is_using(playerPed);

		CHooking::set_player_model(CPlayerMem::player_id(), model);
		
		//random ? PED::SET_PED_RANDOM_COMPONENT_VARIATION(playerPed, true) : PED::SET_PED_DEFAULT_COMPONENT_VARIATION(playerPed);

		if (v != NULL)
			CHooking::set_ped_into_vehicle(playerPed, v, get_free_seat(v));

		CHooking::set_model_as_no_longer_needed(model);

		return true;
	}

	bool is_ped_a_player(Ped ped)
	{
		CPed* pPed = util::handle_to_ptr<CPed>(ped);
		return pPed != nullptr && pPed->pCPlayerInfo != nullptr;
	}

	bool request_control_of_id(Entity netid)
	{
		if(!CHooking::network_has_control_of_network_id(netid))
			CHooking::network_request_control_of_network_id(netid);
		return true && CHooking::network_has_control_of_network_id(netid);
	}

	bool request_control_of_entity(Entity entity)
	{
		if(!CHooking::network_is_session_started())
			return true;
		if(is_entity_a_ped(entity) && is_ped_a_player(entity))
			return false;

		if(!CHooking::network_has_control_of_entity(entity))
			CHooking::network_request_control_of_entity(entity);

		int netID = CHooking::network_get_network_id_from_entity(entity);
		request_control_of_id(netID);
		CHooking::set_network_id_can_migrate(netID, true);
		return true && CHooking::network_has_control_of_entity(entity);
	}

	void update_nearby_ped(bool alive, queue_int* out)
	{
		Ped localPed	= CPlayerMem::player_ped_id();
		CPedInterface*	pedIF	= CHooking::m_replayIntf->pCPedInterface;
		int	numPed	= pedIF->iMaxPeds;
		for(int i = 0; i < numPed; ++i)
		{
			CPed* pPed = pedIF->get_ped(i);
			if(pPed == nullptr || (alive && pPed->fHealth < .001f))
				continue;
			Ped ped = CHooking::ptr_to_handle(pPed);
			if(ped == localPed)
				continue;
			out->push(ped);
		}
	}

	void update_nearby_vehicle(bool driveable, queue_int* out)
	{
		CVehicleInterface*	vehIF	= CHooking::m_replayIntf->pCVehicleInterface;
		int							numVeh	= vehIF->iMaxVehicles;
		for(int i = 0; i < numVeh; ++i)
		{
			CVehicle* pVeh = vehIF->get_vehicle(i);
			if(pVeh == nullptr || (driveable && pVeh->isVehicleDestroyed()))
				continue;
			Vehicle veh = CHooking::ptr_to_handle(pVeh);
			if(veh == CHack::m_lastVehicle)
				continue;
			out->push(veh);
		}
	}

	void teleport_entity_to_coords(Entity e, v3 pos, bool particleFX)
	{
		Vector3 tmp = pos;
		CHooking::set_entity_coords_no_offset(e, &tmp, 0, 0, 0);
	}

	void teleport_to_coords(v3 coords)
	{
		Entity e	= CPlayerMem::player_ped_id();
		if(CPlayerMem::is_player_in_any_vehicle(CPlayerMem::player_id()))
			e = CHooking::get_vehicle_ped_is_using(e);
		teleport_entity_to_coords(e, coords);
	}

	CBlip*	get_blip_waypoint()
	{
		CBlip* r = nullptr;
		for(int i = 0; i < 0x400; i++)
		{
			CBlip*	blip	= CHooking::m_blipList->m_Blips[i];
			if(	blip == nullptr
			||	blip->dwColor	!= ColorWaypoint
			||	blip->iIcon		!= SpriteWaypoint	)
				continue;

			r = blip;
			break;
		}
		return r;
	}

	bool teleport_to_waypoint()
	{
		static int	iHeight	= 0;
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

		constexpr float heightArray[] =
		{ 200.f, 150.f, 100.f, 50.f, 0.f, 250.f, 300.f, 350.f, 400.f, 450.f, 500.f, 550.f, 600.f, 650.f, 700.f, 750.f, 800.f };

		teleport_to_coords({pos.x, pos.y, heightArray[iHeight]});
		Vector3 tmp	= { pos.x, 0, pos.y, 0, heightArray[iHeight], 0 };
		if(!CHooking::get_ground_z_for_3d_coord(&tmp, &pos.z, 0, 0) && iHeight < sizeof(heightArray) / sizeof(*heightArray))
		{
			iHeight++;
			return false;
		}

		iHeight	= 0;
		pos.z	+= 2.5f;
		teleport_to_coords(pos);
		pos		= {};
		return true;
	}

	CBlip*	get_blip_objective()
	{
		CBlip*	r = nullptr;
		for(int i = 0; i < 0x400; i++)
		{
			CBlip*	blip	= CHooking::m_blipList->m_Blips[i];
			if
			(
				blip == nullptr
			||	(
					(blip->dwColor	!= ColorYellowMission	|| blip->iIcon != SpriteStandard)
				&&	(blip->dwColor	!= ColorYellow			|| blip->iIcon != SpriteStandard)
				&&	(blip->dwColor	!= ColorWhite			|| blip->iIcon != SpriteRaceFinish)
				&&	(blip->dwColor	!= ColorGreen			|| blip->iIcon != SpriteStandard)
				&&	(blip->iIcon	!= SpriteCrateDrop)
				)
			)
				continue;

			r = blip;
			break;
		}
		return r;
	}

	void teleport_to_objective()
	{
		CBlip* blip = get_blip_objective();
		blip == nullptr ? notify_above_map("Objective not found.", 0) : teleport_to_coords({ blip->v3Pos.x, blip->v3Pos.y, blip->v3Pos.z + 1.f });
	}

	CBlip*	get_blip_vehicle()
	{
		CBlip*	r = nullptr;
		for(int i = 0; i < 0x400; i++)
		{
			CBlip*	blip	= CHooking::m_blipList->m_Blips[i];
			if
			(	
				blip == nullptr
			||	(
					blip->dwColor != ColorVehicle
				&&	blip->iIcon != SpritePersonalVehicleCar
				&&	blip->iIcon != SpritePersonalVehicleBike
				)
			)
				continue;

			r = blip;
			break;
		}
		return r;
	}

	void teleport_to_personal_vehicle()
	{
		CBlip* blip = get_blip_vehicle();
		blip == nullptr ? notify_above_map("Personal vehicle not found.", 0) : teleport_to_coords({ blip->v3Pos.x, blip->v3Pos.y, blip->v3Pos.z + 1.f });
	}

	void teleport_to_entity(Entity e)
	{
		v3 remotePos = get_entity_coords(e);
		remotePos.z += 2.5f;
		teleport_to_coords(remotePos);
	}

	bool teleport_player_to_me(Player player)
	{
		static int	count[MAX_PLAYERS]	= { 0 };
		v3	playerPos	= script::get_coords_infront_player(6.f);
		v3	remotePos	= CPlayerMem::get_player_coords(player);
		Ped	ped			= CPlayerMem::get_player_ped(player);
		playerPos.z += 1.f;
		++count[player];
		if(playerPos.getDist(remotePos) < 5.f || count[player] > 0x40)
		{
			count[player]	= 0;
			return true;
		}
		script::teleport_player_on_foot(ped, playerPos.x, playerPos.y, playerPos.z);
		return false;
	}

	bool teleport_player_to_sea(Player player)
	{
		static int	count[MAX_PLAYERS]	= { 0 };
		static v3	seaPos				= { -3735.f, -4400.f, 10.f };
		v3			remotePos			= CPlayerMem::get_player_coords(player);
		Ped			ped					= CPlayerMem::get_player_ped(player);
		++count[player];
		if(seaPos.getDist(remotePos) < 5.f || count[player] > 0x40)
		{
			count[player]	= 0;
			return true;
		}
		teleport_player_on_foot(ped, seaPos.x, seaPos.y, seaPos.z);
		return false;
	}

	void teleport_player_to_air(Player player)
	{
		Ped	ped			= CPlayerMem::get_player_ped(player);
		v3 remotePos	= CPlayerMem::get_player_coords(player);
		ped_weapon(ped, 0xfbab5776, false); //GADGET_PARACHUTE
		teleport_player_on_foot(ped, remotePos.x, remotePos.y, remotePos.z + 200.f);
	}

	void notify_above_map(std::string msg, bool blink)
	{
		CHooking::m_textInfo->btTextOutline	= 1;
		CHooking::set_notification_text_entry("STRING");
		CHooking::add_text_comp_substr_playername(&msg[0u]);
		CHooking::draw_notification(blink, false, false);
	}

	void	show_ingame_keyboard(char* title, char* default_text)
	{
		CHooking::display_onscreen_keyboard(true, (title == nullptr ? "subVersion" : title), "", (default_text == nullptr ? "" : default_text), "", "", "", 64);
	}

	bool	get_ingame_keyboard_result(std::string& str)
	{
		str		= "!!INVALID!!";
		bool r	= !!CHooking::update_onscreen_keyboard();
		if(r)
			str = CHooking::m_onscreenKeyboardResult;
		return r;
	}

	bool	ingame_keyboard(std::string& out, eKeyboardOwner owner, bool reset)
	{
		static bool				active		= false;
		static eKeyboardOwner	curOwner	= KBOWNER_NONE;
		if(reset)
		{
			script::show_ingame_keyboard("License");
			curOwner = owner;
			active = true;
		}
		if(curOwner != owner)
			return true;
		if(active && curOwner != KBOWNER_NONE)
		{
			std::string str;
			script::get_ingame_keyboard_result(str);
			if(str != "!!INVALID!!" && str != "")
			{
				out = str;
				curOwner	= KBOWNER_NONE;
				active = false;
			}
		}
		return !active;
	}

	void draw_text(char* text, float x, float y, int font, float scale, CColor color, bool centered)
	{
		CHooking::m_textInfo->iFont	= font;
		CHooking::m_textInfo->btTextOutline	= 0;
		CHooking::m_textInfo->setScale(scale);
		CHooking::m_textInfo->setColor(color);
		CHooking::m_textInfo->fTextWrapStart	= 0.f;
		CHooking::m_textInfo->fTextWrapEnd		= 1.f;
		CHooking::m_textInfo->wNotCentered	= !centered;
		CHooking::m_textInfo->btDropShadow	= 2;
		CHooking::begin_text_cmd_display_text("STRING");
		CHooking::add_text_comp_substr_playername(text);
		CHooking::end_text_cmd_display_text(x, y, 0);
	}

	/*
		flag
		0x01	ESP_BOX			box
		0x02	ESP_HEALTHBAR	healthbar
		0x04	ESP_TEXT_DIST	dist text
		0x08	ESP_TEXT_HEALTH	health text
		0x10	ESP_TEXT_GOD	god text
	*/
	void draw_esp_on_player(Player player, char* text, int flag, float fDrawDist)
	{
		constexpr float	maxDist		= 500.f;
		v3				pos			= CPlayerMem::get_player_coords(player);
		v3				playerPos	= CPlayerMem::get_player_coords(CPlayerMem::player_id());
		float			dist		= pos.getDist(playerPos);
		bool			isClose		= dist < maxDist;
		v2				screen[2];
		bool			onScreen	= false;

		if(dist > fDrawDist)
			return;

		//set esp color
		int		team		= CPlayerMem::get_player_team(player);
		CColor	color		= { 255, 0, 0, 255 };
		CColor	colorHealth	= { 0, 255, 0, 255 };
		CColor	colorText	= { 255, 255, 255, 255 };
		int		localTeam	= CPlayerMem::get_player_team(CPlayerMem::player_id());
		if(localTeam != -1 && localTeam == team)
		{
			color		= colorHealth;
			colorHealth	= { 255, 0, 0, 255 };
		}
		else if(!isClose)
			color		= { 255, 150, 0, 255 };

		onScreen |= util::world_to_screen({pos.x, pos.y, pos.z - 1}, screen[0]);
		onScreen |= util::world_to_screen({pos.x, pos.y, pos.z + .8f}, screen[1]);
		if(!onScreen)
			goto LABEL_NOT_ON_SCREEN;

		//calculate esp size
		float	wBox, hBox, wBoxHalf, hBoxHalf;		//box size
		hBox		= screen[0].y - screen[1].y;
		if(hBox < 0.f)
			hBox	*= -1.f;
		wBox		= hBox / 4;
		wBoxHalf	= wBox / 2;
		hBoxHalf	= hBox / 2;

		float ratio			= (dist > maxDist ? maxDist : dist) / maxDist;
		float distScale		= .05f * ratio;
		float textScale[2]	=
		{
			0.25f - distScale,
			0.2f - distScale,
		};
		float textSpacingScale		= 0.01f - (.001f * ratio);

		//init player info
		float maxHealth	= CPlayerMem::get_player_max_health(player);
		float health	= CPlayerMem::get_player_health(player);
		float armour	= CPlayerMem::get_player_armour(player);

		//draw text
		draw_text(text, screen[1].x - wBoxHalf, screen[1].y - 0.02f, 0, textScale[0], color);

		char	msg[0xFF];
		float	textY	= screen[1].y - 0.006f,				//height of the text
				textX	= screen[1].x + wBoxHalf + 0.0025f;
		if(flag & ESP_TEXT_DIST)
		{
			sprintf_s(msg, "Dist: %i", (int) dist);
			draw_text(msg, textX, textY, 0, textScale[1], colorText);
			textY	+= textSpacingScale;
		}
		if(flag & ESP_TEXT_HEALTH)
		{
			sprintf_s(msg, "Health: %i/%i", (int) health, (int) maxHealth);
			draw_text(msg, textX, textY, 0, textScale[1], colorText);
			textY	+= textSpacingScale;
			sprintf_s(msg, "Armor: %i/50", (int) armour);
			draw_text(msg, textX, textY, 0, textScale[1], colorText);
			textY	+= textSpacingScale;
		}
		if(flag & ESP_TEXT_GOD)
		{
			sprintf_s(msg, "God: %s", CPlayerMem::is_player_god(player) ? "Yes" : "No");
			draw_text(msg, textX, textY, 0, textScale[1], colorText);
			textY	+= textSpacingScale;
		}

		//draw boxes
		if(isClose)		// more than 500 distance, the boxes are too small
		{
			if(flag & ESP_BOX)
			{
					
				CHooking::draw_rect(screen[1].x, screen[1].y, wBox, util::pixel_to_rel(1, true), color.r, color.g, color.b, color.a);		//top
				CHooking::draw_rect(screen[1].x, screen[0].y, wBox, util::pixel_to_rel(1, true), color.r, color.g, color.b, color.a);		//bottom
				CHooking::draw_rect(screen[1].x - wBoxHalf, screen[1].y + hBoxHalf, util::pixel_to_rel(1, false), hBox, color.r, color.g, color.b, color.a);		//left
				CHooking::draw_rect(screen[1].x + wBoxHalf, screen[1].y + hBoxHalf, util::pixel_to_rel(1, false), hBox, color.r, color.g, color.b, color.a);		//right
			}

			if(flag & ESP_HEALTHBAR)
			{
				float barMax	= maxHealth + 50.f;
				float bar		= health + armour;
				CHooking::draw_rect(screen[1].x - wBoxHalf - util::pixel_to_rel(12, false),  screen[1].y + hBoxHalf, util::pixel_to_rel(10, false), hBox, color.r, color.g, color.b, color.a);
				CHooking::draw_rect(screen[1].x - wBoxHalf - util::pixel_to_rel(12, false),  screen[1].y + hBoxHalf + (hBox * (1 - (bar / barMax)) / 2), util::pixel_to_rel(6, false), hBox * (bar / barMax) - util::pixel_to_rel(4, true), colorHealth.r, colorHealth.g, colorHealth.b, colorHealth.a);
			}
		}

	LABEL_NOT_ON_SCREEN:

		//draw world line
		if(flag & ESP_WORLD_LINE)
		{
			Vector3	tmp		= { pos.x, pos.y, pos.z - 1.f };
			Vector3 tmp2	= { playerPos.x, playerPos.y, playerPos.z };
			CHooking::draw_line(&tmp, &tmp2, color.r, color.g, color.b, color.a);
		}
	}

	/*
	flag
		0	PEDSPAWN_NORMAL		normal ped
		1	PEDSPAWN_BODYGUARD	bodyguard
		2	PEDSPAWN_ARMY		army
	*/
	bool spawn_ped(Hash model, ePedType pedType, v3 pos, Ped* pedOut, bool random, int flag)
	{
		if(!CHooking::is_model_in_cdimage(model) || !CHooking::is_model_valid(model))
			return true;
		CHooking::request_model(model);
		if(!CHooking::has_model_loaded(model))
			return false;

		if(pos.empty())
			pos	= get_coords_infront_player(6.f);
		pos.x += util::random_int(-2, 2);
		pos.y += util::random_int(-2, 2);

		Vector3 tmpV3	= pos;

		Ped		ped	= CHooking::create_ped(pedType, model, &tmpV3, 0.f, true, false);
		random ? CHooking::set_ped_random_component_variation(ped) : CHooking::set_ped_default_component_variation(ped);

		if(pedOut != nullptr)
			*pedOut = ped;

		if(flag != PEDSPAWN_NORMAL)
		{
			if(flag == PEDSPAWN_BODYGUARD)
			{
				int grp		= CHooking::get_player_group(CPlayerMem::player_id());
				CHooking::set_ped_as_group_member(ped, grp);
				CHooking::set_ped_never_leaves_group(ped, true);
				CHooking::set_group_formation(grp, FormationIndexCircle);
			}
			if(flag == PEDSPAWN_ARMY)
			{
				CHooking::set_ped_relationship_group_hash(ped, 0xe3d976f3);	//"army"
				CHooking::ai_task_wander_standard(ped, 10.f, true);
			}
			set_ped_can_switch_weapons(ped, false);
			CHooking::give_delayed_weapon_to_ped(ped, 0x22d8fe39, 9999, 0);	//WEAPON_APPISTOL
			CHooking::set_ped_combat_ability(util::handle_to_ptr<CPed>(ped), 3); //0 poor, 1 average, 2 prof

			CHack::m_pedCleanup.push_back(ped);
		}
		else
			CHooking::set_entity_as_no_longer_needed(&ped);

		CHooking::set_model_as_no_longer_needed(model);
		return true;
	}

	/*
		flags
			1 << 0	VEHSPAWN_WARP		warp
			1 << 1	VEHSPAWN_MP_BYPASS	mp bitset bypass
			1 << 2	VEHSPAWN_UPGRADE	upgrade
			1 << 3	VEHSPAWN_LICENSE	license
	*/
	bool spawn_vehicle(Hash model, Vehicle* vehOut, BYTE flags, int64_t colours)//bool warp, bool bypass, bool upgrade)
	{
		Vector3		pos	= get_coords_infront_player(6.f);
		Ped		playerPed	= CPlayerMem::player_ped_id();
	
		if(!CHooking::is_model_in_cdimage(model) || !CHooking::is_model_a_vehicle(model))
			return true;
		CHooking::request_model(model);
		if(!CHooking::has_model_loaded(model))
			return false;

		bool	bFly	= (flags & VEHSPAWN_WARP) && (CHooking::is_model_a_heli(model) || CHooking::is_model_a_plane(model)) ? true : false;
		if(bFly)
			pos.z += 100.f;
		pos.z += 1.f;
		float heading = CHooking::get_entity_heading(playerPed);

		Vehicle	veh	= CHooking::create_vehicle(model, &pos, heading, true, false);
		CVehicle* pVeh = util::handle_to_ptr<CVehicle>(veh);
		if(pVeh == nullptr)
			return false;
		CHooking::set_vehicle_engine_on(veh, true, true, true);
		pVeh->set_stolen(false);
		CHooking::set_model_as_no_longer_needed(model);

		if(bFly)
		{
			CHooking::set_vehicle_forward_speed(pVeh, 100.0f);
			CHooking::set_heli_blades_full_speed(veh, 1.f);
		}
		else
			CHooking::set_vehicle_on_ground_properly(veh, 0);
		if(flags & VEHSPAWN_WARP)
			CHooking::set_ped_into_vehicle(playerPed, veh, -1);
		if(flags & VEHSPAWN_LICENSE)
			CHooking::set_vehicle_number_plate_text(veh, "YO MOMMA");
		if(vehOut != nullptr)
			*vehOut = veh;
		if(flags & VEHSPAWN_UPGRADE)
			upgrade_car(veh, CHooking::is_model_a_car(model) != 0, colours);
		else if(flags & VEHSPAWN_MP_BYPASS)
			vehicle_bypass(veh);	//mp bypass

		return true;
	}

	void vehicle_bypass(Vehicle v)
	{
		CHooking::decor_set_int(v, "MPBitset", (1 << 10));
	}

	void vehicle_mp_bypass(bool b)
	{
		if(b)
			*(int*)	CHooking::getGlobalPtr(GLOBALPTR_MP_VEH_BYPASS + CHooking::player_id())	|= (1 << 3);
		else
			*(int*)	CHooking::getGlobalPtr(GLOBALPTR_MP_VEH_BYPASS + CHooking::player_id())	&= ~(1 << 3);
	}

	void vehicle_sp_bypass(bool b)
	{
		*CHooking::getGlobalPtr(GLOBALPTR_SP_VEH_BYPASS) = b;
	}

	bool	upgrade_car(Vehicle v, bool wheels, int64_t colours)
	{
		if(!request_control_of_entity(v))
			return false;

		vehicle_bypass(v);

		CVehicle* pVeh	= util::handle_to_ptr<CVehicle>(v);
		CHooking::set_vehicle_mod_kit(v, 0);
		CHooking::set_vehicle_number_plate_index(pVeh, PLATE_YELLOWONBLACK);
		if(wheels)
			CHooking::set_vehicle_wheel_type(v, WHEEL_TYPE_HIGHEND);
		CHooking::toggle_vehicle_mod(v, MOD_TURBO, 1);
		CHooking::toggle_vehicle_mod(v, MOD_XENONLIGHTS, 1);
		CHooking::set_vehicle_mod(v, 0, CHooking::get_num_vehicle_mod(v, 0) - 2, false);		//biggest spoiler = ugly
		if(pVeh->pCVehicleMods != nullptr)
			pVeh->pCVehicleMods->btWindowTint	= (BYTE) 1;
		if(colours != -1)
			set_vehicle_color(v, colours & 0xFF, (colours >> 0x08) & 0xFF, (colours >> 0x10) & 0xFF, (colours >> 0x18) & 0xFF);
		for(int i = 1; i < 0x30; ++i)
		{
			if(i > 22 && i < 25)
			{
				if(wheels)
					CHooking::set_vehicle_mod(v, i, WHEEL_HIGHEND_CARBONSHADOW, false);	//WHEEL_HIGHEND_CARBONSHADOW
				continue;
			}
			CHooking::set_vehicle_mod(v, i, CHooking::get_num_vehicle_mod(v, i) - 1, false);
		}
		return true;
	}

	bool	set_vehicle_color(Vehicle v, int p, int s, int pearl, int wheel)
	{
		CVehicle*	pVeh	= util::handle_to_ptr<CVehicle>(v);
		if(pVeh == nullptr || pVeh->pCVehicleMods == nullptr)
			return false;
		if(p != -1)
			pVeh->pCVehicleMods->btPrimary		= (BYTE) p;
		if(s != -1)
			pVeh->pCVehicleMods->btSecondary	= (BYTE) s;
		if(pearl != -1)
			pVeh->pCVehicleMods->btPearlescent	= (BYTE) pearl;
		if(wheel != -1)
			pVeh->pCVehicleMods->btWheelColor	= (BYTE) wheel;

		CHooking::apply_vehicle_colors(pVeh, true);
		return true;
	}

	bool spawn_object(Hash model, Object* objOut)
	{
		v3		pos	= get_coords_infront_player(10.f);
		Ped		playerPed	= CPlayerMem::player_ped_id();
	
		if(!CHooking::is_model_in_cdimage(model))
			return true;
		CHooking::request_model(model);
		if(!CHooking::has_model_loaded(model))
			return false;
		Object	obj;
		CHooking::create_object(model, pos.x, pos.y, pos.z, true, 1, -1, &obj, true, false, false);

		CHooking::set_model_as_no_longer_needed(model);

		if(objOut != nullptr)
			*objOut = obj;
		return true;
	}

	bool ped_give_all_weapons(Ped p, Player player)
	{
		static int	count[MAX_PLAYERS]	= { 0 };
		if(player == -1)
			goto LABEL_GIVE_ALL_NOW;

		if(count[player] >= get_array_size(hash::weapon_hash))
			goto LABEL_END;

		CHooking::give_delayed_weapon_to_ped(p, hash::weapon_hash[count[player]], 9999, 0);
		++count[player];
		return false;

	LABEL_END:
		 count[player]	= 0;
		 return true;

	LABEL_GIVE_ALL_NOW:
		for(int i = 0; i < get_array_size(hash::weapon_hash); i++)
			CHooking::give_delayed_weapon_to_ped(p, hash::weapon_hash[i], 9999, 0);
		return true;
	}

	bool ped_weapon(Ped p, DWORD weapon, bool give)
	{
		if(weapon == 0)
		{
			if(give)
				script::ped_give_all_weapons(p);
			else
				CHooking::remove_all_ped_weapons(p);
		}
		else
		{
			if(give)
				CHooking::give_delayed_weapon_to_ped(p, weapon, 9999, 0);
			else
				CHooking::remove_weapon_from_ped(p, weapon);
		}
		return true;
	}

	void	no_reload_toggle(bool toggle)
	{
		static threeBytes	restore	= { 0 };
		CHooking::nop_bytes(CHooking::m_noReload, restore, toggle);
	}
	void	infinite_ammo_toggle(bool toggle)
	{
		static threeBytes	restore	= { 0 };
		CHooking::nop_bytes(CHooking::m_infAmmo, restore, toggle);
	}

	void	explosive_ammo(int explosionType)
	{
		v3 pos	= {};
		if(CHooking::get_ped_last_weapon_impact(CPlayerMem::player_ped_id(), &pos))
			add_explosion(pos, explosionType, 1.f, true, false, 0.f);
	}

	void get_in_closest_car()
	{
		Ped playerPed	= CPlayerMem::player_ped_id();
		v3 pos			= CPlayerMem::get_player_coords(CPlayerMem::player_id());
		update_nearby_vehicle(true);
		Vehicle veh = CHack::m_nearbyVehicle.front();
		if(get_free_seat(veh) != -1)
		{
			Ped pDriver = CHooking::get_ped_in_vehicle_seat(veh, -1);
			CHooking::clear_ped_tasks_immediately(pDriver);
		}
		CHooking::set_ped_into_vehicle(CPlayerMem::player_ped_id(), veh, -1);
		util::clear_queue(CHack::m_nearbyVehicle);
	}

	Ped clone_ped_bodyguard(Ped p)
	{
		int group = CHooking::get_ped_group_index(p);
		Ped	ped = CHooking::clone_ped(p, CHooking::get_entity_heading(p), 1, 1);
		CHooking::set_ped_as_group_member(ped, group);
		set_ped_can_switch_weapons(ped, false);
		CHooking::give_delayed_weapon_to_ped(ped, 0x22d8fe39, 9999, 0);	//$("WEAPON_APPISTOL")
		CHooking::set_ped_combat_ability(util::handle_to_ptr<CPed>(ped), 2); //0 poor, 1 average, 2 prof
		return ped;
	}

	void fix_vehicle(Vehicle v)
	{
		CVehicle* pVeh = util::handle_to_ptr<CVehicle>(v);
		pVeh->fDirtLevel	= 0.f;
		CHooking::set_vehicle_fixed(v);
		CHooking::set_vehicle_deformation_fixed(util::handle_to_ptr<CVehicle>(v));
		CHooking::set_vehicle_undriveable(v, false);

	}

	void clean_ped(Ped p)
	{
		CHooking::clear_ped_blood_damage(util::handle_to_ptr<CPed>(p));
		CHooking::clear_ped_wetness(p);
	}

	int get_free_seat(Vehicle v)
	{
		CVehicle*	pVeh	= util::handle_to_ptr<CVehicle>(v);
		if(pVeh == nullptr)
			goto LABEL_FAILED;

		int n = pVeh->btMaxPassengers;
		for(int i = -1; i < n; i++)	// 0 = first passenger seat
			if(CHooking::is_vehicle_seat_free(v, i, false))
				return i;

	LABEL_FAILED:
		return -2;
	}

	void teleport_to_ped_car(Ped ped) 
	{
		if(!is_ped_in_any_vehicle(ped))
			return;
		Vehicle v	= CHooking::get_vehicle_ped_is_using(ped);
		int		s	= get_free_seat(v);
		if(s > -1)
			CHooking::set_ped_into_vehicle(CPlayerMem::player_ped_id(), v, s);
	}

	void attach_entities(Entity e, Entity t, int bone, Vector3 pos, Vector3 rot)
	{
		if(bone != -1 && pos.y == -.26f)
			pos.y = 0.f;
		bone == -1 ? bone = 0 : bone = CHooking::get_ped_bone_index(e, bone);
		v3		pos2	= get_coords_infront_player(6.f);
		Object	obj;
		Vector3 empty	= { 0 };
		CHooking::create_object(0xe6cb661e, pos2.x, pos2.y, pos2.z, true, 1, -1, &obj, true, false, false);	//$("prop_cs_dildo_01")
		CHooking::attach_entity_to_entity(e, obj, 0, &pos, &rot, false, false, false, true, 2, true, false);
		CHooking::attach_entity_to_entity(obj, t, bone, &empty, &empty, false, false, false, true, 2, true, false);
		return;
	}

	void detach_entity(Entity e)
	{
		Object obj = CHooking::get_entity_attached_to(e);
		CHooking::detach_entity(e, false, true);
		if(is_entity_a_ped(e))
			CHooking::clear_ped_tasks_immediately(e);
		if(!is_entity_an_object(obj))
			return;
		CHack::m_entityCleanup.push(obj);
		return;
	}

	/*Object attach_object_to_entity(Entity e, char* object, int bone)
	{
		bone == -1 ? bone = 0 : bone = PED::GET_PED_BONE_INDEX(e, bone);
		v3 pos	= get_coords_infront_player(6.f);
		Object obj	= OBJECT::CREATE_OBJECT($(object), pos.x, pos.y, pos.z, true, false, false);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(obj, e, bone, 0.f, bone != 0 ? 0.f : -.25f, 0.f, 0.f, bone != 0 ? 90.f : 0.f, 0.f, false, false, false, true, 2, true);
		return obj;
	}*/

	Object trap_player_in_cage(Player player)
	{
		Ped		ped			= CPlayerMem::get_player_ped(player);
		v3		remotePos	= CPlayerMem::get_player_coords(player);
		Object	obj;
		CHooking::create_object(0x392d62aa, remotePos.x, remotePos.y, remotePos.z, true, 1, -1, &obj, true, false, false);
		//Object obj	= OBJECT::CREATE_OBJECT(0x392d62aa, remotePos.x, remotePos.y, remotePos.z -1.f, true, false, false);	//$("prop_gold_cont_01")
		return obj;
	}

	/*void clear_badsports()
	{
		return;
		CHooking::stat_set_int(util::$("MPPLY_GRIEFING"), 0, 1);
		CHooking::stat_set_int(util::$("MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
		CHooking::stat_set_int(util::$("MPPLY_OFFENSIVE_TAGPLATE"), 0, 1);
		CHooking::stat_set_int(util::$("MPPLY_OFFENSIVE_UGC"), 0, 1);
		CHooking::stat_set_int(util::$("MPPLY_BAD_CREW_NAME"), 0, 1);
		CHooking::stat_set_int(util::$("MPPLY_BAD_CREW_MOTTO"), 0, 1);
		CHooking::stat_set_int(util::$("MPPLY_BAD_CREW_STATUS"), 0, 1);
		CHooking::stat_set_int(util::$("MPPLY_BAD_CREW_EMBLEM"), 0, 1);
		CHooking::stat_set_int(util::$("MPPLY_GAME_EXPLOITS"), 0, 1);
		CHooking::stat_set_int(util::$("MPPLY_EXPLOITS"), 0, 1);
		CHooking::stat_set_int(util::$("MPPLY_ISPUNISHED"), 0, 1);

		CHooking::stat_set_int(util::$("MP0_CHEAT_BITSET"), 0, TRUE);
		CHooking::stat_set_int(util::$("MP0_BAD_SPORT_BITSET"), 0, TRUE);
		CHooking::stat_set_bool(util::$("MPPLY_IS_HIGH_EARNER"), FALSE, TRUE);
		CHooking::stat_set_bool(util::$("MPPLY_IS_CHEATER"), FALSE, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_IS_CHEATER_TIME"), 0, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_WAS_I_BAD_SPORT"), 0, TRUE);
		CHooking::stat_set_float(util::$("MPPLY_OVERALL_BADSPORT"), 0, TRUE);
		CHooking::stat_set_float(util::$("MPPLY_OVERALL_CHEAT"), 0, TRUE);
		CHooking::stat_set_bool(util::$("MPPLY_CHAR_IS_BADSPORT"), FALSE, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_BECAME_BADSPORT_NUM"), 0, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_BECAME_CHEATER_NUM"), 0, TRUE);
		Any date[12];
		memset(&date, 0, sizeof(date));
		STATS::STAT_SET_DATE(util::$("MPPLY_BECAME_CHEATER_DT"), &date[0], 7, TRUE);
		STATS::STAT_SET_DATE(util::$("MPPLY_BECAME_BADSPORT_DT"), &date[0], 7, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_DESTROYED_PVEHICLES"), 0, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_BADSPORT_MESSAGE"), 0, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_KILLS_PLAYERS_CHEATER"), 69, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_DEATHS_PLAYERS_CHEATER"), 420, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_LAST_REPORT_PENALTY"), 0, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_LAST_COMMEND_PENALTY"), 0, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_LAST_REPORT_RESTORE"), 0, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_LAST_COMMEND_RESTORE"), 0, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_REPORT_STRENGTH"), 32, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_COMMEND_STRENGTH"), 32, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_VOTED_OUT"), 0, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_VOTED_OUT_DELTA"), 0, TRUE);
		CHooking::stat_set_int(util::$("MPPLY_VOTED_OUT_QUIT"), 0, TRUE);
		CHooking::stat_set_bool(util::$("MPPLY_WAS_I_BAD_SPORT"), FALSE, TRUE);
		CHooking::stat_set_bool(util::$("MPPLY_WAS_I_CHEATER"), FALSE, TRUE);

		notify_above_map("Reports have been cleared. GL HF", 0);
	}*/

	void teleport_player_on_foot(Ped ped, float X, float Y, float Z)
	{
		CHooking::clear_ped_tasks_immediately(ped);
		Vector3	remotePos	= { X, Y, Z };
		Vector3 cam			= { 0 };
		int	scene			= CHooking::network_create_synchronised_scene(&remotePos, &cam, 2, 0, 0, 0, 0.f, 0.f);
		CHooking::network_add_ped_to_synchronised_scene(ped, scene, "mini@strip_club@private_dance@part3", "priv_dance_p3", 8.0f, -8.0, 5, 0, 30, 0, 0);
		CHooking::network_start_synchronised_scene(scene);
	}

	v3 get_coords_infront_player(float dist)
	{
		v3 r = CPlayerMem::get_player_coords(CPlayerMem::player_id());
		float	heading	= CHooking::get_entity_heading(CPlayerMem::player_ped_id());
				r.x		+= dist * sin(util::deg_to_rad(heading)) * -1,
				r.y		+= dist * cos(util::deg_to_rad(heading));
		return r;
	}

	v3 get_coords_above_player(float dist)
	{
		v3 r	= CPlayerMem::get_player_coords(CPlayerMem::player_id());
				r.z	+= dist;
		return r;
	}

	v3	get_coords_infront_of_cam(float dist)
	{
		Vector3 gameplay_rot	= { 0 };
		Vector3 gameplay_pos	= { 0 };
		CHooking::get_gameplay_cam_rot(&gameplay_rot, 0);
		CHooking::get_gameplay_cam_coord(&gameplay_pos);
		return gameplay_pos + (v3(gameplay_rot).transformRotToDir() * dist);
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
		BYTE		stIdx	= (BYTE) CHooking::get_player_radio_station_index();
		if(stIdx == 0xFF || (std::string) CHooking::get_radio_station_name(stIdx) != station)
			CHooking::set_radio_to_station_name(CHooking::m_gameInfo, &station[0]);
	}

	void	set_entity_invisible(Entity e, bool invis, bool local)
	{
		CHooking::set_entity_visible(e, invis, false);
		if(local)
			CHooking::set_local_player_visible_locally(true);
	}

	int super_run(float force, bool stop, bool keyState)
	{
		Ped playerPed = CPlayerMem::player_ped_id();
		if(keyState)
		{
			apply_force_to_entity(playerPed, 1, 0.f, force, 0.f, 0.f, 0.f, 0.f, true, true);
			return 1;
		}
		else if(stop && !CHooking::is_entity_in_air(playerPed))
		{
			Vector3 vel	= { 0 };
			CHooking::set_entity_velocity(playerPed, &vel);
			return 0;
		}
		return -1;
	}

	bool set_entity_gravity(Entity e, bool gravity)
	{
		CHooking::set_entity_has_gravity(e, gravity);
		if(is_entity_a_ped(e))
			CHooking::set_ped_gravity(e, gravity);
		else if(is_entity_a_vehicle(e))
			util::handle_to_ptr<CVehicle>(e)->fGravity = 0.f;
		else
			return false;
		return true;
	}

	void chaos_mode(int action)
	{
		static clock_t	tmr	= { };
		Ped playerPed		= CPlayerMem::player_ped_id();
		Entity	ent			= NULL;
		clock_t	delay		= 0x200;
		bool	driveable	= true;

		if(action == CHAOSMODE_BOUNCE)	//bounce
			delay			= 0x400;
		if(action == CHAOSMODE_FORCEFIELD)	//forcefield
		{
			clock_t	delay	= 0x60;
			driveable		= false;
		}
		if(action == CHAOSMODE_ARMAGEDDON)
			driveable		= false;

		if(clock() - tmr > delay && CHack::m_nearbyPed.empty() && CHack::m_nearbyVehicle.empty())
		{
			script::update_nearby_ped();
			script::update_nearby_vehicle(driveable);
			tmr = clock();
		}
		else if(!CHack::m_nearbyPed.empty())
		{
			ent	= CHack::m_nearbyPed.front();
			CHack::m_nearbyPed.pop();
		}
		else if(!CHack::m_nearbyVehicle.empty())
		{
			ent	= CHack::m_nearbyVehicle.front();
			CHack::m_nearbyVehicle.pop();
		}

		if(ent != NULL && is_an_entity(ent))
		{
			v3 pos = get_entity_coords(ent);
			if(action == CHAOSMODE_BOUNCE && request_control_of_entity(ent))	//bounce
				apply_force_to_entity(ent, 1, 0, 0, is_entity_a_ped(ent) ? 10.f : 5.f, 0, 0, 0, 1, 1);
			else if(action == CHAOSMODE_ASCENTION && request_control_of_entity(ent))	//ascention
				apply_force_to_entity(ent, 1, 0.f, 0.f, 150.f, 0.f, 0.f, 0.f, false, true);
			else if(action == CHAOSMODE_ARMAGEDDON && request_control_of_entity(ent))	//armageddon
				apply_force_to_entity(ent, 1, (float) util::random_int(-50, 50), (float) util::random_int(-50, 50), (float) util::random_int(-30, 30), (float) util::random_int(-20, 20), (float) util::random_int(-20, 20), (float) util::random_int(-20, 20), 1, 1); 
			else if(action == CHAOSMODE_MAYHEM)	//mayhem
				add_explosion(pos, 29, 1, false, false, 0);
			else if(action == CHAOSMODE_FORCEFIELD && request_control_of_entity(ent))	//forcefield
			{
				v3 playerPos		= CPlayerMem::get_player_coords(CPlayerMem::player_id());
				v3 playerPos_pos	= pos - playerPos;
				float	x				= playerPos_pos.x < 0.f ? playerPos_pos.x * -1.f : playerPos_pos.x,
						y				= playerPos_pos.y < 0.f ? playerPos_pos.y * -1.f : playerPos_pos.y;
				float	ratio			= 100.f	/ (x > y ? x : y);
				apply_force_to_entity(ent, 1, playerPos_pos.x * ratio, playerPos_pos.y * ratio, is_entity_a_ped(ent) ? 20.f : 5.f, (float) util::random_int(-5, 5), (float) util::random_int(-5, 5), (float) util::random_int(-5, 5), false, true);
			}
			else if(action == CHAOSMODE_GRAVITYFIELD && request_control_of_entity(ent))	//gravity field
			{
				set_entity_gravity(ent, false);
				Vector3 velocity	= { 0 };
				CHooking::get_entity_velocity(&velocity, ent);
				velocity.z = 2.f;
				if(is_entity_a_ped(ent) && !is_ped_ragdoll(ent))
				{
					CHooking::set_ped_to_ragdoll(ent, 2000, 0, 2, false, false, false);
					velocity.z = 5.f;
				}
				CHooking::set_entity_velocity(ent, &velocity);
			}
			else if(action == CHAOSMODE_SMASH && request_control_of_entity(ent))	//smash
			{
				teleport_entity_to_coords(ent, {pos.x, pos.y, pos.z + 10.f}, false);
				if(is_entity_a_ped(ent))
					set_ped_health(ent, 0);
				else
					CHooking::set_entity_rotation(ent, &UPSIDE_DOWN, 0);
				Vector3 vel(0.f, 0.f, -150.f);
				CHooking::set_entity_velocity(ent, &vel);
			}
			else if(action == CHAOSMODE_MASSACRE && is_entity_a_ped(ent))	//massacre
				shoot_ped(ent);
			else if(action == CHAOSMODE_ENERGYFIELD && request_control_of_entity(ent) && is_entity_a_vehicle(ent))
			{
				CHooking::set_vehicle_undriveable(ent, true);
				CVehicle* veh = util::handle_to_ptr<CVehicle>(ent);
				veh->fHealth2	= 0;
			}
		}
	}

	bool	smash_vehicles()
	{
		static std::deque<Vehicle>	smash_vehicle;
		static clock_t				tmr	= { };
		static int		i	= 0;
		Ped		playerPed		= CPlayerMem::player_ped_id();
		bool	r	= false;
		if(smash_vehicle.empty())
		{
			queue_int	tmpQueue;
			script::update_nearby_vehicle(true, &tmpQueue);
			while(!tmpQueue.empty())
			{
				smash_vehicle.push_back(tmpQueue.front());
				tmpQueue.pop();
			}
			tmr	= clock();
			i		= 0;
		}
		else
		{
			if(i >= smash_vehicle.size())
				i	= 0;
			if(clock() - tmr < 8000)
			{
				Entity ent	= smash_vehicle[i];
				i++;
				if(!request_control_of_entity(ent))
					return false;
				set_entity_gravity(ent, false);
				Vector3 vel(0.f, 0.f, 2.f);
				CHooking::set_entity_velocity(ent, &vel);
			}
			else if(clock() - tmr > 8000)
			{
				Entity ent	= smash_vehicle.front();
				smash_vehicle.pop_front();
				if(smash_vehicle.empty())
					r	= true;
				set_entity_gravity(ent, true);
				CHooking::set_entity_rotation(ent, &UPSIDE_DOWN, 0);
				Vector3 vel(0.f, 0.f, -150.f);
				CHooking::set_entity_velocity(ent, &vel);
			}
		}

		return r;
	}

	bool	black_hole(int sec)
	{
		Ped		playerPed	= CPlayerMem::player_ped_id();
		Entity	ent			= NULL;
		static Object	bh	= NULL;
		static clock_t	refreshTmr	= clock();
		static clock_t	bhTmr	= NULL;
		if(bh == NULL)
			if(!spawn_object(0x6b795ebc, &bh))	//"prop_alien_egg_01"
				return false;
			else
			{
				bhTmr	= clock();
				CHooking::freeze_entity_position(bh, true);
			}
		else if(!is_an_entity(bh))
		{
			bhTmr	= 0;
			return true;
		}
		if(clock() - refreshTmr > 0x100 && CHack::m_nearbyPed.empty() && CHack::m_nearbyVehicle.empty())
		{
			script::update_nearby_ped(false);
			script::update_nearby_vehicle(false);
			refreshTmr = clock();
		}
		else if(!CHack::m_nearbyPed.empty())
		{
			ent	= CHack::m_nearbyPed.front();
			CHack::m_nearbyPed.pop();
		}
		else if(!CHack::m_nearbyVehicle.empty())
		{
			ent	= CHack::m_nearbyVehicle.front();
			CHack::m_nearbyVehicle.pop();

		}

		if(ent != NULL && is_an_entity(ent))
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
				float	ratio			= 75.f	/ (x > y ? x : y);
				apply_force_to_entity(ent, 1, pos_bhPos.x * ratio, pos_bhPos.y * ratio, is_entity_a_ped(ent) ? 1.f : .5f, (float) util::random_int(-2, 2), (float) util::random_int(-2, 2), (float) util::random_int(-2, 2), false, true);
			}
		}

		if(clock() - bhTmr > sec * 1000)
		{
			CHack::m_entityCleanup.push(bh);
			bh	= NULL;
			return true;
		}
		return false;
	}

	bool	drop_money_on_player(Player player, int amount, DWORD hash)
	{
		Vector3		pos			= CPlayerMem::get_player_coords(player);
		pos.z	+= 2.f;
		Hash		modelHash	= amount > 2000 ? 0x113FD533U : hash;	// 0x113FD533 = prop_money_bag_01
		if(!CHooking::is_model_in_cdimage(modelHash))
			return true;
		CHooking::request_model(modelHash);
		if(!CHooking::has_model_loaded(modelHash))
			return false;
		CHooking::create_ambient_pickup(0xce6fdd6bU, &pos, 0, amount, modelHash, false, true);
		CHooking::set_model_as_no_longer_needed(modelHash);
		return true;
	}

	void	ped_money_drop(Player player, clock_t* tmr)
	{
		v3 playerPos	= CPlayerMem::get_player_coords(player);

		if(clock() - *tmr > 0x60)
		{
			if(CHack::m_nearbyPed.empty())
				script::update_nearby_ped();
			else
			{
				Entity ent	= CHack::m_nearbyPed.front();
				CHack::m_nearbyPed.pop();
				if(ent > 0 && is_an_entity(ent))
				{
					if(!request_control_of_entity(ent))
						return;
					CPed* cped = util::handle_to_ptr<CPed>(ent);
					if(cped != nullptr && cped != CHack::m_pCPedPlayer && cped->fHealth > 100.f && cped->fHealth < 250)
					{
						cped->iCash = 2000;
						CHooking::clear_ped_tasks_immediately(ent);
						teleport_entity_to_coords(ent, {playerPos.x, playerPos.y, playerPos.z + 2.5f}, false);
						cped->fHealth = 0;
					}
				}
				*tmr	= clock();
			}
		}

		if(CHooking::m_replayIntf->pCPickupInterface->iCurPickups > 0)
		{
			int max	= CHooking::m_replayIntf->pCPickupInterface->iMaxPickups;
			for(int i = 0; i < max; ++i)
			{
				CPickup*	pickup	= CHooking::m_replayIntf->pCPickupInterface->get_pickup(i);
				if(pickup == nullptr || pickup->pCNavigation == nullptr || pickup->iValue < 100)
					continue;
				pickup->pCNavigation->v3Pos	= playerPos;
				pickup->v3VisualPos			= playerPos;
			}
		}
	}

	void	stealth_money(int mils, bool remove)
	{
		if(!CHooking::network_is_session_started())
			return;

		int	max		= remove ? 2000 : 15;
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
				amount	= max * 1000000;
				--loops;
			}
			Any transactionID	= INT_MAX;
			if(CHooking::network_shop_begin_service(&transactionID, 1474183246, remove	? -1359375127 : -1586170317, remove ? 537254313 : 1445302971, amount, 4))
				 CHooking::network_shop_checkout_start(transactionID);
		}
	}

	void	trigger_script_event(eScriptEvent id, Player player, uint64_t arg2, uint64_t arg3)
	{
		if(!CHooking::network_is_session_started())
			return;
		constexpr BYTE	c		= 4;
		int32_t			flags	= (1 << player);
		uint64_t		args[c]	= { id, (uint64_t) player, arg2, arg3 };
		CHooking::trigger_script_event(true, args, c, flags);
	}

	void set_time(int h, int m)
	{
		if(h == -1)
			h = CHooking::m_clockTime->hour;
		if(m == -1)
			m = CHooking::m_clockTime->minute;
		*CHooking::m_clockTime = { h, m, 0 };
		CHooking::network_override_clock_time(h, m, 0, 0);
	}

	void set_weather(std::string w)
	{
		CHooking::set_weather_type_now_persist(&w[0]);
	}

	void freeze_time(bool b)
	{
		static	int	h	= -1;
		static	int m	= -1;
		if(!b)
		{
			m	= h	= -1;
			return;
		}
		if(h == -1 || m == -1)
		{
			h	= CHooking::m_clockTime->hour;
			m	= CHooking::m_clockTime->minute;
		}
		*CHooking::m_clockTime = { h, m, 0 };
		CHooking::network_override_clock_time(h, m, 0, 0);
	}

	void draw_speedometer(Vehicle v, bool mph)
	{
		float	speed	= CHooking::get_entity_speed(v) * 3.6f;
		if(mph)
			speed	= speed * .621f;
		char msg[0xFF];
		sprintf_s(msg, "%i", (int) speed);
		draw_text(msg, .97f, .97f, 7, .5f, {255, 0, 0, 255});
	}

	float	get_fps()
	{
		static int		iFrames		= 0;
		static clock_t	clockFrames	= clock();
		static float	iFps;
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
		draw_text(&str[0], .005f, .005f, 7, .5f, { 0, 255, 0, 255});
	}

	void draw_crosshair(CColor color, int flag, int size, int thickness)
	{
		if(flag == 1 && !CHooking::is_aim_cam_active())
			return;

		CHooking::draw_rect(.5f, .5f, util::pixel_to_rel(size, false), util::pixel_to_rel(thickness, true), color.r, color.g, color.b, color.a);	//horizontal
		CHooking::draw_rect(.5f, .5f, util::pixel_to_rel(thickness, false), util::pixel_to_rel(size, true), color.r, color.g, color.b, color.a);	//vertical

		//CHooking::draw_rect(.496f, .5f, .005f, .001f, color.r, color.g, color.b, color.a);	//horizontal
		//CHooking::draw_rect(.504f, .5f, .005f, .001f, color.r, color.g, color.b, color.a);	//horizontal
	}

	void noclip(Entity e, int action, float speed, bool freeCam, bool restore)
	{
		if(!is_entity_a_ped(e) && !is_entity_a_vehicle(e))
			return;
		CHooking::freeze_entity_position(e, !restore);
		CHooking::set_entity_collision(e, restore, true, false);
		if(restore)
			return;
		float turnSpeed = speed > 5 ? 1.5f : ((speed / 10) + 1.f);

		if(!freeCam)
		{
			Vector3 rot	= { 0 };
			if(action & NOCLIP_FORWARD)	//forward
			{
				CHooking::get_entity_rotation(&rot, e, 0);
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), rot, .25f * speed), false);
			}
			if(action & NOCLIP_BACK)	//back
			{
				CHooking::get_entity_rotation(&rot, e, 0);
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), rot, -.25f * speed), false);
			}
			if(action & NOCLIP_LEFT)	//left
				CHooking::set_entity_heading(e, CHooking::get_entity_heading(e) + 2.5f * turnSpeed);
			if(action & NOCLIP_RIGHT)	//right
				CHooking::set_entity_heading(e, CHooking::get_entity_heading(e) - 2.5f * turnSpeed);
		}
		else
		{
			Vector3 camRot	= { 0 };
			CHooking::get_gameplay_cam_rot(&camRot, 0);
			//v3	camRot	= CAM::GET_GAMEPLAY_CAM_ROT(0);
			CHooking::set_entity_rotation(e, &camRot, 0);
			if(action & NOCLIP_FORWARD)	//forward
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), camRot, .25f * speed), false);
			if(action & NOCLIP_BACK)	//back
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), camRot, -.25f * speed), false);
			if(action & NOCLIP_LEFT)	//left
			{
				camRot = { 0.f, 0, 0.f, 0, camRot.z + 90.f, 0 };
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), camRot, .25f * speed), false);
			}
			if(action & NOCLIP_RIGHT)	//right
			{
				camRot = { 0.f, 0, 0.f, 0, camRot.z - 90.f, 0 };
				teleport_entity_to_coords(e, get_coords_infront_of_coords(get_entity_coords(e), camRot, .25f * speed), false);
			}
		}
		if(action & NOCLIP_UP)	//up
			teleport_entity_to_coords(e, get_coords_above_coords(get_entity_coords(e), .2f * speed), false);
		if(action & NOCLIP_DOWN)	//down
			teleport_entity_to_coords(e, get_coords_above_coords(get_entity_coords(e), -.2f * speed), false);
	}

	/*Entity get_raycast_entity()
	{
		Vector3	pos		= {};
		Vector3	start	= {};
		Vector3	end		= {};
		v3		dir		= {};
		int		ray		= 0;
		BOOL	hit		= 0;
		Hash	hash	= 0;
		Entity	entity	= 0;

		if(!CHooking::is_player_free_aiming(CPlayerMem::player_id()))
			return entity;


		CHooking::get_gameplay_cam_rot(&pos, 0);	//this uses pos as a tmp value
		dir		= v3(pos).transformRotToDir();	
		CHooking::get_gameplay_cam_coord(&pos);
		start	= pos + dir;
		end		= pos + (dir * 0x800);


		ray		= CHooking::start_ray_cast(&start, &end, -1, 0, true);
		CHooking::get_ray_cast(ray, &hit, &end, &start, &hash, &entity);

		if(!hit || entity == 0 || !is_an_entity(entity) || !is_entity_a_ped(entity))
			entity = 0;
		return entity;
	}*/

	/*
		flag
			0x01	TRGBOT_PEDS		peds
			0x02	TRGBOT_PLAYERS	players
	*/
	bool trigger_bot(uint32_t flag)
	{
		static bool		down	= false;
		static clock_t	tmr		= 0;
		Ped				ped		= get_entity_crosshair(XHAIR_PEDS_ONLY | XHAIR_ALIVE_ONLY);

		if(!(flag & TRGBOT_PLAYERS))
			goto LABEL_CONTINUE;

		Player	player		= CPlayerMem::get_player_from_ped(ped);
		if(player == -1)
		{
			ped	= NULL;
			goto LABEL_CONTINUE;
		}

		int		team		= CPlayerMem::get_player_team(player);
		int		localTeam	= CPlayerMem::get_player_team(CPlayerMem::player_id());

		if(localTeam != -1 && team == localTeam)
			ped	= NULL;

		LABEL_CONTINUE:
		
		clock_t	curClock	= clock();
		if((!down && ped != NULL) || (down && curClock - tmr > 0x40))
		{
			INPUT	input[1];
			input[0].type			= INPUT_MOUSE;
			input[0].mi.dx			= 0;
			input[0].mi.dy			= 0;
			input[0].mi.mouseData	= 0;
			input[0].mi.dwExtraInfo	= 0;
			input[0].mi.time		= 0;
			input[0].mi.dwFlags		= down ? MOUSEEVENTF_LEFTUP : MOUSEEVENTF_LEFTDOWN;
			down					= !down;
			tmr						= curClock;
			SendInput(get_array_size(input), input, sizeof(input[0]));
		}

		return !down;
	}


	/*
		flag
			0x01	XHAIR_PEDS_ONLY		Peds only
			0x02	XHAIR_ALIVE_ONLY	Alive only
	*/
	Entity	get_entity_crosshair(int flag)
	{
		Entity e	= NULL;
		Player player = CPlayerMem::player_id();
		if(CHooking::is_player_free_aiming(player) && CHooking::get_entity_player_is_free_aiming_at(player, &e) && is_an_entity(e))
		{
			if(is_entity_a_ped(e))
			{
				if(is_ped_in_any_vehicle(e))
				{
					Vehicle v = CHooking::get_vehicle_ped_is_using(e);
					if(is_entity_a_vehicle(v))
						e = v;
				}
			}
			if(flag & XHAIR_PEDS_ONLY && !is_entity_a_ped(e))
				e	= NULL;
			if(flag & XHAIR_ALIVE_ONLY && is_entity_dead(e))
				e	= NULL;
		}
		else
			e	= NULL;
		return e;
	}

	/*
	action
		0x01	EDIT_ACTION_RESET	reset target
		0x02	EDIT_ACTION_LOCK	lock target
		0x04	EDIT_ACTION_DELETE	delete target
	*/

	/*
	flags
		0x01	EDITOR_FLAG_TEXT_TYPE	display text type
		0x02	EDITOR_FLAG_TEXT_POS	display text pos
		0x04	EDITOR_FLAG_COLLISION	disable collision
		0x08	EDITOR_FLAG_FREEZE		freeze entity
		0x10	EDITOR_FLAG_THROW		throw mode
		0x20	EDITOR_FLAG_REL_ROT		relative rotation
		0x40	EDITOR_FLAG_INVISIBLE	invisible
		0x80	EDITOR_FLAG_ROT			rotation enable
	*/
	static Entity editor_locked_entity	= NULL;

	void	editor_reset_target(int flag = 0, float dist = 0.f)
	{
		if(editor_locked_entity	!= NULL && is_an_entity(editor_locked_entity))
		{
			if(flag & EDITOR_FLAG_THROW)
			{
				v3 dir	= get_coords_infront_of_cam(dist + 100.f) - get_entity_coords(editor_locked_entity);
				CHooking::freeze_entity_position(editor_locked_entity, false);
				apply_force_to_entity(editor_locked_entity, 1, dir.x, dir.y, dir.z, 0.f, 0.f, 0.f, false, true);
			}
			if(flag & EDITOR_FLAG_INVISIBLE)
				CHooking::set_entity_visible(editor_locked_entity, false, false);
		}
		editor_locked_entity = NULL;
	}

	bool	entity_editor(int action, float dist, int flag, Vector3 rot, Entity ent)
	{
		if(action & EDIT_ACTION_RESET || (ent != NULL && editor_locked_entity != ent))
			editor_reset_target(flag, dist);

		if(ent != NULL && editor_locked_entity != ent)
			editor_locked_entity	= ent;
		Entity e		= editor_locked_entity == NULL ? NULL : editor_locked_entity;

		//find target
		if(e == NULL)
		{
			e	= get_entity_crosshair();

			if(action & EDIT_ACTION_LOCK)
				editor_locked_entity	= e;
		}	
		if(!is_an_entity(e))
		{
			editor_locked_entity	= NULL;
			return false;
		}

		//delete entity
		if(action & EDIT_ACTION_DELETE)
		{
			CHack::m_entityCleanup.push(e);	//push entity to the cleanup script
			editor_reset_target();
		}

		if(flag & EDITOR_FLAG_TEXT_TYPE)
		{
			std::string str	= "Entity";
			if(is_entity_a_ped(e))
				str	= "Ped";
			else if(is_entity_a_vehicle(e))
				str = "Vehicle";
			else if(is_entity_an_object(e))
				str = "Object";

			CColor	color = { 255, 255, 255, 255 };
			if(editor_locked_entity != NULL)
				color = { 0, 255, 0, 255 };

			draw_text(&str[0], .5f, .5f, 7, .5f, color);
		}

		if(flag & EDITOR_FLAG_TEXT_POS)
		{
			v3		pos		= get_entity_coords(e);
			char	msg[0xFF];
			sprintf_s(msg, "%.3f, %.3f, %.3f", pos.x, pos.y, pos.z);
			draw_text(msg, .5f, .525f, 0, .3f, { 255, 255, 255, 255 });
		}

		if(editor_locked_entity == NULL)	//not locked in yet, return
			return false;

		v3 coords		= get_coords_infront_of_cam(dist);

		request_control_of_entity(e);
		if(flag & EDITOR_FLAG_ROT)
		{
			if(flag & EDITOR_FLAG_REL_ROT)
			{
				Vector3 camRot	= { 0 };
				CHooking::get_gameplay_cam_rot(&camRot, 0);
				rot.z += camRot.z;
			}
			CHooking::set_entity_rotation(e, &rot, 0);
		}
		CHooking::set_entity_visible(e, true, false);
		CHooking::freeze_entity_position(e, !!(flag & EDITOR_FLAG_FREEZE));
		CHooking::set_entity_collision(e, !(flag & EDITOR_FLAG_COLLISION), true, false);
		teleport_entity_to_coords(e, coords, false);
		return true;
	}

	bool send_assasins_after_player(Player player)
	{
		static int	count[MAX_PLAYERS]	= { 0 };
		v3	pos			= CPlayerMem::get_player_coords(player);
		Ped	remotePed	= CPlayerMem::get_player_ped(player);
		if(count[player] < 0xF)
		{
			Ped ped;
			spawn_ped(	0xc1f380e6,	//"cs_chrisformage"
						PedTypeHuman,
						{pos.x + util::random_int(-20, 20), pos.y + util::random_int(-20, 20), pos.z},
						&ped,
						false,
						PEDSPAWN_ARMY);
			CHooking::ai_task_combat_ped(ped, remotePed, 0, 0);
			count[player]++;
			return false;
		}

		count[player]	= 0;
		return true;
	}

	void	shoot_ped(Ped ped, DWORD bone, bool owned)
	{
		Vector3 rot	= { 0 };
		Vector3 pos = { 0 };
		CHooking::get_ped_bone_coords(&pos, ped, bone, &rot);
		CHooking::get_entity_rotation(&rot, ped, 0);
		v3 dir		= v3(rot).transformRotToDir();
		Vector3 pos1		= v3(pos) + dir;
		Vector3 pos2		= v3(pos) - dir;
		CHooking::shoot_single_bullet_between_coords(	&pos1,
														&pos2,
														500,
														false,
														0xc472fe2, //script::$("WEAPON_HEAVYSNIPER")
														owned ? CPlayerMem::player_ped_id() : NULL,
														true,
														false,
														200.f,
														0,
														0,
														0,
														0);
	}

	void	explode_ped(Ped ped, int type)
	{
		v3 remotePos = get_entity_coords(ped);
		add_explosion(remotePos, type, 1, true, false, 0);
	}

	void	explode_nearby_players(Player source)
	{
		Player local	= CPlayerMem::player_id();
		Ped ped			= CPlayerMem::get_player_ped(source);
		for(int i = 0; i < MAX_PLAYERS; ++i)
		{
			if(source == i || i == local || CPlayerMem::get_player_ped(i) == 0)
				continue;
			Vector3 pos = CPlayerMem::get_player_coords(i);
			CHooking::add_owned_explosion(ped, &pos, 2, 1.f, true, false, 0.f);
		}
	}

	void	lester_offradar_toggle(bool b)
	{
		__int64*	ptr	= CHooking::getGlobalPtr(GLOBALPTR_OTR_TOGGLE + (CPlayerMem::player_id() * 358));
		if((b && !(*ptr & 1)) || (!b && *ptr & 1))
			*ptr ^= 1;
	}

	void	lester_offradar_add(int ms)
	{
		uint64_t	time	= CHooking::get_network_time(); //GetTickCount64(); //synced from host
		uint64_t*	ptr		= reinterpret_cast<uint64_t*>(CHooking::getGlobalPtr(GLOBALPTR_OTR_TIME));
		if(*ptr < time + (ms / 2))
			*ptr = time + ms;
	}

	void	spectate_player(Ped p, bool b)
	{
		CHooking::network_set_in_spectator_mode(b, p);
	}

	bool	animate_player(Player player, std::string dict, std::string anim, bool freeze, bool restore)
	{
		Ped remotePed	= CPlayerMem::get_player_ped(player);
		CHooking::clear_ped_tasks_immediately(remotePed);
		if(restore)
			return true;
		CHooking::request_anim_dict(&dict[0]);
		if(!CHooking::has_anim_dict_loaded(&dict[0]))
			return false;
		Vector3	remotePos	= CPlayerMem::get_player_coords(player);
		Vector3 cam			= { 0 };
		int	scene		= CHooking::network_create_synchronised_scene(&remotePos, &cam, 2, 0, 1, 1, 0.f, freeze ? 0.f : 1.f);
		CHooking::network_add_ped_to_synchronised_scene(remotePed, scene, &dict[0], &anim[0], 8.f, 1.f, -1, 1, 1.f, 1, 0);
		CHooking::network_start_synchronised_scene(scene);
		return true;
	}

	bool	animate_local_player(Ped playerPed, std::string dict, std::string anim, bool restore)
	{
		CHooking::clear_ped_tasks_immediately(playerPed);
		if(restore)
			return true;
		CHooking::request_anim_dict(&dict[0]);
		if(!CHooking::has_anim_dict_loaded(&dict[0]))
			return false;
		CHooking::ai_task_play_anim(playerPed, &dict[0], &anim[0], 8.f, 1.f, -1, 1, 1.f, 0, 0, 0, 0, 0);
		return true;
	}

	bool player_dead_clone(Player player, bool cleanup)
	{
		Ped					playerPed	= CPlayerMem::get_player_ped(player);
		Ped					ped			= 0;
		static deque_int	clones[MAX_PLAYERS];
		if(cleanup)
		{
			while(!clones[player].empty())
			{
				CHack::m_entityCleanup.push(clones[player].back());
				clones[player].pop_back();
			}
			return true;
		}
		ped	= CHooking::clone_ped(playerPed, CHooking::get_entity_heading(playerPed), 1, 1);
		if(clones[player].size() > 8)
		{
			CHack::m_entityCleanup.push(clones[player].front());
			clones[player].pop_front();
		}
		clones[player].push_back(ped);
		CPed*	cped	= util::handle_to_ptr<CPed>(ped);
		v3		pos		= cped->v3VisualPos;
		teleport_entity_to_coords(ped, { pos.x, pos.y, pos.z + 2.f }, false);
		cped->fHealth	= 0.f;
		return true;
	}

	bool give_player_wanted_level(Player player)
	{
		static int	count[MAX_PLAYERS]	= { 0 };
		v3	pos			= CPlayerMem::get_player_coords(player);
		Ped	remotePed	= CPlayerMem::get_player_ped(player);
		if(count[player] < 0x8)
		{
			Ped ped;
			spawn_ped(	0x15f8700d,// female cop
						PedTypeHuman,
						{pos.x + util::random_int(-20, 20), pos.y + util::random_int(-20, 20), pos.z + 50.f},
						&ped,
						false,
						PEDSPAWN_ARMY);
			Vector3 pedPos	= get_entity_coords(ped);
			CHooking::add_owned_explosion(remotePed, &pedPos, 2, 1.f, false, true, 0.f);
			
			count[player]++;
			return false;
		}

		count[player]	= 0;
		return true;
	}

	bool clean_session()
	{
		static clock_t    tmr    = { 0 };
		if(!tmr)
		{
			ShellExecute(0, LPCTSTR("open"), LPCTSTR("cmd.exe"), LPCTSTR("/C ipconfig -release"), 0, SW_HIDE);
			tmr    = clock();
		}
		else if(clock() - tmr > 0x2000)
		{
			ShellExecute(0, LPCTSTR("open"), LPCTSTR("cmd.exe"), LPCTSTR("/C ipconfig -renew"), 0, SW_HIDE);
			tmr    = 0;
			return true;
		}
		return false;
	}

	bool crash_player(Player player)
	{
		static const	v3		pos					= CPlayerMem::get_player_coords(player);
		constexpr		Hash	objHash				= 0xceea3f4b;	//0xceea3f4b = barracks

		if(!CHooking::is_model_in_cdimage(objHash))
			return true;
		CHooking::request_model(objHash);
		if(!CHooking::has_model_loaded(objHash))
			return false;
		Object	obj;
		CHooking::create_object(objHash, pos.x, pos.y, pos.z, true, 1, -1, &obj, true, false, false);
		CHooking::set_model_as_no_longer_needed(objHash);
		return true;
	}

	int	get_online_player_index()
	{
		int c;
		CHooking::stat_get_int(0x2f2f120f, &c, -1);	//MPPLY_LAST_MP_CHAR
		return c;
	}

	void unlocks_stats()
	{
		if (get_online_player_index() == 0)
		{
			// MP0_SCRIPT_INCREASE_STAM MP0_SCRIPT_INCREASE_STRN MP0_SCRIPT_INCREASE_LUNG MP0_SCRIPT_INCREASE_DRIV MP0_SCRIPT_INCREASE_FLY MP0_SCRIPT_INCREASE_SHO MP0_SCRIPT_INCREASE_STL
			Hash stats[] = { 0xac49e44e, 0x38fd10e2, 0x813ab1bd, 0x3f45212c, 0x671634fd, 0x432ca7d2, 0xfebcb503 };
			for(Hash h : stats)
				CHooking::stat_set_int(h, 100, 1);
		}
		else
		{
			// MP1_SCRIPT_INCREASE_STAM MP1_SCRIPT_INCREASE_STRN MP1_SCRIPT_INCREASE_LUNG MP1_SCRIPT_INCREASE_DRIV MP1_SCRIPT_INCREASE_FLY MP1_SCRIPT_INCREASE_SHO MP1_SCRIPT_INCREASE_STL
			Hash stats[] = { 0xb4c71144, 0x33c5e654, 0xe7f00851, 0xa21f35e8, 0xb1135b8, 0x61efed9a, 0x33ad14bd };
			for (Hash h : stats)
				CHooking::stat_set_int(h, 100, 1);
		}
		notify_above_map("Stats Unlocked", 0);
	}

	void unlocks_tattoos()
	{
		if (get_online_player_index() == 0)
		{
			// MP0_AWD_FMATTGANGHQ MP0_AWD_FMWINEVERYGAMEMODE MP0_AWD_FMRACEWORLDRECHOLDER MP0_AWD_FMFULLYMODDEDCAR MP0_AWD_FMMOSTKILLSSURVIVE MP0_AWD_FMKILL3ANDWINGTARACE MP0_AWD_FMKILLSTREAKSDM
			Hash Tattoos[] = { 0x49e3d35b, 0xbdda53b4, 0x655e0bad, 0xe9472bb4, 0xc41b8767, 0x43d56fad, 0x3099c3fe };
			for(Hash h : Tattoos)
				CHooking::stat_set_bool(h, 1, 1);
 
			CHooking::stat_set_int(0x12f3b311, 20, 1); // MP0_AWD_HOLD_UP_SHOPS
 
			// MP0_AWD_LAPDANCES MP0_AWD_SECURITY_CARS_ROBBED MP0_AWD_FMKILLBOUNTY MP0_AWD_CAR_BOMBS_ENEMY_KILLS
			Hash Stats25[] = { 0x4314583e, 0x5413e4e9, 0xfb6b31f1, 0xaae88a2f };
			for (Hash h : Stats25)
				CHooking::stat_set_int(h, 25, 1);
 
			// MP0_AWD_FM_DM_WINS MP0_AWD_FM_TDM_MVP MP0_AWD_RACES_WON MP0_AWD_FMREVENGEKILLSDM
			Hash Stats50[] = { 0x4c2e3849, 0xc479c331, 0x54305ac6, 0xb2f3860f };
			for (Hash h :Stats50)
				CHooking::stat_set_int(h, 50, 1);
 
			CHooking::stat_set_int(0xfac3eb18, 500, 1); // MP0_AWD_FM_DM_TOTALKILLS
			CHooking::stat_set_int(0xee25f949, 500, 1); // MP0_PLAYER_HEADSHOTS
			CHooking::stat_set_int(0xcff5c480, 1000, 1); // MP0_DB_PLAYER_KILLS
			CHooking::stat_set_int(0xaba179f2, 50000, 1); // MP0_AWD_FMBBETWIN
		}
		else
		{
			// MP1_AWD_FMATTGANGHQ MP1_AWD_FMWINEVERYGAMEMODE MP1_AWD_FMRACEWORLDRECHOLDER MP1_AWD_FMFULLYMODDEDCAR MP1_AWD_FMMOSTKILLSSURVIVE MP1_AWD_FMKILL3ANDWINGTARACE MP1_AWD_FMKILLSTREAKSDM
			Hash Tattoos[] = { 0x2039515c, 0x4ae88781, 0x90867f4c, 0xe7c84055, 0x98ff48a5, 0xbe3fd785, 0xf3d60861 };
			for (Hash h : Tattoos)
				CHooking::stat_set_bool(h, 1, 1);
 
			CHooking::stat_set_int(0x36177f20, 20, 1); // MP1_AWD_HOLD_UP_SHOPS
 
			// MP1_AWD_LAPDANCES MP1_AWD_SECURITY_CARS_ROBBED MP1_AWD_FMKILLBOUNTY MP1_AWD_CAR_BOMBS_ENEMY_KILLS
			Hash Stats25[] = { 0xf29d01d9, 0x46533e0c, 0x1af2de9e, 0x4f6cded8 };
			for (Hash h : Stats25)
				CHooking::stat_set_int(h, 25, 1);
 
			// MP1_AWD_FM_DM_WINS MP1_AWD_FM_TDM_MVP MP1_AWD_RACES_WON MP1_AWD_FMREVENGEKILLSDM
			Hash Stats50[] = { 0x34069be5, 0x2199954e, 0x43bda5d0, 0x52326867 };
			for (Hash h : Stats50)
				CHooking::stat_set_int(h, 50, 1);
 
			CHooking::stat_set_int(0x76da8dde, 500, 1); // MP1_AWD_FM_DM_TOTALKILLS
			CHooking::stat_set_int(0x3363cba7, 500, 1); // MP1_PLAYER_HEADSHOTS
			CHooking::stat_set_int(0xeec100c9, 1000, 1); // MP1_DB_PLAYER_KILLS
			CHooking::stat_set_int(0xf678de96, 50000, 1); // MP1_AWD_FMBBETWIN
		}
		notify_above_map("Tattoos Unlocked", 0);
	}

	void unlocks_parachutes()
	{
		//Parachutes
		if (get_online_player_index() == 0)
		{
			Hash Parachutes[] =
			{
				// MP0_CHAR_KIT_1_FM_UNLCK MP0_CHAR_KIT_2_FM_UNLCK MP0_CHAR_KIT_3_FM_UNLCK MP0_CHAR_KIT_4_FM_UNLCK MP0_CHAR_KIT_5_FM_UNLCK
				0xad72fbf2, 0x40bd0b85, 0xeda9551e, 0x5b09abba, 0xb2bef7f5,
				// MP0_CHAR_KIT_6_FM_UNLCK MP0_CHAR_KIT_7_FM_UNLCK MP0_CHAR_KIT_8_FM_UNLCK MP0_CHAR_KIT_9_FM_UNLCK MP0_CHAR_KIT_10_FM_UNLCK
				0xd6ae148f, 0x6ef3639f, 0x4e93ab72, 0xd958d97b, 0xabe64158,
				// MP0_CHAR_KIT_11_FM_UNLCK MP0_CHAR_KIT_12_FM_UNLCK
				0x9305c000, 0xe93fe20f,
				// MP0_CHAR_KIT_FM_PURCHASE MP0_CHAR_KIT_FM_PURCHASE2 MP0_CHAR_KIT_FM_PURCHASE3 MP0_CHAR_KIT_FM_PURCHASE4 MP0_CHAR_KIT_FM_PURCHASE5
				0x3d76c26c, 0x591945de, 0x66e0e16d, 0x3d268df9, 0xbc960cd2,
				// MP0_CHAR_KIT_FM_PURCHASE6 MP0_CHAR_KIT_FM_PURCHASE7 MP0_CHAR_KIT_FM_PURCHASE8 MP0_CHAR_KIT_FM_PURCHASE9 MP0_CHAR_KIT_FM_PURCHASE10
				0xca64a86f, 0xa1da575f, 0xb00bf3c2, 0xd8cac53f, 0x72f137e0,
				// MP0_CHAR_KIT_FM_PURCHASE11 MP0_CHAR_KIT_FM_PURCHASE12
				0xf2bc376c, 0x12d219
			};
			for (Hash h : Parachutes)
				CHooking::stat_set_int(h, -1, 1);
		}
		else
		{
			Hash Parachutes[] =
			{
				// MP1_CHAR_KIT_1_FM_UNLCK MP1_CHAR_KIT_2_FM_UNLCK MP1_CHAR_KIT_3_FM_UNLCK MP1_CHAR_KIT_4_FM_UNLCK MP1_CHAR_KIT_5_FM_UNLCK
				0x9f4e767d, 0x997a17cf, 0x53c37587, 0x7b567631, 0x81ef7fa6,
				// MP1_CHAR_KIT_6_FM_UNLCK MP1_CHAR_KIT_7_FM_UNLCK MP1_CHAR_KIT_8_FM_UNLCK MP1_CHAR_KIT_9_FM_UNLCK MP1_CHAR_KIT_10_FM_UNLCK
				0x79334c37, 0x349b4fc0, 0x8c98f47a, 0x6f2457cf, 0x99388033,
				// MP1_CHAR_KIT_11_FM_UNLCK MP1_CHAR_KIT_12_FM_UNLCK
				0x4d6e1b4, 0x3ab201e6,
				// MP1_CHAR_KIT_FM_PURCHASE MP1_CHAR_KIT_FM_PURCHASE2 MP1_CHAR_KIT_FM_PURCHASE3 MP1_CHAR_KIT_FM_PURCHASE4 MP1_CHAR_KIT_FM_PURCHASE5
				0x82421c7b, 0x3c1e7695, 0x45558903, 0x2098bf8a, 0x2a4ad2ee,
				// MP1_CHAR_KIT_FM_PURCHASE6 MP1_CHAR_KIT_FM_PURCHASE7 MP1_CHAR_KIT_FM_PURCHASE8 MP1_CHAR_KIT_FM_PURCHASE9 MP1_CHAR_KIT_FM_PURCHASE10
				0x8ec29bdc, 0xa08d3f71, 0x57462ce4, 0x617c4150, 0x4c24e0ff,
				// MP1_CHAR_KIT_FM_PURCHASE11 MP1_CHAR_KIT_FM_PURCHASE12
				0xddac840c, 0xf89fb9f2
			};
			for (Hash h : Parachutes)
				CHooking::stat_set_int(h, -1, 1);
		}
		notify_above_map("Parachutes Unlocked", 0);
	}

	void unlocks_chrome_rims()
	{
		//Chrome Rims
		if (get_online_player_index() == 0)
		{
			// MP0_AWD_WIN_CAPTURES MP0_AWD_FINISH_HEISTS MP0_AWD_FINISH_HEIST_SETUP_JOB MP0_AWD_WIN_LAST_TEAM_STANDINGS MP0_AWD_ONLY_PLAYER_ALIVE_LTS
			Hash Stats50[] = { 0xcfe6e176, 0x2f5bf8f, 0xe4c4cc91, 0x95546c90, 0xaa71df87 };
			for(Hash h : Stats50)
				CHooking::stat_set_int(h, 50, 1);
       
			// MP0_AWD_DROPOFF_CAP_PACKAGES MP0_AWD_KILL_CARRIER_CAPTURE MP0_AWD_NIGHTVISION_KILLS
			Hash Stats100[] = { 0x624901df, 0xbc4421b6, 0x3c9d6f53 };
			for (Hash h : Stats100)
				CHooking::stat_set_int(h, 100, 1);
		}
		else
		{
			// MP1_AWD_WIN_CAPTURES MP1_AWD_FINISH_HEISTS MP1_AWD_FINISH_HEIST_SETUP_JOB MP1_AWD_WIN_LAST_TEAM_STANDINGS MP1_AWD_ONLY_PLAYER_ALIVE_LTS
			Hash Stats50[] = { 0xd9c9649, 0x2037f997, 0x5550ea43, 0xb957bde2, 0x512fc8f4 };
			for (Hash h : Stats50)
				CHooking::stat_set_int(h, 50, 1);
 
			// MP1_AWD_DROPOFF_CAP_PACKAGES MP1_AWD_KILL_CARRIER_CAPTURE MP1_AWD_NIGHTVISION_KILLS
			Hash Stats100[] = { 0x47ae528d, 0x2a8544ef, 0x77d6ea19 };
			for (Hash h : Stats100)
				CHooking::stat_set_int(h, 100, 1);
		}
		notify_above_map("Rims Unlocked", 0);
	}

	void unlocks_vehicles()
	{
		if (get_online_player_index() == 0)
		{
			Hash StatsMinusOne[] =
			{
				// MP0_CHAR_FM_CARMOD_1_UNLCK MP0_CHAR_FM_CARMOD_2_UNLCK MP0_CHAR_FM_CARMOD_3_UNLCK MP0_CHAR_FM_CARMOD_4_UNLCK MP0_CHAR_FM_CARMOD_5_UNLCK
				0x34e21552, 0x881f0a1e, 0x4ebf2ed2, 0xea7fe34c, 0xd20c5868,
				// MP0_CHAR_FM_CARMOD_6_UNLCK MP0_CHAR_FM_CARMOD_7_UNLCK MP0_CHAR_FM_VEHICLE_1_UNLCK MP0_CHAR_FM_VEHICLE_2_UNLCK
				0xbee92cbe, 0x4d85836e, 0xb56ead95, 0x3d5d8200
			};
			for (Hash h : StatsMinusOne)
				CHooking::stat_set_int(h, -1, 1);
 
			// MP0_AWD_FMRALLYWONDRIVE MP0_AWD_FMRALLYWONNAV MP0_AWD_FMWINSEARACE MP0_AWD_FMWINAIRRACE
			Hash Stats1[] = { 0xbb5b1a96, 0x6ae2181d, 0xc5c0f286, 0x40bf1a36 };
			for (Hash h : Stats1)
				CHooking::stat_set_int(h, 1, 1);
 
			// MP0_RACES_WON MP0_NUMBER_TURBO_STARTS_IN_RACE MP0_USJS_COMPLETED MP0_AWD_FM_RACES_FASTEST_LAP
			Hash Stats50[] = { 0x39a76053, 0x13c6b4b1, 0x13071b8f, 0xc13d4f3a };
			for (Hash h : Stats50)
				CHooking::stat_set_int(h, 50, 1);
 
			CHooking::stat_set_int(0xad05f506, 100, 1); // MP0_NUMBER_SLIPSTREAMS_IN_RACE
		}
		else
		{
			Hash StatsMinusOne[] =
			{
				// MP1_CHAR_FM_CARMOD_1_UNLCK MP1_CHAR_FM_CARMOD_2_UNLCK MP1_CHAR_FM_CARMOD_3_UNLCK MP1_CHAR_FM_CARMOD_4_UNLCK MP1_CHAR_FM_CARMOD_5_UNLCK  
				0x672cdeee, 0xf93314ce, 0x1c07e936, 0xa442c19a, 0xb0a6daa9,
				// MP1_CHAR_FM_CARMOD_6_UNLCK MP1_CHAR_FM_CARMOD_7_UNLCK MP1_CHAR_FM_VEHICLE_1_UNLCK MP1_CHAR_FM_VEHICLE_2_UNLCK
				0x7799e88b, 0x993c61b8, 0x20553352, 0x5a8bf1f7
			};
			for (Hash h : StatsMinusOne)
				CHooking::stat_set_int(h, -1, 1);
 
			// MP1_AWD_FMRALLYWONDRIVE MP1_AWD_FMRALLYWONNAV MP1_AWD_FMWINSEARACE MP1_AWD_FMWINAIRRACE
			Hash Stats1[] = { 0xb43e0e1a, 0xb1590553, 0x58857e4, 0x16f2fd31 };
			for (Hash h : Stats1)
				CHooking::stat_set_int(h, 1, 1);
 
			// MP1_RACES_WON MP1_NUMBER_TURBO_STARTS_IN_RACE MP1_USJS_COMPLETED MP1_AWD_FM_RACES_FASTEST_LAP
			Hash Stats50[] = { 0xb241d53b, 0xb0470aea, 0xde88d22f, 0xe751f17 };
			for (Hash h : Stats50)
				CHooking::stat_set_int(h, 50, 1);
 
			CHooking::stat_set_int(0xe5fd50e2, 100, 1); // MP1_NUMBER_SLIPSTREAMS_IN_RACE
		}
		notify_above_map("Vehicles Unlocked", 0);
	}

	void unlocks_trophies()
	{
		CHooking::stat_set_int(0x53c59a8e, -1, 1); // MPPLY_HEIST_ACH_TRACKER
		CHooking::stat_set_int(0x796d2d6a, 25, 1); // MPPLY_AWD_FM_CR_DM_MADE
		CHooking::stat_set_int(0xd5d5279d, 25, 1); // MPPLY_AWD_FM_CR_RACES_MADE
		CHooking::stat_set_int(0xe00c1321, 100, 1); // MPPLY_AWD_FM_CR_PLAYED_BY_PEEP
 
		if (get_online_player_index() == 0)
		{
			Hash StatsBools[] =
			{
				// MP0_AWD_FM_GOLF_HOLE_IN_1 MP0_AWD_FM_SHOOTRANG_GRAN_WON MP0_AWD_FM_TENNIS_STASETWIN MP0_AWD_FM6DARTCHKOUT MP0_AWD_FMATTGANGHQ
				0x22d9626f, 0x2bfe2b98, 0xcca40e6,  0xb6c51652, 0x49e3d35b,
				// MP0_AWD_BUY_EVERY_GUN MP0_AWD_FMWINEVERYGAMEMODE MP0_AWD_FM25DIFFERENTDM MP0_AWD_FM_TENNIS_5_SET_WINS MP0_AWD_FM25DIFFERENTRACES
				0x21f81ca1, 0xbdda53b4, 0x59de4ddc, 0x69e7c068, 0xb4f06c2f,
				// MP0_AWD_FM25DIFITEMSCLOTHES MP0_AWD_FMFULLYMODDEDCAR MP0_AWD_FMKILL3ANDWINGTARACE MP0_AWD_FMKILLSTREAKSDM MP0_AWD_FMMOSTKILLSGANGHIDE
				0x9ba12d14, 0xe9472bb4, 0x43d56fad, 0x3099c3fe, 0x5941fbad,
				// MP0_AWD_FMMOSTKILLSSURVIVE MP0_AWD_FMRACEWORLDRECHOLDER MP0_AWD_FMPICKUPDLCCRATE1ST MP0_AWD_FMWINCUSTOMRACE MP0_MP0_AWD_FMWINALLRACEMODES
				0xc41b8767, 0x655e0bad, 0x2ae837e4, 0x71212ddf, 0xda28ebe4,
				// MP0_AWD_FMTATTOOALLBODYPARTS
				0xe3520842
			};
 
			for (Hash h : StatsBools)
				CHooking::stat_set_bool(h, 1, 1);
 
			CHooking::stat_set_int(0x723f39d6, 4, 1); // MP0_AWD_PASSENGERTIME
			CHooking::stat_set_int(0x653a8f83, 4, 1); // MP0_AWD_TIME_IN_HELICOPTER
			CHooking::stat_set_int(0x45e1432a, 5, 1); // MP0_MOST_FLIPS_IN_ONE_JUMP
			CHooking::stat_set_int(0xe9e500bc, 5, 1); // MP0_MOST_SPINS_IN_ONE_JUMP
			CHooking::stat_set_int(0x833d3192, 10, 1); // MP0_AWD_FMHORDWAVESSURVIVE
			CHooking::stat_set_int(0x12f3b311, 20, 1); // MP0_AWD_HOLD_UP_SHOPS
 
			Hash Stats25[] =
			{
				// MP0_AWD_CAR_BOMBS_ENEMY_KILLS MP0_AWD_FM_GOLF_WON MP0_AWD_FM_SHOOTRANG_CT_WON MP0_AWD_FM_SHOOTRANG_RT_WON MP0_AWD_FM_SHOOTRANG_TG_WON
				0xaae88a2f, 0xe847156c, 0x741f0838, 0xeac04cce, 0x898dab76,
				// MP0_AWD_FM_TENNIS_WON MP0_AWD_SECURITY_CARS_ROBBED MP0_AWD_LAPDANCES MP0_MOST_ARM_WRESTLING_WINS MP0_AWD_NO_HAIRCUTS
				0xe51a03e4, 0x5413e4e9, 0x4314583e, 0xd9da214e, 0xa43c7aac,
				// MP0_AWD_WIN_AT_DARTS MP0_AWD_FM_GOLF_BIRDIES MP0_AWD_FM_TENNIS_ACE MP0_AWD_PARACHUTE_JUMPS_20M MP0_AWD_PARACHUTE_JUMPS_50M
				0x279625d2, 0x978c6413, 0x7036f468, 0x1e3139c0, 0xd95051b7,
				// MP0_AIR_LAUNCHES_OVER_40M MP0_AWD_FMCRATEDROPS MP0_AWD_FMKILLBOUNTY MP0_AWD_FMSHOOTDOWNCOPHELI MP0_AWD_FMRALLYWONDRIVE
				0x8a8786e7, 0x2671fd3,  0xfb6b31f1, 0xee270322, 0xbb5b1a96,
				// MP0_AWD_FMRALLYWONNAV MP0_AWD_FMWINAIRRACE MP0_AWD_FMWINRACETOPOINTS MP0_AWD_FMWINSEARACE MP0_AWD_FMBASEJMP
				0x6ae2181d, 0x40bf1a36, 0xa11bb5b6, 0xc5c0f286, 0xe54057bd,
				// MP0_AWD_FM_RACE_LAST_FIRST MP0_AWD_FM_RACES_FASTEST_LAP
				0x25609da9, 0xc13d4f3a
			};
 
			for (Hash h : Stats25)
				CHooking::stat_set_int(h, 25, 1);
 
			Hash Stats50[] =
			{
				// MP0_UNARMED_ENEMY_KILLS MP0_STKYBMB_ENEMY_KILLS MP0_GRENADE_ENEMY_KILLS MP0_RPG_ENEMY_KILLS MP0_AWD_FM_DM_WINS
				0x7b47f3c7, 0x2087c74c, 0x85cb967f, 0xb82d3c53, 0x4c2e3849,
				// MP0_AWD_5STAR_WANTED_AVOIDANCE MP0_AWD_CARS_EXPORTED MP0_AWD_FM_GTA_RACES_WON MP0_AWD_FM_TDM_WINS MP0_AWD_RACES_WON
				0xbe3d4bc9, 0x6ad8bf16, 0x9edf3ad7, 0x1fad924e, 0x54305ac6,
				// MP0_AWD_FM_DM_3KILLSAMEGUY MP0_AWD_FM_DM_STOLENKILL MP0_AWD_FM_TDM_MVP MP0_AWD_FMREVENGEKILLSDM
				0x194298a4, 0x8401421f, 0xc479c331, 0xb2f3860f
			};
 
			for (Hash h : Stats50)
				CHooking::stat_set_int(h, 50, 1);
 
			// MP0_SNIPERRFL_ENEMY_KILLS MP0_PASS_DB_PLAYER_KILLS MP0_AWD_FM_DM_KILLSTREAK
			Hash Stats100[] = { 0x422d310, 0x2dd16b4e , 0xe41251dd };
 
			for (Hash h : Stats100)
				CHooking::stat_set_int(h, 100, 1);
 
			CHooking::stat_set_int(0x25ed089e, 255, 1); // MP0_AWD_FMDRIVEWITHOUTCRASH
 
 
			Hash Stats500[] =
			{
				// MP0_PLAYER_HEADSHOTS MP0_PISTOL_ENEMY_KILLS MP0_SAWNOFF_ENEMY_KILLS MP0_MICROSMG_ENEMY_KILLS MP0_ASLTRIFLE_ENEMY_KILLS
				0xee25f949, 0x2216f7ae, 0x1b17a92, 0xb1c7ed0b, 0xaa58ca9d,
				// MP0_MG_ENEMY_KILLS MP0_AWD_VEHICLES_JACKEDR MP0_CARS_EXPLODED MP0_AWD_FM_DM_TOTALKILLS
				0x2dc218c3, 0x8e3ef0b7, 0xa255fada, 0xfac3eb18
			};
 
			for (Hash h : Stats500)
				CHooking::stat_set_int(h, 500, 1);
 
			CHooking::stat_set_int(0x7bd82f11, 1000, 1); // MP0_KILLS_PLAYERS
			CHooking::stat_set_float(0xb14148de, 1000, 1); // MP0_LONGEST_WHEELIE_DIST
			CHooking::stat_set_int(0x69a50e0d, 2147483647, 1); // MP0_CHAR_WANTED_LEVEL_TIME5STAR
		}
		else
		{
			Hash StatsBools[] =
			{
				// MP1_AWD_FM_GOLF_HOLE_IN_1 MP1_AWD_FM_SHOOTRANG_GRAN_WON MP1_AWD_FM_TENNIS_STASETWIN MP1_AWD_FM6DARTCHKOUT MP1_AWD_FMATTGANGHQ
				0x53ce03c5, 0x45b4f9b1, 0x89993cb1, 0xceb4633f, 0x2039515c,
				// MP1_AWD_BUY_EVERY_GUN MP1_AWD_FMWINEVERYGAMEMODE MP1_AWD_FM25DIFFERENTDM MP1_AWD_FM_TENNIS_5_SET_WINS MP1_AWD_FM25DIFFERENTRACES
				0xf3a9910f, 0x4ae88781, 0x99e2c583, 0x9fcb6ca4, 0xf2e60934,
				// MP1_AWD_FM25DIFITEMSCLOTHES MP1_AWD_FMFULLYMODDEDCAR MP1_AWD_FMKILL3ANDWINGTARACE MP1_AWD_FMKILLSTREAKSDM MP1_AWD_FMMOSTKILLSGANGHIDE
				0x41f88bc1, 0xe7c84055, 0xbe3fd785, 0xf3d60861, 0x6d7f3349,
				// MP1_AWD_FMMOSTKILLSSURVIVE MP1_AWD_FMRACEWORLDRECHOLDER MP1_AWD_FMPICKUPDLCCRATE1ST MP1_AWD_FMWINCUSTOMRACE MP1_MP0_AWD_FMWINALLRACEMODES
				0x98ff48a5, 0x90867f4c, 0x3804231b, 0x19c6dc16, 0xc4fa67ee,
				// MP1_AWD_FMTATTOOALLBODYPARTS
				0xab668908
			};
 
			for (Hash h : StatsBools)
				CHooking::stat_set_bool(h, 1, 1);
 
 
			CHooking::stat_set_int(0xa24ba69a, 4, 1); // MP1_AWD_PASSENGERTIME
			CHooking::stat_set_int(0x1fa36d2, 4, 1); // MP1_AWD_TIME_IN_HELICOPTER
			CHooking::stat_set_int(0xeecca992, 5, 1); // MP1_MOST_FLIPS_IN_ONE_JUMP
			CHooking::stat_set_int(0x34c1f2c1, 5, 1); // MP1_MOST_SPINS_IN_ONE_JUMP
			CHooking::stat_set_int(0x18f27d05, 10, 1); // MP1_AWD_FMHORDWAVESSURVIVE
			CHooking::stat_set_int(0x36177f20, 20, 1); // MP1_AWD_HOLD_UP_SHOPS
 
			Hash Stats25[] =
			{
				// MP1_AWD_CAR_BOMBS_ENEMY_KILLS MP1_AWD_FM_GOLF_WON MP1_AWD_FM_SHOOTRANG_CT_WON MP1_AWD_FM_SHOOTRANG_RT_WON MP1_AWD_FM_SHOOTRANG_TG_WON
				0x1af2de9e, 0xa1787290, 0x5f76739a, 0xd356f78f, 0x2c177bad,
				// MP1_AWD_FM_TENNIS_WON MP1_AWD_SECURITY_CARS_ROBBED MP1_AWD_LAPDANCES MP1_MOST_ARM_WRESTLING_WINS MP1_AWD_NO_HAIRCUTS
				0xec234ae2, 0x46533e0c, 0xf29d01d9, 0x3ede081c, 0xc55aafaa,
				// MP1_AWD_WIN_AT_DARTS MP1_AWD_FM_GOLF_BIRDIES MP1_AWD_FM_TENNIS_ACE MP1_AWD_PARACHUTE_JUMPS_20M MP1_AWD_PARACHUTE_JUMPS_50M
				0x61f5db39, 0x786e5b58, 0xae352aa3, 0xafbb09a3, 0x2f6c1441,
				// MP1_AIR_LAUNCHES_OVER_40M MP1_AWD_FMCRATEDROPS MP1_AWD_FMKILLBOUNTY MP1_AWD_FMSHOOTDOWNCOPHELI MP1_AWD_FMRALLYWONDRIVE
				0xe7939c0b, 0x144e7d9f, 0x4f6cded8, 0xf5edcaba, 0xb43e0e1a,
				// MP1_AWD_FMRALLYWONNAV MP1_AWD_FMWINAIRRACE MP1_AWD_FMWINRACETOPOINTS MP1_AWD_FMWINSEARACE MP1_AWD_FMBASEJMP
				0xb1590553, 0x16f2fd31, 0x5a1942e7, 0x58857e4, 0xfa2e93ff,
				// MP1_AWD_FM_RACE_LAST_FIRST MP1_AWD_FM_RACES_FASTEST_LAP
				0x3a2621d6, 0xe751f17
			};
 
			for (Hash h : Stats25)
				CHooking::stat_set_int(h, 25, 1);
 
			Hash Stats50[] =
			{
				// MP1_UNARMED_ENEMY_KILLS MP1_STKYBMB_ENEMY_KILLS MP1_GRENADE_ENEMY_KILLS MP1_RPG_ENEMY_KILLS MP1_AWD_FM_DM_WINS
				0x88cd257a, 0x6e028b1b, 0x792b2764, 0x17855e7c, 0x34069be5,
				// MP1_AWD_5STAR_WANTED_AVOIDANCE MP1_AWD_CARS_EXPORTED MP1_AWD_FM_GTA_RACES_WON MP1_AWD_FM_TDM_WINS MP1_AWD_RACES_WON
				0xf641f229, 0x616b3f61, 0xb22750e1, 0x1198da99, 0x43bda5d0,
				// MP1_AWD_FM_DM_3KILLSAMEGUY MP1_AWD_FM_DM_STOLENKILL MP1_AWD_FM_TDM_MVP MP1_AWD_FMREVENGEKILLSDM
				0x588cc6bc, 0x55e4f0b1, 0x2199954e, 0x52326867
			};
 
			for (Hash h : Stats50)
				CHooking::stat_set_int(h, 50, 1);
 
			// MP1_SNIPERRFL_ENEMY_KILLS MP1_PASS_DB_PLAYER_KILLS MP1_AWD_FM_DM_KILLSTREAK
			Hash Stats100[] = { 0xff18ad04, 0x5f639fb2 , 0x2e9eeca9 };
 
			for (Hash h : Stats100)
				CHooking::stat_set_int(h, 100, 1);
 
			CHooking::stat_set_int(0x5eaa0099, 255, 1); // MP1_AWD_FMDRIVEWITHOUTCRASH
 
			Hash Stats500[] =
			{
				// MP1_PLAYER_HEADSHOTS MP1_PISTOL_ENEMY_KILLS MP1_SAWNOFF_ENEMY_KILLS MP1_MICROSMG_ENEMY_KILLS MP1_ASLTRIFLE_ENEMY_KILLS
				0x3363cba7, 0x51931124, 0x2be59e29, 0x3ce45119, 0xacce32b0,
				// MP1_MG_ENEMY_KILLS MP1_AWD_VEHICLES_JACKEDR MP1_CARS_EXPLODED MP1_AWD_FM_DM_TOTALKILLS
				0x5356f2fb, 0x1d53d003, 0xbb7cddd3, 0x76da8dde
			};
 
			for (Hash h : Stats500)
				CHooking::stat_set_int(h, 500, 1);
 
			CHooking::stat_set_int(0xf21f4859, 1000, 1); // MP1_KILLS_PLAYERS
			CHooking::stat_set_float(0x361609bc, 1000, 1); // MP1_LONGEST_WHEELIE_DIST
			CHooking::stat_set_int(0x5873796d, 2147483647, 1); // MP1_CHAR_WANTED_LEVEL_TIME5STAR
 
		}
		notify_above_map("Trophies Unlocked", 0);
	}

	void unlocks_hairstyles()
	{
		if (get_online_player_index() == 0)
		{
			// MP0_CLTHS_AVAILABLE_HAIR MP0_CLTHS_AVAILABLE_HAIR_1 MP0_CLTHS_AVAILABLE_HAIR_2 MP0_CLTHS_AVAILABLE_HAIR_3 MP0_CLTHS_AVAILABLE_HAIR_4 MP0_CLTHS_AVAILABLE_HAIR_5 MP0_CLTHS_AVAILABLE_HAIR_6 MP0_CLTHS_AVAILABLE_HAIR_7
			Hash HairStyles[] = { 0x3cc6316a, 0x50763097 ,0x67ad5f05 ,0x2d1769da, 0x4269947e, 0x2c646868, 0x42e09560, 0xa07a3af };
			for (Hash h : HairStyles)
				CHooking::stat_set_int(h, -1, 1);
		}
		else
		{
			// MP1_CLTHS_AVAILABLE_HAIR MP1_CLTHS_AVAILABLE_HAIR_1 MP1_CLTHS_AVAILABLE_HAIR_2 MP1_CLTHS_AVAILABLE_HAIR_3 MP1_CLTHS_AVAILABLE_HAIR_4 MP1_CLTHS_AVAILABLE_HAIR_5 MP1_CLTHS_AVAILABLE_HAIR_6 MP1_CLTHS_AVAILABLE_HAIR_7
			Hash HairStyles[] = { 0x2a9fd8ce, 0x485a4609 ,0x569fe294 ,0xd6f4633b, 0xac7e0e4f, 0xf94d47f, 0x1dc670e2, 0x81da390c };
			for (Hash h : HairStyles)
				CHooking::stat_set_int(h, -1, 1);
		}
		notify_above_map("Hairstyles Unlocked", 0);
	}
 
	void unlocks_weapons()
	{
		// Weapons
		if(get_online_player_index() == 0)
		{      
			Hash StatsMinusOne[] =
			{
				// MP0_ADMIN_WEAPON_GV_BS_1 MP0_ADMIN_WEAPON_GV_BS_2 MP0_ADMIN_WEAPON_GV_BS_3 MP0_BOTTLE_IN_POSSESSION MP0_CHAR_FM_WEAP_UNLOCKED
				0x6b779763, 0x2fcea012, 0x4608cc86, 0xe0682331, 0xc0362f66,
				// MP0_CHAR_FM_WEAP_UNLOCKED2 MP0_CHAR_WEAP_FM_PURCHASE MP0_CHAR_WEAP_FM_PURCHASE2 MP0_CHAR_FM_WEAP_ADDON_1_UNLCK MP0_CHAR_FM_WEAP_ADDON_2_UNLCK
				0xddff5128, 0x1b739cce, 0xf4b34427, 0xb0ffbb50, 0x2002f91,
				// MP0_CHAR_FM_WEAP_ADDON_3_UNLCK MP0_CHAR_FM_WEAP_ADDON_4_UNLCK MP0_CHAR_FM_WEAP_ADDON_5_UNLCK MP0_WEAP_FM_ADDON_PURCH MP0_WEAP_FM_ADDON_PURCH2
				0x77238ee3, 0xc0e8c793, 0xa06b70a7, 0x66310122, 0x77c2416b,
				// MP0_WEAP_FM_ADDON_PURCH3 MP0_WEAP_FM_ADDON_PURCH4 MP0_WEAP_FM_ADDON_PURCH5  
				0xdb9d091b, 0xe97424c9, 0xbf3e505e
			};
			for (Hash h : StatsMinusOne)
				CHooking::stat_set_int(h, -1, 1);

			//skins
			Hash Skins[] =
			{
				/*MP0_MOLOTOV_ENEMY_KILLS, MP0_CMBTPISTOL_ENEMY_KILLS, MP0_PISTOL50_ENEMY_KILLS, MP0_APPISTOL_ENEMY_KILLS, MP0_MICROSMG_ENEMY_KILLS,
				MP0_SMG_ENEMY_KILLS, MP0_ASLTSMG_ENEMY_KILLS, MP0_ASLTRIFLE_ENEMY_KILLS, MP0_CRBNRIFLE_ENEMY_KILLS, MP0_ADVRIFLE_ENEMY_KILLS,
				MP0_MG_ENEMY_KILLS, MP0_CMBTMG_ENEMY_KILLS, MP0_ASLTMG_ENEMY_KILLS, MP0_PUMP_ENEMY_KILLS, MP0_SAWNOFF_ENEMY_KILLS,
				MP0_BULLPUP_ENEMY_KILLS, MP0_ASLTSHTGN_ENEMY_KILLS, MP0_SNIPERRFL_ENEMY_KILLS, MP0_HVYSNIPER_ENEMY_KILLS, MP0_GRNLAUNCH_ENEMY_KILLS,
				MP0_RPG_ENEMY_KILLS, MP0_MINIGUNS_ENEMY_KILLS, MP0_GRENADE_ENEMY_KILLS, MP0_SMKGRENADE_ENEMY_KILLS, MP0_STKYBMB_ENEMY_KILLS,
				MP0_MOLOTOV_ENEMY_KILLS*/
				0x9ce23b8d, 0x34551d31, 0x72c8b289, 0xb3b0246b, 0xb1c7ed0b,
				0x7a42f6b3, 0x356623f1, 0xaa58ca9d, 0x5a9b4cdf, 0xab0ec253,
				0x2dc218c3, 0x9163995c, 0x3fe1312b, 0x1e6148ff, 0x1b17a92,
				0xf0a2b61a, 0x4d474708, 0x422d310, 0x1e6d5243, 0x8ac8e746,
				0xb82d3c53, 0x56baf664, 0x85cb967f, 0x4b31cd19, 0x2087c74c,
				0x9ce23b8d,
			};
			for (Hash h : Skins)
				CHooking::stat_set_int(h, 600, 1);
		}
		else
		{
			Hash StatsMinusOne[] =
			{
				// MP1_ADMIN_WEAPON_GV_BS_1 MP1_ADMIN_WEAPON_GV_BS_2 MP1_ADMIN_WEAPON_GV_BS_3 MP1_BOTTLE_IN_POSSESSION MP1_CHAR_FM_WEAP_UNLOCKED
				0x2ac777ec , 0x1894d387, 0x1261471c, 0x9099e601, 0x811fad39,
				// MP0_CHAR_FM_WEAP_UNLOCKED2 MP0_CHAR_WEAP_FM_PURCHASE MP0_CHAR_WEAP_FM_PURCHASE2 MP0_CHAR_FM_WEAP_ADDON_1_UNLCK MP0_CHAR_FM_WEAP_ADDON_2_UNLCK
				0xe1551844, 0x25f16d26, 0x3211e42, 0x2a79d08a, 0xa9ea99f2,
				// MP0_CHAR_FM_WEAP_ADDON_3_UNLCK MP0_CHAR_FM_WEAP_ADDON_4_UNLCK MP0_CHAR_FM_WEAP_ADDON_5_UNLCK MP0_WEAP_FM_ADDON_PURCH MP0_WEAP_FM_ADDON_PURCH2
				0x8bb0f098, 0x5d5099e7, 0xec16309b, 0xe1ea41ec, 0x97deb095,
				// MP0_WEAP_FM_ADDON_PURCH3 MP0_WEAP_FM_ADDON_PURCH4 MP0_WEAP_FM_ADDON_PURCH5
				0xa98d53f2, 0x1ed43e86, 0x2cc3da65
			};
			for (Hash h : StatsMinusOne)
				CHooking::stat_set_int(h, -1, 1);

			//skins
			Hash Skins[] =
			{
				/*MP1_MOLOTOV_ENEMY_KILLS, MP1_CMBTPISTOL_ENEMY_KILLS, MP1_PISTOL50_ENEMY_KILLS, MP1_APPISTOL_ENEMY_KILLS, MP1_MICROSMG_ENEMY_KILLS,
				MP1_SMG_ENEMY_KILLS, MP1_ASLTSMG_ENEMY_KILLS, MP1_ASLTRIFLE_ENEMY_KILLS, MP1_CRBNRIFLE_ENEMY_KILLS, MP1_ADVRIFLE_ENEMY_KILLS,
				MP1_MG_ENEMY_KILLS, MP1_CMBTMG_ENEMY_KILLS, MP1_ASLTMG_ENEMY_KILLS, MP1_PUMP_ENEMY_KILLS, MP1_SAWNOFF_ENEMY_KILLS,
				MP1_BULLPUP_ENEMY_KILLS, MP1_ASLTSHTGN_ENEMY_KILLS, MP1_SNIPERRFL_ENEMY_KILLS, MP1_HVYSNIPER_ENEMY_KILLS, MP1_GRNLAUNCH_ENEMY_KILLS,
				MP1_RPG_ENEMY_KILLS, MP1_MINIGUNS_ENEMY_KILLS, MP1_GRENADE_ENEMY_KILLS, MP1_SMKGRENADE_ENEMY_KILLS, MP1_STKYBMB_ENEMY_KILLS,
				MP1_MOLOTOV_ENEMY_KILLS*/
				0x9fab8be1, 0x22f04348, 0xa0094888, 0x93fe1a03, 0x3ce45119,
				0xe076b62, 0xe31e5e37, 0xacce32b0, 0x68dc8501, 0xe00b3050,
				0x5356f2fb, 0x75836942, 0x555d99a8, 0x97020ed3, 0x2be59e29,
				0xdd2ab0f1, 0xb7d02daf, 0xff18ad04, 0xb51962a0, 0xaba404eb,
				0x17855e7c, 0x5fac9c28, 0x792b2764, 0xa68aa848, 0x6e028b1b,
				0x9fab8be1, 
			};
			for (Hash h : Skins)
				CHooking::stat_set_int(h, 600, 1);
		}
		notify_above_map("Weapons Unlocked", 0);
	}

	void unlocks_clothes()
	{
		if (get_online_player_index() == 0)
		{
			Hash Clothes[] =
			{
				// MP0_CLTHS_AVAILABLE_HAIR MP0_CLTHS_AVAILABLE_HAIR_1 MP0_CLTHS_AVAILABLE_HAIR_2 MP0_CLTHS_AVAILABLE_HAIR_3 MP0_CLTHS_AVAILABLE_HAIR_4
				//0x3cc6316a, 0x50763097, 0x67ad5f05, 0x2d1769da, 0x4269947e,
				// MP0_CLTHS_AVAILABLE_HAIR_5 MP0_CLTHS_AVAILABLE_HAIR_6 MP0_CLTHS_AVAILABLE_HAIR_7
				//0x2c646868, 0x42e09560, 0xa07a3af,
				// MP0_CLTHS_AVAILABLE_JBIB MP0_CLTHS_AVAILABLE_JBIB_1 MP0_CLTHS_AVAILABLE_JBIB_2 MP0_CLTHS_AVAILABLE_JBIB_3 MP0_CLTHS_AVAILABLE_JBIB_4
				0xea3729c5, 0x8c5f29f1, 0x65915c56, 0x67d160d6, 0xd143b3d5,
				// MP0_CLTHS_AVAILABLE_JBIB_5 MP0_CLTHS_AVAILABLE_JBIB_6 MP0_CLTHS_AVAILABLE_JBIB_7
				0xe38ad863, 0xb0e672ff, 0xc027119c,
				// MP0_CLTHS_AVAILABLE_LEGS MP0_CLTHS_AVAILABLE_LEGS_1 MP0_CLTHS_AVAILABLE_LEGS_2 MP0_CLTHS_AVAILABLE_LEGS_3 MP0_CLTHS_AVAILABLE_LEGS_4
				0xb8b3e0c6, 0xd1ebfd1,  0xc3aeacfa, 0xd7c408c,  0xe81375c3,
				// MP0_CLTHS_AVAILABLE_LEGS_5 MP0_CLTHS_AVAILABLE_LEGS_6 MP0_CLTHS_AVAILABLE_LEGS_7
				0xb1730883, 0xce014193, 0xdf45e41c,
				// MP0_CLTHS_AVAILABLE_FEET MP0_CLTHS_AVAILABLE_FEET_1 MP0_CLTHS_AVAILABLE_FEET_2 MP0_CLTHS_AVAILABLE_FEET_3 MP0_CLTHS_AVAILABLE_FEET_4
				0x97573104, 0x93ed984b, 0x623c34e5, 0x7369d740, 0x1cb129e0,
				// MP0_CLTHS_AVAILABLE_FEET_5 MP0_CLTHS_AVAILABLE_FEET_6 MP0_CLTHS_AVAILABLE_FEET_7
				0x2ce3ca45, 0xfb1866ab, 0x9a003be,
				// MP0_CLTHS_AVAILABLE_BERD MP0_CLTHS_AVAILABLE_BERD_1 MP0_CLTHS_AVAILABLE_BERD_2 MP0_CLTHS_AVAILABLE_BERD_3 MP0_CLTHS_AVAILABLE_BERD_4
				0x14b08e07, 0x6f8f492d, 0x21a72d5e, 0x74f2d3f8, 0x269db74f,
				// MP0_CLTHS_AVAILABLE_BERD_5 MP0_CLTHS_AVAILABLE_BERD_6 MP0_CLTHS_AVAILABLE_BERD_7
				0x4f5708c1, 0x8133ec7a, 0xca99ff41,
				// MP0_CLTHS_AVAILABLE_PROPS MP0_CLTHS_AVAILABLE_PROPS_1 MP0_CLTHS_AVAILABLE_PROPS_2 MP0_CLTHS_AVAILABLE_PROPS_3 MP0_CLTHS_AVAILABLE_PROPS_4
				0xb051c305, 0x7d5c4692, 0x7555b685, 0x62da918f, 0xd8217c1b,
				// MP0_CLTHS_AVAILABLE_PROPS_5 MP0_CLTHS_AVAILABLE_PROPS_6 MP0_CLTHS_AVAILABLE_PROPS_7 MP0_CLTHS_AVAILABLE_PROPS_8 MP0_CLTHS_AVAILABLE_PROPS_9
				0xc665d8a4, 0xb6e439a1, 0xa431143b, 0xda520080, 0x9ca5f70,
				// MP0_CLTHS_AVAILABLE_PROPS_10 MP0_CLTHS_AVAILABLE_OUTFIT MP0_CLTHS_ACQUIRED_HAIR MP0_CLTHS_ACQUIRED_HAIR_1 MP0_CLTHS_ACQUIRED_HAIR_2
				0x4c7f28e9, 0xd4b41ccb, 0xa01511e1, 0x2415af29, 0x12630bc4,
				// MP0_CLTHS_ACQUIRED_HAIR_3 MP0_CLTHS_ACQUIRED_HAIR_4 MP0_CLTHS_ACQUIRED_HAIR_5 MP0_CLTHS_ACQUIRED_HAIR_6 MP0_CLTHS_ACQUIRED_HAIR_7
				0x41e4eabf, 0x2f96c623, 0x2b48bd87, 0x1922193a, 0x888a7809,
				// MP0_CLTHS_ACQUIRED_JBIB MP0_CLTHS_ACQUIRED_JBIB_1 MP0_CLTHS_ACQUIRED_JBIB_2 MP0_CLTHS_ACQUIRED_JBIB_3 MP0_CLTHS_ACQUIRED_JBIB_4
				0xaea92fe3, 0xa05ef149, 0x93bfd80b, 0x7a90a5ad, 0x69730372,
				// MP0_CLTHS_ACQUIRED_JBIB_5 MP0_CLTHS_ACQUIRED_JBIB_6 MP0_CLTHS_ACQUIRED_JBIB_7
				0x5e0eeca6, 0x281f80d4, 0x1d856ba0,
				// MP0_CLTHS_ACQUIRED_LEGS MP0_CLTHS_ACQUIRED_LEGS_1 MP0_CLTHS_ACQUIRED_LEGS_2 MP0_CLTHS_ACQUIRED_LEGS_3 MP0_CLTHS_ACQUIRED_LEGS_4
				0x66e4ca67, 0x1b3dca99, 0x598d4737, 0x7c223a2,  0x3ce78dec,
				// MP0_CLTHS_ACQUIRED_LEGS_5 MP0_CLTHS_ACQUIRED_LEGS_6 MP0_CLTHS_ACQUIRED_LEGS_7
				0x6b266a69, 0xa01cd459, 0x4df12fff,
				// MP0_CLTHS_ACQUIRED_FEET MP0_CLTHS_ACQUIRED_FEET_1 MP0_CLTHS_ACQUIRED_FEET_2 MP0_CLTHS_ACQUIRED_FEET_3 MP0_CLTHS_ACQUIRED_FEET_4
				0x12b66dab, 0xcfd67d8b, 0x7964d0a9, 0xaeaf3b3d, 0x56a80b30,
				// MP0_CLTHS_ACQUIRED_FEET_5 MP0_CLTHS_ACQUIRED_FEET_6 MP0_CLTHS_ACQUIRED_FEET_7
				0x88eaefb5, 0x327342bf, 0x63b5254a,
				// MP0_CLTHS_ACQUIRED_BERD MP0_CLTHS_ACQUIRED_BERD_1 MP0_CLTHS_ACQUIRED_BERD_2 MP0_CLTHS_ACQUIRED_BERD_3 MP0_CLTHS_ACQUIRED_BERD_4
				0x2de14803, 0x19299a7d, 0x2b3e3ea6, 0x7574d312, 0x87e277ed,
				// MP0_CLTHS_ACQUIRED_BERD_5 MP0_CLTHS_ACQUIRED_BERD_6 MP0_CLTHS_ACQUIRED_BERD_7
				0x74a9d180, 0x86d375d3, 0x50ec0a05,
				// MP0_CLTHS_ACQUIRED_PROPS MP0_CLTHS_ACQUIRED_PROPS_1 MP0_CLTHS_ACQUIRED_PROPS_2 MP0_CLTHS_ACQUIRED_PROPS_3 MP0_CLTHS_ACQUIRED_PROPS_4
				0xd846c640, 0x18ea3634, 0x3460aec,  0xa1d5c80d, 0x5573af4a,
				// MP0_CLTHS_ACQUIRED_PROPS_5 MP0_CLTHS_ACQUIRED_PROPS_6 MP0_CLTHS_ACQUIRED_PROPS_7 MP0_CLTHS_ACQUIRED_PROPS_8 MP0_CLTHS_ACQUIRED_PROPS_9
				0x3f3182c6, 0x6ad05a03, 0xeaecda3a, 0x9d25bead, 0x87779351,
				// MP0_CLTHS_ACQUIRED_PROPS_10 MP0_CLTHS_ACQUIRED_OUTFIT MP0_CLTHS_AVAILABLE_TORSO MP0_CLTHS_AVAILABLE_SPECIAL MP0_CLTHS_AVAILABLE_SPECIAL_1
				0x466c7ee5, 0xe667df2c, 0x8eb5a109, 0x135b7256, 0x17e66c11,
				// MP0_CLTHS_AVAILABLE_SPECIAL_2 MP0_CLTHS_AVAILABLE_SPECIAL_3 MP0_CLTHS_AVAILABLE_SPECIAL_4 MP0_CLTHS_AVAILABLE_SPECIAL_5 MP0_CLTHS_AVAILABLE_SPECIAL_6
				0x5e5b78fa, 0x2f9c9b7d, 0xeb7a1335, 0x11f3e7f,  0x753cae8,
				// MP0_CLTHS_AVAILABLE_SPECIAL_7 MP0_CLTHS_AVAILABLE_DECL MP0_CLTHS_AVAILABLE_TEETH MP0_CLTHS_AVAILABLE_TEETH_1 MP0_CLTHS_AVAILABLE_TEETH_2
				0x1c91f564, 0x9c7866c7, 0xba50aedd, 0x2e99d7e,  0x112339f1,
				// MP0_CLTHS_ACQUIRED_TORSO MP0_CLTHS_ACQUIRED_SPECIAL MP0_CLTHS_ACQUIRED_SPECIAL_1 MP0_CLTHS_ACQUIRED_SPECIAL_2 MP0_CLTHS_ACQUIRED_SPECIAL_3
				0x85648a0a, 0xd1c336af, 0x5a1bdf57, 0x70020b23, 0x7cc0249f,
				// MP0_CLTHS_ACQUIRED_SPECIAL_4 MP0_CLTHS_ACQUIRED_SPECIAL_5 MP0_CLTHS_ACQUIRED_SPECIAL_6 MP0_CLTHS_ACQUIRED_SPECIAL_7 MP0_CLTHS_ACQUIRED_SPECIAL2
				0x42733006, 0xa132ed84, 0xd96fddfd, 0xe5b1f681, 0x8803887c,
				// MP0_CLTHS_ACQUIRED_SPECIAL2_1 MP0_CLTHS_ACQUIRED_DECL MP0_CLTHS_ACQUIRED_TEETH MP0_CLTHS_ACQUIRED_TEETH_1 MP0_CLTHS_ACQUIRED_TEETH_2
				0x7e9b5630, 0x9e36043,  0xa1425b8,  0x91050cea, 0x68fc3cd5,
				// MP0_DLC_APPAREL_ACQUIRED_0 MP0_DLC_APPAREL_ACQUIRED_1 MP0_DLC_APPAREL_ACQUIRED_2 MP0_DLC_APPAREL_ACQUIRED_3 MP0_DLC_APPAREL_ACQUIRED_4
				0x58087574, 0x4dffe16f, 0x402645bc, 0xf0942689, 0xea6a1a35,
				// MP0_DLC_APPAREL_ACQUIRED_5 MP0_DLC_APPAREL_ACQUIRED_6 MP0_DLC_APPAREL_ACQUIRED_7 MP0_DLC_APPAREL_ACQUIRED_8 MP0_DLC_APPAREL_ACQUIRED_9
				0x1b87fc70, 0x6e4d32a,  0xb80eb57f, 0xd156e80f, 0xa00e858b,
				// MP0_DLC_APPAREL_ACQUIRED_10 MP0_DLC_APPAREL_ACQUIRED_11 MP0_DLC_APPAREL_ACQUIRED_12 MP0_DLC_APPAREL_ACQUIRED_13 MP0_DLC_APPAREL_ACQUIRED_14
				0x786ce981, 0x5e25b4f3, 0x851d82e2, 0xfa586d56, 0xb14a5b3b,
				// MP0_DLC_APPAREL_ACQUIRED_15 MP0_DLC_APPAREL_ACQUIRED_16 MP0_DLC_APPAREL_ACQUIRED_17 MP0_DLC_APPAREL_ACQUIRED_18 MP0_DLC_APPAREL_ACQUIRED_19
				0x978b27bd, 0x41c27c29, 0x2fffd8a4, 0xde5e3562, 0xcca491ef,
				// MP0_DLC_APPAREL_ACQUIRED_21 MP0_DLC_APPAREL_ACQUIRED_22 MP0_DLC_APPAREL_ACQUIRED_23 MP0_DLC_APPAREL_ACQUIRED_24 MP0_DLC_APPAREL_ACQUIRED_24
				0x6bc7cf17, 0xc7a886d7, 0xd543220c, 0x1d1931b7, 0x1d1931b7,
				// MP0_DLC_APPAREL_ACQUIRED_25 MP0_DLC_APPAREL_ACQUIRED_26 MP0_DLC_APPAREL_ACQUIRED_27 MP0_DLC_APPAREL_ACQUIRED_28 MP0_DLC_APPAREL_ACQUIRED_29
				0x32be5d01, 0xd594a2b7, 0xeb77ce7d, 0x3304dd96, 0x40c67919,
				// MP0_DLC_APPAREL_ACQUIRED_30 MP0_DLC_APPAREL_ACQUIRED_31 MP0_DLC_APPAREL_ACQUIRED_32 MP0_DLC_APPAREL_ACQUIRED_33 MP0_DLC_APPAREL_ACQUIRED_34
				0x21993997, 0x76cee405, 0x3d23f0ac, 0x32addbc0, 0xe09e37a2,
				// MP0_DLC_APPAREL_ACQUIRED_35 MP0_DLC_APPAREL_ACQUIRED_36 MP0_DLC_APPAREL_ACQUIRED_37 MP0_DLC_APPAREL_ACQUIRED_38 MP0_DLC_APPAREL_ACQUIRED_39
				0xce3492cf, 0x94611f25, 0x2c57bf0,  0x98902783, 0x865d831e,
				// MP0_DLC_APPAREL_ACQUIRED_40 MP0_ADMIN_CLOTHES_GV_BS_1 MP0_ADMIN_CLOTHES_GV_BS_2 MP0_ADMIN_CLOTHES_GV_BS_3 MP0_ADMIN_CLOTHES_GV_BS_4
				0xd3c59cd1, 0x62e2d64,  0xbc5d19bb, 0xaaedf6dd, 0xd130c362,
				// MP0_ADMIN_CLOTHES_GV_BS_5 MP0_ADMIN_CLOTHES_GV_BS_6 MP0_ADMIN_CLOTHES_GV_BS_7 MP0_ADMIN_CLOTHES_GV_BS_8 MP0_ADMIN_CLOTHES_GV_BS_9
				0xcf3cbf7a, 0x65536ba9, 0x4f824007, 0x85d0aca3, 0x746309c8,
				// MP0_ADMIN_CLOTHES_GV_BS_10 MP0_ADMIN_CLOTHES_GV_BS_11 MP0_ADMIN_CLOTHES_GV_BS_12 MP0_ADMIN_CLOTHES_GV_BS_13
				0xcb76a780, 0xe6a9dde6, 0xefe2f058, 0x1f90cd,
			};
			for (Hash h : Clothes)
				CHooking::stat_set_int(h, -1, 1);

			//tshirts
			CHooking::stat_set_bool(0x9cf3d019, 1, 1); // MP0_AWD_FINISH_HEIST_NO_DAMAGE
			CHooking::stat_set_bool(0x45b6712, 1, 1); // MP0_AWD_STORE_20_CAR_IN_GARAGES
 
			CHooking::stat_set_int(0x2ae837e4, 1, 1); // MP0_AWD_FMPICKUPDLCCRATE1ST also in trophies
			CHooking::stat_set_int(0x833d3192, 10, 1); // MP0_AWD_FMHORDWAVESSURVIVE also in trophies
 
			// MP0_AWD_WIN_CAPTURE_DONT_DYING MP0_AWD_DO_HEIST_AS_MEMBER MP0_AWD_WIN_GOLD_MEDAL_HEISTS MP0_AWD_KILL_TEAM_YOURSELF_LTS MP0_AWD_DO_HEIST_AS_THE_LEADER
			Hash Stats25[] = { 0x68d14c4e, 0x470055dc, 0x9f9ff03c, 0x4930d051, 0xc32a1dd9 };
			for (Hash h : Stats25)
				CHooking::stat_set_int(h, 25, 1);
 
			CHooking::stat_set_int(0x30418014, 100, 1); // MP0_AWD_PICKUP_CAP_PACKAGES
			CHooking::stat_set_int(0xe2a9b0c4, 100, 1); // MP0_AWD_KILL_PSYCHOPATHS
		}
		else
		{
			Hash Clothes[] =
			{
				// MP1_CLTHS_AVAILABLE_FEET_1 MP1_CLTHS_AVAILABLE_HAIR MP1_CLTHS_AVAILABLE_HAIR_1 MP1_CLTHS_AVAILABLE_HAIR_2 MP1_CLTHS_AVAILABLE_HAIR_3
				1348961870, 715118798,  1213875721, 1453318804, 3606340411,
				// MP1_CLTHS_AVAILABLE_HAIR_4 MP1_CLTHS_AVAILABLE_HAIR_5 MP1_CLTHS_AVAILABLE_HAIR_6 MP1_CLTHS_AVAILABLE_HAIR_7
				2893942351, 261411967,  499544290,  2178562316,
				// MP1_CLTHS_AVAILABLE_JBIB MP1_CLTHS_AVAILABLE_JBIB_1 MP1_CLTHS_AVAILABLE_JBIB_2 MP1_CLTHS_AVAILABLE_JBIB_3 MP1_CLTHS_AVAILABLE_JBIB_4
				275330775,  1777222023, 852513612,  1735244934, 245795577,
				// MP1_CLTHS_AVAILABLE_JBIB_5 MP1_CLTHS_AVAILABLE_JBIB_6 MP1_CLTHS_AVAILABLE_JBIB_7
				1146156621, 681754349,  382147382,
				// MP1_CLTHS_AVAILABLE_LEGS MP1_CLTHS_AVAILABLE_LEGS_1 MP1_CLTHS_AVAILABLE_LEGS_2 MP1_CLTHS_AVAILABLE_LEGS_3 MP1_CLTHS_AVAILABLE_LEGS_4
				2709004519, 2485849916, 39021451,   4230471476, 3931716503,
				// MP1_CLTHS_AVAILABLE_LEGS_5 MP1_CLTHS_AVAILABLE_LEGS_6 MP1_CLTHS_AVAILABLE_LEGS_7
				3618838091, 1169715804, 895144353,
				// MP1_CLTHS_AVAILABLE_FEET MP1_CLTHS_AVAILABLE_FEET_1 MP1_CLTHS_AVAILABLE_FEET_2 MP1_CLTHS_AVAILABLE_FEET_3 MP1_CLTHS_AVAILABLE_FEET_4
				4102624674, 1348961870, 1580868083, 2076990743, 2307258506,
				// MP1_CLTHS_AVAILABLE_FEET_5 MP1_CLTHS_AVAILABLE_FEET_6 MP1_CLTHS_AVAILABLE_FEET_7
				394007672,  755122052,  1068557541,
				// MP1_CLTHS_AVAILABLE_BERD MP1_CLTHS_AVAILABLE_BERD_1 MP1_CLTHS_AVAILABLE_BERD_2 MP1_CLTHS_AVAILABLE_BERD_3 MP1_CLTHS_AVAILABLE_BERD_4
				1928518208, 3770082493, 3462414352, 3457826692, 3154942825,
				// MP1_CLTHS_AVAILABLE_BERD_5 MP1_CLTHS_AVAILABLE_BERD_6 MP1_CLTHS_AVAILABLE_BERD_7
				3918132827, 3640087862, 2404336095,
				// MP1_CLTHS_AVAILABLE_PROPS MP1_CLTHS_AVAILABLE_PROPS_1 MP1_CLTHS_AVAILABLE_PROPS_2 MP1_CLTHS_AVAILABLE_PROPS_3 MP1_CLTHS_AVAILABLE_PROPS_4
				3337566278, 3036428004, 2789284206, 3647471547, 3131425335,
				// MP1_CLTHS_AVAILABLE_PROPS_5 MP1_CLTHS_AVAILABLE_PROPS_6 MP1_CLTHS_AVAILABLE_PROPS_7 MP1_CLTHS_AVAILABLE_PROPS_8 MP1_CLTHS_AVAILABLE_PROPS_9
				1503952950, 2401233708, 2121943521, 2946182182, 585962184,
				// MP1_CLTHS_AVAILABLE_PROPS_10 MP1_CLTHS_AVAILABLE_OUTFIT MP1_CLTHS_ACQUIRED_HAIR MP1_CLTHS_ACQUIRED_HAIR_1 MP1_CLTHS_ACQUIRED_HAIR_2
				1501939278, 968692674,  3716797638, 3759332585, 3404509853,
				// MP1_CLTHS_ACQUIRED_HAIR_3 MP1_CLTHS_ACQUIRED_HAIR_4 MP1_CLTHS_ACQUIRED_HAIR_5 MP1_CLTHS_ACQUIRED_HAIR_6 MP1_CLTHS_ACQUIRED_HAIR_7
				3180926966, 1933575005, 2777606138, 1606114388, 2177343596,
				// MP1_CLTHS_ACQUIRED_JBIB MP1_CLTHS_ACQUIRED_JBIB_1 MP1_CLTHS_ACQUIRED_JBIB_2 MP1_CLTHS_ACQUIRED_JBIB_3 MP1_CLTHS_ACQUIRED_JBIB_4
				640586954,  2828782047, 2396690013, 4224446526, 4060470450,
				// MP1_CLTHS_ACQUIRED_JBIB_5 MP1_CLTHS_ACQUIRED_JBIB_6 MP1_CLTHS_ACQUIRED_JBIB_7
				1737541578, 1431511887, 1261047549,
				// MP1_CLTHS_ACQUIRED_LEGS MP1_CLTHS_ACQUIRED_LEGS_1 MP1_CLTHS_ACQUIRED_LEGS_2 MP1_CLTHS_ACQUIRED_LEGS_3 MP1_CLTHS_ACQUIRED_LEGS_4
				2060905796, 830531808,  590892111,  234758619,  4289234224,
				// MP1_CLTHS_ACQUIRED_LEGS_5 MP1_CLTHS_ACQUIRED_LEGS_6 MP1_CLTHS_ACQUIRED_LEGS_7
				4200299158, 3977043961, 3603346285,
				// MP1_CLTHS_ACQUIRED_FEET MP1_CLTHS_ACQUIRED_FEET_1 MP1_CLTHS_ACQUIRED_FEET_2 MP1_CLTHS_ACQUIRED_FEET_3 MP1_CLTHS_ACQUIRED_FEET_4
				3178243862, 787364427,  556441284,  2185912578, 2933439006,
				// MP1_CLTHS_ACQUIRED_FEET_5 MP1_CLTHS_ACQUIRED_FEET_6 MP1_CLTHS_ACQUIRED_FEET_7
				1713088677, 1484131674, 3412194092,
				// MP1_CLTHS_ACQUIRED_BERD MP1_CLTHS_ACQUIRED_BERD_1 MP1_CLTHS_ACQUIRED_BERD_2 MP1_CLTHS_ACQUIRED_BERD_3 MP1_CLTHS_ACQUIRED_BERD_4
				3619810308, 272221408,  1243101332, 1028824841, 1730671283,
				// MP1_CLTHS_ACQUIRED_BERD_5 MP1_CLTHS_ACQUIRED_BERD_6 MP1_CLTHS_ACQUIRED_BERD_7
				1491949118, 3608269445, 2296821296,
				// MP1_CLTHS_ACQUIRED_PROPS MP1_CLTHS_ACQUIRED_PROPS_1 MP1_CLTHS_ACQUIRED_PROPS_2 MP1_CLTHS_ACQUIRED_PROPS_3 MP1_CLTHS_ACQUIRED_PROPS_4
				4017355137, 4169777756, 3947833319, 3626008970, 3379684397,
				// MP1_CLTHS_ACQUIRED_PROPS_5 MP1_CLTHS_ACQUIRED_PROPS_6 MP1_CLTHS_ACQUIRED_PROPS_7 MP1_CLTHS_ACQUIRED_PROPS_8 MP1_CLTHS_ACQUIRED_PROPS_9
				3296516675, 3066248912, 2740525052, 2090257020, 1808083161,
				// MP1_CLTHS_ACQUIRED_PROPS_10 MP1_CLTHS_ACQUIRED_OUTFIT MP1_CLTHS_AVAILABLE_TORSO MP1_CLTHS_AVAILABLE_SPECIAL MP1_CLTHS_AVAILABLE_SPECIAL_1
				2307370787, 89697595,   1497966245, 4146762192, 451816355,
				// MP1_CLTHS_AVAILABLE_SPECIAL_2 MP1_CLTHS_AVAILABLE_SPECIAL_3 MP1_CLTHS_AVAILABLE_SPECIAL_4 MP1_CLTHS_AVAILABLE_SPECIAL_5 MP1_CLTHS_AVAILABLE_SPECIAL_6
				1754646261, 3855761772, 3550485768, 3789994389, 797856995,
				// MP1_CLTHS_AVAILABLE_SPECIAL_7 MP1_CLTHS_AVAILABLE_SPECIAL2 MP1_CLTHS_AVAILABLE_SPECIAL2_1 MP1_CLTHS_AVAILABLE_DECL
				2899988345, 2253821379, 377292608,  2757726117,
				// MP1_CLTHS_AVAILABLE_TEETH MP1_CLTHS_AVAILABLE_TEETH_1 MP1_CLTHS_AVAILABLE_TEETH_2 MP1_CLTHS_ACQUIRED_TORSO
				1357794227, 2744101949, 2445346976, 3353462820,
				// MP1_CLTHS_ACQUIRED_SPECIAL MP1_CLTHS_ACQUIRED_SPECIAL_1 MP1_CLTHS_ACQUIRED_SPECIAL_2 MP1_CLTHS_ACQUIRED_SPECIAL_3 MP1_CLTHS_ACQUIRED_SPECIAL_4
				2479685817, 3775086688, 1627308121, 1933403350, 2693578612,
				// MP1_CLTHS_ACQUIRED_SPECIAL_5 MP1_CLTHS_ACQUIRED_SPECIAL_6 MP1_CLTHS_ACQUIRED_SPECIAL_7 MP1_CLTHS_ACQUIRED_SPECIAL2 MP1_CLTHS_ACQUIRED_SPECIAL2_1
				2865878014, 709710583,  1003877896, 1584681220, 1714217594,
				// MP1_CLTHS_ACQUIRED_DECL MP1_CLTHS_ACQUIRED_TEETH MP1_CLTHS_ACQUIRED_TEETH_1 MP1_CLTHS_ACQUIRED_TEETH_2
				2951853429, 2568616339, 3737588021, 4102700219,
				// MP1_DLC_APPAREL_ACQUIRED_0 MP1_DLC_APPAREL_ACQUIRED_1 MP1_DLC_APPAREL_ACQUIRED_2 MP1_DLC_APPAREL_ACQUIRED_3 MP1_DLC_APPAREL_ACQUIRED_4
				2495025993, 2676369639, 2919843309, 3150635376, 3723797955,
				// MP1_DLC_APPAREL_ACQUIRED_5 MP1_DLC_APPAREL_ACQUIRED_6 MP1_DLC_APPAREL_ACQUIRED_7 MP1_DLC_APPAREL_ACQUIRED_8 MP1_DLC_APPAREL_ACQUIRED_9
				3966649014, 2586943042, 2835364831, 648951605, 827673731,
				// MP1_DLC_APPAREL_ACQUIRED_10 MP1_DLC_APPAREL_ACQUIRED_11 MP1_DLC_APPAREL_ACQUIRED_12 MP1_DLC_APPAREL_ACQUIRED_13 MP1_DLC_APPAREL_ACQUIRED_14
				1579072107, 834494889,  2078766588, 1814156913, 2523671285,
				// MP1_DLC_APPAREL_ACQUIRED_15 MP1_DLC_APPAREL_ACQUIRED_16 MP1_DLC_APPAREL_ACQUIRED_17 MP1_DLC_APPAREL_ACQUIRED_18 MP1_DLC_APPAREL_ACQUIRED_19
				2242742648, 2998330250, 2750760455, 1563605123, 1350049550,
				// MP1_DLC_APPAREL_ACQUIRED_21 MP1_DLC_APPAREL_ACQUIRED_22 MP1_DLC_APPAREL_ACQUIRED_23 MP1_DLC_APPAREL_ACQUIRED_24 MP1_DLC_APPAREL_ACQUIRED_24
				3371569488, 3251733275, 3076550201, 3982973510, 3982973510,
				// MP1_DLC_APPAREL_ACQUIRED_25 MP1_DLC_APPAREL_ACQUIRED_26 MP1_DLC_APPAREL_ACQUIRED_27 MP1_DLC_APPAREL_ACQUIRED_28 MP1_DLC_APPAREL_ACQUIRED_29
				3543999986, 2127265040, 1832704499, 2590979159, 2292158648,
				// MP1_DLC_APPAREL_ACQUIRED_30 MP1_DLC_APPAREL_ACQUIRED_31 MP1_DLC_APPAREL_ACQUIRED_32 MP1_DLC_APPAREL_ACQUIRED_33 MP1_DLC_APPAREL_ACQUIRED_34
				3889745933, 3658888328, 3411908375, 3049417697, 298591223,
				// MP1_DLC_APPAREL_ACQUIRED_35 MP1_DLC_APPAREL_ACQUIRED_36 MP1_DLC_APPAREL_ACQUIRED_37 MP1_DLC_APPAREL_ACQUIRED_38 MP1_DLC_APPAREL_ACQUIRED_39
				51218042,   3981269754, 3733962111, 1508226089, 1143769271,
				// MP1_DLC_APPAREL_ACQUIRED_40
				1689017398,
				// MP1_ADMIN_CLOTHES_GV_BS_1 MP1_ADMIN_CLOTHES_GV_BS_2 MP1_ADMIN_CLOTHES_GV_BS_3 MP1_ADMIN_CLOTHES_GV_BS_4 MP1_ADMIN_CLOTHES_GV_BS_5
				4171901109, 1589834985, 1321751796, 1014476883, 853908783,
				// MP1_ADMIN_CLOTHES_GV_BS_6 MP1_ADMIN_CLOTHES_GV_BS_7 MP1_ADMIN_CLOTHES_GV_BS_8 MP1_ADMIN_CLOTHES_GV_BS_9 MP1_ADMIN_CLOTHES_GV_BS_10
				2543740575, 2349879171, 2046864228, 3735057574, 3853570575,
				// MP1_ADMIN_CLOTHES_GV_BS_11 MP1_ADMIN_CLOTHES_GV_BS_12 MP1_ADMIN_CLOTHES_GV_BS_13
				4230086385, 3536858162, 3798453089
			};
			for (Hash h : Clothes)
				CHooking::stat_set_int(h, -1, 1);

			//tshirts
			CHooking::stat_set_bool(0x59d644b9, 1, 1); // MP1_AWD_FINISH_HEIST_NO_DAMAGE
			CHooking::stat_set_bool(0xa5f06324, 1, 1); // MP1_AWD_STORE_20_CAR_IN_GARAGES
 
			CHooking::stat_set_int(0x3804231b, 1, 1); // MP1_AWD_FMPICKUPDLCCRATE1ST
			CHooking::stat_set_int(0x18f27d05, 10, 1); // MP1_AWD_FMHORDWAVESSURVIVE
 
			// MP1_AWD_WIN_CAPTURE_DONT_DYING MP1_AWD_DO_HEIST_AS_MEMBER MP1_AWD_WIN_GOLD_MEDAL_HEISTS MP1_AWD_KILL_TEAM_YOURSELF_LTS MP1_AWD_DO_HEIST_AS_THE_LEADER
			Hash Stats25[] = { 0x7b245db0, 0xffcb5243, 0x3d6a96c, 0x5c7450f8, 0xc13e46bc };
			for (Hash h : Stats25)
				CHooking::stat_set_int(h, 25, 1);
 
			CHooking::stat_set_int(0x87b6d2d, 100, 1); // MP1_AWD_PICKUP_CAP_PACKAGES
			CHooking::stat_set_int(0xe5e29eea, 100, 1); // MP1_AWD_KILL_PSYCHOPATHS
		}
		notify_above_map("Clothes Unlocked", 0);
	}
};
