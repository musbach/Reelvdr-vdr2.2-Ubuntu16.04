/****************************************************************************
 * Copyright (c) 2008-2011 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * Module Name:
 *     LR_InputHandlerKeyDefs.h
 * 
 * Abstract:
 *     Class to handle serial communication with PIC for IR and CEC commands.
 ***************************************************************************/

#ifndef LR_INPUTHANDLERKEYDEFS_H
#define LR_INPUTHANDLERKEYDEFS_H

typedef INT32 LR_VIRTUAL_KEY_T;

// 
/*!
 * \brief
 * These key definitions were taken from the CEA 2014 draft version 0.01
 * 
 */
#define LR_VK_OK 0x0D
#define LR_VK_POUND 0x23
#define LR_VK_LEFT 0x25
#define LR_VK_UP 0x26
#define LR_VK_RIGHT 0x27
#define LR_VK_DOWN 0x40
#define LR_VK_STAR 0x2A
#define LR_VK_0 0x30
#define LR_VK_1 0x31
#define LR_VK_2 0x32
#define LR_VK_3 0x33
#define LR_VK_4 0x34
#define LR_VK_5 0x35
#define LR_VK_6 0x36
#define LR_VK_7 0x37
#define LR_VK_8 0x38
#define LR_VK_9 0x39

#define LR_VK_BACK 0xA6

#define LR_VK_MUTE 0x1008
#define LR_VK_VOLDOWN 0x1009
#define LR_VK_VOLUP 0x100A
#define LR_VK_SKIP 0x100B
#define LR_VK_REPLAY 0x100C
#define LR_VK_STOP 0x100D

#define LR_VK_CLEAR 0x101B
#define LR_VK_ENTER 0x101C

#define LR_VK_CHUP 0x1021
#define LR_VK_CHDOWN 0x1022
#define LR_VK_PLAY 0x102E
#define LR_VK_PAUSE 0x102F
#define LR_VK_RECORD 0x1030

#define LR_VK_FORWARD 0x1031
#define LR_VK_REWIND 0x1032

#define LR_VK_START 0x200D

#define LR_VK_DVDMENU 0x2024
#define LR_VK_TVJUMP 0x2025
#define LR_VK_MYTV 0x2046
#define LR_VK_MYMUSIC 0x2047
#define LR_VK_RECTV 0x2048
#define LR_VK_MYPICTURES 0x2049
#define LR_VK_MYVIDEOS 0x204A
#define LR_VK_DVDANGLE 0x204B
#define LR_VK_DVDAUDIO 0x204C
#define LR_VK_DVDSUBTITLE 0x204D

#define LR_VK_OEM1 0x2080
#define LR_VK_OEM2 0x2081
#define LR_VK_GUIDE 0x208D
#define LR_VK_INFO 0x2209

// keys defined related to CEC inputs/outputs
// using 0x20B0 code space, since that seems relatively empty

#define LR_VK_POWER				0x20B0	// Note this is 'power' toggle button on remote, not hardware power on/off control to PIC
#define LR_VK_HOME				0x20B1
#define LR_VK_FAST_FWD			0x20B2
#define LR_VK_NO_KEY			0x20B3
#define LR_VK_RECALL_FAVORITE_0 0x20B4
#define LR_VK_BACK_SPACE		0x20B5
#define LR_VK_PINP_TOGGLE		0x20B6
#define LR_VK_F1				0x20B7
#define LR_VK_F2				0x20B8
#define LR_VK_F3				0x20B9
#define LR_VK_F4				0x20BA
#define LR_VK_PERIOD			0x20BB
#define LR_VK_HELP				0x20BC
#define LR_VK_PAGE_UP			0x20BD
#define LR_VK_PAGE_DOWN			0x20BE
#define LR_VK_EJECT_TOGGLE		0x20BF
#define LR_VK_SKIP_FWD			0x20C0
#define LR_VK_SKIP_REV			0x20C1
#define LR_VK_INVALID_KEY		0x20C2	// DO NOT put this into the key table; used to signal a timeout change
#define LR_VK_POWER_DOWN		0x20C3	// Actual power down command from app to middleware to PIC controller
#define LR_VK_SOURCE			0x20C4	//  'source' button
#define LR_VK_POWER_ON			0x20C5	// used with CEC power on command, not deliverable from remote control power toggle button
#define LR_VK_POWER_OFF			0x20C6	// ditto this
#define LR_VK_SETUP				0x20C9
#define LR_VK_KEYBOARD			0x20CA
#define LR_VK_SLEEP				0x20CB
#define LR_VK_CC				0x20CC
#define LR_VK_PVR_STOP			0x20CD
#define LR_VK_PVR_RUN			0x20CE
#define LR_VK_TV_POWER			0x20CF

#define LR_VK_ACTIVE_SOURCE		0x20C7	// CEC has told us we are <Active Source>
#define LR_VK_INACTIVE_SOURCE	0x20C8	// CEC has said someone else is <Active Source>

#endif
