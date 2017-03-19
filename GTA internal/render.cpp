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

LRESULT __stdcall WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

/*
	//CRender static public members
*/

scrnVars		CRender::m_screen;
std::string		CRender::m_szWindowTitle;

/*
	//CRender static protected members
*/
HWND					CRender::m_hWnd;
LPDIRECT3D9				CRender::m_pD3d;			// the pointer to Direct3D interface
LPDIRECT3DDEVICE9		CRender::m_pD3dDev;		// the pointer to the device
LPD3DXFONT				CRender::m_pFont[FONT_BUFFER_SIZE];
int						CRender::m_nFont		= 0;
D3DPRESENT_PARAMETERS	CRender::m_d3dParam;		//d3d9 device params

/*
	//CRender functions
*/

bool	CRender::initialze(HMODULE hModule, std::string szWindowTitle)
{
	m_szWindowTitle = szWindowTitle;
	LPCSTR	szWindowClass	= "subVersionOverlay";
	//Create window
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize			= sizeof(WNDCLASSEX);
	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		= WindowProc;
	wc.hInstance		= hModule;
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hIcon			= LoadIcon(hModule, MAKEINTRESOURCE(IDI_ICON1));
	wc.hIconSm			= LoadIcon(hModule, MAKEINTRESOURCE(IDI_ICON1));
	wc.hbrBackground	= (HBRUSH) CreateSolidBrush(RGB(0, 0, 0));
	wc.lpszClassName	= szWindowClass;

	RegisterClassEx(&wc);
	m_hWnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED,		//dwExStyle [in]
							szWindowClass,											//lpClassName [in, optional]
							(LPCSTR) m_szWindowTitle.c_str(),						//lpWindowName [in, optional]
							WS_POPUP,												//dwStyle [in]
							0,														//x [in]
							0,														//y [in]
							LAYOUT_WIDTH,											//nWidth [in]
							LAYOUT_HEIGHT,											//nHeight [in]
							nullptr,												//hWndParent [in, optional]
							nullptr,												//hMenu [in, optional]
							hModule,												//hInstance [in, optional]		A handle to the instance of the module to be associated with the window.
							nullptr);												//lpParam [in, optional]

	SetLayeredWindowAttributes(m_hWnd, 0, 0, LWA_ALPHA);
	SetLayeredWindowAttributes(m_hWnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
	MARGINS margins {1, 1, 1, 1};
	DwmExtendFrameIntoClientArea(m_hWnd, &margins);
	ShowWindow(m_hWnd, SW_SHOWNORMAL);

	//Create d3d9 interface and device
	m_pD3d	= Direct3DCreate9(D3D_SDK_VERSION);		//interface

	ZeroMemory(&m_d3dParam, sizeof(m_d3dParam));
	m_d3dParam.Windowed				= true;
	m_d3dParam.SwapEffect			= D3DSWAPEFFECT_DISCARD;
	m_d3dParam.hDeviceWindow		= m_hWnd;
	m_d3dParam.BackBufferHeight		= m_screen.h;
	m_d3dParam.BackBufferWidth		= m_screen.w;
	m_d3dParam.MultiSampleQuality	= D3DMULTISAMPLE_NONE;
	m_d3dParam.BackBufferFormat		= D3DFMT_A8R8G8B8;
	m_d3dParam.PresentationInterval	= D3DPRESENT_INTERVAL_IMMEDIATE;

	m_pD3d->CreateDevice(	D3DADAPTER_DEFAULT,
							D3DDEVTYPE_HAL,
							m_hWnd,
							D3DCREATE_HARDWARE_VERTEXPROCESSING,
							&m_d3dParam,
							&m_pD3dDev);

	createFont("Verdana", 14, true, false);
	createFont("Verdana", 14, false, false);
	createFont("Verdana", 18, true, false);

	return true;
}

void	CRender::uninitialze()
{
	releaseFont();
	m_pD3dDev->Release();    // close and release the 3D device
    m_pD3d->Release();		// close and release Direct3D
	DestroyWindow(m_hWnd);
}


bool	CRender::render()
{
	m_pD3dDev->Clear(0, nullptr, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0,0,0,0), 1.f, 0);
	m_pD3dDev->BeginScene();

	if(CMenu::isMenuActive())
	{
		int	x	= 0,
			y	= 0,
			w	= LAYOUT_ELEMENT_WIDTH,
			h	= LAYOUT_ELEMENT_HEIGHT;

		//Draw header
		drawBoxBorder(x, y, w, h, LAYOUT_BORDER_SIZE, LAYOUT_COLOR_BACKGROUND, LAYOUT_COLOR_BORDER);
		drawText(m_szWindowTitle, x, y, w, h, 2, LAYOUT_COLOR_TEXT, DT_CENTER | DT_VCENTER);
		y	+=	h;

		//draw tabs
		int aCat	= CMenu::getActiveCat(),
			nCat	= CMenu::getFeatureCategoryCount();
		for(int i = 0; i < nCat; i++)
		{
			CFeatCat*	tab	= CMenu::getFeatureCategory(i);
			int			w	= i == aCat ? (LAYOUT_ELEMENT_WIDTH / (nCat + 1)) * 2 : LAYOUT_ELEMENT_WIDTH / (nCat + 1);

			drawBoxBorder(	x, y, w, h, LAYOUT_BORDER_SIZE,
									(i == aCat) ? LAYOUT_COLOR_ACTIVE_BG : LAYOUT_COLOR_BACKGROUND,
									(i == aCat) ? LAYOUT_COLOR_ACTIVE_BORDER : LAYOUT_COLOR_BORDER);
			drawText(tab->m_szDisplay, x, y, w - 1, h, 0, LAYOUT_COLOR_TEXT, DT_CENTER | DT_VCENTER);
			x += w;
		}
		x	= 0;
		y	+= h;

		//draw features
		int		nFeat		= CMenu::getFeatureCurCount(),
				aFeat		= CMenu::getActiveFeature();
		bool	checkBox	= CMenu::getCheckBox();

		//draw bg for all features
		drawBoxBorder(	0,
								LAYOUT_ELEMENT_HEIGHT * 2,
								LAYOUT_ELEMENT_WIDTH,
								(nFeat > MAX_MENU_FEATURES_DISPLAYED) ? MAX_MENU_FEATURES_DISPLAYED * LAYOUT_ELEMENT_HEIGHT : LAYOUT_ELEMENT_HEIGHT * nFeat,
								LAYOUT_BORDER_SIZE,
								LAYOUT_COLOR_BACKGROUND,
								LAYOUT_COLOR_BORDER);
		
		//draw individual features
		for(int i = 0, j = CMenu::getDisplayOffset(); i < nFeat && i < MAX_MENU_FEATURES_DISPLAYED; i++, j++)
		{
			CFeat*	feature	= CMenu::getFeatureCur(j);
			x	= 8;

			//selected box
			if(j == aFeat)
				drawBoxBorder(	x - 6,
										y + 2,
										LAYOUT_ELEMENT_WIDTH - (LAYOUT_BORDER_SIZE * 2),
										LAYOUT_ELEMENT_HEIGHT - (LAYOUT_BORDER_SIZE * 2),
										LAYOUT_BORDER_SIZE,
										LAYOUT_COLOR_ACTIVE_BG,
										LAYOUT_COLOR_SELECTED);

			//checkbox
			if(feature->m_type & feat_toggle)
			{
				drawBoxBorder(	x - 2,
										y + 5,
										LAYOUT_ELEMENT_HEIGHT - (LAYOUT_BORDER_SIZE * 5),
										LAYOUT_ELEMENT_HEIGHT - (LAYOUT_BORDER_SIZE * 5),
										LAYOUT_BORDER_SIZE,
										(feature->m_bOn == true) ? LAYOUT_COLOR_SELECTED : LAYOUT_COLOR_BACKGROUND,
										(feature->m_bOn == true) ? LAYOUT_COLOR_ACTIVE_BORDER : LAYOUT_COLOR_BORDER);
			}
			if(checkBox)
				x	+= (LAYOUT_ELEMENT_HEIGHT - (LAYOUT_BORDER_SIZE * 3));
			drawText(feature->m_type & feat_parent ? feature->m_szName + " >>" : feature->m_szName, x, y, 0, LAYOUT_ELEMENT_HEIGHT, 1, LAYOUT_COLOR_TEXT, DT_VCENTER);
			
			//slider & value
			if(feature->m_type & feat_slider | feat_value)
			{
				int				x	= (int) (LAYOUT_ELEMENT_WIDTH * .5f),
								y	= (LAYOUT_ELEMENT_HEIGHT * (i + 2)) + 5,
								w	= (int) ((LAYOUT_ELEMENT_WIDTH * .5f) - (LAYOUT_BORDER_SIZE * 2)),
								h	= LAYOUT_ELEMENT_HEIGHT - (LAYOUT_BORDER_SIZE * 5);
				if(feature->m_type == feat_slider)
				{
					float			mod	= (feature->getValue() - feature->getMin()) / (feature->getMax() - feature->getMin());
					drawBoxBorder(x, y, w, h, LAYOUT_BORDER_SIZE, LAYOUT_COLOR_SLIDER_BG, LAYOUT_COLOR_BORDER);
					drawBoxBorder(x + (int) (mod * (w - h)), y, h, h, LAYOUT_BORDER_SIZE, LAYOUT_COLOR_SLIDER_BTN, LAYOUT_COLOR_BORDER);
				}
				else if(feature->m_type & 1 << 2)
				{
					if(feature->m_type & (1 << 8 | 1 << 10))
					{
						char** ppCh = feature->getCharArray();
						drawText((std::string) "< " +  *((ppCh) + (int) feature->getValue()) + " >", x, y - 5, w, LAYOUT_ELEMENT_HEIGHT, 1, LAYOUT_COLOR_TEXT, DT_VCENTER | DT_CENTER);
					}
					else
						drawText("< " + std::to_string((int) feature->getValue()) + " >", x, y - 5, w, LAYOUT_ELEMENT_HEIGHT, 1, LAYOUT_COLOR_TEXT, DT_VCENTER | DT_CENTER);
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
			drawBoxBorder(LAYOUT_ELEMENT_WIDTH + LAYOUT_BORDER_SIZE , (int) (space * mod), LAYOUT_SCROLLBAR_WIDTH, height, LAYOUT_BORDER_SIZE, LAYOUT_COLOR_BACKGROUND, LAYOUT_COLOR_BORDER);
		}
	}

	m_pD3dDev->EndScene();
	m_pD3dDev->Present(nullptr, nullptr, nullptr, nullptr);
	return true;
}

bool	CRender::createFont(char *name, int size, bool bold, bool italic)
{
	if(m_nFont >= FONT_BUFFER_SIZE)
		return false;
	D3DXCreateFont(m_pD3dDev, size, 0, (bold) ? FW_BOLD : FW_NORMAL, 0, (italic) ? 1 : 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, name, &m_pFont[m_nFont]);
	m_nFont++;
	return true;
}

void	CRender::releaseFont()
{
	for(int i = 0; i < m_nFont; i++)
		if(m_pFont[i] != nullptr)
			m_pFont[i]->Release();
	m_nFont = 0;
	return;
}

void	CRender::drawBox(int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rect {x, y, x + w, y + h};
	m_pD3dDev->Clear(1, &rect, D3DCLEAR_TARGET, color, 1.f, 0);
	return;
}

void	CRender::drawBoxInline(int x, int y, int w, int h, int size, D3DCOLOR color)
{
	drawBox(x,			y,				w,		size,	color);	//top
	drawBox(x + w - size,	y,				size,	h,		color);	//right
	drawBox(x,			y + h - size,	w,		size,	color);	//bottom
	drawBox(x,			y,				size,	h,		color);	//left
	return;
}

void	CRender::drawBoxBorder(int x, int y, int w, int h, int borderSize, D3DCOLOR color, D3DCOLOR borderColor)
{
	drawBox(x, y, w, h, borderColor);
	drawBox(x + borderSize, y + borderSize, w - (borderSize * 2), h - (borderSize * 2), color);
}

void	CRender::drawText(std::string str, int x, int y, int font, D3DCOLOR color)
{
	LPCSTR	pszStr	= str.c_str();
	RECT	pos;
	pos.left	= x;
	pos.top		= y;
	m_pFont[font]->DrawTextA(nullptr, pszStr, (int) strlen(pszStr), &pos, DT_NOCLIP, color);
}

//void	drawText		(std::string str, float x, float y, float w, float h, int font, D3DCOLOR color, DWORD flags = NULL)
void	CRender::drawText(std::string str, int x, int y, int w, int h, int font, D3DCOLOR color, DWORD flags)
{
	LPCSTR	pszStr	= str.c_str();
	RECT	pos;
	pos.left	= x;
	pos.right	= x + w;
	pos.top		= y;
	pos.bottom	= y + h;
	m_pFont[font]->DrawTextA(nullptr, pszStr, (int) strlen(pszStr), &pos, flags | DT_NOCLIP, color);
}

HWND	CRender::getHWnd()
{
	return m_hWnd;
}


LRESULT __stdcall WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		break;
	}

	return DefWindowProc (hWnd, message, wParam, lParam); //default behaviour for any unhandled messages
}