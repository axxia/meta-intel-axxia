DESCRIPTION = "A minimal image used in simulation, flash, \
or as a ram disk that supports the RTE."

IMAGE_INSTALL = " \
packagegroup-core-boot \
${CORE_IMAGE_EXTRA_INSTALL} \
"

IMAGE_INSTALL_append = " \
axxia-rc-local \
libgcc \
inetutils \
gdbserver \
kernel-modules \
libasan \
libubsan "

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE = "8192"
