FILESEXTRAPATHS_prepend := "${THISDIR}:"

COMPATIBLE_MACHINE = "^axxiaarm64$"
INSANE_SKIP_kernel-dev = "debug-files"
PARALLEL_MAKE = ""

LINUX_KERNEL_TYPE = "preempt-rt"
LSI_SRC ?= "linux-yocto"
POWER_MANAGEMENT ?= "low-power"
BIG_ENDIAN ?= "no"
DBG ?= "no"
TESTING ?= "no"
KV = "4.1"
KERNEL_EXTRA_FEATURES = ""

require ${LSI_SRC}-rt_4.1.inc
