/*
Copyright [2008] Intel Corporation

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


/*--------------------------------------------------------------------------*
 *  vid_tex_interface.h                                                     *
 *                                                                          *
 *  Declarations and definitions for the shared memory implementation,      *
 *  which facilitates IPC (inter-process communication) between SMD         *
 *  player apps and video-as-texture apps                                   *
 *--------------------------------------------------------------------------*/

#if !defined(_VID_TEX_INTERFACE_H)
#define _VID_TEX_INTERFACE_H

/*
    INTRODUCTION TO VID_TEX_INTERFACE - A SHARED MEMORY INTERFACE
    -------------------------------------------------------------

    The SHM library provides a shared memory interface to communicate frame 
    attributes of the "most recently" displayed frame between independent
    processes. It is based on a client-server model that allows server to
    continuously update frame attributes to memory at a requested interval
    from the client. The frequency of updates and subsequent reads are
    controlled by built-in protocols which prevent simultaneous access.
    
    High level view of interactions between various processes and shared
    memory interface:
             ___________________________________
            |       shared memory region        |   
            |___________________________________|   
                /|\                         /|\
                 |                           |
            ___________                  _________  
            |SMD player |               |GDL apps |
            |___________|               |_________|
                 |                           |     
                \|/                         \|/
            _______________             _______________
            | ISMD drivers |           |               |
            | &Display     |           | Display       |
            |______________|           |_______________|


    Examples of independent processes include SMD player apps and GDL
    video as texture apps. SMD player apps will function as servers or
    producers of frame data in memory and GDL apps will function as
    clients or consumers of data. 
    
    The server and the clients are expected to adhere to the following
    protocols during initialization, run-time and clean-up.

    Server protocols
    -----------------
    - During initialization, server creates and initializes shared
      memory. (It can also clean up any orphaned shared memory)
    - During run-time, server calls begin_vid_tex_update to acquire
      update lock. If successful, server updates shared memory with
      frame attributes. Then, it releases update lock by calling
      end_vid_tex_update.
    - During clean-up, server releases shared memory if there are no
      clients attached.

    Client protocols
    ----------------
    - During initialization, clients attach to existing shared memory
      region. 
    - During run-time, client calls begin_vid_tex_read to acquire
      read lock. If successful, client reads frame attributes from
      shared memory for processing. It releases read lock by calling
      end_vid_tex_read.
    - During clean-up, client detaches from shared memory and exits.
*/

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

#if defined(__cplusplus)
extern "C" {
#else
#include <stdbool.h>
#endif


/*--------------------------------------------------------------------------*
 * Constants                                                                *
 *--------------------------------------------------------------------------*/

/* The pathname from which we derive our memory key */
#define VID_TEX_SHARED_MEM_PATHNAME "/lib/libshm_util.so"


/*--------------------------------------------------------------------------*
 * Type definitions                                                         *
 *--------------------------------------------------------------------------*/

/* COLOR SPACES (these match both SMD's and GDL's values) */
typedef enum
{
    VTI_COLOR_SPACE_BT601,          /* Standard definition color space */
    VTI_COLOR_SPACE_BT709           /* High definition color space */
} vid_tex_color_space_t;


/* SHARED MEMORY data structure */
typedef struct
{
    /* Synchronization */
    pthread_mutex_t lock_mutex;     /* Lock mutex */
    pthread_cond_t lock_cond;       /* Lock condition */

    /* Condition variables */
    volatile bool being_updated;    /* Buffer being updated */
    volatile bool new_data;         /* New buffer available */
    volatile unsigned short in_use; /* Number of clients/consumers now reading */

    /* Status */
    bool player_running;            /* Player/server still exists */
    unsigned short consumers;       /* Number of consumers/clients attached */
    unsigned int version;           /* Changes with change of frame attributes */
    int shmid;                      /* Shared memory ID */

    /* Buffer characteristics */
    unsigned long phys_addr_y;      /* Physical memory address of Y data */
    unsigned long phys_addr_u;      /* Physical memory address of U data */
    unsigned long phys_addr_v;      /* Physical memory address of V data */
    unsigned int width;             /* Frame width in pixels */
    unsigned int height;            /* Frame height in lines */
    vid_tex_color_space_t cspace;   /* Color space */
} vid_tex_interface_t;


/************************************************************
* SERVER (ONLY) SHARED MEMORY INITIALIZATION ROUTINES
*
* The following 3 routines allow servers to create or destroy
* a shared memory region. These are exclusively for servers.
*************************************************************/

/* vid_tex_create
 *
 * vid_tex_interface creation routine
 *  Acquires shared memory for exclusive use, initializes synchronization
 *  fields, then shares the memory with other processes. This legacy
 *  function is simply a wrapper for vid_tex_create_multi(1);
 *    input: none
 *    return: 0 : error
 *         else : pointer to the new vid_tex_interface struct
 */
extern vid_tex_interface_t *vid_tex_create(void);


/* vid_tex_create_multi
 *
 * vid_tex_interface creation routine
 *  Acquires shared memory for exclusive use, initializes synchronization
 *  fields, then shares the memory with other processes. This function is
 *  the companion to vid_tex_attach_multi.
 *    input: stream number to create
 *    return: 0 : error
 *         else : pointer to the new vid_tex_interface struct
 */
extern vid_tex_interface_t *vid_tex_create_multi(
    int stream_number);


/* vid_tex_destroy
 *
 * vid_tex_interface destruction routine
 *  Marks the shared memory for deletion, and conditionally (if
 *  !player_running && consumers <= 0), terminates synchronization.
 *    input: pvti : pointer to interface data in shared memory
 *    return: 0 : no error, shared memory area destroyed
 *            1 : no error, shared memory area not destroyed
 *           -1 : error
 */
extern int vid_tex_destroy(
    vid_tex_interface_t *pvti);


/************************************************************
* CLIENT INITIALIZATION ROUTINES
*
* The following 3 routines allow clients to attach to or 
* detach from the shared memory region prior to read. 
*************************************************************/

/* vid_tex_attach
 *
 * vid_tex_interface access routine
 *  Attaches to the existing vid_tex_interface shared memory. This
 *  legacy function is simply a wrapper for vid_tex_attach_multi(1).
 *    input: none
 *    return: 0 : error
 *         else : pointer to the new vid_tex_interface struct
 */
extern vid_tex_interface_t *vid_tex_attach(void);


/* vid_tex_attach_multi
 *
 * vid_tex_interface access routine
 *  Attaches to the existing vid_tex_interface shared memory. This
 *  function is the companion to vid_tex_create_multi.
 *    input: stream number to access
 *    return: 0 : error
 *         else : pointer to the new vid_tex_interface struct
 */
extern vid_tex_interface_t *vid_tex_attach_multi(
    int stream_number);


/* vid_tex_detach
 *
 * vid_tex_interface detach routine
 *  Detaches from the vid_tex_interface shared memory, and conditionally
 *  (if !player_running && consumers <= 0), terminates synchronization.
 *    input: pvti : pointer to interface data in shared memory
 *    return: 0 : no error
 *           -1 : error
 */
extern int vid_tex_detach(
    vid_tex_interface_t *pvti);

/************************************************************
* SERVER ACCESS ROUTINES
*
* The following 2 routines allow server to exclusively perform
* update operations to the shared memory region without being 
* intercepted by a read. The begin_vid_tex_update routine acquires
* the lock to start the update process. Once update is done, server
* releases the lock by calling end_vid_tex_update routine.
*************************************************************/

/* begin_vid_tex_update
 *
 * vid_tex_interface updater lock routine
 *    input: pvti : pointer to interface data in shared memory
 *           waittime: timeout in microseconds
 *    return: 0 : no error, lock acquired
 *           -1 : error
 */
extern int begin_vid_tex_update(
    vid_tex_interface_t *pvti,
    suseconds_t waittime);


/* end_vid_tex_update
 *
 * vid_tex_interface updater unlock routine
 *    input: pvti : pointer to interface data in shared memory
 *           waittime: timeout in microseconds
 *    return: 0 : no error
 *            1 : lock not unlocked
 *           -1 : error
 */
extern int end_vid_tex_update(
    vid_tex_interface_t *pvti,
    suseconds_t waittime);

/************************************************************
* CLIENT ACCESS ROUTINES
*
* The following 2 routines allow clients to exclusively perform
* copy or read operations from the shared memory region
* without being intercepted by an update. The begin_vid_tex_read
* routine acquires the lock to start read/copy process. Once 
* read is done, client releases the lock by calling end_vid_tex_read
* routine.
*************************************************************/

/* begin_vid_tex_read
 *
 * vid_tex_interface reader lock routine
 *    input: pvti : pointer to interface data in shared memory
 *           waittime: timeout in microseconds
 *    return: 0 : no error, lock acquired
 *            1 : lock not acquired(timed out)
 *           -1 : error
 */
extern int begin_vid_tex_read(
    vid_tex_interface_t *pvti,
    suseconds_t waittime);


/* end_vid_tex_read
 *
 * vid_tex_interface reader unlock routine
 *    input: pvti : pointer to interface data in shared memory
 *    return: 0 : no error
 *           -1 : error
 */
extern int end_vid_tex_read(
    vid_tex_interface_t *pvti);


#if defined(__cplusplus)
}
#endif

#endif /* _VID_TEX_INTERFACE_H */
