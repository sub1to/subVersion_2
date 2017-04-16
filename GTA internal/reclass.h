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
#ifndef RECLASS_H
#define RECLASS_H

#pragma pack(push, 1)

// Generated using ReClass 2015

class CWorld;
class CPed;
class CNavigation;
class CWorld_Wrap;
class CAttacker;
class CVehicle;
class CPlayerInfo;
class CWeaponManager;
class CWeapon;
class CAmmoInfo;
class CVehicleColors;
class CVehicleColorOptions;
class CVehicleHandling;
class CWantedData;
class CItemInfo;
class CAmmo;

class CWorld
{
public:
	char pad_0x0000[0x8]; //0x0000
	CPed* CPedLocalPlayer; //0x0008 

}; //Size=0x0010

class CPed
{
public:
	char pad_0x0000[0x2C]; //0x0000
	BYTE btInvisibleSP; //0x002C 
	char pad_0x002D[0x1]; //0x002D
	BYTE btFreezeMomentum; //0x002E 
	char pad_0x002F[0x1]; //0x002F
	CNavigation* pCNavigation; //0x0030 
	char pad_0x0038[0x58]; //0x0038
	v3 v3VisualPos; //0x0090 
	char pad_0x009C[0xED]; //0x009C
	BYTE btGodMode; //0x0189 
	char pad_0x018A[0xF6]; //0x018A
	float fHealth; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	float fHealthMax; //0x02A0 
	char pad_0x02A4[0x4]; //0x02A4
	CAttacker* pCAttacker; //0x02A8 
	char pad_0x02B0[0x70]; //0x02B0
	v3 v3Velocity; //0x0320 
	char pad_0x032C[0x9FC]; //0x032C
	CVehicle* pCVehicleLast; //0x0D28 
	char pad_0x0D30[0x378]; //0x0D30
	BYTE btNoRagdoll; //0x10A8 
	char pad_0x10A9[0xF]; //0x10A9
	CPlayerInfo* pCPlayerInfo; //0x10B8 
	char pad_0x10C0[0x8]; //0x10C0
	CWeaponManager* pCWeaponManager; //0x10C8 
	char pad_0x10D0[0x31C]; //0x10D0
	BYTE btSeatbelt; //0x13EC 
	char pad_0x13ED[0xB]; //0x13ED
	BYTE btSeatbeltWindshield; //0x13F8 
	char pad_0x13F9[0x72]; //0x13F9
	BYTE btIsInVehicle; //0x146B 
	char pad_0x146C[0x44]; //0x146C
	float fArmor; //0x14B0 
	char pad_0x14B4[0x20]; //0x14B4
	float fFatiguedHealthThreshold; //0x14D4 
	float fInjuredHealthThreshold; //0x14D8 
	float fDyingHealthThreshold; //0x14DC 
	float fHurtHealthThreshold; //0x14E0 
	char pad_0x14E4[0xC]; //0x14E4
	CVehicle* pCVehicleLast2; //0x14F0 
	char pad_0x14F8[0xDC]; //0x14F8
	__int32 iCash; //0x15D4 

	bool isGod()
	{
		return(	(btGodMode & 0x01)
			||	fFatiguedHealthThreshold < 0.f
			||	fInjuredHealthThreshold < 0.f
			||	fDyingHealthThreshold < 0.f
			||	fHurtHealthThreshold < 0.f		);
	}

	bool isInvisSP()
	{
		return (btInvisibleSP & 0x01) ? true : false;
	}

	bool hasFrozenMomentum()
	{
		return (btFreezeMomentum & 0x02) ? true : false;
	}

	bool canBeRagdolled()
	{
		return (btNoRagdoll & 0x20) ? false : true;
	}

	bool hasSeatbelt()
	{
		return (btSeatbelt & 0x01) ? true : false;
	}

	bool hasSeatbeltWindshield()
	{
		return (btSeatbeltWindshield & 0x10) ? true : false;
	}

	bool isInVehicle()
	{
		return (btIsInVehicle & 0x10) ? false : true;
	}

	void giveHealth()
	{
		if(fHealth	< fHealthMax)
			fHealth	= fHealthMax;
		if(fArmor < 50.f)
			fArmor = 50.f;
	}
}; //Size=0x14F8

/*class CNavigation
{
public:
	char pad_0x0000[0x50]; //0x0000
	v3 v3Pos; //0x0050 

}; //Size=0x005C*/

class CNavigation
{
public:
	char pad_0x0000[0x20]; //0x0000
	float fHeading; //0x0020 
	float fHeading2; //0x0024 
	char pad_0x0028[0x8]; //0x0028
	v3 v3Rotation; //0x0030 
	char pad_0x003C[0x14]; //0x003C
	v3 v3Pos; //0x0050 

}; //Size=0x005C

class CWorld_Wrap
{
public:
	CWorld* CWorld; //0x0000 

}; //Size=0x0008

class CAttacker
{
public:
	CPed* CPed0; //0x0000 
	char pad_0x0008[0x10]; //0x0008
	CPed* CPed1; //0x0018 
	char pad_0x0020[0x10]; //0x0020
	CPed* CPed2; //0x0030 

}; //Size=0x0038

class CVehicle
{
public:
	char pad_0x0000[0x30]; //0x0000
	CNavigation* pCNavigation; //0x0030 
	char pad_0x0038[0x10]; //0x0038
	CVehicleColorOptions* pCVehicleColorOptions; //0x0048 
	char pad_0x0050[0x40]; //0x0050
	v3 v3VisualPos; //0x0090 
	char pad_0x009C[0xED]; //0x009C
	BYTE btGodMode; //0x0189 
	char pad_0x018A[0xF6]; //0x018A
	float fHealth; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	float fHealthMax; //0x02A0 
	char pad_0x02A4[0x4]; //0x02A4
	CAttacker* pCAttacker; //0x02A8 
	char pad_0x02B0[0x6A]; //0x02B0
	BYTE btVolticRocketState; //0x031A 
	char pad_0x031B[0x1]; //0x031B
	float fVolticRocketEnergy; //0x031C 
	char pad_0x0320[0x430]; //0x0320
	v3 v3Velocity; //0x0750 
	char pad_0x075C[0xF0]; //0x075C
	float fHealth2; //0x084C 
	char pad_0x0850[0x28]; //0x0850
	CVehicleHandling* pCVehicleHandling; //0x0878 
	char pad_0x0880[0x3]; //0x0880
	BYTE btBulletproofTires; //0x0883 
	char pad_0x0884[0x160]; //0x0884
	DWORD dwCarAlarmLength; //0x09E4 
	char pad_0x09E8[0x148]; //0x09E8
	BYTE btOpenableDoors; //0x0B30 
	char pad_0x0B31[0x4B]; //0x0B31
	float fGravity; //0x0B7C 

	bool isGod()
	{
		return (btGodMode & 0x01) ? true : false;
	}

	bool hasBulletproofTires()
	{
		return (btBulletproofTires & 0x20) ? true : false;
	}

	bool disabledDoors()
	{
		return (btOpenableDoors == 0) ? true : false;
	}

	void giveHealth()
	{
		if(fHealth < fHealthMax)
			fHealth = fHealthMax;
		if(fHealth2 < fHealthMax)
			fHealth2 = fHealthMax;
	}
}; //Size=0x0B80

class CWantedData
{
public:
	char pad_0x0000[0x2C]; //0x0000
	float fWantedCanChange; //0x002C 
	char pad_0x0030[0x10]; //0x0030
	v3 v3WantedCenterPos; //0x0040 
	char pad_0x004C[0x4]; //0x004C
	v3 v3WantedCenterPos2; //0x0050 
	char pad_0x005C[0x38]; //0x005C
	BYTE btFlag0; //0x0094 
	BYTE btFlag1; //0x0095 
	BYTE btFlag2; //0x0096 
	BYTE btFlag3; //0x0097 
	char pad_0x0098[0xC]; //0x0098
	DWORD dwWantedLevelFake; //0x00A4 
	DWORD dwWantedLevel; //0x00A8 

}; //Size=0x00AC

class CPlayerInfo
{
public:
	char pad_0x0000[0x34]; //0x0000
	__int32 iInternalIP; //0x0034 
	__int16 iInternalPort; //0x0038 
	char pad_0x003A[0x2]; //0x003A
	__int32 iRelayIP; //0x003C 
	__int16 iRelayPort; //0x0040 
	char pad_0x0042[0x2]; //0x0042
	__int32 iExternalIP; //0x0044 
	__int16 iExternalPort; //0x0048 
	char pad_0x004A[0x32]; //0x004A
	char sName[32]; //0x007C 
	char pad_0x009C[0x48]; //0x009C
	float fSwimSpeed; //0x00E4 
	float fRunSpeed; //0x00E8 
	char pad_0x00EC[0x74]; //0x00EC
	CPed* pCPed; //0x0160 
	char pad_0x0168[0x29]; //0x0168
	BYTE btFrameFlags; //0x0191 
	char pad_0x0192[0x55E]; //0x0192
	CWantedData CWantedData; //0x06F0 
	char pad_0x079C[0x464]; //0x079C
	float fStamina; //0x0C00 
	float fStaminaMax; //0x0C04

	void removeWanted()
	{
		if(CWantedData.dwWantedLevel > 0)
			CWantedData.dwWantedLevel = 0;
	}

}; //Size=0x0C08

class CWeaponManager
{
public:
	char pad_0x0000[0x20]; //0x0000
	CWeapon* CWeaponCur; //0x0020 

}; //Size=0x0028

class CWeapon
{
public:
	char pad_0x0000[0x10]; //0x0000
	DWORD dwNameHash; //0x0010 
	DWORD dwModelHash; //0x0014 
	char pad_0x0018[0x24]; //0x0018
	DWORD dwAmmoType; //0x003C 
	DWORD dwWeaponWheelSlot; //0x0040 
	char pad_0x0044[0x4]; //0x0044
	CAmmoInfo* CAmmoInfo; //0x0048 
	char pad_0x0050[0xC]; //0x0050
	float fSpread; //0x005C 
	char pad_0x0060[0x38]; //0x0060
	float fBulletDamage; //0x0098 
	char pad_0x009C[0x1C]; //0x009C
	float fForce; //0x00B8 
	float fForcePed; //0x00BC 
	float fForceVehicle; //0x00C0 
	float fForceFlying; //0x00C4 
	char pad_0x00C8[0x34]; //0x00C8
	float fMuzzleVelocity; //0x00FC 
	DWORD dwBulletInBatch; //0x0100 
	float fBatchSpread; //0x0104 
	char pad_0x0108[0x8]; //0x0108
	float fVehicleReloadTime; //0x0110 
	float fAnimReloadRate; //0x0114 
	char pad_0x0118[0xC]; //0x0118
	float fSpinUpTime; //0x0124 
	float fSpinTime; //0x0128 
	char pad_0x012C[0x12C]; //0x012C
	float fLockOnRange; //0x0258 
	float fWeaponRange; //0x025C 
	char pad_0x0260[0x44]; //0x0260
	float fRecoil; //0x02A4 

}; //Size=0x02A8

class CAmmo
{
public:
	char pad_0x0000[0xC]; //0x0000
	DWORD dwUnknown; //0x000C 
	char pad_0x0010[0x8]; //0x0010
	DWORD dwAmmo; //0x0018 

}; //Size=0x001C

class CAmmoWrap
{
public:
	CAmmo* CAmmo; //0x0000 
	CAmmoWrap* AmmoWrap; //0x0008 

}; //Size=0x0010

class CAmmoInfo
{
public:
	char pad_0x0000[0x8]; //0x0000
	CAmmoWrap* CAmmoWrap; //0x0008 
	char pad_0x0010[0x18]; //0x0010
	DWORD dwMaxAmmo; //0x0028 

}; //Size=0x002C

class CVehicleColors
{
public:
	char pad_0x0000[0xA4]; //0x0000
	BYTE btPrimaryBlue; //0x00A4 
	BYTE btPrimaryGreen; //0x00A5 
	BYTE btPrimaryRed; //0x00A6 
	BYTE btPrimaryAlpha; //0x00A7 
	BYTE btSecondaryBlue; //0x00A8 
	BYTE btSecondaryGreen; //0x00A9 
	BYTE btSecondaryRed; //0x00AA 
	BYTE btSecondaryAlpha; //0x00AB 

}; //Size=0x00AC

class CVehicleColorOptions
{
public:
	char pad_0x0000[0x20]; //0x0000
	CVehicleColors* CVehicleColor; //0x0020 

}; //Size=0x0028

class CVehicleHandling
{
public:
	char pad_0x0000[0xC]; //0x0000
	float fMass; //0x000C 
	char pad_0x0010[0x10]; //0x0010
	v3 v3CentreOfMassOffset; //0x0020 
	char pad_0x002C[0x4]; //0x002C
	v3 v3InertiaMult; //0x0030 
	char pad_0x003C[0x4]; //0x003C
	float fPercentSubmerged; //0x0040 
	char pad_0x0044[0x8]; //0x0044
	float fAcceleration; //0x004C 
	BYTE btInitialDriveGears; //0x0050 
	char pad_0x0051[0x3]; //0x0051
	float fDriveInertia; //0x0054 
	float fClutchChangeRateScaleUpShift; //0x0058 
	float fClutchChangeRateScaleDownShift; //0x005C 
	float fInitialDriveForce; //0x0060 
	char pad_0x0064[0x8]; //0x0064
	float fBrakeForce; //0x006C 
	char pad_0x0070[0x4]; //0x0070
	float fBrakeBiasFront; //0x0074 
	char pad_0x0078[0x4]; //0x0078
	float fHandBrakeForce; //0x007C 
	char pad_0x0080[0x8]; //0x0080
	float fTractionCurveMax; //0x0088 
	char pad_0x008C[0x4]; //0x008C
	float fTractionCurveMin; //0x0090 
	char pad_0x0094[0xC]; //0x0094
	float fTractionSpringDeltaMax; //0x00A0 
	char pad_0x00A4[0x4]; //0x00A4
	float fLowSpeedTractionLossMult; //0x00A8 
	float fCamberStiffnesss; //0x00AC 
	float fTractionBiasFront; //0x00B0 
	float fTwoMinus_fTractionBiasFront; //0x00B4 
	float fTractionLossMult; //0x00B8 
	float fSuspensionForce; //0x00BC 
	float fSuspensionCompDamp; //0x00C0 
	float fSuspensionReboundDamp; //0x00C4 
	float fSuspensionUpperLimit; //0x00C8 
	float fSuspensionLowerLimit; //0x00CC 
	char pad_0x00D0[0xC]; //0x00D0
	float fAntiRollBarForce; //0x00DC 
	char pad_0x00E0[0x8]; //0x00E0
	float fRollCentreHeightFront; //0x00E8 
	float fRollCentreHeightRear; //0x00EC 
	float fCollisionDamageMult; //0x00F0 
	float fWeaponDamageMult; //0x00F4 
	float fDeformationDamageMult; //0x00F8 
	float fEngineDamageMult; //0x00FC 
	float fPetrolTankVolume; //0x0100 
	float fOilVolume; //0x0104 

}; //Size=0x0108







class CObjectWrapper
{
public:
    char _0x0000[168];
    CPlayerInfo* playerInfo; //0x00A8 

};//Size=0x00B0

class CPlayers
{
public:
    char _0x0000[376];
    __int32 numPlayersOnline; //0x0178 
    char _0x017C[4];
    CObjectWrapper* ObjectWrapperList[256]; //0x0180 
};







class CReplayInterfacePed
{
private:
    class CPedList
    {
    private:
    	struct Ped
    	{
    		CPed* ped;
			__int32 handle;
    		char _pad0[0x4];
    	};
     
    public:
    	Ped peds[0x100];
    };
     
public:
    char _pad0[0x100];			// 0000 - 0100
    CPedList* ped_list;			// 0100 - 0108
    int max_peds;				// 0108 - 010C
    char _pad1[0x4];			// 010C - 0110
    int number_of_peds;			// 0110 - 0114
     
    CPed* get_ped(const int& index)
    {
		if(index < max_peds)
			return ped_list->peds[index].ped;
		return nullptr;
    }

	int get_ped_handle(const int& index)
    {
		if(index < max_peds && ped_list->peds[index].ped != nullptr)
			return ped_list->peds[index].handle;
		return -1;
    }
};

class CPickup
{
public:
    char _0x0000[0x30];
    CNavigation* Navigation; //0x0030 
    char _0x0038[0x58];
    v3 VisualPosition; //0x0090 
    char _0x009C[0x3F4];
    __int32 iMoney; //0x0490 
    char _0x0484[0x104];

};//Size=0x0588

class PickupHandle
{
public:
    CPickup* pickup; //0x0000 
    __int32 handle; //0x0008
	char _pad0[0x4];

};//Size=0x0588

class CPickupList
{
public:
    PickupHandle pickups[0x49];//pickups[0x49]; //0x0000 

};//Size=0x0490

class CReplayInterfacePickup
{
public:
    char _0x0000[0x100];
    CPickupList* pickup_list; //0x0100 
    __int32 max_pickups; //0x0108 
    char _0x010C[0x4];
    __int32 number_of_pickups; //0x0110 
    char _0x0114[0x34];

	CPickup* get_pickup(const int& index)
    {
		if(index < max_pickups)
			return pickup_list->pickups[index].pickup;
		return nullptr;
    }

};//Size=0x0148


class CReplayInterface
{
public:
    void* game_interface;
    void* camera_interface;
    void* vehicle_interface;
    CReplayInterfacePed* ped_interface;
    CReplayInterfacePickup* pickup_interface;
    void* object_interface;
};


class CBlip
{
public:
	__int32 iID; //0x0000 
	__int8 iID2; //0x0004 
	char _0x0005[3];
	BYTE N000010FB; //0x0008 (80 = moves with player, some values will turn icon into map cursor and break it)
	char _0x0009[7];
	v3 v3Pos;
	char _0x001C[6];
	BYTE btFocused; //0x0022   (Focused? 0100 0000)
	char _0x0023[5];
	char* szMessage; //0x0028 If not null, contains the string of whatever the blip says when selected.
	char _0x0030[16];
	int iIcon; //0x0040
	char _0x0044[4];
	DWORD dwColor; //0x0048 (Sometimes works?)
	char _0x004C[4];
	float fScale; //0x0050 
	__int16 iRotation; //0x0054 Heading
	BYTE btInfoIDType; //0x0056 GET_BLIP_INFO_ID_TYPE
	BYTE btZIndex; //0x0057 
	BYTE btDisplay; //0x0058  Also Visibility 0010
	BYTE btAlpha; //0x0059
};//Size=0x005A

class CBlipList
{
public:
	CBlip* m_Blips[0x400]; //0x0000 

};//Size=0x2F18

#pragma pack(pop)

#endif