#
# Makefile for ReelBox packages
#
#


ifdef RBMINI
  TARGET = libapt-front-dev_0.4.0-0.2ubuntu1_armel.deb
else
  TARGET = libapt-front-dev_0.4.0-0.2ubuntu1_i386.deb
endif


#CXX="arm-linux-gnueabi-g++" 
#CC="arm-linux-gnueabi-gcc" 
#GCC="arm-linux-gnueabi-gcc"
#export CXX
#export CC
#export GCC

#$(TARGET): .root-copied
#$(TARGET): $(VROOT)/DEBIAN/conffiles
#$(TARGET): $(VROOT)/DEBIAN/changelog
#$(TARGET): $(VROOT)/DEBIAN/postinst
#$(TARGET): $(VROOT)/DEBIAN/postrm

all: $(TARGET)

$(TARGET):
	tar xzf libapt-front_0.4.0-0.2ubuntu1.tar.gz 
ifdef RBMINI
	cd libapt-front-0.4.0 && CXX="arm-linux-gnueabi-g++" CC="arm-linux-gnueabi-gcc" GCC="arm-linux-gnueabi-gcc" dpkg-buildpackage -aarmel -tarm-linux-gnueabi 
else
###	cd libapt-front-0.4.0_test && dpkg-buildpackage -tc -d && rm -rf libapt-front-0.4.0
	cp package.h libapt-front-0.4.0/apt-front/cache/entity/.
	cd libapt-front-0.4.0 && dpkg-buildpackage -tc -d && rm -rf libapt-front-0.4.0
endif
	cp -a *.deb ../


clean: clean-workdir

clean-workdir:
	-rm -f rm -r libapt-front-0.4.0 libapt-front_0.4.0-0.2ubuntu1.dsc libapt-front-dev_0.4.0-0.2ubuntu1_armel.deb  libapt-front_0.4.0-0.2ubuntu1_armel.changes
	-rm -f $(TARGET) *.changes
