/* 

  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2005-2011 Intel Corporation. All rights reserved.

  This program is free software; you can redistribute it and/or modify 
  it under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but 
  WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
  General Public License for more details.

  You should have received a copy of the GNU General Public License 
  along with this program; if not, write to the Free Software 
  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
  The full GNU General Public License is included in this distribution 
  in the file called LICENSE.GPL.

  Contact Information:
    Intel Corporation
    2200 Mission College Blvd.
    Santa Clara, CA  97052

  BSD LICENSE 

  Copyright(c) 2005-2011 Intel Corporation. All rights reserved.

  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions 
  are met:

    * Redistributions of source code must retain the above copyright 
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright 
      notice, this list of conditions and the following disclaimer in 
      the documentation and/or other materials provided with the 
      distribution.
    * Neither the name of Intel Corporation nor the names of its 
      contributors may be used to endorse or promote products derived 
      from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#ifndef HOST_IPC_H
#define HOST_IPC_H 1

#ifndef IPCLIB_H
#include <ipclib.h>
#endif

#include <osal_sema.h>
#include <osal_list.h>
#include <sven_devh.h>

/** Generic Message queue */
struct Host_IPC_MsgQueue
{
    struct IPC_MsgQueue     mq;         /* local MSGQueue handle */
    unsigned int            circbuf_pa; /* Physical addr for circ buffer */
    os_sema_t               sema;       /* semaphore */
};

/** Generic structure for opening send and receive queues */
struct Host_IPC_MsgPortInfo
{
    unsigned int snd_id;               /* Send queue id usually stream id */
    unsigned int snd_circ_pa;          /* Physical addr for Send queue    */
    unsigned int snd_circ_size;        /* Size for Send queue             */
    unsigned int recv_id;              /* recv queue id usually stream id */
    unsigned int recv_circ_pa;         /* Physical addr recv queue        */
    unsigned int recv_circ_size;       /* Size for recv queue             */
};

/** Generic Host-to-Firmware Message Send Queue */
struct Host_IPC_SendQueue
{
    struct Host_IPC_MsgQueue    hmq;    /* Send Message queue           */
    int                         active; /* Queue is enabled or disabled */
};

/** Generic Firmware-to-Host Message Send Queue */
struct Host_IPC_ReceiveQueue
{
    struct Host_IPC_MsgQueue    hmq;          /* Recv Message Queue     */
    int                         active;       /* Queue is enabled or disabled */
/* inbound messages are read into this buffer one at a time */
    unsigned int                one_msg_size; /* Message size of temporary buffer */
    struct _IPC_MessageHeader   one_msg_hdr;  /* Message header of temporary buffer */
    unsigned char               one_msg[CONFIG_IPC_MESSAGE_MAX_SIZE]; /* space for temporary buffer */
};

/** Context for Host IPC */
struct HostIPC_Handler
{
    os_devhandle_t                 *devh;                        /** Device Handle for IPC Communication */
    volatile char                  *sync_msg_buf;                /** Synchronous Message Buffer, shared between host and firmware */
    volatile char                  *int_status;                  /** Int status reg Mainatained by FW and Read by Host */
    int                             fw_doorbell_reg_offset;      /** register offset of "To Firmware" Doorbell */
    int                             host_doorbell_reg_offset;    /** register offset of "To Host" Doorbell */
    struct _IPC_QueueHeader         dummy_rx_qh;                 /** Dummy receive queheader for connect */
    struct _IPC_QueueHeader         dummy_tx_qh;                 /** Dummy transmit queheader for connect */
    struct Host_IPC_ReceiveQueue    rcv_q[CONFIG_IPC_HOST_MAX_RX_QUEUES];     /** FIRMWARE_TO_HOST Message Queues (inbound) */
    struct Host_IPC_SendQueue       snd_q[CONFIG_IPC_FW_MAX_RX_QUEUES];       /** HOST_TO_FIRMWARE Message Queues (outbound) */
    os_sema_t                       sync_msg_sema;               /* semaphore */
};

/*@}*/

/** @weakgroup Host IPC Functions */
/** @ingroup host_ipc */
/*@{*/

/**
This function Initializes the host ipc handle.
@param[in] hipc          : Handle to initialize shared queues.
@retval 0                : if function succeeds.
@retval 1                : if function fails.
*/
int HostIPC_Initialize(struct HostIPC_Handler  *hipc );

/**
This function Initializes the host ipc handle.
@param[in] hipc          : Handle to deinitialize shared queues.
@retval 0                : if function succeeds.
@retval 1                : if function fails.
*/
int HostIPC_Deinitialize(struct HostIPC_Handler  *hipc);
/**
This function creates a output queue from FW.
@param[in] hipc          : Ipc handle.
@param[in] receive_q_num : Id of queue to be opened, usually stream id.
@retval 0                : if function succeeds.
@retval 1                : if function fails.
*/
int HostIPC_ConnectReceivePipeToFirmware(struct HostIPC_Handler  *hipc, unsigned int receive_q_num );

/**
This function creates a input queue to FW.
@param[in] hipc          : Ipc handle.
@param[in] snd_q_num     : Id of queue to be opened, usually stream id.
@retval 0                : if function succeeds.
@retval 1                : if function fails.
*/
int HostIPC_ConnectSendPipeToFirmware(struct HostIPC_Handler *hipc, unsigned int snd_q_num );

/**
This is a helper function to create a send and receive queue for Fw using
HostIPC_ConnectSendPipeToFirmware and HostIPC_ConnectReceivePipeToFirmware.
@param[in] hipc          : Ipc handle.
@param[in] cxt           : Info about snd and recv qnum and physical addr of
                           circular buffers.
@retval 0                : if function succeeds.
@retval 1                : if function fails.
*/
int HostIPC_InitMessagePort(struct HostIPC_Handler  *hipc, struct Host_IPC_MsgPortInfo *cxt );

/**
This is a helper function to close exisitng send and receive queue for Fw.
@param[in] hipc          : Ipc handle.
@param[in] cxt           : Info about snd and recv qnum. rest of input data in
                           cxt is ignored.
*/
void HostIPC_CloseMessagePort(struct HostIPC_Handler  *hipc, struct Host_IPC_MsgPortInfo *cxt );

/**
This function is for sending a synchronous message to Fw.
@param[in] hipc          : Ipc handle.
@param[in] message       : Actual message that needs to be sent.
@param[in] message_size  : Size of the message that is being sent.
*/
void HostIPC_StartSynchronousMessage(struct HostIPC_Handler *hipc, const void *message, int message_size );

/**
This function is for reading result of synchronous message.
@param[in] hipc          : Ipc handle.
@param[out]message       : Reply message from firmware.
@param[out]message_size  : Size of the reply message.
*/
void HostIPC_ReadSynchronousResponse(struct HostIPC_Handler  *hipc, void *message_buf, int message_buf_size );

/**
This function is for sending a asynchronous message to Fw.
@param[in] hipc          : Ipc handle.
@param[in] snd_queue_num : Que id or stream id on which this message needs to be sent.
@param[in] message       : Actual message that needs to be sent.
@param[in] message_size  : Size of the message that is being sent.
@retval -1               : if Invalid parameters are provided.
@retval 0                : if function succeeds.
@retval 1                : If Send queue is full.
*/
int HostIPC_SendMessage(struct HostIPC_Handler  *hipc, unsigned int snd_queue_num, const char *message, unsigned int message_size );

/**
This function is for receiving asynchronous messages from Fw.
@param[in] hipc          : Ipc handle.
@param[in] snd_queue_num : Que id or stream id to read the message from.
@param[out] message      : Message if present gets copied here.
@param[out] message_size : Size of the message that was copied.
@retval -1               : if Invalid parameters are provided.
@retval 0                : if function succeeds.
*/
int HostIPC_ReceiveMessage(struct HostIPC_Handler  *hipc, unsigned int rcv_queue_num, char *message, unsigned int *message_size );

int HostIPC_SpaceAvailForMessage(struct HostIPC_Handler *hipc, unsigned int stream_id, unsigned int message_size);

int HostIPC_GetWriteAvailable(
    struct HostIPC_Handler  *hipc,
    unsigned int             snd_queue_num,
    unsigned int             *amt_avail );
/*@}*/
#endif /* HOST_IPC_H */
