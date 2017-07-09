/** -*- C++ -*-
    @file predicate/predicate.h
    @author Peter Rockai <me@mornfall.net>
    @author Enrico Zini

    Facilities used to filter packages.
    Example use:
    \code
    // Construct predicate statically
    using namespace aptFront::predicate;
    Predicate<Package> p = nameMatch("lib") and descriptionMatch("shared");
    
    // Construct predicate dynamically
    predicate::Predicate<Package> p = predicate::True<Package>();
    if (!name_f.empty())
        p = p and predicate::nameMatch<Package>(name_f);
    if (!desc_f.empty())
        p = p and predicate::descriptionMatch<Package>(desc_f);
    
    // Create a filtered range that holds the filtered packages
    utils::Range<Package> matches = filteredRange(
        utils::Range<Package>(range(packages.packagesBegin(),
            packages.packagesEnd())), p);
    
    // Output the contents of the range to a consumer
    matches.output(consumer);
    \endcode

    \par Adding new search functions
    (to be written)

    \par Adding new generators
    (to be written)
*/

#include <vector>
#include <string>
#include <apt-front/forward.h>
#include <apt-front/utils/multitype.h>

#ifndef APTFRONT_PREDICATE_H
#define APTFRONT_PREDICATE_H

namespace aptFront {
namespace predicate {


struct Argument {
    // std::string name; // want this?
    std::string value;
    /** Literals go out into "...", escaped.  When "..." is
        parsed, literal is set to true otherwise it's a
        subexpression and needs to be parsed recursively.
    */
    bool literal; 

    bool operator==( const Argument &a ) const {
        return a.literal == literal
            && a.value == value;
    }
    
    Argument( std::string v, bool l = true )
        : value( v ), literal( l ) {}
};

typedef std::vector< Argument > ArgumentList;

template <typename T>
struct Base : public utils::MultiTypeBase< Base<T> >
{
    template< typename _T > struct IsPredicate { typedef _T type; };
    typedef utils::Range< Predicate< T > > Parts;
    typedef T argument_type;
    typedef bool result_type;
    virtual bool test( const T & ) = 0;
    virtual void parseArguments( const ArgumentList & ) = 0;

    // fixme
    virtual Parts parts() const {
        return Parts();
    }
    // virtual ArgumentList arguments() = 0;

    virtual std::string prettyPrint() const {
        return "";
    }

    /** @todo refactor to take a serializer object and use it to to
        format the output? it's hardcoded here for now... */
    virtual std::string serialize() const {
        return "#error#";
    }

    operator Predicate<T>();
};

template <typename T>
struct Predicate : utils::MultiType< Predicate<T>, Base<T> >
{
    typedef utils::MultiType<Predicate<T>, Base<T> > Super;
    typedef T argument_type;
    typedef bool result_type;
    typedef utils::Range< Predicate< T > > Parts;
    Predicate( Base<T> *i ) : Super( i ) {}
    Predicate( const Predicate &i ) : Super( i ) {}
    Predicate() {}
    bool operator()( const T &t ) { return this->m_impl->test( t ); }
    std::string prettyPrint() const { return this->m_impl->prettyPrint(); }
    std::string serialize() const { return this->m_impl->serialize(); }
    virtual Parts parts() const {
        return this->m_impl->parts(); }
    void parseArguments( const ArgumentList &a ) {
        this->m_impl->parseArguments( a ); }
    virtual ~Predicate() {} // ?
};

template <typename T, typename Self, typename Base = Base<T> >
struct Implementation : utils::MultiTypeImpl<Self, Base,
                                             utils::equalityComparable>
{
    bool test( const T &t ) {
        return (this->self())( t );
    }
};

template<typename Pred>
Predicate< typename Pred::argument_type > predicate( Pred p ) {
    return p;
}

template< typename T >
Base< T >::operator Predicate< T >() {
    return Predicate< T >( this );
}

}

namespace utils {
template< typename T >
typename T::template IsPredicate< std::string >::type
prettyPrint( const T &p ) {
    return p.prettyPrint();
}

}

}

// vim:set ts=4 sw=4:
#endif
