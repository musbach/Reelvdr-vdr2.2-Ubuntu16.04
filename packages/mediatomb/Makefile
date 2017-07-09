#
# Makefile for ReelBox packages
#
#

PWD = $(shell pwd)

VERSION = 0.12.1
WORKDIR = $(PWD)/mediatomb-$(VERSION)


include ../Make.common

$(TARGET): .root-copied
$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/preinst
$(TARGET): $(VROOT)/DEBIAN/prerm
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(TARGET): tmp/usr/bin/mediatomb

#install
tmp/usr/bin/mediatomb: $(WORKDIR)/build/mediatomb
	sudo make -C $(WORKDIR) install DESTDIR=$(PWD)/tmp INSTALL_PROGRAM="install -sp"
	sudo touch $@

#build
$(WORKDIR)/build/mediatomb: $(WORKDIR)/Makefile
	make -C $(WORKDIR)


# generate the Makefile by autoreconf. So, the touch $@ is not needed.
$(WORKDIR)/Makefile: $(WORKDIR)/configure
	cd $(WORKDIR) && autoreconf -i && ./configure --prefix=/usr --enable-transcoding 
	#cat *.diff | patch -p0
	touch $@

$(WORKDIR)/configure: $(PWD)/mediatomb-$(VERSION).tar.gz
	tar -zxf $<
	touch $@

#use mediatomb's make clean
clean: clean-workdir

clean-workdir:
	-sudo make -C $(WORKDIR) distclean
#	-sudo rm -rf $(WORKDIR)
