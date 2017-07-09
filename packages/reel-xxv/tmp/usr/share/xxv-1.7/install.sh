#!/bin/sh
#
# Shell based installer of xxv
# 
# use options like
# export PREFIX=/opt/xxv;./install.sh
#
# $Id$
#
# based on install.sh for vdradmin
#   Copyright (c) 2003 Frank (xpix) Herrmann)
#   Copyright (c) 2005 Andreas Mair
#   Copyright (c) 2006 Andreas Brachold, Ronny Kornexl 
#
################################################################################
# ROOT should only used for testing, installing outside root folder
# please use PREFIX as destination for installing
ROOT=${ROOT:-""}

################################################################################
# use options like
# export PREFIX=/opt/xxv;./install.sh
#
PREFIX=${PREFIX:-$ROOT/usr/local}

################################################################################
# destination for installing
#
BINDIR=${BINDIR:-$PREFIX/bin}
LIBDIR=${LIBDIR:-$PREFIX/lib/xxv}
SHAREDIR=${SHAREDIR:-$PREFIX/share/xxv}
DOCDIR=${DOCDIR:-$PREFIX/share/xxv/doc}
CONTRIBDIR=${CONTRIBDIR:-$PREFIX/share/xxv/contrib}
LOCDIR=${LOCDIR:-$PREFIX/share/xxv/locale}
SKINDIR=${SKINDIR:-$PREFIX/share/xxv/skins}
MANDIR=${MANDIR:-$PREFIX/share/man/man1}

################################################################################
# some files
#
LOGDIR=${LOGDIR:-$ROOT/var/log}
PIDFILE=${PIDFILE:-$ROOT/var/run/xxvd.pid}
INITFILE=${INITFILE:-$ROOT/etc/init.d/xxvd}
ETCDIR=${ETCDIR:-$ROOT/etc/xxv}

################################################################################
# to adjust more options into xxvd.cfg
#
# e.g. :
# [CHANNELS]
# empty=y
# file=/etc/vdr/channels.conf
# [GRAB]
# file=/dev/shm/live.jpg
# 
# use :
# export CHANNELS_empty=y \
# CHANNELS_file=/etc/vdr/channels.conf \
# GRAB_file=/dev/shm/live.jpg; \
# ./install.sh
#
################################################################################
# begin of scripting part ( below this line, aren't user options )
#
LANGS="de"


PATH=$PATH:/sbin:/bin:/usr/sbin:/usr/bin

usage()
{
	echo ""
	echo "usage: $(basename $0) [-h] [-p] [-u]"
	echo ""
	echo "Default action is install xxv."
	echo -e "\t-h : This message."
	echo -e "\t-p : check perl module."
	echo -e "\t-u : uninstall xxv."
	echo ""
	exit 0
}

killRunning()
{
	local KILLED=0
	ps a | grep xxvd | grep perl | grep -v grep | while read PID UNWANTED
	do
		KILLED=1
		kill $PID
	done

	return $KILLED
}

# $1 - the Perl module to check for.
checkPerlModule()
{
	[ -z "$1" ] && return 1

	local MODULE=$1
	local ALT_MODULE=$2
	local ALT_MESSAGE=
	[ "$ALT_MODULE" ] && ALT_MESSAGE=" or $ALT_MODULE"

	echo -n "Checking for Perl module $MODULE$ALT_MESSAGE... "
	perl -ce 'BEGIN{$0 =~ /(^.*\/)/; $BASENAME = $1; unshift(@INC, $BASENAME . "lib/");} use '$MODULE >/dev/null 2>&1
	if [ $? -eq 2 ]; then
		if [ "$ALT_MODULE" ]; then
			perl -ce 'BEGIN{$0 =~ /(^.*\/)/; $BASENAME = $1; unshift(@INC, $BASENAME . "lib/");} use '$ALT_MODULE >/dev/null 2>&1
			[ $? -eq 0 ] && echo " $ALT_MODULE found" && return 0
		fi
		echo " MISSING"
		read -p "Do you want to install $MODULE? (y)es/(f)orced/(N)ever : "
		if [ "$REPLY" = "y" -o "$REPLY" = "Y" -o "$REPLY" = "yes" -o "$REPLY" = "j" ]; then
            su -c "perl -MCPAN -e 'install '$MODULE"
		elif [ "$REPLY" = "f" -o "$REPLY" = "F" -o "$REPLY" = "force" ]; then
            su -c "perl -MCPAN -e 'force install '$MODULE"
        fi
	else
		echo " found"
	fi
}

perlModules()
{
	checkPerlModule CGI
	checkPerlModule Compress::Zlib
	checkPerlModule Config::Tiny
	checkPerlModule Data::Dumper
	checkPerlModule Date::Manip
	checkPerlModule DBD::mysql
	checkPerlModule DBI
	checkPerlModule Digest::MD5
	checkPerlModule Digest::HMAC_MD5
	checkPerlModule Encode
	checkPerlModule Event
	checkPerlModule Font::TTF::Font
	checkPerlModule GD
	checkPerlModule Getopt::Long
	checkPerlModule HTML::TextToHTML
	checkPerlModule HTML::TreeBuilder
	checkPerlModule JSON
	checkPerlModule Linux::Inotify2
	checkPerlModule LWP::Simple
	checkPerlModule LWP::UserAgent
	checkPerlModule Locale::gettext
	checkPerlModule MIME::Base64
	checkPerlModule MP3::Info
	checkPerlModule Net::Amazon
	checkPerlModule Net::Amazon::Request::Artist
	checkPerlModule Net::XMPP
	checkPerlModule Proc::Killfam
	checkPerlModule Proc::ProcessTable
	checkPerlModule SOAP::Lite
	checkPerlModule SOAP::Transport::HTTP
	checkPerlModule Template
	checkPerlModule Time::Local
	checkPerlModule Time::HiRes
	checkPerlModule URI::Escape
	checkPerlModule XML::RSS
	checkPerlModule XML::Simple
}

makeDir()
{
	[ -z "$1" ] && return 1
	local DIR=$1
	local MUST_CREATE=${2:-0}
	if [ -e "$DIR" -a ! -d "$DIR" ]; then
		echo "$DIR exists but is no directory!"
		echo "Aborting..."
		return 1
	elif [ -d $DIR -a $MUST_CREATE = 1 ]; then
		echo "$DIR exists. Please remove it before calling install.sh!"
		echo "Aborting..."
		return 1
	fi
	if [ ! -e "$DIR" ]; then
		mkdir -p "$DIR"
		if [ $? -ne 0 ]; then
			echo "Failed to create directory $DIR!"
			echo "Aborting..."
			return 1
		fi
	fi

	return 0
}

doInstall()
{
	echo ""
	echo "********* Installing xxv *************"
	echo ""

	perlModules

	echo ""
	echo "********* Copying files *************"
	echo ""
 
	makeDir "$LIBDIR" 1 && cp -r lib/* "$LIBDIR" || exit 1
	makeDir "$SHAREDIR" 1 && cp -r share/* "$SHAREDIR" || exit 1
	makeDir "$DOCDIR" 1 && cp INSTALL doc/COPYING doc/CHANGELOG doc/docu.tmpl doc/README "$DOCDIR" || exit 1
	makeDir "$CONTRIBDIR" 1 && cp contrib/update-xxv contrib/upgrade-xxv-db.sql "$CONTRIBDIR" || exit 1
	makeDir "$SKINDIR" 1 && cp -r skins/* "$SKINDIR" || exit 1
    (cd "$SKINDIR";ln -s html default) || exit 1
	makeDir "$MANDIR" && cp doc/xxvd.1 "$MANDIR" || exit 1
	makeDir "$BINDIR" || exit 1
	makeDir "$LOGDIR" || exit 1
	makeDir `dirname $PIDFILE` || exit 1
	makeDir "$ETCDIR" || exit 1
	makeDir `dirname $INITFILE` || exit 1

	for lang in $LANGS
	do
		makeDir "$LOCDIR/$lang/LC_MESSAGES/" && install -m 644 "locale/$lang/LC_MESSAGES/xxv.mo" "$LOCDIR/$lang/LC_MESSAGES/xxv.mo" || exit 1
	done

	local RESTART=
	[ ! -e "$BINDIR" ] && mkdir -p "$BINDIR"
	if [ ! -d "$BINDIR" ]; then
	   	   echo "$BINDIR exists but is no directory!"
		   echo "Aborting..."
		   exit 1
    fi

	killRunning
	if [ $? -ne 0 ] ; then
		RESTART=1
 		echo "Killed running xxv..."
    fi

	echo ""
	echo "********* Adjust Config *************"
	echo ""

	echo "$BINDIR/xxvd"

  	sed < "bin/xxvd" > "$BINDIR/xxvd" \
  	    -e "s:\$RealBin/../lib:${LIBDIR}:" \
  	    -e "s:/var/log/xxvd.log:${LOGDIR}/xxvd.log:" \
  	    -e "s:/var/run/xxvd.pid:${PIDFILE}:" \
  	    -e "s:\$RealBin/../locale:${LOCDIR}:" \
  	    -e "s:\$RealBin/../lib/XXV/MODULES:${LIBDIR}/XXV/MODULES:" \
  	    -e "s:\$RealBin/../lib/XXV/OUTPUT/NEWS:${LIBDIR}/XXV/OUTPUT/NEWS:" \
  	    -e "s:\$RealBin/../etc/xxvd.cfg:${ETCDIR}/xxvd.cfg:" \
  	    -e "s:\$RealBin/../doc:${DOCDIR}:" \
  	    -e "s:HTMLDIR     => \"\$RealBin/../:HTMLDIR     => \"${SKINDIR}:" \
  	    -e "s:\$RealBin/../share/fonts/ttf-bitstream-vera:${SHAREDIR}/fonts/ttf-bitstream-vera:" \
  	    -e "s:\$RealBin/../share/vtx:${SHAREDIR}/vtx:" \
  	    -e "s:\$RealBin/../share/news:${SHAREDIR}/news:" \
  	    -e "s:\$RealBin/../contrib:${CONTRIBDIR}:"

	[ ! -e "$INITFILE" -a "$INITFILE" != "false" ] && echo "$INITFILE"

	[ ! -e "$INITFILE" -a "$INITFILE" != "false" ] && sed < "etc/xxvd" > "$INITFILE" \
  	    -e "s:/root/XXV:${BINDIR}:" \
  	    -e "s:bin/xxvd:./xxvd:" \
  	    -e "s:\$FOLDER/lib/XXV/MODULES:${LIBDIR}/XXV/MODULES:" \
  	    -e "s:\$FOLDER/lib/XXV/OUTPUT/NEWS:${LIBDIR}/XXV/OUTPUT/NEWS:" \
  	    -e "s:\$FOLDER/etc/xxvd.cfg:${ETCDIR}/xxvd.cfg:" \
  	    -e "s:/var/run/xxvd.pid:${PIDFILE}:" \
  	    -e "s:HTMLDIR=\"\$FOLDER:HTMLDIR=\"${SKINDIR}:" \
  	    -e "s:\$FOLDER/doc:${DOCDIR}:" \
  	    -e "s:/var/log/xxvd.log:${LOGDIR}/xxvd.log:" \
  	    -e "s:\$FOLDER/contrib:${CONTRIBDIR}:" \
  	    -e "s:\$FOLDER/share/news:${SHAREDIR}/news:"

	echo "$ETCDIR/xxvd.cfg"

	[ ! -e "$ETCDIR/xxvd.cfg" ] && \
	    while read i ; do
		case $i in
		    [*) VAR=$(echo $i | tr a-z A-Z | tr -d :[])
			echo $i
			;;
		     *) case ${VAR}${i%%=*} in
			     GENERALDSN|GENERALUSR|GENERALPWD)
				echo $i ; eval $i ; eval GENERAL_${i%%=*}=\${${i%%=*}##*=} ; continue
				;;
			esac
			eval VALUE=$(echo "\$${VAR}_${i}" | cut -d= -f1)
			test -n "$VALUE"
			case $? in
			     0) echo "${i%%=*}=$VALUE"
				;;
			     *) echo $i
				;;
			esac
			;;
		esac
	    done < "etc/xxvd.cfg.example" > "$ETCDIR/xxvd.cfg"

	echo ""
	echo "********* Create database *************"
	echo ""

    mysql -u root -e "
use mysql;
CREATE DATABASE IF NOT EXISTS ${GENERAL_DSN};
use ${GENERAL_DSN};
grant all privileges on ${GENERAL_DSN}.* to ${GENERAL_USR}@localhost IDENTIFIED BY '${GENERAL_PWD}';
flush privileges;"

	echo ""
	echo "********* Check database *************"
	echo ""

    "${CONTRIBDIR}/update-xxv" -d "${GENERAL_DSN}"

	echo ""
	echo "********* Set permissions *************"
	echo ""

	chmod a+x "$BINDIR/xxvd"

    if [ -e "$INITFILE" -a "$INITFILE" != "false" ]; then

        echo ""
        echo "********* Set startscript *************"
    	echo ""

    	chmod a+x "$INITFILE"

        RVV=`runlevel | cut -d " " -f 2`
        makeDir "$ROOT/etc/rc$RVV.d" || exit 1
        ln -s "$INITFILE" "$ROOT/etc/rc$RVV.d/S90xxvd"
        ln -s "$INITFILE" "$ROOT/etc/rc$RVV.d/K90xxvd"

      	if [ "$RESTART" ]; then
  	     	echo "Restarting xxv..."
  	     	"$INITFILE" start
  	    fi
    fi

	echo ""
	echo ""
	echo "xxv has been installed!"
	echo ""
	if [ -z "$RESTART" ]; then
		[ ! -e "$INITFILE" -a "$INITFILE" != "false" ] && \
            echo "*) run \"$INITFILE start\" to start xxv."
		echo "*) open your browser with http://host:8080"
		echo "    login with xxv / xxv"
	        echo "    and adjust all preferences for your system"
	        echo "*) and watch \"${LOGDIR}/xxvd.log\" for messages"
	fi
	exit 0
}

doUninstall()
{
	echo ""
	echo "********* Uninstalling xxv *************"
	echo ""

	killRunning
	if [ -d "$LIBDIR" ]; then
		rm -rf "$LIBDIR" || echo "Can't remove $LIBDIR"
	fi
	if [ -d "$SHAREDIR" ]; then
		rm -rf "$SHAREDIR" || echo "Can't remove $SHAREDIR"
	fi
	if [ -d "$DOCDIR" ]; then
		rm -rf "$DOCDIR" || echo "Can't remove $DOCDIR"
	fi
	if [ -d "$CONTRIBDIR" ]; then
		rm -rf "$CONTRIBDIR" || echo "Can't remove $CONTRIBDIR"
	fi
	if [ -d "$SKINDIR" ]; then
		rm -rf "$SKINDIR" || echo "Can't remove $SKINDIR"
	fi
	if [ -e "$MANDIR/xxvd.1" ]; then
		rm -f "$MANDIR/xxvd.1" || echo "Can't remove $MANDIR/xxvd.1"
	fi
	if [ -e "$BINDIR/xxvd" ]; then
		rm -f "$BINDIR/xxvd" || echo "Can't remove $BINDIR/xxvd"
	fi
	if [ -e "$INITFILE" ]; then
		rm -f "$INITFILE" || echo "Can't remove $INITFILE"
	fi

  RVV=`runlevel | cut -d " " -f 2`
	if [ -h "$ROOT/etc/rc$RVV.d/S90xxvd" ]; then
		rm -f "$ROOT/etc/rc$RVV.d/S90xxvd" || echo "Can't remove $ROOT/etc/rc$RVV.d/S90xxvd"
	fi
	if [ -h "$ROOT/etc/rc$RVV.d/K90xxvd" ]; then
		rm -f "$ROOT/etc/rc$RVV.d/K90xxvd" || echo "Can't remove $ROOT/etc/rc$RVV.d/K90xxvd"
	fi

	if [ -e "$LOGDIR/xxvd.log" ]; then
		rm -f "$LOGDIR/xxvd.log" || echo "Can't remove $LOGDIR/xxvd.log"
	fi
	if [ -e "$PIDFILE" ]; then
		rm -f "$PIDFILE" || echo "Can't remove $PIDFILE"
	fi
	for lang in $LANGS
	do
		if [ -e "$LOCDIR/$lang/LC_MESSAGES/xxv.mo" ]; then
      rm -f "$LOCDIR/$lang/LC_MESSAGES/xxv.mo" || echo "Can't remove $LOCDIR/$lang/LC_MESSAGES/xxv.mo"
    fi
	done

	echo ""
	echo "xxv has been uninstalled!"
	echo ""
	if [ -d "$ETCDIR" ]; then
		echo "Your configuration files located in $ETCDIR have NOT been deleted!"
		echo "If you want to get rid of them, please delete them manually!"
		echo ""
	fi
}

{

UNINSTALL=
PERL=
while [ "$1" ]
do
	case $1 in
		-u) UNINSTALL=1;;
		-p) PERL=1;;
		-h) usage;;
		*) echo "Ignoring param \"$1\$.";;
	esac
	shift
done

if [ $(basename $0) = "uninstall.sh" -o "$UNINSTALL" ]; then
	doUninstall
elif [ "$PERL" ]; then
	echo ""
	echo "Only LISTING needed Perl modules..."
	perlModules
	echo "...done."
else
	doInstall
fi
} # | tee -a install.log
