LINUX_VERSION_standard = "5.4.50"
LINUX_VERSION_preempt-rt = "5.4.44"
SRCREV_standard = "89e6c056f3076641486519375f7bf280bf833223"
SRCREV_preempt-rt = "2e8933a927e7de6ca0e6191c90666a5f00fd7241"
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
