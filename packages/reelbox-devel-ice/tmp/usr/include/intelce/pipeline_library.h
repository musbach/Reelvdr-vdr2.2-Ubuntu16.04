/*
Copyright [2008-2011] Intel Corporation

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/


#ifndef __PIPELINE_LIBRARY_H__
#define __PIPELINE_LIBRARY_H__


/*
   The pipeline library is a pipeline manager meant to be used to simplify
   applications that make use of the ISMD C or gstreamer API.
   It fits into the software stack as follows:
    __________________
   | test application |   The application manages keyboard, buffering,
   |__________________|   PSI, events, and some pipeline configuration
      |    |     |
      \/  \/     |
    ___________  |
   |           | |        The library handles opening handles, connecting
   |pipeline   | |        stages, and some basic default configuration.
   |library    | |        The library can expose the device handles for
   |___________| |        advanced configuration by the application.
     |     |     |
     \/    \/    \/
    _________________
   |  ISMD drivers   |
   |_________________|


   An end-to-end pipe is created by adding devices into a "pipeline" and
   specifying how those get connected.

   This approach makes it easy to add pipeline stages in the future, and easy to
   configure any number of subpipe configurations.

   The pipeline library will allocate and connect all of the devices in the
   pipeline and provide some basic default configuration.  It is up to the
   application to further configure the pipeline to suit its needs.

   Common actions like setting the pipeline state or flushing the pipeline are
   also supported by the pipeline library.

   Since the operations abstracted here match the gstreamer interface we are
   using, the same application can be used to test gstreamer or the C-API - all
   that has to be done is the setting of a flag when creating a new pipeline
   that indicates whether to use gstreamer or the C API.
*/
#include "osal.h"
#include "ismd_core.h"
#include "ismd_demux.h"
#include "ismd_global_defs.h"
#include "ismd_audio_defs.h"
#include "file_device_wrapper.h"
#include "ismd_videnc.h"
#include "ismd_mux.h"
#include "ismd_remux.h"
#include "ismd_vidsink.h"

/////////////////////////////////////
// Exposed Defines
/////////////////////////////////////
#define NUM_PL_PIPES 16
#define PL_MAX_NAME_LENGTH 128


/////////////////////////////////////
// Exposed Data types
/////////////////////////////////////
typedef int pl_pipe_t;
#define PL_PIPE_INVALID (pl_pipe_t)-1

// Defines the type of a pipeline stage
typedef enum {
   PL_TYPE_NONE = 0,

   // SW I/O device types
   PL_TYPE_FILESRC         = FILEDEV_TYPE_SRC,
   PL_TYPE_FILESNK         = FILEDEV_TYPE_SNK,
   PL_TYPE_IMAGE_FILESRC   = FILEDEV_TYPE_IMGSRC,
   PL_TYPE_IMAGE_FILESNK   = FILEDEV_TYPE_IMGSNK,
   PL_TYPE_IMAGE_MEMSNK    = FILEDEV_TYPE_IMGMEMSNK,
   PL_TYPE_UDPSRC          = FILEDEV_TYPE_UDPSRC,

   // HW Input device types
   PL_TYPE_AVCAP_SRC,

   // Capture Device types
   PL_TYPE_AUDCAP_HW,
   PL_TYPE_VIDCAP_HW,

   // Demux types
   PL_TYPE_TSIN_DEMUX,
   PL_TYPE_PS_DEMUX_HW,
   PL_TYPE_TS_DEMUX_HW,
   PL_TYPE_TS192_DEMUX_HW,

   // MVC remux.  Used for 3d blu-ray use case
   PL_TYPE_REMUX,

   // Audio only has one type.
   // Note that ISMD audio is a mini-pipe within itself and is really defined by
   // adding inputs and outputs.
   PL_TYPE_AUDIO_HW,

   // Video decoder (MFD) types - can do multiple codecs.
   PL_TYPE_VIDDEC_HW,

   // Video post-processor types
   PL_TYPE_VID_PPROC_HW,

   // Video encoder type
   PL_TYPE_VIDENC_HW,

   // TSMUX  follows encoder
   PL_TYPE_TSMUX,

   // Video renderer types
   PL_TYPE_VID_REND_HW,

   // Clock types
   PL_TYPE_CLOCK_FREE_RUNNING,
   PL_TYPE_CLOCK_SW_CONTROLLED,

   // Buffering monitor only - not in the datapath
   PL_TYPE_BUFMON,
   //VIDSINK
   PL_TYPE_VIDSINK

} pl_stage_type_t;


// Defines the various handle types
typedef enum {
   PL_HANDLE_TYPE_NONE,       // No handle (filedev inputs/outputs).
   PL_HANDLE_TYPE_ISMD,       // Audio: inputs use this, processors do not
   PL_HANDLE_TYPE_OTHER,      // ports, demux filters, audio processors, clocks
   PL_HANDLE_TYPE_FILEDEV,
} pl_handle_type_t;


// Each pipe stage handle is wrapped with the following structure.
// The structure indicates the handle type along with the handle value.
// This can also be used to wrap input and output handles.
typedef struct {
   char                          name[PL_MAX_NAME_LENGTH];
   pl_stage_type_t               stage_type;
   pl_handle_type_t              handle_type;
   union {
      ismd_dev_handle_t          ismd_handle;
      pl_filedev_t               filedev_handle;
      int                        other_handle;
   };
} pl_handle_wrapper_t;

// for PL_TYPE_VIDENC_HW
typedef struct{
   bool        user_set_interlaced_input_encoding;
   bool        user_set_interlaced_input_flags;
   bool        user_set_progressive_input_encoding;
   bool        user_set_progressive_input_flags;
   bool        user_set_deinterlaced_input_encoding;
   bool        user_set_deinterlaced_input_flags;
} user_set_encoding_policies_t;


typedef struct{
    bool			user_set_aspect_ratio;
	bool			user_set_chroma_format;
	bool			user_set_entropy;
    bool            user_set_bitrate_mode;
	bool			user_set_max_bitrate;
	bool			user_set_bitrate;
	bool			user_set_GOP_length;
	bool			user_set_num_of_B_frames;
	bool			user_set_IDR_Frequency;
    bool            user_set_reuse;
    bool            user_set_scd_threshold;
   user_set_encoding_policies_t   user_set_encoding_policies;
} ismd_videnc_encoding_user_set_params_t;

typedef struct {   
      ismd_videnc_codec_init_params_t           init_params;
      ismd_videnc_stream_init_params_t          stream_params;
	  ismd_videnc_h264_encoder_params_t         videnc_params; 
      bool                                      reuse;
      bool                                      use_sample_ud_rules;
      ismd_videnc_per_input_encoding_policies_t encoding_policies;
	  ismd_videnc_encoding_user_set_params_t	user_set_videnc_params;
      uint32_t                                  scene_change_detect_threshold;
   } videnc_hw_params_t;

 // for PL_TYPE_TSMUX
typedef struct{
   ismd_mux_pid_t					      video_pid;
   ismd_mux_pid_t					      audio_pid;
   ismd_mux_stream_params_t		   mux_stream_params;
   ismd_mux_output_stream_type_t    stream_type;
   ismd_mux_pid_t					      output_pcr_pid;
   bool                             user_ser_pcr_pid;
   ismd_mux_input_stream_config_t   mux_VIDEO_input_stream_config;
   ismd_mux_input_stream_config_t   mux_AUDIO_input_stream_config;
} tsmux_params_t;



// Some devices need parameters at creation time.
// This is a union of the types of parameters for the
// stage types that need them.
typedef union {

   // for PL_TYPE_VIDDEC_HW
   struct {
      ismd_codec_type_t codec_type;
   } viddec_hw_params;

   // for PL_TYPE_TSIN_DEMUX
   struct {
      int nim_number;
   } tsin_hw_params;

   // for PL_TYPE_CLOCK_FREE_RUNNING
   struct {
      bool make_primary;
   } clock_params;

   // for PL_TYPE_AUDIO_HW
   struct {
      bool use_global_processor;
   } audio_hw_params;

   // for PL_TYPE_VIDENC_HW
   videnc_hw_params_t videnc_hw_params;
   
   // for PL_TYPE_TSMUX
   tsmux_params_t tsmux_params;
   
   //for PL_TYPE_VIDSINK
   struct {
      bool bypass_dpe;
   } vidsink_params;

} create_options_t;


// Some devices need parameters to create an input.
// This is a union of the types of parameters for the
// stage types that need them.
typedef union {
   // for PL_TYPE_AUDIO_HW
   struct {
      bool timed_mode;
      bool is_physical; /* true for physical (capture), or false for software */
      int  hw_id;
   } audio_hw_input_params;

  // for PL_TYPE_REMUX
  struct {
     unsigned int view_order_index;
     ismd_remux_view_info_t view_info;
  } remux_input_params;

  // for PL_TYPE_TSMUX
  struct {
    ismd_mux_pid_t					pid;
	ismd_mux_input_stream_config_t	mux_input_stream_config;
  } tsmux_input_params;

} input_options_t;


// Some devices need parameters to create an output.
// This is a union of the types of parameters for the
// stage types that need them.
typedef union {
   // for PL_TYPE_AUDIO_HW
   struct {
      bool sw_output;
      ismd_audio_output_config_t output_config;
      int output_hw_id;
   } audio_hw_output_params;

   // for HW demux/TSI types
   struct {
      ismd_demux_filter_output_format_t out_fmt;
      size_t max_output_buf_size;
      char *output_name_to_index; // Name of the filter that the indexer is indexing, only if out_fmt == ISMD_DEMUX_OUTPUT_INDEXING_INFO
   } demux_filter_params;

   // for PL_TYPE_VIDDEC_HW
   struct {
      unsigned int view_order_index; //Refers to the view index of the views
                                     // for MVC streams
   } viddec_output_params;

   // for PL_TYPE_VIDCAP_HW
   struct {
      unsigned int view_order_index; //Refers to the view index of the views
                                     // for 3D streams
   } vidcap_output_params;

   // for PL_TYPE_VID_REND_HW
   struct {
      int port_depth;
   } vidrend_output_port_params;

} output_options_t;


/////////////////////////////////////
// Exposed Functions
/////////////////////////////////////

// Enables/disables debug information for the pipeline library.
//  0: errors only
//  1: 0+ major operations
//  2: 1+ ismd/file operations
//  3: everything
// This does not propagate to the file devices and is GLOBAL.
// This can be called before the pipeline manager is initialized.
void pl_set_debug_level             (int debug_level);

// Initialize the entire pipeline management library.  This includes the
// file source/sink devices.
// This is not supposed to be thread-safe - it should be called once
// to initialize things and that's it - no matter how many apps
// are to use this thing.
ismd_result_t pl_init               (void);

// De-initialize the entire pipeline management library.  This includes the
// file source/sink devices.
// This can be done no matter which state the pipeline manager is in,
// and will free all resources.
ismd_result_t pl_deinit             (void);

// Allocates a new (empty) pipeline and returns a handle to it.
// If the boolean is true, the pipeline will use GStreamer.
ismd_result_t pl_alloc              (pl_pipe_t          *handle,
                                     bool                use_gstreamer);

// Frees a pipeline handle.  This can be done no matter which state the pipeline
// is in.  Releases all resources.
ismd_result_t pl_free               (pl_pipe_t           handle);

// Adds a stage to the pipeline, given a type and a name.
// The name is important because that is what's used to look up
// the stage later on - it must be unique to the pipeline.
// Some devices need parameters at creation time.  The specific_params
// parameter is type-casted depending on the stage type to provide these
// variables.  Most stages do not need this and it should be set to NULL.
// Note that while a clock is added to the pipeline using this API,
// unlike all of the other stage types there can only be one clock in
// the pipeline.
// When a clock is added to the pipeline it is assigned to all devices
// already in the pipeline.  Devices added after the clock has been added
// are also assigned whatever clock was set in the past.
// Audio inputs are assigned a clock in a similar way.
// The buffering monitor behaves the same way that the clock does - only
// one can be in the pipeline, when one is added to the pipeline all
// of the registration is handled automatically, and when new
// stages are added to the pipeline they are registered with the existing
// buffering monitor.
// Stages added to the pipeline are left in the stopped state, regardless
// of whatever state the pipeline is in at the time they are
// added.
// NULL is not a valid name, and neither is an empty string.
// If this is used to add a clock, it will be in clock index 0.
// If multiple clocks are needed use pl_add_clock().
ismd_result_t pl_add_stage          (pl_pipe_t           handle,
                                     pl_stage_type_t     type,
                                     char               *stage_name,
                                     create_options_t   *specific_params);


// Similar to add_stage, this allows for two pipelines to share a stage.
// This allows two independant pipelines to share an audio processor
// or clock. (Other things can be shared, but these are the two most
// common cases)
// The programming sequence is as follows:
//  * Create a pipeline, add a stage to it normally, get the handle wrapper
//    for that stage.
//  * Create another pipeline, use this API to cause it to use the already
//    allocated stage.
//
// This pipeline will not "own" the stage, and thus will not close it.
// For audio processors, inputs can be created in either pipeline and
// function independantly.
// Note that to ensure the correct shutdown order, the "secondary" pipe
// that is using the shaed resources should be closed before the primary
// pipe that actually owns the resources.
// If this is used to add a clock, it will be in clock index 0.
// If multiple clocks are needed use pl_add_clock().
ismd_result_t pl_add_stage_shared   (pl_pipe_t           handle,
                                     char               *stage_name,
                                     pl_handle_wrapper_t *external_handle);

// Similar to pl_add_stage and pl_add_stage_shared, This allows for more
// control over pipelines that need multiple clocks.  The clock_index
// parameter is used to set a specific clock on different devices with
// pl_select_clock_stage().
// The specific_params parameter is only used if shared is false (new clock)
// and the external_handle parameter is only used if shared is true
// (clock already created in another pipe).
ismd_result_t pl_add_clock (pl_pipe_t            handle,
                            pl_stage_type_t      type,
                            char                *stage_name,
                            unsigned             clock_index,
                            bool                 shared,
                            create_options_t    *specific_params,
                            pl_handle_wrapper_t *external_handle);

// Get a handle for a specific stage in the pipeline.
// The handle wrapper indicates the handle type.
// The handle can be used to do more advanced configuration on a device.
// NULL is not a valid name, and neither is an empty string.
ismd_result_t pl_get_stage          (pl_pipe_t           handle,
                                     char               *stage_name,
                                     pl_handle_wrapper_t **handle_wrapper);

// Removes specified stage from the pipeline.
// Generally, the pipeline must be stopped if removing the clock.
// NULL is not a valid name, and neither is an empty string.
ismd_result_t pl_remove_stage       (pl_pipe_t           handle,
                                     char               *stage_name);


// Adds an input to the specified stage to the pipeline.
// The type of the input depends on the type of the stage.
// Note that not all stages can have inputs added to them.
// (the video decoder, for instance, only has one input and it
// is created when the decoder is created).
// The name is important because that is what's used to look up
// the input later on - it must be unique to the stage.
// Some devices need parameters at input creation time.  The specific_params
// parameter is type-casted depending on the stage type to provide these
// variables.  Most inputs do not need this and it should be set to NULL.
// For inputs with state (as in audio) are left in the stopped state, regardless
// of whatever state the stage is in at the time they are
// added.
// The audio inputs have the clock assigned to them, if one exists
// in the pipe when the input was created.
// The autio inputs are also registered with the buffering monitor
// if one is in the pipeline.
// NULL is not a valid name, and neither is an empty string.
ismd_result_t pl_add_input          (pl_pipe_t           handle,
                                     char               *stage_name,
                                     char               *input_name,
                                     input_options_t    *specific_params);

// Removes an input to the specified stage to the pipeline.
// The names are used to determine which input to remove from which
// stage.
// NULL is not a valid name, and neither is an empty string.
ismd_result_t pl_remove_input       (pl_pipe_t           handle,
                                     char               *stage_name,
                                     char               *input_name);

// Gets an input for the specified stage.
// The name is used to lookup an input that was added through
// pl_add_input().  If this is a device like the video decoder,
// the default input does not have a name string and input_name should
// be specified as NULL.
ismd_result_t pl_get_input          (pl_pipe_t           handle,
                                     char               *stage_name,
                                     char               *input_name,
                                     pl_handle_wrapper_t **input_handle_wrapper);

// Adds an output to the specified stage to the pipeline.
// The type of the output depends on the type of the stage.
// Note that not all stages can have outputs added to them.
// (the video decoder, for instance, only has one output and it
// is created when the decoder is created).
// The name is important because that is what's used to look up
// the output later on - it must be unique to the stage.
// Some devices need parameters at output creation time.  The specific_params
// parameter is type-casted depending on the stage type to provide these
// variables.  Most outputs do not need this and it should be set to NULL.
// NULL is not a valid name, and neither is an empty string.
// Audio outputs are NOT enabled - they must be enabled by the
// application after the application configures them.
ismd_result_t pl_add_output         (pl_pipe_t           handle,
                                     char               *stage_name,
                                     char               *output_name,
                                     output_options_t   *specific_params);

// Removes an output to the specified stage to the pipeline.
// The names are used to determine which output to remove from which
// stage.
// NULL is not a valid name, and neither is an empty string.
ismd_result_t pl_remove_output      (pl_pipe_t           handle,
                                     char               *stage_name,
                                     char               *output_name);

// Gets an output for the specified stage.
// The name is used to lookup an output that was added through
// pl_add_output().  If this is a device like the video decoder,
// the default output does not have a name string and output_name should
// be specified as NULL.
ismd_result_t pl_get_output         (pl_pipe_t           handle,
                                     char               *stage_name,
                                     char               *output_name,
                                     pl_handle_wrapper_t **output_handle_wrapper);

ismd_result_t pl_get_ismd_handle (pl_pipe_t           handle,
                                  char               *stage_name,
                                  ismd_dev_handle_t  *ismd_handle);


// Connects one stage to another.
// Both stage names are specified, as well as the names
// of the first stage's output and second stage's input. If the
// outputs and inputs are created by default (such as the input for the
// video decoder) then NULL should be specified for the input and output names.
// Since devices like the clock and buffering monitor do not have data
// pass through them, they cannot be connected to other devices.
ismd_result_t pl_connect            (pl_pipe_t           handle,
                                     char               *first_stage,
                                     char               *first_stage_output,
                                     char               *second_stage,
                                     char               *second_stage_input);

// Disconnects one stage from another.
// Both stage names are specified, as well as the names
// of the first stage's output and second stage's input. If the
// outputs and inputs are created by default (such as the input for the
// video decoder) then NULL shouldbe specified for the input and output names.
// If they weren't connected this will fail.
ismd_result_t pl_disconnect         (pl_pipe_t           handle,
                                     char               *first_stage,
                                     char               *first_stage_output,
                                     char               *second_stage,
                                     char               *second_stage_input);

// Sets the base time of the pipeline.
// Only for advanced use.
// The base-time is set automatically in the pause and play states.
// This only manipulates devices using clock index 0
ismd_result_t pl_set_base_time      (pl_pipe_t           handle,
                                     ismd_time_t         base_time);

// Like pl_set_base_time() but gives an option for which clock to
// set the base time for.  Only devies set to use the supplied clock
// index will have their base times set.
ismd_result_t pl_set_base_time_clock (pl_pipe_t           handle,
                                      ismd_time_t         base_time,
                                      unsigned            clock_index);

// Gets the base time of the pipeline.
// The base-time is set automatically in the pause and play states.
// Will fail if the base time is not yet valid.
// This only gest the base time for clock index 0
ismd_result_t pl_get_base_time      (pl_pipe_t           handle,
                                     ismd_time_t        *base_time);

// Like pl_get_base_time_clock() but gives an option for which clock to
// get the base time for.
ismd_result_t pl_get_base_time_clock (pl_pipe_t           handle,
                                      ismd_time_t        *base_time,
                                      unsigned            clock_index);

// Sets pipeline state.  All devices that belong to this pipeline will have
// their state set.
// This manages setting/updating the base_time in transitions between
// pause and play.
ismd_result_t pl_set_state          (pl_pipe_t           handle,
                                     ismd_dev_state_t    state);

// Sets the trick-mode play rate of the renderers.  This is for the
// "dynamic rate change" case, not the trick mode case that uses a
// newsegment.
ismd_result_t pl_set_play_rate      (pl_pipe_t           handle,
                                     ismd_pts_t          linear_time,
                                     int                 rate);

// Sets the renderers to advance to the given linear pts
ismd_result_t pl_set_advance_to_pts  (pl_pipe_t           handle,
                                      ismd_pts_t          linear_time,
                                      ismd_pts_t          next_linear_time);


// Sets the state of a specific stage in the pipeline.
// For advanced use only.
// Note that the state of these modified stages will not
// be synchronized to the state of the pipeline.
// Note that this not update the base time, so it should not be used
// on renderers.
ismd_result_t pl_set_state_stage    (pl_pipe_t           handle,
                                     char               *stage_name,
                                     ismd_dev_state_t    state);

// Sets the state of all stages in the pipeline that are acting as sources
// (filesources, tuner inputs, etc...) without affecting the rest
// of the pipeline.
// Note that the state of these modified stages will not
// be synchronized to the state of the pipeline.
ismd_result_t pl_set_state_inputs   (pl_pipe_t           handle,
                                     ismd_dev_state_t    state);

// Gets the pipeline state.
ismd_result_t pl_get_state          (pl_pipe_t           handle,
                                     ismd_dev_state_t   *state);

// Gets the state of a specific stage in the pipeline.
ismd_result_t pl_get_state_stage    (pl_pipe_t           handle,
                                     char               *stage_name,
                                     ismd_dev_state_t   *state);

// Flush the pipeline.  Flush will be called on all devices in the pipeline.
// The pipeline should be stopped for this to have a meaningful effect, but this
// is not enforced.
// This does a "discard flush"
ismd_result_t pl_flush              (pl_pipe_t           handle);

// Flushes a specific stage in the pipeline.
// For advanced use only.
ismd_result_t pl_flush_stage        (pl_pipe_t           handle,
                                     char               *stage_name);

// Sends a newsegment into the pipeline, at the specified
// input point (stage and input).  For devices that do not have
// optional inputs the input name is ignored and should be NULL.
// Note, the newsegment must be sent through a PORT.  This means
// the stage specified should NOT be a source stage, but the stage after
// the source.  If the port is connected, it is temporarily disconnected
// before the data is written in.
// If the port is full this will WAIT until the write succeeds, leaving
// the pipeline locked.
ismd_result_t pl_send_newsegment    (pl_pipe_t           handle,
                                     char               *stage_name,
                                     char               *input_name,
                                     ismd_newsegment_tag_t *newsegment_data);

// Selects which clock the specified stage uses.  By default all devices use
// index 0.  Clocks other than index 0 can be added with pl_add_clock().
ismd_result_t pl_select_clock_stage (pl_pipe_t           handle,
                                     char               *stage_name,
                                     unsigned            clock_index);

// Reset the paused time of the pipeline.
// Only used when seeking.
ismd_result_t pl_reset_paused_time  (pl_pipe_t           handle);

// Like pl_reset_time() but gives an option for which clock to
// get the base time for.
ismd_result_t pl_reset_paused_time_clock (pl_pipe_t      handle,
                                          unsigned       clock_index);

// TODO: for primary and secondary clocks
//    New API for adding a secondary clock
//    New API for assigning a secondary clock to a device
//    New API for switching the primary clock in the pipe
//       needs to internally switch all devices using the primary
//       clock and secondary clocks

// Prints a bug to the screen
void          pl_print_bug          (void);


/////////////////////////////////////
// Exposed Macros
/////////////////////////////////////

// Define a couple of macros to wrap all text I/O
// (we might send it to SVEN one day)
// Note, the format strings passed in must be a literal string ("blah blah") and
// not a string variable.

// NOTE: some of these assume that you store your ISMD result in a variable called "result"
// and your global debug level in a variable called "debug_level".

#define ANSI_FG_GREEN  "\033[0;0;32m"
#define ANSI_FG_NORMAL "\033[0m"
#define ANSI_FG_RED    "\033[0;0;31m"
#define ANSI_FG_ORANGE "\033[0;0;33m"
#define ANSI_FG_GREY   "\033[0;0;37m"

#define PL_MSG(format, ...)                                                                     \
   {OS_INFO("%s: %s: %d: " format, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__); fflush(stdout);}
#define PL_ERR(format, ...) {                                                                   \
   PL_MSG( ANSI_FG_RED format ANSI_FG_NORMAL, ##__VA_ARGS__)                                    \
   pl_print_bug();                                                                              \
}

#define PL_DBG(message_level, format, ...)                                                      \
   {if ((message_level) <= debug_level) {PL_MSG(format, ##__VA_ARGS__)}}

// Macro that wraps ismd and file_io operations
//    - logs them thoroughly without the mess in each function
//    Assumes the action being logged returns ismd_result_t
#define PL_LOG(action, action_string, ...)                                                      \
{                                                                                               \
   PL_DBG(3,ANSI_FG_GREY " Calling: " ANSI_FG_NORMAL #action "\n");                             \
   PL_DBG(4,ANSI_FG_GREY "    with: " ANSI_FG_NORMAL action_string "\n", ##__VA_ARGS__);        \
   result = (action);                                                                           \
   if (result == ISMD_SUCCESS) {                                                                \
      if(debug_level == 2){PL_MSG(ANSI_FG_GREY "Function: " ANSI_FG_NORMAL #action "\n");}      \
      PL_DBG(2, ANSI_FG_GREEN " Success: " ANSI_FG_NORMAL action_string "\n", ##__VA_ARGS__);   \
   } else {                                                                                     \
      if(debug_level <  3){PL_MSG(ANSI_FG_GREY "Function: " ANSI_FG_NORMAL #action "\n");}      \
      PL_ERR( "  FAILED: " action_string " result = %d\n", ##__VA_ARGS__, result);              \
   }                                                                                            \
}

// Slightly simpler version of above macro, that requires less code to use but has slightly
// less debug information.  Function and args passed in separately.
// Will exit the app if the function call does not return 0.
#define PL_CALL(function, ...)                                                                    \
{                                                                                                 \
   int pl_call_ret = 0;                                                                           \
   PL_DBG(3,ANSI_FG_GREY " Calling: " ANSI_FG_NORMAL #function "(" #__VA_ARGS__ ")\n");           \
                                                                                                  \
   pl_call_ret = function(__VA_ARGS__);                                                           \
   if (pl_call_ret == 0) {                                                                        \
      PL_DBG(2, ANSI_FG_GREEN " Success: " ANSI_FG_NORMAL #function "(" #__VA_ARGS__ ")\n");      \
   } else {                                                                                       \
      PL_ERR( "  FAILED: " #function "(" #__VA_ARGS__ "), result = %d - EXITING\n", pl_call_ret); \
      exit(pl_call_ret);                                                                          \
   }                                                                                              \
}


// Do If Success
#define PL_DIS(action...)        \
{                                \
   if (result == ISMD_SUCCESS) { \
      (action);                  \
   }                             \
}

// Function enter and exit
#define PL_ENTER        PL_DBG(4, "Entering\n")
#define PL_EXIT(result) PL_DBG(4, "Exiting, result %d\n", result)

#endif //__PIPELINE_LIBRARY_H__
