TESTS = libapt-front-check
check_PROGRAMS = libapt-front-test
check_SCRIPTS = libapt-front-check
libapt_front_test_SOURCES = tut-main.cpp
libapt_front_test_LDADD  = -dlpreopen ../apt-front/libapt-front.la
noinst_HEADERS = test-utils.h

listfile = ftp.sk.debian.org_debian_dists_unstable_main_binary-i386_Packages
url = http://pdx.freedesktop.org/~mornfall/libapt-front/testdata

check-am: data-stamp

data-stamp:
	mkdir -p data/state/lists/
	mkdir -p data/etc
	mkdir -p data/state
	mkdir -p data/cache
	mkdir -p data/debtags/tags
	mkdir -p data/state/lists/partial
	mkdir -p data/cache/archives/partial
	mkdir -p data/desktop
	sed -e "s|SOURCE|`(cd $(top_builddir)/tests/data/debtags/tags; pwd)`/|" \
		< $(srcdir)/data/debtags/sources.list.in > data/debtags/sources.list
	gzip -c $(srcdir)/data/debtags/tags/package-tags > data/debtags/tags/tags-current.gz
	gzip -c $(srcdir)/data/debtags/tags/vocabulary > data/debtags/tags/vocabulary.gz
	-cp -a $(srcdir)/data/packagelist data/state/lists/$(listfile)
	-cp -a $(srcdir)/data/dpkg-status data/dpkg-status
	-cp -a $(srcdir)/data/etc/sources.list data/etc/
	-cp -a $(srcdir)/data/desktop/*.desktop data/desktop/
	touch data-stamp

CLEANFILES = data-stamp data/debtags/sources.list data/debtags/tags/tags-current.gz data/debtags/tags/vocabulary.gz \
	     data/debtags/package-tags.idxpkg data/debtags/package-tags.idxtag data/debtags/vocabulary.idx \
	     data/debtags/people.debian.org_\%7eenrico_tags_tags-current.gz \
	     data/debtags/people.debian.org_\%7eenrico_tags_vocabulary.gz \
	     data/state/lists/ftp.sk.debian.org_debian_dists_unstable_main_binary-i386_Packages \
	     tests/data/cache/srcpkgcache.bin tests/data/cache/pkgcache.bin

EXTRA_DIST = download data data/debtags
