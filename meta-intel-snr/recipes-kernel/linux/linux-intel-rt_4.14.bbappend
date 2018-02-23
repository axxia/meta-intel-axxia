FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/frags/${KV}:"

KV = "4.14"
LINUX_VERSION_EXTENSION = "-intel-axxia-${LINUX_KERNEL_TYPE}"

KMACHINE_axxiax86-64 = "intel-corei7-64"

# "simics" for simulation system or "frio" for FPGA emulation system
RUNTARGET ?= "simics"

SIMICS_PATCHES = " \
file://SIMICS-0001-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-pci-driver-HACK-reassign-Altera-FPGAs-if-they-have-n.patch \
file://FRIO-0003-pci-driver-HACK-hardcode-size-of-bridge-window-to-NC.patch \
file://FRIO-0004-pci-driver-HACK-don-t-allocate-additional-bridge-win.patch \
file://FRIO-0005-pci-driver-HACK-merge-for-Altera.patch \
"

SRC_URI_append_axxiax86-64 = " \
	${@base_conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} \
	${@base_conditional('RUNTARGET', 'simics', '${SIMICS_PATCHES}', '', d)} \
	file://${RUNTARGET}-runtarget.scc \
	file://common.scc \
	"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"
