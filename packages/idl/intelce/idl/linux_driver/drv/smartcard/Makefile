#/*
#
#  This file is provided under a dual BSD/GPLv2 license.  When using or
#  redistributing this file, you may do so under either license.
#
#  GPL LICENSE SUMMARY
#
#  Copyright(c) 2008-2010 Intel Corporation. All rights reserved.
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of version 2 of the GNU General Public License as
#  published by the Free Software Foundation.
#
#  This program is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
#  The full GNU General Public License is included in this distribution
#  in the file called LICENSE.GPL.
#
#  Contact Information:
#  intel.com
#  Intel Corporation
#  2200 Mission College Blvd.
#  Santa Clara, CA  95052
#  USA
#  (408) 765-8080
#
#
#  BSD LICENSE
#
#  Copyright(c) 2008-2010 Intel Corporation. All rights reserved.
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in
#      the documentation and/or other materials provided with the
#      distribution.
#    * Neither the name of Intel Corporation nor the names of its
#      contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#*/


#-----
# versioning
#-----
# Official build generates the follow version environment variables:
#       COMP_VER1=1
#       COMP_VER2=2
#       COMP_VER3=3
#       COMP_VER4=4
#       COMP_VER=1-2-3-0004
#
# If official build is not being done, we use bogus "development" build number
COMP_VER4 ?= 9999999
COMP_VER  ?= <Unofficial Build>
EXTRA_CFLAGS+= -DLINUX -DVER1=$(COMP_VER1) -DVER2=$(COMP_VER2) -DVER3=$(COMP_VER3) -DVER4=$(COMP_VER4) -DVER="\"$(COMP_VER)\"" -DCOMPONENTNAME="\"$(COMPONENTNAME)\""


BASE_DIR=$(PWD)/../../..
INCLUDE_DIR=$(BASE_DIR)/../include
OSAL_LINUX_INCLUDE_DIR=$(BASE_DIR)/../include/linux

KERNEL_COMPONENT=$(KERNEL_BUILD_DIR)


EXTRA_CFLAGS += -I$(PWD)
EXTRA_CFLAGS += -I$(BASE_DIR)/include/
EXTRA_CFLAGS += -I$(BASE_DIR)/core/smartcard/src
EXTRA_CFLAGS += -I$(BASE_DIR)/intel_gen3/smartcard/src
#EXTRA_CFLAGS += -I$(INCLUDE_DIR)
#EXTRA_CFLAGS += -I$(OSAL_LINUX_INCLUDE_DIR)
EXTRA_CFLAGS += -I$(BUILD_DEST)/include/linux
EXTRA_CFLAGS += -I$(BUILD_DEST)/include/
EXTRA_CFLAGS += -DIDL_DRIVER
EXTRA_CFLAGS += -DLINUX_DRIVER

MODULE_NAME:= idl_smartcard
TARGET      = idl_smartcard.ko

ifneq ($(KERNELRELEASE),)

obj-m := idl_smartcard.o
idl_smartcard-objs := idl_smartcard_drv.o ../../../intel_gen3/smartcard/src/_smartcard.o ../../../core/smartcard/src/idl_smartcard_core.o

empty     :=
space     := $(empty) $(empty)
KERNEL_VER_NUM:=$(lastword $(subst .,$(space),$(KERNEL_VER)))
ifeq ($(KERNEL_VER_NUM),23)
    $(shell cat $(BUILD_DEST)/kernel/module.symvers/* > ./Module.symvers)
else
    KBUILD_EXTRA_SYMBOLS := $(wildcard $(BUILD_DEST)/kernel/module.symvers/*)
endif

else

KERNELDIR ?= $(KERNEL_COMPONENT)
PWD       := $(shell pwd)

$(TARGET): idl_smartcard_drv.c ../../../intel_gen3/smartcard/src/_smartcard.c ../../../core/smartcard/src/idl_smartcard_core.c
	@-rm $(BUILD_DEST)/kernel/module.symvers/$(MODULE_NAME) 2> /dev/null
	make V=1 -C $(KERNEL_COMPONENT) SUBDIRS=$(PWD) modules 
	$(STRIP) -X -x -d idl_smartcard.ko
	@if [ ! -d $(BUILD_DEST)/kernel/module.symvers/ ]; then \
		mkdir $(BUILD_DEST)/kernel/module.symvers/ ; \
	fi
	@cp Module.symvers $(BUILD_DEST)/kernel/module.symvers/$(MODULE_NAME)

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.symvers
	rm -rf ../../../intel_gen3/smartcard/src/_smartcard.o
	rm -rf ../../../core/smartcard/src/idl_smartcard_core.o
	rm -rf ../../../intel_gen3/smartcard/src/.*.cmd
	rm -rf ../../../core/smartcard/src/.*.cmd
endif

