#just for the reelbox package build-system

PKG            := mountall
TARGET_VERSION := 2.15.3
  # look at $(PKG)$(TARGET_VERSION)/debian/changelog for BUILD #
BUILD          := reel2


ifdef RBMINI
    ARCH = armel
else
    ARCH = i386
#    GNU_TYPE = -tpentium3-linux-gnu
    GNU_TYPE = -ti686-linux-gnu
endif

TARGET = $(PKG)_$(TARGET_VERSION)-$(BUILD)_$(ARCH).deb

TMP = $(PKG)-$(TARGET_VERSION)

REEL_VERSION := $(shell grep -m1 $(PKG)  $(PKG)-$(TARGET_VERSION)/debian/changelog | cut -f 2 -d"(" | cut -f1 -d")" )

all: $(TARGET)

$(TARGET): $(TMP)/configure \
		$(TMP)/debian/control \
		$(TMP)/debian/changelog
	echo "this here is really really experimental..."
	cd $(TMP) ; dpkg-buildpackage -a$(ARCH) $(GNU_TYPE) -rfakeroot -us -uc -tc
	cp -av *.deb ..


$(TMP)/configure:
	tar -zxf $(TMP).tar.gz
	cat reel*.diff | patch -p1 -d $(TMP)
	touch $@

$(TMP)/debian/changelog: changelog
	cp -a $(@F) $@

$(TMP)/debian/control \
$(TMP)/debian/$(PKG).postinst \
$(TMP)/debian/$(PKG).prerm: 
	cp -a $(@F) $@

clean:
	-make -C $(PKG)-$(TARGET_VERSION) clean
	-rm -f *.deb *.dsc *.changes $(PKG)_$(TARGET_VERSION)-$(BUILD).tar.gz
	-rm -rf $(TMP)
