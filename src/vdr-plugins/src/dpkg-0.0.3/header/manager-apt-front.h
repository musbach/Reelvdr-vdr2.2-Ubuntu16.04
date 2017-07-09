#include "packagemanager-apt-pkg.h"
#include "acquire-apt-pkg.h"

#include "error-apt-front.h"
#include <apt-front/utils/shared.h>
#include "progresscallback-apt-front.h"
#include <apt-front/cache/cache.h>

#ifndef APT_FRONT_PACKAGEMANAGER_H
#define APT_FRONT_PACKAGEMANAGER_H

namespace aptFront {

namespace exception {
class OperationCancelled:Exception{};
}

/*
   brief Sync cache changes to system, update cache (apt-get update).

   This class encapsulates all actions libapt-front could be doing and that
   will have an impact on the state of the system. It can update the cache
   or commit the changes done in cache to the system (downloading required
   archives in the process). The ::update interface should work with all
   available cache components (including debtags), so all you need to do
   is call manager.update(). You can construct and throw away
   PackageManager objects at will.
*/
class Manager {
public:
    Manager( cache::Cache *c = 0 );
    ~Manager();
    /*
       @brief Commit changes done in the associated cache to system.

       You can only call this when Cache is in consistent state, exception
       will be thrown otherwise. commit will use the associated
       ProgressCallback object to report download and install progress.
    */
    void commit();

    void download();

    /*
       @brief Update the cache ala apt-get update.

       This will do a normal cache update, possibly clearing the changed
       cache states. It will use the associated ProgressCallback object
       to report download and parsing progress.

       Returns true if the operation was successfull (false if not)
    */
    void update();

    // set a ProgressCallback to be used to report progress in update and commit
    void setProgressCallback( SharedPtr<ProgressCallback> progress);
    
    void setUpdateInterval( unsigned interval ) {
        m_updateInterval = interval;
    }

protected:
    void getArchives();
    void fetch();
    void createFetcher();

    cache::Cache *m_cache;
    SharedPtr<ProgressCallback> m_progress;
    unsigned m_updateInterval;
    pkgPackageManager *m_pm;
    pkgAcquire *m_fetcher;
};

}

#endif
