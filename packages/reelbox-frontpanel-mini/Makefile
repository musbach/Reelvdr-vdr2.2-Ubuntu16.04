#
# Makefile for ReelBox frontpanel package
#
#

include ../Make.common
include ../Make.config

$(TARGET): .root-copied                                                                                
#$(TARGET): $(VROOT)/DEBIAN/conffiles                                                                   
$(TARGET): $(VROOT)/DEBIAN/changelog                                                                   
$(TARGET): $(VROOT)/DEBIAN/postinst                                                                     
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(SRCDIR)/utils/reelbox-control/reelbox-ctrld: control
	$(MAKE) -C $(@D) clean reelbox-ctrld

$(SRCDIR)/utils/avr_flash/avr_flasher: control
	$(MAKE) -C $(@D) clean $(@F)

$(SRCDIR)/utils/reelfpctl/reelfpctl: control
	$(MAKE) -C $(@D) clean $(@F)


clean: clean-src

clean-src:
	$(MAKE) -C $(SRCDIR)/utils/reelbox-control clean
	$(MAKE) -C $(SRCDIR)/utils/avr_flash_mini clean
	$(MAKE) -C $(SRCDIR)/utils/reelfpctl clean
