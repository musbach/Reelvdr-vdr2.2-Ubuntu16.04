#!/bin/bash
# SET DEBUG=1 for enhanced Logging and keeping Temp files
set -x
DEBUG=1

function usage() {
   logger -s "Syntax:  $0 video1 [video2] ..."
   exit
}

function execute() {
   log "Starte <$@>"
   eval "$@" 2>&1 | tee -a $LOG
   rc=${PIPESTATUS[0]}
   log "Exit <rc:$rc><$@>"
}

function log() {
   logger -s "$*"
   echo "$(date +"%D %T") - $*" >> $LOG
}

[ "$DEBUG" = "1" ] && set -x

YAC_DIR="${YAC_DIR:=/etc/vdr/plugins/yacoto}"
YAC_CONF_DIR="${YAC_CONF_DIR:=/etc/vdr/plugins/yacoto}"

source $YAC_DIR/yac_helperfuncs.sh

[ -s "$YAC_CONF_DIR/myvars.conf" ] && source "$YAC_CONF_DIR/myvars.conf"
#target_filename=${1// /_}
target_name="$(echo "$1" | sed -e "s/[^abcdefghijklmnopqrstuvwxyzäöü${FOREIGN_CHARS_LOWER}ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÜß${FOREIGN_CHARS_UPPER}0123456789_]/_/g" | tr -s "_")"
[ "$target_name" = "" ] && usage

act_date="$(date +%Y%m%d%H%M)"
target_tempname="${target_name}_${CONFIG}_${act_date}"

rec_date=${2%.rec*}
rec_date=${rec_date##*/}
rec_date=${rec_date//-/}
rec_date=${rec_date//./}
rec_date=${rec_date:0:12}

if [ "$NAMING_CONVENTION" = "NameCfgRDate" ] ; then
   target_filename="${target_name}_${CONFIG}_${rec_date}"
elif [ "$NAMING_CONVENTION" = "NameDate" ] ; then
   target_filename="${target_name}_${act_date}"
elif [ "$NAMING_CONVENTION" = "NameRDate" ] ; then
   target_filename="${target_name}_${rec_date}"
elif [ "$NAMING_CONVENTION" = "Name" ] ; then
   target_filename="${target_name}"
else
   # assuming NameCfgDate
   target_filename="${target_name}_${CONFIG}_${act_date}"
fi


LOG_DIR=${LOG_DIR:=/var/log/yacoto}
[ ! -d $LOG_DIR ] && mkdir -p $LOG_DIR
LOG="${LOG_DIR}/$target_tempname.log"
[ -f $LOG ] && rm -f $LOG

TEMP_DIR=${TEMP_DIR:=/tmp}
TEMP_DIR="${TEMP_DIR}/YAC_$target_tempname"
source "$(yac_choosedir conf/${CONFIG}.sh)/conf/${CONFIG}.sh"
VDR_VIDEO=${VDR_VIDEO:=/video}
TARGET_VIDEO=${TARGET_VIDEO:=/film}
TARGET_AUDIO=${TARGET_AUDIO:=/audio/yacoto}

VDR_VIDEO=${VDR_VIDEO%/}
TARGET_VIDEO=${TARGET_VIDEO%/}
TARGET_AUDIO=${TARGET_AUDIO%/}

NICE_LEVEL=${NICE_LEVEL:=10}
MULTI_AUDIO=${MULTI_AUDIO:=0}

SVDRP_CMD=${SVDRP_CMD:=svdrpsend.pl}

#set -x

log "Start <$0 $*><$(pidof -x "$0")><$$><$PPID>"
shift

parm_err=0
for i in "$@" ; do
   vid_dir="${i%%~*}"
   if [ ! -f "$vid_dir/001.vdr" -a ! -f "$vid_dir/00001.ts" ] ; then
      log "<$vid_dir/001.vdr> not found"
      parm_err=1
      break
   fi
done
[ "$parm_err" != "0" ] && usage

[ -d $TEMP_DIR ] && rm -rf $TEMP_DIR
mkdir -p $TEMP_DIR

log "Starte <$YAC_DIR/yac_status.sh $$ ${CONV_STEPS:=1} $target_filename $LOG>"
screen -dm sh -c "$YAC_DIR/yac_status.sh $$ ${CONV_STEPS:=1} $target_filename $LOG >/tmp/$target_tempname.log 2>&1"
num_recs=0
VIDEO_LEN=0
CONV_FILES=""

for i in "$@" ; do
   VIDEO_DIR=${i%%~*}
   if [ -f "$VIDEO_DIR/001.vdr" ] ; then
      DO_TS=0
   else
      DO_TS=1
   fi

   AUDIO_PARMS=${i#*~}
   VIDEO_DIR=${VIDEO_DIR%/}
   num_recs=$(($num_recs + 1))
   if [ "$CUT_RECS" = "1" -a "$i" = "${i#*/%}" ] && [ -s "$VIDEO_DIR/marks.vdr" -o -s "$VIDEO_DIR/marks" ] ; then
      log "Schneide <$VIDEO_DIR>"
      rec_dir="${VIDEO_DIR##*/}"
      tmp="${VIDEO_DIR%/*}"
      rec_base="${tmp%/*}"
      CUT_VIDEO_DIR="$rec_base/%${tmp##*/}/$rec_dir"
      #hlcut -r "$VIDEO_DIR" -o "$CUT_VIDEO_DIR"
      vdr --edit=$VIDEO_DIR
      VIDEO_DIR=$CUT_VIDEO_DIR
   fi
   if [ "$DO_TS" = "0" -o "$REMUX_TYPE" = "demux_audio" -o "$REMUX_TYPE" = "remux_dvd" ] ; then
      TARGET="$(printf "$TEMP_DIR/yac_%03d" $num_recs)"
      execute ". $YAC_DIR/yac_remux.sh \"${VIDEO_DIR}~${AUDIO_PARMS}\" $TARGET"
      if [ "$(ls $TARGET*)" = "" ] ; then
         $SVDRP_CMD MESG "Erstellung von $TARGET fehlgeschlagen"
         log "Erstellung von $TARGET fehlgeschlagen"
      fi
      CONV_FILES="$CONV_FILES $(ls $TARGET*)"
   else
      CONV_FILES="$CONV_FILES $VIDEO_DIR/*.ts"
   fi
   if [ "$DO_TS" = "0" ] ; then
      IDX_FL="$VIDEO_DIR/index.vdr"
      INFO_FL="$VIDEO_DIR/info.vdr"
   else
      IDX_FL="$VIDEO_DIR/index"
      INFO_FL="$VIDEO_DIR/info"
   fi
   idx_size="$(stat -c %s "$IDX_FL")"
   REC_LEN[$num_recs]=$(($idx_size/8/25))
   VIDEO_LEN="$(($VIDEO_LEN + ${REC_LEN[$num_recs]}))"
   REC_DIR[$num_recs]=$VIDEO_DIR
   title="$(grep "^T " "$INFO_FL")"
#   if [ "${title:2}" != "" ] ; then
#      title="${title:2}"
#   else
      title=${VIDEO_DIR%/*}
      title=${title##*/}
#   fi
#   REC_TITLE[$num_recs]="$(echo "$title" | sed -e "s/[^abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_]/_/g" | tr -s "_")"
   REC_TITLE[$num_recs]="$(echo "$title" | sed -e "s/[^ -\&abcdefghijklmnopqrstuvwxyzäöü${FOREIGN_CHARS_LOWER}ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÜß${FOREIGN_CHARS_UPPER}0123456789_]/_/g" | tr -s "_")"
   REC_AUDIO[$num_recs]="$AUDIO_PARMS"
done
if [ "$TARGET_VIDEO" = "SOURCE" ] ; then
   TARGET_VIDEO="${REC_DIR[1]}"
elif [ "$KEEP_DIRS" = "1" ] ; then
   add_dir="${REC_DIR[1]#$VDR_VIDEO}"
   add_dir="${add_dir%/*}"
   add_dir="${add_dir%/*}"
   [ "$add_dir" != "" ] && TARGET_VIDEO="${TARGET_VIDEO}/${add_dir#/}"
   [ ! -d "$TARGET_VIDEO" ] && mkdir -p "$TARGET_VIDEO"
fi

TARGET=""
#yac_convert "$target_filename" $TEMP_DIR/yac_*
yac_convert "$target_filename" $CONV_FILES
set -x

if [ -s "$TARGET" -o "${TARGET:0:2}" = " +" ] ; then
   if [ "${TARGET:0:2}" = " +" ] ; then
      TARGET="${TARGET:2}"
   fi
   $SVDRP_CMD MESG "$TARGET wurde erstellt"
   log "$TARGET wurde erstellt"
   [ "$(whoami)" = "root" ] && chown -R root:users $TARGET
   if [ -s "$TARGET" ] ; then
      if [ -d "$TARGET" ] ; then
         info_file="${TARGET%/}/${target_name}.info"
      else
         info_file="${TARGET%/*}/${target_name}.info"
      fi
      [ -f "$info_file" ] && info_file="${info_file%.info}.${act_date}.info"

      sh ${YAC_DIR}/yac_format_info.sh "${REC_DIR[1]}" > "${info_file}"
   fi
   RC="SUCCESS"
else
   if [ "${TARGET:0:2}" = " -" ] ; then
      TARGET="${TARGET:2}"
   fi
   $SVDRP_CMD MESG "Erstellung von $TARGET fehlgeschlagen"
   log "Erstellung von $TARGET fehlgeschlagen"
   RC="ERROR"
fi
idx=0
# mark recordings as done or not :)
while [ $idx -lt $num_recs ] ; do
   idx=$(($idx + 1))
   rm -f "${REC_DIR[$idx]}/yacoto.log"
   if [ "$RC" = "SUCCESS" ] ; then
      ln -s "$LOG" "${REC_DIR[$idx]}/yacoto.log"
   fi
done
[ "$DEBUG" != "1" ] && rm -rf "${TEMP_DIR}"
log "$RC <$0 $*>"
