LINUX_VERSION_standard = "6.6.15"
LINUX_VERSION_preempt-rt = "6.6.15"
SRCREV_standard = "332d4668fcc32826907d4f3c4938845206006089"
SRCREV_preempt-rt = "f1ed79ed10e0107924041bfdb685230407343857"
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

LINUX_VERSION:pn-linux-yocto = "${LINUX_VERSION_standard}"
LINUX_VERSION:pn-linux-yocto-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION:pn-linux-yocto-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION:pn-linux-yocto-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine:pn-linux-yocto = "${SRCREV_standard}"
SRCREV_machine:pn-linux-yocto-debug = "${SRCREV_standard}"
SRCREV_machine:pn-linux-yocto-rt = "${SRCREV_preempt-rt}"
SRCREV_machine:pn-linux-yocto-rt-debug = "${SRCREV_preempt-rt}"
