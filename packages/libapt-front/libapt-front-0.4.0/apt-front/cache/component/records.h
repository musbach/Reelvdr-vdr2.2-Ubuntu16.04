/**  -*-C++-*-
 * @file cache/component/records.h
 * @author Peter Rockai <me@mornfall.net>
 */
#ifndef _RECORDSCACHE_H
#define _RECORDSCACHE_H
#include <apt-pkg/pkgrecords.h>
#include <apt-front/cache/cache.h>
#include <apt-front/cache/component/base.h>
#include <apt-front/forward.h>
#include <map>
#include <vector>

class pkgPolicy;

namespace aptFront {
namespace cache {
namespace component {

/**
 * Interface to the textual data as provided by libapt-pkg via its own parser
 */
class Records : public Implementation<Records> {
    // XXX: we shouldn't blindly hold m_records pointer, because
    // its own pointer to cache can disappear from below our hands... sigh
public:
    struct Record {
        std::string shortDescription;
        std::string longDescription;
        std::string maintainer;
        std::string md5sum, source, fileName;
    };
    Records();
    virtual ~Records();
    const Record &record( entity::Version v );
    std::string aptTagData( entity::Version v ) const;
    bool preload();
    virtual void setOwnerCache( Cache *c );

    /* pkgRecord conversion
    Records( pkgRecords *P ); */
    operator pkgRecords*() const {
        return m_records;
    }

    static std::string componentName();

protected:
    typedef std::map<entity::Version,Record> Map;
    typedef std::vector<Map> Vector;
    Vector m_vector;
    // Map m_map;
    pkgRecords *m_records;
    
};

}
}
}
#endif
