#
# Makefile for ReelBox packages
#
#

include ../Make.common

export SRCDIR

# uncomment if you need conffiles, postinst etc. included

#$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
#$(TARGET): $(VROOT)/DEBIAN/preinst
#$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/prerm
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(TARGET): $(VROOT)/usr/share/locale/de_DE/LC_MESSAGES/reel.mo
$(TARGET): $(VROOT)/usr/share/locale/nl_NL/LC_MESSAGES/reel.mo

$(VROOT)/usr/share/locale/de_DE/LC_MESSAGES/reel.mo: $(SRCDIR)/misc/i18n/de_DE.po
	echo install -d $(@D)
	install -d $(@D)
	sudo msgfmt -c $< -o $@

$(VROOT)/usr/share/locale/nl_NL/LC_MESSAGES/reel.mo: $(SRCDIR)/misc/i18n/nl_NL.po
	echo install -d $(@D)
	install -d $(@D)
	sudo msgfmt -c $< -o $@

#RC: next two targets are a trick to clean the VROOT before building

$(VROOT)/DEBIAN/control: tmp

tmp: $(CONTROL)
	sudo rm -rf $@
	sudo rm -f .root-copied
	mkdir $@
#fileout:
	find $(SRCDIR)/vdr-$(VDRVER)/locale -name *.mo -exec rm -f {} \;
	cd $(SRCDIR)/vdr-$(VDRVER) && make i18n ;
	for I in arghdirector bgprocess bgprocess epgsearch extrecmenu femon filebrowser install ipod netcv netcvupdate osdteletext pin premiereepg setup sleeptimer ; do \
		echo $$I ; \
		cd $(SRCDIR)/vdr-plugins/src/$$(echo $$I) ; \
		make i18n ;  \
	done

clean: target-clean


# put any needed Makefile directives here
# add dependency for these targets to "all:"
# Example:
# all: myrule
# myrule:
# 	do_something

$(SRCDIR)/vdr-$(VDRVER)/locale/%/LC_MESSAGES/vdr.mo:
	$(MAKE) -C $(SRCDIR)/vdr-$(VDRVER) i18n-vdr-dist


target-clean:

	-$(MAKE) -C $(src) i18n-clean
