#!/bin/bash
#set -x

YAC_CONF_DIR="${YAC_CONF_DIR:=/etc/vdr/plugins/yacoto}"
DVD_CONF="${YAC_CONF_DIR}/conf/dvd.conf"
YAC_DIR="${YAC_DIR:=/etc/vdr/plugins/yacoto}"

CONF_LINE="$(grep DVD_MENU $DVD_CONF)"
act_conf="${CONF_LINE#*=\"}"
act_conf="${act_conf%%\"*}"
val_conf="none"

all_conf="none"
for curr_basedir in ${YAC_CONF_DIR}/conf ${YAC_DIR}/conf; do
	if [ -d ${curr_basedir} ]; then
		cd ${curr_basedir}
		for dvd_menu in dvd/*/mm-button.png ; do
			if [[ ${curr_basedir} = ${YAC_DIR}/conf ]]; then
				[ ! -s $dvd_menu ] && break
			fi
			cfg=${dvd_menu%/*}
			if ! [[ $all_conf =~ ${cfg##*/} ]]; then
				all_conf="$all_conf,${cfg##*/}"
				[ "${cfg##*/}" = "$act_conf" ] && val_conf=$act_conf
			fi
		done
	fi
done
if [ "$act_conf" != "none" ] && [ "$act_conf" != "$val_conf" ] ; then
   logger -s "Active dvd menu <$act_conf> is invalid"
fi

sed -i $DVD_CONF -e "s/\(^DVD_MENU=.*#~[^~]*~[^~]*~[^~]*~\).*/\1$all_conf~/"
