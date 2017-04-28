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
#ifndef MENU_H
#define MENU_H

/*
	//Defs
*/
#define MAX_SAVEDPOS					0x06		//max saved positions (to teleport to)
#define MAX_KEYS						0x10		//max indexed keys (keybinds)
#define MAX_MENU_FEATURES_DISPLAYED		0x0A		//max features displayed
#define MENU_FEATURE_SCROLL_PADDING		0x02

#define FFB_CATEGORY	1 << 0
#define FFB_PARENT		1 << 1

/*
	//Feature classes
*/

enum eFeatures : unsigned
{
	FEATURE_P_TRUEGOD,
	FEATURE_P_GOD,
	FEATURE_P_INVISIBLE,
	FEATURE_P_VISIBLE_LOCAL,
	FEATURE_P_OFFRADAR,
	FEATURE_P_CLEAN_PLAYER,
	FEATURE_P_WANTED,
	FEATURE_P_NEVERWANTED,
	FEATURE_P_ANTINPC,
	FEATURE_P_SUPER_RUN,
	FEATURE_P_RUNSPD,
	FEATURE_P_SWIMSPD,
	FEATURE_P_SUPERJUMP,
	FEATURE_P_EXPLOSIVEMELEE,
	FEATURE_P_SEATBELT,
	FEATURE_P_NORAGDOLL,
	FEATURE_P_STAMINA,
	FEATURE_P_MOBILE_RADIO,
	FEATURE_P_FREEZE_RADIO,
	FEATURE_P_CLEAR_REPORTS,
	FEATURE_P_MONEY_DROP,
	FEATURE_P_CLONE_BODYGUARD,
	FEATURE_P_CLEANUP_OBJECTS,
	FEATURE_P_ANTI_AFK,
	FEATURE_P_TINY,
	FEATURE_P_TEST,
	FEATURE_P_TEST2,
	FEATURE_V_TRUEGOD,
	FEATURE_V_GOD,
	FEATURE_V_REPAIR,
	FEATURE_V_UPGRADE,
	FEATURE_V_FLIP,
	FEATURE_V_STICK_TO_GROUND,
	FEATURE_V_BOOST,
	FEATURE_V_STOP,
	FEATURE_V_INVISIBLE,
	FEATURE_V_RAINBOW,
	FEATURE_V_COLOR_PRESET,
	FEATURE_V_COLOR_PRESET2,
	FEATURE_V_BULLETPROOFTIRES,
	FEATURE_V_DEFORMATION,
	FEATURE_V_ACCELERATION,
	FEATURE_V_UPSHIFT,
	FEATURE_V_BRAKEFORCE,
	FEATURE_V_TRACTION,
	FEATURE_V_GRAVITY,
	FEATURE_V_SUSPENSION_FORCE,
	FEATURE_V_VOLTIC_BOOST,
	FEATURE_V_INF_CAR_ALARM,
	FEATURE_V_LICENSE,
	FEATURE_M_RANDOMIZE_PED,
	FEATURE_C_SANTA,
	FEATURE_C_TRASH_ORANGE,
	FEATURE_C_TRASH_GREEN,
	FEATURE_C_POLICE,
	FEATURE_U_STOP_ANIM,
	FEATURE_TP_WAYPOINT,
	FEATURE_TP_OBJECTIVE,
	FEATURE_TP_NEARBY_CAR,
	FEATURE_W_SPREAD,
	FEATURE_W_RECOIL,
	FEATURE_W_RELOAD,
	FEATURE_W_DAMAGE,
	FEATURE_W_AMMO,
	FEATURE_W_RANGE,
	FEATURE_W_SPINUP,
	FEATURE_W_EXPLOSIVEAMMO,
	FEATURE_W_FIREAMMO,
	FEATURE_W_BULLET_BATCH,
	FEATURE_W_BATCH_SPREAD,
	FEATURE_W_MUZZLE_VELOCITY,
	FEATURE_T_PAUSE_CLOCK,
	FEATURE_T_SET_HOUR,
	FEATURE_T_SET_MIN,
	FEATURE_T_WEATHER,
	FEATURE_R_RP_LOOP,
	FEATURE_R_STEALTH_MONEY,
	FEATURE_R_STEALTH_MONEY_REMOVE,
	FEATURE_R_UNLOCK_STAT,
	FEATURE_R_UNLOCK_TATTOO,
	FEATURE_R_UNLOCK_PARACHUTE,
	FEATURE_R_UNLOCK_RIMS,
	FEATURE_R_UNLOCK_VEHICLE,
	FEATURE_R_UNLOCK_TROPHY,
	FEATURE_R_UNLOCK_HAIRSTYLE,
	FEATURE_R_UNLOCK_WEAPON,
	FEATURE_R_UNLOCK_CLOTHING,
	FEATURE_D_FRAUD,
	FEATURE_D_KICK,
	FEATURE_D_TELEPORT,
	FEATURE_U_NOCLIP,
	FEATURE_U_NOCLIP_SPEED,
	FEATURE_U_CHAOS_MODE,
	FEATURE_U_SMASH_VEHICLES,
	FEATURE_U_BLACK_HOLE,
	FEATURE_U_PED_DROP,
	FEATURE_U_CLEAN_SESSION,
	FEATURE_I_FPS_COUNTER,
	FEATURE_I_SPEED_O_METER,
	FEATURE_I_MENU_SCALE,
	FEATURE_I_MENU_PADDING_X,
	FEATURE_I_MENU_PADDING_Y,
	FEATURE_I_SAVE_INI,
	FEATURE_A_TRACK,
	FEATURE_A_TP_TO_ME,
	FEATURE_A_TP_TO_SEA,
	FEATURE_A_TP_TO_AIR,
	FEATURE_A_EXPLODE,
	FEATURE_A_GIVE_WEAPON,
	FEATURE_A_GIVE_WEAPONS,
	FEATURE_A_REMOVE_WEAPONS,
	FEATURE_A_TRAP_IN_CAGE,
	FEATURE_A_CLEAR_TASKS,
	FEATURE_A_FREEZE,
	FEATURE_A_ANIMATE,
	FEATURE_O_ESP_MAX_DIST,
	FEATURE_O_ESP_DIST,
	FEATURE_O_ESP_HEALTH,
	FEATURE_O_ESP_BOX,
	FEATURE_O_ATTACH_BONE,
	FEATURE_S_VEH_MOD,
	FEATURE_S_IN_VEHICLE,
	FEATURE_S_SP_BYPASS,
	FEATURE_S_MP_BYPASS,
	FEATURE_S_LICENSE,
	FEATURE_S_COLOR_1,
	FEATURE_S_COLOR_2,
	FEATURE_S_PED_RANDOMIZE,
	FEATURE_S_PED_TYPE,
	FEATURE_S_PED_CLEANUP,
	FEATURE_E_EDITOR_MODE,
	FEATURE_E_DELETE,
	FEATURE_E_DISTANCE,
	FEATURE_E_TEXT_TYPE,
	FEATURE_E_TEXT_POS,
	FEATURE_E_FREEZE,
	FEATURE_E_INVISIBLE,
	FEATURE_E_COLLISION,
	FEATURE_E_ROTATION_ENABLE,
	FEATURE_E_ROTATION_RELATIVE,
	FEATURE_E_ROTATION_X,
	FEATURE_E_ROTATION_Y,
	FEATURE_E_ROTATION_Z,
	FEATURE_E_THROW_MODE,
	FEATURE_END
};

enum ePlrFeats : unsigned
{
	PLRFEAT_PARENT,
	PLRFEAT_INFO,
	PLRFEAT_INFO_NAME,
	PLRFEAT_INFO_IP,
	PLRFEAT_INFO_PORT,
	PLRFEAT_INFO_COORDS,
	PLRFEAT_INFO_DISTANCE,
	PLRFEAT_INFO_HEALTH,
	PLRFEAT_INFO_IS_IN_VEH,
	PLRFEAT_INFO_IS_GOD,
	PLRFEAT_TRACK,
	PLRFEAT_SPECTATE,
	PLRFEAT_PED_DROP,
	PLRFEAT_TP_TO,
	PLRFEAT_TP_TO_CAR,
	PLRFEAT_TP_TO_ME,
	PLRFEAT_TP_TO_SEA,
	PLRFEAT_TP_TO_AIR,
	PLRFEAT_EXPLODE,
	PLRFEAT_GIVE_WEAPON,
	PLRFEAT_GIVE_WEAPONS,
	PLRFEAT_REMOVE_WEAPONS,
	PLRFEAT_CLONE_BODYGUARD,
	PLRFEAT_ATTACH_TO,
	PLRFEAT_ATTACH_PIGGY_BACK,
	PLRFEAT_ATTACH_69,
	PLRFEAT_ATTACH_VIOLATE,
	PLRFEAT_DETACH_ALL,
	PLRFEAT_ATTACH_CLONE,
	PLRFEAT_ATTACH_CLONE_69,
	PLRFEAT_ATTACH_OBJ_PARENT,
	PLRFEAT_TRAP_IN_CAGE,
	PLRFEAT_SHOOT,
	PLRFEAT_CHRISFORMAGE,
	PLRFEAT_CLEAR_TASKS,
	PLRFEAT_FREEZE,
	PLRFEAT_ANIMATE,
	PLRFEAT_DEAD_CLONES,
	PLRFEAT_GIVE_WANTED,
	PLRFEAT_END
};

#define IS_FEATURE_VALID(value) (value < FEATURE_END)
#define IS_PLRFEAT_VALID(value) (value < PLRFEAT_END)

typedef std::array<int, FEATURE_END>	featIndex;
typedef std::array<int, PLRFEAT_END>	plrFeatIndex;

enum eKeys
{
	KEY_EXIT,
	KEY_MENU,
	KEY_MENU_UP,
	KEY_MENU_DOWN,
	KEY_MENU_LEFT,
	KEY_MENU_RIGHT,
	KEY_MENU_SELECT,
	KEY_MENU_BACK,
	KEY_MENU_TAB_NEXT,
	KEY_MENU_TAB_PREV,
	KEY_MENU_SAVE,
	KEY_HOT_TELEPORT,
	KEY_HOT_NOCLIP,
	KEY_HOT_EDITOR,
	KEY_SUPERRUN,
	KEY_NOCLIP_FORWARD,
	KEY_NOCLIP_BACK,
	KEY_NOCLIP_LEFT,
	KEY_NOCLIP_RIGHT,
	KEY_NOCLIP_UP,
	KEY_NOCLIP_DOWN,
	KEY_EDITOR_ACTION,
	KEY_EDITOR_DELETE,
	KEYS_END
};

typedef std::array<DWORD, KEYS_END>	keyIndex;

enum featType
{
	feat_toggle				= (1 << 0),
	feat_slider				= (1 << 1)	| feat_toggle,
	feat_value				= (1 << 2)	| feat_toggle,
	feat_action				= (1 << 3),
	feat_teleport			= (1 << 4),
	feat_parent				= (1 << 5),
	feat_spawn				= (1 << 6),
	feat_action_value		= (1 << 7)	| 1 << 2,
	feat_action_value_str	= (1 << 8)	| feat_action_value,
	feat_attach				= (1 << 9)	| feat_action,
	feat_value_str			= (1 << 10)	| feat_value,
	feat_anim				= (1 << 11)
};

enum teleType	{ tp_saved, tp_static };
enum spwnType	{ spwn_vehicle, spwn_weapon, spwn_weapon_all, dspwn_weapon, dspwn_weapon_all, spwn_model, spwn_ped, spwn_object };

class CFeatCat
{
	public:
		int			m_iId,
					m_iActiveFeatureRet = 0,
					m_iDisplayOffsetRet = 0,
					m_iActiveParentRet	= -1;
		std::string	m_szName,
					m_szDisplay;
};

//CFeat is the default feature type, and also acts as an interface for the other types.
class CFeat
{
	public:
		int			m_iId,
					m_iCat,
					m_iParent;
		featType	m_type;
		std::string	m_szName;
		std::string	m_szIniKey;
		bool		m_bOn		= false,
					m_bRestored	= true,
					m_bSet		= true;
		clock_t		m_clockTick;

						CFeat();
		virtual			~CFeat();
		virtual	void	toggle();
		virtual void	toggle(bool state);
		virtual void	inc();
		virtual void	dec();
		virtual float	getValue();
		virtual void	setValue(float value);
		virtual float	getMin();
		virtual float	getMax();
		virtual void	pushChild(int i) {};
		virtual int		getChild(int i) { return -1; };
		virtual int		getChildCount() { return 0; };
		virtual void	disableChildren() {};
		virtual char**	getCharArray() { return nullptr; };
};

class CFeatAction : public CFeat
{
	public:
				CFeatAction();
				~CFeatAction();
		void	toggle();
};

class CFeatSlider : public CFeat
{
	public:
		float		m_fValue,
					m_fMin,
					m_fMax,
					m_fMod = .10f;

				CFeatSlider();
				~CFeatSlider();
		void	inc();
		void	dec();
		float	getValue();
		void	setValue(float value);
		float	getMin();
		float	getMax();
};

class CFeatValue : public CFeatSlider
{
	public:
				CFeatValue();
				~CFeatValue();
		void	inc();
		void	dec();
};

class CFeatValueStr : public CFeatValue
{
	public:
				CFeatValueStr();
				~CFeatValueStr();
		char**	getCharArray();
		char**	m_ppCh;
};

class CFeatActionValue : public CFeatValue
{
	public:
				CFeatActionValue();
				~CFeatActionValue();
		void	toggle();
};

class CFeatActionValueStr : public CFeatActionValue
{
	public:
				CFeatActionValueStr();
				~CFeatActionValueStr();
		char**	getCharArray();
		char**	m_ppCh;
};

class CFeatTeleport : public CFeat
{
	public:
		teleType	m_tpType;
		v3			m_v3Pos;

				CFeatTeleport();
				~CFeatTeleport();
		void	toggle();
};

class CFeatSpawn : public CFeat
{
	public:
		std::string	m_szHash;
		spwnType	m_spawnType;
				CFeatSpawn();
				~CFeatSpawn();
		void	toggle();
};

class CFeatAnim : public CFeat
{
	public:
		std::string	m_szHash[2];
		spwnType	m_spawnType;
				CFeatAnim();
				~CFeatAnim();
		void	toggle();
};

class CFeatAttach : public CFeat
{
	public:
		std::string	m_szHash;
		int		m_iPlayer;
				CFeatAttach();
				~CFeatAttach();
		void	toggle();
};

class CFeatParent : public CFeat
{
	public:
		int		m_iActiveFeatureRet = 0,
				m_iDisplayOffsetRet = 0;
		std::vector<int>	m_children;

				CFeatParent();
				~CFeatParent();
		void	toggle();
		void	pushChild(int i);
		int		getChild(int i);
		int		getChildCount();
		void	disableChildren();
};

/*
	//INI Parser Class
*/

typedef struct
{
    std::string    key,
                   value;
    int            section;
} iniProperty;

class CIniParser
{
	public:
		std::string	m_szFile;

					CIniParser();
					CIniParser(std::string szFile);
					~CIniParser();

		void		read();
		void		write();

		int			findKey(std::string szKey, std::string szSection = "");
		int			createKey(std::string szKey, std::string szSection = "");


		template	<typename rT>
		rT			getValue(std::string szKey, std::string szSection = "")
		{
			rT		r{};
			int		i	= this->findKey(szKey, szSection);
			if(i == -1 || (szSection != "" && (m_key[i].section < 0 || m_section[m_key[i].section] != szSection)))
				return r;
			std::stringstream	ss(m_key[i].value);
			ss	>> r;
			return r;
		}

		template	<>
		std::string	getValue(std::string szKey, std::string szSection)
		{
			std::string		r = "";
			int				i	= this->findKey(szKey, szSection);
			if(i == -1 || (szSection != "" && (m_key[i].section < 0 || m_section[m_key[i].section] != szSection)))
				return r;
			return m_key[i].value;
		}

		template	<typename wT>
		bool		setValue(std::string szKey, wT value, std::string szSection = "")
		{
			int i	= findKey(szKey, szSection);
			if(i == -1 || (szSection != "" && (m_key[i].section < 0 || m_section[m_key[i].section] != szSection)))
				i	= createKey(szKey, szSection);
			if(i == -1)
				return false;
			m_key[i].value = std::to_string(value);
			return true;
		}
	protected:
		std::vector<std::string>	m_section;
		std::vector<iniProperty>	m_key;
};

class CMenu
{
	public:
		static std::vector<int>	m_disableParent;
		static keyIndex			m_keyIndex;
		static CIniParser		m_iniParser;
		static bool				m_bFgWnd;

		static bool		initialze(std::string szIniDir, std::string szIniName);
		static void		uninitialze();

		static bool		checkKeyState(DWORD key, int flag = 0);
		static void		checkKeys();

		static void		toggleMenu();
		static bool		isMenuActive();
		static void		menuUp();		//prev feature
		static void		menuDown();		//next feature
		static void		menuLeft();		//float value down
		static void		menuRight();	//float value up
		static void		menuSelect();	//toggle feature/teleport or w/e
		static void		menuBack();
		static void		menuTabLeft();	//prev tab
		static void		menuTabRight();	//next tab
		static void		menuTabSave();	//save tab state
		static void		menuTabRestore();	//retore tab

		static int			addFeatureCategory(std::string name);
		static int			getFeatureCategoryCount();
		static CFeatCat*	getFeatureCategory(int id);
		static int			setActiveCat(int);
		static int			getActiveCat();
		static int			getActiveParent();
		static bool			fillFeatureCurBuffer(int i, BYTE flags);

		static int			addFeature(int cat, int parent, std::string name, featType type);
		static int			addFeature(int cat, int parent, std::string name, featType type, std::string iniKey);
		static int			addFeature(int cat, int parent, std::string name, featType type, std::string str1, std::string str2);
		static int			addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, spwnType spawnType);
		static int			addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, int playerId);
		static int			addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, float min, float max);
		static int			addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, float min, float max, float mod, char* enumArray[]);
		static int			addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, float min, float max, float mod);
		static int			addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, teleType tpType);
		static int			addFeature(int cat, int parent, std::string name, featType type, teleType tpType);
		static int			addFeature(int cat, int parent, std::string name, featType type, teleType tpType, float x, float y, float z);
		static int			getFeatureCurCount();
		static CFeat*		getFeatureCur(int i);
		static int			getFeatureCount();
		static CFeat*		getFeature(int id);
		static CFeat*		getFeature(eFeatures feat);
		static bool			indexFeature(eFeatures feat, int value);
		static CFeat*		getPlrFeature(ePlrFeats feat, int player);
		static bool			indexPlrFeature(ePlrFeats feat, int player, int value);

		static int			getActiveFeature();
		static int			getDisplayOffset();
		static bool			getCheckBox();

	protected:
		static std::vector<CFeatCat*>	m_pFeatureCat;
		static int						m_iActiveCat;		//index for featureParent [should be the same as id]
		static int						m_iActiveParent;
		static std::vector<CFeat*>		m_pFeature;
		static int						m_iActiveFeature;	//index for featureCur [DOES NOT HOLD ID!]
		static std::vector<CFeat*>		m_pFeatureCur;
		static bool						m_bMenuActive;
		static bool						m_bCheckBox;		//is there a checkbox feature in featureCur?
		static int						m_iFeatureCurDisplayOffset;
		static featIndex				m_featIndex;
		static plrFeatIndex				m_plrFeatIndex[MAX_PLAYERS];

	private:
		CMenu() {};		//don't allow creating instance of the object
		~CMenu() {};
};

#endif