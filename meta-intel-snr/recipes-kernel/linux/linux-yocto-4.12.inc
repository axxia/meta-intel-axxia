require recipes-kernel/linux/linux-yocto.inc

SRC_URI = "git://git.yoctoproject.org/linux-yocto-4.12.git;name=machine;branch=${KBRANCH}; \
           git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=yocto-4.12;destsuffix=${KMETA}"

DEPENDS += "openssl-native util-linux-native"

PV = "${LINUX_VERSION}+git${SRCPV}"

KMETA = "kernel-meta"
KCONF_BSP_AUDIT_LEVEL = "2"

KV = "4.12"

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
file://SNR-0011-spi-nor-intel-spi-Fix-number-of-protected-range-regi.patch \
file://SNR-0012-spi-nor-intel-spi-Remove-useless-buf-parameter-in-th.patch \
file://SNR-0013-spi-nor-intel-spi-Check-transfer-length-in-the-HW-SW.patch \
file://SNR-0014-spi-nor-intel-spi-Use-SW-sequencer-for-BYT-LPT.patch \
file://SNR-0015-spi-nor-intel-spi-Remove-Atomic-Cycle-Sequence-in-in.patch \
file://SNR-0016-spi-nor-intel-spi-Don-t-assume-OPMENU0-1-to-be-progr.patch \
file://SNR-0017-spi-nor-intel-spi-Remove-the-unnecessary-HSFSTS-regi.patch \
file://SNR-0018-spi-nor-intel-spi-Rename-swseq-to-swseq_reg-in-struc.patch \
file://SNR-0019-spi-nor-intel-spi-Fall-back-to-use-SW-sequencer-to-e.patch \
file://SNR-0020-spi-nor-intel-spi-Remove-EXPERT-dependency.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-acs-override.patch \
"

SRC_URI_append_axxiax86-64 = " \
	file://BOTH-0003-uio-uio_pci_generic-don-t-fail-probe-if-pdev-irq-NUL.patch \
	"

require linux-axxia.inc
