/**
   @file cache/component/state.cpp
   @author Peter Rockai <me@mornfall.net>
*/

#include <apt-front/cache/component/state.h>
#include <apt-front/cache/entity/version.h>
#include <apt-front/error.h>
#include <iostream>

using namespace aptFront::cache;
using namespace aptFront::cache::entity;
using namespace aptFront;
using namespace aptFront::cache::component;

string State::componentName() { return "State"; }

bool State::isInstalled( const entity::Package &P )
{
    if ( P.pointer().package()->CurrentState
         == pkgCache::State::ConfigFiles) return false;
    if ( P.pointer().package()->CurrentState
         == pkgCache::State::NotInstalled) return false;
    return true;
}

Package::State State::packageState( const entity::Package &P )
{
    entity::Package::State s = 0;
    if (isInstalled (P))
        s |= entity::Package::State::Installed;
    if (isInstalled( P ) && P.candidateVersion() != P.installedVersion())
        s |= entity::Package::State::Upgradable;
    pkgDepCache::StateCache S = operator[]( P );
    if (S.Install())
        s |= entity::Package::State::Install;
    if ( ( S.iFlags & pkgDepCache::ReInstall ) == pkgDepCache::ReInstall )
        s |= entity::Package::State::ReInstall;
    if (S.Keep())
        s |= entity::Package::State::Keep;
    if (S.Delete())
        s |= entity::Package::State::Remove;
    if ( ( S.iFlags & pkgDepCache::Purge ) == pkgDepCache::Purge )
        s |= entity::Package::State::Purge;
    if (S.NowBroken())
        s |= entity::Package::State::NowBroken;
    if (S.InstBroken())
        s |= entity::Package::State::WillBreak;
    return s;
}

State::State( const State &s )
    : pkgDepCache( s ), Implementation<State>( s ), m_policy( s.m_policy )
{
    Cache = s.Cache;
    if ( Cache ) {
        // std::cerr << "deep-copying State!" << std::endl;
        // std::cerr << "Cache = " << Cache << std::endl;
        PkgState = new StateCache[Head().PackageCount];
        DepState = new unsigned char[Head().DependsCount];
        std::copy( s.PkgState, s.PkgState+
                   Head().PackageCount, PkgState );
        std::copy( s.DepState, s.DepState+
                   Head().DependsCount, DepState );
        LocalPolicy = &policy();
        delLocalPolicy = 0;
    }
}

void State::action( entity::Package p, Action a, bool notify ) {
    if ( notify )
        notifyPreChange();
    pkgProblemResolver fix( &baseReference() );
    if ( a == AInstall || a == AReInstall ) {
        // std::cerr << "marking for install: " << p.name() << std::endl;
        fix.Clear( p );
        fix.Protect( p );
        MarkInstall( p, true );
        fix.InstallProtect();
        if ( a == AReInstall )
            SetReInstall( p, true );
    } else if ( a == ARemove || a == APurge ) {
        // std::cerr << "marking for removal: " << p.name() << std::endl;
        fix.Clear( p );
        fix.Protect( p );
        fix.Remove( p );
        MarkDelete( p, a == APurge ? true : false );
    } else if ( a == AKeep ) {
        // std::cerr << "marking for keeping: " << p.name() << std::endl;
        fix.Clear( p );
        fix.Protect( p );
        MarkKeep( p, true );
    }
    fix.Resolve( true );
    if ( notify )
        notifyPostChange();
}

void State::revert() {
    Packages::iterator it;
    for ( it = ownerCache()->packages().packagesBegin();
          it != ownerCache()->packages().packagesEnd(); ++ it ) {
        if ( ( !it->markedKeep() ) || it->markedPurge() ) {
            pkgDepCache::StateCache &S = operator[]( *it );
            MarkKeep( *it );
            S.iFlags &= ~pkgDepCache::Purge;
            S.iFlags &= ~pkgDepCache::ReInstall;
        }
    }
}

void State::replay( RequestList l ) {
    notifyPreChange();
    while ( l != l.end() ) {
        action( l->first, l->second, false );
        l.advance();
    }
    notifyPostChange();
}

State::State (cache::Cache *cache)
    : pkgDepCache (&( cache->packages().baseReference() ), 0),
      m_policy( cache )
{
    delete delLocalPolicy;
    delLocalPolicy = 0;
    LocalPolicy = &policy();
    exception::checkGlobal( "error constructing package policy" );
    if (ReadPinFile(policy()) == false)
        throw exception::Error( "error reading pin file" );
}

State::~State ()
{
}

void State::updateCounts() {
    Packages::iterator i;
    m_availableCount = m_removeCount = m_newInstallCount = m_upgradeCount
                     = m_installedCount = m_upgradableCount = m_reInstallCount = 0;
    for (i = ownerCache()->packages().packagesBegin();
         i != ownerCache()->packages().packagesEnd();
         ++ i) {
        if (i->hasVersion())
            ++ m_availableCount;
        if (i->isUpgradable())
            ++ m_upgradableCount;
        if (i->isInstalled())
            ++ m_installedCount;
        if (i->markedNewInstall())
            ++ m_newInstallCount;
        if (i->markedRemove())
            ++ m_removeCount;
        if (i->markedUpgrade())
            ++ m_upgradeCount;
        if (i->markedReInstall())
            ++ m_reInstallCount;
    }
}

bool State::changed() {
    return (removeCount() || newInstallCount() || upgradeCount() || reInstallCount());
}

void State::notifyPostChange() {
    updateCounts();
    Implementation<State>::notifyPostChange();
}

std::string State::sizeString( double d )
{
    const char *post = "BKMG";
    while ( std::fabs( d ) > 4096 && post[0] != 'G' )
        (d /= 1024), (++post);
    std::ostringstream s;
    d = (d - std::floor( d ) > 0.5) ? std::ceil( d ) : std::floor( d );
    s << int( d ) << post[0];
    return s.str();
}

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"

namespace tut {

struct cache_component_state_shar {
    cache_component_state_shar() {
        aptInit();
        c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    }
    Cache c;
};

TESTGRP( cache_component_state );

template<> template<>
void to::test<1>()
{
    State *s1 = &c.state();
    State *s2 = new State( *s1 );
}

template<> template<>
void to::test<2>()
{
    entity::Package gcide = c.packages().packageByName("dict-gcide"),
                    dictd = c.packages().packageByName("dictd");
    ensure( dictd.isInstalled() );
    ensure( gcide.isInstalled() );
    dictd.markRemove();
    ensure( dictd.markedRemove() );
    ensure( gcide.markedRemove() );
}

template<> template<>
void to::test<3>()
{
    entity::Package gcide = c.packages().packageByName("dict-gcide"),
                    dictd = c.packages().packageByName("dictd");
    ensure( dictd.isInstalled() );
    ensure( gcide.isInstalled() );
    dictd.markRemove();
    ensure( dictd.markedRemove() );
    ensure( gcide.markedRemove() );
    gcide.markKeep();
    ensure( gcide.markedKeep() );
    ensure( dictd.markedKeep() );
}

template<> template<>
void to::test<4>()
{
    entity::Package gcide = c.packages().packageByName("dict-gcide"),
                    dictd = c.packages().packageByName("dictd");
    ensure( dictd.isInstalled() );
    ensure( gcide.isInstalled() );
    dictd.markPurge();
    ensure( gcide.markedRemove() );
    ensure( dictd.markedPurge() );
}

template<> template<>
void to::test<5>()
{
    entity::Package dictd = c.packages().packageByName("dictd");
    ensure( dictd.isInstalled() );
    dictd.markReInstall();
    ensure( dictd.markedReInstall() );
}

template<> template<>
void to::test<6>()
{
    ensure_equals( State::sizeString( 8192 ), "8K" );
    ensure_equals( State::sizeString( -8192 ), "-8K" );
    ensure_equals( State::sizeString( 8192 * 1024 ), "8M" );
    ensure_equals( State::sizeString( 8192.0 * 1024 * 1024 ), "8G" );
    ensure_equals( State::sizeString( 8192.0 * 1024 * 1024 * 1024 ), "8192G" );
    ensure_equals( State::sizeString( -8192 * 1024 ), "-8M" );
    ensure_equals( State::sizeString( -(8192 + 700) * 1024  ), "-9M" );
    ensure_equals( State::sizeString( -(8192 + 300) * 1024  ), "-8M" );
}

}

#endif
