#!/bin/bash
CONV_STEPS=1

function yac_convert() {
   TGT="${TARGET_AUDIO}/$1"
   shift
   if [ "$2" != "" ] ; then
      idx=0
      while [ "$1" != "" -a -f "$1" ] ; do      
         TARGET="${TGT}_$idx.ogg"
         [ -f "$TARGET" ] && rm "$TARGET"
         echo "oggenc - -q $QUALITY --output=\"$TARGET\"" >> $LOG.cmd
         lame --decode --mp2input "$1" - 2>>$LOG | oggenc - -q $QUALITY --output="$TARGET"
         idx=$(($idx+1))
         shift
      done
   else
      TARGET="${TGT}.ogg"
      [ -f "$TARGET" ] && rm "$TARGET"
      echo "oggenc - -q $QUALITY --output=\"$TARGET\"" >> $LOG.cmd
      lame --decode --mp2input "$1" - 2>>$LOG | oggenc - -q $QUALITY --output="$TARGET"
   fi
}
