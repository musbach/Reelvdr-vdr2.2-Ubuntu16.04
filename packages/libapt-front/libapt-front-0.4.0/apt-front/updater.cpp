#include <apt-front/updater.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>

/*
#include <ept/init.h>
#include <ept/path.h>
#include <ept/cache/apt/packages.h>
#include <ept/cache/debtags/tagmap.h>
#include <ept/cache/debtags/vocabulary.h>
*/

namespace aptFront {

//ept::configuration::apt::cache::Aggregator* Updater::m_agg = 0;

void Updater::updatePackageTags()
{
	system("/usr/bin/debtags update --reindex");
	/*
	if (m_agg == 0)
		m_agg = new ept::configuration::apt::cache::Aggregator;
	ept::configuration::apt::cache::TagMap& tm = m_agg->tagMap();
	*/
}

void Updater::updateTags()
{
	system("/usr/bin/debtags update --reindex");
	/*
	if (m_agg == 0)
		m_agg = new ept::configuration::apt::cache::Aggregator;
	ept::configuration::apt::cache::Vocabulary& voc = m_agg->vocabulary();
	*/
}

void Updater::updatePkgIdx()
{
	system("/usr/bin/debtags update --reindex");
	// TagMap in turn wants PkgIdx, so we can delegate to that
	//Updater::updatePackageTags();
}

static std::string cached_rcdir;

std::string Updater::rcdir()
{
	if (cached_rcdir.empty())
	{
		struct passwd* udata = getpwuid(getuid());
		cached_rcdir = udata->pw_dir;
		cached_rcdir += "/.debtags/";
	}

	return cached_rcdir;
}

void Updater::setupForTests()
{
	/*
#define TEST_CACHE_DIR TEST_DIR
	ept::Path::setDebtagsSourceDir( TEST_CACHE_DIR "debtags/" );
	ept::Path::setDebtagsIndexDir( TEST_CACHE_DIR "debtags/" );
	ept::Path::setDebtagsUserSourceDir( TEST_CACHE_DIR "debtags/user/" );
	ept::Path::setDebtagsUserIndexDir( TEST_CACHE_DIR "debtags/user/" );
	ept::Init::s_globalDone = true;
	ept::init();
	*/
}

}

//#include <ept/cache/apt/packages.tcc>
//#include <ept/cache/debtags/tagmap.tcc>

