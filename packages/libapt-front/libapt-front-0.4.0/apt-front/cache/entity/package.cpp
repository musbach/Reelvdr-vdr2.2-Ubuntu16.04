/**
 * @file cache/entity/package.cpp
 * @author Peter Rockai <me@mornfall.net>
 */

#include <apt-front/cache/entity/package.h>

namespace aptFront {

using namespace std;
using namespace cache::entity;

// XXX: idea, only mark the entity as invalid and do the re-lookup
// on first access instead of in notifyPostRebuild?
void StablePackage::notifyPreRebuild( component::Base * )
{
    m_pkgName = name();
}

void StablePackage::notifyPostRebuild( component::Base *c )
{
    component::Packages &pc = downcast<component::Packages>(c);
    *this = StablePackage( pc.packageByName(m_pkgName) );
}

}

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"
#include <apt-front/error.h>
#include <apt-front/cache/cache.h>
#include <apt-front/cache/entity/version.h>

namespace tut {
using namespace ::aptFront;
using namespace ::aptFront::cache;

struct cache_entity_package_shar {
    cache_entity_package_shar() {
        aptInit ();
        c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    }
    cache::Cache c;
    entity::Package a;
};

TESTGRP( cache_entity_package );

template<> template<>
void to::test<1> ()
{
    a = c.packages().packageByName("postfix");
    ensure( a.pointer().package() );
    // ensure (a.pkgPtr());
}

template<> template<>
void to::test<2> ()
{
    a = c.packages().packageByName("postfix");
    // std::cerr << a . name () << std::endl;
    ensure_equals (a.name(), "postfix");
}

template<> template<>
void to::test<3> ()
{
    entity::Package b;
    int check = 1;
    try {
        b.name();
        check = 2;
    } catch ( ... ) { // XXX catch specific exception
        check = 3;
    }
    ensure_equals( check, 3 );
}

template<> template<>
void to::test<4> ()
{
    a = c.packages().packageByName("prelink");
    Entity i, j;
    i = a;
    j = i;
    ensure( i == a );
    ensure( j == a );
    ensure( j == i );
}

#if 0
template<> template<>
void to::test<5> ()
{
    pkgCache::PkgIterator P = c.packages().packageByName("exim4");
    entity::Package i = P;
    ensure( P == i );
    ensure( i.valid() );
    for (int j = 0; j < 1024; j ++) {
        ++ P;
        i = i.nextInCache();
        ensure( i.valid() );
        // std::cerr << "pkg(" << j << "): " << i.name() << " [" << P.Name() << "]" << std::endl;
        ensure( P == i );
    }
}

template<> template<>
void to::test<6> ()
{
    vector<entity::Package> l;
    c.packages().packages(back_inserter( l ));
    pkgCache::PkgIterator P = *l.begin();
    entity::Package i = P;
    ensure( P == i );
    for (int j = 0; j < 1024; j ++) {
        ++ P;
        i = i.nextInCache();
        ensure( P == i );
    }
}
#endif

#if 0
template<> template<>
void to::test<7> ()
{
    vector<entity::Package> l;
    c.packages().packages(back_inserter( l ));
    unsigned int j = 0;
    for (vector<entity::Package>::iterator i
             = l.begin(); i != l.end(); ++i) {
        j ++;
    }
    ensure_equals (j, c.packages().packageCount());
}

template<> template<> 
void to::test<8> ()
{
    vector<entity::Package> l;
    c.packages().packages(back_inserter( l ));
    unsigned int j = 0;
    for (vector<entity::Package>::iterator i
             = l.begin(); i != l.end(); ++i) {
        utils::Range< entity::Version > v = i->versions();
        if ( !v.empty() )
            j ++;
    }

    ensure( j > 0 );
    ensure( j < c.packages().packageCount() );
}
#endif

template<> template<>
void to::test<9> ()
{
    entity::StablePackage P = c.packages().packageByName("postfix");
    entity::Package _P = P;
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    ensure_equals(P.name(), "postfix");
}

template<> template<>
void to::test<10> ()
{
    entity::StablePackage P (&c);
    P = c.packages().packageByName("postfix");
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    ensure_equals(P.name(), "postfix");
}

template<> template<>
void to::test<11> ()
{
    entity::Package P;
    P = c.packages().packageByName("postfix");
    Entity i = P.stable();
    entity::StablePackage Q( i );
    P = i;
    ensure_equals(P.name(), "postfix");
    ensure_equals(Q.name(), "postfix");
    ensure(Q == P);
}

template<> template<>
void to::test<12> ()
{
    entity::Package P;
    P = c.packages().packageByName("postfix");
    entity::StablePackage i( P.stable() );
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    P = i;
    ensure_equals(P.name(), "postfix");
}

template<> template<>
void to::test<13> ()
{
    entity::Package P;
    P = c.packages().packageByName("postfix");
    Entity i = P.stable();
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    entity::StablePackage j( i );
    P = j;
    ensure_equals(P.name(), "postfix");
}

template<> template<>
void to::test<14> ()
{
    entity::Package P;
    P = c.packages().packageByName("postfix");
    Entity i = P.stable();
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    P = i;
    ensure_equals(P.name(), "postfix");
}

template<> template<>
void to::test<15> ()
{
    entity::StablePackage P( &c );
    P = c.packages().packageByName("postfix");
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    entity::Package Q;
    entity::Package R = P;
    Q = c.packages().packageByName( "postfix" );
    ensure( R == Q );
}

template<> template<>
void to::test<16> ()
{
    entity::StablePackage P (&c);
    P = c.packages().packageByName("postfix");
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    entity::Package Q;
    Q = c.packages().packageByName("postfix");
    ensure( P == Q );
}

template<> template<>
void to::test<17> ()
{
    cache::Cache c2;
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    entity::StablePackage P1 (&c);
    entity::StablePackage P2 (&c2);
    P1 = c.packages().packageByName("postfix");
    P2 = P1;
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    entity::Package Q, R;
    Q = c.packages().packageByName("postfix");
    R = P2;
    ensure_equals( R.name(), Q.name() );
    ensure_equals( R.name(), "postfix" );
}

template<> template<>
void to::test<18> ()
{
    int i = 0;
    try {
        a = c.packages().packageByName("postfix");
        i = 1;
        ensure( a.pointer().package() );
        // ensure (a.pkgPtr());
        i = 2;
    } catch ( std::out_of_range ) {
        cerr << "out of bounds!" << endl;
        i = 3;
    /* } catch ( NullPointerError ) {
        cerr << "null pointer!" << endl;
        i = 4; */
    } catch ( std::bad_cast ) {
        cerr << "type error!" << endl;
        i = 5;
    }
    ensure_equals( i, 2 );
}

#if 0
template<> template<>
void to::test<19> ()
{
    Cache *_c = new Cache;
    cache::Global::setCache( _c );
    _c->open( Cache::OpenDefault | Cache::OpenReadOnly );
    a = _c->packages().packageByName("postfix");
    entity::Package p( 0, a.pointer().package() );
    entity::Package q( _c, a.pointer().package() );
    ensure( a == p );
    ensure( a == q );
    ensure( p == q );
    cache::Global::setCache( 0 );
}
#endif

template<> template<>
void to::test<20> ()
{
    a = c.packages().packageByName( "postfix" );
    utils::Range< entity::Version > _v1 = a.versions();
    utils::Range< entity::Version > _v3;
    _v3 = c.packages().packageByName( "exim4" ).versions( /*back_inserter( _v3 )*/ );
    Version v1 = *_v1;
    Version v2 = a.versionByString( v1.versionString() );
    Version v3 = *_v3;
    ensure( v1 == v2 );
    ensure( v1 != v3 );
    ensure( v2 != v3 );
}

template<> template<>
void to::test<21>()
{
    Entity i;
    entity::Package p;
    entity::StablePackage s;
    i = p;
    s = i;
}

template<> template<>
void to::test<22>()
{
    Cache *_c = new Cache;
    cache::Global::setCache( _c );
    _c->open( Cache::OpenDefault | Cache::OpenReadOnly );
    a = _c->packages().packageByName("postfix");
	ensure( a.valid() );
	// If the package is valid, it should not throw
	// FIXME: it actually might, if the component is not there
	//a.tags();

	// Check that the invalid package returns the default tags
	a = Package();
	Tagcoll::OpSet<entity::Tag> defaultts;
	defaultts += entity::Tag();
	Tagcoll::OpSet<entity::Tag> ts = a.tags(defaultts);
	ensure( defaultts == ts );

	// FIXME: what else can I assume about availability of tag data and
	// vocabulary here?  Do we have something already, or should I setup some
	// data for Debtags tests?
}

template<> template<>
void to::test<23>()
{
    entity::Package P = c.packages().packageByName("postfix");
    ensure( P.hasVersion() );
}

template<> template<>
void to::test<24>()
{
    entity::Package p = c.packages().packageByName("postfix");
    entity::Entity e = p;
    ensure( e.is< entity::Named >() );
    ensure( e.is< entity::Package >() );
}

template<> template<>
void to::test<25>()
{
    entity::Package p = c.packages().packageByName("postfix");
    ensure_equals( p.section(), "mail" );
}

}

#endif
// vim:set ts=4 sw=4:
