DESCRIPTION = "A minimal image used in simulation, flash, \
or as a ram disk that supports the RTE."

require axxia-image.inc

APPEND = "console=ttyS0"

IMAGE_FEATURES = " \
dev-pkgs \
tools-sdk \
tools-debug \
debug-tweaks \
"

IMAGE_INSTALL = " \
packagegroup-core-boot \
${CORE_IMAGE_EXTRA_INSTALL} \
"

IMAGE_INSTALL_append = " \
axxia-rc-local \
curl \
gdbserver \
inetutils \
initscripts-readonly-rootfs-overlay \
kernel-dev \
kernel-modules \
libasan \
libgcc \
libubsan \
lighttpd \
lvm2 \
man \
man-pages \
net-tools \
openssh \
openssh-sftp \
openssh-sftp-server \
pciutils \
strongswan \
tcpdump \
tcpreplay \
vlan \
${@bb.utils.contains('DISTRO_FEATURES', 'multilib', \
		     '${MULTILIB_PACKAGES}', '', d)}  \
${@bb.utils.contains('DISTRO_FEATURES', 'simics', \
		     'simicsfs-client simics-agent fuse', '', d)} \
"

MULTILIB_PACKAGES ?= " \
lib32-libasan \
lib32-libgcc \
lib32-libubsan \
"

TOOLCHAIN_TARGET_TASK_append = " kernel-devsrc"

TOOLCHAIN_HOST_TASK_append = " nativesdk-elfutils-dev"

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE = "8192"

IMAGE_FSTYPES = "hddimg wic tar.gz ext4"
