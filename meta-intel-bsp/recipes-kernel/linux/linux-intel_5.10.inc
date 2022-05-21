LINUX_VERSION_standard = "5.10.78"
LINUX_VERSION_preempt-rt = "5.10.78"
SRCREV_standard = "4e8162d8163c74e46a9f0bafb860f42249702791"
SRCREV_preempt-rt = "c287378636ba3f627b4da448d62a75ed41a35982"
SRCREV_meta = "64fb693a6c11f21bab3ff9bb8dcb65a70abe05e3"

COMMON_PATCHES = " \
file://COM-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://COM-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://COM-watchdog-iTCO_wdt-use-module_platform_device-macro.patch \
file://COM-watchdog-iTCO_wdt-use-dev_-instead-of-pr_-for-loggin.patch \
file://COM-watchdog-iTCO_wdt-use-dev_err-instead-of-pr_err.patch \
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
file://GRR-vfio-mdev-Add-a-member-for-iommu-domain-in-mdev_devi.patch \
file://GRR-vfio-type1-Save-domain-when-attach-domain-to-mdev.patch \
file://GRR-driver-core-auxiliary-bus-Add-Config-Option.patch \
file://GRR-libsubcmd-Fix-use-after-free-for-realloc-.-0.patch \
file://GRR-mei-kdoc-fix-partial-back-port.patch \
file://GRR-mei-me-disable-driver-on-the-ign-firmware.patch \
"

LINUX_VERSION_pn-linux-intel = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-intel-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-intel-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION_pn-linux-intel-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine_pn-linux-intel = "${SRCREV_standard}"
SRCREV_machine_pn-linux-intel-debug = "${SRCREV_standard}"
SRCREV_machine_pn-linux-intel-rt = "${SRCREV_preempt-rt}"
SRCREV_machine_pn-linux-intel-rt-debug = "${SRCREV_preempt-rt}"
