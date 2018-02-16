FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/conf/axxia-${KV}/${RUNTARGET}/${LINUX_KERNEL_TYPE}:"

require recipes-kernel/linux/linux-yocto.inc

KV = "4.12"
LINUX_VERSION_axxiax86-64 = "4.12.19"
LINUX_KERNEL_TYPE = "preempt-rt"
PV = "${LINUX_VERSION}+git${SRCPV}"

KBRANCH_axxiax86-64 = "standard/preempt-rt/base"
SRCREV_machine_axxiax86-64 = "1b4229c4ef99843401ec2f522b63c9a64ed219a4"

KMETA_axxiax86-64 = ""

# "simics" for simulation system or "frio" for FPGA emulation system
RUNTARGET ?= "simics"

SIMICS_PATCHES = " \
file://SIMICS-0001-intel_th-pci-Add-Cedar-Fork-PCH-support.patch \
file://SIMICS-0002-pinctrl-intel-Add-Intel-Denverton-pin-controller-sup.patch \
file://SIMICS-0003-i2c-i801-Add-support-for-Intel-Cedar-Fork.patch \
file://SIMICS-0004-pinctrl-intel-Make-offset-to-interrupt-status-regist.patch \
file://SIMICS-0005-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
"

KREPO_KERNEL = "git://git@github.com/axxia/axxia_yocto_linux_4.12_private.git;protocol=ssh"
SRC_URI_axxiax86-64 = "${KREPO_KERNEL};name=machine;branch=${KBRANCH} \
	${@base_conditional('RUNTARGET', 'simics', '${SIMICS_PATCHES}', '', d)} \
	file://defconfig \
	"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"
INSANE_SKIP_kernel-dev_axxiax86-64 = "debug-files"

KERNEL_EXTRA_FEATURES_axxiax86-64 = ""
