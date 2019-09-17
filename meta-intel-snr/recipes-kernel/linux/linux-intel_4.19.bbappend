KV = "4.19"

SNR_PATCHES = " \
file://SNR-0001-i2c-ismt-Add-support-for-Intel-Cedar-Fork.patch \
file://SNR-0002-PCI-AER-Remove-pci_cleanup_aer_uncorrect_error_statu.patch \
file://SNR-0003-dmaengine-ioat-fix-prototype-of-ioat_enumerate_chann.patch \
file://SNR-0004-dmaengine-ioatdma-Add-Snow-Ridge-ioatdma-device-id.patch \
file://SNR-0005-dmaengine-ioatdma-disable-DCA-enabling-on-IOATDMA-v3.patch \
file://SNR-0006-dmaengine-ioatdma-add-descriptor-pre-fetch-support-f.patch \
file://SNR-0007-dmaengine-ioatdma-support-latency-tolerance-report-L.patch \
file://SNR-0008-drivers-watchdog-Ignore-No-Reboot-Bit.patch \
file://SNR-0009-clocksource-Add-option-to-force-acpi_pm-as-clocksour.patch \
file://SNR-0010-x86-umwait-Initialize-umwait-control-values.patch \
file://SNR-0011-x86-umwait-Add-sysfs-interface-to-control-umwait-C0..patch \
file://SNR-0012-x86-umwait-Fix-error-handling-in-umwait_init.patch \
file://SNR-0013-x86-umwait-Add-sysfs-interface-to-control-umwait-max.patch \
file://SNR-0014-x86-cpufeatures-Enumerate-user-wait-instructions.patch \
file://SNR-0015-x86-cpufeatures-Enumerate-MOVDIRI-instruction.patch \
file://SNR-0016-x86-cpufeatures-Enumerate-MOVDIR64B-instruction.patch \
file://SNR-0017-PM-arch-x86-Rework-the-MSR_IA32_ENERGY_PERF_BIAS-han.patch \
file://SNR-0018-PM-arch-x86-MSR_IA32_ENERGY_PERF_BIAS-sysfs-interfac.patch \
file://SNR-0019-Documentation-ABI-Document-umwait-control-sysfs-inte.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-Enable-overrides-for-missing-ACS-capabil.patch \
"

require linux-axxia.inc
