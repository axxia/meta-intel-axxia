
require linux-yocto.inc

LINUX_VERSION = "3.14.39"

KBRANCH = "standard/preempt-rt/axxia/base"
KREPO = "git://git.yoctoproject.org/linux-yocto-3.14.git"

SRCREV_machine = "${AUTOREV}"
SRCREV_meta = "${AUTOREV}"
