/** -*- C++ -*-
    @file utils/consumer.cpp
    @author Peter Rockai <me@mornfall.net>
*/

#include <apt-front/utils/consumer.h>
using namespace aptFront;

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"
#include <list>

namespace tut {
using namespace aptFront::utils;

struct utils_consumer_shar {
};

TESTGRP( utils_consumer );

template<> template<>
void to::test<1> ()
{
    std::list<int> a;
    a.push_back( 10 );
    a.push_back( 20 );
    Range< int > r = range( a.begin(), a.end() );
    std::list<int> b;
    ensure( a != b );
    Consumer< int > c = consumer< int >( back_inserter( b ) );
    std::copy( r, r.end(), c );
    ensure( a == b );
}

}

#endif
