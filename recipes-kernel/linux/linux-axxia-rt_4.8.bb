FILESEXTRAPATHS_prepend := "${THISDIR}:${THISDIR}/patches:\
${THISDIR}/conf/axxia-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require recipes-kernel/linux/linux-yocto.inc

inherit axxia-kernel

KV = "4.8"
LINUX_VERSION = "4.8.25"
LINUX_KERNEL_TYPE = "preempt-rt"
PV = "${LINUX_VERSION}+git${SRCPV}"

KBRANCH = "standard/preempt-rt/axxia-dev/base"
KREPO_KERNEL = "git://git@github.com/axxia/axxia_yocto_linux_4.8_private.git;protocol=ssh"
SRC_URI = "${KREPO_KERNEL};name=machine;branch=${KBRANCH} \
           file://0001-intel_th-pci-Add-Cedar-Fork-PCH-support.patch \
           file://0002-drivers-pinctrl-Backport-Cedar-Fork-GPIO.patch \
           file://fit \
           file://defconfig"
SRCREV_machine ="${AUTOREV}"
KMETA = ""

require dt/dt-${KARCH}.inc

COMPATIBLE_MACHINE = "^axxiax86-64$"
INSANE_SKIP_kernel-dev = "debug-files"

#SMP ?= "yes"
#POWER_MANAGEMENT ?= "low-power"
#CHIPSET ?= "5500"
#BIG_ENDIAN ?= "no"
#DBG ?= "no"
#TESTING ?= "no"
KERNEL_EXTRA_FEATURES = ""
