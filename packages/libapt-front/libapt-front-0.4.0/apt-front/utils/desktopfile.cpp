#include <fstream>
#include "desktopfile.h"

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"

namespace tut {

using namespace aptFront;
using namespace aptFront::utils;

struct utils_desktopfile_shar {
    utils_desktopfile_shar() {
    }
};

TESTGRP( utils_desktopfile );

template<> template<>
void to::test< 1 >() {
    DesktopFile f;
    std::string t = "[wee]\n";
    t += "Foo=bar\n";
    std::istringstream i( t );
    i >> f;
    ensure_equals( f.group( "wee" ).name, "wee" );
    ensure_equals( f.group( "wee" ).entry( "Foo" ).value, "bar" );
}

template<> template<>
void to::test< 2 >() {
    DesktopFile f;
    std::string t = "# comment\n[wee]\n";
    t += "Foo=bar\n";
    std::istringstream i( t );
    i >> f;
    ensure_equals( f.group( "wee" ).name, "wee" );
    ensure_equals( f.group( "wee" ).entry( "Foo" ).value, "bar" );
}

template<> template<>
void to::test< 3 >() {
    DesktopFile f;
    std::string t = "  # spaced comment\n[wee]\n";
    t += "Foo=bar\n";
    std::istringstream i( t );
    i >> f;
    ensure_equals( f.group( "wee" ).name, "wee" );
    ensure_equals( f.group( "wee" ).entry( "Foo" ).value, "bar" );
}

template<> template<>
void to::test< 4 >() {
    DesktopFile f;
    std::string t = "\n[wee]\n";
    t += "Foo=bar\n";
    std::istringstream i( t );
    i >> f;
    ensure_equals( f.group( "wee" ).name, "wee" );
    ensure_equals( f.group( "wee" ).entry( "Foo" ).value, "bar" );
}

template<> template<>
void to::test< 5 >() {
    DesktopFile f;
    std::string t = "[wee]\n";
    t += "# Foo=bar\n";
    t += "Foo=dang\n";
    t += "# Foo=baz\n";
    std::istringstream i( t );
    i >> f;
    ensure_equals( f.group( "wee" ).name, "wee" );
    ensure_equals( f.group( "wee" ).entry( "Foo" ).value, "dang" );
    ensure_equals( f.group( "wee" ).entry( "# Foo" ).value, "" );
}

template<> template<>
void to::test< 6 >() {
    DesktopFile f;
    std::string t = "[wee]\n";
    t += "Foo=da ng\n";
    std::istringstream i( t );
    i >> f;
    ensure_equals( f.group( "wee" ).name, "wee" );
    ensure_equals( f.group( "wee" ).entry( "Foo" ).value, "da ng" );
}

template<> template<>
void to::test< 7 >() {
    DesktopFile f;
    std::string t = "[wee]\n";
    t += "Foo=da ng\n\n";
    t += "Zee=gherkin\n";
    std::istringstream i( t );
    i >> f;
    ensure_equals( f.group( "wee" ).name, "wee" );
    ensure_equals( f.group( "wee" ).entry( "Foo" ).value, "da ng" );
    ensure_equals( f.group( "wee" ).entry( "Zee" ).value, "gherkin" );
}

template<> template<>
void to::test< 8 >() {
    DesktopFile f;
    std::string t = "\n[wee]\n";
    t += "Foo=da ng\n";
    std::istringstream i( t );
    i >> f;
    ensure_equals( f.group( "wee" ).name, "wee" );
    ensure_equals( f.group( "wee" ).entry( "Foo" ).value, "da ng" );
}

}

#endif
