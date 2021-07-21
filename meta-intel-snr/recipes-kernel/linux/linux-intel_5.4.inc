LINUX_VERSION_standard = "5.4.123"
LINUX_VERSION_preempt-rt = "5.4.123"
SRCREV_standard = "7a821854911e315d3ed3fe2fc626e12906c9ab24"
SRCREV_preempt-rt = "a6261c6ffb8eb5c0700ff0842565b4b38523dac4"
SRCREV_meta = "b8c82ba37370e4698ff0c42f3e54b8b4f2fb4ac0"

SNR_PATCHES = " \
file://SNR-0001-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://SNR-0002-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://SNR-0003-Support-EDAC-on-SNR-Bx-Stepping-Parts.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-Enable-overrides-for-missing-ACS-capabil.patch \
"

LINUX_VERSION_pn-linux-intel = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-intel-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-intel-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION_pn-linux-intel-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine_pn-linux-intel = "${SRCREV_standard}"
SRCREV_machine_pn-linux-intel-debug = "${SRCREV_standard}"
SRCREV_machine_pn-linux-intel-rt = "${SRCREV_preempt-rt}"
SRCREV_machine_pn-linux-intel-rt-debug = "${SRCREV_preempt-rt}"
