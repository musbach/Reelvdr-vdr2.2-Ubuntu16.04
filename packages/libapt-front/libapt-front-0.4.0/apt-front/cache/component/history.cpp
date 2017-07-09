/**
   @file cache/component/history.cpp
   @author Peter Rockai <me@mornfall.net>
*/

#include <apt-front/cache/component/history.h>
#include <apt-front/cache/component/state.h>

using namespace aptFront::cache;
using namespace aptFront::cache::component;

template<typename T>
string History<T>::componentName() { return "History"; }

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"

namespace tut {

struct cache_component_history_shar {
    Cache c;
    cache_component_history_shar() {
        aptInit();
        c.open( Cache::OpenDefault | Cache::OpenReadOnly );
        c.addComponent( new History<State>() );
    }
    History< State > &h() {
        return c.component<History<State> >();
    }
};

TESTGRP( cache_component_history );

template<> template<>
void to::test<1>()
{
    Packages::PackageRange r = c.packages().range();
    while ( r->name() != "exim4" ) r.advance();
    while (!r->canInstall()) {
        r.advance();
    }
    entity::Package p = *r;
    h().checkpoint();
    p.markInstall();
    ensure( p.markedInstall() );
    ensure( !h().canRedo() );
    ensure( h().canUndo() );
    h().undo();
    ensure( !h().canUndo() );
    ensure( !p.markedInstall() );
    ensure( h().canRedo() );
    h().redo();
    ensure( !h().canRedo() );
    ensure( p.markedInstall() );
    h().undo();
    h().checkpoint();
    p.markInstall();
    ensure( p.markedInstall() );
    ensure( !h().canRedo() );
    ensure( h().canUndo() );
    h().undo();
    ensure( !p.markedInstall() );
    ensure( h().canRedo() );
    ensure( !h().canUndo() );
}

template<> template<>
void to::test<2>()
{
    Packages::PackageRange r = c.packages().range();
    while ( r->name() != "exim4" ) r.advance();
    while (!r->canInstall()) {
        r.advance();
    }
    entity::Package p = *r;

    h().checkpoint();
    p.markInstall();
    ensure( p.markedInstall() );
    ensure( !h().canRedo() );
    ensure( h().canUndo() );
    h().undo();
    ensure( !h().canUndo() );
    ensure( !p.markedInstall() );
    ensure( h().canRedo() );
    c.reopen();
    ensure( !h().canUndo() );
    ensure( !h().canRedo() );
}

template<> template<>
void to::test<3>()
{
    Packages::PackageRange r = c.packages().range();
    while ( r->name() != "exim4" ) r.advance();
    while (!r->canInstall()) {
        r.advance();
    }
    entity::Package p = *r;

    h().checkpoint();
    p.markInstall();
    ensure( p.markedInstall() );
    ensure( !h().canRedo() );
    ensure( h().canUndo() );
    h().undo();
    ensure( !h().canUndo() );
    ensure( !p.markedInstall() );
    ensure( h().canRedo() );
    h().redo();
    c.reopen();
    ensure( !h().canUndo() );
    ensure( !h().canRedo() );
}

template<> template<>
void to::test<4>()
{
    Packages::PackageRange r = c.packages().range();
    while ( r->name() != "exim4" ) r.advance();
    while (!r->canInstall()) {
        r.advance();
    }
    entity::Package p = *r;

    h().setAutoCheckpoint( true );
    p.markInstall();
    ensure( p.markedInstall() );
    ensure( !h().canRedo() );
    ensure( h().canUndo() );
    h().undo();
    ensure( !h().canUndo() );
    ensure( !p.markedInstall() );
    ensure( h().canRedo() );
    h().redo();
    c.reopen();
    ensure( !h().canUndo() );
    ensure( !h().canRedo() );

    r = c.packages().range();
    while ( r->name() != "exim4" ) r.advance();
    while (!r->canInstall()) {
        r.advance();
    }
    p = *r;

    p.markInstall();
    ensure( h().canUndo() );
    ensure( !h().canRedo() );
    p.markRemove();
    ensure( h().canUndo() );
    ensure( !h().canRedo() );
    h().undo();
    ensure( h().canUndo() );
    ensure( h().canRedo() );
    h().undo();
    ensure( !h().canUndo() );
    h().redo();
    ensure( h().canUndo() );
    ensure( h().canRedo() );
}

}

#endif
