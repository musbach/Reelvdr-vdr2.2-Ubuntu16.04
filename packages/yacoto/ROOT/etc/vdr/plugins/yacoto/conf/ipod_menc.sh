#!/bin/bash
CONV_STEPS=2

function yac_convert() {
   TARGET="$TARGET_VIDEO/$1.mp4"

   [ -f "$TARGET" ] && rm "$TARGET"

   shift
   LAVFOPTS="-of lavf -lavfopts format=mp4"
   LAVCOPTS="-oac lavc -ovc lavc -lavcopts aglobal=1:vglobal=1:acodec=libfaac:abitrate=${ABITRATE}:vcodec=mpeg4:vbitrate=${VBITRATE}:keyint=25"
   OTHEROPTS="-ofps 25 -af lavcresample=44100 -vf-add harddup -vf-add scale=${SCALE/x/:}"

   execute "mencoder $LAVFOPTS $LAVCOPTS $OTHEROPTS -o \"$TARGET.n\" $@"
   execute "MP4Box -ipod \"$TARGET.n\" -out \"$TARGET\""
   
   execute "rm \"$TARGET.n\""
}
