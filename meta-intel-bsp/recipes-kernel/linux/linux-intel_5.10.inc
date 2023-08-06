LINUX_VERSION_standard = "5.10.184"
LINUX_VERSION_preempt-rt = "5.10.184"
SRCREV_standard = "c50f8c5a381297c74a9940132fdb407bc6545f5a"
SRCREV_preempt-rt = "eb7d29e72c2206523d080d04bcaa8791ab8fb61e"
SRCREV_meta = "e8e3b361b40a4bbf452caa0dfb255dad7ca9b0ce"

COMMON_PATCHES = " \
file://COM-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://COM-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://COM-watchdog-iTCO_wdt-use-module_platform_device-macro.patch \
file://COM-watchdog-iTCO_wdt-use-dev_err-instead-of-pr_err.patch \
file://COM-watchdog-iTCO_wdt-No-need-to-stop-the-timer-in-probe.patch \
file://COM-reboot-allow-to-specify-reboot-mode-via-sysfs.patch \
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
file://GRR-mei-kdoc-fix-partial-back-port.patch \
file://GRR-mei-me-disable-driver-on-the-ign-firmware.patch \
file://GRR-iommu-Add-support-to-change-default-domain-of-an-iom.patch \
file://GRR-Revert-EDAC-i10nm-Retrieve-and-print-retry_rd_err_lo.patch \
file://GRR-EDAC-i10nm-Add-detection-of-memory-levels-for-ICX-SP.patch \
file://GRR-EDAC-i10nm-Add-support-for-high-bandwidth-memory.patch \
file://GRR-EDAC-i10nm-Retrieve-and-print-retry_rd_err_log-1.patch \
file://GRR-EDAC-igen6-Make-sure-no-pending-errors.patch \
file://GRR-EDAC-igen6-Add-several-Intel-Alder-Lake-N-SoCs-suppo.patch \
file://GRR-EDAC-igen6-Add-another-Intel-Alder-Lake-SoC-support.patch \
file://GRR-EDAC-igen6-Add-another-Intel-Tiger-Lake-SoC-support.patch \
file://GRR-EDAC-skx_common-Add-new-ADXL-components-for-2-level-.patch \
file://GRR-EDAC-skx_common-Add-a-callback-of-decoding-errors-vi.patch \
file://GRR-EDAC-i10nm-Retrieve-and-print-retry_rd_err_log-2.patch \
file://GRR-EDAC-i10nm-Print-an-extra-register-set-of-retry_rd_e.patch \
file://GRR-EDAC-i10nm-Make-more-configurations-CPU-model-specif.patch \
file://GRR-EDAC-skx_common-Add-ChipSelect-ADXL-component.patch \
file://GRR-EDAC-i10nm-Add-Intel-Granite-Rapids-server-support.patch \
file://GRR-EDAC-i10nm-Add-Intel-Grand-Ridge-micro-server-suppor.patch \
"

LINUX_VERSION_pn-linux-intel = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-intel-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-intel-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION_pn-linux-intel-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine_pn-linux-intel = "${SRCREV_standard}"
SRCREV_machine_pn-linux-intel-debug = "${SRCREV_standard}"
SRCREV_machine_pn-linux-intel-rt = "${SRCREV_preempt-rt}"
SRCREV_machine_pn-linux-intel-rt-debug = "${SRCREV_preempt-rt}"
