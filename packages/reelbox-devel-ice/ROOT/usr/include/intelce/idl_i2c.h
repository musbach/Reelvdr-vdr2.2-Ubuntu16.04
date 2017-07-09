/*#
#  This file is provided under a BSD license.  When using or
#  redistributing this file, you may do so under this license.
#
#  BSD LICENSE
#
#  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
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

/*------------------------------------------------------------------------------
 * File Name: idl_i2c.h
 *------------------------------------------------------------------------------
 *
 */

#ifndef _IDL_I2C_H_
#define _IDL_I2C_H_

#ifdef __cplusplus
extern "C" {
#endif
//! \file
/** @weakgroup idl_i2c IDL I2C Functions

This module is a part of the Integrated Device Library (IDL), and it 
provides a low-level software interface between the on-chip Inter Integrated 
Circuit (I2C) bus interface unit and the application software or device driver.

The legacy IDL I2C driver does not support power management, and will not resume correctly after a Suspend-to-RAM.  By, default, the legacy driver is replaced in this release with the Linux driver, which is power-management compliant.
<BR/><BR/>     
A shim version of the IDL I2C API has been added to the IDL library. It preserves the most essential APIs but implements them with calls to the upstream driver.  This will allow clients to transition to the upstream driver.
<BR/><BR/>     
The following legacy IDL I2C functions are <b>deprecated</b> and are not provided in the shim:     
	
- idl_i2c_get_interrupt_mask()
- idl_i2c_get_pending_interrupts()
- idl_i2c_set_interrupt_mask()
- idl_i2c_wait_for_interrupts()
- idl_i2c_register_interrupt_handler()
- idl_i2c_release_interrupt_handler()
  
- idl_i2c_read()
- idl_i2c_read_async()
- idl_i2c_read_byte()
- idl_i2c_read_byte_without_dummy()
- idl_i2c_read_restart()
- idl_i2c_read_sub_addr_async()
- idl_i2c_read_sub_addr_ex_async()
- idl_i2c_read_write_async_wait()
  
- idl_i2c_write()
- idl_i2c_write_async()
- idl_i2c_write_byte()
- idl_i2c_write_restart()
- idl_i2c_write_sub_addr_async()
- idl_i2c_write_sub_addr_ex_async()

Calls to the highlighted functions can be replaced with calls to non-deprecated functions as indicated below (necessary changes are highlighted in this color):

- From: idl_i2c_read(bus, slave, buffer, count);
- To    : idl_i2c_read_sub_addr_ex(bus, slave, NULL, 0, buffer, count);

- From: idl_i2c_write(bus, slave, buffer, count);
- To    : idl_i2c_write_sub_addr_ex(bus, slave, NULL, 0, buffer, count);
 
- From: idl_i2c_read_restart(bus, slave, subaddr, buffer, count);
- To    : idl_i2c_read_sub_addr(bus, slave, subaddr, buffer, count);
 
- From: idl_i2c_write_restart(bus, slave, subaddr, buffer, count);
- To    : idl_i2c_write_sub_addr(bus, slave, subaddr, buffer, count);

The below APIs which are marked as the <b>Deprecated</b>  are eliminated, so use of deprecated functions in user code should be eliminated as soon as possible.
<HR>

@section idl_i2c_overview IDL I2C Overview

<B> I2C Bus </B><BR><BR>

The bus specification for Inter Integrated Circuit (I2C) was first defined in 
1992 with Version 1.0, and this overview of the bus is based on Version 2.1, 
which was released in 2000.

The I2C bus is a bi-directional, two-wire bus developed by Philips Corporation
to control and monitor mixed integrated circuit devices.  It can support 
multiple bus masters because it has the protocol to detect and arbitrate
between competing masters.  The bus can transfer data up to:

- 100 kilobits per second for standard (S) mode.
- 400 kilobits per second for fast (F) mode.
- 3.4 megabits per second for high-speed (Hs) mode.

The bus can support mixed-speed devices because the higher-speed devices are 
downward compatible with the lower-speed devices.  

The two wires defined in the I2C bus are:
-# <B> Serial Clock Line (SCL). </B>  The clock line is always generated by the 
   bus master.  Because of the wired-AND connections, it can be used to 
   synchronize with slow slaves or arbitrating masters.
-# <B> Serial Data / Address (SDA). </B>  The data line is used for 
   byte-oriented data transfers.  The data bytes are transmitted with the Most 
   Significant Bit (MSB) first, and there is no limit on the transfer size as 
   long as each byte is followed by an acknowledge bit from either the master 
   or the slave.

An I2C bus transaction is composed of the following sequence:
-# Master sets the START condition.  A START condition is initiated when SDA 
   transitions from high to low while SCL is held high.
-# Master sends the first byte, which is normally a 7-bit slave address followed 
   by a read/write bit.
-# The addressed slave then sends a one-bit acknowledgement (ACK).
-# Depending on the content of the first byte, the master may send additional
   but optional bytes to clarify the meaning of the first byte.  The slave then 
   acknowledges each subsequent byte.
-# If this is a master-transmit transaction, then the master sends one data 
   byte, and the slave sends back an ACK.  This is repeated until the completion
   of the write transfer.
-# If this is a master-receive transaction, then the slave sends back one data 
   byte, and the master sends an ACK.  This is repeated until the completion of 
   the read transfer.
-# Master can send a repeated START condition and follow up with the same 
   sequence described earlier.  This is so that the master can pick a different 
   device or to switch transmission direction.
-# To terminate the transaction, the master sets the STOP condition at the end 
   of a data transfer or bus error.  A STOP condition is initiated when SDA 
   transitions from low to high while SCL is held high.
-# The bus then returns to idle state when both SCL and SDA are released back
   to high.

Normally, the first byte of the bus transaction is a 7-bit slave address
followed by a read/write bit.  However, that byte can be used to support special
features with the following bit patterns:
- Slave address = 0000 000, read/write bit = 0, then it is a general call 
   address.  This is used to send a message to all devices in order to configure
   the programmable portion of the slave address for the attached devices.
- Slave address = 0000 000, read/write bit = 1, then it is a START byte.  Unless
   the on-chip I2C hardware interface has built-in interrupt mechanism to handle
   the bus errors, those error conditions are normally detected by slow software
   polling process.  This START-byte feature is used to allow the software to 
   poll at a lower rate until detection of such byte.
- Slave address = 0000 001, read/write bit = x, then it is a CBUS address.  This
   provides a mechanism to support an existing CBUS architecture.
- Slave address = 0000 010, read/write bit = x, then it is reserved for 
   different bus formats.
- Slave address = 0000 011, read/write bit = x, then it is reserved for future 
   purposes.
- Slave address = 0000 1xx, read/write bit = x, then it is Hs-mode master code.
   This is used to speed up arbitration during high-speed mode, where the unique
   bus master identification is transmitted while arbitrating.
- Slave address = 1111 1xx, read/write bit = x, then it is reserved for future 
   purposes.
- Slave address = 1111 0xx, read/write bit = x, then it is 10-bit slave 
   addressing.  The least significant two bits of the first byte are the most 
   significant two bits of the 10-bit address, and the next byte after the 
   acknowledge bit is the rest of the 10-bit address.

<HR>

<B> Scope </B><BR><BR>

This library has the following features and restrictions:
-# Supports master-only controller and doesn't respond to general calls.
-# Supports 7-bit slave addressing but not the 10-bit addressing.
-# Supports standard and fast modes but not the high-speed mode.

<HR>

@section idl_i2c_api_usage IDL I2C API Usage

\code

#include <idl_i2c.h>

#define MAX_DEVICES        10
#define MAX_BUFFER_BYTES   1024

int main(int argc, char **argv)
{
   idl_result_t result;
   uint8_t bus_num;
   uint8_t data_buffer[MAX_BUFFER_BYTES];

   if (idl_i2c_open() != IDL_SUCCESS) {
      printf("Failed to open\n");
      is_success = false;
   }

   if (idl_i2c_read(bus_num, 0x8e >> 1, data_buffer, 1)
      != IDL_SUCCESS) {
      printf("Failed to read\n");
      exit (-1);
   }

   if (idl_i2c_close() != IDL_SUCCESS) {
      printf("Failed to close\n");
      is_success = false;
   }

  exit(0);
 }

\endcode
*/

/** @defgroup idl_i2c_defs IDL I2C Definitions */
/** @ingroup idl_i2c_defs */
/*@{*/

#include <idl.h>
#include <osal.h>
#include <osal_interrupt.h>

/** Send only data onto the bus */
#define IDL_I2C_SEND_DATA                 0
/** Send START condition onto the bus */
#define IDL_I2C_SEND_START                (1 << 0)
/** Send STOP condition onto the bus */
#define IDL_I2C_SEND_STOP                 (1 << 1)
/** Send NACK acknowledgement bit */
#define IDL_I2C_SEND_NACK                 (1 << 2)

/** Read data from the bus */
#define IDL_I2C_SEND_READ                 1
/** Write data to the bus */
#define IDL_I2C_SEND_WRITE                0

/** Interrupt flag that is empty */
#define IDL_I2C_NO_INTERRUPT              0
/** Interrupt flag for losing arbitration */
#define IDL_I2C_ARBITRATION_LOSS          (1 << 5)
/** Interrupt flag for bus transmitter is empty */
#define IDL_I2C_TRANSMIT_EMPTY            (1 << 6)
/** Interrupt flag for bus receiver is full */
#define IDL_I2C_RECEIVE_FULL              (1 << 7)
/** Interrupt flag for bus error */
#define IDL_I2C_BUS_ERROR                 (1 << 10)

/** This enumeration lists the I2C operating modes */

typedef enum {
   IDL_I2C_MODE_STANDARD,                 /**< Standard mode up to 100 Kb/s */
   IDL_I2C_MODE_FAST                      /**< Fast mode up to 400 Kb/s */
} idl_i2c_mode_t;

/** This structure is the handle for the asynchronous I2C functions */

typedef struct {
   char dummy[128];
} idl_i2c_read_write_async_handle_t;

/*@}*/

/** @weakgroup idl_i2c IDL I2C Functions */
/** @ingroup idl_i2c */
/*@{*/

/**
This function gets the number of available I2C bus units within the system.
@param[out] *p_bus_count - Number of I2C bus units within system.
@retval IDL_SUCCESS is always returned.
*/

idl_result_t
idl_i2c_get_bus_count(uint8_t *p_bus_count);

/**
This function opens all I2C bus units within the system and resets them.
@retval IDL_SUCCESS if opened all bus units.
@retval IDL_ALREADY_INITIALIZED if already initialized or opened.
@retval IDL_FAILURE if couldn't allocate virtual page or couldn't set speed 
mode or reset individual units.
*/

idl_result_t
idl_i2c_open(void);

/**
This function closes all I2C bus units within the system and frees up 
allocated virtual page.
@retval IDL_SUCCESS if all bus units are closed.
@retval IDL_NOT_INITIALIZED if the bus units were not initialized or opened.
*/

idl_result_t
idl_i2c_close(void);

/**
This function sets the operating mode of a specified I2C bus unit.
<BR><BR> <b> In the shim implementation, this function is only a stub.</b>
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] mode - Operating mode.
@retval IDL_SUCCESS if the operating mode for the specified bus unit.
@retval IDL_INVALID_PARAM if bus_num is out of range.
@retval IDL_NOT_INITIALIZED if the bus units were not initialized or opened.
unit.
*/

idl_result_t
idl_i2c_set_mode(uint8_t bus_num, idl_i2c_mode_t mode);

/**
This function sets whether to poll during data accesses.
<BR><BR> <b> In the shim implementation, this function is only a stub.</b>
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] to_poll - Whether or not to poll.
@retval IDL_SUCCESS is always returned.
unit.
*/

idl_result_t
idl_i2c_enable_polling(uint8_t bus_num, bool to_poll);

/**
This function resets a specified I2C bus unit.
<BR><BR> <b> In the shim implementation, this function is only a stub.</b>
@param[in] bus_num - Index to identify an I2C bus unit.
@retval IDL_SUCCESS if the specified bus unit is reset.
@retval IDL_INVALID_PARAM if bus_num is out of range.
@retval IDL_NOT_INITIALIZED if the bus units were not initialized or opened.
@retval IDL_DEVICE_BUSY if I2C bus unit is busy.
@retval IDL_FAILURE if I2C bus unit is still busy after resetting unit or 
couldn't access registers.
*/

idl_result_t
idl_i2c_reset(uint8_t bus_num);

/*
This function reads one data byte from the bus while setting the appropriate
conditions as specified by control_flags.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] control_flags - OR'ed flags using IDL_I2C_SEND_STOP and 
IDL_I2C_SEND_ACK.
@param[in] interrupt_flags - OR'ed flags using:  IDL_I2C_RECEIVE_FULL and
IDL_I2C_TRANSMIT_EMPTY.
@param[in] wait_condition - Timed out in ms if interrupt-driven and number of
polling loops if polling.
@retval IDL_SUCCESS if one data byte is read.
@retval IDL_INVALID_PARAM if bus_num is out of range or control_flags contains
more than the allowed flags.
@retval IDL_NOT_INITIALIZED if the bus units were not initialized or opened.
@retval IDL_FAILURE if registers could not be accessed.
*/

idl_result_t
idl_i2c_read_byte_without_dummy(uint8_t bus_num, uint32_t control_flags, 
   uint8_t *p_data_byte, uint32_t interrupt_flags, uint32_t wait_condition);

/**
@deprecated 
This function reads one data byte from the bus while setting the appropriate
conditions as specified by control_flags. This fucntion is called by device which
need implement dummy read.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] control_flags - OR'ed flags using IDL_I2C_SEND_STOP and 
IDL_I2C_SEND_ACK.
@param[out] *p_data_byte - Data byte to be read.
@retval IDL_SUCCESS if one data byte is read.
@retval IDL_INVALID_PARAM if bus_num is out of range or control_flags contains
more than the allowed flags.
@retval IDL_NOT_INITIALIZED if the bus units were not initialized or opened.
@retval IDL_FAILURE if registers could not be accessed.
*/

idl_result_t
idl_i2c_read_byte(uint8_t bus_num, uint32_t control_flags, 
   uint8_t *p_data_byte);

/**
@deprecated 
This function writes one data byte to the bus while setting the appropriate
conditions as specified by control_flags.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] control_flags - OR'ed flags using: IDL_I2C_SEND_START, 
IDL_I2C_SEND_STOP, and IDL_I2C_SEND_ACK.
@param[in] data_byte - Data byte to be written.
@retval IDL_SUCCESS if one data byte is written.
@retval IDL_INVALID_PARAM if bus_num is out of range or control_flags contains
more than the allowed flags.
@retval IDL_NOT_INITIALIZED if the bus units were not initialized or opened.
@retval IDL_FAILURE if registers could not be accesed.
*/

idl_result_t
idl_i2c_write_byte(uint8_t bus_num, uint32_t control_flags, uint8_t data_byte);

/**
@deprecated 
This function sets the interrupt mask to enable or disable interrupts from 
the specified I2C bus unit, and it uses a semaphore to control access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] interrupt_mask - OR'ed flags using:  IDL_I2C_BUS_ERROR, 
IDL_I2C_RECEIVE_FULL, IDL_I2C_TRANSMIT_EMPTY, and IDL_I2C_ARBITRATION_LOSS.
@retval IDL_SUCCESS if set interrupt mask.
@retval IDL_INVALID_PARAM if bus_num is out of range or interrupt_flags 
contains more than the allowed flags.
@retval IDL_NOT_INITIALIZED if the bus units were not initialized or opened.
@retval IDL_FAILURE if registers could not be accesed.
*/

idl_result_t
idl_i2c_set_interrupt_mask(uint8_t bus_num, uint32_t interrupt_mask);

/**
@deprecated 
This function gets the interrupt mask to determine which interrupts are enabled
from the specified I2C bus unit, and it uses a semaphore to control access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[out] *p_interrupt_mask - OR'ed flags using:  IDL_I2C_BUS_ERROR, 
IDL_I2C_RECEIVE_FULL, IDL_I2C_TRANSMIT_EMPTY, and IDL_I2C_ARBITRATION_LOSS.
@retval IDL_SUCCESS if we acquired interrupt mask.
@retval IDL_INVALID_PARAM if bus_num is out of range or interrupt_flags 
contains more than the allowed flags.
@retval IDL_NOT_INITIALIZED if the bus units were not initialized or opened.
@retval IDL_FAILURE if couldn't access registers.
*/

idl_result_t
idl_i2c_get_interrupt_mask(uint8_t bus_num, uint32_t *p_interrupt_mask);

/**
This function determines if there are pending interrupts for the specified i2c
bus unit, and it uses a semaphore to control access.  This function will clear 
any pending interrupts.
@param[in] bus_num - Index to identify an I2C bus.
@param[out] *p_interrupt_flags - OR'ed flags using:  IDL_I2C_BUS_ERROR, 
IDL_I2C_RECEIVE_FULL, IDL_I2C_TRANSMIT_EMPTY, and IDL_I2C_ARBITRATION_LOSS.
@retval IDL_SUCCESS if got pending interrupts.
@retval IDL_INVALID_PARAM if bus_num is out of range.
@retval IDL_NOT_INITIALIZED if the bus units were not initialized or opened.
@retval IDL_FAILURE if couldn't access registers or has other spurious 
interrupts.
*/

idl_result_t
idl_i2c_get_pending_interrupts(uint8_t bus_num, uint32_t *p_interrupt_flags);

/**
@deprecated 
This function registers interrupt handler for the specified i2c
bus unit.  This will first release old interrupt handler.  Registering 
interrupt handler would result in reading and writing data using polling method
until the interrupt handler is unregistered.
@param[in] bus_num - Index to identify an I2C bus.
@param[in] *p_interrupt_handler - Interrupt handler function.
@param[in] *p_interrupt_data - Parameter for interrupt handler function.
@retval IDL_SUCCESS if registered interrupt handler.
@retval IDL_INVALID_PARAM if bus_num is out of range.
@retval IDL_NOT_INITIALIZED if the bus units were not initialized or opened.
@retval IDL_FAILURE if couldn't register interrupt handler.
*/

idl_result_t
idl_i2c_register_interrupt_handler(uint8_t bus_num, 
   os_interrupt_handler_t *p_interrupt_handler, void *p_interrupt_data);

/**
@deprecated 
This function releases interrupt handler for the specified i2c
bus unit.
@param[in] bus_num - Index to identify an I2C bus.
@retval IDL_SUCCESS if released interrupt handler.
@retval IDL_INVALID_PARAM if bus_num is out of range.
@retval IDL_NOT_INITIALIZED if the bus units were not initialized or opened.
*/

idl_result_t
idl_i2c_release_interrupt_handler(uint8_t bus_num);

/**
@deprecated 
This function waits for completion of interrupt handler for the specified i2c
bus unit.
@param[in] bus_num - Index to identify an I2C bus.
@param[in] interrupt_flags - OR'ed flags using:  IDL_I2C_RECEIVE_FULL and
IDL_I2C_TRANSMIT_EMPTY.
@param[in] wait_condition - Timed out in ms if interrupt-driven and number of
polling loops if polling.
@retval IDL_SUCCESS if handler completed before wait condition.
@retval IDL_TIMED_OUT if the wait condition expired before handler completed.
@retval IDL_FAILURE if couldn't detect handler completion.
*/

idl_result_t
idl_i2c_wait_for_interrupts(uint8_t bus_num, uint32_t interrupt_flags,
   uint32_t wait_condition);

/**
@deprecated 
This function should be replaced by: 
idl_i2c_read_sub_addr_ex(bus, slave, NULL, 0, buffer, count);

This function reads a buffer-full of data from the I2C bus unit.  It uses a 
semaphore to control access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[out] *p_data_buffer - Data buffer to store read data.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if read the full data buffer.
@retval IDL_FAILURE if couldn't read the full data buffer.
*/

idl_result_t
idl_i2c_read(uint8_t bus_num, uint16_t slave_addr, uint8_t *p_data_buffer, 
   uint32_t byte_count);

/**
@deprecated 
This function should be replaced by: 
idl_i2c_read_sub_addr(bus, slave, subaddr, buffer, count);

This function reads a buffer-full of data from the I2C bus unit by first writing
the slave_addr then repeated the start condition with a write of the 8-bit 
sub_addr (likely a register address within the slave device).  It uses a 
semaphore to control access.  This is an alias for idl_i2c_read_sub_addr() and 
will be removed in the future.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] sub_addr - 8-bit sub-address within slave device.
@param[out] *p_data_buffer - Data buffer to store read data.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if read the full data buffer.
@retval IDL_FAILURE if couldn't read the full data buffer.
*/

idl_result_t
idl_i2c_read_restart(uint8_t bus_num, uint16_t slave_addr, uint8_t sub_addr, 
   uint8_t *p_data_buffer, uint32_t byte_count);

/**
This function reads a buffer-full of data from the I2C bus unit by first writing
the slave_addr then repeated the start condition with a write of the 8-bit 
sub_addr (likely a register address within the slave device).  It uses a 
semaphore to control access.  This is an alias for idl_i2c_read_sub_addr() and 
will be deprecated in the future.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] sub_addr - 8-bit sub-address within slave device.
@param[out] *p_data_buffer - Data buffer to store read data.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if read the full data buffer.
@retval IDL_FAILURE if couldn't read the full data buffer.
*/

idl_result_t
idl_i2c_read_sub_addr(uint8_t bus_num, uint16_t slave_addr, uint8_t sub_addr, 
   uint8_t *p_data_buffer, uint32_t byte_count);

/**
This function reads a buffer-full of data from the I2C bus unit by first writing
the slave_addr then repeated the start condition with a write of the multi-byte 
sub_addr (likely a register address within the slave device).  It uses a 
semaphore to control access.  This is an alias for idl_i2c_read_sub_addr() and 
will be deprecated in the future.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] *p_sub_addr - Multi-byte sub-address within slave device.
@param[in] *sub_addr_byte_count - Number of bytes in the sub-address.
@param[out] *p_data_buffer - Data buffer to store read data.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if read the full data buffer.
@retval IDL_FAILURE if couldn't read the full data buffer.
*/

idl_result_t
idl_i2c_read_sub_addr_ex(uint8_t bus_num, uint16_t slave_addr, 
   uint8_t *p_sub_addr, uint32_t sub_addr_byte_count,
   uint8_t *p_data_buffer, uint32_t byte_count);

/**
This function writes a buffer-full of data to the I2C bus unit.  It uses a 
semaphore to control access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] *p_data_buffer - Data buffer with data to be written.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if wrote the full data buffer.
@retval IDL_FAILURE if couldn't write the full data buffer.
*/

idl_result_t
idl_i2c_write(uint8_t bus_num, uint16_t slave_addr, uint8_t *p_data_buffer, 
   uint32_t byte_count);

/**
This function writes a buffer-full of data from the I2C bus unit by first 
writing the slave_addr then the 8-bit sub_addr (likely a register address 
within the slave device).  It uses a semaphore to control access.  This is 
an alias for idl_i2c_write_sub_addr() and will be removed in the future.  
The use of _restart postfix does not mean that a repeated start condition 
will be added into the sequence.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] sub_addr - 8-bit sub-address within slave device.
@param[in] *p_data_buffer - Data buffer with data to be written.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if wrote the full data buffer.
@retval IDL_FAILURE if couldn't write the full data buffer.
*/

idl_result_t
idl_i2c_write_restart(uint8_t bus_num, uint16_t slave_addr, uint8_t sub_addr, 
   uint8_t *p_data_buffer, uint32_t byte_count);

/**
This function writes a buffer-full of data from the I2C bus unit by first 
writing the slave_addr then the 8-bit sub_addr (likely a register address 
within the slave device).  It uses a semaphore to control access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] sub_addr - 8-bit sub-address within slave device.
@param[in] *p_data_buffer - Data buffer with data to be written.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if wrote the full data buffer.
@retval IDL_FAILURE if couldn't write the full data buffer.
*/

idl_result_t
idl_i2c_write_sub_addr(uint8_t bus_num, uint16_t slave_addr, uint8_t sub_addr, 
   uint8_t *p_data_buffer, uint32_t byte_count);

/**
This function writes a buffer-full of data from the I2C bus unit by first 
writing the slave_addr then the multi-byte sub_addr (likely a register address 
within the slave device).  It uses a semaphore to control access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] *p_sub_addr - Multi-byte sub-address within slave device.
@param[in] *sub_addr_byte_count - Number of bytes in the sub-address.
@param[in] *p_data_buffer - Data buffer with data to be written.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if wrote the full data buffer.
@retval IDL_FAILURE if couldn't write the full data buffer.
*/

idl_result_t
idl_i2c_write_sub_addr_ex(uint8_t bus_num, uint16_t slave_addr, 
   uint8_t *p_sub_addr, uint32_t sub_addr_byte_count, uint8_t *p_data_buffer, 
   uint32_t byte_count);

/**
@deprecated 
This function waits for the completion of an asynchronous access.
@param[in] *p_async_handle - Handle for the asynchronous access.
@param[in] time_out_ms - Time (in ms) to wait before timing out.
@retval IDL_SUCCESS if successfully completed asynchronous access.
@retval IDL_FAILURE if couldn't complete asynchronous access.
*/

idl_result_t
idl_i2c_read_write_async_wait(idl_i2c_read_write_async_handle_t *p_async_handle,
   uint32_t time_out_ms);

/**
@deprecated 
This function reads a buffer-full of data from the I2C bus unit.  It uses a 
semaphore to control access.  This is the asynchronous version of 
idl_i2c_read, where a thread is kicked off to handle the processing.  Only one
thread should be active per bus.
@param[in,out] *p_async_handle - Handle for the asynchronous access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] *p_data_buffer - Data buffer to store read data.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if read the full data buffer.
@retval IDL_FAILURE if couldn't read the full data buffer.
*/

idl_result_t
idl_i2c_read_async(idl_i2c_read_write_async_handle_t *p_async_handle,
   uint8_t bus_num, uint16_t slave_addr, uint8_t *p_data_buffer, 
   uint32_t byte_count);

/**
@deprecated
This function reads a buffer-full of data from the I2C bus unit by first writing
the slave_addr then repeated the start condition with a write of the 8-bit 
sub_addr (likely a register address within the slave device).  It uses a 
semaphore to control access.  This is the asynchronous version of 
idl_i2c_read_restart, where a thread is kicked off to handle the processing.
Only one thread should be active per bus.
@param[in,out] *p_async_handle - Handle for the asynchronous access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] sub_addr - 8-bit sub-address within slave device.
@param[out] *p_data_buffer - Data buffer to store read data.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if read the full data buffer.
@retval IDL_FAILURE if couldn't read the full data buffer.
*/

idl_result_t
idl_i2c_read_sub_addr_async(idl_i2c_read_write_async_handle_t *p_async_handle, 
   uint8_t bus_num, uint16_t slave_addr, uint8_t sub_addr, 
   uint8_t *p_data_buffer, uint32_t byte_count);

/**
@deprecated 
This function reads a buffer-full of data from the I2C bus unit by first writing
the slave_addr then repeated the start condition with a write of the 8-bit 
sub_addr (likely a register address within the slave device).  It uses a 
semaphore to control access.  This is the asynchronous version of 
idl_i2c_read_restart, where a thread is kicked off to handle the processing.
Only one thread should be active per bus.
@param[in,out] *p_async_handle - Handle for the asynchronous access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] *p_sub_addr - Multi-byte sub-address within slave device.
@param[in] sub_addr_byte_count - Number of bytes in the sub-address.
@param[out] *p_data_buffer - Data buffer to store read data.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if read the full data buffer.
@retval IDL_FAILURE if couldn't read the full data buffer.
*/

idl_result_t
idl_i2c_read_sub_addr_ex_async(idl_i2c_read_write_async_handle_t 
   *p_async_handle, uint8_t bus_num, uint16_t slave_addr, uint8_t *p_sub_addr, 
   uint32_t sub_addr_byte_count, uint8_t *p_data_buffer, uint32_t byte_count);

/**
@deprecated 
This function writes a buffer-full of data to the I2C bus unit.  It uses a 
semaphore to control access.  This is the asynchronous version of 
idl_i2c_write, where a thread is kicked off to handle the processing.  Only one 
thread should be active per bus.
@param[in,out] *p_async_handle - Handle for the asynchronous access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] *p_data_buffer - Data buffer with data to be written.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if wrote the full data buffer.
@retval IDL_FAILURE if couldn't write the full data buffer.
*/

idl_result_t
idl_i2c_write_async(idl_i2c_read_write_async_handle_t *p_async_handle, 
   uint8_t bus_num, uint16_t slave_addr, uint8_t *p_data_buffer, 
   uint32_t byte_count);

/**
@deprecated 
This function writes a buffer-full of data to the I2C bus unit by first writing
the slave_addr then the 8-bit sub_addr (likely a register address within the 
slave device).  It uses a semaphore to control access.  This is the asynchronous 
version of idl_i2c_write_sub_addr, where a thread is kicked off to handle the 
processing.  Only one thread should be active per bus.
@param[in,out] *p_async_handle - Handle for the asynchronous access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] sub_addr - 8-bit sub-address within slave device.
@param[in] *p_data_buffer - Data buffer to store read data.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if read the full data buffer.
@retval IDL_FAILURE if couldn't read the full data buffer.
*/

idl_result_t
idl_i2c_write_sub_addr_async(idl_i2c_read_write_async_handle_t *p_async_handle, 
   uint8_t bus_num, uint16_t slave_addr, uint8_t sub_addr, 
   uint8_t *p_data_buffer, uint32_t byte_count);

/**
@deprecated 
This function writes a buffer-full of data to the I2C bus unit by first writing
the slave_addr then the multi-byte sub_addr (likely a register address within 
the slave device).  It uses a semaphore to control access.  This is the 
asynchronous version of idl_i2c_write_sub_addr_ex, where a thread is kicked off 
to handle the processing.  Only one thread should be active per bus.
@param[in,out] *p_async_handle - Handle for the asynchronous access.
@param[in] bus_num - Index to identify an I2C bus unit.
@param[in] slave_addr - Address of the slave device.
@param[in] *p_sub_addr - Multi-byte sub-address within slave device.
@param[in] sub_addr_byte_count - Number of bytes in the sub-address.
@param[in] *p_data_buffer - Data buffer to store read data.
@param[in] byte_count - Number of bytes in the data buffer.
@retval IDL_SUCCESS if read the full data buffer.
@retval IDL_FAILURE if couldn't read the full data buffer.
*/

idl_result_t
idl_i2c_write_sub_addr_ex_async(idl_i2c_read_write_async_handle_t 
   *p_async_handle, uint8_t bus_num, uint16_t slave_addr, uint8_t *p_sub_addr, 
   uint32_t sub_addr_byte_count, uint8_t *p_data_buffer, uint32_t byte_count);

/*@}*/

#ifdef __cplusplus
}
#endif

#endif
