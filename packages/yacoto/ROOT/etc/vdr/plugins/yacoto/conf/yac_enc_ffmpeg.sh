#!/bin/bash
if [ "$VIDEO_OPTS_P1" != "" ] && [ "$VIDEO_OPTS_P2" != "" ] ; then
   CONV_STEPS=2
else
   CONV_STEPS=1
fi

function yac_convert() {
   TARGET="$TARGET_VIDEO/$1.$EXT"

   [ -f \"$TARGET\" ] && rm "$TARGET"

   shift
   get_ffmpeg_parms "$1"

   infls=""
   for i in "$@" ; do
      infls="$infls -i $i"
   done
   execute "ffmpeg -f mpeg $infls $ZOOMOPT -y $SPECIALOPT -vcodec $VCODEC -s $SCALE -b ${VBITRATE}K -acodec $ACODEC -ar $ASRATE -ab ${ABITRATE}K \"$TARGET\""
   #if [ "$VIDEO_OPTS_P1" != "" ] && [ "$VIDEO_OPTS_P2" != "" ] ; then
   #   execute "ffmpeg -vcodec $VIDEO_CODEC $VIDEO_OPTS_P1 $OTHER_OPTS -nosound $OUTPUT_OPTS -o /dev/null $@"
   #   cmd="mencoder -ovc $VIDEO_CODEC $VIDEO_OPTS_P2 $OTHER_OPTS -oac $AUDIO_CODEC $AUDIO_OPTS $OUTPUT_OPTS -o \"$TARGET\" $@"
   #else   
   #   cmd="mencoder -ovc $VIDEO_CODEC $VIDEO_OPTS_P1 $OTHER_OPTS -oac $AUDIO_CODEC $AUDIO_OPTS $OUTPUT_OPTS -o \"$TARGET\" $@"
   #fi   
   #
   #execute "$cmd"
}

function get_ffmpeg_parms {
   #Wenn die Var. SIZE gesetzt ist, wird hier die BITRATE neu berechnet!
   if [ $SIZE -gt 0 ]; then
      ASIZE="$(($ABITRATE*$VIDEO_LEN/8))"
      SIZE="$((($SIZE*1024)-$ASIZE))"
      VBITRATE="$(($SIZE*8/$VIDEO_LEN))"
      echo "Bitrate für Size neu berechnet! Neue Bitrate: $VBITRATE"
   fi

   #Die Bildkoordinaten werden errechnet und die Schnittparameter festgelegt
   OSCALEG="$(mplayer $1 -v -frames 0 2>/dev/null|grep "VIDEO: "|awk {'print $3'})"
   if [ "$OSCALEG" = "" ]; then
      OSCALEG="720x576"
      echo "Original-Auflösung (geschätzt) : "$OSCALEG
   else
      echo "Original-Auflösung : "$OSCALEG
   fi
   OSCALEX="${OSCALEG%x*}"
   OSCALEY="${OSCALEG#*x}"

   if [ "$CROP" != "0" ]; then
      CROPCOUNTER="30"
      CROP1="0"
      CROP2="0"
      while [ "$CROPCOUNTER" -le 600 ]; do
         CROPTMP="$(mplayer $1 -vo null -ao null -ss $CROPCOUNTER -vf cropdetect -frames 5 2>/dev/null|grep "vf crop"|tail -n1|cut -d"=" -f2|cut -d")" -f1)"
         if [ "$CROPTMP" != "" ]; then
            CROPTMP1="${CROPTMP%%:*}"
            CROPTMP="${CROPTMP#*:}"
            CROPTMP2="${CROPTMP%%:*}"
            CROPTMP="${CROPTMP#*:}"
            CROPTMP3="${CROPTMP%%:*}"
            CROPTMP4="${CROPTMP#*:}"
            if [ "$CROPTMP1" -gt "$CROP1" ]; then
               CROP1="$CROPTMP1"
               CROP3="$CROPTMP3"
            fi
            if [ "$CROPTMP2" -gt "$CROP2" ]; then
               CROP2="$CROPTMP2"
               CROP4="$CROPTMP4"
            fi
         fi
         CROPCOUNTER="$(($CROPCOUNTER+30))"
      done
      if [ "$CROP1" == "0" ]; then
         CROP1="$OSCALEX"
         CROP2="$OSCALEY"
         CROP3="0"
         CROP4="0"
         echo "Original-Bildformat (geschätzt) : "$CROP1"x"$CROP2
      else
         echo "Original-Bildformat : "$CROP1"x"$CROP2
      fi
      FFMCL="$CROP3"
      FFMCR="$(($OSCALEX-$CROP3-$CROP1))"
      FFMCT="$CROP4"
      FFMCB="$(($OSCALEY-$CROP4-$CROP2))"
      RRATIO="$(echo "scale=2;($CROP1/$CROP2)/($OSCALEX/$OSCALEY)"|bc -l)"
   else
      RRATIO="1"
      FFMCL="0"
      FFMCR="0"
      FFMCT="0"
      FFMCB="0"
   fi
   echo "Seitenverhältnis-Korrektur-Faktor: "$RRATIO


#SCALE wird bearbeitet (ggf. auf Original-Auflösung gesetzt, gezoomt oder für 16x9 angepasst)!
   if [ -z "$SCALE" ]; then
      SCALE="$OSCALEG"
   fi

   if [ "$($MPLAYER $(resolve_recfile $INPUT/1stvideo) -v -frames 0 2>/dev/null|grep "(aspect 3)")" != "" ]; then
      if [ "$ZOOM" != "0" ]; then
         SCALE="${SCALE%x*}"
      fi
      if [ "$ZOOM" != "" ]; then
         if [ "$(echo "scale=2;$SCALE/16*9/$RRATIO/16"|bc -l|cut -d"." -f2)" -gt "49" ]; then
            SCALE="$SCALE"x"$(echo "scale=0;($SCALE/16*9/$RRATIO/16+1)*16"|bc -l)"
         else
            SCALE="$SCALE"x"$(echo "scale=0;$SCALE/$RRATIO/16*9/16*16"|bc -l)"
         fi
         echo "Auflösung angepasst (16x9)! Neue Auflösung: "$SCALE
         if [ "$CROP" != "" ]; then
            ZOOMOPT="-cropleft $FFMCL -cropright $FFMCR -croptop $FFMCT -cropbottom $FFMCB"
            echo "Option für Crop generiert: $ZOOMOPT"
         fi
      elif [ "$ZOOM" = "0" ]; then
         ZOOMOPT="-aspect 1.7777"
         echo "Auflösung (Fix): "$SCALE
         echo "Aspect gesetzt: "$ZOOMOPT
      elif [ "$ZOOM" = "1" ]; then
         if [ "$(echo "scale=2;$SCALE/4*3/$RRATIO/16"|bc -l|cut -d"." -f2)" -gt "49" ]; then
            SCALE="$SCALE"x"$(echo "scale=0;($SCALE/4*3/$RRATIO/16+1)*16"|bc -l)"
         else
            SCALE="$SCALE"x"$(echo "scale=0;$SCALE/$RRATIO/4*3/16*16"|bc -l)"
         fi
         ZOOMPIXEL="$(echo "scale=0;($OSCALEX-($OSCALEX/16*12))/2"|bc -l)"
         ZOOMOPT="-cropleft $[$ZOOMPIXEL+$FFMCL] -cropright $[$ZOOMPIXEL+$FFMCR] -croptop $FFMCT -cropbottom $FFMCB"
         echo "Auflösung angepasst(16x9-Zoom)! Neue Auflösung: "$SCALE
         echo "Option für Crop generiert: $ZOOMOPT"
      elif [ "$ZOOM" == "2" ]; then
         if [ "$FFMCT" -gt "16" -a "$FFMCB" -gt "16" ]; then
            if [ "$(echo "scale=2;$SCALE/4*3/$RRATIO/16"|bc -l|cut -d"." -f2)" -gt "49" ]; then
               SCALE="$SCALE"x"$(echo "scale=0;($SCALE/4*3/$RRATIO/16+1)*16"|bc -l)"
            else
               SCALE="$SCALE"x"$(echo "scale=0;$SCALE/$RRATIO/4*3/16*16"|bc -l)"
            fi
            ZOOMPIXEL="$(echo "scale=0;($OSCALEX-($OSCALEX/16*12))/2"|bc -l)"
            ZOOMOPT="-cropleft $[$ZOOMPIXEL+$FFMCL] -cropright $[$ZOOMPIXEL+$FFMCR] -croptop $FFMCT -cropbottom $FFMCB"
            echo "Auflösung angepasst(16x9-Cinescope-Zoom)! Neue Auflösung: "$SCALE
         else
            if [ "$(echo "scale=2;$SCALE/16*9/$RRATIO/16"|bc -l|cut -d"." -f2)" -gt "49" ]; then
               SCALE="$SCALE"x"$(echo "scale=0;($SCALE/16*9/$RRATIO/16+1)*16"|bc -l)"
            else
               SCALE="$SCALE"x"$(echo "scale=0;$SCALE/$RRATIO/16*9/16*16"|bc -l)"
            fi
            ZOOMOPT="-cropleft $FFMCL -cropright $FFMCR -croptop $FFMCT -cropbottom $FFMCB"
            echo "Auflösung angepasst(16x9)! Neue Auflösung: "$SCALE
         fi
         echo "Option für Crop generiert: $ZOOMOPT"
      fi
   else
      if [ "$CROP" != "" ]; then
         SCALE="${SCALE%x*}"
         if [ "$(echo "scale=2;$SCALE/4*3/$RRATIO/16"|bc -l|cut -d"." -f2)" -gt "49" ]; then
            SCALE="$SCALE"x"$(echo "scale=0;($SCALE/4*3/$RRATIO/16+1)*16"|bc -l)"
         else
            SCALE="$SCALE"x"$(echo "scale=0;$SCALE/$RRATIO/4*3/16*16"|bc -l)"
         fi
         echo "Auflösung angepasst (4x3)! Neue Auflösung: "$SCALE
         ZOOMOPT="-cropleft $FFMCL -cropright $FFMCR -croptop $FFMCT -cropbottom $FFMCB"
         echo "Option für Crop generiert: $ZOOMOPT"
      fi
   fi
}
