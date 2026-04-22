LINUX_VERSION = "6.18.19"
SRCREV_machine = "1fa8fa91abea837d76ab91c972e8387aae78157e"
SRCREV_meta = "465cb5bcefd72f429e0b3ad6ab5b3fcff5b390fc"

COMMON_PATCHES = " \
file://0001-lib-build_OID_registry-fix-reproducibility-issues.patch \
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
