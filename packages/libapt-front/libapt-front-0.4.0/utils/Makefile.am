noinst_PROGRAMS = apt-cat apt-grep

apt_cat_SOURCES = apt-cat.cpp
apt_cat_LDADD  = ../apt-front/libapt-front.la $(LIBEPT_LIBS) $(LIBTAGCOLL2_LIBS) $(LIBWIBBLE_LIBS)
apt_grep_SOURCES = apt-grep.cpp
apt_grep_LDADD  = ../apt-front/libapt-front.la $(LIBEPT_LIBS) $(LIBTAGCOLL2_LIBS) $(LIBWIBBLE_LIBS)

#INCLUDES = $(LIBEPT_CFLAGS) $(LIBTAGCOLL2_CFLAGS) $(LIBWIBBLE_CFLAGS) -I$(top_srcdir)
CPPFLAGS = $(LIBEPT_CFLAGS) $(LIBTAGCOLL2_CFLAGS) $(LIBWIBBLE_CFLAGS) -I$(top_srcdir)
