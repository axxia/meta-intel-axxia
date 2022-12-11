LINUX_VERSION_standard = "5.15.71"
LINUX_VERSION_preempt-rt = "5.15.71"
SRCREV_standard = "7f0de68338ad7f625a7137278bf1d0a5edcbab45"
SRCREV_preempt-rt = "e29405e36bfbda7ace776548de802b76f61b80d9"
SRCREV_meta = "50e12441b95837206d02d3ecfd17b1c562759d76"

COMMON_PATCHES = " \
file://COM-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://COM-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://COM-watchdog-iTCO_wdt-No-need-to-stop-the-timer-in-probe.patch \
file://COM-libata-add-horkage-for-missing-Identify-Device-log.patch \
"

SNR_PATCHES = " ${COMMON_PATCHES} \
"

GRR_PATCHES = " ${COMMON_PATCHES} \
file://GRR-mtd-spi-nor-intel-spi-add-is_protected-and-is_bios_l.patch \
file://GRR-mtd-spi-nor-intel-spi-Add-support-for-second-flash-c.patch \
file://GRR-platform-msi-Add-device-MSI-infrastructure.patch \
file://GRR-genirq-msi-Provide-helpers-to-return-Linux-IRQ-dev_m.patch \
file://GRR-driver-core-auxiliary-bus-Add-Config-Option.patch \
"

LINUX_VERSION:pn-linux-intel = "${LINUX_VERSION_standard}"
LINUX_VERSION:pn-linux-intel-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION:pn-linux-intel-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION:pn-linux-intel-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine:pn-linux-intel = "${SRCREV_standard}"
SRCREV_machine:pn-linux-intel-debug = "${SRCREV_standard}"
SRCREV_machine:pn-linux-intel-rt = "${SRCREV_preempt-rt}"
SRCREV_machine:pn-linux-intel-rt-debug = "${SRCREV_preempt-rt}"
