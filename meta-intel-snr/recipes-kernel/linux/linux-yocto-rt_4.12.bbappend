FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/conf/yocto-${KV}/${RUNTARGET}/${LINUX_KERNEL_TYPE}:"

KV = "4.12"
LINUX_VERSION_axxiax86-64 = "4.12.19"
KBRANCH_axxiax86-64 = "standard/preempt-rt/base"
KMACHINE_axxiax86-64 = "intel-corei7-64"
SRCREV_machine_axxiax86-64 = "03fdbd9f39161ac8dce16756b22f460252416f54"

SRCREV_meta_axxiax86-64 = "7986844d9de597218a23f82e68b01e5bf060d576"

# "simics" for simulation system or "frio" for FPGA emulation system
RUNTARGET ?= "simics"

SIMICS_PATCHES = " \
file://SIMICS-0001-intel_th-pci-Add-Cedar-Fork-PCH-support.patch \
file://SIMICS-0002-pinctrl-intel-Add-Intel-Denverton-pin-controller-sup.patch \
file://SIMICS-0003-i2c-i801-Add-support-for-Intel-Cedar-Fork.patch \
file://SIMICS-0004-pinctrl-intel-Make-offset-to-interrupt-status-regist.patch \
file://SIMICS-0005-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
"

SRC_URI_append_axxiax86-64 = " \
	${@base_conditional('RUNTARGET', 'simics', '${SIMICS_PATCHES}', '', d)} \
	file://defconfig \
	"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"
INSANE_SKIP_kernel-dev_axxiax86-64 = "debug-files"