#
# Makefile for ReelBox packages
#
#

include ../Make.common

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

ifdef RBMINI
    $(TARGET): $(VROOT)/root/bin/flash_erase
endif

$(VROOT)/root/bin/flash_erase: $(PRECOMPILED)/flash_erase$(SUFFIX).gz
	mkdir -p $(@D)
	gunzip -c $^ > $@
	chmod 755 $@

