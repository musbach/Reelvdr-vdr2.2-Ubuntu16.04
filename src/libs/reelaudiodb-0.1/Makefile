
PRINT_TAG=print_tag.out

MEDIACLEANER=MediaCleaner
MEDIACRAWLER=MediaCrawler
MEDIAANALYZER=MediaAnalyzer
MEDIAREMOVER=MediaRemover

LIBSEARCHAPI=libreelsearchapi.so

CXX=ccache g++
#CXX=g++
###CXXOPTS=-ggdb3 -pg -Wall -fPIC
###CXXOPTS=-ggdb3 -pg -Wall -fPIC -O2 -funroll-loops -fomit-frame-pointer -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE 
CXXOPTS=-ggdb3 -pg -Wall -fPIC -O2 -funroll-loops -m32 -march=pentium3 -mmmx -msse -mfpmath=sse -Wall -Woverloaded-virtual -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE 

MAKEDEP = $(CXX) -MM -MG
DEPFILE = .dependencies


#LIBS += -lrt -ljpeg -ltag -lmagic
#LIBS += -lrt -ljpeg -ltag -lpthread -I/usr/lib/i386-linux-gnu/libmagic.so.1 -I/lib/i386-linux-gnu/libpthread.so.0
LIBS += -lrt -ljpeg -ltag -lpthread -I/usr/lib/i386-linux-gnu/libmagic.so.1 -I/lib/i386-linux-gnu/libpthread.so.0
#LIBS += -lrt -ljpeg -ltag -I/usr/lib/i386-linux-gnu/libmagic.so.1
INCLUDES=-I/usr/include/taglib

DEFINES=-D_GNU_SOURCE

OBJS= analyzer.o crawler.o database.o thread.o databasereader.o databasewriter.o tools.o searchapi.o databasecleaner.o databaseschema.o query.o createdatabaseinstance.o sqlutils.o

default: all

MYSQL=1
SQLITE=1

ifdef MYSQL
OBJS+=mysqldatabase.o
LIBS+=-lmysqlclient_r
endif

ifdef SQLITE
OBJS+=sqlitedatabase.o
LIBS+=-lsqlite3
endif

-include $(DEPFILE)

all: $(LIBSEARCHAPI) $(MEDIAANALYZER) $(MEDIACLEANER) $(MEDIACRAWLER) $(MEDIAREMOVER)

test: 
	make -C test all

%.o: %.c
	$(CXX) $(CXXOPTS) $(DEFINES)  -c  $(INCLUDES) -o $@ $<

# Dependencies:
$(DEPFILE): Makefile
	@$(MAKEDEP) $(INCLUDES) $(DEFINES)  $(OBJS:%.o=%.c) > $@


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

$(LIBSEARCHAPI): searchapi.o database.o databasereader.o mysqldatabase.o sqlitedatabase.o thread.o query.o tools.o createdatabaseinstance.o  databaseschema.o sqlutils.o
	$(CXX) -shared $(CXXOPTS) -o $@ $^ $(LIBS)

clean: clean-tests
	@-rm -f -- *.o *.out *.so *.a
	@-rm  -- $(DEPFILE)
	@-rm -f Media*

clean-tests:
	make -C tests clean
