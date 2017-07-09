#!/bin/bash
if [ "$1" != "" -a -d "$1" ] ; then
   [ ! -e "$1/vcodec" ] && mplayer -identify -vo null -ao null -frames 0 "$(ls $1/[0-9][0-9][0-9]* | head -n 1)" 2>/dev/null| grep ID_VIDEO_CODEC > "$1/vcodec"
   cat "$1/vcodec" | cut -f 2 -d "="
fi
