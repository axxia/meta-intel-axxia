FILESEXTRAPATHS_prepend := "${THISDIR}:"

COMPATIBLE_MACHINE = "^axxiaarm$|^axxiapowerpc$"
INSANE_SKIP_kernel-dev = "debug-files"
PARALLEL_MAKE = ""

LINUX_KERNEL_TYPE = "standard"
LSI_SRC ?= "linux-yocto"
POWER_MANAGEMENT ?= "low-power"
CHIPSET ?= "5500"
BIG_ENDIAN ?= "no"
DBG ?= "no"
TESTING ?= "no"
KV = "3.14"
KERNEL_EXTRA_FEATURES = ""

require ${LSI_SRC}_3.14.inc
