/** -*- C++ -*-
    @file cache/entity-actor.h
    @author Peter Rockai <me@mornfall.net>
    @todo Refactor to allow multiple action "collections"
    @todo Make global (eg. cache) actions possible
    @todo make a multitype and use a normal functor not
          pointer-to-member
*/

#ifndef CACHE_ENTITY_ACTOR_H
#define CACHE_ENTITY_ACTOR_H
#include <vector>
#include <map>
#include <string>
#include <typeinfo>
#include <set>
#include <apt-front/forward.h>
#include <apt-front/utils/range.h>
// #include <apt-front/utils/shared.h>
// #include <apt-front/utils/cast.h>
#include <apt-front/utils/typeset.h>
#include <apt-front/error.h>

namespace aptFront {
namespace actor { 

template< typename T >
struct Collection :
        std::vector< Actor< T > >,
        utils::TypeComparable< Collection< T > > 
{
};

struct GlobalData
{
    static utils::TypeSet *s_actions;
};

template< typename T >
struct Global {
    static utils::Range< Actor< T > > list();
    static Collection< T > &collection();
    static void add( const Actor< T > & );
    static void clear() {
        collection().clear();
    }
    static utils::Range< Actor< T > > listPossible( const T & );
};

template< typename T >
struct Base : utils::MultiTypeBase< Base< T > >
{
    bool possible( const T &x ) const { return possibleOnItem( x ); }
    bool possible( utils::Range< T > r ) const { return possibleOnRange( r ); }
    void act( T &x ) { actOnItem( x ); }
    void act( utils::Range< T > r ) { actOnRange( r ); }
    virtual std::string name() const = 0;
    virtual std::string prettyName() const = 0;
    operator Actor< T >() const;
protected:
    virtual bool possibleOnItem( const T & ) const = 0;
    virtual bool possibleOnRange( utils::Range< T > ) const = 0;
    virtual void actOnItem( T & ) = 0;
    virtual void actOnRange( utils::Range< T > ) = 0;
};

template< typename T, typename Self, typename Base = Base< T > >
struct Implementation: utils::MultiTypeImpl< Self, Base >
{
    bool possibleOnRange( utils::Range< T > r ) const {
        while (r != r.end()) {
            if (possible( *r ))
                return true;
            ++r;
        }
        return false;
    }

    void act( utils::Range< T > r ) {
        while (r != r.end()) {
            if (possible( *r )) { // safety...
                T x = *r;
                (this->self())( x );
            }
            ++r;
        }
    }

    void actOnItem( T &x ) {
        (this->self())( x );
    }

    void actOnRange( utils::Range< T > r ) {
        (this->self()).act( r );
    }

};

template< typename T >
struct Actor : utils::MultiType< Actor< T >, Base< T > >
{
    typedef utils::MultiType< Actor< T >, Base< T > > Super;
    Actor( const Base< T > *i ) : Super( i ) {}
    Actor( const Actor &i ) : Super( i ) {}

    void operator()( T &e ) {
        this->m_impl->act( e );
    }

    void operator()( utils::Range< T > r ) {
        this->m_impl->act( r );
    }

    bool possible( const T &e ) const {
        return this->m_impl->possible( e );
    }

    bool possible( utils::Range< T > r ) const {
        return this->m_impl->possible( r );
    }

    template< typename C > operator Actor< C >();

    std::string name() const { return this->m_impl->name(); }
    std::string prettyName() const { return this->m_impl->prettyName(); }

};

template< typename T >
struct Bound : Actor< T > //utils::MultiType< Bound< T >, Base< T > >
{
    typedef Actor< T > Super;
    // typedef utils::MultiType< Bound< T >, Base< T > > Super;
    // Bound( const Base< T > *i ) : Super( i ) {}
    Bound( const Bound &i ) : Super( i ), m_bound( i.m_bound ) {}
    Bound( Actor< T > a, T b ) : Super( a ), m_bound( b ) {}

    void operator()() {
        this->m_impl->act( m_bound );
    }

    bool possible() const {
        return this->m_impl->possible( m_bound );
    }

    template< typename C > operator Bound< C >();

protected:
    T m_bound;
};

/* this does not work on things you can't copy... */
template< typename C, typename T >
struct Upcast : Implementation< C, Upcast< C, T > >
{
    Upcast( Actor< T > c ) : m_casted( c ) {}

    virtual std::string name() const { return m_casted.name(); }
    virtual std::string prettyName() const { return m_casted.prettyName(); }

    virtual bool possibleOnItem( const C &x ) const {
        return m_casted.possible( x );
    }

    void operator()( C &x ) {
        C y( x );
        T z( y );
        m_casted( z );
    }

protected:
    Actor< T > m_casted;
};

template< typename T >
struct FromMemberUnconditional :
    Implementation< T, FromMemberUnconditional< T > >
{
    typedef void (T::*Action)( void );

    FromMemberUnconditional( std::string n, std::string pn, Action act )
        : m_name( n ), m_prettyName( pn ), m_act( act )
    {}

    virtual bool possibleOnItem( const T & ) const {
        return true;
    }

    void operator()( T &x ) {
        (x.*m_act)();
    }

    virtual std::string name() const { return m_name; }
    virtual std::string prettyName() const { return m_prettyName; }

protected:
    FromMemberUnconditional() {} // booo
    std::string m_name, m_prettyName;
    Action m_act;
};

template< typename T >
struct FromMember : Implementation< T, FromMember< T >,
                                    FromMemberUnconditional< T > >
{
    typedef bool (T::*Possible)( void ) const;
    typedef void (T::*Action)( void );
    FromMember( std::string n, std::string pn,
                Action act, Possible pos )
    {
        this->m_name = n;
        this->m_prettyName = pn;
        this->m_act = act;
        this->m_possible = pos;
    }

    virtual bool possibleOnItem( const T &x ) const {
        return (x.*m_possible)();
    }

protected:
    Possible m_possible;
};

template< typename T >
Collection< T > &Global< T >::collection()
{
    utils::TypeSet *ts;
    if (!(ts = GlobalData::s_actions))
        ts = GlobalData::s_actions = new utils::TypeSet;
    if (!(ts->template has< Collection< T > >())) {
        ts->put( Collection< T >() );
    }
    return ts->template getReference< Collection< T > >();
}

template< typename T >
void Global< T >::add( const Actor< T > &a ) {
    collection().push_back( a ); // easy eh ;-)
}

template< typename T >
utils::Range< Actor< T > > Global< T >::list() {
    utils::VectorRange< Actor< T > > vr;
    std::copy( collection().begin(), collection().end(), utils::consumer( vr ) );
    return vr;
}

template< typename T >
utils::Range< Actor< T > > Global< T >::listPossible( const T &e ) {
    utils::VectorRange< Actor< T > > ret;
    // hmm, copy_remove_if with member-function-into-unary-predicate thingy?
    typename Collection< T >::iterator i = collection().begin();
    for (; i != collection().end(); ++i) {
        if (i->possible( e )) {
            ret.consume( *i );
        }
    }
    return ret;
}

template< typename T >
inline Base< T >::operator Actor< T >() const {
    return Actor< T >( this );
}

template< typename T > template< typename C >
Actor< T >::operator Actor< C >()
{
    return Upcast< C, T >( *this );
}

template< typename T > template< typename C >
Bound< T >::operator Bound< C >()
{
    return Bound< C >( Upcast< C, T >(
                           static_cast< Actor< T > >( *this ) ), m_bound );
}

}
}

#endif

#if 0 // temporary stuff
#endif

