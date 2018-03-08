DESCRIPTION = "A minimal image used in simulation."

IMAGE_INSTALL = " \
packagegroup-core-boot \
${CORE_IMAGE_EXTRA_INSTALL} \
"

IMAGE_INSTALL_append = " \
axxia-rc-local \
boost \
dhcp-client \
dhcp-server \
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
libgcc \
libnl \
libnl-genl \
libnl-nf \
libnl-route \
libpcap \
libpython2 \
libpython3 \
libubsan \
libudev \
lttng-modules \
lttng-modules-dev \
lttng-tools \
lttng-tools-dev \
lttng-ust \
lttng-ust-dev \
mtools \
ncurses \
net-tools \
netcat \
netkit-tftp-client \
numactl \
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
python3-cffi \
python3-core \
python3-dev \
python3-distutils \
python3-modules \
python3-netserver \
python3-nose \
python3-pexpect \
python3-pyexpect \
python3-pyyaml \
python3-pynetlinux \
python3-robotframework \
python3-scapy \
readline \
swig \
tcl \
telnetd \
tk \
tmux \
vlan \
${@base_conditional('SIMICSFS', 'yes', 'simicsfs-client fuse', '', d)} "

IMAGE_FEATURES += "dev-pkgs"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE = "16384"

SDKIMAGE_FEATURES = "dev-pkgs dbg-pkgs staticdev-pkgs"
