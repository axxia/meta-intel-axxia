DESCRIPTION = "A more complete image used for development, \
when size doesn't matter as much."

require recipes-core/images/core-image-minimal-dev.bb
require axxia-image.inc
require axxia-devsrc.inc
require ${@bb.utils.contains('BBFILE_COLLECTIONS', 'intel-rdk', \
			     'axxia-rdk.inc', '', d)}

IMAGE_FEATURES:append = " \
dev-pkgs \
tools-sdk \
tools-debug \
eclipse-debug \
tools-testapps \
debug-tweaks \
ssh-server-openssh"

IMAGE_INSTALL = " \
accel-config \
acl \
aer-inject \
asciidoc \
at \
atftp \
attr \
autoconf \
autofs \
axxia-rc-local \
babeltrace \
base-files \
base-passwd \
bash \
bc \
bind \
bind-utils \
bison \
bluez5 \
bmon \
bpftool \
bridge-utils \
boost \
boost-dev \
busybox \
bzip2 \
cifs-utils \
cmake \
coreutils \
cpio \
cpuid \
cpupower \
cracklib \
cronie \
curl \
db \
dbus \
dbus-glib \
devmem2 \
dhcpcd \
dhrystone \
diffutils \
dmidecode \
docker \
dos2unix \
dosfstools \
dtc \
e2fsprogs \
e2fsprogs-badblocks \
e2fsprogs-e2fsck \
e2fsprogs-mke2fs \
e2fsprogs-resize2fs \
e2fsprogs-tune2fs \
ed \
efibootmgr \
elfutils \
ethtool \
expat \
expect \
file \
findutils \
flac \
flex \
fwts \
gawk \
gdb \
gdbserver \
gettext \
gfortran \
gfortran-symlinks \
git \
glib-2.0 \
glog \
glog-dev \
gmp \
gnutls \
go \
googletest-dev \
gptfdisk \
grep \
groff \
gzip \
hdparm \
htop \
hwloc \
i2c-tools \
iasl \
icu \
inetutils \
inetutils-telnetd \
init-ifupdown \
initscripts \
initscripts-readonly-rootfs-overlay \
intel-pcm \
ipmiutil \
iperf3 \
iproute2 \
iproute2-devlink \
iproute2-ss \
iptables \
iputils \
irda-utils \
jansson \
json-c \
iptraf \
iw \
kdump \
kernel-dev \
kernel-modules \
kexec \
kexec-tools \
kmod \
kmod-dev \
ldd \
less \
libaio \
libaio-dev \
libasan \
libbpf \
libbpf-dev \
libbsd \
libcap \
libcheck \
libdaemon \
libdrm \
libevent \
libffi \
libgcc \
libgcrypt \
libgfortran \
libgfortran-dev \
libgfortran-dbg \
libgpg-error \
libgpiod \
libgpiod-tools \
libice \
libjpeg-turbo \
libkmod \
liblzma \
libnl \
libnl-genl \
libnl-nf \
libnl-route \
libnss-mdns \
libnss-nis \
libogg \
libpam \
libpcap \
libpcap-dev \
libpciaccess \
libpciaccess-dev \
libpcre \
libpng \
libpython3 \
libsamplerate0 \
libsm \
libsndfile1 \
libtasn1 \
libthrift \
libthrift-c-glib \
libthriftnb \
libthriftz \
libtirpc \
libtool \
libubsan \
libudev \
libunwind \
libusb-compat \
libusb1 \
libxau \
libxcb \
libxcrypt \
libxcrypt-compat \
libxdmcp \
libxml2 \
lighttpd \
lldpd \
lmbench \
lmdb \
lmdb-dev \
logrotate \
lrzsz \
lshw \
lsof \
lsscsi \
ltp \
lvm2 \
lzo \
man \
man-pages \
mce-inject \
mce-test \
mcelog \
mdadm \
meson \
modutils-initscripts \
mokutil \
mpich \
msmtp \
msr-tools \
mtd-utils \
mtd-utils-misc \
nasm \
ncurses \
ncurses-dev \
net-tools \
netbase \
netcat \
nfs-utils \
nfs-utils-client \
ninja \
nmap \
ntp \
numactl \
openjdk-11-bin \
openssh \
openssh-sftp \
openssh-sftp-server \
openssl \
openssl-dev \
opkg \
opkg-arch-config \
opkg-utils \
os-release \
p7zip \
p7zip-dev \
packagegroup-core-boot \
packagegroup-core-buildessential \
parted \
pbzip2 \
pciutils \
pciutils-dev \
perf \
perl \
perl-module-bigint \
perl-module-encode-encoding \
perl-module-feature \
perl-module-file-spec-functions \
perl-module-findbin \
perl-module-getopt-std \
perl-module-lib \
perl-module-pod-text \
perl-ptest \
pkgconfig \
pmtools \
popt \
postfix \
ppp \
procps \
psmisc \
python3 \
python3-babeltrace \
python3-cffi \
python3-colorama \
python3-core \
python3-dev \
python3-humanfriendly \
python3-lmdb \
python3-lxml \
python3-modules \
python3-netserver \
python3-nose \
python3-num2words \
python3-openpyxl \
python3-paramiko \
python3-pexpect \
python3-pip \
python3-prctl \
python3-psutil \
python3-pyelftools \
python3-pyexpect \
python3-pyparsing \
python3-pytest \
python3-pyyaml \
python3-pynetlinux \
python3-robotframework \
python3-scapy \
python3-sheet2dict \
python3-trex-stl-lib \
qemu \
quota \
radvd \
rasdaemon \
readline \
rpcbind \
rpcsvc-proto \
rpm \
rsync \
rsyslog \
run-postinsts \
samba \
screen \
sed \
setserial \
shadow \
shadow-securetty \
sqlite3 \
strace \
stress-ng \
stressapptest \
strongswan \
sudo \
swig \
sysfsutils \
sysstat \
tar \
tcl \
tcp-wrappers \
tcpdump \
tcsh \
telnetd \
thrift \
thrift-compiler \
thrift-dev \
time \
tk \
tmux \
tpm2-abrmd \
tpm2-tools \
tshark \
turbostat \
tzdata \
udev \
udev-extraconf \
unzip \
update-rc.d \
usbutils \
util-linux \
util-linux-libblkid \
util-linux-libuuid \
util-linux-lscpu \
util-macros \
valgrind \
vim \
vlan \
watchdog \
wget \
which \
yaml-cpp \
yasm \
xfsprogs \
xxhash \
yp-tools \
yp-tools-dev \
ypbind-mt \
zip \
zlib \
zlib-dev \
${LTTNG_SUPPORT} \
${LXC_SUPPORT} \
${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', ' \
			${ALTERNATIVE_KERNELS_INSTALL} \
			${ALTERNATIVE_KERNELS_MODULES_INSTALL} \
			${ALTERNATIVE_KERNELS_LTTNG_MODULES}', d)} \
${@bb.utils.contains('DISTRO_FEATURES', 'simics', \
		     'simicsfs-client simics-agent fuse', '', d)} \
${@bb.utils.contains('DISTRO_FEATURES', 'multilib', \
		     '${MULTILIB_PACKAGES}', '', d)}  \
"

LXC_SUPPORT ?= " \
cgroup-lite \
gnupg \
libvirt \
libvirt-libvirtd \
lxc \
lxc-networking \
lxc-templates \
xz"

LTTNG_SUPPORT ?= " \
lttng-modules \
lttng-modules-dev \
lttng-tools \
lttng-tools-dev \
lttng-ust \
lttng-ust-dev"

MULTILIB_PACKAGES ?= " \
lib32-libaio \
lib32-libasan \
lib32-libcap \
lib32-libcheck \
lib32-libdaemon \
lib32-libdrm \
lib32-libevent \
lib32-libffi \
lib32-libgcc \
lib32-libgcrypt \
lib32-libgpg-error \
lib32-libgpiod \
lib32-libice \
lib32-libjpeg-turbo \
lib32-libkmod \
lib32-libnl \
lib32-libnl-genl \
lib32-libnl-nf \
lib32-libnl-route \
lib32-libnss-mdns \
lib32-libnss-nis \
lib32-libogg \
lib32-libpam \
lib32-libpcap \
lib32-libpcap-dev \
lib32-libpciaccess \
lib32-libpcre \
lib32-libpng \
lib32-libpython3 \
lib32-libsamplerate0 \
lib32-libsm \
lib32-libsndfile1 \
lib32-libtasn1 \
lib32-libthrift \
lib32-libthrift-c-glib \
lib32-libthriftnb \
lib32-libthriftz \
lib32-libtirpc \
lib32-libtool \
lib32-libubsan \
lib32-libudev \
lib32-libunwind \
lib32-libusb-compat \
lib32-libusb1 \
lib32-libxau \
lib32-libxcb \
lib32-libxdmcp \
lib32-libxml2 \
"

TOOLCHAIN_TARGET_TASK:append = " \
binutils-staticdev \
elfutils-dev \
libc-staticdev \
libelf \
libnl-dev \
libunwind-dev \
numactl-dev \
python3-dev \
slang-dev \
strace-dev \
systemtap \
systemtap-dev \
xmlto \
xz-dev"

SDKIMAGE_FEATURES = "dev-pkgs dbg-pkgs staticdev-pkgs"

TOOLCHAIN_HOST_TASK:append = " \
nativesdk-bison \
nativesdk-elfutils-dev \
nativesdk-flex \
nativesdk-libelf \
nativesdk-ncurses-dev \
nativesdk-ncurses-libform \
nativesdk-ncurses-libmenu \
nativesdk-ncurses-libncurses \
nativesdk-ncurses-libpanel \
nativesdk-openssl-dev \
nativesdk-python3-cffi \
nativesdk-python3-dev \
nativesdk-python3-netserver \
nativesdk-python3-nose \
nativesdk-python3-pexpect \
nativesdk-python3-pyelftools \
nativesdk-python3-pyexpect \
nativesdk-python3-pycparser \
nativesdk-python3-pyyaml \
nativesdk-python3-pynetlinux \
nativesdk-python3-robotframework \
nativesdk-python3-scapy "
