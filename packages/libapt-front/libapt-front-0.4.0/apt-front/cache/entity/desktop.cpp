/**
 * @file cache/entity/desktop.cpp
 * @author Peter Rockai <me@mornfall.net>
 */

#include <apt-front/cache/entity/desktop.h>

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"

namespace tut {
using namespace ::aptFront;
using namespace ::aptFront::cache;

struct cache_entity_desktop_shar {
    cache_entity_desktop_shar() {
        aptInit();
        c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    }
    component::Desktop comp() {
        return c.component< component::Desktop >(); }
    typedef component::Desktop::Entry Entry;
    typedef component::Desktop::EntityRange EntityRange;
    cache::Cache c;
};

TESTGRP( cache_entity_desktop );

template<> template<>
void to::test< 1 >()
{
    c.addComponent( new component::Desktop() );
    comp().loadDirectory( TEST_DIR "/desktop" );
    EntityRange r = comp().entries();
    while ( r != r.end() ) {
        if ( r->name() == "Kdict" || r->name() == "X-Server" ) {
            ensure( r->package().valid() );
        } else {
            ensure( !r->package().valid() );
        }
        r.advance();
    }
}

}

#endif
