SUMMARY = "Intel RDK userspace tools"
DESCRIPTION = "Intel RDK package containing all userspace (API and CLI) sources."
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-or-later;md5=fed54355545ffd980b814dab4a3b312c"

RDK_TOOLS_ARCHIVE ?= "file://rdk_user_src.tar.xz"

SRC_URI = "${RDK_TOOLS_ARCHIVE}"

FILESEXTRAPATHS_prepend := "${LAYER_PATH_meta-intel-rdk}/downloads:"

BB_STRICT_CHECKSUM_axxiax86-64 = "0"

RDK_TOOLS_VERSION ?= "unknown_release_info"
PR = "${RDK_TOOLS_VERSION}"

DEPENDS = "virtual/kernel libnl libpcap openssl rsync-native thrift meson-native \
	   ${@oe.utils.conditional('RDK_LTTNG_ENABLE', 'true', 'lttng-ust lttng-tools', '', d)}"

S = "${WORKDIR}/rdk"

inherit autotools

export SDKTARGETSYSROOT = "${STAGING_DIR_HOST}"
export OECORE_NATIVE_SYSROOT = "${STAGING_DIR_NATIVE}"

# Choose IES API mode of operation: "true" for SHM (shared-memory model)
# which is the default or "false" for RPC (remote procedure call)
export IES_ENABLE_SHM ??= "true"

# Choose whether to enable LTTng support for RDK (experimental)
export RDK_LTTNG_ENABLE ??= "false"

# Set LTTng instalation path (recipe sysroot)
export LTTNG_ROOT = "${STAGING_DIR_HOST}${prefix}"

# Add new include path for KLM headers exported for userspace
CXXFLAGS += " -I${SYSROOT}/usr/kernel-headers/include/klm "

do_configure_append () {
	# Use python3 since python2 is deprecated
	sed -i "s#\/usr\/bin\/env python#\/usr\/bin\/env python3#g" \
		${S}/user_modules/ies-api/tools/meson/*
}

do_compile () {
	cd ${S}
	oe_runmake cpk-ae-lib netd-lib qat_lib
	oe_runmake ies_api_install nura install

	# install netd headers from NETD_CLIENT_SRC/linux directory
	cp -r user_modules/netd/linux install/include
	
	oe_runmake cli 
}

do_install () {
	oe_runmake -C ${S} install

	install -d ${D}${bindir} ${D}${libdir}
	install -d ${D}${includedir} ${D}${sysconfdir}
	cp -r ${S}/install/bin/* ${D}${bindir}
	cp -r ${S}/install/lib/* ${D}${libdir}
	cp -r ${S}/install/include/* ${D}${includedir}
	cp -r ${S}/install/etc/* ${D}${sysconfdir}

	# replace local rpaths from .pc files to pass QA testing
	sed -i 's#prefix=.*#prefix=${prefix}#' \
		${D}${libdir}/pkgconfig/*.pc 2>/dev/null || :
}

FILES_${PN}-dev = " ${includedir} ${libdir}/libies*.so"

FILES_${PN} = " ${bindir} ${sysconfdir} ${libdir}"

INSANE_SKIP_${PN} = "already-stripped ldflags"

BBCLASSEXTEND = "native nativesdk"
