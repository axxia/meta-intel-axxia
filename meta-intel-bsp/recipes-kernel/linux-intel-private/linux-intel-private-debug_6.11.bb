require linux-intel-private_6.11.bb

SRC_URI:append = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-intel-private-debug-${LINUX_KERNEL_TYPE}"

INSANE_SKIP += "buildpaths"
