# This file is provided under a dual BSD/LGPLv2.1 license.  When using 
# or redistributing this file, you may do so under either license.
#
# LGPL LICENSE SUMMARY
#
# Copyright(c) 2008-2011. Intel Corporation. All rights reserved.
#
# This program is free software; you can redistribute it and/or modify 
# it under the terms of version 2.1 of the GNU Lesser General Public 
# License as published by the Free Software Foundation.
#
# This library is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public 
# License along with this library; if not, write to the Free Software 
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 
# USA. The full GNU Lesser General Public License is included in this 
# distribution in the file called LICENSE.LGPL.
#
# Contact Information:
#     Intel Corporation
#     2200 Mission College Blvd.
#     Santa Clara, CA  97052
#
#
#  BSD LICENSE
#
#  Copyright(c) 2008-2011 Intel Corporation. All rights reserved.
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

########################################################################
#
# Intel Corporation Proprietary Information
# Copyright (c) 2008-2011 Intel Corporation. All rights reserved.
#
# This listing is supplied under the terms of a license agreement
# with Intel Corporation and may not be used, copied, nor disclosed
# except in accordance with the terms of that agreement.
#
########################################################################
                                                                       
ifndef IDL_BASE
        export IDL_BASE=$(PWD)/../../../../
endif
include ../../../Makefile.inc


ifndef VER1
VER1=9
VER2=9
VER3=9
VER4=9
VER=<Unofficial Build>
VERSION_NUMBER=<Unofficial Build>
endif

CFLAGS=-DFORMAT_ELF -O2 -Wuninitialized -D_INTERNAL_PCI_ -W -Wimplicit -Wreturn-type -Wswitch -Wcomment -Wformat -Wchar-subscripts -Wcast-qual
CFLAGS += -DVER1=$(VER1) -DVER2=$(VER2) -DVER3=$(VER3) -DVER4=$(VER4) -DVER="\"$(VER)\"" -DCOMPONENTNAME="\"$(COMPONENTNAME)\""


TARG_LIB = idl_smartcard_core

#APP_PVT_LIBS = \
#	idl_i2c \

LIB_OBJ_PVT = idl_smartcard.o
         
COMP_LIB_NAME = libidl_smartcard.a

COMP_LIBS = idl_smartcard_core

#CFLAGS += -I$(IDL_BASE)/$(TARGET)/include
#CFLAGS += -I$(IDL_BASE)/$(TARGET)/include/linux_user
CFLAGS += -I$(BUILD_DEST)/include/
CFLAGS += -I$(BUILD_DEST)/include/linux_user


CFLAGS += -I$(IDL_BASE)/idl/linux_driver/drv/smartcard
CFLAGS += -I$(IDL_BASE)/idl/intel_gen3/smartcard/src
CFLAGS += -I$(IDL_BASE)/idl/include
LDFLAGS += -l_smartcard -l$(TARG_LIB)

.PHONY: all
$(COMP_LIB_NAME):$(LIB_OBJ_PVT)
	mkdir -p $(outdir)/lib
	$(AR) $(ARFLAGS) $(COMP_LIB_NAME)  $(LIB_OBJ_PVT) 
	cp $(COMP_LIB_NAME) $(outdir)/lib/

all: $(COMP_LIB_NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean: 
	rm -f $(LIB_OBJ_PVT) $(COMP_LIB_NAME)

