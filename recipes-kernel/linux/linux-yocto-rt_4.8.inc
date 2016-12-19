# Use linux 4.8 from yocto, but with defconfig instead fragments
FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${AXXIA_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

# require dt-${KARCH}.inc
# require frags-${KARCH}.inc

KBRANCH = "standard/preempt-rt/base"
SRCREV_machine ="${AUTOREV}"
# SRCREV_meta ="${AUTOREV}"
SRC_URI += "file://fit"

# Use defconfig until proper fragments will pe pushed to yocto-kernel-cache. If not:
# [ERROR] No configuration fragments found, this typically is a misconfigured BSP. 
SRC_URI += "file://defconfig"
