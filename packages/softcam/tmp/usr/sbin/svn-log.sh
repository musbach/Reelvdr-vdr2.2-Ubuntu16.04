#!/bin/sh

#
# SVN Log Viewer
#

if [ -f "/tmp/svn.log" ]; then
  rm -f /tmp/svn.log
fi

cd /tmp
wget http://www.onlinelaufwerk.de/reel/svn.log
cat /tmp/svn.log
