/**
 * @file cache/component/packages.cpp
 * @author Peter Rockai <me@mornfall.net>
 */
#include <apt-front/cache/component/packages.h>
#include <apt-front/cache/component/state.h>
#include <apt-front/utils/paths.h>
#include <apt-front/error.h>

#include <apt-pkg/strutl.h> // for stringcasecmp
#include <apt-pkg/configuration.h> // for _config

using namespace aptFront;
using namespace cache;
using namespace component;

string Packages::componentName() { return "Packages"; }

time_t Packages::computeTimestamp()
{
    return utils::Path::timestamp(_config->FindFile( "Dir::Cache::pkgcache" ));
}

int Packages::hashSize ()
{
    return sizeof (HeaderP->HashTable) / sizeof (HeaderP->HashTable[0]);
}

entity::Package Packages::packageByName( const std::string& n ) {
    const char *Name = n.c_str();
    Package *Pkg = PkgP + HeaderP->HashTable[Hash(Name)];
    for (; Pkg != PkgP; Pkg = PkgP + Pkg->NextPackage)
    {
        if (Pkg->Name != 0 && StrP[Pkg->Name] == Name[0] &&
            ::stringcasecmp(Name,StrP + Pkg->Name) == 0)
            return entity::Package( PackagesPointer( this, Pkg, 0 ) );
    }
    return entity::Package();
    // return entity::Package( PackagesPointer( this, i.operator->(), 0 ) );
}

/* List<PackageIterator> PackageCache::packageList() {
    return List<PackageIterator>( PackageIterator( PkgBegin() ) );
    } */

Packages::VersionRange Packages::versions( entity::Package p ) {
    utils::VectorRange< entity::Version > r;
    Version *_v = verPtr( p.pointer().package()->VersionList );
    entity::Version v( &cache(), _v );
    while ( v.valid() ) {
        r.consume( v );
        v = v.nextInCache();
    }
    return r;
}


component::Packages::~Packages()
{
    delete &Map;
}

template< typename T >
bool lessByName( const T &e1, const T &e2 )
{
    return e1.name() < e2.name();
}

component::Packages::Packages( MMap *Map, bool DoMap )
    : pkgCache( Map, DoMap ), m_sorted( lessByName< entity::Package > )
{
    m_timestamp = computeTimestamp();
    // m_data.resize( packageCount() );
}

static void advancePackageInCache( entity::Package &p )
{
    p.checkValid();

    // Follow the current links
    if ( p.pointer().package() != p.component().pkgPtr() )
        p.pointer().package() = p.component().pkgPtr(
            p.pointer().package()->NextPackage );
        /* p = entity::Package( PackagePointer( &p.component(),
                                             p.pointer().package()->NextPackage,
                                             p.hashIndex() ) ); */
        // if (m_package != packageCache().pkgPtr())
        // p.m_package = packageCache().pkgPtr(m_package->NextPackage);

    // Follow the hash table
    while ( p.pointer().package() == p.component().pkgPtr()
           && (p.pointer().hashIndex() + 1 ) < p.component().hashSize() )
    {
        p.pointer().hashIndex()++;
        p.pointer().package() = p.component().pkgPtr(
            p.component().hashOffset( p.pointer().hashIndex() ) );
    }

    // we would wrap around, put out an invalid entity
    if (p.pointer().package() == p.component().pkgPtr() )
        p = entity::Package(); 
}

static bool lastPackageInCache( const entity::Package &p ) {
    return p == entity::Package();
}

Packages::PackageRange Packages::range() {
    entity::Package f( PackagesPointer( this, pkgPtr(), -1 ) );
    advancePackageInCache( f );
    return generatedRange( f, advancePackageInCache, lastPackageInCache );
}

entity::Version Packages::currentVersion( entity::Package p ) {
    return entity::Version( &cache(), verPtr( p.pointer().package()->CurrentVer ) );
}

entity::Package Packages::packageForVersion( entity::Version v ) {
    return entity::Package( PackagesPointer( this, pkgPtr( v.data()->ParentPkg ), 0 ) );
    // return Version( &cache(), p.pointer().package()->CurrentVersion );
}

void component::Packages::preSort() {
    ownerCache()->progress().OverallProgress(
        0, packageCount(), 100, gettext( "Sorting" ) );
    int done = 0;
    for ( iterator i = packagesBegin(); i != packagesEnd(); ++i ) {
        done ++;
        m_sorted.insert( m_sorted.begin(), *i );
        if ( done % 100 == 0 )
            ownerCache()->progress().Progress( done );
    }
    ownerCache()->progress().Done();
}

utils::Range< entity::Package > component::Packages::sorted() const
{
    return utils::range( m_sorted.begin(), m_sorted.end() );
}

#ifdef COMPILE_TESTSUITE
#include <apt-pkg/progress.h>
#include "test-utils.h"

namespace tut {

struct cache_component_packages_shar {
    cache_component_packages_shar () {
        aptInit ();
        c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    }
    cache::Cache c;
    OpProgress progress;
};
TESTGRP( cache_component_packages );

template<> template<>
void to::test<1> ()
{
    /* cf.Open( progress, false );
    _error->DumpErrors();
    // std::cerr << std::endl << "package count: " << cf . pkgCache () -> HeaderP -> PackageCount;
    ensure_equals( cf.packageCache()->packageCount(), 19113 ); */
}

template<> template<>
void to::test<2> ()
{
    std::set<cache::entity::Package> v;
    std::set<cache::entity::Package>::iterator i;
    // c.packageCache().packages( inserter( v, v.begin() ) );
    /* std::copy( c.packageCache().packagesBegin(),
               c.packageCache().packagesEnd(),
               inserter( v, v.begin() )); */
    component::Packages::iterator j;
    int x = 0;
    for (j = c.packages().packagesBegin();
         j != c.packages().packagesEnd();
         ++ j) {
        /* if (x == 0 || x > 19100) {
            std::cerr << "pkg(" << x << "): ";
            std::cerr << j->name() << std::endl;
            } */
        ensure( x <= c.packages().packageCount() );
        ++ x;
    }
    // std::cerr << "x = " << x << ", count = " << c.packageCache().packageCount() << std::endl;
    ensure_equals( x, c.packages().packageCount() );
    /* filter::erase_if( 
        v, filter::Description<cache::entity::Package>(
        "exim4" )); */
    /* for (i = v.begin(); i != v.end(); ++i) {
        ensure_equals( i->name(), "exim4-config" );
        } */
}

template<> template<>
void to::test<3> ()
{
    std::set<cache::entity::Package>::iterator i;
    std::set<cache::entity::Package> v(
        c.packages().packagesBegin(),
        c.packages().packagesEnd());
    int x = 0;
    for (i = v.begin(); i != v.end(); ++ i) {
        ensure( x <= c.packages().packageCount() );
        ++x;
    }
    ensure_equals( x, c.packages().packageCount() );
}

template<> template<>
void to::test<4> ()
{
    entity::Package p = c.packages().packageByName( "purring-foo" );
    ensure( p == entity::Package() );
}

}
#endif
