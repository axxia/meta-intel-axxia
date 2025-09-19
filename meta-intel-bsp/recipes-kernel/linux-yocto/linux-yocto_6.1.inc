LINUX_VERSION = "6.1.152"
SRCREV_machine = "325d5faeaf770957a79b1c413c18e07c8680d372"
SRCREV_meta = "325d5faeaf770957a79b1c413c18e07c8680d372"

COMMON_PATCHES = " \
file://0001-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://0002-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://0003-perf-cpumap-Make-counter-as-unsigned-ints.patch \
"

SNR_PATCHES = " \
"

GRR_PATCHES = " \
file://0001-platform-msi-Add-device-MSI-infrastructure.patch \
file://0002-driver-core-auxiliary-bus-Add-Config-Option.patch \
"

PMR_PATCHES = " \
file://0001-platform-msi-Add-device-MSI-infrastructure.patch \
file://0002-driver-core-auxiliary-bus-Add-Config-Option.patch \
"
