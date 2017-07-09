#
# Softcam plugin to VDR
#
# This code is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This code is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
# Or, point your browser to http://www.gnu.org/copyleft/gpl.html

# The official name of this plugin.
# This name will be used in the '-P...' option of VDR to load the plugin.
# By default the main source file also carries this name.
#
PLUGIN = sc
export MCLISC=1

### The version number of this plugin

DISTFILE = .distvers
HGARCHIVE = .hg_archival.txt
RELEASE := $(shell grep 'define SC_RELEASE' version.h | awk '{ print $$3 }' | sed -e 's/[";]//g')
SUBREL  := $(shell if test -d .hg; then \
                     echo -n "HG-"; (hg identify 2>/dev/null || echo -n "Unknown") | sed -e 's/ .*//'; \
                   elif test -r $(HGARCHIVE); then \
                     echo -n "AR-"; grep "^node" $(HGARCHIVE) | awk '{ printf "%.12s",$$2 }'; \
                   elif test -r $(DISTFILE); then \
                     cat $(DISTFILE); \
                   else \
                     echo -n "Unknown"; \
                   fi)
VERSION := $(RELEASE)-$(SUBREL)
SCAPIVERS := $(shell sed -ne '/define SCAPIVERS/ s/^.[a-zA-Z ]*\([0-9]*\).*$$/\1/p' version.h)

### The version number of VDR (taken from VDR's "config.h"):

VDRVERSION := $(shell sed -ne '/define VDRVERSION/ s/^.*"\(.*\)".*$$/\1/p' $(VDRDIR)/include/vdr/config.h)
APIVERSION := $(shell sed -ne '/define APIVERSION/ s/^.*"\(.*\)".*$$/\1/p' $(VDRDIR)/include/vdr/config.h)
ifeq ($(strip $(APIVERSION)),)
   APIVERSION = $(VDRVERSION)
endif
VDRVERSNUM := $(shell sed -ne '/define VDRVERSNUM/ s/^.[a-zA-Z ]*\([0-9]*\) .*$$/\1/p' $(VDRDIR)/include/vdr/config.h)
APIVERSNUM := $(shell sed -ne '/define APIVERSNUM/ s/^.[a-zA-Z ]*\([0-9]*\) .*$$/\1/p' $(VDRDIR)/include/vdr/config.h)
ifeq ($(strip $(APIVERSNUM)),)
   APIVERSNUM = $(VDRVERSNUM)
endif
export APIVERSNUM
export VDRVERSNUM
export APIVERSION
export VDRVERSION

## #The directory environment:

VDRDIR = /usr/src/reelbox/testing/src/vdr-1.7.28
LIBDIR = ./lib
SYSDIR = ./systems
PREDIR = ./systems-pre
TMPDIR = /tmp

### The C++ compiler and options:

CXX      ?= g++
#CXXFLAGS ?= -O2 -g -Wall -Woverloaded-virtual
#CXXFLAGS ?= -g -O2 -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -DDVBAPI_V5 -DNEW_FFMPEG -DNEWUBUNTU -DREELVDR -DUSEMYSQL -DDEVICE_ATTRIBUTES -DUSE_CRASHLOG -DUSE_CUTTERLIMIT -DUSE_CUTTIME -DUSE_JUMPPLAY -DUSE_LIEMIEXT -DUSE_MCLI -DUSE_NOEPG -DUSE_PINPLUGIN -DUSE_PLUGINMISSING -DUSE_SETUP -DUSE_TTXTSUBS -DUSE_YAEPG -DUSE_BOUQUETS -DUSE_DELAYED_TRICKMODE -DUSE_LIVEBUFFER -DUSE_PROVIDERCHARSET=1 -DREMOTE_KBD -DREMOTE_LIRC # doesn't work!
#CXXFLAGS ?= -fPIC -pg -O2 -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -DDVBAPI_V5 -DNEW_FFMPEG -DNEWUBUNTU -DREELVDR -DUSEMYSQL -DDEVICE_ATTRIBUTES -DUSE_CRASHLOG -DUSE_CUTTERLIMIT -DUSE_CUTTIME -DUSE_JUMPPLAY -DUSE_LIEMIEXT -DUSE_MCLI -DUSE_NOEPG -DUSE_PINPLUGIN -DUSE_PLUGINMISSING -DUSE_SETUP -DUSE_TTXTSUBS -DUSE_YAEPG -DUSE_BOUQUETS -DUSE_DELAYED_TRICKMODE -DUSE_LIVEBUFFER -DUSE_PROVIDERCHARSET=1 -DREMOTE_KBD -DREMOTE_LIRC 
#CXXFLAGS ?= -fPIC -pg -O2 -Wall -Woverloaded-virtual -Wno-parentheses # this doen't work! 
#CCXXFLAGS = -O3 -march=pentium3 -fexpensive-optimizations -funroll-loops -march=pentium3 -mmmx -msse -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE
CCXXFLAGS = -O2 -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -fno-strict-aliasing  -shared -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE
#CCXXFLAGS ?= -g -O2 -fPIC -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE
#CCXXFLAGS ?= -fPIC -pg -O2 -Wall -Woverloaded-virtual -Wno-parentheses -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse
#CCXXFLAGS ?=         -O2 -Wall -Woverloaded-virtual -Wno-parentheses                                     -m32 -march=pentium3 -mmmx -msse -mfpmath=sse
#CXXFLAGS ?= -O2 -g -Wall -Woverloaded-virtual

### Includes and Defines

INCLUDES      = -I$(VDRDIR)/include
DEFINES       = -DPLUGIN_NAME_I18N='"$(PLUGIN)"' -DVDR_IS_SC_PATCHED=402 -DREEL_AVANTGARDE
SHAREDDEFINES = -DAPIVERSNUM=$(APIVERSNUM) -D_GNU_SOURCE
LIBS          = -lcrypto
LIBS          = -lpthread -lrt -ljpeg -lcrypto
SHAREDLIBS    =

### Allow user defined options to overwrite defaults:

-include $(VDRDIR)/Make.global
-include $(VDRDIR)/Make.config
-include $(VDRDIR)/Make.common
#-include Make.config

# we need this ATM because of the helper.h macros...
CXXFLAGS += -fno-strict-aliasing 
### The object files (add further files here):

OBJS = $(PLUGIN).o data.o filter.o system.o misc.o cam.o version.o \
       smartcard.o network.o crypto.o system-common.o parse.o log.o \
       override.o
OBJS -= mcli_sc.o
### Internationalization (I18N):

PODIR     = po
I18Npot   = $(PODIR)/$(PLUGIN).pot
ifeq ($(strip $(APIVERSION)),1.5.7)
  I18Nmo  = $(PLUGIN).mo
else
  I18Nmo  = vdr-$(PLUGIN).mo
endif

I18Nmsgs  = $(addprefix $(LOCALEDIR)/,$(addsuffix /LC_MESSAGES/$(I18Nmo),$(notdir $(foreach file, $(wildcard $(PODIR)/*.po), $(basename $(file))))))
LOCALEDIR = $(VDRDIR)/locale
HASLOCALE = $(shell grep -l 'I18N_DEFAULT_LOCALE' $(VDRDIR)/include/vdr/i18n.h)

ifeq ($(strip $(HASLOCALE)),)
  OBJS += i18n.o
endif

### VDR version dependant

# test VDR version
BYVERS = $(strip $(shell if test $(APIVERSNUM) -ge 010703; then echo "*"; fi))
# test if PlayTsVideo() exists (e.g. TSplay patch)
BYTSPL = $(strip $(shell grep -l 'PlayTsVideo' $(VDRDIR)/include/vdr/device.h))

ifneq ($(BYVERS)$(BYTSPL),)
  SHAREDDEFINES += -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE
endif
  SHAREDDEFINES += -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE

#
# generic stuff
#

# smartcard default port (dropped)
ifdef DEFAULT_PORT
  $(error DEFAULT_PORT support was removed, use cardslot.conf)
endif

ifdef WITH_PCSC
  DEFINES  += -DWITH_PCSC
  LIBS     += -lpcsclite
endif

# max number of CAIDs per slot
#MAXCAID := $(shell sed -ne '/define MAXCASYSTEMIDS/ s/^.[a-zA-Z ]*\([0-9]*\).*$$/\1/p' $(VDRDIR)/ci.c)
MAXCAID := 256
ifneq ($(strip $(MAXCAID)),)
  DEFINES += -DVDR_MAXCAID=$(MAXCAID)
endif

# FFdeCSA
### VDR-SC Makefile FFdeCSA OPTS ###
#CPUOPT     ?= native
CPUOPT        = pentium3 
#PARALLEL_MODE = 1
#export PARALLEL_MODE
#PARALLEL   ?= PARALLEL_128_2MMX
#PARALLEL   ?= PARALLEL_64_MMX
PARALLEL   ?= PARALLEL_128_SSE
#PARALLEL   ?= PARALLEL_32_INT
#CSAFLAGS   = -g -O2 -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -DDVBAPI_V5 -DNEW_FFMPEG -DNEWUBUNTU -DREELVDR -DUSEMYSQL -DDEVICE_ATTRIBUTES -DUSE_CRASHLOG -DUSE_CUTTERLIMIT -DUSE_CUTTIME -DUSE_JUMPPLAY -DUSE_LIEMIEXT -DUSE_MCLI -DUSE_NOEPG -DUSE_PINPLUGIN -DUSE_PLUGINMISSING -DUSE_SETUP -DUSE_TTXTSUBS -DUSE_YAEPG -DUSE_BOUQUETS -DUSE_DELAYED_TRICKMODE -DUSE_LIVEBUFFER -DUSE_PROVIDERCHARSET=1 -DREMOTE_KBD -DREMOTE_LIRC 
CSAFLAGS ?= -fPIC -pg -O2 -Wall -Woverloaded-virtual -Wno-parentheses
#CSAFLAGS ?= -fPIC -pg -O2 -Wall -Woverloaded-virtual -Wno-parentheses -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse
#CSAFLAGS ?= -fPIC -O2 -Wall -Woverloaded-virtual -Wno-parentheses -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse
#CSAFLAGS =     -O2 -Wall -Woverloaded-virtual -Wno-parentheses                                     -m32 -march=pentium3 -mmmx -msse -mfpmath=sse
#CSAFLAGS   ?= -O2 -fexpensive-optimizations -fomit-frame-pointer -funroll-loops

### GENERIC FFdeCSA make OPTS ###
#FLAGS="-O2 -march=native -fexpensive-optimizations -fomit-frame-pointer -funroll-loops" PARALLEL_MODE=PARALLEL_128_SSE
#FLAGS="-O2 -march=native -fexpensive-optimizations -fomit-frame-pointer -funroll-loops" PARALLEL_MODE=PARALLEL_32_INT
#FLAGS= -g -O2 -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -DDVBAPI_V5 -DNEW_FFMPEG -DNEWUBUNTU -DREELVDR -DUSEMYSQL -DDEVICE_ATTRIBUTES -DUSE_CRASHLOG -DUSE_CUTTERLIMIT -DUSE_CUTTIME -DUSE_JUMPPLAY -DUSE_LIEMIEXT -DUSE_MCLI -DUSE_NOEPG -DUSE_PINPLUGIN -DUSE_PLUGINMISSING -DUSE_SETUP -DUSE_TTXTSUBS -DUSE_YAEPG -DUSE_BOUQUETS -DUSE_DELAYED_TRICKMODE -DUSE_LIVEBUFFER -DUSE_PROVIDERCHARSET=1 -DREMOTE_KBD -DREMOTE_LIRC 
FLAGS ?= -fPIC -pg -O2 -Wall -Woverloaded-virtual -Wno-parentheses
#FLAGS="-O2 -march=pentium3                                                        " PARALLEL_MODE=PARALLEL_128_SSE
#FLAGS="-O2 -march=native -fexpensive-optimizations -fomit-frame-pointer -funroll-loops" PARALLEL_MODE=PARALLEL_128_SSE
FFDECSADIR  = FFdecsa
FFDECSA     = $(FFDECSADIR)/FFdecsa.o
FFDECSATEST = $(FFDECSADIR)/FFdecsa_test.done

ifdef MCLISC
  MCLI_SHARED=1
  MCLISC_DIR=$(VDRDIR)/../vdr-plugins/src/mcli
  ifdef RBMINI
    FFDECSA =
    INCLUDES += -I/usr/arm-linux-gnueabi/include
  endif
  DEFINES  += -DMCLISC
  INCLUDES += -I $(MCLISC_DIR)
# XML_INC := $(shell xml2-config --cflags)
# XML_LIB := $(shell xml2-config --libs)
  XML_INC := `xml2-config --cflags`
  XML_LIB := `xml2-config --libs`
  INCLUDES += $(XML_INC)
# ifdef MCLI_SHARED
#   LIBS     += -lmcli -L$(MCLISC_DIR)/mcast/client $(XML_LIB)
# else
# satellit HACK
  LIBS     -= ../vdr-mcli-188/libvdr-mcli.so.$(APIVERSION) $(XML_LIB)
  LIBS     -= /usr/lib/vdr/libvdr-mcli.so.$(APIVERSION) $(XML_LIB)
  LIBSi     = mcast/client/libmcli.a $(XML_LIB)
# LIBS     -= /usr/lib/vdr/libvdr-mcli.so.$(APIVERSION) $(XML_LIB)
# LIBS     += $(MCLISC_DIR)/mcast/client/libmcli.a $(XML_LIB)
# LIBS     -= $(MCLISC_DIR)/libvdr-mcli.so
# LIBS     -= /usr/lib/libvdr-mcli.so
  LIBS     += /usr/lib/libmcli.so
  LIBS     += /usr/lib/vdr/libvdr-mcli.so.$(APIVERSION)
#endif
endif


# SASC 
ifdef SASC
DEFINES += -DSASC
FFDECSA =
FFDECSATEST =
endif

# export for system makefiles
export SCAPIVERS
export APIVERSION
export INCLUDES
export SHAREDDEFINES
export SHAREDLIBS
export CXX
export CXXFLAGS
export CSAFLAGS
export FLAGS
export MCLISC
export LIBS

### Targets:

ifdef STATIC
BUILDTARGETS = $(LIBDIR)/libvdr-$(PLUGIN).a
SHAREDDEFINES += -DSTATICBUILD
else
BUILDTARGETS = $(LIBDIR)/libvdr-$(PLUGIN).so.$(APIVERSION) systems-pre
endif

ifdef RBMINI
BUILDTARGETS += systems
else
BUILDTARGETS += $(FFDECSATEST) systems
endif

ifneq ($(strip $(HASLOCALE)),)
BUILDTARGETS += i18n
endif

all: $(BUILDTARGETS)
.PHONY: i18n systems systems-pre contrib clean clean-core clean-systems clean-pre dist srcdist

# Dependencies:

MAKEDEP = g++ -MM -MG
DEPFILE = .dependencies
DEPFILES = $(subst i18n.c,,$(subst version.c,,$(OBJS:%.o=%.c)))
$(DEPFILE): $(DEPFILES) $(wildcard *.h)
	@$(MAKEDEP) $(DEFINES) $(SHAREDDEFINES) $(INCLUDES) $(DEPFILES) > $@

-include $(DEPFILE)

# Rules

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $(DEFINES) $(SHAREDDEFINES) $(INCLUDES) $<

ifdef RBMINI
libvdr-$(PLUGIN).so: $(OBJS)
	$(CXX) $(CXXFLAGS) -shared $(OBJS) $(LIBS) $(SHAREDLIBS) -o $@
else
libvdr-$(PLUGIN).so: $(OBJS) $(FFDECSA)
	$(CXX) $(CXXFLAGS) -shared $(OBJS) $(FFDECSA) $(LIBS) $(SHAREDLIBS) -o $@
endif
	cp $@ $(LIBDIR)/$@.$(APIVERSION)

$(LIBDIR)/libvdr-$(PLUGIN).so.$(APIVERSION): libvdr-$(PLUGIN).so
	@cp -p $< $@

$(LIBDIR)/libvdr-$(PLUGIN).a: $(OBJS)
	$(AR) r $@ $(OBJS)

$(FFDECSA) $(FFDECSATEST): $(FFDECSADIR)/*.c $(FFDECSADIR)/*.h
	@$(MAKE) COMPILER="$(CXX)" FLAGS="$(CSAFLAGS) -march=$(CPUOPT)" PARALLEL_MODE=$(PARALLEL) -C $(FFDECSADIR) all

$(I18Npot): $(shell grep -rl '\(tr\|trNOOP\)(\".*\")' *.c $(SYSDIR))
	xgettext -C -cTRANSLATORS --no-wrap --no-location -k -ktr -ktrNOOP --msgid-bugs-address='<noone@nowhere.org>' -o $@ `ls $^`

%.po: $(I18Npot)
	msgmerge -U --no-wrap --no-location --backup=none -q $@ $<
	@touch $@

%.mo: %.po
	msgfmt -c -o $@ $<

$(I18Nmsgs): $(LOCALEDIR)/%/LC_MESSAGES/$(I18Nmo): $(PODIR)/%.mo
	@mkdir -p $(dir $@)
	cp $< $@

i18n: $(I18Nmsgs)

i18n.c: $(PODIR)/*.po i18n-template.c po2i18n.pl
	perl ./po2i18n.pl <i18n-template.c >i18n.c

version.c: FORCE
	@echo >$@.new "/* generated file, do not edit */"; \
	 echo >>$@.new 'const char *ScVersion =' '"'$(VERSION)'";'; \
	 diff $@.new $@ >$@.diff 2>&1; \
	 if test -s $@.diff; then mv -f $@.new $@; fi; \
	 rm -f $@.new $@.diff;

systems:
	@for i in `ls -A -I ".*" $(SYSDIR)`; do $(MAKE) -f ../../Makefile.system -C "$(SYSDIR)/$$i" all || exit 1; done

systems-pre:
	@for i in `ls -A -I ".*" $(PREDIR) | grep -- '-$(SCAPIVERS).so.$(APIVERSION)$$'`; do cp -p "$(PREDIR)/$$i" "$(LIBDIR)"; done

contrib:
	@$(MAKE) -C contrib all

clean-systems:
	@for i in `ls -A -I ".*" $(SYSDIR)`; do $(MAKE) -f ../../Makefile.system -C "$(SYSDIR)/$$i" clean; done

clean-core:
	@-rm -f $(LIBDIR)/libsc-*-$(SCAPIVERS).so.$(APIVERSION)
	@-rm -f $(LIBDIR)/libvdr-$(PLUGIN).a $(LIBDIR)/libsc-*.a
	@-rm -f $(OBJS) $(DEPFILE) version.c i18n.c *.so *.tar.gz core* *~
	@-rm -f $(PODIR)/*.mo
	@$(MAKE) -C testing clean
	@$(MAKE) -C contrib clean
ifndef RBMINI
	@if test -d $(FFDECSADIR); then $(MAKE) -C $(FFDECSADIR) clean; fi
endif

clean-pre:
	@-find "$(PREDIR)" -type f -not -name ".empty" -not -iname "*-$(SCAPIVERS).so.*" | xargs rm -f

clean: clean-systems clean-core

dist: ARCHIVE := $(PLUGIN)-$(RELEASE)
dist: clean-core
	@for i in `ls -A -I ".*" $(SYSDIR)`; do $(MAKE) -f ../../Makefile.system -C "$(SYSDIR)/$$i" dist; done
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@mkdir $(TMPDIR)/$(ARCHIVE)
	@cp -a * $(TMPDIR)/$(ARCHIVE)
	@echo -n "release" >$(TMPDIR)/$(ARCHIVE)/$(DISTFILE)
	@path="$(TMPDIR)/$(ARCHIVE)/$(notdir $(SYSDIR))";\
	 for i in `ls -A -I ".*" $$path`; do if [ -f "$$path/$$i/nonpublic.mk" ]; then rm -rf "$$path/$$i"; fi; if [ -f "$$path/$$i/nonpublic.sh" ]; then (cd $$path/$$i ; source ./nonpublic.sh ; rm ./nonpublic.sh); fi; done
	@strip --strip-unneeded --preserve-dates $(TMPDIR)/$(ARCHIVE)/$(notdir $(PREDIR))/* || true
	@tar czf vdr-$(ARCHIVE).tar.gz -C $(TMPDIR) $(ARCHIVE)
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@echo Distribution package created as vdr-$(ARCHIVE).tar.gz

copy: ARCHIVE := $(PLUGIN)-$(VERSION)
copy: clean clean-pre
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@mkdir $(TMPDIR)/$(ARCHIVE)
	@cp -a .hgtags .hgignore * $(TMPDIR)/$(ARCHIVE)
	@echo -n $(SUBREL) | sed -e 's/HG-/CP-/' >$(TMPDIR)/$(ARCHIVE)/$(DISTFILE)
	@tar czf vdr-$(ARCHIVE).tar.gz -C $(TMPDIR) $(ARCHIVE)
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@echo Full copy package created as vdr-$(ARCHIVE).tar.gz

FORCE:
