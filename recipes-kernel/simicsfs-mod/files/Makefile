#
# Makefile for Simics hostfs

ifneq ($(KERNELRELEASE),)

# building with Kbuild
obj-m := simicsfs.o
simicsfs-y := hostfs_inode.o hostfs_super.o hostfs_dir.o hostfs_file.o \
	hostfs_host.o

else

# building normally
KERNELDIR ?= /lib/modules/`uname -r`/build
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install

tests:
	 $(MAKE) -C $@ $(BUILD_RULE)

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

.PHONY: clean tests

endif
