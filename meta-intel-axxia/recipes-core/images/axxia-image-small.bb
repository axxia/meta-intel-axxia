DESCRIPTION = "A minimal image used in simulation, flash, \
or as a ram disk that supports the RTE."

require axxia-image.inc

IMAGE_INSTALL = " \
packagegroup-core-boot \
${CORE_IMAGE_EXTRA_INSTALL} \
"

IMAGE_INSTALL_append = " \
axxia-rc-local \
dhcp-client \
gdbserver \
inetutils \
kernel-dev \
kernel-modules \
libasan \
libgcc \
libubsan "

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE = "8192"
