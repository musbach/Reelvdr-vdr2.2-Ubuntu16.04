#
# Makefile for ReelBox packages
#
#

PWD = $(shell pwd)

VERSION = 0.48
WORKDIR = $(PWD)/tftp-hpa-$(VERSION)


include ../Make.common

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/prerm
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(TARGET): tmp/usr/sbin/in.tftpd

#install
tmp/usr/sbin/in.tftpd: $(WORKDIR)/tftpd/tftpd
	sudo make -C $(WORKDIR) install INSTALLROOT=$(PWD)/tmp \
		INSTALL_PROGRAM="install -sp"

#build
$(WORKDIR)/tftpd/tftpd: $(WORKDIR)/Makefile
	make -C $(WORKDIR)

#unpack + configure
$(WORKDIR)/Makefile: tftp-hpa-$(VERSION).tar.gz
	tar -zxf $<
	cd $(WORKDIR) && ./configure --prefix=/usr
	touch $@

clean: clean-workdir

clean-workdir:
	-rm -rf $(WORKDIR)
