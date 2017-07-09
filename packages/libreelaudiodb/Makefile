#
# Makefile for ReelBox packages
#
#


include ../Make.common
include $(SRCDIR)/Make.config

$(TARGET): $(VROOT)/DEBIAN/postinst $(VROOT)/DEBIAN/postrm

all: $(TARGET)

#### User defined rules
$(SRCDIR)/libs/reelaudiodb/libreelsearchapi.so: control $(SRCDIR)/libs/reelaudiodb/*.[ch]
	$(MAKE) -C $(@D) libreelsearchapi.so

