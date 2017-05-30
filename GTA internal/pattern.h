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
		CPatternResult(void* pVoid, void* pBegin, void* pEnd);
		~CPatternResult();

		template <typename rT>
		rT*	get(int offset = 0)
		{
			rT*	ret	= nullptr;
			if(m_pVoid != nullptr)
				ret	= reinterpret_cast<rT*>(reinterpret_cast<char*>(m_pVoid) + offset);
			return ret;
		}

		template <typename rT>
		rT* get_rel(int offset = 0)
		{
			rT*		result	= nullptr;
			int32_t	rel;
			char*	ptr		= get<char>(offset);

			if(ptr == nullptr)
				goto LABEL_RETURN;

			rel	= *(int32_t*) ptr;
			result = reinterpret_cast<rT*>(ptr + rel + sizeof(rel));

		LABEL_RETURN:
			return result;
		}

		template <typename rT>
		rT*	section_begin()
		{
			return reinterpret_cast<rT*>(m_pBegin);
		}

		template <typename rT>
		rT*	section_end()
		{
			return reinterpret_cast<rT*>(m_pEnd);
		}

	protected:
		void*	m_pVoid		= nullptr;
		void*	m_pBegin	= nullptr;
		void*	m_pEnd		= nullptr;
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
		
		CPattern&		find(int i = 0, uint64_t startAddress = 0);		//scans for i patterns
		CPattern&		virtual_find(int i = 0, uint64_t startAddress = 0);
		CPatternResult	get(int i);				//returns result i

	protected:
		char*			m_szByte;
		char*			m_szMask;
		bool			m_bSet;
		vec_result		m_result;

		bool		match(int i = 0, uint64_t startAddress = 0, bool virt = false);
		bool		byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask);
		uint64_t	find_pattern(uint64_t i64Address, uint64_t end, BYTE *btMask, char *szMask);
		uint64_t	virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask);
};