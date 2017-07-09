#	$NetBSD: Makefile.in,v 1.5 2005/06/10 04:36:12 lukem Exp $
#

srcdir	= .

SHELL	= /bin/sh

CC	= gcc
CFLAGS	= -g -O2
CPPFLAGS= -I${srcdir} -I${srcdir}/.. -I. -I.. -I${srcdir}/../libedit  -I${srcdir}/../libnetbsd 

AR	= ar
RANLIB	= ranlib

LIB	= libnetbsd.a

OBJS	=  ${LIBOBJDIR}fgetln$U.o ${LIBOBJDIR}setprogname$U.o ${LIBOBJDIR}sl_init$U.o ${LIBOBJDIR}strlcat$U.o ${LIBOBJDIR}strlcpy$U.o ${LIBOBJDIR}strunvis$U.o ${LIBOBJDIR}strvis$U.o ${LIBOBJDIR}glob$U.o


all:	${LIB}

${LIB}: ${OBJS}
	${AR} cr $@ ${OBJS}
	${RANLIB} $@

${OBJS}: ${srcdir}/../tnftp.h ../config.h

.c.o:
	${CC} ${CFLAGS} ${CPPFLAGS} -c $<

install:

clean:
	rm -f ${LIB} ${OBJS}

distclean: clean
	rm -f Makefile
