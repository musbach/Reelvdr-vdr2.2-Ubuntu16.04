#
# Makefile for ReelBox packages
#
#

include ../Make.common

export SRCDIR

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)
clean: target-clean


version = 0.0.5
src := skinenigmang-$(version)

$(TARGET): $(VROOT)/usr/lib/vdr/libvdr-skinenigmang.so.$(APIVERSION)

$(VROOT)/usr/lib/vdr/libvdr-skinenigmang.so.$(APIVERSION): $(src)/libvdr-skinenigmang.so
	install -sp -m755 -D $< $@

$(src)/libvdr-skinenigmang.so:
	$(MAKE) -C $(@D) all


target-clean:
	$(MAKE) -C $(src) clean
