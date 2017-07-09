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
 *     LR_CECIRCommon.h
 * 
 * Abstract:
 *     Class to handle serial communication with PIC for IR and CEC commands.
 ***************************************************************************/

#ifndef _CECIR_COMMON_H
#define _CECIR_COMMON_H

// CEC test mode key output
#define LR_VK_CEC_TEST	0xCE	// NOTE -- ensure this is unused in the key defs file...
#define CECIR_INPUT_EVENT	"CECIR_Input_Event"		// key from CEC/IR to host
#define CECIR_OUTPUT_EVENT	"CECIR_Output_Event"	// key from host to CEC/IR 
#define CECIR_CONFIG_EVENT	"CECIR_Config_Event"	// CecIr config storage has been changed
#define CECIR_POWER_HANDLER_NAME "Power_YFI_CecIr_d"// name used when registering with power handler client
#define CECIR_OSD_NAME		"Lamar Creek"			// CEC 1.3a OSD name; must be 14 or fewer characters
#define CECIR_VENDOR_ID		0x0002B3				// one of the Intel OUI numbers
#define CECIR_CONFIG_EVENT_HDMI	0	// config change is due to HDMI hot plug
#define CECIR_CONFIG_EVENT_CEC	1	// config change is due to CEC event
#define CECIR_CONFIG_EVENT_USER	2	// config change is due to user input
#define CECIR_CONFIG_EVENT_NONE	-1	// no config change currently
// CEC/IR configuration
#define CONFIG_POLL_TIMEOUT			12000	// poll for config changes every 12 sec
#define CECIRCONFIG_NO_CEC			0
#define CECIRCONFIG_CEC				1

#define CECIRCONFIG_NO_IR_CODE		-1

#define CECIRCONFIG_INVALID_ADDRESS 0xFF

// values used with SerialConfig.h and configuration fields
// setting is manual or auto
#define CECIRCONFIG_NA				-1	// setting does not apply
#define CECIRCONFIG_MANUAL			0
#define CECIRCONFIG_AUTO			1

// means of control is one of these
#define CECIRCONFIG_SETTING_NA		-1	// does not apply
#define CECIRCONFIG_SETTING_NONE 	0
#define CECIRCONFIG_SETTING_CEC		1
#define CECIRCONFIG_SETTING_IR		2
#define CECIRCONFIG_SETTING_OTHER	3	//eg, ZWave...
// device used for control is one of these
#define CECIRCONFIG_SETTING_TV		1
#define CECIRCONFIG_SETTING_AVR		2
#define CECIRCONFIG_SETTING_STB		3

//Physical Address F.F.F.F when not assigned.
#define CEC_INVALID_PHYSICAL_ADDRESS  0xFFFF

// command opcodes, from HDMI spec tables
#define CECCMD_POLL						0x66	// not defined in the spec
#define CECCMD_ACK_STATE				0x67	// not defined in spec
#define CECCMD_ADRS_SET					0x68	// not defined in spec
#define CECCMD_ACTIVE_SOURCE			0x82
#define CECCMD_INACTIVE_SOURCE			0x9D
#define CECCMD_REQUEST_ACTIVE_SOURCE	0x85
#define CECCMD_IMAGE_VIEW_ON			0x04
#define CECCMD_TEXT_VIEW_ON				0x0D
#define	CECCMD_ROUTING_CHANGE			0x80
#define CECCMD_ROUTING_INFORMATION		0x81
#define CECCMD_SET_STREAM_PATH			0x86
#define CECCMD_STANDBY					0x36
#define CECCMD_CEC_VERSION				0x9E
#define CECCMD_GET_CEC_VERSION			0x9F
#define CECCMD_GIVE_PHYSICAL_ADDRESS	0x83
#define CECCMD_GET_MENU_LANGUAGE		0x91
#define CECCMD_REPORT_PHYSICAL_ADDRESS	0x84
#define CECCMD_SET_MENU_LANGUAGE		0x32
#define CECCMD_DECK_CONTROL				0x42
#define CECCMD_DECK_STATUS				0x1B
#define CECCMD_GIVE_DECK_STATUS			0x1A
#define CECCMD_PLAY						0x41
#define CECCMD_GIVE_TUNER_DEVICE_STATUS	0x08
#define CECCMD_SELECT_ANALOG_SERVICE	0x92
#define CECCMD_SELECT_DIGITAL_SERVICE	0x93
#define CECCMD_TUNER_DEVICE_STATUS		0x07
#define CECCMD_TUNER_STEP_DECREMENT		0x06
#define CECCMD_TUNER_STEP_INCREMENT		0x05
#define CECCMD_DEVICE_VENDOR_ID			0x87
#define CECCMD_GIVE_DEVICE_VENDOR_ID	0x8C
#define CECCMD_VENDOR_COMMAND			0x89
#define CECCMD_VENDOR_COMMAND_WITH_ID	0xA0
#define CECCMD_VENDOR_REMOTE_BUTTON_DOWN 0x8A
#define CECCMD_VENDOR_REMOTE_BUTTON_UP	0x8B
#define CECCMD_SET_OSD_STRING			0x64
#define CECCMD_GIVE_OSD_NAME			0x46
#define CECCMD_SET_OSD_NAME				0x47
#define CECCMD_USER_CONTROL_PRESSED		0x44
#define CECCMD_USER_CONTROL_RELEASED	0x45
#define CECCMD_GIVE_DEVICE_POWER_STATUS	0x8F
#define CECCMD_REPORT_POWER_STATUS		0x90
#define CECCMD_FEATURE_ABORT			0x00
#define CECCMD_ABORT					0xFF
#define CECCMD_GIVE_AUDIO_STATUS		0x71
#define CECCMD_GIVE_SYSTEM_AUDIO_MODE_STATUS 0x7D
#define CECCMD_REPORT_AUDIO_STATUS		0x7A
#define CECCMD_SET_SYSTEM_AUDIO_MODE	0x72
#define CECCMD_SYSTEM_AUDIO_MODE_REQUEST 0x70
#define CECCMD_SYSTEM_AUDIO_MODE_STATUS 0x7E
// HDMI 1.4 Spec
#define CECCMD_MENU_REQUEST             0x8D
#define CECCMD_MENU_STATUS              0x8E
#define CECCMD_SET_AUDIO_RATE           0x9A
#define CECCMD_INITIATE_ARC             0xC0
#define CECCMD_REPORT_ARC_INITIATED     0xC1
#define CECCMD_REPORT_ARC_TERMINATED    0xC2
#define CECCMD_REQUEST_ARC_INITIATION   0xC3
#define CECCMD_REQUEST_ARC_TERMINATION  0xC4
#define CECCMD_TERMINATE_ARC            0xC5
#define CECCMD_CDC_MESSAGE              0xF8
// One Touch Record Feature
#define CECCMD_RECORD_OFF               0x0B
#define CECCMD_RECORD_ON                0x09
#define CECCMD_RECORD_STATUS            0x0A
#define CECCMD_RECORD_TV_SCREEN         0x0F
// Timer Programming Feature
#define CECCMD_CLEAR_ANALOGUE_TIMER     0X33
#define CECCMD_CLEAR_DIGITAL_TIMER      0X99
#define CECCMD_CLEAR_EXTERNAL_TIMER     0XA1
#define CECCMD_SET_ANALOGUE_TIMER       0X34
#define CECCMD_SET_DIGITAL_TIMER        0X97
#define CECCMD_SET_EXTERNAL_TIMER       0XA2
#define CECCMD_SET_TIMER_PROGRAM_TITLE  0X67
#define CECCMD_TIMER_CLEARED_STATUS     0X43
#define CECCMD_TIMER_STATUS             0X35

// HDMI 1.3a spec user key definitions
#define CECUSERCMD_VOLUME_UP			0x41
#define CECUSERCMD_VOLUME_DOWN			0x42
#define CECUSERCMD_VOLUME_MUTE			0x43
#define CECUSERCMD_CHANNEL_UP			0x30
#define CECUSERCMD_CHANNEL_DOWN			0x31
#define CECUSERCMD_POWER_KEY			0x40	// remote control power toggle key
#define CECUSERCMD_POWER_TOGGLE			0x6B	// CEC 1.3a feature
#define CECUSERCMD_POWER_OFF			0x6C
#define CECUSERCMD_POWER_ON				0x6D
#define CECUSERCMD_NUMBER_0				0x20
#define CECUSERCMD_NUMBER_1				0x21
#define CECUSERCMD_NUMBER_2				0x22
#define CECUSERCMD_NUMBER_3				0x23
#define CECUSERCMD_NUMBER_4				0x24
#define CECUSERCMD_NUMBER_5				0x25
#define CECUSERCMD_NUMBER_6				0x26
#define CECUSERCMD_NUMBER_7				0x27
#define CECUSERCMD_NUMBER_8				0x28
#define CECUSERCMD_NUMBER_9				0x29
#define CECUSERCMD_SELECT				0x00

// HDMI 1.3a spec, 10.2
#define CEC_TV_ADDRESS					0
#define CEC_RECORDING_DEVICE_1_ADDRESS	1
#define CEC_RECORDING_DEVICE_2_ADDRESS	2
#define CEC_TUNER_1_ADDRESS				3
#define CEC_PLAYBACK_DEVICE_1_ADDRESS	4
#define CEC_AUDIO_SYSTEM_ADDRESS		5
#define CEC_TUNER_2_ADDRESS				6
#define CEC_TUNER_3_ADDRESS				7
#define CEC_PLAYBACK_DEVICE_2_ADDRESS	8
#define CEC_RECORDING_DEVICE_3_ADDRESS	9
#define CEC_TUNER_4_ADDRESS				10
#define CEC_PLAYBACK_DEVICE_3_ADDRESS	11
#define CEC_RESERVED_1_ADDRESS			12
#define CEC_RESERVED_2_ADDRESS			13
#define CEC_FREE_USE_ADDRESS			14  //Do Not use for HDMI 1.4
#define CEC_SPECIFIC_USE_ADDRESS        14
#define CEC_UNREGISTERED_ADDRESS		15 // as initiator
#define CEC_BROADCAST_ADDRESS			15 // as destination
// command bits to send to PIC
#define BROADCAST_COMMAND		1
#define DIRECT_COMMAND			0

// ack state from bus
#define CEC_COMMAND_ACKED		0
#define CEC_COMMAND_NOT_ACKED	1

// HDMI 1.3 spec, CE17 Operand Descriptions

// Abort reasons
#define CECCMD_UNRECOGNIZED_OPCODE				0
#define CECCMD_NOT_IN_CORRECT_MODE_TO_RESPOND	1
#define CECCMD_CANNOT_PROVIDE_SOURCE			2
#define CECCMD_INVALID_OPERAND					3
#define CECCMD_REFUSED							4
#define CECCMD_UNABLE_TO_DETERMINE              5   // HDMI 1.4
// CEC versions
#define CECVERSION_UNKNOWN	(-1)
#define CECVERSION_1_1		0x00
#define CECVERSION_1_2		0x01
#define CECVERSION_1_2a		0x02
#define CECVERSION_1_3		0x03
#define CECVERSION_1_3a		0x04
#define CECVERSION_1_4      0x05

// Device Type
#define CECDEVICTTYPE_TV				0
#define CECDEVICTTYPE_RECORDING_DEVICE	1
#define CECDEVICTTYPE_RESERVED			2
#define CECDEVICTTYPE_TUNER				3
#define CECDEVICTTYPE_PLAYBACK_DEVICE	4
#define CECDEVICTTYPE_AUDIO_SYSTEM		5
#define CECDEVICTTYPE_PURE_CEC_SWITCH   6       // HDMI 1.4
#define CECDEVICTTYPE_VIDEO_PROCESSOR   7       // HDMI 1.4
#define CECDEVICTTYPE_UNDEFINED			0xFF	// not in CEC spec, used to init data
#define CECSYSYTEMAUDIOSTATUS_OFF		0
#define CECSYSYTEMAUDIOSTATUS_ON		1

// expected device IDs for config storage (correlate with CEC devices)
#define CECDEVICEID_TV1					"tv1"
#define CECDEVICEID_TV2					"tv2"
#define CECDEVICEID_AUDIO_SYSTEM		"audio1"
#define CECDEVICEID_RECORDING_DEVICE1	"recorder1"
#define CECDEVICEID_RECORDING_DEVICE2	"recorder2"
#define CECDEVICEID_RECORDING_DEVICE3	"recorder3"
#define CECDEVICEID_TUNER1				"tuner1"
#define CECDEVICEID_TUNER2				"tuner2"
#define CECDEVICEID_TUNER3				"tuner3"
#define CECDEVICEID_TUNER4				"tuner4"
#define CECDEVICEID_PLAYBACK_DEVICE1	"playback1"
#define CECDEVICEID_PLAYBACK_DEVICE2	"playback2"
#define CECDEVICEID_PLAYBACK_DEVICE3	"playback3"
#define CECDEVICEID_NO_DEVICE			"none"
#define CECDEVICEID_SPECIFIC_USE_DEVICE "specific use"

#define CECNUMTV						2
#define CECNUMAUDIO						1
#define CECNUMRECORDER					3
#define CECNUMTUNER						4
#define CECNUMPLAYBACK					3

// Status Request.
// The Status Request mode which can be report once or on all future changes, or off.
#define CEC_STATUS_REQUEST_ON                   1
#define CEC_STATUS_REQUEST_OFF                  2
#define CEC_STATUS_REQUEST_ONCE                 3

// Deck Control Mode constants.
#define CEC_DECK_MODE_SKIP_FORWARD_WIND         1
#define CEC_DECK_MODE_SKIP_REVERSE_REWIND       2
#define CEC_DECK_MODE_STOP                      3
#define CEC_DECK_MODE_EJECT                     4

// Deck Info constants  Indicates the current status of tape or disk deck
#define CEC_DECK_INFO_PLAY                       0x11
#define CEC_DECK_INFO_RECORD                     0x12
#define CEC_DECK_INFO_PlAY_REVERSE               0x13
#define CEC_DECK_INFO_STILL                      0x14
#define CEC_DECK_INFO_SLOW                       0x15
#define CEC_DECK_INFO_SLOW_REVERSE               0x16
#define CEC_DECK_INFO_FAST_FORWARD               0x17
#define CEC_DECK_INFO_FAST_REVERSE               0x18
#define CEC_DECK_INFO_NO_MEDIA                   0x19
#define CEC_DECK_INFO_STOP                       0x1A
#define CEC_DECK_INFO_SKIP_FORWARD_WIND          0x1B
#define CEC_DECK_INFO_SKIP_REVERSE_REWIND        0x1C
#define CEC_DECK_INFO_INDEX_SEARCH_FORWARD       0x1D
#define CEC_DECK_INFO_INDEX_SEARCH_REVERSE       0x1E
#define CEC_DECK_INFO_OTHER_STATUS               0x1F

// size of largest data buffer to be sent to PIC
#define MAX_CEC_DATA_SIZE				16
#define MAX_VERSION_DATA_SIZE			16

// CEC Power status.  Used to indicate current power status of device.
#define CEC_POWER_ON                0
#define CEC_POWER_STANDBY           1
#define CEC_POWER_STANDBY_TO_ON     2
#define CEC_POWER_ON_TO_STANDBY     3

// configuration storage GUID
// {D22EB7B5-66C1-432e-A38E-237AB1D944E8}

// CECIR Configuration storage paths
extern char CECIRConfigPath[];

extern char CECConfigDeviceType[];			// string
extern char CECIRConfigManufacturer[];		// string
extern char CECIRConfigName[];				// string
extern char CECIRConfigCECControl[];		// int, 0 -> no CEC or not CEC 1.3a, 1 -> CEC 1.3a
extern char CECIRConfigIRControl[];			// signed int, -1 -> no code, other value is code (4 digit number)

#endif
