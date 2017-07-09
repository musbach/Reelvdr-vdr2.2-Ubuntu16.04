#!/bin/bash
if [ "$VIDEO_OPTS_P1" != "" ] && [ "$VIDEO_OPTS_P2" != "" ] ; then
   CONV_STEPS=2
else
   CONV_STEPS=1
fi

function yac_convert() {
   TARGET="$TARGET_VIDEO/$1.avi"

   [ -f "$TARGET" ] && rm "$TARGET"

   shift

   if [ "$VIDEO_OPTS_P1" != "" ] && [ "$VIDEO_OPTS_P2" != "" ] ; then
      execute "mencoder -ovc $VIDEO_CODEC $VIDEO_OPTS_P1 $OTHER_OPTS -nosound $OUTPUT_OPTS -o /dev/null $@"
      cmd="mencoder -ovc $VIDEO_CODEC $VIDEO_OPTS_P2 $OTHER_OPTS -oac $AUDIO_CODEC $AUDIO_OPTS $OUTPUT_OPTS -o \"$TARGET\" $@"
   else   
      cmd="mencoder -ovc $VIDEO_CODEC $VIDEO_OPTS_P1 $OTHER_OPTS -oac $AUDIO_CODEC $AUDIO_OPTS $OUTPUT_OPTS -o \"$TARGET\" $@"
   fi   

   execute "$cmd"
}
