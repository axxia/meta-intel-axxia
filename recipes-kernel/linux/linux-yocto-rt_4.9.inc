FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${AXXIA_SRC}/linux-${KV}/${MACHINE}/common:\
${THISDIR}/conf/${AXXIA_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require dt-${KARCH}.inc
require frags-${KARCH}.inc

KBRANCH = "standard/preempt-rt/axxia/base"
SRCREV_machine ="${AUTOREV}"
SRCREV_meta ="${AUTOREV}"
SRC_URI += "file://fit"
