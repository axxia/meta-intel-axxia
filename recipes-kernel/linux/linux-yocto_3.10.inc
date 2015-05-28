
require linux-yocto.inc

LINUX_VERSION = "3.10.65"

KBRANCH = "standard/axxia/base"
KREPO = "git://git.yoctoproject.org/linux-yocto-3.10.git"

#SRCREV_machine ?= "87c1d0a694a7670b54e6e0e72e2f3614509ad333"
#SRCREV_meta ?= "9c4ff467f66428488b1cd9798066a8cb5d6b4c3b"
SRCREV_machine = "${AUTOREV}"
SRCREV_meta = "${AUTOREV}"
