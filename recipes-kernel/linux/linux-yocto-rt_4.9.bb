FILESEXTRAPATHS_prepend := "${THISDIR}:"

require recipes-kernel/linux/linux-yocto-rt_4.8.bb

SRC_URI = "git://git.yoctoproject.org/linux-yocto-4.9.git;name=machine;branch=${KBRANCH}; \
           git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=yocto-4.9;destsuffix=${KMETA}"

KV = "4.9"
LINUX_VERSION = "4.9.13"

COMPATIBLE_MACHINE = "^axxiaarm$|^axxiaarm64$|^axxiax86-64$"
INSANE_SKIP_kernel-dev = "debug-files"
PARALLEL_MAKE = ""

AXXIA_SRC ?= "linux-yocto"
SMP ?= "yes"
POWER_MANAGEMENT ?= "low-power"
CHIPSET ?= "5500"
BIG_ENDIAN ?= "no"
DBG ?= "no"
TESTING ?= "no"
KERNEL_EXTRA_FEATURES = ""

require ${AXXIA_SRC}-rt_4.9.inc
