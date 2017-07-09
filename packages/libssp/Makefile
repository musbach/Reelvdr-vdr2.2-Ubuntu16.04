#
# Makefile for ReelBox packages
#
#

include ../Make.common

export SRCDIR

# uncomment if you need conffiles, postinst etc. included

$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
#$(TARGET): $(VROOT)/DEBIAN/preinst
$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/prerm
$(TARGET): $(VROOT)/DEBIAN/postrm


# put any needed Makefile directives here
# add dependency for these targets to "all:"
# Example:
# all: myrule
# myrule:
# 	do_something

all: $(TARGET)


#clean: target-clean

target-clean:
	-$(MAKE) -C $(src) clean
