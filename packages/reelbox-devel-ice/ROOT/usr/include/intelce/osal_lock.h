/*==========================================================================
  This file is provided under a BSD license.  When using or 
  redistributing this file, you may do so under this license.

  BSD LICENSE 

  Copyright(c) 2005-2011 Intel Corporation. All rights reserved.
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
 =========================================================================*/

/*
 * This file contains OS abstracted interfaces to lock operations.
 */

//! \file
//!  This file contains OS abstracted interfaces to lock operations.

/** \defgroup OSAL_LOCK OSAL Mutex locks
 *
 * <I> Provides OS independent interface for locks
 * </I>
 *
 *\{*/

#ifndef _OSAL_SYNC_H_
#define _OSAL_SYNC_H_


#include "osal_type.h"
#include "os/osal_lock.h"


#ifdef __cplusplus
extern "C" {
#endif


//! \function
//
//! \brief  Creates a lock and returns a handle to a it.
//! \returns handle to the lock
os_lock_t os_create_lock(void);

//! \function
//
//! \brief  Gets the lock.
//! \param  lock handle to the lock
//! \returns 0 on success non zero error code on error
int os_lock(os_lock_t lock);

//! \function
//
//! \brief  Gets the lock without blocking.
//! \param  lock handle to the lock
//! \returns 0 on success non zero error code on error
int os_try_lock(os_lock_t lock);

//! \function
//
//! \brief  Releases the lock
//! \param  lock handle to the lock
//! \returns 0 on success non zero error code on error
int os_unlock(os_lock_t lock);

//! \function
//
//! \brief deallocates the lock
//! \param  lock handle to the lock
//! \returns 0 on success non zero error code on error
int os_destroy_lock(os_lock_t lock);


/*
 * Native mutex functions.  Functions above should be deprecated.
 */

/**
Initialize a mutex lock

@param mtx : Pointer to the mutex lock to initialize.

@retval OSAL_SUCCESS : initialization successful
@retval OSAL_INVALID_PARAM : mxt parameter is NULL.
*/
osal_result os_mutex_init(os_mutex_t *mtx);


/**
destroy a mutex lock

@param mtx : the mutex lock to be destroyed

@retval OSAL_SUCCESS : destruction successful
@retval OSAL_INVALID_PARAM : mxt parameter is NULL or
	or contains an invalid value.
*/
osal_result os_mutex_destroy(os_mutex_t *mtx);


/**
Acquire a mutex lock, block until the lock is acquired.

@param mtx : the mutex lock to acquire.
@retval OSAL_SUCCESS : lock successfully acquired.
@retval OSAL_INVALID_PARAM : mxt parameter is NULL or
	or contains an invalid value.
*/
osal_result os_mutex_lock(os_mutex_t *mtx);


/**
Acquire a mutex lock without blocking.

@param mtx : the mutex lock to acquire.

@retval OSAL_SUCCESS : lock successfully acquired
@retval OSAL_ERROR : lock not acquired
@retval OSAL_INVALID_PARAM : mxt parameter is NULL or
	or contains an invalid value.
*/
osal_result os_mutex_trylock(os_mutex_t *mtx);


/**
Release a mutex lock

@param mtx : the mutex lock to release.

@retval OSAL_SUCCESS : lock successfully released.
@retval OSAL_INVALID_PARAM : mxt parameter is NULL or
	or contains an invalid value.
*/
osal_result os_mutex_unlock(os_mutex_t *mtx);

#ifdef __cplusplus
}
#endif

#endif
