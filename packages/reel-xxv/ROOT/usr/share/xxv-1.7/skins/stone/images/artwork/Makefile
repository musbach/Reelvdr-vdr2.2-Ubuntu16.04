#
# Makefile
#
# $Id$

IMAGES = ../on.gif ../delete.gif ../record.gif ../off.gif ../edit.gif \
../watch.gif ../find.gif ../new.gif ../back.gif ../forward.gif ../down.gif \
../home.gif ../refresh.gif ../onoff.gif ../movie.gif ../play.gif ../folder.gif \
../select.gif ../deselect.gif ../invers.gif ../newfolder.gif \
../cut.gif ../file.gif ../audio.gif  ../topten.gif ../warning.gif \
../imdb.gif ../ofdb.gif ../info.gif ../tvm.gif ../nocover.gif ../noactor.gif \
../recover.gif ../loud.gif ../quiet.gif  ../mute.gif  ../webcast.gif

### Targets:

%.gif: %.png
	@convert -unsharp 0.1 $< $@

all: $(IMAGES)

#convert -colorspace GRAY -resize 16x16 -dispose 2 -background white -transparent white -delay 10 "wait0*.png" "../wait.gif"
