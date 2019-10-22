require recipes-kernel/linux/linux-intel_4.19.bb

KV = "4.19"
LINUX_VERSION = "4.19.78"
SRCREV_machine = "fb2607123169ee7f1283cef35ef95ba86c425d48"
SRCREV_meta = "ad6f8b357720ca8167a090713b7746230cf4b314"

require linux-intel_${KV}.inc
require linux-axxia.inc

SRC_URI_append_axxiax86-64 = " file://debug.scc"

LINUX_VERSION_EXTENSION = "-intel-axxia-debug-${LINUX_KERNEL_TYPE}"
