
require linux-yocto.inc

LINUX_VERSION = "3.10.65"

#KBRANCH = "standard/preempt-rt/axxia/base"
KBRANCH = "standard/axxia/base"
KREPO = "git://git.yoctoproject.org/linux-yocto-3.10.git"

SRCREV_machine ?= "7511f4d2ce8049fcce67a76cb2cdc04edf4d8b72"
SRCREV_meta ?= "9c4ff467f66428488b1cd9798066a8cb5d6b4c3b"