dnl Process this file with autoconf to produce a configure script.
AC_INIT(libapt-front, 0.4.0, [libapt-front-devel@lists.alioth.debian.org])
AC_CONFIG_SRCDIR([configure.ac])
dnl AC_CONFIG_AUX_DIR(admin)
AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_GNU_GETTEXT_VERSION(0.12.1)
AM_CONFIG_HEADER(config.h)

dnl To use subdirs
AC_PROG_MAKE_SET

AC_LANG([C++])

AC_ISC_POSIX
AC_PROG_CC
AC_PROG_CXX
AM_PROG_CC_STDC
AC_HEADER_STDC

AM_GNU_GETTEXT([external])

#AM_PROG_LEX
#AC_PROG_YACC

dnl Use libtool
AM_ENABLE_STATIC
AM_DISABLE_SHARED
AM_PROG_LIBTOOL

LIBWIBBLE_DEFS
LIBTAGCOLL2_DEFS
LIBEPT_DEFS

#LIBTAGCOLL_VERSION_INFO=`echo $VERSION | awk -F. '{ printf "%d:%d:%d", $1+$2, $3, $2 }'`
#AC_SUBST(LIBTAGCOLL_VERSION_INFO)

dnl Directory where the shared databases are kept
debtagsdbdir="$localstatedir/lib/debtags"
AC_SUBST(debtagsdbdir)

dnl Directory where the cached downloaded data are kept
debtagsdownloaddir="$localstatedir/cache/debtags"
AC_SUBST(debtagsdownloaddir)

dnl Directory where Debtags configuration is kept
debtagsconfdir="$sysconfdir/debtags"
AC_SUBST(debtagsconfdir)

dnl Directory where Debtags's packaged data files are kept
debtagsdatadir="$datadir/debtags"
AC_SUBST(debtagsdatadir)

CXXFLAGS="-Wall $CXXFLAGS"

AC_CONFIG_FILES([ po/Makefile.in
Makefile
apt-front/Makefile
tests/Makefile
utils/Makefile
doc/Makefile
doc/libapt-front.dox
libapt-front.pc
])
AC_OUTPUT

