#!/usr/bin/env python

import aptfront
import sys

aptfront.aptFrontInit()
cache = aptfront.Global_cache()
if not cache.openCacheFile(aptfront.OpProgress(), aptfront.Cache.OpenReadOnly):
    print "Error opening cache file"
    error = aptfront.getGlobalError()
    error.DumpErrors()

pc = cache.packageCache()

callback = aptfront.ProgressCallback()
callback.thisown = 0 # flip to 1 and see it segfault...
ptr = aptfront.SharedPtrProgressCallback(callback)

print "python test suite running..."
# write tests :-)
print "done: <summary>"
