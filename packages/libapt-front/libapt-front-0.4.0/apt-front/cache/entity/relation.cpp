/*
  @file cache/entity/relation.cpp
  @author Peter Rockai <me@mornfall.net>
*/

#include <apt-front/cache/entity/relation.h>

#include <apt-front/error.h>
#include <apt-front/cache/cache.h>
#include <apt-front/cache/entity/version.h>

using namespace aptFront::cache::entity;

Relation::Type Relation::type() const
{
    return static_cast< Type >( firstAtom().d->Type - 1 ); // XXX hack?
}

std::string Relation::typeString() const
{
    const char *t[] = { "required", "pre-required", "suggested", "recommended",
                        "conflict", "replaces", "obsoletes" };
    if ( type() < sizeof( t ) )
        return std::string( t[ type() ] );
    return std::string( "invalid" );
}

std::string Relation::format() const {
    return typeString() + ": " + name();
}

std::string Relation::name() const {
    std::string ret;
    Atom a = firstAtom();
    while ( a.valid() ) {
        ret += a.format();
        if ( a.next().valid() )
            ret += " or ";
        a = a.next();
    }
    return ret;
}

std::string Relation::standardFormat() const {
    std::string ret;
    Atom a = firstAtom();
    while ( a.valid() ) {
        ret += a.format();
        if ( a.next().valid() )
            ret += " | ";
        a = a.next();
    }
    return ret;
}

std::string Relation::Atom::format() const {
    std::string vs;
    switch ( compareOperator() & ~0x10 ) {
    case 0x1: vs += "<="; break;
    case 0x2: vs += ">="; break;
    case 0x3: vs += "<"; break;
    case 0x4: vs += ">"; break;
    case 0x5: vs += "="; break;
    case 0x6: vs += "!="; break;
    }
    if ( vs != "" ) vs = std::string( " " ) + vs + " " + targetVersionString();
    return name() + vs;
}

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"

namespace tut {
using namespace ::aptFront;
using namespace ::aptFront::cache;

struct cache_entity_relation_shar {
    cache_entity_relation_shar() {
        aptInit ();
        c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    }
    cache::Cache c;
    entity::Package a;
    entity::Version v;
    entity::Relation r;
    utils::Range<entity::Relation> rr;
    utils::Range<entity::Version> vr;
    utils::Range<entity::Package> pr;
};

TESTGRP( cache_entity_relation );

template<> template<>
void to::test<1> ()
{
    v = c.packages().packageByName("postfix").candidateVersion();
    rr = v.depends();
    ensure( !rr.empty() );
}

template<> template<>
void to::test<2>()
{
    v = c.packages().packageByName("postfix").candidateVersion();
    rr = v.depends();

    ensure ( !rr.empty() );

    ensure( !rr->targetPackages().empty() );
    ensure_equals( rr->targetPackages()->name(), "libc6" );
    ++ rr;
    ensure_equals( rr->targetPackages()->name(), "libdb4.2" );
    ++ rr;
    ensure_equals( rr->targetPackages()->name(), "libgdbm3" );
    ++ rr;
    pr = rr->targetPackages();
    ensure_equals( pr->name(), "debconf" );
    ++ pr;
    // ensure_equals( pr->name(), "debconf-2.0" );
    // ++ pr;
    ensure( pr == pr.end() );

    ++ rr;
    ensure_equals( rr->targetPackages()->name(), "netbase" );
    ++ rr;
    ensure_equals( rr->targetPackages()->name(), "adduser" );
    ++ rr;
    ensure_equals( rr->targetPackages()->name(), "dpkg" );
    ++ rr;
    ensure_equals( rr->targetPackages()->name(), "debconf" );

    ++rr;
    ensure_equals( rr->targetPackages()->name(), "procmail" );
    ++rr; ++rr; ++rr; ++rr; ++rr; ++rr; // no target versions in there
    ensure_equals( rr->targetPackages()->name(), "resolvconf" );
    ++rr; ++rr; ++rr; ++rr; ++rr; // not here either
    /* ensure_equals( rr->targetPackages()->name(), "postfix-doc" );
       ++rr; ++rr; */
    ++rr; ++rr;
    ensure( rr == rr.end() );

    while ( rr != rr.end() ) {
        if ( !rr->targetPackages().empty() )
            std::cerr << rr->targetPackages()->name() << std::endl;
        else
            std::cerr << "no target packages" << std::endl;
        rr.advance();
    }
    // ++ rr;
    // ensure_equals( rr->targetPackages()->name(), "postfix-mysql" );
}

template<> template<>
void to::test<3>()
{
    v = c.packages().packageByName("postfix").candidateVersion();
    rr = v.depends();

    ensure( !rr->targetPackages().empty() );
    ensure_equals( rr->format(), "required: libc6 >= 2.3.2.ds1-4" );
    ++ rr;
    ensure_equals( rr->format(), "required: libdb4.2" );
    ++ rr;
    ensure_equals( rr->format(), "required: libgdbm3" );
    ++ rr;
    ensure_equals( rr->format(), "required: debconf >= 0.5 or debconf-2.0" );
    ++ rr;
    ensure_equals( rr->format(), "required: netbase" );
    ++ rr;
    ensure_equals( rr->format(), "required: adduser >= 3.48" );
    ++ rr;
    ensure_equals( rr->format(), "required: dpkg >= 1.8.3" );
    ++ rr;
    ensure_equals( rr->format(), "required: debconf" );
    ++ rr;

    ++ rr;
    ensure_equals( rr->format(), "suggested: postfix-mysql" );
}

template<> template<>
void to::test<4>()
{
    v = c.packages().packageByName("postfix").candidateVersion();
    rr = v.depends();
    std::string rels;
    while ( rr != rr.end() ) {
        rels += rr->format() + "\n ";
        rr++; // = rr.next();
    }

    ensure_equals( rels,
                   "required: libc6 >= 2.3.2.ds1-4\n required: libdb4.2\n "
                   "required: libgdbm3\n "
                   "required: debconf >= 0.5 or debconf-2.0\n required: netbase\n "
                   "required: adduser >= 3.48\n required: dpkg >= 1.8.3\n "
                   "required: debconf\n "
                   "suggested: procmail\n "
                   "suggested: postfix-mysql\n suggested: postfix-pgsql\n "
                   "suggested: postfix-ldap\n suggested: postfix-pcre\n "
                   "recommended: mail-reader\n recommended: resolvconf\n "
                   "conflict: mail-transport-agent\n conflict: smail\n "
                   "conflict: libnss-db < 2.2-3\n conflict: postfix-tls < 2.0-0\n "
                   "replaces: postfix-doc < 1.1.7-0\n replaces: postfix-tls\n " );

}

template<> template<>
void to::test< 5 >()
{
    const char *sat[] = { "exim", "exim4", "postfix", "fetchmail" };
    v = c.packages().packageByName( "procmail" ).candidateVersion();
    rr = v.depends();
    rr.advance(); // libc6
    pr = rr->targetPackages(); // exim4 | mail-transport-agent | fetchmail

    int i = 0;
    while ( pr != pr.end() ) {
        ensure_equals( pr->name(), sat[i] );
        // std::cerr << pr->name() << std::endl;
        pr.advance();
        ++i;
    };
    ensure_equals( i, 4 );
}

}

#endif
