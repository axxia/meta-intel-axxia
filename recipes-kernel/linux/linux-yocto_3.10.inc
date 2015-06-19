
require linux-yocto.inc

LINUX_VERSION = "3.10.65"

KBRANCH = "standard/axxia/base"
KMETA = "meta"
KREPO = "git://git.yoctoproject.org/linux-yocto-3.10.git"

SRCREV_machine = "87c1d0a694a7670b54e6e0e72e2f3614509ad333"
SRCREV_meta = "1b6394b7047e4b614e14145987463cb030dc81f9"

SRC_URI = "${KREPO};nocheckout=1;branch=${KBRANCH},${KMETA};name=machine,meta"
SRC_URI += "file://fit"

require ${MACHINE}_3.10.inc
