// -*- mode: c++; indent-tabs-mode: t -*-

/** \file
 * libdebtags paths
 */
 
/*
 * Copyright (C) 2005  Enrico Zini <enrico@debian.org>, Peter Rockai <me@mornfall.net>
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

#include <unistd.h>		// access
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "config.h"
#include <apt-front/utils/paths.h>
#include <apt-front/utils/paths.cpp.h>
#include <apt-front/updater.h>
#include <wibble/exception.h>

using namespace aptFront;
using namespace utils;

Path &Path::instance() {
	if (!s_instance) {
		s_instance = new Path;
		instance().m_prefix = DEBTAGS_DB_DIR;
		instance().m_debtagsDownloadDir = DEBTAGSDOWNLOADDIR;
		instance().m_debtagsConfigDir = DEBTAGSCONFIGDIR;
		instance().m_debtagsDataDir = DEBTAGSDATADIR;
	}
	return *s_instance;
}

bool Path::access( const std::string &s, int m ) {
	return ::access( s.c_str(), m ) != -1;
}

time_t Path::timestamp( const std::string& file ) {
	struct stat st;
	if (stat(file.c_str(), &st) == -1)
		if (errno == ENOENT)
			return 0;
		else
			throw wibble::exception::System("getting file informations for " + file);
	else
		return st.st_mtime;
}

static std::string newer(const std::string& filea, const std::string& fileb)
{
	if (Path::timestamp(filea) < Path::timestamp(fileb))
		return fileb;
	return filea;
}

void Path::setStateDir( const std::string &s ) {
	instance().m_prefix = s;
}

void Path::setDebtagsDownloadDir( const std::string &s ) {
	instance().m_debtagsDownloadDir = s;
}

void Path::setDebtagsConfigDir( const std::string &s ) {
	instance().m_debtagsConfigDir = s;
}

std::string Path::stateDir() {
	return instance().m_prefix;
}

std::string Path::pkgidx() {
	return newer(Updater::rcdir() + "/pkgidx.idx", stateDir() + "/pkgidx.idx");
}

std::string Path::defaultVocabulary() {
	return instance().m_debtagsDataDir + "/vocabulary";
}

std::string Path::vocabulary() {
	return newer(Updater::rcdir() + "/vocabulary", stateDir() + "/vocabulary");
}

std::string Path::vocabularyIndex() {
	return newer(Updater::rcdir() + "/vocabulary.idx", stateDir() + "/vocabulary.idx");
}

std::string Path::tagdb() {
	return newer(Updater::rcdir() + "/package-tags", stateDir() + "/package-tags");
}

std::string Path::tagdbIndex() {
	return newer(Updater::rcdir() + "/package-tags.idx", stateDir() + "/package-tags.idx");
}

std::string Path::debtagssources() {
	return instance().m_debtagsConfigDir + "/sources.list";
}

std::string Path::downloadcache() {
	return instance().m_debtagsDownloadDir;
}

Path *Path::s_instance = 0;

// vim:set ts=4 sw=4:
