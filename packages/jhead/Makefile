#
# Makefile for jhead
#
#

include ../Make.common
include ../Make.config

#$(TARGET): .root-copied                                                                                
#$(TARGET): $(VROOT)/DEBIAN/conffiles                                                                   
#$(TARGET): $(VROOT)/DEBIAN/changelog                                                                   
#$(TARGET): $(VROOT)/DEBIAN/postinst                                                                     
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(TARGET): $(VROOT)/usr/sbin/jhead

clean: clean-src

JHEAD_VER=jhead-2.90

$(JHEAD_VER).tar.gz:
	wget http://www.sentex.net/~mwandel/jhead/$(JHEAD_VER).tar.gz

$(JHEAD_VER)/makefile: $(JHEAD_VER).tar.gz
	@tar -xf $(JHEAD_VER).tar.gz

$(JHEAD_VER)/jhead: $(JHEAD_VER)/makefile
	make -C $(JHEAD_VER)

$(VROOT)/usr/sbin/jhead: $(JHEAD_VER)/jhead
	install -d $(VROOT)/usr/sbin/
	install -m 755 $(JHEAD_VER)/jhead $(VROOT)/usr/sbin/

clean-src:
	rm -rf $(JHEAD_VER)

