LINUX_VERSION_standard = "5.10.216"
LINUX_VERSION_preempt-rt = "5.10.216"
SRCREV_standard = "4af417c06d37be4517a786aef96716f13b4b7f3b"
SRCREV_preempt-rt = "421ad32504cf202dafd09394bae1ad6521539a49"
SRCREV_meta = "19c510890b99cfc450db69a97cf585593deb1d95"

COMMON_PATCHES = " \
file://0001-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://0002-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://0003-watchdog-iTCO_wdt-use-module_platform_device-macro.patch \
file://0004-watchdog-iTCO_wdt-use-dev_-instead-of-pr_-for-loggin.patch \
file://0005-watchdog-iTCO_wdt-use-dev_err-instead-of-pr_err.patch \
file://0006-Revert-mtd-spi-nor-intel-spi-Disable-write-protectio.patch \
file://0007-mtd-spi-nor-intel-spi-add-is_protected-and-is_bios_l.patch \
file://0008-mtd-spi-nor-intel-spi-Move-platform-data-header-to-x.patch \
file://0009-mtd-spi-nor-intel-spi-Add-support-for-second-flash-c.patch \
file://0010-reboot-allow-to-specify-reboot-mode-via-sysfs.patch \
file://0011-Introduce-an-Intel-SPI-controller-level-mutex.patch \
file://0012-mtd-spi-nor-handle-unsupported-FSR-opcodes-properly.patch \
"

SNR_PATCHES = " \
"

GRR_PATCHES = " \
file://0001-platform-msi-Add-device-MSI-infrastructure.patch \
file://0002-genirq-msi-Provide-helpers-to-return-Linux-IRQ-dev_m.patch \
file://0003-Add-auxiliary-bus-support.patch \
file://0004-driver-core-auxiliary-bus-move-slab.h-from-include-f.patch \
file://0005-driver-core-auxiliary-bus-make-remove-function-retur.patch \
file://0006-driver-core-auxiliary-bus-minor-coding-style-tweaks.patch \
file://0007-driver-core-auxiliary-bus-Fix-auxiliary-bus-shutdown.patch \
file://0008-driver-core-auxiliary-bus-Fix-calling-stage-for-auxi.patch \
file://0009-driver-core-auxiliary-bus-Remove-unneeded-module-bit.patch \
file://0010-driver-core-auxiliary-bus-Fix-memory-leak-when-drive.patch \
file://0011-driver-core-auxiliary-bus-Add-Config-Option.patch \
file://0012-mei-kdoc-fix-partial-back-port.patch \
file://0013-mei-me-disable-driver-on-the-ign-firmware.patch \
file://0014-vfio-mdev-Add-a-member-for-iommu-domain-in-mdev_devi.patch \
file://0015-vfio-type1-Save-domain-when-attach-domain-to-mdev.patch \
file://0016-Vt-d-patch.patch \
file://0017-iommu-Add-support-to-change-default-domain-of-an-iom.patch \
file://0018-EDAC-Add-three-new-memory-types.patch \
file://0019-EDAC-Add-DDR5-new-memory-type.patch \
file://0020-EDAC-i10nm-Add-Intel-Sapphire-Rapids-server-support.patch \
file://0021-EDAC-i10nm-Add-detection-of-memory-levels-for-ICX-SP.patch \
file://0022-EDAC-i10nm-Add-support-for-high-bandwidth-memory.patch \
file://0023-EDAC-i10nm-Retrieve-and-print-retry_rd_err_log-regis.patch \
file://0024-EDAC-igen6-Add-EDAC-driver-for-Intel-client-SoCs-usi.patch \
file://0025-EDAC-igen6-Add-debugfs-interface-for-Intel-client-So.patch \
file://0026-EDAC-igen6-Add-registration-APIs-for-In-Band-ECC-err.patch \
file://0027-EDAC-igen6-Add-Intel-ICL-NNPI-SoC-support.patch \
file://0028-EDAC-igen6-Add-Intel-Tiger-Lake-SoC-support.patch \
file://0029-EDAC-igen6-Add-Intel-Alder-Lake-SoC-support.patch \
file://0030-EDAC-igen6-Make-sure-no-pending-errors.patch \
file://0031-EDAC-igen6-Add-several-Intel-Alder-Lake-N-SoCs-suppo.patch \
file://0032-EDAC-igen6-Add-another-Intel-Alder-Lake-SoC-support.patch \
file://0033-EDAC-igen6-Add-another-Intel-Tiger-Lake-SoC-support.patch \
file://0034-EDAC-skx_common-Add-new-ADXL-components-for-2-level-.patch \
file://0035-EDAC-skx_common-Add-a-callback-of-decoding-errors-vi.patch \
file://0036-EDAC-i10nm-Retrieve-and-print-retry_rd_err_log-regis.patch \
file://0037-EDAC-i10nm-Print-an-extra-register-set-of-retry_rd_e.patch \
file://0038-EDAC-i10nm-Make-more-configurations-CPU-model-specif.patch \
file://0039-EDAC-skx_common-Add-ChipSelect-ADXL-component.patch \
file://0040-EDAC-i10nm-Add-Intel-Granite-Rapids-server-support.patch \
file://0041-EDAC-i10nm-Add-Intel-Grand-Ridge-micro-server-suppor.patch \
"

LINUX_VERSION_pn-linux-yocto = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-yocto-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-yocto-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION_pn-linux-yocto-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine_pn-linux-yocto = "${SRCREV_standard}"
SRCREV_machine_pn-linux-yocto-debug = "${SRCREV_standard}"
SRCREV_machine_pn-linux-yocto-rt = "${SRCREV_preempt-rt}"
SRCREV_machine_pn-linux-yocto-rt-debug = "${SRCREV_preempt-rt}"
