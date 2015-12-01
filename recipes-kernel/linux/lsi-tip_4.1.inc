FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require dt-${KARCH}.inc

LSI_KERNEL_TAG = "tip"
LINUX_VERSION = "4.1.8-${LSI_KERNEL_TAG}"
KBRANCH = "standard/axxia-dev/base"
KMETA = ""
KREPO_KERNEL = "git://git@github.com/lsigithub/axxia_yocto_linux_4.1_private.git;protocol=ssh"
SRCREV_machine ="${AUTOREV}"
SRC_URI = "${KREPO_KERNEL};name=machine;branch=${KBRANCH}"
SRC_URI += "file://fit"
SRC_URI += "file://defconfig"
