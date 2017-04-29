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

class CHack
{
	public:
		static std::string			m_szRequestedAnim;
		static std::string			m_szRequestedAnimDict;

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

		//queue to keep track of spawned peds
		static deque_int			m_pedCleanup;
		static clock_t				m_pedCleanupClock;

		//queue where objects will be pushed to be destroyed
		static queue_int			m_entityCleanup;
		static clock_t				m_entityCleanupClock;
		static int					m_entityCleanupTries;

		//a deque for each player, to store every attached entity
		static deque_int			m_remotePlayerAttach[MAX_PLAYERS];

		//model change vars
		static std::string			m_szRequestedModel;
		static bool					m_bModelSet;
		static bool					m_bModelWeapons;
		static clock_t				m_modelClock;

		//spawn requests
		static queue_str	m_requestedVehicle;
		static queue_str	m_requestedWeapon;
		static bool			m_bWeaponGive;
		static queue_str	m_requestedPed;
		static queue_str	m_requestedObject;

		// queue with nearby peds, updated by update_nearby_ped() (by default)
		static queue_int	m_nearbyPed;
		static queue_int	m_nearbyVehicle;

		//teleport
		static v3	m_v3Teleport;

		//player info update timer
		static clock_t	m_clockPlayerInfo;

		//functions
		static void	killNpc();
		//static void	fillAmmo();
		static bool	refresh();

	private:
		CHack() {};		//don't allow creating instance of the object
		~CHack() {};


		template <typename T>
		static bool	checkFeature(eFeatures feat, T TDefault, T TValue, T* TOut, bool bRestore = true)
		{
			CFeat* CFeature	= CMenu::getFeature(feat);
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

		static void	checkAllPlayerFeature(eFeatures feature, ePlrFeats plrFeature, int flag);
};

#endif