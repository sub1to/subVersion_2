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
keyMap				CMenu::m_keyMap;
bool				CMenu::m_bKeyState[0x100]	= { false };
clock_t				CMenu::m_clockKeyState[0x100];

/*
	//CMenu static private members
*/
std::vector<CFeatCat*>	CMenu::m_pFeatureCat;
int						CMenu::m_iActiveCat					= 0;		//index for featureParent [should be the same as id]
std::vector<CFeat*>		CMenu::m_pFeature;
int						CMenu::m_iActiveFeature				= 0;		//index for featureCur [DOES NOT HOLD ID!]
std::vector<CFeat*>		CMenu::m_pFeatureCur;
bool					CMenu::m_bMenuActive				= false;
bool					CMenu::m_bCheckBox					= false;	//is there a checkbox feature in featureCur?
int						CMenu::m_iFeatureCurDisplayOffset	= 0;


/*
	//CMenu functions
*/

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
	{
		std::ofstream file;
		file.open(m_iniParser.m_szFile, std::ios::out | std::ios::trunc);
		file << INI_DEFAULT;
	}

	m_iniParser.read();

	//keys
	m_keyMap.emplace("Exit", strToVk(m_iniParser.getValue<std::string>("Exit", "Keys")));
	m_keyMap.emplace("Menu", strToVk(m_iniParser.getValue<std::string>("Menu", "Keys")));
	m_keyMap.emplace("MenuUp", strToVk(m_iniParser.getValue<std::string>("MenuUp", "Keys")));
	m_keyMap.emplace("MenuDown", strToVk(m_iniParser.getValue<std::string>("MenuDown", "Keys")));
	m_keyMap.emplace("MenuLeft", strToVk(m_iniParser.getValue<std::string>("MenuLeft", "Keys")));
	m_keyMap.emplace("MenuRight", strToVk(m_iniParser.getValue<std::string>("MenuRight", "Keys")));
	m_keyMap.emplace("MenuSelect", strToVk(m_iniParser.getValue<std::string>("MenuSelect", "Keys")));
	m_keyMap.emplace("MenuBack", strToVk(m_iniParser.getValue<std::string>("MenuBack", "Keys")));
	m_keyMap.emplace("MenuTabNext", strToVk(m_iniParser.getValue<std::string>("MenuTabNext", "Keys")));
	m_keyMap.emplace("MenuTabPrev", strToVk(m_iniParser.getValue<std::string>("MenuTabPrev", "Keys")));
	m_keyMap.emplace("MenuSave", strToVk(m_iniParser.getValue<std::string>("MenuSave", "Keys")));
	m_keyMap.emplace("HotTeleport", strToVk(m_iniParser.getValue<std::string>("HotTeleport", "Keys")));
	m_keyMap.emplace("HotNoclip", strToVk(m_iniParser.getValue<std::string>("HotNoclip", "Keys")));
	m_keyMap.emplace("HotEditor", strToVk(m_iniParser.getValue<std::string>("HotEditor", "Keys")));
	m_keyMap.emplace("SuperRun", strToVk(m_iniParser.getValue<std::string>("SuperRun", "Keys")));
	m_keyMap.emplace("NoClipForward", strToVk(m_iniParser.getValue<std::string>("NoClipForward", "Keys")));
	m_keyMap.emplace("NoClipBack", strToVk(m_iniParser.getValue<std::string>("NoClipBack", "Keys")));
	m_keyMap.emplace("NoClipLeft", strToVk(m_iniParser.getValue<std::string>("NoClipLeft", "Keys")));
	m_keyMap.emplace("NoClipRight", strToVk(m_iniParser.getValue<std::string>("NoClipRight", "Keys")));
	m_keyMap.emplace("NoClipUp", strToVk(m_iniParser.getValue<std::string>("NoClipUp", "Keys")));
	m_keyMap.emplace("NoClipDown", strToVk(m_iniParser.getValue<std::string>("NoClipDown", "Keys")));
	m_keyMap.emplace("EditorAction", strToVk(m_iniParser.getValue<std::string>("EditorAction", "Keys")));
	m_keyMap.emplace("EditorDelete", strToVk(m_iniParser.getValue<std::string>("EditorDelete", "Keys")));

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
	0x1		realtime	(bit 0x0 and 0xF)
*/
bool CMenu::checkKeyState(DWORD key, int flag)
{
	if(!m_bFgWnd)
		return false;
	clock_t	c	= clock();
	bool	r	= false;
	bool	b	= (GetKeyState(key) & 0x8000) == 0x8000;
	if((b && flag == 0) || (b && flag & 1 && (!m_bKeyState[key] || c - m_clockKeyState[key] > 0xFF)))
	{
		r		= true;
		m_clockKeyState[key]	= c;
	}
	m_bKeyState[key]	= b;
	return r;
}

void CMenu::checkKeys()
{
	if(checkKeyState(m_keyMap["Menu"], 1))
	{
		toggleMenu();
		return;
	}
	
	//hotkeys
	if(checkKeyState(m_keyMap["HotTeleport"], 1))
	{
		getFeature(feature::map["FEATURE_TP_WAYPOINT"])->toggle();
		return;
	}
	if(checkKeyState(m_keyMap["HotNoclip"], 1))
	{
		getFeature(feature::map["FEATURE_U_NOCLIP"])->toggle();
		return;
	}
	if(checkKeyState(m_keyMap["HotEditor"], 1))
	{
		getFeature(feature::map["FEATURE_E_EDITOR_MODE"])->toggle();
		return;
	}
	if(checkKeyState(m_keyMap["EditorDelete"], 1))
	{
		getFeature(feature::map["FEATURE_E_DELETE"])->toggle();
		return;
	}

	//if menu is not active, no need to check other keys
	if(!isMenuActive())
	{
		//EDITOR (HOT) KEYS
		return;
	}

	//menu navigation
	if(checkKeyState(m_keyMap["MenuDown"], 1))
	{
		menuDown();
		return;
	}
	if(checkKeyState(m_keyMap["MenuUp"], 1))
	{
		menuUp();
		return;
	}
	if(checkKeyState(m_keyMap["MenuRight"], 1))
	{
		menuRight();
		return;
	}
	if(checkKeyState(m_keyMap["MenuLeft"], 1))
	{
		menuLeft();
		return;
	}
	if(checkKeyState(m_keyMap["MenuTabNext"], 1))
	{
		menuTabRight();
		return;
	}
	if(checkKeyState(m_keyMap["MenuTabPrev"], 1))
	{
		menuTabLeft();
		return;
	}
	if(checkKeyState(m_keyMap["MenuSave"], 1))
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
	if(checkKeyState(m_keyMap["MenuSelect"], 1))
	{
		CMenu::menuSelect();
		return;
	}
	if(checkKeyState(m_keyMap["MenuBack"], 1))
	{
		CMenu::menuBack();
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
		case feat_attach:
			m_pFeature.push_back(new CFeatAttach);
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
	if(m_pFeature[id]->m_type == feat_spawn)
		static_cast<CFeatSpawn*>(m_pFeature[id])->m_szHash = iniKey;
	else if(m_pFeature[id]->m_type == feat_attach)
		static_cast<CFeatAttach*>(m_pFeature[id])->m_szHash = iniKey;
	else
		m_pFeature[id]->m_szIniKey	= iniKey;
	m_pFeature[id]->m_bOn		= (bool) m_iniParser.getValue<bool>(m_pFeature[id]->m_szIniKey, "FeatureToggle");
	m_pFeature[id]->m_bRestored	= (m_pFeature[id]->m_bOn) ? false : true;
	m_pFeature[id]->m_bSet		= (m_pFeature[id]->m_bOn) ? false : true;
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, spwnType spawnType)
{
	int id = addFeature(cat, parent, name, type, iniKey);
	if(id < 0)
		return id;
	static_cast<CFeatSpawn*>(m_pFeature[id])->m_spawnType		= spawnType;
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, int playerId)
{
	int id = addFeature(cat, parent, name, type, iniKey);
	if(id < 0)
		return id;
	if(m_pFeature[id]->m_type == feat_attach)
		static_cast<CFeatAttach*>(m_pFeature[id])->m_iPlayer		= playerId;
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, float min, float max)
{
	int id = addFeature(cat, parent, name, type, iniKey);
	if(id < 0)
		return id;
	static_cast<CFeatSlider*>(m_pFeature[id])->m_fMin		= min;
	static_cast<CFeatSlider*>(m_pFeature[id])->m_fMax		= max;
	float v	= m_iniParser.getValue<float>(iniKey, "FeatureValue");
	if(v <= max && v >= min)
		static_cast<CFeatSlider*>(m_pFeature[id])->m_fValue	= v;
	else
	{
		static_cast<CFeatSlider*>(m_pFeature[id])->m_fValue	= min;
		m_iniParser.setValue<float>(iniKey, min, "FeatureValue");
	}
	return id;
}

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, float min, float max, float mod, char* enumArray[])
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

int		CMenu::addFeature(int cat, int parent, std::string name, featType type, std::string iniKey, teleType tpType)
{
	if(tpType != tp_saved)
		return -1;
	int id = addFeature(cat, parent, name, type, iniKey);
	if(id < 0)
		return id;
	static_cast<CFeatTeleport*>(m_pFeature[id])->m_tpType		= tpType;
	static_cast<CFeatTeleport*>(m_pFeature[id])->m_v3Pos.x		= m_iniParser.getValue<float>(iniKey + "_x", "Teleport");
	static_cast<CFeatTeleport*>(m_pFeature[id])->m_v3Pos.y		= m_iniParser.getValue<float>(iniKey + "_y", "Teleport");
	static_cast<CFeatTeleport*>(m_pFeature[id])->m_v3Pos.z		= m_iniParser.getValue<float>(iniKey + "_z", "Teleport");
	static_cast<CFeatTeleport*>(m_pFeature[id])->m_szName		+= " | " + m_iniParser.getValue<std::string>(iniKey + "_name", "Teleport");
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
	if(id > m_pFeature.size() - 1)
		return 0;
	return m_pFeature[id];
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
		CMenu::m_iniParser.setValue<bool>((std::string) m_szIniKey, (int) m_bOn, "FeatureToggle");
	return;
}

void	CFeat::toggle(bool state)
{
	m_bOn = state;
	if(m_bOn)
		m_bRestored = false;
	m_bSet = false;
	if(m_szIniKey != "")
		CMenu::m_iniParser.setValue<bool>((std::string) m_szIniKey, (int) m_bOn, "FeatureToggle");
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
	CMenu::m_iniParser.setValue<float>((std::string) m_szIniKey, m_fValue, "FeatureValue");
	return;
}

void	CFeatSlider::dec()
{
	float v		= (m_fValue - ( (m_fMax - m_fMin) * m_fMod) );
	if(v >= m_fMin)
		m_fValue = v;
	else
		m_fValue = m_fMin;
	CMenu::m_iniParser.setValue<float>((std::string) m_szIniKey, m_fValue, "FeatureValue");
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
	CMenu::m_iniParser.setValue<float>((std::string) m_szIniKey, m_fValue, "FeatureValue");
	return;
}

void	CFeatValue::dec()
{
	float v		= m_fValue - m_fMod;
	if(v >= m_fMin)
		m_fValue = v;
	else
		m_fValue = m_fMax;
	CMenu::m_iniParser.setValue<float>((std::string) m_szIniKey, m_fValue, "FeatureValue");
	return;
}

CFeatValueStr::CFeatValueStr() {}
CFeatValueStr::~CFeatValueStr() {}

char**	CFeatValueStr::getCharArray()
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

CFeatActionValueStr::CFeatActionValueStr() {}
CFeatActionValueStr::~CFeatActionValueStr() {}

char**	CFeatActionValueStr::getCharArray()
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
			CHack::m_requestedVehicle.push_back(m_szHash);
		break;
		case spwn_weapon:
			CHack::m_requestedWeapon.push_back(m_szHash);
			CHack::m_bWeaponGive	= true;
		break;
		case spwn_weapon_all:
			CHack::m_requestedWeapon.push_back("ALL");
			CHack::m_bWeaponGive	= true;
		break;
		case dspwn_weapon:
			CHack::m_requestedWeapon.push_back(m_szHash);
			CHack::m_bWeaponGive	= false;
		break;
		case dspwn_weapon_all:
			CHack::m_requestedWeapon.push_back("ALL");
			CHack::m_bWeaponGive	= false;
		break;
		case spwn_model:
			CHack::m_szRequestedModel	= m_szHash;
			CHack::m_bModelSet			= false;
		break;
		case spwn_ped:
			CHack::m_requestedPed.push_back(m_szHash);
		break;
		case spwn_object:
			CHack::m_requestedObject.push_back(m_szHash);
			CFeat* feat = CMenu::getFeature(feature::map["FEATURE_E_EDITOR_MODE"]);
			if(!feat->m_bOn)
				feat->toggle();
		break;
	}
}

CFeatAttach::CFeatAttach() {}
CFeatAttach::~CFeatAttach() {}

void	CFeatAttach::toggle()
{
	CFeat* feat = CMenu::getFeature(feature::map["FEATURE_O_ATTACH_BONE"]);
	int	iAttachBone = -1;
	if(feat->m_bOn)
		iAttachBone = (int) feat->getValue();
	CHack::m_requestedAttach.push_back({ m_iPlayer, iAttachBone, m_szHash });
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
	m_key.clear();

	std::string szLine;
	int			iSection = -1;
	std::regex	regexSection("^\\[([A-Za-z0-9_]+)\\]$"),
				regexKey	("^([A-Za-z0-9_]+)=([A-Za-z0-9_\\-*/+.\\s]+)$"),
				regexComment("^(;|#)(.*)$");

	while(std::getline(file, szLine, '\n'))
	{
		std::smatch    regexMatch;    //std::string match object

		if(szLine == "")
			continue;
        
		else if(std::regex_search(szLine, regexMatch, regexComment) && regexMatch.size() > 1)
			m_key.push_back({"__COMMENT__", regexMatch[2], iSection});
             
		else if(std::regex_search(szLine, regexMatch, regexSection) && regexMatch.size() > 1)
		{
			iSection    = (int) m_section.size();
			m_section.push_back(regexMatch[1]);
		}
            
		else if(std::regex_search(szLine, regexMatch, regexKey) && regexMatch.size() > 1)
			m_key.push_back({regexMatch[1], regexMatch[2], iSection});
	}
	return;
}

void CIniParser::write()
{
	std::ofstream file;
	file.open(m_szFile, std::ios::out | std::ios::trunc);
	if(!file.is_open())
		return;
	for(int j = 0; j <= m_section.size(); j++)
	{
		if(j > 0)
			file << "[" << m_section[j - 1] << "]\n";
		for(int i = 0; i < m_key.size(); i++)
		{
			if(m_key[i].section != j - 1)
				continue;
			if(m_key[i].key == "__COMMENT__")
				file << ";" ;
			else
				file << m_key[i].key << "=";
			file << m_key[i].value << "\n";
		}
	}
	return;
}

int CIniParser::findKey(std::string szKey, std::string szSection)
{
	for(int i = 0; i < m_key.size(); i++)
		if(m_key[i].key == szKey && (szSection == "" || szSection == m_section[m_key[i].section]))
			return i;
	return -1;
}

int CIniParser::createKey(std::string szKey, std::string szSection)
{
	if(szKey == "")
		return -1;
	int iSection = -1;
	if(szSection != "")
	{
		for(int i = 0; i < m_section.size(); i++)
			if(m_section[i] == szSection)
			{
				iSection = i;
				break;
			}
	}
	m_key.push_back({szKey, "", iSection});
	return (int) m_key.size() - 1;
}