/********************************************************************
 * File Name: io8051EventMap.h
 ********************************************************************
 *  Copyright (c) 2011 Intel Corporation
 *  DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *  This Distributable As Sample Source Software is subject to the terms and conditions of
 *  the Intel Software License Agreement for the Intel(R) Media Processor Software
 *  Development Kit
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Purpose: Header file for customer to define IO Wake Events and Mappings
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *-----------------------------------------------------------------------------
 * Author: Rick Bell
 * Date:   10/04/2011
 *******************************************************************/

#ifndef IO_8051_EVENT_MAP_H
#define IO_8051_EVENT_MAP_H

 typedef enum {
	IO_8051_WAKE_EVT_NONE,				// IO_8051_WAKE_EVT_NONE requireed to be 0
	IO_8051_WAKE_EVT_RTC,				// RTC Wake Event
	IO_8051_WAKE_EVT_IR,				// IR Wake Events
	IO_8051_WAKE_EVT_CEC,				// CEC Wake Events
    IO_8051_WAKE_EVT_WoWLAN,			// Wake On WiFi Event
    IO_8051_WAKE_EVT_WoLAN,				// Wake On LAN Event
    IO_8051_WAKE_EVT_WATCHDOG,			// Watchdog Wake Event
	IO_8051_WAKE_EVT_POWER_BUTTON,		// Power Button Wake Event
    IO_8051_WAKE_EVT_FP_INT,			// Front Panel Wake Event
    IO_8051_WAKE_EVT_BLUETOOTH,			// Wake On BlueTooth Event
    IO_8051_WAKE_EVT_RF4CE,				// RF4CE Wake Events
    IO_8051_WAKE_EVT_RF_CUSTOM,			// RF Custom Wake Event
    IO_8051_WAKE_EVT_NUM_EVENTS			// IO_8051_WAKE_EVT_NUM_EVENTS required to be last entry in enumeration. This is number of entries in the enumeration
} IO_8051_wake_event_t;

#endif // IO_8051_EVENT_MAP_H

