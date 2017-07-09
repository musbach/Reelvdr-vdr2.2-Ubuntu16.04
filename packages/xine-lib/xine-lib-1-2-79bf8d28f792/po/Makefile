# Makefile for PO directory in any package using GNU gettext.
# Copyright (C) 1995-1997, 2000-2007 by Ulrich Drepper <drepper@gnu.ai.mit.edu>
#
# This file can be copied and used freely without restrictions.  It can
# be used in projects which are not available under the GNU General Public
# License but which still want to provide support for the GNU gettext
# functionality.
# Please note that the actual code of GNU gettext is covered by the GNU
# General Public License and is *not* in the public domain.
#
# Origin: gettext-0.17
GETTEXT_MACRO_VERSION = 0.17

PACKAGE = xine-lib
VERSION = 1.2.6hg
PACKAGE_BUGREPORT = xine-bugs@lists.sourceforge.net

SHELL = /bin/sh


srcdir = .
top_srcdir = ..


prefix = /usr/local
exec_prefix = ${prefix}
datarootdir = ${prefix}/share
datadir = ${datarootdir}
localedir = ${datarootdir}/locale
gettextsrcdir = $(datadir)/gettext/po

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644

# We use $(mkdir_p).
# In automake <= 1.9.x, $(mkdir_p) is defined either as "mkdir -p --" or as
# "$(mkinstalldirs)" or as "$(install_sh) -d". For these automake versions,
# ${SHELL} /usr/src/reelbox/testing/packages/xine-lib/xine-lib-1-2-79bf8d28f792/install-sh does not start with $(SHELL), so we add it.
# In automake >= 1.10, /bin//mkdir -p is derived from ${MKDIR_P}, which is defined
# either as "/path/to/mkdir -p" or ".../install-sh -c -d". For these automake
# versions, $(mkinstalldirs) and $(install_sh) are unused.
mkinstalldirs = $(SHELL) ${SHELL} /usr/src/reelbox/testing/packages/xine-lib/xine-lib-1-2-79bf8d28f792/install-sh -d
install_sh = $(SHELL) ${SHELL} /usr/src/reelbox/testing/packages/xine-lib/xine-lib-1-2-79bf8d28f792/install-sh
MKDIR_P = /bin//mkdir -p
mkdir_p = /bin//mkdir -p

GMSGFMT_ = /usr/bin/msgfmt
GMSGFMT_no = /usr/bin/msgfmt
GMSGFMT_yes = /usr/bin/msgfmt
GMSGFMT = $(GMSGFMT_$(USE_MSGCTXT))
MSGFMT_ = /usr/bin/msgfmt
MSGFMT_no = /usr/bin/msgfmt
MSGFMT_yes = /usr/bin/msgfmt
MSGFMT = $(MSGFMT_$(USE_MSGCTXT))
XGETTEXT_ = /usr/bin/xgettext
XGETTEXT_no = /usr/bin/xgettext
XGETTEXT_yes = /usr/bin/xgettext
XGETTEXT = $(XGETTEXT_$(USE_MSGCTXT))
MSGMERGE = msgmerge
MSGMERGE_UPDATE = /usr/bin/msgmerge --update
MSGINIT = msginit
MSGCONV = msgconv
MSGFILTER = msgfilter

POFILES =  cs.po de.po en_US.po eo.po es.po eu.po fr.po it.po ja.po pl.po pt_BR.po sk.po tr.po
GMOFILES =  cs.gmo de.gmo en_US.gmo eo.gmo es.gmo eu.gmo fr.gmo it.gmo ja.gmo pl.gmo pt_BR.gmo sk.gmo tr.gmo
UPDATEPOFILES =  cs.po-update de.po-update en_US.po-update eo.po-update es.po-update eu.po-update fr.po-update it.po-update ja.po-update pl.po-update pt_BR.po-update sk.po-update tr.po-update
DUMMYPOFILES =  cs.nop de.nop en_US.nop eo.nop es.nop eu.nop fr.nop it.nop ja.nop pl.nop pt_BR.nop sk.nop tr.nop
DISTFILES.common = Makefile.in.in remove-potcdate.sin \
$(DISTFILES.common.extra1) $(DISTFILES.common.extra2) $(DISTFILES.common.extra3)
DISTFILES = $(DISTFILES.common) Makevars POTFILES.in \
$(POFILES) $(GMOFILES) \
$(DISTFILES.extra1) $(DISTFILES.extra2) $(DISTFILES.extra3)

POTFILES = \
     ../contrib/libmpcdec/requant.c \
     ../contrib/libmpcdec/synth_filter.c \
     ../lib/hstrerror.c \
     ../src/audio_dec/ff_dvaudio_decoder.c \
     ../src/audio_dec/xine_a52_decoder.c \
     ../src/audio_dec/xine_dts_decoder.c \
     ../src/audio_dec/xine_faad_decoder.c \
     ../src/audio_dec/xine_musepack_decoder.c \
     ../src/audio_out/audio_alsa_out.c \
     ../src/audio_out/audio_coreaudio_out.c \
     ../src/audio_out/audio_directx2_out.c \
     ../src/audio_out/audio_directx_out.c \
     ../src/audio_out/audio_esd_out.c \
     ../src/audio_out/audio_file_out.c \
     ../src/audio_out/audio_irixal_out.c \
     ../src/audio_out/audio_jack_out.c \
     ../src/audio_out/audio_none_out.c \
     ../src/audio_out/audio_oss_out.c \
     ../src/audio_out/audio_pulse_out.c \
     ../src/audio_out/audio_sun_out.c \
     ../src/audio_out/speakers.h \
     ../src/combined/ffmpeg/ff_audio_decoder.c \
     ../src/combined/ffmpeg/ff_video_decoder.c \
     ../src/combined/xine_ogg_demuxer.c \
     ../src/combined/xine_vorbis_decoder.c \
     ../src/demuxers/demux_asf.c \
     ../src/demuxers/demux_avi.c \
     ../src/demuxers/demux_film.c \
     ../src/demuxers/demux_flv.c \
     ../src/demuxers/demux_iff.c \
     ../src/demuxers/demux_mpc.c \
     ../src/demuxers/demux_mpeg_block.c \
     ../src/demuxers/demux_mpeg_pes.c \
     ../src/demuxers/demux_qt.c \
     ../src/demuxers/demux_snd.c \
     ../src/demuxers/demux_tta.c \
     ../src/demuxers/demux_voc.c \
     ../src/demuxers/demux_wc3movie.c \
     ../src/dxr3/dxr3_decode_spu.c \
     ../src/dxr3/dxr3_decode_video.c \
     ../src/dxr3/dxr3.h \
     ../src/dxr3/dxr3_mpeg_encoders.c \
     ../src/dxr3/dxr3_scr.c \
     ../src/dxr3/ffmpeg_encoder.c \
     ../src/dxr3/video_out_dxr3.c \
     ../src/input/input_bluray.c \
     ../src/input/input_cdda.c \
     ../src/input/input_dvb.c \
     ../src/input/input_dvd.c \
     ../src/input/input_file.c \
     ../src/input/input_gnome_vfs.c \
     ../src/input/input_http.c \
     ../src/input/input_mms.c \
     ../src/input/input_net.c \
     ../src/input/input_pnm.c \
     ../src/input/input_pvr.c \
     ../src/input/input_rtp.c \
     ../src/input/input_rtsp.c \
     ../src/input/input_smb.c \
     ../src/input/input_stdin_fifo.c \
     ../src/input/input_test.c \
     ../src/input/input_v4l.c \
     ../src/input/input_vcd.c \
     ../src/input/librtsp/rtsp.c \
     ../src/input/librtsp/rtsp_session.c \
     ../src/input/media_helper.c \
     ../src/input/mms.c \
     ../src/input/mmsh.c \
     ../src/input/net_buf_ctrl.c \
     ../src/input/pnm.c \
     ../src/input/vcd/vcdio.c \
     ../src/input/vcd/vcdplayer.c \
     ../src/input/vcd/vcdplayer.h \
     ../src/input/vcd/xineplug_inp_vcd.c \
     ../src/libreal/real_common.c \
     ../src/libreal/xine_real_audio_decoder.c \
     ../src/libreal/xine_real_video_decoder.c \
     ../src/libw32dll/common.c \
     ../src/libw32dll/w32codec.c \
     ../src/post/audio/stretch.c \
     ../src/post/audio/upmix.c \
     ../src/post/audio/upmix_mono.c \
     ../src/post/audio/volnorm.c \
     ../src/post/deinterlace/xine_plugin.c \
     ../src/post/goom/xine_goom.c \
     ../src/post/mosaico/mosaico.c \
     ../src/post/mosaico/switch.c \
     ../src/post/planar/boxblur.c \
     ../src/post/planar/denoise3d.c \
     ../src/post/planar/eq2.c \
     ../src/post/planar/eq.c \
     ../src/post/planar/expand.c \
     ../src/post/planar/noise.c \
     ../src/post/planar/pp.c \
     ../src/post/planar/unsharp.c \
     ../src/spu_dec/cmml_decoder.c \
     ../src/spu_dec/sputext_decoder.c \
     ../src/spu_dec/sputext_demuxer.c \
     ../src/spu_dec/xine_cc_decoder.c \
     ../src/vdr/input_vdr.c \
     ../src/vdr/post_vdr_video.c \
     ../src/video_dec/bitplane.c \
     ../src/video_dec/libjpeg.c \
     ../src/video_out/color_matrix.c \
     ../src/video_out/video_out_aa.c \
     ../src/video_out/video_out_caca.c \
     ../src/video_out/video_out_directfb.c \
     ../src/video_out/video_out_directx.c \
     ../src/video_out/video_out_fb.c \
     ../src/video_out/video_out_none.c \
     ../src/video_out/video_out_opengl2.c \
     ../src/video_out/video_out_opengl.c \
     ../src/video_out/video_out_pgx32.c \
     ../src/video_out/video_out_pgx64.c \
     ../src/video_out/video_out_raw.c \
     ../src/video_out/video_out_sdl.c \
     ../src/video_out/video_out_stk.c \
     ../src/video_out/video_out_vaapi.c \
     ../src/video_out/video_out_vdpau.c \
     ../src/video_out/video_out_vidix.c \
     ../src/video_out/video_out_xcbshm.c \
     ../src/video_out/video_out_xcbxv.c \
     ../src/video_out/video_out_xshm.c \
     ../src/video_out/video_out_xv.c \
     ../src/video_out/video_out_xvmc.c \
     ../src/video_out/video_out_xxmc.c \
     ../src/video_out/x11osd.c \
     ../src/video_out/xcbosd.c \
     ../src/video_out/xv_common.h \
     ../src/xine-engine/alphablend.c \
     ../src/xine-engine/audio_decoder.c \
     ../src/xine-engine/audio_out.c \
     ../src/xine-engine/buffer.c \
     ../src/xine-engine/buffer_types.c \
     ../src/xine-engine/configfile.c \
     ../src/xine-engine/demux.c \
     ../src/xine-engine/info_helper.c \
     ../src/xine-engine/input_cache.c \
     ../src/xine-engine/input_rip.c \
     ../src/xine-engine/io_helper.c \
     ../src/xine-engine/load_plugins.c \
     ../src/xine-engine/osd.c \
     ../src/xine-engine/spu.c \
     ../src/xine-engine/video_decoder.c \
     ../src/xine-engine/video_out.c \
     ../src/xine-engine/vo_scale.c \
     ../src/xine-engine/xine.c \
     ../src/xine-engine/xine_interface.c \
     ../src/xine-utils/memcpy.c

CATALOGS =  cs.gmo de.gmo en_US.gmo eo.gmo es.gmo eu.gmo fr.gmo it.gmo ja.gmo pl.gmo pt_BR.gmo sk.gmo tr.gmo

# Makevars gets inserted here. (Don't remove this line!)
# Makefile variables for PO directory in any package using GNU gettext.

include Makevars.extra

DISTFILES += Makevars.extra.in

# Usually the message domain is the same as the package name.
DOMAIN = $(LIBNAME)

# These two variables depend on the location of this directory.
subdir = po
top_builddir = ..

# Internal usage
XGETTEXT_FORMAT_FLAGS_PRIVATE = \
	--flag=xine_log_msg:1:c-format \
	--flag=xine_log_err:1:c-format \
	--flag=xprintf:3:c-format \
	--flag=xine_printf:3:c-format \
	--flag=set_hc_result:3:c-format \
	--flag=log_printf:1:c-format \
	--flag=error_message:1:c-format \
	--flag=error_callback:5:c-format \
	--flag=dbgprintf:1:c-format \
	--flag=dbg_printf:1:c-format \
	--flag=sock_string_write:3:c-format \
	--flag=broadcaster_string_write:3:c-format \
	--flag=scratch_printf:3:c-format

# External usage (installed include files)
XGETTEXT_FORMAT_FLAGS = \
	--flag=xine_log:3:c-format \
	--flag=xine_vlog:3:c-format

# These options get passed to xgettext.
XGETTEXT_OPTIONS = --keyword=_ --keyword=N_ --from-code=UTF-8 \
		   $(XGETTEXT_FORMAT_FLAGS_PRIVATE) \
		   $(XGETTEXT_FORMAT_FLAGS)		 

# This is the copyright holder that gets inserted into the header of the
# $(DOMAIN).pot file.  Set this to the copyright holder of the surrounding
# package.  (Note that the msgstr strings, extracted from the package's
# sources, belong to the copyright holder of the package.)  Translators are
# expected to transfer the copyright for their translations to this person
# or entity, or to disclaim their copyright.  The empty string stands for
# the public domain; in this case the translators are expected to disclaim
# their copyright.
COPYRIGHT_HOLDER = Copyright (C) 2000-2006 the xine project

# This is the email address or URL to which the translators shall report
# bugs in the untranslated strings:
# - Strings which are not entire sentences, see the maintainer guidelines
#   in the GNU gettext documentation, section 'Preparing Strings'.
# - Strings which use unclear terms or require additional context to be
#   understood.
# - Strings which make invalid assumptions about notation of date, time or
#   money.
# - Pluralisation problems.
# - Incorrect English spelling.
# - Incorrect formatting.
# It can be your email address, or a mailing list address where translators
# can write to without being subscribed, or the URL of a web page through
# which the translators can contact you.
MSGID_BUGS_ADDRESS = xine-devel@lists.sourceforge.net

# This is the list of locale categories, beyond LC_MESSAGES, for which the
# message catalogs shall be used.  It is usually empty.
EXTRA_LOCALE_CATEGORIES =

debug:
install-debug:
	

.SUFFIXES:
.SUFFIXES: .po .gmo .mo .sed .sin .nop .po-create .po-update

.po.mo:
	@echo "$(MSGFMT) -c -o $@ $<"; \
	$(MSGFMT) -c -o t-$@ $< && mv t-$@ $@

.po.gmo:
	@lang=`echo $* | sed -e 's,.*/,,'`; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics -o $${lang}.gmo $${lang}.po"; \
	cd $(srcdir) && rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics -o t-$${lang}.gmo $${lang}.po && mv t-$${lang}.gmo $${lang}.gmo

.sin.sed:
	sed -e '/^#/d' $< > t-$@
	mv t-$@ $@


all: check-macro-version all-yes

all-yes: stamp-po
all-no:

# Ensure that the gettext macros and this Makefile.in.in are in sync.
check-macro-version:
	@test "$(GETTEXT_MACRO_VERSION)" = "0.17" \
	  || { echo "*** error: gettext infrastructure mismatch: using a Makefile.in.in from gettext version $(GETTEXT_MACRO_VERSION) but the autoconf macros are from gettext version 0.17" 1>&2; \
	       exit 1; \
	     }

# $(srcdir)/$(DOMAIN).pot is only created when needed. When xgettext finds no
# internationalized messages, no $(srcdir)/$(DOMAIN).pot is created (because
# we don't want to bother translators with empty POT files). We assume that
# LINGUAS is empty in this case, i.e. $(POFILES) and $(GMOFILES) are empty.
# In this case, stamp-po is a nop (i.e. a phony target).

# stamp-po is a timestamp denoting the last time at which the CATALOGS have
# been loosely updated. Its purpose is that when a developer or translator
# checks out the package via CVS, and the $(DOMAIN).pot file is not in CVS,
# "make" will update the $(DOMAIN).pot and the $(CATALOGS), but subsequent
# invocations of "make" will do nothing. This timestamp would not be necessary
# if updating the $(CATALOGS) would always touch them; however, the rule for
# $(POFILES) has been designed to not touch files that don't need to be
# changed.
stamp-po: $(srcdir)/$(DOMAIN).pot
	test ! -f $(srcdir)/$(DOMAIN).pot || \
	  test -z "$(GMOFILES)" || $(MAKE) $(GMOFILES)
	@test ! -f $(srcdir)/$(DOMAIN).pot || { \
	  echo "touch stamp-po" && \
	  echo timestamp > stamp-poT && \
	  mv stamp-poT stamp-po; \
	}

# Note: Target 'all' must not depend on target '$(DOMAIN).pot-update',
# otherwise packages like GCC can not be built if only parts of the source
# have been downloaded.

# This target rebuilds $(DOMAIN).pot; it is an expensive operation.
# Note that $(DOMAIN).pot is not touched if it doesn't need to be changed.
$(DOMAIN).pot-update: $(POTFILES) $(srcdir)/POTFILES.in remove-potcdate.sed
	if LC_ALL=C grep 'GNU xine-lib' $(top_srcdir)/* 2>/dev/null | grep -v 'libtool:' >/dev/null; then \
	  package_gnu='GNU '; \
	else \
	  package_gnu=''; \
	fi; \
	if test -n '$(MSGID_BUGS_ADDRESS)' || test '$(PACKAGE_BUGREPORT)' = '@'PACKAGE_BUGREPORT'@'; then \
	  msgid_bugs_address='$(MSGID_BUGS_ADDRESS)'; \
	else \
	  msgid_bugs_address='$(PACKAGE_BUGREPORT)'; \
	fi; \
	case `$(XGETTEXT) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	  '' | 0.[0-9] | 0.[0-9].* | 0.1[0-5] | 0.1[0-5].* | 0.16 | 0.16.[0-1]*) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	  *) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --package-name="$${package_gnu}xine-lib" \
	      --package-version='1.2.6hg' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	esac
	test ! -f $(DOMAIN).po || { \
	  if test -f $(srcdir)/$(DOMAIN).pot; then \
	    sed -f remove-potcdate.sed < $(srcdir)/$(DOMAIN).pot > $(DOMAIN).1po && \
	    sed -f remove-potcdate.sed < $(DOMAIN).po > $(DOMAIN).2po && \
	    if cmp $(DOMAIN).1po $(DOMAIN).2po >/dev/null 2>&1; then \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(DOMAIN).po; \
	    else \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(srcdir)/$(DOMAIN).pot && \
	      mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	    fi; \
	  else \
	    mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	  fi; \
	}

# This rule has no dependencies: we don't need to update $(DOMAIN).pot at
# every "make" invocation, only create it when it is missing.
# Only "make $(DOMAIN).pot-update" or "make dist" will force an update.
$(srcdir)/$(DOMAIN).pot:
	$(MAKE) $(DOMAIN).pot-update

# This target rebuilds a PO file if $(DOMAIN).pot has changed.
# Note that a PO file is not touched if it doesn't need to be changed.
$(POFILES): $(srcdir)/$(DOMAIN).pot
	@lang=`echo $@ | sed -e 's,.*/,,' -e 's/\.po$$//'`; \
	if test -f "$(srcdir)/$${lang}.po"; then \
	  test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	  echo "$${cdcmd}$(MSGMERGE_UPDATE) $${lang}.po $(DOMAIN).pot"; \
	  cd $(srcdir) && $(MSGMERGE_UPDATE) $${lang}.po $(DOMAIN).pot; \
	else \
	  $(MAKE) $${lang}.po-create; \
	fi


install: install-exec install-data
install-exec:
install-data: install-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    $(INSTALL_DATA) $(srcdir)/$$file \
			    $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	  for file in Makevars; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
install-data-no: all
install-data-yes: all
	$(mkdir_p) $(DESTDIR)$(datadir)
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  if test -r $$cat; then realcat=$$cat; else realcat=$(srcdir)/$$cat; fi; \
	  $(INSTALL_DATA) $$realcat $(DESTDIR)$$dir/$(DOMAIN).mo; \
	  echo "installing $$realcat as $(DESTDIR)$$dir/$(DOMAIN).mo"; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	      rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      ln -s ../LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      ln $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      cp -p $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      echo "installing $$realcat link as $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo"; \
	    fi; \
	  done; \
	done

install-strip: install

installdirs: installdirs-exec installdirs-data
installdirs-exec:
installdirs-data: installdirs-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	else \
	  : ; \
	fi
installdirs-data-no:
installdirs-data-yes:
	$(mkdir_p) $(DESTDIR)$(datadir)
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	    fi; \
	  done; \
	done

# Define this as empty until I found a useful application.
installcheck:

uninstall: uninstall-exec uninstall-data
uninstall-exec:
uninstall-data: uninstall-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
uninstall-data-no:
uninstall-data-yes:
	catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  for lc in LC_MESSAGES $(EXTRA_LOCALE_CATEGORIES); do \
	    rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	  done; \
	done

check: all

info dvi ps pdf html tags TAGS ctags CTAGS ID:

mostlyclean:
	rm -f remove-potcdate.sed
	rm -f stamp-poT
	rm -f core core.* $(DOMAIN).po $(DOMAIN).1po $(DOMAIN).2po *.new.po
	rm -fr *.o

clean: mostlyclean

distclean: clean
	rm -f Makefile Makefile.in POTFILES *.mo

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f stamp-po $(GMOFILES)

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir:
	$(MAKE) update-po
	@$(MAKE) dist2
# This is a separate target because 'update-po' must be executed before.
dist2: stamp-po $(DISTFILES)
	dists="$(DISTFILES)"; \
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  dists="$$dists Makevars.template"; \
	fi; \
	if test -f $(srcdir)/$(DOMAIN).pot; then \
	  dists="$$dists $(DOMAIN).pot stamp-po"; \
	fi; \
	if test -f $(srcdir)/ChangeLog; then \
	  dists="$$dists ChangeLog"; \
	fi; \
	for i in 0 1 2 3 4 5 6 7 8 9; do \
	  if test -f $(srcdir)/ChangeLog.$$i; then \
	    dists="$$dists ChangeLog.$$i"; \
	  fi; \
	done; \
	if test -f $(srcdir)/LINGUAS; then dists="$$dists LINGUAS"; fi; \
	for file in $$dists; do \
	  if test -f $$file; then \
	    cp -p $$file $(distdir) || exit 1; \
	  else \
	    cp -p $(srcdir)/$$file $(distdir) || exit 1; \
	  fi; \
	done

update-po: Makefile
	$(MAKE) $(DOMAIN).pot-update
	test -z "$(UPDATEPOFILES)" || $(MAKE) $(UPDATEPOFILES)
	$(MAKE) update-gmo

# General rule for creating PO files.

.nop.po-create:
	@lang=`echo $@ | sed -e 's/\.po-create$$//'`; \
	echo "File $$lang.po does not exist. If you are a translator, you can create it through 'msginit'." 1>&2; \
	exit 1

# General rule for updating PO files.

.nop.po-update:
	@lang=`echo $@ | sed -e 's/\.po-update$$//'`; \
	if test "$(PACKAGE)" = "gettext-tools"; then PATH=`pwd`/../src:$$PATH; fi; \
	tmpdir=`pwd`; \
	echo "$$lang:"; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}$(MSGMERGE) $$lang.po $(DOMAIN).pot -o $$lang.new.po"; \
	cd $(srcdir); \
	if $(MSGMERGE) $$lang.po $(DOMAIN).pot -o $$tmpdir/$$lang.new.po; then \
	  if cmp $$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	    rm -f $$tmpdir/$$lang.new.po; \
	  else \
	    if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	      :; \
	    else \
	      echo "msgmerge for $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	      exit 1; \
	    fi; \
	  fi; \
	else \
	  echo "msgmerge for $$lang.po failed!" 1>&2; \
	  rm -f $$tmpdir/$$lang.new.po; \
	fi

$(DUMMYPOFILES):

update-gmo: Makefile $(GMOFILES)
	@:

Makefile: Makefile.in.in Makevars $(top_builddir)/config.status POTFILES.in LINGUAS
	cd $(top_builddir) \
	  && $(SHELL) ./config.status $(subdir)/$@.in po-directories

force:

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
# Special Makefile rules for English message catalogs with quotation marks.

DISTFILES.common.extra1 = quot.sed boldquot.sed en@quot.header en@boldquot.header insert-header.sin Rules-quot

.SUFFIXES: .insert-header .po-update-en

en@quot.po-create:
	$(MAKE) en@quot.po-update
en@boldquot.po-create:
	$(MAKE) en@boldquot.po-update

en@quot.po-update: en@quot.po-update-en
en@boldquot.po-update: en@boldquot.po-update-en

.insert-header.po-update-en:
	@lang=`echo $@ | sed -e 's/\.po-update-en$$//'`; \
	if test "$(PACKAGE)" = "gettext"; then PATH=`pwd`/../src:$$PATH; GETTEXTLIBDIR=`cd $(top_srcdir)/src && pwd`; export GETTEXTLIBDIR; fi; \
	tmpdir=`pwd`; \
	echo "$$lang:"; \
	ll=`echo $$lang | sed -e 's/@.*//'`; \
	LC_ALL=C; export LC_ALL; \
	cd $(srcdir); \
	if $(MSGINIT) -i $(DOMAIN).pot --no-translator -l $$ll -o - 2>/dev/null | sed -f $$tmpdir/$$lang.insert-header | $(MSGCONV) -t UTF-8 | $(MSGFILTER) sed -f `echo $$lang | sed -e 's/.*@//'`.sed 2>/dev/null > $$tmpdir/$$lang.new.po; then \
	  if cmp $$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	    rm -f $$tmpdir/$$lang.new.po; \
	  else \
	    if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	      :; \
	    else \
	      echo "creation of $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	      exit 1; \
	    fi; \
	  fi; \
	else \
	  echo "creation of $$lang.po failed!" 1>&2; \
	  rm -f $$tmpdir/$$lang.new.po; \
	fi

en@quot.insert-header: insert-header.sin
	sed -e '/^#/d' -e 's/HEADER/en@quot.header/g' $(srcdir)/insert-header.sin > en@quot.insert-header

en@boldquot.insert-header: insert-header.sin
	sed -e '/^#/d' -e 's/HEADER/en@boldquot.header/g' $(srcdir)/insert-header.sin > en@boldquot.insert-header

mostlyclean: mostlyclean-quot
mostlyclean-quot:
	rm -f *.insert-header
