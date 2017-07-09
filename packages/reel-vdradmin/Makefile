#
# Makefile for ReelBox packages
#
#

include ../Make.common

$(TARGET): .root-copied
$(TARGET): $(VROOT)/DEBIAN/conffiles
$(TARGET): $(VROOT)/DEBIAN/postinst
$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)


PODIR     = $(SRCDIR)/misc/vdradmin
LOCALEDIR = $(VROOT)/usr/share/locale
I18Npo    = $(wildcard $(PODIR)/*.po)
I18Nmsgs  = $(addprefix $(LOCALEDIR)/, $(addsuffix /LC_MESSAGES/vdradmin.mo, \
                $(notdir $(foreach file, $(I18Npo), $(basename $(file))))))

$(TARGET): $(I18Nmsgs)

$(I18Nmsgs): $(LOCALEDIR)/%/LC_MESSAGES/vdradmin.mo: $(SRCDIR)/misc/vdradmin/%.po
	@echo "making: $@"
	sudo install -d $(@D)
	sudo msgfmt -c -o $@ $<	

#RC: next two targets are a trick to clean the VROOT before building
$(VROOT)/DEBIAN/control: tmp

tmp: $(CONTROL)
	sudo rm -rf $@
	sudo rm -f .root-copied
	mkdir $@
