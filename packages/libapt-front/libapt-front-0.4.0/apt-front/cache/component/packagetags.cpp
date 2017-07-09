/**
 * @file cache/component/packagetags.cpp
 * @author Enrico Zini (enrico) <enrico@enricozini.org>
 */

/*
 * System tag database
 *
 * Copyright (C) 2003-2006  Enrico Zini <enrico@debian.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 */

#include <apt-front/cache/component/packagetags.h>

using namespace std;
using namespace aptFront;
using namespace cache;
using namespace component;

std::string PackageTags::componentName() { return "PackageTags"; }

#include <ept/debtags/debtags.tcc>

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"

namespace tut {

struct cache_component_debtags_shar {
    cache_component_debtags_shar () {
        aptInit ();
        c.open( Cache::OpenDefault |
                Cache::OpenReadOnly );
    }
    Cache c;
};

TESTGRP( cache_component_debtags );

template<> template<>
void to::test<1>()
{
    c.reopen();
}


#if 0

template<> template<>
void to::test<1> ()
{
    /* Get the 'debtags' package */
    entity::Package p = c.packages().packageByName( "debtags" );
    ensure(p.valid());

    /* Get its tags */
    Tagcoll::OpSet<entity::Tag> tags = c.debtags().tagdb().getTags(p);
    ensure(!tags.empty());

    /* Get the items for the tagset of 'debtags' */
    Tagcoll::OpSet<entity::Package> packages = c.debtags().tagdb().getItems(tags);
    ensure(!packages.empty());
    /* They should at least contain 'debtags' */
    ensure(packages.contains(p));

    /* Get one of the tags of 'debtags' */
    entity::Tag tag = *tags.begin();
    ensure(tag);

    /* Get its items */
    {
        /* Need this workaround until I figure out how to tell the new GCC
         * that TagDB is a TDBReadonlyDiskIndex and should behave as such
         */
        Tagcoll::OpSet<entity::Tag> ts;
	ts += tag;
        packages = c.debtags().tagdb().getItems(ts);
    }
    //packages = c.debtags().tagdb().getItems(tag);
    ensure(!packages.empty());
    /* They should at least contain 'debtags' */
    ensure(packages.contains(p));

    //c.debtags().getTags(""); // XXX HACK AWW!
}

template<> template<>
void to::test<2>()
{
}
#endif

}

// vim:set ts=4 sw=4:
#endif
