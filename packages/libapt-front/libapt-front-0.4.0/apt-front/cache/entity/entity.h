/** -*- C++ -*-
    @file cache/entity/entity.h
    @author Peter Rockai <me@mornfall.net>
    @todo Parametrize the (end user) entities over some
    representation, which gets wrapped by Iterable template (which is
    then specialised)
*/

#include <apt-front/cache/cache.h>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include <apt-front/forward.h>
#include <apt-front/cache/cache.h>
#include <apt-front/utils/multitype.h>

#ifndef APTFRONT_CACHE_ENTITY_H
#define APTFRONT_CACHE_ENTITY_H
namespace aptFront {
namespace cache {

namespace entity {

template< typename _Component >
struct Pointer {
    typedef _Component Component;
    Component &component() const { return *m_component; }
    Cache &cache() const { return component().cache(); }
    Pointer( Component *c ) : m_component( c ) {}
    Pointer() : m_component( 0 ) {}
    bool valid() const { return m_component; }
private:
    Component *m_component;
};

/**
   @brief Common Iterator base class.
*/
class Base : public utils::MultiTypeBase<Base> {
public:
    Base () : m_cache (0) { setCache( 0 ); }
    Base( const Base &b ) : utils::MultiTypeBase<Base>( b ),
        m_cache( 0 ) {
        setCache( b.m_cache );
    }
    virtual ~Base() {}
    virtual bool valid() const = 0;
    void checkValid () const throw (std::out_of_range) {
        if (valid())
            return;
        throw std::out_of_range("Tried to use invalid Entity");
    }
    virtual Cache &cache() const { return *cache::Global::getPointer( m_cache ); }
    virtual void setCache( Cache *c ) { m_cache = c; }
    virtual Entity stable() const;
    operator Entity () const;
protected:
    Cache *m_cache;
};

template <typename T, typename _Base = Base>
struct Implementation : public utils::MultiTypeImpl<T, _Base, utils::comparable> {
    inline component::Packages &packageCache () const {
        return this->cache().packages();
    }
    inline component::PackageTags &debtagsCache () const {
        return this->cache().debtags();
    }
    inline component::Tags &tagsCache () const {
        return this->cache().tags();
    }
    // lets avoid dynamic binding here...
    void checkValid () const throw (std::out_of_range) {
        if ((this->self()).valid())
            return;
        throw std::out_of_range("Tried to use invalid Entity");
    }
    static inline bool instance (const Entity b);
    virtual ~Implementation () {}
};

/**
   @brief A common iterator wrapper object. Handle Iterators as values.
   
   This is a simple wrapper holding a pointer to the implementation,
   allowing polymorphic response on value (non-pointer) variables.
   
   MyIteratorType = i; // i is of type Iterator
   
   should work if i is of type MyIteratorType, throws std::bad_cast otherwise.
*/
class Entity : public utils::MultiType<Entity, Base> {
public:
    typedef utils::MultiType<Entity, Base> Super;
    Entity( Base *i ) : Super( i ) {}
    Entity( const Entity &i ) : Super( i ) {}
    Entity() {}

    /**
       @brief Return a stable variant of the Iterator.
       @see IteratorBase::stable().
    */
    Entity stable() const {
        return m_impl->stable();
    }

    ~Entity() {}
};

template <typename T, T (T::*_Next)( void ) const>
class Iterator {
protected:
    T current;
public:
    typedef std::forward_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef T &reference;

    Iterator() {}
    Iterator( T start ) : current( start ) {}
    const T &operator*() const { return current; }
    const T *operator->() const { return &current; }
    Iterator &operator++() { current = (current.*_Next)(); return *this; }
    Iterator operator++(int) {
        Iterator tmp = *this;
        current = (current.*_Next)();
        return tmp;
    }
    bool operator==( const Iterator &i ) const {
        return *i == **this;
    }
    bool operator!=( const Iterator &i ) const {
        return !(i == *this);
    }
};

template <typename T>
struct Iterable {};

inline Base::operator Entity () const
{
    return Entity( duplicate() );
}

template <typename T, typename B>
inline bool Implementation<T,B>::instance (const Entity b) {
    return dynamic_cast<T *>( b.impl() );
}

inline Entity Base::stable() const {
    return *this; 
}

}
}
}
#endif
