LINUX_VERSION_standard = "5.15.129"
LINUX_VERSION_preempt-rt = "5.15.129"
SRCREV_standard = "6a3035823c5db6ee250a049f98a6d7bd53f837c7"
SRCREV_preempt-rt = "0aa56022fb159e8e577f34e6ef509e1cee4632f4"
SRCREV_meta = "0b002d94afb8a3b60ed1f3be419cb9f5a8815cfc"

COMMON_PATCHES = " \
file://COM-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://COM-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://COM-watchdog-iTCO_wdt-No-need-to-stop-the-timer-in-probe.patch \
file://COM-libata-add-horkage-for-missing-Identify-Device-log.patch \
file://COM-mtd-spi-nor-intel-spi-Add-support-for-second-flash-c.patch \
file://COM-Introduce-an-Intel-SPI-controller-level-mutex.patch \
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
