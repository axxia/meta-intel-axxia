DESCRIPTION = "A minimal image used in simulation."

require axxia-image.inc

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
connman \	  
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
libubsan \
libudev \
mtools \
ncurses \
netcat \
netkit-tftp-client \
numactl \
openssh \
openssh-sftp \
pciutils \
packagegroup-core-full-cmdline \
perl-module-bigint \
python-cffi \
python-core \
python-dev \
python-distutils \
python-modules \
python-netserver \
python-nose \
readline \
swig \
tcl \
tcpdump \
telnetd \
tk \
tmux \
vlan \
${@bb.utils.contains('DISTRO_FEATURES', 'simicsfs', \
		     'simicsfs-client fuse', '', d)} "

IMAGE_FEATURES_append = " dev-pkgs"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE = "16384"

SDKIMAGE_FEATURES = "dev-pkgs dbg-pkgs staticdev-pkgs"
