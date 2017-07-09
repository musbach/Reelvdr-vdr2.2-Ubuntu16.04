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

/*------------------------------------------------------------------------------
 * File Name: idl_smartcard_drv.c
 *------------------------------------------------------------------------------
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/proc_fs.h>
#include <linux/wait.h>
#include <linux/pci.h>

#include <asm/uaccess.h>
#include <asm/irq.h>
#include <asm/io.h>

#include <osal_event.h>
#include <osal_sema.h>

#include <_smartcard.h>
#include <idl_smartcard.h>
#include <idl_smartcard_core.h>

#include <pal.h>
  
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,28)
    #include <asm/semaphore.h>
#else
    #include <linux/semaphore.h>
#endif

#ifdef DEBUG
#define scard_dbg(fmt, args...) do \
  { \
	      printk(KERN_INFO fmt, ##args); \
  } while(0)
#else
#define scard_dbg(fmt, arg...)
#endif

/* Driver identification */
 MODULE_AUTHOR("Intel Corporation, (C) 2006 - 2010 - All Rights Reserved");
 MODULE_DESCRIPTION("IDL SMARTCARD Device Driver for Linux 2.6");
 MODULE_SUPPORTED_DEVICE("Intel Media Processors");
 MODULE_LICENSE("Dual BSD/GPL"); /* Inform kernel that driver is not GPL. */

/* Unique name for driver */
static char *devname[] = {"scard0", "scard1"};

#ifndef MOD_NAME
#define MOD_NAME "idl_smartcard.ko"
#endif

char *version_string = "#@#" MOD_NAME " " VER;


/* This function is the first function called to load the driver after an insmod */
/* command */

int
scard_init(void);

/* This function is the first function called to unload the driver after an rmmod */
/* command */

void
scard_cleanup(void);

/* This function is called when an application tries to open a connection to the */
/* driver */

int
scard_open(struct inode *p_inode, struct file *p_file);

/* This function is called when an application disconnects from the driver */

int
scard_close(struct inode *p_inode, struct file *p_file);

/* This function is called when an application tries to open a connection to the */
/* driver */

int
scard1_open(struct inode *p_inode, struct file *p_file);

/* This function is called when an application disconnects from the driver */

int
scard1_close(struct inode *p_inode, struct file *p_file);


/* This function is called when an application requests that the driver performs a */
/* task or service on the application's behalf */

int
scard_ioctl(/*struct inode *p_inode,*/ struct file *p_file, u_int command, u_long p_args);

/* Specify driver entry points for kernel */
/* Macros are defined in linux/module.h */
module_init(scard_init);
module_exit(scard_cleanup);

static void smcard_handler(unsigned long ingnored);
static void irq_handler(void *data);
static struct timer_list smcard_event_timer[SC_MAX_SLOTS_SUPPORTED] = { \
	TIMER_INITIALIZER(smcard_handler, 0, 0), 
	TIMER_INITIALIZER(smcard_handler, 0, 1)  
};
static int TIME_INTERVAL_SM = 50;

static sc_slot_info_t g_slot_info[SC_MAX_SLOTS_SUPPORTED];

static bool device_open_count[SC_MAX_SLOTS_SUPPORTED]={false, false};
static bool device_initialized[SC_MAX_SLOTS_SUPPORTED]={false, false};

/* This is the major number assigned dynamically assigned by Linux */
/* This number is required by the mknod command */
static int m_scard_major_number[SC_MAX_SLOTS_SUPPORTED];

static struct pci_driver scard_pci_driver;
/* Structure to map driver functions to kernel */
struct file_operations m_scard_ops = { 	
        .owner   = THIS_MODULE,
        .unlocked_ioctl   = scard_ioctl, 
        .open    = scard_open, 
        .release = scard_close,
};

uint32_t scard_irq;

/*------------------------------------------------------------------------------
 * Support structure for interrupt callback mechanism
 *------------------------------------------------------------------------------
 */
static os_event_t scard_interrupt_start[SC_MAX_SLOTS_SUPPORTED];
static os_event_t scard_interrupt_done[SC_MAX_SLOTS_SUPPORTED];
#define SCARD_INTERRUPT_START_LENGTH (sizeof(scard_interrupt_start)/sizeof(scard_interrupt_start[0]))
/*------------------------------------------------------------------------------
 * Functions to support interrupt callback mechanism
 *------------------------------------------------------------------------------
 */

 /*------------------------------------------------------------------------------
 * Functions to support interrupt callback mechanism
 *------------------------------------------------------------------------------
 */
static uint32_t event_status[SC_MAX_SLOTS_SUPPORTED];
static int	has_event_handler[SC_MAX_SLOTS_SUPPORTED];
/* Interrupt handler for SmartCard  - using os_acquire interrupt */
void irq_handler(void *data)
{
	 uint32_t irq_status=0;
     int slot = (int)data;	
	_scard_get_interrupt_status((uint8_t)slot, &irq_status);

	if( irq_status == 0)
		return;

  	event_status[slot] = irq_status;
		
   	//del_timer(&smcard_event_timer);
	if(has_event_handler[slot] && (irq_status & SC_EVENT_CARD_DET))
	{
   		mod_timer(&smcard_event_timer[slot], jiffies + TIME_INTERVAL_SM);
	}
   	sc_infc_clear_event(slot, irq_status & SC_EVENT_MASK);
}
/* handler for timer, check whether a smartcard event happenned or not*/
void smcard_handler(unsigned long data)
{
   int slot = (int)data;
   sc_slot_info_t t_slot_info;
   // check whether the status is changed.   yes to continue, no to abort.
   sc_infc_get_slot_info(slot, &t_slot_info);
   if (t_slot_info.status == g_slot_info[slot].status)
      return;
   g_slot_info[slot].status = t_slot_info.status;
   // end check

   os_event_set(&scard_interrupt_start[slot]);
}       

/*------------------------------------------------------------------------------
 * scard_init
 *------------------------------------------------------------------------------
 */
int
scard_init(void)
{
    int  slot;
	int retval = 0;
	int num_devs_ok=0;
	retval = pci_register_driver(&scard_pci_driver);
	if (retval) {
		printk(KERN_ERR "Smartcard pci register failure\n");
		return retval;
	}
	m_scard_major_number[0]  = 0;
    for (slot = 0; slot < SC_MAX_SLOTS_SUPPORTED; slot++) {
     	/* Register the device with the operating system */	
        if ((m_scard_major_number[slot] = __register_chrdev(m_scard_major_number[0], slot,1,devname[slot], &m_scard_ops)) < 0) {
        	printk(KERN_ERR "%s:%4i: scard_init failed\n", __FILE__, __LINE__);
			continue;
        }
        if (sc_infc_init(slot) < 0) {
        	 printk(KERN_ERR "%s:%4i: IDL SmartCard initialization failed.\n",  __FILE__, __LINE__);
			 continue;
        }
        /* initialize event handlers prior to enabling interrupts */       

        os_event_create(&scard_interrupt_start[slot], 0);
        os_event_create(&scard_interrupt_done[slot], 0);
		device_initialized[slot] = true;
		num_devs_ok++;
    }
	if(!num_devs_ok)
	{
		pci_unregister_driver(&scard_pci_driver);
		return -ENODEV;
	}
    return 0;
}
        
/*------------------------------------------------------------------------------
 * scard_open
 *------------------------------------------------------------------------------
 */

void
scard_cleanup(void)
{
    int  slot;

	for (slot = SC_MAX_SLOTS_SUPPORTED; slot > 0;) {
    	/* release smartcard */
		--slot;
		if(device_initialized[slot])
		{
			sc_infc_deinit(slot);

	        /* destroy event handlers */
		    os_event_destroy(&scard_interrupt_start[slot]);
			os_event_destroy(&scard_interrupt_done[slot]);

			/* un-register the device from operating system */
			__unregister_chrdev(m_scard_major_number[0],slot,1, devname[slot]);
		}
   }
   pci_unregister_driver(&scard_pci_driver);
}
/*--------------------------------------------------
 * get-slot
 *-------------------------------------------------*/
static unsigned inline get_slot(struct inode *p_inode)
{
	return iminor(p_inode);
}
static int register_event_handler(int slot)
{
     if (sc_infc_register_event_handler(slot, &irq_handler, (void *)slot) < 0) 
	{
        	return -EINVAL;
        }
	return 0;
}
/*------------------------------------------------------------------------------
 * scard_open
 *------------------------------------------------------------------------------
 */

int
scard_open(struct inode *p_inode, struct file *p_file)
{
	unsigned slot = get_slot(p_inode);
	if(slot >= SC_MAX_SLOTS_SUPPORTED)
	{
		printk("%s: Wrong slot number\n",__FUNCTION__);
		return -ENODEV;
	}
	if(device_open_count[slot]){
        	printk("The smartcard decice has already been opened!\n");
            return -1;
        }
        else
        {
		int ret=register_event_handler(slot);
		if(ret)
			return ret;
        	set_scard_alt_fun_pin(slot ? 11: 19, 1);
		device_open_count[slot]=true;
		has_event_handler[slot]=false; 
   		mod_timer(&smcard_event_timer[slot], jiffies + TIME_INTERVAL_SM);
        }
        return 0;
}
        
/*------------------------------------------------------------------------------
 * scard_close
 *------------------------------------------------------------------------------
 */
        
int
scard_close(struct inode *p_inode, struct file *p_file)
{
	unsigned slot = get_slot(p_inode);
	if(slot >= SC_MAX_SLOTS_SUPPORTED)
	{
		printk("%s: Wrong slot number\n",__FUNCTION__);
		return -ENODEV;
	}
       if(!device_open_count[slot]){
               printk("The smartcard decice has already been closed!\n");
               return -1;
               }
       	set_scard_alt_fun_pin(slot ? 11: 19, 0);
        device_open_count[slot]=false;
	has_event_handler[slot]=false; 
        sc_infc_release_event_handler(slot);
        return 0;
}
        





/*------------------------------------------------------------------------------
 * scard_ioctl
 *------------------------------------------------------------------------------
 */
int
scard_ioctl(/*struct inode *p_inode,*/ struct file *p_file, u_int command, u_long p_args)
{
        uint8_t           slot;
        int               status = 0;
		sc_ioctl_args_t   params;
		uint32_t		  v32;

        /* Check to see if the ioctl command is meant for this device */
        if (_IOC_TYPE(command) != SC_IOCTL_MAGIC) {
                printk(KERN_ERR "%s:%4i:  scard_ioctl failed\n", __FILE__, __LINE__);
                return -ENOTTY;
        }
        
		if(copy_from_user(&params,(void *)p_args,sizeof(params)))
		{
            printk(KERN_ERR "%s:%4i:  scard_ioctl failed\n", __FILE__, __LINE__);
			return -EINVAL;
		}
        if(copy_from_user(&slot,(void *)params.p_params[0],sizeof(slot)))
			return -EINVAL;
		if(slot != get_slot(/*p_inode*/p_file->f_dentry->d_inode))
			return -ENODEV;
        /* Execute ioctl request */
        switch (command) {
                case SC_IOCTL_GET_SLOT_INFO:
					{
						sc_slot_info_t si;
                        if (sc_infc_get_slot_info(slot,&si))
							status =  -EINVAL;
						else if(copy_to_user((void *)params.p_params[1],&si,sizeof(si)))
							status = -EINVAL;                   
					}
                    break;
                case SC_IOCTL_GET_TX_LENGTH:
                        if (sc_infc_get_tx_length(slot,&v32))
							status = -EINVAL;
						else if(copy_to_user((void *)params.p_params[1],&v32,sizeof(v32)))
							status = -EINVAL;
                        break;
                case SC_IOCTL_GET_RX_LENGTH:
                        if (sc_infc_get_rx_length(slot,&v32))
                                status = -EINVAL;
						else if(copy_to_user((void *)params.p_params[1],&v32,sizeof(v32)))
							status = -EINVAL;
                        break;
                case SC_IOCTL_RESET_RXFIFO:
                        if (sc_infc_reset_rx_fifo(slot)<0)
                                status = -EINVAL;
                        break;
                case SC_IOCTL_RESET_TXFIFO:
                        if (sc_infc_reset_tx_fifo(slot))
                                status = -EINVAL;
                        break;

                case SC_IOCTL_START_SECTION:
						{
						sc_section_t st;
						if(copy_from_user(&st,(void *)params.p_params[1],sizeof(st)))
							status = -EINVAL;
						else if((status = sc_infc_start_section(slot,&st)) < 0)
							;
						else if(copy_to_user((void *)params.p_params[1],&st,sizeof(st)))
								status = -EINVAL;
						}
                        break;

                case SC_IOCTL_REGISTER_EVENT_HANDLER:
						has_event_handler[slot] = 1;
                        break;

                case SC_IOCTL_RELEASE_EVENT_HANDLER:
						has_event_handler[slot] = 0;
                        break;

                case SC_IOCTL_WAIT_FOR_EVENT:            
                        if ( (os_event_wait(&scard_interrupt_start[slot], -1) != OSAL_SUCCESS) ) {
                                status = -ERESTARTSYS;
                        }
                        else {
                                os_event_reset(&scard_interrupt_start[slot]);
                        }

                        break;

                case SC_IOCTL_RELEASE_EVENT:
                        os_event_set(&scard_interrupt_start[slot]);
                        break;

                case SC_IOCTL_NOTIFY_EVENT_DONE:
                        /* clear events that already processed by application */
						if(copy_from_user(&v32,(void *)params.p_params[1],sizeof(v32)))
							status =  -EINVAL;
						else if (v32 != 0) {
                                if(sc_infc_clear_event(slot, v32))
									status = -EINVAL;
                        }
                        os_event_set(&scard_interrupt_done[slot]);
                        break;

                case SC_IOCTL_CLEAR_EVENT:
						if(copy_from_user(&v32,(void *)params.p_params[1],sizeof(v32)))
							status =  -EINVAL;
                        else if (sc_infc_clear_event(slot,v32))
                                status = -EINVAL;
                        break;
                case SC_IOCTL_GET_EVENT_STATUS:
					v32 = event_status[slot];
					if(copy_to_user((void*)params.p_params[1],&v32,sizeof(v32)))
						status = -EINVAL;
					break;
                case SC_IOCTL_READ:
					if(copy_from_user(&v32,(void *)params.p_params[2],sizeof(v32)))
						status =  -EINVAL;
					else
					{
						unsigned char *p = vmalloc(v32);
						if(p)
						{
							status = sc_infc_read(slot,p,v32,&v32);
							if(status >= 0)
							{
								if(v32)
									copy_to_user((void *)params.p_params[1],p,v32);
								copy_to_user((void *)params.p_params[3],&v32,sizeof(v32));
							}
							vfree(p);
						} else
							status = -ENOMEM;
					}
                    break;

                case SC_IOCTL_WRITE:
					if(copy_from_user(&v32,(void *)params.p_params[2],sizeof(v32)))
						status =  -EINVAL;
					else
					{
						unsigned char *p = vmalloc(v32);
						if(p)
						{
							if(copy_from_user(p,(void *)params.p_params[1],v32))
							{
								status = -EINVAL;
								vfree(p);
								break;
							}
							status = sc_infc_write(slot,p, v32,&v32);
							vfree(p);
							if(copy_to_user((void *)params.p_params[3],&v32,sizeof(v32)))
								status = -EINVAL;
						} else
							status = -ENOMEM;
					}
					break;

                case SC_IOCTL_DEACTIVATE:
                        if (sc_infc_card_deactivate(slot)<0)
                                status = -EINVAL;
                        break;
                case SC_IOCTL_CARD_REMOVAL: 
                        if (sc_infc_card_removal(slot)<0)
                                status = -EINVAL;
                        break;
                case SC_IOCTL_WARM_RESET: 
                        if (sc_infc_warm_reset(slot)<0)
                                status = -EINVAL;
                        break;
                case SC_IOCTL_SET_IO_MODE: 
						if(copy_from_user(&v32,(void *)params.p_params[1],sizeof(v32)))
							status =  -EINVAL;
						else if (sc_infc_set_iomode(slot,v32)<0)
                            status = -EINVAL;
                        break;
                case SC_IOCTL_SET_CWTR: 
						if(copy_from_user(&v32,(void *)params.p_params[1],sizeof(v32)))
							status =  -EINVAL;
                        else if (sc_infc_set_cwt(slot,v32)<0)
                                status = -EINVAL;
                        break;
                case SC_IOCTL_SET_BWTR: 
						if(copy_from_user(&v32,(void *)params.p_params[1],sizeof(v32)))
								status =  -EINVAL;
                        else if (sc_infc_set_bwt(slot,v32)<0)
                                status = -EINVAL;
                        break;
                case SC_IOCTL_SET_TOR: 
						if(copy_from_user(&v32,(void *)params.p_params[1],sizeof(v32)))
								status =  -EINVAL;
                        else if (sc_infc_set_tor(slot,v32)<0)
                                status = -EINVAL;
                        break;
                case SC_IOCTL_SET_CLOCK: 
						if(copy_from_user(&v32,(void *)params.p_params[1],sizeof(v32)))
								status =  -EINVAL;
                        else if (sc_infc_set_clk_divisor(slot,v32)<0)
                                status = -EINVAL;
                        break;
                case SC_IOCTL_SET_BGTR: 
						if(copy_from_user(&v32,(void *)params.p_params[1],sizeof(v32)))
								status =  -EINVAL;
                        else  if (sc_infc_set_bgtr(slot,v32)<0)
                                status = -EINVAL;
                        break;
                case SC_IOCTL_SET_EGTR: 
						if(copy_from_user(&v32,(void *)params.p_params[1],sizeof(v32)))
								status =  -EINVAL;
                        else if (sc_infc_set_egtr(slot,v32)<0)
                                status = -EINVAL;
                        break;
                case SC_IOCTL_SET_ETU:
					{
						uint32_t divisor, factor,c_div;
						if(copy_from_user(&c_div,(void *)params.p_params[1],sizeof(uint32_t))
							||copy_from_user(&divisor,(void *)params.p_params[2],sizeof(uint32_t))
							||copy_from_user(&factor,(void *)params.p_params[3],sizeof(uint32_t)))
						{
							status = -EINVAL;
							break;
						}
                        if (sc_infc_set_etu(slot,c_div,divisor,factor)<0)
                                status = -EINVAL;
					}
                        break;			
                case SC_IOCTL_ADJUST_RESET_DELAY:
						if(copy_from_user(&v32,(void *)params.p_params[1],sizeof(v32)))
								status =  -EINVAL;
                        else if (sc_infc_adjust_reset_delay(slot,v32)<0)
                                status = -EINVAL;
                        break;

#if 0
                case IOCTL_SMARTCARD_GET_FEATURE:
						params.result = idl_sc_get_feature(slot);
                        if ( ((idl_smartcard_ioctl_args_t *)p_args)->result != IDL_SUCCESS ) {
                                status = -EINVAL;
                        }
                        break;

                case IOCTL_SMARTCARD_RESET_CONFIG:
                        ((idl_smartcard_ioctl_args_t *)p_args)->result = idl_sc_reset_config(
                                *((uint32_t *) (((idl_smartcard_ioctl_args_t *)p_args)->p_params[0])));
                        
                        if ( ((idl_smartcard_ioctl_args_t *)p_args)->result != IDL_SUCCESS ) {
                                status = -EINVAL;
                        }

                        break;
					
                case SC_IOCTL_SET_RX_TRIGGER_LEVEL:
                        if (sc_infc_set_rx_trigger_level(
                                    *((uint8_t *) (((sc_ioctl_args_t *)p_args)->p_params[0])),
                                    *((uint16_t *) (((sc_ioctl_args_t *)p_args)->p_params[1]))) < 0) {
                                status = -EINVAL;
                        }

                        break;

                case SC_IOCTL_SET_TX_TRIGGER_LEVEL:
                        if (sc_infc_set_tx_trigger_level(
                                    *((uint8_t *) (((sc_ioctl_args_t *)p_args)->p_params[0])),
                                    *((uint16_t *) (((sc_ioctl_args_t *)p_args)->p_params[1]))) < 0) {
                                status = -EINVAL;
                        }

                        break;
#endif
				case SC_IOCTL_SET_PROTOCOL:
						if(copy_from_user(&v32,(void *)params.p_params[1],sizeof(v32)))
								status =  -EINVAL;
                        else if (sc_infc_set_protocol(slot,v32)<0)
                                status = -EINVAL;
                        break;

                default:
                        /* POSIX compliance return returning -ENOTTY if invalid */
                        status = -ENOTTY;
        }

        return (status);
}

static const struct pci_device_id scard_id_tables[] __devinitdata = {
{ PCI_DEVICE(0x8086, 0x2e69), },
{0 },
};
MODULE_DEVICE_TABLE(pci, scard_id_tables);


static int __init scard_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
  	pal_soc_info_t pal_info;
	pal_soc_name_t soc;
	int retval = 0;
	if (PAL_SUCCESS != pal_get_soc_info(&pal_info)) {
		printk(KERN_ERR "Can't get SOC_INFO!\n");
		return -1;
	}
	soc = pal_info.name;
	switch (soc) {
	 		case SOC_NAME_CE3100:
				 printk(KERN_ERR "CE3100 Smartcard found currently!\n");
				 break;
			case SOC_NAME_CE4100:
			     printk(KERN_ERR "CE4100 Smartcard found currently!\n");
				 break;
			case SOC_NAME_CE4200:
			     printk(KERN_ERR "CE4200 Smartcard found currently!\n");
				 break;
			case SOC_NAME_CE5300:
			     printk(KERN_ERR "CE5300 Smartcard found currently!\n");
				 break;
			default:
			     printk(KERN_ERR "The platform is not recognized!\n");
		  		 retval = -1;
				 break;
	}	
	if (retval) return retval;
	pci_enable_device(pdev);
	pci_intx(pdev, 1);
	scard_irq = pdev->irq;
	scard_dbg("Smartcard irq line is %d\n", scard_irq);
	pci_dev_get(pdev);
    return retval;
}

static void __exit scard_pci_remove(struct pci_dev *pdev)
{

	pci_disable_device(pdev);
	pci_intx(pdev, 0);
	pci_dev_put(pdev);
	scard_irq = 0;
}
#ifdef CONFIG_PM  
/* scard pci device suspend */
static int scard_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
    int  slot = 0;
  	int retval = 0;
    /*smartcard suspend */
    for (slot=0; slot < SC_MAX_SLOTS_SUPPORTED; slot++) {
		retval = sc_infc_suspend(slot);
		if (retval) return retval;
	}	
	/*pci device save*/
	pci_save_state(pdev);
	pci_disable_device(pdev);
	pci_set_power_state(pdev, pci_choose_state(pdev, state));
	return retval;
}

/* scard pci device resume */
static int scard_pci_resume(struct pci_dev *pdev)
{
    int  slot = 0;
    int retval = 0;
	/*pci device restore*/
	pci_set_power_state(pdev, PCI_D0);
	pci_restore_state(pdev);
	retval = pci_enable_device(pdev);
	if (retval)
	   	 return retval;
    /*smartcard resume */
    for (slot=0; slot < SC_MAX_SLOTS_SUPPORTED; slot++) {
		retval = sc_infc_resume(slot);
		if (retval) return retval;
	}	
    return retval;
}
#endif
static struct pci_driver scard_pci_driver = {
	.name = "scard_pci_driver",
	.id_table = scard_id_tables,
	.probe = scard_pci_probe,
	.remove = scard_pci_remove,
#ifdef CONFIG_PM
	.suspend = scard_pci_suspend,
	.resume = scard_pci_resume,
#endif
};

