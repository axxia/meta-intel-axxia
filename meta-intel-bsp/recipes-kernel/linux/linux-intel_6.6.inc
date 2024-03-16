LINUX_VERSION = "6.6.15"
SRCREV_machine = "8d72e5cc1f3f4a7b6bdbf8f008d67002b1f14ff8"
SRCREV_meta = "6b4249d0f2e333cf54123e4cba3636867e56bfac"

COMMON_PATCHES = " \
file://0001-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://0002-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
"

SNR_PATCHES = " \
"

GRR_PATCHES = " \
file://0001-platform-msi-Add-device-MSI-infrastructure.patch \
file://0002-driver-core-auxiliary-bus-Add-Config-Option.patch \
file://0003-intel_idle-add-Grand-Ridge-SoC-support.patch \
"

PMR_PATCHES = " \
file://0001-platform-msi-Add-device-MSI-infrastructure.patch \
file://0002-driver-core-auxiliary-bus-Add-Config-Option.patch \
"