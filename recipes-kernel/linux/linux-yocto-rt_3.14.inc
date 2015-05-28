
require linux-yocto.inc

LINUX_VERSION = "3.14.39"

KBRANCH = "standard/preempt-rt/axxia/base"
KREPO = "git://git.yoctoproject.org/linux-yocto-3.14.git"

SRCREV_machine ?= "5ac60622463fd062e9c35e4953eee95d84895bb7"
SRCREV_meta ?= "9c4ff467f66428488b1cd9798066a8cb5d6b4c3b"
