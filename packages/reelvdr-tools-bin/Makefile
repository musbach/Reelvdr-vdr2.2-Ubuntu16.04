#
# Makefile for ReelBox tools packages
#
#

include ../Make.common

$(TARGET): #.root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

clean: clean-fskcheck clean-genindex clean-speedcontrol

## fskcheck
$(SRCDIR)/vdr-plugins/src/pin/fskcheck: control
	$(MAKE) -C $(@D) clean-$(@F) $(@F)

clean-fskcheck:
	$(MAKE) -C $(SRCDIR)/vdr-plugins/src/pin $@


## genindex
$(SRCDIR)/utils/genindex/genindex: control
	make -C $(@D) clean $(@F)

## speedcontrol
$(SRCDIR)/utils/speedcontrol/speedcontrol: control
	make -C $(@D) clean $(@F)

clean-genindex:
	make -C $(SRCDIR)/utils/genindex clean

clean-speedcontrol:
	make -C $(SRCDIR)/utils/speedcontrol clean
