#
# Makefile for ReelBox packages
#
#

PLUGIN = reelice
VERSION = 1.0
LIBDIR  = $(PWD)/lib
#PATCHES = dummydevice-reel.diff

include ../Make.common

export SRCDIR
export MAINSRC

# uncomment if you need conffiles, postinst etc. included

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
#$(TARGET): $(VROOT)/DEBIAN/preinst
#$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/prerm
#$(TARGET): $(VROOT)/DEBIAN/postrm

src = $(PLUGIN)-$(VERSION)
src = $(SRCDIR)/vdr-plugins/src/$(PLUGIN)

all: $(TARGET)

clean: target-clean

# the next two targets are a trick to clean the VROOT before building
$(VROOT)/DEBIAN/control: tmp

tmp: $(CONTROL)
	$(MAKE) -C $(SRCDIR)/vdr-plugins/src/$(PLUGIN) clean
	sudo rm -rf $@
	sudo rm -f .root-copied
	mkdir $@

# put any needed Makefile directives here
# add dependency for these targets to "all:"
# Example:
# all: myrule
# myrule:
#      do_something
#$(VROOT)/usr/lib/vdr/libvdr-$(PLUGIN).so.$(APIVERSION): $(PLUGIN)-$(VERSION)/libvdr-$(PLUGIN).so
#	#install -d $(@D)
#	sudo $(install_exe) $< $@

#$(PLUGIN)-$(VERSION)/libvdr-$(PLUGIN).so: $(PLUGIN)-$(VERSION)/Makefile $(LIBDIR)
#	make -C $(<D) all

#$(PLUGIN)-$(VERSION)/Makefile: vdr-$(PLUGIN)-$(VERSION).tgz
#	tar -zxf $<
#	patch -d $(@D) < $(PATCHES)

#	-$(MAKE) -C $(SRCDIR)/vdr-plugins/src/$(PLUGIN) clean
target-clean:
	-rm -rf $(LIBDIR)
	-$(MAKE) -C $(src) clean
