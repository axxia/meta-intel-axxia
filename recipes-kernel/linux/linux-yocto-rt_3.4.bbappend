FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/linux-3.4/${KARCH}:${THISDIR}:"

LINUX_KERNEL_TYPE = "preempt-rt"
LSI_SRC ?= "linux-yocto"
KV = "3.4"

require ${LSI_SRC}-rt_3.4.inc

SRC_URI = "${KREPO};nocheckout=1;branch=${KBRANCH},${KMETA};name=machine,meta"

SRC_URI += "file://defconfig"
SRC_URI += "file://fit"
