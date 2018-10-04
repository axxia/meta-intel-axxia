FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/frags/${KV}:"

KV = "4.14"
LINUX_VERSION_EXTENSION = "-intel-axxia-${LINUX_KERNEL_TYPE}"

KMACHINE_axxiax86-64 = "intel-corei7-64"

# "simics" for simulation system or "frio" for FPGA emulation system
RUNTARGET ?= "simics"

SIMICS_PATCHES = " \
file://SIMICS-0001-mtd-spi-nor-intel-spi-Add-support-for-Intel-Cedar-Fo.patch \
file://SIMICS-0002-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
file://SIMICS-0003-mmc-sdhci-pci-Add-support-for-Intel-CDF.patch \
file://SIMICS-0004-x86-cpufeatures-Enumerate-cldemote-instruction.patch \
file://SIMICS-0005-x86-intel_rdt-Add-command-line-parameter-to-control-.patch \
file://SIMICS-0006-serial-8250_mid-Enable-HSU-on-Intel-Cedar-Fork-PCH.patch \
file://SIMICS-0007-drivers-tty-8250-use-setup_timer-helper.patch \
file://SIMICS-0008-serial-8250-Convert-timers-to-use-timer_setup.patch \
file://SIMICS-0009-serial-8250-fix-potential-deadlock-in-rs485-mode.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-acs-override.patch \
"

SRC_URI_append_axxiax86-64 = " \
	${@base_conditional('RUNTARGET', 'simics', '${SIMICS_PATCHES}', '', d)} \
	${@base_conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} \
	file://BOTH-001-PCI_INTERRUPT_PIN-Should-Always-Read-0.patch \
	file://${RUNTARGET}-runtarget.scc \
	file://common.scc \
	"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"

require linux-axxia.inc
