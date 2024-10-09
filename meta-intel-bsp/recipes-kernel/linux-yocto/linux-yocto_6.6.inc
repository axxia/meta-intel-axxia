LINUX_VERSION = "6.6.52"
SRCREV_machine = "01b1f32be4b0eb108c00b16ec4eef29ce7fa9546"
SRCREV_meta = "dc93ca87c4710ed799c8d45c8867c58685e88ecd"

COMMON_PATCHES = " \
file://0001-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://0002-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://0003-spi-Unify-error-codes-by-replacing-ENOTSUPP-with-EOP.patch \
"

SNR_PATCHES = " \
"

GRR_PATCHES = " \
file://0001-platform-msi-Add-device-MSI-infrastructure.patch \
file://0002-driver-core-auxiliary-bus-Add-Config-Option.patch \
file://0003-intel_idle-add-Grand-Ridge-SoC-support.patch \
file://0004-perf-Add-branch_sample_call_stack.patch \
file://0005-perf-Add-branch-stack-counters.patch \
file://0006-perf-x86-Add-PERF_X86_EVENT_NEEDS_BRANCH_STACK-flag.patch \
file://0007-perf-x86-intel-Support-branch-counters-logging.patch \
file://0008-perf-test-Basic-branch-counter-support.patch \
file://0009-tools-headers-UAPI-Sync-include-uapi-linux-perf_even.patch \
file://0010-perf-tools-Add-branch-counter-knob.patch \
file://0011-perf-header-Support-num-and-width-of-branch-counters.patch \
file://0012-perf-x86-intel-uncore-Support-Granite-Rapids.patch \
file://0013-perf-x86-intel-uncore-Support-IIO-free-running-count.patch \
file://0014-perf-x86-uncore-Use-u64-to-replace-unsigned-for-the-.patch \
file://0015-perf-x86-intel-uncore-Support-Sierra-Forest-and-Gran.patch \
file://0016-perf-x86-intel-uncore-Generic-uncore_get_uncores-and.patch \
file://0017-perf-x86-intel-cstate-Cleanup-duplicate-attr_groups.patch \
file://0018-perf-x86-intel-cstate-Add-Sierra-Forest-support.patch \
file://0019-perf-x86-intel-cstate-Add-Grand-Ridge-support.patch \
file://0020-x86-smp-Export-symbol-cpu_clustergroup_mask.patch \
file://0021-platform-x86-intel-uncore-freq-Ignore-minor-version-.patch \
file://0022-platform-x86-intel-tpmi-Add-defines-to-get-version-i.patch \
file://0024-EDAC-i10nm-Add-Intel-Grand-Ridge-micro-server-suppor.patch \
"

PMR_PATCHES = " \
file://0001-platform-msi-Add-device-MSI-infrastructure.patch \
file://0002-driver-core-auxiliary-bus-Add-Config-Option.patch \
"
