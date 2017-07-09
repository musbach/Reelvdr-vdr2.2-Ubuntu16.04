#
# Makefile for a Video Disk Recorder plugin
#
# $Id$

# The official name of this plugin.
# This name will be used in the '-P...' option of VDR to load the plugin.
# By default the main source file also carries this name.
#
PLUGIN = graphlcd

# define this if you built graphlcd-base with freetype:
#HAVE_FREETYPE2 = 1
HAVE_FREETYPE2 = 0

### The version number of this plugin (taken from the main source file):

VERSION = $(shell grep 'static const char \*VERSION *=' plugin.c | awk '{ print $$6 }' | sed -e 's/[";]//g')

### The directory environment:

VDRDIR = ../../..
LIBDIR = ../../lib
TMPDIR = /tmp
-include $(VDRDIR)/Make.config
-include $(VDRDIR)/Make.common

### The C++ compiler and options:

CXX      ?= g++
#CXXFLAGS ?= -g -O2 -Wall -Woverloaded-virtual -Wno-parentheses 
CXXFLAGS += -g -O2 -Wall -Woverloaded-virtual -Wno-parentheses -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -DDVBAPI_V5 -DNEW_FFMPEG -DNEWUBUNTU -DREELVDR -DUSEMYSQL -DDEVICE_ATTRIBUTES -DUSE_CRASHLOG -DUSE_CUTTERLIMIT -DUSE_CUTTIME -DUSE_JUMPPLAY -DUSE_LIEMIEXT -DUSE_MCLI -DUSE_NOEPG -DUSE_PINPLUGIN -DUSE_PLUGINMISSING -DUSE_SETUP -DUSE_TTXTSUBS -DUSE_YAEPG -DUSE_BOUQUETS -DUSE_DELAYED_TRICKMODE -DUSE_LIVEBUFFER -DUSE_PROVIDERCHARSET=1 -DREMOTE_KBD -DFP_DEVICE=\"/dev/frontpanel\" -fomit-frame-pointer -fPIC -m32 -march=pentium3 -mfpmath=sse -mmmx -msse

##CXXFLAGS += -g -O2 -Wall -Woverloaded-virtual -Wno-parentheses funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -DDVBAPI_V5 -DNEW_FFMPEG -DNEWUBUNTU -DREELVDR -DUSEMYSQL -DDEVICE_ATTRIBUTES -DUSE_CRASHLOG -DUSE_CUTTERLIMIT -DUSE_CUTTIME -DUSE_JUMPPLAY -DUSE_LIEMIEXT -DUSE_MCLI -DUSE_NOEPG -DUSE_PINPLUGIN -DUSE_PLUGINMISSING -DUSE_SETUP -DUSE_TTXTSUBS -DUSE_YAEPG -DUSE_BOUQUETS -DUSE_DELAYED_TRICKMODE -DUSE_LIVEBUFFER -DUSE_PROVIDERCHARSET=1 -DREMOTE_KBD


CXXFLAGS = -g -O2 -Wall -Woverloaded-virtual -Wno-parentheses 
CXXFLAGS = -g -O2 -Wall -Woverloaded-virtual -Wno-parentheses -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse 

export INSTALLPREFIX = /usr
export INSTALLDOCDIR = $(INSTALLPREFIX)/share/doc

### Make sure that necessary options are included:

-include $(VDRDIR)/Make.global

### Allow user defined options to overwrite defaults:

#-include $(VDRDIR)/Make.config
#-include $(VDRDIR)/Make.common
#include $(VDRDIR)/Make.common

### The version number of VDR (taken from VDR's "config.h"):

VDRVERSION = $(shell grep 'define VDRVERSION ' $(VDRDIR)/config.h | awk '{ print $$3 }' | sed -e 's/"//g')
VDRVERSNUM = 20106
APIVERSION = $(shell grep 'define APIVERSION ' $(VDRDIR)/config.h | awk '{ print $$3 }' | sed -e 's/"//g')
ifeq ($(strip $(APIVERSION)),)
  APIVERSION = $(VDRVERSION)
endif


### The name of the distribution archive:

ARCHIVE = $(PLUGIN)-$(VERSION)
PACKAGE = vdr-$(ARCHIVE)


### Includes and Defines (add further entries here):

INCLUDES += -lusb -I./graphlcd-base/ -I$(VDRDIR)/include -I$(INSTALLPREFIX)/include -I$(INSTALLPREFIX)/lib -I/usr/lib/i386-linux-gnu/libusb-0.1.so.4
#INCLUDES += -I./graphlcd-base/ -I$(VDRDIR)/include -I$(INSTALLPREFIX)/include -I$(INSTALLPREFIX)/lib

DEFINES += -D_GNU_SOURCE -DPLUGIN_NAME_I18N='"$(PLUGIN)"'

ifdef HAVE_FREETYPE2
    INCLUDES += -I$(INSTALLPREFIX)/include/freetype2
    DEFINES += -DHAVE_FREETYPE2
endif

### The object files (add further files here):

OBJS = avrctl.o driver.o glcd.o i18n.o logolist.o setup.o widgets.o bitmap.o drivers.o gu126x64D-K610A4.o image_dri.o image_gra.o menu.o port.o simlcd.o common_dri.o font.o gu140x32f.o imagefile.o network.o reel_usbfp.o st7565_reel.o config.o framebuffer.o gu256x64-372.o ks0108.o noritake800.o sed1330.o state.o display.o gu256x64-3900.o layout.o pbm.o sed1520.o strfct.o dm140gink.o g15daemon.o hd61830.o logo.o plugin.o serdisp.o t6963c.o
###OBJS = avrctl.o driver.o glcd.o i18n.o logolist.o setup.o widgets.o bitmap.o drivers.o gu126x64D-K610A4.o image_dri.o image_gra.o menu.o port.o simlcd.o common_dri.o common_gra.o font.o gu140x32f.o imagefile.o network.o reel_usbfp.o st7565_reel.o config.o framebuffer.o gu256x64-372.o ks0108.o noritake800.o sed1330.o state.o display.o futabaMDM166A.o gu256x64-3900.o layout.o pbm.o sed1520.o strfct.o dm140gink.o g15daemon.o hd61830.o logo.o plugin.o serdisp.o t6963c.o
###OBJS = display.o layout.o logo.o logolist.o menu.o plugin.o setup.o state.o strfct.o widgets.o bitmap.o common.o font.o glcd.o imagefile.o image.o pbm.o

### The main target:
TARGETS = libvdr-$(PLUGIN).so
ifneq ($(shell grep -l 'Phrases' $(VDRDIR)/i18n.c),$(VDRDIR)/i18n.c)
TARGETS += i18n
endif


all: $(TARGETS)

### Implicit rules:

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $(DEFINES) $(INCLUDES) $<


# Dependencies:

MAKEDEP = g++ -MM -MG
DEPFILE = .dependencies
$(DEPFILE): Makefile
	@$(MAKEDEP) $(DEFINES) $(INCLUDES) $(OBJS:%.o=%.c) > $@

-include $(DEPFILE)


### Internationalization (I18N):

PODIR     = po
LOCALEDIR = $(VDRDIR)/locale
I18Npo    = $(wildcard $(PODIR)/*.po)
I18Nmo    = $(addsuffix .mo, $(foreach file, $(I18Npo), $(basename $(file))))
I18Ndirs  = $(notdir $(foreach file, $(I18Npo), $(basename $(file))))
I18Npot   = $(PODIR)/$(PLUGIN).pot


%.mo: %.po
	msgfmt -c -o $@ $<

$(I18Npot): $(wildcard *.c)
	xgettext -C -cTRANSLATORS --no-wrap --no-location -k -ktr -ktrNOOP --msgid-bugs-address='<nobody@domain.com>' -o $@ $^

$(I18Npo): $(I18Npot)
	msgmerge -U --no-wrap --no-location --backup=none -q $@ $<
	@touch $@

i18n: $(I18Nmo)
	@mkdir -p $(LOCALEDIR)
	for i in $(I18Ndirs); do\
	    mkdir -p $(LOCALEDIR)/$$i/LC_MESSAGES;\
	    cp $(PODIR)/$$i.mo $(LOCALEDIR)/$$i/LC_MESSAGES/vdr-$(PLUGIN).mo;\
	    done

### Targets:
all:
libvdr-$(PLUGIN).so: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -shared $(OBJS) -lstdc++ -o $@
	@cp $@ $(LIBDIR)/$@.$(APIVERSION)

#	$(CXX) $(CXXFLAGS) $(INCLUDES) -L$(INSTALLPREFIX)/lib -L./graphlcd-base/glcddrivers/ -L./graphlcd-base/glcdgraphics/ -shared $(OBJS) -L./graphlcd-base/glcddrivers/libglcddrivers.so  -L./graphlcd-base/glcdgraphics/libglcdgraphics.so -lstdc++ -o $@
#	$(CXX) $(CXXFLAGS) -L$(INSTALLPREFIX)/lib -L./graphlcd-base/glcddrivers/ -L./graphlcd-base/glcdgraphics/ -shared $(OBJS) -L/usr/lib/libglcddrivers.so  -L/usr/lib/libglcdgraphics.so -lstdc++ -o $@
#	$(CXX) $(CXXFLAGS) -L$(INSTALLPREFIX)/lib -L./graphlcd-base/glcddrivers/ -L./graphlcd-base/glcdgraphics/ -shared $(OBJS) -L./graphlcd-base/glcddrivers/libglcddrivers.so  -L./graphlcd-base/glcdgraphics/libglcdgraphics.so -lstdc++ -o $@
#	$(CXX) $(CXXFLAGS) -L$(INSTALLPREFIX)/lib -L./graphlcd-base/glcddrivers/ -L./graphlcd-base/glcdgraphics/ -shared $(OBJS) -lglcddrivers -lglcdgraphics -lstdc++ -o $@
#	$(CXX) $(CXXFLAGS) -L$(INSTALLPREFIX)/lib -L./graphlcd-base/glcddrivers/ -L./graphlcd-base/glcdgraphics/ -shared $(OBJS) -L/usr/lib/libglcddrivers.so  -L/usr/lib/libglcdgraphics.so -lstdc++ -o $@

dist: clean
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@mkdir $(TMPDIR)/$(ARCHIVE)
	@cp -a * $(TMPDIR)/$(ARCHIVE)
	@tar czf $(PACKAGE).tgz --exclude .svn --exclude .git --exclude *.cbp --exclude *.layout -C $(TMPDIR) $(ARCHIVE)
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@echo Distribution package created as $(PACKAGE).tgz

clean:
	@-rm -f $(PODIR)/*.mo $(PODIR)/*.pot
	@-rm -f *.o $(DEPFILE) *.so *.tgz core* *~

install: all
	@install -d $(INSTALLDOCDIR)/$(PLUGIN)
	@install -m 644 README $(INSTALLDOCDIR)/$(PLUGIN)

uninstall:
	@rm -rf $(INSTALLDOCDIR)/$(PLUGIN)
