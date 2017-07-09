#
# Makefile for ReelBox packages
#
#

## all plattforms
PACKAGES  = ash-busybox
PACKAGES += bftpd
PACKAGES += dyndns-client
#PACKAGES += libapt-front
PACKAGES += libgraphlcd
PACKAGES += libmcli
#PACKAGES += mjpegtools
PACKAGES += netceiver-client
PACKAGES += netceiver-firmware
PACKAGES += osd-color-themes
PACKAGES += reelbox
PACKAGES += reelbox-stable
PACKAGES += reelbox-testing
PACKAGES += reel-keyring
PACKAGES += reelvdr
PACKAGES += reelvdr-baseconfig
PACKAGES += reelvdr-baseconfig-channels
PACKAGES += reelvdr-bin
PACKAGES += reelvdr-langpack
PACKAGES += reelvdr-pi-avahi
PACKAGES += reelvdr-pi-bouquets
PACKAGES += reelvdr-pi-channelscan
PACKAGES += reelvdr-pi-childlock
PACKAGES += reelvdr-pi-dpkg
PACKAGES += reelvdr-pi-eepg
PACKAGES += reelvdr-pi-formatdisk
PACKAGES += reelvdr-pi-graphlcd
PACKAGES += reelvdr-pi-graphlcd-support
PACKAGES += reelvdr-pi-mcli
PACKAGES += reelvdr-pi-media
PACKAGES += reelvdr-pi-netwatcher
PACKAGES += reelvdr-pi-reelblog
PACKAGES += reelvdr-pi-reelchannellist
PACKAGES += reelvdr-pi-reelepg
PACKAGES += reelvdr-pi-remote
PACKAGES += reelvdr-pi-skinreel3
PACKAGES += reelvdr-plugins-base
PACKAGES += reelvdr-tools
PACKAGES += reelvdr-tools-bin
PACKAGES += usbmount

## architecture dependent pkgs
ifdef RBMINI

   PACKAGES += cnxt-modules
   PACKAGES += dvbloop-2.6.18
   PACKAGES += jhead
   PACKAGES += kernel-experimental-mini
   PACKAGES += kernel-production-mini
   PACKAGES += reelbox-standard
   PACKAGES += reelbox-frontpanel-mini
   PACKAGES += reelvdr-output-rbmini
   PACKAGES += rbmini-dvbusb-modules

   export RBMINI=1

else ## RB AVG

#PACKAGES += alsa-shim
#PACKAGES += dvb-firmware
PACKAGES += chrome-ice
PACKAGES += display
#PACKAGES += dvbloop
#PACKAGES += dvbloop-2.6.24
#PACKAGES += dvdauthor-0.6.14
PACKAGES += extensionHD
#PACKAGES += gphotofs
PACKAGES += hdplayer
PACKAGES += hdshm-modules-3.13.0
PACKAGES += idl
#PACKAGES += ismd
PACKAGES += mediatomb
#PACKAGES += mountall
#PACKAGES += djmount
PACKAGES += ndis-wlan4reel
PACKAGES += noad
PACKAGES += noreelbox
PACKAGES += libreelaudiodb
PACKAGES += libssp
PACKAGES += reelaudiodb
PACKAGES += reel-editor
#PACKAGES += reel-links2
PACKAGES += reel-umts
PACKAGES += reel-vdradmin
PACKAGES += reel-wlan
PACKAGES += reel-xxv
PACKAGES += reelbox-browser-autostart
PACKAGES += reelbox-devel
PACKAGES += reelbox-devel-hd
#PACKAGES += reelbox-devel-ice
PACKAGES += reelbox-devel-lite
PACKAGES += reelbox-devel-mini
#PACKAGES += reelbox-devel-mini-common
PACKAGES += reelbox-devel-mini-debian
PACKAGES += reelbox-frontpanel
PACKAGES += reelbox-mr-service
PACKAGES += reelvdr-plugins-dvd
PACKAGES += reelvdr-external-epg
#PACKAGES += reelbox-ice
#PACKAGES += reelvdr-output-ice
PACKAGES += reelvdr-output-reelbox
PACKAGES += reelvdr-pi-amarokstarter
PACKAGES += reelvdr-pi-games
#PACKAGES += reelvdr-pi-musicbrowser
PACKAGES += reelvdr-pi-pip
PACKAGES += reelvdr-pi-rotor
PACKAGES += reelvdr-pi-timeline
#PACKAGES += reelvdr-pi-txtsubs
PACKAGES += reelvdr-pi-webbrowser
#PACKAGES += reelvdr-skinenigmang
PACKAGES += reelvdr-softdevice
PACKAGES += reelvdr-xineout
PACKAGES += reelvdr-xineliboutput
PACKAGES += reel-vga1080p60
PACKAGES += replex
PACKAGES += rubuntu-standard
PACKAGES += system-utils
PACKAGES += telnetd-reel
PACKAGES += tftp-hpa
#PACKAGES += tnftp
PACKAGES += tvtv
PACKAGES += ubuntu-minimal
PACKAGES += ubuntu-standard
PACKAGES += usb-display-firmware
#PACKAGES += vobcopy
PACKAGES += wlan-rtl8192
PACKAGES += xine-reel-ehd
PACKAGES += yacoto
PACKAGES += xserver-xorg-video-ice

endif  ### RBMINI

#-include Make.config



all:
	@[ "$(RBMINI)" = "1" ] && echo "Building for RBMINI" || true
	@for pkg in $(PACKAGES); do \
		echo "Building $$pkg" ;\
		if [ -f $$pkg/makefile.reel ] ; then \
			$(MAKE) -C $$pkg -f makefile.reel ;\
		else \
			$(MAKE) -C $$pkg ;\
		fi \
	done

clean:
	@[ "$(RBMINI)" = "1" ] && echo "Cleaning for RBMINI" || true
	@for pkg in $(PACKAGES); do \
		echo "Cleaning $$pkg" ;\
		if [ -f $$pkg/makefile.reel ] ; then \
			$(MAKE) -C $$pkg -f makefile.reel clean ;\
		else \
			$(MAKE) -C $$pkg clean ;\
		fi \
	done
