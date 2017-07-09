/** -*- C++ -*-
    @file utils/prettyprint.h
    @author Peter Rockai <me@mornfall.net>
*/

#include <string>
#ifndef APTFRONT_UTILS_PRETTYPRINT_H
#define APTFRONT_UTILS_PRETTYPRINT_H

namespace aptFront {
namespace utils {

template< typename T >
std::string prettyPrint( const T & ) { return ""; }

template<>
inline std::string prettyPrint( const std::string &s ) { return s; }

}
}

#endif
