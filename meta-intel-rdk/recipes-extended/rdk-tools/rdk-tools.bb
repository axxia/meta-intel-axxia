SUMMARY = "Intel RDK userspace tools"
DESCRIPTION = "Intel RDK package containing all userspace (API and CLI) sources."
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-or-later;md5=fed54355545ffd980b814dab4a3b312c"

USE_RDK_REPO ?= "false"
RDK_REPO ?= ""
RDK_REPO_REV ?= ""
RDK_REPO_SRC_URI ?= "git://${@d.getVar('RDK_REPO').replace('https://','')};protocol=https;nobranch=1"
SRCREV = "${RDK_REPO_REV}"

FILESEXTRAPATHS_prepend := "${LAYER_PATH_meta-intel-rdk}/downloads:"
RDK_TOOLS_ARCHIVE ?= "file://rdk_user_src.tar.xz"
BB_STRICT_CHECKSUM = "0"

SRC_URI = "${@oe.utils.conditional('USE_RDK_REPO', 'false', '${RDK_TOOLS_ARCHIVE}', '${RDK_REPO_SRC_URI}', d)}"

RDK_TOOLS_VERSION ?= "${@oe.utils.conditional('USE_RDK_REPO', 'false', \
	'unknown_release_info', 'git_${RDK_REPO_REV}', d)}"
PR = "${RDK_TOOLS_VERSION}"

DEPENDS = "virtual/kernel libnl libpcap openssl rsync-native thrift meson-native \
	   ${@oe.utils.conditional('RDK_LTTNG_ENABLE', 'true', 'lttng-ust lttng-tools', '', d)}"

RDEPENDS_${PN} += "${@oe.utils.conditional('RDK_LTTNG_ENABLE', 'true', 'lttng-ust lttng-tools', '', d)}"

S = "${@oe.utils.conditional('USE_RDK_REPO', 'false', "${WORKDIR}/rdk", "${WORKDIR}/git/rdk", d)}"

inherit autotools

export SDKTARGETSYSROOT = "${STAGING_DIR_HOST}"
export OECORE_NATIVE_SYSROOT = "${STAGING_DIR_NATIVE}"

# Choose IES API mode of operation: "true" for SHM (shared-memory model)
# which is the default or "false" for RPC (remote procedure call)
export IES_ENABLE_SHM ??= "true"

# Choose whether to enable LTTng support for RDK (experimental)
export RDK_LTTNG_ENABLE ??= "true"
export LTTNG_ROOT = "${STAGING_DIR_HOST}${prefix}"

# Extra flags required by ies_api_install target for autotools build
IES_EXTRA_FLAGS = "host_alias=${HOST_SYS}"

# Don't remove libtool *.la files
REMOVE_LIBTOOL_LA = "0"

# Add new include path for KLM headers exported for userspace
CXXFLAGS += " -I${SYSROOT}/usr/kernel-headers/include/klm "

do_compile () {
	cd ${S}
	oe_runmake cpk-ae-lib netd-lib
	oe_runmake ${IES_EXTRA_FLAGS} ies_api_install
	oe_runmake -j1 qat_lib nura
	oe_runmake install cli
}

do_install () {
	oe_runmake -C ${S} install

	install -d ${D}${bindir} ${D}${libdir}
	install -d ${D}${includedir} ${D}${sysconfdir}
	cp -r ${S}/install/bin/* ${D}${bindir}
	cp -r ${S}/install/lib/* ${D}${libdir}
	cp -r ${S}/install/include/* ${D}${includedir}
	cp -r ${S}/install/etc/* ${D}${sysconfdir}
	
	if [ -d ${S}/install/lib/firmware/intel ]; then
		install -d ${D}${nonarch_base_libdir}/firmware/intel
		cp -r ${S}/install/lib/firmware/intel/* \
		${D}${nonarch_base_libdir}/firmware/intel 2>/dev/null || :
	fi

	# fix symlinks removed on install by "rsync -L --no-l"
	cp -r ${S}/user_modules/ies-api/lib/* ${D}${libdir} 2>/dev/null || :

	# replace local rpaths from libtool files to pass QA testing
	sed -i "s#libdir=.*#libdir='${libdir}'#g" \
		${D}${libdir}/*.la 2>/dev/null || :

	# remove local rpath from binaries to pass QA testing
	for file in ${D}${libdir}/*.so* ${D}${bindir}/*; do
		chrpath -d $file 2>/dev/null || :
	done

	# replace local rpaths from .pc files to pass QA testing
	sed -i 's#prefix=.*#prefix=${prefix}#' \
		${D}${libdir}/pkgconfig/*.pc 2>/dev/null || :
}

PACKAGES += "rdk-firmware"

FILES_rdk-firmware = " ${nonarch_base_libdir}/firmware"
ALLOW_EMPTY_rdk-firmware = "1"

FILES_${PN}-dev = " ${includedir} \
	${libdir}/libies*.so \
	${libdir}/*.la"

FILES_${PN} = " ${bindir} ${sysconfdir} ${libdir}"

INSANE_SKIP_${PN} = "already-stripped ldflags dev-deps"

BBCLASSEXTEND = "native nativesdk"
