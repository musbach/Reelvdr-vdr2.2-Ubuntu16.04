/*---------------------------------------------------------------------------
 * File Name: libdts.h
 *--------------------------------------------------------------------------/
/****************************************************************************
 * Copyright (c) 2008-2009 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************/

#ifndef _LIB_DTS_H_
#define _LIB_DTS_H_

#if defined(__ARM__)
	#include "idl.h"
	#include "idl_gpio.h"
	#include "libgdl.h"
#elif defined(PLAT_CE31XX)
	#include "idl.h"
	#include "idl_gpio.h"
	#include "gdl.h"
	#include <sys/io.h>
	#include "pal.h"
#endif

#ifdef _WIN32
	typedef BOOL bool;
	#define true 1
	#define false 0

	#define stricmp _stricmp
	#define strnicmp _strnicmp
	#define SLEEP(x)	Sleep(x)
#else
	#define stricmp strcasecmp
	#define strnicmp strncasecmp
	#define SLEEP(x)	usleep(x * 1000)
	typedef unsigned long long int uint64_t;
#endif

// Constants
#define COLOR_WHITE     "\033[1;37m"
#define COLOR_RED       "\033[1;31m"
#define COLOR_RESET     "\033[0m"

#define MAX_DISPLAY_BUFFER		2048
#define MAX_DISPLAY_LINE		80
#define MAX_ERROR_SZ			0x400

// Verbose
#define V_SPECIAL_LEVEL		0x10000
#define V_DEBUG_LEVEL		0x01000
#define V_PASS_LEVEL		0x00100
#define V_PROGRESS_LEVEL	0x00010
#define V_INFO_LEVEL		0x00001

// Colors
#define BLACK   0
#define BLUE    (0x3ff)
#define GREEN   (0x3ff<<10)
#define RED     (0x3ff<<20)
#define WHITE   ((0x3ff<<20) | (0x3ff<<10) | (0x3ff))
#define YELLOW	RED |GREEN

extern char* g_szDTSErrMsgs[];

// Configure the GPIO for output
#define GPIO_NORMAL_POLARITY	(1 << 0)
// Configure the GPIO to invert polarity
#define GPIO_INVERT_POLARITY	(1 << 1)
	
//#ifdef __ARM__
	#define OR_IRQ_BASE				0xFFFE0000
	#define OR_IRQ_SIZE				0x100
	#define OR_IRQ_27_CONFIG		0xBC

	#define OR_NUM_GPIO_PINS		104

	#define OR_GPIO_BASE			0xFFFE0400
	#define OR_GPIO_SIZE			0x100

	#define OR_GPIO_IRQ				27

	#define OR_GPIO_NUM_MIN			0
	#define OR_GPIO_NUM_MAX			OR_NUM_GPIO_PINS - 1 // 0 based count

	// Starting point for the different GPIO groups on ARM based platforms
	#define OR_GPIO_GROUP_ZERO		0
	#define OR_GPIO_GROUP_ONE		8
	#define OR_GPIO_GROUP_TWO		40
	#define OR_GPIO_GROUP_THREE		72

	#define OR_GPIO_GROUP_MAX		4

	/* GPIO Unit Register Map */
	/* GPIOs 0-7 */
	/* GPIO Group 0 - Dedicated GPIOs with Interrupt capability */
	#define OR_GPIO0_GPOUTR		0x00	// GPIO 0:7 pin data output register
	#define OR_GPIO0_GPOER		0x04	// GPIO 0:7 pin output enable register
	#define OR_GPIO0_GPINR		0x08	// GPIO 0:7 pin input register
	#define OR_GPIO0_GPSTR		0x0C	// GPIO 0:7 interrupt status register
	#define OR_GPIO0_GPIT1R		0x10	// GPIO 0:7 interrupt type and control register

	/* GPIO Group 1 - General Purpose Input/Outputs with polarity and Pin function control */
	/* GPIOs 8 to 39 */
	#define OR_GPIO1_GPOUTR		0x20	// GPIO 8:39 pin data output register  
	#define OR_GPIO1_GPOER		0x24	// GPIO 8:39 pin output enable register
	#define OR_GPIO1_GPINR		0x28	// GPIO 8:39 pin input register
	#define OR_GPIO1_GPPOL		0x2C	// GPIO 8:39 pin I/O polarity register
	#define OR_GPIO1_GPALT		0x30	// GPIO 8:39 pin gpio/alternate function selection register

	/* GPIO Group 2 – General Purpose Input/Outputs with polarity and Pin function control */
	/* GPIOs 40 to 71 */
	#define OR_GPIO2_GPOUTR		0x40	// GPIO 40:71 pin data output register  
	#define OR_GPIO2_GPOER		0x44	// GPIO 40:71 pin output enable register
	#define OR_GPIO2_GPINR		0x48	// GPIO 40:71 pin input register
	#define OR_GPIO2_GPPOL		0x4C	// GPIO 40:71 pin I/O polarity register
	#define OR_GPIO2_GPALT		0x50	// GPIO 40:71 pin gpio/alternate function selection register

	/* GPIO Group 3 - – General Purpose Input/Outputs with polarity and Pin function control */
	/* GPIOs 72 to 103 */
	#define OR_GPIO3_GPOUTR		0x60	// GPIO 72:103 pin data output register  
	#define OR_GPIO3_GPOER		0x64	// GPIO 72:103 pin output enable register
	#define OR_GPIO3_GPINR		0x68	// GPIO 72:103 pin input register
	#define OR_GPIO3_GPPOL		0x6C	// GPIO 72:103  pin I/O polarity register
	#define OR_GPIO3_GPALT		0x70	// GPIO 72:103 pin gpio/alternate function selection register

	#define TEST_MODE_NONE			0x0
	#define TEST_MODE_ENC_ETP1		0x1
	#define TEST_MODE_ENC_ETP2		0x2
	#define TEST_MODE_ENC_ETP3		0x3
	#define TEST_MODE_ENC_ETP4		0x4
	#define TEST_MODE_ENC_ETP5		0x5
	#define TEST_MODE_UNUSED		0x6
	#define TEST_MODE_DAC_MD		0x7
	#define TEST_MODE_DAC_T1		0x8
	#define TEST_MODE_DAC_T2		0x9
	#define TEST_MODE_DAC_T3		0xA
	#define TEST_MODE_DAC_T4		0xB
	#define TEST_MODE_DAC_T5		0xC
	#define TEST_MODE_DAC_T6		0xD
	#define TEST_MODE_DAC_T7		0xE
	#define TEST_MODE_DAC_T8		0xF
//#elif defined(PLAT_GEN5)

	#define CM_NUM_GPIO_PINS		26

	#define CM_GPIO_MEM_BASE		0xDFFE0400
	#define CM_GPIO_IO_BASE			0x0
	#define CM_GPIO_MEM_SIZE		256
	#define CM_IRQ_BASE				0xFEC00000
	#define CM_IRQ_SIZE				256
	#define CM_IRQ_MASK_OFFSET		0x80
	#define CM_GPIO_IRQ_MASK_OFFSET	15

	#define CM_GPIO_IRQ				27
	#define CM_GPIO_NUM_INT			12

	#define CM_GPIO_NUM_MIN			0
	#define CM_GPIO_NUM_MAX			CM_NUM_GPIO_PINS - 1 // 0 based count

	// Starting points for the different GPIO Wells on Intel_CM
	#define CE31XX_GPIO_GROUP_ZERO   0  // GPIOAUX [0-11]   Aux (in Core Well)
	#define CE31XX_GPIO_GROUP_ONE	12	// GPIO [0-9]		Core Well
	#define CE31XX_GPIO_GROUP_TWO	15	// GPIO [0-9]		Core Well
	#define CE31XX_GPIO_GROUP_THREE	22	// GPIOSUS [0-4]	Resume Well

	#define CE31XX_GPIO_GROUP_MAX 4

	/* AUX Well - GPIO Group 0															 */
	/* 1.3 - GPIO Unit Registers (CM_PUB_GPIO.doc)				                         */
	/* GP0 – GP11						                                                 */
	/* These GPIOs are in the Core Well and are implemented in the PUB GPIO unit.        */
	#define CM_GPIO0_GPOUTR		0x00	// 00	23	GPOUTR   - GPIO 0:11 pin Data Output Register
	#define CM_GPIO0_GPOER		0x04	// 04	27	GPOER    - GPIO 0:11 pin Output Driving Register 
	#define CM_GPIO0_GPINR		0x08	// 08	2B	GPINR    - GPIO 0:11 pin Status Input Register
	#define CM_GPIO0_GPSTR		0x0C	// 0C	2F	GPSTR    - GPIO 0:11 Interrupt Status Register
	#define CM_GPIO0_GPIT1R0	0x10	// 10	33	GPIT1R0  - GPIO 0:7 Interrupt Type and Control Register
	#define CM_GPIO0_INT		0x14	// 14	37	INT      - GPIO Interrupt Register
	#define CM_GPIO0_GPIT1R1	0x18	// 18	3B	GPIT1R1  - GPIO 8:11 Interrupt Type and Control Register
	#define CM_GPIO0_MUX_CNTL	0x1C	// 1C	3F	MUX_CNTL - GPIO Mux Control

	/* Core Well - GPIO Groups 1 & 2													 */
	/* 16.7.1 - Core Well GPIO I/O Registers (Northbridge and Legacy Intel_CM EAS)       */
	/* GPC0 – GPC9						                                                 */
	/* The control for the general purpose I/O signals is handled through an independent */
	/* 64-byte I/O space.  The base offset for this space is selected by the GPIO_BAR    */
    /* register in D31:F0 config space.                                                  */
	#define CM_GPIO1_CGEN		0x00	// 00	23	CGEN -	Core Well GPIO Enable
	#define CM_GPIO1_CGIO		0x04	// 04	27	CGIO -	Core Well GPIO Input / Output Select
	#define CM_GPIO1_CGLV		0x08	// 08	2B	CGLV -	Core Well GPIO Level for Input or Output
	#define CM_GPIO1_CGTPE		0x0C	// 0C	2F	CGTPE - Core Well GPIO Trigger Positive Edge Enable
	#define CM_GPIO1_CGTNE		0x10	// 10	33	CGTNE - Core Well GPIO Trigger Negative Edge Enable
	#define CM_GPIO1_CGGPE		0x14	// 14	37	CGGPE - Core Well GPIO GPE Enable
	#define CM_GPIO1_CGSMI		0x18	// 18	3B	CGSMI - Core Well GPIO SMI Enable
	#define CM_GPIO1_CGTS		0x1C	// 1C	3F	CGTS -	Core Well GPIO Trigger Status

	/* Core Well - GPIO Groups 1 & 2													 */
	/* 16.7.1 - Core Well GPIO I/O Registers (Northbridge and Legacy Intel_CM EAS)       */
	/* GPC0 – GPC9						                                                 */
	/* The control for the general purpose I/O signals is handled through an independent */
	/* 64-byte I/O space.  The base offset for this space is selected by the GPIO_BAR    */
    /* register in D31:F0 config space.                                                  */
	#define CM_GPIO2_CGEN		0x00	// 00	23	CGEN -	Core Well GPIO Enable
	#define CM_GPIO2_CGIO		0x04	// 04	27	CGIO -	Core Well GPIO Input / Output Select
	#define CM_GPIO2_CGLV		0x08	// 08	2B	CGLV -	Core Well GPIO Level for Input or Output
	#define CM_GPIO2_CGTPE		0x0C	// 0C	2F	CGTPE - Core Well GPIO Trigger Positive Edge Enable
	#define CM_GPIO2_CGTNE		0x10	// 10	33	CGTNE - Core Well GPIO Trigger Negative Edge Enable
	#define CM_GPIO2_CGGPE		0x14	// 14	37	CGGPE - Core Well GPIO GPE Enable
	#define CM_GPIO2_CGSMI		0x18	// 18	3B	CGSMI - Core Well GPIO SMI Enable
	#define CM_GPIO2_CGTS		0x1C	// 1C	3F	CGTS -	Core Well GPIO Trigger Status

	/* Resume Well - GPIO Group 3														 */
	/* 16.7.2 - Resume Well GPIO I/O Registers (Northbridge and Legacy Intel_CM EAS)     */
	/* GPR0 – GPR4																		 */
	/* The control for the general purpose I/O signals is handled through an independent */
	/* 64-byte I/O space.  The base offset for this space is selected by the GPIO_BAR    */
    /* register in D31:F0 config space.                                                  */
	#define CM_GPIO3_RGEN		0x20	// 20	23	RGEN  - Resume Well GPIO Enable
	#define CM_GPIO3_RGIO		0x24	// 24	27	RGIO  - Resume Well GPIO Input / Output Select
	#define CM_GPIO3_RGLV		0x28	// 28	2B	RGLV  - Resume Well GPIO Level for Input or Output
	#define CM_GPIO3_RGTPE		0x2C	// 2C	2F	RGTPE - Resume Well GPIO Trigger Positive Edge Enable
	#define CM_GPIO3_RGTNE		0x30	// 30	33	RGTNE - Resume Well GPIO Trigger Negative Edge Enable
	#define CM_GPIO3_RGGPE		0x34	// 34	37	RGGPE - Resume Well GPIO GPE Enable
	#define CM_GPIO3_RGSMI		0x38	// 38	3B	RGSMI - Resume Well GPIO SMI Enable
	#define CM_GPIO3_RGTS		0x3C	// 3C	3F	RGTS  - Resume Well GPIO Trigger Status
//#elif defined(PLAT_CE31XX)
	#define GEN4D5_NUM_GPIO_PINS			86

	#define GEN4D5_GPIO_MEM_BASIE			0xDFFE0400
	#define GEN4D5_GPIO_IO_BASE			0x1080
	#define GEN4D5_GPIO_MEM_SIZE			256
	#define GEN4D5_IRQ_BASE				0xBFFFF000
	#define GEN4D5_IRQ_SIZE				256
	#define GEN4D5_IRQ_MASK_OFFSET			0x80
	#define GEN4D5_GPIO_IRQ_MASK_OFFSET		15

	#define GEN4D5_GPIO_IRQ				27
	#define GEN4D5_GPIO_ADJ_NUM_INT			5
	#define GEN4D5_GPIO_NUM_INT			78

	#define GEN4D5_GPIO_NUM_MIN			0
	#define GEN4D5_GPIO_NUM_MAX			GEN4D5_NUM_GPIO_PINS - 1 // 0 based count

	// Starting points for the different GPIO Wells on Intel_GEN4D5
/*	#define CE31XX_GPIO_GROUP_ZERO  0  
	#define CE31XX_GPIO_GROUP_ONE	32	// GPIO AUX [77:0] => GPIOAUX[98:21]  - 96 register bits but only 78 bits are assigned to external pins, GPIO 0 -> GPIOAUX 21 .... 
	#define CE31XX_GPIO_GROUP_TWO	64	// GPIO [85:78]    => GPIOS[7:0]
	#define CE31XX_GPIO_GROUP_THREE 78
	#define CE31XX_GPIO_GROUP_MAX 	4 */
	
	#define GEN4D5_GPIO_GROUP_ZERO 0
	#define GEN4D5_GPIO_GROUP_ONE  32
	#define GEN4D5_GPIO_GROUP_TWO  64
	#define GEN4D5_GPIO_GROUP_THREE 78
	#define GEN4D5_GPIO_GROUP_MAX  4

	/* AUX Well - GPIO Group 0  == GPIOS[77:0]		*/
	/* 1.3 - GPIO Unit Registers	*/				                        						                                               
	/* These GPIOs are in the Core Well and are implemented in the PUB GPIO unit accessing GPIO_AUX_MBAR.        */
	//GPIOAUX[31:0]
	#define GEN4D5_GPIO0_GPOUTR_0		0x00	// 00	23	GPOUTR   - GPIO 0:31 pin Data Output Register
	#define GEN4D5_GPIO0_GPOER_0		0x04	// 04	27	GPOER    - GPIO 0:31 pin Output Driving Register 
	#define GEN4D5_GPIO0_GPINR_0		0x08	// 08	2B	GPINR    - GPIO 0:31 pin Status Input Register
	#define GEN4D5_GPIO0_GPSTR_0		0x0C	// 0C	2F	GPSTR    - GPIO 0:31 Interrupt Status Register
	#define GEN4D5_GPIO0_INTEN_0		0x10	// 10   33	INTEN	 - GPIO 0:31 Interrupt Enable Register
	#define GEN4D5_GPIO0_GPIT1R0_0		0x14	// 14   37	GPIT1R0  - GPIO 0:4  Interrupt Type and Control Register
	#define GEN4D5_GPIO0_MUX_CNTL_0		0x18	// 18	3F	MUX_CNTL - GPIO Mux Control
	#define GEN4D5_GPIO0_GROUP_0		0x20
	
	//GPIOAUX[63:32]
	#define GEN4D5_GPIO0_GPOUTR_1 		0x20	// 20		GPOUTR	 - GPIO 32:63 Pin Data Output Register
	#define GEN4D5_GPIO0_GPOER_1		0x24	// 24		GPOER	 - GPIO 32:63 Pin Output Driving Register
	#define GEN4D5_GPIO0_GPINR_1		0x28	// 28		GPINR	 - GPIO 32:63 Pin Status Input Register
	#define GEN4D5_GPIO0_GPSTR_1		0x2C	// 2C 		GPSTR	 - GPIO 32:63 Interrupt Status Register
	#define GEN4D5_GPIO0_INTEN_1		0x30	// 30 		INTEN	 - GPIO 32:63 Interrupt Enble Register
	#define GEN4D5_GPIO0_GROUP_1		0x40
	
	//GPIOAUX[64:77]
	#define GEN4D5_GPIO0_GPOUTR_2		0x40	// 40		GPOUTR	 - GPIO 64:95 Pin Data Output Register
	#define GEN4D5_GPIO0_GPOER_2		0x44	// 44		GPOER	 - GPIO 64:95 Pin Output Driving Register
	#define GEN4D5_GPIO0_GPINR_2		0x48	// 48		GPINR	 - GPIO 64:95 Pin Status Input Register
	#define GEN4D5_GPIO0_GPSTR_2		0x4C	// 4C		GPSTR 	 - GPIO 64:95 Interrupt Status Register
	#define GEN4D5_GPIO0_INTEN_2		0x50	// 50		INTEN	 - GPIO 64:95 Interrupt Enable Register
	#define GEN4D5_GPIO0_GROUP_2		0x4E

	/* Core Well - GPIO Groups 1								  */
	/* 16.7.1 - Core Well GPIO I/O Registers (Northbridge and Legacy Intel_GEN4D5 EAS)       */ 
	/* The control for the general purpose I/O signals is handled through an independent 	*/
	/* 64-byte I/O space.  The base offset for this space is selected by the GPIO_BAR      */
   	/* register in D31:F0 config space.                                                   */
	//GPIOS[7:0]
	#define GEN4D5_GPIO1_CGEN		0x00	// 00	03	CGEN -	Core Well GPIO Enable
	#define GEN4D5_GPIO1_CGIO		0x04	// 04	07	CGIO -	Core Well GPIO Input / Output Select
	#define GEN4D5_GPIO1_CGLV		0x08	// 08	0B	CGLV -	Core Well GPIO Level for Input or Output
	#define GEN4D5_GPIO1_CGTPE		0x0C	// 0C	0F	CGTPE - Core Well GPIO Trigger Positive Edge Enable
	#define GEN4D5_GPIO1_CGTNE		0x10	// 10	13	CGTNE - Core Well GPIO Trigger Negative Edge Enable
	#define GEN4D5_GPIO1_CGGPE		0x14	// 14	17	CGGPE - Core Well GPIO GPE Enable
	#define GEN4D5_GPIO1_CGSMI		0x18	// 18	1B	CGSMI - Core Well GPIO SMI Enable
	#define GEN4D5_GPIO1_CGTS		0x1C	// 1C	1F	CGTS -	Core Well GPIO Trigger Status
//#endif

/*****************************************************************************/
/******** Copied from idl driver, _gpio_gen5.h *************************************/
#define GEN5_NUM_GPIO_PINS		136

//#define GEN5_GPIO_MEM_BASE		0xDFFE0400
//#define GEN5_GPIO_IO_BASE			0x1080
//#define GEN5_GPIO_MEM_SIZE			256

#define GEN5_IRQ_BASE				0xBFFFF000
#define GEN5_IRQ_SIZE				256
#define GEN5_IRQ_MASK_OFFSET		0x80
#define GEN5_GPIO_IRQ_MASK_OFFSET	15

//GPIOAUX[127:0] support adjustable interrupt
#define GEN5_GPIO_NUM_INT		128

#define GEN5_GPIO_NUM_MIN		0
#define GEN5_GPIO_NUM_MAX		GEN5_NUM_GPIO_PINS - 1 // 0 based count

// starting point for the different GPIO groups on intel_gen5
#define GEN5_GPIO_GROUP_ZERO	0	
#define GEN5_GPIO_GROUP_ONE	128	//GPIO[127:0] = GPIOAUX[127:0]
#define GEN5_GPIO_GROUP_TWO	136	//GPIO[135:128] = GPIOS[7:0]
#define GEN5_GPIO_GROUP_MAX	2

/* GPIOAUX Group 0 == GPIOs[127:0]*/
//GPIOAUX[31:0]
#define GEN5_GPIO0_GPOUTR_0		0x00
#define GEN5_GPIO0_GPOER_0		0x04
#define GEN5_GPIO0_GPINR_0		0x08
#define GEN5_GPIO0_GPSTR_0		0x0C
#define GEN5_GPIO0_INTEN_0		0x10
#define GEN5_GPIO0_GPITMODLE0		0x14
#define GEN5_GPIO0_GPITMODRF0		0x18
#define GEN5_GPIO0_MUX_CNTL		0x1C
#define GEN5_GPIO0_GROUP_0		0x20
//GPIOAUX[63:32]
#define GEN5_GPIO0_GPOUTR_1		0x20
#define GEN5_GPIO0_GPOER_1		0x24
#define GEN5_GPIO0_GPINR_1		0x28
#define GEN5_GPIO0_GPSTR_1		0x2C
#define GEN5_GPIO0_INTEN_1		0x30
#define GEN5_GPIO0_GPITMODLE1		0x34
#define GEN5_GPIO0_GPITMODRF1		0x38
#define GEN5_GPIO0_GROUP_1		0x40
//GPIOAUX[93:64]
#define GEN5_GPIO0_GPOUTR_2		0x40
#define GEN5_GPIO0_GPOER_2		0x44
#define GEN5_GPIO0_GPINR_2		0x48
#define GEN5_GPIO0_GPSTR_2		0x4C
#define GEN5_GPIO0_INTEN_2		0x50
#define GEN5_GPIO0_GPITMODLE2		0x54
#define GEN5_GPIO0_GPITMODRF2		0x58
#define GEN5_GPIO0_GROUP_2		0x60
//GPIOAUX[127:94]
#define GEN5_GPIO0_GPOUTR_3		0x60
#define GEN5_GPIO0_GPOER_3		0x64
#define GEN5_GPIO0_GPINR_3		0x68
#define GEN5_GPIO0_GPSTR_3		0x6C
#define GEN5_GPIO0_INTEN_3		0x70
#define GEN5_GPIO0_GPITMODLE3		0x74
#define GEN5_GPIO0_GPITMODRF3		0x78
#define GEN5_GPIO0_GROUP_3		0x80

/* GPIO Group 1*/
//GPIOS[7:0]
#define GEN5_GPIO1_CGEN		0x00
#define GEN5_GPIO1_CGIO		0x04
#define GEN5_GPIO1_CGLV		0x08
#define GEN5_GPIO1_CGTPE		0x0C
#define GEN5_GPIO1_CGTNE		0x10
#define GEN5_GPIO1_CGGPE		0x14
#define GEN5_GPIO1_CGSMI		0x18
#define GEN5_GPIO1_CGTS		0x1C


#ifdef __ARM__
	#define _IRQ_BASE			OR_IRQ_BASE
	#define _IRQ_SIZE			OR_IRQ_SIZE
	
	#define _GPIO_BASE			OR_GPIO_BASE
	#define _GPIO_SIZE			OR_GPIO_SIZE

	#define _GPIO_NUM_MIN		OR_GPIO_NUM_MIN
	#define _GPIO_NUM_MAX		OR_GPIO_NUM_MAX
	#define _NUM_GPIO_PINS		OR_NUM_GPIO_PINS

	#define _GPIO_GROUP_ZERO	OR_GPIO_GROUP_ZERO
	#define _GPIO_GROUP_ONE		OR_GPIO_GROUP_ONE
	#define _GPIO_GROUP_TWO		OR_GPIO_GROUP_TWO
	#define _GPIO_GROUP_THREE	OR_GPIO_GROUP_THREE

	#define _GPIO_GROUP_MAX		OR_GPIO_GROUP_MAX

	#define _GPIO0_OUTR			OR_GPIO0_GPOUTR
	#define _GPIO0_OER			OR_GPIO0_GPOER
	#define _GPIO0_INR			OR_GPIO0_GPINR
	#define _GPIO0_STR			OR_GPIO0_GPSTR
	#define _GPIO0_IT1R0		OR_GPIO0_GPIT1R

	#define _GPIO0_POL			-1
	#define _GPIO0_ALT			-1

	#define _GPIO0_INT			-1		
	#define _GPIO0_IT1R1		-1	
	#define _GPIO0_MUX_CNTL		-1

	#define _GPIO0_EN			-1
	#define _GPIO0_IO			-1
	#define _GPIO0_LV			-1
	#define _GPIO0_TPE			-1
	#define _GPIO0_TNE			-1
	#define _GPIO0_GPE			-1
	#define _GPIO0_SMI			-1
	#define _GPIO0_TS			-1

	#define _GPIO1_OUTR			OR_GPIO1_GPOUTR
	#define _GPIO1_OER			OR_GPIO1_GPOER
	#define _GPIO1_INR			OR_GPIO1_GPINR
	#define _GPIO1_POL			OR_GPIO1_GPPOL
	#define _GPIO1_ALT			OR_GPIO1_GPALT

	#define _GPIO1_STR			-1		
	#define _GPIO1_IT1R0		-1

	#define _GPIO1_EN			-1
	#define _GPIO1_IO			-1
	#define _GPIO1_LV			-1
	#define _GPIO1_TPE			-1
	#define _GPIO1_TNE			-1
	#define _GPIO1_GPE			-1
	#define _GPIO1_SMI			-1
	#define _GPIO1_TS			-1

	#define _GPIO2_OUTR			OR_GPIO2_GPOUTR
	#define _GPIO2_OER			OR_GPIO2_GPOER
	#define _GPIO2_INR			OR_GPIO2_GPINR
	#define _GPIO2_POL			OR_GPIO2_GPPOL
	#define _GPIO2_ALT			OR_GPIO2_GPALT

	#define _GPIO2_STR			-1		
	#define _GPIO2_IT1R0		-1

	#define _GPIO2_INT			-1		
	#define _GPIO2_IT1R1		-1	
	#define _GPIO2_MUX_CNTL		-1

	#define _GPIO2_EN			-1
	#define _GPIO2_IO			-1
	#define _GPIO2_LV			-1
	#define _GPIO2_TPE			-1
	#define _GPIO2_TNE			-1
	#define _GPIO2_GPE			-1
	#define _GPIO2_SMI			-1
	#define _GPIO2_TS			-1

	#define _GPIO3_OUTR			OR_GPIO3_GPOUTR
	#define _GPIO3_OER			OR_GPIO3_GPOER
	#define _GPIO3_INR			OR_GPIO3_GPINR
	#define _GPIO3_POL			OR_GPIO3_GPPOL
	#define _GPIO3_ALT			OR_GPIO3_GPALT
	
	#define _GPIO3_STR			-1		
	#define _GPIO3_IT1R0		-1

	#define _GPIO3_INT			-1		
	#define _GPIO3_IT1R1		-1	
	#define _GPIO3_MUX_CNTL		-1

	#define _GPIO3_EN			-1
	#define _GPIO3_IO			-1
	#define _GPIO3_LV			-1
	#define _GPIO3_TPE			-1
	#define _GPIO3_TNE			-1
	#define _GPIO3_GPE			-1
	#define _GPIO3_SMI			-1
	#define _GPIO3_TS			-1
#elif defined(PLAT_GEN5)
	#define _IRQ_BASE			CM_IRQ_BASE
	#define _IRQ_SIZE			CM_IRQ_SIZE
	
	#define _GPIO_BASE			CM_GPIO_MEM_BASE
	#define _GPIO_SIZE			CM_GPIO_MEM_SIZE

	#define _GPIO_NUM_MIN		CM_GPIO_NUM_MIN
	#define _GPIO_NUM_MAX		CM_GPIO_NUM_MAX
	#define _NUM_GPIO_PINS		CM_NUM_GPIO_PINS

	#define _GPIO_GROUP_ZERO	CE31XX_GPIO_GROUP_ZERO
	#define _GPIO_GROUP_ONE		CE31XX_GPIO_GROUP_ONE
	#define _GPIO_GROUP_TWO		CE31XX_GPIO_GROUP_TWO
	#define _GPIO_GROUP_THREE	CE31XX_GPIO_GROUP_THREE

	#define _GPIO_GROUP_MAX		CE31XX_GPIO_GROUP_MAX

	#define _GPIO0_OUTR			CM_GPIO0_GPOUTR		
	#define _GPIO0_OER			CM_GPIO0_GPOER		
	#define _GPIO0_INR			CM_GPIO0_GPINR		
	#define _GPIO0_STR			CM_GPIO0_GPSTR		
	#define _GPIO0_IT1R0		CM_GPIO0_GPIT1R0

	#define _GPIO0_POL			-1
	#define _GPIO0_ALT			-1

	#define _GPIO0_INT			CM_GPIO0_INT		
	#define _GPIO0_IT1R1		CM_GPIO0_GPIT1R1	
	#define _GPIO0_MUX_CNTL		CM_GPIO0_MUX_CNTL

	#define _GPIO0_EN			-1
	#define _GPIO0_IO			-1
	#define _GPIO0_LV			-1
	#define _GPIO0_TPE			-1
	#define _GPIO0_TNE			-1
	#define _GPIO0_GPE			-1
	#define _GPIO0_SMI			-1
	#define _GPIO0_TS			-1

	#define _GPIO1_OUTR			-1		
	#define _GPIO1_OER			-1		
	#define _GPIO1_INR			-1		
	#define _GPIO1_STR			-1		
	#define _GPIO1_IT1R0		-1

	#define _GPIO1_POL			-1
	#define _GPIO1_ALT			-1

	#define _GPIO1_INT			-1		
	#define _GPIO1_IT1R1		-1	
	#define _GPIO1_MUX_CNTL		-1

	#define _GPIO1_EN			CM_GPIO1_CGEN
	#define _GPIO1_IO			CM_GPIO1_CGIO
	#define _GPIO1_LV			CM_GPIO1_CGLV
	#define _GPIO1_TPE			CM_GPIO1_CGTPE
	#define _GPIO1_TNE			CM_GPIO1_CGTNE
	#define _GPIO1_GPE			CM_GPIO1_CGGPE
	#define _GPIO1_SMI			CM_GPIO1_CGSMI
	#define _GPIO1_TS			CM_GPIO1_CGTS

	#define _GPIO2_OUTR			-1		
	#define _GPIO2_OER			-1		
	#define _GPIO2_INR			-1		
	#define _GPIO2_STR			-1		
	#define _GPIO2_IT1R0		-1

	#define _GPIO2_POL			-1
	#define _GPIO2_ALT			-1

	#define _GPIO2_INT			-1		
	#define _GPIO2_IT1R1		-1	
	#define _GPIO2_MUX_CNTL		-1

	#define _GPIO2_EN			CM_GPIO2_CGEN
	#define _GPIO2_IO			CM_GPIO2_CGIO
	#define _GPIO2_LV			CM_GPIO2_CGLV
	#define _GPIO2_TPE			CM_GPIO2_CGTPE
	#define _GPIO2_TNE			CM_GPIO2_CGTNE
	#define _GPIO2_GPE			CM_GPIO2_CGGPE
	#define _GPIO2_SMI			CM_GPIO2_CGSMI
	#define _GPIO2_TS			CM_GPIO2_CGTS

	#define _GPIO3_OUTR			-1		
	#define _GPIO3_OER			-1		
	#define _GPIO3_INR			-1		
	#define _GPIO3_STR			-1		
	#define _GPIO3_IT1R0		-1

	#define _GPIO3_POL			-1
	#define _GPIO3_ALT			-1

	#define _GPIO3_INT			-1		
	#define _GPIO3_IT1R1		-1	
	#define _GPIO3_MUX_CNTL		-1

	#define _GPIO3_EN			CM_GPIO3_RGEN
	#define _GPIO3_IO			CM_GPIO3_RGIO
	#define _GPIO3_LV			CM_GPIO3_RGLV
	#define _GPIO3_TPE			CM_GPIO3_RGTPE
	#define _GPIO3_TNE			CM_GPIO3_RGTNE
	#define _GPIO3_GPE			CM_GPIO3_RGGPE
	#define _GPIO3_SMI			CM_GPIO3_RGSMI
	#define _GPIO3_TS			CM_GPIO3_RGTS
#elif defined(PLAT_CE31XX)
	#define _IRQ_BASE			GEN4D5_IRQ_BASE
	#define _IRQ_SIZE			GEN4D5_IRQ_SIZE
	
	#define _GPIO_BASE			GEN4D5_GPIO_MEM_BASE
	#define _GPIO_SIZE			GEN4D5_GPIO_MEM_SIZE

	#define _GPIO_NUM_MIN			GEN4D5_GPIO_NUM_MIN
	#define _GPIO_NUM_MAX			GEN4D5_GPIO_NUM_MAX
	#define _NUM_GPIO_PINS			GEN4D5_NUM_GPIO_PINS

	#define _GPIO_GROUP_ZERO		GEN4D5_GPIO_GROUP_ZERO
	#define _GPIO_GROUP_ONE			GEN4D5_GPIO_GROUP_ONE
	#define _GPIO_GROUP_TWO			GEN4D5_GPIO_GROUP_TWO
	#define _GPIO_GROUP_THREE		GEN4D5_GPIO_GROUP_THREE

	#define _GPIO_GROUP_MAX			GEN4D5_GPIO_GROUP_MAX

	#define _GPIO0_OUTR			GEN4D5_GPIO0_GPOUTR_0		
	#define _GPIO0_OER			GEN4D5_GPIO0_GPOER_0		
	#define _GPIO0_INR			GEN4D5_GPIO0_GPINR_0		
	#define _GPIO0_STR			GEN4D5_GPIO0_GPSTR_0		
	#define _GPIO0_IT1R0			GEN4D5_GPIO0_GPIT1R0_0

	#define _GPIO0_POL			-1
	#define _GPIO0_ALT			-1

	#define _GPIO0_INT			GEN4D5_GPIO0_INTEN_0		
	#define _GPIO0_IT1R1			-1	
	#define _GPIO0_MUX_CNTL			GEN4D5_GPIO0_MUX_CNTL_0
	#define _GPIO0_GROUP			GEN4D5_GPIOO_GROUP_0	

	#define _GPIO0_EN			-1
	#define _GPIO0_IO			-1
	#define _GPIO0_LV			-1
	#define _GPIO0_TPE			-1
	#define _GPIO0_TNE			-1
	#define _GPIO0_GPE			-1
	#define _GPIO0_SMI			-1
	#define _GPIO0_TS			-1

	#define _GPIO1_OUTR			GEN4D5_GPIO0_GPOUTR_1		
	#define _GPIO1_OER			GEN4D5_GPIO0_GPOER_1		
	#define _GPIO1_INR			GEN4D5_GPIO0_GPINR_1		
	#define _GPIO1_STR			GEN4D5_GPIO0_GPSTR_1		
	#define _GPIO1_IT1R0			-1

	#define _GPIO1_POL			-1
	#define _GPIO1_ALT			-1

	#define _GPIO1_INT			GEN4D5_GPIO0_INTEN_1		
	#define _GPIO1_IT1R1			-1	
	#define _GPIO1_MUX_CNTL			-1

	#define _GPIO1_EN			-1
	#define _GPIO1_IO			-1
	#define _GPIO1_LV			-1
	#define _GPIO1_TPE			-1
	#define _GPIO1_TNE			-1
	#define _GPIO1_GPE			-1
	#define _GPIO1_SMI			-1
	#define _GPIO1_TS			-1

	#define _GPIO2_OUTR			GEN4D5_GPIO0_GPOUTR_2		
	#define _GPIO2_OER			GEN4D5_GPIO0_GPOER_2		
	#define _GPIO2_INR			GEN4D5_GPIO0_GPINR_2		
	#define _GPIO2_STR			GEN4D5_GPIO0_GPSTR_2		
	#define _GPIO2_IT1R0			-1

	#define _GPIO2_POL			-1
	#define _GPIO2_ALT			-1

	#define _GPIO2_INT			GEN4D5_GPIO0_INTEN_2		
	#define _GPIO2_IT1R1			-1	
	#define _GPIO2_MUX_CNTL			-1

	#define _GPIO2_EN			-1
	#define _GPIO2_IO			-1
	#define _GPIO2_LV			-1
	#define _GPIO2_TPE			-1
	#define _GPIO2_TNE			-1
	#define _GPIO2_GPE			-1
	#define _GPIO2_SMI			-1
	#define _GPIO2_TS			-1

	#define _GPIO3_OUTR			-1		
	#define _GPIO3_OER			-1		
	#define _GPIO3_INR			-1		
	#define _GPIO3_STR			-1		
	#define _GPIO3_IT1R0			-1

	#define _GPIO3_POL			-1
	#define _GPIO3_ALT			-1

	#define _GPIO3_INT			-1		
	#define _GPIO3_IT1R1			-1	
	#define _GPIO3_MUX_CNTL			-1

	#define _GPIO3_EN			GEN4D5_GPIO1_CGEN
	#define _GPIO3_IO			GEN4D5_GPIO1_CGIO
	#define _GPIO3_LV			GEN4D5_GPIO1_CGLV
	#define _GPIO3_TPE			GEN4D5_GPIO1_CGTPE
	#define _GPIO3_TNE			GEN4D5_GPIO1_CGTNE
	#define _GPIO3_GPE			GEN4D5_GPIO1_CGGPE
	#define _GPIO3_SMI			GEN4D5_GPIO1_CGSMI
	#define _GPIO3_TS			GEN4D5_GPIO1_CGTS
#endif

#define CHK(func, expected_val, fail_action) \
	do{ \
		int return_val = func; \
		if(expected_val != return_val) \
		{ \
			tsError(DTS_FUNC_FAIL, g_szDTSErrMsgs[DTS_FUNC_FAIL], #func, return_val); \
			fail_action; \
		} \
	}while(0)


#ifdef __cplusplus
extern "C" {
#endif

uint32_t PORT_READ(uint32_t addr);

void PORT_WRITE(uint32_t addr, uint32_t data);

struct GPIO_Register
{
	uint32_t data;
	uint32_t offset;
	char* name;
	uint32_t enumeration;
};

enum DTS_GPIO_REGISTER_ENUM
{
	GPIO_ENUM_OUTR,
	GPIO_ENUM_OER,
	GPIO_ENUM_INR,
	GPIO_ENUM_STR,
	GPIO_ENUM_IT1R0,

	GPIO_ENUM_POL,
	GPIO_ENUM_ALT,

	GPIO_ENUM_INT,
	GPIO_ENUM_IT1R1,
	GPIO_ENUM_MUX_CNTL,

	GPIO_ENUM_EN,
	GPIO_ENUM_IO,
	GPIO_ENUM_LV,
	GPIO_ENUM_TPE,
	GPIO_ENUM_TNE,
	GPIO_ENUM_GPE,
	GPIO_ENUM_SMI,
	GPIO_ENUM_TS,

	NUM_GPIO_ENUMS
};

extern char* g_szDtsGpioRegisterNames[NUM_GPIO_ENUMS];

struct GPIO_Register_Group					
{
	uint32_t base; //LSB = 0 memory space, LSB = 1 port space
	uint32_t group;
	uint32_t start_number;
	uint32_t end_number;
	char well[32];

	uint32_t num_registers;
	struct GPIO_Register registers[NUM_GPIO_ENUMS]; //maximum number of registers
};

// GPIO Functions
bool dtsGPIOInit(uint32_t **gpio_base);

bool dtsGPIOGetGroup(uint32_t gpio, uint32_t *group);
bool dtsGPIOCreateGroup(uint32_t group, uint32_t gpio_base, struct GPIO_Register_Group* gpio_register_group);

bool dtsGPIOReadRegisters(struct GPIO_Register_Group *);
void dtsGPIODisplayRegisters(struct GPIO_Register_Group* group, bool verbose);

//does API write
bool dtsGPIOWrite(uint32_t number, uint32_t gpioData, uint32_t gpioDirection, uint32_t gpioPolarity, bool bPrimary, bool bDisplay);

#ifdef PLAT_CE31XX
bool dtsGPIOMemoryBase(uint32_t *gpio_base);
bool dtsGPIOPortBase(uint32_t *gpio_base);
#endif
// Display Modes
typedef enum
{
	MODE_480I,		/* 720 x 480i, 60Hz - NTSC */
	MODE_NTSC_J,	/* 720 x 480i, 60Hz */
	MODE_NTSC_443,	/* 720 x 480i, 60Hz */
	MODE_PAL_M,		/* 720 x 480i, 60Hz */
	MODE_PAL_N,		/* 720 x 576i, 50Hz */
	MODE_PAL,		/* 720 x 576i, 50Hz */
	MODE_480P,		/* 720 x 480p, 60Hz */
	MODE_720P,		/* 1280 x 720p, 60Hz */
	MODE_576P,		/* 720 x 576p, 50Hz */
	MODE_1080I_60,	/* 1920 x 1080i, 60Hz */
	MODE_1080I_50,	/* 1920 x 1080i, 50Hz */
	MODE_1080P_60,
	MODE_1080P_50,
	MODE_720P_50,	/* 1280 x 720p, 50Hz */
	MODE_SECAM		/* 720 x 576i, 50Hz - SECAM External encoder only */
} display_mode;

#ifdef __ARM__

// Graphics Information
	typedef struct _display_mode_t
	{
		char *label;
		gdl_display_info_t di;
	} display_mode_t;

	// Attribute IDs
	enum attibute_id
	{
		ID_BRIGHTNESS,
		ID_CONTRAST,
		ID_HUE,
		ID_ADAPTIVE_FLICKER_FILTER,
		ID_RESERVED4,
		ID_RESERVED5,
		ID_CHROMA_FILTER,
		ID_MACROVISION,
		ID_TV_OUTPUT_TYPE,
		ID_SATURATION,
		ID_RESERVED10,
		ID_INTTVENC_PORT_DRIVER,
		ID_DATE,
		ID_TIME,
		ID_TEST_MODE,
		ID_UNDERSCAN,
		ID_RESERVED16,
		ID_RESERVED17,
		ID_RESERVED18,
		ID_RESERVED19,
		ID_RESERVED20,
		ID_RESERVED21,
		ID_RESERVED22,
		ID_HORIZONTAL_Y_FILTER,
		ID_HORIZONTAL_UV_FILTER,
		ID_VERTICAL_Y_FILTER,
		ID_VERTICAL_UV_FILTER,
		ID_BLANK_LEVEL,
		ID_BLACK_LEVEL,
		ID_BURST_LEVEL,
		ID_RESERVED30,
		ID_RESERVED31,

		ATTRIB_COUNT
	};



	enum tvOutput
	{
		TV_OUT_COMPOSITE,
		TV_OUT_SVIDEO,
		TV_OUT_COMPONENT,
		TV_OUT_COMBO,
		TV_OUT_SCART,
		TV_OUT_SCART_SVIDEO,
		TV_OUT_HDMI,
	};

	// Attribute IDs
	enum bg_color
	{
		BG_BLACK,
		BG_BLUE,
		BG_GREEN,
		BG_RED,
		BG_WHITE,
		BG_YELLOW,
	};

	// Graphics/Streamer Functions
	gdl_display_port_t dtsGetPortType (void);
	int dtsGetTVOutput(void);
	int dtsGetModeParameter(int default_mode);
	uint32_t dtsGetBackgroundColor(int *bg_color);

	gdl_int32 dtsSetPortType(gdl_display_port_t port_type);
	gdl_int32 dtsSetPortMode(gdl_display_port_t port_type, int mode_resolution, int tv_output, gdl_display_info_t *di_in);

	void dtsGetModeResolution(gdl_display_info_t *di_out);
	void dtsSetModeResolution(char *txt, gdl_display_info_t *di_in);
	bool dtsIsModeResolution(gdl_display_port_t port_type, int mode_resolution);

	bool dtsIsValidCombination(gdl_display_port_t port_type, int mode_resolution, int tv_output);

	pd_attr_t *dtsGetPortAttributes(gdl_display_port_t port_type, int *count);
	int dtsSetPortAttributes(gdl_display_port_t port_type, int attr_id, int attr_value);
	int dtsGetPortAttributeValue(gdl_display_port_t port_type, int attr_id, int *attr_value);

	void dtsPrintDisplayInfo(gdl_display_info_t *d);
	char * dtsDisplayInfoString(gdl_display_info_t *d);

#elif defined(PLAT_CE31XX)

// Graphics Information
	typedef struct _display_mode_t
	{
		char *label;
		gdl_display_info_t di;
	} display_mode_t;

	// Attribute IDs
	enum attibute_id
	{
		ID_BRIGHTNESS,
		ID_CONTRAST,
		ID_HUE,
		ID_ADAPTIVE_FLICKER_FILTER,
		ID_RESERVED4,
		ID_RESERVED5,
		ID_CHROMA_FILTER,
		ID_MACROVISION,
		ID_TV_OUTPUT_TYPE,
		ID_SATURATION,
		ID_RESERVED10,
		ID_INTTVENC_PORT_DRIVER,
		ID_DATE,
		ID_TIME,
		ID_TEST_MODE,
		ID_UNDERSCAN,
		ID_RESERVED16,
		ID_RESERVED17,
		ID_RESERVED18,
		ID_RESERVED19,
		ID_RESERVED20,
		ID_RESERVED21,
		ID_RESERVED22,
		ID_HORIZONTAL_Y_FILTER,
		ID_HORIZONTAL_UV_FILTER,
		ID_VERTICAL_Y_FILTER,
		ID_VERTICAL_UV_FILTER,
		ID_BLANK_LEVEL,
		ID_BLACK_LEVEL,
		ID_BURST_LEVEL,
		ID_RESERVED30,
		ID_RESERVED31,

		ATTRIB_COUNT
	};

	enum tvOutput
	{
		TV_OUT_COMPOSITE,
		TV_OUT_SVIDEO,
		TV_OUT_COMPONENT,
		TV_OUT_COMBO,
		TV_OUT_HDMI,
	};

	// Attribute IDs
	enum bg_color
	{
		BG_BLACK,
		BG_BLUE,
		BG_GREEN,
		BG_RED,
		BG_WHITE,
		BG_YELLOW,
	};

	// Graphics/Streamer Functions
	gdl_pd_id_t dtsGetPortType (void);
	int dtsGetTVOutput(void);
	int dtsGetModeParameter(int default_mode);
	uint32_t dtsGetBackgroundColor(int *bg_color);

	gdl_int32 dtsSetPortType(gdl_pd_id_t port_type);
	gdl_int32 dtsSetPortMode(gdl_display_id_t display_id, int tv_output, int mode_resolution, gdl_display_info_t *di_in);

	gdl_ret_t dtsGetModeResolution(gdl_display_id_t id, gdl_display_info_t *di_out);
	void dtsSetModeResolution(char *txt, gdl_display_info_t *di_in);
	bool dtsIsModeResolution(gdl_pd_id_t port_type, int mode_resolution);

	bool dtsGetPlaneParam(gdl_plane_id_t *plane);

	bool dtsIsValidCombination(gdl_display_id_t displayId, int mode_resolution, int tv_output);

	gdl_pd_attribute_t *dtsGetPortAttributes(gdl_pd_id_t port_type, int *count);
	int dtsSetPortAttributes(gdl_pd_id_t port_type, int attr_id, int attr_value);
	int dtsGetPortAttributeValue(gdl_pd_id_t port_type, int attr_id, int *attr_value);

	void dtsPrintDisplayInfo(gdl_display_info_t *d);
	char * dtsDisplayInfoString(gdl_display_info_t *d);

#endif

// Parameters
enum dts_param
{
	P_DTS_COLOR,
	P_DTS_DELAY,
	P_DTS_TIMEOUT,
	P_DTS_MODE,
	P_DTS_PORT,
	P_DTS_TV_OUTPUT,
	P_DTS_LOOPS,
	P_DTS_PROMPT,
	P_DTS_DISPLAYID,
	P_DTS_PLANE_ID,
	P_DTS_RESET_PLANE,
};

// Errors
enum dts_errors
{
	DTS_NONE,
	DTS_ERROR_MESSAGE,
	DTS_INVALID_TEST_NAME,
	DTS_FUNC_FAIL,
	DTS_NO_PARAM,
	DTS_PARAM_INVALID,
	DTS_WRITE_VFY_FAIL,
	DTS_FILE_OPEN_FAIL,
	DTS_FILE_CLOSE_FAIL,
	DTS_RANGE_FAIL,
	DTS_VALIDATION_FAIL,
	DTS_READ_FAIL,
	DTS_FUNC_FAIL_RET
};

/* Macro to make reporting failures easier */
#define FAIL(fname, ret) tsError(DTS_ERROR_MESSAGE, "ERROR 0x%2.2X: %s failed at line %d\n", \
                                 (ret), (fname), __LINE__);

// General Functions
bool dtsParameterFlag(const char * szName);
bool dtsGetPrompt(void);
bool dtsGetDelay (uint32_t *delay);
uint32_t dtsGetLoopCount(void);
void dtsGetTimeOut(uint32_t *timeOut);
char* dtsDisplayCat(char* displayBuffer, const char* tempBuffer, size_t *currentSize);
uint32_t dtsReportError(uint32_t errCode, ...);
char *dtsAttribId2string(int id);
char *dtsRefreshId2string(int id);

// PCI functions
bool dtsGetPciMemory(int bus, int dev, int fun, int off, unsigned int * result);

// Memory Functions
void dtsMemoryRead(uint32_t address, uint32_t *data, uint32_t size, bool bDisplay);
void dtsMemoryWrite(uint32_t address, uint32_t data, uint32_t size, bool bDisplay, bool bVerify);

// CPU Functions
bool readRegister(uint32_t address, uint32_t* data);
int getSiliconSerialNumber(uint64_t *siliconSerialNumber);
void getSiliconCPUId(uint32_t *siliconCPUId);

typedef enum 
{
	I2C_AND_MASK,
	I2C_OR_MASK
} I2C_MASK_TYPE;

//i2c Functions
void dtsI2CWriteMask(uint32_t bus, uint32_t dev, uint32_t address, uint8_t data, I2C_MASK_TYPE mask, bool bDisplay);

#ifdef __cplusplus
}
#endif

#endif





