#!/bin/bash
CONV_STEPS=2

function yac_convert() {
   TARGET="${TARGET_VIDEO}/$1.3gp"
   [ -f "$TARGET" ] && rm -f "$TARGET"
   TEMP_FILE="${TEMP_DIR}/~tmp.avi"
   shift
   execute "mencoder $@ $MENCODER_OPTS -o $TEMP_FILE"
   execute "ffmpeg -i $TEMP_FILE $FFMPEG_OPTS "$TARGET""
}
