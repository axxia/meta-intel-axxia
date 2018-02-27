DESCRIPTION = "A minimal image used in simulation."

IMAGE_INSTALL = " \
packagegroup-core-boot \
${CORE_IMAGE_EXTRA_INSTALL} \
"

IMAGE_INSTALL_append = " \
axxia-rc-local \
boost \
dhcp-server \
dhcp-client \
dmidecode \
e2fsprogs-resize2fs \
ethtool \
expect \
gdb \
gdbserver \
iasl \
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
libpython3 \
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
net-tools \
numactl \
openssh \
openssh-sftp \
pciutils \
perl-module-bigint \
mtools \
python-cffi \
python3-cffi \
python-core \
python3-core \
python-dev \
python3-dev \
python-distutils \
python-modules \
python-netserver \
python-nose \
python3-distutils \
python3-modules \
python3-netserver \
python3-nose \
telnetd \
tmux \
vlan \
${@base_conditional('SIMICSFS', 'yes', 'simicsfs-client fuse', '', d)} "

IMAGE_FEATURES += "dev-pkgs"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE = "16384"

SDKIMAGE_FEATURES = "dev-pkgs dbg-pkgs staticdev-pkgs"
