LINUX_VERSION_standard = "5.10.25"
LINUX_VERSION_preempt-rt = "5.10.25"
SRCREV_standard = "cf5b0320cf4544d3db9ce3ddd6ddb7553a610651"
SRCREV_preempt-rt = "be2935bce35f9adb6d0e735d42651e81a5094adf"
SRCREV_meta = "eb09284047fec2f09d62068c338ae320c6681bd1"

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
