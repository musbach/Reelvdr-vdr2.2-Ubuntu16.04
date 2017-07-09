/** -*- C++ -*-
 * @file cache/component/packages.h
 * @author Peter Rockai <me@mornfall.net>
 */
#include <apt-pkg/pkgcache.h>
#include <apt-pkg/depcache.h>
#include <apt-front/cache/cache.h>
#include <apt-front/cache/entity/entity.h>
#include <apt-front/cache/entity/package.h>
#include <apt-front/cache/component/base.h>
#include <string>
#include <vector>

#ifndef APTFRONT_CACHE_COMPONENT_PACKAGE_H
#define APTFRONT_CACHE_COMPONENT_PACKAGE_H

class pkgPolicy;

namespace aptFront {

namespace cache {

namespace component {

struct PackagesPointer : entity::Pointer< Packages > {
    long id() const { return m_package->ID; }
    bool valid() const { return entity::Pointer< Packages >::valid() && m_package; }
    PackagesPointer() : m_package( 0 ), m_hashIndex( 0 ) {}

    // internal interface
    pkgCache::Package *package() const {
        return m_package;
    }
    pkgCache::Package *&package() { return m_package; }
    long hashIndex() const { return m_hashIndex; }
    long &hashIndex() { return m_hashIndex; }
    PackagesPointer( Packages *c, pkgCache::Package *p, long h )
        : entity::Pointer< Packages >( c ), m_package( p ), m_hashIndex( h ) {}
private:
    pkgCache::Package *m_package;
    long m_hashIndex;
};

/**
   @brief Interface to the cached mmapped APT database
   
   A libapt-pkg pkgCache with added PackageCache relation.
 
   This subclass only adds a PackageCache pointer to the original pkgCache,
   making it possible to convert pkgCache::PackageIterator's
   to aptFront::PackageIterator's transparently.

   @note In normal libapt-front use you won't need to interact with
   this class at all. [FIXME: we do it all the time with packagesBegin and
   packagesEnd: are we wrong or is the comment wrong?]

   @todo Handle MMap ownership!! (it is leaked currently)

   This class provide the main access point to the collection of packages as a
   whole:
   \code
   // Print a summary of all the package in a format similar to apt-cache
   // search
   for (Packages::iterator i = packages.packagesBegin();
            i != packages.packagesEnd(); i++)
       try {
	   // If the package is virtual or has no installation candidates, then
	   // shortDescription will throw an exception.  We just ignore it in
	   // this case
           cout i->name() << " - " << i->shortDescription() << endl;
       } catch () {}
   \endcode
   @todo add more examples with matchers
 */
class Packages : public pkgCache, public Implementation<Packages> {
public:
    struct PackageData {
        PackageData() : valid(false) {}
        std::string name;
        bool valid:1;
    };

    /* typedef entity::Iterator<entity::Package,
       &entity::Package::nextInCache> iterator; */
    Packages( MMap *Map,bool DoMap = true );
    virtual ~Packages();

    // somewhat friendlier mmap-ed area interface
    const char *strPtr (map_ptrloc offset = 0) const {
        return offset ? StrP + offset : ""; }
    Package *pkgPtr (map_ptrloc offset = 0) const { return PkgP + offset; }
    Version *verPtr (map_ptrloc offset = 0) const { return VerP + offset; }
    Dependency *depPtr (map_ptrloc offset = 0) const { return DepP + offset; }
    VerFile *verFilePtr( map_ptrloc offset = 0 ) const { return VerFileP + offset; }
    Provides *providesPtr( map_ptrloc offset = 0 ) const { return ProvideP + offset; }
    map_ptrloc hashOffset (int idx) const { return HeaderP->HashTable[idx]; }

    typedef utils::Range< entity::Version > VersionRange;
    typedef utils::Range< entity::Relation > RelationRange;
    typedef utils::GeneratedRange< entity::Package,
                                   void(*)( entity::Package & ),
                                   bool(*)( const entity::Package & ) > PackageRange;
    typedef PackageRange iterator;

    VersionRange versions( entity::Package p );
    RelationRange relations( entity::Version v );

    entity::Version currentVersion( entity::Package p );
    entity::Package packageForVersion( entity::Version );

    PackageRange range(); // { return m_range; }

    int hashSize ();

    /// Get the number of packages in the cache
    int packageCount() { return HeaderP->PackageCount; }

    /// Get the name of a package
    std::string packageName( const entity::Package &p ) {
        return std::string( strPtr( p.pointer().package()->Name ) );
        // return packageData( p ).name;
    }

    std::string packageSection( const entity::Package &p ) {
        return std::string( strPtr( p.pointer().package()->Section ) );
    }

    const PackageData &packageData( const entity::Package &p ) {
        PackageData &d = m_data[p.id()];
        if (d.valid)
            return d;
        d.name = strPtr( p.pointer().package()->Name );
        d.valid = true;
        return d;
    }

    /// output all the packages in a cache to a model of OutputIterator
    // template<class I> void packages(I i);

    /// Get an iterator to the first package in the cache
    iterator packagesBegin() {
        return range().begin();
    }
   
    /// Get an (invalid) iterator to the end of the cache
    iterator packagesEnd() {
        return range().end();
    }

    time_t timestamp() const { return m_timestamp; }

    /// return a package of a given name
    entity::Package packageByName( const std::string& name );

    pkgCache &baseReference() { return *this; }
    void preSort();
    utils::Range< entity::Package > sorted() const;

    static std::string componentName();
    static time_t computeTimestamp();

protected:
    // PackageRange m_range;
    std::vector< PackageData > m_data;
    std::set< entity::Package, bool(*)( const entity::Package &,
                                        const entity::Package & ) > m_sorted;
    time_t m_timestamp;
};

}

}
}

#include <apt-front/cache/entity/package.h>

/* namespace aptFront { namespace cache {
template<class I> void component::Packages::packages(I i) {
    entity::Package P = entity::Package( PkgBegin() );
    while (P.valid()) {
        *i++ = P;
        P = P.nextInCache();
    }
}
}} */

#endif
