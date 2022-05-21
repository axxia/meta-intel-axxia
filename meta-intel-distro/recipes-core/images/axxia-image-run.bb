DESCRIPTION = "A minimal image used in simulation."

require axxia-image.inc
require ${@bb.utils.contains('BBFILE_COLLECTIONS', 'intel-rdk', \
			     'axxia-rdk.inc', '', d)}

IMAGE_INSTALL = " \
packagegroup-core-boot \
${CORE_IMAGE_EXTRA_INSTALL} \
"

IMAGE_INSTALL_append = " \
accel-config \
axxia-rc-local \
babeltrace \
boost \
boost-dev \
cpupower \
dmidecode \
dtc \
e2fsprogs-resize2fs \
ethtool \
expect \
gdb \
gdbserver \
htop \
i2c-tools \
iasl \
inetutils \
initscripts-readonly-rootfs-overlay \
iproute2 \
iproute2-devlink \
kernel-dev \
kernel-modules \
kexec \
kexec-tools \
kmod \
ldd \
libarchive \
libasan \
libatomic \
libbsd \
libgcc \
libnl \
libnl-genl \
libnl-nf \
libnl-route \
libpcap \
libthrift \
libthrift-c-glib \
libthriftnb \
libthriftz \
libubsan \
libudev \
libxcrypt \
libxcrypt-compat \
msr-tools \
mtd-utils-misc \
mtools \
ncurses \
netcat \
netkit-tftp-client \
numactl \
openssh \
openssh-sftp \
pciutils \
packagegroup-core-full-cmdline \
perf \
perl-module-bigint \
python3-babeltrace \
python3-cffi \
python3-core \
python3-dev \
python3-distutils \
python3-modules \
python3-netserver \
python3-nose \
readline \
swig \
tcl \
tcpdump \
telnetd \
tk \
tmux \
vlan \
${@bb.utils.contains('DISTRO_FEATURES', 'multilib', \
		     '${MULTILIB_PACKAGES}', '', d)}  \
${@bb.utils.contains('DISTRO_FEATURES', 'simics', \
		     'simicsfs-client simics-agent fuse', '', d)} "

MULTILIB_PACKAGES ?= " \
lib32-libasan \
lib32-libgcc \
lib32-libnl \
lib32-libnl-genl \
lib32-libnl-nf \
lib32-libnl-route \
lib32-libpcap \
lib32-libpython3 \
lib32-libubsan \
lib32-libudev \
"

IMAGE_FEATURES_append = " dev-pkgs"

TOOLCHAIN_TARGET_TASK_append = " kernel-devsrc"

TOOLCHAIN_HOST_TASK_append = " nativesdk-elfutils-dev"

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE = "16384"

SDKIMAGE_FEATURES = "dev-pkgs dbg-pkgs staticdev-pkgs"

PACKAGE_EXCLUDE_append = "libxcrypt-compat-dev"