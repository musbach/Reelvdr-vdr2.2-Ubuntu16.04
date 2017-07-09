/** -*- C++ -*-
	@file cache/component/base.h
	@author Peter Rockai <me@mornfall.net>
*/

#ifndef CACHE_COMPONENT_BASE_H
#define CACHE_COMPONENT_BASE_H
#include <apt-front/cache/cache.h>

namespace aptFront {
namespace cache {
namespace component {
/**
   @brief Common cache component base.
   
   Internal interfaces for Cache interaction. Deriving
   component::Implementation is preferred instead of this class.
   
   @author Peter Rockai <me@mornfall.net>
 */
class Base {
protected:
    Cache *m_ownerCache;
    bool m_allowDelete:1;
    bool m_allowClose:1;
public:
    Cache *ownerCache () const { return m_ownerCache; }
    Cache &cache() const { return cache::Global::get( m_ownerCache ); }
    virtual void setOwnerCache (Cache *c) { m_ownerCache = c; }
    virtual std::string id() const = 0;
    virtual ~Base() {}
    void setAllowDelete( bool e ) { m_allowDelete = e; }
    void setAllowClose( bool e ) { m_allowClose = e; }
    virtual bool allowDelete() { return m_allowDelete; }
    virtual bool allowClose() { return m_allowClose; }
    Base() : m_ownerCache( 0 ), m_allowDelete( true ),
             m_allowClose( true ) {}
};

template <typename Child, typename Base = Base>
class Implementation: public Base {
public:
    static std::string s_id() {
        return typeid(Child).name();
    }

    std::string id() const {
        return s_id();
    }

    void notifyPreChange() {
        this->ownerCache()->notify( this, &cache::Observer::notifyPreChange );
    }

    void notifyPostChange() {
        this->ownerCache()->notify( this, &cache::Observer::notifyPostChange );
    }

};

}
}
}

#endif
