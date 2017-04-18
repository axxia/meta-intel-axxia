DESCRIPTION = "A minimal image that supports the RTE."

IMAGE_INSTALL = " \
packagegroup-core-boot \
${ROOTFS_PKGMANAGE_BOOTSTRAP} \
${CORE_IMAGE_EXTRA_INSTALL} \
"

IMAGE_INSTALL_append = " \
libgcc \
inetutils \
gdb \
gdbserver \
python-core \
python-modules \
python-netserver \
lttng-modules \
lttng-modules-dev \
lttng-tools \
lttng-tools-dev \
lttng-ust \
lttng-ust-dev \
dhcp-client \
netkit-tftp-client \
openssh \
openssh-sftp \
inetutils \
netcat \
perl-module-bigint \
kmod \
libnl \
libnl-genl \
libnl-nf \
libnl-route \
libpcap "

IMAGE_FEATURES += "dev-pkgs"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE = "16384"

SDKIMAGE_FEATURES = "dev-pkgs dbg-pkgs staticdev-pkgs"
