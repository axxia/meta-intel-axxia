require linux-intel-staging_6.12.bb

SRC_URI:append = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-intel-staging-debug-${LINUX_KERNEL_TYPE}"

INSANE_SKIP += "buildpaths"
