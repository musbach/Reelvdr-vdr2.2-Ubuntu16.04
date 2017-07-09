#!/bin/bash
YAC_DIR="${YAC_DIR:=/etc/vdr/plugins/yacoto}"

logger -s "$0 $1"
if [ "$1" = "-init" ] ; then
   logger -s "YAC - vdr startet"
   screen -dm sh -c "${YAC_DIR}/yac_setplgconf.sh"
elif [ "$1" = "-start" ] ; then
   logger -s "YAC plugin startet"
elif [ "$1" = "-save" ] ; then
   sh ${YAC_DIR}/yac_setcfgfiles.sh
else
   echo "Illegal Parameter <$1>"
fi
