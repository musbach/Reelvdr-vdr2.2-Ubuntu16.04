#
# Makefile to generate help pages
#

man  = xxvd.1
html = xxvd.html
pdf  = xxvd.pdf
txt  = xxvd.txt


%.1: %.sgml
	@docbook2x-man --to-stdout $< > $@

#%.1: %.sgml
#	@docbook-to-man $< > $@

%.texi: %.sgml
	@docbook2x-texi --to-stdout $< > $@

%.html: %.texi
	@texi2html $<

%.pdf: %.texi
	@texi2pdf $< -o $@

#%.txt: %.1
#	@groff -a -man -Tascii $< > $@

#
# generate html files
#
html: $(html)


#
# generate pdf files
#
pdf: $(pdf)


#
# generate man files
#
man: $(man) 

#
# generate plain ascii files
#
#text: $(txt) 

#
# generate all files
#
all: help

#
# clean generated files
#
clean:
	@rm -f $(txt) $(man) $(pdf) $(html)

#
# End user targets
#
help:
	@echo "----------- documentation make targets --------------"
	@echo "man:              generate manpages (requires: docbook2x-man)"
	@echo "pdf:              generate pdf (requires: docbook2x-texi, texi2pdf)"
	@echo "html:             generate html (requires: docbook2x-texi, texi2html)"
#	@echo "text:             generate text (requires: docbook2x-man, groff)"

