/*
#
#  This file is provided under a dual BSD/GPLv2 license.  When using or
#  redistributing this file, you may do so under either license.
#
#  GPL LICENSE SUMMARY
#
#  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of version 2 of the GNU General Public License as
#  published by the Free Software Foundation.
#
#  This program is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
#  The full GNU General Public License is included in this distribution
#  in the file called LICENSE.GPL.
#
#  Contact Information:
#  intel.com
#  Intel Corporation
#  2200 Mission College Blvd.
#  Santa Clara, CA  95052
#  USA
#  (408) 765-8080
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
 *  OSAI Header file for Linux kernel space
 *
 *  Note: cosai_ prefix now is used to differ our names from osal names.
 */

#ifndef _COSAI_H_
#define _COSAI_H_

#ifdef __cplusplus
extern "C" {
#endif

#define LINUX_KERNEL
#define NOT_UPSTREAM

/* Error code */
#include <linux/errno.h>

#define cosai_error_t               int
/* Operation not permitted */
#define COSAI_EPERM                 EPERM
/* No such file or directory */
#define COSAI_NOENT                 ENOENT
/* Bad address */
#define COSAI_FAULT                 EFAULT
/* Out of memory */
#define COSAI_NOMEM                 ENOMEM
/* Only used for wait_event_timeout */
#define COSAI_TIMEOUT               0
/* A signal interrupts */
#define COSAI_INTERRUPTED           ERESTARTSYS

/* Memory management */
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/vmalloc.h>
#include <asm/io.h>
#define cosai_alloc(size)            kmalloc(size, GFP_KERNEL)
#define cosai_zalloc(size)           kzalloc(size, GFP_KERNEL)
#define cosai_free(objp)             kfree(objp)
#define cosai_alloc_nonblock(size)   kmalloc(size, GFP_ATOMIC)
#define cosai_zalloc_nonblock(size)  kzalloc(size, GFP_ATOMIC)
#define cosai_free_nonblock(objp)    kfree(objp)
#define cosai_alloc_page()           __get_free_pages(GFP_KERNEL, 0)
#define cosai_zalloc_page()          get_zeroed_page(GFP_KERNEL)
#define cosai_free_page(objp)        free_pages(objp, 0)
#define cosai_alloc_virtual(size)    vmalloc(size)
#define cosai_free_virtual(objp)     vfree(objp)
#define cosai_memset(mem, c, count)  memset(mem, c, count)
#define cosai_memcpy(dst, src, cnt)  memcpy(dst, src, cnt)
#define cosai_memcmp(m1, m2, cnt)    memcmp(m1, m2, cnt)
#define cosai_virt_to_phys(addr)     virt_to_phys(addr)
#define cosai_phys_to_virt(addr)     phys_to_virt(addr)

/* I/O */
#include <asm/io.h>
#define cosai_read8(addr)            readb(addr)
#define cosai_read16(addr)           readw(addr)
#define cosai_read32(addr)           readl(addr)
#define cosai_write8(value, addr)    writeb(value, addr)
#define cosai_write16(value, addr)   writew(value, addr)
#define cosai_write32(value, addr)   writel(value, addr)

/* Memory Mapping */
#include <linux/types.h>
#include <asm/io.h>
#include <asm/page.h>
#define cosai_phys_addr_t                     phys_addr_t
#define cosai_map_io_cache(base_addr, size)   ioremap_cache(base_addr, size)
#define cosai_map_io_nocache(base_addr, size) ioremap_nocache(base_addr, size)
/* TODO: Add into doc */
#define cosai_map_io_wc(base_addr, size)      ioremap_wc(base_addr, size)
#define cosai_unmap_io(addr, size)            iounmap(addr)
#define cosai_get_page_size()                 PAGE_SIZE

/* Time */
#include <linux/jiffies.h>
#define cosai_get_time()                     jiffies_to_usecs(jiffies)
#define cosai_get_time_in_ms()               jiffies_to_msecs(jiffies)
/* FIXME: precise 64-bit version is not available at Linux. */
#define cosai_get_time64()                   jiffies_to_usecs(get_jiffies_64())
#define cosai_get_time64_in_ms()             jiffies_to_msecs(get_jiffies_64())
/* TODO: Add into doc and user-level */
#include <linux/time.h>
#define cosai_timeval_t                      struct timeval
#define cosai_gettimeofday(tv)               do_gettimeofday(tv)

/* Spin Lock */
#include <linux/spinlock.h>
#define cosai_lock_t                         spinlock_t
#define cosai_rwlock_t                       rwlock_t
#define cosai_irqflag_t                      unsigned long
#define cosai_lock_init(lock, name)          spin_lock_init(lock)
#define cosai_lock(lock)                     spin_lock(lock)
#define cosai_unlock(lock)                   spin_unlock(lock)
#define cosai_trylock(lock)                  spin_trylock(lock)
#define cosai_lock_irqsave(lock, flags)      spin_lock_irqsave(lock, flags)
#define cosai_unlock_irqrestore(lock, flags) spin_unlock_irqrestore(lock, flags)
#define cosai_trylock_irq(lock)              spin_trylock_irq(lock)
#define cosai_lock_destroy(lock)
#define cosai_rwlock_init(lock)              rwlock_init(lock)
#define cosai_read_lock(lock)                read_lock(lock)
#define cosai_read_unlock(lock)              read_unlock(lock)
#define cosai_write_lock(lock)               write_lock(lock)
#define cosai_write_unlock(lock)             write_unlock(lock)
#define cosai_read_lock_irqsave(lock, flags)        read_lock_irqsave(lock, flags)
#define cosai_read_unlock_irqrestore(lock, flags)   read_unlock_irqrestore(lock, flags)
#define cosai_write_lock_irqsave(lock, flags)       write_lock_irqsave(lock, flags)
#define cosai_write_unlock_irqrestore(lock, flags)  write_unlock_irqrestore(lock, flags)
#define cosai_rwlock_destroy(lock)

/* Mutex */
#include <linux/mutex.h>
#define cosai_mutex_t                       struct mutex
#define cosai_mutex_init(mutex)             mutex_init (mutex)
#define cosai_mutex_lock(mutex)             mutex_lock(mutex)
#define cosai_mutex_trylock(mutex)          mutex_trylock(mutex)
#define cosai_mutex_unlock(mutex)           mutex_unlock(mutex)
#define cosai_mutex_destroy(mutex)          mutex_destroy(mutex) 

/* Semaphore */
#include <linux/semaphore.h>
#define cosai_sema_t                  struct semaphore
#define cosai_sema_init(sema, init)   sema_init(sema, init)
#define cosai_sema_down(sema)         down(sema)
#define cosai_sema_down_trylock(sema) down_trylock(sema)
#define cosai_sema_up(sema)           up(sema)
#define cosai_sema_destroy(sema)    

/* Atomics */
#include <asm/atomic.h>
#define cosai_atomic_t                   atomic_t
#define cosai_atomic_get(avar)           atomic_read(avar)
#define cosai_atomic_set(val, avar)      atomic_set(avar, val)
#define cosai_atomic_add(val, avar)      atomic_add(val, avar)
#define cosai_atomic_sub(val, avar)      atomic_sub(val, avar)
#define cosai_atomic_inc(avar)           atomic_inc(avar)
#define cosai_atomic_dec(avar)           atomic_dec(avar)
#define cosai_atomic_inc_and_test(avar)  atomic_inc_and_test(avar)
#define cosai_atomic_dec_and_test(avar)  atomic_dec_and_test(avar)

/* Threading */
#include <linux/kthread.h>
#include <linux/sched.h>
#define cosai_thread_t                               struct task_struct
#define cosai_thread_param_t                         struct sched_param
#define COSAI_SCHED_REALTIME                         SCHED_RR
#define COSAI_SCHED_NORMAL                           SCHED_NORMAL
#define COSAI_SCHED_FIFO                             SCHED_FIFO
#define cosai_thread_create(func, data, name)        kthread_create(func, data, "%s", name)
#define cosai_thread_create_run(func, data, name)    kthread_run(func, data, "%s", name)
#define cosai_thread_get_current()                   get_current()
#define cosai_thread_should_stop()                   kthread_should_stop()
#define cosai_thread_wait(thread)                    kthread_stop(thread)
#define cosai_thread_exit()
#define cosai_thread_bind(thread)                    kthread_bind(thread, cpu)
#define cosai_thread_destroy(thread)
#define cosai_thread_set_scheduler(thread, policy, param) sched_setscheduler(thread, policy, param)
#define cosai_thread_get_policy(thread)              thread->policy
#define cosai_thread_get_priority(thread)            thread->prio
#define cosai_thread_wake_up(thread)                 wake_up_process(thread)

/* Schedule */
#include <linux/sched.h>
#include <linux/delay.h>
#include <asm/processor.h>
#define cosai_yield()                                    sched_yield()
#define cosai_schedule_timeout_interruptible(timeout)    schedule_timeout_interruptible(timeout)
#define cosai_sleep(msec)                                msleep_interruptible(msec)
/* TODO: Add into doc and user-level */
#define cosai_usleep(usec)                               udelay(usec)
#define cosai_cpu_relax()                                cpu_relax() 

/* Waiting and Event */
#include <linux/wait.h>
#define cosai_waitqueue_t              wait_queue_head_t
#define cosai_init_waitqueue(waitq)    init_waitqueue_head(waitq)
#define cosai_destroy_waitqueue(waitq)
#define cosai_wake_up_waitqueue(waitq) wake_up(waitq)
#define cosai_wake_up_waitqueue_interruptible(waitq) wake_up_interruptible(waitq)

#define cosai_mrevent_t                  int 
#define cosai_init_mrevent(event, init_signaled) event = init_signaled
#define cosai_destroy_mrevent(event)
#define cosai_set_mrevent(event)         event = 1 
#define cosai_reset_mrevent(event)       event = 0 
#define cosai_mrevent_is_set(event)      event
#define cosai_wait_mrevent(waitq, event)                                wait_event(waitq, event)
#define cosai_wait_mrevent_timeout(waitq, event, timeout)               wait_event_timeout(waitq, event, msecs_to_jiffies(timeout))
#define cosai_wait_mrevent_interruptible(waitq, event)                  wait_event_interruptible(waitq, event)
#define cosai_wait_mrevent_interruptible_timeout(waitq, event, timeout) wait_event_interruptible_timeout(waitq, event, msecs_to_jiffies(timeout))

/* Extension to Linux manual events. soc_utils.a is required to use them */
#define cosai_event_t                                         soc_event_t
#define cosai_init_event(event, manual_reset, init_signaled)  soc_init_event(event, manual_reset, init_signaled)
#define cosai_set_event(event)                                soc_set_event(event)
#define cosai_reset_event(event)                              soc_reset_event(event)
#define cosai_wait_event(event, timeout, interruptible)       soc_wait_event(event, timeout, interruptible)
#define cosai_destroy_event(event)                            soc_destroy_event(event)

/* Debugging API */
#include <linux/kernel.h>
#define cosai_print(fmt, ...)   printk(fmt, ##__VA_ARGS__)
#define cosai_error(fmt, ...)   pr_err(fmt, ##__VA_ARGS__)
#define cosai_debug(fmt, ...)   pr_debug(fmt, ##__VA_ARGS__)
#include <asm/bug.h>
#define cosai_bug_on(cond)      BUG_ON(cond)
#define cosai_warn_on(cond)     WARN_ON(cond)

/* Interrupt */
#include <linux/interrupt.h>
#define NUM_IRQS                 256
#define cosai_irqreturn_t       irqreturn_t
#define COSAI_IRQ_NONE          IRQ_NONE
#define COSAI_IRQ_HANDLED       IRQ_HANDLED
#define COSAI_IRQ_WAKE_THREAD   IRQ_WAKE_THREAD
#define cosai_irq_handler_t     irq_handler_t
#define cosai_register_irq(irq, handler, name, dev)          request_irq(irq, handler, IRQF_SHARED, name, dev)
/* TODO: add into doc */
#define cosai_register_threaded_irq(irq, handler, func, name, dev) request_threaded_irq(irq, handler, func, IRQF_SHARED, name, dev)
#define cosai_unregister_irq(irq, dev_id) free_irq(irq, dev_id)
#define cosai_enable_irq(irq)             enable_irq(irq)
#define cosai_disable_irq(irq)            disable_irq(irq)
#define cosai_local_irq_save(flags)       local_irq_save(flags)
#define cosai_local_irq_restore(flags)    local_irq_restore(flags)

/* PCI */
#include <linux/pci.h>
#define cosai_pci_dev_t                   struct pci_dev
#define cosai_pci_get_device(vendor, device, from)  pci_get_device(vendor, device, from)
#define cosai_pci_get_device_by_bus_and_slot(bus, dev, func)   pci_get_bus_and_slot(bus, func)
#define cosai_pci_get_device_by_class(class, from)  pci_get_class(class, from)
#define cosai_pci_free_device(device)          
#define cosai_pci_enable_device(dev)                pci_enable_device(dev)
#define cosai_pci_disable_device(dev)               pci_disable_device(dev)
#define cosai_pci_enable_int(dev)                   pci_intx(dev, 1)
#define cosai_pci_disable_int(dev)                  pci_intx(dev, 0)
#define cosai_pci_get_busnum(dev)                   dev->bus->number
#define cosai_pci_get_slot(dev)                     PCI_SLOT(dev->devfn)
#define cosai_pci_get_func(dev)                     PCI_FUNC(dev->devfn)
#define cosai_pci_config_read8(dev, where, val)     pci_read_config_byte(dev, where, val)
#define cosai_pci_config_read16(dev, where, val)    pci_read_config_word(dev, where, val)
#define cosai_pci_config_read32(dev, where, val)    pci_read_config_dword(dev, where, val)
#define cosai_pci_config_write8(dev, where, val)    pci_write_config_byte(dev, where, val)
#define cosai_pci_config_write16(dev, where, val)   pci_write_config_word(dev, where, val)
#define cosai_pci_config_write32(dev, where, val)   pci_write_config_dword(dev, where, val)


/* List */
#include <linux/list.h>
#define cosai_list_head_t                         struct list_head
#define cosai_init_list_head(list)                INIT_LIST_HEAD(list)
#define cosai_list_add_head(entry, list)          list_add(entry, list)
#define cosai_list_add_tail(entry, list)          list_add_tail(entry, list)
#define cosai_list_delete(entry)                  list_del(entry)
#define COSAI_LIST_FOR_EACH(pos, list)            list_for_each(pos, list)
#define COSAI_LIST_FOR_EACH_SAFE(pos, tmp, list)  list_for_each_safe(pos, tmp, list)
#define cosai_list_empty(list)                    list_empty(list)
#define cosai_list_next(entry)                    entry->next
#define cosai_list_prev(entry)                    entry->prev
#define COSAI_LIST_ENTRY(ptr, type, member)       list_entry(ptr, type, member)


/* Work Queue */
#include <linux/workqueue.h>
#define cosai_workqueue_t                     struct workqueue_struct
#define cosai_work_t                          struct work_struct
#define cosai_create_workqueue(name)          create_workqueue(name)
#define cosai_destroy_workqueue(wq)           destroy_workqueue(wq)
#define cosai_init_work(work, func)           INIT_WORK(work, func)
#define cosai_queue_work(wq, work)            queue_work(wq, work)


/* MISC */
#include <asm/div64.h>
#define cosai_do_div64(n, base)           do_div(n, base)

#include <linux/kernel.h>
#define cosai_container_of(ptr, type, member)   container_of(ptr, type, member)


#ifdef __cplusplus
};
#endif

#endif //_COSAI_H
