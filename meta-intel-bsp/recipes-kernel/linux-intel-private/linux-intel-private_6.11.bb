require recipes-kernel/linux/linux-intel.inc
require recipes-kernel/linux/linux-axxia.inc
require linux-intel-private_6.11.inc

LINUX_VERSION_EXTENSION = "-intel-private-${LINUX_KERNEL_TYPE}"

SRC_URI:prepend = "git://github.com/intel-innersource/os.linux.kernel.kernel-staging.git;protocol=https;name=machine;branch=${KBRANCH}; \
                    "
KBRANCH = "iotg-next/v6.11"
KMETA_BRANCH = "yocto-6.10"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

DEPENDS += "elfutils-native openssl-native util-linux-native"

# Functionality flags
KERNEL_EXTRA_FEATURES ?= "features/netfilter/netfilter.scc features/security/security.scc"
