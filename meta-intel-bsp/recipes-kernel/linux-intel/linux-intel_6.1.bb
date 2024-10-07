require recipes-kernel/linux/linux-intel.inc
require recipes-kernel/linux/linux-axxia.inc
require linux-intel_6.1.inc

LINUX_VERSION_EXTENSION = "-intel-axxia-${LINUX_KERNEL_TYPE}"

SRC_URI:prepend = "git://github.com/intel/linux-intel-lts.git;protocol=https;name=machine;branch=${KBRANCH}; \
                    "
KBRANCH = "6.1/linux"
KMETA_BRANCH = "yocto-6.1"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

DEPENDS += "elfutils-native openssl-native util-linux-native"

# Functionality flags
KERNEL_EXTRA_FEATURES ?= "features/netfilter/netfilter.scc features/security/security.scc"

UPSTREAM_CHECK_GITTAGREGEX = "^lts-(?P<pver>v6.1.(\d+)-linux-(\d+)T(\d+)Z)$"
