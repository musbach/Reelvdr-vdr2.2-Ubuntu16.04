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
 * File Name:       idl_gpio.h
 * $Revision: 0.1 $
 *----------------------------------------------------------------------
 * 
 */

/** 
* @weakgroup idl_gpio IDL GPIO Functions
* IDL Interface for General Purpose Inputs/Outputs (GPIOs). 
*
* @section idl_gpio_overview IDL GPIO Overview
* This library provides a set of functions to access GPIOs on intel_gen3. 
*
* @section idl_gpio_audience Intended Audience
* This library is intended to be used by system designers, device driver 
* developers, and application developers.
* 
* @section idl_gpio_organization Organization
* The library is subdivided into three general categories:
* - Initialization/Cleanup
* - Configuration
* - Get/Set line state information
* .
* <B> Initialization/Cleanup </B> <br><br>
* These routines are responsible for allocating the resources needed to 
* access the GPIOs and to free up these resources when they are no longer
* needed. This API defines two functions in this category:
* -# idl_gpio_init() - Initialize system resources needed to access GPIO
* interface.
* -# idl_gpio_release() - Release the resourced allocated by idl_gpio_init().
* .
* <B> Configuration </B><br><br>
* These routines configure the different capabilities of the GPIOs.
* -# idl_gpio_line_config() - Configure the specified gpio to act as a data 
* line.
* -# idl_gpio_interrupt_config() - Configure the GPIO to act as an interrupt.
* line.
* -# idl_gpio_set_alt_function() - Set specified GPIO to its alternate 
* function.
* -# idl_gpio_register_interrupt_handler() - Specifies the function to be
* called when a GPIO interrupt occurs. 
* .
* <B> Get/Set routines </B><br><br>
* These routines get/set the data values of the GPIO lines, or read the GPIO
* interrupt status register.
* -# idl_gpio_get_line() - Reads the GPIO data line to determine its state.
* -# idl_gpio_set_line() - Outputs a 0 or 1 to the particular GPIO line.
* -# idl_gpio_interrupt_status() - Reads the interrupt state for a GPIO.
* -# idl_gpio_clear_interrupt() - Clears the specified GPIO bit in the 
* interrupt status register. 
* -# idl_gpio_set_glitch_filter() - Sets glitch filter settings.
* -# idl_gpio_set_edge_detector() - Enables/disables edge detector.
* .
* @section idl_gpio_api_usage IDL GPIO API Usage
* 
* <B>
* Example 1:
* Configure GPIO 73 as an input with inverted polarity.
* </B>
* 
* <CODE>
* idl_result_t status;<br>
* uint32_t line_val;
* 
* if ((status = idl_gpio_init()) != IDL_SUCCESS)
* {
* <I>
* <B>
* handle errors here
* </B>
* </I>
* }
* <br>
* if ((status = idl_gpio_line_config(73, IDL_GPIO_INPUT | IDL_GPIO_INVERT_POLARITY)) != IDL_SUCCESS)
* {
* <I>
* <B>
* handle errors here
* </B>
* </I>
* }
* 
* <I>
* <B>
* ...<br>sometime later, read the GPIO value<br>
* </B>
* </I>
* if ((status = idl_gpio_get_line(73, &line_val)) != IDL_SUCCESS)
* {
* <I>
* <B>
* handle errors here
* </B>
* </I>
* }
* 
* <I>
* <B>
* ...
* </B>
* </I>
* 
* <I>
* <B>
* when finished, release the GPIO device
* </B>
* </I>
* <br>idl_gpio_release();
* 
* </CODE>
* 
* <B>
* Example 2:
* Configure GPIO 3 to be an rising edge interrupt line
* </B>
* 
* <CODE>
* idl_result_t status;<br>
* uint32_t interrupt_status;
* 
* if ((status = idl_gpio_init()) != IDL_SUCCESS)
* {
* <I>
* <B>
* handle errors here
* </B>
* </I>
* }
* <br>
* if ((status = idl_gpio_interrupt_config(3, IDL_GPIO_RISING_EDGE)) != IDL_SUCCESS)
* {
* <I>
* <B>
* handle errors here
* </B>
* </I>
* }
* <br>
* <I>
* <B>
* 
* ...<br>
* Sometime later, after an interrupt<br>
* Read the interrupt status. 
* </B>
* </I>
* <br>
* if ((status = idl_gpio_interrupt_status(3, &interrupt_status)) != IDL_SUCCESS)
* {
* <I>
* <B>
* handle errors here
* </B>
* </I>
* }
* 
* <br>
* <I>
* <B>
* ...
* </B>
* </I>
* <br>
* 
*  <I>
* <B>
* when finished, release the GPIO device
* </B>
* </I>
* <br>idl_gpio_release();
* 
* </CODE>
* 
*
*
*/


#ifndef _IDL_GPIO_H_
#define _IDL_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "idl.h"
#include "osal_type.h"
#include "osal_interrupt.h"
//! \file
/** @defgroup idl_gpio_defs IDL GPIO Definitions */
/** @ingroup idl_gpio_defs */

/*@{*/

/***
* These defines are used to specify the type of GPIO configuration.
*/

/**
* Configure the GPIO for input 
*/
#define IDL_GPIO_INPUT				0

/**
* Configure the GPIO for output
*/
#define IDL_GPIO_OUTPUT				(1 << 0)

/**
* Configure the GPIO to invert polarity
*/
#define IDL_GPIO_INVERT_POLARITY		(1 << 1)

/**
* Configure the GPIO to alternate function
*/
//#define IDL_GPIO_INVERT_ALT	(1 << 2)

/** 
* This enumeration defines the different GPIO interrupt types. <BR><BR>
* The field IDL_GPIO_ACTIVE_HIGH_LEVEL indicates an active high level interrupt type.<BR>  
* The field IDL_GPIO_ACTIVE_LOW_LEVEL indicates an active low level interrupt type.<BR> 
* The field IDL_GPIO_RISING_UP_EDGE indicates a rising edge interrupt type.<BR> 
* The field IDL_GPIO_FALLING_DOWN_EDGE indicates an falling down edge interrupt type.<BR> 
*
*/
typedef enum {
	IDL_GPIO_ACTIVE_HIGH_LEVEL		= 0x0, /**< - Active high level interrupt */
	IDL_GPIO_ACTIVE_LOW_LEVEL		= 0x1, /**< - Active low level interrupt */
	IDL_GPIO_RISING_UP_EDGE			= 0x2, /**< - Rising up edge interrupt  */
	IDL_GPIO_FALLING_DOWN_EDGE		= 0x3, /**< - Falling down edge interrupt */
} idl_gpio_interrupt_type_t;

/**
* This enumeration is used to enable/disable the trigger positive
*/
typedef enum {
	IDL_GPIO_DISABLE_TRIGGER_POSITIVE  = 0x0, /**< - Disable trigger positive */
	IDL_GPIO_ENABLE_TRIGGER_POSITIVE   = 0x1,  /**< - Enable trigger positive */
} idl_gpio_trigger_positive_t;

/**
* This enumeration is used to enable/disable the trigger negative
*/
typedef enum {
	IDL_GPIO_DISABLE_TRIGGER_NEGATIVE  = 0x0, /**< - Disable trigger negative */
	IDL_GPIO_ENABLE_TRIGGER_NEGATIVE   = 0x1,  /**< - Enable trigger negative */
} idl_gpio_trigger_negative_t;

/*@}*/

/** @weakgroup idl_gpio IDL GPIO Functions
*/
/** @ingroup idl_gpio*/
/*@{
*/

/***
**Soc chipset judgment
***/
/**
* This functions implement the GPIO device suspend and resume opearton 
* @retval 0 if GPIO device supsended or resumed successfully.
* @retval -1 if GPIO device failed to be suspended or resumed. 
*/
int gpio_suspend(void);
int gpio_resume(void);

/**
* This function initializes the GPIO interface. This is the first function that should
* be called to begin using the GPIOs.
* @retval IDL_SUCCESS if GPIOs are initialized
* @retval IDL_NOT_INITIALIZED if system is unable to map GPIO register space or if the system is out of memory.
* @retval IDL_ALREADY_INITIALIZED - if GPIOs are already initialized
*/
idl_result_t idl_gpio_init(void);

/**
* This function configures a GPIO line. Depending on the capabilities of the particular
* GPIO, the direction may be specified. For multiplexed GPIOs, this automatically
* configures the signal to act as a GPIO.
* @param gpio_num - The number of the GPIO to configure.
* @param gpio_config - Configuration parameters for GPIOs. May be:
* - IDL_GPIO_INPUT
* - IDL_GPIO_OUTPUT
* 
* Examples: 
* -# To configure a GPIO for input, gpio_config should be: 
* IDL_GPIO_INPUT.
* -# To configure a GPIO for output, gpio_config should be: IDL_GPIO_OUTPUT
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number exceeds range, or if GPIO number selected does not support direction type.
* @retval IDL_NOT_INITIALIZED if GPIOs are not initialized. Call idl_gpio_init() to initialize the GPIOs.
*/
idl_result_t idl_gpio_line_config(uint32_t gpio_num, uint32_t gpio_config);

/**
* This function will set the pin associated with the gpio_num to its alternate 
* function. 
* @param gpio_num - The number of the GPIO to configure.
* @param fn_num - The alternate function number. If a pin has only one alternate 
* function, pass in 0. 
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number does not have an alternate function, or if the alternate 
* function number is invalid.
* @retval IDL_NOT_INITIALIZED if GPIOs are not initialized. Call idl_gpio_init() to initialize the GPIOs.
*/
idl_result_t idl_gpio_set_alt_function(uint32_t gpio_num, uint32_t fn_num);

/** 
* This function configures the type of interrupt that the GPIO line detects.
* @param gpio_num - The number of the GPIO to configure.
* @param interrupt_type - Specifies the type of interrupt. The following types 
* are currently supported:
* 
* - Active High Level Interrupt
* - Active Low Level Interrupt
* - Rising Up Edge Interrupt
* - Falling Down Edge Interrupt
* 
* See idl_gpio_interrupt_type_t enumeration for more information.
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number selected does not support interrupts or the specified interrupt type.
* @retval IDL_NOT_INITIALIZED if GPIOs are not initialized. Call idl_gpio_init() to initialize the GPIOs.
*/
idl_result_t idl_gpio_interrupt_config(uint32_t gpio_num, idl_gpio_interrupt_type_t interrupt_type);

/** 
* This function returns the value of the interrupt status bit for the specified GPIO. If interrupts have 
* not been configured for the specified GPIO, the value read is not defined.
* @param gpio_num - The number of the GPIO to get interrupt status for.
* @param interrupt_status - Value of the interrupt status for the specified GPIO. Will be 1 if interrupt is pending on GPIO; 0 otherwise.
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number selected does not support interrupts or the specified interrupt type.
* @retval IDL_NOT_INITIALIZED if GPIOs are not initialized. Call idl_gpio_init() to initialize the GPIOs.
*/
idl_result_t idl_gpio_interrupt_status(uint32_t gpio_num, uint32_t *interrupt_status);

/** 
* This function clears the interrupt for the specified GPIO.
* @param gpio_num - The number of the GPIO to clear.
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number selected does not support interrupts.
* @retval IDL_NOT_INITIALIZED if GPIOs are not initialized. Call idl_gpio_init() to initialize the GPIOs.
*/
idl_result_t idl_gpio_clear_interrupt(uint32_t gpio_num);

/** 
* This function registers an interrupt handler to be used by the GPIO.
* @param gpio_num - The number of the GPIO to register the interrupt handler for
* @param handler - The function to be called when the interrupt is trigger
* @param data -  A void pointer to be passed to the interrupt handler when the
* interrupt is triggered.
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number selected does not support interrupts.
* @retval IDL_NOT_INITIALIZED if the system was unable to register interrupts.
*/
idl_result_t idl_gpio_register_interrupt_handler(uint32_t gpio_num, os_interrupt_handler_t *handler, void *data);

/** 
* This function sets the line state for a GPIO line. 
* @param gpio_num - The number of the GPIO to set
* @param val - Value to write. Only the least significant bit is used, all other bits are ignored.
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
* @retval IDL_NOT_INITIALIZED if GPIOs are not initialized. Call idl_gpio_init() to initialize the GPIOs.
*/
idl_result_t idl_gpio_set_line(uint32_t gpio_num, uint32_t val);


/** 
* Reads the line state for the GPIO.
* @param gpio_num - The number of the GPIO to query
* @param val - Pointer to return value to write. Will be 0 if clear, 1 if set.
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
* @retval IDL_NOT_INITIALIZED if GPIOs are not initialized. Call idl_gpio_init() to initialize the GPIOs.
*/
idl_result_t idl_gpio_get_line(uint32_t gpio_num, uint32_t *val);

/**
* This function releases the OSAL interrupt handler. It always returns IDL_SUCCESS as 
* the underlying OSAL function does not return an error code.
* @param gpio_num - The number of the GPIO to free.
* @retval IDL_SUCCESS always
*/
idl_result_t 
idl_gpio_release_interrupt_handler(uint32_t gpio_num);


/**
* This function releases the GPIO interface. Call this function when you are through using GPIOs.
*/
void		 idl_gpio_release(void);

/** 
* This function sets the GPIO line to trigger positive mode. 
* @param gpio_num - The number of the GPIO to set
* @param setting - Value to write. Only the least significant bit is used, all other bits are ignored.
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
*/
idl_result_t idl_gpio_set_trigger_positive(uint32_t gpio_num, uint32_t setting);

/** 
* This function sets the GPIO line to trigger negative mode. 
* @param gpio_num - The number of the GPIO to set
* @param setting - Value to write. Only the least significant bit is used, all other bits are ignored.
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
*/
idl_result_t idl_gpio_set_trigger_negative(uint32_t gpio_num, uint32_t setting);

/** 
* This function sets the GPE for the GPIO. 
* @param gpio_num - The number of the GPIO to set
* @param setting - Value to write. Only the least significant bit is used, all other bits are ignored.
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
*/
idl_result_t idl_gpio_set_gpe(uint32_t gpio_num, uint32_t setting);

/** 
* This function sets the SMI for the GPIO. 
* @param gpio_num - The number of the GPIO to set
* @param setting - Value to write. Only the least significant bit is used, all other bits are ignored.
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
*/
idl_result_t idl_gpio_set_smi(uint32_t gpio_num, uint32_t setting);

/** 
* This function gets the trigger status value from the GPIO. 
* @param gpio_num - The number of the GPIO to set
* @param setting - point to return the ts value.
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
*/
idl_result_t idl_gpio_get_ts(uint32_t gpio_num, uint32_t *setting);

/** 
* This function clears the trigger status for the GPIO. 
* @param gpio_num - The number of the GPIO to set
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
*/
idl_result_t idl_gpio_clear_ts(uint32_t gpio_num);

/** 
* This function enables the interrupt mode for the GPIO. 
* @param gpio_num - The number of the GPIO to set
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
*/
idl_result_t idl_gpio_enable_interrupt(uint32_t gpio_num);

/** 
* This function disables the interrupt mode for the GPIO. 
* @param gpio_num - The number of the GPIO to set
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
*/
idl_result_t idl_gpio_disable_interrupt(uint32_t gpio_num);

/** 
* This function checks to see if the gpio number specified is a valid gpio on intel_gen3 or intel_gen4.5.
* @param gpio_num - The number of the GPIO to set
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
*/
idl_result_t idl_valid_gpio_num(uint32_t gpio_num);

/** 
* This function checks to see if the gpio number specified is a valid interrupt gpio on intel_gen3 or intel_gen4.5.
* @param gpio_num - The number of the GPIO to set
* @retval IDL_SUCCESS if successful.
* @retval IDL_INVALID_PARAM if GPIO number is invalid. 
*/
idl_result_t idl_gpio_supports_interrupts(uint32_t gpio_num);

void idl_gpio_event_create(void);
void idl_gpio_event_destroy(void);
void idl_gpio_event_set(unsigned long gpio_num);
int idl_gpio_wait_for_irq(unsigned int gpio_num);
void idl_gpio_irq_handler(int gpio);
void idl_gpio_irq_release(int val);
void idl_gpio_set_irq_params(unsigned long gpio_num);
idl_result_t idl_gpio_multi_soc_register_interrupt_handler(uint32_t gpio_num, os_interrupt_handler_t *handler);
uint32_t * idl_gpio_get_irq_params(unsigned long gpio_num);

#ifdef __cplusplus
}
#endif

#endif
/*@}*/

