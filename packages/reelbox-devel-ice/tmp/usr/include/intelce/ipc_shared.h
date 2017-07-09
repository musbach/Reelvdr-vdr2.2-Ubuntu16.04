/* 

  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2005-2008 Intel Corporation. All rights reserved.

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

  Copyright(c) 2005-2008 Intel Corporation. All rights reserved.

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
#ifndef IPC_SHARED_H
#define IPC_SHARED_H

/** Four Byte "checked marker" of lumps of binary data communicated through
* the circular buffer between sender and receiver.
*/
struct _IPC_LumpHeader
{
    unsigned int        ipc_lh_size_sync;   /* */
    #define ipc_lh_get_size(lh)         ( (lh)->ipc_lh_size_sync & 0xffff)
    #define ipc_lh_get_sync(lh)         (((lh)->ipc_lh_size_sync>>16) & 0xffff)
    #define ipc_lh_set_size(lh,siz)     (lh)->ipc_lh_size_sync = ((lh)->ipc_lh_size_sync & 0xffff0000) | (siz);
    #define ipc_lh_set_sync(lh,sync)    (lh)->ipc_lh_size_sync = ((lh)->ipc_lh_size_sync & 0x0000ffff) | ((sync)<<16)

    #ifdef CONFIG_IPC_USES_LUMPS
    #ifdef CONFIG_IPC_FW_MUST_USE_DMA_FOR_SHARED_STRUCTS
    unsigned int        ipc_lh_dma_pad;     /* struct size must be 8 bytes */
    #endif
    #endif
};

/** LumpHeader plus an additional four-byte mux/demux/async reply
* support tags which can be used for more advanced control.
*/
struct _IPC_MessageHeader
{
    struct _IPC_LumpHeader    lump;

    /* offset 0x4 (source_q:8 dest_q:8 unique_id:16) */
    unsigned int              ipc_mh_src_dst_id;
    #define ipc_mh_get_src_qnum(mh)     ( (mh)->ipc_mh_src_dst_id & 0xff)
    #define ipc_mh_get_dst_qnum(mh)     (((mh)->ipc_mh_src_dst_id >>8) & 0xff)
    #define ipc_mh_get_unique_id(mh)    (((mh)->ipc_mh_src_dst_id >>16) & 0xffff)
    #define ipc_mh_set_src_qnum(mh,q)     (mh)->ipc_mh_src_dst_id = (((mh)->ipc_mh_src_dst_id & 0xffffff00) | (q))
    #define ipc_mh_set_dst_qnum(mh,q)     (mh)->ipc_mh_src_dst_id = (((mh)->ipc_mh_src_dst_id & 0xffff00ff) | ((q)<<8))
    #define ipc_mh_set_unique_id(mh,id)   (mh)->ipc_mh_src_dst_id = (((mh)->ipc_mh_src_dst_id & 0x0000ffff) | ((id)<<16))

    /** MSBit of unique ID indicates reply */
    #define IPC_MESSAGE_UNIQUE_ID_IS_REPLY       (1<<15)
    #define IPC_MESSAGE_UNIQUE_ID_MASK           (IPC_MESSAGE_UNIQUE_ID_IS_REPLY-1)
    #define IPC_MESSAGE_HEADER_GET_ID( uid )     ((uid) & IPC_MESSAGE_UNIQUE_ID_MASK)

    /* offset 0x8 */
};

/** HOST/IPC Queue Header Shared Memory structure */
struct _IPC_QueueHeader
{
    volatile signed int    ipc_qh_wpos;    /* must be signed for mathematical X_avail() optimizations  */
    volatile signed int    ipc_qh_rpos;    /* must be signed for mathematical X_avail() optimizations  */
    signed int             ipc_qh_size;    /* must be signed for mathematical X_avail() optimizations  */

    /** Bytes available to write from indicated writer position */
    #define ipc_qh_write_avail_from_wpos(qh,wpos)  (((qh)->ipc_qh_rpos + (qh)->ipc_qh_size) - (wpos))

    /** Bytes available to read from indicated writer position */
    #define ipc_qh_read_avail_from_rpos(qh,rpos)   ( (qh)->ipc_qh_wpos - (rpos) )

    /** Bytes available for writing */
    #define ipc_qh_write_avail(qh)  ipc_qh_write_avail_from_wpos((qh),(qh)->ipc_qh_wpos)

    /** Bytes available for reading */
    #define ipc_qh_read_avail(qh)   ipc_qh_read_avail_from_rpos( (qh),(qh)->ipc_qh_rpos)


    /**
     *  High and low watermarks.
     *
     *  IPC TRANSMITTER Action
     *  if ( ipc_qh_write_avail(qh) < ipc_qh_get_hi_wmark(qh) )
     *      transmitter about to get blocked, interrupt receiver
     *
     *  IPC RECEIVER Action
     *  if ( ipc_qh_read_avail(qh) < ipc_qh_get_lo_wmark(qh) )
     *      receiver about to get blocked, interrupt transmitter
     *
     */
    unsigned int    ipc_qh_hi_lo_wmark;   /* */
    #define ipc_qh_get_lo_wmark(qh)     ( (qh)->ipc_qh_hi_lo_wmark & 0xffff)
    #define ipc_qh_get_hi_wmark(qh)     (((qh)->ipc_qh_hi_lo_wmark >>16) & 0xffff)
    #define ipc_qh_set_lo_wmark(qh,val)   (qh)->ipc_qh_hi_lo_wmark = ((qh)->ipc_qh_hi_lo_wmark & 0xffff0000) | (val);
    #define ipc_qh_set_hi_wmark(qh,val)   (qh)->ipc_qh_hi_lo_wmark = ((qh)->ipc_qh_hi_lo_wmark & 0x0000ffff) | ((val)<<16)

    /** is the transmitter position above the high watermark? (queue almost full) */
    #define ipc_qh_tx_above_wmark(qh)     (ipc_qh_write_avail(qh) <= ipc_qh_get_hi_wmark(qh))

    /** is the receiver position below the low watermark? (queue almost empty) */
    #define ipc_qh_rx_below_wmark(qh)     (ipc_qh_read_avail(qh) <= ipc_qh_get_lo_wmark(qh))

    /* struct size is 16 bytes */
};

/** Synchronous Message for communication to/from host */
struct _IPC_SynchronousMessage
{
    int             command_id;
        #define IPC_SYNCMESSAGE_COMMAND_MARKER           (0x73<<24)
        #define IPC_SYNCMESSAGE_COMMAND_INITIALIZE       (0x00 | IPC_SYNCMESSAGE_COMMAND_MARKER)
        #define IPC_SYNCMESSAGE_COMMAND_OPEN_HOST_QUEUE  (0x01 | IPC_SYNCMESSAGE_COMMAND_MARKER)
        #define IPC_SYNCMESSAGE_COMMAND_OPEN_RISC_QUEUE  (0x02 | IPC_SYNCMESSAGE_COMMAND_MARKER)
        #define IPC_SYNCMESSAGE_COMMAND_CLOSE_HOST_QUEUE (0x03 | IPC_SYNCMESSAGE_COMMAND_MARKER)
        #define IPC_SYNCMESSAGE_COMMAND_CLOSE_RISC_QUEUE (0x04 | IPC_SYNCMESSAGE_COMMAND_MARKER)
        #define IPC_SYNCMESSAGE_COMMAND_FLUSH_QUEUE      (0x05 | IPC_SYNCMESSAGE_COMMAND_MARKER)
        #define IPC_SYNCMESSAGE_COMMAND_SVEN_PROXY       (0x06 | IPC_SYNCMESSAGE_COMMAND_MARKER)

    union
    {
        union {
            struct {
                unsigned int    num_host_queues;
                unsigned int    host_queue_size;
                unsigned int    num_fw_queues;
                unsigned int    fw_queue_size;
                unsigned int    msg_struct_offsets[5];
            } send;     /* host sends */

            struct {
                unsigned int    error;
                unsigned int    num_host_queues;
                unsigned int    host_queue_size;
                unsigned int    num_fw_queues;
                unsigned int    fw_queue_size;
                unsigned int    msg_struct_offsets[5];
            } reply;    /* FW Response */
        }initialize;

        union {
            struct {
                unsigned int    ignored;
                unsigned int    queue_number;
                unsigned int    qheader_phys_addr;
                unsigned int    circbuf_phys_addr;
                unsigned int    circbuf_size;
            } send;

            struct {
                unsigned int    error;
                unsigned int    queue_number;
                unsigned int    qheader_fw_addr;
                unsigned int    circbuf_fw_addr;
                unsigned int    size_msg_header;
            } reply;
        }open_queue;

        union {

            struct {
                unsigned int    queue_number;
            } send;

            struct {
                unsigned int    error;
            } reply;
        }close_queue;

        union {

            struct {
                unsigned int    fw_queue_number;
                unsigned int    reply_to_flushed_messages;
            } send;

            struct {
                unsigned int    error;
            } reply;
        }flush_queue;

        union {

            struct {
                unsigned int    fw_queue_number;
                unsigned int    reply_to_flushed_messages;
            } send;

            struct {
                unsigned int    error;
            } reply;
        }sven_proxy;
    };
};

#endif /* IPC_SHARED_H */
