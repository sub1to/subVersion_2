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

#ifndef HOOKING_H
#define HOOKING_H

typedef void	(__cdecl *NativeHandler)(scrNativeCallContext* context);	// Native function handler type
typedef std::unordered_map<uint64_t,NativeHandler>	handlerCache;

struct NativeRegistration
{
	NativeRegistration*	nextRegistration;
	NativeHandler		handlers[7];
	uint32_t			numEntries;
	uint64_t			hashes[7];
};

#pragma pack(push, 1)
struct threeBytes
{
	BYTE	byte[3];

	bool	empty();
};

struct screenReso
{
	uint32_t	w,
				h;
};

struct objectHash
{
	DWORD*	ptr;
	DWORD	hash;
};
#pragma pack(pop)

class CHooking
{
	public:
		static std::vector<LPVOID>		m_hookedNative;
		static eGameState* 				m_gameState;
		static CBlipList*				m_blipList;
		static NativeRegistration**		m_regTable;
		static CReplayInterface*		m_replayIntf;
		static handlerCache				m_handlerCache;
		static __int64**				m_globalBase;
		static MemoryPool**				m_entityPool;
		static CRITICAL_SECTION			m_critSec;
		static threeBytes*				m_infAmmo;
		static threeBytes*				m_noReload;
		static CViewPort*				m_viewPort;
		static screenReso*				m_resolution;
		static void*					m_objectHashTable;
		static void*					m_objectHashTableSectionEnd;

		static void				init();
		static void				cleanup();
		static void				onTick();
		static NativeHandler	getNativeHandler(uint64_t origHash);
		static __int64*			getGlobalPtr(int index);
		static void				defuseEvent(eRockstarEvent e, bool toggle);
		static void				antiCrash(bool toggle);

		template <typename T>
		static void nop_bytes(T* address, T& restore, bool toggle)
		{
			if(toggle)
			{
				if(restore.empty())
					restore	= *address;
				mem_nop(address, sizeof(T));
			}
			else if(!restore.empty())
				memcpy_s(address, sizeof(address), restore.byte, sizeof(T));
		}
};

#endif