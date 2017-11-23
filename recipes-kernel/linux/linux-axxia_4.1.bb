FILESEXTRAPATHS_prepend := "\
${THISDIR}\
:${THISDIR}/conf/axxia-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require recipes-kernel/linux/linux-yocto.inc

inherit axxia-kernel

KV = "4.1"
LINUX_VERSION = "4.1.42"
LINUX_KERNEL_TYPE = "standard"
PV = "${LINUX_VERSION}+git${SRCPV}"

KBRANCH = "standard/axxia-dev/base"
KREPO_KERNEL = "git://git@github.com/axxia/axxia_yocto_linux_4.1_private.git;protocol=ssh"
SRC_URI = "${KREPO_KERNEL};name=machine;branch=${KBRANCH} \
           file://fit \
           file://defconfig"
SRCREV_machine = "${AUTOREV}"
KMETA = ""

require dt/dt-${KARCH}.inc

COMPATIBLE_MACHINE = "^axxiaarm$|^axxiaarm64$|^axxiapowerpc$"
INSANE_SKIP_kernel-dev = "debug-files"

SMP ?= "yes"
POWER_MANAGEMENT ?= "low-power"
CHIPSET ?= "5500"
BIG_ENDIAN ?= "no"
DBG ?= "no"
TESTING ?= "no"
KERNEL_EXTRA_FEATURES = ""