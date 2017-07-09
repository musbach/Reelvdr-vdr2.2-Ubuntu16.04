#
# Makefile for ReelBox packages
#
#

MAINSRC ?= $(shell cd ../../../../testing/src ; pwd)

#VDRDIR = $(MAINSRC)/vdr-1.7

### Allow user defined options to overwrite defaults:

#-include $(VDRDIR)/Make.config
#VDRDIR = $(MAINSRC)/vdr-1.7
#-include $(VDRDIR)/Make.common

CXX      ?= g++
CXXFLAGS ?= -g -O3 -Wall -Woverloaded-virtual -Wno-parentheses

# use ICE includes/libs from reelbox-devel-ice, not SDK
INCLUDES += -I/usr/include/intelce
INCLUDES += -I/usr/include/intelce/linux_user
#INCLUDES += -I../../reelvdr-output-ice/reelice-0.1
INCLUDES += -I$(SRCDIR)/vdr-plugins/src/reelice

LIBDIRS = -L/usr/lib/intelce
LDFLAGS = -rdynamic
LDFLAGS  += -Wl,-rpath-link=/usr/lib/intelce

#LIBS += -lgdl -lgma -lismd_audio -lismdmessage -lsven -losal -lpal -lsrb -lsystem_utils -lplatform_config
LIBS  = -lpng -lz -lm -lpthread
LIBS += -lgdl -lismd_audio -lsrb

TARGET = splash

OBJS = splash.o util.o util_ImagePNG.o util_Surfaces.o util_VDR.o util_TvMode.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) $(LIBDIRS) $(LIBS) -o $@

%.o: %.c*
	$(CXX) $(CXXFLAGS) $(LDFLAGS )-c $(DEFINES) $(INCLUDES) $<

clean:
	@rm -f *.o *~ $(TARGET)

