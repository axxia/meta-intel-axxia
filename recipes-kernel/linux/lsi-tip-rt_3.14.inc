FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require dt-${KARCH}.inc

LSI_KERNEL_TAG = "tip"
LINUX_VERSION = "3.14.39-${LSI_KERNEL_TAG}"

KBRANCH = "standard/preempt-rt/axxia/base"
KREPO_KERNEL = "git://git@github.com/lsigithub/axxia_yocto_linux_3.14_private.git;protocol=ssh"
KREPO_META = "git://git.yoctoproject.org/yocto-kernel-cache"

SRCREV_machine ="${AUTOREV}"
SRCREV_meta ="${AUTOREV}"

SRC_URI = "${KREPO_KERNEL};branch=${KBRANCH};name=machine; \
           ${KREPO_META};type=kmeta;name=meta;branch=yocto-3.14;destsuffix=${KMETA}"
SRC_URI += "file://fit"
SRC_URI += "file://defconfig"
