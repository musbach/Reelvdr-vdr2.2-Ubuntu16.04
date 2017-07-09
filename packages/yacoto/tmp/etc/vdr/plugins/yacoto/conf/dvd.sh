#!/bin/bash
DVD_DEV=${DVD_DEV:=/dev/dvd}
[ "$DISC_SIZE" = 0 -o "$DISC_SIZE" = "" ] && DISC_SIZE=999999
CONV_STEPS=1
[ "$CREATE_ISO" = "1" ] && CONV_STEPS=$(($CONV_STEPS+1))
[ "$BURN_DVD" = "1" ]   && CONV_STEPS=$(($CONV_STEPS+1))

source "$(yac_choosedir /conf/dvd/dvd_menu.sh)/conf/dvd/dvd_menu.sh"

function yac_convert() {
   if [ "$1" = "" ] ; then
      log "$0 - No parameter given"
      exit
   fi
   TGT="${1// /_}"
   if [ "$CREATE_VIDEO_TS" = "1" ] ; then
      DVD_DIR="${TARGET_VIDEO}/$TGT"
      TARGET="$DVD_DIR"
   else
      DVD_DIR="${TEMP_DIR}/$TGT"
      TARGET=""
   fi
   ID="${TGT%_dvd_*}"
   ID="${ID:0:31}"
   ID=$(echo "$ID" | tr -s '[:lower:]' '[:upper:]')

   [ -x $DVD_DIR ] && rm -rf $DVD_DIR
   mkdir -p $DVD_DIR

   shift
   NUM_RECORDINGS="$#"
   tot_size=0
   for i in "$@" ; do
      sz=$(du --block-size=1M "$i" | cut -f 1)
      tot_size=$(($tot_size+$sz))
   done
   tot_size=$(($tot_size*105/100))

   if [ $tot_size -gt $DISC_SIZE ] ; then
      req_fac=$(($tot_size*100/$DISC_SIZE))
      req_a=$(($req_fac/100))
      req_d=${req_fac: -2}
      for i in "$@" ; do
         fs="$(du -b $i | cut -f 1)"
         num_audio=$(replex --scan --vdr "$i" 2>/dev/null |grep " AUDIO " |wc -l)
         aud_str="-a 1"
         idx=1
         while [ $idx -lt $num_audio ] ; do
            idx=$(($idx + 1))
            aud_str="$aud_str,$idx"
         done
         cat "$i" | vamps $aud_str -E ${req_a}.${req_d} -S $fs > $i.req
         mv -f $i.req $i
      done
   fi

   if [ "${DVD_MENU}" != "" -a -d ${DVD_CONF_DIR}/${DVD_MENU} ]; then
      dvd_make_menu $ID $DVD_DIR "$@"   
   elif [ "$SPLIT_MODE" = "chapters" -a "$2" != "" ] ; then
      in_fls=""
      while [ "$1" != "" ] ; do
         in_fls="$in_fls -f $1"
         shift
      done
      execute "dvdauthor -t -o $DVD_DIR $in_fls"
      execute "dvdauthor -T -o $DVD_DIR"
   else
      idx=1
      while [ "$1" != "" ] ; do
         CHAPTERS=""
         dvd_get_chapters "$1" $((${REC_LEN[$idx]} / 60))
         execute "dvdauthor -t -o $DVD_DIR -c $CHAPTERS -f $1"
         shift
         idx=$(($idx + 1))
      done
      execute "dvdauthor -T -o $DVD_DIR"
   fi
   if [ "$CREATE_ISO" = "1" ] ; then
      TARGET="${TARGET_VIDEO}/$TGT.iso"
      [ -f "$TARGET" ] && rm -f "$TARGET"
      execute "mkisofs -V $ID -dvd-video -o \"$TARGET\" $DVD_DIR"
      BURN_PARMS="-Z \"$DVD_DEV=$TARGET\""
   else
      BURN_PARMS="-Z $DVD_DEV -V $ID -dvd-video $DVD_DIR"
   fi
   if [ "$BURN_DVD" = "1" ] ; then
      if [ "$(mount | grep "$DVD_DEV")" != "" ] ; then
         execute "umount $DVD_DEV"
         execute "dvd+rw-format -blank $DVD_DEV"
      fi
      execute "dvd+rw-format -blank $DVD_DEV"
      if [ "$(dvd+rw-mediainfo $DVD_DEV | grep "Disc status.*blank")" != "" ] ; then
         eject $DVD_DEV
         $SVDRP_CMD MESG "Beschreibbare DVD einlegen"
         sleep 10
         while [ "$(dvd+rw-mediainfo $DVD_DEV | grep "Disc status.*blank")" = "" ] ; do
            sleep 5
            $SVDRP_CMD MESG "Beschreibbare DVD einlegen"
         done
      fi

      execute "growisofs  -use-the-force-luke=tty -speed=$BURN_SPEED -dvd-compat $BURN_PARMS"
      if [ "$TARGET" = "" ] ; then
         if [ "$rc" = "0" ] ; then
            TARGET=" +DVD - $TGT"
         else
            TARGET=" -DVD - $TGT"
         fi
      fi
   fi
   echo "Target: $TARGET"
   if [ "CREATE_VIDEO_TS" = "0" ] ; then
      execute "rm -rf $DVD_DIR"
   fi
}
