#!/usr/bin/env python

import aptfront
import sys

aptfront.aptFrontInit()
cache = aptfront.CacheGlobal_cache()
if not cache.openCacheFile(aptfront.OpProgress(), aptfront.Cache.OpenReadOnly):
    print "Error opening cache file"
    error = aptfront.getGlobalError()
    error.DumpErrors()

pc = cache.pkgCache()

it = pc.packageByName(sys.argv[1])
print "Mark install: %s " % it.name()
it.markInstall()
print "Marked install: %s" % it.markedInstall()

prog = aptfront.CacheProgress()
cache.commit(prog)
