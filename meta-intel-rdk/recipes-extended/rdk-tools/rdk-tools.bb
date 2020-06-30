SUMMARY = "Intel RDK userspace tools"
DESCRIPTION = "Intel RDK package containing all userspace (API and CLI) sources."
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

RDK_TOOLS_ARCHIVE ?= "file://rdk_user_src.tar.xz"

SRC_URI = "${RDK_TOOLS_ARCHIVE}"

FILESEXTRAPATHS_prepend := "${LAYER_PATH_meta-intel-rdk}/downloads:"

BB_STRICT_CHECKSUM_axxiax86-64 = "0"

RDK_TOOLS_VERSION ?= "unknown_release_info"
PR = "${RDK_TOOLS_VERSION}"

DEPENDS = "virtual/kernel libnl libpcap openssl rsync-native thrift"

inherit autotools

export SDKTARGETSYSROOT = "${STAGING_DIR_HOST}"

export LIB_CPKAE_DIR = "${WORKDIR}/rdk/user_modules/cpk-ae-lib"

export QAT_DIR = "${WORKDIR}/rdk/user_modules/qat"
export LIB_QAT18_DIR = "${QAT_DIR}"

export IES_API_DIR = "${WORKDIR}/rdk/user_modules/ies-api"
export IES_API_BUILD_DIR = "${IES_API_DIR}"
export IES_API_OUTPUT_DIR = "${IES_API_DIR}"
export IES_API_CORE_DIR = "user_modules/ies-api/core"
export OPENSSL_ROOT = "${STAGING_DIR_HOST}/usr"

export NURA_DIR = "${WORKDIR}/rdk/nvm_ura"

# Choose IES API mode of operation: "true" for SHM (shared-memory model)
# which is the default or "false" for RPC (remote procedure call)
export IES_ENABLE_SHM ??= "true"

# Choose whether to enable LTTng support for RDK (experimental)
export RDK_LTTNG_ENABLE ??= "false"

# Extra flags required by ies_api_install target from the main Makefile
IES_EXTRA_FLAGS = "host_alias=${HOST_SYS}"

# Overwrite IES_API_CFLAGS to unset global FORTIFY_SOURCE flag
export IES_API_CFLAGS = "-g -Wno-unused-result -U_FORTIFY_SOURCE \
			 -D_FORTIFY_SOURCE=0 -Wno-address-of-packed-member"

# qat_lib and nura targets doesn't support random ordering of some operations,
# thus force them to build single-threaded
NO_PARALLEL = "-j1"

# Don't remove libtool *.la files
REMOVE_LIBTOOL_LA = "0"

# Add new include path for KLM headers exported for userspace
CXXFLAGS += " -I${SYSROOT}/usr/kernel-headers/include/klm "

do_compile () {
	cd ${WORKDIR}/rdk
	oe_runmake cpk-ae-lib netd-lib
	oe_runmake ${NO_PARALLEL} qat_lib
	oe_runmake ${IES_EXTRA_FLAGS} ies_api_install
	oe_runmake cli
	oe_runmake ${NO_PARALLEL} nura
}

do_install () {
	oe_runmake -C ${WORKDIR}/rdk install

	install -d ${D}${bindir} ${D}${libdir}
	install -d ${D}${includedir} ${D}${sysconfdir}
	cp -r ${WORKDIR}/rdk/install/bin/* ${D}${bindir}
	cp -r ${WORKDIR}/rdk/install/lib/* ${D}${libdir}
	cp -r ${WORKDIR}/rdk/install/include/* ${D}${includedir}
	cp -r ${WORKDIR}/rdk/install/etc/* ${D}${sysconfdir}

	# fix symlinks removed on install by "rsync -L --no-l"
	cp -r ${IES_API_DIR}/lib/* ${D}${libdir}

	# replace local rpaths from libtool files to pass QA testing
	sed -i "s#${IES_API_DIR}/lib#${libdir}#g" ${D}${libdir}/*.la

	# remove local rpath from binaries to pass QA testing
	for file in ${D}${libdir}/*.so* ${D}${bindir}/*; do
		chrpath -d $file 2>/dev/null || :
	done

	# replace local rpaths from .pc files to pass QA testing
	if [ -f ${D}${libdir}/pkgconfig/iesclient.pc ]; then
		sed -i "s#${IES_API_DIR}#${prefix}#g" \
		${D}${libdir}/pkgconfig/iesclient.pc
	fi
}

FILES_${PN}-dev = " ${includedir} \
	${libdir}/libies*.so \
	${libdir}/*.la"

FILES_${PN} = " ${bindir} ${sysconfdir} ${libdir}"

INSANE_SKIP_${PN} = "ldflags"
INSANE_SKIP_${PN}-dev = "ldflags"

BBCLASSEXTEND = "native nativesdk"
