#!/bin/bash

YAC_CONF_DIR="${YAC_CONF_DIR:=/etc/vdr/plugins/yacoto}"
YAC_DIR="${YAC_DIR:=/etc/vdr/plugins/yacoto}"
cd "${YAC_CONF_DIR}"
find . -name "*.conf.sample" | while read i ; do
   if [ ! -f "${i%.sample}" ] ; then
      cp -v "$i" "${i%.sample}" 
   else
      echo "Keeping <${i%.sample}>"
   fi
done
cd "${YAC_DIR}"
