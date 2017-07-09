/*
Copyright [2008-2009] Intel Corporation

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


#ifndef __FILE_DEVICE_WRAPPER_H__
#define __FILE_DEVICE_WRAPPER_H__

#include "ismd_global_defs.h"
#include "file_source.h"
#include "file_sink.h"
#include "image_file_source.h"
#include "image_file_sink.h"
#include "image_memory_sink.h"

typedef enum {
   FILEDEV_TYPE_INVALID = 0,
   FILEDEV_TYPE_SRC,
   FILEDEV_TYPE_SNK,
   FILEDEV_TYPE_IMGSRC,
   FILEDEV_TYPE_IMGSNK,
   FILEDEV_TYPE_IMGMEMSNK,
   FILEDEV_TYPE_UDPSRC
} pl_filedev_type_t;

// Generic handle type - must match the dev handle types
typedef void* pl_filedev_t;


// See documentation in each file device for the function specifics

ismd_result_t filedevs_init(void);



ismd_result_t filedevs_deinit(void);


ismd_result_t filedev_open(            pl_filedev_type_t       type,
                                       pl_filedev_t           *handle);

ismd_result_t filedev_close(           pl_filedev_type_t       type,
                                       pl_filedev_t            handle);

ismd_result_t filedev_set_port(        pl_filedev_type_t       type,
                                       pl_filedev_t            handle,
                                       ismd_port_handle_t      port);

ismd_result_t filedev_set_state(       pl_filedev_type_t       type,
                                       pl_filedev_t            handle,
                                       ismd_dev_state_t        state);

ismd_result_t filedev_get_state(       pl_filedev_type_t       type,
                                       pl_filedev_t            handle,
                                       ismd_dev_state_t       *state);

ismd_result_t filedev_set_path(        pl_filedev_type_t       type,
                                       pl_filedev_t            handle,
                                       char                   *path,
                                       int                     path_length);

ismd_result_t filedev_register_event(  pl_filedev_type_t       type,
                                       pl_filedev_t            handle,
                                       ismd_event_t            ismd_event,
                                       int                     mask);

char *filedev_type_to_string(          pl_filedev_type_t       type);



#endif //__FILE_DEVICE_WRAPPER_H__
