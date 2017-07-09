#!/bin/bash

echo "$0 $@ called" >> /tmp/vlc-repack.log

INPUT="$1"
OUTPUT="$2"
MUXER="ts"

exec /usr/bin/vlc -I dummy "${INPUT}" --sout \
"#standard{access=file,mux=${MUXER},dst=${OUTPUT}}" vlc:quit \
>/dev/null 2>&1

