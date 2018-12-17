FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/frags/${KV}:"

KV = "4.18"
LINUX_VERSION_axxiax86-64 = "4.18.21"
KBRANCH_axxiax86-64 = "v4.18/standard/base"
KMACHINE_axxiax86-64 = "intel-corei7-64"
SRCREV_machine_axxiax86-64 = "9eddc793f95f4e7e283996a007e205622c633539"
SRCREV_meta_axxiax86-64 = "8f4a98c93851f7f83d796aae2871df2798b8d917"

# "snr" for Victoria Canyon or ASE.  "frio" for FPGA emulation system
RUNTARGET ?= "snr"

SNR_PATCHES = " \
file://SNR-0001-pinctrl-cedarfork-Correct-EAST-pin-ordering.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-acs-override.patch \
"

SRC_URI_append_axxiax86-64 = " \
	${@oe.utils.conditional('RUNTARGET', 'snr', '${SNR_PATCHES}', '', d)} \
	${@oe.utils.conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} \
	file://BOTH-0001-vfio-pci-Mask-buggy-SR-IOV-VF-INTx-support.patch \
	file://BOTH-0002-iommu-vt-d-Handle-domain-agaw-being-less-than-iommu-.patch \
	file://${RUNTARGET}-runtarget.scc \
	file://common.scc \
	"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"

require linux-axxia.inc
