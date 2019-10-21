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
	file://${RUNTARGET}-runtarget.scc \
	file://common.scc \
	"

require recipes-kernel/linux/linux-yocto_virtualization.inc
SRC_URI_remove_axxiax86-64 = " file://lxc.scc file://docker.scc"

# If this kernel package is not set as virtual/kernel provider,
# allow to be used as alternative kernel.
KERNEL_PACKAGE_NAME = "${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel', \
		       '${PN}', 'kernel', 'kernel-${PN}', d)}"

do_configure_append() {
	sed -i s@UTS_VERSION=\"\#\$VERSION\"@UTS_VERSION=\"${RELEASE_VERSION}\ \#\$VERSION\"@g \
	       ${STAGING_KERNEL_DIR}/scripts/mkcompile_h
}

kernel_do_deploy_append() {
	install -d ${DEPLOYDIR}
	install -m 0644 ${KBUILD_OUTPUT}/System.map \
		${DEPLOYDIR}/System${KERNEL_ARTIFACT_NAME}.map
	cd ${DEPLOYDIR}
	rm -f System.map
	ln -sf System${KERNEL_ARTIFACT_NAME}.map System.map
}

KERNEL_EXTRA_FEATURES = ""
