LINUX_VERSION_standard = "5.10.184"
LINUX_VERSION_preempt-rt = "5.10.184"
SRCREV_standard = "c50f8c5a381297c74a9940132fdb407bc6545f5a"
SRCREV_preempt-rt = "eb7d29e72c2206523d080d04bcaa8791ab8fb61e"
SRCREV_meta = "e8e3b361b40a4bbf452caa0dfb255dad7ca9b0ce"

COMMON_PATCHES = " \
file://0001-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://0002-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://0003-watchdog-iTCO_wdt-use-module_platform_device-macro.patch \
file://0004-watchdog-iTCO_wdt-use-dev_err-instead-of-pr_err.patch \
file://0005-watchdog-iTCO_wdt-No-need-to-stop-the-timer-in-probe.patch \
file://0006-reboot-allow-to-specify-reboot-mode-via-sysfs.patch \
file://0007-mtd-spi-nor-intel-spi-Move-platform-data-header-to-x.patch \
file://0008-mtd-spi-nor-intel-spi-Add-support-for-second-flash-c.patch \
file://0009-Introduce-an-Intel-SPI-controller-level-mutex.patch \
"

SNR_PATCHES = " \
file://0001-perf-Cap-allocation-order-at-aux_watermark.patch \
file://0002-perf-intel-pt-Use-aux_watermark.patch \
"

GRR_PATCHES = " \
file://0001-platform-msi-Add-device-MSI-infrastructure.patch \
file://0002-genirq-msi-Provide-helpers-to-return-Linux-IRQ-dev_m.patch \
file://0003-vfio-mdev-Add-a-member-for-iommu-domain-in-mdev_devi.patch \
file://0004-vfio-type1-Save-domain-when-attach-domain-to-mdev.patch \
file://0005-mei-kdoc-fix-partial-back-port.patch \
file://0006-mei-me-disable-driver-on-the-ign-firmware.patch \
file://0007-iommu-Add-support-to-change-default-domain-of-an-iom.patch \
file://0008-Revert-EDAC-i10nm-Retrieve-and-print-retry_rd_err_lo.patch \
file://0009-EDAC-i10nm-Add-detection-of-memory-levels-for-ICX-SP.patch \
file://0010-EDAC-i10nm-Add-support-for-high-bandwidth-memory.patch \
file://0011-EDAC-i10nm-Retrieve-and-print-retry_rd_err_log-1.patch \
file://0012-EDAC-igen6-Make-sure-no-pending-errors.patch \
file://0013-EDAC-igen6-Add-several-Intel-Alder-Lake-N-SoCs-suppo.patch \
file://0014-EDAC-igen6-Add-another-Intel-Alder-Lake-SoC-support.patch \
file://0015-EDAC-igen6-Add-another-Intel-Tiger-Lake-SoC-support.patch \
file://0016-EDAC-skx_common-Add-new-ADXL-components-for-2-level-.patch \
file://0017-EDAC-skx_common-Add-a-callback-of-decoding-errors-vi.patch \
file://0018-EDAC-i10nm-Retrieve-and-print-retry_rd_err_log-2.patch \
file://0019-EDAC-i10nm-Print-an-extra-register-set-of-retry_rd_e.patch \
file://0020-EDAC-i10nm-Make-more-configurations-CPU-model-specif.patch \
file://0021-EDAC-skx_common-Add-ChipSelect-ADXL-component.patch \
file://0022-EDAC-i10nm-Add-Intel-Granite-Rapids-server-support.patch \
file://0023-EDAC-i10nm-Add-Intel-Grand-Ridge-micro-server-suppor.patch \
"

LINUX_VERSION:pn-linux-intel = "${LINUX_VERSION_standard}"
LINUX_VERSION:pn-linux-intel-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION:pn-linux-intel-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION:pn-linux-intel-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine:pn-linux-intel = "${SRCREV_standard}"
SRCREV_machine:pn-linux-intel-debug = "${SRCREV_standard}"
SRCREV_machine:pn-linux-intel-rt = "${SRCREV_preempt-rt}"
SRCREV_machine:pn-linux-intel-rt-debug = "${SRCREV_preempt-rt}"
