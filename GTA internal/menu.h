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

typedef std::map<std::string, DWORD>	keyMap;

/*
	//Feature classes
*/


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
		static keyMap			m_keyMap;
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

		static int			getActiveFeature();
		static int			getDisplayOffset();
		static bool			getCheckBox();

	protected:
		static std::vector<CFeatCat*>	m_pFeatureCat;
		static int						m_iActiveCat;		//index for featureParent [should be the same as id]
		static std::vector<CFeat*>		m_pFeature;
		static int						m_iActiveFeature;	//index for featureCur [DOES NOT HOLD ID!]
		static std::vector<CFeat*>		m_pFeatureCur;
		static bool						m_bMenuActive;
		static bool						m_bCheckBox;		//is there a checkbox feature in featureCur?
		static int						m_iFeatureCurDisplayOffset;

	private:
		CMenu() {};		//don't allow creating instance of the object
		~CMenu() {};
};

#endif