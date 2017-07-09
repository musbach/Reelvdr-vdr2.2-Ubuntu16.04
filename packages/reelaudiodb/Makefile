#
# Makefile for ReelBox packages
#
#


include ../Make.common
include $(SRCDIR)/Make.config

$(TARGET): $(VROOT)/DEBIAN/postinst $(VROOT)/DEBIAN/postrm

all: $(TARGET)


$(SRCDIR)/libs/reelaudiodb/MediaCleaner \
$(SRCDIR)/libs/reelaudiodb/MediaCrawler \
$(SRCDIR)/libs/reelaudiodb/MediaRemover \
$(SRCDIR)/libs/reelaudiodb/MediaAnalyzer : control $(SRCDIR)/libs/reelaudiodb/*.[ch]
	$(MAKE) -C $(@D) all

