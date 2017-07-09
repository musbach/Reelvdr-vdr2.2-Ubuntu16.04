#!/bin/bash

#set -x
function usage() {
   echo "Syntax:  $0 [--preferac3|--prefermp2|--ac3streams=nnn|--mp2streams=nnn] [--audioonly] [--demux] <recording-path>"
   exit

}
SOURCE_DIR="${0%/*}"

if [ "${SOURCE_DIR:0:1}" = "." ] ; then
   SOURCE_DIR="$(pwd)/${SOURCE_DIR}"
elif [ "${SOURCE_DIR:0:1}" != "/" ] ; then
   SOURCE_DIR="$(pwd)"
fi
      
AUDIO_PREF="all"
VIDEO_STREAMS="all"
DEMUX_ONLY=0

DD_STREAMS="123456789"
MP_STREAMS="123456789"

while [ ! -z "$1" ] ; do
   case $1 in
      --preferac3)     
         AUDIO_PREF="ac3"
	 ;;
      --prefermp2)     
         AUDIO_PREF="mp2"
	 ;;
      --ac3streams=*)  
         DD_STREAMS="${i##*=}"
	 ;;
      --mp2streams=*)  
         MP_STREAMS="${i##*=}"
	 ;;
      --audioonly)     
         VIDEO_STREAMS="none"
	 DEMUX_ONLY=1
	 ;;
      --demux)
         DEMUX_ONLY=1
	 ;; 	 
      *)
         if [ -d "$1" ] ; then
	    VIDEO_DIR="$1"
            source "$SOURCE_DIR/config.sh"
         else
            usage
         fi
         ;;
   esac
   shift
done
										    
if [ ! -e "$VIDEO_DIR/001.vdr" ] ; then
   log "$VIDEO_DIR/001.vdr ist nicht vorhanden"
   exit
fi

log "Starte <$0 $*>"

TMP=/tmp/v2m.log

if [ -f "$SOURCE_DIR/${video_filename}.conf" ] ; then
    source "$SOURCE_DIR/${video_filename}.conf"    
    AUDIO_PREF="all"
fi
	    
parms=""

cd "$VIDEO_DIR"

cat "info.vdr" >> $LOG

if [ "$DEMUX_ONLY" = "0" ] ; then
   SYNC=$(replex -y 2 001.vdr 2>/dev/null |grep "^Video unit: P" |head -n 1|sed -e "s/ DTS.*//" -e "s/.*diff://" -e "s/[:.]//g" -e "s/ 0*//g")
   # Make Targetformat
   [ "$SYNC" != "" ] && parms="$parms -e $SYNC"
fi   

replex -s --vdr 001.vdr > $TMP 2>/dev/null

mp2_parms=""
ac3_parms=""
def_parms=""

#set -x
strnum=0
for i in $(grep "MPEG AUDIO" $TMP | cut -f4 -d" " | sort -u) ; do
   strnum=$(($strnum+1))
   [ "$def_parms" = "" ] && def_parms=" -a $i"
   if [ "$AUDIO_PREF" != "all" ] ; then
      mp2_parms="-a $i"
      break
   else
      if [ "$MP_STREAMS" != "" ] ; then
         case $MP_STREAMS in
	    *$strnum*) mp2_parms="$mp2_parms -a $i" ;;
	 esac
#      else
#         mp2_parms="$mp2_parms -a $i"
      fi
   fi   
done
strnum=0
for i in $(grep "AC3 AUDIO" $TMP | cut -f4 -d" " | sort -u) ; do
   strnum=$(($strnum+1))
   [ "$def_parms" = "" ] && def_parms=" -c $i"
   if [ "$AUDIO_PREF" != "all" ] ; then
      ac3_parms="-c $i"
      break
   else
      if [ "$DD_STREAMS" != "" ] ; then
         case $DD_STREAMS in
	    *$strnum*) ac3_parms="$ac3_parms -c $i" ;;
	 esac
#      else
#         ac3_parms="$ac3_parms -c $i"
      fi
   fi   
done

if [ "${ac3_parms}${mp2_parms}" = "" ] ; then
   log "Audio-Stream <$AUDIO_STREAM> nicht vorhanden"
   mp2_parms=$def_parms
fi   

if [ "$AUDIO_PREF" = "ac3" ] ; then
   if [ "$ac3_parms" != "" ] ; then
      parms="$parms $ac3_parms"
   else
      parms="$parms $mp2_parms"
   fi      
elif [ "$AUDIO_PREF" = "mp2" ] ; then
   if [ "$mp2_parms" != "" ] ; then
      parms="$parms $mp2_parms"
   else
      parms="$parms $ac3_parms"
   fi
else  
   parms="$parms $mp2_parms $ac3_parms"
fi

if [ "$DEMUX_ONLY" = "0" ] ; then
   parms="$parms -v $(grep "MPEG VIDEO" $TMP | cut -f4 -d" ") -t MPEG2"
   TARGET="$TARGET_DIR/$video_filename.mpeg"
else
   [ "$VIDEO_STREAMS" = "none" ] && parms="$parms --audio_only"
   parms="$parms --demux"
   TARGET="$TARGET_DIR/$video_filename"
fi

infls=$(ls [0-9][0-9][0-9].vdr)
execute replex -j --vdr $parms -o "$TARGET" $infls
[ -f "$SOURCE_DIR/${video_filename}.conf" ] && rm -f "$SOURCE_DIR/${video_filename}.conf"
