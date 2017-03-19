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
	//Vector
*/
namespace vec
{
	v3::v3(float fx, float fy, float fz)
	{
		x = fx;
		y = fy;
		z = fz;
	}

	v3&		v3::operator=(const v3& rhs)
	{
		x	= rhs.x;
		y	= rhs.y;
		z	= rhs.z;
		return *this;
	}

	v3&		v3::operator*=(const v3& rhs)
	{
		x	*= rhs.x;
		y	*= rhs.y;
		z	*= rhs.z;
		return *this;
	}

	v3&		v3::operator*=(const float rhs)
	{
		x	*= rhs;
		y	*= rhs;
		z	*= rhs;
		return *this;
	}

	v3&		v3::operator+=(const v3& rhs)
	{
		x	+= rhs.x;
		y	+= rhs.y;
		z	+= rhs.z;
		return *this;
	}

	v3&		v3::operator-=(const v3& rhs)
	{
		x	-= rhs.x;
		y	-= rhs.y;
		z	-= rhs.z;
		return *this;
	}

	v3&		v3::transformRotToDir()
	{
		double	a	= util::deg_to_rad(x),
				b	= util::deg_to_rad(z),
				c	= cos(a);
		x	= (float) -(c * sin(b));
		y	= (float) (c * cos(b));
		z	= (float) sin(a);
		return *this;
	}

	v3::operator Vector3() const
	{
		return {x, 0, y, 0, z, 0};
	}

	float	v3::getDist(v3 to)
	{
		return (float)sqrt(	pow(double(x - to.x), 2.0) +
							pow(double(y - to.y), 2.0) +
							pow(double(z - to.z), 2.0));
	}

	bool	v3::empty()
	{
		return	x	== 0.f
			&&	y	== 0.f
			&&	z	== 0.f;
	}

	void	v3::clear()
	{
		x	= 0.f;
		y	= 0.f;
		z	= 0.f;
	}
};