
require linux-yocto.inc

LSI_KERNEL_TAG = "8.8.1.33"
LINUX_VERSION = "3.10.55-${LSI_KERNEL_TAG}"

KBRANCH = "standard/lsi/base"
KREPO = "git://github.com/lsigithub/lsi_axxia_yocto_public_3.10.git"

SRCREV_machine ?="e8262c2980bebc353ec42b15186536bf73611a2d"
SRCREV_meta ?="9c4ff467f66428488b1cd9798066a8cb5d6b4c3b"
