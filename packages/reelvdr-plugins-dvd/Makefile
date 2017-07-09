#
# Makefile for Reelvdr-Plugins-DVD Packages
#
#

include ../Make.common

export SRCDIR

src1 = $(SRCDIR)/vdr-plugins/src/burn
src2 = $(SRCDIR)/vdr-plugins/src/dvdswitch
src3 = $(SRCDIR)/vdr-plugins/src/mediad
src4 = $(SRCDIR)/vdr-plugins/src/mediaplayer
src5 = $(SRCDIR)/vdr-plugins/src/ripit

# uncomment if you need conffiles, postinst etc. included

$(TARGET): .root-copied
$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
#$(TARGET): $(VROOT)/DEBIAN/preinst
#$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/prerm
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

clean: target-clean


# the next two targets are a trick to clean/rebuild the VROOT and plugin-dir before building
$(VROOT)/DEBIAN/control: tmp

tmp: $(CONTROL)
	$(MAKE) -C $(src1) plug i18n-dist
	$(MAKE) -C $(src2) plug i18n-dist
	$(MAKE) -C $(src3) plug i18n-dist
	$(MAKE) -C $(src4) plug i18n-dist
	$(MAKE) -C $(src5) plug i18n-dist
	sudo rm -rf $@
	sudo rm -f .root-copied
	mkdir $@


# put any needed Makefile directives here
# add dependency for these targets to "all:"
# Example:
# all: myrule
# myrule:
#       do_something


target-clean:
	make -C $(src1) clean
	make -C $(src2) clean
	make -C $(src3) clean
	make -C $(src4) clean
	make -C $(src5) clean
