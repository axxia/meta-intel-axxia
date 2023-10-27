FILESEXTRAPATHS:prepend := "\
:${THISDIR}/patches/${KERNEL_MAJOR_VERSION}\
:${THISDIR}/frags/${KERNEL_MAJOR_VERSION}:"

KERNEL_MAJOR_VERSION = "${@'.'.join(d.getVar('PV').split('.')[0:2])}"

KMACHINE:intel-axxia-snr = "intel-corei7-64"
KMACHINE:intel-axxia-grr = "intel-corei7-64"
KMACHINE:intel-axxia-pmr = "intel-corei7-64"
COMPATIBLE_MACHINE:intel-axxia-snr = "${MACHINE}"
COMPATIBLE_MACHINE:intel-axxia-grr = "${MACHINE}"
COMPATIBLE_MACHINE:intel-axxia-pmr = "${MACHINE}"

SRC_URI:append:intel-axxia-snr = " ${SNR_PATCHES}"
SRC_URI:append:intel-axxia-grr = " ${GRR_PATCHES}"
SRC_URI:append:intel-axxia-pmr = " ${PMR_PATCHES}"
SRC_URI:append = " file://common.scc"

# If this kernel package is not set as virtual/kernel provider,
# allow to be used as alternative kernel.
KERNEL_PACKAGE_NAME = "${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel', \
		       '${PN}', 'kernel', 'altkernel-${PN}', d)}"

# Alternative kernels should not provide virtual/kernel to be parsed and compiled
PROVIDES = "${@ "virtual/kernel" if (d.getVar("KERNEL_PACKAGE_NAME") == "kernel") else "" }"

do_configure:append() {
	if [ "${RELEASE_VERSION}" != "" ]; then
		sed -i s@UTS_VERSION=\"\#\$VERSION\"@UTS_VERSION=\"${RELEASE_VERSION}\ \#\$VERSION\"@g \
			${STAGING_KERNEL_DIR}/scripts/mkcompile_h
	fi
}

do_install:append() {
	depmod -a -b ${D} -F ${D}/boot/System.map-${KERNEL_VERSION} ${KERNEL_VERSION}
}

do_shared_workdir:append() {
	if [ "${KERNEL_PACKAGE_NAME}" != "kernel" ]; then
		# Expose kernel tree in work-shared if not preferred provider for virtual/kernel
		rm -f ${TMPDIR}/work-shared/${MACHINE}/kernel-*-${PN}
		ln -sf ${STAGING_KERNEL_DIR} ${TMPDIR}/work-shared/${MACHINE}/kernel-source-${PN}
		ln -sf ${STAGING_KERNEL_BUILDDIR} ${TMPDIR}/work-shared/${MACHINE}/kernel-build-artifacts-${PN}
	fi
}

kernel_do_deploy:append() {
	install -d ${DEPLOYDIR}
	install -m 0644 ${KBUILD_OUTPUT}/System.map \
		${DEPLOYDIR}/System-${PN}${KERNEL_ARTIFACT_NAME}.map
	if [ "${KERNEL_PACKAGE_NAME}" = "kernel" ]; then
		cd ${DEPLOYDIR}
		rm -f System.map
		ln -sf System-${PN}${KERNEL_ARTIFACT_NAME}.map System.map
	fi
}

KERNEL_MODULE_AUTOLOAD += "openvswitch kvm"
KERNEL_EXTRA_FEATURES = ""

FILES:${KERNEL_PACKAGE_NAME}-modules += "${nonarch_base_libdir}/modules/${KERNEL_VERSION}/modules.*"

# Clean alternative kernels if virtual/kernel's clean or cleansstate is run
ALTERNATIVE_KERNELS_CLEAN ??= ""
ALTERNATIVE_KERNELS_CLEANSSTATE ??= ""
do_clean[depends] += "${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel', '${PN}', \
		     '${ALTERNATIVE_KERNELS_CLEAN}', '', d)}"
do_cleansstate[depends] += "${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel', '${PN}', \
			   '${ALTERNATIVE_KERNELS_CLEANSSTATE}', '', d)}"
											   
# Compile tools needed by external modules each time kernel is clean
do_clean[depends] += "make-mod-scripts:do_cleansstate"
