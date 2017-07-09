#!/bin/bash
CONV_STEPS=0

function yac_convert() {
   TGT="${TARGET_VIDEO}/$1"
   shift
   if [ "$2" != "" ] ; then
      idx=0
      while [ "$1" != "" -a -f "$1" ] ; do
         TARGET="${TGT}_$idx.mpeg"
         [ -f "$TARGET" ] && rm "$TARGET"
         execute "mv -v \"$1\" \"$TARGET\""
         idx=$(($idx+1))
         shift
      done
   else
      TARGET="${TGT}.mpeg"
      [ -f "$TARGET" ] && rm "$TARGET"
      execute "mv -v \"$1\" \"$TARGET\""
   fi
}
