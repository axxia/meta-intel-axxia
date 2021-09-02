LINUX_VERSION_standard = "5.10.41"
LINUX_VERSION_preempt-rt = "5.10.30"
SRCREV_standard = "916ac934a98bc8206c1b5e1500c891dbcb43aac7"
SRCREV_preempt-rt = "8b07bfbd844f73cbedc1f8eaa63e8b79295745d8"
SRCREV_meta = "cd049697e9b2d3e9118110d476075ff8f87202cc"

SNR_PATCHES = " \
file://SNR-0001-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://SNR-0002-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://SNR-0003-mtd-spi-nor-intel-spi-Move-platform-data-header-to-x.patch \
file://SNR-0004-mtd-spi-nor-intel-spi-Add-is_protected-and-bios_lock.patch \
file://SNR-0005-mtd-spi-nor-intel-spi-Add-support-for-second-flash-c.patch \
file://SNR-0006-platform-msi-Add-device-MSI-infrastructure.patch \
file://SNR-0007-genirq-msi-Provide-helpers-to-return-Linux-IRQ-dev_m.patch \
file://SNR-0008-drivers-mtd-Do-Not-Use-the-FSR-for-Some-Parts.patch \
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
