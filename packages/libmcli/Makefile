#
# Makefile for ReelBox packages
#
#

include ../Make.common

export SRCDIR

# uncomment if you need conffiles, postinst etc. included

#$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
#$(TARGET): $(VROOT)/DEBIAN/preinst
$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/prerm
$(TARGET): $(VROOT)/DEBIAN/postrm

#src := $(SRCDIR)/vdr-plugins/src/vdr-mcli-plugin
src := $(SRCDIR)/vdr-plugins/src/mcli

all: $(TARGET)

$(TARGET): $(VROOT)/usr/lib/libmcli.so

$(VROOT)/usr/lib/libmcli.so: $(src)/mcast/client/libmcli.so
	$(install_lib) -D $< $@

$(src)/mcast/client/libmcli.so: $(src)/mcast/client/*.c $(src)/mcast/client/*.h
	$(MAKE) -C $(src) $(@F)

clean: target-clean

# put any needed Makefile directives here
# add dependency for these targets to "all:"
# Example:
# all: myrule
# myrule:
# 	do_something

target-clean:
	-$(MAKE) -C $(src) clean
