
require linux-yocto.inc

LSI_KERNEL_TAG = "8.8.1.50"
LINUX_VERSION = "3.10.38-${LSI_KERNEL_TAG}"

KBRANCH = "standard/preempt-rt/lsi/base"
KREPO = "git://github.com/lsigithub/lsi_axxia_yocto_public_3.10.git"

SRCREV_machine ?="560c64f461183102703fc60476db858f4bf4b25b"
SRCREV_meta ?="9c4ff467f66428488b1cd9798066a8cb5d6b4c3b"
