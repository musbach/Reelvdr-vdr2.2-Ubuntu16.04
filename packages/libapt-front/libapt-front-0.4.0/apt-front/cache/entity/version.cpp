/**
 * @file cache/entity/version.cpp
 * @author Peter Rockai <me@mornfall.net>
 */
#include <apt-front/cache/entity/version.h>
#include <apt-front/cache/component/state.h>
#include <apt-front/cache/component/packages.h>
#include <apt-front/cache/entity/relation.h>    // for completeRecord
#include <apt-front/utils/cast.h>
#include <iostream>

//#include <apt-pkg/tagfile.h>  /* used only by completeRecord() */


using namespace std;
using namespace aptFront;
using namespace cache;
using namespace entity;



/* Version::operator pkgCache::VerIterator() {
    return pkgCache::VerIterator( packageCache(),m_version );
    } */

void StableVersion::notifyPreRebuild (component::Base *)
{
    m_pkgName = package().name();
    m_pkgVersion = versionString();
}

/*
template< typename T >
VersionT< T >::VersionT< T >(pkgCache::VerIterator V)
{
    component::Packages &pc = downcast<component::Packages>( V.Cache() );
    setCache( pc.ownerCache() );
    m_data = (pkgCache::Version *) V;
    } */

void StableVersion::notifyPostRebuild (component::Base *c)
{
    component::Packages &pc = downcast<component::Packages>(c);
    *this = StableVersion( pc.packageByName(m_pkgName).versionByString( m_pkgVersion ) );
}

static inline void addToHeader(std::string& header, const std::string& name, const std::string& val)
{
	if (header.empty())
		header = "\n" + name + ": " + val;
	else
		header += ", " + val;
}

template< typename T >
std::string VersionT< T >::completeRecord() {
    std::string na = getstring( "not available" );
	std::string depends, predepends, recommends, suggests, conflicts, replaces, obsoletes;
	for (utils::Range<entity::Relation> rr = this->depends(); rr != rr.end(); ++rr)
		switch (rr->type())
		{
			case Relation::Dependency:		addToHeader(depends, "Depends", rr->standardFormat()); break;
			case Relation::PreDependency:	addToHeader(predepends, "Pre-Depends", rr->standardFormat()); break;
			case Relation::Recommends:		addToHeader(recommends, "Recomments", rr->standardFormat()); break;
			case Relation::Suggests:		addToHeader(suggests, "Suggests", rr->standardFormat()); break;
			case Relation::Conflicts:		addToHeader(conflicts, "Conflicts", rr->standardFormat()); break;
			case Relation::Replaces:		addToHeader(replaces, "Replaces", rr->standardFormat()); break;
			case Relation::Obsoletes:		addToHeader(obsoletes, "Obsoletes", rr->standardFormat()); break;
		}
	
	return std::string("Package: ") + package().name() +
        gettext( "\nPriority: not available" ) +
        gettext( "\nSection: " ) + section( na ) +
        gettext( "\nInstalled-Size: " ) + installedSizeString( na ) +
        gettext( "\nMaintainer: " ) + maintainer( na ) +
        gettext( "\nArchitecture: " ) + architecture( na ) +
        gettext( "\nVersion: "  ) + versionString( na ) +
		depends + predepends + recommends + suggests + conflicts + replaces + obsoletes +
        gettext( "\nFilename: " ) + fileName( na ) +
        gettext( "\nSize: not available" ) +
        gettext( "\nMD5Sum: " ) + md5sum( na ) +
        gettext( "\nDescription: " ) + longDescription( na );
}

template class VersionT< pkgCache::Version * > ;


#ifdef COMPILE_TESTSUITE
#include "test-utils.h"
namespace tut {

struct cache_entity_version_shar {
    cache_entity_version_shar () {
        aptInit ();
        c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    }
    Cache c;
    Version a;
};

TESTGRP( cache_entity_version );

template<> template<>
void to::test<1> ()
{
    Version v;
    Entity i (v);
    ensure( Version::instance (i) );
}

template<> template<>
void to::test<2> ()
{
    Package p = c.packages().packageByName( "exim4" );
    utils::Range< entity::Version > _v = p.versions();
    Version v = *_v;
    ensure_equals( v.shortDescription(), "An MTA (Mail Transport Agent)" );
}

template<> template<>
void to::test<3> ()
{
    Package p = c.packages().packageByName( "mail-transport-agent" );
    utils::Range< entity::Version > l = p.versions();
    ensure_equals( p.name(), "mail-transport-agent" );
    ensure( !p.hasVersion() );
    ensure( l.empty() );
}

template<> template<>
void to::test<4> ()
{
    Package p = c.packages().packageByName( "exim4" );
    Package q = c.packages().packageByName( "exim4" );
    Package r = c.packages().packageByName( "exim" );
    Version v = *p.versions();
    Version w = *q.versions();
    Version x = *r.versions();
    ensure( v == w );
    ensure( v != x );
}

template<> template<>
void to::test<5> ()
{
    Package p = c.packages().packageByName( "exim4" );
    utils::Range< entity::Version > l = p.versions(),
                                    v = l,
                                    w = l.end(), x, y = v;
    ++ y;
    if (v != l.end() && w != l.end())
        ensure( *v != *w );
    if (w != l.end() && x != l.end())
        ensure( *w == *x );
    if (w != l.end() && y != l.end())
        ensure( *w == *y );
}

template<> template<>
void to::test<6> ()
{
    Package p = c.packages().packageByName( "exim4" );
    utils::Range< entity::Version > l = p.versions(),
                                    v = l,
                                    w = v;
    ++ w;
    ensure( v != w );
    if (v != l.end() && w != l.end())
        ensure( *v != *w );
    ++ v;
    ensure( v == w );
    if (v != l.end() && w != l.end())
        ensure( *v == *w );
}

template<> template<>
void to::test<7> ()
{
    Package p = c.packages().packageByName( "exim4" );
    utils::Range< entity::Version > l = p.versions();
    Version v = *l;
    ensure( v.package() == p );
}

static void ensure_field ( std::string rec, std::string field, std::string expect ) {
    field += ": ";
    size_t p = rec.find( field );
    ensure( p != string::npos );
    std::string after = rec.substr( p + field.size(), std::string::npos );
    p = after.find( "\n" );
    ensure( p != string::npos );
    // std::cerr << field << after.substr( 0, p ) << std::endl;
    ensure_equals( after.substr( 0, p ), expect );
}

template<> template<>
void to::test<8> ()
// TODO: check for exact field values?
{
    Package pkg = c.packages().packageByName( "exim4" );
    string rec = pkg.candidateVersion().completeRecord();
    string field;
    size_t p;

    ensure_field( rec, "Section", "mail" );
    ensure_field( rec, "Maintainer",
                  "Exim4 Maintainers <pkg-exim4-maintainers@lists.alioth.debian.org>" );
    ensure_field( rec, "Architecture", "all" );
    ensure_field( rec, "Version", "4.34-5" );
    ensure_field( rec, "Description", "An MTA (Mail Transport Agent)" );
    ensure_field( rec, "Installed-Size", "32K" );
    ensure_field( rec, "MD5Sum", "2d34984aff22458f8083f7fe21e391cc" );
    ensure_field( rec, "Filename", "pool/main/e/exim4/exim4_4.34-5_all.deb" );
}

template<> template<>
void to::test<9> ()
{
    Version v = c.packages().packageByName( "exim4" ).candidateVersion();
    ensure_equals( v.installedSize(), 32768 );
    ensure_equals( v.installedSizeString(), "32K" );
    v = c.packages().packageByName( "exim4-base" ).candidateVersion();
    ensure_equals( v.installedSize(), 1264 * 1024 );
    ensure_equals( v.installedSizeString(), "1264K" );
}

}

#endif

// vim:set ts=4 sw=4:
