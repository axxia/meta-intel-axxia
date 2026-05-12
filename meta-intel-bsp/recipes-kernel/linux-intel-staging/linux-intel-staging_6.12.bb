require recipes-kernel/linux/linux-intel.inc
require recipes-kernel/linux/linux-axxia.inc

SRC_URI:prepend = "git://github.com/intel-innersource/os.linux.kernel.kernel-staging.git;protocol=https;name=machine;branch=${KBRANCH}"

KBRANCH = "iotg-next/v6.12"
KMETA_BRANCH = "yocto-6.12"

LINUX_VERSION = "6.12.0"
LINUX_VERSION_EXTENSION = "-intel-staging-${LINUX_KERNEL_TYPE}"

SRCREV_machine = "411c5c5f39493db2835cf84b341e7b67bc3c15c5"
SRCREV_meta = "8f57fada9d056588228a27f6eaaaed9e176cd6a5"

COMMON_PATCHES = " \
"

SNR_PATCHES = " \
"

GRR_PATCHES = " \
"

PMR_PATCHES = " \
"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

# Functionality flags
KERNEL_EXTRA_FEATURES ?= "features/netfilter/netfilter.scc features/security/security.scc"
