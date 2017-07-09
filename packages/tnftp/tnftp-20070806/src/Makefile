#	$NetBSD: Makefile.in,v 1.6 2007/05/09 04:44:36 lukem Exp $
#

srcdir	= .

SHELL	= /bin/sh

prefix	= /usr
exec_prefix = ${prefix}
bindir	= ${exec_prefix}/bin
datarootdir = ${prefix}/share
mandir	= ${prefix}/share/man
transform = s,x,x,

mandircat1 = ${mandir}/cat1

CC	= gcc
CFLAGS	= -g -O2
CPPFLAGS= -I${srcdir} -I${srcdir}/.. -I. -I.. -I${srcdir}/../libedit  -I${srcdir}/../libnetbsd 
LIBS	= -ledit -ltermcap  -lnetbsd
LDFLAGS	= -L../libedit  -L../libnetbsd

INSTALL	= /usr/bin/install -c

PROG	= ftp
SRCS	= cmds.c cmdtab.c complete.c domacro.c fetch.c ftp.c main.c \
	  progressbar.c ruserpass.c util.c
OBJS	= ${SRCS:.c=.o}


all:	${PROG}

${PROG}: ${OBJS}  ../libedit/libedit.a ../libnetbsd/libnetbsd.a
	${CC} ${CFLAGS} ${LDFLAGS} -o ${PROG} ${OBJS} ${LIBS}

${OBJS}: ${srcdir}/../tnftp.h ../config.h

.c.o:
	${CC} ${CFLAGS} ${CPPFLAGS} -c $<

install: all
	-mkdir -p ${bindir}
	${INSTALL} -m 555 ${PROG} ${bindir}/`echo ${PROG}|sed '$(transform)'`
	-mkdir -p ${mandircat1}
	${INSTALL} -m 444 ${srcdir}/${PROG}.cat1 ${mandircat1}/`echo ${PROG}|sed '$(transform)'`.1

clean:
	rm -f core ${PROG} ${OBJS}

distclean: clean
	rm -f Makefile
