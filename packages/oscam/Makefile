#
# Makefile for ReelBox packages
#
#

PLUGIN = oscam

include ../Make.common

export SRCDIR
#SRCDIR = /usr/src/reelbox/testing/src
#SRCDIR = ../../src

# uncomment if you need conffiles, postinst etc. included

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
#$(TARGET): $(VROOT)/DEBIAN/preinst
$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/prerm
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

clean: target-clean

target-clean:
	$(MAKE) -C $(SRCDIR)/vdr-plugins/src/$(PLUGIN) clean

# the next two targets are a trick to clean the VROOT before building
$(VROOT)/DEBIAN/control: tmp

tmp: $(CONTROL)
	sudo rm -rf $@
	sudo rm -f .root-copied
	mkdir $@
	$(MAKE) -C $(SRCDIR)/vdr-plugins/src/$(PLUGIN)
	$(MAKE) OSCAM_BIN=oscam -C $(SRCDIR)/vdr-plugins/src/$(PLUGIN)

i18n:


comp:
	$(MAKE) -C $(SRCDIR)/vdr-plugins/src/$(PLUGIN)

# put any needed Makefile directives here
# add dependency for these targets to "all:"
# Example:
# all: myrule
# myrule:
#      do_something
