#!/bin/sh

# RC: triggered by udev / sec_kernel module
# taken from original init.d/sec

. /etc/default/globals
#exec > /tmp/load_hdmi.log 2>&1

   # load SEC kernel driver
    SOC_NAME=`get_soc_info_utility NAME STRING 2>/dev/null`

    case "$SOC_NAME" in
        "SOC_NAME_CE3100" | \
        "SOC_NAME_CE4200" | \
        "SOC_NAME_CE5100" | \
        "SOC_NAME_CE5300")
            #try_command insmod /lib/modules/sec_kernel.ko
            #make_dev sec sec
            ;;
        "SOC_NAME_CE4100")
            #try_command insmod /lib/modules/sec_kernel.ko
            #make_dev sec sec
            FW_FILE=`find  /lib/firmware/sec -name sec_fw_4000.ce4100`
            if [ -z "$FW_FILE" ];then
                FW_FILE=`find  /lib/firmware/sec -name sec_fw_4000*ce4100`
            fi
            echo $FW_FILE
            if [ -n "$FW_FILE" ];then
                /sbin/sec_init_tdp $FW_FILE
            fi
            ;;
        default)
            echo "Unknown SOC: '$SOC_NAME'"
            exit 0
            ;;
    esac

