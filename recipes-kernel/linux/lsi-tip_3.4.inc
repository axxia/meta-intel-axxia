
require linux-yocto.inc

LSI_KERNEL_TAG = "tip"
LINUX_VERSION = "3.4.88-${LSI_KERNEL_TAG}"

KBRANCH = "standard/lsi/base"
KREPO = "git://git@github.com/lsigithub/lsi_axxia_yocto.git;protocol=ssh"

SRCREV_machine="${AUTOREV}"
SRCREV_meta="${AUTOREV}"