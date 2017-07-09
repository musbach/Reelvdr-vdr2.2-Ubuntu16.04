/**  -*-C++-*-
 * @file cache/component/records.h
 * @author Peter Rockai <me@mornfall.net>
 */

#include <vector>

#include <apt-front/cache/component/base.h>
#include <apt-front/cache/entity/desktop.h>
#include <apt-front/utils/range.h>
#include <apt-front/utils/comparable.h>
#include <apt-front/forward.h>

#ifndef APTFRONT_CACHE_COMPONENT_DESKTOP_H
#define APTFRONT_CACHE_COMPONENT_DESKTOP_H

namespace aptFront {
namespace cache {
namespace component {

struct Desktop : Implementation< Desktop >
{
    typedef utils::Range< std::string > Categories;
    struct GroupPolicy {
        virtual std::string groupForCategories( Categories );
    };

    struct Entry : utils::Comparable< Entry > {
        typedef Desktop Source;
        Entry() {}
        Entry( std::string n, std::string g,
               std::string p, std::string d , std::string i )
            : m_name( n ), m_package( p ), m_description( d ), m_icon( i )
        { setCategories( g ); }
        void load( std::string file );
        Categories categories() const { return m_categories; }
        std::string name() const { return m_name; }
        std::string package() const { return m_package; }
        std::string description() const { return m_description; }
        std::string icon() const { return m_icon; }
        void setCategories( std::string s );
        bool operator< ( const Entry &o ) const {
            if ( m_name < o.m_name ) return true;
            if ( m_package < o.m_package ) return true;
            return false;
        }
    protected:
        std::string m_name, m_package, m_description, m_icon;
        bool m_supported, m_free;
        Categories m_categories;
    };

    struct EntryInGroup {
        const Desktop *desktop;
        typedef Entry argument_type;
        EntryInGroup( const Desktop *d, std::string s ) : desktop( d ), group( s ) {}
        std::string group;
        bool operator()( const Entry &e ) const {
            return desktop->policy()->groupForCategories( e.categories() ) == group;
        }
    };

    typedef entity::DesktopT< Entry > Entity;

    struct MakeEntity {
        typedef Entry argument_type;
        typedef Entity result_type;
        MakeEntity( Cache *_c ) : c( _c ) {}
        Entity operator()( const Entry &e ) const { return Entity( c, e ); }
        Cache *c;
    };

    struct GetEntityGroup {
        typedef Entity argument_type;
        typedef std::string result_type;
        std::string operator()( const Entity &e ) const { return e.group(); }
    };

    typedef utils::Range< Entry > Range;
    typedef utils::Range< Entity > EntityRange;
    typedef utils::Range< std::string > StringRange;

    StringRange availableGroups() const { return availableGroups( entries() ); }

    StringRange availableGroups( EntityRange r ) const {
        return utils::uniqueRange(
            utils::transformedRange< GetEntityGroup >( r, GetEntityGroup() ) );
    }

    EntityRange group( std::string id ) const {
        return utils::transformedRange< MakeEntity >(
            utils::filteredRange( utils::range( m_vrange ), EntryInGroup( this, id ) ),
            MakeEntity( ownerCache() ) );
    }

    EntityRange entries() const {
        return utils::transformedRange< MakeEntity >(
            m_vrange, MakeEntity( ownerCache() ) );
    }

    void loadDirectory( std::string path );

    Desktop();
    virtual ~Desktop();

    GroupPolicy *policy() const { return m_policy; }
    void setPolicy( GroupPolicy * );

    void add( Entry e ) { m_vrange.consume( e ); }

    static std::string componentName();
protected:
    typedef utils::VectorRange< Entry > VRange;
    GroupPolicy m_defaultPolicy;
    GroupPolicy *m_policy;
    VRange m_vrange;
};

}
}
}

#endif
