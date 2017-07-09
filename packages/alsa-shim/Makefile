#
# Makefile for ReelBox packages
#
#

include ../Make.common

export SRCDIR
export MAINSRC
PROJECT_BUILD_DIR=.

#include alsa_shim.mk

src        = alsa-driver-1.0.23
kernelsrc := $(shell cd ../linux-image-2.6.39-reel/kernel-intel/linux-2.6.39 ; pwd )

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

# put any needed Makefile directives here
# add dependency for these targets to "all:"
# Example:
# all: myrule
# myrule:
# 	do_something

$(TARGET): $(VROOT)/lib/modules/2.6.39/updates/sound/acore/snd.ko
#	$(VROOT)/etc/asound.conf \
#	$(VROOT)/etc/init.d/alsa_shim


$(VROOT)/lib/modules/2.6.39/updates/sound/acore/snd.ko: $(src)/acore/snd.ko
	sudo $(MAKE) -C $(src) install-modules DESTDIR=$(PWD)/$(VROOT)

$(src)/acore/snd.ko: $(src)/Makefile.conf
	$(MAKE) -C $(src) V=1

$(src)/Makefile.conf: $(src)/Makefile
	cd $(src) && ./configure --with-kernel=$(kernelsrc) \
	--with-build=$(KERNEL_BUILD_DIR) \
	--with-moddir=/lib/modules/2.6.39/updates/sound \
	--with-cross=$(CROSS_COMPILE) \
	--with-oss=no --with-cards=usb-audio

$(src)/Makefile: alsa-driver-1.0.23.tar.bz2
	tar -jxf $<
	cat alsa-driver-1.0.23-2.6.35.patch alsa-driver-1.0.23-2.6.39.patch | patch -d $(src) -p1
	touch $@

$(VROOT)/etc/asound.conf: $(ALSA_SHIM_DIR)/asound.conf
	$(install_cfg) $< $@

$(VROOT)/etc/init.d/alsa_shim: $(ALSA_SHIM_DIR)/init_alsa_shim
	$(install_cfg) $< $@


target-clean:
	#-$(MAKE) -C $(src) clean
	-rm -rf $(src)
