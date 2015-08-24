FILESEXTRAPATHS_prepend := "${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/common:\
${THISDIR}/conf/${LSI_SRC}/linux-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}:"

require ${@base_conditional('KARCH', 'arm64', 'placeholder.inc', 'dt-${KARCH}.inc', d)}

LINUX_VERSION = "3.14.39"
KBRANCH = "standard/axxia/base"
SRCREV_machine ="${AUTOREV}"
SRCREV_meta ="${AUTOREV}"
SRC_URI += "file://fit"

require ${@base_conditional('KARCH', 'arm64', 'placeholder.inc', 'frags-${KARCH}-${KV}.inc', d)}
