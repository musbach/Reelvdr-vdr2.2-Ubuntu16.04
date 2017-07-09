#
# Makefile for ReelBox packages
#
#

PWD = $(shell pwd)

VERSION = 4.4
VERSIONNUM = 0404
WORKDIR = $(PWD)/bftpd-$(VERSION)

include ../Make.common

$(TARGET): .root-copied
$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/prerm
$(TARGET): $(VROOT)/DEBIAN/postrm


all: $(TARGET)

$(TARGET): tmp/usr/sbin/bftpd

#install
tmp/usr/sbin/bftpd: $(WORKDIR)/bftpd
	sudo $(install_exe) -o 0 -g 0 -D $< $@
	sudo $(STRIP) $@

#build
$(WORKDIR)/bftpd: $(WORKDIR)/Makefile
	make -C $(WORKDIR)

#unpack + configure
$(WORKDIR)/Makefile: bftpd-$(VERSION).tar.gz
	tar -zxf $<
	[ ! -f $@ ] && [ -f bftpd/Makefile ] && mv bftpd $(WORKDIR) || true
	[ $(VERSIONNUM) -lt 0305 ] && patch -p1 -d $(@D) < socketfix.diff || true
	cd $(WORKDIR) && ./configure --prefix=/usr $(HOST)
	touch $@

# the next two targets are a trick to clean the VROOT before building
$(VROOT)/DEBIAN/control: tmp

tmp: $(CONTROL)
	sudo rm -rf $(WORKDIR)
	sudo rm -rf $@
	sudo rm -f .root-copied
	mkdir $@


clean: clean-workdir

clean-workdir:
	-rm -rf $(WORKDIR)
