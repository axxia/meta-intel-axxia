
require linux-yocto.inc

LINUX_VERSION = "3.10.65"

KBRANCH = "standard/preempt-rt/axxia/base"
KMETA = "meta"
KREPO = "git://git.yoctoproject.org/linux-yocto-3.10.git"

SRCREV_machine = "7511f4d2ce8049fcce67a76cb2cdc04edf4d8b72"
SRCREV_meta = "1b6394b7047e4b614e14145987463cb030dc81f9"

SRC_URI = "${KREPO};bareclone=1;branch=${KBRANCH},${KMETA};name=machine,meta"
SRC_URI += "file://fit"

require ${MACHINE}_3.10.inc
