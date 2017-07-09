#
# Makefile for ReelBox packages
#
#

GLCD_V  = 1.9

include ../Make.common
include $(SRCDIR)/Make.config

$(TARGET): $(VROOT)/DEBIAN/postinst $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(TARGET): $(VROOT)/usr/lib/libglcddrivers.so.2.2.0 $(VROOT)/usr/lib/libglcdgraphics.so.2.2.0

$(VROOT)/usr/lib/libglcddrivers.so.1.0.0: \
		$(SRCDIR)/libs/graphlcd-base/glcddrivers/libglcddrivers.so.2.2.0
	$(install_lib) -D $< $@

$(SRCDIR)/libs/graphlcd-base/glcddrivers/libglcddrivers.so.2.2.0: control
	$(MAKE) -C $(@D) clean all


$(VROOT)/usr/lib/libglcdgraphics.so.2.2.0: \
		$(SRCDIR)/libs/graphlcd-base/glcdgraphics/libglcdgraphics.so.2.2.0
	$(install_lib) -D $< $@

$(SRCDIR)/libs/graphlcd-base/glcdgraphics/libglcdgraphics.so.2.2.0: control
	$(MAKE) -C $(@D) clean all


clean: glcd-clean

glcd-clean:
	$(MAKE) -C $(SRCDIR)/libs/graphlcd-base/glcddrivers/ clean
	$(MAKE) -C $(SRCDIR)/libs/graphlcd-base/glcdgraphics/ clean
