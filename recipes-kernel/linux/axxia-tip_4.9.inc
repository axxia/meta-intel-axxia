FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${AXXIA_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require dt-${KARCH}.inc

LINUX_VERSION = "4.9.36-tip"
KBRANCH = "standard/axxia-dev/base"
KMETA = ""
KREPO_KERNEL = "git://git@github.com/axxia/axxia_yocto_linux_4.9_private.git;protocol=ssh"
SRCREV_machine ="${AUTOREV}"
SRC_URI = "${KREPO_KERNEL};name=machine;branch=${KBRANCH}"
SRC_URI += "file://fit"
SRC_URI += "file://defconfig"
