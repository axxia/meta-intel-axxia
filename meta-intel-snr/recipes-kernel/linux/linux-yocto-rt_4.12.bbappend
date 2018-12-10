FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/frags/${KV}:"

KV = "4.12"
LINUX_VERSION_axxiax86-64 = "4.12.29"
KBRANCH_axxiax86-64 = "standard/preempt-rt/base"
KMACHINE_axxiax86-64 = "intel-corei7-64"
SRCREV_machine_axxiax86-64 = "930622b5cdb1fea9cad09ced7a53b385bdcccaee"
SRCREV_meta_axxiax86-64 = "12333728637b4fc73c48cc742e444cb5f60485fd"

# "snr" for Victoria Canyon or ASE.  "frio" for FPGA emulation system
RUNTARGET ?= "snr"

SNR_PATCHES = " \
file://SNR-0001-i2c-i801-Add-support-for-Intel-Cedar-Fork.patch \
file://SNR-0002-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
file://SNR-0003-mmc-sdhci-pci-Add-support-for-Intel-CDF.patch \
file://SNR-0004-pinctrl-intel-Make-offset-to-interrupt-status-regist.patch \
file://SNR-0005-x86-cpufeatures-Enumerate-cldemote-instruction.patch \
file://SNR-0006-x86-intel_rdt-Add-command-line-parameter-to-control-.patch \
file://SNR-0007-serial-8250_mid-Enable-HSU-on-Intel-Cedar-Fork-PCH.patch \
file://SNR-0008-drivers-tty-8250-use-setup_timer-helper.patch \
file://SNR-0009-serial-8250-Convert-timers-to-use-timer_setup.patch \
file://SNR-0010-pinctrl-cedarfork-Correct-EAST-pin-ordering.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-acs-override.patch \
"

SRC_URI_append_axxiax86-64 = " \
	${@base_conditional('RUNTARGET', 'snr', '${SNR_PATCHES}', '', d)} \
	${@base_conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} \
	file://BOTH-0001-vfio-pci-Mask-buggy-SR-IOV-VF-INTx-support.patch \
	file://BOTH-0002-iommu-vt-d-Handle-domain-agaw-being-less-than-iommu-.patch \
	file://BOTH-0003-uio-uio_pci_generic-don-t-fail-probe-if-pdev-irq-NUL.patch \
	file://${RUNTARGET}-runtarget.scc \
	file://common.scc \
	"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"

require linux-axxia.inc
