SUMMARY = "SimicsFS kernel module that talks to a simulated device"
DESCRIPTION="SimicsFS gives you access to the file system of your real computer inside the simulated machine. This greatly simplifies the process of importing files into the simulated machine."
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://README;md5=d85032171211186dc98a06988cb7504a"

inherit module

PV="1.22"

SRC_URI = "file://CHANGES \
           file://Kconfig \
           file://Makefile \
           file://README \
           file://README.html \
           file://README.pdf \
           file://hostfs.h \
           file://hostfs_data.h \
           file://hostfs_dir.c \
           file://hostfs_file.c \
           file://hostfs_host.c \
           file://hostfs_inode.c \
           file://hostfs_linux.h \
           file://hostfs_super.c \
           "

S = "${WORKDIR}"
export KERNELDIR="${KERNEL_SRC}"

do_install_append () {
	mkdir -p ${D}/host
}

FILES_${PN} += "host"

