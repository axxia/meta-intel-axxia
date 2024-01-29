require recipes-kernel/linux/linux-yocto-rt_${PV}.bb
require linux-axxia.inc
require linux-yocto_${KERNEL_MAJOR_VERSION}.inc

SRC_URI:append = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-yocto-axxia-debug-${LINUX_KERNEL_TYPE}"
