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

void getTime(char* out)
{
	time_t	t;
	tm		tInfo;
	time(&t);
	localtime_s(&tInfo, &t);
	strftime(out, 32, "[%F %H:%M:%S]", &tInfo);
	return;
}

void addTime(std::string& str)
{
	char time[32];
	getTime(time);
	str.insert(0, time);
	return;
}

std::string	CLog::log(char* format, char* prefix, va_list args)
{
	std::ofstream	file;
	char			msg[2][0xFF]	= {};
	char			time[0x20]		= {};

	file.open(CLog::m_szFile, std::ios::out | std::ios::app);
	if(!file.is_open())
		return {};

	getTime(time);
	vsprintf_s(msg[0], format, args);
	sprintf_s(msg[1], "%s %s %s", time, prefix, msg[0]);
	
	file << msg[1] << std::endl;
	return std::string(msg[1]);
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

	return true;
}

void	CLog::msg(char* msg, ...)
{
	va_list	args;
	va_start(args, msg);
	m_msg.push_back(log(msg, "[Msg]", args));
	va_end(args);
	return;
}

void	CLog::error(char* error, ...)
{
	va_list	args;
	va_start(args, error);
	m_error.push_back(log(error, "[Error]", args));
	va_end(args);
	return;
}

void	CLog::fatal(char* error, ...)
{
	va_list	args;
	va_start(args, error);
	m_fatal.push_back(log(error, "[Fatal]", args));
	va_end(args);
	return;
}