LINUX_VERSION = "6.6.15"
SRCREV_machine = "332d4668fcc32826907d4f3c4938845206006089"
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
"

PMR_PATCHES = " \
file://0001-platform-msi-Add-device-MSI-infrastructure.patch \
file://0002-driver-core-auxiliary-bus-Add-Config-Option.patch \
"
