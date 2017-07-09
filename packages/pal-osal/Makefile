#
# Makefile for ReelBox packages
#
#

include ../Make.common

export SRCDIR
export MAINSRC

package = osal
include $(package).mk

src        = $(package)-$(OSAL_VERSION)
kernelsrc := $(shell cd ../linux-image-2.6.35-reel/kernel-intel/linux-2.6.35 ; pwd )

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

#$(TARGET): $(VROOT)/lib/modules/2.6.35/kernel/intel/$(package)-linux.ko \
#	$(VROOT)/etc/init.d/init_$(package)
#
#
#$(VROOT)/lib/modules/2.6.35/kernel/intel/$(package)-linux.ko: $(src)/Makefile
#	make -C $(kernelsrc) V=1 M=$(PWD)/$(OSAL_DIR)/linux_kernel \
#		TARGETCC=gcc EXTRA_CFLAGS="-I/usr/include/intelce -I/usr/include/intelce/linux"
#	$(install_bin) $(OSAL_DIR)/linux_kernel/$(package)-linux.ko $@
#
#$(src)/Makefile: $(package)-None-SRC-$(OSAL_VERSION).tgz
#	tar --strip-components=2 -zxf $<
#	touch $@
#
#$(VROOT)/etc/init.d/init_$(package): $(src)/init_$(package)
#	$(install_cfg) $< $@


target-clean:
	-rm -rf $(src)
	#-$(MAKE) -C $(src) clean
