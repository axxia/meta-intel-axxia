FILESEXTRAPATHS_prepend := "${THISDIR}/conf/yocto-${KV}/${MACHINE}/common:\
${THISDIR}/conf/yocto-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:${THISDIR}:"

inherit axxia-kernel

KV = "4.1"
LINUX_VERSION = "4.1.45"

KBRANCH = "standard/preempt-rt/axxia/base"
SRCREV_machine ="${AUTOREV}"
SRCREV_meta ="${AUTOREV}"
SRC_URI += "file://fit"

require dt/dt-${KARCH}.inc
require frags/frags-${KARCH}.inc

COMPATIBLE_MACHINE = "^axxiaarm$|^axxiaarm64$|^axxiapowerpc$"
INSANE_SKIP_kernel-dev = "debug-files"

SMP ?= "yes"
POWER_MANAGEMENT ?= "low-power"
CHIPSET ?= "5500"
BIG_ENDIAN ?= "no"
DBG ?= "no"
TESTING ?= "no"
KERNEL_EXTRA_FEATURES = ""
