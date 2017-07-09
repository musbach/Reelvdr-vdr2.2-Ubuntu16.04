#
# Makefile for a Video Disk Recorder plugin
#
# $Id$

# The official name of this plugin.
# This name will be used in the '-P...' option of VDR to load the plugin.
# By default the main source file also carries this name.
#
PLUGIN = reelchannellist

### The object files (add further files here):

OBJS = $(PLUGIN).o activelist.o menu.o menuitem.o channelListFilter.o tools.o setup.o MenuMoveChannels.o favourites.o MenuEditChannel.o MenuCISlot.o
//OBJS = $(PLUGIN).o activelist.o menu.o menuitem.o channelListFilter.o tools.o setup.o MenuMoveChannels.o favourites.o MenuCISlot.o

### The directory environment:

VDRDIR = ../../../vdr
LIBDIR = ../../lib
TMPDIR = /tmp

### Allow user defined options to overwrite defaults:

-include $(VDRDIR)/Make.config
-include $(VDRDIR)/Make.common


### include *.h for pot file creation since some trNOOPs are present

$(I18Npot): menu.h menuitem.h
