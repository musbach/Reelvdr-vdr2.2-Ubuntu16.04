#
# Makefile
#
# $Id$

XXV = xxv
VERSION = 1.6.1

### The name of the distribution archive:

ARCHIVE = $(XXV)-$(VERSION)
PACKAGE = $(ARCHIVE)
TMPDIR = /tmp

### The subdirectories:

### Targets:
EXCLUDE = "*~" "*.bak" "*.org" "*.diff" "xxvd.pid" "$(XXV)-*.tgz"


clean:
	@for i in $(EXCLUDE) ;\
	do \
	    find -name "$$i" -exec rm -rf "{}" \; \
	|| exit 1;\
	done

tmpfolder:
	@-rm -rf $(TMPDIR)/$(ARCHIVE)

copyfiles:
	@svn export . $(TMPDIR)/$(ARCHIVE)


removefiles:
	@for i in $(EXCLUDE) ;\
	do \
	    find $(TMPDIR)/$(ARCHIVE) -name "$$i" -exec rm -f "{}" \; \
	|| exit 1;\
	done
	@for i in $(EXCLUDEFOLDER) ;\
	do \
	    find "$(TMPDIR)/$(ARCHIVE)/$$i" -exec rm -rf "{}" \; \
	|| exit 1;\
	done

updateversion:
	@sed -e "s/__VERSION__/$(VERSION)/g" bin/xxvd > $(TMPDIR)/$(ARCHIVE)/bin/xxvd

DBTABLES = $(shell cat ./contrib/update-xxv | grep tables= | cut -d '=' -f 2 | sed -e s/\'//g;)
updatesql:
	@echo Please type the DB-Password for root:
	@mysqldump --add-drop-table=FALSE --set-charset=FALSE -u root -p -n -d xxv $(DBTABLES) -r $(TMPDIR)/$(ARCHIVE)/contrib/upgrade-xxv-db.sql
	@sed -e "s/CREATE TABLE/CREATE TABLE IF NOT EXISTS/g" -e "s/\ ENGINE=MyISAM.*;/;/g" $(TMPDIR)/$(ARCHIVE)/contrib/upgrade-xxv-db.sql > ./contrib/upgrade-xxv-db.sql

setpermission:
	@find $(TMPDIR)/$(ARCHIVE) -type d -exec chmod 755 {} \;
	@find $(TMPDIR)/$(ARCHIVE) -type f -exec chmod 644 {} \;
	@chmod a+x $(TMPDIR)/$(ARCHIVE)/bin/xxvd
	@chmod a+x $(TMPDIR)/$(ARCHIVE)/contrib/update-xxv
	@chmod a+x $(TMPDIR)/$(ARCHIVE)/contrib/at-vdradmin2xxv.pl
	@chmod a+x $(TMPDIR)/$(ARCHIVE)/locale/xgettext.pl
	@chmod a+x $(TMPDIR)/$(ARCHIVE)/etc/xxvd
	@chmod a+x $(TMPDIR)/$(ARCHIVE)/install.sh
	@chmod a+x $(TMPDIR)/$(ARCHIVE)/install-debian.sh

dist: tmpfolder\
    copyfiles\
    removefiles\
    updateversion\
    setpermission
	@chown root.root -R $(TMPDIR)/$(ARCHIVE)/*
	@tar czf $(PACKAGE).tgz --exclude=.svn -C $(TMPDIR) $(ARCHIVE)
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@echo Distribution package created as $(PACKAGE).tgz

all: dist
