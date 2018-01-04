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

#include "hostfs_linux.h"
#include <linux/moduleparam.h>

static struct super_operations hostfs_super_ops;

int hostfs_debug;
module_param(hostfs_debug, int, 0);
MODULE_PARM_DESC(hostfs_debug, "A debug level integer, default off (0)");

static int
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 18)
hostfs_statfs(struct dentry *de, struct kstatfs *buf)
#else
hostfs_statfs(struct super_block *sb, struct kstatfs *buf)
#endif
{
	struct hf_vfsstat_data data;

	get_host_data(hf_VfsStat, 0, NULL, &data);

	memset(buf, 0, sizeof(*buf));
	buf->f_type = HOSTFS_MAGIC;
	buf->f_bsize = data.bsize;
	buf->f_blocks = data.blocks;
	buf->f_bfree = data.bfree;
	buf->f_bavail = data.bavail;
	buf->f_files = data.files;
	buf->f_ffree = data.ffree;
	buf->f_namelen = HOSTFS_FILENAME_LEN;

	return 0;
}

static int hostfs_read_super(struct super_block *sb, void *data, int silent)
{
	struct inode *root_inode;
	struct hf_handshake_data odata;
	struct hf_handshake_reply_data idata;

	odata.version = HOSTFS_VERSION;
	get_host_data(hf_Handshake, 0, &odata, &idata);

	if (idata.sys_error || idata.magic != HOSTFS_MAGIC) {
		printk(DEVICE_NAME
		       " Handshake with Simics module failed (err=%d, magic=%x/expected %x!\n",
		       idata.sys_error, idata.magic, HOSTFS_MAGIC);
		goto out_fail;
	}

	printk(DEVICE_NAME " mounted\n");

	sb->s_op = &hostfs_super_ops;
	sb->s_magic = HOSTFS_MAGIC;
	sb->s_blocksize = HOSTFS_BLOCK_SIZE;
	sb->s_blocksize_bits = HOSTFS_BLOCK_BITS;
	root_inode = new_inode(sb);
	if (!root_inode)
		goto out_fail;
	root_inode->i_ino = HOSTFS_ROOT_INO;
	hostfs_read_inode(root_inode);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 3, 0)
	sb->s_root = d_make_root(root_inode);
#else
	sb->s_root = d_alloc_root(root_inode);
#endif
	if (!sb->s_root)
		goto out_no_root;

	return 0;

out_no_root:
	printk(DEVICE_NAME " get root inode failed\n");
	iput(root_inode);

out_fail:
	return -EINVAL;
}

static void hostfs_put_super(struct super_block *sb)
{
	struct hf_common_data idata;
	get_host_data(hf_Unmount, 0, NULL, &idata);
}

static struct super_operations hostfs_super_ops = {
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 25)
	.read_inode = hostfs_read_inode,
#endif
	.write_inode = hostfs_write_inode,
	.put_super = hostfs_put_super,
	.statfs = hostfs_statfs,
};

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 39)
static struct dentry *hostfs_mount(struct file_system_type *fs_type,
				   int flags, const char *dev_name, void *data)
{
	return mount_nodev(fs_type, flags, data, hostfs_read_super);
}
#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 18)
static int
hostfs_get_sb(struct file_system_type *fs_type,
	      int flags, const char *dev_name, void *data, struct vfsmount *mnt)
{
	return get_sb_nodev(fs_type, flags, data, hostfs_read_super, mnt);
}
#else
static struct super_block *hostfs_get_sb(struct file_system_type *fs_type,
					 int flags, const char *dev_name,
					 void *data)
{
	return get_sb_nodev(fs_type, flags, data, hostfs_read_super);
}
#endif

static struct file_system_type host_fs_type = {
	.owner = THIS_MODULE,
	.name = "simicsfs",
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 39)
	.mount = hostfs_mount,
#else
	.get_sb = hostfs_get_sb,
#endif
	.kill_sb = kill_anon_super,
};

static int
__init init_hostfs(void)
{
	printk(DEVICE_NAME " " SYMBOL_TO_STRING(HOSTFS_VERSION) "."
	       SYMBOL_TO_STRING(HOSTFS_SUBVERSION) " loaded\n");
	init_host_fs();
	return register_filesystem(&host_fs_type);
}

static void
__exit cleanup_hostfs(void)
{
	unregister_filesystem(&host_fs_type);
	printk(DEVICE_NAME " unloaded\n");
}

module_init(init_hostfs);
module_exit(cleanup_hostfs);
