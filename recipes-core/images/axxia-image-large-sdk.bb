require axxia-image-large.bb

DESCRIPTION = "Image that includes everything within axxia-image-large \
plus meta-toolchain, development headers and libraries to \
form a standalone SDK."

IMAGE_FEATURES += " \
dev-pkgs \
tools-sdk \
tools-debug \
eclipse-debug \
tools-testapps \
debug-tweaks \
ssh-server-openssh"

IMAGE_INSTALL += "kernel-devsrc"

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
nativesdk-python-dev"
