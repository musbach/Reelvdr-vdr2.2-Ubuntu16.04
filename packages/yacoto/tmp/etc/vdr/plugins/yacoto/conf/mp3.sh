#!/bin/bash
CONV_STEPS=1

function yac_convert() {
   TGT="${TARGET_AUDIO}/$1"

   shift
   if [ "$2" != "" ] ; then
      idx=0
      while [ "$1" != "" -a -f "$1" ] ; do
         TARGET="${TGT}_$idx.mp3"      
         [ -f "$TARGET" ] && rm "$TARGET"
         execute "lame $LAME_OPTS --mp2input \"$1\" \"${TARGET}\""
         idx=$(($idx+1))
         shift
      done
   else
      TARGET="${TGT}.mp3"
      [ -f "$TARGET" ] && rm "$TARGET"
      execute "lame --nohist $LAME_OPTS --mp2input \"$1\" \"${TARGET}\""
   fi
}
