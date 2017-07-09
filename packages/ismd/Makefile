#
# Makefile for ReelBox packages
#
#

include ../Make.common

export SRCDIR
export MAINSRC

# uncomment if you need conffiles, postinst etc. included

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
#$(TARGET): $(VROOT)/DEBIAN/preinst
$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/prerm
#$(TARGET): $(VROOT)/DEBIAN/postrm

#SDK_FULLVERSION := 25.0.11473.304186
SDK_FULLVERSION := 20120919
src             := fsmd_gst_plugin-$(SDK_FULLVERSION)

all: $(TARGET)

clean: target-clean

# the next two targets are a trick to clean the VROOT before building
$(VROOT)/DEBIAN/control: tmp

tmp: $(CONTROL)
	$(MAKE) target-clean
	sudo rm -rf $@
	sudo rm -f .root-copied
	mkdir $@


# put any needed Makefile directives here
# add dependency for these targets to "all:"
# Example:
# all: myrule
# myrule:
# 	do_something
$(TARGET): $(VROOT)/usr/lib/gstreamer-0.10/libgstfluismd.so
$(TARGET): $(VROOT)/usr/sbin/splash
$(TARGET): $(VROOT)/usr/sbin/gstplayer
$(TARGET): $(VROOT)/usr/sbin/transcode

$(VROOT)/usr/lib/gstreamer-0.10/libgstfluismd.so: $(src)/libgstfluismd.so
	sudo $(install_lib) $< $@

fsmd_gst_plugin-$(SDK_FULLVERSION)/libgstfluismd.so: $(src)/*.[ch]
	make -C $(@D)

$(VROOT)/usr/sbin/splash: splash/splash
	sudo $(install_exe) $< $@

splash/splash:
	make -C $(@D)

$(VROOT)/usr/sbin/gstplayer: gstplayer/gstplayer
	sudo $(install_exe) $< $@

gstplayer/gstplayer:
	make -C $(@D)

$(VROOT)/usr/sbin/transcode: transcode/transcode
	sudo $(install_exe) $< $@

transcode/transcode:
	make -C $(@D)

target-clean:
	-$(MAKE) -C $(src) clean
	-$(MAKE) -C splash clean
	-$(MAKE) -C gstplayer clean
	-$(MAKE) -C transcode clean
