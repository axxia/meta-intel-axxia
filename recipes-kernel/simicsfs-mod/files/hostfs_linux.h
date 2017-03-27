/*
   hostfs for Linux
   Copyright 2001 - 2006 Virtutech AB
   Copyright 2001 SuSE

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
   NON INFRINGEMENT.  See the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef HOSTFS_H
#define HOSTFS_H 1

#include <linux/version.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 19)
  /* linux/config.h has been deprecated way before 2.6.19, but has at least
     worked. Starting with 2.6.19 it does not */
#include <linux/config.h>
#endif

#define DEVICE_NAME "[simicsfs]"

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 11)
#error "Unsupported kernel version"
#endif

#include <linux/sched.h>
#include <linux/version.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/pagemap.h>
#include <linux/fs.h>
#include <linux/aio.h>
#include <linux/unistd.h>
#include <linux/errno.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 16)
#include <asm/io.h>
#else
#include <linux/io.h>
#endif
#include <linux/init.h>
#include <linux/statfs.h>

#define TARGETOS_LINUX
#include "hostfs.h"
#include "hostfs_data.h"

#define GET_HI_LO(tgt, src) do {					  \
	typedef int check_tgt_size[sizeof(tgt) == 8 || sizeof(tgt) == 4	  \
				   ? 1 : -1] __attribute__((unused));	  \
	if (sizeof(tgt) == 4)						  \
		tgt = src ## _lo;					  \
	else if (sizeof(tgt) == 8) {					  \
		tgt = src ## _hi;					  \
		tgt <<= 16;						  \
		tgt <<= 16;						  \
		tgt |= src ## _lo;					  \
	}								  \
} while (0)

#define SET_HI_LO(tgt, src) do {					  \
	typedef int check_src_size[sizeof(src) == 8 || sizeof(src) == 4	  \
				   ? 1 : -1] __attribute__((unused));	  \
	if (sizeof(src) == 4) {						  \
		tgt ## _lo = src;					  \
		tgt ## _hi = 0;						  \
	} else if (sizeof(src) == 8) {					  \
		unsigned long long tmp = src;				  \
		tgt ## _lo = (uint)src;					  \
		tgt ## _hi = tmp >> 32;					  \
	}								  \
} while (0)

#define DEBUG_LEVEL 0
#define HOSTFS_BLOCK_BITS 10
#define HOSTFS_BLOCK_SIZE (1 << HOSTFS_BLOCK_BITS)

#define HOSTFS_ROOT_INO 1

#define DPRINTINODE1(inode) do {			\
	if (DEBUG_LEVEL >= 1)				\
		print_inode(inode);			\
} while (0)

#define DPRINTFILE1(file) do { } while (0)

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define NTOHSWAP(field) do {						\
	int __i;							\
	for (__i = 0; __i < (sizeof(field) + 3) / 4; ++__i) {		\
		((uint *)&field)[__i] = ntohl(((uint *)&field)[__i]);	\
	}								\
} while (0)

#define HTONSWAP(field) NTOHSWAP(field)

extern const struct file_operations hostfs_file_fops;
extern const struct file_operations hostfs_file_dirops;

int hostfs_revalidate_inode(struct inode *inode);
void hostfs_read_inode(struct inode *inode);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 34)
int hostfs_write_inode(struct inode *inode, struct writeback_control *wbc);
#else
int hostfs_write_inode(struct inode *inode, int sync);
#endif

extern spinlock_t get_host_data_lock;
extern spinlock_t hostfs_position_lock;

/* host interface */
int get_host_data(enum host_func func, uint hnode, void *in_buf, void *out_buf);
int hf_do_seek(ino_t inode, loff_t off);
int init_host_fs(void);

#endif
