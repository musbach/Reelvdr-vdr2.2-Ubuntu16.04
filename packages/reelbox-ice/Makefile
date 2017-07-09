#
# Makefile for ReelBox packages
#
#

include ../Make.common

$(TARGET): .root-copied
$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)
clean: target-clean

#$(TARGET): $(VROOT)/etc/initramfs-tools/scripts/local-premount/reel_desaster_recovery
#$(TARGET): $(VROOT)/etc/udev/rules.d/71-persistent-net.rules
#$(TARGET): $(VROOT)/usr/share/reel/frontpanel/ice4200_8051_firmware.bin
#$(TARGET): $(VROOT)/sbin/load_8051

#$(VROOT)/etc/initramfs-tools/scripts/local-premount/reel_desaster_recovery: \
#		$(MAINSRC)/etc/initramfs-tools/scripts/local-premount/reel_desaster_recovery
#	sudo $(install_script) $^ $@

$(VROOT)/sbin/load_8051: $(SRCDIR)/utils/ice/8051_load/load_8051
	sudo $(install_exe) $^ $@

$(SRCDIR)/utils/ice/8051_load/8051_load: $(SRCDIR)/utils/ice/8051_load/load_8051.c
	$(MAKE) -C $(<D)

#$(VROOT)/usr/share/reel/frontpanel/ice4200_8051_firmware.bin: $(SRCDIR)/ice/8051_fw/build/ce4200_8051_firmware.bin
#	sudo $(install_bin) $^ $@

$(VROOT)/sbin/ice_wol: $(SRCDIR)/utils/ice/ice_wol/ice_wol.c
	$(MAKE) -C $(<D)
	sudo $(install_bin) $^ $@

$(VROOT)/sbin/ice_pm: $(SRCDIR)/utils/ice/ice_pm/ice_pm.c
	$(MAKE) -C $(<D)
	sudo $(install_bin) $^ $@

#$(VROOT)/etc/udev/rules.d/71-persistent-net.rules: $(MAINSRC)/etc/udev/rules.d/71-persistent-net.rules
#	sudo $(install_cfg) $^ $@

#clean targets
target-clean:
	-$(MAKE) -C $(SRCDIR)/ice/8051_load clean
