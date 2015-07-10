FILESEXTRAPATHS_prepend := "${THISDIR}/conf/lsi-tip/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require linux-yocto.inc

LINUX_VERSION = "3.14.39"

KBRANCH = "standard/preempt-rt/axxia/base"
KMETA = "meta"
KREPO = "git://git.yoctoproject.org/linux-yocto-3.14.git"

SRCREV_machine = "26e942373fbc26ec8a14492e4eff841221442b3e"
SRCREV_meta = "4c54da246369a9da73f8b4571ea7c9e61faa4d69"

SRC_URI = "${KREPO};bareclone=1;branch=${KBRANCH},${KMETA};name=machine,meta"
SRC_URI += "file://fit"
SRC_URI += "file://defconfig"
