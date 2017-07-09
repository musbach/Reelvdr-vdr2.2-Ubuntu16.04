#!/bin/bash

# Version wanted for gcc/g++
# currently this _must_ be 3.3 so don't touch it
GCC_MAJOR=3
GCC_MINOR=3
GCC_SUB4GEN2=6

#export GCC_MAJOR GCC_MINOR GCC_SUB4GEN2

# unset this if you don't have ccache (but it is highly (!) recommended to use ccache)
export CCACHE=ccache


CURDIR=`pwd`
cd ..
DOWNLOADSDIR=`pwd`/downloads
cd $CURDIR

TEMPDIR=`pwd`/temp
#OSSDIR=`pwd`/src/build

# check version for gcc/g++
. build/.test4cc.sh $GCC_MAJOR $GCC_MINOR $GCC_SUB4GEN2


if [ ! -d $TEMPDIR ] ; then
	mkdir -p $TEMPDIR
fi


eval `grep DISTRIB_DESCRIPTION /etc/lsb-release`
case $DISTRIB_DESCRIPTION in
	"Ubuntu 6.06")
		echo "$DISTRIB_DESCRIPTION not supported any longer. Please upgrade to Ubuntu 7.04."
		exit 1
		;;
	"Ubuntu 6.10")
		HOST_OS=ubuntu610
		;;
	"Ubuntu 7.04")
		HOST_OS=ubuntu704
		;;
	"Ubuntu 7.10")
		HOST_OS=ubuntu710
		;;
	"Ubuntu14.04")
		HOST_OS=ubuntu1404
		;;
	*)
		if [ -f .hostos ] ; then
			HOST_OS=`cat .hostos`
		else
			echo "Please tell me your host OS. Possible values are: "
			echo "   suse92 | gentoo-2006.0 | gentoo-2006.1 | ubuntu610 | ubuntu704 | ubuntu710"
			read HOST_OS
		fi
		;;
esac


for filelist in build/scripts/filelist-base-$HOST_OS build/scripts/filelist-misc-$HOST_OS ; do
	if [ ! -f $filelist ] ; then
		echo "Sorry, can't find filelist $filelist. Please check your input or create one."
		exit 1
	else
		echo $HOST_OS > .hostos
	fi
done
export  HOST_OS

BUILD=`cat .build`
echo $((++BUILD)) > .build
export BUILD

case $1 in
	release)
		RELEASE=true
		FACTORY=false
		;;
	factory)
		RELEASE=true
		FACTORY=true
		;;
	*)
		RELEASE=false
		FACTORY=false
esac

export RELEASE
export FACTORY

# workaround for dd/gettext 0.14.5 used by ubuntu 6.06
unset LANG


echo "Starting make"
make all REELBOX_ISO=$CURDIR/ReelBox.iso HOST_OS=$HOST_OS

if [ $? = 0 ] && [ -f .autoburn ] ; then
	`dirname $0`/blank+burn.sh
fi
