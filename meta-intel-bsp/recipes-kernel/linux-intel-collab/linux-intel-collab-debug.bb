require linux-intel-collab.bb

SRC_URI:append = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-intel-collab-debug-${LINUX_KERNEL_TYPE}"

INSANE_SKIP += "buildpaths"
