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

/*
	//CLog
*/

typedef std::vector<std::string> vec_str;

class CLog
{
	public:	
		static vec_str		m_msg;
		static vec_str		m_error;
		static vec_str		m_fatal;

		static bool	initialize(std::string szDir,std::string szFile);
		static void msg(char* msg, ...);
		static void error(char* error, ...);
		static void	fatal(char* erro, ...);

	protected:
		static std::string	m_szFile;
		static std::string	log(char*, char*, va_list vars);
};