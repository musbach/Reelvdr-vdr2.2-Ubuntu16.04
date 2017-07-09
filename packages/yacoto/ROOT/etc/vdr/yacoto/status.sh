#!/bin/bash

#set -x

for i in 1 2 3 4 5 ; do
   LOG_PROC="$(ps x|grep "tee \-a /film/.*\.log")"
   LOG_FILE="/film/${LOG_PROC#*/film/}"
   LOG_FILE="${LOG_FILE/ */}"
   if [ -f "$LOG_FILE" ] ; then
      break
   fi
   sleep 1
done

if [ ! -f "$LOG_FILE" ] ; then
   echo "Konvertierung beendet"
   exit
fi

for i in 1 2 3 4 5 ; do
   LOG_ENTRY="$(cat $LOG_FILE | tr "\r" "\n" | egrep "^Pos|^read" |tail -n 1)"
   [ "$LOG_ENTRY" != "" ] && break
   sleep 1
done   

case $LOG_ENTRY in
   read*) 
      STATUS="Remux: ${LOG_ENTRY/read/}"
      ;;
   Pos*)
      menc="$(ps x |grep mencoder |grep "pass=.")"
      pass="${menc##*pass=}"
      pct="${LOG_ENTRY%%)*}"
      STATUS="Durchgang ${pass%%:*}: ${pct##*(}"
      ;;
   *)
      STATUS="Konvertierung laeuft"
      ;;
esac     
echo "$STATUS"
