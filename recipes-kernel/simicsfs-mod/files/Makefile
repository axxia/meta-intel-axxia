#
# Makefile for Simics hostfs

ifeq (,$(CONFIG_SIMICSFS))
CONFIG_SIMICSFS=m
endif

obj-$(CONFIG_SIMICSFS) += simicsfs.o

simicsfs-objs := hostfs_inode.o hostfs_super.o hostfs_dir.o hostfs_file.o \
	hostfs_host.o
