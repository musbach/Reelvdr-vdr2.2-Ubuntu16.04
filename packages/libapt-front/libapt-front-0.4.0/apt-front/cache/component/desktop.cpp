/**
 * @file cache/component/desktop.cpp
 * @author Peter Rockai <me@mornfall.net>
 */

#include <dirent.h>
#include <unistd.h>
#include <fstream>
#include <sstream>

#include <apt-front/cache/component/desktop.h>
#include <apt-front/utils/desktopfile.h>

using namespace aptFront::cache;
using namespace component;

string Desktop::componentName() { return "Desktop"; }

Desktop::Desktop()
    : m_policy( &m_defaultPolicy )
{
}

void Desktop::setPolicy( GroupPolicy *p ) {
    m_policy = p;
}

std::string Desktop::GroupPolicy::groupForCategories( Categories c ) {
    if ( c == c.end() ) return "Unknown";
    return *c;
}

Desktop::~Desktop() {}

struct Category {
    std::string name;
    operator std::string() const { return name; }
};

std::istream &operator >>( std::istream &i, Category &cat ) {
    char c;
    cat.name = "";
    while ( i.peek() != EOF ) {
        c = i.get();
        if ( c == ';' ) return i;
        cat.name += c;
    }
    return i;
}

void Desktop::Entry::load( std::string f ) {
    std::ifstream i( f.c_str() );
    if ( !i.is_open() )
        return; // throw?
    utils::DesktopFile e;
    i >> e;
    i.close();
    utils::DesktopFile::Group &g = e.group( "Desktop Entry" );
    m_name = g.entry( "Name" ).value;
    m_description = g.entry( "Comment" ).value;
    if ( m_description == "" )
        m_description = g.entry( "GenericName" ).value;
    m_package = g.entry( "X-AppInstall-Package" ).value;
    // m_group = g.entry( "Categories" ).value;
    m_icon = g.entry( "Icon" ).value;
    setCategories( g.entry( "Categories" ).value );
}

void Desktop::Entry::setCategories( std::string s )
{
    // std::cerr << "Desktop::Entry::setCategories( '" << s << "' )" << std::endl;
    utils::VectorRange< std::string > v;
    std::istringstream i( s );
    std::copy( std::istream_iterator< Category >( i ),
               std::istream_iterator< Category >(), utils::consumer( v ) );
    // std::cerr << "setCategories: " << v.size() << std::endl;
    m_categories = v;
}

void Desktop::loadDirectory( std::string dir ) {
    // read in the output and dump it to stdout
    // std::cerr << "loadDirectory " << dir << std::endl;
    DIR *d = opendir( dir.c_str() );
    if ( !d ) return;
    dirent *ent = 0;
    while ( ( ent = readdir( d ) ) != 0 ) {
        string name( ent->d_name ), line;
        if ( name == "." || name == ".." )
            continue;
        std::string::size_type off = name.find( ".desktop" );
        if ( off != name.length() - std::string( ".desktop" ).length() )
            continue;
        string f = dir + "/" + name;

        // skip directories
        DIR *d = opendir( f.c_str() );
        if ( d ) { closedir( d ); continue; }

        // std::cerr << "loading " << f << std::endl;
        Entry e;
        e.load( f );
        if ( e.name() != "" )
            add( e );
    }
}


#ifdef COMPILE_TESTSUITE
#include "test-utils.h"

namespace tut {
using namespace ::aptFront;
using namespace ::aptFront::cache;

struct cache_component_desktop_shar {
    cache_component_desktop_shar() {
        aptInit();
        c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    }
    component::Desktop comp() {
        return c.component< component::Desktop >(); }
    typedef component::Desktop::Entry Entry;
    typedef component::Desktop::EntityRange EntityRange;
    cache::Cache c;
};

TESTGRP( cache_component_desktop );

template<> template<>
void to::test<1>() {
    const char *check[] = { "foo", "baz", "wee" };
    c.addComponent( new component::Desktop() );
    comp().add( Entry( "foo", "bar", "", "", "" ) );
    comp().add( Entry( "baz", "bar", "", "", "" ) );
    comp().add( Entry( "wee", "bble", "", "", "" ) );
    EntityRange r = comp().entries();
    int i = 0;
    while ( r != r.end() ) {
        ensure_equals( r->name(), check[ i ] );
        ++r; ++i;
    }
}

template<> template<>
void to::test<2>() {
    const char *g1[] = { "foo", "baz" };
    const char *g2[] = { "wee" };
    c.addComponent( new component::Desktop() );
    comp().add( Entry( "foo", "bar", "", "", "" ) );
    comp().add( Entry( "baz", "bar", "", "", "" ) );
    comp().add( Entry( "wee", "bble", "", "", "" ) );

    EntityRange r = comp().group( "bar" );
    int i = 0;
    while ( r != r.end() ) {
        ensure_equals( r->name(), g1[ i ] );
        ++r; ++i;
    }
    ensure_equals( i, 2 );

    r = comp().group( "bble" );
    i = 0;
    while ( r != r.end() ) {
        ensure_equals( r->name(), g2[ i ] );
        ++r; ++i;
    }
    ensure_equals( i, 1 );
}

template<> template<>
void to::test<3>() {
    const char *check[] = { "bar", "bble" };
    c.addComponent( new component::Desktop() );
    comp().add( Entry( "foo", "bar", "", "", "" ) );
    comp().add( Entry( "baz", "bar", "", "", "" ) );
    comp().add( Entry( "wee", "bble;", "", "", "" ) );
    utils::Range< std::string > r = comp().availableGroups();
    int i = 0;
    while ( r != r.end() ) {
        // std::cerr << *r << std::endl;
        ensure_equals( *r, check[ i ] );
        ++r; ++i;
    }
    ensure_equals( i, 2 );
}

template<> template<>
void to::test<4>() {
    c.addComponent( new component::Desktop() );
    Entry foo[] = {
        Entry( "foo", "bar", "postfix", "", "" ),
        Entry( "baz", "bar", "exim4", "", "" ),
        Entry( "wee", "bble", "dictd", "", "" ) };
    for ( int i = 0; i < 3; ++i )
        comp().add( foo[i] );
    EntityRange r = comp().entries();
    int i = 0;
    while ( r != r.end() ) {
        ensure_equals( r->package().name(), foo[i].package() );
        ++r; ++i;
    }
    ensure_equals( i, 3 );
}

template<> template<>
void to::test<5>() {
    c.addComponent( new component::Desktop() );
    comp().loadDirectory( TEST_DIR "/desktop" );
    EntityRange r = comp().entries();
    int i = 0;
    while ( r != r.end() ) {
        if ( r->name() == "XQF" )
            ensure_equals( r->group(), "X-SuSE-Core-Game" );
        else if ( r->name() == "X-Server" )
            ensure_equals( r->group(), "Qt" );
        else if ( r->name() == "Kdict" ); // nothing for now
        else ensure( false );
        ++r; ++i;
    }
    ensure_equals( i, 3 );
}

template<> template<>
void to::test<6>() {
    c.addComponent( new component::Desktop() );
    comp().loadDirectory( TEST_DIR "/desktop" );
    EntityRange r = comp().entries();
    int i = 0;
    while ( r != r.end() ) {
        if ( r->name() == "XQF" ) {
            ensure_equals( r->group(), "X-SuSE-Core-Game" );
        }
        else if ( r->name() == "X-Server" ) {
            ensure_equals( r->group(), "Qt" );
        }
        else if ( r->name() == "Kdict" ); // nothing for now
        else ensure( false );
        ++r; ++i;
    }
    ensure_equals( i, 3 );
}

template<> template<>
void to::test<7>() {
    c.addComponent( new component::Desktop() );
    comp().loadDirectory( TEST_DIR "/desktop" );
    EntityRange r = comp().entries();
    int i = 0;
    while ( r != r.end() ) {
        if ( r->name() == "XQF" ) {
            ensure_equals( r->categories().current(), "X-SuSE-Core-Game" );
            ensure_equals( r->categories().next().current(), "Application" );
            ensure_equals( r->categories().next().next().current(), "Game" );
        }
        else if ( r->name() == "X-Server" ) {
            ensure_equals( r->categories().current(), "Qt" );
            ensure_equals( r->categories().next().current(), "KDE" );
            ensure_equals( r->categories().next().next().current(), "X-KDE-information" );
        }
        else if ( r->name() == "Kdict" ); // nothing for now
        else ensure( false );
        ++r; ++i;
    }
    ensure_equals( i, 3 );
}

template<> template<>
void to::test<8>() {
    c.addComponent( new component::Desktop() );
    comp().loadDirectory( TEST_DIR "/desktop" );
    EntityRange r = comp().entries();
    int i = 0;
    while ( r != r.end() ) {
        if ( r->name() == "Kdict" ) {
            ensure_equals( r->description(), "Online Dictionary" );
            ++i;
        }
        ++r;
    }
    ensure_equals( i, 1 );
}

}

#endif
