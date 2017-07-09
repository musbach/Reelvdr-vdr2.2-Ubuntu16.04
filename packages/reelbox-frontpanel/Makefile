#
# Makefile for ReelBox frontpanel package
#
#

include ../Make.common
include ../Make.config

$(TARGET): .root-copied                                                                                
$(TARGET): $(VROOT)/DEBIAN/conffiles                                                                   
$(TARGET): $(VROOT)/DEBIAN/changelog                                                                   
$(TARGET): $(VROOT)/DEBIAN/postinst                                                                     
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(SRCDIR)/utils/reelbox-control/reelbox-ctrld: control
	make -C $(@D) clean reelbox-ctrld

$(SRCDIR)/utils/avr_flash/avr_flasher: control
	make -C $(@D) clean $(@F)

$(SRCDIR)/utils/reelfpctl/reelfpctl: control
	make -C $(@D) clean $(@F)

$(SRCDIR)/utils/reelfpctl/reelfpctl1: control
	make -C $(@D) $(@F)


clean: clean-src

clean-src:
	$(MAKE) -C $(SRCDIR)/utils/reelbox-control clean
	$(MAKE) -C $(SRCDIR)/utils/avr_flash clean
	$(MAKE) -C $(SRCDIR)/utils/reelfpctl clean
