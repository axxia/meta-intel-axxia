require recipes-kernel/linux/linux-yocto.inc
require recipes-kernel/linux/linux-axxia.inc

SRC_URI = "git://github.com/intel-innersource/networking.wireless.transport.rdk.bts-kernel.git;protocol=https;name=machine;branch=${KBRANCH}"

INTEL_PRIVATE_BRANCH ?= "${CPU}/latest/${CPU}"
KBRANCH = "${INTEL_PRIVATE_BRANCH}"

LINUX_VERSION = "dev.${@d.getVar('INTEL_PRIVATE_BRANCH').replace('/','.')}"
LINUX_VERSION_EXTENSION = "-intel-private-${LINUX_KERNEL_TYPE}"

INTEL_PRIVATE_REVISION ?= "${AUTOREV}"
SRCREV_machine = "${INTEL_PRIVATE_REVISION}"

COMMON_PATCHES = " \
"

SNR_PATCHES = " \
"

GRR_PATCHES = " \
"

PMR_PATCHES = " \
"

KMETA = ""
KCONFIG_MODE = "alldefconfig"
KBUILD_DEFCONFIG = "${CPU}_defconfig"
INTEL_AXXIA_FRAGS = ""
KERNEL_EXTRA_FEATURES = ""
KERNEL_FEATURES:remove = "cfg/efi.scc"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

KERNEL_VERSION_SANITY_SKIP = "1"
