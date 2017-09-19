DESCRIPTION = "A minimal image that supports the RTE."

IMAGE_INSTALL = " \
packagegroup-core-boot \
${ROOTFS_PKGMANAGE_BOOTSTRAP} \
${CORE_IMAGE_EXTRA_INSTALL} \
"

IMAGE_INSTALL_append = " \
boost \
dhcp-server \
dhcp-client \
dmidecode \
ethtool \
gdb \
gdbserver \
inetutils \
kernel-modules \
kmod \
ldd \
libasan \
libubsan \
libgcc \
libnl \
libnl-genl \
libnl-nf \
libnl-route \
libpython2 \
libpcap \
libudev \
lttng-modules \
lttng-modules-dev \
lttng-tools \
lttng-tools-dev \
lttng-ust \
lttng-ust-dev \
netcat \
netkit-tftp-client \
${@base_conditional('MACHINE', 'axxiaarm', '', 'numactl', d)} \
openssh \
openssh-sftp \
pciutils \
perl-module-bigint \
python-cffi \
python-core \
python-dev \
python-distutils \
python-modules \
python-netserver \
python-nose \
telnetd \
tmux \
vlan \
${@base_conditional('MACHINE', 'axxiax86-64', 'axxia-rc-local', '', d)} "

IMAGE_FEATURES += "dev-pkgs"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE = "16384"

SDKIMAGE_FEATURES = "dev-pkgs dbg-pkgs staticdev-pkgs"
