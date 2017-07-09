#
# Makefile for ReelBox packages
#
#

include ../Make.common

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/postrm

SVNREV = $(shell svn info 2>/dev/null | grep Revision | cut -f2 -d" ")
SVNREV = 14.14.1
DATE   = $(shell date --rfc-3339=date)

RELEASE = $(shell test -f $(SRCDIR)/etc/reel/release-$(DISTRIB_RELEASE) && echo release-$(DISTRIB_RELEASE) || echo release)
RELEASE = $(shell echo release)

all: $(TARGET)

$(TARGET): $(VROOT)/etc/reel/release

$(VROOT)/etc/reel/release: release
	sudo mkdir -p $(@D)
	sudo $(install_cfg) $^ $@

release: $(SRCDIR)/etc/reel/$(RELEASE) ../lastbuild
	@echo "==> svn: $(SVNREV) $(DATE)"
	cat $< | sed s/@BUILD@/$(SVNREV)/ | sed s/@DATE@/$(DATE)/ > $@


clean: target-clean

target-clean:
	rm release
