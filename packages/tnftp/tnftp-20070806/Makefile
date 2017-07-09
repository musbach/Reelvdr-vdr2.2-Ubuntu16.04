#	$NetBSD: Makefile.in,v 1.3 2005/05/11 03:03:42 lukem Exp $
#

srcdir	= .

SHELL	= /bin/sh




SUBDIRS	= libedit libnetbsd src

all:	ftp

ftp:	libedit.a libnetbsd.a
	( cd src; ${MAKE} )

libedit.a:
	( cd libedit; ${MAKE} )

libnetbsd.a:
	( cd libnetbsd; ${MAKE} )

install clean:
	@for i in ${SUBDIRS}; do \
	    ( echo "$@ ===> $$i" ; cd $$i ; ${MAKE} $@ ); \
	done

distclean: clean
	@for i in ${SUBDIRS}; do \
	    ( echo "$@ ===> $$i" ; cd $$i ; ${MAKE} $@ ); \
	done
	rm -f Makefile config.cache config.log config.status config.h
