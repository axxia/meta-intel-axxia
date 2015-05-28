FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/linux-3.10/${KARCH}:${THISDIR}:${THISDIR}/patch:"

LINUX_KERNEL_TYPE = "preempt-rt"
LSI_SRC ?= "linux-yocto"
KV = "3.10"

require ${LSI_SRC}-rt_3.10.inc

SRC_URI = "${KREPO};bareclone=1;branch=${KBRANCH},${KMETA};name=machine,meta"

SRC_URI += "file://defconfig"
SRC_URI += "file://fit"
