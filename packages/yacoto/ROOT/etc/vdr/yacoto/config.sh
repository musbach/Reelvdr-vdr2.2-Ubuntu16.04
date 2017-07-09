# Verzeichnis der Zieldateien

if [ -f /tmp/.mediadir ]; then
	. /tmp/.mediadir
	TARGET_DIR=$MEDIADIR/video
	AUDIO_DIR=$MEDIADIR/music/yacoto
	VIDEO=$VIDEODIR
else
	TARGET_DIR=/media/hd/video
	AUDIO_DIR=/media/hd/music/yacoto
	VIDEO=/media/hd/video
fi



[ "${SOURCE_DIR:0:1}" != "/" ] && SOURCE_DIR="$(pwd)/${SOURCE_DIR}"

[ ! -d $TARGET_DIR ] && mkdir -p $TARGET_DIR
[ ! -d $AUDIO_DIR ] && mkdir -p $AUDIO_DIR

# Prioritaet der Umwandlung ( -19=MAX , 20=MIN )
NICE_LEVEL=10

function get_video_filename() {
   title="$(grep "^T " "$1/info.vdr" | cut -f 2- -d " ")"
   stitle="$(grep "^S " "$1/info.vdr" | cut -f 2- -d " ")"
   if [ "$stitle" != "" ] ; then
      fname="${title}_-_$stitle"
   elif [ "$title" != "" ] ; then
      fname="$title"
   else
      fname="$(echo "$1" | sed -e "s%$VIDEO/%%" -e "s%/20[0-9][0-9]\-[0-9][0-9]\-[0-9][0-9]\.[0-9][0-9]\.[0-9][0-9]\..*%%" | tr "/" "-")"
   fi
   fn="${fname// /_}"
   video_filename="${fn//:/_}"
}

function execute() {
   log "Starte <$@>"
   nice -n $NICE_LEVEL "$@" 2>&1 | tee -a $LOG
   log "Exit <$@>"
}

function log() {
   logger -s "$*"
   echo "$(date +"%D %T") - $*" >> $LOG   
} 

video_filename=""
get_video_filename "$VIDEO_DIR"
LOG=$TARGET_DIR/${video_filename}.log
