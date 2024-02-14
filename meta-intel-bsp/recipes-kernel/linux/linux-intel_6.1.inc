LINUX_VERSION = "6.1.69"
SRCREV_machine = "6dc9c8bac0a2a28811f198fcb7d418faa0868654"
SRCREV_meta = "43d1723dbe0ce7b341cf32feeb35ecbe6b0ce29a"

COMMON_PATCHES = " \
file://0001-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://0002-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
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
