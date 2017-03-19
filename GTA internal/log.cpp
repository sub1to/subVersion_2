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
	//CLog Public vars
*/
vec_str		CLog::m_msg;
vec_str		CLog::m_error;
vec_str		CLog::m_fatal;

/*
	//CLog Protected vars
*/
std::string	CLog::m_szFile;

/*
	//CLog Private functions
*/

void getTime(char* out)	//requires 12 bytes
{
	time_t	t;
	tm		tInfo;
	time(&t);
	localtime_s(&tInfo, &t);
	strftime(out, 12, "[%H:%M:%S]", &tInfo);
	return;
}

void addTime(std::string& str)
{
	char time[12] { ' ' };
	getTime(time);
	str.insert(0, time);
	return;
}

std::string	CLog::log(std::string msg, std::string prefix)
{
	std::ofstream file;
	file.open(CLog::m_szFile, std::ios::out | std::ios::app);
	if(!file.is_open())
		return "";
	msg.insert(0, prefix);
	addTime(msg);
	file << msg << std::endl;
	return msg;
}

/*
	//CLog Public functions
*/

bool	CLog::initialize(std::string szDir, std::string szFile)
{
	char*	appdata	= nullptr;
	size_t	size	= 0;
	if(_dupenv_s(&appdata, &size, "APPDATA") != 0 || appdata == nullptr)
		return false;

	m_szFile		= appdata;
	free(appdata);
	m_szFile.append("\\" + szDir);
	DWORD	attr	= GetFileAttributesA(&m_szFile[0]);
	if((attr == 0xFFFFFFFF || !(attr & FILE_ATTRIBUTE_DIRECTORY)) && !CreateDirectoryA(&m_szFile[0], NULL))
		return false;

	m_szFile.append("\\" + szFile);

	std::ofstream file;
	file.open(m_szFile, std::ios::out | std::ios::trunc);	//clear the file
	return true;
}

void	CLog::msg(char* msg)
{
	m_msg.push_back(log(msg, " [Msg] "));
	return;
}

void	CLog::error(char* error)
{
	m_error.push_back(log(error, " [Error] "));
	return;
}

void	CLog::fatal(char* error)
{
	m_fatal.push_back(log(error, " [Fatal] "));
	return;
}