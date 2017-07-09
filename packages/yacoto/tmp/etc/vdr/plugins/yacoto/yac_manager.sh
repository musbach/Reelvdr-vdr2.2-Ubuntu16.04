#!/bin/bash
sleep 10
YAC_DIR="${YAC_DIR:=/etc/vdr/plugins/yacoto}"

if [ "$(pidof -o %PPID -x $0)" != "" ] ; then
   logger -s "$0 is already running"
   exit
fi

YAC_CONF_DIR="${YAC_CONF_DIR:=/etc/vdr/plugins/yacoto}"
YAC_CONF="${YAC_CONF_DIR}/yacoto.conf"


if [ ! -f $YAC_CONF ] ; then
   logger -s "Yac config <$CONFIG> nicht vorhanden"
   exit
fi
source $YAC_CONF
if [ "$PARALLEL_EXECUTION" = "1" ] ; then
   if [ $(grep "^processor" /proc/cpuinfo |wc -l) -lt 2 ] ; then
      logger -s "Parallel execution only valid for multiple cpus"
      PARALLEL_EXECUTION=0
   fi
fi

rm queue/*.old >/dev/null 2>&1

found=1
while [ "$found" = "1" ] ; do
   found=0
   touch 
   for i in queue/yac_queue_*.sh ; do
      [ ! -f $i ] && break
      found=1
      logger -s "Executing <$i>"
      mv $i $i.run
      chmod +x $i.run
      if [ "$PARALLEL_EXECUTION" = "1" ] ; then
         screen -dm sh -c "$i.run ; mv $i.run $i.old"
      else
         sh $i.run
         mv $i.run $i.old
      fi
      sleep 15
   done
done
