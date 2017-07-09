## Process this file with automake to produce Makefile.in

#noinst_DATA = html/index.html libapt-front.doxytags

libapt-front.doxytags: libapt-front.dox $(top_builddir)/apt-front/libapt-front.la
	doxygen $<

html/index.html: libapt-front.dox $(top_builddir)/apt-front/libapt-front.la
	doxygen $<
	chmod a+rX -R html/

EXTRA_DIST = libapt-front.dox

CLEANFILES = libapt-front.doxytags

clean-local:
	rm -rf html
