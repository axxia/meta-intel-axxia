require linux-korg-netdev_6.11.bb

SRC_URI:append = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-korg-netdev-debug-${LINUX_KERNEL_TYPE}"
