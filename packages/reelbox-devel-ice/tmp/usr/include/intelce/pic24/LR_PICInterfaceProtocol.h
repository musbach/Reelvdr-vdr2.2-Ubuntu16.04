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
 *     LR_PICInterfaceProtocol.h
 * 
 * Abstract:
 *     Macros and typedefs for PIC interface protocol.
 ***************************************************************************/

/*!
* \file LR_PICInterfaceProtocol.h
* \brief
* Macros defining objects related to microcontroller interface library
* 
* \remarks
* Microcontroller handles CEC and IR interfaces for the system.  Objects here allow caller
* to send and receive messages according to the microcontroller interface document.
* 
*/

#ifndef _PIC_INTERFACE_PROTOCOL_H
#define _PIC_INTERFACE_PROTOCOL_H

#include "tdef.h"
#include "LR_CECIRCommon.h"

// PIC/Host command numbers
//									Cmd	  Meaning											Source
#define LR_PIC_IR					1	// Received IR Code follows							PIC
#define LR_HOST_IR					1	// IR Blaster Code Follows							Host

#define LR_PIC_CEC					2	// Received CEC Code Follows							PIC
#define LR_HOST_CEC					2	// Transmit CEC Code Follows							Host

#define LR_HOST_ADRS				3	// Store CEC Physical / Logical Address				Host

#define LR_PIC_PWRBTN				4	// Power Button										PIC
#define LR_HOST_PWRDN				4	// Power Down										Host

#define LR_HOST_CECACK				5	// Set/Clear CEC ACK bit								Host

#define LR_BOTH_ACK					6	// ACK												Both
#define LR_BOTH_NAK					7	// NAK												Both

#define LR_HOST_STARTUP				8	// Startup message									Host

#define LR_PIC_VERSION				9	// PIC version message								PIC

#define LR_BOTH_PROGRAM				10	// Program mode					          			Host

#define LR_PIC_RS232				11	// External RS232 Command Interface      			PIC

#define LR_PIC_IR_REPEAT_START		12	// Received IR Repeat Start Code 					PIC
#define LR_PIC_IR_REPEAT_STOP		13	// Received IR Repeat Stop Code						PIC

#define LR_BOTH_IR_REPEAT_MODE		14	// Sets IR Repeat Mode Code							Both

#define LR_PIC_IO_EVENT         	15	//Received IO Event									PIC
#define LR_PIC_IO_TIMER_VALUE   	16	//Received IO Timer Value							PIC
#define LR_PIC_IR_PLUS				17	// Received IR Plus Code							PIC

#define LR_PIC_CHECKSUM         	18	//Checksum											PIC
#define LR_PWM_PANEL				19	//PWM Panel											Host
#define LR_PWM_FAN					20	//PWM Fan											Host
#define LR_PIC_CT					21	//Capactive Touch									PIC
#define LR_PIC_GPIO					22	//PIC GPIOs											PIC
#define LR_PIC_POWERUPKEYS			23	// Get key mask for any keys held during powerup
#define LR_PIC_LTDC					24	// 
#define LR_PIC_WDT_SET				25
#define LR_PIC_WDT_HEARTBEAT		26
#define LR_PIC_IR_PLUS_REPEAT_START	27	// Received IR Plus - Repeat Start Code				PIC
#define LR_PIC_IR_PLUS_REPEAT_STOP	28	// Received IR Plus - Repeat Stop Code				PIC
#define LR_PWM_LOGO					29	//PWM Logo											Host
#define LR_PIC_FACMODE				30

// registration parameters
#define CEFDK_REGISTRATION		0x01
#define MIDDLEWARE_REGISTRATION	0x02

// IR Repeat Mode parameters
#define IR_REPEAT_MODE_BUFFER		0x01
#define IR_REPEAT_MODE_START_STOP	0x02

// PIC buffer classes
// Classes corresponding to messages to the PIC have serialize()
// Classes corresponding to messages from the PIC have static unserialize() to recover an instance from a buffer
// All begin with cmd and have a length equal to the total length of the message when serialized, including cmd

/*!
* \brief
* Interface object base class
* 
* \remarks
* All interface objects have a data buffer and data length; each object represents a command type.<br>
* All buffers begin with the command type and have a total buffer length equal to the total length of the message when serialized, including cmd.<br>
* Classes corresponding to messages to the PIC have serialize().  Classes corresponding to messages from the PIC have static unserialize() to recover an instance from a buffer
* 
*/
class PicBuffer {
	public:
		INT8 cmd;
		INT8 length;
		PicBuffer() { };
		virtual ~PicBuffer() {};
		virtual UINT8* serialize() = 0;
};
	
// RS232 code -- input only, so serialize returns NULL
/*!
* \brief
* RS232 message interface object class, to receive RS232 codes from microcontroller
* 
* \remarks
* Input only, so serialize() just returns null.<br>
* Object uses unserialize() to parse RS232 codes from an incoming buffer.
* 
*/
class PicBufferRS232 : public PicBuffer {
	public:
		UINT8 code;			// ASCII code, 1 byte
		PicBufferRS232() { cmd = LR_PIC_RS232; length = 3; };
		virtual ~PicBufferRS232() {};
		virtual UINT8* serialize() { return NULL; };
		static PicBufferRS232 * unserialize( UINT8* buffer ) { PicBufferRS232* pBuffer = new PicBufferRS232; pBuffer->code = buffer[1]; return pBuffer; };
};

// version -- input only, so serialize just returns NULL
/*!
* \brief
* Version interface object class
* 
* \remarks
* Input-only message to recover version information from an incoming microcontroller buffer.<br>
* Version string is 0-terminated.  Length parameter is total length of incoming buffer.
* 
*/
class PicBufferVersion : public PicBuffer {
	public:
		PicBufferVersion() { cmd = LR_PIC_VERSION; length = 1; memset(version, 0, sizeof(version)); };
		virtual ~PicBufferVersion() {};
		UINT8 version[MAX_VERSION_DATA_SIZE+1];
		UINT8* serialize() { cmdBuffer = LR_PIC_VERSION; return &cmdBuffer; };		
		static PicBufferVersion* unserialize( UINT8* _buffer ) 
		{ 
		PicBufferVersion* pBuffer = new PicBufferVersion; 
		strncpy( (char*)(pBuffer->version), (const char*)(_buffer+1), MAX_VERSION_DATA_SIZE); 
		pBuffer->length = strlen( (char*)(pBuffer->version) ) + 2; 
		return pBuffer; 
		};
	private:
		UINT8 cmdBuffer;	
};

// startup command -- output only, so unserialize returns NULL
/*!
* \brief
* Startup message interface object class
* 
* \remarks
* Output only, so unserialize() just returns null.<br>
* Object initializes startup parameter to middleware registration, so no further initialization is needed to use this object.
* 
*/
class PicBufferStartup : public PicBuffer {
	public:
		INT8 registration;
		PicBufferStartup() { cmd = LR_HOST_STARTUP; length = 2; registration = MIDDLEWARE_REGISTRATION; };
		virtual ~PicBufferStartup() {};
		virtual UINT8* serialize() { buffer[0] = cmd; buffer[1] = registration; return buffer; };
		static PicBufferStartup* unserialize( UINT8* buffer ) { return NULL; };
	private:
		UINT8 buffer[2];		
};

// IR code -- input only, so serialize returns NULL
/*!
* \brief
* IR message interface object class, to receive IR code from microcontroller
* 
* \remarks
* Input only, so serialize() just returns null.<br>
* Object uses unserialize() to parse irDevice and irNumber from an incoming buffer.
* 
*/
class PicBufferIR : public PicBuffer {
	public:
		UINT8 irDevice;			// keycode, two bytes
		UINT8 irNumber;
		PicBufferIR() { cmd = LR_PIC_IR; length = 3; };
		virtual ~PicBufferIR() {};
		virtual UINT8* serialize() { return NULL; };
		static PicBufferIR* unserialize( UINT8* buffer ) 
		{ 
			PicBufferIR* pBuffer = new PicBufferIR; 
			pBuffer->irDevice = buffer[1]; 
			pBuffer->irNumber = buffer[2]; 
			return pBuffer; 
		};
};

// IR Repeat Start code -- input only, so serialize returns NULL
/*!
* \brief
* IR message interface object class, to receive IR Repeat Start code from microcontroller
* 
* \remarks
* Input only, so serialize() just returns null.<br>
* Object uses unserialize() to parse irDevice and irNumber from an incoming buffer.
* 
*/
class PicBufferRepeatStartIR : public PicBuffer {
	public:
		UINT8 irDevice;			// keycode, two bytes
		UINT8 irNumber;
		PicBufferRepeatStartIR() { cmd = LR_PIC_IR_REPEAT_START; length = 3; };
		virtual ~PicBufferRepeatStartIR() {};
		virtual UINT8* serialize() { return NULL; };
		static PicBufferRepeatStartIR* unserialize( UINT8* buffer ) { PicBufferRepeatStartIR* pBuffer = new PicBufferRepeatStartIR; pBuffer->irDevice = buffer[1]; pBuffer->irNumber = buffer[2]; return pBuffer; };
};

// IR Repeat Stop code -- input only, so serialize returns NULL
/*!
* \brief
* IR message interface object class, to receive IR Repeat Stop code from microcontroller
* 
* \remarks
* Input only, so serialize() just returns null.<br>
* Object uses unserialize() to parse irDevice and irNumber from an incoming buffer.
* 
*/
class PicBufferRepeatStopIR : public PicBuffer {
	public:
		UINT8 irDevice;			// keycode, two bytes
		UINT8 irNumber;
		PicBufferRepeatStopIR() { cmd = LR_PIC_IR_REPEAT_STOP; length = 3; };
		virtual ~PicBufferRepeatStopIR() {};
		virtual UINT8* serialize() { return NULL; };
		static PicBufferRepeatStopIR* unserialize( UINT8* buffer ) { PicBufferRepeatStopIR* pBuffer = new PicBufferRepeatStopIR; pBuffer->irDevice = buffer[1]; pBuffer->irNumber = buffer[2]; return pBuffer; };
};

// IR Repeat Mode command -- output only, so unserialize returns NULL
/*!
* \brief
* IR Repeat Mode message interface object class
* 
* \remarks
* Supports both Input and Output.<br>
* Object initializes IR Repeat Mode parameter to either IR Repeat Buffer Mode or IR Repeat Start/Stop Mode irRepeatMode, so no further initialization is needed to use this object.
* 
*/
class PicBufferIrRepeatMode : public PicBuffer {
	public:
		UINT8 irRepeatMode;
		PicBufferIrRepeatMode() { cmd = LR_BOTH_IR_REPEAT_MODE; length = 2; irRepeatMode = IR_REPEAT_MODE_BUFFER; };
		virtual ~PicBufferIrRepeatMode() {};
		// Output Function
		virtual UINT8* serialize() { buffer[0] = cmd; buffer[1] = irRepeatMode; return buffer; };
		// Input Function
		static PicBufferIrRepeatMode* unserialize( UINT8* buffer ) { PicBufferIrRepeatMode* pBuffer = new PicBufferIrRepeatMode; pBuffer->irRepeatMode = buffer[1]; return pBuffer; };
	private:
		UINT8 buffer[2];		
};

// IR Plus code -- input only, so serialize returns NULL
/*!
* \brief
* IR message interface object class, to receive IR Plus code from microcontroller
* 
* \remarks
* Input only, so serialize() just returns null.<br>
* Object uses unserialize() to parse irType, irLength and irData from an incoming buffer.
* 
*/
class PicBufferIRPlus : public PicBuffer {
	public:
		UINT8 irType;			// IR Protocol Type
		UINT8 irLength;			// IR Key Code Number of Bytes
		UINT8 irData[8];		// IR Key Code - maximum of 8 bytes

		PicBufferIRPlus( ) { cmd = LR_PIC_IR_PLUS; length = 11;  irData[0] = 0;};
		virtual ~PicBufferIRPlus() {};
		virtual UINT8* serialize() { return NULL; };
		static PicBufferIRPlus* unserialize( UINT8* buffer ) 
		{ 
			int i = 0;
			PicBufferIRPlus* pBuffer = new PicBufferIRPlus;
			pBuffer->irType = buffer[1];
			pBuffer->irLength = buffer[2];
			
			if (sizeof(pBuffer->irData) < pBuffer->irLength)
				pBuffer->irLength = sizeof(pBuffer->irData);
		
			for (i = 0; i < pBuffer->irLength; i++)
			{
				pBuffer->irData[i] = buffer[i + 3];
			}
			
		return pBuffer; 
		};
};

// IR Plus - Repeat Start code -- input only, so serialize returns NULL
/*!
* \brief
* IR message interface object class, to receive IR Plus - Repeat Start code from microcontroller
* 
* \remarks
* Input only, so serialize() just returns null.<br>
* Object uses unserialize() to parse irType, irLength and irData from an incoming buffer.
* 
*/
class PicBufferIRPlusRepeatStart : public PicBuffer {
	public:
		UINT8 irType;			// IR Protocol Type
		UINT8 irLength;			// IR Key Code Number of Bytes
		UINT8 irData[8];		// IR Key Code - maximum of 8 bytes

		PicBufferIRPlusRepeatStart( ) { cmd = LR_PIC_IR_PLUS_REPEAT_START; length = 11;  irData[0] = 0;};
		virtual ~PicBufferIRPlusRepeatStart() {};
		virtual UINT8* serialize() { return NULL; };
		static PicBufferIRPlusRepeatStart* unserialize( UINT8* buffer ) 
		{ 
			int i = 0;
			PicBufferIRPlusRepeatStart* pBuffer = new PicBufferIRPlusRepeatStart;
			pBuffer->irType = buffer[1];
			pBuffer->irLength = buffer[2];
			
			if (sizeof(pBuffer->irData) < pBuffer->irLength)
				pBuffer->irLength = sizeof(pBuffer->irData);
		
			for (i = 0; i < pBuffer->irLength; i++)
			{
				pBuffer->irData[i] = buffer[i + 3];
			}
			
		return pBuffer; 
		};
};

// IR Plus - Repeat Stop code -- input only, so serialize returns NULL
/*!
* \brief
* IR message interface object class, to receive IR Plus - Repeat Stop code from microcontroller
* 
* \remarks
* Input only, so serialize() just returns null.<br>
* Object uses unserialize() to parse irType, irLength and irData from an incoming buffer.
* 
*/
class PicBufferIRPlusRepeatStop : public PicBuffer {
	public:
		UINT8 irType;			// IR Protocol Type
		UINT8 irLength;			// IR Key Code Number of Bytes
		UINT8 irData[8];		// IR Key Code - maximum of 8 bytes

		PicBufferIRPlusRepeatStop( ) { cmd = LR_PIC_IR_PLUS_REPEAT_STOP; length = 11;  irData[0] = 0;};
		virtual ~PicBufferIRPlusRepeatStop() {};
		virtual UINT8* serialize() { return NULL; };
		static PicBufferIRPlusRepeatStop* unserialize( UINT8* buffer ) 
		{ 
			int i = 0;
			PicBufferIRPlusRepeatStop* pBuffer = new PicBufferIRPlusRepeatStop;
			pBuffer->irType = buffer[1];
			pBuffer->irLength = buffer[2];
			
			if (sizeof(pBuffer->irData) < pBuffer->irLength)
				pBuffer->irLength = sizeof(pBuffer->irData);
		
			for (i = 0; i < pBuffer->irLength; i++)
			{
				pBuffer->irData[i] = buffer[i + 3];
			}
			
		return pBuffer; 
		};
};

// CEC data from PIC -- input only, so no serialize
// length is total length of input: length of CEC command + 2 (1 for cmd, 1 for length)
// CEC length is length of CEC data itself -- may be 1 (header only), 2 (header and cmd), or many (header, cmd, parameters) up to 16 bytes
/*!
* \brief
* Incoming CEC message interface object class, to receive a CEC message from microcontroller
* 
* \remarks
* Input only, so serialize() just returns null.<br>
* Object uses unserialize() to recover CEC data from an incoming buffer.<br>
* Length is length of entire input buffer.  CecLength is length of CEC portion of incoming buffer.  CecHeader and CecCmd (if included in the incoming message) are decoded from the incoming buffer.  CecParameterLength gives the length of the CEC parameters, if any.
* 
*/
class PicBufferIncomingCEC : public PicBuffer {
	public:
		UINT8 CecCmd;		// CEC command
		UINT8 CecHeader;	// CEC header
		UINT8 CecLength;	// length of CEC data, including header and command (if any)
		UINT8 CecParameterLength;
		UINT8 CecParameters[MAX_CEC_DATA_SIZE];
		PicBufferIncomingCEC() { cmd = LR_PIC_CEC; length = 0; CecCmd = 0; CecHeader = 0; CecLength = 0; CecParameterLength = 0; };
		virtual ~PicBufferIncomingCEC() {};
		virtual UINT8* serialize() { return NULL; };
		static PicBufferIncomingCEC* unserialize( UINT8* buffer ) { 
			if ( buffer[1] > MAX_CEC_DATA_SIZE ) return NULL;
			PicBufferIncomingCEC* pBuffer = new PicBufferIncomingCEC; 
			pBuffer->length = buffer[1] + 2; 
			pBuffer->CecLength = buffer[1]; 
			// get header from buffer
			pBuffer->CecHeader = buffer[2]; 
			if ( pBuffer->CecLength > 1 ) 
			{ 
				// get command and possibly parameters from buffer
				pBuffer->CecCmd = buffer[3];
				if ( pBuffer->CecLength > 2 )
				{
					pBuffer->CecParameterLength = pBuffer->CecLength - 2;
					// have header and command -- get parameters
					memcpy( (void*)(pBuffer->CecParameters), (const void*)&buffer[4], pBuffer->CecLength - 2 );
				}
			}
			return pBuffer; 
		};
};

// CEC data out to PIC -- output only, so serialize, no unserialize
// length is total length of output string
// CecLength is length of CEC command: header, command, and parameters
// note command and parameters may not be in message -- length must reflect that (may be 1, 2, or many)
/*!
* \brief
* Outgoing CEC message interface object class, to send a CEC message to microcontroller
* 
* \remarks
* Output only, so unserialize() is not implemented.<br>
* Object uses serialize() to format CEC data to send to the microcontroller.<br>
* setCommand() gives the object the CEC command to send (if any).<br>
* setHeader() gives the object the CEC header to send<br>
* setParameterLength() gives the total length of the parameters to send.<br>
* CecParameters[] is an array of parameter bytes to be filled in to send to the microcontroller.<br>
* CecBroadcast is a byte to be set to BROADCAST_COMMAND or DIRECT_COMMAND.<br>
* serialize() serializes the data to be sent to the microcontroller.
*/
class PicBufferOutgoingCEC : public PicBuffer {
	public:
		UINT8	CecBroadcast;			// broadcast or direct command
		UINT8 CecParameters[MAX_CEC_DATA_SIZE-2];
		void setCommand( UINT8 cmd ) { CecCommand = cmd; CecLength++; };
		void setHeader( UINT8 hdr ) { CecHeader = hdr; };
		void setParameterLength( UINT8 len ) { CecParameterLength = len; CecLength += len; };
		PicBufferOutgoingCEC() { cmd = LR_PIC_CEC; length = 3; CecBroadcast = 0; CecParameterLength = 0; CecLength = 1; CecHeader = 0; CecCommand = 0; };
		virtual ~PicBufferOutgoingCEC() {};
		virtual UINT8* serialize() { 
			memset( buffer, 0, sizeof(buffer) );
			if ( CecParameterLength > MAX_CEC_DATA_SIZE-2 ) return NULL;
			buffer[0] = LR_PIC_CEC; 
			buffer[1] = CecLength + 1; 
			buffer[2] = CecBroadcast;
			buffer[3] = CecHeader;
			buffer[4] = CecCommand;		// may not actually be part of message
			if ( CecParameterLength > 0 )
				memcpy( (void*)(buffer+5), (const void*)CecParameters, CecParameterLength ); 
			length = CecLength + 3; 
			return buffer; 
		};
	private:
		UINT8 CecLength;				// parameters + header + cmd
		UINT8 CecParameterLength;
		UINT8 CecHeader;
		UINT8 CecCommand;
		UINT8 buffer[MAX_CEC_DATA_SIZE+3];
};

// Power button and power off command 
/*!
* \brief
* Outgoing power message interface object class, to send a power message to microcontroller
* 
* \remarks
* Output only, so unserialize() is not implemented.<br>
* On input, the power message is a single byte, so unserialize() is not required.
*/
class PicBufferPower : public PicBuffer {
	public:
		PicBufferPower() { cmd = LR_HOST_PWRDN; length = 1; };
		virtual ~PicBufferPower() {};
		virtual UINT8* serialize() { cmdBuffer = LR_HOST_PWRDN; return &cmdBuffer; };
	private:
		UINT8 cmdBuffer;
};

// CEC address to send to PIC -- output only, no unserialize
/*!
* \brief
* Outgoing CEC address message interface object class
* 
* \remarks
* Output only, so unserialize() is not implemented.<br>
* Sends HDMI physical address and CEC logical address to microcontroller.
*/
class PicBufferHostAdrs : public PicBuffer {
	public:
		UINT8 physAdrsHigh;		// two bytes physical address
		UINT8 physAdrsLo;
		UINT8 logicalAdrs;		// one byte logical address
		PicBufferHostAdrs() { cmd = LR_HOST_ADRS; length = 4; physAdrsHigh = 0xff; physAdrsLo = 0xff; logicalAdrs = 0xf; };
		virtual ~PicBufferHostAdrs() {};
		virtual UINT8* serialize() { buffer[0] = LR_HOST_ADRS; buffer[1] = physAdrsHigh; buffer[2] = physAdrsLo; buffer[3] = logicalAdrs; return buffer; };
	private:
		UINT8 buffer[4];
};

// CEC ACK -- input only, so no serialize
/*!
* \brief
* Incoming CEC ACK message interface object class
* 
* \remarks
* Input only, so serialize() returns NULL.<br>
* Receives CEC ACK from the microcontroller.<br>
* Object contains the message being ACK'ed and the ACK value.
*/
class PicBufferCECAck : public PicBuffer {
	public:
		UINT8 CecCmd;
		UINT8 CecAck;				// CEC ACK state
		PicBufferCECAck() { cmd = LR_HOST_CECACK; length = 3; CecAck = 0; CecCmd = 0; };
		virtual ~PicBufferCECAck() {};
		virtual UINT8* serialize() { return NULL; };
		static PicBufferCECAck* unserialize( UINT8* buffer ) { PicBufferCECAck* pAck = new PicBufferCECAck(); pAck->CecCmd = buffer[1]; pAck->CecAck = buffer[2]; return pAck; }
		UINT8 getOpcode() { return CecCmd; }
		UINT8 isAck() { return (CecAck == CEC_COMMAND_ACKED); }
};

// PWM Panel command -- output only, so unserialize returns NULL
/*!
* \brief
* PWM Panel message interface object class
* 
* \remarks
* Supports both Input and Output.<br>
* Object initializes PWM Panel Duty Cycle parameter in a range 0 to 100, so no further initialization is needed to use this object.
* 
*/
class PicBufferPanel : public PicBuffer {
	public:
		INT16 pwmPanelFrequency;
		INT8 pwmPanelDutyCycle;
		// Default pwmPanelFrequency - 160Hz with Range of 31Hz to 1KHz and pwmPanelDutyCycle - 50% with Range of 0% to 100%
		PicBufferPanel() { cmd = LR_PWM_PANEL; length = 4;  pwmPanelFrequency = 120; pwmPanelDutyCycle = 50;};
		virtual ~PicBufferPanel() {};
		// Output Function
		virtual UINT8* serialize()	{ 
									pwmBuffer[0] = cmd; 
									pwmBuffer[1] = ((int)pwmPanelFrequency & 0xFF);
									pwmBuffer[2] = (int)pwmPanelFrequency << 8;
									pwmBuffer[3] = pwmPanelDutyCycle;
									return pwmBuffer; 
									};
		// Input Function
		static PicBufferPanel* unserialize( UINT8* pwmBuffer ) { 
															PicBufferPanel* pBuffer = new PicBufferPanel; 
															pBuffer->pwmPanelFrequency = pwmBuffer[1] | (pwmBuffer[2] << 8);
															pBuffer->pwmPanelDutyCycle = pwmBuffer[3]; 
															return pBuffer; 
															};
	private:
		UINT8 pwmBuffer[4];		
};

// PWM Logo command -- output only, so unserialize returns NULL
/*!
* \brief
* PWM Logo message interface object class
* 
* \remarks
* Supports both Input and Output.<br>
* Object initializes PWM Logo Duty Cycle parameter in a range 0 to 100, so no further initialization is needed to use this object.
* 
*/
class PicBufferLogo : public PicBuffer {
	public:
		INT16 pwmLogoFrequency;
		INT8 pwmLogoDutyCycle;
		// Default pwmLogoFrequency - 22 KHZ with Range of 31Hz to 1KHz and pwmLogoDutyCycle - 50% with Range of 0% to 100%
		PicBufferLogo() { cmd = LR_PWM_LOGO; length = 4;  pwmLogoFrequency = 22000; pwmLogoDutyCycle = 50;};
		virtual ~PicBufferLogo() {};
		// Output Function
		virtual UINT8* serialize()	{ 
									pwmBuffer[0] = cmd; 
									pwmBuffer[1] = ((int)pwmLogoFrequency & 0xFF);
									pwmBuffer[2] = (int)pwmLogoFrequency << 8;
									pwmBuffer[3] = pwmLogoDutyCycle;
									return pwmBuffer; 
									};
		// Input Function
		static PicBufferLogo* unserialize( UINT8* pwmBuffer ) { 
															PicBufferLogo* pBuffer = new PicBufferLogo; 
															pBuffer->pwmLogoFrequency = pwmBuffer[1] | (pwmBuffer[2] << 8);
															pBuffer->pwmLogoDutyCycle = pwmBuffer[3]; 
															return pBuffer; 
															};
	private:
		UINT8 pwmBuffer[4];		
};

// PWM Fan command -- output only, so unserialize returns NULL
/*!
* \brief
* PWM Fan message interface object class
* 
* \remarks
* Supports both Input and Output.<br>
* Object initializes PWM Fan parameter in a range 0 to 100, so no further initialization is needed to use this object.
* 
*/
class PicBufferFan : public PicBuffer {
	public:
		UINT8 pwmFan;
		PicBufferFan() { cmd = LR_PWM_FAN; length = 2;  pwmFan = 100;};
		virtual ~PicBufferFan() {};
		// Output Function
		virtual UINT8* serialize() { buffer[0] = cmd; buffer[1] = pwmFan; return buffer; };
		// Input Function
		static PicBufferFan* unserialize( UINT8* buffer ) { PicBufferFan* pBuffer = new PicBufferFan; pBuffer->pwmFan = buffer[1]; return pBuffer; };
	private:
		UINT8 buffer[2];		
};

// Program command -- output only, so unserialize returns NULL
/*!
* \brief
* Outgoing program message interface object class, to send a program message to microcontroller
* 
* \remarks
* Output only, so unserialize() is not required.<br>
* On input, the program message is a single byte, so unserialize() is not required.
*/
class PicBufferProgram : public PicBuffer {
	public:
		PicBufferProgram() { cmd = LR_BOTH_PROGRAM; length = 1; };
		virtual ~PicBufferProgram() {};
		virtual UINT8* serialize() { cmdBuffer = LR_BOTH_PROGRAM; return &cmdBuffer; };
	private:
		UINT8 cmdBuffer;
};

// GPIO command -- supports both directions serialize and unserialize
/*!
* \brief
* GPIO message interface object class
* 
* \remarks
* Supports both directions serialize and unserialize.<br>
* Object initializes GPIO parameter in a number 37 to 38, so no further initialization is needed to use this object.
* Valid GPIO Values: 0, 1, or 2
* If GPIO Value equal 0 or 1 then GPIO will be an setup as output and output will be set to 0 or 1.
* If GPIO Value equals 2 then GPIO will be setup as input.
* 
*/
class PicBufferGPIO : public PicBuffer {
	public:
		UINT8 gpioNumber;
		UINT8 gpioValue;
		PicBufferGPIO() { cmd = LR_PIC_GPIO; length = 3;};
		virtual ~PicBufferGPIO() {};
		// Output Function
		virtual UINT8* serialize() { buffer[0] = cmd; buffer[1] = gpioNumber; buffer[2] = gpioValue; return buffer; };
		// Input Function
		static PicBufferGPIO* unserialize( UINT8* buffer ) { PicBufferGPIO* pBuffer = new PicBufferGPIO; pBuffer->gpioNumber = buffer[1]; pBuffer->gpioValue = buffer[2]; return pBuffer; };
	private:
		UINT8 buffer[3];		
};

// PWM Factory Mode command -- output only, so unserialize returns NULL
/*!
* \brief
* Factory Mode message interface object class
* 
* \remarks
* Supports both Input and Output.<br>
* Object initializes Factory Mode parameter is a 0xFF - Factory Mode or 0xFE - Normal Mode, so no further initialization is needed to use this object.
* 
*/
class PicBufferFacMode : public PicBuffer {
	public:
		UINT16 FacMode;
		PicBufferFacMode() { cmd = LR_PIC_FACMODE; length = 3;};
		virtual ~PicBufferFacMode() {};
		virtual UINT8* serialize() { buffer[0] = cmd; buffer[1] = FacMode & 0xFF; buffer[2] = (FacMode & 0xFF00) >> 8; printf("Writing %x for Facmode\n", FacMode);return buffer;};
	private:
		UINT8 buffer[3];	
};

// PowerUpKeys code -- input only, so serialize returns NULL
/*!
* \brief
* PowerUpKeys message interface object class, to receive PowerUp key mask from microcontroller
* 
* \remarks
* Input only, so serialize() just returns null.<br>
* Object uses unserialize() to recover key mask from incoming buffer.
* 
*/
class PicBufferPowerUpKeys : public PicBuffer {
        public:
                UINT16 keys;
                PicBufferPowerUpKeys() { cmd = LR_PIC_POWERUPKEYS; length = 3; };
                virtual ~PicBufferPowerUpKeys() {};
                virtual UINT8* serialize() { return NULL; };
                static PicBufferPowerUpKeys* unserialize( UINT8* buffer ) {
                          PicBufferPowerUpKeys* pBuffer = new PicBufferPowerUpKeys;
                          pBuffer->keys = buffer[1];
                          pBuffer->keys |= (buffer[2] << 8);
                          return pBuffer; 
                       };
};

// LTDC code -- Supports both Input and Output. 
/*!
* \brief
* Light to digital converter message interface object class. Sets polling rate for LTDC.
* Receives Visable plus IR and IR conversions.
* 
* \remarks
* Supports both Input and Output.<br>
* Object uses unserialize() to recover light conversions from buffer.
* 
*/
class PicBufferLTDC : public PicBuffer {
        public:
                UINT16 Vis_IR;
		UINT16 IR;
 		UINT8  PollingRate; //Half second polling rate.
                PicBufferLTDC() { cmd = LR_PIC_LTDC; length = 2; };
                virtual ~PicBufferLTDC() {};
                virtual UINT8* serialize() { buffer[0] = cmd; buffer[1] = PollingRate;
                                             return buffer; };
                static PicBufferLTDC* unserialize( UINT8* inBuffer ) {
                          PicBufferLTDC* pBuffer = new PicBufferLTDC;
                          pBuffer->Vis_IR = *((UINT16 *)&inBuffer[1]);
                          pBuffer->IR     = *((UINT16 *)&inBuffer[3]);
                          return pBuffer; 
                       };
	private:
		UINT8 buffer[2];
};

// Set Watchdog Timer code -- Supports both Input and Output. 
/*!
* \brief
* Set Watchdog Timer message interface object class. 
* Sets Primary and Secondary watchdog timers and actions.
* Receives status.
* 
* \remarks
* Supports both Input and Output.<br>
* Object uses unserialize() to recover light conversions from buffer.
* 
*/
class PicBufferWdtSet : public PicBuffer {
        public:
		UINT8  PrimaryAction;
		UINT16 PrimaryActionTimeout;
		UINT16 PrimaryActionRecovery;
 		UINT8  PrimaryActionCount; 
		UINT8  SecondaryAction;
		UINT16 SecondaryActionTimeout;
		UINT16 SecondaryActionRecovery;
 		UINT8  SecondaryActionCount; 
		UINT8  ReturnStatus;

                PicBufferWdtSet() { cmd = LR_PIC_WDT_SET; length = 13; };
                virtual ~PicBufferWdtSet() {};
                virtual UINT8* serialize() { buffer[0] = cmd; 
											buffer[1] = PrimaryAction;
											buffer[2] = PrimaryActionTimeout & 0xff;
											buffer[3] = PrimaryActionTimeout >> 8;
											buffer[4] = PrimaryActionRecovery & 0xff;
											buffer[5] = PrimaryActionRecovery >> 8;
											buffer[6] = PrimaryActionCount;
											buffer[7] = SecondaryAction;
											buffer[8] = SecondaryActionTimeout & 0xff;
											buffer[9] = SecondaryActionTimeout >> 8;
											buffer[10] = SecondaryActionRecovery & 0xff;
											buffer[11] = SecondaryActionRecovery >> 8;
											buffer[12] = SecondaryActionCount;
											return buffer; };
                static PicBufferWdtSet* unserialize( UINT8* inBuffer ) {
                          PicBufferWdtSet* pBuffer = new PicBufferWdtSet;
                          pBuffer->ReturnStatus = inBuffer[1];
                          return pBuffer; 
                       };
	private:
		UINT8 buffer[13];
};

// Watchdog Timer Heartbeat code -- Input only, serialize returns NULL. 
/*!
* \brief
* Watchdog Timer Heartbeat message interface object class. 
* Receives status code.
* 
* \remarks
* Supports both Input and Output.<br>
* Object uses unserialize() to recover light conversions from buffer.
* 
*/
class PicBufferWdtHeartbeat : public PicBuffer {
        public:
 		UINT8 ReturnStatus; 
                PicBufferWdtHeartbeat() { cmd = LR_PIC_WDT_HEARTBEAT; length = 1; };
                virtual ~PicBufferWdtHeartbeat() {};
                virtual UINT8* serialize() { return NULL; };
                static PicBufferWdtHeartbeat* unserialize( UINT8* inBuffer ) {
                          PicBufferWdtHeartbeat* pBuffer = new PicBufferWdtHeartbeat;
                          pBuffer->ReturnStatus = inBuffer[1];
                          return pBuffer; 
                       };
	private:
		UINT8 buffer[2];
};



// IR Blaster code -- Output only, so unserialize returns NULL
/*!
* \brief
* IR Blaster message interface object class, to send IR blaster code to microcontroller
* 
* \remarks
* 
*/

#define MAX_BLASTER_BUFFER 70
class PicBufferIRBlaster : public PicBuffer {
	public:
		UINT8  freq;
		UINT8  duty;
                UINT8  cnt;
                UINT16 pulses[MAX_BLASTER_BUFFER]; //Non-packed samples
                int i,j;

		PicBufferIRBlaster() { cmd = LR_HOST_IR; length = 4 /* no pulses yet */; };
		virtual ~PicBufferIRBlaster() {};
		virtual UINT8* serialize() { 
                    buffer[0]=cmd;
                    buffer[1]=freq;
                    buffer[2]=duty;
                    // counting in 2 pulse increments
                    // that will be compresseed into three buffer bytes
                    for(i=0,j=4; i < cnt; i+=2)
                    {
                        //drops lower nibble of first sample
                        buffer[j++] = (pulses[i]>>4 & 0xff); 
                        //lower nibble of first and top signif nibble of second sample
			buffer[j++] = ((pulses[i]&0xf)<<4) | ((pulses[i+1]>>8) & 0x0f); 
                        //The rest of the second sample
                        buffer[j++] = pulses[i+1]&0xff;
                    }
                    length = j;

                    // New cnt... (number of packed bytes)
                    buffer[3]=j-4;

                    return buffer;
                };

		static PicBufferIRBlaster* unserialize( UINT8* buffer ) 
		{ 
			return NULL; 
		};

                // This is where the pulses get compressed
                UINT8 buffer[4 + MAX_BLASTER_BUFFER + (MAX_BLASTER_BUFFER*2)/3 ];
};

// CT code -- input only, so serialize returns NULL
/*!
* \brief
* CT message interface object class, to receive CT code from microcontroller
* 
* \remarks
* Input only, so serialize() just returns null.<br>
* Object uses unserialize() to parse four bytes ctValues from an incoming buffer.
* 
*/
class PicBufferCT : public PicBuffer {
	public:
		UINT8 ctValue[4];			// CT Value, four bytes
		PicBufferCT() { cmd = LR_PIC_CT; length = 5; };
		virtual ~PicBufferCT() {};
		virtual UINT8* serialize() { return NULL; };
		static PicBufferCT* unserialize( UINT8* buffer ) 
		{ 
			PicBufferCT* pBuffer = new PicBufferCT; 
			pBuffer->ctValue[0] = buffer[1]; 
			pBuffer->ctValue[1] = buffer[2]; 
			pBuffer->ctValue[2] = buffer[3]; 
			pBuffer->ctValue[3] = buffer[4]; 
			return pBuffer; 
		};
};

// ACK and NAK are only used in the parser; not abstracted here
typedef struct _picBufferAck {
	UINT8 cmd;				// expect 0x06
} LR_BOTHACKBUFFER;

typedef struct _picBufferNak {
	UINT8 cmd;				// expect 0x07
} LR_BOTHNAKBUFFER;

// key codes for IR and CEC
struct _keyCodes {
	char* irCode;
	short ceaCode;
	unsigned char irNumber;
	unsigned char irDevice;
	unsigned char cecCode;
};

#endif
