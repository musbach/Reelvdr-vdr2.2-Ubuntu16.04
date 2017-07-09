#
# Makefile
#
# $Id$

VERSION = 1.6.1

ARCHIVE = skins
PACKAGE = xxv-$(ARCHIVE)-$(VERSION)
DEVPACKAGE = xxv-$(ARCHIVE)-devel-$(VERSION)
TMPDIR = /tmp/$(ARCHIVE)

### The name of the distribution archive:

SKINS = stone snow blue deltab lcars stone_flat snow_flat blue_flat lcars_flat xstyle
FILES = README COPYRIGHT HISTORY

all: devel full dist

dist: 
	@for i in $(SKINS); do $(MAKE) -C "./$$i" VERSION=$(VERSION) dist; done


full: 
	@mkdir -p $(TMPDIR)/$(PACKAGE)
	@for i in $(SKINS); do $(MAKE) -C "./$$i" TMPDIR=$(TMPDIR)/$(PACKAGE) VERSION=$(VERSION) full; done
	@for i in $(SKINS); do for j in $(FILES); do cp "$(TMPDIR)/$(PACKAGE)/$$i/$$j" $(TMPDIR)/$(PACKAGE); done; done
	@for i in $(SKINS); do for j in $(FILES); do rm -f "$(TMPDIR)/$(PACKAGE)/$$i/$$j" ; done; done
	@tar czf $(PACKAGE).tgz --exclude=.svn -C $(TMPDIR) $(PACKAGE)
	@echo Distribution package created as $(PACKAGE).tgz
	@rm -rf $(TMPDIR)


devel: 
	@mkdir -p $(TMPDIR)/$(PACKAGE)
	@for i in $(SKINS); do $(MAKE) -C "./$$i" TMPDIR=$(TMPDIR)/$(PACKAGE) VERSION=$(VERSION) devel; done
	@for i in $(SKINS); do for j in $(FILES); do cp "$(TMPDIR)/$(PACKAGE)/$$i/$$j" $(TMPDIR)/$(PACKAGE); done; done
	@for i in $(SKINS); do for j in $(FILES); do rm -f "$(TMPDIR)/$(PACKAGE)/$$i/$$j" ; done; done
	@cp Makefile $(TMPDIR)/$(PACKAGE)
	@tar czf $(DEVPACKAGE).tgz --exclude=.svn -C $(TMPDIR) $(PACKAGE)
	@echo Distribution package created as $(DEVPACKAGE).tgz
	@rm -rf $(TMPDIR)
