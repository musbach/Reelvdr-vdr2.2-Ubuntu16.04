#!/bin/bash
YAC_DIR="${YAC_DIR:=/etc/vdr/plugins/yacoto}"
YAC_CONF_DIR="${YAC_CONF_DIR:=/etc/vdr/plugins/yacoto}"
YAC_CONF="${YAC_CONF_DIR}/yacoto.conf"

if [ ! -f $YAC_CONF ] ; then
   logger -s "Yac config <$CONFIG> nicht vorhanden"
   exit
fi

source $YAC_CONF
source $YAC_DIR/yac_helperfuncs.sh

YAC_PLG_CONF="${YAC_CONF_DIR}/yacadmin.conf"

function getVals() {
   ln=$1
   VAR=${ln%%=*}
   ln=${ln#*=\"}
   VAL=${ln%%\"*}
   [ "$VAL" = "" ] && VAL=" "
   ln=${ln#*\"}
   ln=${ln#*#}
   if [ "${ln:0:1}" = "~" ] ; then
      ln=${ln:1}
      COMMENT=${ln%%~*}
      ln=${ln#*~}
      TYPE=${ln%%~*}
      TYPE=${TYPE// /}
      ln=${ln#*~}
      LENGTH=${ln%%~*}
      LENGTH=${LENGTH// /}
      ln=${ln#*~}
      VAL_INPUT=${ln%%~*}
      [ "$TYPE" = "" ] && TYPE="F"
      [ "$LENGTH" = "" ] && LENGTH="99"
      [ "$VAL_INPUT" = "" ] && VAL_INPUT=" "
   else
      COMMENT=$ln
      TYPE="F"
      VAL_INPUT=" "
   fi
   [ "$COMMENT" = "" ] && COMMENT=$VAR
}


[ "$1" != "" ] && [ -f $1 ] && YAC_CONF=$1
[ "$2" != "" ] && [ -f $2 ] && YAC_PLG_CONF=$2

CFG_NAMES=""
Newline=$'\n'
IFS="${Newline}"

[ -f $YAC_PLG_CONF ] && mv $YAC_PLG_CONF $YAC_PLG_CONF.old
[ -f $YAC_PLG_CONF.new ] && rm $YAC_PLG_CONF.new

for cfg_file in $YAC_CONF_DIR/conf/*.conf ; do
	profile=${cfg_file##*/}
	profile=${profile%%\.*}
	script_dir="$(yac_choosedir conf/$profile.sh)/conf"
	exitcode="$?"
	if [ $exitcode = 0 ]; then
		[ -f "$script_dir/$profile.conf.sh" ] && sh "$script_dir/$profile.conf.sh"
		[ ! -f "$script_dir/$profile.sh" ] && continue
		CFG_NAMES="$CFG_NAMES,$profile"
		echo ":$profile" >> $YAC_PLG_CONF.new
		for i in $(grep "^[A-Z].*=" $cfg_file) ; do
			getVals "$i"
			case "$VAR" in
				*)
					echo "$cfg_file~$VAR~$VAL~$TYPE~$LENGTH~$VAL_INPUT~$COMMENT~" >> $YAC_PLG_CONF.new
					;;
			esac
		done
	fi
done

CFG_NAMES=${CFG_NAMES:1}
DEF_CFG=${CFG_NAMES%%,*}

ACT_CFG=$DEF_CFG

for i in $(grep "^[A-Z].*=" $YAC_CONF) ; do
   getVals "$i"

   case "$VAR" in
      CONFIG)
         case ",$CFG_NAMES," in
            *,$VAL,*)
               echo "CFG <$VAL> found"
               ;;
            *) 
               echo "CFG changed <$CFG_NAMES> <$VAL>"
               VAL=${CFG_NAMES:0}
               VAL=${VAL%%,*}
               ;;
         esac
         ACT_CFG=""
         TYPE="L"
         LENGTH="0"
         VAL_INPUT="$CFG_NAMES"
         ;;
      NICE_LEVEL)
         TYPE="I"
         LENGTH="3"
         VAL_INPUT="-19,19"
         ;;
      KEEP_LOGS)
         TYPE="B"
         LENGTH="0"
         VAL_INPUT=" "
         ;;
      *)
         ;;
   esac
   echo "$YAC_CONF~$VAR~$VAL~$TYPE~$LENGTH~$VAL_INPUT~$COMMENT~" >> $YAC_PLG_CONF
done

if [ "$ACT_CFG" != "" ] ; then
   echo "$YAC_CONF~CONFIG~$ACT_CFG~L~0~$CFG_NAMES~Konfiguration~" >> $YAC_PLG_CONF
fi
cat $YAC_PLG_CONF.new >> $YAC_PLG_CONF 
