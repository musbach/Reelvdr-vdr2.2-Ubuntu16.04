# how to build
swig `pkg-config --cflags libtagcoll libapt-front` -I/usr/include -python -c++ aptfront.i

g++ -c aptfront_wrap.cxx -I/usr/include/python2.4 `pkg-config --cflags libtagcoll libapt-front`
g++ -shared aptfront_wrap.o -o _aptfront.so `pkg-config --libs libapt-front libtagcoll` -lrt
