/** -*- C++ -*-
    @file cache/observer.h
    @author Peter Rockai <me@mornfall.net>
*/

#ifndef CACHE_OBSERVER_H
#define CACHE_OBSERVER_H
#include <set>
#include <string>

#include <apt-front/forward.h>

namespace aptFront {
namespace cache {

/**
   @brief Base class for Cache observers.

   Derive this class (and reimplement (some of) the notify* methods to
   have your class receive notifications of changes in the cache. You
   will have to call registerComponent() to tell the class which cache
   components should be observed. Also, don't forget to pass the Cache
   pointer to the constructor if you posses one.

   @todo Possibly remove the =0 default argument for constructor
   to make it harder to omit by mistake?
   
   @see Cache
   @author Peter Rockai <me@mornfall.net>
 */

class Observer {
public:
    Observer( Cache *c = 0 );
    Observer( const Observer & );
    virtual void notifyPreChange(component::Base *) {}
    virtual void notifyPostChange(component::Base *) {}
    virtual void notifyPreRebuild(component::Base *) {}
    virtual void notifyPostRebuild(component::Base *) {}
    virtual void setCache( Cache *c );
    template <typename T> void observeComponent();
    virtual void unobserveAll();
    virtual ~Observer();
protected:
    typedef std::set<std::string> Registrations;
    Registrations m_registrations;
    Cache *m_cache;
};

}
}

#include <apt-front/cache/cache.h>

namespace aptFront {
namespace cache {
template <typename C>
void Observer::observeComponent()
{
    m_registrations.insert(C::s_id());
    Global::getPointer(m_cache)->template registerObserver<C>( this );
}
}
}

#endif
