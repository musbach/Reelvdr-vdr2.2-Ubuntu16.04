/** -*- C++ -*-
    @file cache/observer.cpp
    @author Peter Rockai <me@mornfall.net>
*/

#include <apt-front/cache/observer.h>
#include <apt-front/cache/cache.h>

using namespace aptFront::cache;

Observer::Observer (Cache *c)
    : m_cache (0)
{
    setCache( c );
}

Observer::Observer(const Observer &o)
    : m_registrations( o.m_registrations ), m_cache( 0 )
{
    setCache( o.m_cache );
}

void Observer::unobserveAll() {
    for (Registrations::iterator i = m_registrations.begin();
            i != m_registrations.end(); ++i)
        Global::get(m_cache).deregisterObserver(this, *i);
}

void Observer::setCache( Cache *c ) {
    unobserveAll();
    m_cache = c;
    for (Registrations::iterator i = m_registrations.begin();
            i != m_registrations.end(); ++i)
        Global::get(m_cache).registerObserver(this, *i);
}

Observer::~Observer ()
{
    unobserveAll();
}


#ifdef COMPILE_TESTSUITE
#include "test-utils.h"
#include <apt-front/cache/component/state.h>

namespace tut {

struct cache_observer_shar {
    cache_observer_shar () {
        aptInit ();
    }
    OpProgress progress;
};

TESTGRP( cache_observer );

class TestObserver : public Observer {
public:
    TestObserver(Cache *c=0) : Observer (c) {
        observeComponent<component::State>();
    }
    virtual void notifyPreRebuild(component::Base *c) {
        try {
            if (c != &Global::get(m_cache).component<component::State>())
                throw -1;
            throw 22;
        } catch (int i) {
            throw i;
        } catch (...) {}
    }
};

class Test2Observer : public Observer {
public:
    component::Base *m_mycomp;
    Test2Observer(Cache *c=0) : Observer (c) {
        observeComponent<component::State>();
    }
    virtual void notifyPreRebuild(component::Base *c) {
        m_mycomp = c;
    }
    virtual void notifyPostRebuild(component::Base *c) {
        if (c == m_mycomp)
            throw -1;
        throw 42;
    }
};

template<> template<>
void to::test<1> ()
{
    Global::get().open( Cache::OpenDefault | Cache::OpenReadOnly);
    TestObserver *o = new TestObserver;
    int a = 0;
    try {
        Global::get().reopen();
        ensure(0);
    } catch (int e) {
        ensure_equals (e, 22);
        a = e;
    }
    ensure_equals( a, 22 );
    delete o;
}

template<> template<>
void to::test<2> ()
{
    Global::get().open( Cache::OpenDefault | Cache::OpenReadOnly);
    Test2Observer *o = new Test2Observer;
    int a = 0;
    try {
        Global::get().reopen();
        ensure(0);
    } catch (int e) {
        ensure_equals (e, 42);
        a = e;
    }
    ensure_equals( a, 42 );
    delete o;
}

}

#endif
