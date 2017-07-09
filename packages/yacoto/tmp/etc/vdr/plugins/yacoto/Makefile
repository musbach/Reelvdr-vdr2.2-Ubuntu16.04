PACKAGE  = yacoto-scripts
VERSION  = 0.0.3
ARCHIVE  = $(PACKAGE)-helau-$(VERSION)
prefix  ?= /usr
DOCDIR   = $(DESTDIR)$(prefix)/share/doc/$(PACKAGE)-$(VERSION)

YAC_CONF_DIR ?= /etc/vdr/plugins/yacoto
YAC_DIR ?= $(YAC_CONF_DIR)

#
# "detect" mandatory dependencies
HAVE_VDRSYNC ?= $(shell which vdrsync.pl &>/dev/null && echo "1")
HAVE_SCREEN ?= $(shell which screen &>/dev/null && echo "1")
HAVE_REPLEX ?= $(shell which replex &>/dev/null && echo "1")

#
# "detect" optional dependencies

HAVE_MJPEGTOOLS ?= $(shell which png2yuv &>/dev/null && echo "1")
HAVE_CDRTOOLS ?= $(shell which mkisofs &>/dev/null && echo "1")
HAVE_DVDPLUSRWTOOLS ?= $(shell which growisofs &>/dev/null && echo "1")
HAVE_IMAGEMAGICK ?= $(shell which convert &>/dev/null && echo "1")
HAVE_VAMPS ?= $(shell which vamps &>/dev/null && echo "1")
HAVE_DVDAUTHOR ?= $(shell which dvdauthor &>/dev/null && echo "1")
HAVE_MENCODER ?= $(shell which mencoder &>/dev/null && echo "1")
HAVE_FFMPEG ?= $(shell which ffmpeg &>/dev/null && echo "1")
HAVE_MP4BOX ?= $(shell which MP4Box &>/dev/null && echo "1")
HAVE_LAME ?= $(shell which lame &>/dev/null && echo "1")
HAVE_VORBISTOOLS ?= $(shell which oggenc &>/dev/null && echo "1")
HAVE_PROJECTX ?= $(shell which projectx_nogui &>/dev/null && echo "1")


#
#
# "select" options
WITH_DVD ?= 1
WITH_3GP ?= 1
WITH_IPOD ?= 1
WITH_MP3 ?= 1
WITH_OGG ?= 1
WITH_H264 ?= 1
WITH_DIVX ?= 1
WITH_PROJECTX ?= 1

# these need mandatory deps only:
ENC_SCRIPTS = mpeg2
ENC_CONFIGS = mpeg2

# want DVD and have all the deps?
ifeq ($(WITH_DVD),1)
ifeq ($(HAVE_MJPEGTOOLS),1)
ifeq ($(HAVE_CDRTOOLS),1)
ifeq ($(HAVE_DVDPLUSRWTOOLS),1)
ifeq ($(HAVE_IMAGEMAGICK),1)
ifeq ($(HAVE_VAMPS),1)
ifeq ($(HAVE_DVDAUTHOR),1)
	ENC_SCRIPTS += dvd
	ENC_CONFIGS += dvd
endif
endif
endif
endif
endif
endif
endif

# if we have ProjectX (useful not only for DVD remuxing)
ifeq ($(HAVE_PROJECTX),1)
	ENC_INIS += ProjectX
endif

# if we have just mencoder
ifeq ($(HAVE_MENCODER),1)
	ENC_SCRIPTS += yac_enc_mencoder youtube
	ENC_CONFIGS += youtube
	ifeq ($(WITH_DIVX),1)
		ENC_SCRIPTS += divx divx_mobile
		ENC_CONFIGS += divx divx_mobile
	endif
	ifeq ($(HAVE_MP4BOX),1)
		ifeq ($(WITH_IPOD),1)
			ENC_SCRIPTS += ipod_menc
			ENC_CONFIGS += ipod_menc
		endif
	endif
	ifeq ($(WITH_H264),1)
		ENC_SCRIPTS += h264
		ENC_CONFIGS += h264
	endif
endif

# if we have just ffmpeg
ifeq ($(HAVE_FFMPEG),1)
	ENC_SCRIPTS += yac_enc_ffmpeg
	ifeq ($(WITH_DIVX),1)
		ENC_SCRIPTS += divx_ffmpeg
		ENC_CONFIGS += divx_ffmpeg
	endif
	ifeq ($(HAVE_MP4BOX),1)
		ifeq ($(WITH_IPOD),1)
			ENC_SCRIPTS += ipod_ffmpeg
			ENC_CONFIGS += ipod_ffmpeg
		endif
	endif
endif

# if we have both mencoder and ffmpeg
ifeq ($(HAVE_MENCODER),1)
	ifeq ($(HAVE_FFMPEG),1)
		ifeq ($(WITH_3GP),1)
			ENC_SCRIPTS += 3gp
			ENC_CONFIGS += 3gp
		endif
		ifeq ($(WITH_IPOD),1)
			ENC_SCRIPTS += ipod_nano
			ENC_CONFIGS += ipod_nano
		endif
	endif
endif

# if we have lame and possibly vorbis tools
ifeq ($(HAVE_LAME),1)
	ifeq ($(WITH_MP3),1)
		ENC_SCRIPTS += mp3
		ENC_CONFIGS += mp3
	endif
	ifeq ($(HAVE_VORBISTOOLS),1)
		ifeq ($(WITH_OGG),1)
			ENC_SCRIPTS += ogg
			ENC_CONFIGS += ogg
		endif
	endif
endif



detect-deps:
	@echo ""
	@if ! [[ "$(HAVE_VDRSYNC)" = "1" ]] || ! [[ "$(HAVE_SCREEN)" = "1" ]] || ! [[ "$(HAVE_REPLEX)" = "1" ]]; then \
		if ! [[ "$(HAVE_VDRSYNC)" = "1" ]]; then \
			echo "Mandatory package 'vdrsync' not found !!!"; \
		fi; \
		if ! [[ "$(HAVE_SCREEN)" = "1" ]]; then \
			echo "Mandatory package 'screen' not found !!!"; \
		fi; \
		if ! [[ "$(HAVE_REPLEX)" = "1" ]]; then \
			echo "Mandatory package 'replex' not found !!!"; \
		fi; \
		echo ""; \
		echo "The scripts cannot work on your system and will not be installed."; \
		false; \
	fi
	@if [[ "$(WITH_DVD)" = "1" ]] && ! [[ "$(HAVE_MJPEGTOOLS)" = "1" ]]; then \
		echo "Optional package 'mjpegtools' not found !!!"; \
	fi
	@if [[ "$(WITH_DVD)" = "1" ]] && ! [[ "$(HAVE_CDRTOOLS)" = "1" ]]; then \
		echo "Optional package 'cdrtools' not found !!!"; \
	fi
	@if [[ "$(WITH_DVD)" = "1" ]] && ! [[ "$(HAVE_DVDPLUSRWTOOLS)" = "1" ]]; then \
		echo "Optional package 'dvd+rw-tools' not found !!!"; \
	fi
	@if [[ "$(WITH_DVD)" = "1" ]] && ! [[ "$(HAVE_IMAGEMAGICK)" = "1" ]]; then \
		echo "Optional package 'imagemagick' not found !!!"; \
	fi
	@if [[ "$(WITH_DVD)" = "1" ]] && ! [[ "$(HAVE_VAMPS)" = "1" ]]; then \
		echo "Optional package 'vamps' not found !!!"; \
	fi
	@if [[ "$(WITH_DVD)" = "1" ]] && ! [[ "$(HAVE_DVDAUTHOR)" = "1" ]]; then \
		echo "Optional package 'dvdauthor' not found !!!"; \
	fi
	@if [[ "$(WITH_3GP)" = "1" ]] || [[ "$(WITH_IPOD)" = "1" ]] || [[ "$(WITH_H264)" = "1" ]] || [[ "$(WITH_DIVX)" = "1" ]]; then \
		if ! [[ "$(HAVE_MENCODER)" = "1" ]]; then \
			echo "Optional package 'mencoder' (sometimes part of 'mplayer') not found !!!"; \
		fi; \
		if ! [[ "$(HAVE_FFMPEG)" = "1" ]]; then \
			echo "Optional package 'ffmpeg' not found !!!"; \
		fi; \
	fi
	@if [[ "$(WITH_IPOD)" = "1" ]]; then \
		if ! [[ "$(HAVE_MP4BOX)" = "1" ]]; then \
			echo "Optional package 'MP4Box' (sometimes part of 'gpac') not found !!!"; \
		fi; \
	fi
	@if [[ "$(WITH_MP3)" = "1" ]] || [[ "$(WITH_OGG)" = "1" ]]; then \
		if ! [[ "$(HAVE_LAME)" = "1" ]]; then \
			echo "Optional package 'Lame' not found !!!"; \
		fi; \
	fi
	@if [[ "$(WITH_OGG)" = "1" ]]; then \
		if ! [[ "$(HAVE_VORBISTOOLS)" = "1" ]]; then \
			echo "Optional package 'oggenc' (sometimes part of 'vorbis tools') not found !!!"; \
		fi; \
	fi
	@if [[ "$(WITH_PROJECTX)" = "1" ]]; then \
		if ! [[ "$(HAVE_PROJECTX)" = "1" ]]; then \
			echo "Optional (yet very useful) package 'ProjectX' not found !!!"; \
		fi; \
	fi
	@echo ""
	@echo "Encoding profiles according to selection / fullfilled dependencies:"
	@echo "$(ENC_CONFIGS)"
	@echo ""
	@if [[ "$(HAVE_PROJECTX)" = "1" ]]; then \
		echo "ProjectX demuxer: yes"; \
	else \
		echo "ProjectX demuxer: NO"; \
	fi
	@echo ""
	@echo "Scripts directory YAC_DIR:      $(YAC_DIR)"
	@echo "Configs directory YAC_CONF_DIR: $(YAC_CONF_DIR)"
	@echo ""

all: detect-deps
	@for scriptfile in $$(grep -r -l --include=*.sh 'YAC_CONF_DIR=' .); do \
		if ! [[ '$$(grep "YAC_CONF_DIR=" "$$scriptfile")' = 'YAC_CONF_DIR="$${YAC_CONF_DIR:=$(YAC_CONF_DIR)}"' ]]; then \
			sed -i "$$scriptfile" -e 's#'$$(grep "YAC_CONF_DIR=" "$$scriptfile")'#'YAC_CONF_DIR=\"\$${YAC_CONF_DIR\:=$(YAC_CONF_DIR)}\"'#'; \
		fi; \
	done
	@for scriptfile in $$(grep -r -l --include=*.sh 'YAC_DIR=' .); do \
		if ! [[ '$$(grep "YAC_DIR=" "$$scriptfile")' = 'YAC_DIR="$${YAC_DIR:=$(YAC_DIR)}"' ]]; then \
			sed -i "$$scriptfile" -e 's#'$$(grep "YAC_DIR=" "$$scriptfile")'#'YAC_DIR=\"\$${YAC_DIR\:=$(YAC_DIR)}\"'#'; \
		fi; \
	done

install: all
	@mkdir -p $(DESTDIR)$(YAC_CONF_DIR)/conf
	@mkdir -p $(DESTDIR)$(YAC_DIR)/conf
	@mkdir -p $(DESTDIR)$(YAC_DIR)/queue
	@mkdir -p $(DESTDIR)/var/log/yacoto
	@chmod ugo+x yac_*.sh
	@cp --recursive --remove-destination --archive yac_*.sh $(DESTDIR)$(YAC_DIR)
	@cp --recursive --remove-destination --archive *.conf.sample $(DESTDIR)$(YAC_CONF_DIR)
	@for cfg in $(ENC_CONFIGS); do \
		if [[ -d conf/"$$cfg" ]]; then \
			cp --archive --recursive conf/"$$cfg" $(DESTDIR)$(YAC_DIR)/conf; \
			mkdir -p $(DESTDIR)$(YAC_CONF_DIR)/conf/"$$cfg"; \
			mv $(DESTDIR)$(YAC_DIR)/conf/"$$cfg"/*.conf.sample $(DESTDIR)$(YAC_CONF_DIR)/conf/"$$cfg"; \
		fi; \
		if [[ -x conf/"$$cfg".conf.sh ]]; then \
			cp --recursive --remove-destination --archive conf/"$$cfg".conf.sh $(DESTDIR)$(YAC_DIR)/conf; \
		fi; \
		cp --recursive --remove-destination --archive conf/"$$cfg".conf.sample $(DESTDIR)$(YAC_CONF_DIR)/conf; \
	done
	@for cfg in $(ENC_INIS); do \
		cp --recursive --remove-destination --archive conf/"$$cfg".ini $(DESTDIR)$(YAC_CONF_DIR)/conf; \
	done
	@for cfg in $(ENC_SCRIPTS); do \
		cp --recursive --remove-destination --archive conf/"$$cfg".sh $(DESTDIR)$(YAC_DIR)/conf; \
	done
	@mkdir -p $(DOCDIR)
	@cp --recursive --remove-destination --archive HISTORY README README.en -t $(DOCDIR)

dist:
	@for cfgfile in $$(find . -name "*.conf"); do \
		mv $$cfgfile $$cfgfile.sample; \
	done
	@chmod +x $$(find . -name "*.sh")
	@tar -czvf ./$(ARCHIVE).tgz -C . --exclude=*.tgz --exclude=*.conf.old --exclude=*.org --exclude=*.conf.new \
		--exclude=status/* --exclude=queue/* --exclude=yacadmin.conf* ../yacoto/*
	@echo Distribution package created as ./$(ARCHIVE).tgz
#	@tar -tzvf "$(ARCHIVE).tgz"
	@sh ./yac_update.sh


.PHONY: install
