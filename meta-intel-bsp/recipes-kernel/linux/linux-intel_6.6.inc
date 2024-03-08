LINUX_VERSION = "6.6.14"
SRCREV_machine = "bb56715daf2e0efbbd8cf00a04a020e83baa05cb"
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
file://0003-platform-x86-intel-vsec-Move-structures-to-header.patch \
file://0004-Added-S3M-auxiliary-driver-functionality-to-vsec-dri.patch \
file://0005-intel_s3m-Initial-release-for-intel_s3m-driver.patch \
file://0006-intel_idle-add-Grand-Ridge-SoC-support.patch \
"

PMR_PATCHES = " \
file://0001-platform-msi-Add-device-MSI-infrastructure.patch \
file://0002-driver-core-auxiliary-bus-Add-Config-Option.patch \
"
