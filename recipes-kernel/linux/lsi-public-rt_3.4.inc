
require linux-yocto.inc

LSI_KERNEL_TAG = "7.8.1.39"
LINUX_VERSION = "3.4.88-${LSI_KERNEL_TAG}"

KBRANCH = "standard/preempt-rt/lsi/base"
KREPO = "git://github.com/lsigithub/lsi_axxia_yocto_public.git"

SRCREV_machine="2ca3532bf2ea4aa31b31307a52f7b1f56adef6df"
SRCREV_meta="03cd6f841fd2566b033db19eb6665228ea406adf"
