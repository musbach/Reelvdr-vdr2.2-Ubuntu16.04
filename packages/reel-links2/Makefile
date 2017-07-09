#
# Makefile for ReelBox packages
#
#

PWD = $(shell pwd)

VERSION = 2.12
WORKDIR = $(PWD)/links-$(VERSION)
ORIGSRC	= links-2.12.tar.gz


include ../Make.common

$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(TARGET): tmp/usr/sbin/links2

#install
$(VROOT)/usr/sbin/links2: $(WORKDIR)/links
	sudo $(install_exe) -D $< $@

#build
$(WORKDIR)/links: $(WORKDIR)/Makefile
	make -C $(WORKDIR)

#unpack + configure
$(WORKDIR)/Makefile:$(ORIGSRC)
	tar -zxf $(ORIGSRC)
	#zcat $(SRCDIR)/archiv/reel-diffs/links2_2.1pre28-1.diff.gz|patch -d $(@D) -p1
	#patch -d $(@D) -p1 < $(SRCDIR)/archiv/reel-diffs/reel-links2.diff
	cd $(WORKDIR) && ./configure --without-x --without-svgalib --with-directfb --enable-graphics --with-gpm --enable-javascript -with-ssl
	touch $@

clean: clean-workdir

clean-workdir:
	-rm -rf $(WORKDIR)
