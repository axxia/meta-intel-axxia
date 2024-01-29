LINUX_VERSION_standard = "6.6.13"
LINUX_VERSION_preempt-rt = "6.6.13"
SRCREV_standard = "43f7233f561431ae4c0e745985921bc84095a39e"
SRCREV_preempt-rt = "55f4682a75d1673cd78504a7342918c1b5dc4d16"
SRCREV_meta = "b45c991cb442e78a307565783e14d31048ad3ee6"

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

LINUX_VERSION:pn-linux-yocto = "${LINUX_VERSION_standard}"
LINUX_VERSION:pn-linux-yocto-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION:pn-linux-yocto-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION:pn-linux-yocto-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine:pn-linux-yocto = "${SRCREV_standard}"
SRCREV_machine:pn-linux-yocto-debug = "${SRCREV_standard}"
SRCREV_machine:pn-linux-yocto-rt = "${SRCREV_preempt-rt}"
SRCREV_machine:pn-linux-yocto-rt-debug = "${SRCREV_preempt-rt}"
