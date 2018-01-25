FILESEXTRAPATHS_prepend := "\
${THISDIR}\
:${THISDIR}/conf/yocto-${KV}/${MACHINE}/common\
:${THISDIR}/conf/yocto-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

inherit axxia-kernel

KV = "4.1"
LINUX_VERSION = "4.1.48"

KBRANCH = "standard/axxia/base"
SRCREV_machine = "909c98a4f6512eaca1c975469d58b46b7326b8e9"
SRCREV_meta = "78e5080885b6c72d436fc14614e575ec0f422c76"
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
