/*
#
# This file is provided under a dual BSD/LGPLv2.1 license.  When using 
# or redistributing this file, you may do so under either license.
#
# LGPL LICENSE SUMMARY
#
# Copyright(c) 2007-2011. Intel Corporation. All rights reserved.
#
# This program is free software; you can redistribute it and/or modify 
# it under the terms of version 2.1 of the GNU Lesser General Public 
# License as published by the Free Software Foundation.
#
# This library is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public 
# License along with this library; if not, write to the Free Software 
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 
# USA. The full GNU Lesser General Public License is included in this 
# distribution in the file called LICENSE.LGPL.
#
# Contact Information:
#     Intel Corporation
#     2200 Mission College Blvd.
#     Santa Clara, CA  97052
#
#
#  BSD LICENSE
#
#  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in
#      the documentation and/or other materials provided with the
#      distribution.
#    * Neither the name of Intel Corporation nor the names of its
#      contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#*/

/* 
 *  OSAI Header file for Linux user space
 */

#ifndef _COSAI_H_
#define _COSAI_H_

#ifdef __cplusplus
extern "C" {
#endif

#if (defined(LINUX_KERNEL) || defined(NOT_UPSTEAM))
#error "The macros LINUX_KERNEL and NOT_STREAM cannot be defined in user-level COSAI"
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE //to compile with affinity and cpu_set stuff
#endif // _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "cosai_internal.h"

/* Error code */
#include <linux/errno.h>
#define cosai_error_t               int
#define COSAI_EPERM                 EPERM           /* Operation not permitted */
#define COSAI_NOENT                 ENOENT          /* No such file or directory */
#define COSAI_FAULT                 EFAULT          /* Bad address */
#define COSAI_NOMEM                 ENOMEM          /* Out of memory */
#define COSAI_TIMEOUT               0               /* Only used for wait_event_timeout's */
#define COSAI_INTERRUPTED           ERESTARTSYS     /* A signal interrupts */

/* Memory management */
#include <string.h>
#define cosai_alloc(size)           malloc(size)
#define cosai_zalloc(size)          calloc(1, size)
#define cosai_free(objp)            free(objp)
#define cosai_alloc_nonblock(size)  malloc(size)
#define cosai_zalloc_nonblock(size) calloc(1, size)
#define cosai_free_nonblock(objp)   free(objp)
#define cosai_alloc_page()          linuxuser_alloc_page()
#define cosai_zalloc_page()         linuxuser_zalloc_page()
#define cosai_free_page(objp)       free(objp)
#define cosai_alloc_virtual(size)   malloc(size)
#define cosai_free_virtual(objp)    free(objp)
#define cosai_memset(mem, c, count) memset(mem, c, count)
#define cosai_memcpy(dst, src, cnt) memcpy(dst, src, cnt)
#define cosai_memcmp(m1, m2, cnt)   memcmp(m1, m2, cnt)
/* TODO: implement this */
#define cosai_virt_to_phys(addr)    (void *)0 
#define cosai_phys_to_virt(addr)    (void *)0
extern void *linuxuser_alloc_page(void);
extern void *linuxuser_zalloc_page(void);
 
/* I/O */
#define cosai_read8(addr) linuxuser_read8(addr)
#define cosai_read16(addr) linuxuser_read16(addr)
#define cosai_read32(addr) linuxuser_read32(addr)

extern unsigned char linuxuser_read8(void *addr);
extern unsigned short linuxuser_read16(void *addr);
extern unsigned int linuxuser_read32(void *addr);

extern void linuxuser_write8(unsigned char val, void *addr);
extern void linuxuser_write16(unsigned short val, void *addr);
extern void linuxuser_write32(unsigned int val, void *addr);

#define cosai_write8(value, addr)    linuxuser_write8(value, addr)
#define cosai_write16(value, addr)   linuxuser_write16(value, addr)
#define cosai_write32(value, addr)   linuxuser_write32(value, addr)

/* Memory Mapping */
#include <unistd.h>
#define cosai_phys_addr_t           uintptr_t
#define cosai_map_io_cache(base_addr, size)   linuxuser_map_io_cache(base_addr, size)
#define cosai_map_io_nocache(base_addr, size) linuxuser_map_io_nocache(base_addr, size)
/* TODO: Add into doc */
#define cosai_map_io_wc(base_addr, size)      linuxuser_map_io_nocache(base_addr, size)
#define cosai_unmap_io(addr, size)            linuxuser_unmap_io(addr, size)
extern void *linuxuser_map_io_cache(uintptr_t base_addr, unsigned long size);
extern void *linuxuser_map_io_nocache(uintptr_t base_addr, unsigned long size);
extern void linuxuser_unmap_io(void *addr, unsigned long size);
#define cosai_get_page_size()       getpagesize()

/* Time */
#define cosai_get_time()            linuxuser_get_time()
#define cosai_get_time_in_ms()      linuxuser_get_time_in_ms()
#define cosai_get_time64()          linuxuser_get_time64()
#define cosai_get_time64_in_ms()    linuxuser_get_time64_in_ms()
#define cosai_gettimeofday(tv)      gettimeofday(tv, NULL)
extern unsigned long linuxuser_get_time(void);
extern unsigned long long linuxuser_get_time64(void);
extern unsigned long linuxuser_get_time_in_ms(void);
extern unsigned long long linuxuser_get_time64_in_ms(void);

/* Spin Lock */
#ifdef ANDROID_USER
#include "bionic_ext.h"
#else
#include <pthread.h>
#endif
#define cosai_lock_t                     pthread_spinlock_t
#define cosai_rwlock_t                   pthread_rwlock_t
#define cosai_irqflag_t                  unsigned long
#define cosai_lock_init(lock, name)      pthread_spin_init(lock, PTHREAD_PROCESS_PRIVATE)
#define cosai_lock(lock)                 pthread_spin_lock(lock)
#define cosai_unlock(lock)               pthread_spin_unlock(lock)
#define cosai_trylock(lock)              pthread_spin_trylock(lock)
#define cosai_lock_irqsave(lock, flags)  (void)flags; pthread_spin_lock(lock)
#define cosai_unlock_irqrestore(lock, flags) (void)flags; pthread_spin_unlock(lock)
#define cosai_trylock_irq(lock)          linuxuser_trylock(lock)
#define cosai_lock_destroy(lock)         pthread_spin_destroy(lock)
#define cosai_rwlock_init(lock)          pthread_rwlock_init(lock, NULL)
#define cosai_read_lock(lock)            pthread_rwlock_rdlock(lock)
#define cosai_read_unlock(lock)          pthread_rwlock_unlock(lock)
#define cosai_write_lock(lock)           pthread_rwlock_wrlock(lock)
#define cosai_write_unlock(lock)         pthread_rwlock_unlock(lock)
#define cosai_read_lock_irqsave(lock, flags)        (void) flags; pthread_rwlock_rdlock(lock)
#define cosai_read_unlock_irqrestore(lock, flags)   (void) flags; pthread_rwlock_unlock(lock)
#define cosai_write_lock_irqsave(lock, flags)       (void) flags; pthread_rwlock_wrlock(lock)
#define cosai_write_unlock_irqrestore(lock, flags)  (void) flags; pthread_rwlock_unlock(lock)
#define cosai_rwlock_destroy(lock)       pthread_rwlock_destroy(lock)

extern int linuxuser_trylock(pthread_spinlock_t *lock);

/* Mutex */
/* TODO: please add into doc */
#include <pthread.h>
#define cosai_mutex_t                    pthread_mutex_t 
#define cosai_mutex_init(mutex)          pthread_mutex_init(mutex, NULL)
#define cosai_mutex_lock(mutex)          pthread_mutex_lock(mutex)
#define cosai_mutex_trylock(mutex)       linuxuser_mutex_trylock(mutex)
#define cosai_mutex_unlock(mutex)        pthread_mutex_unlock(mutex)
#define cosai_mutex_destroy(mutex)       pthread_mutex_destroy(mutex) 

extern int linuxuser_mutex_trylock(pthread_mutex_t *mutex);

/* Semaphore */
#include <semaphore.h>
#define cosai_sema_t                   sem_t  
#define cosai_sema_init(sema, init)    sem_init(sema, 0, init)
#define cosai_sema_down(sema)          sem_wait(sema)
#define cosai_sema_down_trylock(sema)  linuxuser_sema_down_trylock(sema)
#define cosai_sema_up(sema)            sem_post(sema)
#define cosai_sema_destroy(sema)       sem_destroy(sema)
 
extern int linuxuser_sema_down_trylock(sem_t *sem);

/* Atomics */
#define cosai_atomic_t                int
#define cosai_atomic_get(avar)        (*avar)
#define cosai_atomic_set(val, avar)   *avar = val
#define cosai_atomic_add(val, avar)   __sync_fetch_and_add(avar, val)
#define cosai_atomic_sub(val, avar)   __sync_fetch_and_sub(avar, val)
#define cosai_atomic_inc(avar)        __sync_fetch_and_add(avar, 1)
#define cosai_atomic_dec(avar)        __sync_fetch_and_sub(avar, 1)
#define cosai_atomic_inc_and_test(avar)  (__sync_add_and_fetch(avar, 1) != 0)
#define cosai_atomic_dec_and_test(avar)  (__sync_sub_and_fetch(avar, 1) != 0)

/* Threading */
#include <pthread.h>
#define cosai_thread_t                               linuxuser_thread_t
#define cosai_thread_param_t                         struct sched_param
#define COSAI_SCHED_REALTIME                         SCHED_RR
#define COSAI_SCHED_NORMAL                           SCHED_OTHER
#define COSAI_SCHED_FIFO                             SCHED_FIFO
#define cosai_thread_create(func, data, name)        linuxuser_thread_create(func, data)
#define cosai_thread_create_run(func, data, name)    linuxuser_thread_create(func, data)
#define cosai_thread_get_current()                   linuxuser_thread_self()
#define cosai_thread_should_stop()                   linuxuser_thread_should_stop()
#define cosai_thread_wait(thread)                    linuxuser_thread_wait(thread)
#define cosai_thread_exit()                          linuxuser_thread_exit()
#define cosai_thread_bind(thread)                    linuxuser_thread_bind(thread, cpu)
#define cosai_thread_destroy(thread)                 linuxuser_thread_destroy(thread)
#define cosai_thread_set_scheduler(thread, policy, param) linuxuser_thread_set_scheduler(thread, policy, param)
#define cosai_thread_get_policy(thread)              linuxuser_thread_get_policy(thread)
#define cosai_thread_get_priority(thread)            linuxuser_thread_get_priority(thread)
#define cosai_thread_wake_up(thread)                  
/* move to cosai_internal.h
struct linuxuser_list_head {
  struct linuxuser_list_head *next, *prev;
};

typedef struct _linuxuser_thread {
  pthread_t                  tid;
  int                        stop; //should stop bit
  struct linuxuser_list_head list;
} linuxuser_thread_t;
*/

extern linuxuser_thread_t *linuxuser_thread_create(int (*func)(void *), void *data);
extern linuxuser_thread_t *linuxuser_thread_self(void);
extern int linuxuser_thread_should_stop(void);
extern void linuxuser_thread_exit(void);
extern void linuxuser_thread_bind(linuxuser_thread_t *thread, int cpu);
extern void linuxuser_thread_wait(linuxuser_thread_t *thread);
extern void linuxuser_thread_destroy(linuxuser_thread_t *thread);
extern int linuxuser_thread_set_scheduler(linuxuser_thread_t *thread, int policy, struct sched_param *param);
extern int linuxuser_thread_get_policy(linuxuser_thread_t *thread);

/* Schedule */
#include <unistd.h>
#include <sched.h>
#define cosai_yield()                                   sched_yield()
#define cosai_schedule_timeout_interruptible(timeout)   usleep(timeout) 
#define cosai_sleep(msec)                               usleep(msec*1000)
#define cosai_usleep(usec)                               usleep(usec)
/* TODO: Add into doc */
#define cosai_cpu_relax()                               cpu_relax()

/* Waiting and Event API */
#include <sys/types.h>
/* move to cosai_interal.h
typedef struct {
  pthread_cond_t  cond;
  pthread_mutex_t mutex;
} linuxuser_waitqueue_t;
*/
#define cosai_waitqueue_t              linuxuser_waitqueue_t
#define cosai_init_waitqueue(waitq)    linuxuser_init_waitqueue(waitq)
#define cosai_destroy_waitqueue(waitq) linuxuser_destroy_waitqueue(waitq)
#define cosai_wake_up_waitqueue(waitq) linuxuser_wake_up_waitqueue(waitq)
#define cosai_wake_up_waitqueue_interruptible(waitq) linuxuser_wake_up_waitqueue(waitq)
extern void linuxuser_init_waitqueue(linuxuser_waitqueue_t *waitq);
extern void linuxuser_destroy_waitqueue(linuxuser_waitqueue_t *waitq);
extern void linuxuser_wake_up_waitqueue(linuxuser_waitqueue_t *waitq);

#define cosai_mrevent_t                  int
#define cosai_init_mrevent(event, init_signaled) event = init_signaled
#define cosai_destroy_mrevent(event)
#define cosai_set_mrevent(event)         event = 1 
#define cosai_reset_mrevent(event)       event = 0 
#define cosai_mrevent_is_set(event)      event

#define cosai_wait_mrevent(waitq, event)                                  \
        linuxuser_wait_mrevent(&waitq, event)
#define cosai_wait_mrevent_interruptible(waitq, event)                    \
        linuxuser_wait_mrevent_interruptible(&waitq, event)
#define cosai_wait_mrevent_timeout(waitq, event, timeout)                 \
        linuxuser_wait_mrevent_timeout(&waitq, event, timeout)
#define cosai_wait_mrevent_interruptible_timeout(waitq, event, timeout)   \
        linuxuser_wait_mrevent_interruptible_timeout(&waitq, event, timeout)

extern void linuxuser_wait_mrevent(linuxuser_waitqueue_t *waitq, cosai_mrevent_t event);
extern int linuxuser_wait_mrevent_interruptible(linuxuser_waitqueue_t *waitq, 
                                                cosai_mrevent_t event);
extern int linuxuser_wait_mrevent_timeout(linuxuser_waitqueue_t *waitq, 
                                          cosai_mrevent_t event, 
                                          unsigned long time_ms);
extern int linuxuser_wait_mrevent_interruptible_timeout(linuxuser_waitqueue_t *waitq, 
                                                        cosai_mrevent_t event,
                                                        unsigned long time_ms);

#define cosai_event_t                  soc_event_t
#define cosai_init_event(event, manual_reset, init_signaled) \
        soc_init_event(event, manual_reset, init_signaled)
#define cosai_set_event(event)         soc_set_event(event)
#define cosai_reset_event(event)       soc_reset_event(event)
#define cosai_wait_event(event, timeout, interruptible) \
        soc_wait_event(event, timeout, interruptible)


/* Debugging API */
#include <stdio.h>
#define cosai_print(fmt, ...)       printf(fmt, ##__VA_ARGS__)
#define cosai_error(fmt, ...)       fprintf(stderr, fmt, ##__VA_ARGS__)
#define cosai_debug(fmt, ...)       fprintf(stderr, fmt, ##__VA_ARGS__)
#include <assert.h>
#define cosai_bug_on(cond)          do { \
                                       if (cond) { \
                                         fprintf(stderr, "BUG: failure at %s:%d/%s()!\n", __FILE__, __LINE__, __func__); \
                                         assert(0); \
                                       } \
                                     } while(0)
#define cosai_warn_on(cond)         cosai_error("WARNING: at %s:%d/%s()!\n", __FILE__, __LINE__, __func__)


/* Interrupt */
#include <signal.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define NUM_IRQS         256
#define SIG_ISR          48
typedef int cosai_irqreturn_t;
typedef cosai_irqreturn_t (*linuxuser_irq_handler_t)(int, void *);

#define COSAI_IRQ_NONE          0        
#define COSAI_IRQ_HANDLED       1
#define COSAI_IRQ_WAKE_THREAD   2
typedef linuxuser_irq_handler_t cosai_irq_handler_t;

typedef struct {
    unsigned char           irqnum;
    int                     fd;
    pthread_t               thread;
    cosai_irq_handler_t    irqfunc;
    void *                  data;
} linuxuser_irq_t;

#define cosai_register_irq(irq, handler, name, dev) \
        linuxuser_register_irq(irq, handler, name, dev)
#define cosai_register_threaded_irq(irq, handler, name, dev) \
        linuxuser_register_irq(irq, handler, name, dev)
#define cosai_unregister_irq(irq, dev_id) \
        linuxuser_unregister_irq(irq, dev_id)
#define cosai_enable_irq(irq) \
        linuxuser_enable_irq(irq)
#define cosai_disable_irq(irq) \
        linuxuser_disable_irq(irq)
#define cosai_local_irq_save(flags)       
#define cosai_local_irq_restore(flags)    
extern int linuxuser_register_irq(unsigned int irq, linuxuser_irq_handler_t handler, const char *name, void *data);
extern void linuxuser_unregister_irq(unsigned int irq, void *data);
extern void linuxuser_enable_irq(unsigned int irq);
extern void linuxuser_disable_irq(unsigned int irq);

/* PCI */

#define PCI_BUS(a)  ((a & 0x7FFF0000) >> 16)
#define PCI_DEV(a)  ((a & 0x0000F800) >> 11)
#define PCI_FUNC(a) ((a & 0x00000700) >> 8)

typedef struct linuxuser_pci_dev {
  unsigned int slot_addr; 
  unsigned int irq;
} linuxuser_pci_dev_t;
typedef linuxuser_pci_dev_t cosai_pci_dev_t;
#define cosai_pci_get_device(vendor, device, from)  linuxuser_pci_get_device(vendor, device, from)
#define cosai_pci_get_device_by_bus_and_slot(bus, dev, func)   linuxuser_pci_get_device_from_bus_and_slot(bus, dev, func)
#define cosai_pci_get_device_by_class(arg_class, from)  linuxuser_pci_get_class(arg_class, from)
#define cosai_pci_free_device(device)               linuxuser_pci_free_device(device)
#define cosai_pci_enable_device(dev)                linuxuser_pci_enable_device(dev)
#define cosai_pci_disable_device(dev)               linuxuser_pci_disable_device(dev)
#define cosai_pci_enable_int(dev)                   linuxuser_pci_enable_int(dev)
#define cosai_pci_disable_int(dev)                  linuxuser_pci_disable_int(dev)
#define cosai_pci_get_busnum(dev)                   PCI_BUS(dev->slot_addr)
#define cosai_pci_get_slot(dev)                     PCI_DEV(dev->slot_addr)
#define cosai_pci_get_func(dev)                     PCI_FUNC(dev->slot_addr)
#define cosai_pci_config_read8(dev, where, val)     linuxuser_pci_config_read8(dev, where, val)
#define cosai_pci_config_read16(dev, where, val)    linuxuser_pci_config_read16(dev, where, val)
#define cosai_pci_config_read32(dev, where, val)    linuxuser_pci_config_read32(dev, where, val)
#define cosai_pci_config_write8(dev, where, val)    linuxuser_pci_config_write8(dev, where, val)
#define cosai_pci_config_write16(dev, where, val)   linuxuser_pci_config_write16(dev, where, val)
#define cosai_pci_config_write32(dev, where, val)   linuxuser_pci_config_write32(dev, where, val)
extern linuxuser_pci_dev_t *linuxuser_pci_get_device(unsigned int vender_id, unsigned int device_id, linuxuser_pci_dev_t *from);
extern linuxuser_pci_dev_t *linuxuser_pci_get_device_from_bus_and_slot(unsigned int bus, unsigned int dev, unsigned int func);
extern linuxuser_pci_dev_t *linuxuser_pci_get_device_from_slot(unsigned int bus, unsigned int dev, unsigned int func);
extern void linuxuser_pci_free_device(linuxuser_pci_dev_t *device);
extern linuxuser_pci_dev_t *linuxuser_pci_get_class(unsigned int arg_class, linuxuser_pci_dev_t *from);
extern void linuxuser_pci_enable_device(linuxuser_pci_dev_t *dev); 
extern void linuxuser_pci_disable_device(linuxuser_pci_dev_t *dev);
extern void linuxuser_pci_enable_int(linuxuser_pci_dev_t *dev);
extern void linuxuser_pci_disable_int(linuxuser_pci_dev_t *dev);
extern int linuxuser_pci_config_read8(linuxuser_pci_dev_t *dev, unsigned int where, unsigned char *val);
extern int linuxuser_pci_config_read16(linuxuser_pci_dev_t *dev, unsigned int where, unsigned short *val);
extern int linuxuser_pci_config_read32(linuxuser_pci_dev_t *dev, unsigned int where, unsigned int *val);
extern int linuxuser_pci_config_write8(linuxuser_pci_dev_t *dev, unsigned int where, unsigned char val);
extern int linuxuser_pci_config_write16(linuxuser_pci_dev_t *dev, unsigned int where, unsigned short val);
extern int linuxuser_pci_config_write32(linuxuser_pci_dev_t *dev, unsigned int where, unsigned int val);

/* List */
#define cosai_list_head_t                 struct linuxuser_list_head
#define cosai_init_list_head(list)        linuxuser_init_list_head(list)
#define cosai_list_add_head(entry, list)  linuxuser_list_add_head(entry, list)
#define cosai_list_add_tail(entry, list)  linuxuser_list_add_tail(entry, list)
#define cosai_list_delete(entry)          linuxuser_list_delete(entry)
#define COSAI_LIST_FOR_EACH(pos, list)    \
        for (pos = (list)->next; pos != (list); pos = pos->next)
#define COSAI_LIST_FOR_EACH_SAFE(pos, tmp, list)  \
        for (pos = (list)->next, tmp = pos->next; \
             pos != (list); \
             pos = tmp, tmp = pos->next)
#define cosai_list_empty(list)            linuxuser_list_empty(list)
#define cosai_list_next(entry)            linuxuser_list_next(entry)
#define cosai_list_prev(entry)            linuxuser_list_prev(entry)
#define COSAI_LIST_ENTRY(ptr, type, member)       \
        ((type *)((char *)(ptr)-(size_t)&(((type *)0)->member)))
          
extern void linuxuser_init_list_head(struct linuxuser_list_head *list);
extern void linuxuser_list_add_head(struct linuxuser_list_head *entry, 
                                    struct linuxuser_list_head *list);
extern void linuxuser_list_add_tail(struct linuxuser_list_head *entry, 
                                    struct linuxuser_list_head *list);
extern void linuxuser_list_delete(struct linuxuser_list_head *entry);
extern int linuxuser_list_empty(struct linuxuser_list_head *list);
extern struct linuxuser_list_head *linuxuser_list_next(struct linuxuser_list_head *list);
extern struct linuxuser_list_head *linuxuser_list_prev(struct linuxuser_list_head *list);

/* Work Queue */
/* move to cosai_interal.h
#define NUM_CPU         1
struct linuxuser_work
{
  struct linuxuser_list_head entry;
  void (*func)(struct linuxuser_work *work);
};

struct linuxuser_workqueue
{
  pthread_spinlock_t lock;
  const char *name;
  struct linuxuser_list_head list;   //List of work in the queue
  pthread_t threads[NUM_CPU];
  volatile int stop[NUM_CPU];
};
*/


#define cosai_workqueue_t                     struct linuxuser_workqueue
#define cosai_work_t                          struct linuxuser_work
#define cosai_create_workqueue(name)          linuxuser_create_workqueue(name)
#define cosai_destroy_workqueue(wq)           linuxuser_destroy_workqueue(wq)
#define cosai_init_work(work, func)           linuxuser_init_work(work, func)
#define cosai_queue_work(wq, work)            linuxuser_queue_work(wq, work)

extern struct linuxuser_workqueue *linuxuser_create_workqueue(const char *name);
extern void linuxuser_destroy_workqueue(struct linuxuser_workqueue *wq);
extern void linuxuser_init_work(struct linuxuser_work *work, void (*func)(struct linuxuser_work *));
extern void linuxuser_queue_work(struct linuxuser_workqueue *wq, struct linuxuser_work *work);

/* MISC */
#define cosai_do_div64(n, base)            ({ uint64_t _n; _n=n; n=n/base; _n-n*base;})

#define cosai_container_of(ptr, type, member)       \
        ((type *)((char *)(ptr)-(size_t)&(((type *)0)->member)))

/* error code */
#define cosai_get_last_errcode()               linuxuser_get_retresult()
extern int linuxuser_get_retresult(void);

#ifdef __cplusplus
};
#endif

#endif //_COSAI_H

