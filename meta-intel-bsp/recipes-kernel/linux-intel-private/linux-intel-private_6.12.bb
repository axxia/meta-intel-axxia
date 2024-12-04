require recipes-kernel/linux/linux-intel.inc
require recipes-kernel/linux/linux-axxia.inc
require linux-intel-private_6.12.inc

LINUX_VERSION_EXTENSION = "-intel-private-${LINUX_KERNEL_TYPE}"

SRC_URI:prepend = "git://github.com/intel-innersource/networking.wireless.transport.rdk.bts-kernel.git;protocol=https;name=machine;branch=${KBRANCH}; \
                    "
KBRANCH = "pmr/latest" 
KMETA_BRANCH = "yocto-6.12"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

DEPENDS += "elfutils-native openssl-native util-linux-native"

# Functionality flags
KERNEL_EXTRA_FEATURES ?= "features/netfilter/netfilter.scc features/security/security.scc"
