FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}:"

require linux-yocto.inc

LSI_KERNEL_TAG = "tip"
LINUX_VERSION = "4.1.2-${LSI_KERNEL_TAG}"

KBRANCH = "standard/axxia-dev/base"
KREPO = "git://git@github.com/lsigithub/axxia_yocto_linux_4.1_private.git;protocol=ssh"

SRCREV_machine ="${AUTOREV}"
SRCREV_meta ="${AUTOREV}"

SRC_URI = "${KREPO};bareclone=1;branch=${KBRANCH},${KMETA};name=machine,meta"
SRC_URI += "file://fit"
SRC_URI += "file://defconfig"
