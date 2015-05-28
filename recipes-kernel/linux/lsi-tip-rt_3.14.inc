
require linux-yocto.inc

LSI_KERNEL_TAG = "tip"
LINUX_VERSION = "3.14.39-${LSI_KERNEL_TAG}"

KBRANCH = "standard/preempt-rt/lsi/base"
KREPO = "git://git@github.com/lsigithub/axxia_yocto_linux_3.14_private.git;protocol=ssh"

SRCREV_machine="${AUTOREV}"
SRCREV_meta="${AUTOREV}"