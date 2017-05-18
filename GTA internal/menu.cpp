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
#include "ini_default.h"

/*
	//CMenu static public members
*/
std::vector<int>	CMenu::m_disableParent;
CIniParser			CMenu::m_iniParser;
bool				CMenu::m_bFgWnd	= true;
keyIndex			CMenu::m_keyIndex;

/*
	//CMenu static private members
*/
std::vector<CFeatCat*>	CMenu::m_pFeatureCat;
int						CMenu::m_iActiveCat					= 0;		//index for featureParent [should be the same as id]
int						CMenu::m_iActiveParent				= -1;
std::vector<CFeat*>		CMenu::m_pFeature;
int						CMenu::m_iActiveFeature				= 0;		//index for featureCur [DOES NOT HOLD ID!]
std::vector<CFeat*>		CMenu::m_pFeatureCur;
bool					CMenu::m_bMenuActive				= false;
bool					CMenu::m_bCheckBox					= false;	//is there a checkbox feature in featureCur?
int						CMenu::m_iFeatureCurDisplayOffset	= 0;
featIndex				CMenu::m_featIndex					= { };
plrFeatIndex			CMenu::m_plrFeatIndex[MAX_PLAYERS]	= { };

/*
	//CMenu functions
*/

void resetIni()
{
	std::ofstream file;
	file.open(CMenu::m_iniParser.m_szFile, std::ios::out | std::ios::trunc);
	file << INI_DEFAULT;
}

bool CMenu::initialze(std::string szIniDir, std::string szIniName)
{
	char*	appdata	= nullptr;
	size_t	size	= 0;
	if(_dupenv_s(&appdata, &size, "APPDATA") != 0 || appdata == nullptr)
		return false;
	m_iniParser.m_szFile		= appdata;
	free(appdata);

	m_iniParser.m_szFile.append("\\" + szIniDir);
	DWORD	attr	= GetFileAttributesA(&m_iniParser.m_szFile[0]);
	if((attr == INVALID_FILE_ATTRIBUTES || !(attr & FILE_ATTRIBUTE_DIRECTORY)) && !CreateDirectoryA(&m_iniParser.m_szFile[0], NULL))
		return false;

	m_iniParser.m_szFile.append("\\" + szIniName);

	attr	= GetFileAttributesA(&m_iniParser.m_szFile[0]);
	if(attr == INVALID_FILE_ATTRIBUTES && GetLastError() == ERROR_FILE_NOT_FOUND)
		resetIni();

	m_iniParser.read();

	struct keyInit
	{
		eKeys	index;
		char	iniKey[0x20];
	};

	constexpr keyInit	keys[]	= 
	{
		{ KEY_EXIT,				"Exit" },
		{ KEY_MENU,				"Menu" },
		{ KEY_MENU_UP,			"MenuUp" },
		{ KEY_MENU_DOWN,		"MenuDown" },
		{ KEY_MENU_LEFT,		"MenuLeft" },
		{ KEY_MENU_RIGHT,		"MenuRight" },
		{ KEY_MENU_SELECT,		"MenuSelect" },
		{ KEY_MENU_BACK,		"MenuBack" },
		{ KEY_MENU_TAB_NEXT,	"MenuTabNext" },
		{ KEY_MENU_TAB_PREV,	"MenuTabPrev" },
		{ KEY_MENU_SAVE,		"MenuSave" },
		{ KEY_HOT_TELEPORT,		"HotTeleport" },
		{ KEY_HOT_NOCLIP,		"HotNoclip" },
		{ KEY_HOT_EDITOR,		"HotEditor" },
		{ KEY_HOT_HEALTH,		"HotHealth" },
		{ KEY_SUPERRUN,			"SuperRun" },
		{ KEY_NOCLIP_FORWARD,	"NoClipForward" },
		{ KEY_NOCLIP_BACK,		"NoClipBack" },
		{ KEY_NOCLIP_LEFT,		"NoClipLeft" },
		{ KEY_NOCLIP_RIGHT,		"NoClipRight" },
		{ KEY_NOCLIP_UP,		"NoClipUp" },
		{ KEY_NOCLIP_DOWN,		"NoClipDown" },
		{ KEY_EDITOR_ACTION,	"EditorAction" },
		{ KEY_EDITOR_DELETE,	"EditorDelete" },
	};

	for(int i = 0; i < get_array_size(keys); ++i)
	{
		std::string	str;
		if(!m_iniParser.getValue<std::string>(keys[i].iniKey, "Keys", str))
		{
			resetIni();
			m_iniParser.read();
			i	= -1;
			continue;
		}
		m_keyIndex[keys[i].index]			= strToVk(str);
	}

	return true;
}
void CMenu::uninitialze()
{
	for(int i = 0; i < m_pFeature.size(); i++)
	{
		if(m_pFeature[i])
			delete m_pFeature[i];
	}

	for(int i = 0; i < m_pFeatureCat.size(); i++)
	{
		if(m_pFeatureCat[i])
			delete m_pFeatureCat[i];
	}
}


/*
	flag
	0x1		step
*/
bool CMenu::checkKeyState(DWORD key, int flag)
{
	if(!m_bFgWnd)
		return false;

	clock_t	c	= clock();
	static BYTE			btKeyState[0x100]		= { 0 };	//1 << 0 = keystate; 1 << 1 = held down
	static clock_t		clockKeyState[0x100]	= { c };

	bool	r		= false;
	BYTE	btState	= (GetKeyState(key) & 0x8000U) >> 0xF;
	short	wDelay	= btKeyState[key] & 2 ? 0x50 : 0x200;

	if(btState)
	{
		if(flag & 1)
		{
			if(!(btKeyState[key] & 1) || c - clockKeyState[key] > wDelay)
			{
				if((btKeyState[key] & 3) == 1)
					btKeyState[key]	|= 2;
				r		= true;
				clockKeyState[key]	= c;
			}
		}
		else
			r	= true;
	}
	else
		btKeyState[key]	&= ~(2);
	//btKeyState[key]		= (btKeyState[key] & ~(1)) | btState;
	btKeyState[key]		^= (-btState ^ btKeyState[key]) & 1;
	return r;
}

void CMenu::checkKeys()
{
	if(checkKeyState(m_keyIndex[KEY_MENU], 1))
		toggleMenu();
	
	struct hotKey
	{
		eKeys		key;
		eFeatures	feature;
	};

	constexpr hotKey	hotKeys[]	= 
	{
		{ KEY_HOT_TELEPORT,		FEATURE_TP_WAYPOINT },
		{ KEY_HOT_NOCLIP,		FEATURE_U_NOCLIP },
		{ KEY_HOT_EDITOR,		FEATURE_E_EDITOR_MODE },
		{ KEY_HOT_HEALTH,		FEATURE_P_GIVE_HEALTH },
		{ KEY_EDITOR_DELETE,	FEATURE_E_DELETE },
	};

	for(int i = 0; i < sizeof(hotKeys) / sizeof(*hotKeys); ++i)
	{
		if(checkKeyState(m_keyIndex[hotKeys[i].key], 1))
			getFeature(hotKeys[i].feature)->toggle();
	}

	//if menu is not active, no need to check other keys
	if(!isMenuActive())
	{
		//EDITOR (HOT) KEYS
		return;
	}

	struct menuKey
	{
		eKeys	key;
		void	(*fn)();
	};

	constexpr menuKey	menuKeys[]	= 
	{
		{ KEY_MENU_DOWN,		&menuDown },
		{ KEY_MENU_UP,			&menuUp }, 
		{ KEY_MENU_RIGHT,		&menuRight }, 
		{ KEY_MENU_LEFT,		&menuLeft }, 
		{ KEY_MENU_TAB_NEXT,	&menuTabRight }, 
		{ KEY_MENU_TAB_PREV,	&menuTabLeft }, 
		{ KEY_MENU_SELECT,		&menuSelect }, 
		{ KEY_MENU_BACK,		&menuBack }, 
	};

	for(int i = 0; i < sizeof(menuKeys) / sizeof(*menuKeys); ++i)
		if(checkKeyState(m_keyIndex[menuKeys[i].key], 1))
			menuKeys[i].fn();


	if(checkKeyState(m_keyIndex[KEY_MENU_SAVE], 1))
	{
		CFeatTeleport* tp	= dynamic_cast<CFeatTeleport*>(CMenu::getFeatureCur(CMenu::getActiveFeature()));
		if(tp == nullptr || tp->m_tpType != tp_saved)
			return;
		tp->m_v3Pos.x = CHack::m_pCPedPlayer->v3VisualPos.x;
		tp->m_v3Pos.y = CHack::m_pCPedPlayer->v3VisualPos.y;
		tp->m_v3Pos.z = CHack::m_pCPedPlayer->v3VisualPos.z + 1.f;
		m_iniParser.setValue<float>(tp->m_szIniKey + "_x", tp->m_v3Pos.x, "Teleport");
		m_iniParser.setValue<float>(tp->m_szIniKey + "_y", tp->m_v3Pos.y, "Teleport");
		m_iniParser.setValue<float>(tp->m_szIniKey + "_z", tp->m_v3Pos.z, "Teleport");
		return;
	}
}

void CMenu::toggleMenu()
{
	m_bMenuActive = !m_bMenuActive;
	return;
}

bool CMenu::isMenuActive()
{
	return m_bMenuActive;
}

void CMenu::menuDown()
{
	if(m_iActiveFeature + 1 < (int) m_pFeatureCur.size())
	{
		m_iActiveFeature++;
		if (m_iActiveFeature == m_iFeatureCurDisplayOffset + MAX_MENU_FEATURES_DISPLAYED - MENU_FEATURE_SCROLL_PADDING)
		{
			int displayOffset	= m_iActiveFeature - (MAX_MENU_FEATURES_DISPLAYED - 1 - MENU_FEATURE_SCROLL_PADDING);
			displayOffset	= (displayOffset > (int) m_pFeatureCur.size() - MAX_MENU_FEATURES_DISPLAYED) ? (int) m_pFeatureCur.size() - MAX_MENU_FEATURES_DISPLAYED : displayOffset;
			displayOffset	= (displayOffset < 0) ? 0 : displayOffset;
			m_iFeatureCurDisplayOffset = displayOffset;
		}
	}
	else
	{
		m_iActiveFeature = 0;
		m_iFeatureCurDisplayOffset = 0;
	}

	return;
}

void CMenu::menuUp()
{
	if(m_iActiveFeature - 1 >= 0)
	{
		m_iActiveFeature--;
		if (m_iActiveFeature == m_iFeatureCurDisplayOffset + MENU_FEATURE_SCROLL_PADDING - 1)
		{
			int displayOffset	= m_iActiveFeature - MENU_FEATURE_SCROLL_PADDING;
				displayOffset	= (displayOffset > (int) m_pFeatureCur.size() - MAX_MENU_FEATURES_DISPLAYED) ? (int) m_pFeatureCur.size() - MAX_MENU_FEATURES_DISPLAYED : displayOffset;
				displayOffset	= (displayOffset < 0) ? 0 : displayOffset;
			m_iFeatureCurDisplayOffset = displayOffset;
		}
	}
	else
	{
		m_iActiveFeature = (int) m_pFeatureCur.size() - 1;
		int displayOffset	= (int) m_pFeatureCur.size() - MAX_MENU_FEATURES_DISPLAYED;
			displayOffset	= (displayOffset < 0) ? 0 : displayOffset;
		m_iFeatureCurDisplayOffset = displayOffset;
	}

	return;
}

void CMenu::menuRight()
{
	return getFeatureCur(m_iActiveFeature)->inc();
}

void CMenu::menuLeft()
{
	return getFeatureCur(m_iActiveFeature)->dec();
}

void CMenu::menuTabSave()
{
	m_pFeatureCat[m_iActiveCat]->m_iActiveParentRet		= m_pFeatureCur[0]->m_iParent;
	m_pFeatureCat[m_iActiveCat]->m_iDisplayOffsetRet	= m_iFeatureCurDisplayOffset;
	m_pFeatureCat[m_iActiveCat]->m_iActiveFeatureRet	= m_iActiveFeature;
	m_pFeatureCat[m_iActiveCat]->m_szDisplay			= m_pFeatureCat[m_iActiveCat]->m_szName;
}

void CMenu::menuTabRestore()
{
	if(m_pFeatureCat[m_iActiveCat]->m_iActiveParentRet > -1)
		fillFeatureCurBuffer(m_pFeatureCat[m_iActiveCat]->m_iActiveParentRet, FFB_PARENT);
	m_iFeatureCurDisplayOffset	= m_pFeatureCat[m_iActiveCat]->m_iDisplayOffsetRet;
	m_iActiveFeature			= m_pFeatureCat[m_iActiveCat]->m_iActiveFeatureRet;
}

void CMenu::menuTabRight()
{
	menuTabSave();
	if(m_iActiveCat < m_pFeatureCat.size() - 1)
		setActiveCat(m_iActiveCat + 1);
	else
		setActiveCat(0);
	menuTabRestore();
	return;
}

void CMenu::menuTabLeft()
{
	menuTabSave();
	if(m_iActiveCat - 1 >= 0)
		setActiveCat(m_iActiveCat - 1);
	else
		setActiveCat((int) m_pFeatureCat.size() - 1);
	menuTabRestore();
	return;
}

void CMenu::menuSelect()
{
	CFeat* feat	= getFeatureCur(m_iActiveFeature);
	feat->toggle();
	return;
}

void CMenu::menuBack()
{
	if(m_pFeatureCur[0]->m_iParent >= 0)	//if the buffer is filled with features that have a parent, not a category
	{
		CFeatParent* parent = dynamic_cast<CFeatParent*>(m_pFeature[m_pFeatureCur[0]->m_iParent]);
		if(parent->m_iCat < 0)
			fillFeatureCurBuffer(parent->m_iParent, FFB_PARENT);
		else
			fillFeatureCurBuffer(parent->m_iCat, FFB_CATEGORY);

		m_iFeatureCurDisplayOffset	= parent->m_iDisplayOffsetRet;
		m_iActiveFeature			= parent->m_iActiveFeatureRet;
	}
	return;
}



int	CMenu::addFeatureCategory(std::string name)
{
	int id;
	m_pFeatureCat.push_back(new CFeatCat);
	id	= (int) m_pFeatureCat.size() - 1;
	m_pFeatureCat[id]->m_iId		= id;
	m_pFeatureCat[id]->m_szName		= name;
	m_pFeatureCat[id]->m_szDisplay	= name;
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type)
{
	if(	(parent < 0 && cat < m_pFeatureCat.size() - 1 && m_pFeatureCat[cat] == nullptr) ||				//invalid cat
		(cat < 0 && parent < m_pFeature.size() - 1 && (m_pFeature[parent] == nullptr || m_pFeature[parent]->m_type != feat_parent)) ||	//invalid parent
		(cat < 0 && parent < 0) || (cat > 0 && parent > 0))												//both cat and parent were provided
		return -1;
	switch(type)
	{
		case feat_toggle:
			m_pFeature.push_back(new CFeat);
		break;
		case feat_action:
			m_pFeature.push_back(new CFeatAction);
		break;
		case feat_action_value:
			m_pFeature.push_back(new CFeatActionValue);
		break;
		case feat_action_value_str:
			m_pFeature.push_back(new CFeatActionValueStr);
		break;
		case feat_slider:
			m_pFeature.push_back(new CFeatSlider);
		break;
		case feat_value:
			m_pFeature.push_back(new CFeatValue);
		break;
		case feat_value_str:
			m_pFeature.push_back(new CFeatValueStr);
		break;
		case feat_teleport:
			m_pFeature.push_back(new CFeatTeleport);
		break;
		case feat_parent:
			m_pFeature.push_back(new CFeatParent);
			m_pFeature[m_pFeature.size() - 1]->m_bOn = true;
		break;
		case feat_spawn:
			m_pFeature.push_back(new CFeatSpawn);
		break;
		case feat_anim:
			m_pFeature.push_back(new CFeatAnim);
		break;
		case feat_menu_option:
			m_pFeature.push_back(new CFeatActionValueMenu);
		break;
	}
	int id	= (int) m_pFeature.size() - 1;
	m_pFeature[id]->m_iId		= id;
	m_pFeature[id]->m_iCat		= cat;
	m_pFeature[id]->m_iParent	= parent;
	m_pFeature[id]->m_type		= type;
	m_pFeature[id]->m_szName	= name;
	m_pFeature[id]->m_clockTick	= clock();
	if(parent >= 0)
		m_pFeature[parent]->pushChild(id);
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, std::string iniKey)
{
	int id = addFeature(cat, parent, name, type);
	if(id < 0)
		return id;
	if(m_pFeature[id]->m_type == feat_anim)
		static_cast<CFeatAnim*>(m_pFeature[id])->m_szHash[0] = iniKey;
	else
		m_pFeature[id]->m_szIniKey	= iniKey;
	m_iniParser.getValue<bool>(std::string("tog_") + m_pFeature[id]->m_szIniKey, "FeatureToggle", m_pFeature[id]->m_bOn);
	m_pFeature[id]->m_bRestored	= (m_pFeature[id]->m_bOn) ? false : true;
	m_pFeature[id]->m_bSet		= (m_pFeature[id]->m_bOn) ? false : true;
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, std::string str2)
{
	int id = addFeature(cat, parent, name, type, iniKey);
	if(id < 0)
		return id;
	if(m_pFeature[id]->m_type == feat_anim)
		static_cast<CFeatAnim*>(m_pFeature[id])->m_szHash[1]	= str2;
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, DWORD hash, spwnType spawnType)
{
	int id = addFeature(cat, parent, name, type);
	if(id < 0)
		return id;
	static_cast<CFeatSpawn*>(m_pFeature[id])->m_spawnType	= spawnType;
	static_cast<CFeatSpawn*>(m_pFeature[id])->m_dwHash		= hash;
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, float min, float max)
{
	int id = addFeature(cat, parent, name, type, iniKey);
	if(id < 0)
		return id;
	static_cast<CFeatSlider*>(m_pFeature[id])->m_fMin		= min;
	static_cast<CFeatSlider*>(m_pFeature[id])->m_fMax		= max;
	float v;
	m_iniParser.getValue<float>(std::string("val_") + iniKey, "FeatureValue", v);
	if(v <= max && v >= min)
		static_cast<CFeatSlider*>(m_pFeature[id])->m_fValue	= v;
	else
	{
		static_cast<CFeatSlider*>(m_pFeature[id])->m_fValue	= min;
		m_iniParser.setValue<float>(std::string("val_") + iniKey, min, "FeatureValue");
	}
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, float min, float max, float mod, const char* const enumArray[])
{
	int id = addFeature(cat, parent, name, type, iniKey, min, max, mod);
	if(id < 0)
		return id;

	if(type == feat_action_value_str)
		dynamic_cast<CFeatActionValueStr*>(m_pFeature[id])->m_ppCh = enumArray;
	else if(type == feat_value_str)
		dynamic_cast<CFeatValueStr*>(m_pFeature[id])->m_ppCh = enumArray;
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, float min, float max, float mod)
{
	int id = addFeature(cat, parent, name, type, iniKey, min, max);
	if(id < 0)
		return id;
	static_cast<CFeatSlider*>(m_pFeature[id])->m_fMod		= mod;
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, menuType menuOptionType, std::string iniKey, float min, float max, float mod, void* pointer)
{
	int id = addFeature(cat, parent, name, type, iniKey, min, max, mod);
	if(id < 0)
		return id;
	CFeatActionValueMenu*	feat	= static_cast<CFeatActionValueMenu*>(m_pFeature[id]);
	feat->m_menuOptionType	= menuOptionType;
	feat->m_pointer			= pointer;
	feat->toggle();
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, teleType tpType)
{
	if(tpType != tp_saved)
		return -1;
	int id = addFeature(cat, parent, name, type, iniKey);
	if(id < 0)
		return id;
	CFeatTeleport* feat = static_cast<CFeatTeleport*>(m_pFeature[id]);
	feat->m_tpType		= tpType;
	m_iniParser.getValue<float>(iniKey + "_x", "Teleport", feat->m_v3Pos.x);
	m_iniParser.getValue<float>(iniKey + "_y", "Teleport", feat->m_v3Pos.y);
	m_iniParser.getValue<float>(iniKey + "_z", "Teleport", feat->m_v3Pos.z);
	std::string str;
	m_iniParser.getValue<std::string>(iniKey + "_name", "Teleport", str);
	feat->m_szName		+= " | " + str;
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, teleType tpType)
{
	if(tpType == tp_saved)
		return -1;
	int id = addFeature(cat, parent, name, type);
	if(id < 0)
		return id;
	static_cast<CFeatTeleport*>(m_pFeature[id])->m_tpType	= tpType;
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, teleType tpType, float x, float y, float z)
{
	if(tpType == tp_saved)
		return -1;
	int id = addFeature(cat, parent, name, type, tpType);
	if(id < 0)
		return id;
	static_cast<CFeatTeleport*>(m_pFeature[id])->m_v3Pos.x	= x;
	static_cast<CFeatTeleport*>(m_pFeature[id])->m_v3Pos.y	= y;
	static_cast<CFeatTeleport*>(m_pFeature[id])->m_v3Pos.z	= z;
	return id;
}

int		CMenu::getFeatureCategoryCount()
{
	return (int) m_pFeatureCat.size();
}

CFeatCat*	CMenu::getFeatureCategory(int id)
{
	if(id > m_pFeatureCat.size() - 1)
		return 0;
	return m_pFeatureCat[id];
}

int			CMenu::getActiveCat()
{
	return m_iActiveCat;
}

int			CMenu::getActiveParent()
{
	return m_iActiveParent;
}

int			CMenu::setActiveCat(int cat)
{
	if(cat > m_pFeatureCat.size() - 1)
		return 0;

	m_iActiveCat		= cat;
	fillFeatureCurBuffer(cat, FFB_CATEGORY);

	return 1;
}

bool		CMenu::fillFeatureCurBuffer(int id, BYTE flag)
{
	if(m_pFeatureCur.size() > 0)
		m_pFeatureCur.clear();
	m_iActiveFeature			= 0;
	m_iFeatureCurDisplayOffset	= 0;
	m_bCheckBox					= false;

	if(flag & FFB_CATEGORY)
		m_iActiveCat	= id;

	if(flag & FFB_PARENT)
		m_iActiveParent	= id;
	else
		m_iActiveParent	= -1;

	for(int i = 0; i < m_pFeature.size(); i++)		//create a list of features from current category
	{
		if(	(m_pFeature[i]->m_iCat		== id && flag & FFB_CATEGORY) ||
			(m_pFeature[i]->m_iParent	== id && flag & FFB_PARENT))
		{
			m_pFeatureCur.push_back(m_pFeature[i]);
			if(m_pFeature[i]->m_type & feat_toggle)
				m_bCheckBox	= true;
		}
	}

	if(flag & FFB_CATEGORY)
		m_pFeatureCat[m_iActiveCat]->m_szDisplay	= m_pFeatureCat[m_iActiveCat]->m_szName;
	else if(flag & FFB_PARENT)
		m_pFeatureCat[m_iActiveCat]->m_szDisplay	= m_pFeature[m_pFeatureCur[0]->m_iParent]->m_szName;
	return 1;
}

int		CMenu::getFeatureCurCount()
{
	return (int) m_pFeatureCur.size();
}

CFeat*	CMenu::getFeatureCur(int i)
{
	if(i > m_pFeatureCur.size() -1)
		return 0;
	return m_pFeatureCur[i];
}

int		CMenu::getFeatureCount()
{
	return (int) m_pFeature.size();
}

CFeat*	CMenu::getFeature(int id)
{
	if(id < m_pFeature.size())
		return m_pFeature[id];
	return nullptr;
}

CFeat*	CMenu::getFeature(eFeatures feat)
{
	CFeat* r	= nullptr;
	if(IS_FEATURE_VALID(feat))
		r = getFeature(m_featIndex[feat]);
	return r;
}

bool	CMenu::indexFeature(eFeatures feat, int value)
{
	if(IS_FEATURE_VALID(feat))
	{
		m_featIndex[feat]	= value;
		return true;
	}
	return false;
}

CFeat*	CMenu::getPlrFeature(ePlrFeats feat, int player)
{
	CFeat* r	= nullptr;
	if(IS_PLRFEAT_VALID(feat) && player < MAX_PLAYERS)
		r = getFeature(m_plrFeatIndex[player][feat]);
	return r;
}

bool	CMenu::indexPlrFeature(ePlrFeats feat, int player, int value)
{
	if(IS_PLRFEAT_VALID(feat) && player < MAX_PLAYERS)
	{
		m_plrFeatIndex[player][feat]	= value;
		return true;
	}
	return false;
}

int		CMenu::getActiveFeature()
{
	return m_iActiveFeature;
}

int		CMenu::getDisplayOffset()
{
	return m_iFeatureCurDisplayOffset;
}

bool	CMenu::getCheckBox()
{
	return m_bCheckBox;
}


/*
	//FEATURE CLASSES
*/

CFeat::CFeat() {}

CFeat::~CFeat() {}

void	CFeat::toggle()
{
	m_bOn = !m_bOn;
	if(m_bOn)
		m_bRestored = false;
	m_bSet = false;
	if(m_szIniKey != "")
		CMenu::m_iniParser.setValue<bool>(std::string("tog_") + m_szIniKey, (int) m_bOn, "FeatureToggle");
	return;
}

void	CFeat::toggle(bool state)
{
	m_bOn = state;
	if(m_bOn)
		m_bRestored = false;
	m_bSet = false;
	if(m_szIniKey != "")
		CMenu::m_iniParser.setValue<bool>(std::string("tog_") + m_szIniKey, (int) m_bOn, "FeatureToggle");
	return;
}

void	CFeat::inc() {}
void	CFeat::dec() {}
float	CFeat::getValue() { return 0.f; }
void	CFeat::setValue(float value) { return; }
float	CFeat::getMin() { return 0.f; }
float	CFeat::getMax() { return 0.f; }

CFeatAction::CFeatAction(){}
CFeatAction::~CFeatAction() {}

void	CFeatAction::toggle()
{
	m_bOn = true;
	m_bSet	= false;
}



CFeatSlider::CFeatSlider() {}
CFeatSlider::~CFeatSlider() {}

void	CFeatSlider::setValue(float value)
{
	if(value <= m_fMax && value >= m_fMin)
		m_fValue = value;
	return;
}

void	CFeatSlider::inc()
{
	float v		= (m_fValue + ( (m_fMax - m_fMin) * m_fMod) );
	if(v <= m_fMax)
		m_fValue = v;
	else
		m_fValue = m_fMax;
	CMenu::m_iniParser.setValue<float>(std::string("val_") + m_szIniKey, m_fValue, "FeatureValue");
	return;
}

void	CFeatSlider::dec()
{
	float v		= (m_fValue - ( (m_fMax - m_fMin) * m_fMod) );
	if(v >= m_fMin)
		m_fValue = v;
	else
		m_fValue = m_fMin;
	CMenu::m_iniParser.setValue<float>(std::string("val_") + m_szIniKey, m_fValue, "FeatureValue");
	return;
}

CFeatValue::CFeatValue() {}
CFeatValue::~CFeatValue() {}

void	CFeatValue::inc()
{
	float v		= m_fValue + m_fMod;
	if(v <= m_fMax)
		m_fValue = v;
	else
		m_fValue = m_fMin;
	CMenu::m_iniParser.setValue<float>(std::string("val_") + m_szIniKey, m_fValue, "FeatureValue");
	return;
}

void	CFeatValue::dec()
{
	float v		= m_fValue - m_fMod;
	if(v >= m_fMin)
		m_fValue = v;
	else
		m_fValue = m_fMax;
	CMenu::m_iniParser.setValue<float>(std::string("val_") + m_szIniKey, m_fValue, "FeatureValue");
	return;
}

CFeatValueStr::CFeatValueStr() {}
CFeatValueStr::~CFeatValueStr() {}

const char* const *	CFeatValueStr::getCharArray()
{
	return m_ppCh;
};

CFeatActionValue::CFeatActionValue() {}
CFeatActionValue::~CFeatActionValue() {}

void	CFeatActionValue::toggle()
{
	m_bOn = true;
	m_bSet	= false;
}

CFeatActionValueMenu::CFeatActionValueMenu() {}
CFeatActionValueMenu::~CFeatActionValueMenu() {}

void	CFeatActionValueMenu::toggle()
{
	switch(m_menuOptionType)
	{
		case menu_color:
		{
			BYTE*	ptr	= (BYTE*)	m_pointer;
			*ptr		= (BYTE) m_fValue;
		}
		break;
		case menu_padding:
		{
			int*	ptr	= (int*)	m_pointer;
			*ptr		= (int) m_fValue;
		}
		break;
	}
}

void	CFeatActionValueMenu::inc()
{
	CFeatActionValue::inc();
	toggle();
}

void	CFeatActionValueMenu::dec()
{
	CFeatActionValue::dec();
	toggle();
}

CFeatActionValueStr::CFeatActionValueStr() {}
CFeatActionValueStr::~CFeatActionValueStr() {}

const char* const *	CFeatActionValueStr::getCharArray()
{
	return m_ppCh;
};

float	CFeatSlider::getValue() { return m_fValue; }
float	CFeatSlider::getMin() { return m_fMin; }
float	CFeatSlider::getMax() { return m_fMax; }

CFeatTeleport::CFeatTeleport() {}
CFeatTeleport::~CFeatTeleport() {}

void	CFeatTeleport::toggle()
{
	CHack::m_v3Teleport = m_v3Pos;
}

CFeatSpawn::CFeatSpawn() {}
CFeatSpawn::~CFeatSpawn() {}

void	CFeatSpawn::toggle()
{
	switch(m_spawnType)
	{
		case spwn_vehicle:
			CHack::m_requestedVehicle.push(m_dwHash);
		break;
		case spwn_weapon:
			CHack::m_requestedWeapon.push(m_dwHash);
			CHack::m_bWeaponGive	= true;
		break;
		case spwn_weapon_all:
			CHack::m_requestedWeapon.push(0);
			CHack::m_bWeaponGive	= true;
		break;
		case dspwn_weapon:
			CHack::m_requestedWeapon.push(m_dwHash);
			CHack::m_bWeaponGive	= false;
		break;
		case dspwn_weapon_all:
			CHack::m_requestedWeapon.push(0);
			CHack::m_bWeaponGive	= false;
		break;
		case spwn_model:
			CHack::m_dwRequestedModel	= m_dwHash;
			CHack::m_bModelSet			= false;
		break;
		case spwn_ped:
			CHack::m_requestedPed.push(m_dwHash);
		break;
		case spwn_object:
			CHack::m_requestedObject.push(m_dwHash);
			CMenu::getFeature(FEATURE_E_EDITOR_MODE)->toggle(true);
		break;
	}
}

CFeatAnim::CFeatAnim() {}
CFeatAnim::~CFeatAnim() {}

void	CFeatAnim::toggle()
{
	CHack::m_szRequestedAnim		= m_szHash[0];
	CHack::m_szRequestedAnimDict	= m_szHash[1];
}

CFeatParent::CFeatParent() {}
CFeatParent::~CFeatParent() {}

void	CFeatParent::toggle()
{
	if(!m_bOn)
		return;
	m_iActiveFeatureRet = CMenu::getActiveFeature();
	m_iDisplayOffsetRet	= CMenu::getDisplayOffset();
	CMenu::fillFeatureCurBuffer(m_iId, FFB_PARENT);

	return;
}

void	CFeatParent::pushChild(int i)
{
	m_children.push_back(i);
	return;
}

int	CFeatParent::getChild(int i)
{
	return m_children[i];
}

int	CFeatParent::getChildCount()
{
	return (int) m_children.size();
}

void	CFeatParent::disableChildren()
{
	int n = CMenu::getFeatureCount();
	int a = CMenu::getFeatureCur(CMenu::getActiveFeature())->m_iParent;
	if(m_iId == a)
			CMenu::menuBack();
	for(int i = 0; i < m_children.size(); i++)
	{
		CFeat* feat = CMenu::getFeature(m_children[i]);
		if(feat->m_type == feat_parent)
		{
			feat->disableChildren();
			continue;
		}
		feat->m_bOn		= false;
		feat->m_bSet	= true;
	}
}



/*
	//INI PARSER CLASS
*/

CIniParser::CIniParser(){};

CIniParser::CIniParser(std::string szFile)	:
m_szFile(szFile)
{};

CIniParser::~CIniParser(){};

void CIniParser::read()
{
	std::ifstream file;
	file.open(m_szFile, std::ios::in);
	if(!file.is_open())
		return;

	m_section.clear();
	m_propertyMap.clear();

	std::string szLine;
	int			iSection = -1;
	std::regex	regexSection("^\\[([A-Za-z0-9_]+)\\]$"),
				regexKey	("^([A-Za-z0-9_]+)=([A-Za-z0-9_\\-*/+.\\s]+)$");

	while(std::getline(file, szLine, '\n'))
	{
		std::smatch    regexMatch;    //std::string match object

		if(szLine == "")
			continue;
             
		else if(std::regex_search(szLine, regexMatch, regexSection) && regexMatch.size() > 1)
		{
			iSection    = (int) m_section.size();
			m_section.push_back(regexMatch[1]);
		}
            
		else if(std::regex_search(szLine, regexMatch, regexKey) && regexMatch.size() > 1)
		{
			iniProperty	tmp	= { regexMatch[2], iSection };
			m_propertyMap.emplace(regexMatch[1], tmp);
		}
	}
	return;
}

void CIniParser::write()
{
	std::ofstream file;
	file.open(m_szFile, std::ios::out | std::ios::trunc);
	if(!file.is_open())
		return;
	for(int j = -1; j < (int) m_section.size(); ++j)
	{
		if(j >= 0)
			file << "[" << m_section[j] << "]\n";
		for(iniMap::iterator it = m_propertyMap.begin(); it != m_propertyMap.end(); ++it)
		{
			if(it->second.section != j)
				continue;
			file << it->first << "=" << it->second.value << "\n";
		}
	}
	return;
}

bool CIniParser::createKey(std::string szKey, std::string szSection)
{
	if(szKey == "")
		return false;
	int iSection = -1;
	if(szSection != "")
	{
		for(int i = 0; i < m_section.size(); i++)
			if(m_section[i] == szSection)
			{
				iSection = i;
				break;
			}
		if(iSection == -1)
		{
			m_section.push_back(szSection);
			iSection = (int) m_section.size() - 1;
		}
	}
	iniProperty	tmp	= { "", iSection };
	m_propertyMap.emplace(szKey, tmp);
	return true;
}