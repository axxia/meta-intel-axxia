require axxia-image-large.bb

DESCRIPTION = "Image that includes everything within axxia-image-large \
plus meta-toolchain, development headers and libraries to \
form a standalone SDK."

IMAGE_FEATURES += "dev-pkgs tools-sdk tools-debug eclipse-debug tools-profile \
	           tools-testapps debug-tweaks ssh-server-openssh"

IMAGE_INSTALL += "kernel-devsrc"

TOOLCHAIN_TARGET_TASK_append = " \
libelf \
elfutils-dev \
systemtap \
systemtap-dev \
libunwind-dev \
slang-dev \
xz-dev \
numactl-dev \
binutils-staticdev"

TOOLCHAIN_HOST_TASK_append = " \
nativesdk-bison \
nativesdk-python-dev"
