/** -*- C++ -*-
    @file cache/cache.cpp
    @author Peter Rockai <me@mornfall.net>
*/

#include <apt-front/cache/cache.h>
#include <apt-front/cache/component/packages.h>
#include <apt-front/cache/component/state.h>
#include <apt-front/cache/component/records.h>
#include <apt-front/utils/paths.h>
#include <apt-front/error.h>

#include <apt-pkg/pkgcachegen.h>
#include <apt-pkg/pkgsystem.h>
#include <apt-pkg/sourcelist.h>

#include <iostream>

using namespace aptFront::cache;

Cache *Global::s_cache = 0;

Cache::Cache ()
    : m_progress( 0 ), m_openFlags( 0 ), m_desiredFlags( 0 ), m_isOpen( false )
{
}

Cache::~Cache ()
{
    close();
}

void Cache::close()
{
    m_isOpen = false;
    // std::cerr << "Cache::close()" << std::endl;
    ComponentMap::iterator i = m_components.begin();
    for (; i != m_components.end(); ++i) {
        deleteComponent( i->second );
    }
    // std::cerr << "Cache::close()d" << std::endl;
    // m_components.clear(); // not good idea really...
    _system->UnLock(true);
    m_desiredFlags = m_openFlags = 0;
}

void Cache::deleteComponent( component::Base *old, bool really )
{
    // std::cerr << "deleteComponent( " << old << " )" << std::endl;
    if (old && old->allowClose()) {
        notifyPreRebuild(old);
        m_components[old->id()] = 0;
        if (really && old->allowDelete())
            delete old;
    }
}

void Cache::notify( component::Base *c,
                    void (cache::Observer::*F)( component::Base * ) )
{
    if (! c)
        return;
    ObserverSet::iterator i = m_observers[c->id()].begin();
    Observer *o;
    for (; i !=  m_observers[c->id()].end(); ++i) {
        o = (*i);
        (o->*F)( c );
    }
}

void Cache::notifyPreRebuild( component::Base *c )
{
    if (! c)
        return;
    ObserverSet::iterator i = m_observers[c->id()].begin();
    for (; i !=  m_observers[c->id()].end(); ++i)
        (*i)->notifyPreRebuild(c);
}

void Cache::notifyPostRebuild( component::Base *c )
{
    if (! c)
        return;
    ObserverSet::iterator i = m_observers[c->id()].begin();
    for (; i !=  m_observers[c->id()].end(); ++i)
        (*i)->notifyPostRebuild(c);
}

component::Packages &Cache::packages() const {
    return component<component::Packages>(); }
component::PackageTags &Cache::debtags() const {
    return component<component::PackageTags>(); }
component::State &Cache::state() const {
    return component<component::State>(); }
component::Records &Cache::records() const {
    return component<component::Records>(); }
ept::debtags::Vocabulary &Cache::tags() const {
    return debtags().vocabulary(); }


void Cache::openState()
{
    if (m_openFlags & OpenState) return; // already opened
    if (not (m_desiredFlags & OpenState)) return; // not wanted

    openPackages(); // required

    component::State *s;
    exception::checkGlobal( exception::Error(
                                "error constructing state cache" ) );
    s = new component::State( this );
    s->Init(&progress());
    exception::checkGlobal( exception::Error(
                                "error initializing state cache" ) );

    m_openFlags |= OpenState;
    addComponent( s );
}

void Cache::openPackages()
{
    if (m_openFlags & OpenPackages) return; // already opened
    if (not (m_desiredFlags & OpenPackages)) return; // not wanted

    bool lock = writeable();
    if (lock)
        if (_system->Lock() == false)
            throw exception::Error( "Could not lock APT database" );
    
    pkgSourceList list;
    if (list.ReadMainList() == false)
        throw exception::Error( "The list of sources could not be read.");
    
    MMap *m = 0;
    bool Res = pkgMakeStatusCache(list,progress(),&m,!lock);
    progress().Done();
    if (!Res)
        throw exception::Error(
            "The package lists or status file could not be parsed or opened." );

    component::Packages *p = new component::Packages( m );
    exception::checkGlobal("Failed building cache");

    m_openFlags |= OpenPackages; // ok, no failures expected
    addComponent( p, AvoidNotify );
    p->preSort();

    notifyPostRebuild( p ); // notifies are called here, so above avoids
                            // a dupe opening ??
}

void Cache::openRecords()
{
    if (m_openFlags & OpenRecords) return; // already opened
    if (not (m_desiredFlags & OpenRecords)) return; // not wanted

    openPackages(); // required

    component::Records *r = new component::Records;
    m_openFlags |= OpenRecords;
    addComponent( r );
}

void Cache::openDebtags()
{
    if (m_openFlags & OpenDebtags) return; // already opened
    if (not ((m_desiredFlags & OpenDebtags)
             || (m_desiredFlags & OpenDebtagsEditable))) return; // not wanted

    openPackages(); // required

    component::PackageTags *t = new component::PackageTags(m_desiredFlags & OpenDebtagsEditable);

    m_openFlags |= OpenDebtags;
    m_openFlags |= m_desiredFlags & OpenDebtagsEditable;
    addComponent( t );
}

void Cache::open( unsigned flags )
{
    m_desiredFlags |= flags;
    m_openFlags |= (flags & OpenReadOnly);
    openPackages();
    openState();
    openRecords();
    openDebtags();
    m_isOpen = true;
}

void Cache::reopen()
{
    unsigned flags = m_desiredFlags;
    close();
    open( flags );
}

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"

namespace tut {

struct cache_shar {
    cache_shar () {
        aptInit ();
    }
    OpProgress progress;
};

TESTGRP( cache );

template<> template<>
void to::test<1>()
{
    Cache c;
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    ensure_equals( c.packages().ownerCache(), &c);
    ensure_equals( c.state().ownerCache(), &c);
}

template<> template<>
void to::test<2>()
{
    Global::get().open( Cache::OpenDefault | Cache::OpenReadOnly );
    Cache &c = Global::get();
    ensure_equals( c.packages().ownerCache(), &c);
    ensure_equals( c.state().ownerCache(), &c);
    Global::get().close();
}


template<> template<>
void to::test<3> ()
{
    Cache c;
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    ensure_equals( c.packages().ownerCache(), &c );
    ensure_equals( c.state().ownerCache(), &c );
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    ensure_equals( c.packages().ownerCache(), &c );
    ensure_equals( c.state().ownerCache(), &c );
}

template<> template<>
void to::test<4> ()
{
    Cache c;
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    ensure( c.isOpen() );
    c.reopen();
    ensure( c.isOpen() );
}


}
#endif
