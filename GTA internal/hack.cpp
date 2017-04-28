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
	//Init static public members
*/
std::string			CHack::m_szRequestedAnim;
std::string			CHack::m_szRequestedAnimDict;

CPlayers*			CHack::m_pCPlayers			= nullptr;
CWorld*				CHack::m_pCWorld			= nullptr;
CPed*				CHack::m_pCPedPlayer		= nullptr;
CPlayerInfo*		CHack::m_pCPlayerInfo		= nullptr;
CVehicle*			CHack::m_pCVehicle			= nullptr;
CVehicleHandling*	CHack::m_pCVehicleHandling	= nullptr;
CWeapon*			CHack::m_pCWeapon			= nullptr;

CVehicle			CHack::m_CVehicle;
CVehicleHandling	CHack::m_CVehicleHandling;
CWeapon				CHack::m_CWeapon;

int					CHack::m_lastVehicle		= NULL;

vec_int			CHack::m_pedCleanup;						//vector with all spawned peds
clock_t			CHack::m_pedCleanupClock	= clock();

vec_int			CHack::m_entityCleanup;					//vector where objects will be pushed to be destroyed
clock_t			CHack::m_entityCleanupClock	= clock();
int				CHack::m_entityCleanupTries	= 0;

vec_int			CHack::m_remotePlayerAttach[MAX_PLAYERS];
vec_attach		CHack::m_requestedAttach;

std::string		CHack::m_szRequestedModel	= "";
bool			CHack::m_bModelSet			= true;
bool			CHack::m_bModelWeapons		= true;
clock_t			CHack::m_modelClock			= clock();

vec_str			CHack::m_requestedVehicle;
vec_str			CHack::m_requestedWeapon;
bool			CHack::m_bWeaponGive;
vec_str			CHack::m_requestedPed;
vec_str			CHack::m_requestedObject;

vec_int			CHack::m_nearbyPed;
vec_int			CHack::m_nearbyVehicle;

v3				CHack::m_v3Teleport			= {};

clock_t			CHack::m_clockPlayerInfo	= clock();


/*
	//CHack static functions
*/

void	CHack::killNpc()
{
	if(m_pCPedPlayer->pCAttacker == nullptr)
		return;
	if(m_pCPedPlayer->pCAttacker->CPed0 != nullptr && m_pCPedPlayer->pCAttacker->CPed0 != m_pCPedPlayer && m_pCPedPlayer->pCAttacker->CPed0->fHealth > 0.f)
		m_pCPedPlayer->pCAttacker->CPed0->fHealth = 0.f;
	if(m_pCPedPlayer->pCAttacker->CPed1 != nullptr && m_pCPedPlayer->pCAttacker->CPed1 != m_pCPedPlayer && m_pCPedPlayer->pCAttacker->CPed1->fHealth > 0.f)
		m_pCPedPlayer->pCAttacker->CPed1->fHealth = 0.f;
	if(m_pCPedPlayer->pCAttacker->CPed2 != nullptr && m_pCPedPlayer->pCAttacker->CPed2 != m_pCPedPlayer && m_pCPedPlayer->pCAttacker->CPed2->fHealth > 0.f)
		m_pCPedPlayer->pCAttacker->CPed2->fHealth = 0.f;
	return;
}

/*void	CHack::fillAmmo()
{
	CAmmoWrap* AmmoWrap = m_pCWeapon->CAmmoInfo->CAmmoWrap;
	while(AmmoWrap->CAmmo->dwUnknown == 0)
	{
		if(AmmoWrap->AmmoWrap == nullptr)
			return;
		AmmoWrap	= AmmoWrap->AmmoWrap;
	}
	AmmoWrap->CAmmo->dwAmmo = m_pCWeapon->CAmmoInfo->dwMaxAmmo;
	return;
}*/

/*
	flag
		0		normal toggle()
		1 << 0	sync toggle state
		1 << 1	restore
*/
void	CHack::checkAllPlayerFeature(eFeatures feature, ePlrFeats plrFeature, int flag = 0)
{
	CFeat* feat	= CMenu::getFeature(feature);
	if((feat->m_bOn || flag & 2) && !feat->m_bSet)
	{
		for(int i = 0; i < MAX_PLAYERS; i++)
		{
			CFeat* plrParent = CMenu::getPlrFeature(PLRFEAT_PARENT, i);
			if(!plrParent->m_bOn)
				continue;
			CFeat* plrFeat = CMenu::getPlrFeature(plrFeature, i);
			plrFeat->setValue(feat->getValue());
			if(flag & 1)
				plrFeat->toggle(feat->m_bOn ? true : false);
			else
				plrFeat->toggle();
		}
		feat->m_bSet = true;
	}
}

bool	CHack::refresh()
{
	if(m_pCWorld->CPedLocalPlayer != nullptr)
	{
		
		//init player, playerPed and playerVeh
		Player	player		= PLAYER::PLAYER_ID();
		Ped		playerPed	= PLAYER::PLAYER_PED_ID();

		if(!PLAYER::IS_PLAYER_PLAYING(player))
			return false;

		/*int max = CHooking::m_replayIntf->ped_interface->max_peds;
		for(int i = 0; i < max; i++)
		{
			CPed* ped = CHooking::m_replayIntf->ped_interface->get_ped(i);
			if(ped == nullptr || ped == m_pCPedPlayer)
				continue;
			Ped id = CHooking::m_replayIntf->ped_interface->get_ped_handle(i);
			char	buf[0xFF];
			sprintf_s(buf, "Replay - Ped Handle %i: %i", i, id);
			CLog::msg(buf);
			//if(ENTITY::DOES_ENTITY_EXIST(id))
			//	CLog::msg("Exists");
			//v3 playerPos = ENTITY::GET_ENTITY_COORDS(playerPed, false);
			//script::teleport_entity_to_coords(id, playerPos, false);
		}

		script::update_nearby_ped(playerPed, 0x80);
		int tmp = 0;
		while(!m_nearbyPed.empty())
		{
			char	buf[0xFF];
			sprintf_s(buf, "Native - Ped Handle %i: %i", tmp, m_nearbyPed[0]);
			CLog::msg(buf);
			m_nearbyPed.erase(m_nearbyPed.begin());
			++tmp;
		}*/

		//bool	playerInVeh	= PED::IS_PED_IN_ANY_VEHICLE(playerPed, true) > 0;
		bool	playerInVeh	= script::is_ped_in_any_vehicle(playerPed);
		Vehicle playerVeh = NULL;
		bool	playerVehDriver = false;
		if(playerInVeh)
		{
			playerVeh		= PED::GET_VEHICLE_PED_IS_USING(playerPed);
			if(m_lastVehicle != playerVeh)
			{
				CMenu::getFeature(FEATURE_V_LICENSE)->m_bSet		= true;		//disable the keyboard for license
				CMenu::getFeature(FEATURE_V_LICENSE)->m_bRestored	= true;		//so if it was triggered, we don't get a popup as soon as we get in the car
				m_lastVehicle	= playerVeh;
			}
			if(VEHICLE::GET_PED_IN_VEHICLE_SEAT(playerVeh, -1) == playerPed)
				playerVehDriver = true;
		}
		else if(m_lastVehicle != NULL)
			if(ENTITY::IS_AN_ENTITY(m_lastVehicle) && ENTITY::IS_ENTITY_A_VEHICLE(m_lastVehicle) && VEHICLE::IS_VEHICLE_DRIVEABLE(m_lastVehicle, false))
				playerVeh		= m_lastVehicle;
			else
				m_lastVehicle	= NULL;
		
		CFeat* feat;

		//TEST
		/*feat = CMenu::getFeature(FEATURE_P_TEST);
		if(feat->m_bOn && !feat->m_bSet)
		{
			CPed* cp	= util::ped_handle_to_ptr(playerPed);
			if(cp != nullptr && cp->pCNavigation != nullptr)
			{
				char	msg[0xFF];

				//sprintf_s(msg, "Native Heading: %.4f", ENTITY::GET_ENTITY_HEADING(playerPed));
				//CLog::msg(msg);

				float heading	= cp->pCNavigation->fHeading;
				float heading2	= cp->pCNavigation->fHeading2;
				//heading += 1.f;
				//heading *= 180.f;
				sprintf_s(msg, "Memory Heading: %.4f", heading);
				CLog::msg(msg);
				sprintf_s(msg, "Memory Heading2: %.4f", heading2);
				CLog::msg(msg);

				v3	nativeRot	= ENTITY::GET_ENTITY_ROTATION(playerPed, 0);
				v3	memoryRot	= cp->pCNavigation->v3Rotation;

				sprintf_s(msg, "Native Rot X: %.4f", nativeRot.x);
				CLog::msg(msg);
				sprintf_s(msg, "Native Rot Y: %.4f", nativeRot.y);
				CLog::msg(msg);
				sprintf_s(msg, "Native Rot Z: %.4f", nativeRot.z);
				CLog::msg(msg);

				sprintf_s(msg, "Memory Rot X: %.4f", memoryRot.x);
				CLog::msg(msg);
				sprintf_s(msg, "Memory Rot Y: %.4f", memoryRot.y);
				CLog::msg(msg);
				sprintf_s(msg, "Memory Rot Z: %.4f", memoryRot.z);
				CLog::msg(msg);
			}
			feat->m_bSet	= true;
		}*/

		//Fps counter
		feat = CMenu::getFeature(FEATURE_I_FPS_COUNTER);
		if(feat->m_bOn)
			script::draw_fps();
		
		//spawned ped cleanup
		feat = CMenu::getFeature(FEATURE_S_PED_CLEANUP);
		if(!m_pedCleanup.empty() && clock() - m_pedCleanupClock > 0xFF)
		{
			if(feat->m_bOn)
			{
				for(int i = 0; i < m_pedCleanup.size(); i++)
				{
					Ped e = m_pedCleanup[i];
					if(!ENTITY::IS_ENTITY_DEAD(e) && i < MAX_SPAWNED_PEDS)
						continue;
					if(ENTITY::IS_ENTITY_ATTACHED(e))
						script::detach_entity(e);
					m_entityCleanup.push_back(e);
					m_pedCleanup.erase(m_pedCleanup.begin() + i);
					break;
				}
			}
			else
				m_pedCleanup.clear();
			m_pedCleanupClock = clock();
		}
		
		//entity cleanup
		static std::unordered_map<Entity, int>	countMap;
		if(!m_entityCleanup.empty() && clock() - m_entityCleanupClock > 0x10)
		{
			Entity e = m_entityCleanup[0];
			if(!ENTITY::IS_AN_ENTITY(e))
			{
				if(countMap.find(m_entityCleanup[0]) != countMap.end())
					countMap.erase(m_entityCleanup[0]);
				m_entityCleanup.erase(m_entityCleanup.begin());
				m_entityCleanupTries = 0;
			}
			else if(m_entityCleanupTries > 5)
			{
				std::unordered_map<Entity, int>::iterator it = countMap.find(m_entityCleanup[0]);
				if(it != countMap.end())
					if(it->second < 0xFF)
						it->second++;
					else
					{
						countMap.erase(it);
						m_entityCleanup.erase(m_entityCleanup.begin());
						m_entityCleanupTries = 0;
					}
				else
					countMap[m_entityCleanup[0]] = 1;
				m_entityCleanup.push_back(m_entityCleanup[0]);
				m_entityCleanup.erase(m_entityCleanup.begin());
				m_entityCleanupTries = 0;
			}
			else if(script::request_control_of_entity(e))
			{
				script::detach_entity(e);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(e, false, false);
				ENTITY::DELETE_ENTITY(&e);
				if(ENTITY::IS_AN_ENTITY(m_entityCleanup[0]))
					m_entityCleanupTries = 0xFF;
				m_entityCleanupTries++;
			}	
			else
				m_entityCleanupTries++;
			m_entityCleanupClock	= clock();
		}
		
		//mp vehicles in sp
		feat = CMenu::getFeature(FEATURE_S_SP_BYPASS);
		if(!feat->m_bSet)
		{
			script::vehicle_sp_bypass(feat->m_bOn);
			feat->m_bSet = true;
		}

		//global mp kick bypass
		feat = CMenu::getFeature(FEATURE_S_MP_BYPASS);
		if(!feat->m_bSet)
		{
			script::vehicle_mp_bypass(feat->m_bOn);
			feat->m_bSet = true;
		}
		
		//vehicle spawn
		if(!m_requestedVehicle.empty())
		{
			BYTE	flags	= 0;
			int		colours	= -1;

			if(CMenu::getFeature(FEATURE_S_IN_VEHICLE)->m_bOn)
				flags	|= 0x01;
			if(CMenu::getFeature(FEATURE_S_MP_BYPASS)->m_bOn)
				flags	|=	0x02;
			if(CMenu::getFeature(FEATURE_S_VEH_MOD)->m_bOn)
				flags	|= 0x04;
			if(CMenu::getFeature(FEATURE_S_LICENSE)->m_bOn)
				flags	|= 0x08;

			CFeat* feat		= CMenu::getFeature(FEATURE_S_COLOR_1);
			CFeat* feat2	= CMenu::getFeature(FEATURE_S_COLOR_2);
			if(feat->m_bOn || feat2->m_bOn)
				colours	= 0;
			if(feat->m_bOn)
				colours	|=	(int) feat->getValue();
			if(feat2->m_bOn)
				colours	|=	((int) feat2->getValue()) << 0x08;

			if(script::spawn_vehicle(&m_requestedVehicle[0][0], nullptr, flags, colours))
				m_requestedVehicle.erase(m_requestedVehicle.begin());
		}
			
		
		//ped spawn
		if(!m_requestedPed.empty())
			if(script::spawn_ped(&m_requestedPed[0][0], PedTypeHuman, {}, nullptr, CMenu::getFeature(FEATURE_S_PED_RANDOMIZE)->m_bOn, (int) CMenu::getFeature(FEATURE_S_PED_TYPE)->getValue()))
				m_requestedPed.erase(m_requestedPed.begin());
		
		//weapon spawn
		if(!m_requestedWeapon.empty())
		{
			script::ped_weapon(playerPed, &m_requestedWeapon[0][0], m_bWeaponGive);
			m_requestedWeapon.erase(m_requestedWeapon.begin());
		}

		//anim request
		if(!m_szRequestedAnim.empty() && script::animate_local_player(playerPed, &m_szRequestedAnimDict[0], &m_szRequestedAnim[0]))
		{
			m_szRequestedAnim.clear();
			m_szRequestedAnimDict.clear();
		}

		//stop anim
		feat = CMenu::getFeature(FEATURE_U_STOP_ANIM);
		if(!feat->m_bSet && feat->m_bOn)
		{
			AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
			feat->m_bSet = true;
		}
		
		//model changer
		//feat = CMenu::getFeature(FEATURE_M_RANDOMIZE_PED);
		static int tmpVeh;
		if(!m_bModelSet)
		{
			if(playerInVeh)
				tmpVeh	= playerVeh;
			if(script::apply_model(m_szRequestedModel))
			{
				m_bModelSet = true;
				m_bModelWeapons = false;
				m_modelClock = clock();
			}
		}
		else if(!m_bModelWeapons && clock() - m_modelClock > 0xF0)
		{
			if (tmpVeh != NULL)
				PED::SET_PED_INTO_VEHICLE(playerPed, tmpVeh, script::get_free_seat(tmpVeh));
			tmpVeh = NULL;
			script::ped_give_all_weapons(playerPed);
			m_pCPedPlayer->fHealthMax = 328.f;
			m_bModelWeapons = true;
		}
		
		//object attach requests
		/*if(!m_requestedAttach.empty())
		{
			Object obj = script::attach_object_to_entity(PLAYER::GET_PLAYER_PED(m_requestedAttach[0].player), &m_requestedAttach[0].hash[0], hash::ped_bone_hash[m_requestedAttach[0].bone]);
			m_remotePlayerAttach[m_requestedAttach[0].player].push_back(obj);
			m_requestedAttach.erase(m_requestedAttach.begin());
		}*/

		//teleport
		if(m_v3Teleport.x != 0.f && m_v3Teleport.y != 0.f && m_v3Teleport.z != 0.f)
		{
			script::teleport_to_coords(m_v3Teleport);
			m_v3Teleport = {};
		}
		
		//tp to waypoint
		feat = CMenu::getFeature(FEATURE_TP_WAYPOINT);
		if(feat->m_bOn && !feat->m_bSet && clock() - feat->m_clockTick > 0x20)
		{
			if(script::teleport_to_waypoint())
				feat->m_bSet		= true;
			else
				feat->m_clockTick	= clock();
		}
		
		//tp to waypoint
		feat = CMenu::getFeature(FEATURE_TP_OBJECTIVE);
		if(feat->m_bOn && !feat->m_bSet)
		{
			script::teleport_to_objective();
			feat->m_bSet		= true;
		}
		
		//tp to nearby car
		feat = CMenu::getFeature(FEATURE_TP_NEARBY_CAR);
		if(feat->m_bOn && !feat->m_bSet)
		{
			script::get_in_closest_car();
			feat->m_bSet		= true;
		}

		//noclip
		feat = CMenu::getFeature(FEATURE_U_NOCLIP);
		if(feat->m_bOn || !feat->m_bSet)
		{
			int flags	= 0;
			if(CMenu::checkKeyState(CMenu::m_keyIndex[KEY_NOCLIP_FORWARD]))	//w
				flags	|= 0x01;
			if(CMenu::checkKeyState(CMenu::m_keyIndex[KEY_NOCLIP_BACK]))	//s
				flags	|= 0x02;
			if(CMenu::checkKeyState(CMenu::m_keyIndex[KEY_NOCLIP_LEFT]))	//a
				flags	|= 0x04;
			if(CMenu::checkKeyState(CMenu::m_keyIndex[KEY_NOCLIP_RIGHT]))	//d
				flags	|= 0x08;
			if(CMenu::checkKeyState(CMenu::m_keyIndex[KEY_NOCLIP_UP]))	//l shift
				flags	|= 0x10;
			if(CMenu::checkKeyState(CMenu::m_keyIndex[KEY_NOCLIP_DOWN]))	//l ctrl
				flags	|= 0x20;
			script::noclip(playerInVeh ? playerVeh : playerPed, flags, CMenu::getFeature(FEATURE_U_NOCLIP_SPEED)->getValue(), feat->getValue() > 0.f, !feat->m_bOn);
			feat->m_bSet = true;
		}
		
		//Editor mode
		feat = CMenu::getFeature(FEATURE_E_EDITOR_MODE);
		if(feat->m_bOn || !feat->m_bSet)
		{
			int	a	= 0,
				f	= 0;

			//action
			if(CMenu::checkKeyState(CMenu::m_keyIndex[KEY_EDITOR_ACTION], 1))	//e
			{
				if(!feat->m_bRestored)
					a	|=	0x02;	//lock
				else
					a	|=	0x01;	//reset
			}
			if(!CMenu::getFeature(FEATURE_E_DELETE)->m_bSet)
			{
				a	|=	0x04;
				CMenu::getFeature(FEATURE_E_DELETE)->m_bSet = true;
			}
			if(!feat->m_bOn)
				a	|= 0x01;

			//flags
			if(CMenu::getFeature(FEATURE_E_TEXT_TYPE)->m_bOn)
				f	|=	0x01;
			if(CMenu::getFeature(FEATURE_E_TEXT_POS)->m_bOn)
				f	|=	0x02;
			if(CMenu::getFeature(FEATURE_E_COLLISION)->m_bOn)
				f	|=	0x04;
			if(CMenu::getFeature(FEATURE_E_FREEZE)->m_bOn)
				f	|=	0x08;
			if(CMenu::getFeature(FEATURE_E_THROW_MODE)->m_bOn)
				f	|=	0x10;
			if(CMenu::getFeature(FEATURE_E_ROTATION_RELATIVE)->m_bOn)
				f	|=	0x20;
			if(CMenu::getFeature(FEATURE_E_INVISIBLE)->m_bOn)
				f	|=	0x40;

			v3		rot;
			if(CMenu::getFeature(FEATURE_E_ROTATION_ENABLE)->m_bOn)
			{
				rot		= {	CMenu::getFeature(FEATURE_E_ROTATION_X)->getValue(),
							CMenu::getFeature(FEATURE_E_ROTATION_Y)->getValue(),
							CMenu::getFeature(FEATURE_E_ROTATION_Z)->getValue(),};
				f	|=	0x80;
			}

			Entity e	= NULL;
			if(!m_requestedObject.empty() && script::spawn_object(&m_requestedObject[0][0], &e))
			{
				m_requestedObject.erase(m_requestedObject.begin());
				feat->m_bRestored = true;
			}

			feat->m_bRestored = script::entity_editor(	a,
														CMenu::getFeature(FEATURE_E_DISTANCE)->getValue(),
														f,
														rot,
														e);
			feat->m_bSet = true;
		}
		
		//anti afk
		/*feat = CMenu::getFeature(FEATURE_P_ANTI_AFK);
		if(!feat->m_bSet && (feat->m_bOn || (!feat->m_bOn && !feat->m_bRestored)))
		{
			script::ped_scenario(playerPed, hash::anti_afk_hash[(int) feat->getValue()], !feat->m_bOn);
			feat->m_bSet		= true;
			if(!feat->m_bOn)
				feat->m_bRestored	= true;
		}*/

		//santa outfit
		feat = CMenu::getFeature(FEATURE_C_SANTA);
		if(!feat->m_bSet && feat->m_bOn)
		{
			script::apply_outfit(OUTFIT_SANTA);
			feat->m_bSet		= true;
		}

		//trash orange outfit
		feat = CMenu::getFeature(FEATURE_C_TRASH_ORANGE);
		if(!feat->m_bSet && feat->m_bOn)
		{
			script::apply_outfit(OUTFIT_TRASH_ORANGE);
			feat->m_bSet		= true;
		}

		//trash green outfit
		feat = CMenu::getFeature(FEATURE_C_TRASH_GREEN);
		if(!feat->m_bSet && feat->m_bOn)
		{
			script::apply_outfit(OUTFIT_TRASH_GREEN);
			feat->m_bSet		= true;
		}

		//police outfit
		feat = CMenu::getFeature(FEATURE_C_POLICE);
		if(!feat->m_bSet && feat->m_bOn)
		{
			script::apply_outfit(OUTFIT_POLICE);
			feat->m_bSet		= true;
		}


		//mobile radio
		feat = CMenu::getFeature(FEATURE_P_MOBILE_RADIO);
		if(!feat->m_bSet || feat->m_bOn && clock() - feat->m_clockTick > 0xFF)
		{
			AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(feat->m_bOn);
			feat->m_clockTick	= clock();
			feat->m_bSet		= true;
		}

		//freeze radio
		feat = CMenu::getFeature(FEATURE_P_FREEZE_RADIO);
		if(feat->m_bOn && clock() - feat->m_clockTick > 0xFF)
		{
			script::set_radio_station(hash::radio_station_hash[(int) feat->getValue()]);
			feat->m_clockTick = clock();
		}
		
		//inf ammo
		feat = CMenu::getFeature(FEATURE_W_AMMO);
		if(!feat->m_bSet || (feat->m_bOn && clock() - feat->m_clockTick > 0xFF))
		{
			WEAPON::SET_PED_INFINITE_AMMO_CLIP(playerPed, feat->m_bOn);
			feat->m_clockTick = clock();
			feat->m_bSet = true;
		}
		
		//player invis
		feat = CMenu::getFeature(FEATURE_P_INVISIBLE);
		if(feat->m_bOn || !feat->m_bSet)
		{
			script::set_entity_invisible(playerPed, !feat->m_bOn, CMenu::getFeature(FEATURE_P_VISIBLE_LOCAL)->m_bOn);
			feat->m_bSet = true;
		}
		
		//player offradar
		feat = CMenu::getFeature(FEATURE_P_OFFRADAR);
		if(feat->m_bOn || !feat->m_bSet)
		{
			script::lester_offradar_toggle(feat->m_bOn);
			if(feat->m_bOn)
				script::lester_offradar_add(60000);
			feat->m_bSet = true;
		}
		
		//clean player
		feat = CMenu::getFeature(FEATURE_P_CLEAN_PLAYER);
		if(!feat->m_bSet && feat->m_bOn)
		{
			script::clean_ped(playerPed);
			feat->m_bSet = true;
		}
		
		//clone ped
		feat = CMenu::getFeature(FEATURE_P_CLONE_BODYGUARD);
		if(!feat->m_bSet && feat->m_bOn)
		{
			m_pedCleanup.push_back(script::clone_ped_bodyguard(playerPed));
			feat->m_bSet = true;
		}
		
		/*/clean objects
		feat = CMenu::getFeature(FEATURE_P_CLEANUP_OBJECTS);
		if(!feat->m_bSet && feat->m_bOn)
		{
			script::remove_nearby_objects();
			feat->m_bSet = true;
		}//*/
		
		//Super run
		feat = CMenu::getFeature(FEATURE_P_SUPER_RUN);
		if(feat->m_bOn && !playerInVeh)
		{
			
			int i	= script::super_run(feat->getValue(), !feat->m_bRestored, CMenu::checkKeyState(CMenu::m_keyIndex[KEY_SUPERRUN]));
			if(i == 1)
				feat->m_bRestored = false;
			if(i == 0)
				feat->m_bRestored = true;
		}
		
		//Chaos mode
		feat = CMenu::getFeature(FEATURE_U_CHAOS_MODE);
		if(feat->m_bOn)
			script::chaos_mode(&feat->m_clockTick, (int) feat->getValue());
		
		//Smash Vehicles
		feat = CMenu::getFeature(FEATURE_U_SMASH_VEHICLES);
		if(feat->m_bOn && !feat->m_bSet)
			if(script::smash_vehicles(&feat->m_clockTick))
				feat->m_bSet	= true;

		//black hole
		feat = CMenu::getFeature(FEATURE_U_BLACK_HOLE);
		if(feat->m_bOn && !feat->m_bSet && script::black_hole((int) feat->getValue()))
			feat->m_bSet	= true;
		
		//money drop (sp only)
		/*feat = CMenu::getFeature(FEATURE_P_MONEY_DROP);
		if(feat->m_bOn && clock() - feat->m_clockTick > 0x60)
		{
			script::drop_money_on_entity(playerPed, 40000, hash::object_prop_money_hash[(int) feat->getValue()]);//"prop_alien_egg_01");
			feat->m_clockTick = clock();
		}*/

		//ped drop
		feat = CMenu::getFeature(FEATURE_U_PED_DROP);
		if(feat->m_bOn || !feat->m_bSet)
		{
			if(feat->m_bOn)
				script::ped_money_drop(playerPed, &feat->m_clockTick);
			else
				m_nearbyPed.clear();
			feat->m_bSet		= true;
		}
		
		//stealth give money
		feat = CMenu::getFeature(FEATURE_R_STEALTH_MONEY);
		if(feat->m_bOn && !feat->m_bSet)
		{
			script::stealth_money((int) feat->getValue());
			feat->m_bSet		= true;
		}

		//stealth remove money
		feat = CMenu::getFeature(FEATURE_R_STEALTH_MONEY_REMOVE);
		if(feat->m_bOn && !feat->m_bSet)
		{
			script::stealth_money((int) feat->getValue(), true);
			feat->m_bSet		= true;
		}

		//rp loop
		feat = CMenu::getFeature(FEATURE_R_RP_LOOP);
		if((feat->m_bOn && clock() - feat->m_clockTick > 0x6F) || !feat->m_bSet)
		{
			if(!feat->m_bSet)
			{
				CMenu::getFeature(FEATURE_P_WANTED)->toggle(false);
				CMenu::getFeature(FEATURE_P_NEVERWANTED)->toggle(false);
				feat->m_bSet	= true;
			}
			m_pCPedPlayer->pCPlayerInfo->CWantedData.dwWantedLevel	= feat->m_bOn && feat->m_bRestored ? 5 : 0;
			feat->m_bRestored	= !feat->m_bRestored;
			feat->m_clockTick	= clock();
		}

		//clear reports
		/*feat = CMenu::getFeature(FEATURE_P_CLEAR_REPORTS);
		if(!feat->m_bSet && feat->m_bOn)
		{
			script::clear_badsports();
			feat->m_bSet = true;
		}*/

		//tiny player
		feat = CMenu::getFeature(FEATURE_P_TINY);
		if(!feat->m_bSet)
		{
			PED::SET_PED_CONFIG_FLAG(playerPed, 223, feat->m_bOn);
			feat->m_bSet = true;
		}
		
		//Time Freeze
		feat = CMenu::getFeature(FEATURE_T_PAUSE_CLOCK);
		if(!feat->m_bSet || (feat->m_bOn && clock() - feat->m_clockTick > 0xFF))
		{
			TIME::PAUSE_CLOCK(feat->m_bOn);
			feat->m_bSet = true;
		}
		
		//Time Hour
		feat = CMenu::getFeature(FEATURE_T_SET_HOUR);
		if(!feat->m_bSet && feat->m_bOn)
		{
			script::set_time((int) feat->getValue(), -1);
			feat->m_bSet = true;
		}

		//Time Mins
		feat = CMenu::getFeature(FEATURE_T_SET_MIN);
		if(!feat->m_bSet && feat->m_bOn)
		{
			script::set_time(-1, (int) feat->getValue());
			feat->m_bSet = true;
		}

		//Time Weather
		feat = CMenu::getFeature(FEATURE_T_WEATHER);
		if(!feat->m_bSet && feat->m_bOn)
		{
			script::set_weather(feat->getCharArray()[(int) feat->getValue()]);
			feat->m_bSet = true;
		}

		//Clean session
		feat = CMenu::getFeature(FEATURE_U_CLEAN_SESSION);
		if(!feat->m_bSet && feat->m_bOn && script::clean_session())
			feat->m_bSet = true;

		//Unlocks
		const eFeatures unlockFeat[]	= {
			FEATURE_R_UNLOCK_STAT,
			FEATURE_R_UNLOCK_TATTOO,
			FEATURE_R_UNLOCK_PARACHUTE,
			FEATURE_R_UNLOCK_RIMS,
			FEATURE_R_UNLOCK_VEHICLE,
			FEATURE_R_UNLOCK_TROPHY,
			FEATURE_R_UNLOCK_HAIRSTYLE,
			FEATURE_R_UNLOCK_WEAPON,
			FEATURE_R_UNLOCK_CLOTHING,
		};
		void (*unlockFunc[])() = {
			&script::unlocks_stats,
			&script::unlocks_tattoos,
			&script::unlocks_parachutes,
			&script::unlocks_chrome_rims,
			&script::unlocks_vehicles,
			&script::unlocks_trophies,
			&script::unlocks_hairstyles,
			&script::unlocks_weapons,
			&script::unlocks_clothes,
		};

		for(int i = 0; i < sizeof(unlockFeat) / sizeof(*unlockFeat); ++i)
		{
			feat = CMenu::getFeature(unlockFeat[i]);
			if(feat->m_bOn && !feat->m_bSet)
			{
				unlockFunc[i]();
				feat->m_bSet = true;
			}
		}

		//Event protections
		const eFeatures protexFeat[]	= {
			FEATURE_D_TELEPORT,
			FEATURE_D_KICK,
		};

		const eRockstarEvent protexEnum[]	= {
			REVENT_NETWORK_START_SYNCED_SCENE_EVENT,
			REVENT_KICK_VOTES_EVENT,
		};

		for(int i = 0; i < sizeof(protexFeat) / sizeof(*protexFeat); ++i)
		{
			feat = CMenu::getFeature(protexFeat[i]);
			if(!feat->m_bSet)
			{
				CHooking::defuseEvent(protexEnum[i], feat->m_bOn);
				feat->m_bSet	= true;
			}
		}
		
		//vehicle stuff
		if(playerVeh != NULL)
		{
			//request control
			if(playerVehDriver)
				script::request_control_of_entity(playerVeh);

			//Speed-O-Meter
			feat = CMenu::getFeature(FEATURE_I_SPEED_O_METER);
			if(feat->m_bOn && playerInVeh)
				script::draw_speedometer(playerVeh);
			
			//vehicle invis
			feat = CMenu::getFeature(FEATURE_V_INVISIBLE);
			if(feat->m_bOn || !feat->m_bSet)
			{
				ENTITY::SET_ENTITY_VISIBLE(playerVeh, !feat->m_bOn, false);
				feat->m_bSet = true;
			}

			//repair vehicle
			feat = CMenu::getFeature(FEATURE_V_REPAIR);
			if(!feat->m_bSet && feat->m_bOn)
			{
				script::fix_vehicle(playerVeh);
				feat->m_bSet = true;
			}

			//upgrade
			feat = CMenu::getFeature(FEATURE_V_UPGRADE);
			if(playerInVeh && !feat->m_bSet && feat->m_bOn && script::upgrade_car(playerVeh, true))
				feat->m_bSet = true;

			//Flip vehicle
			feat = CMenu::getFeature(FEATURE_V_FLIP);
			if(!feat->m_bSet && feat->m_bOn)
			{
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(playerVeh);
				feat->m_bSet = true;
			}

			//stick to ground
			feat = CMenu::getFeature(FEATURE_V_STICK_TO_GROUND);
			if(feat->m_bOn)
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(playerVeh);
			
			//Boost
			feat = CMenu::getFeature(FEATURE_V_BOOST);
			if(!feat->m_bSet && feat->m_bOn)
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(playerVeh, feat->getValue());
				feat->m_bSet = true;
			}

			//Stop
			feat = CMenu::getFeature(FEATURE_V_STOP);
			if(!feat->m_bSet && feat->m_bOn)
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(playerVeh, 0.f);
				feat->m_bSet = true;
			}
			
			//License
			feat = CMenu::getFeature(FEATURE_V_LICENSE);
			if(!feat->m_bSet && feat->m_bOn)
			{
				if(feat->m_bRestored)
				{
					script::show_ingame_keyboard("License");
					feat->m_bRestored = false;
				}
				if(!feat->m_bRestored)
				{
					std::string str = script::get_ingame_keyboard_result();
					if(str != "!!INVALID!!" && str != "")
					{
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(playerVeh, &str[0]);
						feat->m_bRestored	= true;
						feat->m_bSet		= true;
					}
				}
			}
			
			//rainbow car
			feat = CMenu::getFeature(FEATURE_V_RAINBOW);
			if(feat->m_bOn && clock() - feat->m_clockTick > 200)
			{
				VEHICLE::SET_VEHICLE_COLOURS(playerVeh, util::random_int(1, 120), util::random_int(1, 120));
				feat->m_clockTick = clock();
			}

			//preset vehicle colors
			feat = CMenu::getFeature(FEATURE_V_COLOR_PRESET);
			if(!feat->m_bSet && feat->m_bOn)
			{
				int p, s;
				VEHICLE::GET_VEHICLE_COLOURS(playerVeh, &p, &s);
				VEHICLE::SET_VEHICLE_COLOURS(playerVeh, (int) feat->getValue(), s);
				feat->m_bSet = true;
			}
			feat = CMenu::getFeature(FEATURE_V_COLOR_PRESET2);
			if(!feat->m_bSet && feat->m_bOn)
			{
				int p, s;
				VEHICLE::GET_VEHICLE_COLOURS(playerVeh, &p, &s);
				VEHICLE::SET_VEHICLE_COLOURS(playerVeh, p, (int) feat->getValue());
				feat->m_bSet = true;
			}
			
		}

		
		//Bone index for attach
		feat = CMenu::getFeature(FEATURE_O_ATTACH_BONE);
		int	iAttachBone = -1;
		if(feat->m_bOn)
			iAttachBone = hash::ped_bone_hash[(int) feat->getValue()];

		//esp settings
		bool	bEspDist	= CMenu::getFeature(FEATURE_O_ESP_DIST)->m_bOn;
		bool	bEspHealth	= CMenu::getFeature(FEATURE_O_ESP_HEALTH)->m_bOn;
		bool	bEspBox		= CMenu::getFeature(FEATURE_O_ESP_BOX)->m_bOn;
		float	fEspMaxDist	= CMenu::getFeature(FEATURE_O_ESP_MAX_DIST)->getValue();
		
		//online players
		for(int i = 0; i < MAX_PLAYERS; i++)
		{
			CFeat* feat = CMenu::getPlrFeature(PLRFEAT_PARENT, i);

			//update players
			std::string szName = "!Invalid!";
			Ped remotePed	= 0;
			remotePed	= PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);

			if (remotePed > 0 && remotePed != playerPed)
			{
				szName = PLAYER::GET_PLAYER_NAME(i);
				if(feat->m_szName != szName)
				{
					CMenu::m_disableParent.push_back(feat->m_iId);
					feat->m_szName = szName;
				}
				feat->m_bOn = true;
			}
			else if(feat->m_bOn)
			{
				for(int j = 0; j < m_remotePlayerAttach[i].size(); j++)		//clear up all attachments if the player leaves
				{
					script::detach_entity(m_remotePlayerAttach[i][j]);
					m_entityCleanup.push_back(m_remotePlayerAttach[i][j]);
					m_remotePlayerAttach[i].erase(m_remotePlayerAttach[i].begin() + j);
					j--;
				}
				CMenu::m_disableParent.push_back(feat->m_iId);
				feat->m_szName = szName;
				feat->m_bOn = false;
			}

			if(!feat->m_bOn)	//if the parent is disabled, don't check the children
				continue;

			CFeat*	plrFeat;

			//update player info features, if the screen is active for this player
			plrFeat = CMenu::getPlrFeature(PLRFEAT_INFO, i);
			if(clock() - m_clockPlayerInfo > 0x400 && CMenu::getActiveParent() == plrFeat->m_iId)
			{
				char	msg[0xFF];
				CPed*	cp			= util::ped_handle_to_ptr(remotePed);
				if(cp != nullptr && cp->pCPlayerInfo != nullptr)
				{
					//name
					sprintf_s(msg, "Name: %s", &szName[0]);
					CMenu::getPlrFeature(PLRFEAT_INFO_NAME, i)->m_szName = msg;

					//ip
					BYTE*	btIP	= reinterpret_cast<BYTE*>(&cp->pCPlayerInfo->iExternalIP);
					sprintf_s(msg, "IP: %i.%i.%i.%i", *(btIP + 3), *(btIP + 2), *(btIP + 1), *btIP);
					CMenu::getPlrFeature(PLRFEAT_INFO_IP, i)->m_szName = msg;

					//port
					sprintf_s(msg, "Port: %i", cp->pCPlayerInfo->iExternalPort);
					CMenu::getPlrFeature(PLRFEAT_INFO_PORT, i)->m_szName = msg;

					//coords
					sprintf_s(msg, "Coords: %.3f, %.3f, %.3f", cp->v3VisualPos.x, cp->v3VisualPos.y, cp->v3VisualPos.z);
					CMenu::getPlrFeature(PLRFEAT_INFO_COORDS, i)->m_szName = msg;

					//dist
					sprintf_s(msg, "Distance: %.3f", cp->v3VisualPos.getDist(script::get_entity_coords(playerPed)));
					CMenu::getPlrFeature(PLRFEAT_INFO_DISTANCE, i)->m_szName = msg;

					//health/armor
					sprintf_s(msg, "Hp/Armor: %i/%i, %i/50", (int) cp->fHealth, (int) cp->fHealthMax, (int) cp->fArmor);
					CMenu::getPlrFeature(PLRFEAT_INFO_HEALTH, i)->m_szName = msg;

					//is in veh
					sprintf_s(msg, "In Vehicle: %s", cp->isInVehicle() ? "Yes" : "No");
					CMenu::getPlrFeature(PLRFEAT_INFO_IS_IN_VEH, i)->m_szName = msg;

					//is god
					sprintf_s(msg, "Is God: %s", cp->isGod() ? "Yes" : "No");
					CMenu::getPlrFeature(PLRFEAT_INFO_IS_GOD, i)->m_szName = msg;
				}
				m_clockPlayerInfo	= clock();
			}

			if(remotePed != playerPed && !ENTITY::IS_ENTITY_VISIBLE(remotePed))
				NETWORK::SET_PLAYER_VISIBLE_LOCALLY(i, true);

			//copy ip to clipboard
			plrFeat = CMenu::getPlrFeature(PLRFEAT_INFO_IP, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet)
			{
				util::to_clipboard(&plrFeat->m_szName[0] + 4);
				plrFeat->m_bSet		= true;
			}

			//ped drop
			plrFeat = CMenu::getPlrFeature(PLRFEAT_PED_DROP, i);
			if(plrFeat->m_bOn || !plrFeat->m_bSet)
			{
				if(plrFeat->m_bOn)
					script::ped_money_drop(remotePed, &plrFeat->m_clockTick);
				else
					m_nearbyPed.clear();
				plrFeat->m_bSet		= true;
			}

			//Track player
			plrFeat = CMenu::getPlrFeature(PLRFEAT_TRACK, i);
			if(plrFeat->m_bOn || CMenu::getFeature(FEATURE_A_TRACK)->m_bOn)
				script::draw_esp_on_entity(remotePed, szName, bEspBox, bEspHealth, bEspDist, fEspMaxDist);

			//Specate player
			plrFeat = CMenu::getPlrFeature(PLRFEAT_SPECTATE, i);
			if(!plrFeat->m_bSet)
			{
				script::spectate_player(remotePed, plrFeat->m_bOn);
				plrFeat->m_bSet = true;
			}
			
			//teleport to player
			plrFeat = CMenu::getPlrFeature(PLRFEAT_TP_TO, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet)
			{
				script::teleport_to_entity(remotePed);
				plrFeat->m_bSet = true;
			}
			
			//teleport to player vehicle
			plrFeat = CMenu::getPlrFeature(PLRFEAT_TP_TO_CAR, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet)
			{
				script::teleport_to_ped_car(remotePed);
				plrFeat->m_bSet = true;
			}
			
			//teleport player to me
			plrFeat = CMenu::getPlrFeature(PLRFEAT_TP_TO_ME, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet && clock() - plrFeat->m_clockTick > 0x80)
			{
				if(script::teleport_player_to_me(remotePed, i))
					plrFeat->m_bSet = true;
				plrFeat->m_clockTick = clock();
			}
			
			//teleport player to sea
			plrFeat = CMenu::getPlrFeature(PLRFEAT_TP_TO_SEA, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet && clock() - plrFeat->m_clockTick > 0x80)
			{
				if(script::teleport_player_to_sea(remotePed, i))
					plrFeat->m_bSet = true;
				plrFeat->m_clockTick = clock();
			}
			
			//teleport player in the air
			plrFeat = CMenu::getPlrFeature(PLRFEAT_TP_TO_AIR, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet)
			{
				script::teleport_player_to_air(remotePed);
				plrFeat->m_bSet = true;
			}
			
			//explode
			plrFeat = CMenu::getPlrFeature(PLRFEAT_EXPLODE, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet)
			{
				script::explode_ped(remotePed, (int) plrFeat->getValue());
				plrFeat->m_bSet = true;
			}
			
			//Give weapon
			plrFeat = CMenu::getPlrFeature(PLRFEAT_GIVE_WEAPON, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet)
			{
				script::ped_weapon(remotePed, hash::weapon_hash[(int) plrFeat->getValue()], true);
				plrFeat->m_bSet = true;
			}
			
			//Give all weapons
			plrFeat = CMenu::getPlrFeature(PLRFEAT_GIVE_WEAPONS, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet)
			{
				script::ped_give_all_weapons(remotePed);
				plrFeat->m_bSet = true;
			}
			
			//Remove all weapons
			plrFeat = CMenu::getPlrFeature(PLRFEAT_REMOVE_WEAPONS, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet)
			{
				script::ped_weapon(remotePed, "ALL", false);
				plrFeat->m_bSet = true;
			}
			
			//Clone Ped Bodyguard
			plrFeat = CMenu::getPlrFeature(PLRFEAT_CLONE_BODYGUARD, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet)
			{
				m_pedCleanup.push_back(script::clone_ped_bodyguard(remotePed));
				plrFeat->m_bSet = true;
			}
			
			//Attach to player
			plrFeat = CMenu::getPlrFeature(PLRFEAT_ATTACH_TO, i);
			if(!plrFeat->m_bSet)
			{
				if(plrFeat->m_bOn)
					script::attach_entities(playerPed, remotePed, iAttachBone);
				else if(!plrFeat->m_bRestored)
				{
					script::detach_entity(playerPed);
					plrFeat->m_bRestored	= true;
				}
				plrFeat->m_bSet = true;
			}
			
			//Attach Piggy Back
			plrFeat = CMenu::getPlrFeature(PLRFEAT_ATTACH_PIGGY_BACK, i);
			if(!plrFeat->m_bSet)
			{
				if(plrFeat->m_bOn)
				{
					if(script::animate_local_player(playerPed, "veh@bike@dirt@front@base", "sit"))
					{
						script::attach_entities(playerPed, remotePed, 0, {0.f, -.3f, .1f});
						plrFeat->m_bSet = true;
					}
				}
				else if(!plrFeat->m_bRestored)
				{
					script::detach_entity(playerPed);
					plrFeat->m_bRestored	= true;
					plrFeat->m_bSet = true;
				}
			}
			
			//Attach 69
			plrFeat = CMenu::getPlrFeature(PLRFEAT_ATTACH_69, i);
			if(!plrFeat->m_bSet)
			{
				if(plrFeat->m_bOn)
				{
					if(script::animate_local_player(playerPed, "veh@bike@dirt@front@base", "sit"))
					{
						script::attach_entities(playerPed, remotePed, 0, {0.f, .3f, .6f}, {-10.f, 180.f, 180.f});
						plrFeat->m_bSet = true;
					}
				}
				else if(!plrFeat->m_bRestored)
				{
					script::detach_entity(playerPed);
					plrFeat->m_bRestored	= true;
					plrFeat->m_bSet = true;
				}
			}
			
			//Attach Violate
			plrFeat = CMenu::getPlrFeature(PLRFEAT_ATTACH_VIOLATE, i);
			if(!plrFeat->m_bSet)
			{
				if(plrFeat->m_bOn)
				{
					if(script::animate_local_player(playerPed, "rcmpaparazzo_2", "shag_loop_a"))
					{
						script::animate_player(remotePed, "rcmpaparazzo_2", "shag_loop_poppy");
						script::attach_entities(playerPed, remotePed, -1, { 0.f, -.37f, -.2f}, { 60.f, 0.f, 0.f});
						plrFeat->m_bSet = true;
					}
				}
				else if(!plrFeat->m_bRestored)
				{
					script::detach_entity(playerPed);
					AI::CLEAR_PED_TASKS_IMMEDIATELY(remotePed);
					plrFeat->m_bRestored = true;
					plrFeat->m_bSet = true;
				}
			}
			
			//Detach everything from the player
			plrFeat = CMenu::getPlrFeature(PLRFEAT_DETACH_ALL, i);
			if(!plrFeat->m_bSet)	//without m_bOn check, this will also be run when the hack is unloaded
			{
				for(int j = 0; j < m_remotePlayerAttach[i].size(); j++)
				{
					script::detach_entity(m_remotePlayerAttach[i][j]);
					m_entityCleanup.push_back(m_remotePlayerAttach[i][j]);
					m_remotePlayerAttach[i].erase(m_remotePlayerAttach[i].begin() + j);
					j--;
				}
				plrFeat->m_bSet = true;
			}
			
			//Attach clone to player
			plrFeat = CMenu::getPlrFeature(PLRFEAT_ATTACH_CLONE, i);
			if(!plrFeat->m_bSet && plrFeat->m_bOn)
			{
				Ped ped = remotePed;
				for(int j = 0; j < (int) plrFeat->getValue(); j++)
				{
					Ped bodyguard = script::clone_ped_bodyguard(remotePed);
					m_remotePlayerAttach[i].push_back(bodyguard);
					script::attach_entities(bodyguard, ped, iAttachBone);
					ped	= bodyguard;
				}
				plrFeat->m_bSet = true;
			}
			
			//Attach clone 69
			plrFeat = CMenu::getPlrFeature(PLRFEAT_ATTACH_CLONE_69, i);
			if(!plrFeat->m_bSet && plrFeat->m_bOn)
			{
				Ped bodyguard = script::clone_ped_bodyguard(remotePed);
				m_remotePlayerAttach[i].push_back(bodyguard);
				if(script::animate_local_player(bodyguard, "veh@bike@dirt@front@base", "sit"))
				{
					script::attach_entities(bodyguard, remotePed, 0, {0.f, .3f, .6f}, {-10.f, 180.f, 180.f});
					plrFeat->m_bSet = true;
				}
			}
			
			//Trap In Cage
			plrFeat = CMenu::getPlrFeature(PLRFEAT_TRAP_IN_CAGE, i);
			if(!plrFeat->m_bSet && plrFeat->m_bOn)
			{
				if(clock() - plrFeat->m_clockTick > 0x7FF)
					plrFeat->m_clockTick = clock();
				if(clock() - plrFeat->m_clockTick < 0x40)
					AI::CLEAR_PED_TASKS_IMMEDIATELY(remotePed);
				if(clock() - plrFeat->m_clockTick > 200)
				{
					m_remotePlayerAttach[i].push_back(script::trap_player_in_cage(remotePed));
					plrFeat->m_clockTick = clock();
					plrFeat->m_bSet = true;
				}
			}
			
			//clear tasks
			plrFeat = CMenu::getPlrFeature(PLRFEAT_CLEAR_TASKS, i);
			if(!plrFeat->m_bSet && plrFeat->m_bOn)
			{
				AI::CLEAR_PED_TASKS_IMMEDIATELY(remotePed);
				plrFeat->m_bSet = true;
			}
			
			//send assasins
			plrFeat = CMenu::getPlrFeature(PLRFEAT_CHRISFORMAGE, i);
			if(!plrFeat->m_bSet && plrFeat->m_bOn)
			{
				if(script::send_assasins_after_player(i, remotePed))
					plrFeat->m_bSet = true;
			}
			
			//shoot
			/*plrFeat = CMenu::getPlrFeature(PLRFEAT_SHOOT, i);
			if(!plrFeat->m_bSet && plrFeat->m_bOn)
			{
				script::shoot_ped(remotePed);
				plrFeat->m_bSet = true;
			}*/

			//Freeze
			plrFeat = CMenu::getPlrFeature(PLRFEAT_FREEZE, i);
			if(!plrFeat->m_bSet && plrFeat->m_bOn)
			{
				if(script::animate_player(remotePed, "mini@strip_club@pole_dance@pole_a_2_stage", "pole_a_2_stage", true))
					plrFeat->m_bSet			= true;
			}

			//Animate
			plrFeat = CMenu::getPlrFeature(PLRFEAT_ANIMATE, i);
			if(!plrFeat->m_bSet && (plrFeat->m_bOn || !plrFeat->m_bRestored))
			{
				plrFeat->m_bRestored	= plrFeat->m_bOn ? false : true;
				if(script::animate_player(remotePed, hash::ped_anim_dict[(int) plrFeat->getValue() * 2 + 1], hash::ped_anim_dict[(int) plrFeat->getValue() * 2], false, !plrFeat->m_bOn))
					plrFeat->m_bSet			= true;
			}

			//dead clones
			plrFeat = CMenu::getPlrFeature(PLRFEAT_DEAD_CLONES, i);
			if((plrFeat->m_bOn && clock() - plrFeat->m_clockTick > 500) || !plrFeat->m_bSet)
			{
				script::player_dead_clone(i, remotePed, !plrFeat->m_bOn);
				plrFeat->m_bSet			= true;
				plrFeat->m_clockTick	= clock();
			}

			//give wanted level
			plrFeat = CMenu::getPlrFeature(PLRFEAT_GIVE_WANTED, i);
			if(plrFeat->m_bOn && !plrFeat->m_bSet)
			{
				if(script::give_player_wanted_level(i, 0x14))
					plrFeat->m_bSet			= true;
			}
		}

		//all players
		checkAllPlayerFeature(FEATURE_A_TP_TO_ME, PLRFEAT_TP_TO_ME);
		checkAllPlayerFeature(FEATURE_A_TP_TO_SEA, PLRFEAT_TP_TO_SEA);
		checkAllPlayerFeature(FEATURE_A_TP_TO_AIR, PLRFEAT_TP_TO_AIR);
		checkAllPlayerFeature(FEATURE_A_GIVE_WEAPON, PLRFEAT_GIVE_WEAPON);
		checkAllPlayerFeature(FEATURE_A_GIVE_WEAPONS, PLRFEAT_GIVE_WEAPONS);
		checkAllPlayerFeature(FEATURE_A_REMOVE_WEAPONS, PLRFEAT_REMOVE_WEAPONS);
		checkAllPlayerFeature(FEATURE_A_TRAP_IN_CAGE, PLRFEAT_TRAP_IN_CAGE);
		checkAllPlayerFeature(FEATURE_A_EXPLODE, PLRFEAT_EXPLODE);
		checkAllPlayerFeature(FEATURE_A_FREEZE, PLRFEAT_FREEZE);
		checkAllPlayerFeature(FEATURE_A_CLEAR_TASKS, PLRFEAT_CLEAR_TASKS);
		checkAllPlayerFeature(FEATURE_A_ANIMATE, PLRFEAT_ANIMATE);

		//memory hack stuff
		if(m_pCPedPlayer != m_pCWorld->CPedLocalPlayer)
			m_pCPedPlayer = m_pCWorld->CPedLocalPlayer;
		if(m_pCPlayerInfo != m_pCWorld->CPedLocalPlayer->pCPlayerInfo)
			m_pCPlayerInfo = m_pCWorld->CPedLocalPlayer->pCPlayerInfo;

		if(	CMenu::getFeature(FEATURE_P_GOD)->m_bOn ||
			CMenu::getFeature(FEATURE_P_TRUEGOD)->m_bOn)		m_pCPedPlayer->giveHealth();
		if(	CMenu::getFeature(FEATURE_P_ANTINPC)->m_bOn)		killNpc();

		checkFeature<BYTE>	(	FEATURE_P_TRUEGOD,
								(m_pCPedPlayer->btGodMode | 0x01) ^ 0x01,
								m_pCPedPlayer->btGodMode | 0x01,
								&m_pCPedPlayer->btGodMode);

		checkFeature<BYTE>	(	FEATURE_P_SEATBELT,
								(m_pCPedPlayer->btSeatbelt | 0x01) ^ 0x01,
								m_pCPedPlayer->btSeatbelt | 0x01,
								&m_pCPedPlayer->btSeatbelt);

		checkFeature<BYTE>	(	FEATURE_P_NORAGDOLL,
								m_pCPedPlayer->btNoRagdoll | 0x20,
								(m_pCPedPlayer->btNoRagdoll | 0x20) ^ 0x20,
								&m_pCPedPlayer->btNoRagdoll);

		//PlayerInfo
		if(m_pCPlayerInfo != nullptr)
		{
			if(CMenu::getFeature(FEATURE_P_NEVERWANTED)->m_bOn)
				m_pCPlayerInfo->removeWanted();

			checkFeature<float>	(	FEATURE_P_SWIMSPD,
									1.f,
									CMenu::getFeature(FEATURE_P_SWIMSPD)->getValue(),
									&m_pCPlayerInfo->fSwimSpeed);

			checkFeature<float>	(	FEATURE_P_RUNSPD,
									1.f,
									CMenu::getFeature(FEATURE_P_RUNSPD)->getValue(),
									&m_pCPlayerInfo->fRunSpeed);

			checkFeature<DWORD>	(	FEATURE_P_WANTED,
									0,
									(DWORD) CMenu::getFeature(FEATURE_P_WANTED)->getValue(),
									&m_pCPlayerInfo->CWantedData.dwWantedLevel,
									false);

			checkFeature<float>	(	FEATURE_P_STAMINA,
									m_pCPlayerInfo->fStaminaMax,
									m_pCPlayerInfo->fStaminaMax,
									&m_pCPlayerInfo->fStamina);

			checkFeature<float>	(	FEATURE_P_NEVERWANTED,
									1.f,
									0.f,
									&m_pCPlayerInfo->CWantedData.fWantedCanChange);

			checkFeature<BYTE>	(	FEATURE_P_SUPERJUMP,
									0,
									m_pCPlayerInfo->btFrameFlags | (1 << 6),
									&m_pCPlayerInfo->btFrameFlags,
									false);

			checkFeature<BYTE>	(	FEATURE_P_EXPLOSIVEMELEE,
									0,
									m_pCPlayerInfo->btFrameFlags | (1 << 5),
									&m_pCPlayerInfo->btFrameFlags,
									false);

			checkFeature<BYTE>	(	FEATURE_W_FIREAMMO,
									0,
									m_pCPlayerInfo->btFrameFlags | (1 << 4),
									&m_pCPlayerInfo->btFrameFlags,
									false);

			checkFeature<BYTE>	(	FEATURE_W_EXPLOSIVEAMMO,
									0,
									m_pCPlayerInfo->btFrameFlags | (1 << 3),
									&m_pCPlayerInfo->btFrameFlags,
									false);
		}

		//Vehicle
		if(m_pCWorld->CPedLocalPlayer->pCVehicleLast != nullptr)
		{
			if(m_pCVehicle != m_pCWorld->CPedLocalPlayer->pCVehicleLast)
			{
				m_pCVehicle = m_pCWorld->CPedLocalPlayer->pCVehicleLast;
				m_CVehicle	= *m_pCVehicle;
			}

			if(m_pCVehicleHandling != m_pCWorld->CPedLocalPlayer->pCVehicleLast->pCVehicleHandling)
			{
				if(m_pCVehicleHandling != nullptr)		//restore previous vehicle handling
					*m_pCVehicleHandling	= m_CVehicleHandling;
				m_pCVehicleHandling = m_pCWorld->CPedLocalPlayer->pCVehicleLast->pCVehicleHandling;
				m_CVehicleHandling	= *m_pCVehicleHandling;
			}

			if(	CMenu::getFeature(FEATURE_V_GOD)->m_bOn ||
				CMenu::getFeature(FEATURE_V_TRUEGOD)->m_bOn)
				m_pCVehicle->giveHealth();

			checkFeature<BYTE>	(	FEATURE_V_TRUEGOD,
									(m_CVehicle.btGodMode | 0x01) ^ 0x01,
									m_CVehicle.btGodMode | 0x01,
									&m_pCVehicle->btGodMode);

			checkFeature<float>	(	FEATURE_V_GRAVITY,
									m_CVehicle.fGravity,
									CMenu::getFeature(FEATURE_V_GRAVITY)->getValue(),
									&m_pCVehicle->fGravity);

			checkFeature<BYTE>	(	FEATURE_V_BULLETPROOFTIRES,
									m_CVehicle.btBulletproofTires,
									m_CVehicle.btBulletproofTires | 0x20,
									&m_pCVehicle->btBulletproofTires);

			checkFeature<BYTE>	(	FEATURE_V_VOLTIC_BOOST,
									m_CVehicle.btVolticRocketState,
									m_CVehicle.btVolticRocketState | 0x01,
									&m_pCVehicle->btVolticRocketState,
									false);

			checkFeature<float>	(	FEATURE_V_VOLTIC_BOOST,
									m_CVehicle.fVolticRocketEnergy,
									1.25f,
									&m_pCVehicle->fVolticRocketEnergy,
									false);

			checkFeature<DWORD>	(	FEATURE_V_INF_CAR_ALARM,
									0,
									0x7FF,
									&m_pCVehicle->dwCarAlarmLength);

			checkFeature<float>	(	FEATURE_V_ACCELERATION,
									m_CVehicleHandling.fAcceleration,
									m_CVehicleHandling.fAcceleration * CMenu::getFeature(FEATURE_V_ACCELERATION)->getValue(),
									&m_pCVehicleHandling->fAcceleration);

			checkFeature<float>	(	FEATURE_V_BRAKEFORCE,
									m_CVehicleHandling.fBrakeForce,
									m_CVehicleHandling.fBrakeForce * CMenu::getFeature(FEATURE_V_BRAKEFORCE)->getValue(),
									&m_pCVehicleHandling->fBrakeForce);

			checkFeature<float>	(	FEATURE_V_TRACTION,
									m_CVehicleHandling.fTractionCurveMin,
									m_CVehicleHandling.fTractionCurveMin * CMenu::getFeature(FEATURE_V_TRACTION)->getValue(),
									&m_pCVehicleHandling->fTractionCurveMin);

			checkFeature<float>	(	FEATURE_V_DEFORMATION,
									m_CVehicleHandling.fDeformationDamageMult,
									CMenu::getFeature(FEATURE_V_DEFORMATION)->getValue(),
									&m_pCVehicleHandling->fDeformationDamageMult);

			checkFeature<float>	(	FEATURE_V_UPSHIFT,
									m_CVehicleHandling.fClutchChangeRateScaleUpShift,
									CMenu::getFeature(FEATURE_V_UPSHIFT)->getValue(),
									&m_pCVehicleHandling->fClutchChangeRateScaleUpShift);

			checkFeature<float>	(	FEATURE_V_SUSPENSION_FORCE,
									m_CVehicleHandling.fSuspensionForce,
									m_CVehicleHandling.fSuspensionForce * CMenu::getFeature(FEATURE_V_SUSPENSION_FORCE)->getValue(),
									&m_pCVehicleHandling->fSuspensionForce);
		}

		//Weapon
		if(m_pCWorld->CPedLocalPlayer->pCWeaponManager != nullptr && m_pCWorld->CPedLocalPlayer->pCWeaponManager->CWeaponCur != nullptr)
		{
			if(m_pCWeapon != m_pCWorld->CPedLocalPlayer->pCWeaponManager->CWeaponCur)
			{
				if(m_pCWeapon != nullptr)		//restore previous weapon
				{
					m_pCWeapon->dwBulletInBatch		= m_CWeapon.dwBulletInBatch;
					m_pCWeapon->fBatchSpread		= m_CWeapon.fBatchSpread;
					m_pCWeapon->fMuzzleVelocity		= m_CWeapon.fMuzzleVelocity;
					m_pCWeapon->fSpinUpTime			= m_CWeapon.fSpinUpTime;
					m_pCWeapon->fSpinTime			= m_CWeapon.fSpinTime;
					m_pCWeapon->fWeaponRange		= m_CWeapon.fWeaponRange;
					m_pCWeapon->fBulletDamage		= m_CWeapon.fBulletDamage;
					m_pCWeapon->fVehicleReloadTime	= m_CWeapon.fVehicleReloadTime;
					m_pCWeapon->fAnimReloadRate		= m_CWeapon.fAnimReloadRate;
					m_pCWeapon->fSpread				= m_CWeapon.fSpread;
					m_pCWeapon->fRecoil				= m_CWeapon.fRecoil;
				}
				m_pCWeapon	= m_pCWorld->CPedLocalPlayer->pCWeaponManager->CWeaponCur;
				m_CWeapon	= *m_pCWeapon;
			}

			checkFeature<float>	(	FEATURE_W_RECOIL,
									m_CWeapon.fRecoil,
									0.f,
									&m_pCWeapon->fRecoil);

			checkFeature<float>	(	FEATURE_W_SPREAD,
									m_CWeapon.fSpread,
									0.f,
									&m_pCWeapon->fSpread);

			checkFeature<float>	(	FEATURE_W_RELOAD,
									m_CWeapon.fAnimReloadRate,
									m_CWeapon.fAnimReloadRate * CMenu::getFeature(FEATURE_W_RELOAD)->getValue(),
									&m_pCWeapon->fAnimReloadRate);

			checkFeature<float>	(	FEATURE_W_RELOAD,
									m_CWeapon.fVehicleReloadTime,
									0.f,
									&m_pCWeapon->fVehicleReloadTime);

			checkFeature<float>	(	FEATURE_W_DAMAGE,
									m_CWeapon.fBulletDamage,
									m_CWeapon.fBulletDamage * CMenu::getFeature(FEATURE_W_DAMAGE)->getValue(),
									&m_pCWeapon->fBulletDamage);

			//checkFeature<float>	(	"FEATURE_W_RANGE",
			//						m_CWeapon.fWeaponRange,
			//						m_CWeapon.fWeaponRange * CMenu::getFeature(FEATURE_W_RANGE)->getValue(),
			//						&m_pCWeapon->fWeaponRange);

			checkFeature<float>	(	FEATURE_W_SPINUP,
									m_CWeapon.fSpinTime,
									0.f,
									&m_pCWeapon->fSpinTime);

			checkFeature<float>	(	FEATURE_W_SPINUP,
									m_CWeapon.fSpinUpTime,
									0.f,
									&m_pCWeapon->fSpinUpTime);

			/*float	fValue	= m_CWeapon.dwBulletInBatch * CMenu::getFeature(FEATURE_W_BULLET_BATCH)->getValue();
					fValue	= (fValue > 15) ? 15 : fValue;
			checkFeature<DWORD>	(	"FEATURE_W_BULLET_BATCH",
									m_CWeapon.dwBulletInBatch,
									(DWORD) fValue,
									&m_pCWeapon->dwBulletInBatch);

			checkFeature<float>	(	"FEATURE_W_MUZZLE_VELOCITY",
									m_CWeapon.fMuzzleVelocity,
									m_CWeapon.fMuzzleVelocity * CMenu::getFeature(FEATURE_W_MUZZLE_VELOCITY)->getValue(),
									&m_pCWeapon->fMuzzleVelocity);

			checkFeature<float>	(	"FEATURE_W_BATCH_SPREAD",
									m_CWeapon.fBatchSpread,
									CMenu::getFeature(FEATURE_W_BATCH_SPREAD)->getValue(),
									&m_pCWeapon->fBatchSpread);*/
		}
	}
	return 1;
}