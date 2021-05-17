LINUX_VERSION_standard = "5.10.34"
LINUX_VERSION_preempt-rt = "5.10.34"
SRCREV_standard = "85c17ad073e9249f261cc550e8ada89a900d7d9a"
SRCREV_preempt-rt = "400fbf5b14a0c88afb7c31d65be56fb9d6214c81"
SRCREV_meta = "38eb7ca3f4b59339c57a04c310f20809b198fa91"

SNR_PATCHES = " \
file://SNR-0001-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://SNR-0002-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-Enable-overrides-for-missing-ACS-capabil.patch \
"

LINUX_VERSION_pn-linux-yocto = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-yocto-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-yocto-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION_pn-linux-yocto-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine_pn-linux-yocto = "${SRCREV_standard}"
SRCREV_machine_pn-linux-yocto-debug = "${SRCREV_standard}"
SRCREV_machine_pn-linux-yocto-rt = "${SRCREV_preempt-rt}"
SRCREV_machine_pn-linux-yocto-rt-debug = "${SRCREV_preempt-rt}"
