#just for the reelbox package build-system

#package := $(shell grep Package debian/control | cut -f2 -d" ")
#version := $(shell dpkg-parsechangelog | grep Version: | cut -f2 -d" ")
PACKAGE := vobcopy
VERSION := 1.2.0
BUILD   := 2

ARCH     := i386
#GNU_TYPE := pentium3-linux-gnu
#GNU_TYPE := i486-linux-gnu

TARGET = $(PACKAGE)_$(VERSION)-$(BUILD)_$(ARCH).deb
TMP    = $(PACKAGE)-$(VERSION)

all: $(TARGET)

$(TARGET): $(TMP)/debian/changelog
	echo "this here is really really experimental..."
	cd $(TMP) && ./configure.sh
	cd $(TMP) ; LANG=C dpkg-buildpackage -a$(ARCH) -t$(GNU_TYPE) -rfakeroot -us -uc -tc
	cp -av *.deb ..

#obsolete - rm later!!!
build-stamp:
	echo "this here is really really experimental..."
	cd $(package)-$(version) && ./configure.sh
	#make
	dpkg-buildpackage -rfakeroot -us -uc -tc -tpentium3-gnu-linux

clean:
	-sudo $(MAKE) -C $(PACKAGE)-$(VERSION) -f debian/rules clean
	-$(MAKE) -C $(PACKAGE)-$(VERSION) distclean
	-rm -f $(PACKAGE)_$(VERSION)-$(BUILD)_* $(PACKAGE)_$(VERSION)-$(BUILD).*
