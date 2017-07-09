/*----------------------------------------------------------------------------
 *    This file is provided under a dual BSD/GPLv2 license.  When using or 
 *    redistributing this file, you may do so under either license.
 *
 *    GPL LICENSE SUMMARY
 *
 *    Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
 *
 *    This program is free software; you can redistribute it and/or modify 
 *    it under the terms of version 2 of the GNU General Public License as
 *    published by the Free Software Foundation.
 *
 *    This program is distributed in the hope that it will be useful, but 
 *    WITHOUT ANY WARRANTY; without even the implied warranty of 
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
 *    General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License 
 *    along with this program; if not, write to the Free Software 
 *    Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *    The full GNU General Public License is included in this distribution 
 *    in the file called LICENSE.GPL.
 *
 *    Contact Information:
 *
 *    Intel Corporation
 *    2200 Mission College Blvd.
 *    Santa Clara, CA  97052
 *
 *    BSD LICENSE
 *
 *    Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
 *    All rights reserved.
 *
 *    Redistribution and use in source and binary forms, with or without 
 *    modification, are permitted provided that the following conditions 
 *    are met:
 *
 *      * Redistributions of source code must retain the above copyright 
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above copyright 
 *        notice, this list of conditions and the following disclaimer in 
 *        the documentation and/or other materials provided with the 
 *        distribution.
 *      * Neither the name of Intel Corporation nor the names of its 
 *        contributors may be used to endorse or promote products derived 
 *        from this software without specific prior written permission.
 *
 *    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 *    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *    OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 *    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 *    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *----------------------------------------------------------------------------*/

#ifndef CLOCK_CONTROL_H
#define CLOCK_CONTROL_H

#include "clock_control_types.h"

/**
    @file  clock_control.h
    @brief Interface for the Clock Control Module 
     
    This file details the API for setting and reading bit fields from the
    Clock and Reset Unit control registers.
*/

/**
 @mainpage Clock Control Component

    The Clock and Reset Unit of the SOC exposes a set of registers with
    individual bit fields allowing control of a variety of clocks, reset of
    various hardware units, and access to various strap settings.  The bit
    fields in a given register may be controlled by different software
    components.

    The purpose of the clock control component is to avoid races between
    components sharing a register, which could result in settings by one
    component being overwritten and lost due by a racing component.  It does
    little more than serialize and register accesses, making them atomic. It
    also hides the exact position and register in which a bit field can be
    found.

    But it still provides direct access to register fields, whose meanings (and
    existence) may change from SOC to SOC or even stepping to stepping. The
    caller is completely responsible for accessing the correct fields with the
    correct values for the current target SOC. ONLY DRIVERS WITH THIS KIND OF
    KNOWLEDGE SHOULD CALL THIS COMPONENT.  APPLICATIONS AND MIDDLEWARE SHOULD
    KEEP OUT.

@par Anatomy
    One interface is available from two different contexts: userspace and
    kernelspace. Both contexts use the same two function calls.\n
    \n
    The userspace interface consists of a shared library called
    libclock_control.so.  The library uses a device node named "clock_control"
    to access the kernel module through ioctl calls.\n
    \n
    The kernelspace interface is facilitated by a direct interface to the kernel
    module. 

@par Usage
    An enumeration (clock_control_resource_t) is provided  specifying each of
    the clock control bit fields ('resources') that clients can read and/or
    modify.  Clients pass one of these resource IDs when asking to read or
    write a bit field.\n
    \n
    The Clock Control component is designed for simultaneous access by multiple
    clients.  A boolean argument is exposed in APIs to indicate whether the
    library should wait for the control registers to become available or to
    return immediately (aborting the requested access) if the registers are
    currently locked for access by another process.\n

@par Building
    To use this component in either context, include clock_control.h from
    client source code. From userspace it is also necessary to link against
    libclock_control.so.
 
@par Runtime
    Kernel space clients must be loaded after loading the clock_control.ko
    module.  must be loaded in the kernel.\n
    \n
    User space clients are also dependent on the kernel module being loaded.
    In addition, the device node /dev/clock_control must have been created.
*/

/** Component is incompatible with clients built against different major version
 */
#define CC_VERSION_MAJOR  11
/** Component is backward-compatible with clients built against lower minor
 *  version, but not with clients built with higher minor version
 */
#define CC_VERSION_MINOR  0
#define CC_VERSION ((CC_VERSION_MAJOR << 24) | (CC_VERSION_MINOR << 16))


#ifdef DOXYGEN_SKIP // This is for the doxygen

/**
 This function returns the current value of a within a clock control register. 

 It uses a semaphore to serialize access by clients, and so cannot be called
 from an interrupt context or while holding a spinlock.

 @param [in] resource
    The bit field to be read.
 @param [out] value
    The current value of the field is returned here.
 @param [in] block_flag
    CLOCK_TRUE (the normal value) indicates the call should block if necessary
    until all preceding client calls complete.
    CLOCK_FALSE causes an immediate return with the value CLOCK_BUSY if other
    clients are already queued or executing; no changes were made to the 
    clock registers and the caller will need to try again later.
 @return Indicates whether the request completed successfully.
 */
clock_control_ret_t clock_control_read(clock_control_resource_t resource, 
                                       unsigned int            *value, 
                                       clock_control_bool_t     block_flag);

/**
 This function sets the current value of a bitfield within a clock control
 register. 

 It uses a semaphore to serialize access by clients, and so cannot be called
 from an interrupt context or while holding a spinlock.

 @param [in] resource
    The bit field to be set.
 @param [in] value
    This value to which the field is to be set.
 @param [in] block_flag
    CLOCK_TRUE (the normal value) indicates the call should block if necessary
    until all preceding client calls complete.
    CLOCK_FALSE causes an immediate return with the value CLOCK_BUSY if other
    clients are already queued or executing; no changes were made to the 
    clock registers and the caller will need to try again later.

 @return Indicates whether the request completed successfully.
 */
clock_control_ret_t clock_control_write(clock_control_resource_t resource, 
                                        unsigned int             value, 
                                        clock_control_bool_t     block_flag);

#else // This is for the actual use

clock_control_ret_t _clock_control_read(unsigned int               version,
                                        clock_control_resource_t   resource, 
                                        unsigned int             * value, 
                                        clock_control_bool_t       block_flag);

#define clock_control_read(resource, value, block_flag) \
    _clock_control_read(CC_VERSION, resource, value, block_flag)

clock_control_ret_t _clock_control_write(unsigned int             version,
                                         clock_control_resource_t resource, 
                                         unsigned int             value, 
                                         clock_control_bool_t     block_flag);

#define clock_control_write(resource, value, block_flag) \
    _clock_control_write(CC_VERSION, resource, value, block_flag)

#endif // DOXYGEN_SKIP

#endif //CLOCK_CONTROL_H
