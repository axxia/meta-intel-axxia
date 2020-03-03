KERNEL = "${@d.getVar('ALTERNATIVE_KERNELS')[1:].split(' ')[${ALTERNATIVE_KERNEL_NUMBER}]}"

BPN = "lttng-modules"
PN = "lttng-modules-${KERNEL}"

FILESEXTRAPATHS_prepend := "${COREBASE}/meta/recipes-kernel/lttng/${BPN}:"

DEPENDS += "${KERNEL} make-mod-scripts"

KERNEL_PATH = "${TMPDIR}/work-shared/${MACHINE}/kernel-source-${KERNEL}"
KERNEL_OUTPUT = "${TMPDIR}/work-shared/${MACHINE}/kernel-build-artifacts-${KERNEL}"

export KERNEL_VERSION = "${@oe.utils.read_file('${KERNEL_OUTPUT}/kernel-${KERNEL}-abiversion')}"
export KBUILD_OUTPUT = "${KERNEL_OUTPUT}"

EXTRA_OEMAKE = "KERNEL_SRC=${KERNEL_PATH} KERNELDIR='${KERNEL_PATH}'"

module_do_compile() {
	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
	oe_runmake KERNEL_PATH="${KERNEL_PATH}" \
		KERNEL_VERSION="${KERNEL_VERSION}" \
		CC="${KERNEL_CC}" LD="${KERNEL_LD}" \
		AR="${KERNEL_AR}" \
		O="${KERNEL_OUTPUT}" \
		KBUILD_EXTRA_SYMBOLS="${KBUILD_EXTRA_SYMBOLS}" \
		${MAKE_TARGETS}
}

module_do_install() {
	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
	oe_runmake DEPMOD=echo MODLIB="${D}${nonarch_base_libdir}/modules/${KERNEL_VERSION}" \
	           CC="${KERNEL_CC}" LD="${KERNEL_LD}" \
	           O=${KERNEL_OUTPUT} \
	           ${MODULES_INSTALL_TARGET}

	if [ ! -e "${B}/${MODULES_MODULE_SYMVERS_LOCATION}/Module.symvers" ] ; then
		bbwarn "Module.symvers not found in ${B}/${MODULES_MODULE_SYMVERS_LOCATION}"
		bbwarn "Please consider setting MODULES_MODULE_SYMVERS_LOCATION to a"
		bbwarn "directory below B to get correct inter-module dependencies"
	else
		install -Dm0644 "${B}/${MODULES_MODULE_SYMVERS_LOCATION}"/Module.symvers ${D}${includedir}/${PN}/Module.symvers
		# Module.symvers contains absolute path to the build directory.
		# While it doesn't actually seem to matter which path is specified,
		# clear them out to avoid confusion
		sed -e 's:${B}/::g' -i ${D}${includedir}/${PN}/Module.symvers
	fi
}

do_package[postfuncs] += "fix_alternative_rdepends"
fix_alternative_rdepends () {
	# For lttng-modules built for alternative kernels, some sub-packages have on runtime depends
	# sub-packages from the main kernel. Replace them with alternative kernels sub-packages.
	if [ "${KERNEL_PACKAGE_NAME}" != "kernel" ]; then
		sed -i "s/kernel-${KERNEL_VERSION}/kernel-${KERNEL}-${KERNEL_VERSION}/g" \
			${PKGDESTWORK}/runtime/*
		sed -i "s/kernel-module-kvm-${KERNEL_VERSION}/kernel-${KERNEL}-module-kvm-${KERNEL_VERSION}/g" \
			${PKGDESTWORK}/runtime/*
	fi
}
