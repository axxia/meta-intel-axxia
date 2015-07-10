FILESEXTRAPATHS_prepend := "${THISDIR}/conf/lsi-tip/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require linux-yocto.inc

LINUX_VERSION = "3.14.39"

KBRANCH = "standard/axxia/base"
KMETA = "meta"
KREPO = "git://git.yoctoproject.org/linux-yocto-3.19"

SRCREV_machine = "f490412acb655a4573f7612a7fcfa806674a46f6"
SRCREV_meta = "4c54da246369a9da73f8b4571ea7c9e61faa4d69"

SRC_URI = "${KREPO};bareclone=1;branch=${KBRANCH},${KMETA};name=machine,meta"
SRC_URI += "file://fit"
SRC_URI += "file://defconfig"
