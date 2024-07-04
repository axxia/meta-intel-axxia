require linux-intel_${PV}.bb

SRC_URI:append = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-intel-axxia-debug-${LINUX_KERNEL_TYPE}"
