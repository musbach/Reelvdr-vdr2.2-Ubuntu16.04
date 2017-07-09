#!/bin/sh
#
# quick & dirty shell based installer of xxv for debian lenny
# 
# ./install-debian.sh
#
# $Id$
#

XXVSOURCE=`pwd`

if [ ! -e /usr/share/man/man1 ] ; then
  echo 'Install Manpage'
  cp doc/xxvd.1 /usr/share/man/man1
fi 

if [ ! -e /etc/logrotate.d/xxvd ] ; then
  echo 'Logrotate'
  cp etc/logrotate.d/xxvd /etc/logrotate.d/xxvd
fi 

if [ ! -e /usr/bin/vdr2jpeg ] ; then
  echo 'install vdr2jpeg'
  apt-get install vdr2jpeg
fi

echo 'install PerlModules'

apt-get install \
  perl \
  perl-base \
  perl-modules \
  libio-zlib-perl \
  libconfig-tiny-perl \
  libdate-manip-perl \
  libdbd-mysql-perl \
  libdbi-perl \
  libfont-ttf-perl \
  libdigest-hmac-perl \
  libevent-perl \
  libgd-gd2-perl libgd-graph-perl libgd-graph3d-perl libgd-text-perl \
  txt2html \
  libhtml-tree-perl \
  libjson-perl \
  libwww-perl \
  liblinux-inotify2-perl \
  liblocale-gettext-perl \
  libmp3-info-perl \
  libnet-amazon-perl \
  libnet-xmpp-perl \
  libproc-processtable-perl \
  libsoap-lite-perl \
  libtemplate-perl \
  libhtml-template-perl \
  liburi-perl \
  libxml-rss-perl \
  libxml-simple-perl

if [ ! -e /etc/init.d/mysql ] ; then
apt-get install \
    mysql-server
fi 

echo 'start mysql server'
/etc/init.d/mysql start


echo 'create Database'
cat contrib/create-database.sql | mysql -u root

if [ ! -e "~/.xxvd.cfg" ]; then
  echo 'DB connectstring write in config'
  echo '[General]' >> ~/.xxvd.cfg
  echo 'DSN=DBI:mysql:database=xxv;host=localhost;port=3306' >> ~/.xxvd.cfg
  echo 'PWD=xxv' >> ~/.xxvd.cfg
  echo 'USR=xxv' >> ~/.xxvd.cfg
fi

if [ ! -e "/etc/init.d/xxvd" ]; then
  echo 'create Startscript'
  sed -e 's/FOLDER=\".+?\"/FOLDER=\"$XXVSOURCE\"/' etc/xxvd > /etc/init.d/xxvd
  chmod a+x /etc/init.d/xxvd
  RVV=`runlevel | cut -d " " -f 2`
  if [ ! -e "/etc/rc$RVV.d/S90xxvd" ]; then
    ln -s /etc/init.d/xxvd "/etc/rc$RVV.d/S90xxvd"
  fi
fi

echo 'Start XXV'
/etc/init.d/xxvd restart

echo 'read the Logfile'
tail -f /var/log/xxvd.log

echo 'Now you can call a browser to address:'
echo 'http://your_vdr:8080/'
echo 'have Fun'


