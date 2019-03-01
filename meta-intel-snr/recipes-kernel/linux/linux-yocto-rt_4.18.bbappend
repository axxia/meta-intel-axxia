KV = "4.18"
LINUX_VERSION_axxiax86-64 = "4.18.21"
KBRANCH_axxiax86-64 = "v4.18/standard/preempt-rt/base"
SRCREV_machine_axxiax86-64 = "6228ee37a46479d624e608c572d241f74eee11b6"
SRCREV_meta_axxiax86-64 = "8f4a98c93851f7f83d796aae2871df2798b8d917"

SNR_PATCHES = " \
file://SNR-0001-pinctrl-cedarfork-Correct-EAST-pin-ordering.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-acs-override.patch \
"

require linux-axxia.inc