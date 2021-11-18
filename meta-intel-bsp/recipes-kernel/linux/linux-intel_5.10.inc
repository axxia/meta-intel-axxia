LINUX_VERSION_standard = "5.10.56"
LINUX_VERSION_preempt-rt = "5.10.56"
SRCREV_standard = "cef410ba7c738624a98b855c955a0092789b224e"
SRCREV_preempt-rt = "8394053722549076e54a9dc82a92c513907d227f"
SRCREV_meta = "873ef26ef35da24d217a1aeb44717278d77e818c"

COMMON_PATCHES = " \
file://COM-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://COM-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://COM-watchdog-iTCO_wdt-use-module_platform_device-macro.patch \
file://COM-watchdog-iTCO_wdt-use-dev_-instead-of-pr_-for-loggin.patch \
file://COM-watchdog-iTCO_wdt-use-dev_err-instead-of-pr_err.patch \
file://COM-watchdog-iTCO_wdt-Fix-detection-of-SMI-off-case.patch \
file://COM-watchdog-iTCO_wdt-No-need-to-stop-the-timer-in-probe.patch \
"

SNR_PATCHES = " ${COMMON_PATCHES} \
file://SNR-perf-Cap-allocation-order-at-aux_watermark.patch \
file://SNR-perf-intel-pt-Use-aux_watermark.patch \
"

GRR_PATCHES = " ${COMMON_PATCHES} \
file://GRR-mtd-spi-nor-intel-spi-Move-platform-data-header-to-x.patch \
file://GRR-mtd-spi-nor-intel-spi-Add-support-for-second-flash-c.patch \
file://GRR-platform-msi-Add-device-MSI-infrastructure.patch \
file://GRR-genirq-msi-Provide-helpers-to-return-Linux-IRQ-dev_m.patch \
file://GRR-Add-auxiliary-bus-support.patch \
file://GRR-driver-core-auxiliary-bus-move-slab.h-from-include-f.patch \
file://GRR-driver-core-auxiliary-bus-make-remove-function-retur.patch \
file://GRR-driver-core-auxiliary-bus-minor-coding-style-tweaks.patch \
file://GRR-driver-core-auxiliary-bus-Fix-auxiliary-bus-shutdown.patch \
file://GRR-driver-core-auxiliary-bus-Fix-calling-stage-for-auxi.patch \
file://GRR-driver-core-auxiliary-bus-Remove-unneeded-module-bit.patch \
file://GRR-driver-core-auxiliary-bus-Fix-memory-leak-when-drive.patch \
file://GRR-driver-core-auxiliary-bus-Add-Config-Option.patch \
file://GRR-vfio-mdev-Add-a-member-for-iommu-domain-in-mdev_devi.patch \
file://GRR-vfio-type1-Save-domain-when-attach-domain-to-mdev.patch \
"

FRIO_PATCHES = " \
file://FRIO-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-drivers-pci-Enable-overrides-for-missing-ACS-capabil.patch \
"

LINUX_VERSION_pn-linux-intel = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-intel-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-intel-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION_pn-linux-intel-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine_pn-linux-intel = "${SRCREV_standard}"
SRCREV_machine_pn-linux-intel-debug = "${SRCREV_standard}"
SRCREV_machine_pn-linux-intel-rt = "${SRCREV_preempt-rt}"
SRCREV_machine_pn-linux-intel-rt-debug = "${SRCREV_preempt-rt}"
