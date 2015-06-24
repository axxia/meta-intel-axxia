FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require linux-yocto.inc

LSI_KERNEL_TAG = "tip"
LINUX_VERSION = "3.10.38-${LSI_KERNEL_TAG}"

KBRANCH = "standard/lsi/base"
KREPO = "git://git@github.com/lsigithub/lsi_axxia_yocto_3.10.git;protocol=ssh"

SRCREV_machine="${AUTOREV}"
SRCREV_meta="${AUTOREV}"

SRC_URI = "${KREPO};nocheckout=1;branch=${KBRANCH},${KMETA};name=machine,meta"
SRC_URI += "file://fit"
SRC_URI += "file://defconfig"
