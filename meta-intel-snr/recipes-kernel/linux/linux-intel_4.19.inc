LINUX_VERSION_standard = "4.19.78"
LINUX_VERSION_preempt-rt = "4.19.72"
SRCREV_standard = "fb2607123169ee7f1283cef35ef95ba86c425d48"
SRCREV_preempt-rt = "cf2e1ceb823576067ce01f02f1750a45c35adae5"
SRCREV_meta = "ad6f8b357720ca8167a090713b7746230cf4b314"

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
file://SNR-0020-vfio-pci-Mask-buggy-SR-IOV-VF-INTx-support.patch \
file://SNR-0021-EDAC-i10nm-Add-a-driver-for-Intel-10nm-server-proces.patch \
file://SNR-0022-perf-x86-kvm-Avoid-unnecessary-work-in-guest-filteri.patch \
file://SNR-0023-perf-x86-Support-outputting-XMM-registers.patch \
file://SNR-0024-perf-x86-intel-Extract-memory-code-PEBS-parser-for-r.patch \
file://SNR-0025-perf-x86-intel-ds-Extract-code-of-event-update-in-sh.patch \
file://SNR-0026-perf-x86-intel-Support-adaptive-PEBS-v4.patch \
file://SNR-0027-perf-x86-lbr-Avoid-reading-the-LBRs-when-adaptive-PE.patch \
file://SNR-0028-perf-x86-intel-Add-Tremont-core-PMU-support.patch \
file://SNR-0029-perf-tools-x86-Add-support-for-recording-and-printin.patch \
file://SNR-0030-perf-record-Fix-suggestion-to-get-list-of-registers-.patch \
file://SNR-0031-perf-parse-regs-Improve-error-output-when-faced-with.patch \
file://SNR-0032-perf-parse-regs-Split-parse_regs.patch \
file://SNR-0033-perf-parse-regs-Add-generic-support-for-arch__intr-u.patch \
file://SNR-0034-perf-regs-x86-Add-X86-specific-arch__intr_reg_mask.patch \
file://SNR-0035-perf-core-Add-PERF_PMU_CAP_NO_EXCLUDE-for-exclusion-.patch \
file://SNR-0036-perf-x86-Support-constraint-ranges.patch \
file://SNR-0037-perf-x86-intel-pt-Export-pt_cap_get.patch \
file://SNR-0038-perf-x86-intel-pt-Remove-software-double-buffering-P.patch \
file://SNR-0039-perf-x86-Disable-extended-registers-for-non-supporte.patch \
file://SNR-0040-perf-x86-regs-Check-reserved-bits.patch \
file://SNR-0041-perf-x86-Clean-up-PEBS_XMM_REGS.patch \
file://SNR-0042-perf-x86-Remove-pmu-pebs_no_xmm_regs.patch \
file://SNR-0043-perf-x86-regs-Use-PERF_REG_EXTENDED_MASK.patch \
file://SNR-0044-perf-x86-intel-uncore-Add-uncore-support-for-Snow-Ri.patch \
file://SNR-0045-perf-x86-intel-uncore-Support-multi-die-package.patch \
file://SNR-0046-perf-x86-intel-uncore-Cosmetic-renames-in-response-t.patch \
file://SNR-0047-perf-x86-intel-uncore-Factor-out-box-ref-unref-funct.patch \
file://SNR-0048-perf-x86-intel-uncore-Support-MMIO-type-uncore-block.patch \
file://SNR-0049-perf-x86-intel-uncore-Clean-up-client-IMC.patch \
file://SNR-0050-perf-x86-intel-uncore-Add-IMC-uncore-support-for-Sno.patch \
file://SNR-0051-perf-core-Add-function-to-test-for-event-exclusion-f.patch \
file://SNR-0052-x86-cpu-Add-Atom-Tremont-Jacobsville.patch \
file://SNR-0053-x86-cpufeature-Add-facility-to-check-for-min-microco.patch \
file://SNR-0054-perf-core-Add-perf_pmu_resched-as-global-function.patch \
file://SNR-0055-perf-x86-intel-Force-resched-when-TFA-sysctl-is-modi.patch \
file://SNR-0056-perf-x86-intel-Add-Icelake-support.patch \
file://SNR-0057-x86-smpboot-Rename-match_die-to-match_pkg.patch \
file://SNR-0058-perf-ring_buffer-Fix-AUX-software-double-buffering.patch \
file://SNR-0059-x86-topology-Add-CPUID.1F-multi-die-package-support.patch \
file://SNR-0060-x86-topology-Create-topology_max_die_per_package.patch \
file://SNR-0061-cpu-topology-Export-die_id.patch \
file://SNR-0062-x86-topology-Define-topology_die_id.patch \
file://SNR-0063-x86-topology-Define-topology_logical_die_id.patch \
file://SNR-0064-topology-Create-package_cpus-sysfs-attribute.patch \
file://SNR-0065-topology-Create-core_cpus-and-die_cpus-sysfs-attribu.patch \
file://SNR-0066-Revert-Changes-to-tools-perf.patch \
file://SNR-0067-pinctrl-intel-Avoid-potential-glitches-if-pin-is-in-.patch \
file://SNR-0068-intel_idle-add-support-for-Jacobsville.patch \
file://SNR-0069-x86-mce-Add-macros-for-the-corrected-error-count-bit.patch \
file://SNR-0070-ACPI-ADXL-Add-address-translation-interface-using-an.patch \
file://SNR-0071-EDAC-skx_common-Separate-common-code-out-from-skx_ed.patch \
file://SNR-0072-EDAC-skx_edac-Delete-duplicated-code.patch \
file://SNR-0073-EDAC-skx-i10nm-Make-skx_common.c-a-pure-library.patch \
file://SNR-0074-EDAC-i10nm-Add-Intel-additional-Ice-Lake-support.patch \
file://SNR-0075-EDAC-i10nm-Check-ECC-enabling-status-per-channel.patch \
file://SNR-0076-EDAC-skx-i10nm-Fix-source-ID-register-offset.patch \
file://SNR-0077-Support-EDAC-on-SNR-Bx-Stepping-Parts.patch \
file://SNR-0078-perf-vendor-events-intel-Add-Tremontx-event-file-v1..patch \
file://SNR-0079-x86-cpu-Add-Elkhart-Lake-to-Intel-family.patch \
file://SNR-0080-perf-x86-msr-Add-Tremont-support.patch \
file://SNR-0081-perf-x86-cstate-Add-Tremont-support.patch \
file://SNR-0082-perf-x86-intel-Add-more-available-bits-for-OFFCORE_R.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-Enable-overrides-for-missing-ACS-capabil.patch \
file://FRIO-0003-vfio-pci-Mask-buggy-SR-IOV-VF-INTx-support.patch \
"

LINUX_VERSION_pn-linux-intel = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-intel-debug = "${LINUX_VERSION_standard}"
LINUX_VERSION_pn-linux-intel-rt = "${LINUX_VERSION_preempt-rt}"
LINUX_VERSION_pn-linux-intel-rt-debug = "${LINUX_VERSION_preempt-rt}"

SRCREV_machine_pn-linux-intel = "${SRCREV_standard}"
SRCREV_machine_pn-linux-intel-debug = "${SRCREV_standard}"
SRCREV_machine_pn-linux-intel-rt = "${SRCREV_preempt-rt}"
SRCREV_machine_pn-linux-intel-rt-debug = "${SRCREV_preempt-rt}"
