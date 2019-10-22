require recipes-kernel/linux/linux-intel-rt_4.19.bb

KV = "4.19"
LINUX_VERSION = "4.19.72"
SRCREV_machine = "cf2e1ceb823576067ce01f02f1750a45c35adae5"
SRCREV_meta = "ad6f8b357720ca8167a090713b7746230cf4b314"

require linux-intel_${KV}.inc
require linux-axxia.inc

SRC_URI_append_axxiax86-64 = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-intel-axxia-debug-${LINUX_KERNEL_TYPE}"
