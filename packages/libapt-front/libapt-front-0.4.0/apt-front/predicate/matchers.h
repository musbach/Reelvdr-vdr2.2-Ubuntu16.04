/** -*- C++ -*-
    @file predicate/matchers.h
    @author Peter Rockai <me@mornfall.net>
    @author Enrico Zini
*/

#include <apt-front/predicate/predicate.h>
#include <apt-front/utils/prettyprint.h>
#include <apt-front/cache/entity/package.h>
#include <ept/debtags/tag.h>
#include <ept/debtags/expression.h>
#include <wibble/operators.h>
#include <functional>
#include <cctype>

#ifndef APTFRONT_PREDICATE_MATCHERS_H
#define APTFRONT_PREDICATE_MATCHERS_H

namespace aptFront {


namespace utils {

template<>
inline std::string prettyPrint< std::set<ept::debtags::Tag> >( const std::set<ept::debtags::Tag> &s )
{
    std::string res;
    for (std::set<ept::debtags::Tag>::const_iterator i = s.begin();
         i != s.end(); i++)
        if (i == s.begin())
            res += i->fullname();
        else
            res += "," + i->fullname();
    return res;
}

}

namespace predicate {

namespace match {


template< typename T, typename Self >
struct Match : predicate::Implementation< T, Self >
{
    bool operator==( const Match &s ) const {
        return this->self().pattern() == s.self().pattern();
    }
};

/**
 * Match the exact value.
 *
 * It can work with any type that allows comparison.
 */
template<typename T>
struct Exact : Match< T, Exact< T > >
{
protected:
	T m_pattern;
public:
    Exact(const T& pattern) : m_pattern(pattern) {}

	bool operator()( const T& item )
	{
        return m_pattern == item;
	}

    void parseArguments( const ArgumentList & ) {}
    T pattern() const { return m_pattern; }
};

template< typename T >
struct LessThan: Match< T, LessThan< T > >
{
    LessThan( const T& pattern ): m_pattern( pattern ) {}

    bool operator()( const T &item ) { return item < m_pattern; }

    void parseArguments( const ArgumentList & ) {}

    T pattern() const { return m_pattern; }

protected:
    T m_pattern;
};

/**
 * Match a substring.
 */
struct Substring : Match< std::string, Substring >
{
protected:
	std::string m_pattern;
public:
    Substring(const std::string& pattern) {
        std::transform( pattern.begin(), pattern.end(),
                        std::back_inserter( m_pattern ), tolower );
    }

	bool operator()( const std::string& str )
	{
        std::string in;
        std::transform( str.begin(), str.end(), std::back_inserter( in ), tolower );
        return in.find( m_pattern, 0 ) != std::string::npos;
	}

    void parseArguments( const ArgumentList &a ) {
        m_pattern = a.begin()->value; // safety?
    }

    std::string pattern() const { return m_pattern; }

};

/**
 * Match a regular expression.
 *
 * (still unfinished)
 */
struct Ereg : Match<std::string, Ereg>
{
protected:
	std::string m_pattern;
public:
    Ereg(const std::string& pattern) : m_pattern(pattern) {}

	bool operator()( const std::string& str )
	{
        return str.find( m_pattern, 0 ) != std::string::npos;
	}

    void parseArguments( const ArgumentList & ) {}
    std::string pattern() const { return m_pattern; }
};


/**
 * Match tag sets containing the given tags.
 */
template< typename M = ept::debtags::Tag >
struct TagMatch : Match< std::set<ept::debtags::Tag>, TagMatch< M > >
{
protected:
	M m_tag;
public:
	TagMatch(const M& tag) : m_tag(tag) {}

	bool operator()( const std::set<ept::debtags::Tag>& tags )
	{
		using namespace wibble::operators;
		return m_tag <= tags;
	}

    void parseArguments( const ArgumentList & ) {}
	M pattern() const { return m_tag; }
};

typedef TagMatch< ept::debtags::Tag > Tag;
typedef TagMatch< std::set<ept::debtags::Tag> > TagSet;

class TagExpr : public tagcoll::Expression
{
public:
	TagExpr(const std::string expr) : tagcoll::Expression(expr) {}
	TagExpr(const TagExpr& expr) : tagcoll::Expression(expr) {}

	typedef std::set<ept::debtags::Tag> argument_type;
	typedef bool result_type;

    bool operator==( const TagExpr & ) const { return false; } // fixme

    void parseArguments( const ArgumentList & ) {}
};

}

/**
 * Generic predicate for matching.
 *
 * It puts together the machinery of extracting the value from the items using
 * a getter function and of invoking the matching functor on it.
 */
template<typename T, typename Matcher, typename Pattern = typename Matcher::argument_type>
struct AttributeAdaptor : Implementation< T, AttributeAdaptor< T, Matcher, Pattern > >
{
	typedef typename Matcher::argument_type matched_type;

protected:
    typedef matched_type (T::*Getter)( cache::entity::DefaultArgument< matched_type > ) const;
    Getter m_getter;
    Matcher m_match;
public:
    typedef T argument_type;
    typedef bool result_type;

    AttributeAdaptor( Getter g, const Pattern& pattern )
        : m_getter( g ), m_match( pattern ) {}

    bool operator()( const T &t ) {
        return m_match((t.*m_getter)(typename Matcher::argument_type()));
    }

    /* std::string serialize() const {
        return std::string( "(" ) + m_prettyWhat + " \"" + m_match.prettyPrint() + "\")";
        } */

    void parseArguments( const ArgumentList &a ) {
        m_match.parseArguments( a );
    }

    bool operator==( const AttributeAdaptor &a ) const {
        return m_getter == a.m_getter
            && m_match == a.m_match;
    }
};

template< typename T >
struct MemberAdaptor : Implementation< T, MemberAdaptor< T > >
{
    typedef bool (T::*Member)( void ) const;

    MemberAdaptor( Member m ) : m_member( m ) {}

    bool operator()( const T &t ) {
        return (t.*m_member)();
    }

    void parseArguments( const ArgumentList & ) {}

    std::string serialize() const {
        return "#error#";
    }

    bool operator==( const MemberAdaptor &a ) const {
        return m_member == a.m_member;
    }
protected:
    Member m_member;
};

/**
 * Predicate matching tag expressions.
 */
/*
template<typename T>
struct TagexprPredicate : Implementation< T, TagexprMatch< T > >
{
protected:
    typedef std::set<ept::debtags::Tag> (T::*Getter)( const std::set<ept::debtags::Tag>& ) const;
    Getter m_getter;
	Tagcoll::TagExpression m_match;
    std::string m_prettyWhat;
public:
    typedef T argument_type;
    typedef bool result_type;

    TagexprPredicate( Getter g, const std::string& pattern, const std::string& w )
        : m_getter( g ), m_match( pattern ), m_prettyWhat( w ) {}

    bool operator()( const T &t ) {
        return m_match((t.*m_getter)(std::set<ept::debtags::Tag>()));
    }

    std::string prettyPrint() const { 
        return m_prettyWhat + ": \"" + m_match.prettyPrint() + "\"";
    }

    std::string serialize() const {
        return std::string( "(" ) + m_prettyWhat + " \"" + m_match.prettyPrint() + "\")";
    }

    void parseArguments( const ArgumentList &a ) {
        m_match.parseArguments( a );
    }
};
*/


}
}

// vim:set ts=4 sw=4:
#endif
