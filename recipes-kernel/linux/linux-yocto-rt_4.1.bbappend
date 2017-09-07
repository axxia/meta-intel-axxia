FILESEXTRAPATHS_prepend := "${THISDIR}:"

inherit axxia-kernel

KV = "4.1"
LINUX_VERSION = "4.1.43"

COMPATIBLE_MACHINE = "^axxiaarm$|^axxiaarm64$|^axxiapowerpc$"
INSANE_SKIP_kernel-dev = "debug-files"

AXXIA_SRC ?= "linux-yocto"
SMP ?= "yes"
POWER_MANAGEMENT ?= "low-power"
CHIPSET ?= "5500"
BIG_ENDIAN ?= "no"
DBG ?= "no"
TESTING ?= "no"
KERNEL_EXTRA_FEATURES = ""

require ${AXXIA_SRC}-rt_4.1.inc
