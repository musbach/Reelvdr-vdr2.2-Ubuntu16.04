
PRINT_TAG=print_tag.out

MEDIACLEANER=MediaCleaner
MEDIACRAWLER=MediaCrawler
MEDIAANALYZER=MediaAnalyzer
MEDIAREMOVER=MediaRemover

LIBSEARCHAPI=libreelsearchapi.so

CXX=ccache g++
#CXX=g++
###CXXOPTS=-ggdb3 -pg -Wall -fPIC
CXXOPTS ?= -O2 -Wall -Woverloaded-virtual -Wextra
CXXOPTS=-ggdb3 -pg -Wall -fPIC -O2 -funroll-loops -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE

### Allow user defined options to overwrite defaults:

VDRDIR=../..

include $(VDRDIR)/Make.config
#include $(VDRDIR)/Make.common



MAKEDEP = $(CXX) -MM -MG
DEPFILE = .dependencies


#LIBS=-lrt -ljpeg -ltag -lmagic
#LIBS=-lrt -ljpeg -ltag -I/usr/lib/i386-linux-gnu/libmagic.so.1 -I/lib/i386-linux-gnu/libpthread.so.0
LIBS=-lrt -ljpeg -ltag -I/usr/lib/i386-linux-gnu/libmagic.so.1 -I/lib/i386-linux-gnu/libpthread-2.11.1.so
#INCLUDES=-I/usr/include/taglib -I/usr/lib/i386-linux-gnu/libmagic.so.1 -I/lib/i386-linux-gnu/libpthread.so.0
INCLUDES=-I/usr/include/taglib 


OBJS= analyzer.o crawler.o database.o thread.o databasereader.o databasewriter.o tools.o searchapi.o databasecleaner.o databaseschema.o query.o createdatabaseinstance.o

default: all

MYSQL=1
SQLITE=1

ifdef MYSQL
OBJS+=mysqldatabase.o
#LIBS+=-lmysqlclient_r
LIBS+=-lmysqlclient
endif

ifdef SQLITE
OBJS+=sqlitedatabase.o
LIBS+=-lsqlite3
endif
LIBS-="-lpthread" ./configure
LIBS+="-lpthread"

-include $(DEPFILE)

all: $(LIBSEARCHAPI) $(MEDIAANALYZER) $(MEDIACLEANER) $(MEDIACRAWLER) $(MEDIAREMOVER)

test: 
	make -C test all

%.o: %.c
	$(CXX) $(CXXOPTS) -c  $(INCLUDES) -o $@ $<

# Dependencies:
$(DEPFILE): Makefile
	@$(MAKEDEP) $(INCLUDES) $(OBJS:%.o=%.c) > $@


$(MEDIAANALYZER): analyzer_daemon.o $(OBJS)
	$(CXX) $(CXXOPTS) -o $@ $^ $(LIBS)

$(MEDIACLEANER): databasecleaner_test.o $(OBJS)
	$(CXX) $(CXXOPTS) -o $@ $^ $(LIBS)

$(MEDIACRAWLER): crawler_test.o $(OBJS)
	$(CXX) $(CXXOPTS) -o $@ $^ $(LIBS)

$(MEDIAREMOVER): removedirectorytree.o $(OBJS)
	$(CXX) $(CXXOPTS) -o $@ $^ $(LIBS)

$(PRINT_TAG): print_tags.o
	$(CXX) $(CXXOPTS) -o $@ $^ -ltag -I /usr/include/taglib

$(LIBSEARCHAPI): searchapi.o database.o databasereader.o mysqldatabase.o sqlitedatabase.o thread.o query.o tools.o createdatabaseinstance.o  databaseschema.o
	$(CXX) -shared $(CXXOPTS) -o $@ $^ $(LIBS)

clean: clean-tests
	@-rm -f -- *.o *.out *.so *.a
	@-rm  -- $(DEPFILE)
	@-rm -f Media*

clean-tests:
	make -C tests clean
