LINUX_VERSION_standard = "5.4.93"
LINUX_VERSION_preempt-rt = "5.4.91"
SRCREV_standard = "8d1d3c280f86dbbaea50114eace1c9a1a398685f"
SRCREV_preempt-rt = "5c536585fb1d1888d9d3ff0ca3ac9e1a255d07b2"
SRCREV_meta = "09db22d544479b779be4a800b27910fd0ce6a05a"

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
