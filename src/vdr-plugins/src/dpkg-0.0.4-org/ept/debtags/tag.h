// -*- mode: c++; tab-width: 4; indent-tabs-mode: t -*-
/* @file
 * @author Enrico Zini (enrico) <enrico@enricozini.org>
 */

/*
 * libpkg Debtags data provider
 *
 * Copyright (C) 2003-2007  Enrico Zini <enrico@debian.org>
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

#ifndef EPT_DEBTAGS_DEBTAGS_H
#define EPT_DEBTAGS_DEBTAGS_H

#include <ept/debtags/coll/fast.h>
#include <string>

namespace ept {
namespace debtags {

/**
 * Access the on-disk Debtags tag database.
 *
 * The database is normally found in /var/lib/debtags.
 *
 * Tags and Facets are returned as std::strings.  The objects follow
 * the flyweight pattern and access the data contained in the Vocabulary
 * instantiated inside Debtags.
 *
 * It is possible to get a reference to the Vocabulary object using the
 * vocabulary() method.
 */
class Debtags : public coll::Fast
{
protected:
	// User rc directory to store patches
	std::string rcdir;

	// Last modification timestamp of the index
	time_t m_timestamp;

    void load(const std::string& pathname);

public:
    typedef ept::debtags::coll::Fast coll_type;
    typedef std::pair< std::string, std::set<std::string> > value_type;

    /// Create a Debtags object, reading the system database
    Debtags();
    /// Create a Debtags object, reading the given database file
//    Debtags(const std::string& pathname);
    ~Debtags() {}

	/// Get the timestamp of when the index was last updated
	time_t timestamp() const { return m_timestamp; }

	/// Return true if this data source has data, false if it's empty
	bool hasData() const { return m_timestamp != 0; }

	coll_type& tagdb() { return *this; }
	const coll_type& tagdb() const { return *this; }

    /**
     * Return the default pathname for the debtags tags.
     *
     * This returns /var/lib/debtags/package-tags, unless it has been
     * overridden by setting $DEBTAGS_TAGS
     */
    static std::string pathname();
};

}
}

// vim:set ts=4 sw=4:
#endif
