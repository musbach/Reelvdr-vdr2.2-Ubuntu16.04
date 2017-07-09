#!/usr/bin/env python
import os
import sys
import aptfront

aptfront.init()

class TagsScorer(aptfront.DebtagsConsumer):
    def __init__(self):
        aptfront.DebtagsConsumer.__init__(self)
        self.scores = {}
        self.ignore = aptfront.Expression("special::not-yet-tagged*")
    
    def consumeItemUntagged(self, *args): pass
    def consumeItmesUntaggged(self, *args): pass
    def consumeItem(self, item, tags):
        if item.isInstalled() or item.isUpgradable() or item.isBroken():
            for t in tags:
                ts = aptfront._OpSet_T()
                ts += t
                if not self.ignore.apply(ts):
                    try:
                        self.scores[t.fullname()] += 1
                    except KeyError:
                        self.scores[t.fullname()] = 1


    
class PackageScorer(aptfront.DebtagsConsumer):
    def __init__(self, scores):
        aptfront.DebtagsConsumer.__init__(self)
        self.scores = scores.scores
        self.pkgscores = []
        
    def consumeItemUntagged(self, *args): pass
    def consumeItemsUntagged(self, *args): pass

    def consumeItem(self, item, tags):
        if item.valid() and not (item.isInstalled() or item.isUpgradable() or item.isBroken()):
            score = 0
            for t in tags:
                score += self.scores.get(t.fullname(), 0)
            self.pkgscores.append((score, pkgcopy(item)))

            
class TagcollChecker(aptfront.Consumer_s_s):
    def __init__(self):
        aptfront.Consumer_s_s.__init__(self)
        self.voc = aptfront.getCache().tags()
        self.missing_count = 0
        self.mtag_width = 0
        self.max_missing = 0
        self.missing = {}

    def consumeItemUntagged(*args): pass
    def consumeItemsUntagged(*args): pass
    
    def consumeItem(self, item, tags):
        for t in tags:
            self.checkTag(t)

    def consumeItems(self, items, tags):
        for t in tags:
            self.checkTag(t)

    def checkTag(self, tag):
        if not self.voc.hasTag(tag):
            self.missing_count += 1
            try:
                self.missing[tag] += 1
            except KeyError:
                self.missing[tag] = 1
            if len(tag) > self.mtag_width:
                self.mtag_width = len(tag)
            if self.missing[tag] > self.max_missing:
                self.max_missing = self.missing[tag]

    def report(self):
        if self.missing_count > 0:
            print "%i tags were found in packages but not in the vocabulary" % (len(self.missing), )
            print "This happened %i times" % (self.missing_count, )
            print "The tags found in the collection but not in the vocabulary are:"
            for name, times in self.missing.iteritems():
                print name, "(in", times, "packages)"


def readConvCollection(toitem, totag, filename, output):
    if filename == "-":
        input = aptfront.StdioParserInput(sys.stdin, "<stdin>")
        aptfront.DebtagsTextFormat_parse(toitem, totag, input, output)
    else:
        input = aptfront.StdioParserInput(filename);
        aptfront.DebtagsTextFormat_parse(toitem, totag, input, output)


def readCollection(filename, output):
    conv = aptfront.Converter_s_s()    
    if filename == "-":
        input = aptfront.StdioParserInputer(sys.stdin, "<stdin>")
        aptfront.TextFormat_s_s_parse(conv, conv, input, output)
    else:
        input = aptfront.StdioParserInput(filename)
        aptfront.TextFormat_s_s_parse(conv, conv, input, output)


class SubstringTagMatcher(object):
    def __init__(self):
        self.patterns = []

    def match(self, item):
        for p in self.patterns:
            if p in getattr(item, "fullname", item.name)():
                return True
        
            if p in item.shortDescription():
                return True

            if p in item.longDescription():
                return True
        
        return False


class MaintPrinter(aptfront.Consumer_s_T):
    def consumeItemUntagged(self, string):
        print string

    def consumeItem(self, string, tags):
        print "%s: %s" % (string,
                          ", ".join([t.fullname() for t in tags]))

        
class PackagePrinter(aptfront.DebtagsConsumer):
    def __init__(self, blacklist = []):
        aptfront.DebtagsConsumer.__init__(self)
        self.blacklist = blacklist
        
    def consumeItem(self, pkg, opset):
        self.consume(pkg)

    def consumeItemUntagged(self, pkg):
        if pkg in self.blacklist:
            return
        print "%s - %s" % (pkg.name(),
                           pkg.shortDescription("(short description not available)"))

    def print_(self, pkgs):
        self.consume(pkgs)


class TagPrinter(aptfront.DebtagsConsumer):
    def consumeItem(self, pkg, opset):
        print "%s: %s" % (pkg.name(),
                          ", ".join([t.fullname() for t in pkg.tags()]))


    def consumeItemUntagged(self, pkg):
        print pkg.name()


def pkgcopy(pkg):
    # XXX: figure out how to wrap copy ctor of entity::Package
    return aptfront.Package(aptfront.getCache(), pkg.pkgPtr())


class ItemAdder(aptfront.DebtagsConsumer):
    def __init__(self):
        aptfront.Consumer_P_T.__init__(self)
        self.targets = []
        
    def consumeItem(self, item, tags):
        self.targets.append(pkgcopy(item))
        
    def consumeItemUntagged(self, item):
        self.targets.append(pkgcopy(item))


def printVocabularyItem(item):
    w = getattr(item, "fullname", item.name)
    print """Tag: %s
Description: %s
 %s
""" % (w(), item.shortDescription(), item.longDescription())


def printShortVocabularyItem(item):
    if not hasattr(item, "fullname"):
        name = "%s (facet)" % (item.name(),)
    else:
        name = item.fullname()
    print "%s - %s" % (name, item.shortDescription())


class Commands(object):
    def openCache(self, writeAccess = False):
        if writeAccess:
            flags = aptfront.Cache.OpenDefault 
        else:
            flags = aptfront.Cache.OpenDefault | \
                    aptfront.Cache.OpenReadOnly
        self.cache = aptfront.getCache()
        self.cache.open(flags)


    def openDebtags(self):
        self.openCache()
        return self.cache.debtags()
    
    # commands
    def cat(self, *args):
        dt = self.openDebtags()
        dt.outputPatched(TagPrinter())


    def search(self, *args):
        self.openCache()
        assert len(args) == 1, "'search' needs one argument"
        dt = self.openDebtags()
        out = PackagePrinter()
        m = aptfront.DebtagsFilterItemsByExpression(out, args[0])
        dt.outputPatched(m)


    def grep(self, *args):
        assert len(args) == 1, "'grep' needs one argument"
        dt = self.openDebtags()
        t = TagPrinter() #XXX: how to steal reference to tagprinter?
        filter = aptfront.DebtagsFilterItemsByExpression(t, args[0])
        dt.outputPatched(filter)

        
    def install(self, *args):
        self.openCache(writeAccess = True)
        dt = self.cache.debtags()
        adder = ItemAdder()
        m = aptfront.DebtagsFilterItemsByExpression(adder, args[0])
        dt.outputPatched(m)
        for pkg in adder.targets:
            pkg.markInstall()
            
        m = aptfront.Manager(aptfront.getCache())
        m.download()
        m.commit()

        
    def tagcat(self, *args):
        self.openCache()
        for facet in self.cache.tags().facets():
            printVocabularyItem(facet)
            for tag in facet.tags():
                printVocabularyItem(tag)


    def tagshow(self, *args):
        assert len(args) == 1, "'tagsearch' needs on argument"
        self.openCache()
        tag = self.cache.tags().tagByName(args[0])
        if tag.valid():
            printVocabularyItem(tag)
        else:
            print "Tag '%s' was not found in vocabulary data." % (args[0],)


    def tagsearch(self, *args):
        assert len(args) > 0
        self.openCache()
        matcher = SubstringTagMatcher()
        matcher.patterns = args
        for facet in self.cache.tags().facets():
            if matcher.match(facet):
                printShortVocabularyItem(facet)
            for tag in facet.tags():
                if matcher.match(tag):
                    printShortVocabularyItem(tag)


    def show(self, *args):
        dt = self.openDebtags()
        for name in args:
            pkg = self.cache.packages().packageByName(name)
            if pkg.valid():
               print pkg.candidateVersion().completeRecord()
               tags = dt.tagdb().getTags(pkg)
               print "Tags: %s" % (", ".join([tag.fullname() for tag in tags]),)
            else:
                print "Package '%s' not found" % (name, )


    def related(self, *args):
        assert len(args) == 1, "'related' needs on argument"
        dt = self.openDebtags()
        # TODO: add maxdist argument
        maxdist = 1
        pkgs = []
        for name in args[0].split(","):
            pkg = self.cache.packages().packageByName(name.strip())
            assert pkg.valid(), "'%s' does not exist in collection" % (name,)
            pkgs.append(pkg)
        # get the intersection of the tagsets of all packages in pkgs
        from operator import xor
        ts = reduce(xor, [p.tags() for p in pkgs])
        if ts.empty():
            # TODO: add error messages
            print "give me an error msg!"
            return
        
        printer = PackagePrinter(pkgs)
        related = dt.tagdb().getRelatedItems(ts, maxdist)
        printer.print_(related)
    

    def check(self, *args):
        dt = self.openDebtags()
        if len(args) == 0:
            filename = aptfront.Path_tagdb()
        else:
            filename = args[0]
        checker = TagcollChecker()

        readCollection(filename, checker)
        if checker.missing_count > 0:
            checker.report()
            return 1
        else:
            return 0

        
    def update(self, *args):
        assert os.geteuid() == 0, "You must be root to update the system database"
        # TODO: progress for download
        prev_umask = os.umask(022)
        aptfront.updateDatabase()
        os.umask(prev_umask)
        print "Done."


    def mkpatch(self, *args):
        assert len(args) == 1, "no filename specified"
        dt = self.openDebtags()
        filename = args[0]
        coll = aptfront.DebtagsInputMerger()
        toitem = aptfront.Converter_s_P()
        totag = aptfront.Converter_s_T()
        readConvCollection(toitem, totag, filename, coll)

        newpatches = aptfront.DebtagsPatchList()
        newpatches.addPatch(dt.tagdb(), coll)
        fromitem = aptfront.Converter_P_s()
        fromtag = aptfront.Converter_T_s()
        aptfront.DebtagsTextFormat_outputPatch(fromitem, fromtag, newpatches, sys.stdout)
        

    def maintainers(self, *args):
        self.openCache()
        pkgs = self.cache.packages()
        maints = aptfront.InputMerger_s_T()
        for pkg in pkgs:
            v = pkg.candidateVersion()
            if not v.valid():
                continue
            maints.consume(v.maintainer(), pkg.tags())
        mp = MaintPrinter()
        maints.output(mp)

        
    def tag(self, *args):
        raise NotImplementedError


    def submit(self, *args):
        dt = self.openDebtags()
        if len(args) > 0:
            input = aptfront.StdioParserInput(args[0])
            toitem = aptfront.Converter_s_P()
            totag = aptfront.Converter_s_T()
            patch = aptfront.DebtagsPatchlist(
                aptfront.DebtagsTextFormat_parsePatch(toitem, totag, input))
            dt.sendPatch(patch)
        else:
            dt.sendPatch()
            

    def todo(self, *args):
        class TODOFilter(aptfront.DebtagsFilterItemsByExpression):
            def __init__(self, writer):
                aptfront.DebtagsFilterItemsByExpression.__init__(
                    self, writer, "special::not-yet-tagged*")

            def consumeItemUntagged(self, pkg):
                if pkg.isInstalled() or pkg.isUpgradable() or pkg.isBroken():
                    aptfront.DebtagsFilterItemsByExpression.consumeItemUntagged(
                        self, pkg)
                    
            def consumeItem(self, pkg, tags):
                if pkg.isInstalled() or pkg.isUpgradable() or pkg.isBroken():
                    aptfront.DebtagsFilterItemsByExpression.consumeItem(
                        self, pkg, tags)
        dt = self.openDebtags()
        writer = PackagePrinter()
        filter = TODOFilter(writer)
        dt.outputPatched(filter)

        
    def score(self, *args):
        dt = self.openDebtags()

        tscorer = TagsScorer()
        dt.outputPatched(tscorer)

        pscorer = PackageScorer(tscorer)
        dt.outputPatched(pscorer)
        for score, pkg in pscorer.pkgscores:
            print "%i %s - %s" % (score, pkg.name(), pkg.shortDescription("short description not available"))


    def facetcoll(self, *args):
        class FacetcollPrinter(aptfront.Consumer_P_F):
            def consumeItemUntagged(self, pkg):
                print pkg.name()

            def consumeItem(self, pkg, tags):                
                print "%s: %s" % (pkg.name(),
                                  ", ".join([t.name() for t in tags]))

        dt = self.openDebtags()
        printer = FacetcollPrinter()
        out = aptfront.TagToFacet_P(printer)
        dt.outputPatched(out)


    def stats(self, *args):
        raise NotImplementedError


    def todoreport(self, *args):
        raise NotImplementedError


    def ssearch(self, *args):
        raise NotImplementedError
        
            
if len(sys.argv) > 1:
    cmd = sys.argv[1]
    args = sys.argv[2:]
    c = Commands()
    getattr(c, cmd)(*args)
