afdir = $(includedir)/apt-front
afwdir = $(afdir)/workarounds
afudir = $(afdir)/utils
afpdir = $(afdir)/predicate
afcdir = $(afdir)/cache
afccdir = $(afcdir)/component
afccddir = $(afcdir)/component/debtags
afcedir = $(afcdir)/entity

af_HEADERS = manager.h progresscallback.h init.h error.h \
    forward.h actor.h sources.h workarounds.h gettext.h
afw_HEADERS = workarounds/policy.h
afu_HEADERS = utils/shared.h utils/cast.h utils/typeset.h \
    utils/multitype.h utils/consumer.h utils/range.h \
    utils/prettyprint.h  utils/paths.h \
    utils/desktopfile.h utils/comparable.h
#./apt-front/utils/Regexp.h
afp_HEADERS = predicate/predicate.h predicate/matchers.h \
    predicate/combinators.h predicate/factory.h
afc_HEADERS = cache/cache.h cache/observer.h
afcc_HEADERS = cache/component/packages.h \
    cache/component/records.h cache/component/packagetags.h \
    cache/component/state.h cache/component/history.h \
    cache/component/desktop.h \
    cache/component/base.h
afce_HEADERS = cache/entity/package.h cache/entity/version.h \
    cache/entity/entity.h cache/entity/relation.h cache/entity/desktop.h

BUILT_SOURCES = utils/paths.cpp.h

lib_LTLIBRARIES = libapt-front.la
libapt_front_la_SOURCES = \
    sources.cpp \
    utils/consumer.cpp \
    utils/range.cpp \
    utils/paths.cpp \
    utils/desktopfile.cpp \
    manager.cpp \
	error.cpp \
	init.cpp \
	progresscallback.cpp \
	predicate/predicate.cpp \
	predicate/matchers.cpp \
	cache/cache.cpp \
	cache/observer.cpp \
	cache/component/base.cpp \
	cache/component/packages.cpp \
	cache/component/records.cpp \
	cache/component/packagetags.cpp \
	cache/component/state.cpp \
	cache/component/history.cpp \
	cache/component/desktop.cpp \
	cache/entity/entity.cpp \
	actor.cpp \
	cache/entity/package.cpp \
	cache/entity/version.cpp \
	cache/entity/relation.cpp \
	cache/entity/desktop.cpp

utils/paths.cpp.h: $(srcdir)/utils/paths.cpp.h.in Makefile
	mkdir -p utils
	sed \
		-e 's#\@DEBTAGS_DB_DIR\@#"$(debtagsdbdir)"#' \
		-e 's#\@DEBTAGSCONFIGDIR\@#"$(debtagsconfdir)"#' \
		-e 's#\@DEBTAGSDOWNLOADDIR\@#"$(debtagsdownloaddir)"#' \
		-e 's#\@DEBTAGSDATADIR\@#"$(debtagsdatadir)"#' \
		< $< > $@

libapt_front_la_LIBADD = -lapt-pkg $(INTLLIBS) $(LIBEPT_LIBS) $(LIBTAGCOLL2_LIBS) $(LIBWIBBLE_LIBS) -lrt libupdater.la
libapt_front_la_LDFLAGS = -no-undefined
libapt_front_la_CXXFLAGS = -I$(top_srcdir)/tests/ -I$(top_srcdir) -DTEST_DIR=\"`pwd`/$(top_builddir)/tests/data/\" $(LIBEPT_CFLAGS) $(LIBTAGCOLL2_CFLAGS) $(LIBWIBBLE_LIBS)
#libapt_front_la_CXXFLAGS = -I$(top_srcdir)/tests/ -I$(top_srcdir) -DCOMPILE_TESTSUITE -DTEST_DIR=\"`pwd`/$(top_builddir)/tests/data/\" $(LIBTAGCOLL2_CFLAGS)

noinst_LTLIBRARIES = libupdater.la
libupdater_la_SOURCES = updater.cpp
libupdater_la_CXXFLAGS = -I$(top_srcdir)/tests/ -I$(top_srcdir) -DTEST_DIR=\"`pwd`/$(top_builddir)/tests/data/\" $(LIBEPT_CFLAGS) $(LIBTAGCOLL2_CFLAGS) $(LIBWIBBLE_LIBS)
#libupdater_la_CXXFLAGS = -I$(top_srcdir)/tests/ -I$(top_srcdir) -DCOMPILE_TESTSUITE -DTEST_DIR=\"`pwd`/$(top_builddir)/tests/data/\" $(LIBEPT_CFLAGS)

EXTRA_DIST = utils/paths.cpp.h.in updater.h

# vim:set ts=4 sw=4:
