require recipes-kernel/linux/linux-yocto_${PV}.bb
require linux-axxia.inc
require linux-yocto_${KERNEL_MAJOR_VERSION}.inc

SRC_URI_append = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-yocto-axxia-debug-${LINUX_KERNEL_TYPE}"
