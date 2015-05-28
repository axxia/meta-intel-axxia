FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/linux-3.10/${KARCH}:${THISDIR}:${THISDIR}/patch:"

LINUX_KERNEL_TYPE = "standard"
LSI_SRC ?= "linux-yocto"
KV = "3.10"

require ${LSI_SRC}_3.10.inc

SRC_URI = "${KREPO};nocheckout=1;branch=${KBRANCH},${KMETA};name=machine,meta"

SRC_URI += "file://defconfig"
SRC_URI += "file://fit"
