#!/usr/bin/env python

import aptfront
import string
import sys

class MyProgressCallback(aptfront.ProgressCallback):
    def UpdatePulse(self,a,b,c):
        print "\rUpdatePulse %s %s %s              " % (a,b,c),

if len(sys.argv) < 2:
    print "%s: need argument" % sys.argv[0]
    print "supports: update, install $pkgs"
    sys.exit(1)

# init
aptfront.aptFrontInit()
error = aptfront.getGlobalError()
cache = aptfront.CacheGlobal_cache()

# open cache
if not cache.openCacheFile(aptfront.OpProgress(), aptfront.Cache.OpenReadOnly):
    print "Error opening cache file"
    error.DumpErrors()

# update
if string.strip(sys.argv[1]) == "update":
    # get a packagemanager
    pm = aptfront.PackageManager(cache)
    # and a callback object
    callback = MyProgressCallback()
    ptr = aptfront.SharedPtrProgressCallback(callback)
    pm.setProgressCallback(ptr)
    print ptr.data()
    # do the udpate
    pm.update()
# install
elif string.strip(sys.argv[1]) == "install":
    pc = cache.pkgCache()
    for pkg in sys.argv[2:]:
        it = pc.packageByName(pkg)
        if it != None:
            it.markInstall()
    pm = aptfront.PackageManager(cache)
    progress = MyProgressCallback()
    callback = aptfront.SharedPtrProgressCallback(progress)
    pm.setProgressCallback(callback)
    pm.commit()

# show any erros
error.DumpErrors()
