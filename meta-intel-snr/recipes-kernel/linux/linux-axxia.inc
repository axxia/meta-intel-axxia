FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KV}\
:${THISDIR}/frags/${KV}:"

LINUX_VERSION_EXTENSION = "-intel-axxia-${LINUX_KERNEL_TYPE}"

KMACHINE_axxiax86-64 = "intel-corei7-64"
COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"

# "snr" for Victoria Canyon or ASE.  "frio" for FPGA emulation system
RUNTARGET ?= "snr"

SRC_URI_append_axxiax86-64 = " \
	${@oe.utils.conditional('RUNTARGET', 'snr', '${SNR_PATCHES}', '', d)} \
	${@oe.utils.conditional('RUNTARGET', 'frio', '${FRIO_PATCHES}', '', d)} \
	file://BOTH-0001-vfio-pci-Mask-buggy-SR-IOV-VF-INTx-support.patch \
	file://BOTH-0002-iommu-vt-d-Handle-domain-agaw-being-less-than-iommu-.patch \
	file://${RUNTARGET}-runtarget.scc \
	file://common.scc \
	"

require recipes-kernel/linux/linux-yocto_virtualization.inc

kernel_do_deploy_append() {
	install -d ${DEPLOYDIR}
	install -m 0644 ${KBUILD_OUTPUT}/System.map \
		${DEPLOYDIR}/System${KERNEL_IMAGE_BASE_NAME}.map
	cd ${DEPLOYDIR}
	rm -f System.map
	ln -sf System${KERNEL_IMAGE_BASE_NAME}.map System.map
}
