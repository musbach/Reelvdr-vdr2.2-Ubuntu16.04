/** -*- C++ -*-
    @file forward.h
    @author Peter Rockai <me@mornfall.net>
*/

#include <apt-pkg/pkgcache.h> // eww

#ifndef APTFRONT_FORWARD_H
#define APTFRONT_FORWARD_H

namespace aptFront {

namespace utils {
template< typename > struct Range;
template< typename > struct Consumer;
}

namespace actor {
template< typename > struct Collection;
template< typename > struct Global;
template< typename > struct Actor;
template< typename > struct Bound;
template< typename > struct FromMember;
}

namespace predicate {
template <typename> struct Predicate;
}

namespace cache {
class Cache;
class Observer;
class Global;

namespace component {
class Base;
class Packages;
class PackagesPointer;
class State;
class PackageFile;
class Records;
class PackageTags;
class Tags;
class MasterMMap;

namespace debtags {
class PackageIntConverter;
class PackageStringConverter;
class FacetIntConverter;
class FacetStringConverter;
class TagIntConverter;
class TagStringConverter;
}
}

namespace entity {
class Entity;
template< typename > class PackageT;
typedef PackageT< component::PackagesPointer > Package;
template< typename > class VersionT;
typedef VersionT< pkgCache::Version * > Version;
class StableVersion;
class Relation;
}

}

}

namespace ept {
namespace debtags {
class Vocabulary;
}
}

#endif
