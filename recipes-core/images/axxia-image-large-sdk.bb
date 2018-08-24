require axxia-image-large.bb

DESCRIPTION = "Image that includes everything within axxia-image-large \
plus meta-toolchain, development headers and libraries to \
form a standalone SDK."

IMAGE_FEATURES_append = " \
dev-pkgs \
tools-sdk \
tools-debug \
eclipse-debug \
tools-testapps \
debug-tweaks \
ssh-server-openssh"

IMAGE_INSTALL_append = " kernel-devsrc"

TOOLCHAIN_TARGET_TASK_append = " \
binutils-staticdev \
elfutils-dev \
libelf \
libnl-dev \
libunwind-dev \
numactl-dev \
python-dev \
slang-dev \
strace-dev \
systemtap \
systemtap-dev \
xz-dev"

TOOLCHAIN_HOST_TASK_append = " \
nativesdk-bison \
nativesdk-python-cffi \
nativesdk-python-nose \
nativesdk-python3-cffi \
nativesdk-python3-dev \
nativesdk-python3-distutils \
nativesdk-python3-netserver \
nativesdk-python3-nose \
nativesdk-python3-pexpect \
nativesdk-python3-pyexpect \
nativesdk-python3-pycparser \
nativesdk-python3-pyyaml \
nativesdk-python3-pynetlinux \
nativesdk-python3-robotframework \
nativesdk-python3-scapy "
