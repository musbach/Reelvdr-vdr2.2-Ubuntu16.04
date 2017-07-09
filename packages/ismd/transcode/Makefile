
include ../../Make.config

MACHINE  ?= -m32 -march=pentium3 -mmmx -msse -mfpmath=sse

CC       ?= $(CCACHE) $(DISTCC) $(CROSS)gcc
CFLAGS   ?= -O2 -g -Wall -pg $(MACHINE)

CXX      ?= $(CCACHE) $(DISTCC) $(CROSS)g++-4.4
CXXFLAGS ?= -g -O2 -funroll-loops -fomit-frame-pointer $(MACHINE) -Wall -Woverloaded-virtual

LDFLAGS  ?= -g -O2 -funroll-loops -fomit-frame-pointer $(MACHINE) -Wall -Woverloaded-virtual -fstack-protector-all
LDFLAGS  += -Wl,-rpath-link=/usr/lib/intelce

TARGET   ?= transcode

OBJS := $(TARGET).o

#INCLUDES += -I/usr/include/libxml2  -I/usr/include/glib-2.0  -I/usr/lib/glib-2.0/include
#INCLUDES += -I/usr/include/gstreamer-0.10  -I/usr/include/intelce  -I/usr/include/intelce/linux_user
#LDFLAGS  += -shared
#LIBS     += -lpthread -ldl -lxml2 -lglib-2.0 -lgstreamer-0.10 -lgstbase-0.10 -lgstvideo-0.10
#LIBS     += -ldl -lxml2 -lglib-2.0 -lgstbase-0.10 \
#            -lismd_audio -lismd_bufmon -lismd_clock -lismd_clock_recovery \
#            -lismd_core -lismd_demux -lismdmessage \
#            -lismd_viddec -lismd_videnc -lismd_vidpproc -lismd_vidrend -lismd_vidsink_direct -lismd_mux \
#            -lplatform_config -lpq_library -lsystem_utils -lgdl -lsven -lpal -lgstinterfaces-0.10  
#LIBS     += -lismd_audio -lismd_bufmon -lismd_clock -lismd_clock_recovery \
#            -lismd_core -lismd_demux -lismdmessage \
#            -lismd_viddec -lismd_videnc -lismd_vidpproc -lismd_vidrend -lismd_vidsink_direct -lismd_mux \
#            -lplatform_config -lsven -losal -lpal
#            -lplatform_config -lsystem_utils 
#            -lplatform_config -lpq_library -lsystem_utils -lgdl -lsven -lpal
#

INCLUDES += -I/usr/include/intelce  -I/usr/include/intelce/linux_user
VDRDIR   ?=/media/hd/home/reel/s/testing/src/vdr-1.4
INCLUDES += -I$(VDRDIR)
LIBS     += -lismd_audio -lismd_core -lismd_mux -lismd_demux_v3 -lismd_viddec -lismd_videnc -lismd_vidpproc -lsi
#LIBS     += -lsrb -lgdl -lsystem_utils -lsi
#LIBS     += -lismd_audio -lismd_bufmon -lismd_videnc -lismd_mux -lismd_demux_v3 -lismd_viddec -lismd_vidpproc -lismd_vidrend -lismd_clock_recovery -lsven -losal -lpal -lplatform_config -lismdmessage -lcommon_debug -lismd_core

LIBDIRS  += -L/usr/lib/intelce -L$(VDRDIR)/libsi 

all: $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(DEFINES) $(INCLUDES) $<


$(TARGET): $(OBJS) Makefile
	$(CXX) $(LDFLAGS) $(OBJS) $(LIBDIRS) $(LIBS) -o $@

clean:
	-rm -f *.o *~ $(TARGET)

install: all
	cp $(TARGET) /media/intel/usr/sbin/

