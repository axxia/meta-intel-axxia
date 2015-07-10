FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require linux-yocto.inc

LSI_KERNEL_TAG = "tip"
LINUX_VERSION = "3.19.2-${LSI_KERNEL_TAG}"

KBRANCH = "standard/preempt-rt/axxia/base"
KREPO = "git://git@github.com/lsigithub/axxia_yocto_linux_3.19_private.git;protocol=ssh"

SRCREV_machine ="${AUTOREV}"
SRCREV_meta ="${AUTOREV}"

SRC_URI = "${KREPO};bareclone=1;branch=${KBRANCH},${KMETA};name=machine,meta"
SRC_URI += "file://fit"
SRC_URI += "file://defconfig"
