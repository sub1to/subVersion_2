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
#ifndef CROSSMAP_H
#define CROSSMAP_H

typedef	std::unordered_map<uint64_t, uint64_t>	hashMap;
typedef struct hashEntry
{
	uint64_t	x,
				y;
} hashEntry;

class CCrossMap
{
public:
	static	void		init();
	static	uint64_t	get(uint64_t inNative);
};

#endif


