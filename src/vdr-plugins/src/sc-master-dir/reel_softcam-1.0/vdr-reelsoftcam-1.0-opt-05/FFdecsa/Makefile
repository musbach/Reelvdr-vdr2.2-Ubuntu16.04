##### compiling with g++ gives a little more speed
#COMPILER=gcc
#COMPILER=g++

###there are two functions which apparently don't want to be inlined
#FLAGS=-O3 -march=athlon-xp -fexpensive-optimizations -funroll-loops -finline-limit=6000000 --param max-unrolled-insns=500
#FLAGS=-O3 -march=athlon-xp -fexpensive-optimizations -funroll-loops --param max-unrolled-insns=500
#FLAGS=-O3 -march=pentium3 -fexpensive-optimizations -funroll-loops
#FLAGS=-O3 -march=pentium3 -fexpensive-optimizations -funroll-loops -march=pentium3 -mmmx -msse -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE
FLAGS= -O2 -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -fno-strict-aliasing  -shared -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE

###icc crashes for unknown reasons
#COMPILER=/opt/intel_cc_80/bin/icc
#FLAGS=-O3 -march=pentiumiii

#FLAGS += -g
#FLAGS += -fno-alias
#FLAGS += -vec_report3
#FLAGS += -Wall -Winline
#FLAGS += -fomit-frame-pointer 
#FLAGS += -pg

COMPILER ?= g++
#FLAGS ?= -Wall -fPIC -O3 -march=pentium3 -mmmx -fomit-frame-pointer -fexpensive-optimizations -funroll-loops
#FLAGS ?= -Wall -fPIC -pg -O2 -march=pentium3 -mmmx -fomit-frame-pointer -fexpensive-optimizations  -funroll-loops -Woverloaded-virtual -Wno-parentheses -m32 -msse -mfpmath=sse
#FLAGS ?= -Wall -fPIC -O2 -march=pentium3 -mmmx -fomit-frame-pointer -fexpensive-optimizations  -funroll-loops -Woverloaded-virtual -Wno-parentheses -m32 -msse -mfpmath=sse
#FLAGS = -Wall         -O2 -march=pentium3 -mmmx                                                                -Woverloaded-virtual -Wno-parentheses -m32 -msse -mfpmath=sse
#FLAGS ?= -Wall -fPIC -O3 -march=pentium3 -mmmx -fomit-frame-pointer -fexpensive-optimizations -funroll-loops
#FLAGS = -fPIC -pg -O2 -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -c -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -DDVBAPI_V5 -DNEW_FFMPEG -DNEWUBUNTU -DREELVDR -DUSEMYSQL -DDEVICE_ATTRIBUTES -DUSE_CRASHLOG -DUSE_CUTTERLIMIT -DUSE_CUTTIME -DUSE_JUMPPLAY -DUSE_LIEMIEXT -DUSE_MCLI -DUSE_NOEPG -DUSE_PINPLUGIN -DUSE_PLUGINMISSING -DUSE_SETUP -DUSE_TTXTSUBS -DUSE_YAEPG -DUSE_BOUQUETS -DUSE_DELAYED_TRICKMODE -DUSE_LIVEBUFFER -DUSE_PROVIDERCHARSET=1 -DREMOTE_KBD -DREMOTE_LIRC
#PARALLEL_MODE ?= PARALLEL_032_INT
#PARALLEL_MODE ?= PARALLEL_128_SSE

H_FILES = FFdecsa.h parallel_generic.h parallel_std_def.h fftable.h \
          parallel_032_4char.h \
          parallel_032_int.h \
          parallel_064_2int.h \
          parallel_064_8charA.h \
          parallel_064_8char.h \
          parallel_064_long.h \
          parallel_064_mmx.h \
          parallel_128_16charA.h \
          parallel_128_16char.h \
          parallel_128_2long.h \
          parallel_128_2mmx.h \
          parallel_128_4int.h \
          parallel_128_sse2.h \
          parallel_128_sse.h

all: FFdecsa.o FFdecsa_test.done

%.o: %.c
	$(COMPILER) $(FLAGS) -DPARALLEL_MODE=$(PARALLEL_MODE) -c $<

FFdecsa_test:	FFdecsa_test.o FFdecsa.o
	$(COMPILER) $(FLAGS) -o FFdecsa_test FFdecsa_test.o FFdecsa.o

FFdecsa_test.o: FFdecsa_test.c FFdecsa.h FFdecsa_test_testcases.h
FFdecsa.o: 	FFdecsa.c stream.c $(H_FILES)

FFdecsa_test.done: FFdecsa_test
	@./FFdecsa_test
	@touch FFdecsa_test.done

clean:
	@rm -f FFdecsa_test.o FFdecsa.o FFdecsa_test FFdecsa_test.done

test:	FFdecsa_test
	sync;usleep 200000;nice --19 ./FFdecsa_test
