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
//class CVehicleColors;
//class CVehicleColorOptions;
class CVehicleHandling;
class CWantedData;
class CItemInfo;
class CAmmo;
class CViewPort;
class CVehicleMods;
class CVehicleModsVisual;
class CTireInfo;
class CLicencePlateInfo;
class CColor;
class CTextInfo;
class CPedStyle;

class CCameraInterface;
class CVehicleInterface;
class CPedInterface;
class CPickupInterface;
class CPickupList;
class CPickupHandle;
class CPickup;
class CPedList;
class CPedHandle;
class CVehList;
class CVehHandle;
class CObjectInterface;
class CObjectList;
class CObjectHandle;
class CObject;

class CColor
{
public:
	BYTE	r,g,b,a;

	CColor&	swap_r_b()
	{
		std::swap(r, b);
		return *this;
	}
};

class CWorld
{
public:
	char pad_0x0000[0x8]; //0x0000
	CPed* CPedLocalPlayer; //0x0008 

}; //Size=0x0010

class CPed
{
public:
	char pad_0x0000[0x28]; //0x0000
	BYTE btEntityType; //0x0028 
	char pad_0x0029[0x3]; //0x0029
	BYTE btInvisible; //0x002C 
	char pad_0x002D[0x1]; //0x002D
	BYTE btFreezeMomentum; //0x002E 
	char pad_0x002F[0x1]; //0x002F
	CNavigation* pCNavigation; //0x0030 
	char pax_0x0038[0x10]; //0x0038
	CPedStyle*	pCPedStyle; //0x0048
	char pad_0x0038[0x40]; //0x0050
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
	BYTE btSeatBelt; //0x13EC 
	char pad_0x13ED[0xB]; //0x13ED
	BYTE btSeatbeltWindshield; //0x13F8 
	char pad_0x13F9[0x1]; //0x13F9
	BYTE btCanSwitchWeapons; 
	char pad_0x13FB[0x5]; 
	BYTE btForcedAim; //0x1400 
	BYTE N00000936; //0x1401 
	BYTE N00000939; //0x1402 
	BYTE N00000937; //0x1403 
	char pad_0x1404[0x67]; //0x1404
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

//entity type 3 = car, 4 = ped
	bool isGod()
	{
		return(	(btGodMode & 0x01)
			//||	fFatiguedHealthThreshold < 0.f
			//||	fInjuredHealthThreshold < 0.f
			//||	fDyingHealthThreshold < 0.f
			||	fHurtHealthThreshold < 0.f		);
	}

	bool isInvisible()
	{
		return (btInvisible & 0x01) ? true : false;
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
		return (btSeatBelt & 0x01) ? true : false;
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

	void giveHealth(float value)
	{
		value	+= fHealth;
		if(value <= fHealthMax)
			fHealth	= value;
		else if(fHealth	< fHealthMax)
			fHealth	= fHealthMax;
	}

	void setForcedAim(bool toggle)
	{
		btForcedAim ^= (btForcedAim ^ -(char)toggle) & 0x20;
	}
}; //Size=0x15D8

class CPedStyle
{
public:
    char _0x0000[48];
    void* N4100AE4A; //0x0030 
    void* pColors; //0x0038 
    char _0x0040[168];
    BYTE propIndex[12]; //0x00E8 
    char _0x00F4[12];
    BYTE textureIndex[12]; //0x0100 
	BYTE paletteIndex[12]; //0x10C
    char _0x010C[9];
    BYTE N4100F70F; //0x0121 
    BYTE N4134BE09; //0x0122 
    BYTE N4134C676; //0x0123 
    BYTE btEars; //0x0124 
    char _0x0125[3];
    BYTE btEarsTexture; //0x0128 
    char _0x0129[72];
    BYTE N4100F719; //0x0171 
    BYTE N413811BF; //0x0172 
    BYTE N41381E8E; //0x0173 
    BYTE btHats; //0x0174 
    char _0x0175[3];
    BYTE btHatsTexture; //0x0178 
    BYTE N4100F71A; //0x0179 
    BYTE N4461C523; //0x017A 
    BYTE N4461D118; //0x017B 
    BYTE N4461C524; //0x017C 
    BYTE N445D0F2B; //0x017D 
    BYTE N445D279D; //0x017E 
    BYTE N445D3102; //0x017F 
    BYTE N445D279E; //0x0180 
    BYTE N4100F71B; //0x0181 
    BYTE N445D522D; //0x0182 
    BYTE N445D5D09; //0x0183 
    char _0x0184[61];
    BYTE N4100F723; //0x01C1 
    BYTE N4132EABE; //0x01C2 
    BYTE N4132F80B; //0x01C3 
    BYTE btGlasses; //0x01C4 
    char _0x01C5[3];
    BYTE btGlassesTexture; //0x01C8 
};//Size=0x03A8

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
	CVehicleMods* pCVehicleMods; //0x0048 
	char pad_0x0050[0x40]; //0x0050
	v3 v3VisualPos; //0x0090 
	char pad_0x009C[0x3C]; //0x009C
	BYTE btState; //0x00D8 
	char pad_0x00D9[0xB0]; //0x00D9
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
	char pad_0x0884[0x4]; //0x0884
	BYTE btStolen; //0x0888 
	char pad_0x0889[0x11]; //0x0889
	BYTE N00000954; //0x089A 
	char pad_0x089B[0x41]; //0x089B
	float N0000081E; //0x08DC 
	char pad_0x08E0[0x58]; //0x08E0
	float fDirtLevel; //0x0938			max = 15.f
	char pad_0x093C[0xA8]; //0x093C
	DWORD dwCarAlarmLength; //0x09E4 
	char pad_0x09E8[0x148]; //0x09E8
	BYTE btOpenableDoors; //0x0B30 
	char pad_0x0B31[0x4B]; //0x0B31
	float fGravity; //0x0B7C
	BYTE btMaxPassengers; //0x0B80 
	char pad_0x0B81[0x1]; //0x0B81
	BYTE btNumOfPassengers; //0x0B82 
	char pad_0x0B83[0x3D]; //0x0B83

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

//btState & 7    0 = inside of vehicle, 2 = outside of vehicle, 3 = vehicle blown up
	bool isVehicleDestroyed()
	{
		return (btState & 7) == 3;
	}

	void set_stolen(bool toggle)
	{
		this->btStolen	&= 0xFEu;
		this->btStolen	|= toggle & 1;
	}
}; //Size=0x0BC0

class CWantedData
{
public:
	char pad_0x0000[0x1C]; //0x0000
	float fWantedCanChange; //0x001C 
	char pad_0x0020[0x10]; //0x0020
	v3 v3WantedCenterPos; //0x0030 
	char pad_0x003C[0x4]; //0x003C
	v3 v3WantedCenterPos2; //0x0040 
	char pad_0x004C[0x38]; //0x004C
	BYTE btFlag0; //0x0084 
	BYTE btFlag1; //0x0085 
	BYTE btFlag2; //0x0086 
	BYTE btFlag3; //0x0087 
	char pad_0x0088[0xC]; //0x0088
	DWORD dwWantedLevelFake; //0x0094 
	DWORD dwWantedLevel; //0x0098 

}; //Size=0x009C

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
	char sName[20]; //0x007C 
	char pad_0x0090[0x4]; //0x0090
	__int32 iTeam; //0x0094 
	char pad_0x0098[0x4C]; //0x0098
	float fSwimSpeed; //0x00E4 
	float fRunSpeed; //0x00E8 
	char pad_0x00EC[0x74]; //0x00EC
	CPed* pCPed; //0x0160 
	char pad_0x0168[0x29]; //0x0168
	BYTE btFrameFlags; //0x0191 
	char pad_0x0192[0x56E]; //0x0192
	CWantedData CWantedData; //0x0700 
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
	DWORD dwRecoil; //0x02A4 
	DWORD dwRecoilFP; //0x02A8 

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

/*class CVehicleColors
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

}; //Size=0x0028*/

class CVehicleMods
{
public:
	void* N00002582; //0x0000 
	void* N00002583; //0x0008 
	char _0x0010[16];
	CVehicleModsVisual* vehicleModsVisual; //0x0020 
	char _0x0028[840];
	CTireInfo* pTireInfo; //0x0370 
	char _0x0378[40];
	CColor NeonColor; //0x03A0 
	char _0x03A4[12];
	BYTE btTuningTires; //0x03B0 
	BYTE N41D07714; //0x03B1 
	BYTE btSpoiler; //0x03B2 
	BYTE btFrontBumper; //0x03B3 
	BYTE btRearBumber; //0x03B4 
	BYTE btSideSkirt; //0x03B5 
	BYTE btExhaust; //0x03B6 
	BYTE btChassis; //0x03B7 
	BYTE btGrille; //0x03B8 
	BYTE btHood; //0x03B9 
	BYTE btFender; //0x03BA 
	BYTE btRightfender; //0x03BB 
	BYTE btRoof; //0x03BC 
	BYTE btPlateholder; //0x03BD 
	BYTE btVanityPlates; //0x03BE 
	BYTE btTrim; //0x03BF 
	BYTE btOrnamentHead; //0x03C0 
	BYTE btDashboard; //0x03C1 
	BYTE btDial; //0x03C2 
	BYTE btDoorSpeaker; //0x03C3 
	BYTE btSteats; //0x03C4 
	BYTE btSteeringwheel; //0x03C5 
	BYTE btShifterLeavers; //0x03C6 
	BYTE btPlaques; //0x03C7 
	BYTE btSpeakers; //0x03C8 
	BYTE btTrunk; //0x03C9 
	BYTE btHydraulics; //0x03CA 
	BYTE btEngineBlock; //0x03CB 
	BYTE btAirFilter; //0x03CC 
	BYTE btStruts; //0x03CD 
	BYTE btArchCover; //0x03CE 
	BYTE btAerials; //0x03CF 
	BYTE btTrim2; //0x03D0 
	BYTE btFuel; //0x03D1 
	BYTE btWindow; //0x03D2 
	BYTE btunk1; //0x03D3 
	BYTE btLivery; //0x03D4 
	BYTE N41D48824; //0x03D5 
	BYTE btEngine; //0x03D6 
	BYTE btBreaks; //0x03D7 
	BYTE btTransmission; //0x03D8 
	BYTE btHorns; //0x03D9 
	BYTE btSuspension; //0x03DA 
	BYTE btArmor; //0x03DB 
	BYTE N41884B66; //0x03DC 
	BYTE btTurbo; //0x03DD 
	BYTE N41D63CF5; //0x03DE 
	BYTE btTireSmoke; //0x03DF 
	BYTE N41D63CF6; //0x03E0 
	BYTE btXenonLight; //0x03E1 
	BYTE btTireIndex; //0x03E2 
	BYTE N41D631AD; //0x03E3 
	BYTE N41884B65; //0x03E4 
	BYTE btOrnamentBody; //0x03E5 
	char _0x03E6[14];
	BYTE N41D9A820; //0x03F4 
	BYTE btPrimary; //0x03F5 
	BYTE btSecondary; //0x03F6 
	BYTE btPearlescent; //0x03F7 
	BYTE btWheelColor; //0x03F8 
	BYTE N41DA70FC; //0x03F9 
	BYTE N41DA7E0A; //0x03FA 
	BYTE btTireColorR; //0x03FB 
	BYTE btTireColorG; //0x03FC 
	BYTE btTireColorB; //0x03FD 
	BYTE btWindowTint; //0x03FE 
	BYTE btTireType; //0x03FF 
	BYTE N41884B5A; //0x0400 
	BYTE btNeonLeft; //0x0401 
	BYTE btNeonRight; //0x0402 
	BYTE btNeonFront; //0x0403 
	BYTE btNeonBack; //0x0404 
};
class CTireInfo
{
public:
	char _0x0000[8];
	CColor tireColor; //0x0008 
	char _0x000C[4];
	BYTE btCustumTires; //0x0010 
};//Size=0x0108


class CLicencePlateInfo
{
public:
	char _0x0000[40];
	char* plateName; //0x0028 
	char _0x0030[136];
	char* tireName; //0x00B8 
	char _0x00C0[136];
	char* visualName; //0x0148 
	char _0x0150[48];
};

class CVehicleModsVisual
{
public:
	char _0x0000[164];
	CColor PrimaryColor; //0x00A4 
	CColor SecondaryColor; //0x00A8 
	CColor unknownColor; //0x00AC 
	CColor wheelColor; //0x00B0 
	CColor modelColor; //0x00B4 
	CColor seatColor; //0x00B8 
	CColor speedometerColor; //0x00BC 
	CColor perlColor; //0x00C0 
	char _0x00C4[92];
	CLicencePlateInfo* pLicencePlateInfo; //0x0120 
	char licencePlate[8]; //0x0128 
	char _0x0130[2956];

};//Size=0x0CBC


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


class CViewPort
{
public:
	char _0x0000[0x24C];
	float fViewMatrix[0x10];
};//Size=0x028C





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






/*
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

	/*int get_ped_handle(const int& index)
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

class VehicleHandle
{
public:
    CVehicle* vehicle; //0x0000 
    __int32 handle; //0x0008
	char _pad0[0x4];

};//Size=0x0588

class CVehicleList
{
public:
    VehicleHandle vehicles[0x100];//0x0000 

};//Size=0x0490

class CReplayInterfaceVehicle
{
public:
    char _0x0000[0x180];
    CVehicleList* vehicle_list; //0x0180
    __int32 max_vehicles; //0x0188 
    char _0x010C[0x4];
    __int32 number_of_vehicles; //0x0190 
    char _0x0114[0x34];

	CVehicle* get_vehicle(const int& index)
    {
		if(index < max_vehicles)
			return vehicle_list->vehicles[index].vehicle;
		return nullptr;
    }

};*/

class CPickupHandle
{
public:
	CPickup* pCPickup; //0x0000 
	__int32 iHandle; //0x0008 
	char pad_0x000C[0x4]; //0x000C

}; //Size=0x0010

class CPickupList
{
public:
	CPickupHandle pickups[73]; //0x0000 

}; //Size=0x0490

class CPickup
{
public:
	char pad_0x0000[0x30]; //0x0000
	CNavigation* pCNavigation; //0x0030 
	char pad_0x0038[0x58]; //0x0038
	v3 v3VisualPos; //0x0090 
	char pad_0x009C[0x3F4]; //0x009C
	__int32 iValue; //0x0490 
	char pad_0x0494[0xC4]; //0x0494

}; //Size=0x0558

class CPedHandle
{
public:
	CPed* pCPed; //0x0000 
	__int32 iHandle;
    char _pad0[0x4];

}; //Size=0x0010

class CPedList
{
public:
	CPedHandle peds[256]; //0x0000 

}; //Size=0x1000

class CVehHandle
{
public:
	CVehicle* pCVehicle; //0x0000 
	__int32 iHandle;
    char _pad0[0x4];

}; //Size=0x0010

class CVehList
{
public:
	CVehHandle vehs[300]; //0x0000 

}; //Size=0x1000

class CObjectHandle
{
public:
	CObject* pCObject; //0x0000 
	__int32 iHandle; //0x0008 
	char pad_0x000C[0x4]; //0x000C

}; //Size=0x0010

class CObjectList
{
public:
	CObjectHandle ObjectList[2300]; //0x0000 

}; //Size=0x8FC0

class CObject
{
public:
	char pad_0x0000[0x8]; //0x0000

}; //Size=0x0008


class CCameraInterface
{
public:
	char pad_0x0000[0x248]; //0x0000

}; //Size=0x0248

class CObjectInterface
{
public:
	char pad_0x0000[0x158]; //0x0000
	CObjectList* pCObjectList; //0x0158 
	__int32 iMaxObjects; //0x0160 
	char pad_0x0164[0x4]; //0x0164
	__int32 iCurObjects; //0x0168 
	char pad_0x016C[0x5C]; //0x016C

}; //Size=0x01C8

class CVehicleInterface
{
public:
	char pad_0x0000[0x180]; //0x0000
	CVehList* VehList; //0x0180 
	__int32 iMaxVehicles; //0x0188 
	char pad_0x018C[0x4]; //0x018C
	__int32 iCurVehicles; //0x0190 
	char pad_0x0194[0x74]; //0x0194

	CVehicle* get_vehicle(const int& index)
    {
		if(index < iMaxVehicles)
			return VehList->vehs[index].pCVehicle;
		return nullptr;
    }
}; //Size=0x0208

class CPedInterface
{
public:
	char pad_0x0000[0x100]; //0x0000
	CPedList* PedLIst; //0x0100 
	__int32 iMaxPeds; //0x0108 
	char pad_0x010C[0x4]; //0x010C
	__int32 iCurPeds; //0x0110 
	char pad_0x0114[0x34]; //0x0114

	CPed* get_ped(const int& index)
    {
		if(index < iMaxPeds)
			return PedLIst->peds[index].pCPed;
		return nullptr;
    }
}; //Size=0x0148

class CPickupInterface
{
public:
	char pad_0x0000[0x100]; //0x0000
	CPickupList* pCPickupList; //0x0100 
	__int32 iMaxPickups; //0x0108 
	char pad_0x010C[0x4]; //0x010C
	__int32 iCurPickups; //0x0110 

	CPickup* get_pickup(const int& index)
	{
		if(index < iMaxPickups)
			return pCPickupList->pickups[index].pCPickup;
		return nullptr;
	}
}; //Size=0x0114

class CReplayInterface
{
public:
	void* N000006F5; //0x0000 
	CCameraInterface* pCCameraInterface; //0x0008 
	CVehicleInterface* pCVehicleInterface; //0x0010 
	CPedInterface* pCPedInterface; //0x0018 
	CPickupInterface* pCPickupInterface; //0x0020 
	CObjectInterface* pCObjectInterface; //0x0028 

}; //Size=0x0030






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




class CTextInfo
{
public:
	CColor	color;
	float	fTextScale1;
	float	fTextScale2;
	float	fTextWrapStart;
	float	fTextWrapEnd;
	int64_t	iFont;
	WORD	wNotCentered;
	BYTE	btDropShadow;
	BYTE	btTextOutline;

	void	setColor(CColor c)
	{
		c.swap_r_b();
		color	= c;
	}

	void	setScale(float f)
	{
		fTextScale1	= f;
		fTextScale2	= f;
	}
};



#pragma pack(pop)

#endif
