LINUX_VERSION = "6.12.76"
SRCREV_machine = "068a40a467541f1977624c4b91d75eaa5f2c8f83"
SRCREV_meta = "9a7e5434a02c01df4901784d29694d940743d56c"

COMMON_PATCHES = " \
file://0001-6.12-lib-build_OID_registry-fix-reproducibility-issues.patch \
file://0002-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://0003-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
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
