#
# Makefile for ReelBox packages
#
#

include ../Make.common

#$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

#RC: next two targets are a trick to clean the VROOT before building                                                           
$(VROOT)/DEBIAN/control: tmp                                                                                                   
                                                                                                                               
tmp: control                                                                                                                   
	sudo rm -rf $@                                                                                                         
	mkdir $@

$(TARGET): $(VROOT)/usr/share/reel/hdplayer/hdplayer

$(VROOT)/usr/share/reel/hdplayer/hdplayer: $(PRECOMPILED)/hdplayer.gz
	sudo mkdir -p $(@D)
	sudo cp $< $(@D)
	sudo gunzip -f $(@D)/$(<F)
