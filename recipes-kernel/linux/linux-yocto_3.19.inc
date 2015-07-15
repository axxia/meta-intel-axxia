FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/common:\
${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require linux-yocto.inc

LINUX_VERSION = "3.19.2"

KBRANCH = "standard/axxia/base"
KMETA = "meta"
KREPO = "git://git.yoctoproject.org/linux-yocto-3.19"

SRCREV_machine = "30cd4222e08b9dc58d87ef48b14d85045c764b65"
#SRCREV_meta = "913358acd0e27f274c96da7d699e2d18b2c9ee27"
SRCREV_meta = "${AUTOREV}"

SRC_URI = "${KREPO};bareclone=1;branch=${KBRANCH},${KMETA};name=machine,meta"
SRC_URI += "file://fit"

require ${MACHINE}_${LINUX_KERNEL_TYPE}_${KV}.inc
