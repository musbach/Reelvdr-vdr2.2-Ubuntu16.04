#include <apt-front/actor.h>
#include <apt-front/init.h>
#include <apt-front/gettext.h>
#include <apt-front/cache/entity/package.h>
#include <apt-front/cache/component/packages.h>
#include <apt-front/cache/component/state.h>

namespace {

using namespace aptFront;
using namespace aptFront::actor;
using namespace aptFront::cache;
using namespace aptFront::utils;

void initactors() {

    typedef entity::Package P;
    typedef actor::Global< P > G_P;
    typedef FromMember< P > FM_P;
    G_P::clear();
    G_P::add( P::unboundInstall() );
    G_P::add( P::unboundUpgrade() );
    G_P::add( P::unboundKeep() );
    G_P::add( P::unboundRemove() );
    G_P::add( P::unboundReInstall() );
    G_P::add( P::unboundPurge() );

    actor::Global<cache::component::State>::add(
        FromMemberUnconditional< cache::component::State >(
            "cache-upgrade", gettext( "Safe Upgrade" ),
            &component::State::upgrade ) );
}

Init actors(initactors);

}

namespace aptFront {
namespace actor {
utils::TypeSet *GlobalData::s_actions = 0;
}
}

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"

namespace tut {

using namespace aptFront::cache::entity;

struct actor_shar {
    actor_shar () {
        aptInit ();
        c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    }
    Cache c;
};
  
TESTGRP(actor);

template<> template<>
void to::test<1>()
{
    int j = 0;
    typedef Actor<entity::Package> PackageActor;
    entity::Package p = c.packages().packageByName( "exim4" );
    Range< PackageActor > r =
        actor::Global< entity::Package >::listPossible( p );
    for (; r != r.end(); ++r) {
        ++ j;
        ensure( r->possible(p) );
    }
    ensure( j > 0 );
}

template<> template<>
void to::test<2>()
{
    int j = 0;
    typedef Actor<entity::Package> PackageActor;
    std::set<cache::entity::Package>::iterator k;
    std::set<cache::entity::Package> v(
        c.packages().packagesBegin(),
        c.packages().packagesEnd());
    for (k = v.begin(); k != v.end() && j < 1024; ++k) {
        Range< PackageActor > r =
            actor::Global< entity::Package >::listPossible( *k );
        bool install = false, remove = false;
        for (; r != r.end(); ++r) {
            ++ j;
            if (r->name() == "package-install" )
                install = true;
            if (r->name() == "package-remove" )
                remove = true;
        }
        if (k->canInstall())
            ensure( install );
        if (k->canRemove())
            ensure( remove );
        if (install) {
            if ( remove ) ensure_equals( k->name(), "" );
            ensure( !remove );
        }
    }
    ensure( j > 0 );
}

template<> template<>
void to::test<3>()
{
    int j = 0, i = 0;
    typedef Actor<entity::Package> PackageActor;
    std::set<cache::entity::Package>::iterator k;
    std::set<cache::entity::Package> v(
        c.packages().packagesBegin(),
        c.packages().packagesEnd() );
    Range< PackageActor > r =
        actor::Global< entity::Package >::list();
    // make a package that can be kept
    c.packages().packageByName( "exim4" ).markInstall();
    for (; r != r.end(); ++r) {
        for ( k = v.begin(); k != v.end(); ++k ) {
            if ( r->possible( *k ) ) {
                ++ j;
                break;
            }
        }
        ++ i;
    }
    ensure_equals( j, i );
}

template<> template<>
void to::test<4>()
{
    Package p = c.packages().packageByName( "exim4" );
    Bound< Package > a = p.install();
    Actor< Package > b = Package::unboundInstall();
    ensure( a.possible() );
    a();
    ensure( p.markedInstall() );
    ensure( a.name() == b.name() );
    ensure( a.prettyName() == b.prettyName() );
}

template<> template<>
void to::test<5>()
{
    Package p = c.packages().packageByName( "exim4" );
    Bound< entity::Entity > a = p.install();
    Actor< entity::Entity > b = Package::unboundInstall();
    ensure( a.possible() );
    a();
    ensure( p.markedInstall() );
    ensure( a.name() == b.name() );
    ensure( a.prettyName() == b.prettyName() );
}

}

#endif
