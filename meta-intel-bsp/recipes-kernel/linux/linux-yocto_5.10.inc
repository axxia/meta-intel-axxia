LINUX_VERSION_standard = "5.10.107"
LINUX_VERSION_preempt-rt = "5.10.107"
SRCREV_standard = "763c0dbc0458ebcb1d06afe2f324925f0f61bd27"
SRCREV_preempt-rt = "7f96d3fd60eea0ab38afdf07b3fc7c8c9f501802"
SRCREV_meta = "24ab54209a8822aad92afe2c51ea5b95f5175394"

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
file://GRR-mtd-spi-nor-intel-spi-add-is_protected-and-is_bios_l.patch \
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
file://GRR-mei-kdoc-fix-partial-back-port.patch \
file://GRR-mei-me-disable-driver-on-the-ign-firmware.patch \
"

LINUX_VERSION_pn-linux-yocto = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-yocto-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-yocto-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION_pn-linux-yocto-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine_pn-linux-yocto = "${SRCREV_standard}"
SRCREV_machine_pn-linux-yocto-debug = "${SRCREV_standard}"
SRCREV_machine_pn-linux-yocto-rt = "${SRCREV_preempt-rt}"
SRCREV_machine_pn-linux-yocto-rt-debug = "${SRCREV_preempt-rt}"
