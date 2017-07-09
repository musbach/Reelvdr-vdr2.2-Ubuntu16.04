#
# Makefile
#
# $Id$

SKIN = xstyle
VERSION = 1.6.1

### The name of the distribution archive:

ARCHIVE = $(SKIN)
PACKAGE = xxv-$(ARCHIVE)-$(VERSION)
TMPDIR = /tmp

### Targets:

all: dist

dist: clean preparepkg copyfollow removedevel postpkg
	@tar czfh ../$(PACKAGE).tgz --exclude=.svn -C $(TMPDIR) $(ARCHIVE) 
	@echo Distribution package created as $(PACKAGE).tgz
	@-rm -rf $(TMPDIR)/$(ARCHIVE)

preparepkg:
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@mkdir -p $(TMPDIR)/$(ARCHIVE)

copyfollow:
	@cp -LpR * $(TMPDIR)/$(ARCHIVE)

copylinks:
	@cp -a * $(TMPDIR)/$(ARCHIVE)

full: clean preparepkg copylinks removedevel postpkg

devel: clean preparepkg copylinks postpkg 

removedevel:
	@-rm -f $(TMPDIR)/$(ARCHIVE)/Makefile

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
	@-rm -f $(PACKAGE).tgz
