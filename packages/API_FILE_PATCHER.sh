#!/bin/sh

# changed api version

APIVERSION=`grep 'define APIVERSION ' ../src/vdr-2.1.6/config.h | awk '{ print $3 }' | sed -e 's/"//g' `
APIVERSION14=`grep 'define APIVERSION ' ../src/vdr-1.4/config.h | awk '{ print $3 }' | sed -e 's/"//g' `
echo new APIVERSION for vdr 2.1 is $APIVERSION, for vdr 1.4 it is $APIVERSION14

PATCHLIST="\
           reelvdr-external-epg/files \
           reelvdr-output-ice/files \
           reelvdr-output-rbmini/files \
           reelvdr-output-reelbox/files \
           reelvdr-pi-amarokstarter/files \
           reelvdr-pi-avahi/files \
           reelvdr-pi-bouquets/files \
           reelvdr-pi-channelscan/files \
           reelvdr-pi-childlock/files \
           reelvdr-pi-dpkg/files \
           reelvdr-pi-eepg/files \
           reelvdr-pi-formatdisk/files \
	   reelvdr-pi-graphlcd/files \
           reelvdr-pi-games/files \
           reelvdr-pi-media/files \
           reelvdr-pi-mcli/files \
           reelvdr-pi-musicbrowser/files \
	   reelvdr-pi-netwatcher/files \
           reelvdr-pi-pip/files \
           reelvdr-pi-rotor/files \
           reelvdr-pi-reelblog/files \
           reelvdr-pi-reelcam/files \
           reelvdr-pi-reelchannellist/files \
           reelvdr-pi-reelepg/files \
           reelvdr-pi-remote/files \
           reelvdr-pi-skinreel3/files \
           reelvdr-pi-timeline/files \
           reelvdr-pi-txtsubs/files \
           reelvdr-pi-vlcclient/files \
	   reelvdr-pi-webbrowser/files \
           reelvdr-plugins-base/files \
           reelvdr-plugins-base/files-mini \
           reelvdr-plugins-dvd/files \
           "

for file in $PATCHLIST ; do

        if [ -f ${file}-14.04 ] ; then
            echo "changing $file-14.04"
            sed -e "s/2.1.[0-9][0-9].[0-9]*\t*/$APIVERSION\t/g" -i ${file}-14.04
        fi

	if [ -f ${file}-10.04 ] ; then
	    echo "changing $file-10.04"
	    sed -e "s/1.7.[0-9][0-9].[0-9]*\t*/$APIVERSION\t/g" -i ${file}-10.04
	else
	    echo "changing $file"
	    sed -e "s/1.7.[0-9][0-9].[0-9]*\t*/$APIVERSION\t/g" -i ${file}
        fi
	if [ -f ${file}-mini ] ; then
	    echo "changing $file-mini"
	    sed -e "s/1.7.[0-9][0-9].[0-9]*\t*/$APIVERSION\t/g" -i ${file}-mini
	fi

	if [ -f ${file}-8.04 ] ; then
	    echo "changing $file-8.04"
	    sed -e "s/1.4.[0-9][0-9].[0-9]*\t*/$APIVERSION14\t/g" -i ${file}-8.04
	fi
	#sed -e "s/1.7.(.*\t)/$APIVERSION\t/g" -i ${file}-10.04
	#svn revert ${file}-10.04
	#sed -e "s/vdr-1.7/vdr-1.7/g" -i ${file}-10.04

done
