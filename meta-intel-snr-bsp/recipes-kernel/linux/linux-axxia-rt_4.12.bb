FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/conf/axxia-${KV}/${RUNTARGET}/${LINUX_KERNEL_TYPE}:"

require recipes-kernel/linux/linux-yocto.inc

KV = "4.12"
LINUX_VERSION = "4.12.18"
LINUX_KERNEL_TYPE = "preempt-rt"
PV = "${LINUX_VERSION}+git${SRCPV}"

KBRANCH_axxiax86-64 = "standard/preempt-rt/axxia/base"
SRCREV_machine = "${AUTOREV}"
KMETA_axxiax86-64 = ""

# "simics" for simulation system or "frio" for FPGA emulation system
RUNTARGET ?= "simics"

SIMICS_PATCHES = " \
file://SIMICS-0001-intel_th-pci-Add-Cedar-Fork-PCH-support.patch \
file://SIMICS-0002-pinctrl-intel-Add-support-for-variable-size-pad-grou.patch \
file://SIMICS-0003-pinctrl-intel-Make-it-possible-to-specify-mode-per-p.patch \
file://SIMICS-0004-pinctrl-intel-Add-Intel-Denverton-pin-controller-sup.patch \
file://SIMICS-0005-i2c-i801-Add-support-for-Intel-Cedar-Fork.patch \
file://SIMICS-0006-pinctrl-intel-Make-offset-to-interrupt-status-regist.patch \
file://SIMICS-0007-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-pci-driver-HACK-reassign-Altera-FPGAs-if-they-have-n.patch \
file://FRIO-0003-pci-driver-HACK-hardcode-size-of-bridge-window-to-NC.patch \
file://FRIO-0004-pci-driver-HACK-don-t-allocate-additional-bridge-win.patch \
file://FRIO-0005-pci-driver-HACK-merge-for-Altera.patch \
"

KREPO_KERNEL = "git://git@github.com/axxia/axxia_yocto_linux_4.12_private.git;protocol=ssh"
SRC_URI_axxiax86-64 = "${KREPO_KERNEL};name=machine;branch=${KBRANCH} \
           ${@base_conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} \
           ${@base_conditional('RUNTARGET', 'simics', '${SIMICS_PATCHES}', '', d)} \
           file://defconfig \
"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"
INSANE_SKIP_kernel-dev = "debug-files"

KERNEL_EXTRA_FEATURES_axxiax86-64 = ""
