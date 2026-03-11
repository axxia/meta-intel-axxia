LINUX_VERSION = "6.1.166"
SRCREV_machine = "fba1566243637aeb16554272b0a8627bf5d0fbfc"
SRCREV_meta = "aab21b2ddf5eeeed1d7171141e847ca9d33bbb82"

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
