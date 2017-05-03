DESCRIPTION = "A minimal image that supports the RTE."

IMAGE_INSTALL = " \
packagegroup-core-boot \
${ROOTFS_PKGMANAGE_BOOTSTRAP} \
${CORE_IMAGE_EXTRA_INSTALL} \
"

IMAGE_INSTALL_append = " libgcc inetutils gdbserver kernel-modules"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE = "8192"
