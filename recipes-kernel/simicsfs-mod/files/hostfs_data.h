/*
   hostfs for Linux
   Copyright 2001 - 2006 Virtutech AB

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

#ifndef _HOST_FS_DATA_H
#define _HOST_FS_DATA_H

/* WARNING: Only include once. Contains definitions */

/* when transferring data the following protocol is used:
 *
 *   to host:  4 byte  function
 *   to host:  4 bytes hnode
 *   to host:  X bytes out data (defined by fkn_len[fkn].out)
 * from host:  X bytes in data  (defined by fkn_len[fkn].in)  ( X > 0 !!! )
 *
 */

static struct host_funcs host_funcs[] = {
	{hf_VfsStat,
	 "VfsStat",
	 0,
	 sizeof(struct hf_vfsstat_data) >> 2,
	 -1,
	 -1},

	{hf_Root,
	 "Root",
	 0,
	 sizeof(struct hf_hnode_data) >> 2,
	 -1,
	 -1},

	{hf_GetAttr,
	 "GetAttr",
	 0,
	 sizeof(struct hf_getattr_data) >> 2,
	 -1,
	 -1},

	{hf_SetAttr,
	 "SetAttr",
	 sizeof(struct hf_setattr_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 -1,
	 -1},

	{hf_Open,
	 "Open",
	 1,
	 sizeof(struct hf_common_data) >> 2,
	 -1,
	 -1},

	{hf_Close,
	 "Close",
	 0,
	 1,
	 -1,
	 -1},

	{hf_Readdir,
	 "Readdir",
	 1,
	 sizeof(struct hf_readdir_data) >> 2,
	 -1,
	 2},

	{hf_Lookup,
	 "Lookup",
	 sizeof(struct hf_lookup_data),
	 sizeof(struct hf_hnode_data) >> 2,
	 0,
	 -1},

	{hf_Seek,
	 "Seek",
	 sizeof(struct hf_seek_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 -1,
	 -1},

	{hf_Read,
	 "Read",
	 1,
	 sizeof(struct hf_read_data) >> 2,
	 -1,
	 2},

	{hf_Write,
	 "Write",
	 sizeof(struct hf_write_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 2,
	 -1},

	{hf_Create,
	 "Create",
	 sizeof(struct hf_create_data) >> 2,
	 sizeof(struct hf_hnode_data) >> 2,
	 3,
	 -1},

	{hf_Remove,
	 "Remove",
	 sizeof(struct hf_remove_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 0,
	 -1},

	{hf_MkDir,
	 "MkDir",
	 sizeof(struct hf_mkdir_data) >> 2,
	 sizeof(struct hf_hnode_data) >> 2,
	 1,
	 -1},

	{hf_Parent,
	 "Parent",
	 0,
	 sizeof(struct hf_hnode_data) >> 2,
	 -1,
	 -1},

	{hf_Rename,
	 "Rename",
	 sizeof(struct hf_rename_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 1,
	 -1},

	{hf_Link,
	 "Link",
	 sizeof(struct hf_link_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 1,
	 -1},

	{hf_Symlink,
	 "Symlink",
	 sizeof(struct hf_symlink_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 0,
	 -1},

	{hf_Readlink,
	 "Readlink",
	 0,
	 sizeof(struct hf_readlink_data) >> 2,
	 -1,
	 1},

	{hf_Debug,
	 "Debug",
	 sizeof(struct hf_debug_data) >> 2,
	 1,
	 0,
	 -1},

	{hf_Handshake,
	 "Handshake",
	 sizeof(struct hf_handshake_data) >> 2,
	 sizeof(struct hf_handshake_reply_data) >> 2,
	 -1,
	 -1},

	{hf_Unmount,
	 "Unmount",
	 0,
	 sizeof(struct hf_common_data) >> 2,
	 -1,
	 -1}
};

typedef int check_enough_host_funcs[sizeof(host_funcs) / sizeof(host_funcs[0])
				    == hf_Functions ? 1 : -1];

#if defined(HOSTFS_HOST)
static struct host_funcs host_funcs_v0[] = {
	{hf_VfsStat,
	 "VfsStat",
	 0,
	 sizeof(struct hf_vfsstat_data) >> 2,
	 -1,
	 -1},

	{hf_Root,
	 "Root",
	 0,
	 sizeof(struct hf_hnode_data) >> 2,
	 -1,
	 -1},

	{hf_GetAttr,
	 "GetAttr",
	 0,
	 sizeof(struct hf_getattr_data) >> 2,
	 -1,
	 -1},

	{hf_SetAttr,
	 "SetAttr",
	 sizeof(struct hf_setattr_data_v0) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 -1,
	 -1},

	{hf_Open,
	 "Open",
	 1,
	 sizeof(struct hf_common_data) >> 2,
	 -1,
	 -1},

	{hf_Close,
	 "Close",
	 0,
	 1,
	 -1,
	 -1},

	{hf_Readdir,
	 "Readdir",
	 1,
	 sizeof(struct hf_readdir_data) >> 2,
	 -1,
	 2},

	{hf_Lookup,
	 "Lookup",
	 sizeof(struct hf_lookup_data),
	 sizeof(struct hf_hnode_data) >> 2,
	 0,
	 -1},

	{hf_Seek,
	 "Seek",
	 sizeof(struct hf_seek_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 -1,
	 -1},

	{hf_Read,
	 "Read",
	 1,
	 sizeof(struct hf_read_data) >> 2,
	 -1,
	 2},

	{hf_Write,
	 "Write",
	 sizeof(struct hf_write_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 2,
	 -1},

	{hf_Create,
	 "Create",
	 sizeof(struct hf_create_data) >> 2,
	 sizeof(struct hf_hnode_data) >> 2,
	 3,
	 -1},

	{hf_Remove,
	 "Remove",
	 sizeof(struct hf_remove_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 0,
	 -1},

	{hf_MkDir,
	 "MkDir",
	 sizeof(struct hf_mkdir_data) >> 2,
	 sizeof(struct hf_hnode_data) >> 2,
	 1,
	 -1},

	{hf_Parent,
	 "Parent",
	 0,
	 sizeof(struct hf_hnode_data) >> 2,
	 -1,
	 -1},

	{hf_Rename,
	 "Rename",
	 sizeof(struct hf_rename_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 1,
	 -1},

	{hf_Link,
	 "Link",
	 sizeof(struct hf_link_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 1,
	 -1},

	{hf_Symlink,
	 "Symlink",
	 sizeof(struct hf_symlink_data) >> 2,
	 sizeof(struct hf_common_data) >> 2,
	 0,
	 -1},

	{hf_Readlink,
	 "Readlink",
	 0,
	 sizeof(struct hf_readlink_data) >> 2,
	 -1,
	 1},

	{hf_Debug,
	 "Debug",
	 sizeof(struct hf_debug_data) >> 2,
	 1,
	 0,
	 -1},

	{hf_Handshake,
	 "Handshake",
	 sizeof(struct hf_handshake_data) >> 2,
	 sizeof(struct hf_handshake_reply_data) >> 2,
	 -1,
	 -1},

	{hf_Unmount,
	 "Unmount",
	 0,
	 0,
	 -1,
	 -1}
};

typedef int check_enough_host_funcs_v0[sizeof(host_funcs_v0)
				       / sizeof(host_funcs_v0[0])
				       == hf_Functions ? 1 : -1];
#endif				/* HOSTFS_HOST */

#endif				/* _HOST_FS_DATA */
