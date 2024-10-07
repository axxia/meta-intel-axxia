require recipes-kernel/linux/linux-intel_6.6.bb
require recipes-kernel/linux/linux-axxia.inc
require linux-intel_6.6.inc

SRC_URI:append = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-intel-axxia-debug-${LINUX_KERNEL_TYPE}"
