#!/bin/sh

MAKETARGET=false
if [ "$1" = "-t" ]; then
	MAKETARGET=true
	shift
fi

SRCDIR="$1"
DESTDIR="$2"

while read src dest type owner ; do 
	case $src in
		\#*)
			#echo "line is a comment"
			;;
		*)
			[ "$src" = "" ] && continue		#empty line
			if [ "$dest" = "" ] ||  [ "$dest" = "-" ]; then
				dest=$src
			fi
			if $MAKETARGET; then
				echo ${SRCDIR}/$dest
			else
				echo ${DESTDIR}/$dest: ${SRCDIR}/$src
			fi
			;;
	esac
done < /dev/stdin


