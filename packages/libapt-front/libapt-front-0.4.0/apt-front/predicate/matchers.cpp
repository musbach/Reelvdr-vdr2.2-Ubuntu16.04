/** -*- C++ -*-
    @file filters.cpp
    @author Peter Rockai <me@mornfall.net>
*/

#include <apt-front/predicate/matchers.h>
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

struct predicate_matchers_shar {
    predicate_matchers_shar () {
        aptInit ();
        c.open( cache::Cache::OpenDefault |
                cache::Cache::OpenReadOnly );
    }
    cache::Cache c;
};

TESTGRP( predicate_matchers );

template<> template<>
void to::test<1> ()
{
    std::list<cache::entity::Package> v;
    std::list<cache::entity::Package>::iterator i;

    Range< entity::Package > r = range( c.packages().packagesBegin(),
               c.packages().packagesEnd() );
    cache::entity::Package p;
    Range< entity::Package > fr = filteredRange(
        r, predicate::Package::name( "exim4-config-2" ) );

    std::copy( fr, fr.end(), back_inserter( v ) );

    for (i = v.begin(); i != v.end(); ++i) {
        ensure_equals( i->name(), "exim4-config-2" );
    }
}

template<> template<>
void to::test<2> ()
{
    std::list<cache::entity::Package> v;
    std::list<cache::entity::Package>::iterator i;
    std::remove_copy_if(
        c.packages().packagesBegin(),
        c.packages().packagesEnd(),
        back_inserter( v ),
        not predicate::Package::description( "exim4" ) );
    for (i = v.begin(); i != v.end(); ++i) {
        ensure_equals( i->name(), "exim4-config" );
    }
}

template<> template<>
void to::test<3> ()
{
    std::set<cache::entity::Package> v;
    std::set<cache::entity::Package>::iterator i;
    std::remove_copy_if(
        c.packages().packagesBegin(),
        c.packages().packagesEnd(),
        inserter( v, v.begin() ),
        not predicate::Package::description( "exim4" ) );
    for (i = v.begin(); i != v.end(); ++i) {
        ensure_equals( i->name(), "exim4-config" );
    }
}

template<> template<>
void to::test<4> ()
{
    Range< entity::Package > r =
        range( c.packages().packagesBegin(),
               c.packages().packagesEnd() );
    cache::entity::Package p;
    Range< entity::Package > fr = filteredRange(
        r, predicate::Package::description( "exim4" ) );
    while (fr != fr.end()) {
        p = *fr;
        ensure_equals( p.name(), "exim4-config" );
        ++fr;
    }
}

template<> template<>
void to::test<5> ()
{
    Range< entity::Package > r = range( c.packages().packagesBegin(),
               c.packages().packagesEnd() );
    cache::entity::Package p;
    Range< entity::Package > fr = filteredRange(
        r, predicate::Package::description( "exim4" ) );
    VectorRange< entity::Package > vr = VectorRange< entity::Package >();
    fr.output( consumer( vr ) );
    ensure( vr.size() > 0 );
    while (vr != vr.end()) {
        p = *vr;
        ensure_equals( p.name(), "exim4-config" );
        ++vr;
    }
}

template<> template<>
void to::test<6> ()
{
    Range< entity::Entity > r =
        upcastRange< entity::Entity >( range( c.packages().packagesBegin(),
               c.packages().packagesEnd() ) );
    cache::entity::Package p;
    Range< entity::Entity > fr = filteredRange(
        r, adapt< entity::Entity >(
            predicate::Package::description( "exim4" ) ) );
    VectorRange< entity::Entity > vr = VectorRange< entity::Entity >();
    fr.output( consumer( vr ) );
    while (vr != vr.end()) {
        p = *vr;
        ensure_equals( p.name(), "exim4-config" );
        ++vr;
    }
}

template<> template<>
void to::test<7> ()
{
    std::list<cache::entity::Package> v;
    std::list<cache::entity::Package>::iterator i;

    Range< entity::Package > r = range( c.packages().packagesBegin(),
               c.packages().packagesEnd() );
    cache::entity::Package p;
    Range< entity::Package > fr = filteredRange(
        r, predicate::Package::maintainer( "enrico@debian.org" ) );

    std::copy( fr, fr.end(), back_inserter( v ) );
    /* c.packages().packages( back_inserter( v ) );
    v.erase( remove_if(
                 v.begin(), v.end(),
                 not predicate::Package::maintainer( "enrico@debian.org" ) ),
                 v.end() ); */
    ensure( !v.empty() );

    std::set<string> allowed;
    allowed.insert("libtagcoll0");
    allowed.insert("log2mail");
    allowed.insert("libdebtags0");
    allowed.insert("libdebtags-dev");
    allowed.insert("tagcoll");
    allowed.insert("debtags");
    allowed.insert("guessnet");
    allowed.insert("buffy");
    allowed.insert("libtagcoll-dev");
    allowed.insert("launchtool");
    allowed.insert("debtags-edit");
    allowed.insert("tagcolledit");

    /* This is left here to allow to recheck the list if the test dataset
     * changes
    fprintf(stderr, "--> %d %d <--\n", v.size(), allowed.size());
    for (i =v.begin(); i != v.end(); ++i)
	    fprintf(stderr, "GOT: %s\n", i->name().c_str());
    */

    ensure_equals( v.size(), allowed.size() );

    for (i = v.begin(); i != v.end(); ++i) {
        ensure( allowed.find(i->name()) != allowed.end() );
    }
}

template<> template<>
void to::test<8>()
{
    /* VectorRange< entity::Package > r;
    c.packages().packages( consumer( r ) );
    entity::Package p = c.packages().packageByName( "debtags" );
    ensure(p.valid());
    Tagcoll::OpSet<entity::Tag> tags = p.tags();
    ensure(!tags.empty());
    Range< entity::Package > x, f = filteredRange(
        range( r ), predicate::Package::tag( tags ) );
    x = std::find( f, f.end(), p );
    ensure_equals( x->name(), "debtags" ); */
}

template<> template<>
void to::test<9> ()
{
    Range< entity::Package > r = range( c.packages().packagesBegin(),
               c.packages().packagesEnd() );
    cache::entity::Package p;
    Range< entity::Package > fr = filteredRange(
        r, predicate::Package::member( &entity::Package::hasVersion ) );
    VectorRange< entity::Package > vr = VectorRange< entity::Package >();
    fr.output( consumer( vr ) );
    ensure( vr.size() > 0 );
}

template<> template<>
void to::test<10> ()
{
    Range< entity::Package > r = range( c.packages().packagesBegin(),
               c.packages().packagesEnd() );
    cache::entity::Package p;
    Range< entity::Package > fr = filteredRange(
        r, predicate::Package::name( "exim4" )
        and predicate::Package::member( &entity::Package::hasVersion ) );
    VectorRange< entity::Package > vr = VectorRange< entity::Package >();
    fr.output( consumer( vr ) );
    ensure( vr.size() > 0 );
    while (vr != vr.end()) {
        p = *vr;
        // test
        ++vr;
    }
}

}

#endif
