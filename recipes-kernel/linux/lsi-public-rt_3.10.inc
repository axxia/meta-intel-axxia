
require linux-yocto.inc

LSI_KERNEL_TAG = "8.8.1.33"
LINUX_VERSION = "3.10.38-${LSI_KERNEL_TAG}"

KBRANCH = "standard/preempt-rt/lsi/base"
KREPO = "git://github.com/lsigithub/lsi_axxia_yocto_public_3.10.git"

SRCREV_machine="4ebe5ee757562dc1b2530dccf775ff55a28d570a"
SRCREV_meta="1eb79862c2959cfa305773e7f785d6d1810bf190"
