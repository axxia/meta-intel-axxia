require linux-intel-private.bb

LINUX_VERSION_EXTENSION = "-intel-private-debug-${LINUX_KERNEL_TYPE}"

KBUILD_DEFCONFIG = "${CPU}_debug_defconfig"

INSANE_SKIP += "buildpaths"
