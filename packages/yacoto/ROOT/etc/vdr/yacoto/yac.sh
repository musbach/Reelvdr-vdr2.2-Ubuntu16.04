#!/bin/bash

SOURCE_DIR="${0%/*}"

if [ "${SOURCE_DIR:0:1}" = "." ] ; then
   SOURCE_DIR="$(pwd)/${SOURCE_DIR}"
elif [ "${SOURCE_DIR:0:1}" != "/" ] ; then
   SOURCE_DIR="$(pwd)"
fi

. /etc/default/globals

set -x

text=`tl "Converting %s to %t"`
echo $text | sed -e s§%s§"$2"§ -e s/%t/$1/


cmd="${SOURCE_DIR}/yacoto.sh"
logger -s "Starte <$cmd $1 $2>"
screen -dm sh -c "$cmd \"$1\" \"$2\""
