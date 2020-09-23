SUMMARY = "Simics Magic Pipe library (libmagicpipe)"
DESCRIPTION = "Simics Magic Pipe library (libmagicpipe)"

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://Makefile;md5=1954481ecfe48bef2a1c90cc5930ec44"

SIMICS_VERSION ?= "6.0.51"
PV = "${SIMICS_VERSION}"

FILESEXTRAPATHS_prepend := "${THISDIR}/../../downloads:"

SRC_URI = "file://simics-${PV}.tgz"

SRC_URI[md5sum] = "c3b69ffff751fa6bdf258bd802c14ac3"
SRC_URI[sha256sum] = "8efbda455b18ffc420eb3ecaa45c3ed546937ee9345ae6c732b0faaae11b8a7a"

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
