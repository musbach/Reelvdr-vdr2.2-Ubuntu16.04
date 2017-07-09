#include "version-apt-pkg.h"
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

    bool valid() const {
        return m_cache && dataValid( m_data )
            && type() >= 0 && type() <= 7;
    }

    bool operator==( const Relation &d ) const {
        return d.m_cache == m_cache;
    }

    bool operator<( const Relation &d ) const {
        return false;
    }

    std::string name() const;
    std::string standardFormat() const;
    std::string format() const;
    std::string typeString() const;

    utils::Range< Version > targetList() const;

    utils::Range< Package > targetPackages() const {
        utils::VectorRange< Package > r;
        Atom a = firstAtom();
        while ( a.valid() ) {
            Provides p( *this, a.package() );
            if ( a.package().candidateVersion().valid()
                && cache().state().VS().CheckDep(
                    a.package().candidateVersion().versionString().c_str(),
                    a.compareOperator(), a.targetVersionString().c_str() ) ) {
                utils::Range< Version > vr = a.package().versions();
                r.consume( a.package() );
            }
            while ( !p.isLast() ) {
                if ( p.package().hasVersion() )
                    r.consume( p.package() );
                p.advance();
            }
            a = a.next();
        }
        return uniqueRange( r );
    }

    Type type() const;

    Package ownerPackage() const;

    Version ownerVersion() const {
        return Version( m_cache, packageCache().verPtr( firstAtom().d->ParentVer) );
    }

    Relation straight() const;

    bool isReverse() const {
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
                throw std::bad_cast();
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
        return r;
    }

    bool nextAtomBelongsToGroup( pkgCache::Dependency *d ) const {
        return ((d->CompareOp & pkgCache::Dep::Or) == pkgCache::Dep::Or);
    }

    bool dataValid( pkgCache::Dependency *d ) const {
        return d && d != packageCache().depPtr();
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
