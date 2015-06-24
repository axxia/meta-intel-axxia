FILESEXTRAPATHS_prepend := "${THISDIR}:"

LINUX_KERNEL_TYPE = "preempt-rt"
LSI_SRC ?= "linux-yocto"
POWER_MANAGEMENT ?= "low-power"
BIG_ENDIAN ?= "no"
DBG ?= "no"
TESTING ?= "no"
KV = "3.14"
KERNEL_EXTRA_FEATURES = ""

require ${LSI_SRC}-rt_3.14.inc
