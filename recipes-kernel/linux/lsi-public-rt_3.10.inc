
require linux-yocto.inc

LSI_KERNEL_TAG = "8.8.1.50"
LINUX_VERSION = "3.10.38-${LSI_KERNEL_TAG}"

KBRANCH = "standard/preempt-rt/lsi/base"
KREPO = "git://github.com/lsigithub/lsi_axxia_yocto_public_3.10.git"

SRCREV_machine ="e8262c2980bebc353ec42b15186536bf73611a2d"
SRCREV_meta ="${AUTOREV}"
