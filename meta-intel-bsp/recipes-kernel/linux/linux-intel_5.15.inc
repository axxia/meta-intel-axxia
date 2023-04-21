LINUX_VERSION_standard = "5.15.96"
LINUX_VERSION_preempt-rt = "5.15.96"
SRCREV_standard = "dfff915012ab62c58f33603bb3eeb3e21027b332"
SRCREV_preempt-rt = "6f0314a2d01136f4d0ed30e5df28e9dfb1aff037"
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
file://GRR-platform-msi-Add-device-MSI-infrastructure.patch \
file://GRR-genirq-msi-Provide-helpers-to-return-Linux-IRQ-dev_m.patch \
file://GRR-driver-core-auxiliary-bus-Add-Config-Option.patch \
"

# Replace patch from meta-axxia with a refreshed one for kernel 5.15.94
SRC_URI:remove = " file://0001-menuconfig-mconf-cfg-Allow-specification-of-ncurses-.patch"
SRC_URI:append = " file://0001-menuconfig-mconf-cfg-Allow-specification-of-ncurses-5.15.94.patch"

LINUX_VERSION:pn-linux-intel = "${LINUX_VERSION_standard}"
LINUX_VERSION:pn-linux-intel-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION:pn-linux-intel-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION:pn-linux-intel-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine:pn-linux-intel = "${SRCREV_standard}"
SRCREV_machine:pn-linux-intel-debug = "${SRCREV_standard}"
SRCREV_machine:pn-linux-intel-rt = "${SRCREV_preempt-rt}"
SRCREV_machine:pn-linux-intel-rt-debug = "${SRCREV_preempt-rt}"
