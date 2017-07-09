#!/bin/bash

YAC_DIR="${YAC_DIR:=/etc/vdr/plugins/yacoto}"
YAC_CONF_DIR="${YAC_CONF_DIR:=/etc/vdr/plugins/yacoto}"

#
# will return one of the base directories $YAC_CONF_DIR or $YAC_DIR (in
# this order of precedence) in which the file or directory (also
# possibly given with an absolute or relative path) is found, or return nothing
# if the file or directory is not found in either location
function yac_choosedir() {
	# trim away leading full path if applicable
	inpath=$1
	inpath=${inpath##$YAC_CONF_DIR/}
	if [ -e "$YAC_CONF_DIR/$inpath" ]; then
		echo "$YAC_CONF_DIR"
		return 0
	else
		# trim away leading full path if applicable
		inpath=$1
		inpath=${inpath##$YAC_DIR/}
		if [ -e "$YAC_DIR/$inpath" ]; then
			echo "$YAC_DIR"
			return 0
		fi
	fi
	echo "yac_choosedir_INVALID"
	return 1
}

#
# will return the actual path to the first video, info, index or marks file
# of a vdr recording, depending if it's a TS recording or an "old" one,
# provided that the given full path or the current directory contain them,
# or interrupt execution on failure
function resolve_recfile() {
	pathonly="$(dirname "$1")"
	if [ "${pathonly}" = "" ]; then
		pathonly="$(pwd)"
	fi
	filetype="$(basename "$1")"
	resolved=""
	if [ ${filetype} = "1stvideo" ]; then
		if [ -f "${pathonly}/00001.ts" ]; then
			resolved="${pathonly}/00001.ts"
		elif [ -f "${pathonly}/001.vdr" ]; then
			resolved="${pathonly}/001.vdr"
		fi
	elif [ ${filetype} = "info" ] || [ ${filetype} = "index" ] || [ ${filetype} = "marks" ]; then
		if [ -f "${pathonly}/${filetype}" ]; then
			resolved="${pathonly}/${filetype}"
		elif [ -f "${pathonly}/${filetype}.vdr" ]; then
			resolved="${pathonly}/${filetype}.vdr"
		fi
	fi

	if [ -f "${resolved}" ]; then
		echo "${resolved}"
	else
		echo "WRONG path specified '${pathonly}/${filetype}'!"
		echo "Usage:  resolve_recfile [rec_path/]{1stvideo | info | index | marks}"
	fi
}
