
require linux-yocto.inc

LSI_KERNEL_TAG = "tip"
LINUX_VERSION = "3.10.38-${LSI_KERNEL_TAG}"

KBRANCH = "standard/lsi/base"
KREPO = "git://git@github.com/lsigithub/lsi_axxia_yocto_3.10.git;protocol=ssh"

SRCREV_machine="${AUTOREV}"
SRCREV_meta="${AUTOREV}"