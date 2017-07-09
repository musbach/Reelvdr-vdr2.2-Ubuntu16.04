/** -*- C++ -*-
	@file utils/typeset.h
	@author Peter Rockai <me@mornfall.net>
    @todo Could use some refactoring -- specifically get rid of TypeComparable
          and its consequences (hint: TypeSet::put knows the type)
*/

#ifndef APTFRONT_UTILS_TYPESET_H
#define APTFRONT_UTILS_TYPESET_H
#include <set>
#include <string>
#include <typeinfo>
#include <stdexcept>
#include <apt-front/utils/shared.h>

namespace aptFront {

namespace utils {

struct TypeComparableBase : public SharedBase {
    virtual std::string typekey() const = 0;
    static std::string s_typekey() {
        return "invalid!";
    }
};

template <typename T, typename Base = TypeComparableBase>
struct TypeComparable : public Base {
    virtual std::string typekey() const {
        return typeid(T).name();
    }
    static std::string s_typekey() {
        return typeid(T).name();
    };
};

template <typename T>
struct TypeComparison {
    typedef const T &first_argument_type;
    typedef const T &second_argument_type;
    typedef bool result_type;
    bool operator()(const T &a, const T &b) {
        return a->typekey() < b->typekey();
    }
};

template <typename T>
struct TypeEquals {
    std::string a;
    TypeEquals( const std::string &x ) : a( x ) {}
    bool operator()( const T& b ) {
        return a == b->typekey();
    }
};

template<typename Container>
struct _TypeSet : Container
{
    typedef TypeEquals<typename Container::value_type> Equals;
    typedef typename Container::value_type value_type;
    typedef typename Container::iterator iterator;
    // typedef SharedPtr<TypeComparableBase> element_type;
    template<typename U> void put(U a) {
        insert( this->begin(), SharedPtr<TypeComparableBase>( new U( a ) ) );
    }
    template<typename U> U &getReference() {
        if (!has<U>())
            throw std::out_of_range( "oops!" );
        iterator i = std::find_if(
            this->begin(), this->end(),
            Equals( U::s_typekey() ) );
        value_type x = *i;
        return downcast<U>( x.data() );
    }
    template<typename U> U get() {
        return U( getReference() );
    }
    template<typename U> bool has() {
        return std::find_if( this->begin(), this->end(),
                             Equals( U::s_typekey() ) ) != this->end();
    }
};

typedef _TypeSet<
    std::set<
        SharedPtr<TypeComparableBase>,
        TypeComparison< SharedPtr<TypeComparableBase> >
    >
> TypeSet;

typedef _TypeSet<
    std::multiset<
        SharedPtr<TypeComparableBase>,
        TypeComparison< SharedPtr<TypeComparableBase> >
    >
> TypeMultiset;

}

}

#endif
