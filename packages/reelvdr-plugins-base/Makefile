#
# Makefile for ReelBox packages
#
#

include ../Make.common

export SRCDIR

# uncomment if you need conffiles, postinst etc. included

$(TARGET): .root-copied
$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
#$(TARGET): $(VROOT)/DEBIAN/preinst
#$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/prerm
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)


# put any needed Makefile directives here
# add dependency for these targets to "all:"
# Example:
# all: myrule
# myrule:
# 	do_something

VDRPLUGINS = $(shell for i in $(FILES) ; do basename $$i | grep libvdr- ; done )

$(VROOT)/DEBIAN/control: tmp

tmp: $(CONTROL)
	@echo making: $@
	@echo cleanup: deleting old plugins
	@for j in $(VDRPLUGINS) ; do \
		rm -vf $(SRCDIR)/vdr-plugins/lib/$$j 2>/dev/null ;\
		rm -vf $(SRCDIR)/vdr-plugins/src/`echo $$j | cut -f2 -d- | cut -f1 -d.`/*.so 2>/dev/null ;\
	done
	sudo rm -rf $@
	sudo rm -f .root-copied
	mkdir $@

clean: clean-target
clean-target:
	@echo Doing clean-target
#	make -C $(SRCDIR)/vdr-$(VDRVER) plugins-clean
