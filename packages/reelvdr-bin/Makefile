#
# Makefile for ReelBox packages
#
#

include ../Make.common
#include ../Make.config

#$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
$(TARGET): $(VROOT)/DEBIAN/changelog
#$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

#$(TARGET): $(VROOT)/usr/share/man/man1/vdr.1.gz $(VROOT)/usr/share/man/man5/vdr.5.gz

$(VROOT)/DEBIAN/control: clean-target

$(VROOT)/usr/share/man/man1/vdr.%.gz \
$(VROOT)/usr/share/man/man5/vdr.%.gz: $(SRCDIR)/vdr-$(VDRVER)/vdr.%
	sudo mkdir -p $(VROOT)/$(@D)
	sudo chmod a+w $(VROOT)/$(@D)
	gzip -c $< > $(VROOT)/$@


$(SRCDIR)/vdr-$(VDRVER)/vdr: $(CONTROL)
	make -C $(@D) vdr i18n-vdr-dist

clean-target: $(CONTROL)
	-[ -f $(TARGET) ] && make -C $(SRCDIR)/vdr-$(VDRVER) clean || true
	touch $@
