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
#$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/prerm
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

clean: target-clean

# put any needed Makefile directives here
# add dependency for these targets to "all:"
# Example:
# all: myrule
# myrule:
# 	do_something

target-clean:
	-$(MAKE) -C $(src) clean
