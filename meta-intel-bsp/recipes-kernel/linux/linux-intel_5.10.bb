require recipes-kernel/linux/linux-intel.inc
require linux-axxia.inc
require linux-intel_5.10.inc

LINUX_VERSION_EXTENSION = "-intel-axxia-${LINUX_KERNEL_TYPE}"

SRC_URI = "git://github.com/intel/linux-intel-lts.git;protocol=https;name=machine;branch=${KBRANCH}; \
	   ${KERNEL_CONFIG_URI} \
	   file://0000-menuconfig-mconf-cfg-Allow-specification-of-ncurses-.patch \
	   file://0000-io-mapping-Cleanup-atomic-iomap.patch \
	   "

KBRANCH = "5.10/yocto"
KMETA_BRANCH = "yocto-5.10"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

DEPENDS += "elfutils-native openssl-native util-linux-native"

# Functionality flags
KERNEL_EXTRA_FEATURES ?= "features/netfilter/netfilter.scc features/security/security.scc"
