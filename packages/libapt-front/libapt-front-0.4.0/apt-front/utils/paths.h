// -*- mode: c++; indent-tabs-mode: t -*-
/** \file
 * libdebtags paths
 */

/*
 * Copyright (C) 2005  Enrico Zini <enrico@debian.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <string>

#ifndef APTFRONT_UTILS_PATHS_H
#define APTFRONT_UTILS_PATHS_H

namespace aptFront {
namespace utils {

class Path
{
public:
	static std::string pkgidx();
	static std::string defaultVocabulary();
	static std::string vocabulary();
	static std::string vocabularyIndex();
	static std::string tagdb();
	static std::string tagdbIndex();
	static std::string debtagssources();
	static std::string downloadcache();

	static std::string stateDir();
	static void setStateDir( const std::string &s );
	static void setDebtagsDownloadDir( const std::string &s );
	static void setDebtagsConfigDir( const std::string &s );

	static bool access( const std::string &, int );
	static time_t timestamp( const std::string& );

protected:
	static Path *s_instance;
	static Path &instance();
	std::string m_prefix;
	std::string m_debtagsDownloadDir;
	std::string m_debtagsConfigDir;
	std::string m_debtagsDataDir;
};

}
}

// vim:set ts=4 sw=4:
#endif
