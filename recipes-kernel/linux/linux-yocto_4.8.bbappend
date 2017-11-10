FILESEXTRAPATHS_prepend := "${THISDIR}/conf/yocto-${KV}/${MACHINE}/common:\
${THISDIR}/conf/yocto-${KV}/${MACHINE}/${RUNTARGET}/${LINUX_KERNEL_TYPE}:${THISDIR}:${THISDIR}/patches:"

inherit axxia-kernel

KV = "4.8"
LINUX_VERSION = "4.8.25"

# skip yocto-kernel-cache for axxiax86_64 to use full defconfig untill we'll have fragments upstream
KMETA_SOURCES = "git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=yocto-4.8;destsuffix=${KMETA}"

# "simix" for simulation system or "frio" for FPGA emulation system
RUNTARGET ?= "simix"
FRIO_PATCHES = "file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
                file://FRIO-0002-pci-driver-HACK-reassign-Altera-FPGAs-if-they-have-n.patch \
                file://FRIO-0003-pci-driver-HACK-hardcode-size-of-bridge-window-to-NC.patch \
                file://FRIO-0004-pci-driver-HACK-don-t-allocate-additional-bridge-win.patch \
                file://FRIO-0005-pci-driver-HACK-merge-for-Altera.patch "

SRC_URI = "git://git.yoctoproject.org/linux-yocto-4.8.git;name=machine;branch=${KBRANCH}; \
           ${@base_conditional('MACHINE', 'axxiax86-64', '', '${KMETA_SOURCES}', d)} \
           file://COMMON-0001-intel_th-pci-Add-Cedar-Fork-PCH-support.patch \
           file://COMMON-0002-drivers-pinctrl-Backport-Cedar-Fork-GPIO.patch \
           ${@base_conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} "

KBRANCH = "standard/base"
SRCREV_machine ="${AUTOREV}"
SRCREV_meta ="${AUTOREV}"
SRC_URI += "file://fit"

require dt/dt-${KARCH}.inc
#require frags/frags-${KARCH}.inc

# use full defconfig for axxiax86_64 untill we'll have fragments upstream
SRC_URI += "${@base_conditional('MACHINE', 'axxiax86-64', 'file://defconfig', '', d)}"

COMPATIBLE_MACHINE = "^axxiax86-64$"
INSANE_SKIP_kernel-dev = "debug-files"

#SMP ?= "yes"
#POWER_MANAGEMENT ?= "low-power"
#CHIPSET ?= "5500"
#BIG_ENDIAN ?= "no"
#DBG ?= "no"
#TESTING ?= "no"
KERNEL_EXTRA_FEATURES = ""
