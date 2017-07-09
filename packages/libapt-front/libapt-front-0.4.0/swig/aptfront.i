%module(directors="1",dirprot="1") aptfront

%{
#include <apt-pkg/pkgcache.h>
#include <apt-pkg/depcache.h>

#include <apt-front/init.h>
#include <apt-front/error.h>
#include <apt-front/sources.h>
#include <apt-front/manager.h>
#include <apt-front/actor.h>

#include <apt-front/utils/paths.h>

#include <apt-front/cache/cache.h>
#include <apt-front/cache/observer.h>
#include <apt-front/cache/entity/entity.h>
#include <apt-front/cache/entity/package.h>
#include <apt-front/cache/entity/tag.h>
#include <apt-front/cache/entity/version.h>

#include <apt-front/cache/component/packagetags.h>
#include <apt-front/cache/component/packages.h>
#include <apt-front/cache/component/tags.h>

#include <apt-front/cache/component/debtags/expression.h>
#include <apt-front/cache/component/debtags/update.h>
#include <apt-front/cache/component/debtags/utils.h>

#include <apt-front/predicate/combinators.h>
#include <apt-front/predicate/predicate.h>
#include <apt-front/predicate/factory.h>

using namespace aptFront;
using namespace aptFront::cache;
using namespace aptFront::cache::entity;
using namespace aptFront::utils;
//using namespace aptFront::predicate;

using namespace Tagcoll;
%}


#ifdef SWIGPYTHON
%include "python.i"
#endif

// these forward declarations are needed
// unfortunately, we cannot use <apt-front/forward.h>
// since swig chokes on template< typename >

namespace Tagcoll {
class Consumer;
class Collection;
class InputMerger;
class StdioParserInput;
}

namespace aptFront {

namespace utils {
class Path;
}

namespace cache {
class Cache;
class Observer;
class Global;

namespace component {
class Base;
class Packages;
class State;
class PackageFile;
class Records;
class PackageTags;
class Tags;
}

namespace entity {
class Base;
class Entity;
class Version;
class Package;
class Facet;
class Tag;
}

namespace predicate {
struct Argument;
struct Base;
struct Predicate;
}

}

namespace actor {
class Actor;
}

}

/* Tagcoll */
/* ======= */

%include "tagcoll.i"

/* apt-pkg */
/* ======= */

%include <apt-pkg/pkgcache.h>
%include <apt-pkg/error.h>


/* aptFront */
/* ======== */

%include <apt-front/utils/shared.h>
%include <apt-front/utils/paths.h>

/* only use init() from apt-front/init.h */
void init();


%include <apt-front/error.h>
%include <apt-front/progresscallback.h>
%include <apt-front/manager.h>

// return nested structs or use them as arguments, ignored for now
%ignore aptFront::Sources::add;
%ignore aptFront::Sources::disable;
%ignore aptFront::Sources::enable;
%ignore aptFront::Sources::entries;

%include <apt-front/sources.h>
%include <apt-front/manager.h>


/* aptFront::cache */
/* =============== */

%include <apt-front/cache/cache.h>
%include <apt-front/cache/observer.h>

/* aptFront::cache::entity */
/* ======================= */

// returns nested struct, currently ignored
%ignore aptFront::cache::entity::Package::state;

%include <apt-front/cache/entity/package.h>
%include <apt-front/cache/entity/tag.h>
%include <apt-front/cache/entity/version.h>


/* aptFront::cache::component */
/* ========================== */

%include <apt-front/cache/component/base.h>

%include <apt-front/cache/component/packagetags.h>

// used by C++ iterator, not needed
%ignore aptFront::cache::component::Packages::packagesBegin;
%ignore aptFront::cache::component::Packages::packagesEnd;
%ignore aptFront::cache::component::Packages::packageData;

%include <apt-front/cache/component/packages.h>

// return protected struct, compilation fails if not ignored
%ignore aptFront::cache::component::Tags::facetData;
%ignore aptFront::cache::component::Tags::tagData;

%include <apt-front/cache/component/tags.h>

// returns nested struct, ignored for now
%ignore aptFront::cache::component::Records::record;

%include <apt-front/cache/component/records.h>

// returns nested struct, ignored for now
%ignore aptFront::cache::component::State::packageState;

%include <apt-front/cache/component/state.h>

%include <apt-front/cache/component/history.h>

/* aptFront::cache::component::debtags */
/* =================================== */

%include <apt-front/cache/component/debtags/expression.h>
%include <apt-front/cache/component/debtags/update.h>
%include <apt-front/cache/component/debtags/utils.h>

%template(TagToFacet_P) aptFront::cache::component::debtags::TagToFacet<aptFront::cache::entity::Package>;

/* aptFront::predicate */
/* =================== */

//TODO: add template instantiations, use them with ssearch
%include <apt-front/predicate/combinators.h>

// ignore for sanity...
%ignore aptFront::predicate::Argument;
%ignore aptFront::predicate::Base;
%ignore aptFront::utils::prettyPrint;
%include <apt-front/predicate/predicate.h>

%include <apt-front/predicate/factory.h>


#ifdef SWIGPYTHON
%include "python-module-code.i"
#endif
