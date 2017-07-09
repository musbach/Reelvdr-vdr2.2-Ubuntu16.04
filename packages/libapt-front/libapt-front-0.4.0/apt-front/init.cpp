#include <apt-pkg/init.h>
#include <apt-front/init.h>
#include <libintl.h>

namespace aptFront {

Init::FunctionDeque *Init::s_functions = 0;
bool Init::s_done = false;
bool Init::s_globalDone = false;

void init() {
    Init::FunctionDeque::iterator i;
    for (i = Init::s_functions->begin();
         i != Init::s_functions->end();
         ++ i) {
        (*i)();
    }
    Init::s_done = true;
};

namespace {
void globalinit() {
    if (! Init::s_globalDone) {
        pkgInitConfig(*_config);
        pkgInitSystem(*_config, _system);
        textdomain( "libapt-front" );
    }
    Init::s_globalDone = true;    
}
Init global( globalinit );
}

}

#ifdef COMPILE_TESTSUITE
#include "test-utils.h"
#include <apt-pkg/configuration.h>
#include <apt-pkg/error.h>
#include <apt-pkg/pkgsystem.h>
#include <apt-pkg/init.h>
#include <apt-front/cache/cache.h>
#include <apt-front/init.h>
#include <apt-front/utils/paths.h>

namespace tut {

using namespace aptFront;
using namespace cache;
using namespace component;

#define CACHE_DIR TEST_DIR

void aptInit () {
    static bool done = false;
    if (done)
        return;
    done = true;
    pkgInitConfig (*_config);
    _config->Set("Dir", CACHE_DIR);
    _config->Set("Dir::Cache", "cache");
    _config->Set("Dir::State", "state");
    _config->Set("Dir::Etc", "etc");
    _config->Set("Dir::State::status", CACHE_DIR "dpkg-status");
    pkgInitSystem (*_config, _system);
    aptFront::utils::Path::setStateDir( CACHE_DIR "debtags" );
    aptFront::utils::Path::setDebtagsDownloadDir( CACHE_DIR "debtags" );
    aptFront::utils::Path::setDebtagsConfigDir( CACHE_DIR "debtags" );
    aptFront::Init::s_globalDone = true;
    aptFront::init();
    debtagsInit();
    // _config -> Set ("Capture::Cache::UseExtState", extstate);
}

void debtagsInit() {
    static bool done = false;
    if (done)
        return;
    done = true;
    //debtags::generateIndexes();
    //debtags::fetchNewData();
}

}
#endif
