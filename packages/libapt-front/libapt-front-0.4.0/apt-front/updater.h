/** -*- C++ -*-
	@file init.h
	@author Peter Rockai <me@mornfall.net>
*/

#ifndef APTFRONT_UPDATER_H
#define APTFRONT_UPDATER_H

#include <string>

//#include <ept/forward.h>
//#include <ept/configuration/apt.h>

namespace aptFront {

class Updater
{
   //static ept::configuration::apt::cache::Aggregator* m_agg;

public:
    static void updatePackageTags();
    static void updateTags();
    static void updatePkgIdx();

    static std::string rcdir();

    static void setupForTests();
};

}

#endif
