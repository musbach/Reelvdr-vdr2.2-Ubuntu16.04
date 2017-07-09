#!/bin/sh
#=========================================================================
#  This file is provided under a dual BSD/GPLv2 license.  When using or 
#  redistributing this file, you may do so under either license.
#
#  GPL LICENSE SUMMARY
#  BSD LICENSE 
#==========================================================================

# Script name can be the called name, or something more meaningful.
SCRIPTNAME=$0
PATH=/usr/local/bin:/usr/bin:/bin:/sbin:/usr/sbin

#. /etc/init.d/init_utilities

start_function() {
    # Install the platform config module
    #try_command insmod /lib/modules/platform_config.ko

    # Setup the appropriate platform configuration
    SOC_NAME=`get_soc_info_utility NAME STRING 2>/dev/null`
    DIR=/etc/platform_config
    APP=platform_config_app
    PMR_APP=config_pmrs

    MemTotal=$(grep MemTotal /proc/meminfo | awk '{print $2}')
    #TODO: should we use memmap= param from command line?
    #      eval base address: printf "0x%x\n" $(($MyMem*1024*1024))
    if [ $MemTotal -gt 190000 ] && [ $MemTotal -lt 200000 ]; then
        MyMem=200
        BaseAddr=0xC800000
    elif
       [ $MemTotal -gt 250000 ] && [ $MemTotal -lt 256000 ]; then
        MyMem=256
        BaseAddr=0x10000000
    elif
       [ $MemTotal -gt 500000 ] && [ $MemTotal -lt 512000 ]; then
        MyMem=512
        BaseAddr=0x20000000
    elif
       [ $MemTotal -gt 600000 ] && [ $MemTotal -lt 616000 ]; then
        MyMem=616
        BaseAddr=0x26800000
    elif
       [ $MemTotal -gt 1000000 ] && [ $MemTotal -lt 1100000 ]; then
        MyMem=1024
        BaseAddr=0x40000000
    elif
       [ $MemTotal -gt 1550000 ] && [ $MemTotal -lt 1600000 ]; then
        MyMem=1536
        BaseAddr=0x60000000
    fi
    BaseAddrCalc=$(printf "0x%x\n" $(($MyMem*1024*1024)))

    #echo "MyMem:    $MyMem" > /tmp/platform.config.out
    #echo "BaseAddr: $BaseAddr" >> /tmp/platform.config.out
    #echo "BaseAddrCalc: $BaseAddrCalc" >> /tmp/platform.config.out

    case "$SOC_NAME" in
    SOC_NAME_CE4100)
	sed -i s/media_base_address.*/"media_base_address = $BaseAddr \/* $MyMem Megabytes *\/ }"/ /etc/platform_config/ce4100.hcfg
        $APP load $DIR/ce4100.hcfg
        $APP load $DIR/ce4100/memory_layout_512M.hcfg platform.memory.layout
        ;;
    SOC_NAME_CE4200)
	sed -i s/media_base_address.*/"media_base_address = $BaseAddr \/* $MyMem Megabytes *\/ }"/ /etc/platform_config/ce4200.hcfg
        $APP load $DIR/ce4200.hcfg
	$APP load $DIR/ce4200/memory_layout_1G.hcfg platform.memory.layout
        ;;
    SOC_NAME_CE5300)
	sed -i s/media_base_address.*/"media_base_address = $BaseAddr \/* $MyMem Megabytes *\/ }"/ /etc/platform_config/ce5300.hcfg
        $APP load $DIR/ce5300.hcfg
	$APP load $DIR/ce5300/memory_layout_1G.hcfg platform.memory.layout
        ;;
    *)
	echo "Unrecognized or unsupported processor ID: \"$SOC_NAME\""	
        exit 1
        ;;
    esac

    # Configure the PMRs and base addresses from the memory layout
    $PMR_APP
        
    $APP execute platform.startup

    # Uncomment this command to dump the database created by processing the
    # config files.  Good for regression testing changes.
    # The sed removes the trailing "id" comment output by the dump app.
    #
    #   $APP dump | sed 's; */\* id .*;;' > /$SOC_NAME.txt
}

stop_function() {
    # Remove the platform config module
    rmmod platform_config
}

case $1 in
    "start")
        start_function
        ;;
    "stop")
        stop_function
        ;;
    "restart")
        stop_function
        start_function
        ;;
    *)
        echo "Usage: $0 {start|stop|restart}"
        ;;
esac
