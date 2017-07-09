#include <apt-front/workarounds.h>
#include <apt-pkg/pkgcache.h>
#include <apt-pkg/depcache.h>
#include <apt-pkg/policy.h>
#include <apt-pkg/algorithms.h>
#include <apt-front/cache/cache.h>
#include <apt-front/cache/entity/package.h>
#include "version-apt-front2.h"

#include <iostream>

#ifndef CACHE_COMPONENT_STATE_H
#define CACHE_COMPONENT_STATE_H

class pkgPolicy;

namespace aptFront {
namespace cache {
namespace component {
class Packages;

struct PackagePolicy : public pkgPolicy
{
    PackagePolicy( const PackagePolicy &p )
        : pkgPolicy( *static_cast<const pkgPolicy *>( &p ) )
    {
        unsigned c = Cache->Head().PackageCount;
        unsigned fc = Cache->Head().PackageFileCount;
        Pins = new Pin[c];
        std::copy( p.Pins, p.Pins+c, Pins );
        PFPriority = new signed short[fc];
        std::copy( p.PFPriority, p.PFPriority+fc, PFPriority );
    }
    PackagePolicy( aptFront::cache::Cache *owner )
        : pkgPolicy( &(owner->packages().baseReference()) )
    {
    }
};

struct State : public pkgDepCache, public Implementation<State>
{
    State( cache::Cache *cache );
    State( const State & );
    virtual ~State();
    entity::Package::State packageState( const entity::Package &i );
    bool isInstalled( const entity::Package &i );

    enum Action { AInstall, ARemove, AKeep, APurge, AReInstall };
    typedef std::pair< entity::Package, Action > Request;
    typedef utils::Range< Request > RequestList;

    void revert();
    void replay( RequestList );

    void markInstall( entity::Package p ) {
        action( p, AInstall, true );
    }

    void markRemove( entity::Package p ) {
        action( p, ARemove, true );
    }

    void markKeep( entity::Package p ) {
        action( p, AKeep, true );
    }

    void markPurge( entity::Package p ) {
        action( p, APurge, true );
    }

    void markReInstall( entity::Package p ) {
        action( p, AReInstall, true );
    }

    PackagePolicy &policy() { return m_policy; }

    void upgrade() {
        notifyPreChange();
        pkgAllUpgrade( *this );
        notifyPostChange();
    }

    void distUpgrade() {
        notifyPreChange();
        pkgDistUpgrade( *this );
        notifyPostChange();
    }

    void notifyPostChange();
    pkgDepCache &baseReference() { return *this; }

    void setOwnerCache( cache::Cache *c ) {
        Base::setOwnerCache( c );
        updateCounts();
    }

    entity::Version candidateVersion( entity::Package p ) {
        return entity::Version( &cache(), GetCandidateVer( p ) );
    }

    static std::string sizeString( double );
    std::string downloadSizeString() { return sizeString( downloadSize() ); }
    std::string installSizeString() { return sizeString( installSize() ); }
    double downloadSize() { return iDownloadSize; }
    double installSize() { return iUsrSize; }
    int brokenCount() { return BrokenCount(); }
    int removeCount() { return m_removeCount; }
    int newInstallCount() { return m_newInstallCount; } 
    int upgradeCount() { return m_upgradeCount; } 
    int reInstallCount() { return m_reInstallCount; } 

    int installedCount() { return m_installedCount; }
    int upgradableCount() { return m_upgradableCount; }
    int availableCount() { return m_availableCount; }

    bool changed();

    void updateCounts();

    static std::string componentName();
protected:
    void action( entity::Package p, Action a, bool notify );

    PackagePolicy m_policy;
    int m_removeCount;
    int m_newInstallCount;
    int m_upgradeCount;
    int m_installedCount;
    int m_upgradableCount;
    int m_availableCount;
    int m_reInstallCount;
};


}
}
}
#endif
