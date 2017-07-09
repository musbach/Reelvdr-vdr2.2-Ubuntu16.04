#!/bin/bash
CONV_STEPS=2

function yac_convert() {
   TARGET="$TARGET_VIDEO/$1.mp4"

   [ -f "$TARGET" ] && rm "$TARGET"

   shift

   infls=""
   for i in "$@" ; do
      infls="$infls -i $i"
   done
   execute "ffmpeg $infls -f mp4 -vcodec mpeg4 -maxrate ${VMAXBITRATE}k -b ${VBITRATE}k -qmin 3 -qmax 5 -bufsize 4096k -g 300 -acodec libfaac -ab ${ABITRATE}k -ar 44100 -s $SCALE -aspect 4:3 \"$TARGET.n\""
   execute "MP4Box -ipod \"$TARGET.n\" -out \"$TARGET\""
   execute "rm \"$TARGET.n\""
}
