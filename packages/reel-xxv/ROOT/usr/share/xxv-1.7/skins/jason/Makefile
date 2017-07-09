#
# jason - Javascript based skin for xxv
# Copyright(c) 2008-2012, anbr
#
# http://projects.vdr-developer.org/projects/xxv
#
#

include files.lst

#all.js: $(FILES)
#	cat $(FILES) > all.tmp

#alljs: all.js
#	java -jar ./temp/yuicompressor-2.4.2/build/yuicompressor-2.4.2.jar --line-break 80 --nomunge --type js all.tmp > all.js


SKIN = $(shell basename `pwd`)
VERSION = 1.6.1

### The name of the distribution archive:

ARCHIVE = $(SKIN)
PACKAGE = xxv-$(ARCHIVE)-$(VERSION)
TMPDIR = /tmp

### Targets:

all: dist

dist: clean preparepkg copy removedevel postpkg
	@tar czfh ../$(PACKAGE).tgz --exclude=.svn -C $(TMPDIR) $(ARCHIVE) 
	@echo Distribution package created as $(PACKAGE).tgz
	@-rm -rf $(TMPDIR)/$(ARCHIVE)

preparepkg:
	@-rm -rf $(TMPDIR)/$(ARCHIVE)

copy:
	@svn export . $(TMPDIR)/$(ARCHIVE)

full: clean preparepkg copy removedevel postpkg

devel: clean preparepkg copy postpkg 

removedevel:
	@-rm -f $(TMPDIR)/$(ARCHIVE)/Makefile
	@-rm -rf $(TMPDIR)/$(ARCHIVE)/artwork

postpkg:
	@find $(TMPDIR)/$(ARCHIVE) -type d -exec chmod 755 {} \;
	@find $(TMPDIR)/$(ARCHIVE) -type f -exec chmod 644 {} \;
	@chown root.root -R $(TMPDIR)/$(ARCHIVE)/*


backup: clean
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@mkdir -p $(TMPDIR)/$(ARCHIVE)
	@cp -a * $(TMPDIR)/$(ARCHIVE)
	@-rm -f $(TMPDIR)/$(ARCHIVE)/xxv-$(ARCHIVE)-*.tgz
	@find $(TMPDIR)/$(ARCHIVE) -type d -exec chmod 755 {} \;
	@find $(TMPDIR)/$(ARCHIVE) -type f -exec chmod 644 {} \;
	@chown root.root -R $(TMPDIR)/$(ARCHIVE)/*
	@tar czf ../$(PACKAGE).tgz --exclude=.svn -C $(TMPDIR) $(ARCHIVE) 
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@echo Backup package created as $(PACKAGE).tgz

clean:
	@-find -name "*~" -print -exec rm -f {} \;
	@-rm -f *~ all.tmp all.js
	@-rm -f $(PACKAGE).tgz
