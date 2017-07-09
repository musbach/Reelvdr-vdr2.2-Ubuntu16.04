/** -*- C++ -*-
 * @file cache/cache.h
 * @author Peter Rockai <me@mornfall.net>
 */
#include <map>
#include <set>
#include <cstdlib>

#include <apt-pkg/progress.h> // FIXME

#include <apt-front/forward.h>
#include <apt-front/utils/cast.h>

#include <stdexcept>

#ifndef APTFRONT_CACHE_H
#define APTFRONT_CACHE_H
namespace aptFront {

namespace cache {

/**
   @brief A singleton Cache keeper object.

   You can use Global::getPointer() if your program only needs a single
   Cache instance (which is the case in probably 90% of
   scenarios). This will relieve you of passing the Cache pointer
   around, since all classes taking a Cache pointer should use
   CacheGlobal::getPointer() on it, thus allowing 0 as a pointer to the
   global cache.
*/
class Global {
protected:
    static Cache *s_cache;
public:
    /// Re-set the global cache to a different instance.
    static void setCache(Cache *c);

    /**
       @brief Get a cache pointer.

       This function will return the reference to object you pass as
       an argument in the case it's non-NULL, but will return the
       global cache pointer otherwise. This allows you to implement
       behaviour you can see in libapt-front itself, where passing 0
       as a Cache pointer causes the relevant object to use a global
       instance.
    */
    static Cache &get(Cache *my = 0);

    /**
       @brief Get a cache reference.

       Same as get(Cache *), but returns a pointer.
    */
    static Cache *getPointer(Cache *my = 0);
};


/**
   @brief A central cache object managing all the cache components.

   The Cache object is the central data object in libapt-front. All
   data is stored in some of the cache components, be it package data,
   state, debtags data or anything like that. Unless you are extending
   libapt-front, all you need to do with this class is usually to
   initialize and open an instance of it and have cache::Global take
   care of things (or you can pass your instance around if you prefer
   that).

   All data access is done through cache::entity objects so that's
   what your usual programs using libapt-front will use.
   
   @see entity::Entity, entity::Package
   @author Peter Rockai <me@mornfall.net>
*/
class Cache {
public:

    friend class Observer;
    typedef std::set<Observer *> ObserverSet;
    typedef std::map<std::string, ObserverSet> ObserverMap;
    typedef std::map<std::string, component::Base *> ComponentMap;
    enum OpenFlags { OpenReadOnly = 0x1,
                     OpenPackages = 0x2,
                     OpenState = 0x4,
                     OpenRecords = 0x8,
                     OpenDebtags = 0x10,
                     OpenDebtagsEditable = 0x20,
                     OpenDefault = 0x2 | 0x4 | 0x8 | 0x10 | 0x40 | 0x80 | 0x100 };
    enum AddComponentFlags { KeepOld = 0x1, AvoidNotify = 0x2 };

    void openRecords();
    void openDebtags();
    void openPackages();
    void openState();
    void open( unsigned flags = OpenDefault );

    void close();
    void reopen();

    bool writeable() { return !(m_openFlags & OpenReadOnly); }
    void setProgress( OpProgress *p = 0 ) { m_progress = p; }
    OpProgress &progress();

    /**
       @brief Get a component pointer of type T via it's type.

       Call this to get a component pointer of a specific type.
       It may be 0. Use component() to get a reference safely.
    */
    template<typename T> T *componentPointer() const;

    /**
       @brief Get a component reference of type T.

       This is a safe variant of componentPointer(). It either returns
       a valid component reference or throws.
    */
    template<typename T> T &component() const;

    /**
       @brief add a new component to cache

       This allows you to add (or replace) a cache component. The flags
       argument can be used to pass Cache::KeepOld to not delete the
       previous instance of the component, even if the component has
       allowDelete() set.
    */
    template<typename T>
    void addComponent( T *c, unsigned flags = 0 );

    /**
       @brief Delete a registered component.

       This will delete a component with appropriate
       notifications and only if really is set to true
       and the component is allowDelete().
    */
    void deleteComponent( component::Base *old, bool really = true );

    component::Packages &packages() const;
    component::PackageTags &debtags() const;
    component::State &state() const;
    component::Records &records() const;
    ept::debtags::Vocabulary &tags() const;
    component::debtags::PackageIntConverter &packageintconverter() const;
    component::debtags::PackageStringConverter &packagestringconverter() const;
    component::debtags::FacetIntConverter &facetintconverter() const;
    component::debtags::FacetStringConverter &facetstringconverter() const;
    component::debtags::TagIntConverter &tagintconverter() const;
    component::debtags::TagStringConverter &tagstringconverter() const;

    /**
       @brief observers use this to register themselves */
    template<typename T>
    void registerObserver( Observer *o );

    /**
       @brief observers use this to deregister themselves */
    template<typename T>
    void deregisterObserver( Observer *o );

    void notify( component::Base *c,
                 void (cache::Observer::*F)( component::Base * ) );
    void notifyPreRebuild( component::Base *c );
    void notifyPostRebuild( component::Base *c );

    bool isOpen() { return m_isOpen; }

    Cache ();
    ~Cache ();
protected:
    ComponentMap m_components;
    ObserverMap m_observers;
    OpProgress *m_progress;
    OpProgress m_silentProgress;

    // flags
    unsigned m_openFlags;
    unsigned m_desiredFlags;
    bool m_isOpen;

    void registerObserver( Observer *o, std::string c );
    void deregisterObserver( Observer *o, std::string c );
    template<typename T> T *componentPointer( std::string s ) const;

private:
    Cache( const Cache & ) { abort(); }; // no copying please
};

}

}

#include <apt-front/cache/observer.h>

namespace aptFront {
namespace cache {

inline OpProgress &Cache::progress() { return m_progress ?
                                    *m_progress : m_silentProgress; }
template<typename T> T *Cache::componentPointer() const {
    return componentPointer<T>( T::s_id() );
}

template<typename T> T &Cache::component() const {
    T *t = componentPointer<T>();
    if (!t)
        throw std::out_of_range( "component " + T::componentName() + " not found" );
    return *t;
}

template<typename T>
void Cache::addComponent( T *c, unsigned flags ) {
    component::Base *old;
    try {
        old = componentPointer<T>( c ? c->id() : T::s_id() );
    } catch (...) {
        old = 0;
    }
    if (old == c) return;
    if (old) deleteComponent( old, !(flags & KeepOld) );
    m_components[c ? c->id() : T::s_id()] = c;
    if (c) {
        c->setOwnerCache( this );
        if ( !( flags & AvoidNotify ) )
            notifyPostRebuild( c );
    }
}

template<typename T>
void Cache::registerObserver( Observer *o ) {
    registerObserver(o, T::s_id() );
}

template<typename T>
void Cache::deregisterObserver( Observer *o ) {
    deregisterObserver(o, T::s_id() );
}

inline void Cache::registerObserver( Observer *o, std::string c ) {
    m_observers[c].insert(o);
}

inline void Cache::deregisterObserver( Observer *o, std::string c ) {
    m_observers[c].erase(o);
}

template<typename T> T *Cache::componentPointer( std::string s ) const {
    ComponentMap::const_iterator i = m_components.find( s );
    if (i == m_components.end())
        return 0;
    T &t = downcast<T>( i->second );
    return &t;
}

inline Cache &Global::get( Cache *my ) {
    return my ? *my : (s_cache ? (*s_cache) : *(s_cache = new Cache ()));
}
inline Cache *Global::getPointer( Cache *my ) {
    return &get( my );
}
inline void Global::setCache( Cache *c ) {
    if ( c == s_cache ) return; delete s_cache; s_cache = c;
}

}
}

#endif
