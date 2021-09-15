LINUX_VERSION_standard = "5.10.56"
LINUX_VERSION_preempt-rt = "5.10.56"
SRCREV_standard = "cef410ba7c738624a98b855c955a0092789b224e"
SRCREV_preempt-rt = "8394053722549076e54a9dc82a92c513907d227f"
SRCREV_meta = "873ef26ef35da24d217a1aeb44717278d77e818c"

SNR_PATCHES = " \
file://SNR-0001-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://SNR-0002-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://SNR-0006-platform-msi-Add-device-MSI-infrastructure.patch \
file://SNR-0007-genirq-msi-Provide-helpers-to-return-Linux-IRQ-dev_m.patch \
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
