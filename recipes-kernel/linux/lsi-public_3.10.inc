
require linux-yocto.inc

LSI_KERNEL_TAG = "8.8.1.33"
LINUX_VERSION = "3.10.38-${LSI_KERNEL_TAG}"

KBRANCH = "standard/lsi/base"
KREPO = "git://github.com/lsigithub/lsi_axxia_yocto_public_3.10.git"

SRCREV_machine="8ac4827b975dd1047d94a5bd8d8790c50d60bb07"
SRCREV_meta="1eb79862c2959cfa305773e7f785d6d1810bf190"
