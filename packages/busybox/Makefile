#just for the reelbox package build-system
PACKAGE     := busybox
PKG_VERSION := 1.10.2

DEBIAN_PATCHES := $(PACKAGE)_$(PKG_VERSION)-2.diff.gz

ifdef RBMINI
    ARCH = armel
    CROSS_COMPILE = arm-linux-gnueabi-
    export ARCH CROSS_COMPILE
else
    ARCH = i386
endif

TARGET = $(PACKAGE)_$(PKG_VERSION)_$(ARCH).deb

TMP = $(PACKAGE)-$(PKG_VERSION)

REEL_VERSION := $(shell grep -m1 $(PACKAGE) $(PACKAGE)-$(PKG_VERSION)/debian/changelog | cut -f 2 -d"(" | cut -f1 -d")" )

all: $(TARGET)

$(TARGET): $(TMP)/configure \
		$(TMP)/debian/control \
		$(TMP)/debian/changelog
	@echo "this here is experimental..."
	cd $(TMP) ; dpkg-buildpackage -a$(ARCH) -rfakeroot -us -uc -tc
	cp -av *.deb ..


$(TMP)/configure: $(PACKAGE)-$(PKG_VERSION).orig.tar.gz
	tar -zxf $<
	zcat $(DEBIAN_PATCHES) | patch -p1 -d $(TMP)
	cat reel*.diff | patch -p1 -d $(TMP)
	chmod a+x $(TMP)/debian/rules
	-rm -f $(TMP)/debian/changelog $(TMP)/debian/control
	touch $@

$(TMP)/debian/changelog \
$(TMP)/debian/control \
$(TMP)/debian/$(PACKAGE).postinst \
$(TMP)/debian/$(PACKAGE).prerm: $(@F)
	cp -a $(@F) $@

clean:
	-make -C $(PACKAGE)-$(PKG_VERSION) clean
	-rm -f *.deb *.dsc *.changes $(PACKAGE)$(PKG_VERSION).tar.gz
	-rm -rf $(TMP) *.deb *.udeb
