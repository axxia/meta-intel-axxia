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
file://FRIO-0002-drivers-pci-acs-override.patch \
"

SRC_URI_append_axxiax86-64 = " \
	${@base_conditional('RUNTARGET', 'simics', '${SIMICS_PATCHES}', '', d)} \
	${@base_conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} \
	file://${RUNTARGET}-runtarget.scc \
	file://common.scc \
	"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"
