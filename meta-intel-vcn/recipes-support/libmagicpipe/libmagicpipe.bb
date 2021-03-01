SUMMARY = "Simics Magic Pipe library (libmagicpipe)"
DESCRIPTION = "Simics Magic Pipe library (libmagicpipe)"

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-or-later;md5=fed54355545ffd980b814dab4a3b312c"

SIMICS_VERSION ?= "generic"
PV = "${SIMICS_VERSION}"

FILESEXTRAPATHS_prepend := "${THISDIR}/../../downloads:"

SRC_URI = "file://simics-${PV}.tgz"

S = "${WORKDIR}/simics-${PV}/src/misc/${PN}"

do_compile () {
	oe_runmake
}

do_install () {
	install -d ${D}${libdir}
	install -d ${D}${includedir}
	install -m 0644 ${S}/*.a   ${D}${libdir}
	install -m 0644 ${S}/*.h   ${D}${includedir}
}

ALLOW_EMPTY_${PN} = "1"

FILES_${PN}-dev = "${includedir}/*.h"

FILES_${PN}-staticdev = "${libdir}/*.a"

BBCLASSEXTEND = "native nativesdk"
