// Author: Enrico Zini with help from Peter Rockai
// License: GPL


#include <apt-front/init.h>
#include <apt-front/cache/cache.h>
#include <apt-front/cache/entity/package.h>
#include <apt-front/cache/entity/version.h>
#include <apt-front/cache/component/packages.h>

#include <iostream>
#include <ctype.h>
#include <time.h>

void printClocks(const char *msg) {
    static clock_t t = 0;
    clock_t x = clock();
    std::cerr << msg << "; last = " << t / 1000.0
              << ", current = " << x / 1000.0
              << ", diff = " << (x - t) / 1000.0 << std::endl;
    t = x;
}


using namespace aptFront;
using namespace cache;
using namespace std;

static void printTags(cache::entity::Package i)
{
	std::set<ept::debtags::Tag> ts = i.tags();
	if (!ts.empty())
	{
		cout << "Tags: ";
		for (std::set<ept::debtags::Tag>::const_iterator it = ts.begin(); it != ts.end(); it++)
			if (it == ts.begin())
				cout << it->fullname();
			else
				cout << ", " << it->fullname();
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
    printClocks( "start" );
    aptFront::init();
    printClocks( "init" );

	// Opens the package cache
	// 0 is a pointer to an optional OpProgress object for status feedback
	cache::Global::get().open(cache::Cache::OpenDefault
                              | cache::Cache::OpenReadOnly
                              | cache::Cache::OpenDebtags);
    printClocks( "cache opened" );
	
	// Access the package cache
	cache::component::Packages& pc = cache::Global::get().packages();
	
    typedef vector<cache::entity::Package> PV;
    typedef vector<cache::entity::Version> VV;
    PV l;
    // pc.packages( back_inserter( l ) );
    printClocks( "vector initialised" );
	for (component::Packages::iterator i = pc.packagesBegin(); i != pc.packagesEnd(); ++i)
	{
		if (!i->candidateVersion().valid())
		{
			cout << "Package: " << i->name() << endl;
			cout << "Section: " << i->section() << endl;
			printTags(*i);
			//cout << "No version" << endl;
		} else {
			//List<VersionIterator> versions = i.versionList().begin();
			//VersionIterator vi = versions.begin();
			cache::entity::Version cv = i->candidateVersion();
			string record = cv.completeRecord();

			/* Trim trailing spaces */
			while (record.size() > 0 && isspace(record[record.size() - 1]))
				record.resize(record.size() - 1);

			/* Place the tags just after Section */
			string::size_type pos = record.find("\nSection:");
			pos = record.find('\n', pos + 1);
			cout << record.substr(0, pos) << endl;
			printTags(*i);
			cout << record.substr(pos + 1) << endl;
		}
		cout << endl;
	}
    printClocks( "done" );
	
	return 0;
}
