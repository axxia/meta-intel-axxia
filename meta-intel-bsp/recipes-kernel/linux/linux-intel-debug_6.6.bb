require recipes-kernel/linux/linux-intel_${PV}.bb
require linux-axxia.inc
require linux-intel_${KERNEL_MAJOR_VERSION}.inc

SRC_URI:append = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-intel-axxia-debug-${LINUX_KERNEL_TYPE}"
