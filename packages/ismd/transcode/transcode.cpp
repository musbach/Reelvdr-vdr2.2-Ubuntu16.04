#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <locale.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ismd_core.h"
#include "ismd_global_defs.h"
#include "ismd_demux.h"
#include "ismd_audio.h"
#include "ismd_audio_ac3_enc.h"
#include "ismd_audio_dts_enc.h"
#include "ismd_audio_dts.h"
#include "ismd_audio_ddplus.h"
#include "ismd_audio_aac.h"
#include "ismd_audio_ac3.h"
#include "gen3_audio.h"
#include "ismd_audio_defs.h"
#include "ismd_viddec.h"
#include "ismd_vidpproc.h"
#include "ismd_audio_aac_enc.h"
#include "ismd_videnc.h"
#include "ismd_mux.h"
#include "ismd_vidrend.h"
#include "ismd_bufmon.h"

#include <libsi/si.h>
#include <libsi/section.h>
#include <libsi/descriptor.h>

#define DBG_NONE   0
#define DBG_STDOUT 1

#define DBG_SMD DBG_STDOUT                                                                   \

#define VIDEO_FLAG_PROFILE_BASELINE (1<<0)
#define VIDEO_FLAG_PROFILE_MAIN     (1<<1)
#define VIDEO_FLAG_IPHONE_LEVEL_3_0 (1<<2)
#define VIDEO_FLAG_IPHONE_LEVEL_3_1 (1<<3)

#define AUDIO_FLAG_CONVERT_MPA 0x2000
#define AUDIO_FLAG_CONVERT_AC3 0x4000
#define AUDIO_FLAG_PID_MASK    0x1FFF

#define VID_CHUNK_SIZE 32768
#define AUD_CHUNK_SIZE 8192

#define PORT_WRITE_RETRY_COUNT 100
#define PORT_WRITE_RETRY_DELAY 30
#define PORT_WRITE_FAIL_DELAY  100

#define TS_SYNC_BYTE          0x47
#define TS_SIZE               188
#define TS_ERROR              0x80
#define TS_PAYLOAD_START      0x40
#define TS_TRANSPORT_PRIORITY 0x20
#define TS_PID_MASK_HI        0x1F
#define TS_SCRAMBLING_CONTROL 0xC0
#define TS_ADAPT_FIELD_EXISTS 0x20
#define TS_PAYLOAD_EXISTS     0x10
#define TS_CONT_CNT_MASK      0x0F
#define TS_ADAPT_DISCONT      0x80
#define TS_ADAPT_RANDOM_ACC   0x40 // would be perfect for detecting independent frames, but unfortunately not used by all broadcasters
#define TS_ADAPT_ELEM_PRIO    0x20
#define TS_ADAPT_PCR          0x10
#define TS_ADAPT_OPCR         0x08
#define TS_ADAPT_SPLICING     0x04
#define TS_ADAPT_TP_PRIVATE   0x02
#define TS_ADAPT_EXTENSION    0x01

inline bool TsHasPayload(const unsigned char *p) {
	return p[3] & TS_PAYLOAD_EXISTS;
} // TsHasPayload

inline bool TsHasAdaptationField(const unsigned char *p) {
	return p[3] & TS_ADAPT_FIELD_EXISTS;
} // TsHasAdaptationField

inline bool TsPayloadStart(const unsigned char *p) {
	return p[1] & TS_PAYLOAD_START;
} // TsPayloadStart

inline bool TsError(const unsigned char *p) {
	return p[1] & TS_ERROR;
} // TsError

inline int TsPid(const unsigned char *p) {
	return (p[1] & TS_PID_MASK_HI) * 256 + p[2];
} // TsPid

inline int TsPayloadOffset(const unsigned char *p) {
	int o = TsHasAdaptationField(p) ? p[4] + 5 : 4;
	return o <= TS_SIZE ? o : TS_SIZE;
} // TsPayloadOffset

inline int TsGetPayload(const unsigned char **p) {
	if (TsHasPayload(*p)) {
		int o = TsPayloadOffset(*p);
		*p += o;
		return TS_SIZE - o;
	}
	return 0;
} // TsGetPayload

#define TS_SECTION_LENGTH(x,l) ((l >= 3) ? ((int(x[1]) & 0x0F) << 8) | x[2] : 0 )

#define READ_BUFFER_SIZE (TS_SIZE*100)
#define MAX_SECTION_SIZE 4096
#define MAX_PIDS 0x2000

#define PRINT(x...) fprintf(stderr, x)
#define FLUSH() fflush(stderr)

#define STREAM_TYPE_STR(x) (                                           \
    (0x01 == x) ? "11172 VIDEO" :                                      \
    (0x02 == x) ? "13818 VIDEO" :                                      \
    (0x1B == x) ? "ISO/IEC 14496-10 Video" :                           \
    (0x03 == x) ? "11172 AUDIO" :                                      \
    (0x04 == x) ? "13818 AUDIO" :                                      \
    (0x0F == x) ? "ISO/IEC 13818-7 Audio with ADTS transport syntax" : \
    (0x11 == x) ? "ISO/IEC 14496-3 Audio with LATM transport syntax" : \
    (0x06 == x) ? "13818 PES PRIVATE" :                                \
    (""))

#define CODEC_TYPE_STR(x) (                    \
    (ISMD_CODEC_TYPE_INVALID==x)?("INVALID") : \
    (ISMD_CODEC_TYPE_MPEG2  ==x)?("MPEG2")   : \
    (ISMD_CODEC_TYPE_H264   ==x)?("H264")    : \
    (ISMD_CODEC_TYPE_VC1    ==x)?("VC1")     : \
    (ISMD_CODEC_TYPE_MPEG4  ==x)?("MPEG4")   : \
    (""))

#define AUDIO_MEDIA_FMT_STR(x) (                                             \
    (ISMD_AUDIO_MEDIA_FMT_INVALID            ==x)? ("INVALID")             : \
    (ISMD_AUDIO_MEDIA_FMT_PCM                ==x)? ("PCM")                 : \
    (ISMD_AUDIO_MEDIA_FMT_DVD_PCM            ==x)? ("DVD_PCM")             : \
    (ISMD_AUDIO_MEDIA_FMT_BLURAY_PCM         ==x)? ("BLUREAY_PCM")         : \
    (ISMD_AUDIO_MEDIA_FMT_MPEG               ==x)? ("MPEG")                : \
    (ISMD_AUDIO_MEDIA_FMT_AAC                ==x)? ("AAC")                 : \
    (ISMD_AUDIO_MEDIA_FMT_AAC_LOAS           ==x)? ("AAC_LOAS")            : \
    (ISMD_AUDIO_MEDIA_FMT_DD                 ==x)? ("Dolby Digital")       : \
    (ISMD_AUDIO_MEDIA_FMT_DD_PLUS            ==x)? ("Dolby Digital+")      : \
    (ISMD_AUDIO_MEDIA_FMT_TRUE_HD            ==x)? ("TRUE_HD")             : \
    (ISMD_AUDIO_MEDIA_FMT_DTS_HD             ==x)? ("DTS_HD")              : \
    (ISMD_AUDIO_MEDIA_FMT_DTS_HD_HRA         ==x)? ("DTS_HD_HRA")          : \
    (ISMD_AUDIO_MEDIA_FMT_DTS_HD_MA          ==x)? ("DTS_HD_MA")           : \
    (ISMD_AUDIO_MEDIA_FMT_DTS                ==x)? ("DTS")                 : \
    (ISMD_AUDIO_MEDIA_FMT_DTS_LBR            ==x)? ("DTS_LBR")             : \
    (ISMD_AUDIO_MEDIA_FMT_DTS_BC             ==x)? ("DTS_BC")              : \
    (ISMD_AUDIO_MEDIA_FMT_WM9                ==x)? ("WM9")                 : \
    (""))

#define ISMD_ERR_STR(x) (                                                \
    (ISMD_SUCCESS                      ==x)?("SUCCESS")                : \
    (ISMD_ERROR_FEATURE_NOT_IMPLEMENTED==x)?("FEATURE_NOT_IMPLEMENTED"): \
    (ISMD_ERROR_FEATURE_NOT_SUPPORTED  ==x)?("FEATURE_NOT_SUPPORTED")  : \
    (ISMD_ERROR_INVALID_VERBOSITY_LEVEL==x)?("INVALID_VERBOSITY_LEVEL"): \
    (ISMD_ERROR_INVALID_PARAMETER      ==x)?("INVALID_PARAMETER")      : \
    (ISMD_ERROR_INVALID_HANDLE         ==x)?("INVALID_HANDLE")         : \
    (ISMD_ERROR_NO_RESOURCES           ==x)?("NO_RESOURCES")           : \
    (ISMD_ERROR_INVALID_RESOURCE       ==x)?("INVALID_RESOURCE")       : \
    (ISMD_ERROR_INVALID_QUEUE_TYPE     ==x)?("INVALID_QUEUE_TYPE")     : \
    (ISMD_ERROR_NO_DATA_AVAILABLE      ==x)?("NO_DATA_AVAILABLE")      : \
    (ISMD_ERROR_NO_SPACE_AVAILABLE     ==x)?("NO_SPACE_AVAILABLE")     : \
    (ISMD_ERROR_TIMEOUT                ==x)?("TIMEOUT")                : \
    (ISMD_ERROR_EVENT_BUSY             ==x)?("EVENT_BUSY")             : \
    (ISMD_ERROR_OBJECT_DELETED         ==x)?("OBJECT_DELETED")         : \
    (ISMD_ERROR_ALREADY_INITIALIZED    ==x)?("ALREADY_INITIALIZED")    : \
    (ISMD_ERROR_IOCTL_FAILED           ==x)?("IOCTL_FAILED")           : \
    (ISMD_ERROR_INVALID_BUFFER_TYPE    ==x)?("INVALID_BUFFER_TYPE")    : \
    (ISMD_ERROR_INVALID_FRAME_TYPE     ==x)?("INVALID_FRAME_TYPE")     : \
    (ISMD_ERROR_QUEUE_BUSY             ==x)?("QUEUE_BUSY")             : \
    (ISMD_ERROR_NOT_FOUND              ==x)?("NOT_FOUND")              : \
    (ISMD_ERROR_OPERATION_FAILED       ==x)?("OPERATION_FAILED")       : \
    (ISMD_ERROR_PORT_BUSY              ==x)?("PORT_BUSY")              : \
    (ISMD_ERROR_NULL_POINTER           ==x)?("NULL_POINTER")           : \
    (ISMD_ERROR_INVALID_REQUEST        ==x)?("INVALID_REQUEST")        : \
    (ISMD_ERROR_OUT_OF_RANGE           ==x)?("OUT_OF_RANGE")           : \
    (ISMD_ERROR_NOT_DONE               ==x)?("NOT_DONE")               : \
    (ISMD_ERROR_SUSPENDED              ==x)?("SUSPENDED")              : \
    (ISMD_ERROR_UNSPECIFIED            ==x)?("UNSPECIFIED")            : \
    (""))

#define SMDCHECK(x...) {                                                                          \
    ret = x;                                                                                      \
    if (ISMD_SUCCESS != ret) {                                                                    \
        if(DBG_SMD==DBG_STDOUT)                                                                   \
            PRINT("SMD %s <%d>: 0x%x %s=" #x "\n", __FILE__, __LINE__, ret, ISMD_ERR_STR(ret) );    \
    }                                                                                             \
}

#define SMDCHECK_IGN(y,x...) {                                                                    \
    ret = x;                                                                                      \
    if ((ISMD_SUCCESS != ret) && (y != ret)) {                                                    \
        if(DBG_SMD==DBG_STDOUT)                                                                   \
            PRINT("SMD %s <%d>: 0x%x %s=" #x "\n", __FILE__, __LINE__, ret, ISMD_ERR_STR(ret) );    \
    }                                                                                             \
}

#define SMDCHECK_CLEANUP(x...) { \
    SMDCHECK(x);                 \
    if (ISMD_SUCCESS != ret)     \
        goto cleanup;            \
}

#define H264_PROFILE(x) ( \
    (x & VIDEO_FLAG_PROFILE_BASELINE) ? ISMD_VIDENC_H264_PROFILE_BASELINE : \
    (x & VIDEO_FLAG_PROFILE_MAIN) ? ISMD_VIDENC_H264_PROFILE_BASELINE : \
    ISMD_VIDENC_H264_PROFILE_HIGH)

#define H264_LEVEL(x) ( \
    (x & VIDEO_FLAG_IPHONE_LEVEL_3_0) ? ISMD_VIDENC_H264_LEVEL_3_0 : \
    (x & VIDEO_FLAG_IPHONE_LEVEL_3_1) ? ISMD_VIDENC_H264_LEVEL_3_1 : \
    ISMD_VIDENC_H264_LEVEL_4_1)

/////////////////////////////////////////////////////////////////////////////////////
// TOOLS

static ismd_pts_t pts_val(unsigned char Check, const unsigned char *Data) {
	if((Data[0]>>4) != Check) {
		PRINT("pts_val: Invalid pts check %02x %02x %02x %02x %02x - %x", Data[0], Data[1], Data[2], Data[3], Data[4], Check);
		return ISMD_NO_PTS;
	} // if
	if(!(Data[0]&0x1) || !(Data[2]&0x1) || !(Data[4]&0x1)) {
		PRINT("pts_val: Invalid field check %02x %02x %02x %02x %02x", Data[0], Data[1], Data[2], Data[3], Data[4]);
		return ISMD_NO_PTS;
	} // if
	ismd_pts_t ret;
	ret =  (((ismd_pts_t)Data[0]) & 0x0E)<<(30-1);
	ret += (((ismd_pts_t)Data[1]) & 0xFF)<<22;
	ret += (((ismd_pts_t)Data[2]) & 0xFE)<<(15-1);
	ret += (((ismd_pts_t)Data[3]) & 0xFF)<<7;
	ret += (((ismd_pts_t)Data[4]) & 0xFE)>>1;
	return ret;
} // pts_val

typedef union {
	unsigned char attributes[256];
	ismd_es_buf_attr_t buf_attr;
} __attribute__((__may_alias__)) ismd_es_buf_attr_mapper_t;

static int write_chunk(ismd_port_handle_t Port, int ChunkSize, const unsigned char *Data, int Size, ismd_es_buf_attr_t *Attr, bool write_new_seg) {
	ismd_result_t ret = ISMD_SUCCESS;
	ismd_buffer_handle_t buffer = ISMD_BUFFER_HANDLE_INVALID;
	ismd_buffer_descriptor_t buffer_desc;
	void *buff_ptr = NULL;
	ismd_es_buf_attr_mapper_t *buff_attr = NULL;
	SMDCHECK_IGN(ISMD_ERROR_NO_RESOURCES, ismd_buffer_alloc(ChunkSize, &buffer));
	if(ISMD_SUCCESS != ret) goto error;
	SMDCHECK(ismd_buffer_read_desc(buffer, &buffer_desc));
	if(ISMD_SUCCESS != ret) goto error;
	buff_ptr = OS_MAP_IO_TO_MEM_CACHE(buffer_desc.phys.base, buffer_desc.phys.size);
	if(!buff_ptr) goto error;
	buffer_desc.phys.level = (Size > buffer_desc.phys.size) ? buffer_desc.phys.size : Size;
	memcpy(buff_ptr, Data, buffer_desc.phys.level);
	OS_UNMAP_IO_FROM_MEM(buff_ptr, buffer_desc.phys.size);
	buff_attr = (ismd_es_buf_attr_mapper_t *)&buffer_desc.attributes;
	if(!Attr) {
		buff_attr->buf_attr.local_pts      = ISMD_NO_PTS;
		buff_attr->buf_attr.original_pts   = ISMD_NO_PTS;
		buff_attr->buf_attr.original_dts   = ISMD_NO_DTS;
		buff_attr->buf_attr.discontinuity  = false;
		buff_attr->buf_attr.pvt_data_valid = false;
	} else
		buff_attr->buf_attr = *Attr;
	SMDCHECK(ismd_buffer_update_desc(buffer, &buffer_desc));
	if(ISMD_SUCCESS != ret) goto error;
	if(write_new_seg) {
		ismd_newsegment_tag_t newsegment_data = {
				start           : Attr ? buff_attr->buf_attr.original_pts : 0,
				stop            : ISMD_NO_PTS,
				linear_start    : 0,
				requested_rate  : ISMD_NORMAL_PLAY_RATE,
				applied_rate    : ISMD_NORMAL_PLAY_RATE,
				rate_valid      : true,
				segment_position: ISMD_NO_PTS};
		PRINT("Set new segment %09llx\n", newsegment_data.start);
		SMDCHECK(ismd_tag_set_newsegment_position(buffer, newsegment_data));
	} // if
	SMDCHECK_IGN(ISMD_ERROR_NO_SPACE_AVAILABLE, ismd_port_write(Port, buffer));
	if(ISMD_SUCCESS != ret) goto error;
	return buffer_desc.phys.level;
error:
	if(NULL != buff_ptr) OS_UNMAP_IO_FROM_MEM(buff_ptr, buffer_desc.phys.size);
	if(ISMD_BUFFER_HANDLE_INVALID != buffer) SMDCHECK(ismd_buffer_dereference(buffer));
	return 0;
} // write_chunk

typedef union {
	int param;
	ismd_audio_decoder_param_t enc_param;
} __attribute__((__may_alias__)) ismd_audio_decoder_param_mapper_t;

/////////////////////////////////////////////////////////////////////////////////////
// TStoPES

#define MAXPESLENGTH 0xFFF0

inline bool PesLongEnough(int Length) {
  return Length >= 6;
}

inline bool PesHasLength(const unsigned char *p) {
  return p[4] | p[5];
}

inline int PesLength(const unsigned char *p) {
  return 6 + p[4] * 256 + p[5];
}

class cTsToPes {
private:
	unsigned char *data;
	int size;
	int length;
	int offset;
	unsigned char *lastData;
	int lastLength;
	bool repeatLast;
public:
	cTsToPes(void) {
		data = NULL;
		size = 0;
		Reset();
	} // cTsToPes
	~cTsToPes() {
		if(data) free(data);
	} // ~cTsToPes
	void PutTs(const unsigned char *Data, int Length) {
		if (TsError(Data)) {
			Reset();
			return; // ignore packets with TEI set, and drop any PES data collected so far
		} // if
		if (TsPayloadStart(Data))
			Reset();
		else if (!size)
			return; // skip everything before the first payload start
		Length = TsGetPayload(&Data);
		if (length + Length > size) {
			int NewSize = length + Length;
			if(NewSize < 2048) NewSize = 2048;
			if (unsigned char *NewData = (unsigned char *)realloc(data, NewSize)) {
				data = NewData;
				size = NewSize;
			} else {
				PRINT("ERROR: out of memory");
				Reset();
				return;
			} // if
		} // if
		memcpy(data + length, Data, Length);
		length += Length;
	} // PutTs
	const unsigned char *GetPes(int &Length) {
		if (repeatLast) {
			repeatLast = false;
			Length = lastLength;
			return lastData;
		} // if
		if (offset < length && PesLongEnough(length)) {
			if (!PesHasLength(data)) // this is a video PES packet with undefined length
				offset = 6; // trigger setting PES length for initial slice
			if (offset) {
				unsigned char *p = data + offset - 6;
				if (p != data) {
					p -= 3;
					memmove(p, data, 4);
				}
				int l = length - offset;
				if(l > MAXPESLENGTH) l = MAXPESLENGTH;
				offset += l;
				if (p != data) {
					l += 3;
					p[6]  = 0x80;
					p[7]  = 0x00;
					p[8]  = 0x00;
				} // if
				p[4] = l / 256;
				p[5] = l & 0xFF;
				Length = l + 6;
				lastLength = Length;
				lastData = p;
				return p;
			} else {
				Length = PesLength(data);
				if (Length <= length) {
					offset = Length; // to make sure we break out in case of garbage data
					lastLength = Length;
					lastData = data;
					return data;
				} // if
			} // if
		} // if
		return NULL;
	} // GetPes
	void SetRepeatLast(void) {
		repeatLast = true;
	} // SetRepeatLast
	void Reset(void) {
		length = offset = 0;
		lastData = NULL;
		lastLength = 0;
		repeatLast = false;
	} // Reset
}; // cTsToPes

/////////////////////////////////////////////////////////////////////////////////////
// TRANSCODE

class cTranscode { 
	class cHandler {
	public:
		cHandler() {
			owner = NULL;
			new_seg = true;
			pid = type = 0;
			port = ISMD_PORT_HANDLE_INVALID;
			auddec_handle = audenc_handle = viddec_handle = pproc_handle = videnc_handle = ISMD_DEV_HANDLE_INVALID;
			aud_proc = AUDIO_INVALID_HANDLE;
		}; // cHandler
		~cHandler() {
			destroyPipeline();
		} // ~cHandler
		void setOwner(cTranscode *Owner) {
			owner = Owner;
		} // setOwner
		bool createVideoPipeline(int Pid, int Type, int Bitrate, int Width, int Height, int Flags) {
			if(!owner) return false;
			if(pid) destroyPipeline();
			new_seg = true;
			pid  = Pid;
			type = Type;
			ismd_result_t ret = ISMD_SUCCESS;
			ismd_port_handle_t input  = ISMD_PORT_HANDLE_INVALID;
			ismd_port_handle_t output = ISMD_PORT_HANDLE_INVALID;
			ismd_mux_input_stream_config_t mux_config = {
					stream_mode: ISMD_MUX_INPUT_MODE_ES, 
					stream_type: ISMD_MUX_STREAM_TYPE_VIDEO_H264, 
					ts_offset  : 135000, 
					descriptors: ISMD_BUFFER_HANDLE_INVALID, 
					event      : ISMD_EVENT_HANDLE_INVALID, 
					event_mask : ISMD_MUX_INPUT_STREAM_EVENT_NONE, 
					flags      : ISMD_MUX_STREAM_NO_FLAGS};
			ismd_mux_pid_t mux_pid = Pid;
			ismd_videnc_stream_init_params_t init_params = {
					max_frame_width :1920, 
					max_frame_height:1080, 
					scene_change_control:{
							scene_change_detect_enabled: false, 
							lookahead_count            : 0}};
			ismd_videnc_codec_init_params_t codec_params = {
					h264_init_params:{
						profile: H264_PROFILE(Flags),
						level  : H264_LEVEL(Flags)}};
			PRINT("Baseline 3.0\n");
			ismd_videnc_h264_encoder_params_t enc_params;
			ismd_videnc_per_input_encoding_policies_t policies;
			bool reuse;
			if(!Pid) return false;
			if(ISMD_PORT_HANDLE_INVALID != port) destroyPipeline();
			PRINT("Convert VIDEO pid 0x%04X %s (BR %d) %dx%d\n", Pid, CODEC_TYPE_STR(Type), Bitrate, Width, Height);
			// VIDDEC
			SMDCHECK_CLEANUP(ismd_viddec_open((ismd_codec_type_t)Type, &viddec_handle));
			SMDCHECK_CLEANUP(ismd_viddec_set_pts_interpolation_policy(viddec_handle, ISMD_VIDDEC_INTERPOLATE_MISSING_PTS, ISMD_NO_PTS));
			SMDCHECK_CLEANUP(ismd_viddec_set_max_frames_to_decode(viddec_handle, ISMD_VIDDEC_ALL_FRAMES));
			SMDCHECK_CLEANUP(ismd_viddec_set_frame_error_policy(viddec_handle, ISMD_VIDDEC_EMIT_ALL));
			SMDCHECK_CLEANUP(ismd_viddec_enable_output_scaling(viddec_handle, ISMD_VIDDEC_HALF_HORIZONTAL));
			SMDCHECK_CLEANUP(ismd_viddec_enable_override_frame_polarity(viddec_handle));
			SMDCHECK_CLEANUP(ismd_dev_set_state(viddec_handle, ISMD_DEV_STATE_STOP));
			//PPROC
			SMDCHECK_CLEANUP(ismd_vidpproc_open(&pproc_handle));
			SMDCHECK_CLEANUP(ismd_vidpproc_deringing_disable(pproc_handle));
			SMDCHECK_CLEANUP(ismd_vidpproc_set_parameter(pproc_handle, PAR_HSC_COEFF_IDXSHIFT_Y, 0));
			SMDCHECK_CLEANUP(ismd_vidpproc_set_parameter(pproc_handle, PAR_HSC_COEFF_IDXSHIFT_UV, 0));
			SMDCHECK_CLEANUP(ismd_vidpproc_set_parameter(pproc_handle, PAR_VSC_COEFF_IDXSHIFT_Y, 0));
			SMDCHECK_CLEANUP(ismd_vidpproc_set_parameter(pproc_handle, PAR_VSC_COEFF_IDXSHIFT_UV, 0));
			SMDCHECK_CLEANUP(ismd_vidpproc_gaussian_enable(pproc_handle));
			SMDCHECK_CLEANUP(ismd_vidpproc_pan_scan_enable(pproc_handle));
			SMDCHECK_CLEANUP(ismd_vidpproc_set_scaling_policy(pproc_handle, ZOOM_TO_FIT/*SCALE_TO_FIT*/) );
			SMDCHECK_CLEANUP(ismd_vidpproc_set_dest_params2(pproc_handle, Width, Height, 16, (9*Width)/Height, 0, 0)); // We always want 16:9 output
			//VIDENC
			SMDCHECK_CLEANUP(ismd_videnc_open(ISMD_CODEC_TYPE_H264, &init_params, &codec_params, &videnc_handle));
			SMDCHECK_CLEANUP(ismd_videnc_h264_get_encoding_params(videnc_handle, &enc_params));
			enc_params.bitrate_settings.bitrate = Bitrate;
			enc_params.bitrate_settings.bitrate_mode = ISMD_VIDENC_H264_RATE_CONTROL_VBR/*ISMD_VIDENC_H264_RATE_CONTROL_CBR*/;
			enc_params.bitrate_settings.max_bitrate = Bitrate;
			//enc_params.gop_settings.GOP_length = 24;
			//enc_params.gop_settings.num_of_B_frames = 2;
			//enc_params.gop_settings.IDR_Frequency = 1;
			enc_params.entropy = ISMD_VIDENC_H264_ENTROPY_MODE_CAVLC;
			enc_params.aspect_ratio = ISMD_VIDENC_H264_ASPECT_RATIO_16_9; // We always want 16:9 output //AUTO/*ISMD_VIDENC_H264_ASPECT_RATIO_SAME_AS_INPUT*/;
			//enc_params.chroma_format = ISMD_VIDENC_H264_CHROMA_FORMAT_4_2_0;
			SMDCHECK_CLEANUP(ismd_videnc_h264_set_encoding_params(videnc_handle, &enc_params));
			SMDCHECK_CLEANUP(ismd_videnc_get_reuse_input_end_sequence(videnc_handle, &reuse));
			//reuse = false;
			SMDCHECK_CLEANUP(ismd_videnc_set_reuse_input_end_sequence(videnc_handle, reuse));
			SMDCHECK_CLEANUP(ismd_videnc_get_per_input_encoding_policies(videnc_handle, &policies));
	//		policies.deinterlaced_input_encoding_scan_mode = ISMD_VIDENC_SCAN_MODE_ENCODE_PROGRESSIVE;
	//		policies.deinterlaced_input_flags              = ISMD_VIDENC_INPUT_DEINTERLACED_FLAGS_NONE;
	//		policies.interlaced_input_encoding_scan_mode   = ISMD_VIDENC_SCAN_MODE_ENCODE_PROGRESSIVE;
	//		policies.interlaced_input_flags                = ISMD_VIDENC_INPUT_DEINTERLACED_FLAGS_NONE;
			policies.progressive_input_flags               = ISMD_VIDENC_INPUT_PROGRESSIVE_FLAGS_HALVE_FRAME_RATE;
	//		policies.progressive_input_flags               = ISMD_VIDENC_INPUT_PROGRESSIVE_FLAGS_NONE;
			SMDCHECK_CLEANUP(ismd_videnc_set_per_input_encoding_policies(videnc_handle, &policies));
			// CONNECT
			SMDCHECK_CLEANUP(ismd_viddec_get_input_port(viddec_handle, &port));
			SMDCHECK_CLEANUP(ismd_viddec_get_output_port(viddec_handle, &output));
			SMDCHECK_CLEANUP(ismd_vidpproc_get_input_port(pproc_handle, &input));
			SMDCHECK_CLEANUP(ismd_port_connect(output, input));
			SMDCHECK_CLEANUP(ismd_vidpproc_get_output_port(pproc_handle, &output));
			SMDCHECK_CLEANUP(ismd_videnc_get_input_port(videnc_handle, &input));
			SMDCHECK_CLEANUP(ismd_port_connect(output, input));
			SMDCHECK_CLEANUP(ismd_videnc_get_output_port(videnc_handle, &output));
			SMDCHECK_CLEANUP(ismd_mux_add_input(owner->mux_handle, &mux_config, &mux_pid, &input));
			SMDCHECK_CLEANUP(ismd_port_connect(output, input));
			// START
			SMDCHECK_CLEANUP(ismd_dev_set_state(viddec_handle, ISMD_DEV_STATE_PLAY));
			SMDCHECK_CLEANUP(ismd_dev_set_state(pproc_handle, ISMD_DEV_STATE_PLAY));
			SMDCHECK_CLEANUP(ismd_dev_set_state(videnc_handle, ISMD_DEV_STATE_PLAY));
			return true;
		cleanup:
			destroyPipeline();
			return false;
		} // createVideoPipeline
		bool createAudioPipeline(int Pid, int Type, int Bitrate) {
			if(!owner) return false;
			if(pid) destroyPipeline();
			new_seg = true;
			pid  = Pid;
			type = Type;
			ismd_result_t ret = ISMD_SUCCESS;
			ismd_port_handle_t input  = ISMD_PORT_HANDLE_INVALID;
			ismd_port_handle_t output = ISMD_PORT_HANDLE_INVALID;
			ismd_mux_input_stream_config_t mux_config = {
					stream_mode: ISMD_MUX_INPUT_MODE_ES, 
					stream_type: ISMD_MUX_STREAM_TYPE_AUDIO_MPEG2_AAC,
					ts_offset  : 45000, 
					descriptors: ISMD_BUFFER_HANDLE_INVALID, 
					event      : ISMD_EVENT_HANDLE_INVALID, 
					event_mask : ISMD_MUX_INPUT_STREAM_EVENT_NONE, 
					flags      : ISMD_MUX_STREAM_NO_FLAGS};
			ismd_mux_pid_t mux_pid = Pid;
			ismd_audio_decoder_param_mapper_t *param = NULL;
			ismd_audio_decoder_param_t enc_param;
			ismd_audio_output_config_t config = {
					stream_delay: 0, 
					sample_size : 16, 
					ch_config   : ISMD_AUDIO_STEREO,
					out_mode    : ISMD_AUDIO_OUTPUT_ENCODED_AAC, 
					sample_rate : 48000, 
					ch_map      : 0};
			if(!Pid) return false;
			if(ISMD_PORT_HANDLE_INVALID != port) destroyPipeline();
			PRINT("Convert audio pid 0x%04X %s (BR %d)\n", Pid, AUDIO_MEDIA_FMT_STR(Type), Bitrate);
			SMDCHECK_CLEANUP(ismd_audio_open_processor(&aud_proc));
			SMDCHECK_CLEANUP(ismd_audio_add_input_port(aud_proc, false, &auddec_handle, &port));
			SMDCHECK_CLEANUP(ismd_audio_input_set_data_format(aud_proc, auddec_handle, (ismd_audio_format_t)Type));
//			SMDCHECK_CLEANUP(ismd_audio_input_get_notification_event(pipe->audio_processor, pipe->audio_input_handle, ISMD_AUDIO_NOTIFY_STREAM_END, &pipe->audio_eos_event) );
			SMDCHECK_CLEANUP(ismd_audio_mute(aud_proc, false) );
			SMDCHECK_CLEANUP(ismd_audio_add_output_port(aud_proc, config, &audenc_handle, &output));
			SMDCHECK_CLEANUP(ismd_audio_output_enable(aud_proc, audenc_handle));
			param = (ismd_audio_decoder_param_mapper_t *)&enc_param;
			param->param = 2;  //output_context->enc_params.aac_enc_params.num_input_ch;
			SMDCHECK_CLEANUP(ismd_audio_output_set_encode_params(aud_proc, ISMD_AUDIO_AAC_ENC_NUM_INPUT_CH, &enc_param));
			param->param  = Bitrate; //output_context->enc_params.aac_enc_params.data_rate;
			SMDCHECK_CLEANUP(ismd_audio_output_set_encode_params(aud_proc, ISMD_AUDIO_AAC_ENC_DATA_RATE, &enc_param ) );
      param->param  = 2; // output_context->enc_params.aac_enc_params.quality_level;
			SMDCHECK_CLEANUP(ismd_audio_output_set_encode_params(aud_proc, ISMD_AUDIO_AAC_ENC_QUALITY_LEVEL, &enc_param ) );
      param->param  = 0; // output_context->enc_params.aac_enc_params.encode_mode;
			SMDCHECK_CLEANUP(ismd_audio_output_set_encode_params(aud_proc, ISMD_AUDIO_AAC_ENC_ENCODE_MODE, &enc_param ) );
			SMDCHECK_CLEANUP(ismd_mux_add_input(owner->mux_handle, &mux_config, &mux_pid, &input));
			// CONNECT
			SMDCHECK_CLEANUP(ismd_port_connect(output, input));
			// START
			SMDCHECK_CLEANUP(ismd_dev_set_state(auddec_handle, ISMD_DEV_STATE_PLAY));
//			SMDCHECK_CLEANUP(ismd_dev_set_state(audenc_handle, ISMD_DEV_STATE_PLAY));
			return true;
		cleanup:
			destroyPipeline();
			return false;
		} // createAudioPipeline
		bool createPassthrouPipeline(int Pid, int Type) {
			if(!owner) return false;
			if(pid) destroyPipeline();
			pid  = Pid;
			type = Type;
			ismd_result_t ret = ISMD_SUCCESS;
			ismd_mux_input_stream_config_t mux_config = {
					stream_mode: ISMD_MUX_INPUT_MODE_ES, 
					stream_type: (ismd_mux_input_stream_type_t)Type,
					ts_offset  : 45000, 
					descriptors: ISMD_BUFFER_HANDLE_INVALID, 
					event      : ISMD_EVENT_HANDLE_INVALID, 
					event_mask : ISMD_MUX_INPUT_STREAM_EVENT_NONE, 
					flags      : ISMD_MUX_STREAM_NO_FLAGS};
			ismd_mux_pid_t mux_pid = Pid;
			if(!Pid) return false;
			if(ISMD_PORT_HANDLE_INVALID != port) destroyPipeline();
			PRINT("Passthrou pid 0x%04X %s\n", Pid, STREAM_TYPE_STR(Type));
			SMDCHECK_CLEANUP(ismd_mux_add_input(owner->mux_handle, &mux_config, &mux_pid, &port));
			return true;
		cleanup:
			destroyPipeline();
			return false;
		} // createPassthrouPipeline
		void destroyPipeline() {
			ismd_result_t ret = ISMD_SUCCESS;
			// VIDEO
			if(ISMD_DEV_HANDLE_INVALID != viddec_handle) SMDCHECK(ismd_dev_close(viddec_handle));
			viddec_handle = ISMD_DEV_HANDLE_INVALID;
			if(ISMD_DEV_HANDLE_INVALID != pproc_handle) SMDCHECK(ismd_dev_close(pproc_handle));
			pproc_handle = ISMD_DEV_HANDLE_INVALID;
			if(ISMD_DEV_HANDLE_INVALID != videnc_handle) SMDCHECK(ismd_dev_close(videnc_handle));
			videnc_handle = ISMD_DEV_HANDLE_INVALID;
			// AUDIO
			if(ISMD_DEV_HANDLE_INVALID != auddec_handle) SMDCHECK(ismd_audio_remove_input(aud_proc, auddec_handle));
			auddec_handle = ISMD_DEV_HANDLE_INVALID;
			if(ISMD_DEV_HANDLE_INVALID != audenc_handle) SMDCHECK(ismd_audio_remove_output(aud_proc, audenc_handle));
			audenc_handle = ISMD_DEV_HANDLE_INVALID;
			if(AUDIO_INVALID_HANDLE != aud_proc) ismd_audio_close_processor(aud_proc);
			aud_proc = AUDIO_INVALID_HANDLE;
			// BOTH
			if(owner && (ISMD_PORT_HANDLE_INVALID != port)) {
				PRINT("REMOVE 0x%04X\n", pid);
				SMDCHECK(ismd_mux_remove_input(owner->mux_handle, pid));
				port = ISMD_PORT_HANDLE_INVALID;
			} // if
			pid = type = 0;
		} // destroyPipeline
		bool writeTs(unsigned char *Data) {
			if(!pid || (ISMD_PORT_HANDLE_INVALID == port)) return true;
			if (TsPayloadStart(Data)) {
				int l;
				while (const unsigned char *p = toPes.GetPes(l)) {
					if(!writePort(port, p, l, VID_CHUNK_SIZE)) {
						toPes.SetRepeatLast();
						return false;
					} // if
				} // while
				toPes.Reset();
			} // if
			toPes.PutTs(Data, TS_SIZE);
			return true;
		} // writeTs
	protected:
		cTranscode *owner;
		int pid;
		int type;
		cTsToPes toPes;
		ismd_port_handle_t port;
		ismd_dev_t viddec_handle, pproc_handle, videnc_handle, auddec_handle, audenc_handle;
		ismd_audio_processor_t aud_proc;
		bool new_seg;
		bool writePort(ismd_port_handle_t port, const unsigned char *data, int size, int chunk_size) {
			if(ISMD_PORT_HANDLE_INVALID == port) return true;
			if(size <= 0) return true;
			ismd_result_t ret = ISMD_SUCCESS;
			ismd_port_status_t status;
			bool write_new_seg = false;
			SMDCHECK_IGN(ISMD_INVALID_HANDLE, ismd_port_get_status(port, &status));
			if(ISMD_SUCCESS != ret) return true;
			int written = 0;
			ismd_es_buf_attr_t attr;
			attr.local_pts = attr.original_pts = ISMD_NO_PTS;
			attr.original_dts = ISMD_NO_DTS;
			attr.discontinuity = attr.pvt_data_valid = attr.au_start = false;
			attr.discontinuity = false;
			ismd_es_buf_attr_t *attr_ptr = &attr;
			if((size >= 9) && !data[0] && !data[1] && (data[2]==1)) { // We have to strip pes header
				switch(data[3]) {
					case 0xBD:
					case 0xC0 ... 0xDF:
					case 0xE0 ... 0xEF: {
						switch(data[7]&0xC0) {
							case 0x80:
								if(size >= 9+5) {
									if(data[8]>=5) {
										attr.local_pts = attr.original_pts = pts_val(0x2, &data[9]);
									} else
										PRINT("PES header to small %02x-%02x %d %d", data[3], data[7], data[8], size);
								} else
									PRINT("PES to small %02x %d", data[3], size);
								break;
							case 0xC0:
								if(size >= 9+5) {
									if(data[8]>=10) {
										attr.local_pts = attr.original_pts = pts_val(0x3, &data[9]);
										attr.original_dts = pts_val(0x1, &data[9+5]);
									} else
										PRINT("PES header to small %02x-%02x %d %d", data[3], data[7], data[8], size);
								} else
									PRINT("PES to small %02x %d", data[3], size);
								break;
							default:
								break;
						} // switch
						written = data[8]+9;
						break;
					} // case
				} // switch
			} // if
			if(new_seg && (ISMD_NO_PTS != attr.original_pts))
				write_new_seg = true;
			int retry = PORT_WRITE_RETRY_COUNT;
			while(size > written) {
				int len = write_chunk(port, chunk_size, &data[written], size-written, attr_ptr, write_new_seg);
				if(!len) {
					if(attr_ptr) return false;  // We haven't written something yet
					if(!retry--) break; // Give up
					os_sleep(PORT_WRITE_RETRY_DELAY);
					continue;
				} // if
				if(write_new_seg) new_seg = false;
				write_new_seg = false;
				written += len;
				attr_ptr = NULL;
				retry = PORT_WRITE_RETRY_COUNT;
			} // while
			return attr_ptr ? false : true;
		} // writePort
	}; // cHandler 
public:
	cTranscode(int source_fd, int target_fd, int vid_bitrate, int aud_bitrate, int vid_width, int vid_height, int vid_flags, int aud_flags) : vidBitRate(vid_bitrate), audBitRate(aud_bitrate), vidWidth(vid_width), vidHeight(vid_height), vidFlags(vid_flags), audFlags(aud_flags), source (source_fd), target(target_fd) {
			terminate = eos = true;
			pmtSize = 0; 
			patVersion = pmtVersion = -1;
		for(int i=0; i<MAX_PIDS; i++)
			handler[i].setOwner(this);
		mux_out = ISMD_PORT_HANDLE_INVALID;
		ismd_result_t ret = ISMD_SUCCESS;
		SMDCHECK(ismd_mux_open(&mux_handle, ISMD_MUX_TYPE_MPEG_TS_188));
		if(ISMD_SUCCESS == ret) SMDCHECK(ismd_mux_get_output_port(mux_handle, &mux_out));
		if(ISMD_SUCCESS == ret) {
			terminate = eos = false;
			os_thread_create(&input_thread_handle, input_thread_fn, this, 0, 0, (char *)"cTranscode_input_thread");
		} // if
	} // cTranscode
	~cTranscode() {
		if(!terminate) {
			terminate = true;
			os_thread_wait(&input_thread_handle, 1);
		} // if
		ismd_result_t ret = ISMD_SUCCESS;
		SMDCHECK(ismd_dev_set_state(mux_handle, ISMD_DEV_STATE_STOP));
		for(int i=0; i<MAX_PIDS; i++)
			handler[i].destroyPipeline();
		if(ISMD_DEV_HANDLE_INVALID != mux_handle) SMDCHECK(ismd_dev_close(mux_handle));
		mux_handle = ISMD_DEV_HANDLE_INVALID;
	} // ~cTranscode
	virtual bool process() {
		ismd_result_t ret = ISMD_SUCCESS;
		if(terminate) return false;
		while(!terminate) {
			ismd_port_status_t status;
			SMDCHECK(ismd_port_get_status(mux_out, &status));
			if(status.cur_depth) {
				ismd_buffer_handle_t buffer;
				ismd_buffer_descriptor_t buffer_desc;
				SMDCHECK(ismd_port_read(mux_out, &buffer));
				SMDCHECK(ismd_buffer_read_desc(buffer, &buffer_desc));
				int retry = 0;
				int total = 0;
				while(retry < 100) {
					unsigned char *buff_ptr = (unsigned char *)OS_MAP_IO_TO_MEM_CACHE(buffer_desc.phys.base, buffer_desc.phys.size);
					if(buff_ptr) {
						int len = write(target, &buff_ptr[total], buffer_desc.phys.level-total);
						if(len > 0) {
							retry = 0;
							total += len;
							PRINT("."); FLUSH();
						} // if
						OS_UNMAP_IO_FROM_MEM(buff_ptr, buffer_desc.phys.size);
					} else PRINT("Failed to get buffer ptr %d\n", buffer_desc.phys.size);
					if(total == buffer_desc.phys.level)
						break;
					os_sleep(100);
					retry++;
				} // while
				if(total != buffer_desc.phys.level)
					PRINT("Unable to write pending data. Skipped %d bytes\n", buffer_desc.phys.level - total);
				SMDCHECK(ismd_buffer_dereference(buffer));
			} else if(eos)
				terminate = true;
			else
				os_sleep(100);
		} // while
		return true;
	} // process
protected:
	bool terminate, eos;
	int pmtSize;
	int pmtPid;
	int patVersion, pmtVersion;
	int vidBitRate, audBitRate;
	int vidWidth, vidHeight, vidFlags;
	int audFlags;
	unsigned char pmt[MAX_SECTION_SIZE];
	os_thread_t input_thread_handle;
	int source, target;
	ismd_dev_t mux_handle;
	ismd_port_handle_t mux_out;
	cHandler handler[MAX_PIDS];
protected:
	static void *input_thread_fn(void *param) {
		if(!param) return NULL;
		cTranscode *owner = (cTranscode *)param;
		int count = 0;
		unsigned char buffer_data[READ_BUFFER_SIZE];
		while(!owner->terminate) {
			int readc = read(owner->source, &buffer_data[count], sizeof(buffer_data)-count);
			static int total = 0;
			if(readc > 0) {
				count += readc;
				owner->eos = false;
			} else {
				if(readc) PRINT("cTranscode::input_thread_fn FAILED TO READ %d/%d@%d %d\n", readc, sizeof(buffer_data)-count, total, errno); 
				if(!owner->eos) PRINT("cTranscode::input_thread_fn EOS @ %d\n", total);
				owner->eos = true;
				os_sleep(100);
			} // if 
			if(readc > 0) total += readc;
			unsigned char *data = buffer_data;
			while(!owner->terminate && (count > TS_SIZE)) {
				if(data[0] != TS_SYNC_BYTE) {
					data++; count--;
					continue;
				} // if
				int Pid = TsPid(data);
				if (Pid == 0) {
					owner->parsePat(data);
				} else if (Pid == owner->pmtPid) {
					owner->parsePmt(data);
				} else if(!owner->handler[Pid].writeTs(data)) {
					os_sleep(PORT_WRITE_FAIL_DELAY);
					continue;
				} // if
				count -= TS_SIZE;
				data  += TS_SIZE;
			} // while
			if(count) memcpy(buffer_data, data, count);
		} // while
		return NULL;
	} // thread_fn
	bool parsePat(unsigned char *Data) {
		int PayloadOffset = TsPayloadOffset(Data);
		Data += PayloadOffset;
		int Length = TS_SIZE - PayloadOffset;
		if ((Length -= Data[0] + 1) <= 0)
			return false;
		Data += Data[0] + 1; // process pointer_field
		SI::PAT Pat(Data, false);
		if (!Pat.CheckCRCAndParse()) {
			PRINT("ERROR: can't parse PAT");
			return false;
		} // if
		if (patVersion == Pat.getVersionNumber())
			return false;
//PRINT("cTranscode::parsePat NewPAT: TSid = %d, c/n = %d, v = %d, s = %d, ls = %d\n", Pat.getTransportStreamId(), Pat.getCurrentNextIndicator(), Pat.getVersionNumber(), Pat.getSectionNumber(), Pat.getLastSectionNumber());
		SI::PAT::Association assoc;
		for (SI::Loop::Iterator it; Pat.associationLoop.getNext(assoc, it); ) {
//PRINT("                         isNITPid = %d\n", assoc.isNITPid());
			if (!assoc.isNITPid()) {
				pmtPid = assoc.getPid();
//PRINT("                         service id = %d, pid = %d\n", assoc.getServiceId(), assoc.getPid());
			} // if
		} // for
		patVersion = Pat.getVersionNumber();
		return true;
	} // parsePat
	bool parsePmt(unsigned char *Data) {
		ismd_result_t ret = ISMD_SUCCESS;
		int PayloadOffset = TsPayloadOffset(Data);
		bool PayLoadStart = TsPayloadStart(Data);
		Data += PayloadOffset;
		int Length = TS_SIZE - PayloadOffset;
		if (PayLoadStart) {
			pmtSize = 0;
			if ((Length -= Data[0] + 1) <= 0)
				return false;
			Data += Data[0] + 1;
			if (TS_SECTION_LENGTH(Data, Length) > Length) {
				if (Length <= int(sizeof(pmt))) {
					memcpy(pmt, Data, Length);
					pmtSize = Length;
				}	else
					PRINT("ERROR: PMT packet length too big (%d byte)!\n", Length);
				return false;
			} // if
		} else if (pmtSize > 0) {
			if (Length <= int(sizeof(pmt)) - pmtSize) {
				memcpy(pmt + pmtSize, Data, Length);
				pmtSize += Length;
			}	else {
				PRINT("ERROR: PMT section length too big (%d byte)!\n", pmtSize + Length);
				pmtSize = 0;
			} // if
			if (TS_SECTION_LENGTH(pmt, pmtSize) > pmtSize)
				return false;
			Data = pmt;
		}	else
			return false;
		SI::PMT Pmt(Data, false);
		if (!Pmt.CheckCRCAndParse()) {
			PRINT("ERROR: can't parse PMT\n");
			pmtSize = 0;
			return false;
		} // if
		if (pmtVersion == Pmt.getVersionNumber())
			return false;
//		PRINT("cTranscode::parsePmt NewPMT: sid = %d, c/n = %d, v = %d, s = %d, ls = %d\n", Pmt.getServiceId(), Pmt.getCurrentNextIndicator(), Pmt.getVersionNumber(), Pmt.getSectionNumber(), Pmt.getLastSectionNumber());
//		PRINT("                         pcr = 0x%04X\n", Pmt.getPCRPid());
		ismd_mux_stream_params_t mux_params;
		SMDCHECK(ismd_dev_set_state(mux_handle, ISMD_DEV_STATE_STOP));
		SMDCHECK(ismd_mux_get_stream_params(mux_handle, &mux_params));
		mux_params.scheduling_mode = ISMD_MUX_SCHEDULING_MODE_BACKGROUND;
		mux_params.ts_params.transport_stream_id = 0;
		mux_params.ts_params.pat_interval = 22500;
		mux_params.ts_params.program_params.program_num = 1;
		mux_params.ts_params.program_params.pmt_interval = 22500;
		mux_params.ts_params.program_params.pcr_interval = 4500;
		mux_params.ts_params.program_params.pmt_pid = pmtPid;
		mux_params.ts_params.program_params.bitrate = 0;
//		mux_params.ts_params.program_params.descriptors = ISMD_BUFFER_HANDLE_INVALID;
//		mux_params.ts_params.program_params.flags = 0;
		SMDCHECK(ismd_mux_set_stream_params(mux_handle, &mux_params));
		for(int i=0; i<MAX_PIDS; i++)
			handler[i].destroyPipeline();
		SI::PMT::Stream stream;
		for (SI::Loop::Iterator it; Pmt.streamLoop.getNext(stream, it); ) {
//			PRINT("     stream pid = 0x%04X, type = 0x%02X %s\n", stream.getPid(), stream.getStreamType(), STREAM_TYPE_STR(stream.getStreamType()));
			switch (stream.getStreamType()) {
				case 0x01:
				case 0x02:
					handler[stream.getPid()].createVideoPipeline(stream.getPid(), ISMD_CODEC_TYPE_MPEG2, vidBitRate, vidWidth, vidHeight, vidFlags);
					SMDCHECK(ismd_mux_set_pcr_pid(mux_handle, Pmt.getPCRPid()));
					break;
				case 0x1B:
					handler[stream.getPid()].createVideoPipeline(stream.getPid(), ISMD_CODEC_TYPE_H264, vidBitRate, vidWidth, vidHeight, vidFlags);
					SMDCHECK(ismd_mux_set_pcr_pid(mux_handle, Pmt.getPCRPid()));
					break;
				case 0x03: // STREAMTYPE_11172_AUDIO
				case 0x04: // STREAMTYPE_13818_AUDIO
				case 0x0F: // ISO/IEC 13818-7 Audio with ADTS transport sytax
				case 0x11: // ISO/IEC 14496-3 Audio with LATM transport syntax
					if(!(audFlags & AUDIO_FLAG_PID_MASK) || ((audFlags & AUDIO_FLAG_PID_MASK) == stream.getPid())) {
						if(audFlags & AUDIO_FLAG_CONVERT_MPA)
							handler[stream.getPid()].createAudioPipeline(stream.getPid(), ISMD_AUDIO_MEDIA_FMT_MPEG, audBitRate);
						else
							handler[stream.getPid()].createPassthrouPipeline(stream.getPid(), stream.getStreamType());
					} // if
					break;
				case 0x06: { // STREAMTYPE_13818_PES_PRIVATE
					SI::Descriptor *d;
					for (SI::Loop::Iterator it; (d = stream.streamDescriptors.getNext(it)); ) {
//						PRINT("         sub type = 0x%02X\n", d->getDescriptorTag());
						switch (d->getDescriptorTag()) {
							case SI::AC3DescriptorTag:
							case SI::EnhancedAC3DescriptorTag:
								if(!(audFlags & AUDIO_FLAG_PID_MASK) || ((audFlags & AUDIO_FLAG_PID_MASK) == stream.getPid())) {
									if(audFlags & AUDIO_FLAG_CONVERT_AC3)
										handler[stream.getPid()].createAudioPipeline(stream.getPid(), ISMD_AUDIO_MEDIA_FMT_DD, audBitRate);
									else
										handler[stream.getPid()].createPassthrouPipeline(stream.getPid(), ISMD_MUX_STREAM_TYPE_AUDIO_AC3_DDP);
								} // if
								break;
							default: ;
						} // switch
					} // for
					break;
				} // case
				default: ;
			} // switch
		} // for
		pmtVersion = Pmt.getVersionNumber();
		pmtSize = 0;
		SMDCHECK(ismd_dev_set_state(mux_handle, ISMD_DEV_STATE_PLAY));
		return true;
	} // parsePmt
}; // cTranscode

/////////////////////////////////////////////////////////////////////////////////////
// USAGE

int usage(char *prog, int ret) {
	PRINT("transcode v 1.0 (c) Reel Multimedia\n");
	PRINT("usage: %s [options]\n", prog);
	PRINT("options:\n");
	PRINT("   -h        show usage\n");
	PRINT("   -f file   specify output file\n");
	PRINT("   -v value  video bitrate\n");
	PRINT("   -a value  audio bitrate\n");
	PRINT("   -r value  video resolution\n");
	PRINT("   -p value  only transcode this audio pid\n");
	PRINT("   -m        convert mpa to aac     (default is passthrou)\n");
	PRINT("   -d        convert dd(ac3) to aac (default is passthrou)\n");
	return ret;
} // usage

/////////////////////////////////////////////////////////////////////////////////////
// MAIN

int main(int argc, char **argv) {
	int video_bitrate = 0;
	int audio_bitrate = 0;
	int video_width   = 0;
	int video_height  = 0;
	int video_flags   = 0;
	int audio_flags   = 0;
	int source_fd = STDIN_FILENO;
	int target_fd = STDOUT_FILENO;
	char *target_file_name = NULL;
	char *video_resolution = NULL;
	int opt = -1;
	while((opt = getopt(argc, argv, "hf:v:a:r:p:dm")) != -1) {
		switch(opt) {
			case 'h': return usage(argv[0], 0);
			case 'f': target_file_name = optarg; break;
			case 'v': video_bitrate = atoi(optarg); break;
			case 'a': audio_bitrate = atoi(optarg); break;
			case 'r': video_resolution = optarg; break;
			case 'p': audio_flags = (audio_flags & !AUDIO_FLAG_PID_MASK) | (atoi(optarg) & AUDIO_FLAG_PID_MASK); break;
			case 'd': audio_flags |= AUDIO_FLAG_CONVERT_AC3; break;
			case 'm': audio_flags |= AUDIO_FLAG_CONVERT_MPA; break;
			case '?': return usage(argv[0], -1);
			default : break;
		} // switch
	} // while
	if(video_resolution) {
		if(!strcmp(video_resolution, "HSD")) {
			video_width  = 360;
			video_height = 576;
		} else if(!strcmp(video_resolution, "QSD")) {
			video_width  = 360;
			video_height = 288;
		} else if(!strcmp(video_resolution, "720")) {
			video_width  = 1280;
			video_height = 720;
		} else if(!strcmp(video_resolution, "1080")) {
			video_width  = 1920;
			video_height = 1080;
		} else if(!strcmp(video_resolution, "IPHONE")) {
			video_width  = 480;
			video_height = 320;
			video_flags |= VIDEO_FLAG_PROFILE_BASELINE | VIDEO_FLAG_IPHONE_LEVEL_3_0;
		} else if(!strcmp(video_resolution, "IPAD")) {
			video_width  = 1024;
			video_height = 768;
			video_flags |= VIDEO_FLAG_PROFILE_MAIN | VIDEO_FLAG_IPHONE_LEVEL_3_1;
		} else
			PRINT("Unknown video resolution \"%s\"\n", video_resolution);
	} // if
	if((video_width <=0) || (video_height <= 0)) {
			video_width  = 720;
			video_height = 576;
	} // if
	int ret = 0;
	if(target_file_name != NULL) {
		target_fd = open(target_file_name, O_CREAT|O_WRONLY|O_TRUNC, S_IWUSR|S_IRUSR|S_IRGRP|S_IROTH);
		if(-1 == target_fd) {
			PRINT("Failed to open target file \"%s\"\n", target_file_name);
			ret = -2;
		} // if
	} // if
	if(video_bitrate <= 0) video_bitrate = 2400000;
	if(audio_bitrate <= 0) audio_bitrate = 64000;
#if 0
PRINT("testing ismd_demux_stream_open\n");
ismd_dev_t demux_handle;
ismd_port_handle_t demux_port;
ismd_demux_stream_open(ISMD_DEMUX_STREAM_TYPE_MPEG2_TRANSPORT_STREAM, &demux_handle, &demux_port);
PRINT("testing ismd_demux_stream_open SUCCESS\n");
#endif
	if(!ret) {
		cTranscode input(source_fd, target_fd, video_bitrate, audio_bitrate, video_width, video_height, video_flags, audio_flags);
		struct timeval start, end;
		gettimeofday(&start, NULL);
		if(input.process()) {
			gettimeofday(&end, NULL);
			uint64_t dur = ((uint64_t)  end.tv_sec * (uint64_t)1000000 + (uint64_t)  end.tv_usec)-
			               ((uint64_t)start.tv_sec * (uint64_t)1000000 + (uint64_t)start.tv_usec);
			PRINT("Conver time %llds\n", dur / 1000000);
		} else	ret = -1;
	} // if
	if((target_file_name != NULL) && (-1 != target_fd)) close(target_fd);
	return ret; 
} // main

