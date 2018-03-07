FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/frags/${KV}:"

KV = "4.9"
LINUX_VERSION_axxiax86-64 = "4.9.78"
KBRANCH_axxiax86-64 = "standard/preempt-rt/base"
KMACHINE_axxiax86-64 = "intel-corei7-64"
SRCREV_machine_axxiax86-64 = "a00bc26b1d4fa49b71dc8f9de046534d4a330647"
SRCREV_meta_axxiax86-64 = "688a904c38ecfdc36c23eafc8e93aadc2c537535"

# "simics" for simulation system or "frio" for FPGA emulation system
RUNTARGET ?= "simics"

SIMICS_PATCHES = " \
file://SIMICS-0001-intel_th-pci-Add-Cedar-Fork-PCH-support.patch \
file://SIMICS-0002-spi-nor-Add-support-for-Intel-SPI-serial-flash-contr.patch \
file://SIMICS-0003-pinctrl-intel-set-default-handler-to-be-handle_bad_i.patch \
file://SIMICS-0004-pinctrl-baytrail-Do-not-add-all-GPIOs-to-IRQ-domain.patch \
file://SIMICS-0005-pinctrl-intel-Convert-to-use-devm_gpiochip_add_data.patch \
file://SIMICS-0006-pinctrl-intel-Add-support-for-hardware-debouncer.patch \
file://SIMICS-0007-pinctrl-intel-Add-support-for-1k-additional-pull-dow.patch \
file://SIMICS-0008-pinctrl-intel-unlock-on-error-in-intel_config_set_pu.patch \
file://SIMICS-0009-pinctrl-intel-Add-support-for-variable-size-pad-grou.patch \
file://SIMICS-0010-pinctrl-intel-Make-it-possible-to-specify-mode-per-p.patch \
file://SIMICS-0011-mtd-spi-nor-intel-spi-Add-support-for-Intel-Denverto.patch \
file://SIMICS-0012-pinctrl-intel-Add-Intel-Denverton-pin-controller-sup.patch \
file://SIMICS-0013-i2c-i801-Add-support-for-Intel-Cedar-Fork.patch \
file://SIMICS-0014-pinctrl-intel-Make-offset-to-interrupt-status-regist.patch \
file://SIMICS-0015-pinctrl-intel-Add-Intel-Cedar-Fork-PCH-pin-controlle.patch \
file://SIMICS-0016-mtd-spi-nor-intel-spi-Add-support-for-Intel-Cedar-Fo.patch \
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