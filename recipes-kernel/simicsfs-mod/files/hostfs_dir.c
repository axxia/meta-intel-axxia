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

static int
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 11, 0)
hostfs_fo_iterate(struct file *file, struct dir_context *ctx)
#else
hostfs_fo_readdir(struct file *file, void *buf, filldir_t fill)
#endif
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 20)
	struct dentry *dentry = file->f_path.dentry;
#else
	struct dentry *dentry = file->f_dentry;
#endif
	struct inode *inode = dentry->d_inode;
	struct hf_readdir_data data;
	uint offset = file->f_pos;

/*	DPRINT1(DEVICE_NAME " hostfs_fo_readdir("); */
/*	DPRINTFILE1(file); */
/*	DPRINT1(", %p, %p)\n", buf, fill); */
/*	DPRINT1("	file->fpos == %ld\n", (long)file->f_pos); */

	get_host_data(hf_Readdir, inode->i_ino, &offset, &data);
	while (data.hnode) {
		NTOHSWAP(data.filename);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 11, 0)
		if (!dir_emit(ctx, data.filename, strlen(data.filename),
			      data.hnode, DT_UNKNOWN))
			return 0;
		ctx->pos = ++offset;
#else
		if (fill(buf, data.filename, strlen(data.filename), offset,
			 data.hnode, DT_UNKNOWN) < 0)
			return 0;
		file->f_pos = ++offset;
#endif
		get_host_data(hf_Readdir, inode->i_ino, &offset, &data);
	}
	return 0;
}

static ssize_t
hostfs_fo_dir_read(struct file *file, char *buf, size_t len, loff_t *off)
{
/*	DPRINT1(DEVICE_NAME " hostfs_fo_dir_read()\n"); */
	return -EISDIR;
}

static int hostfs_dir_release(struct inode *inode, struct file *file)
{
	uint dummy;
	get_host_data(hf_Close, inode->i_ino, NULL, &dummy);
	return 0;
}

const struct file_operations hostfs_file_dirops = {
	.read = hostfs_fo_dir_read,
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 11, 0)
	.iterate = hostfs_fo_iterate,
#else
	.readdir = hostfs_fo_readdir,
#endif
	.release = hostfs_dir_release,
};
