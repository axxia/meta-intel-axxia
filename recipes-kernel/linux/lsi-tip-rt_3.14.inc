FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require dt-${KARCH}.inc

LSI_KERNEL_TAG = "tip"
LINUX_VERSION = "3.14.39-${LSI_KERNEL_TAG}"
KBRANCH = "standard/preempt-rt/axxia-dev/base"
KMETA = ""
KREPO_KERNEL = "git://git@github.com/lsigithub/axxia_yocto_linux_3.14_private.git;protocol=ssh"
SRCREV_machine ="${AUTOREV}"
SRC_URI = "${KREPO_KERNEL};branch=${KBRANCH};name=machine"
SRC_URI += "file://fit"
SRC_URI += "file://defconfig"
