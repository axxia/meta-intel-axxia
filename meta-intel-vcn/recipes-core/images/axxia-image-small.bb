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
initscripts-readonly-rootfs-overlay \
kernel-dev \
kernel-modules \
libasan \
libgcc \
libubsan \
${@bb.utils.contains('DISTRO_FEATURES', 'multilib', \
		     '${MULTILIB_PACKAGES}', '', d)}  \
"

MULTILIB_PACKAGES ?= " \
lib32-libasan \
lib32-libgcc \
lib32-libubsan \
"

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE = "8192"
