#!/bin/bash
#set -x
SVDRP_CMD=${SVDRP_CMD:=svdrpsend.pl}

function vdr_status() {
   logger -s "vdr_status PLUG bgprocess yacoto PROCESS $STARTTIME $*"
   #$SVDRP_CMD PLUG yacoto STAT $* 2>&1 |logger
   $SVDRP_CMD PLUG bgprocess PROCESS yacoto $STARTTIME $* 2>&1 |logger
}

STARTTIME="$(date +%s)"
YAC_DIR="${YAC_DIR:=/etc/vdr/plugins/yacoto}"

logger -s "$*"
PARENT_PID="$1"
CONV_STEPS="$(($2+1))"
TARGET="$3"
LOG_FILE="$4"

vdr_status 0 "$TARGET"

if [ ! -f "$LOG_FILE" ] ; then
   echo "Waiting for convert ..."
   for i in $(seq 1 10); do
      [ -f "$LOG_FILE" ] && break
      sleep 3
   done
   if [ ! -f "$LOG_FILE" ] ; then
      echo "Konvertierung beendet"
      vdr_status 101 "$TARGET Konvertierung beendet"
      exit
   fi
fi
menc=""
old_proc=""
old_pass=1
step=0
remux_total=""
remux_act=""
last_pct=101
dvdauth_size_total=0
dvdasd_offs=0
dvdasd_last=0
while ( ps -p $PARENT_PID >/dev/null 2>&1 ) ; do
   if [ ! -f "$LOG_FILE" ] ; then
      break
   fi
   for i in 1 2 3 4 5 ; do
      [ "$menc" != "" ] && menc="$(ps x |grep mencoder |grep "pass=.")"
      [ "$act_proc" = "remux" ] && remux_act="$(grep "^Input file length" $LOG_FILE |wc -l)"	 
      LOG_ENTRY="$(cat $LOG_FILE | tr "\r" "\n" | egrep "^Pos|^read|^frame=|^STAT: VOBU| done, estimate finish| Mbytes of |^Frame#|%\)\| " |tail -n 1)" 
      # just for beautifying mcedit adding an "
      [ "$LOG_ENTRY" != "" ] && break
      sleep 1
   done   
   echo "<$LOG_ENTRY>"
   pct=0
   case $LOG_ENTRY in
      read*) 
         if [ "$remux_total" = "" ] ; then
	    remux_total="$(grep "replex -j --vdr" $LOG_FILE | tail -n 1 | sed -e "s/.*mpeg //" | wc -w)"
	 fi
	 if [ $remux_total -gt 0 ] ; then
            act_pct="${LOG_ENTRY/read/}"
	    act_pct=${act_pct//\%/}
            if [ $act_pct -lt $last_pct ] ; then
               remux_act=$(($remux_act + 1))
            fi
            last_pct=$act_pct
	    pct=$((($remux_act-1)*100/$remux_total + $act_pct/$remux_total))
	 fi    
         STATUS="Remux: ${pct}"
         act_proc="remux"
         ;;
      Pos*)
         pct="${LOG_ENTRY%%\%)*}"
         pct="${pct##*(}"
	 echo "$pct" | grep -q -v "^[0-9][0-9]*$" && continue
         if [ "$menc" != "" ] ; then
            pass="${menc##*pass=}"
            pass="${pass%%:*}"
            old_pass="$pass"
         else
            pass="$old_pass"
	    menc="1"
         fi
            
         STATUS="Durchgang ${pass}: ${pct}"
         act_proc="mencoder-$pass"
         ;;
      STAT*)
         if [ "$dvdauth_size_total" = "0" ] ; then
	    in="$(grep "<dvdauthor " $LOG_FILE | tail -n 1)"
	    if [ "$in" != "" ] ; then
	       in=${in##* }
	       infls=${in/\/yac_0*//yac_0*.mpeg}
	       if [ "$infls" != "" ] ; then
	          for i in $(du -B 1M $infls | cut -f 1) ; do
		     dvdauth_size_total=$(($dvdauth_size_total+$i))
		  done
	       fi
	    fi
	 fi   

         if [ $dvdauth_size_total -gt 0 ] ; then
	    as="${LOG_ENTRY%MB,*}"
	    as="${as##* at }"
	    if [ as -lt dvdasd_last ] ; then
	       dvdasd_offs=$(($dvdasd_offs+$dvdasd_last))
	    fi   
	    dvdasd_last=$as
	    pct=$((($dvdasd_offs+$as)*100/$dvdauth_size_total))
	 fi 
         STATUS="DVD Struktur erstellen: ${pct}%"
         act_proc="dvdauthor"      
         ;;	 
      frame*)
         duration="$(grep "^  Duration:" $LOG_FILE)"	 
	 duration=${duration#*:}
	 dh=${duration%%:*}
	 duration=${duration#*:}
	 dm=${duration%%:*}
	 duration=${duration#*:}
	 ds=${duration%%\.*}
	 vid_len=$(($dh*3600 + $dm*60 + $ds))
	 p1=${LOG_ENTRY#* time=}
	 act_pos=${p1%%\.*}
	 pct=$(($act_pos*100/$vid_len))
         STATUS="Encodieren: ${pct}%"
         act_proc="ffmpeg"
         ;;	 
      *estimate*)
         pct="${LOG_ENTRY%%.*}"
	 pct="${pct# *}"
         STATUS="DVD ISO: ${pct}%"
         act_proc="mkisofs"
         ;;	 
      *Mbytes*)
         br="${LOG_ENTRY%% Mbytes*}"
         bt="${LOG_ENTRY##*of }"
         bt="${bt%% read*}"
         pct=$(($br*100/$bt))
         STATUS="Demuxen: ${pct}%"
         act_proc="vdrsync"
         ;;
      Frame*)
         br=${LOG_ENTRY%%/*}
         br=${br##* }
         tot=${LOG_ENTRY#*/}
         tot=${tot%% *}
         pct=$(($br*100/$tot))
         pct=${pct##*(}
         STATUS="ogg erstellen: ${pct}"
         act_proc="oggenc"
         ;;
      *%\)\|*)
         pct=${LOG_ENTRY%%)*}
         pct="${pct##*(}"
         STATUS="mp3 erstellen: ${pct}"
         act_proc="lame"
         ;;
      *)
         act_proc=""
         STATUS="Konvertierung laeuft"
         ;;
   esac    
   pct=${pct%\%*}
   echo "$pct" | grep -q -v "^[0-9][0-9]*$" && continue
   if [ "$act_proc" != "" -a "$act_proc" != "$old_proc" ] ; then
      step=$(($step+1))
      old_proc=$act_proc
   fi
   if [ "$pct" != "0" ] ; then
      [ $step -gt $CONV_STEPS ] && CONV_STEPS=$step
      tot_pct=$(((${pct//\%/}/$CONV_STEPS)+(($step-1)*100/$CONV_STEPS)))
      vdr_status $tot_pct "$TARGET"
   fi

   logger -s "YACOTO Status: $STATUS"
   sleep 3
done
sleep 3
if [ "$(tail "$LOG_FILE" | grep " SUCCESS ")" != "" ] ; then
   vdr_status 101 "$TARGET converted successfully"
else
   vdr_status 101 "Error converting $TARGET"
fi

if [ "$KEEP_LOGS" != "1" ] ; then
   rm -vf $LOG | logger -s
fi

