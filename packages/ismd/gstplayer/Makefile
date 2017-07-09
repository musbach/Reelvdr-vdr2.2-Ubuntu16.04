
MACHINE  ?= -m32 -march=pentium3 -mmmx -msse -mfpmath=sse

CC       ?= $(CCACHE) $(DISTCC) $(CROSS)gcc
CFLAGS   ?= -O2 -g -Wall -pg $(MACHINE)

CXX      ?= g++
CXXFLAGS ?= -g -O3 -Wall -Woverloaded-virtual -Wno-parentheses

TARGET   ?= gstplayer

OBJS := $(TARGET).o

INCLUDES += -I/usr/include/libxml2  -I/usr/include/glib-2.0  -I/usr/lib/glib-2.0/include -I/usr/lib/i386-linux-gnu/glib-2.0/include/
INCLUDES += -I/usr/include/gstreamer-0.10  -I/usr/include/intelce  -I/usr/include/intelce/linux_user
#LDFLAGS  += -shared -Wl,-rpath-link=/usr/lib/intelce
LIBS     += -L/usr/lib -lm -ldl -lxml2 -lglib-2.0 -lgstbase-0.10 -lgstinterfaces-0.10

LIBDIRS  += -L/usr/lib/intelce

all: gstplayer

%.o: %.c
	$(CC) $(CFLAGS) -c $(DEFINES) $(INCLUDES) $<


$(TARGET): $(OBJS) Makefile
	$(CC) $(LDFLAGS) $(OBJS) $(LIBDIRS) $(LIBS) -o $@

clean:
	-rm -f *.o *~ $(TARGET)

install: all
	cp $(TARGET) /media/intel/usr/sbin/


