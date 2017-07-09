#!/bin/bash

. /etc/default/globals


function usage() {
   echo "Syntax:  $0 <video-dir> <convert-config>"
   exit
}
      
SOURCE_DIR="${0%/*}"
if [ "${SOURCE_DIR:0:1}" = "." ] ; then
   SOURCE_DIR="$(pwd)/${SOURCE_DIR}"
elif [ "${SOURCE_DIR:0:1}" != "/" ] ; then
   SOURCE_DIR="$(pwd)"
fi

CONF_FILE=""
VIDEO_DIR=""
while [ ! -z "$1" ] ; do
   if [ -f "$SOURCE_DIR/$1.conf" ] ; then
      CONF_FILE="$SOURCE_DIR/$1.conf"
   elif [ -f "$1/001.vdr" ] ; then
      VIDEO_DIR="$1"
   else
      usage
   fi 
   shift  
done      

[ "$CONF_FILE" = "" ] || [ "$VIDEO_DIR" = "" ] && usage

source "$SOURCE_DIR/config.sh"
source "$CONF_FILE"

rm -f $TARGET_DIR/$video_filename[0123456.]*
[ -f $LOG ] && rm -f $LOG
log "Starte <$0 $*>"

MPG_TARGET="$TARGET_DIR/$video_filename.mpeg"

[ -f $MPG_TARGET ] && rm $MPG_TARGET

if [ "$AUDIO_SOURCE" = "ac3" ] ; then
   parms="--preferac3"
elif [ "$AUDIO_SOURCE" = "mp2" ] ; then   
   parms="--prefermp2"
fi
[ "$VIDEO_CODEC" = "" ] && parms="$parms --audioonly"
   
execute $SOURCE_DIR/remux.sh "$VIDEO_DIR" $parms
#set +x

if [ "$VIDEO_CODEC" = "" ] ; then
   SRC="$TARGET_DIR/${video_filename}0.mp2"
   if [ -f "$SRC" ] ; then
      TGT="${AUDIO_DIR}/${video_filename}.${AUDIO_CODEC}"
      [ -f $TGT ] && rm -f $TGT
      cmd=${AUDIO_ENCODER/\%source\%/$SRC}
      cmd=${cmd/\%target\%/$TGT}
      execute $cmd
      if [ -s $TGT ] ; then
         smesg "Erstellung von $TGT erfolgreich"
         log "Erstellung von $TGT erfolgreich"
      else	    
         smesg "Erstellung von $TGT fehlgeschlagen"
         log "Erstellung von $TGT fehlgeschlagen"
      fi
   else
      smesg "Erstellung von $SRC fehlgeschlagen"
      log "Erstellung von $SRC fehlgeschlagen"
   fi
   exit
fi

if [ ! -s $MPG_TARGET ] ; then
   smesg "Erstellung von $MPG_TARGET fehlgeschlagen"
   log "Erstellung von $MPG_TARGET fehlgeschlagen"
   exit
elif [ "$VIDEO_CODEC" = "mpeg2" ] ; then
   smesg "Erstellung von $MPG_TARGET erfolgreich"
   log "Erstellung von $MPG_TARGET erfolgreich"
   exit
fi

oac_opts="$AUDIO_CODEC"
   
if ( ! replex --scan $MPG_TARGET 2>/dev/null | grep AC3) ; then 
   if [ "$AUDIO_CODEC" = "mp2" ] ; then
      AUDIO_CODEC="copy"
      AUDIO_OPTS=""
   fi              
fi
TARGET="$TARGET_DIR/$video_filename.avi"
[ -f $TARGET ] && rm $TARGET

if [ "$VIDEO_OPTS_P1" != "" ] && [ "$VIDEO_OPTS_P2" != "" ] ; then
   execute mencoder -ovc $VIDEO_CODEC $VIDEO_OPTS_P1 $OTHER_OPTS -nosound $OUTPUT_OPTS -o /dev/null "$MPG_TARGET"
   cmd="mencoder -ovc $VIDEO_CODEC $VIDEO_OPTS_P2 $OTHER_OPTS -oac $AUDIO_CODEC $AUDIO_OPTS $OUTPUT_OPTS -o $TARGET $MPG_TARGET"
else   
   cmd="mencoder -ovc $VIDEO_CODEC $VIDEO_OPTS_SP $OTHER_OPTS -oac $AUDIO_CODEC $AUDIO_OPTS $OUTPUT_OPTS -o $TARGET $MPG_TARGET"
fi   
execute $cmd

if [ -s $TARGET ] ; then
   smesg "$TARGET wurde erstellt"
   log "$TARGET wurde erstellt"
else
   smesg "Erstellung von $TARGET fehlgeschlagen"
   log "Erstellung von $TARGET fehlgeschlagen"
fi
