#!/bin/bash

YAC_DIR="${YAC_DIR:=/usr/share/vdr/yacoto}"
source "${YAC_DIR}/yac_helperfuncs.sh"

set -x
PROJECTX="/usr/bin/projectx_nogui"
PROJECTX_INI="${YAC_CONF_DIR}/conf/ProjectX.ini"

function usage() {
   echo "Syntax:  $0 [--preferac3|--prefermp2|--ac3streams=nnn|--mp2streams=nnn] [--audioonly] [--demux] <recording-path>"
   exit
}

function remux_exec() {
   echo "$(date +"%D %T") - Starte <$@>"
   "$@"
   echo "$(date +"%D %T") - Exit <$@>"
}

REMUX_TYPE=${REMUX_TYPE:=mpeg2}
AUDIO_SOURCE=${AUDIO_SOURCE:=mp2}

TMP="/tmp/~replex"
vid_dir=${1%%~*}

TARGET=$2

audio_stream_prefs=${1#*~}

if [ ! -f "$vid_dir/001.vdr" -a !-f "$vid_dir/00001.ts" ] ; then
   logger -s "<$vid_dir/001.vdr> not found"
   usage
fi

echo "Starte <$0 $*>"

act_dir=$(pwd)
cd "$vid_dir"

#cat "info.vdr"

if [ "$REMUX_TYPE" = "mpeg2" -o "$REMUX_TYPE" = "remux_dvd"  ] ; then
   SYNC=$(replex -y 2 *01.* 2>/dev/null |grep "^Video unit: P" |head -n 1|sed -e "s/ DTS.*//" -e "s/.*diff://" -e "s/[:.]//g" -e "s/ 0*//g")
   [ "$SYNC" != "" ] && parms="$parms -e $SYNC"
fi
VDR_PARM=""
if [ -f 001.vdr ] ; then
   replex -s 001.vdr > $TMP 2>/dev/null
   if [ "$(grep "AC3 AUDIO" $TMP)" = "" ] ; then
      replex -s --vdr 001.vdr > $TMP 2>/dev/null
      VDR_PARM="--vdr"
   fi
fi

stream_mp2_all=""
stream_mp2_sel=""
stream_ac3_all=""
stream_ac3_sel=""
stream_audio_master=""
stream_video=""
#set -x
if [ "${REMUX_TYPE:0:5}" = "remux" ] ; then
   if [ "$REMUX_TYPE" = "remux_dvd" ] ; then
      REMUXER="projectx"
   else
      REMUXER="replex"
   fi
else
   REMUXER="vdrsync"
fi

act_pref=$audio_stream_prefs
str_idx=0
for i in $(grep "MPEG AUDIO" $TMP | cut -f4 -d" " | sort -u) ; do
   stream_mp2_all="$stream_mp2_all,${i}"
   if [ "${audio_stream_prefs:$str_idx:1}" = "1" ] && [ "$AUDIO_SOURCE" = "all" ] ; then
      stream_mp2_sel="$stream_mp2_sel,${i}"
   elif [ "${audio_stream_prefs:$str_idx:1}" = "2" ] ; then
      stream_mp2_sel=",${i}${stream_mp2_sel}"
      stream_audio_master="$i"
   fi
   str_idx=$(($str_idx+2))
done
[ "$stream_mp2_sel" = "" -a "$AUDIO_SOURCE" != "ac3" ] && stream_mp2_sel=$stream_mp2_all
for i in $(grep "AC3 AUDIO" $TMP | cut -f4 -d" " | sort -u) ; do
   stream_ac3_all="$stream_ac3_all,${i}"
   if [ "${audio_stream_prefs:$str_idx:1}" = "1" ] && [ "$AUDIO_SOURCE" = "all" ] ; then
      stream_ac3_sel="$stream_ac3_sel,${i}"
   elif [ "${audio_stream_prefs:$str_idx:1}" = "2" ] ; then
      stream_ac3_sel=",${i}${stream_ac3_sel}"
      stream_audio_master="$i"
   fi
   str_idx=$(($str_idx+2))
done
[ "$stream_mp2_sel" = "" -a "$stream_ac3_sel" = "" ] && stream_ac3_sel=$stream_mp2_all
stream_video=$(grep -m 1 VIDEO $TMP | cut -f4 -d" ")

if [ "$REMUXER" = "replex" ] ; then
   if [ "${REMUX_TYPE:0:5}" = "remux" ] ; then
      TARGET="${TARGET}.mpeg"
      if [ "$AUDIO_SOURCE" = "all" ] ; then
         parms="${stream_mp2_sel//,/ -a } ${stream_ac3_sel//,/ -c }"
      elif [ "$AUDIO_SOURCE" = "mp2" ] ; then
         parms="${stream_mp2_sel//,/ -a }"
      elif [ "$AUDIO_SOURCE" = "ac3" ] ; then
         parms="${stream_ac3_sel//,/ -c }"
      fi
      if [ "$REMUX_TYPE" = "remux_mpeg2" ] ; then
         parms="$parms -t MPEG2"
      else
         parms="$parms -t DVD"
      fi
      infls=$(ls [0-9][0-9][0-9].vdr)
      remux_exec replex -j $VDR_PARM -v $stream_video $parms -o "$TARGET" $infls
   else
      log "Replex not valid for: <$REMUX_TYPE>"
   fi
elif [ "$REMUXER" = "vdrsync" ] ; then
   if [ "${REMUX_TYPE:0:5}" = "demux" ] ; then
      all_audio="$stream_mp2_all$stream_ac3_all"
      ignore_audio=${all_audio/,$master/}
      ignore_audio=${ignore_audio//,0x/,}
      ignore_audio=${ignore_audio:1}
      if [ "$ignore_audio" != "" ] ; then
         parms="-ignore $ignore_audio"
      else
         parms=""
      fi
      if [ -f 001.vdr ] ; then
         remux_exec vdrsync.pl . -o "${TARGET%/*}/" -basename "${TARGET##*/}" -audio-only $parms
      else
         infls=$(ls [0-9][0-9][0-9][0-9][0-9].ts)
         remux_exec replex --demux --audio_only -o "${TARGET}" $infls
      fi
   else
      log "VDRSYNC not valid for: <$REMUX_TYPE>"
   fi
elif [ "$REMUXER" = "projectx" ] ; then
   infls=$(ls [0-9][0-9][0-9]*.*)
   rm ${TEMP_DIR}/prjx_streams*
   remux_exec $PROJECTX -ini $PROJECTX_INI -id ${stream_video}${stream_mp2_sel}${stream_ac3_sel} -demux -out $TEMP_DIR -name prjx_streams $infls
   if [ "${REMUX_TYPE:0:5}" = "remux" ] ; then
      TARGET="${TARGET}.mpeg"
      parms="-S 0 -M"
      if [ "$REMUX_TYPE" = "remux_dvd" ] ; then
         parms="$parms -f 8"
      else
         parms="$parms -t 3"
      fi
      infls="$(ls $TEMP_DIR/prjx_streams*mp* $TEMP_DIR/prjx_streams*ac3* 2>/dev/null)"
      remux_exec mplex $parms -o "$TARGET" $infls
   fi
fi

cd "$act_dir"
