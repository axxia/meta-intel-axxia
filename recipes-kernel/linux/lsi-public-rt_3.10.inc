FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require linux-yocto.inc

LSI_KERNEL_TAG = "8.8.1.50"
LINUX_VERSION = "3.10.38-${LSI_KERNEL_TAG}"

KBRANCH = "standard/preempt-rt/lsi/base"
KREPO = "git://github.com/lsigithub/lsi_axxia_yocto_public_3.10.git"

SRCREV_machine="560c64f461183102703fc60476db858f4bf4b25b"
SRCREV_meta="d07bc7ba4ff00ddcd77db1026a63c327b81a35d8"

SRC_URI = "${KREPO};bareclone=1;branch=${KBRANCH},${KMETA};name=machine,meta"
SRC_URI += "file://fit"
SRC_URI += "file://defconfig"
