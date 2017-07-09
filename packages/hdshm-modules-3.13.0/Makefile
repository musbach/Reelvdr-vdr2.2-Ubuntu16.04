#!/bin/bash
#
# Makefile for ReelBox packages
#
#

include ../Make.common
KV=$(shell uname -r | cut -d- -f1-2)
#KERNELVERSION = $(shell lsb_release -sr )

export KERNELPATH = $(SRCDIR)/kernel/linux-$(KV)

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/preinst
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

#RC: next two targets are a trick to clean the VROOT before building
$(VROOT)/DEBIAN/control: tmp

tmp: control
	sudo rm -rf $@
	mkdir $@


$(SRCDIR)/utils/hdshm/x86/driver/hdshm.o: control
	$(MAKE) -C $(SRCDIR)/utils/hdshm clean x86

$(SRCDIR)/utils/hdshm/x86/hdctrld/hdctrld: $(SRCDIR)/utils/hdshm/x86/hdctrld/*.c
	$(MAKE) -C $(@D)

clean:

