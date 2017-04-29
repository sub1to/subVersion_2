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

void	mem_nop(void* ptr, int size);

/*
	//CMetaData
*/

class CMetaData
{
	public:
		static uint64_t	begin();
		static uint64_t	end();
		static DWORD	size();
		static void		init();
	private:
		static uint64_t	m_begin;
		static uint64_t	m_end;
		static DWORD	m_size;
};

/*
	//CPatternResult
*/

class CPatternResult
{
	public:
		CPatternResult(void* pVoid);
		~CPatternResult();

		template <typename rT>
		rT*	get(int offset = 0)
		{
			rT*	ret	= nullptr;
			if(m_pVoid != nullptr)
				ret	= reinterpret_cast<rT*>(reinterpret_cast<char*>(m_pVoid) + offset);
			return ret;
		}

	protected:
		void*	m_pVoid	= nullptr;
};

/*
	//CPattern
*/

typedef	std::vector<CPatternResult>	vec_result;
class CPattern
{
	public:
		CPattern(char* szByte, char* szMask);
		~CPattern();
		
		CPattern&		find(int i = 0);		//scans for i patterns
		CPatternResult	get(int i);				//returns result i

	protected:
		char*			m_szByte;
		char*			m_szMask;
		bool			m_bSet;
		vec_result		m_result;

		bool		match(int i = 0);
		bool		byteCompare(const BYTE* pData, const BYTE* btMask, const char* szMask);
		uint64_t	findPattern(uint64_t i64Address, uint64_t end, BYTE *btMask, char *szMask);
};