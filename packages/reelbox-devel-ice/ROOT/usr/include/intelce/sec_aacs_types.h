//-----------------------------------------------------------------------------
// Copyright (c) 2008-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------

#ifndef SEC_AACS_TYPES_H
#define SEC_AACS_TYPES_H


#define SEC_AACS_SKB_SELECT_MAX  5u  ///< Maximum permitted value of skb_select
#define SEC_AACS_MAX_DEV_KEY_INDEX 252  ///< Maximum index value of Device Key
#define SEC_AACS_MAX_SEQ_KEY_INDEX 255  ///< Maximum index value of Sequence Key

#define AACS_FLASH_MODULE_SIZE 9632
                ///< Encrypted AACS Confidential Data Flash Module size in bytes

/** AACS context key ids */
typedef enum
{
    SEC_AACS_BLURAY_SEG_KEY     = 0xC0,  /*!<  sec_aacs_process_packets: Segment Key  */
    SEC_AACS_Kmv_0              = 0xC1,  /*!<  Kmv for SKB 0              */
    SEC_AACS_Kmv_1,                      /*!<  Kmv for SKB 1              */
    SEC_AACS_Kmv_2,                      /*!<  Kmv for SKB 2              */
    SEC_AACS_Kmv_3,                      /*!<  Kmv for SKB 3              */
    SEC_AACS_Kmv_4,                      /*!<  Kmv for SKB 4              */
    SEC_AACS_Kmv_5,                      /*!<  Kmv for SKB 5              */
    SEC_AACS_Kvvu_0             = 0xC7,  /*!<  Kvvu for SKB 0             */
    SEC_AACS_Kvvu_1,                     /*!<  Kvvu for SKB 1             */
    SEC_AACS_Kvvu_2,                     /*!<  Kvvu for SKB 2             */
    SEC_AACS_Kvvu_3,                     /*!<  Kvvu for SKB 3             */
    SEC_AACS_Kvvu_4,                     /*!<  Kvvu for SKB 4             */
    SEC_AACS_Kvvu_5,                     /*!<  Kvvu for SKB 5             */
    SEC_AACS_Dv_0               = 0xCD,  /*!<  Dv for SKB 0               */
    SEC_AACS_Dv_1,                       /*!<  Dv for SKB 1               */
    SEC_AACS_Dv_2,                       /*!<  Dv for SKB 2               */
    SEC_AACS_Dv_3,                       /*!<  Dv for SKB 3               */
    SEC_AACS_Dv_4,                       /*!<  Dv for SKB 4               */
    SEC_AACS_Dv_5,                       /*!<  Dv for SKB 5               */
    SEC_AACS_K                  = 0xD3,  /*!<  Processing Key             */
    SEC_AACS_Km_Kmp             = 0xD4,  /*!< Media Key: Km / Kmp         */
    SEC_AACS_Kms_i              = 0xD5,  /*!< Media Sequence Key          */
    SEC_AACS_Kvu                = 0xD6,  /*!< Volume Unique Key           */
    SEC_AACS_Kt_Kcu             = 0xD7,  /*!< Title Key / CPS Unit Key    */
    SEC_AACS_BK                 = 0xD8,  /*!< Bus Key                     */
    SEC_AACS_DATAKey            = 0xD9,  /*!< Data Key  (bus encryption)  */
    SEC_AACS_Kpa                = 0xDA,  /*!< Protected Area Key          */
    SEC_AACS_USER_INPUT         = 0xFF   /*!< Host-provided value         */
} sec_aacs_context_key_t;

/** convenience macro to select SEC_AACS_Kmv_(i) for SKB (i)  */
#define SEC_AACS_Kmv(i)  ( ((unsigned)(i)==0u) ? SEC_AACS_Kmv_0 : \
                           ((unsigned)(i)==1u) ? SEC_AACS_Kmv_1 : \
                           ((unsigned)(i)==2u) ? SEC_AACS_Kmv_2 : \
                           ((unsigned)(i)==3u) ? SEC_AACS_Kmv_3 : \
                           ((unsigned)(i)==4u) ? SEC_AACS_Kmv_4 : \
                                                 SEC_AACS_Kmv_5 )

/** convenience macro to select SEC_AACS_Kvvu_(i) for SKB (i)  */
#define SEC_AACS_Kvvu(i)  ( ((unsigned)(i)==0u) ? SEC_AACS_Kvvu_0 : \
                            ((unsigned)(i)==1u) ? SEC_AACS_Kvvu_1 : \
                            ((unsigned)(i)==2u) ? SEC_AACS_Kvvu_2 : \
                            ((unsigned)(i)==3u) ? SEC_AACS_Kvvu_3 : \
                            ((unsigned)(i)==4u) ? SEC_AACS_Kvvu_4 : \
                                                  SEC_AACS_Kvvu_5 )

/** convenience macro to select SEC_AACS_Dv_(i) for SKB (i)  */
#define SEC_AACS_Dv(i)  ( ((unsigned)(i)==0u) ? SEC_AACS_Dv_0 : \
                          ((unsigned)(i)==1u) ? SEC_AACS_Dv_1 : \
                          ((unsigned)(i)==2u) ? SEC_AACS_Dv_2 : \
                          ((unsigned)(i)==3u) ? SEC_AACS_Dv_3 : \
                          ((unsigned)(i)==4u) ? SEC_AACS_Dv_4 : \
                                                SEC_AACS_Dv_5 )

/** sec_aacs_process_key_derivative(): AACS algorithm types  */
typedef enum
{
    SEC_AACS_ALG_AES_G=0x0,      ///< AES-G
    SEC_AACS_ALG_AES_128_D,      ///< AES-CBC decryption, 128 bits key size
    SEC_AACS_ALG_AES_128_CBC_D,  ///< AES-CBC decryption, 128 bits key size
    SEC_AACS_ALG_XOR,            ///< XOR
    SEC_AACS_ALG_AES_128_CBC_E,  ///< AES-CBC encryption, 128 bits key size
    SEC_AACS_ALG_AES_128_CBC_NONCE_E, ///< AES-CBC encryption with Nonce, 128 bits key size
    SEC_AACS_ALG_AES_128_CBC_NONCE_D, ///< AES-CBC decryption with Nonce, 128 bits key size
} sec_aacs_algorithm_t;

/** sec_aacs_process_packets(): AACS packet types */
typedef enum
{
    SEC_AACS_PACKET_TYPE_6144=0x0,
    SEC_AACS_PACKET_TYPE_2048,
} sec_aacs_packet_type_t;

/** CMAC operations */
typedef enum
{
    SEC_AACS_CMAC_GEN = 0x0,     ///< CMAC generation
    SEC_AACS_CMAC_VERIFY         ///< CMAC verification
} sec_aacs_cmac_t;


/** Apply Bus or Content Cryto operation */
typedef enum
{
    SEC_AACS_BUS = 0x1,          ///< Bus encryption or decryption
    SEC_AACS_CONTENT,            ///< Content encryption or descryption
    SEC_AACS_BUS_CONTENT         ///< Bus and Content encryption or decryption
}sec_aacs_bus_content_cipher_mode;


/** An AACS packet to be processed. */
typedef struct
{
    unsigned long           context_id;
                                ///< AACS context id
    sec_aacs_packet_type_t  packet_type;
                                ///< Packet type
    sec_cipher_mode_t       content_cipher_mode;
                                ///< Content encryption/decryption
    sec_aacs_bus_content_cipher_mode bus_content_mod;
                                ///< Bus or content crypto operation
    sec_aacs_context_key_t  title_key;
                                ///< SEC_AACS_Kt_Kcu or SEC_AACS_BLURAY_SEG_KEY
    int                     play_item_id;
                                ///< Play item id (only applicable for SEC_AACS_BLURAY_SEG_KEY)
    int                     play_list_id;
                                ///< Play list id (only applicable for SEC_AACS_BLURAY_SEG_KEY)
    void *                  src_packet_data;
                                ///< Source packet data
    void *                  dst_packet_data;
                                ///< Destination Packet data
} sec_aacs_packet_t;


/** memory types for packet buffers. */
typedef enum
{
    SEC_AACS_BUFFER_TYPE_VIRTUAL = 0,     ///< packet_data is pointer to virtual memory
    SEC_AACS_BUFFER_TYPE_PHYS_CONTIGUOUS, ///< packet_data is physical address to physically-contiguous memory
} sec_aacs_packet_buffer_type_t;


/** A linked list of AACS packets to be processed */
typedef struct
{
    unsigned long                  num_packets;
                                       /*!<  number of entries in the packets array  */
    sec_aacs_packet_t *            packets;
                                       /*!<  array of packet buffers to process  */
    sec_aacs_packet_buffer_type_t  src_buffer_type;
                                       /*!<  memory type for source buffers in packet list  */
    sec_aacs_packet_buffer_type_t  dst_buffer_type;
                                       /*!<  memory type for destination buffers in packet list  */
} sec_aacs_packet_list_t;


/** SKB variant data record types. */
typedef enum
{
    SEC_AACS_VDRT_CVDR = 0,  ///< Calculate Variant Data Record
    SEC_AACS_VDRT_CCVDR = 1, ///< Conditionally Calculate Variant Data Record
} sec_aacs_skb_vdr_type_t;


/** Types of provisioning that can be done with sec_wrap_AACS_keys(). */
typedef enum
{
    sec_prov_initial,
                /**<
                 * Entire confidential data flash module is provisioned.
                 */
    sec_prov_devkey_uvdata,
                /**<
                 * Only source device keys and UV data are renewed.
                 */
    sec_prov_elliptic_curve,
                /**<
                 * Only elliptic curve data is renewed.
                 */
    sec_prov_devkey_uvdata_elliptic_curve
                /**<
                 * Source device keys, UV data and elliptic curve data is
                 * renewed.
                 */
} sec_aacs_provision_t;

#endif
