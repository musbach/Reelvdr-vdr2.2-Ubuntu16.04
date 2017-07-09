#Comment this out to disable debugging output
#DEBUG=1
#VERBOSE=1
#WIN32=1
#VERBOSE=1
#BACKTRACE=1

ifdef RBMINI
  ARMEL=1
endif

ARCH= $(shell $(CC) -dumpmachine)
APPLE_DARWIN = $(shell echo $(ARCH) | grep -q 'apple-darwin' && echo "1" || echo "0")
CYGWIN = $(shell echo $(ARCH) | grep -q 'cygwin' && echo "1" || echo "0")
MIPSEL = $(shell echo $(ARCH) | grep -q 'mipsel' && echo "1" || echo "0")

DEFS=-DCLIENT -DLIBRARY -D_REENTRANT -D_GNU_SOURCE

API_SOCK=1

VDRDIR=../../../../../vdr
include $(VDRDIR)/Make.config

ifdef ARMEL
  XML_INC := -I/usr/arm-linux-gnueabi/include/libxml2
  XML_LIB := -lxml2
  CROSS = arm-linux-gnueabi-
else
  ifeq ($(MIPSEL),1)
    DEFS:=$(DEFS) -DMIPSEL
    XML_INC:=-I../../libxml2/include
    XML_LIB:=-L../../libxml2/lib
  else
    XML_INC:=`xml2-config --cflags`
    XML_LIB:=`xml2-config --libs`
    LIBRARY_PATH=/usr/lib
  endif
endif
CFLAGS:= $(CFLAGS) -fPIC -Wall -I../common $(DEFS)
CFLAGS ?= -fPIC -pg -O2 -Wall -Woverloaded-virtual -Wno-parentheses -pthread

ifdef BACKTRACE
CFLAGS:= $(CFLAGS) -DBACKTRACE -g
endif

ifdef API_SHM
LDFLAGS:= $(LDFLAGS) -lrt
CFLAGS:= $(CFLAGS) -DAPI_SHM
endif
ifdef API_SOCK
CFLAGS:= $(CFLAGS) -DAPI_SOCK
endif

ifdef VERBOSE
CFLAGS:= $(CFLAGS) -DDEBUG
DEBUG=1
endif

CFLAGS:= $(CFLAGS)  -I../dvbloop $(XML_INC)
LDFLAGS:=$(LDFLAGS)
LDLIBS:=$(XML_LIB) -lpthread -lz -lm

ifdef DEBUG
LDFLAGS:= $(LDFLAGS) -g -rdynamic
CFLAGS:= $(CFLAGS) -g -O0
else
CFLAGS:= $(CFLAGS) -O3
endif

MCLI = mcli

#MCLI_OBJS= mld_common.o mld_client.o mld_reporter.o mcast.o recv_tv.o recv_ccpp.o tools.o tca_handler.o tra_handler.o satlists.o interfaces.o api_server.o ciparser.o ci_handler.o mmi_handler.o
MCLI_OBJS= mld_reporter.o recv_tv.o tca_handler.o tra_handler.o satlists.o api_server.o ci_handler.o mmi_handler.o
MCLI_COBJS= ../common/mld_common.o ../common/mld_client.o ../common/mcast.o ../common/tools.o ../common/interfaces.o ../common/ciparser.o ../common/recv_ccpp.o
MCLI_OBJS := $(MCLI_OBJS) $(MCLI_COBJS)

MCLI_SOBJS = main.o
MCLI_SOBJS := $(MCLI_SOBJS) dvblo_handler.o input.o

all: lib$(MCLI)
VPATH = .:../common

static: $(MCLI)-static


MAKEDEP = $(CXX) -MM -MG
DEPFILE = .dependencies
$(DEPFILE): Makefile
	$(MAKEDEP) $(CFLAGS) $(MCLI_OBJS:%.o=%.c) > $@

-include $(DEPFILE)


$(MCLI): $(MCLI_OBJS) $(MCLI_SOBJS)
	$(CC) $(LDFLAGS) -o $@ $(MCLI_OBJS) $(MCLI_SOBJS) $(LDLIBS)
ifndef DEBUG
	strip $(MCLI)
endif

lib$(MCLI): $(MCLI_OBJS)
	$(CC) $(LDFLAGS) -shared -o $@.so $(MCLI_OBJS) $(LDLIBS)
	$(AR) $(ARFLAGS) $@.a $(MCLI_OBJS)


$(MCLI)-shared: lib$(MCLI)
	$(CC) -c $(CFLAGS) -ULIBRARY -o main.o main.c
	$(CC) -c $(CFLAGS) -ULIBRARY -o input.o input.c
	$(CC) -c $(CFLAGS) -ULIBRARY -o dvblo_handler.o dvblo_handler.c
	$(CC) $(LDFLAGS) -o $@ $(MCLI_SOBJS) $(LDLIBS) -L. -lmcli

$(MCLI)-static: $(MCLI_OBJS) $(MCLI_SOBJS)
	$(CC) $(LDFLAGS) -static -static-libgcc -o $@ $(MCLI_OBJS) $(MCLI_SOBJS) $(LDLIBS) $(LIBRARY_PATH)/libxml2.a $(LIBRARY_PATH)/libz.a $(LIBRARY_PATH)/libm.a $(LIBRARY_PATH)/libpthread.a
ifndef DEBUG 
	strip $(MCLI)-static
endif

api_shm_test.o: api_shm_test.c
	$(CC) -c $(CFLAGS) -DUSE_SHM_API -o $@ $<
	
api_sock_test.o:api_sock_test.c
	$(CC) -c $(CFLAGS) -DUSE_SOCK_API -o $@ $<
	
$(MCLI)-shmtest: api_shm_test.o
	$(CC) $(LDFLAGS) -o $@ api_shm_test.o $(LDLIBS) -lrt

$(MCLI)-socktest: api_sock_test.o
	$(CC) $(LDFLAGS) -o $@ api_sock_test.o 
	
install: mcli
	install -p $< /usr/sbin/$<

install-lib: libmcli.la
	libtool --mode=install install $< /usr/local/lib/	

install-shared: mcli-shared
	libtool --mode=install install $< /usr/local/bin

depend: .dependencies
	#makedepend -Y -- $(CFLAGS)  -- *c >/dev/null 2>&1

clean:
	rm -f $(MCLI) $(MCLI)-* *.elf *.gdb *.o *.lo *.la *~ *.so *.a *.def *.dll *.dylib out.ts

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

%.lo: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
