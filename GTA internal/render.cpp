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
	//CRender static public members
*/

scrnVars		CRender::m_screen;
std::string		CRender::m_szWindowTitle;
CColor CRender::LAYOUT_COLOR_BACKGROUND		= { 0x38, 0x78, 0xE2, 0xFF };
CColor CRender::LAYOUT_COLOR_BORDER			= { 0x01, 0x01, 0x01, 0xFF };
CColor CRender::LAYOUT_COLOR_SLIDER_BG		= { 0x28, 0x28, 0x28, 0xFF };
CColor CRender::LAYOUT_COLOR_SLIDER_BTN		= { 0x73, 0x73, 0x73, 0xFF };
CColor CRender::LAYOUT_COLOR_ACTIVE_BG		= { 0x85, 0xac, 0xed, 0xFF };
CColor CRender::LAYOUT_COLOR_SELECTED		= { 0xFF, 0xFF, 0xFF, 0xFF };

/*
	//CRender functions
*/

bool	CRender::initialze(HMODULE hModule, std::string szWindowTitle)
{
	m_szWindowTitle = szWindowTitle;
	return true;
}


bool	CRender::render()
{
	if(!CMenu::isMenuActive())
		return false;

	int	x	= m_screen.x,
		y	= m_screen.y,
		w	= LAYOUT_ELEMENT_WIDTH,
		h	= LAYOUT_ELEMENT_HEIGHT;

	//Draw header
	drawBoxBorder(x, y, w, h, LAYOUT_BORDER_SIZE, LAYOUT_COLOR_BACKGROUND, LAYOUT_COLOR_BORDER);
	drawText(&m_szWindowTitle[0], x, y - 1, w, h, 4, 0.35f, LAYOUT_COLOR_BORDER, TEXTFLAG_CENTER | TEXTFLAG_NOSHADOW);
	y	+=	h;

	//draw tabs
	int aCat	= CMenu::getActiveCat(),
		nCat	= CMenu::getFeatureCategoryCount(),
		xCat	= x;
	for(int i = 0; i < nCat; i++)
	{
		CFeatCat*	tab	= CMenu::getFeatureCategory(i);
		int			w	= i == aCat ? (LAYOUT_ELEMENT_WIDTH / (nCat + 1)) * 2 : LAYOUT_ELEMENT_WIDTH / (nCat + 1);

		drawBoxBorder(	xCat, y, w, h, LAYOUT_BORDER_SIZE,
								(i == aCat) ? LAYOUT_COLOR_ACTIVE_BG : LAYOUT_COLOR_BACKGROUND,
								(i == aCat) ? LAYOUT_COLOR_BORDER : LAYOUT_COLOR_BORDER);
		drawText(&tab->m_szDisplay[0], xCat, y + 1, w - 1, h, 0, 0.25f, LAYOUT_COLOR_BORDER, TEXTFLAG_CENTER | TEXTFLAG_NOSHADOW);
		xCat += w;
	}
	y	+= h;

	//draw features
	int		nFeat		= CMenu::getFeatureCurCount(),
			aFeat		= CMenu::getActiveFeature(),
			xFeat		= x;
	bool	checkBox	= CMenu::getCheckBox();

	//draw bg for all features
	drawBoxBorder(	m_screen.x,
					m_screen.y + LAYOUT_ELEMENT_HEIGHT * 2,
					LAYOUT_ELEMENT_WIDTH,
					(nFeat > MAX_MENU_FEATURES_DISPLAYED) ? MAX_MENU_FEATURES_DISPLAYED * LAYOUT_ELEMENT_HEIGHT : LAYOUT_ELEMENT_HEIGHT * nFeat,
					LAYOUT_BORDER_SIZE,
					LAYOUT_COLOR_BACKGROUND,
					LAYOUT_COLOR_BORDER);
		
	//draw individual features
	for(int i = 0, j = CMenu::getDisplayOffset(); i < nFeat && i < MAX_MENU_FEATURES_DISPLAYED; i++, j++)
	{
		CFeat*	feature	= CMenu::getFeatureCur(j);
		xFeat	= x + 8;

		//selected box
		if(j == aFeat)
			drawBoxBorder(	xFeat - 6,
							y + 2,
							LAYOUT_ELEMENT_WIDTH - (LAYOUT_BORDER_SIZE * 2),
							LAYOUT_ELEMENT_HEIGHT - (LAYOUT_BORDER_SIZE * 2),
							LAYOUT_BORDER_SIZE,
							LAYOUT_COLOR_ACTIVE_BG,
							LAYOUT_COLOR_SELECTED);

		//checkbox
		if(feature->m_type & feat_toggle)
		{
			drawBoxBorder(	xFeat - 2,
							y + 5,
							LAYOUT_ELEMENT_HEIGHT - (LAYOUT_BORDER_SIZE * 5),
							LAYOUT_ELEMENT_HEIGHT - (LAYOUT_BORDER_SIZE * 5),
							LAYOUT_BORDER_SIZE,
							(feature->m_bOn == true) ? LAYOUT_COLOR_SELECTED : LAYOUT_COLOR_BACKGROUND,
							(feature->m_bOn == true) ? LAYOUT_COLOR_BORDER : LAYOUT_COLOR_BORDER);
		}
		if(checkBox)
			xFeat	+= (LAYOUT_ELEMENT_HEIGHT - (LAYOUT_BORDER_SIZE * 3));
		std::string featname = feature->m_type & feat_parent ? feature->m_szName + " >>" : feature->m_szName;
		drawText(&featname[0], xFeat, y + 2, 0, 0, 0, .24f, LAYOUT_COLOR_BORDER, TEXTFLAG_NOSHADOW);
			
		//slider & value
		if(feature->m_type & feat_slider | feat_value)
		{
			int		xSlide	= x + (int) (LAYOUT_ELEMENT_WIDTH * .5f),
					ySlide	= y + 5,
					w		= (int) ((LAYOUT_ELEMENT_WIDTH * .5f) - (LAYOUT_BORDER_SIZE * 2)),
					h		= LAYOUT_ELEMENT_HEIGHT - (LAYOUT_BORDER_SIZE * 5);
			if(feature->m_type == feat_slider)
			{
				float			mod	= (feature->getValue() - feature->getMin()) / (feature->getMax() - feature->getMin());
				drawBoxBorder(xSlide, ySlide, w, h, LAYOUT_BORDER_SIZE, LAYOUT_COLOR_SLIDER_BG, LAYOUT_COLOR_BORDER);
				drawBoxBorder(xSlide + (int) (mod * (w - h)), ySlide, h, h, LAYOUT_BORDER_SIZE, LAYOUT_COLOR_SLIDER_BTN, LAYOUT_COLOR_BORDER);
			}
			else if(feature->m_type & 1 << 2)
			{
				if(feature->m_type & (1 << 8 | 1 << 9))
				{
					const char* const * ppCh = feature->getCharArray();
					char msg[0x20];
					sprintf_s(msg, "< %s >", *((ppCh) + (int) feature->getValue()));
					drawText(msg, xSlide, ySlide - 3, w, 0, 0, .24f, LAYOUT_COLOR_BORDER, TEXTFLAG_CENTER | TEXTFLAG_NOSHADOW);
				}
				else
				{
					char msg[0x20];
					sprintf_s(msg, "< %i >", (int) feature->getValue());
					drawText(msg, xSlide, ySlide - 3, w, 0, 0, .24f, LAYOUT_COLOR_BORDER, TEXTFLAG_CENTER | TEXTFLAG_NOSHADOW);
				}
			}
		}
		y	+= h;
	}

	//draw scrollbar
	int	max = nFeat - MAX_MENU_FEATURES_DISPLAYED;	//number of features that are not displayed
	if(max > 0)
	{
		int		space = LAYOUT_ELEMENT_HEIGHT * (MAX_MENU_FEATURES_DISPLAYED + 2),
				height = (space / max <= space / 2) ? space / (max > MAX_MENU_FEATURES_DISPLAYED ? MAX_MENU_FEATURES_DISPLAYED : max) : space / 2;
				space -= height;
		float	mod	= (CMenu::getDisplayOffset() / (float) max);
		drawBoxBorder(m_screen.x + LAYOUT_ELEMENT_WIDTH + LAYOUT_BORDER_SIZE , m_screen.y + (int) (space * mod), LAYOUT_SCROLLBAR_WIDTH, height, LAYOUT_BORDER_SIZE, LAYOUT_COLOR_BACKGROUND, LAYOUT_COLOR_BORDER);
	}

	return true;
}

void	CRender::drawBox(int x, int y, int w, int h, CColor color)
{
	float	relW	= util::pixel_to_rel(w, false);
	float	relH	= util::pixel_to_rel(h, true);
	float	relX	= util::pixel_to_rel(x, false) + (relW / 2);
	float	relY	= util::pixel_to_rel(y, true) + (relH / 2);
	GRAPHICS::DRAW_RECT(relX, relY, relW, relH, color.r, color.g, color.b, color.a);
	return;
}

void	CRender::drawBoxInline(int x, int y, int w, int h, int size, CColor color)
{
	drawBox(x,			y,				w,		size,	color);	//top
	drawBox(x + w - size,	y,				size,	h,		color);	//right
	drawBox(x,			y + h - size,	w,		size,	color);	//bottom
	drawBox(x,			y,				size,	h,		color);	//left
	return;
}

void	CRender::drawBoxBorder(int x, int y, int w, int h, int borderSize, CColor color, CColor borderColor)
{
	drawBox(x, y, w, h, borderColor);
	drawBox(x + borderSize, y + borderSize, w - (borderSize * 2), h - (borderSize * 2), color);
}

void	CRender::drawText(char* str, int x, int y, int w, int h, int font, float scale, CColor color, uint32_t flags)
{
	float	relX	= util::pixel_to_rel(x, false);
	float	relY	= util::pixel_to_rel(y, true);
	if(flags & TEXTFLAG_CENTER)
		relX += (util::pixel_to_rel(w, false) / 2);
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scale, scale);
	UI::SET_TEXT_COLOUR(color.r, color.g, color.b, color.a);
	UI::SET_TEXT_WRAP(0.0, 1.0); //
	UI::SET_TEXT_CENTRE(flags & TEXTFLAG_CENTER);
	if(flags & TEXTFLAG_NOSHADOW)
		UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	else
		UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 175);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING"); //
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(str);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(relX, relY);
}

