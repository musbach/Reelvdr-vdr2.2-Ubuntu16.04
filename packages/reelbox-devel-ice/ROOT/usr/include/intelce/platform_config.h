/************************************************************************ 

  This file is provided under a BSD license.  When using or 
  redistributing this file, you may do so under this license.

  BSD LICENSE 

  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
  All rights reserved.

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

*************************************************************************/



/** \file platform_config.h */
#ifndef _PLATFORM_CONFIG_H_
#define _PLATFORM_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "htuple.h"

#ifdef __KERNEL__
#include <linux/types.h>
#include <linux/slab.h>
#else
#include <stdlib.h>
#endif

//! \file
/** @defgroup platform Platform Configutation*/
/** @addtogroup platform */
/*@{*/
#define ROOT_NODE 0

typedef enum {
	CONFIG_SUCCESS 						= 0,
	CONFIG_ERR_NOT_FOUND 				= 1,
	CONFIG_ERR_INVALID_REFERENCE 		= 2,
	CONFIG_ERR_NO_RESOURCES 			= 3,
	CONFIG_ERR_NOT_INITIALIZED 			= 4,
	CONFIG_ERR_INITIALIZE_FAILED		= 5,
	CONFIG_ERR_ALREADY_INITIALIZED 		= 6,
	CONFIG_ERR_ALREADY_DEINITIALIZED 	= 7,
	CONFIG_ERR_DEINITIALIZE_FAILED 		= 8,
} config_result_t;

typedef unsigned int config_ref_t;

/**
 * Start at the specified reference node, locate the sub-node with the
 * specified name, and return the integer value associated with that name.
 * @param[in] base_ref       based node reference 
 * @param[in] name           node name            
 * @param[out] val       return value
 */
config_result_t config_get_int(
            config_ref_t    base_ref,
            const char *    name,
            int *           val );
/**
 * Start at the specified reference node, locate the sub-node with the
 * specified name, and return the string value associated with that name.
 * @param[in] base_ref       based node reference 
 * @param[in] name           node name            
 * @param[out] string        attribute content 
 * @param[in] bufsize       string buffer size   
 */
config_result_t config_get_str(
            config_ref_t    base_ref,
            const char *    name,
            char *          string,
            size_t          bufsize ); 

/** 
 * Start at the specified reference node, locate or create the sub-node with
 * the specified name, and assign the integer value to that name.
 * @param[in] base_ref       based node reference 
 * @param[in] name           node name            
 * @param[out] val       return value
 */
config_result_t config_set_int(
            config_ref_t    base_ref,
            const char *    name,
            int             val );

/** 
 * Start at the specified reference node, locate or create the sub-node with
 * the specified name, and assign the string value to that name.
 *
 * @param[in] base_ref       based node reference 
 * @param[in] name           node name            
 * @param[in] string       target node reference
 * @param[in] bufsize      the buffer size
 */
config_result_t config_set_str(
            config_ref_t    base_ref,
            const char *    name,
            const char *    string,
            size_t          bufsize ); 

/** 
 * Start at the specified reference node, locate the sub-node with the
 * specified name, and return a reference to that node.
 * 
 * @param[in] base_ref       based node reference
 * @param[in] name           node name
 * @param[out] node_ref       target node reference
 */
config_result_t config_node_find(
            config_ref_t    base_ref,
            const char *    name,
            config_ref_t *  node_ref );

/**
 * Find the first child of the specified reference node, and return a
 * reference to that child. 
 * @param[in] node_ref       target node reference
 * @param[out] child_ref       return child reference
 */
config_result_t config_node_first_child(
            config_ref_t    node_ref,
            config_ref_t *  child_ref );

/** 
 * Find the next sibling of the specified reference node, and return a
 * reference to that sibling.
 *
 * @param[in] node_ref       target node reference
 * @param[out] child_ref       return sibling reference
 *
 */
config_result_t config_node_next_sibling(
            config_ref_t    node_ref,
            config_ref_t *  child_ref );

/**
 * Return the name of the specified reference node. 
 * @param[in] node_ref       based node reference 
 * @param[in] name           node name            
 * @param[in] bufsize       string buffer size   
 */
config_result_t config_node_get_name(
            config_ref_t    node_ref,
            char *          name,
            size_t          bufsize );

/**
 * Return the string value associated with the specified reference node.
 *
 * @param[in] node_ref       based node reference 
 * @param[in] string         get the node string by name            
 * @param[in] bufsize       string buffer size   
 *
 */
config_result_t config_node_get_str(
            config_ref_t    node_ref,
            char *          string,
            size_t          bufsize );

/**
 * Return the integer value associated with the specified reference node. 
 *
 * @param[in] node_ref       based node reference 
 * @param[in] val           return the integer value           
 *
 */
config_result_t config_node_get_int(
            config_ref_t    node_ref,
            int *           val );

/**
 * Parse the specified string of configuration data and insert it into the
 * dictionary at the specified reference node.
 * 
 * @param[in] base_ref       based node reference 
 * @param[in] config_data    specified configuration data
 * @param[in] datalength     the datalength of the config_data
 */
config_result_t config_load(
            config_ref_t    base_ref,
            const char *    config_data,
            size_t          datalength );

/**
 * Parse the specified string of configuration data and insert it into the
 * dictionary at the specified reference node.
 * @param[in] base_ref       based node reference 
 */
config_result_t config_private_tree_remove( 
			config_ref_t 	base_ref );




/** @deprecated DEPRECATED: DRIVER PRIVATE: initialize the memory layout internal hash table */
config_result_t config_initialize( void );
/** @deprecated DEPRECATED: DRIVER PRIVATE: deinitialize memory layout internal hash table */
config_result_t config_deinitialize( void );
/*@}*/
#ifdef __cplusplus
}
#endif
#endif /* _PLATFORM_CONFIG_H_ */
