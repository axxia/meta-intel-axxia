FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/frags/${KV}:"

KV = "4.12"
LINUX_VERSION_axxiax86-64 = "4.12.21"
KBRANCH_axxiax86-64 = "standard/preempt-rt/base"
KMACHINE_axxiax86-64 = "intel-corei7-64"
SRCREV_machine_axxiax86-64 = "00367470471fd119fcd9a9d41789e19cb2824a0d"
SRCREV_meta_axxiax86-64 = "19d815d5a34bfaad95d87cc097cef18b594daac8"

# "simics" for simulation system or "frio" for FPGA emulation system
RUNTARGET ?= "simics"

SIMICS_PATCHES = " \
file://SIMICS-0001-intel_th-pci-Add-Cedar-Fork-PCH-support.patch \
file://SIMICS-0002-pinctrl-intel-Add-Intel-Denverton-pin-controller-sup.patch \
file://SIMICS-0003-i2c-i801-Add-support-for-Intel-Cedar-Fork.patch \
file://SIMICS-0004-pinctrl-intel-Make-offset-to-interrupt-status-regist.patch \
file://SIMICS-0005-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
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