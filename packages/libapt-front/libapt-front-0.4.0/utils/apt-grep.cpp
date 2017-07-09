// Author: Enrico Zini with help from Peter Rockai
// License: GPL


#include <apt-front/init.h>
#include <apt-front/cache/cache.h>
#include <apt-front/cache/entity/package.h>
#include <apt-front/cache/entity/version.h>
#include <apt-front/cache/component/packages.h>
#include <apt-front/predicate/factory.h>
#include <apt-front/predicate/matchers.h>

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

int main(int argc, char* argv[])
{
    printClocks( "start" );
    aptFront::init();
    printClocks( "init" );

    Cache &c = cache::Global::get();
	// Opens the package cache
	// 0 is a pointer to an optional OpProgress object for status feedback
	c.open(cache::Cache::OpenDefault
           | cache::Cache::OpenReadOnly
           | cache::Cache::OpenDebtags);
    printClocks( "cache opened" );
	
	// Access the package cache
	cache::component::Packages& pc = c.packages();
	
    cache::entity::Package p;
    utils::Range< entity::Package > fr = filteredRange(
        pc.range(), predicate::Package::description( "exim" ) ), fre = fr.end(), bfr = fr;

    while ( fr != fre ) {
        std::cout << fr->name() << std::endl;
        fr.advance();
    }
    printClocks( "done" );

    while ( bfr != fre ) {
        std::cout << bfr->name() << std::endl;
        bfr.advance();
    }
    printClocks( "reiterated" );
	
	return 0;
}
