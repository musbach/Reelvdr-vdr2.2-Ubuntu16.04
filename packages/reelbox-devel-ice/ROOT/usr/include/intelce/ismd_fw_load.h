//****************************************************************************
// Copyright(c) 2011 Intel Corporation. All rights reserved.
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable as Sample Source Software is subject to the terms
// and conditions of the Intel Software License Agreement for the Intel(R)
// Media Processor Software Development Kit
//****************************************************************************

#ifndef ISMD_FW_LOAD_H
#define ISMD_FW_LOAD_H

#include "osal.h"
#include "platform_config.h"
#include "platform_config_paths.h"

/**
helper function to read platform_config and memory_layout to get FW physical base address, 
and FW buf size, as well as FW image actual size.

@param[in] fw_name : the fw name to query. e.g: "audio_dsp0"
@param[out] fw_base: FW physical address
@param[out] buf_size: the pre-defined bufferr size to hold FW image. The buffer size may larger than image_size
@param[out] iamge_size: the FW image actually size.
@retval CONFIG_SUCCESS : the query was successfully retrieved.
*/

static inline config_result_t fw_load_query_region(char* fw_name, int32_t* fw_base, int32_t* buf_size, int32_t* image_size)
{
   config_ref_t        node;
   config_result_t     result = CONFIG_SUCCESS;
   char location[64] = {0};

   OS_ASSERT(fw_name != NULL);
   OS_ASSERT(fw_base != NULL);
   OS_ASSERT(buf_size != NULL);
   OS_ASSERT(image_size != NULL);

   *fw_base = 0;
   *buf_size = 0;
   *image_size = 0;

   if(CONFIG_SUCCESS == config_node_find( ROOT_NODE, CONFIG_PATH_PLATFORM_SMD_DRIVERS ".firmware", &node ) && 
      CONFIG_SUCCESS == config_node_find( node, fw_name, &node ) && 
      CONFIG_SUCCESS == config_get_str( node, "location", location, sizeof(location)) &&
      CONFIG_SUCCESS == config_get_int( node, "size", image_size)) {

      if ( CONFIG_SUCCESS == config_node_find( ROOT_NODE, CONFIG_PATH_PLATFORM_MEMORY_LAYOUT, &node ) &&
           CONFIG_SUCCESS == config_node_find( node, location, &node ) &&
           CONFIG_SUCCESS == config_get_int( node, "base", fw_base) &&
           CONFIG_SUCCESS == config_get_int( node, "size", buf_size)) {
         // For debug: OS_PRINT( "\t%20s: base %08x size %08x image_size %08x\n", name, *fw_base, *buf_size, *image_size );
      }
      else {
         OS_PRINT("ERR: entry %s.%s requires integer entries \"base\" and \"size\"\n", CONFIG_PATH_PLATFORM_MEMORY_LAYOUT, location );
         result = CONFIG_ERR_NOT_FOUND;
      }
   }
   else {
      OS_PRINT("ERR: Reading entry %s.%s failed.\n", CONFIG_PATH_PLATFORM_SMD_DRIVERS, location );
      result = CONFIG_ERR_NOT_FOUND;
   }


   return( result );
}

#endif // ISMD_FW_LOAD_H
