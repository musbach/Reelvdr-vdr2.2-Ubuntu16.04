#/*
#
#  This file is provided under a dual BSD/GPLv2 license.  When using or
#  redistributing this file, you may do so under either license.
#
#  GPL LICENSE SUMMARY
#
#  Copyright(c) 2008-2009 Intel Corporation. All rights reserved.
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
#  Copyright(c) 2008-2009 Intel Corporation. All rights reserved.
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

########################################################################
#
# Intel Corporation Proprietary Information
# Copyright (c) 2008-2009 Intel Corporation. All rights reserved.
#
# This listing is supplied under the terms of a license agreement
# with Intel Corporation and may not be used, copied, nor disclosed
# except in accordance with the terms of that agreement.
#
########################################################################
                                                                       
ifndef IDL_BASE
        export IDL_BASE=$(PWD)/../../../../
endif
include $(IDL_BASE)/idl/Makefile.inc

KBUILD_NOPEDANTIC = 1

ifndef VER1
VER1=9
VER2=9
VER3=9
VER4=9
VER=<Unofficial Build>
VERSION_NUMBER=<Unofficial Build>
endif

CFLAGS += -DVER1=$(VER1) -DVER2=$(VER2) -DVER3=$(VER3) -DVER4=$(VER4) -DVER="\"$(VER)\"" -DCOMPONENTNAME="\"$(COMPONENTNAME)\""


TARG_LIB = libidl_smartcard_core.a

LIB_OBJ_PVT = idl_smartcard.o
         
#CFLAGS += -I$(IDL_BASE)/$(TARGET)/include/linux_user
CFLAGS += -I$(IDL_BASE)/idl/include
CFLAGS += -I$(BUILD_DEST)/include/
CFLAGS += -I$(BUILD_DEST)/include/linux_user
CFLAGS += -I$(IDL_BASE)/idl/intel_gen3/smartcard/src
LDFLAGS += -l_smartcard -l$(TARG_LIB)

.PHONY: all
$(TARG_LIB):$(LIB_OBJ_PVT)
	mkdir -p $(outdir)/lib
	$(AR) $(ARFLAGS) $(TARG_LIB) $^
	cp $(TARG_LIB) $(outdir)/lib/

all: $(TARG_LIB)

$(LIB_OBJ_PVT): idl_smartcard_core.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean: 
	rm -f $(LIB_OBJ_PVT) $(TARG_LIB)
