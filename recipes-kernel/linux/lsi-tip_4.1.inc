FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require dt-${KARCH}.inc

LSI_KERNEL_TAG = "tip"
LINUX_VERSION = "4.1.8-${LSI_KERNEL_TAG}"

KBRANCH = "standard/axxia-dev/base"
KREPO_KERNEL = "git://git@github.com/lsigithub/axxia_yocto_linux_4.1_private.git;protocol=ssh"
KREPO_META = "git://git.yoctoproject.org/yocto-kernel-cache"

SRCREV_machine ="${AUTOREV}"
SRCREV_meta ="${AUTOREV}"

SRC_URI = "${KREPO_KERNEL};name=machine;branch=${KBRANCH}; \
           ${KREPO_META};type=kmeta;name=meta;branch=yocto-4.1;destsuffix=${KMETA}"
SRC_URI += "file://fit"
SRC_URI += "file://defconfig"
