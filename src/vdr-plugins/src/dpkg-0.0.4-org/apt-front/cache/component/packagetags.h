/** -*- C++ -*-
 * @file cache/component/packagetags.h
 * @author Enrico Zini (enrico) <enrico@enricozini.org>
 */

/*
 * System tag database
 *
 * Copyright (C) 2003-2006  Enrico Zini <enrico@debian.org>
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

#include <apt-front/cache/component/base.h>
#include <ept/debtags/debtags.h>

#ifndef CACHE_COMPONENT_DEBTAGS_H
#define CACHE_COMPONENT_DEBTAGS_H

namespace aptFront {
namespace cache {
namespace component {

/**
 * Access the Debtags tag database.
 */
struct PackageTags : public Implementation<PackageTags>, public ept::debtags::Debtags
{
//	PackageTags(bool editable = false) : ept::debtags::Debtags(editable) {}
	PackageTags(bool editable = false) : ept::debtags::Debtags() {}
//	PackageTags(bool editable = false) : ept::debtags::Debtags(editable ? "true" : "false") {}
/*	const std::string& EditableT="true";
	const std::string& EditableF="false";
	PackageTags(bool editable = false) : ept::debtags::Debtags(editable ? EditableT : EditableF) {}*/
	static std::string componentName();
};


}
}
}

// vim:set ts=4 sw=4:
#endif
