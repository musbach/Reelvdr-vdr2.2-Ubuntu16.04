#!/bin/sh
#
# GDL server
# 

# RC: triggered by udev / gdl_server

pre_start () { 
    echo "GDL-server: pre-start"
    #modprobe gdl_mm
    rm -rf /dev/gdl/ || true
    mkdir -p /dev/gdl
    count=0
    echo waiting for gdl module to appear
    while ! grep -q gdl /proc/devices ; do
	sleep 1
	count=`expr $count + 1`
    done
    echo waited ${count}sec for gdl to appear
    /sbin/create_dev.sh make_dev gdl gdl/0
    /sbin/create_dev.sh make_dev gdl_track gdl/track

    chmod 666 /dev/gdl/*

    ulimit -c unlimited
}

post_start () {

    modprobe pd_inttvenc_cvbs

    # Query SOC name and load TV encoder only if supported
    SOC_NAME=`get_soc_info_utility NAME STRING 2>/dev/null`

    case "$SOC_NAME" in
        "SOC_NAME_CE5300")
            ;;
        *)
            echo "load component TV encoder..."
            modprobe pd_inttvenc_comp
            ;;
    esac

}
#end script

case $1 in
	""|start)
		pre_start && \
		gdl_udaemon && \
		post_start
		;;
	stop)
		killall gdl_udaemon
		;;
	*)
		echo "no such option $1. Use 'stop' or 'start'"
		;;
esac


