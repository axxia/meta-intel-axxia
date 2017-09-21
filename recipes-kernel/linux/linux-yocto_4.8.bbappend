FILESEXTRAPATHS_prepend := "${THISDIR}/conf/yocto-${KV}/${MACHINE}/common:\
${THISDIR}/conf/yocto-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:${THISDIR}:"

inherit axxia-kernel

KV = "4.8"
LINUX_VERSION = "4.8.25"

# skip yocto-kernel-cache for axxiax86_64 to use full defconfig untill we'll have fragments upstream
KMETA_SOURCES = "git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=yocto-4.8;destsuffix=${KMETA}"

SRC_URI = "git://git.yoctoproject.org/linux-yocto-4.8.git;name=machine;branch=${KBRANCH}; \
           ${@base_conditional('MACHINE', 'axxiax86-64', '', '${KMETA_SOURCES}', d)}"

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
