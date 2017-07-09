/** -*- C++ -*-
	@file predicate/factory.h
	@author Peter Rockai <me@mornfall.net>
*/

#include <apt-front/predicate/matchers.h>
#include <apt-front/predicate/combinators.h> //?
#include <apt-front/forward.h> //?

#ifndef APTFRONT_PREDICATE_FACTORY_H
#define APTFRONT_PREDICATE_FACTORY_H

namespace aptFront {
namespace predicate {

template< typename T >
struct Factory {
    typedef AttributeAdaptor< T, match::Substring > SubstringAdaptor;
    typedef ept::debtags::Tag Tag;

    static SubstringAdaptor name( const std::string &match = "" ) {
        return SubstringAdaptor( &T::name, match ); 
    }

    static SubstringAdaptor description( const std::string &match = "" ) {
        return SubstringAdaptor( &T::shortDescription, match ); 
    }

    static SubstringAdaptor maintainer( const std::string &match = "" ) {
        return SubstringAdaptor( &T::maintainer, match ); 
    }

    static SubstringAdaptor sectionSubstring( const std::string &match = "" ) {
        return SubstringAdaptor( &T::section, match ); 
    }

    static AttributeAdaptor< T, match::Tag, Tag > tag( const Tag &match = Tag() )
    {
        return AttributeAdaptor< T, match::Tag, Tag >( &T::tags, match ); 
    }

    static AttributeAdaptor< T, match::TagSet, Tag::Set > tagSet(
        const Tag::Set &match = Tag::Set() )
    {
        return AttributeAdaptor< T, match::TagSet, Tag::Set >( &T::tags, match ); 
    }

    template< typename P >
    static MemberAdaptor< T > member( P func ) {
        return MemberAdaptor< T >( func );
    }

/* mornfall: from matchers.h
template< typename T >
AttributeAdaptor< T, match::TagExpr, std::string > tagexprMatch( const std::string& match ) {
    return AttributeAdaptor< T, match::TagExpr, std::string >( &T::tags, match, "tags" );
}
*/
/*
template< typename T >
TagexprPredicate< T > tagexprMatch( const std::string& match ) {
    return TagexprPredicate< T >( &T::tags, match, "tags" );
}
*/
};

typedef Factory< cache::entity::Package > Package;
typedef Factory< cache::entity::Version > Version;
typedef Factory< cache::entity::Entity > Entity;

}
}


#endif
