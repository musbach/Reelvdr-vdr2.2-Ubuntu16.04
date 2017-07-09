/** -*- C++ -*-
 * @file cache/entity/package.h
 * @author Peter Rockai <me@mornfall.net>
 */

#include <apt-pkg/pkgcache.h>

#include <apt-front/forward.h>
#include <apt-front/gettext.h>
#include <apt-front/utils/range.h>
#include <apt-front/cache/entity/entity.h>
// satellit hack
//#include <ept/debtags/tag.h>
#include <ept/debtags/debtags.h>
#include <taglib/tag.h>
#include <string>
#include <set>
#include <stdexcept>

#ifndef APTFRONT_CACHE_ENTITY_PACKAGE_H
#define APTFRONT_CACHE_ENTITY_PACKAGE_H

namespace aptFront {

namespace cache {
namespace entity {

// eventually s/Default/Fallback/, hmm?
template< typename T >
struct DefaultArgument {
    const T *value;
    bool valid:1;
    DefaultArgument( const T &v )
        : value( &v ), valid( true ) {}
    DefaultArgument()
        : value( 0 ), valid( false ) {}
    template< typename E > T get( E e ) {
        if (valid)
            return *value;
        throw e;
    }
};

struct Named {
    typedef DefaultArgument< std::string > DefaultString;
    virtual std::string name( DefaultString d = DefaultString() ) const = 0;
    virtual ~Named() {}
};

/**
   @brief The standard interface to interact with packages in cache.

   PackageIterator is one of the central classes to libapt-front. You will
   come into contact with it on every corner. It allows you to query cache
   for data about packages, it allows you to mark packages for
   (un)installation, gives you access to VersionIterator's associated
   with individual available package versions and so on. 

   The class is intended to be used as a regular by-value class, since its
   data part is fairly small and copy overhead is negligible this should be
   fairly ok in most cases. Use const references if you need to get few
   cycles more out of it.
*/
template< typename _Pointer >
struct PackageT : public Implementation<PackageT< _Pointer > >, public Named
{
    typedef _Pointer Pointer;
    typedef typename Pointer::Component Component;

    struct State {
        enum Query {
            Install = 1 << 0,
            Upgrade = 1 << 1,
            Keep = 1 << 2,
            Remove = 1 << 3,
            Installed = 1 << 4,
            Upgradable = 1 << 5,
            NowBroken = 1 << 6,
            WillBreak = 1 << 7,
            ReInstall = 1 << 8,
            Purge = 1 << 9
        };

        typedef unsigned state;

        operator unsigned() { return m_state; };

        State &operator=( unsigned i ) {
            m_state = i;
            return *this;
        }

        State &operator|=( const State &s ) {
            m_state |= s.m_state;
            return *this;
        }

        State( unsigned a ) {
            m_state = a;
        }

        State() : m_state( 0 ) {}

    protected:
        unsigned m_state;
    };

    typedef actor::Actor< PackageT > Actor;
    typedef actor::Bound< PackageT > BoundActor;

    PackageT( Pointer p )
        : m_pointer( p )
    {}

    PackageT() {}
    ~PackageT() {}

    PackageT( const Entity &i ) {
        this->initFromBase( i.impl() );
    }

    /* pkgCache::PkgIterator conversion */
    PackageT( pkgCache::PkgIterator P );
    operator pkgCache::PkgIterator() const;

    virtual Entity stable() const;

    virtual bool valid() const {
        return pointer().valid();
    }

    /* Package functionality */
    bool operator ==( const PackageT &p ) const {
        if (!p.valid() || !valid())
            return p.valid() == valid();
        return ( p.id() == id() && ( &p.cache() ) == ( &cache() ) );
    }

    bool operator <( const PackageT &p ) const {
        if (valid()) {
            if (p.valid())
                return id() < p.id(); // name() < p.name();
            else
                return false;
        } else 
            return p.valid() != valid();
    }

    State state( DefaultArgument< State > = DefaultArgument< State >() ) const;

    bool markedInstall() const { return (state() & State::Install)
            || markedReInstall(); }
    bool markedUpgrade() const { return markedInstall() && isUpgradable(); }
    bool markedNewInstall() const { return markedInstall() && !isUpgradable()
            && !markedReInstall(); }
    bool markedReInstall() const { return state() & State::ReInstall; }
    bool markedKeep() const { return state() & State::Keep; }
    bool markedRemove() const { return state() & State::Remove; }
    bool markedPurge() const { return state() & State::Purge; }
    
    bool isInstalled() const { return state() & State::Installed; }
    bool isUpgradable() const { return state() & State::Upgradable; }
    bool isBroken() const { return state() & State::NowBroken; }
    bool willBreak() const { return state() & State::WillBreak; }

    bool canInstall() const {
        return ((! isInstalled()) && ! markedInstall()) || markedRemove()
            || isBroken(); }
    bool canRemove() const { return isInstalled() && not markedRemove(); }
    bool canKeep() const {
        return markedUpgrade() || markedRemove() || markedInstall(); }
    bool canUpgrade() const { return isUpgradable () && ! markedUpgrade (); }
    bool canReInstall() const { return isInstalled() && !isUpgradable()
            && !markedReInstall(); }
    bool canRevertInstall() const { return markedNewInstall(); }

    utils::Range< Version > versions() const;
    utils::Range< Relation > depends() const;

    Version anyVersion() const;
    bool hasVersion() const;
    Version versionByString( const std::string& ver ) const;

    exception::InternalError getterError( std::string f ) const {
        return exception::InternalError(
            std::string( "Error calling entity::Package::" ) + f
            + ", the data is not available" );
    }

    std::string shortDescription( DefaultString = DefaultString() ) const;
    std::string longDescription( DefaultString = DefaultString() ) const;
    std::string statusString( DefaultString = DefaultString() ) const;
    std::string actionString( DefaultString = DefaultString() ) const;
    std::string name( DefaultString = DefaultString() ) const;
    std::string md5sum( DefaultString = DefaultString() ) const;
    std::string fileName( DefaultString = DefaultString() ) const;
    std::string source( DefaultString = DefaultString() ) const;

    std::string section( DefaultString = DefaultString() ) const;
    std::string maintainer( DefaultString = DefaultString() ) const;
    std::string architecture( DefaultString = DefaultString() ) const;

    inline unsigned short id() const {
        this->checkValid();
        return pointer().id();
    }

    /**
     * Return the Debtags tags attached to this package
     */
    typedef std::set<ept::debtags::Tag> TagSet;
    TagSet tags( DefaultArgument< TagSet > = DefaultArgument< TagSet >() ) const;

    Version installedVersion() const;
    Version candidateVersion() const;

    // marking intefrace
    void markInstall();
    void markRemove();
    void markKeep();
    void markReInstall();
    void markPurge();

    BoundActor install() const;
    BoundActor remove() const;
    BoundActor keep() const;
    BoundActor upgrade() const;
    BoundActor purge() const;
    BoundActor reInstall() const;

    static Actor unboundInstall();
    static Actor unboundRemove();
    static Actor unboundKeep();
    static Actor unboundUpgrade();
    static Actor unboundPurge();
    static Actor unboundReInstall();

    Pointer &pointer() { return m_pointer; }
    const Pointer &pointer() const { return m_pointer; }
    Component &component() const { return pointer().component(); }
    Cache &cache() const { return pointer().cache(); }
protected:
    typedef actor::FromMember< PackageT > ActorFM;
    Pointer m_pointer;
};

}
}
}

#include <apt-front/cache/component/packages.h>
#include <apt-front/cache/component/state.h>
#include <apt-front/cache/component/packagetags.h>
#include <apt-front/cache/entity/version.h>
#include <apt-front/actor.h>

namespace aptFront {

namespace cache {
namespace entity {

/**
   @brief Stable variant of PackageIterator (invariant to cache reloads).

   This class acts exactly like PackageIterator, apart from the fact it
   will survive cache reloads and/or updates without harm (unless the package
   disappeared from archive in which case it will become invalid (past the
   end) iterator.
*/
class StablePackage : public Implementation<StablePackage, Package>, public Observer {
public:
    StablePackage( const Package &p ) {
        Package::initFromBase( &p );
        if ( &Package::component() )
            setCache( &Package::cache() );
        else
            setCache( 0 );
        observeComponent<component::Packages>();
    }
    StablePackage( Cache *c = 0 ) : Observer (c) {
        setCache( c );
        observeComponent<component::Packages>();
    }
    StablePackage( const Entity &i ) {
        Package::initFromBase( i.impl() );
        if ( &Package::component() )
            setCache( &Package::cache() );
        else
            setCache( 0 );
        observeComponent<component::Packages>();
    }
    virtual ~StablePackage() {}
    void notifyPreRebuild( component::Base *c );
    void notifyPostRebuild( component::Base *c );
    virtual void setCache( Cache *c ) {
        Package::setCache( c );
        Observer::setCache( c );
    }
protected:
    std::string m_pkgName;
};

template< typename P >
inline Entity PackageT< P >::stable() const {
    return StablePackage( *this );
}

template< typename P >
inline Version PackageT< P >::installedVersion() const
{
    this->checkValid();
    return component().currentVersion( *this );
}

template< typename P >
inline Version PackageT< P >::candidateVersion() const // XXX - beautify
{
    this->checkValid();
    return cache().state().candidateVersion( *this );
}

template< typename P >
inline bool PackageT< P >::hasVersion() const
{
    typename Component::VersionRange vr = versions();
    return vr != vr.end();
}

template< typename P >
inline typename PackageT< P >::State PackageT< P >::state( DefaultArgument< State > s ) const {
    if (!valid())
        return s.get( getterError( "state()" ) );
    return cache().state().packageState( *this );
}

template< typename P >
inline typename PackageT< P >::TagSet PackageT< P >::tags( DefaultArgument< TagSet > d) const {
	if (!valid())
        return d.get( getterError( "tags()" ) );
	return this->debtagsCache().getTagsOfItem( this->name() );
}

template< typename P >
inline std::string PackageT< P >::name( DefaultArgument< std::string > d ) const
{
    if (!valid())
        return d.get( getterError( "name()" ) );
    return component().packageName( *this );
}

template< typename P >
inline std::string PackageT< P >::shortDescription( DefaultString d ) const
{
    if (!hasVersion())
        return d.get( getterError( "shortDescription()" ) );
    return anyVersion().shortDescription( d );
}

template< typename P >
inline std::string PackageT< P >::md5sum( DefaultString d ) const
{
    if ( !hasVersion() )
        return d.get( getterError( "md5sum()" ) );
    return anyVersion().md5sum( d );
}

template< typename P >
inline std::string PackageT< P >::fileName( DefaultString d ) const
{
    if ( !hasVersion() )
        return d.get( getterError( "fileName()" ) );
    return anyVersion().fileName( d );
}

template< typename P >
inline std::string PackageT< P >::source( DefaultString d ) const
{
    if ( !hasVersion() )
        return d.get( getterError( "source()" ) );
    return anyVersion().source( d );
}

template< typename P >
inline std::string PackageT< P >::longDescription( DefaultArgument< std::string > d ) const
{
    if (!hasVersion())
        return d.get( getterError( "longDescription()" ) );
    return anyVersion().longDescription( d );
}

template< typename P >
inline std::string PackageT< P >::maintainer( DefaultArgument< std::string > d ) const
{
    if (!hasVersion())
        return d.get( getterError( "maintainer()" ) );
    return anyVersion().maintainer( d );
}

template< typename P >
inline std::string PackageT< P >::architecture( DefaultArgument< std::string > d ) const
{
    if (!hasVersion())
        return d.get( getterError( "architecture()" ) );
    return anyVersion().architecture( d );
}

template< typename P >
inline std::string PackageT< P >::section( DefaultArgument< std::string > d ) const
{
    if (!valid())
        return d.get( getterError( "section()" ) );
    return component().packageSection( *this );
    // return anyVersion().section( d );
    // return (component().strPtr( pkgPtr()->Section ));
}

template< typename P >
inline typename PackageT< P >::Actor PackageT< P >::unboundInstall() {
    return ActorFM( "package-install", gettext( "Request Install" ),
                    &entity::PackageT< P >::markInstall,
                    &entity::PackageT< P >::canInstall );
}

template< typename P >
inline typename PackageT< P >::Actor PackageT< P >::unboundRemove() {
    return ActorFM( "package-remove", gettext( "Request Removal" ),
                    &entity::PackageT< P >::markRemove,
                    &entity::PackageT< P >::canRemove );
}

template< typename P >
inline typename PackageT< P >::Actor PackageT< P >::unboundUpgrade() {
    return ActorFM( "package-upgrade", gettext( "Request Upgrade" ),
                    &entity::PackageT< P >::markInstall,
                    &entity::PackageT< P >::canUpgrade );
}

template< typename P >
inline typename PackageT< P >::Actor PackageT< P >::unboundKeep() {
    return ActorFM( "package-keep", gettext( "Cancel Changes" ),
                    &entity::PackageT< P >::markKeep,
                    &entity::PackageT< P >::canKeep);
}

template< typename P >
inline typename PackageT< P >::Actor PackageT< P >::unboundPurge() {
    return ActorFM( "package-purge", gettext( "Request Purging" ),
                    &entity::PackageT< P >::markPurge,
                    &entity::PackageT< P >::canRemove);
}

template< typename P >
inline typename PackageT< P >::Actor PackageT< P >::unboundReInstall() {
    return ActorFM( "package-reinstall", "Request Reinstall",
                    &entity::PackageT< P >::markReInstall,
                    &entity::PackageT< P >::canReInstall);
}

template< typename P >
inline typename PackageT< P >::BoundActor PackageT< P >::install() const {
    return BoundActor( unboundInstall(), *this );
}

template< typename P >
inline typename PackageT< P >::BoundActor PackageT< P >::upgrade() const {
    return BoundActor( unboundUpgrade(), *this );
}

template< typename P >
inline typename PackageT< P >::BoundActor PackageT< P >::keep() const {
    return BoundActor( unboundKeep(), *this );
}

template< typename P >
inline typename PackageT< P >::BoundActor PackageT< P >::remove() const {
    return BoundActor( unboundRemove(), *this );
}

template< typename P >
inline typename PackageT< P >::BoundActor PackageT< P >::purge() const {
    return BoundActor( unboundPurge(), *this );
}

template< typename P >
inline typename PackageT< P >::BoundActor PackageT< P >::reInstall() const {
    return BoundActor( unboundReInstall(), *this );
}

template< typename P >
inline utils::Range< Version > PackageT< P >::versions() const {
    return component().versions( *this );
}

template< typename P >
inline utils::Range< Relation > PackageT< P >::depends() const {
    return anyVersion().depends();
}

template< typename P >
Version PackageT< P >::anyVersion() const
{
    Version v = candidateVersion();
    if (!v.valid())
        v = *versions();
    return v;
}

#if 0
template< typename _P >
PackageT< _P >::PackageT( pkgCache::PkgIterator P )
{
    component::Packages &pc = downcast<component::Packages>( P.Cache() );
    this->setCache( pc.ownerCache () );
    m_package = (pkgCache::Package *) P;
    m_hashIndex = m_package ?
                  /*pkgCache().Hash(pkgCache().strPtr(m_package->Name))*/ 0 : 0;
}
#endif

template< typename P >
std::string PackageT< P >::statusString( DefaultArgument< std::string > d ) const
{
    if (!valid())
        return d.get( getterError( "statusString()" ) );
    std::string ret;
    if (isBroken()) {
        ret += gettext( "BROKEN" );
        ret +=  " (";
    }
    if (isUpgradable())
        ret += gettext( "upgradable" );
    else if (isInstalled())
        ret += gettext( "installed" );
    else ret += gettext( "not installed" );
    if (isBroken())
        ret += ")";
    return ret;
}

template< typename P >
std::string PackageT< P >::actionString( DefaultArgument< std::string > d ) const
{
    if (!valid())
        return d.get( getterError( "actionString()" ) );
    std::string ret;
    if (willBreak()) {
        ret += gettext( "BREAK" );
        ret += " (";
    }
    if (markedUpgrade())
        ret += gettext( "upgrade" );
    else if ( markedReInstall() )
        ret += gettext( "reinstall" );
    else if (markedInstall())
        ret += gettext( "install" );
    else if ( markedPurge() )
        ret += gettext( "purge" );
    else if (markedRemove())
        ret += gettext( "remove" );
    else if (markedKeep())
        ret += gettext( "no change" );
    if (willBreak())
        ret += ")";
    return ret;
}

template< typename P >
Version PackageT< P >::versionByString( const std::string& v ) const
{
    utils::Range< entity::Version > r = versions();
    while ( r != r.end() && r->versionString() != v )
        ++r;
    if ( r->versionString() == v )
        return *r;
    throw std::out_of_range( "No such version!" );
}

template< typename P >
void PackageT< P >::markInstall() {
    this->checkValid();
    cache().state().markInstall(*this);
}

template< typename P >
void PackageT< P >::markRemove() {
    this->checkValid();
    cache().state().markRemove(*this);
}

template< typename P >
void PackageT< P >::markKeep() {
    this->checkValid();
    cache().state().markKeep(*this);
}

template< typename P >
void PackageT< P >::markPurge() {
    this->checkValid();
    cache().state().markPurge(*this);
}

template< typename P >
void PackageT< P >::markReInstall() {
    this->checkValid();
    cache().state().markReInstall(*this);
}

template< typename P >
PackageT< P >::operator pkgCache::PkgIterator() const // XXX
{
    return pkgCache::PkgIterator( component().baseReference(), pointer().package() );
}


}

}

}

#endif
