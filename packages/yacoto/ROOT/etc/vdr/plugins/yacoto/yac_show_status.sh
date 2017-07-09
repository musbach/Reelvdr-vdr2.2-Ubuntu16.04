#!/bin/bash
#set -x
YAC_DIR="${YAC_DIR:=/etc/vdr/plugins/yacoto}"

ps x | grep -v grep | grep yac_queue_1222863016.sh.run

logger -s "$*"
ls queue/*.sh* 2>/dev/null | while read conv_job ; do
   TARGET="$(grep "\. \./yac_exec\.sh" $conv_job |cut -f 2 -d "\"")"
   CONFIG="$(grep "^CONFIG=" $conv_job |cut -f 2 -d "\"")"
   ext=${conv_job##*.}
   case $ext in
      old)
         STAT="has been done"
         ;;
      run)
         PROCS="$(ps x | grep -v "grep" | grep "$conv_job")"
         if [ "$PROCS" = "" ] ; then
	    for i in 1 2 3 4 5 ; do
	       sleep 1
               PROCS="$(ps x | grep -v "grep" | grep "$conv_job")"
	       [ "$PROCS" != "" ] && break
	    done
	 fi 
         if [ "$PROCS" != "" ] ; then
            STAT="is running"
         else	    
            STAT="was killed"
	    mv $conv_job "${conv_job/.run/.old}"
	 fi    
         ;;
      sh)
         STAT="is in queue"
         ;;
      *)
         STAT="is in unknown status"
         ;;
   esac
   echo "$CONFIG <$TARGET> $STAT"
done
[ "$(ls queue/*.sh* 2>/dev/null)" = "" ] && echo "Nothing to be done"
