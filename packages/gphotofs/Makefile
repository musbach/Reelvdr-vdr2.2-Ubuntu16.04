#just for the reelbox package build-system
TARGET_VERSION := 0.4.0
#PATCHES := xine-lib-debian.diff xine-lib-reel.diff xine-lib-vdr.diff
#PATCHES := xine-lib-debian.diff xine-lib-reel.diff
#PATCHES := xine-lib_1.1.8-1ubuntu1.diff xine-lib-reel.diff

REEL_VERSION := $(shell grep -m1 gphotofs gphotofs-$(TARGET_VERSION)/debian/changelog | cut -f 2 -d"(" | cut -f1 -d")" )

all: gphotofs_$(REEL_VERSION)_i386.deb

gphotofs_0.4.0-1reel1_i386.deb: gphotofs-$(TARGET_VERSION)/debian/changelog \
		gphotofs-$(TARGET_VERSION)/debian/control
	echo "this here is really really experimental..."
	cd gphotofs-$(TARGET_VERSION) ; dpkg-buildpackage -rfakeroot -us -uc -tc
	cp -av *.deb ..

clean:
	-cd gphotofs-$(TARGET_VERSION) ; make clean
	-rm -f *.deb *.dsc *.changes *.tar.gz
