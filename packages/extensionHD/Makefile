#
# Makefile for ReelBox packages
#
#

include ../Make.common
#LK=$(shell uname -r | cut -d- -f1-2)
LK=$(shell uname -r )

export SRCDIR = /usr/src/reelbox/testing/src

#export KERNELPATH = $(SRCDIR)/kernel/linux-2.6.20
export KERNELPATH = $(SRCDIR)/kernel/linux-$(LK)

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

#RC: next two targets are a trick to clean the VROOT before building
$(VROOT)/DEBIAN/control: tmp

tmp: control
	sudo rm -rf $@
	mkdir $@
	$(MAKE) -C $(SRCDIR)/utils/hdshm3 clean


$(TARGET): $(VROOT)/usr/share/reel/hdimage/linux.bin

$(VROOT)/usr/share/reel/hdimage/linux.bin: $(PRECOMPILED)/linux.bin.gz
	[ -d $(@D) ] || sudo mkdir -p $(@D)
	sudo cp -a $< $(@D)
	sudo gunzip -f $(@D)/$(<F)


#$(SRCDIR)/utils/hdshm3/x86/driver/hdshm.o: control
#	$(MAKE) -C $(SRCDIR)/utils/hdshm3 clean x86

$(SRCDIR)/utils/hdshm3/x86/hdctrld/hdctrld: $(SRCDIR)/utils/hdshm3/x86/hdctrld/*.c
	$(MAKE) -C $(@D)

$(SRCDIR)/utils/hdshm3/x86/hdboot/hdboot: $(SRCDIR)/utils/hdshm3/x86/hdboot/*.c
	$(MAKE) -C $(@D)

$(SRCDIR)/utils/hdshm3/x86/shmnetd/shmnetd: $(SRCDIR)/utils/hdshm3/x86/shmnetd/*.c
	$(MAKE) -C $(@D)

$(SRCDIR)/utils/hdshm3/x86/hdfbctl/hdfbctl: $(SRCDIR)/utils/hdshm3/x86/hdfbctl/*.c
	$(MAKE) -C $(@D)

$(SRCDIR)/utils/hdshm3/x86/hdfbshot/hdfbshot: $(SRCDIR)/utils/hdshm3/x86/hdfbshot/*.c
	$(MAKE) -C $(@D)

$(SRCDIR)/utils/hdfbshot/hdfbshot: $(SRCDIR)/utils/hdfbshot/*.c
	$(MAKE) -C $(@D)

clean: clean-hdshm

clean-hdshm:
	$(MAKE) -C $(SRCDIR)/utils/hdshm3 clean

