/** -*- C++ -*-
    @file utils/comparable.h
    @author Peter Rockai <me@mornfall.net>
*/

#ifndef APTFRONT_UTILS_COMPARABLE_H
#define APTFRONT_UTILS_COMPARABLE_H

namespace aptFront {
namespace utils {

template< typename Self >
struct Comparable {
    const Self &self() const { return *static_cast< const Self * >( this ); }
    bool operator>( const Self &o ) const { return not ( self() < o || self() == o ); }
    bool operator==( const Self &o ) const { return not ( self() < o || o < self() ); }
};

}
}

#endif
