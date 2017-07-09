/** -*- C++ -*-
 * @file cache/component/history.h
 * @author Peter Rockai <me@mornfall.net>
 */

#include <apt-front/cache/cache.h>
#include <apt-front/cache/component/base.h>
#include <apt-front/error.h>
#include <deque>
#include <iostream>
#include <algorithm>

#ifndef CACHE_COMPONENT_HISTORY_H
#define CACHE_COMPONENT_HISTORY_H

namespace aptFront {
namespace cache {
namespace component {

/**
   This class template implements an undo history for an arbitrary
   cache component. However, this component absolutely must have
   a deep-copying copy constructor!
 */
template<typename T>
class History : public Implementation<History<T> >, public Observer {
protected:
    typedef std::deque< T * > TDeque;
    TDeque m_redo;
    TDeque m_undo;
    T * m_current;

    int m_limit;
    bool m_winding:1;
    bool m_autoCheckpoint;

public:

    History( int limit = 16 )
        : m_current( 0 ), m_limit( limit ), m_winding( false ), m_autoCheckpoint( false )
    {
        // clear() to be called in setOwnerCache
        // std::cerr << "history constructed..." << std::endl;
    }
    virtual ~History() {}

    virtual bool allowClose() {
        return false;
    }

    void setAutoCheckpoint( bool b ) {
        m_autoCheckpoint = b;
    }

    virtual void notifyPreRebuild( component::Base * ) {
        // std::cerr << "pre rebuild, winding = " << m_winding << std::endl;
        if ( !m_winding ) {
            clear(); // nuke the old stuff
        }
    }

    virtual void notifyPreChange( component::Base * ) {
        if ((!m_winding) && m_autoCheckpoint)
            checkpoint();
    }

    virtual void notifyPostRebuild( component::Base * ) {
        if ( !m_winding ) {
            clear();
        }
        // std::cerr << "post rebuild, winding = " << m_winding << std::endl;
    }

    void setOwnerCache( Cache *c ) {
        if (m_winding)
            throw exception::InternalError( "history tried to wind while winding" );
        Implementation<History<T> >::setOwnerCache( c );
        // OBSERVER API NEEDS TO BE FUCKING FIXED
        /* and the set(Owner)Cache crap synced somewhat */
        setCache( c ); // for Observer
        observeComponent< T >(); // this really should NOT go to ctor
        clear();
    }

    T &current() {
        return *m_current;
        /* T *cur = &(this->ownerCache()->template component<T>());
        m_current = std::find( m_queue.begin(), m_queue.end(), cur );
        if (m_current == m_queue.end())
            clear();
            return **m_current; */
    }

    T &previous() {
        return m_undo.back();
    }

    void undo(int steps = 1) {
        if ( m_winding )
            throw exception::InternalError( "history tried to wind while winding" );
        if ( !canUndo( steps ) )
            throw exception::InternalError( "history tried to unwind into void" );
        for ( int i = 0; i < steps; ++i ) {
            m_redo.push_back( m_current );
            m_current = m_undo.back();
            m_undo.pop_back();
        }
        m_winding = true;
        this->ownerCache()->addComponent( m_current, Cache::KeepOld );
        m_winding = false;
    }

    void redo(int steps = 1) {
        if ( m_winding )
            throw exception::InternalError( "history tried to wind while winding" );
        if ( !canRedo( steps ) )
            throw exception::InternalError( "history tried to unwind into void" );
        for ( int i = 0; i < steps; ++i ) {
            m_undo.push_back( m_current );
            m_current = m_redo.back();
            m_redo.pop_back();
        }
        m_winding = true;
        this->ownerCache()->addComponent( m_current, Cache::KeepOld );
        m_winding = false;
    }

    bool canUndo( int steps = 1 ) {
        return m_undo.size() >= steps;
    }

    bool canRedo( int steps = 1 ) {
        return m_redo.size() >= steps;
    }

    bool winding() const {
        return m_winding;
    }

    struct kill {
        Cache *c;
        T *cur;
        void operator()( T *t ) {
            if (t == &(c->template component<T>())) return;
            // c->deleteComponent( t );
            delete t;
        }
        kill( Cache *_c, T *_t ) : c( _c ), cur( _t ) {}
    };

    void checkpoint() {
        clearRedo();
        T *x;
        m_undo.push_back( x = new T( current() ) );
        x->setAllowDelete( false );
        while ( m_undo.size() > m_limit )
           m_undo.pop_front();
    }

    void setSizeLimit( int x ) {
        m_limit = x;
    }

    void clearDeque( TDeque &s ) {
        std::for_each( s.begin(), s.end(),
                       kill( this->ownerCache(), m_current ) );
        s.clear();
    }

    void clearRedo() { clearDeque( m_redo ); }
    void clearUndo() { clearDeque( m_undo ); }

    void clear() {
        clearRedo();
        clearUndo();
        if ( m_current != &(this->ownerCache()->template component<T>()) ) {
            delete m_current;
            m_current = &(this->ownerCache()->template component<T>());
            m_current->setAllowDelete( false );
        }
    }

    static std::string componentName();
};

}
}
} 

#endif
