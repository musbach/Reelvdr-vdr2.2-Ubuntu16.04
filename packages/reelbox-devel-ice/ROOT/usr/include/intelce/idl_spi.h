/*
#
#  This file is provided under a BSD license.  When using or
#  redistributing this file, you may do so under this license.
#
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

/*----------------------------------------------------------------------
 * File Name:       idl_spi.h
 * $Revision: 0.1 $
 *----------------------------------------------------------------------
 *
 */


/** @weakgroup idl_spi IDL SPI Functions
* IDL Interface for synchronous serial port (SPI). 
*
* The legacy IDL SPI driver does not support power management, and will not resume correctly after a Suspend-to-RAM.  The legacy driver is being replaced with the upstream open-source Linux driver, which is power-management compliant.
* <BR/><BR/>
* A shim version of the IDL SPI API has been added to the IDL library. It preserves the most essential APIs but implements them with calls to the upstream driver. This will allow clients to transition to the upstream driver.
* <BR/><BR/>
* The following IDL SPI functions are deprecated and are not provided in the shim:
* 	
* - idl_spi_set_event_callback()
* - idl_spi_event_enable()
* - idl_spi_event_disable()
* 
* The below APIs which are marked as the <b>Deprecated</b> are eliminated, so use of deprecated functions in user code should be eliminated as soon as possible.
* 
* @section idl_spi_overview IDL SPI Overview
* This library provides a set of functions to control and transmit data 
* through synchronous serial port hardware
*
* @section Intended Audience
* This library is for use by system designers, device driver developers, 
* and application developers.
* 
* @section Organization
* The library is subdivided into the general categories:
* - Initialization/Cleanup
* - Configuration/Status
* - Read/Write
* .
* <B> Initialization/Cleanup </B> <br><br>
* These routines are responsible for allocating the resources needed to 
* access the synchronous serial port and to free up these resources when 
* they are no longer needed. There are two functions in this category:
* -# idl_spi_init() - Initialize system resources needed to access the spi
* interface.
* -# idl_spi_release() - Release the resources allocated by idl_spi_init().
* .
* <B> Configuration/Status </B><br><br>
* These routines configure the capabilities and query the status of the 
* SPI interface.
* -# idl_spi_set_config() - Configure the SPI interface.
* -# idl_spi_get_status() - Queries the status of the SPI interface.
* .
* <B> Event Handling and Support </B><br><br>
* -# idl_spi_set_event_callback() - Set the function to call when an event
* occurs within the SPI interface.
* -# idl_spi_event_enable() - Enable one or more events that the device can 
* trigger.
* -# idl_spi_event_disable() - Disable one or more events that the are 
* currently enabled.
* .
* <B> Read/Write routines </B><br><br>
* These routines read data from and write data to the SPI interface.
* -# idl_spi_read() - Reads data from the SPI interface.
* -# idl_spi_write() - Writes data to the SPI interface.
* .
* @section idl_spi_api_usage IDL SPI API Usage
* 
* <B>
* Example 1:
* Configure SPI 73 as an input with inverted polarity.
* </B>
* 
* \code
* #include idl_spi.h
* 
* #define PORT 0
*
* void my_spi_setup() 
* {
* idl_result_t status;<br>
* uint32_t line_val;
* spi_config_t spi_config;
* 
* status = idl_spi_init(PORT);
* if (status != IDL_SUCCESS) {
* <I>
* <B>
* handle errors here
* </B>
* </I>
* }
* 
* spi_config.clock_rate   = 1843200;
* spi_config.data_size    = 16;
* spi_config.frame_format = MOTOROLA_SPI;
* spi_config.rx_threshold = 8;
* spi_config.tx_threshold = 0;
* spi_config.spi_phase    = PHASE_HALF_ONE;
*
* <br>
* status = idl_spi_config(PORT, &spi_config); 
* if (status != IDL_SUCCESS) {
* <I>
* <B>
* handle errors here
* </B>
* </I>
* }
* 
* status = idl_spi_set_event_callback(PORT, my_spi_event_handler, NULL);
* if (status != IDL_SUCCESS) {
* <I>
* <B>
* handle errors here
* </B>
* </I>
* }
* 
* status = idl_spi_event_enable(PORT, SPI_EVENT_RX_THRESHOLD | SPI_EVENT_TX_THRESHOLD);
* if (status != IDL_SUCCESS) {
* <I>
* <B>
* handle errors here
* </B>
* </I>
* }
*
* <I>
* <B>
* Allow my_spi_event_handler to process all SPI data.  Some synchronization my be required.
* </B>
* </I>
* 
* status = idl_spi_release(PORT);
* if (status != IDL_SUCCESS) {
* <I>
* <B>
* handle errors here
* </B>
* </I>
* }
*
* return;
* }
* \endcode
*/


#ifndef _IDL_SPI_H_
#define _IDL_SPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef IDL_DRIVER
//#include "stdbool.h"
#include "stdint.h"
#endif

#include "idl.h"
//! \file
/** @defgroup idl_spi_defs IDL SPI Definitions */
/** @ingroup idl_spi_defs */

/*@{*/

/** SPI frame format protocols */
typedef enum {
	MOTOROLA_SPI          = 0,  /**< Motorola SPI                     */
	TEXAS_INSTRUMENTS_SSP = 1,  /**< Texas Instruments SSP            */
	NATIONAL_MICROWIRE    = 2   /**< National Semiconductor Microwire */
} spi_frame_t;


/** SPI phase types */
typedef enum {
	PHASE_HALF_ONE = 0, /**< Serial clock inactive one-half clock before frame, and one clock after frame */
	PHASE_ONE_HALF = 1  /**< Serial clock inactive one clock before frame, and one-half clock after frame */
} spi_phase_t;


//#define USE_POLARITY
typedef enum {
	INACTIVE_LOW  = 0, /**< Clock signal is low while inactive/idle */
	INACTIVE_HIGH = 1  /**< Clock signal is high while inactive/idle */
} spi_polarity_t;


/** SPI event type: can represent one or more events OR'ed together */
typedef uint32_t spi_event_t;

#define SPI_EVENT_NONE         0          /**< No events */
#define SPI_EVENT_RX_THRESHOLD (1 << 0)   /**< Receive threshold reached */
#define SPI_EVENT_TX_THRESHOLD (1 << 1)   /**< Transmit threshold reached */
#define SPI_EVENT_RX_OVERRUN   (1 << 2)   /**< Receiver overrun (data has been lost) */
#define SPI_EVENT_ALL  (SPI_EVENT_RX_THRESHOLD|SPI_EVENT_TX_THRESHOLD|SPI_EVENT_RX_OVERRUN)  /**< All events OR'ed together */


/** SPI Configuration Parameters */
typedef struct {
	uint32_t       clock_rate;    /**< Clockrate or bit rate */
	uint32_t       data_size;      /**< Number of data bits in each frame */
	spi_frame_t    frame_format;   /**< Frame format/protocol */
	spi_polarity_t clock_polarity; /**< Inactive clock polarity */
	uint32_t       rx_threshold;   /**< Receive FIFO threshold */
	uint32_t       tx_threshold;   /**< Transmit FIFO threshold */
	spi_phase_t    phase;          /**< Phase type */
	uint32_t       chip_select;    /**< Chip select line */
} spi_config_t;


/** SPI Status Indicators */
typedef struct {
	uint32_t    rx_fifo_size;    /**< Size of the receive FIFO */
	uint32_t    tx_fifo_size;    /**< Size of the transmit FIFO */
	uint32_t    rx_fifo_level;   /**< Current receive FIFO level */
	uint32_t    tx_fifo_level;   /**< Current transmit FIFO level */
	spi_event_t	event_status;    /**< Events currently pending in the device */
	spi_event_t	events_enabled;  /**< Events currently enabled out of the device */
} spi_status_t;

/** SPI event callback function is the prototype for a user function that can be invoked when an SPI event occurs. */
typedef void (*spi_callback_t)( void *callback_data );

/*@}*/


/** @weakgroup idl_spi IDL SPI Functions
*/
/** @ingroup idl_spi*/
/*@{
*/


/**
* This function initializes the specified SPI port. This function should be called before 
* calling any other SPI functions.  Note that it cannot be used to reinitialize the port.
* For this case, users must call idl_spi_release before calling idl_spi_init again.
*
* @param port_num - Numerical identifier of the port to initialize.  Each SPI port in
* the platform has a unique identifier from 0 to N, where N is the number of ports 
* supported in the hardware implementation.
*
* @retval IDL_SUCCESS if SPI port initialization succeeds.
* @retval IDL_ERROR_NO_RESOURCES if there are not enough available resources to initialize the SPI port.
* @retval IDL_ERROR_INVALID_PARAMETER if the port number is ouside the range of valud port numbers.
* @retval IDL_ERROR_ALREADY_INITIALIZED if SPI port is already initialized
*/
idl_result_t idl_spi_init(uint32_t port_num);


/**
* This function releases all resources allocated when initializing the specified port
*
* @param port_num - The SPI port number.
* 
* @retval IDL_SUCCESS if release of port is successful.
* @retval IDL_INVALID_PARAM if the port number is not valid.
* @retval IDL_NOT_INITIALIZED if the specified port has not been initialized.
*/
idl_result_t idl_spi_release(uint32_t port_num);


/** 
* This function configures the physical properties of the specified SPI port.
*
* @param port_num - The SPI port number.
* @param config - A structure containing all of the configuration parameters for the port.  See the 
* definition of the spi_config_t structure for more information on the configuration parameters.
*
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if port number or any of the elements of the spi_config structure are not valid.
* @retval IDL_NOT_INITIALIZED if the specified port has not been initialized.
*/
idl_result_t idl_spi_set_config(uint32_t port_num, spi_config_t *config);



/** 
* This function retrieves the status of the specified SPI port. The status may be used to 
* to determine how to respond to an event generated by the port.  See the definition of the 
* spi_status_t structure for more information on the status indicators.
* <BR> <BR> <b> In the shim implementation, this function is only a stub.</b>
*
* @param port_num - The SPI port number.
* @param spi_status - A structure containing the status indicators for the specified port. See 
* the definition of the spi_status_t structure for more information on the status items.
*
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if the port number is not valid.
* @retval IDL_NOT_INITIALIZED if the specified port has not been initialized.
*/
idl_result_t idl_spi_get_status(uint32_t port_num, spi_status_t *spi_status);


/**
* @deprecated 
* This function specifies the user function that should be called when the SPI port
* generates an event. For example, when the receive FIFO level is above a previously 
* defined threshold.  To disable event callbacks, call this function again with the 
* callback_function parameter set to NULL.
*
* @param port_num - The SPI port number.
* @param callback_function - Pointer to the function that should be called when the specified 
* SPI port generates an event.
* @param callback_data - A pointer to user data.  This pointer will be passed unmodified into the 
* callback function (see the definition of spi_callback_t for parameters.  The callback function 
* may use this parameter to access user data.
*
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if the port number is not valid.
* @retval IDL_NOT_INITIALIZED if the specified port has not been initialized.
*/
idl_result_t idl_spi_set_event_callback(uint32_t port_num, spi_callback_t callback_function, void *callback_data);


/** 
* @deprecated 
* This function enables an event for the specified port.  This function must be called to 
* enable event callbacks to the callback function.
*
* @param port_num - The SPI port number
* @param events - The events to enable.
*
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if the port number or the event is not valid.
* @retval IDL_NOT_INITIALIZED if the specified SPI has not been initialized.
*/
idl_result_t idl_spi_event_enable(uint32_t port_num, spi_event_t events);


/**
* @deprecated 
* This function disables an event for the specified port.  The callback function will no 
* longer be called for this event until the event is enabled again.
*
* @param port_num - The number of the SPI port.
* @param events - The events to disable.
*
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if the port number or the event is not valid.
* @retval IDL_NOT_INITIALIZED if the specified SPI has not been initialized.
*/
idl_result_t idl_spi_event_disable( uint32_t port_num, spi_event_t events );

#if 0
/*
* This function notifies the interface that events have been handled.  When
* an event is triggered in the SPI interface, the event is disabled until 
* it is serviced.  This function is typically called by the callback function 
* after it services the event.
*
* @param port_num - The number of the SPI port.
* @param spi_event - The events that have been handled.
*
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if the port number or the event is not valid.
* @retval IDL_NOT_INITIALIZED if the specified SPI has not been initialized.
*/
idl_result_t idl_spi_event_handled( uint32_t port_num, spi_event_t spi_event );
#endif

/** 
* This function writes one data element to the specified SPI port.  The size of the data must be 
* set in idl_spi_config().
*
* @param port_num - The number of the SPI port.
* @param data -  The data to write to the specified port.  The data must be in the least 
* significant bits of this parameter.
*
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if the port number is not valid.
* @retval IDL_NOT_INITIALIZED if the specified SPI has not been initialized.
*/
idl_result_t idl_spi_write(uint32_t port_num, uint32_t data);


/** 
* This function reads one data element from the specified SPI port.
*
* @param port_num - The number of the SPI port.
* @param data - A pointer to a buffer where the data should be stored.  This buffer must be 
* 32-bit aligned.  The data read will be in the least significant bits of this buffer.
*
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if the port number is not valid.
* @retval IDL_NOT_INITIALIZED if the specified SPI has not been initialized.
*/
idl_result_t idl_spi_read(uint32_t port_num, uint32_t *data);


#ifdef __cplusplus
}
#endif

#endif
/*@}*/
