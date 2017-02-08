FILESEXTRAPATHS_prepend := "${THISDIR}:"

COMPATIBLE_MACHINE = "^axxiaarm$|^axxiaarm64$|^axxiax86-64$"
INSANE_SKIP_kernel-dev = "debug-files"
PARALLEL_MAKE = ""

AXXIA_SRC ?= "linux-yocto"
#SMP ?= "yes"
#POWER_MANAGEMENT ?= "low-power"
#BIG_ENDIAN ?= "no"
#DBG ?= "no"
#TESTING ?= "no"
KV = "4.9"
LINUX_VERSION = "4.9.8"
KERNEL_EXTRA_FEATURES = ""

require ${AXXIA_SRC}_4.9.inc
