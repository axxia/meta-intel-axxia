FILESEXTRAPATHS_prepend := "\
:${THISDIR}/patches/${KERNEL_MAJOR_VERSION}\
:${THISDIR}/frags/${KERNEL_MAJOR_VERSION}:"

LINUX_VERSION_EXTENSION = "-intel-axxia-${LINUX_KERNEL_TYPE}"
KERNEL_MAJOR_VERSION = "${@'.'.join(d.getVar('PV').split('.')[0:2])}"

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
		${DEPLOYDIR}/System-${PN}${KERNEL_ARTIFACT_NAME}.map
	if [ "${KERNEL_PACKAGE_NAME}" = "kernel" ]; then
		cd ${DEPLOYDIR}
		rm -f System.map
		ln -sf System-${PN}${KERNEL_ARTIFACT_NAME}.map System.map
	else
		# Expose kernel tree in work-shared if not preferred provider for virtual/kernel
		rm -f ${TMPDIR}/work-shared/${MACHINE}/kernel-*-${PN}
		ln -sf ${STAGING_KERNEL_DIR} ${TMPDIR}/work-shared/${MACHINE}/kernel-source-${PN}
		ln -sf ${STAGING_KERNEL_BUILDDIR} ${TMPDIR}/work-shared/${MACHINE}/kernel-build-artifacts-${PN}
	fi
}

KERNEL_EXTRA_FEATURES = ""
