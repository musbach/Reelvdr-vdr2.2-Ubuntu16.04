#
# Makefile for ReelBox packages
#
#

include ../Make.common

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/postrm

#$(shell  sed -e 's/1.4.7\(.[0-9]*\t*\)/$(APIVERSION)\t/g' -i files)

all: $(TARGET)

#RC: next two targets are a trick to clean the VROOT before building

$(VROOT)/DEBIAN/control: tmp


tmp: control
	$(MAKE) -C $(SRCDIR)/vdr-plugins/src/rbmini clean all
	sudo rm -rf $@
	sudo rm -f .root-copied
	mkdir $@
