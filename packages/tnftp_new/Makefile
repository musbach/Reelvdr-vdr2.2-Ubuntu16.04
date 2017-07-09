#
# Makefile for ReelBox packages
#
#

PWD = $(shell pwd)

NAME     = tnftp
VERSION  = 20091122
PL       = 0.1
PLATFORM = i386
WORKDIR := $(PWD)/$(NAME)-$(VERSION)

#include ../Make.common

#$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
#$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/prerm
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(NAME)_$(VERSION)-$(PL)_$(PLATFORM).deb


$(NAME)_$(VERSION)-$(PL)_$(PLATFORM).deb: $(WORKDIR)/debian/changelog $(WORKDIR)/debian/control
	-rm -f $(NAME)*.tar.gz $(NAME)*.dsc $(NAME)*.changes $(NAME)*.deb
	echo "this here is really really experimental..."
	cd $(WORKDIR) ; dpkg-buildpackage -rfakeroot -us -uc # -tc
	cp -a $(NAME)_$(VERSION)*.deb ..


clean: clean-workdir

clean-workdir:
	-rm -f $(NAME)*.tar.gz $(NAME)*.dsc $(NAME)*.changes $(NAME)*.deb
	make -C $(WORKDIR) distclean
	
