require recipes-kernel/linux/linux-yocto_6.6.bb
require recipes-kernel/linux/linux-axxia.inc
require linux-yocto_6.6.inc

SRC_URI:append = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-yocto-axxia-debug-${LINUX_KERNEL_TYPE}"

INSANE_SKIP += "buildpaths"
