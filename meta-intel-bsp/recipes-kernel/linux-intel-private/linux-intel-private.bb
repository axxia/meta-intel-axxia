require recipes-kernel/linux/linux-yocto.inc
require recipes-kernel/linux/linux-axxia.inc

SRC_URI = "git://github.com/intel-innersource/networking.wireless.transport.rdk.bts-kernel.git;protocol=https;name=machine;branch=${KBRANCH}"

KBRANCH_INTEL_PRIVATE ?= "${CPU}/latest/${CPU}"
KBRANCH = "${KBRANCH_INTEL_PRIVATE}"

LINUX_VERSION = "dev.${@d.getVar('KBRANCH_INTEL_PRIVATE').replace('/','.')}"
LINUX_VERSION_EXTENSION = "-intel-private-${LINUX_KERNEL_TYPE}"

SRCREV_INTEL_PRIVATE ?= "${AUTOREV}"
SRCREV_machine = "${SRCREV_INTEL_PRIVATE}"

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
