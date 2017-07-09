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
 *     LR_PICInterface.h
 * 
 * Abstract:
 *     Class to handle serial communication with PIC for IR and CEC commands.
 ***************************************************************************/

/*! \mainpage PIC Interface API

The PIC Interface API is used to enable communication with the PIC using IR and CEC messages.
It uses threads and locks to prevent other processes from using the serial bus while it is in use. 
Once an instance of the LR_PICInterface class has been created and initialized, the HostReaderProc() 
function is called whenever a new message is recieved by the PIC. Once it is done the parsed data 
is stored in a PicBuffer class and passed back to a callback function where it can be used.
*/

/*!
* \file LR_PICInterface.h
* \brief
* APIs and macros related to microcontroller interface library
* 
* \remarks
* Microcontroller handles CEC and IR interfaces for the system.  APIs here allow caller
* to send and receive messages according to the microcontroller interface document.
* 
*/


#ifndef _PIC_INTERFACE_H
#define _PIC_INTERFACE_H

#include "osal.h"
#include "LR_PICInterfaceProtocol.h"

using namespace std;
#include <deque>

#define MAX_PIC_COMM_LENGTH 	255
#define MAX_PIC_BUFFER_LENGTH   128 
#define AMOUNT_TO_READ			512


#define ACK_WAIT_TIMEOUT		2000	// timeout waiting for ACK (ms)
				 
#define CEC_ACK_ASSERT			1
#define CEC_ACK_UNASSERT		0
#define CEC_ACK_UNDEFINED		(-1)

typedef enum ePICSTATUS
{
	PIC_SUCCESS,
	PIC_ERROR_RETURNED,
} PICSTATUS;

/*!
* \brief
* Owner callback called when messages arrive from the microcontroller.
*
* \param cmd
* The message cmd, defined in the microcontroller protocol document.
* 
* \param length
* Total length of the message.
*
* \param data
* The message data.
*
* \param clientData
* Pointer to data given to the interface when the user created it.
* 
* \returns
* Returns an integer value that is currently ignored.<br>
* 
* \remarks
* This routine allows the interface owner to respond to PIC messages.<br>
* The owner may call Write() within the callback to generate chains of message to/from the microcontroller.
* 
*/
typedef INT32 (*PICLIENTCB)( UINT8 cmd, UINT8 length, void* data, void* clientData );

/*! 
* \class LR_PICInterface
* \brief Framework class for the PIC Interface
*
* This is the class that hold all the functions for recieving, parsing, and sending messages.
*/
class LR_PICInterface
{
	public:
		
/*!
* \brief
* Interface library constructor.
* 
* \param callBack
* Interface owners callback.
*
* \param clientData
* Pointer to data to be given to the owner as part of the callback. 
* 
* \returns
* Interface library in dormant form; the library Init() routine must be called in order to use it.<br>
* 
*/
		LR_PICInterface( PICLIENTCB callBack, void* clientData );
		virtual ~LR_PICInterface();
		
/*!
* \brief
* Initialize the library for use, connect it to the microcontroller.
* 
* \param commDevice
* String giving the name of the comm device on which to connect to the microcontroller; generally /dev/ttyS1.
*
* \returns
* PIC_SUCCESS if initialization is successful, otherwise PIC_ERROR_RETURNED_RETURNED.<br>
* 
* \remarks
* This routine opens the comm port to the microcontroller and initializes locks and threads used internally by the library.<br>
* This routine is blocking and thread safe.
* 
*/
		PICSTATUS Init( const INT8* commDevice );

/*!
* \brief
* Set the IR Repeat Mode, connect it to the microcontroller.
* 
* \param irRepeatMode
* Integer for Buffer mode or Start/Stop mode.
*
* \returns
* PIC_SUCCESS if initialization is successful, otherwise PIC_ERROR_RETURNED_RETURNED.<br>
* 
* \remarks
* This routine sets the IR Repeat Mode to Buffer mode or Start/Stop mode.
* 
*/
		PICSTATUS setIrRepeatMode(UINT8 irRepeatMode);

/*!
* \brief
* Set the GPIO Value for a particular GPIO number, connect it to the microcontroller.
* 
* \param value
* UINT16 value for a specific command.
* Valid GPIO Values: 0, 1, or 2
* If GPIO Value equal 0 or 1 then GPIO will be an setup as output and output will be set to 0 or 1.
* If GPIO Value equals 2 then GPIO will be setup as input.
*
* \returns
* PIC_SUCCESS if initialization is successful, otherwise PIC_ERROR_RETURNED_RETURNED.<br>
* 
* \remarks
* This routine sets the UINT16 Value for a specific command.
* 
*/
		PICSTATUS setGPIOValue(UINT8 number, UINT8 value);

/*!
* \brief
* Set the PWM for a particular PIC UART Command, connect it to the microcontroller.
* 
* \param command
* UINT8 command for a specific PIC UART command.
*
* \param frequency
* UINT16 frequency for a specific PIC UART command.
*
* \param dutyCycle
* UINT8 dutyCycle for a specific PIC UART command The range is 0% (off) to 100% (full on).
*
* \returns
* PIC_SUCCESS if initialization is successful, otherwise PIC_ERROR_RETURNED_RETURNED.<br>
* 
* \remarks
* This routine sets the UINT16 Value for a specific command.
* 
*/
		PICSTATUS setPWM(UINT8 command, UINT16 frequency, UINT8 dutyCycle);

/*!
* \brief
* Set the UINT8 Value for a particular command, connect it to the microcontroller.
* 
* \param value
* UINT8 value for a specific command.
*
* \returns
* PIC_SUCCESS if initialization is successful, otherwise PIC_ERROR_RETURNED_RETURNED.<br>
* 
* \remarks
* This routine sets the UINT8 Value for a specific command.
* 
*/
		PICSTATUS setUINT8Value(UINT8 command, UINT8 value);

/*!
* \brief
* Set the UINT16 Value for a particular command, connect it to the microcontroller.
* 
* \param value
* UINT16 value for a specific command.
*
* \returns
* PIC_SUCCESS if initialization is successful, otherwise PIC_ERROR_RETURNED_RETURNED.<br>
* 
* \remarks
* This routine sets the UINT16 Value for a specific command.
* 
*/
		PICSTATUS setUINT16Value(UINT8 command, UINT16 value);

/*!
* \brief
* Set the UINT32 Value for a particular command, connect it to the microcontroller.
* 
* \param value
* UINT32 value for a specific command.
*
* \returns
* PIC_SUCCESS if initialization is successful, otherwise PIC_ERROR_RETURNED_RETURNED.<br>
* 
* \remarks
* This routine sets the UINT32 Value for a specific command.
* 
*/
		PICSTATUS setUINT32Value(UINT8 command, UINT32 value);

/*!
* \brief
* Writes a message to the microcontroller; optionally waits for a return ACK value from the CEC bus.
* 
* \param length
* Length of the message buffer; must be <= max buffer length defined in protocol document (16).
*
* \param buffer
* The message buffer; must not be null.
*
* \param cecAck
* An optional integer that receives the ACK value returned by the CEC bus; may be NULL if no ACK is required.
*
* \returns
* PIC_SUCCESS if write is successful, otherwise PIC_ERROR_RETURNED_RETURNED.<br>
* 
* \remarks
* This routine is blocking and thread safe.  Write() may be called within the interface callback routine.
* 
*/
		PICSTATUS Write( UINT8 length, UINT8* buffer, INT32* cecAck = NULL );
		
/*!
* \brief
* Writes a message to the microcontroller using a PicBuffer interface object; optionally waits for a return ACK value from the CEC bus.
* 
* \param pCommand
* Pointer to a PicBuffer interface object; must not be null.
*
* \param cecAck
* An optional integer that receives the ACK value returned by the CEC bus; may be NULL if no ACK is required.
*
* \returns
* PIC_SUCCESS if write is successful, otherwise PIC_ERROR_RETURNED_RETURNED.<br>
* 
* \remarks
* This routine is blocking and thread safe.  Write() may be called within the interface callback routine.
* 
*/
		PICSTATUS Write( PicBuffer* pCommand, INT32* cecAck = NULL );
		PICSTATUS unRegisterWithPic();
	
	private:
		
		// internal messsage queue to send buffers received from microcontroller to owners callback
		struct _buffer {
			UINT8* buffer;
			UINT8 length;
		};
		
		typedef deque< struct _buffer* > MSGQUEUE;		 
		typedef deque< struct _buffer* >::iterator MSGQUEUE_ITERATOR;
		
		enum LR_IncomingParseStates { PSTART, PSYNC, PCHARS1, PCHARS2, PLEN1, PLEN2 };
		
		PICSTATUS initComm();
		PICSTATUS registerWithPic();
		
		PICSTATUS sendNAK();
		PICSTATUS sendAck();
		PICSTATUS sendCECAck();
		PICSTATUS sendCommand( INT32 dwToWrite, UINT8 * lpBuf );
		PICSTATUS receiveIncoming();
		PICSTATUS encodeOutputBuffer( UINT8* inBuffer, INT32 inLength, UINT8* outputBuffer, INT32* outputLength );
		PICSTATUS constructOutputBuffer( INT32 command, INT32 cmdLength, UINT8* cmdString, INT32 *commandBufferLength, UINT8* cmdBuffer );
		PICSTATUS parseIncoming( UINT8 length, UINT8* incomingBuffer, UINT8* outgoingLength, UINT8* outgoingBuffer );
		PICSTATUS validateBuffer( UINT32 length, UINT8* buffer );
		
		INT32 lengthIncoming();
		PICSTATUS dumpIncoming( INT32 length );
		PICSTATUS dumpIncoming();
		PICSTATUS removeIncoming( INT32 length );
		PICSTATUS removeIncoming( INT32 length, UINT8* data );
		PICSTATUS addIncoming( INT32 length, UINT8* data );
		PICSTATUS peekIncoming( INT32 idx, UINT8* data );
		PICSTATUS predFullIncoming();
		PICSTATUS predEmptyIncoming();
		
		PICSTATUS queueCommand( UINT8 length, UINT8* buffer);
		
		static void* HostReaderProc( void* owner );
		PICSTATUS hostReaderProc();
		static void* HostCallbackProc( void* owner );
		PICSTATUS hostCallbackProc();
		PICSTATUS waitForWriteAck();

		INT32 incoming[AMOUNT_TO_READ];	// buffer with room for more than two or three commands from the PIC
		INT32 incomingFirst;			// place from which a valid command starts
		INT32 incomingNext;			// place to put the next incoming character
		
		LR_IncomingParseStates parseState;
		UINT8 parseBufferIndex;
		UINT8 parseMessageLength;
		UINT8 parseCharacterCount;
		UINT8 parseCurrentChar;
		UINT8 parseChecksum;
		UINT8 messageChecksum;
		UINT8 parseResult[MAX_PIC_COMM_LENGTH];
		UINT8 parseResultIndex;

		// lock, cond var, event for inputs
		os_lock_t 		lckInputEventEvent;
		os_event_t	 	cvInputEventEvent;
		bool			bInputEventEvent;
		os_thread_t 	readerThread;		// get commands from PIC read buffer, send keys to host
		os_thread_t	callbackThread;
		bool			m_stopThread;
		
		// lock, cond var, event for ack/nak
		os_lock_t 		lckAckNak;
		os_event_t	 	cvAckNak;
		bool			bAckEvent;
		bool			bNakEvent;
		
		// lock, cond var, event for cec ack
		os_lock_t 		lckCecAck;
		os_event_t	 	cvCecAck;
		INT32			iCecAckEvent;
		
		os_lock_t 		lckCmdQueue;
		os_event_t	 	cvCmdQueue;
		bool			bCmdQueueEvent;
		
		void* 			m_clientData;
		PICLIENTCB 		m_callBack;
		
		UINT8 			m_comm[MAX_PIC_COMM_LENGTH+1];
		INT32 			m_fd;               // ttyS1 device descriptor
		
		UINT32 			m_incomingNumber;
		
		MSGQUEUE*		m_callbackQueue;
public:
        os_lock_t       lckCntPicIRTimer1;
        int             cntPicIRTimer1;
};

extern "C" {
    extern int PicInitIR(PICLIENTCB callback, void *data);
    extern int PicIRTimer1 (int msec);
    extern int PicIRTimer1Get ();
    extern int PicPowerDownNotify ();
    extern LR_PICInterface * pLR_PICInterface_global;
}

#endif // _PIC_INTERFACE_H
