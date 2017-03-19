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
#ifndef RENDER_H
#define RENDER_H

#define FONT_BUFFER_SIZE	0x10									//max amount of fonts

//Layout defines
#define LAYOUT_PADDING_TOP	50
#define LAYOUT_PADDING_LEFT	50

#define LAYOUT_BORDER_SIZE		2
#define LAYOUT_ELEMENT_WIDTH	300
#define LAYOUT_ELEMENT_HEIGHT	25

#define LAYOUT_SCROLLBAR_WIDTH	0x08
#define LAYOUT_SCROLLBAR_HEIGHT	0x40

#define LAYOUT_COLOR_BACKGROUND		D3DCOLOR_ARGB(0xff, 0x38, 0x78, 0xe2)
#define LAYOUT_COLOR_BORDER			D3DCOLOR_ARGB(0xff, 1, 1, 1)
#define LAYOUT_COLOR_TEXT			D3DCOLOR_ARGB(0xff, 1, 1, 1)
#define LAYOUT_COLOR_SLIDER_BG		D3DCOLOR_ARGB(0xff, 0x28, 0x28, 0x28)
#define LAYOUT_COLOR_SLIDER_BTN		D3DCOLOR_ARGB(0xff, 0x73, 0x73, 0x73)
#define LAYOUT_COLOR_ACTIVE_BG		D3DCOLOR_ARGB(0xff, 0x85, 0xac, 0xed)
#define LAYOUT_COLOR_ACTIVE_BORDER	D3DCOLOR_ARGB(0xff, 1, 1, 1)
#define LAYOUT_COLOR_SELECTED		D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff)

#define LAYOUT_WIDTH	310
#define LAYOUT_HEIGHT	300

struct scrnVars
{
	int		w = LAYOUT_WIDTH,		//screen width
			h = LAYOUT_HEIGHT;
};

class CRender
{
	public:
		static scrnVars		m_screen;
		static std::string	m_szWindowTitle;

		static bool	initialze(HMODULE hModule, std::string szWindowTitle);
		static void	uninitialze();

		static bool	render();
		static bool	createFont(char *font, int size, bool bold, bool italic);
		static void	releaseFont();

		static void	drawBox(int x, int y, int w, int h, D3DCOLOR color);
		static void	drawBoxInline(int x, int y, int w, int h, int size, D3DCOLOR color);
		static void	drawBoxBorder(int x, int y, int w, int h, int borderSize, D3DCOLOR color, D3DCOLOR borderColor);
		static void	drawText(std::string str, int x, int y, int font, D3DCOLOR color);
		static void	drawText(std::string str, int x, int y, int w, int h, int font, D3DCOLOR color, DWORD flags = NULL);

		static HWND	getHWnd();

	protected:
		static HWND						m_hWnd;
		static LPDIRECT3D9				m_pD3d;			// the pointer to Direct3D interface
		static LPDIRECT3DDEVICE9		m_pD3dDev;		// the pointer to the device
		static LPD3DXFONT				m_pFont[FONT_BUFFER_SIZE];
		static int						m_nFont;
		static D3DPRESENT_PARAMETERS	m_d3dParam;		//d3d9 device params

	private:
		CRender	() {};		//don't allow construction
		~CRender() {};
};

#endif