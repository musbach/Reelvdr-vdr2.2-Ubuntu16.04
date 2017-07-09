/** -*- C++ -*-
    @file cache/entity/entity.cpp
    @author Peter Rockai <me@mornfall.net>
*/

#include <apt-front/cache/entity/entity.h>

using namespace std;
using namespace aptFront::cache;
using namespace aptFront::cache::entity;

#ifdef COMPILE_TESTSUITE
#include <apt-front/cache/entity/package.h>
#include <apt-front/cache/entity/relation.h>
#include "test-utils.h"
namespace tut {

    struct iterator_shar {
        iterator_shar () {
            aptInit ();
            c.open( Cache::OpenDefault | Cache::OpenReadOnly );
        }
        Cache c;
        entity::Package a;
    };
    typedef test_group<iterator_shar> tg;
    typedef tg::object to;
    tg iterator_tg ("iterator");

    /* void iteratorType (Iterator i, Iterator::Type t)
    {
        ensure_equals (i . type (), t);
    } */

    void tryPackage (entity::Package p)
    {}

    template<> template<>
    void to::test<1> () // test Iterator::type ()
    {
        entity::Relation b;
        Entity i( b );
        ensure( i == b );
        Entity j;
        j = b;
        ensure( j == i );
        ensure( j == b );
        entity::Relation c;
        c = j;
        ensure( c == b );
        ensure( c == i );
    }

    template<> template<>
    void to::test<2> ()
    {
        entity::Package a;
        entity::Relation b;
        Entity i (a);
        ensure( i == a );
        tryPackage( i );
        i = b;
        ensure( i == b );
        int check = 1;
        try {
            tryPackage( i );
            check = 2;
        } catch (std::bad_cast) {
            check = 3;
        }
        ensure_equals( check, 3 );
    }

    template<> template<>
    void to::test<3> ()
    {
        Entity i, j;
        ensure(i == j);
    }

    template<> template<>
    void to::test<4> ()
    {
        Entity i, j (new entity::Package);
        ensure(! (i == j));
    }

    template<> template<>
    void to::test<5> ()
    {
        Entity i, j (new entity::Package);
        ensure (i != j);
    }

template<> template<>
void to::test<6> ()
{
    typedef std::vector<entity::Entity> vector;
    entity::Package p;
    vector::iterator i;
    vector v(c.packages().packagesBegin(),
          c.packages().packagesEnd());
    std::set<entity::Entity> s( v.begin(), v.end() );
    ensure (s.size() > 1);
}

}
#endif
