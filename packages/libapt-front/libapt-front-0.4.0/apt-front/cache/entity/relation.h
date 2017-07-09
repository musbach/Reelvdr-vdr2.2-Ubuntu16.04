/** -*- C++ -*-
    @file cache/entity/relation.h
    @author Peter Rockai <me@mornfall.net>
*/

#include <apt-pkg/version.h> // fear and loathing
#include <apt-front/cache/entity/entity.h>
#include <apt-front/cache/component/packages.h>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

#ifndef APTFRONT_CACHE_ENTITY_RELATION_H
#define APTFRONT_CACHE_ENTITY_RELATION_H

namespace aptFront {
namespace cache {
namespace entity {

/**
   @brief Represents relations of a given package with others.

   This is your interface to the package relationships stored within apt's
   cache. This includes dependencies, reverse dependencies, conflicts,
   reverse conflicts. You can get the relevant relation entity ranges using
   the relevant entity::Package accessors.
*/

// template< typename Representation >
class Relation : public Implementation<Relation, Base> {
public:
    enum Type { Dependency = 0, PreDependency = 1, Suggests = 2, Recommends = 3,
                Conflicts = 5, Replaces = 6, Obsoletes = 7 };

    Relation() {}
    Relation( const Entity &i ) {
        initFromBase( i.impl() );
    }

    Relation( Cache *c, pkgCache::Dependency *d )
        : m_data( d )
    {
        setCache( c );
    }

    Relation nextInCache() const {
        Relation r = *this;
        r.m_data = lastAtomInGroup();
        return r;
    }

    /* Interface safety. */
    bool valid() const {
        return m_cache && dataValid( m_data )
            && type() >= 0 && type() <= 7;
    }

    /* entity::Relation functionality. */
    bool operator==( const Relation &d ) const {
        return d.m_cache == m_cache;
    }

    bool operator<( const Relation &d ) const {
        return false; // grr
    }

    /**
       @brief Get a sensible name of the relation.

       This will give you a reasonably useful name of the relation's declaration.
       It does NOT include the type. For a given package/version/type combination,
       this should also be fairly unique. It roughly corresponds how apt-cache
       formats the Depends: et al fields when showing package details.
    */
    std::string name() const;
    std::string standardFormat() const;
    std::string format() const;
    std::string typeString() const;

    /**
       @brief Get list of possible targets for this relation.

       This method will return you a list of all VersionIterator's that are
       fit for satisfying this relation declaration. For depends, this means
       list of packages that would satisfy the dependency (you need to have
       only once of those installed to satisfy it!), for conflicts, this means
       list of all packages conflicting with owner of this relation (you
       need to uninstall all of those to be able to install owner!).
    */
    utils::Range< Version > targetList() const;
    // the above should be implemented using targetPackages()

    utils::Range< Package > targetPackages() const {
        utils::VectorRange< Package > r;
        Atom a = firstAtom();
        while ( a.valid() ) {
            Provides p( *this, a.package() );
            // XXX libapt-pkg foo
            if ( a.package().candidateVersion().valid()
                && cache().state().VS().CheckDep(
                    a.package().candidateVersion().versionString().c_str(),
                    a.compareOperator(), a.targetVersionString().c_str() ) ) {
                utils::Range< Version > vr = a.package().versions();
                r.consume( a.package() );
            }
            while ( !p.isLast() ) {
                /* std::cerr << "looking at providing pkg: "
                   << p.package().name() << std::endl; */
                if ( p.package().hasVersion() )
                    r.consume( p.package() );
                p.advance();
            }
            a = a.next();
        }
        return uniqueRange( r );
    }

    /// Get the type of this relation.
    Type type() const;

    /// Get the owner PackageIterator (that is, the one from which we were obtained).
    Package ownerPackage() const;

    /// Get the owner VersionIterator (that is the one from which we were obtained).
    Version ownerVersion() const {
        return Version( m_cache, packageCache().verPtr( firstAtom().d->ParentVer) );
    }

    /**
       @brief Get a "straight" version of this RelationIterator.
       
       This will return a straight (as opposed to reverse) version of this
       very same iterator. If it was already straight, you will get a copy
       of it. If it was reverse, the straight variant will be looked up in the
       cache and returned.
    */
    Relation straight() const;

    bool isReverse() const { // XXX
        return false;
    }

    component::Packages &component() const { return packageCache(); }
protected:
    pkgCache::Dependency *m_data;

    struct Atom {

        Package package() const {
            if ( !valid() )
                throw std::out_of_range( "past-the-end Atom dereferenced" );
            return Package( component::PackagesPointer(
                                &r.cache().packages(),
                                r.cache().packages().pkgPtr( d->Package ),
                                0 ) );
        }

        bool valid() const {
            return r.dataValid( d );
        }

        Atom next() const {
            if ( !valid() )
                throw std::out_of_range( "past-the-end Atom dereferenced" );
            if ( r.nextAtomBelongsToGroup( d ) )
                return Atom( r, r.nextAtomInCache( d ) );
            return Atom( r, 0 );
        }

        std::string name() const { return package().name(); }
        std::string format() const;

        int compareOperator() const {
            return d->CompareOp;
        }

        std::string targetVersionString() const {
            return std::string( r.cache().packages().strPtr( d->Version ) );
        }

        Atom( const entity::Relation &_r, pkgCache::Dependency *_d )
            : d( _d ), r( _r )
        {}

        Atom &operator=( const Atom &a ) {
            if ( a.r != r )
                throw std::bad_cast(); // XXX
            d = a.d;
            return *this;
        }

        pkgCache::Dependency *d;
        const entity::Relation &r;
    };

    Atom firstAtom() const {
        return Atom( *this, m_data );
    }

    pkgCache::Dependency *nextAtomInCache( pkgCache::Dependency *c ) const {
        pkgCache::Dependency *r = c;
        map_ptrloc off = 0;
        if (isReverse())
            off = r->NextRevDepends;
        else
            off = r->NextDepends;
        r = cache().packages().depPtr( off );
        return r;
        /* if (r->Type == c->Type)
           break;
        if ( !dataValid( r ) )
            return r;
        n&& r->Type == c->Type )
            return r;
        if ( d == ownerVersion().firstDependInCache().firstAtom().d )
        break; */
    }

    pkgCache::Dependency *lastAtomInGroup() const {
        pkgCache::Dependency *r = m_data;
        bool run = true;
        while (run) {
            run = nextAtomBelongsToGroup( r );
            r = nextAtomInCache( r );
            if (not dataValid( r ) )
                run = false;
        }
        // std::cerr << "data valid: " << dataValid( r ) << std::endl;
        return r;
    }

    bool nextAtomBelongsToGroup( pkgCache::Dependency *d ) const {
        return ((d->CompareOp & pkgCache::Dep::Or) == pkgCache::Dep::Or);
    }

    bool dataValid( pkgCache::Dependency *d ) const {
        return d && d != packageCache().depPtr();
        // && d != ownerVersion().firstDependInCache().firstAtom().d ;
    }

    struct Provides {
        enum Type { TVersion, TPackage };

        Provides( const entity::Relation &_r, Version v )
            : p( _r.cache().packages().providesPtr( v.data()->ProvidesList ) ),
              r( _r ), t( TVersion )
        {}

        Provides( const entity::Relation &_r, Package _p )
            : p( _r.cache().packages().providesPtr(
                     _p.pointer().package()->ProvidesList ) ),
              r( _r ), t( TPackage )
        {}

        Provides next() {
            Provides x = *this;
            x.advance();
            return x;
        }

        // XXX argh
        entity::Package package() {
            return Version( &r.cache(),
                            r.cache().packages().verPtr( p->Version ) ).package();
        }

        void advance() {
            p = r.cache().packages().providesPtr(
                t == TVersion ? p->NextPkgProv : p->NextProvides );
        }

        bool isLast() { return p == r.cache().packages().providesPtr(); }
        pkgCache::Provides *p;
        const entity::Relation &r;
        Type t;
    };

};

}
}
}
#endif
