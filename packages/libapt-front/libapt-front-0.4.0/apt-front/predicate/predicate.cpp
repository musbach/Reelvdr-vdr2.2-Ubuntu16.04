/** -*- C++ -*-
    @file filters.cpp
    @author Peter Rockai <me@mornfall.net>
*/

#include <apt-front/predicate/predicate.h>
using namespace aptFront;

namespace aptFront {
namespace predicate {
// ...
}
}

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"
#include <apt-front/cache/entity/package.h>
#include <apt-front/cache/component/packages.h>
#include <apt-front/cache/cache.h>
#include <apt-front/predicate/combinators.h>
#include <apt-front/predicate/factory.h>
#include <apt-front/utils/range.h>
#include <list>

namespace tut {
using namespace aptFront::utils;
using namespace aptFront::predicate;
using namespace aptFront::cache;

struct predicate_shar {
    predicate_shar () {
        aptInit ();
        c.open( cache::Cache::OpenDefault | cache::Cache::OpenReadOnly );
    }
    cache::Cache c;
};

TESTGRP( predicate );

template<> template<>
void to::test<1>()
{
    Range< entity::Entity > r =
        upcastRange< entity::Entity >( range( c.packages().packagesBegin(),
               c.packages().packagesEnd() ) );
    cache::entity::Package p;
    Range< entity::Entity > fr = filteredRange(
        r, adapt< entity::Entity >(
            predicate::Package::description( "exim4" )
            and predicate::Package::description( "exim4" ) ) );
    VectorRange< entity::Entity > vr = VectorRange< entity::Entity >();
    fr.output( consumer( vr ) );
    while (vr != vr.end()) {
        p = *vr;
        ensure_equals( p.name(), "exim4-config" );
        ++vr;
    }
}
/*
template<> template<>
void to::test<2>()
{
    Predicate< entity::Package > p = predicate::Package::name( "blah" );
    ensure_equals( p.prettyPrint(), "name: \"blah\"" );
    Predicate< entity::Entity > q = adapt< entity::Entity >( p );
    ensure_equals( p.prettyPrint(), "name: \"blah\"" );
    Predicate< entity::Entity > l = q and q;
    And< entity::Entity, Predicate< entity::Entity >,
        Predicate< entity::Entity > > s = l;
    ensure_equals (s.first().prettyPrint(), "name: \"blah\"" );
    ensure_equals (s.second().prettyPrint(), "name: \"blah\"" );
}

template<> template<>
void to::test<3>()
{
    Predicate< entity::Package > p = predicate::Package::description( "blah" );
    ensure_equals( p.prettyPrint(), "description: \"blah\"" );
    Predicate< entity::Entity > q = adapt< entity::Entity >( p );
    ensure_equals( p.prettyPrint(), "description: \"blah\"" );
    Predicate< entity::Entity > l = q and q;
    And< entity::Entity, Predicate< entity::Entity >,
        Predicate< entity::Entity > > s = l;
    ensure_equals (s.first().prettyPrint(), "description: \"blah\"" );
    ensure_equals (s.second().prettyPrint(), "description: \"blah\"" );
}

template<> template<>
void to::test<4>()
{
    Predicate< entity::Package > p = predicate::Package::maintainer( "blah" );
    ensure_equals( p.prettyPrint(), "maintainer: \"blah\"" );
    Predicate< entity::Entity > q = adapt< entity::Entity >( p );
    ensure_equals( p.prettyPrint(), "maintainer: \"blah\"" );
    Predicate< entity::Entity > l = q and q;
    And< entity::Entity, Predicate< entity::Entity >,
        Predicate< entity::Entity > > s = l;
    ensure_equals (s.first().prettyPrint(), "maintainer: \"blah\"" );
    ensure_equals (s.second().prettyPrint(), "maintainer: \"blah\"" );
}

template<> template<>
void to::test<5>()
{
    ArgumentList l;
    l.push_back( Argument( "test!" ) );
    Predicate< entity::Package > p =
        predicate( predicate::Package::maintainer( "" ) )
        or predicate( predicate::Package::name( "" ) ),
        q = predicate::map( p, l, "quick" );
    ensure_equals( q.serialize(),
            "(or (maintainer \"test!\") (name \"test!\"))" );
    ensure_equals( q.prettyPrint(), "quick: \"test!\"" );
}
*/
/* TODO: test if maintainer filter works.  I'm offline atm and I can't access
 * test data */
/*
template<> template<>
void to::test<6>()
{
    Tagcoll::OpSet<entity::Tag> match;
    Predicate< entity::Package > p = predicate::Package::tag( match );
    ensure_equals( p.prettyPrint(), "tags: \"blah\"" );
    Predicate< entity::Entity > q = adapt< entity::Entity >( p );
    ensure_equals( p.prettyPrint(), "tags: \"blah\"" );
    Predicate< entity::Entity > l = q and q;
    And< entity::Entity, Predicate< entity::Entity >,
        Predicate< entity::Entity > > s = l;
    ensure_equals( s.first().prettyPrint(), "tags: \"blah\"" );
    ensure_equals( s.second().prettyPrint(), "tags: \"blah\"" );
}
*/

template<> template<>
void to::test<2>()
{
    predicate::ArgumentList l;
    l.push_back( predicate::Argument( "exim4" ) );
    Predicate< entity::Package > pred = predicate::map(
        predicate::predicate(
            (predicate::predicate(
                predicate::Package::description( "" ) )
             or predicate::predicate(
                 predicate::Package::name( "" ) ) ) ), l );
    Range< entity::Package > fr = filteredRange(
        range( c.packages().packagesBegin(),
               c.packages().packagesEnd() ),
        pred );
    while (fr != fr.end()) {
        entity::Package p = *fr;
        // std::cerr << p.name( "" ) << std::endl;
        ensure( p.name( std::string() ).find( "exim" ) != std::string::npos
                || p.shortDescription( std::string() ).find( "exim" ) != std::string::npos );
        ++fr;
    }
}

template<> template<>
void to::test<3> ()
{
    // FIXME: I put it here just so that it's compiled
    //tagexprMatch< entity::Package >( "" );
    /*
    std::list<cache::entity::Package> v;
    std::list<cache::entity::Package>::iterator i;
    c.packages().packages( back_inserter( v ) );
    v.erase( remove_if(
                 v.begin(), v.end(),
                 not tagexprMatch< entity::Package >( "" ) ),
             v.end() );
    ensure( v.empty() );
    */
}

template<> template<>
void to::test<4>()
{
    match::Substring x( "a" ), y( "b" );
    Predicate< entity::Package > p, q, r, s;
    p = predicate::Package::name( "bla" );
    q = predicate::Package::name( "bla" );
    r = predicate::Package::name( "glah" );
    s = predicate::Package::description( "glah" );
    ensure( !(x == y) );
    ensure( x != y );
    ensure( !(p == s) );
    ensure( !(r == s) );
    ensure( p != s );
    ensure( r != s );
    ensure( p == q );
    ensure( q == p );
    ensure( !(p == r) );
    ensure( p != r );
    ensure( q != r );
    ensure( r != q );
    ensure( p == p );
}

template<> template<>
void to::test<5>()
{
    Predicate< entity::Package > p, q, r, s;
    p = predicate::Package::name( "a" );
    q = predicate::Package::name( "b" );
    r = p or q;
    s = p and q;
    ensure( remove( r, p ) == q );
    ensure( remove( r, q ) == p );
    ensure( remove( s, p ) == q );
    ensure( remove( s, q ) == p );
    s = r and s;
    ensure( remove( s, p ) == (q and q) );
}

template<> template<>
void to::test<6>()
{
    Predicate< entity::Entity > a;
    Predicate< entity::Package > b;
    a = adapt< entity::Entity >( b );
}

}

#endif
