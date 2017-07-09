/** -*- C++ -*-
    @file predicate/combinators.h
    @author Peter Rockai <me@mornfall.net>
    @author Enrico Zini
*/

#include <algorithm>
#include <apt-front/utils/multitype.h>
#include <apt-front/predicate/predicate.h>
#include <apt-front/utils/range.h>

#ifndef APTFRONT_PREDICATE_COMBINATORS_H
#define APTFRONT_PREDICATE_COMBINATORS_H

namespace aptFront {
namespace predicate {

template< typename T, typename Self, typename Base = Implementation< T, Self > >
struct Compound: Base {

    typename Base::Parts parts() const {
        return m_parts;
    }

    bool operator==( const Compound &o ) const {
        return m_parts == o.m_parts;
    }

    std::string serialize() const {
        std::string ret = std::string( "(" ) /* + id() */;
        typename Base::Parts p;
        for (p = m_parts; p != p.end(); ++p)
            ret += " " + p->serialize();
        ret += ")";
        return ret;
    }

    void parseArguments( const ArgumentList & ) {}

protected:
    utils::VectorRange< Predicate< T > > m_parts;
};

template< typename T >
struct And: Compound< T, And<T> >
{
    And( Predicate< T > op1, Predicate< T > op2 ) {
        this->m_parts.consume( op1 );
        this->m_parts.consume( op2 );
    }

    And( const Predicate< T > &i ) {
        initFromBase( i.impl() );
    }

    And( const typename Base< T >::Parts &p ) {
        p.output( this->m_parts );
    }

    bool operator()( const T &t ) {
        bool ok = true;
        typename Base< T >::Parts p;
        for (p = this->parts(); p != p.end(); ++p)
            ok = ok && (*p)( t );
        return ok;
    }
};

template< typename T >
struct Or: Implementation< T, Or<T> >
{
    typedef bool result_type;
    typedef T argument_type;
    Or( Predicate< T > op1, Predicate< T > op2 ) : m_op1( op1 ), m_op2( op2 ) {}

    bool operator()( const T &t ) {
        return m_op1( t ) || m_op2( t );
    }

    Predicate< T > &first() { return m_op1; }
    Predicate< T > &second() { return m_op2; }

    bool operator==( const Or &o ) const {
        return m_op1 == o.m_op1
            && m_op2 == o.m_op2;
    }

    std::string serialize() const {
        return std::string("(or ") + m_op1.serialize()
            + " " + m_op2.serialize() + ")";
    }

    void parseArguments( const ArgumentList & ) {}

protected:
    Predicate< T > m_op1, m_op2;
};

template< typename T >
struct Not: Implementation< T, Not< T > >
{
    typedef bool result_type;
    typedef T argument_type;

    Not( Predicate< T > op ) : m_op( op ) {}

    bool operator()( const T &t ) {
        return not m_op( t );
    }

    bool operator==( const Not &n ) const {
        return m_op == n.m_op;
    }

    std::string serialize() const {
        return std::string( "(not " ) + m_op.serialize() + ")";
    }

    Predicate< T > &inner() { return m_op; }

    void parseArguments( const ArgumentList & ) {}
protected:
    Predicate< T > m_op;
};

template<typename Op1, typename Op2>
And<typename Op1::argument_type> operator and( Op1 op1, Op2 op2 )
{
    return And< typename Op1::argument_type >( op1, op2 );
}

template< typename Op1, typename Op2 >
Or< typename Op1::argument_type > operator or( Op1 op1, Op2 op2 )
{
    return Or< typename Op1::argument_type >( op1, op2 );
}

template< typename Op >
Not< typename Op::argument_type > operator not( Op op )
{
    return Not< typename Op::argument_type >( op );
}

template< typename T >
struct True : Implementation< T, True< T > >
{
    bool operator()( const T & ) { return true; }
    std::string serialize() const { return "(true)"; }
    void parseArguments( const ArgumentList & ) {}
    // true is true...
    bool operator==( const True & ) const { return true; }
};

template<typename Adapt, typename Pred>
struct Adaptor : Implementation< Adapt, Adaptor< Adapt, Pred > >,
                 Pred {
    typedef Adapt argument_type;
    typedef Pred predicate_type;
    typedef bool result_type;
    Adaptor( Pred op ) : Pred( op ) {}
    Pred &self() { return *static_cast< Pred * >( this ); }
    bool operator()( Adapt a ) {
        utils::Maybe< typename Pred::result_type > r;
        r = a.template ifType<typename Pred::argument_type>( this->self() );
        if (r.nothing())
            return false;
        return r.value();
    }
    // bool operator==( const Adaptor &a ) const { return m_op == a.m_op; }
    // std::string serialize() const { return m_op.serialize(); }
    void parseArguments( const ArgumentList &a ) {
        self().parseArguments( a ); // we do not exist :-)
    }
};

template<typename Adapt, typename Pred>
Adaptor<Adapt, Pred> adapt( Pred op ) {
    return Adaptor<Adapt, Pred>( op );
}

template< typename T, typename F >
struct Walker {
    typedef Or< T > OrType;
    typedef And< T > AndType;
    typedef Not< T > NotType;
    Walker( F func ) : m_functor( func ) {}
    void operator()( Predicate< T > &p ) {
        if (p.template is< OrType >()) {
            OrType &o = downcast< OrType >( p );
            (*this)( o.first() );
            (*this)( o.second() );
        } else if (p.template is< AndType >()) {
            // this actually should work, but it's not nice
            // update: this actually doesn't work
            // std::for_each( p.parts(), p.parts().end(), *this );
        } else if (p.template is< NotType >()) {
            NotType &n = downcast< NotType >( p );
            (*this)( n.inner() );
        } else {
            m_functor( p );
        }
    }
protected:
    F m_functor;
};

template< typename P >
struct Map : Implementation<
    typename P::argument_type, Map< P > >
{
    typedef typename P::argument_type argument_type;
    struct DistributeArguments {
        ArgumentList a;
        void operator()( Predicate< argument_type > &p ) {
            p.parseArguments( a );
        }
    };
    Map( P pred, const ArgumentList & a )
        : m_pred( pred ) {
        distributeArguments( a );
    }
    void distributeArguments( const ArgumentList &a ) {
        m_args = a;
        DistributeArguments d;
        d.a = a;
        Walker< argument_type, DistributeArguments > w( d );
        w( m_pred );
    }
    void parseArguments( const ArgumentList & ) {}
    bool operator()( const argument_type &arg ) {
        return m_pred( arg );
    }
    
    std::string serialize() const {
        return m_pred.serialize(); // own serialisation later
    }

    bool operator==( const Map &m ) const {
        return m_args == m.m_args
            && m_pred == m.m_pred;
    }
protected:
    P m_pred;
    ArgumentList m_args;
};

template< typename P >
Predicate< typename P::argument_type > map(
    P p, const ArgumentList &a )
{
    Map< P > m( p, a );
    return m;
}

template< typename T >
struct Remove : Implementation< T, Remove< T > >
{
    bool operator()( const T & ) {
        throw 0; // fixme
    }
    bool operator==( const Remove & ) const {
        return true;
    }
    void parseArguments( const ArgumentList & ) {}
};

template< typename P >
Predicate< typename P::argument_type > remove(
    P p, Predicate< typename P::argument_type > rem );

template< typename P >
Predicate< typename P::argument_type > remove_helper(
    P p, Predicate< typename P::argument_type > rem )
{
    typedef typename P::argument_type T;
    Predicate< T > ret;
    typedef Or< T > OrType;
    typedef And< T > AndType;
    typedef Not< T > NotType;
    if (p.template is< OrType >()) {
        OrType &o = downcast< OrType >( p );
        if (o.first() == rem) {
            if (o.second() == rem)
                return Remove< T >();
            return remove( o.second(), rem );
        } else {
            if (o.second() == rem)
                return remove( o.first(), rem );
            return remove( o.first(), rem ) or remove( o.second(), rem );
        }
    } else if (p.template is< AndType >()) {
        AndType &a = downcast< AndType >( p );
        utils::Range< Predicate< T > > parts = filteredRange(
            p.parts(),
            std::bind2nd( std::not_equal_to< Predicate< T > >(), rem ) );
        if (parts.empty())
            return Remove< T >();
        if (std::distance( parts, parts.end()) == 1)
            return remove( *parts, rem );
        return AndType( transformedRange(
                            parts,
                            std::bind2nd( std::ptr_fun( &predicate::remove< P > ), rem ) ) );
    } else if (p.template is< NotType >()) {
        NotType &n = downcast< NotType >( p );
        if (n.inner() == rem) {
            return Remove< T >();
        } else {
            return not remove( n.inner(), rem );
        }
    } else {
            if( p == rem )
                return Remove< T >(); 
            return p;
    }
}

template< typename P >
Predicate< typename P::argument_type > remove(
    P p, Predicate< typename P::argument_type > rem )
{
    Predicate< typename P::argument_type > a, b, rmp;
    rmp = Remove< typename P::argument_type >();
    a = remove_helper( p, rem );
    while( a != b ) {
        b = a;
        a = remove_helper( a, rmp );
    }
    if( a == rmp )
        return True< typename P::argument_type >();
    return a;
}

template <typename P, typename W>
P &unwrap( W &p ) {

}

}

}

// vim:set ts=4 sw=4:
#endif
