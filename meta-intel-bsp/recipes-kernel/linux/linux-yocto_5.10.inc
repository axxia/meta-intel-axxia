LINUX_VERSION_standard = "5.10.63"
LINUX_VERSION_preempt-rt = "5.10.63"
SRCREV_standard = "164ed895bc1e94722e80fe6496b176f6bb815cd4"
SRCREV_preempt-rt = "31e2870ebfd892708e8c5f3aced96565e2456ed9"
SRCREV_meta = "bce2813b162bb472c137fb503951295a931c25b6"

COMMON_PATCHES = " \
file://COM-0001-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://COM-0002-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
"

SNR_PATCHES = " ${COMMON_PATCHES} \
file://SNR-0001-perf-Cap-allocation-order-at-aux_watermark.patch \
file://SNR-0002-perf-intel-pt-Use-aux_watermark.patch \
"

GRR_PATCHES = " ${COMMON_PATCHES} \
file://GRR-0004-platform-msi-Add-device-MSI-infrastructure.patch \
file://GRR-0005-genirq-msi-Provide-helpers-to-return-Linux-IRQ-dev_m.patch \
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
