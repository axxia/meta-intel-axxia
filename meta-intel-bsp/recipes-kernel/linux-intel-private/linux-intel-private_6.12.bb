require recipes-kernel/linux/linux-yocto.inc
require recipes-kernel/linux/linux-axxia.inc
require linux-intel-private_6.12.inc

LINUX_VERSION_EXTENSION = "-intel-private-${LINUX_KERNEL_TYPE}"

SRC_URI = "git://github.com/intel-innersource/networking.wireless.transport.rdk.bts-kernel.git;protocol=https;name=machine;branch=${KBRANCH} \
          "
KBRANCH_INTEL_PRIVATE ?= "pmr/latest" 
KBRANCH = "${KBRANCH_INTEL_PRIVATE}"

KMETA = ""
KCONFIG_MODE = "alldefconfig"
KBUILD_DEFCONFIG:intel-axxia-pmr = "pmr_defconfig"
INTEL_AXXIA_FRAGS = ""
KERNEL_EXTRA_FEATURES = ""
KERNEL_FEATURES:remove = "cfg/efi.scc"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"
