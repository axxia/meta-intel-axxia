FILESEXTRAPATHS_prepend := "\
${THISDIR}\
:${THISDIR}/patches/${KV}\
:${THISDIR}/conf/yocto-${KV}/${MACHINE}/common\
:${THISDIR}/conf/yocto-${KV}/${MACHINE}/${LINUX_KERNEL_TYPE}\
:${THISDIR}/conf/yocto-${KV}/${MACHINE}/${RUNTARGET}/${LINUX_KERNEL_TYPE}:"

require recipes-kernel/linux/linux-yocto.inc

inherit axxia-kernel

KV = "4.9"
LINUX_VERSION = "4.9.71"
LINUX_KERNEL_TYPE = "standard"
PV = "${LINUX_VERSION}+git${SRCPV}"

KBRANCH = "standard/axxia/base"
KMETA = "kernel-meta"
SRCREV_machine = "95fe699e8a23c05858255c17b92816b67c37b5ce"
SRCREV_meta = "4540e14cdccbb8bf8db591fd60fb03342f155342"

# skip yocto-kernel-cache for axxiax86_64 to use full defconfig untill we'll have fragments upstream
KMETA_SOURCES = "git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=yocto-4.9;destsuffix=${KMETA}"

# "simics" for simulation system or "frio" for FPGA emulation system
RUNTARGET ?= "simics"

SIMICS_PATCHES = " \
file://SIMICS-0001-intel_th-pci-Add-Cedar-Fork-PCH-support.patch \
file://SIMICS-0002-spi-nor-Add-support-for-Intel-SPI-serial-flash-contr.patch \
file://SIMICS-0003-pinctrl-intel-set-default-handler-to-be-handle_bad_i.patch \
file://SIMICS-0004-pinctrl-intel-Convert-to-use-devm_gpiochip_add_data.patch \
file://SIMICS-0005-pinctrl-intel-Add-support-for-hardware-debouncer.patch \
file://SIMICS-0006-pinctrl-intel-Add-support-for-1k-additional-pull-dow.patch \
file://SIMICS-0007-pinctrl-intel-unlock-on-error-in-intel_config_set_pu.patch \
file://SIMICS-0008-pinctrl-intel-Add-support-for-variable-size-pad-grou.patch \
file://SIMICS-0009-pinctrl-intel-Make-it-possible-to-specify-mode-per-p.patch \
file://SIMICS-0010-mtd-spi-nor-intel-spi-Add-support-for-Intel-Denverto.patch \
file://SIMICS-0011-pinctrl-intel-Add-Intel-Denverton-pin-controller-sup.patch \
file://SIMICS-0012-i2c-i801-Add-support-for-Intel-Cedar-Fork.patch \
file://SIMICS-0013-pinctrl-intel-Make-offset-to-interrupt-status-regist.patch \
file://SIMICS-0014-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
file://SIMICS-0015-mtd-spi-nor-intel-spi-Add-support-for-Intel-Cedar-Fo.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-pci-driver-HACK-reassign-Altera-FPGAs-if-they-have-n.patch \
file://FRIO-0003-pci-driver-HACK-hardcode-size-of-bridge-window-to-NC.patch \
file://FRIO-0004-pci-driver-HACK-don-t-allocate-additional-bridge-win.patch \
file://FRIO-0005-pci-driver-HACK-merge-for-Altera.patch \
"

SRC_URI = "git://git.yoctoproject.org/linux-yocto-4.9.git;name=machine;branch=${KBRANCH}; \
           ${@base_conditional('MACHINE', 'axxiax86-64', '', '${KMETA_SOURCES}', d)} \
           ${@base_conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} \
           ${@base_conditional('RUNTARGET', 'simics', '${SIMICS_PATCHES}', '', d)} \
           file://fit \
"

require dt/dt-${KARCH}.inc
require frags/frags-${KARCH}.inc

# use full defconfig for axxiax86_64 untill we'll have fragments upstream
SRC_URI += "${@base_conditional('MACHINE', 'axxiax86-64', 'file://defconfig', '', d)}"

COMPATIBLE_MACHINE = "^axxiaarm$|^axxiaarm64$|^axxiax86-64$"
INSANE_SKIP_kernel-dev = "debug-files"

SMP ?= "yes"
POWER_MANAGEMENT ?= "low-power"
CHIPSET ?= "5500"
BIG_ENDIAN ?= "no"
DBG ?= "no"
TESTING ?= "no"
KERNEL_EXTRA_FEATURES = ""
