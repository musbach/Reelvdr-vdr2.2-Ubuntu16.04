#
# Makefile for ReelBox packages
#
#

PWD = $(shell pwd)

VERSION = 0.71
WORKDIR = $(PWD)/djmount-$(VERSION)


include ../Make.common

$(TARGET): .root-copied
$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/preinst
#$(TARGET): $(VROOT)/DEBIAN/prerm
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(TARGET): tmp/usr/local/bin/djmount

#install
tmp/usr/local/bin/djmount: $(WORKDIR)/djmount/djmount
	sudo make -C $(WORKDIR) install DESTDIR=$(PWD)/tmp INSTALL_PROGRAM="install -sp"
	sudo touch $@

#build
$(WORKDIR)/djmount/djmount: $(WORKDIR)/Makefile
	make -C $(WORKDIR)

$(WORKDIR)/Makefile: $(WORKDIR)/configure
	cd $(WORKDIR) && ./configure
	touch $@

$(WORKDIR)/configure: $(PWD)/djmount-$(VERSION).tar.gz
	tar -zxf $<
	touch $@

clean: clean-workdir

clean-workdir:
	-sudo make -C $(WORKDIR) distclean
	-sudo rm -rf $(WORKDIR)
