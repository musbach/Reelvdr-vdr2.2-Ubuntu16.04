#
# Makefile for ReelBox packages
#
#

include ../Make.common

#$(TARGET): .root-copied
$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/postrm

ifdef RBMINI
  SUFFIX = -mini
endif

all: $(TARGET)

$(TARGET): $(VROOT)/usr/sbin/mcli \
		$(VROOT)/usr/sbin/netcvdiag \
		$(VROOT)/usr/sbin/netcvupdate \
		$(VROOT)/usr/sbin/netcvlogview

clean: tools-clean


$(VROOT)/usr/sbin/mcli: $(SRCDIR)/vdr-plugins/src/mcli/mcast/client/*.[ch] \
		$(SRCDIR)/vdr-plugins/src/mcli/mcast/common/*.h
	$(MAKE) -C $(<D) $(@F)-shared
	$(install_exe) -D $(<D)/$(@F)-shared $@
	$(STRIP) $@

$(VROOT)/usr/sbin/netcvdiag \
$(VROOT)/usr/sbin/netcvupdate \
$(VROOT)/usr/sbin/netcvlogview: $(SRCDIR)/vdr-plugins/src/mcli/mcast/tool/*.[ch]
	$(MAKE) -C $(<D) $(@F)
	$(install_exe) $(<D)/$(@F) $@
	$(STRIP) $@


tools-clean:
	-make -C $(SRCDIR)/vdr-plugins/src/mcli/mcast/tool clean
	-make -C $(SRCDIR)/vdr-plugins/src/mcli/mcast/client clean
