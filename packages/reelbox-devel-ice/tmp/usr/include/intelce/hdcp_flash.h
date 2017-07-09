/****************************************************************************
 * Copyright (c) 2008-2009 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: hdcp_flash.h
 ***************************************************************************/

#ifndef _HDCP_FLASH_H_
#define _HDCP_FLASH_H_

#include "flash_appdata_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RIV_MAX		4
#define EKS_MAX		288
#define KSV_MAX		5
#define PAD_MAX		11

//			320		=	16		 +	288	   +	5	 +	11
#define	KEY_RECORD (RIV_MAX * 4) + EKS_MAX + KSV_MAX + PAD_MAX

#define SRM_MAX		5120	// 5K bytes for SRM  (System Renewability Message)

#define HDCP_2_MAX	922		// 922 bytes for HDCP 2 Keys

/*!
 *  Structure to store the Random Initialization Vector when in CBC mode.
 *  @struct hdcp_riv
 */
typedef struct 
{
   flash_appdata_u32_t riv3; /*!< bits 96-127 of the 128 bit IV. */
   flash_appdata_u32_t riv2; /*!< bits 64-95 of the 64 bit & 128 bit IV. */
   flash_appdata_u32_t riv1; /*!< bits 32-63 of the IV. */
   flash_appdata_u32_t riv0; /*!< bits 0-31 of the IV. */
}hdcp_riv;

typedef struct
{
	hdcp_riv				riv;
	flash_appdata_u8_t		eks[EKS_MAX];
	flash_appdata_u8_t		ksv[KSV_MAX];
}hdcp_image;

typedef struct  
{
	hdcp_image				hdcpFlash;	
	flash_appdata_u8_t		pad[PAD_MAX];
}hdcp_record;

typedef struct  
{
	flash_appdata_u32_t		siliconCPUid;
	flash_appdata_u64_t		siliconSerialNumber;
	hdcp_image			hdcpFlash;	
	flash_appdata_u32_t		srmLength;			// Length of SRM
	flash_appdata_u8_t		srm[SRM_MAX];			// SRM Buffer
}hdcp_info;

typedef struct  
{
	flash_appdata_u32_t		siliconCPUid;
	flash_appdata_u64_t		siliconSerialNumber;
	flash_appdata_u8_t		hdcp_2_key[HDCP_2_MAX];	// HDCP 2 Keys
}hdcp_2_info;

/*###################################################################################*/
/*  FUNCTION PROTOTYPES:                                                             */
/*###################################################################################*/
/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read HDCP Keys from boot flash
 *
 *   Reads 288-byte encrypted HDCP Key blob, 5-byte KSV, 32-bit Silicon CPU ID, and 
 *   32-bit Silicon Serial Number into caller-allocated buffers.  The KSV buffer should 
 *   not be padded beyond 5 bytes.
 *
 *   The silicon CPU ID and silicon Serial Number was retrieved from the silicon during 
 *   the process that wrote the HDCP Keys to flash, and stored along with the keys.  The 
 *   caller can use this value to compare with the current result to test if the HDCP Keys 
 *   are bound to this silicon for diagnostic reporting purposes.
 *
 *   It is possible that no HDCP Keys are installed in the system.  In that case, the
 *   function still returns indicating success but returns 0 as the KSV (the other
 *   values are not defined).
 *
 *   Returns logical true if the function was successful.  Successful means that either
 *   the data was successfully read, or that there were no HDCP Keys stored in flash.
 *
 *   Returns logical false if failed.  Failures are abnormal conditions that indicate
 *   a software failure, hardware failure, or device configuration problem.  Other
 *   logging mechanisms such as SVEN can be used to indicate to the user what the
 *   failure condition was.
 *
 *     @param[out] hdcp_keys                     filled with encrypted HDCP Keys (288-byte blob)
 *     @param[out] ksv                           filled with KSV (5 bytes, little-endian)
 *     @param[out] si_cpu_id				     filled with silicon CPU ID (32 bits)
 *     @param[out] si_serial_number              filled with silicon serial number (32 bits)
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_read_keys(hdcp_info *hdcpInfo);

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read HDCP Keys from specified flash
 *
 *   Reads 288-byte encrypted HDCP Key blob, 5-byte KSV, 32-bit Silicon CPU ID, and 
 *   32-bit Silicon Serial Number into caller-allocated buffers.  The KSV buffer should 
 *   not be padded beyond 5 bytes.
 *
 *   The silicon CPU ID and silicon Serial Number was retrieved from the silicon during 
 *   the process that wrote the HDCP Keys to flash, and stored along with the keys.  The 
 *   caller can use this value to compare with the current result to test if the HDCP Keys 
 *   are bound to this silicon for diagnostic reporting purposes.
 *
 *   It is possible that no HDCP Keys are installed in the system.  In that case, the
 *   function still returns indicating success but returns 0 as the KSV (the other
 *   values are not defined).
 *
 *   Returns logical true if the function was successful.  Successful means that either
 *   the data was successfully read, or that there were no HDCP Keys stored in flash.
 *
 *   Returns logical false if failed.  Failures are abnormal conditions that indicate
 *   a software failure, hardware failure, or device configuration problem.  Other
 *   logging mechanisms such as SVEN can be used to indicate to the user what the
 *   failure condition was.
 *
 *     @param[out] hdcp_keys                     filled with encrypted HDCP Keys (288-byte blob)
 *     @param[out] ksv                           filled with KSV (5 bytes, little-endian)
 *     @param[out] si_cpu_id				     filled with silicon CPU ID (32 bits)
 *     @param[out] si_serial_number              filled with silicon serial number (32 bits)
 *     @param[in] dwflashtype                       flash type to read hdcp keys from (0 is NOR, 1 is NAND)
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_read_keys_byft(hdcp_info *hdcpInfo, flash_appdata_u32_t dwflashtype);

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write HDCP Keys to boot flash
 *
 *   Writes 288-byte encrypted HDCP Key blob, 5-byte KSV, 32-bit Silicon CPU ID, and 
 *   32-bit Silicon Serial Number into caller-allocated buffers.  The KSV buffer should 
 *   not be padded beyond 5 bytes.
 *
 *   Writes the silicon CPU ID and silicon Serial Number into flash, and stored along with  
 *   the keys. These values will be used to compare with the silicon values to test if the  
 *   HDCP Keys are bound to this silicon for diagnostic reporting purposes.
 *
 *   It is possible that no HDCP Keys are installed in the system.  In that case, the
 *   function still returns indicating success but returns 0 as the KSV (the other
 *   values are not defined).
 *
 *   Returns logical true if the function was successful.  Successful means that either
 *   the data was successfully written in flash.
 *
 *   Returns logical false if failed.  Failures are abnormal conditions that indicate
 *   a software failure, hardware failure, or device configuration problem.  Other
 *   logging mechanisms such as SVEN can be used to indicate to the user what the
 *   failure condition was.
 *
 *     @param[in] hdcp_keys                     filled with encrypted HDCP Keys (288-byte blob)
 *     @param[in] ksv                           filled with KSV (5 bytes, little-endian)
 *     @param[in] si_cpu_id				     filled with silicon CPU ID (32 bits)
 *     @param[in] si_serial_number              filled with silicon serial number (32 bits)
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_write_keys(hdcp_info *hdcpInfo);

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write HDCP Keys to specified flash
 *
 *   Writes 288-byte encrypted HDCP Key blob, 5-byte KSV, 32-bit Silicon CPU ID, and 
 *   32-bit Silicon Serial Number into caller-allocated buffers.  The KSV buffer should 
 *   not be padded beyond 5 bytes.
 *
 *   Writes the silicon CPU ID and silicon Serial Number into flash, and stored along with  
 *   the keys. These values will be used to compare with the silicon values to test if the  
 *   HDCP Keys are bound to this silicon for diagnostic reporting purposes.
 *
 *   It is possible that no HDCP Keys are installed in the system.  In that case, the
 *   function still returns indicating success but returns 0 as the KSV (the other
 *   values are not defined).
 *
 *   Returns logical true if the function was successful.  Successful means that either
 *   the data was successfully written in flash.
 *
 *   Returns logical false if failed.  Failures are abnormal conditions that indicate
 *   a software failure, hardware failure, or device configuration problem.  Other
 *   logging mechanisms such as SVEN can be used to indicate to the user what the
 *   failure condition was.
 *
 *     @param[in] hdcp_keys                     filled with encrypted HDCP Keys (288-byte blob)
 *     @param[in] ksv                           filled with KSV (5 bytes, little-endian)
 *     @param[in] si_cpu_id				     filled with silicon CPU ID (32 bits)
 *     @param[in] si_serial_number              filled with silicon serial number (32 bits)
 *     @param[in] dwflashtype                       flash type to write hdcp keys to (0 is NOR, 1 is NAND)
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_write_keys_byft(hdcp_info *hdcpInfo, flash_appdata_u32_t dwflashtype);

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read HDCP SRM from boot flash
 *
 *   Reads the System Renewability Message (SRM) from flash into a caller-allocated
 *   buffer.  The SRM can be any length up to 5K bytes long and can be read or written
 *   during normal operations (e.g. content playback).
 *
 *   It is possible that no SRM is currently stored in flash.  In that case, the
 *   function still returns indicating success but reports 0 as the returned SRM
 *   length.
 *
 *   Returns logical true if the function was successful.  Successful means that either
 *   the data was successfully read, or that there was no SRM stored in flash.
 *
 *   Returns logical false if failed.  Failures are abnormal conditions that indicate
 *   a software failure, hardware failure, or device configuration problem.  Other
 *   logging mechanisms such as SVEN can be used to indicate to the user what the
 *   failure condition was.
 *
 *   It is possible that srm_buffer_length_bytes is less than the actual length of the
 *   SRM stored in flash.  This is not an error.  The function should simply return a
 *   truncated result of srm_buffer_length_bytes and report the actual length back in
 *   returned_length_bytes.  So, in that case -and only in the case where the stored
 *   SRM length is greater than srm_buffer_length_bytes, would return_length_bytes be
 *   greater than srm_buffer_length_bytes.  But no more than srm_buffer_length_bytes
 *   is written to the buffer.  This peculiarity allows for a clean upgrade path to
 *   later SRM generations that may be longer but the installed SW does not yet
 *   support such later SRM generations (e.g. SRM installed at manufacture is a
 *   future generation that is longer than 5K bytes, but our SW only knows about
 *   generation 1 SRMs which are no more than 5K bytes, and can still read and
 *   treat it like a generation 1 SRM due to the backward compatability of future
 *   generations).  The following cases summarize all of the options:
 *
 *     IF <no SRM stored> THEN
 *       - copy 0 bytes to srm_buffer
 *       - returned_length_bytes = 0.
 *     ELSE IF srm_buffer_length_bytes >= <stored SRM length> THEN
 *       - copy <stored SRM length> to srm_buffer
 *       - returned_length_bytes = <stored SRM length>
 *     ELSE ( <stored SRM length> is greater than srm_buffer_length_bytes )
 *       - copy srm_buffer_length_bytes to srm_buffer
 *       - returned_length_bytes = <stored SRM length>
 *     ENDIF
 *
 *   Flash must support storing SRMs up to 5KB long for generation 1 SRMs.  Future
 *   variations of the HDCP Specification may require subsequent SRM generations
 *   of which will likely need more than 5KB storage.
 *
 *     @param[in] srm_buffer_length_bytes        the size of the buffer pointed to by srm_buffer
 *     @param[out] srm_buffer                    filled with encrypted HDCP Keys (288-byte blob)
 *     @param[out] returned_length_bytes         length of SRM returned (0 means none)
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_read_srm(flash_appdata_u32_t srm_buffer_length_bytes, void *srm_buffer, flash_appdata_u32_t *returned_length_bytes);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read HDCP SRM from specified flash
 *
 *   Reads the System Renewability Message (SRM) from flash into a caller-allocated
 *   buffer.  The SRM can be any length up to 5K bytes long and can be read or written
 *   during normal operations (e.g. content playback).
 *
 *   It is possible that no SRM is currently stored in flash.  In that case, the
 *   function still returns indicating success but reports 0 as the returned SRM
 *   length.
 *
 *   Returns logical true if the function was successful.  Successful means that either
 *   the data was successfully read, or that there was no SRM stored in flash.
 *
 *   Returns logical false if failed.  Failures are abnormal conditions that indicate
 *   a software failure, hardware failure, or device configuration problem.  Other
 *   logging mechanisms such as SVEN can be used to indicate to the user what the
 *   failure condition was.
 *
 *   It is possible that srm_buffer_length_bytes is less than the actual length of the
 *   SRM stored in flash.  This is not an error.  The function should simply return a
 *   truncated result of srm_buffer_length_bytes and report the actual length back in
 *   returned_length_bytes.  So, in that case -and only in the case where the stored
 *   SRM length is greater than srm_buffer_length_bytes, would return_length_bytes be
 *   greater than srm_buffer_length_bytes.  But no more than srm_buffer_length_bytes
 *   is written to the buffer.  This peculiarity allows for a clean upgrade path to
 *   later SRM generations that may be longer but the installed SW does not yet
 *   support such later SRM generations (e.g. SRM installed at manufacture is a
 *   future generation that is longer than 5K bytes, but our SW only knows about
 *   generation 1 SRMs which are no more than 5K bytes, and can still read and
 *   treat it like a generation 1 SRM due to the backward compatability of future
 *   generations).  The following cases summarize all of the options:
 *
 *     IF <no SRM stored> THEN
 *       - copy 0 bytes to srm_buffer
 *       - returned_length_bytes = 0.
 *     ELSE IF srm_buffer_length_bytes >= <stored SRM length> THEN
 *       - copy <stored SRM length> to srm_buffer
 *       - returned_length_bytes = <stored SRM length>
 *     ELSE ( <stored SRM length> is greater than srm_buffer_length_bytes )
 *       - copy srm_buffer_length_bytes to srm_buffer
 *       - returned_length_bytes = <stored SRM length>
 *     ENDIF
 *
 *   Flash must support storing SRMs up to 5KB long for generation 1 SRMs.  Future
 *   variations of the HDCP Specification may require subsequent SRM generations
 *   of which will likely need more than 5KB storage.
 *
 *     @param[in] srm_buffer_length_bytes        the size of the buffer pointed to by srm_buffer
 *     @param[out] srm_buffer                    filled with encrypted HDCP Keys (288-byte blob)
 *     @param[out] returned_length_bytes         length of SRM returned (0 means none)
 *     @param[in] dwflashtype                       flash type to read hdcp keys from (0 is NOR, 1 is NAND)
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_read_srm_byft(flash_appdata_u32_t srm_buffer_length_bytes, void *srm_buffer, flash_appdata_u32_t *returned_length_bytes, flash_appdata_u32_t dwflashtype);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write HDCP SRM to boot flash
 *
 *   Writes the System Renewability Message (SRM) to flash.  The caller can write any
 *   non-zero length up to 5K bytes.  Future revisions of the HDCP Specification may
 *   require more than 5K bytes.
 *
 *   Returns logical true if the function was successful.  Successful means that the
 *   flash was successfully updated to the data in the buffer.
 *
 *   Returns logical false if failed.  Failures are abnormal conditions that indicate
 *   a software failure, hardware failure, or device configuration problem.  Other
 *   logging mechanisms such as SVEN can be used to indicate to the user what the
 *   failure condition was.  If at all possible, the flash should be left unmodified
 *   in the event of a failure, allowing the previous SRM state to be retained.
 *
 *   If srm_buffer_length_bytes is more than supported (e.g. > 5K bytes), then this
 *   function should indicate failure.
 *
 *     @param[in] srm_buffer_length_bytes        the size of the buffer pointed to by srm_buffer.
 *     Important: If srm_buffer_length_bytes = 0 the SRM List will be cleared and set to all FFs
 *
 *     @param[in] srm_buffer                     filled with SRM List (Less than or equal 5120-byte blob)
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_write_srm(flash_appdata_u32_t srm_buffer_length_bytes, const void *srm_buffer);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  
 *   \brief Write HDCP SRM to specified flash
 *
 *   Writes the System Renewability Message (SRM) to flash.  The caller can write any
 *   non-zero length up to 5K bytes.  Future revisions of the HDCP Specification may
 *   require more than 5K bytes.
 *
 *   Returns logical true if the function was successful.  Successful means that the
 *   flash was successfully updated to the data in the buffer.
 *
 *   Returns logical false if failed.  Failures are abnormal conditions that indicate
 *   a software failure, hardware failure, or device configuration problem.  Other
 *   logging mechanisms such as SVEN can be used to indicate to the user what the
 *   failure condition was.  If at all possible, the flash should be left unmodified
 *   in the event of a failure, allowing the previous SRM state to be retained.
 *
 *   If srm_buffer_length_bytes is more than supported (e.g. > 5K bytes), then this
 *   function should indicate failure.
 *
 *     @param[in] srm_buffer_length_bytes        the size of the buffer pointed to by srm_buffer.
 *     Important: If srm_buffer_length_bytes = 0 the SRM List will be cleared and set to all FFs
 *
 *     @param[in] srm_buffer                     filled with SRM List (Less than or equal 5120-byte blob)
 *     @param[in] dwflashtype                       flash type to write hdcp keys to (0 is NOR, 1 is NAND)
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_write_srm_byft(flash_appdata_u32_t srm_buffer_length_bytes, const void *srm_buffer, flash_appdata_u32_t dwflashtype);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/*!  \brief Read HDCP 2 Keys to boot flash
 *
 *   Read a blob of HDCP 2 keys to boot flash.
 *
 *   922 bytes: Blob contains the following data
 *
 *   The format of the materials is as follows:
 *   4   bytes:   Module ID:  0x8000
 *   4   bytes:   revision
 *   4   bytes:   flags (see below)
 *   4   bytes:   date/time stamp
 *   16  bytes:   permissions (see below)
 *   16  bytes:   IV
 *   16  bytes:   lc128 (encrypted)
 *   522 bytes:   cert (not encrypted)
 *   320 bytes:   private key (encrypted)
 *   16  bytes:   CMAC or SHA1 hash of unencrypted data
 *
 *   flags:
 *     0x00FF  - key mask:
 *                 0x0 - unencrypted
 *                 0x1 - encrypted with test key 0x001002300450067008900ab00cd00ef0
 *                 0x2 - GKEK encryted (with SHA-1 hash on end)
 *                 0x3 - KOEM encrypted (with CMAC on end)
 *     0x0100  - REPEATER flag
 *     0x0200  - test vectors mode is enabled
 *
 *   permissions bit mask (a 1 indicates permitted use):
 *     bit:
 *     0       WiDi (through TSD)
 *     1       NAL  (through SEC)
 *     others  reserved for future use
 *
 *   The GKEK-wrapped keys are normally received with a SHA1 hash of the
 *   unencrypted version of the data, followed by another SHA1 hash of the
 *   encrypted version of the same data (i.e. previous hash is not hashed)
 *   Unencrypted keys do not have a hash.
 *   KOEM-encrypted keys have a 16-byte CMAC instead.
 *
 *     @param[out hdcp2Info						filled with hdcp_2_info structure type
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_2_read_keys(hdcp_2_info *hdcp2Info);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read HDCP 2 Keys to specified flash
 *
 *   Read a blob of HDCP 2 keys to specified flash.
 *
 *   922 bytes: Blob contains the following data
 *
 *   The format of the materials is as follows:
 *   4   bytes:   Module ID:  0x8000
 *   4   bytes:   revision
 *   4   bytes:   flags (see below)
 *   4   bytes:   date/time stamp
 *   16  bytes:   permissions (see below)
 *   16  bytes:   IV
 *   16  bytes:   lc128 (encrypted)
 *   522 bytes:   cert (not encrypted)
 *   320 bytes:   private key (encrypted)
 *   16  bytes:   CMAC or SHA1 hash of unencrypted data
 *
 *   flags:
 *     0x00FF  - key mask:
 *                 0x0 - unencrypted
 *                 0x1 - encrypted with test key 0x001002300450067008900ab00cd00ef0
 *                 0x2 - GKEK encryted (with SHA-1 hash on end)
 *                 0x3 - KOEM encrypted (with CMAC on end)
 *     0x0100  - REPEATER flag
 *     0x0200  - test vectors mode is enabled
 *
 *   permissions bit mask (a 1 indicates permitted use):
 *     bit:
 *     0       WiDi (through TSD)
 *     1       NAL  (through SEC)
 *     others  reserved for future use
 *
 *   The GKEK-wrapped keys are normally received with a SHA1 hash of the
 *   unencrypted version of the data, followed by another SHA1 hash of the
 *   encrypted version of the same data (i.e. previous hash is not hashed)
 *   Unencrypted keys do not have a hash.
 *   KOEM-encrypted keys have a 16-byte CMAC instead.
 *
 *     @param[out hdcp2Info						filled with hdcp_2_info structure type
 *     @param[in] dwflashtype					flash type to read hdcp keys from (0 is NOR, 1 is NAND)
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_2_read_keys_byft(hdcp_2_info *hdcp2Info, flash_appdata_u32_t dwflashtype);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write HDCP 2 Keys to boot flash
 *
 *   Write a HDCP 2 key to boot flash.
 *
 *   922 bytes: HDCP 2 key contains the following data
 *
 *   The format of the materials is as follows:
 *   4   bytes:   Module ID:  0x8000
 *   4   bytes:   revision
 *   4   bytes:   flags (see below)
 *   4   bytes:   date/time stamp
 *   16  bytes:   permissions (see below)
 *   16  bytes:   IV
 *   16  bytes:   lc128 (encrypted)
 *   522 bytes:   cert (not encrypted)
 *   320 bytes:   private key (encrypted)
 *   16  bytes:   CMAC or SHA1 hash of unencrypted data
 *
 *   flags:
 *     0x00FF  - key mask:
 *                 0x0 - unencrypted
 *                 0x1 - encrypted with test key 0x001002300450067008900ab00cd00ef0
 *                 0x2 - GKEK encryted (with SHA-1 hash on end)
 *                 0x3 - KOEM encrypted (with CMAC on end)
 *     0x0100  - REPEATER flag
 *     0x0200  - test vectors mode is enabled
 *
 *   permissions bit mask (a 1 indicates permitted use):
 *     bit:
 *     0       WiDi (through TSD)
 *     1       NAL  (through SEC)
 *     others  reserved for future use
 *
 *   The GKEK-wrapped keys are normally received with a SHA1 hash of the
 *   unencrypted version of the data, followed by another SHA1 hash of the
 *   encrypted version of the same data (i.e. previous hash is not hashed)
 *   Unencrypted keys do not have a hash.
 *   KOEM-encrypted keys have a 16-byte CMAC instead.
 *
 *   Writes the silicon CPU ID and silicon Serial Number into flash, and stored along with  
 *   the keys. These values will be used to compare with the silicon values to test if the  
 *   HDCP 2 Keys are bound to this silicon for diagnostic reporting purposes.
 *
 *   Returns logical true if the function was successful.  Successful means that either
 *   the data was successfully written in flash.
 *
 *   Returns logical false if failed.  Failures are abnormal conditions that indicate
 *   a software failure, hardware failure, or device configuration problem.  Other
 *   logging mechanisms such as SVEN can be used to indicate to the user what the
 *   failure condition was.
 *
 *     @param[in] hdcp2Info						filled with hdcp_2_info structure type
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_2_write_keys(hdcp_2_info *hdcp2Info);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write HDCP 2 Keys to specified flash
 *
 *   Write a HDCP 2 key to specified flash.
 *
 *   922 bytes: HDCP 2 key contains the following data
 *
 *   The format of the materials is as follows:
 *   4   bytes:   Module ID:  0x8000
 *   4   bytes:   revision
 *   4   bytes:   flags (see below)
 *   4   bytes:   date/time stamp
 *   16  bytes:   permissions (see below)
 *   16  bytes:   IV
 *   16  bytes:   lc128 (encrypted)
 *   522 bytes:   cert (not encrypted)
 *   320 bytes:   private key (encrypted)
 *   16  bytes:   CMAC or SHA1 hash of unencrypted data
 *
 *   flags:
 *     0x00FF  - key mask:
 *                 0x0 - unencrypted
 *                 0x1 - encrypted with test key 0x001002300450067008900ab00cd00ef0
 *                 0x2 - GKEK encryted (with SHA-1 hash on end)
 *                 0x3 - KOEM encrypted (with CMAC on end)
 *     0x0100  - REPEATER flag
 *     0x0200  - test vectors mode is enabled
 *
 *   permissions bit mask (a 1 indicates permitted use):
 *     bit:
 *     0       WiDi (through TSD)
 *     1       NAL  (through SEC)
 *     others  reserved for future use
 *
 *   The GKEK-wrapped keys are normally received with a SHA1 hash of the
 *   unencrypted version of the data, followed by another SHA1 hash of the
 *   encrypted version of the same data (i.e. previous hash is not hashed)
 *   Unencrypted keys do not have a hash.
 *   KOEM-encrypted keys have a 16-byte CMAC instead.
 *
 *   Writes the silicon CPU ID and silicon Serial Number into flash, and stored along with  
 *   the keys. These values will be used to compare with the silicon values to test if the  
 *   HDCP 2 Keys are bound to this silicon for diagnostic reporting purposes.
 *
 *   Returns logical true if the function was successful.  Successful means that either
 *   the data was successfully written in flash.
 *
 *   Returns logical false if failed.  Failures are abnormal conditions that indicate
 *   a software failure, hardware failure, or device configuration problem.  Other
 *   logging mechanisms such as SVEN can be used to indicate to the user what the
 *   failure condition was.
 *
 *     @param[in] hdcp2Info						filled with hdcp_2_info structure type
 *     @param[in] dwflashtype                   flash type to write hdcp keys to (0 is NOR, 1 is NAND)
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_2_write_keys_byft(hdcp_2_info *hdcp2Info, flash_appdata_u32_t dwflashtype);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read the HDCP2 Receiver Public Key Certificate
 *
 *   Returns the HDCP2 Receiver Public Key Certificate that is specific to
 *   each HDCP Receiver Key Order signed by DCP LLC.  This Certificate contains 
 *   the Receiver ID and the RSA public key corresponding to the HDCP Reciever.
 *
 *     @param[in] cert_rx_buffer                Allocated buffer to store the Reciever Public Key Certificate.
 *     @param[in] cert_rx_buffer_size           Size of buffer for Reciever Public key Certificate.
 *     @return  logical true if successful
 *              logical false if failed for some reason.
 */
int flash_hdcp_2_get_certrx(flash_appdata_u8_t * cert_rx_buffer, int cert_rx_buffer_size);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */


int flash_hdcp_rw_flash(int isRead, flash_appdata_u8_t* pData, flash_appdata_u32_t datasize, flash_appdata_u32_t offset,	flash_appdata_u32_t dwflashtype);
int flash_hdcp_secretrw_flash(int isRead,	flash_appdata_u8_t* pData, flash_appdata_u32_t datasize, flash_appdata_u32_t offset, flash_appdata_u32_t dwflashtype);

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Retrieve Flash and Device Type
 *
 *   Retrieve Flash and Device Type.
 *
 *     @param[in/out] flash			flash type (NOR, NAND, and DEF_FLASH) If DEF_FLASH passed in then actual value that is used is returned
 *     @param[out] device			device type (GEN3, GEN4, and GEN5) There is no default value
 *     @return  nothing
 */
flash_appdata_result_t flash_hdcp_type(FLASH_TYPE * flash, DEVICE_TYPE * device);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */


#ifdef __cplusplus
}
#endif

#endif  /*  ifndef _FLASH_HDCP_H  */
