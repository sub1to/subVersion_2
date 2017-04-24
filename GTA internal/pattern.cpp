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

void	mem_nop(void* ptr, int size)
{
	memset(ptr, 0x90, size);
}

/*
	//CMetaData
*/

uint64_t	CMetaData::m_begin		= 0;
uint64_t	CMetaData::m_end		= 0;
DWORD		CMetaData::m_size		= 0;

uint64_t	CMetaData::begin()
{
	return m_begin;
}
uint64_t	CMetaData::end()
{
	return m_end;
}
DWORD		CMetaData::size()
{
	return m_size;
}

void		CMetaData::init()
{
	if(m_begin && m_size)
		return;

	m_begin		= (uint64_t) GetModuleHandleA(nullptr);
	const IMAGE_DOS_HEADER*	headerDos	= (const IMAGE_DOS_HEADER*)		m_begin;
	const IMAGE_NT_HEADERS*	headerNt	= (const IMAGE_NT_HEADERS64*)	((const BYTE*) headerDos +  headerDos->e_lfanew);
	m_size		= headerNt->OptionalHeader.SizeOfCode;
	m_end		= m_begin + m_size;
	return;
}

/*
	//CPatternResult
*/

CPatternResult::CPatternResult(void* pVoid) :
	m_pVoid(pVoid)
{}
CPatternResult::~CPatternResult() {}

/*
	//CPattern Public
*/

CPattern::CPattern(char* szByte, char* szMask)	:
	m_szByte(szByte),
	m_szMask(szMask),
	m_bSet(false)
{}
CPattern::~CPattern() {}

CPattern&	CPattern::find(int i)
{
	match(i);
	if(m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
	//return m_result[0];
}

CPatternResult	CPattern::get(int i)
{
	if(m_result.size() > i)
		return m_result[i];
	return nullptr;
}

/*
	//CPattern Private
*/

bool	CPattern::match(int i)
{
	if(m_bSet)
		return false;
	CMetaData::init();
	uint64_t	begin	= CMetaData::begin();
	int			j		= 0;
	do
	{
		begin	= findPattern(begin, CMetaData::end(), (BYTE*) m_szByte, m_szMask);
		if(begin == NULL)
			break;
		j++;
	}	while(j < i);
	
	m_bSet = true;
	return true;
}

bool	CPattern::byteCompare(const BYTE* pData, const BYTE* btMask, const char* szMask)
{
	for(; *szMask; ++szMask, ++pData, ++btMask)
		if(*szMask == 'x' && *pData != *btMask)
			break;
	if((*szMask) != 0)
		return false;
	return true;
}


uint64_t	CPattern::findPattern(uint64_t address, uint64_t end, BYTE *btMask, char *szMask)
{
	for(DWORD i = 0; i < (end - address); i++)
		if(byteCompare((BYTE*) (address + i), btMask, szMask))
		{
			m_result.push_back(CPatternResult((void*) (address + i)));
			return address + i;
		}
	return NULL;
}
