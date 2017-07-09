#!/bin/bash

SOURCE_DIR="${0%/*}"

if [ "${SOURCE_DIR:0:1}" = "." ] ; then
   SOURCE_DIR="$(pwd)/${SOURCE_DIR}"
elif [ "${SOURCE_DIR:0:1}" != "/" ] ; then
   SOURCE_DIR="$(pwd)"
fi   

function usage() {
   echo "Syntax: $0 <videoverzeichnis> [--mp=x|--dd=x|--all|--reset]"
   echo "   --mp=x/-dd=x waehlt audio stream x (mpeg oder dd) aus"
   echo "e.g.   --mp=13 --dd=1 waehlt mp2 stream 2 und 3 und dd stream 1 aus"
   exit
}   

if [ "$1" = "" ] ; then
   usage
fi    

MP_STREAMS=""
DD_STREAMS=""
INCL_AS=""

#set -x
while [ ! -z "$1" ] ; do
   case $1 in
      --all)
         MP_STREAMS="123456789"
         DD_STREAMS="123456789"
         INCL_AS="+"
	 ;;
      --reset)
         MP_STREAMS="123456789"
         DD_STREAMS="123456789"
         INCL_AS="*"
	 ;;
      --mp=*)	 
         MP_STREAMS=${1##*--mp=}
         INCL_AS="+"
	 ;;
      --dd=*)
         DD_STREAMS=${1##*--dd=}
         INCL_AS="+"
	 ;;
      *) 	 
         if [ -d "$1" ] ; then
            VIDEO_DIR="$1"
	    source "$SOURCE_DIR/config.sh"
         else
	    usage
         fi
	 ;;
   esac	 
   shift
done   
	 	    	     
if [ ! -e "$VIDEO_DIR/info.vdr" ] ; then
   logger -s "$VIDEO_DIR/info.vdr ist nicht vorhanden"
   usage
fi    

if [ "$INCL_AS" = "" ] ; then
   if [ -f "$SOURCE_DIR/${video_filename}.conf" ] ; then
      source "$SOURCE_DIR/${video_filename}.conf"
      INCL_AS="+"
   else 
      MP_STREAMS="123456789"
      DD_STREAMS="123456789"
      INCL_AS="*"
   fi   
elif [ "$INCL_AS" = "+" ] ; then
   echo "MP_STREAMS=\"$MP_STREAMS\"" > "$SOURCE_DIR/${video_filename}.conf"
   echo "DD_STREAMS=\"$DD_STREAMS\"" >> "$SOURCE_DIR/${video_filename}.conf"
elif [ "$INCL_AS" = "*" ] ; then
   [ -f "$SOURCE_DIR/${video_filename}.conf" ] && rm -f "$SOURCE_DIR/${video_filename}.conf"
fi
					  					  
Newline=$'\n'
IFS="${Newline}"
AS_MP=0
AS_DD=0
VS=0
AM="${Newline} "
AD="${Newline} "
V="${Newline} "
for i in $(grep "^X [12]" "$VIDEO_DIR/info.vdr") ; do
   S_TYPE=${i:2:1}
   S_DET=${i:4:2}
   S_INFO=${i:7}
   if [ "$S_TYPE" = "1" ] ; then
      VS=$(($VS + 1))
      V="$V${Newline}Video Information:  $S_INFO"
   else
      if [ "$S_DET" = "05" ] ; then
         AS_DD=$(($AS_DD+1))
         INCL="-"
         case "$DD_STREAMS" in
            *$AS_DD*) INCL=$INCL_AS ;;
         esac   
         AD="$AD${Newline}Audio DD  Spur $AS_DD:   $INCL $S_INFO"
      else
         AS_MP=$(($AS_MP+1))
         INCL="-"
         case "$MP_STREAMS" in
            *$AS_MP*) INCL=$INCL_AS ;;
         esac   
         AM="$AM${Newline}Audio MP2 Spur $AS_MP:   $INCL $S_INFO"
      fi    
   fi
done
echo ""
echo "Groesse: $(du -hsL "$VIDEO_DIR")"   
echo ""
echo "Film: $video_filename"   
echo ""
for i in $V $AM $AD ; do
   echo $i
done      
