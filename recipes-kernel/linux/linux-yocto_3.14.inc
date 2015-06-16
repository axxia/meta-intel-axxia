
require linux-yocto.inc

LINUX_VERSION = "3.14.39"

KBRANCH = "standard/axxia/base"
KREPO = "git://git.yoctoproject.org/linux-yocto-3.14"


#SRCREV_machine = "bda175966009d5a94103559e6e6ae51279952f39"
#SRCREV_meta = "{AUTOREV}"
SRCREV_machine = "${AUTOREV}"
SRCREV_meta = "${AUTOREV}"
