#
# Makefile for ReelBox packages
#
#

PWD = $(shell pwd)

VERSION = 1.3.1
WORKDIR = $(PWD)/bftpd-$(VERSION)


include ../Make.common

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/prerm
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

