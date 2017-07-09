#
# Makefile for a Video Disk Recorder plugin
#
# $Id$

# The official name of this plugin.
# This name will be used in the '-P...' option of VDR to load the plugin.
# By default the main source file also carries this name.
#
PLUGIN = yacoto

### The version number of this plugin (taken from the main source file):
VERSION = $(shell grep 'static const char \*VERSION *=' $(PLUGIN).c | awk '{ print $$6 }' | sed -e 's/[";]//g')

### The C++ compiler and options:
CXX      ?= g++
CXXFLAGS ?= -fPIC -g -O2 -Wall -Woverloaded-virtual

### The directory environment:
VDRDIR = ../../..
LIBDIR = ../../lib
TMPDIR = /tmp

### The directory containing the conf files
YAC_CONF_DIR ?= /etc/vdr/plugins/$(PLUGIN)

### The directory containing the script files
YAC_DIR ?= $(YAC_CONF_DIR)

### Allow user defined options to overwrite defaults:
-include $(VDRDIR)/Make.config
-include $(VDRDIR)/Make.common

### Test whether VDR has locale support
VDRLOCALE = $(shell grep 'I18N_DEFAULT_LOCALE' $(VDRDIR)/i18n.h)

### The version number of VDR's plugin API (taken from VDR's "config.h"):
APIVERSION = $(shell sed -ne '/define APIVERSION/s/^.*"\(.*\)".*$$/\1/p' $(VDRDIR)/config.h)

### The name of the distribution archive:
ARCHIVE = $(PLUGIN)-$(VERSION)
PACKAGE = vdr-$(ARCHIVE)

### Includes and Defines (add further entries here):
INCLUDES += -I$(VDRDIR)/include
DEFINES += -D_GNU_SOURCE -DPLUGIN_NAME_I18N='"$(PLUGIN)"' -DYAC_DIR='"$(YAC_DIR)"'

### The object files (add further files here):
OBJS = $(PLUGIN).o yac-menurecordings.o yac-menurecinfo.o yac-menuconvert.o yac-recordings.o yac-tools.o yac-setup.o

ifeq ($(strip $(VDRLOCALE)),)
OBJS += i18n.o
endif

### Implicit rules:
%.o: %.c
	$(CXX) $(CXXFLAGS) -c $(DEFINES) $(INCLUDES) $<

# Dependencies:
MAKEDEP = $(CXX) -MM -MG
DEPFILE = .dependencies

$(DEPFILE): Makefile i18n.c
	@$(MAKEDEP) $(DEFINES) $(INCLUDES) $(subst i18n.c,,$(OBJS:%.o=%.c)) > $@

-include $(DEPFILE)

### Internationalization (I18N):
PODIR     = po
LOCALEDIR = $(VDRDIR)/locale
I18Npo    = $(wildcard $(PODIR)/*.po)
I18Nmsgs  = $(addprefix $(LOCALEDIR)/, $(addsuffix /LC_MESSAGES/vdr-$(PLUGIN).mo, $(notdir $(foreach file, $(I18Npo), $(basename $(file))))))
I18Npot   = $(PODIR)/$(PLUGIN).pot

ifeq ($(strip $(APIVERSION)),1.5.7)
  I18Nmsgs  = $(addprefix $(LOCALEDIR)/, $(addsuffix /LC_MESSAGES/$(PLUGIN).mo, $(notdir $(foreach file, $(I18Npo), $(basename $(file))))))
endif

ifneq ($(strip $(VDRLOCALE)),)
### do gettext based i18n stuff
%.mo: %.po
	msgfmt -c -o $@ $<

$(I18Npot): $(subst i18n.c,,$(wildcard *.c))
	xgettext -C -cTRANSLATORS --no-wrap --no-location -k -ktr -ktrNOOP --msgid-bugs-address='<helmut@helmutauer.de>' -o $@ $(subst i18n.c,,$(wildcard *.c))
	./addConfToPot.sh $(YAC_CONF_DIR) $@

%.po: $(I18Npot)
	msgmerge -U -N --previous --no-wrap --no-location --backup=none -q $@ $<
	@touch $@

$(I18Nmsgs): $(LOCALEDIR)/%/LC_MESSAGES/vdr-$(PLUGIN).mo: $(PODIR)/%.mo
	@mkdir -p $(dir $@)
	cp -v $< $@

.PHONY: i18n
i18n: $(I18Nmsgs)

i18n.c: i18n-template.c
	@cp i18n-template.c i18n.c

else ### do i18n.c based i18n stuff

i18n:
	@### nothing to do

#i18n compatibility generator:
i18n.c: i18n-template.c po2i18n.pl $(I18Npo)
	./po2i18n.pl < i18n-template.c > i18n.c

endif

### Targets:
all: libvdr-$(PLUGIN).so i18n

libvdr-$(PLUGIN).so: $(OBJS)
	$(CXX) $(CXXFLAGS) -shared $(OBJS) -o $@
	@cp $@ $(LIBDIR)/$@.$(APIVERSION)

dist: clean
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@mkdir $(TMPDIR)/$(ARCHIVE)
	@cp -a * $(TMPDIR)/$(ARCHIVE)
	@tar czvf $(PACKAGE).tgz -C $(TMPDIR) $(ARCHIVE)
	@-rm -rf $(TMPDIR)/$(ARCHIVE) i18n.c
	@echo Distribution package created as $(PACKAGE).tgz :
	@tar tzvf $(PACKAGE).tgz

clean:
	@-rm -f $(OBJS) $(DEPFILE) *.so *.tgz core* *~ $(PODIR)/*.mo $(PODIR)/*.pot 
	@-rm -f $(OBJS) $(DEPFILE) *.so *.tgz core* *~ .dep*
