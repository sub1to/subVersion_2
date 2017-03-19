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
#ifndef HACK_H
#define HACK_H

#define MAX_PLAYERS					0x20
#define MAX_SPAWNED_PEDS			0x10

typedef struct playerAttach
{
	int			player,
				bone;
	std::string hash;
} playerAttach;

typedef	std::vector<int>			vec_int;
typedef	std::vector<std::string>	vec_str;
typedef std::vector<playerAttach>	vec_attach;

class CHack
{
	public:
		//structs
		static CPlayers*			m_pCPlayers;
		static CWorld*				m_pCWorld;
		static CPed*				m_pCPedPlayer;
		static CPlayerInfo*			m_pCPlayerInfo;
		static CVehicle*			m_pCVehicle;
		static CVehicleHandling*	m_pCVehicleHandling;
		static CWeapon*				m_pCWeapon;

		//backups for default values
		static CVehicle				m_CVehicle;
		static CVehicleHandling		m_CVehicleHandling;
		static CWeapon				m_CWeapon;

		//last vehicle
		static int					m_lastVehicle;

		//vector to keep track of spawned peds
		static vec_int				m_pedCleanup;
		static clock_t				m_pedCleanupClock;

		//vector where objects will be pushed to be destroyed
		static vec_int				m_entityCleanup;
		static clock_t				m_entityCleanupClock;
		static int					m_entityCleanupTries;

		//a vector for each player, to store every attached entity
		static vec_int				m_remotePlayerAttach[MAX_PLAYERS];
		static vec_attach			m_requestedAttach;

		//model change vars
		static std::string			m_szRequestedModel;
		static bool					m_bModelSet;
		static bool					m_bModelWeapons;
		static clock_t				m_modelClock;

		//spawn requests
		static vec_str	m_requestedVehicle;
		static vec_str	m_requestedWeapon;
		static bool		m_bWeaponGive;
		static vec_str	m_requestedPed;
		static vec_str	m_requestedObject;

		// vector with nearby peds, update by update_nearby_ped()
		static std::vector<int>	m_nearbyPed;
		static std::vector<int>	m_nearbyVehicle;

		//teleport
		static v3	m_v3Teleport;

		//functions
		static void	killNpc();
		static void	fillAmmo();
		static bool	refresh();

	private:
		CHack() {};		//don't allow creating instance of the object
		~CHack() {};


		template <typename T>
		static bool	checkFeature(std::string szFeature, T TDefault, T TValue, T* TOut, bool bRestore = true)
		{
			CFeat* CFeature	= CMenu::getFeature(feature::map[szFeature]);
			if(!CFeature->m_bOn)
			{
				if(!CFeature->m_bRestored)
				{
					if(*TOut != TDefault && bRestore)
						*TOut = TDefault;
					CFeature->m_bRestored = true;
				}
				return 0;
			}
			if(*TOut != TValue)
				*TOut	= TValue;
			return 1;
		}

		static void	checkAllPlayerFeature(std::string feature, std::string plrFeature, int flag);
};

#endif