/*
   hostfs for Linux
   Copyright 2001-2006 Virtutech AB

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

#ifndef _HOST_FS_H
#define _HOST_FS_H

#define HOSTFS_VERSION 1
/* update before release, reset to 99 when done */
#define HOSTFS_SUBVERSION 21

#if defined(__powerpc__)
#define HOSTFS_DEV    0xff660000
#elif defined(__arm__)
#define HOSTFS_DEV    0x50000000
#elif defined(__mips__)
#define HOSTFS_DEV    0x1c000000
#else
#define HOSTFS_DEV    0xffe81000
#endif

#define HOSTFS_MAGIC 0x66685456	/* "VThf" */

#define DATA_BUF_LEN        1040
#define HOSTFS_FILENAME_LEN  512
#define DEBUG_LEN           1024
#define XFER_DATA_WORDS      256

#define SYMBOL_TO_STRING2(n) #n
#define SYMBOL_TO_STRING(n) SYMBOL_TO_STRING2(n)

/* used on target */
#define DPRINT1 if (hostfs_debug >= 1) printk
#define DPRINT2 if (hostfs_debug >= 2) printk

enum {
	HF_FREAD = 0x01,
	HF_FWRITE = 0x02,
	HF_FNDELAY = 0x04,
	HF_FAPPEND = 0x08,
	HF_FSYNC = 0x10
};

/* only in target part */
extern dev_t hostfs_dev;
extern int hostfs_debug;

struct hf_node;

enum host_func {
	hf_VfsStat,
	hf_Root,
	hf_GetAttr,
	hf_SetAttr,
	hf_Open,
	hf_Close,
	hf_Readdir,
	hf_Lookup,
	hf_Seek,
	hf_Read,
	hf_Write,
	hf_Create,
	hf_Remove,
	hf_MkDir,
	hf_Parent,
	hf_Rename,
	hf_Link,
	hf_Symlink,
	hf_Readlink,
	hf_Debug,
	hf_Handshake,
	hf_Unmount,
	hf_Functions
};

struct host_funcs {
	enum host_func func;
	const char *name;
	int out;
	int in;
	int ie_out;
	int ie_in;
};

/*********
 *
 *IMPORTANT:
 * If you change the parameters make sure the ie_out and ie_in are still
 * correct. They signal the first entry to do endian conversion on.
 * -1 is no conversion at all.
 *
 */

struct hf_common_data {
	uint sys_error;
};

struct hf_hnode_data {
	uint sys_error;
	uint hnode;
	uint type;
};

struct hf_vfsstat_data {
	uint bsize;
	uint frsize;
	uint blocks;
	uint bfree;
	uint bavail;
	uint files;
	uint ffree;
	uint favail;
};

struct hf_getattr_data {
	uint sys_error;
	uint mode;		/* access mode */
	uint uid;		/* user id */
	uint gid;		/* group id */
	uint link;		/* number of references */
	uint size_hi;		/* file size */
	uint size_lo;
	uint atime_hi;		/* access time */
	uint atime_lo;
	uint mtime_hi;		/* modification time */
	uint mtime_lo;
	uint ctime_hi;		/* creation time */
	uint ctime_lo;
	uint blksize;		/* fundamental block size */
	uint blocks_hi;		/* blocks allocated */
	uint blocks_lo;
};

struct hf_setattr_data {
	uint set_atime;
	uint set_mtime;
	uint set_mode;
	uint set_uid;
	uint set_gid;
	uint atime_hi;		/* access time */
	uint atime_lo;
	uint mtime_hi;		/* modification time */
	uint mtime_lo;
	uint mode;
	uint uid;
	uint gid;
	uint set_size;
	uint size_hi;
	uint size_lo;
};

struct hf_setattr_data_v0 {
	uint set_atime;
	uint set_mtime;
	uint set_mode;
	uint set_uid;
	uint set_gid;
	uint atime_hi;		/* access time */
	uint atime_lo;
	uint mtime_hi;		/* modification time */
	uint mtime_lo;
	uint mode;
	uint uid;
	uint gid;
};

struct hf_readdir_data {
	uint sys_error;
	uint hnode;
	char filename[HOSTFS_FILENAME_LEN];
};

struct hf_readlink_data {
	uint sys_error;
	char filename[HOSTFS_FILENAME_LEN];
};

struct hf_lookup_data {
	char filename[HOSTFS_FILENAME_LEN];
};

struct hf_remove_data {
	char filename[HOSTFS_FILENAME_LEN];
};

struct hf_rename_data {
	uint new_hnode;
	char old_name[HOSTFS_FILENAME_LEN];
	char new_name[HOSTFS_FILENAME_LEN];
};

struct hf_create_data {
	uint excl;
	uint trunc;
	uint mode;
	char filename[HOSTFS_FILENAME_LEN];
};

struct hf_mkdir_data {
	uint mode;
	char dirname[HOSTFS_FILENAME_LEN];
};

struct hf_seek_data {
	uint off_hi;
	uint off_lo;
};

struct hf_read_data {
	uint sys_error;
	uint size;
	uint data[XFER_DATA_WORDS];	/* 1 or 2 KiB of data */
};

struct hf_write_data {
	uint size;
	uint append;
	uint data[XFER_DATA_WORDS];	/* 1 or 2 KiB of data */
};

struct hf_link_data {
	uint hnode;
	char link[HOSTFS_FILENAME_LEN];
};

struct hf_symlink_data {
	char target[HOSTFS_FILENAME_LEN];
	char link[HOSTFS_FILENAME_LEN];
};

struct hf_debug_data {
	char string[DEBUG_LEN];
};

struct hf_handshake_data {
	uint version;
};

struct hf_handshake_reply_data {
	uint sys_error;
	uint magic;
};

#endif				/* _HOST_FS_H */
