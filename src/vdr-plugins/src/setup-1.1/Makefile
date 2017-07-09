#
# Makefile for a Video Disk Recorder plugin
#
# $Id: Makefile,v 1.11 2005/10/03 14:05:20 ralf Exp $

# The official name of this plugin.
# This name will be used in the '-P...' option of VDR to load the plugin.
# By default the main source file also carries this name.
#
PLUGIN = setup

### set defines
#DEFINES = -DDVBAPIVERSION=0x0500
#DEFINES = -DDVBAPIVERSION=1280
#DEFINES = -DSYS_DAB=0

### The object files (add further files here):
OBJS = $(PLUGIN).o blockdevice.o config.o energyoptionsmenu.o formatmenu.o i18n.o \
	mainmenu.o meminfo.o menus.o menueditrefreshitems.o menusysteminfo.o \
	netinfo.o networkfilesystem.o plugins.o setupmenu.o setupmultiroom.o \
	setupnetclientmenu.o setupnetworkfilesystemmenu.o setuprecordingdevicemenu.o \
	setupsetup.o setupwlanmenu.o resetsettingsmenu.o  systeminfo.o \
	util.o wlansetting.o
OBJS += menusetup_vdr.o
#OBJS += tinystr.o tinyxml.o tinyxmlerror.o tinyxmlparser.o
#OBJS += tinystr.o tinyxml.o

### The directory environment:

VDRDIR = ../../..
LIBDIR = ../../lib
TMPDIR = /tmp

### Allow user defined options to overwrite defaults:

-include $(VDRDIR)/Make.config

### The name of the distribution archive:

ARCHIVE = $(PLUGIN)-$(VERSION)
PACKAGE = vdr-$(ARCHIVE)

### Includes and Defines (add further entries here):

ifdef USEMYSQL
  OBJS += setupmysqlmenu.o
endif

#INCLUDES += -I$(VDRDIR)
INCLUDES += -I../../$(DVBDIR)/include

DEFINES += -D__STL_CONFIG_H 

ifdef DEBUG
  DEFINES += -DDEBUG_SETUP -DDEBUG
endif

LIBS += -lavahi-client
#LIBS += -L/usr/lib/i386-linux-gnu/libtinyxml.a
LIBS += -L$(VDRDIR)/tinyxml/libtinyxml.a

CXXFLAGS += -fno-strict-aliasing
##CXXFLAGS +=  -Wl,--no-undefined

#BDATE=$(shell date +%Y-%m-%d)
#DEFINES += -DBUILD="\"$(BUILD)\"" -DBDATE="\"$(BDATE)\""



### Allow user defined options to overwrite defaults:
include $(VDRDIR)/Make.common


### Implicit rules:

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(DEFINES) -DPLUGIN_NAME_I18N='"$(PLUGIN)"' $(INCLUDES) $<


### Aditional rules

$(I18Npot): $(wildcard *.cpp)

$(DEPFILE): vdrsetupclasses.h Makefile
	@$(MAKEDEP) $(DEFINES) $(INCLUDES) $(OBJS:%.o=%.cpp)   > $@

libvdr-$(PLUGIN).so: vdrsetupclasses.h

vdrsetupclasses.h:  $(VDRDIR)/menu.c
	@echo "Extracting class definitions from VDR's menu.c for standard Setup"
	@./getVdrSetupMenu.pl $(VDRDIR)/menu.c

clean: clean-setup

clean-setup:
	@-rm -f vdrsetupclasses.h

useless-target-for-compatibility-with-vanilla-vdr:
	$(LIBDIR)/$@.$(APIVERSION)

