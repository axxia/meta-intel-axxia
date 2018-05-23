FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/frags/${KV}:"

require recipes-kernel/linux/linux-yocto.inc

KV = "4.12"
LINUX_VERSION_axxiax86-64 = "4.12.19"
LINUX_KERNEL_TYPE = "preempt-rt"
PV = "${LINUX_VERSION}+git${SRCPV}"

KBRANCH_axxiax86-64 = "standard/preempt-rt/base"
KMACHINE_axxiax86-64 = "intel-corei7-64"
SRCREV_machine_axxiax86-64 = "1b4229c4ef99843401ec2f522b63c9a64ed219a4"
SRCREV_meta_axxiax86-64 = "19d815d5a34bfaad95d87cc097cef18b594daac8"

# "simics" for simulation system or "frio" for FPGA emulation system
RUNTARGET ?= "simics"

SIMICS_PATCHES = " \
file://SIMICS-0001-intel_th-pci-Add-Cedar-Fork-PCH-support.patch \
file://SIMICS-0002-pinctrl-intel-Add-Intel-Denverton-pin-controller-sup.patch \
file://SIMICS-0003-i2c-i801-Add-support-for-Intel-Cedar-Fork.patch \
file://SIMICS-0004-pinctrl-intel-Make-offset-to-interrupt-status-regist.patch \
file://SIMICS-0005-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
file://SIMICS-0006-pinctrl-cedarfork-Correct-EAST-pin-ordering.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-acs-override.patch \
"

KREPO_KERNEL = "git://git@github.com/axxia/axxia_yocto_linux_4.12_private.git;protocol=ssh"
SRC_URI_axxiax86-64 = " \
	${KREPO_KERNEL};name=machine;branch=${KBRANCH} \
	git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=yocto-4.12;destsuffix=${KMETA} \
	${@base_conditional('RUNTARGET', 'simics', '${SIMICS_PATCHES}', '', d)} \
	${@base_conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} \
	file://${RUNTARGET}-runtarget.scc \
	file://common.scc \
	"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"
