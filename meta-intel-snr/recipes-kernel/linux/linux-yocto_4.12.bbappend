FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/conf/yocto-${KV}/${RUNTARGET}/${LINUX_KERNEL_TYPE}:"

KV = "4.12"
LINUX_VERSION_axxiax86-64 = "4.12.19"
KBRANCH_axxiax86-64 = "standard/axxia/base"
KMACHINE_axxiax86-64 = "intel-corei7-64"
SRCREV_machine = "4b7a5c1b4ec5536806942340755bcfbf6f3584d9"
SRCREV_meta = "7986844d9de597218a23f82e68b01e5bf060d576"

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
file://FRIO-0002-pci-driver-HACK-reassign-Altera-FPGAs-if-they-have-n.patch \
file://FRIO-0003-pci-driver-HACK-hardcode-size-of-bridge-window-to-NC.patch \
file://FRIO-0004-pci-driver-HACK-don-t-allocate-additional-bridge-win.patch \
file://FRIO-0005-pci-driver-HACK-merge-for-Altera.patch \
"

SRC_URI_append_axxiax86-64 = " \
	${@base_conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} \
	${@base_conditional('RUNTARGET', 'simics', '${SIMICS_PATCHES}', '', d)} \
	file://defconfig \
	"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"
INSANE_SKIP_kernel-dev_axxiax86-64 = "debug-files"