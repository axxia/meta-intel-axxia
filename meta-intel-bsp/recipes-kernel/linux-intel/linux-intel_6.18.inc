LINUX_VERSION = "6.18.33"
SRCREV_machine = "a9f2f3b43edac043dcca612544d2251ceaba0b8d"
SRCREV_meta = "4101033495af309ba83fc76eb3c0cbd0fb030f8c"

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
