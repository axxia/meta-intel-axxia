LINUX_VERSION = "6.18.52"
SRCREV_machine = "364c4b44ab2dcc7dfff16076522b62827bcb0e7d"
SRCREV_meta = "2184786cc3deed04926e1cca6c320ed9314da9da"

COMMON_PATCHES = " \
file://0001-lib-build_OID_registry-fix-reproducibility-issues.patch \
file://0002-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://0003-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://0004-lib-crc-Add-CRC8-Config-Option.patch \
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
