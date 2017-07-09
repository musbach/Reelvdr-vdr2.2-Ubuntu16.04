/**
 * @file cache/component/records.cpp
 * @author Peter Rockai <me@mornfall.net>
 */

#include <apt-front/cache/component/records.h>
#include <apt-front/cache/entity/version.h>
#include <apt-front/cache/component/packages.h>
#include <apt-front/error.h>
#include <ept/apt/recordparser.h>
#include <iostream>
#include <map>

using namespace aptFront::cache;
using namespace aptFront::cache::component;

string Records::componentName() { return "Records"; }

Records::Records()
    : m_records(0)
{
}

Records::~Records()
{
}

void Records::setOwnerCache(Cache *c)
{
    Base::setOwnerCache(c);
    delete m_records;
    m_records = new pkgRecords( ownerCache()->packages().baseReference() );
    m_vector.resize(ownerCache()->packages().packageCount());
}

const Records::Record &Records::record( entity::Version v )
{
    if (!m_records)
        throw 1; // XXX
    Map &map = m_vector[v.package().id()];
    Map::iterator i = map.find(v);
    if (i != map.end())
        return i->second;
    pkgCache::VerFileIterator Vf;
    pkgRecords::Parser *parser = 0;
    Vf = v.fileList();
    if (Vf.end())
        throw 0; // XXX
    parser = &(m_records->Lookup(Vf));
    Record rec;
    rec.shortDescription = parser->ShortDesc();
    rec.longDescription = parser->LongDesc();
    rec.maintainer = parser->Maintainer();
    rec.fileName = parser->FileName();
    rec.source = parser->SourcePkg();
    rec.md5sum = parser->MD5Hash();
    map[v] = rec;
    m_vector[v.package().id()] = map;
    return map[v];
}

std::string Records::aptTagData( entity::Version v ) const
{
    if (!m_records)
        throw 1; // XXX
    pkgCache::VerFileIterator Vf;
    pkgRecords::Parser *parser = 0;
    Vf = v.fileList();
    if (Vf.end())
        throw 0; // XXX
    parser = &(m_records->Lookup(Vf));
    const char *start, *stop;
    parser->GetRec(start, stop);

    // Access the right part of the mmapped buffer
    std::string str(start, stop-start);
    ept::apt::RecordParser rec(str);
    return rec["Tag"];
}

bool component::Records::preload()
{
    throw exception::NotImplemented("component::Records preloading");
}

#ifdef COMPILE_TESTSUITE
#include <apt-pkg/progress.h>
#include "test-utils.h"

namespace tut {

struct cache_component_records_shar {
    cache_component_records_shar () {
        aptInit ();
    }
    OpProgress progress;
};
  
TESTGRP(cache_component_records);

template<> template<>
void to::test<1> ()
{
    component::Records *rc;
    Cache c;
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    rc = &c.records();
    entity::Package p = c.packages().packageByName("postfix");
    component::Records::Record rec = rc->record(p.installedVersion());
    ensure_equals( rec.shortDescription, "A high-performance mail transport agent" );
}

template<> template<>
void to::test<2> ()
{
    component::Records *rc;
    Cache c;
    c.open( Cache::OpenDefault | Cache::OpenReadOnly );
    rc = &c.records();
    entity::Package p = c.packages().packageByName("postfix");
    component::Records::Record rec = rc->record(p.installedVersion());
    ensure_equals( rec.shortDescription, "A high-performance mail transport agent" );
    rec = rc->record(p.installedVersion());
    ensure_equals( rec.shortDescription, "A high-performance mail transport agent" );
}
}
#endif
