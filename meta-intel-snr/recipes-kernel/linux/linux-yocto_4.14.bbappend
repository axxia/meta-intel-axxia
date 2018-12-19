FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/frags/${KV}:"

KV = "4.14"
LINUX_VERSION_axxiax86-64 = "4.14.79"
KBRANCH_axxiax86-64 = "v4.14/standard/base"
KMACHINE_axxiax86-64 = "intel-corei7-64"
SRCREV_machine_axxiax86-64 = "f1d93b219bde37a8a286cd18d6af2dcf0d02c1a8"
SRCREV_meta_axxiax86-64 = "7fc4e9eb69bd011f7ef99380c261079a3e59a709"

# "snr" for Victoria Canyon or ASE.  "frio" for FPGA emulation system
RUNTARGET ?= "snr"

SNR_PATCHES = " \
file://SNR-0001-mtd-spi-nor-intel-spi-Add-support-for-Intel-Cedar-Fo.patch \
file://SNR-0002-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
file://SNR-0003-mmc-sdhci-pci-Add-support-for-Intel-CDF.patch \
file://SNR-0004-pinctrl-intel-Make-offset-to-interrupt-status-regist.patch \
file://SNR-0005-x86-cpufeatures-Enumerate-cldemote-instruction.patch \
file://SNR-0006-x86-intel_rdt-Add-command-line-parameter-to-control-.patch \
file://SNR-0007-serial-8250_mid-Enable-HSU-on-Intel-Cedar-Fork-PCH.patch \
file://SNR-0008-drivers-tty-8250-use-setup_timer-helper.patch \
file://SNR-0009-serial-8250-Convert-timers-to-use-timer_setup.patch \
file://SNR-0010-serial-8250-fix-potential-deadlock-in-rs485-mode.patch \
file://SNR-0011-pinctrl-cedarfork-Correct-EAST-pin-ordering.patch \
file://SNR-0012-spi-nor-intel-spi-Fix-number-of-protected-range-regi.patch \
file://SNR-0013-spi-nor-intel-spi-Remove-useless-buf-parameter-in-th.patch \
file://SNR-0014-spi-nor-intel-spi-Check-transfer-length-in-the-HW-SW.patch \
file://SNR-0015-spi-nor-intel-spi-Use-SW-sequencer-for-BYT-LPT.patch \
file://SNR-0016-spi-nor-intel-spi-Remove-Atomic-Cycle-Sequence-in-in.patch \
file://SNR-0017-spi-nor-intel-spi-Don-t-assume-OPMENU0-1-to-be-progr.patch \
file://SNR-0018-spi-nor-intel-spi-Remove-the-unnecessary-HSFSTS-regi.patch \
file://SNR-0019-spi-nor-intel-spi-Rename-swseq-to-swseq_reg-in-struc.patch \
file://SNR-0020-spi-nor-intel-spi-Fall-back-to-use-SW-sequencer-to-e.patch \
file://SNR-0021-spi-nor-intel-spi-Remove-EXPERT-dependency.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-acs-override.patch \
"

SRC_URI_append_axxiax86-64 = " \
	${@oe.utils.conditional('RUNTARGET', 'snr', '${SNR_PATCHES}', '', d)} \
	${@oe.utils.conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} \
	file://BOTH-0001-vfio-pci-Mask-buggy-SR-IOV-VF-INTx-support.patch \
	file://BOTH-0002-iommu-vt-d-Handle-domain-agaw-being-less-than-iommu-.patch \
	file://${RUNTARGET}-runtarget.scc \
	file://common.scc \
	"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"

require linux-axxia.inc
