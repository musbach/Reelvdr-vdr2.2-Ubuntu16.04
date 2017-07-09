#!/bin/bash
YAC_DIR="${YAC_DIR:=/etc/vdr/plugins/yacoto}"
YAC_CONF_DIR="${YAC_CONF_DIR:=/etc/vdr/plugins/yacoto}"

YAC_PLG_CONF="${YAC_CONF_DIR}/yacadmin.conf"

[ "$2" != "" ] && [ -f $2 ] && YAC_PLG_CONF=$2

old_cfg=""
grep "\.conf~.*~" $YAC_PLG_CONF | while read i ; do
   cfg_file=${i%%~*}

   if [ "$cfg_file" != "" ] ; then
      if [ "$cfg_file" != "$old_cfg" ] ; then
         [ -f $cfg_file ] && mv $cfg_file $cfg_file.old
         old_cfg=$cfg_file
      fi
      ln=${i#*~}
      VAR=${ln%%~*}
      ln=${ln#*~}
      VAL=${ln%%~*}
      [ "$VAL" = " " ] && VAL=""
      ln=${ln#*~}
      TYPE=${ln%%~*}
      ln=${ln#*~}
      LENGTH=${ln%%~*}
      ln=${ln#*~}
      VAL_INPUT=${ln%%~*}
      ln=${ln#*~}
      COMMENT=${ln%%~*}

      VARVAL="$VAR=\"$VAL\""
      printf "%-25s  #~$COMMENT~$TYPE~$LENGTH~$VAL_INPUT~\n" "$VARVAL" >> $cfg_file
   fi
done
