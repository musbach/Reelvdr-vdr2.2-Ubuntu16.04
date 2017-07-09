#include <fstream>
#include "sources.h"

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"
#include <apt-pkg/configuration.h>

namespace tut {

using namespace aptFront;
using namespace aptFront::utils;

struct sources_shar {
    sources_shar() {
        aptInit();
    }
};

TESTGRP( sources );

template<> template<>
void to::test< 1 >() {
    Sources s;
    std::ifstream f( _config->FindFile("Dir::Etc::sourcelist").c_str() );
    f >> s;
    Range< Sources::Entry > r = s.entries();
    int i = 0;
    while (r != r.end()) {
        if (i < 3) {
            ensure_equals( r->type(), Sources::Entry::Binary );
            ensure_equals( r->url(), "ftp://ftp.sk.debian.org/debian" );
            ensure_equals( r->distribution(), "unstable" );
            ensure_equals( r->components(), "main " );
            if (i > 0)
                ensure(! r->enabled() );
            else
                ensure( r->enabled() );
        } else {
            ensure_equals( r->type(), Sources::Entry::Comment );
            if (i == 3)
                ensure_equals( r->comment(), "# a fancy comment, actually :-)" );
            if (i == 4)
                ensure_equals( r->comment(), "  # and another, but smarter" );
        }
        ++ r; ++ i;
    }
    ensure_equals (i, 5);
}

template<> template<>
void to::test< 2 >() {
    Sources s;
    VectorRange< std::string > r;
    r.consume( "blah" );
    r.consume( "foo" );
    s.add( Sources::Entry( true, Sources::Entry::Binary,
                           "http://test.me", "purr", r ) );
    std::ostringstream y;
    y << s;
    ensure_equals( y.str(), "deb http://test.me purr blah foo \n" );
}

template<> template<>
void to::test< 3 >() {
    Sources s;
    std::string t = "deb cdrom:[fancy stuff]/isnt-it/ unstable main\n";
    std::istringstream i( t );
    i >> s;
    Range< Sources::Entry > r = s.entries();
    ensure_equals( r->typeString(), "deb" );
    ensure_equals( r->url(), "cdrom:[fancy stuff]/isnt-it/" );
    ensure_equals( r->distribution(), "unstable" );
    ensure_equals( r->components(), "main " );
}

}

#endif
