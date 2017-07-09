
MACHINE  ?= -m32 -march=pentium3 -mmmx -msse -mfpmath=sse

CC       ?= $(CCACHE) $(DISTCC) $(CROSS)gcc
CFLAGS    = -O2 -g -Wall $(MACHINE) #-pg

CXX      ?= g++
CXXFLAGS ?= -g -O3 -Wall -Woverloaded-virtual -Wno-parentheses


OBJS := gstmpegdesc.o gstsectionfilter.o ismd_gst_audio_dec.o ismd_gst_audio_sink.o \
	ismd_gst_buffer.o ismd_gst_clock.o ismd_gst_clock_recovery_provider.o ismd_gst_demux.o \
	ismd_gst_dvb_src.o ismd_gst_dvb_stream.o ismd_gst_element.o ismd_gst_enum.o ismd_gst_h264_viddec.o \
	ismd_gst_h264_videnc.o ismd_gst_mpeg2_viddec.o ismd_gst_mpeg4_viddec.o ismd_gst_pad.o ismd_gst_rectangle.o \
	ismd_gst_refiller.o ismd_gst_ts_muxer.o ismd_gst_vc1_viddec.o ismd_gst_vidpproc.o ismd_gst_vidrend_bin.o \
	ismd_gst_vidrend_sink.o ismd_gst_vidsink.o ismd_plugin.o psi_helper.o

INCLUDES += -I/usr/include/libxml2  -I/usr/include/glib-2.0  -I/usr/lib/glib-2.0/include
INCLUDES += -I/usr/include/gstreamer-0.10  -I/usr/include/intelce  -I/usr/include/intelce/linux_user
LDFLAGS  += -shared
#LIBS     += -lpthread -ldl -lxml2 -lglib-2.0 -lgstreamer-0.10 -lgstbase-0.10 -lgstvideo-0.10
LIBS     += -ldl -lxml2 -lglib-2.0 -lgstbase-0.10 \
            -lismd_audio -lismd_bufmon -lismd_clock -lismd_clock_recovery \
            -lismd_core -lismd_demux -lismdmessage \
            -lismd_viddec -lismd_videnc -lismd_vidpproc -lismd_vidrend -lismd_vidsink_direct -lismd_mux \
            -lplatform_config -lpq_library -lsystem_utils -lgdl -lsven -lpal -lgstaudio-0.10 
LIBDIRS  += -L/usr/lib/intelce

all: libgstfluismd.so

%.o: %.c
	$(CC) $(CFLAGS) -c $(DEFINES) $(INCLUDES) $<


libgstfluismd.so: $(OBJS) Makefile
	$(CC) $(LDFLAGS) $(OBJS) $(LIBDIRS) $(LIBS) -o $@

clean:
	-rm -f *.o *~ libgstfluismd.so
