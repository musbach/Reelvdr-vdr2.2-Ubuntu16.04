/** -*- C++ -*-
 * @file cache/entity/desktop.h
 * @author Peter Rockai <me@mornfall.net>
 */

#include <apt-front/forward.h>
#include <apt-front/cache/entity/package.h> // XXX for DefaultArgument

#ifndef APTFRONT_CACHE_ENTITY_DESKTOP_H
#define APTFRONT_CACHE_ENTITY_DESKTOP_H

namespace aptFront {
namespace cache {
namespace entity {

template< typename Data >
struct DesktopT : Implementation< DesktopT< Data > >, public Named
{
    bool valid() const { return true; } // XXX

    DesktopT() {}
    DesktopT( Cache *c, const Data &d ) : m_data( d ) { this->setCache( c ); }

    bool operator<( const DesktopT &o ) const { return name() < o.name(); }
    bool operator==( const DesktopT &o ) const { return name() == o.name(); }

    exception::InternalError getterError( std::string f ) const {
        return exception::InternalError(
            std::string( "Error calling entity::Desktop::" ) + f
            + ", the data is not available" );
    }

    std::string group( DefaultString d = DefaultString() ) const {
        if ( !this->valid() )
            return d.get( getterError( "group()" ) );
        return component().policy()->groupForCategories( data().categories() );
    }

    typedef DefaultArgument< utils::Range< std::string > > DefaultStringRange;
    utils::Range< std::string > categories(
        DesktopT::DefaultStringRange a = typename DesktopT::DefaultStringRange() ) const
    {
        if ( !this->valid() )
            return a.get( getterError( "categories()" ) );
        return data().categories();
    }

    std::string name( DefaultString d = DefaultString() ) const {
        if ( !this->valid() )
            return d.get( getterError( "name()" ) );
        return data().name();
    }

    std::string icon( DefaultString d = DefaultString() ) const {
        if ( !this->valid() )
            return d.get( getterError( "icon()" ) );
        return data().icon();
    }

    std::string shortDescription( DefaultString d = DefaultString() ) const {
        return description( d );
    }

    std::string description( DefaultString d = DefaultString() ) const {
        if ( !this->valid() )
            return d.get( getterError( "description()" ) );
        return data().description();
    }

    typedef std::set<ept::debtags::Tag> TagSet;
    TagSet tags( DefaultArgument< TagSet > d = DefaultArgument< TagSet >() ) const {
        if ( !this->valid() || !package( Package() ).valid() )
            return d.get( getterError( "tags()" ) );
        return package().tags();
    }

    std::string section( DefaultString d = DefaultString() ) const {
        if ( !this->valid() || !package( Package() ).valid() )
            return d.get( getterError( "section()" ) );
        return package().section();
    }

    Package package( DefaultArgument< Package > d = DefaultArgument< Package >() ) const
    {
        if ( !this->valid() )
            return d.get( getterError( "package()" ) );
        return this->cache().packages().packageByName( data().package() );
    }

protected:
    Data m_data;
    const Data &data() const { return m_data; }
    typename Data::Source &component() const {
        return this->cache().template component< typename Data::Source >();
    }
};

}
}
}

#include <apt-front/cache/component/desktop.h>

namespace aptFront {
namespace cache {
namespace entity {

typedef DesktopT< component::Desktop::Entry > Desktop;

}
}
}

#endif
