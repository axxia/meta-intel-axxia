FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/frags/${KV}:"

KV = "4.12"
LINUX_VERSION_axxiax86-64 = "4.12.26"
KBRANCH_axxiax86-64 = "standard/base"
KMACHINE_axxiax86-64 = "intel-corei7-64"
SRCREV_machine_axxiax86-64 = "bd8f931e213614bc5fdc6aeaa132d273caa002af"
SRCREV_meta_axxiax86-64 = "8359926e32b1f6a28734f4fc33f22c4beda8af38"

# "simics" for simulation system or "frio" for FPGA emulation system
RUNTARGET ?= "simics"

SIMICS_PATCHES = " \
file://SIMICS-0002-i2c-i801-Add-support-for-Intel-Cedar-Fork.patch \
file://SIMICS-0003-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
file://SIMICS-0004-mmc-sdhci-pci-Add-support-for-Intel-CDF.patch \
file://SIMICS-0005-intel_th-pci-Add-Cedar-Fork-PCH-support.patch \
file://SIMICS-0006-pinctrl-intel-Make-offset-to-interrupt-status-regist.patch \
file://SIMICS-0007-x86-cpufeatures-Enumerate-cldemote-instruction.patch \
file://SIMICS-0008-x86-intel_rdt-Add-command-line-parameter-to-control-.patch \
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
