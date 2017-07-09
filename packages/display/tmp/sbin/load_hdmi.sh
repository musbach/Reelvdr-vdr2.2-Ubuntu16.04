#!/bin/sh

# RC: triggered by udev / sec_kernel module

. /etc/default/globals
#exec > /tmp/load_hdmi.log 2>&1

c=0
while [ ! -c /dev/sec ] ; do
	sleep 1
	c=$((c+1))
done

/usr/sbin/load_pd /usr/lib/pd_hdmi.so

if [ $? = 0 ] ; then
        Syslog "successfully loaded pd_hdmi.so, waited $c sec for /dev/sec"
else
        Syslog "Error: FAILED loading pd_hdmi.so, waited $c sec for /dev/sec"
fi
