#!/usr/bin/env python

import aptfront
import sys

aptfront.init()
cache = aptfront.getCache()
cache.open(aptfront.Cache.OpenDefault | aptfront.Cache.OpenReadOnly)

pc = cache.packages()

for pkg in pc:
    print "Package: " + pkg.name()
    for V in pkg:
        print "Version: " + V.versionString()
        print "Section: " + V.section()
        print "Architecture: " + V.architecture()
        print "Description: " + V.shortDescription() + V.longDescription()
