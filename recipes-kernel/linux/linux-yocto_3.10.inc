FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/common:\
${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require linux-yocto.inc

LINUX_VERSION = "3.10.65"

KBRANCH = "standard/axxia/base"
KMETA = "meta"
KREPO = "git://git.yoctoproject.org/linux-yocto-3.10.git"

SRCREV_machine = "87c1d0a694a7670b54e6e0e72e2f3614509ad333"
SRCREV_meta = "1e670aaa446b3d6a72eb527bf9b8af04bc5a96ef"

SRC_URI = "${KREPO};nocheckout=1;branch=${KBRANCH},${KMETA};name=machine,meta"
SRC_URI += "file://fit"

require ${MACHINE}_${LINUX_KERNEL_TYPE}_${KV}.inc
