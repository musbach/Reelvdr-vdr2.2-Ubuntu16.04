#
# Makefile for ReelBox packages
#
#


include ../Make.common

$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(TARGET): $(VROOT)/usr/lib/libreel.so

$(VROOT)/usr/lib/libreel.so: \
		$(SRCDIR)/libs/libreel/src/libreel.so
	$(install_lib) -D $< $@

$(SRCDIR)/libs/libreel/src/libreel.so: control $(SRCDIR)/libs/libreel/src/*.[ch]
	$(MAKE) -C $(@D) clean all


clean: libreel-clean

libreel-clean:
	$(MAKE) -C $(SRCDIR)/libs/libreel/src clean
