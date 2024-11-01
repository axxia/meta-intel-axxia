require linux-intel_6.1.bb

SRC_URI:append = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-intel-axxia-debug-${LINUX_KERNEL_TYPE}"

INSANE_SKIP += "buildpaths"
