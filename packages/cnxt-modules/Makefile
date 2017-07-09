#
# Makefile for ReelBox packages
#
#

include ../Make.common

export KERNELPATH = $(SRCDIR)/kernel/linux-2.6.18

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/preinst
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(TARGET): $(VROOT)/usr/sbin/rbmdisp


$(SRCDIR)/utils/hdfbshot/hdfbshot: $(SRCDIR)/utils/hdfbshot/*.c
	$(MAKE) -C $(@D)

$(VROOT)/usr/sbin/rbmdisp: $(SRCDIR)/utils/rbmdisp/rbmdisp
	sudo $(install_exe) -D $< $@

$(SRC)/utils/rbmdisp/rbmdisp: $(SRCDIR)/utils/rbmdisp/*.c
	make -C $(@D) RBMINI=1
