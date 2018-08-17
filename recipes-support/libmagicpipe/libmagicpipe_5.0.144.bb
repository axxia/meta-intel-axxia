SUMMARY = "Simics Magic Pipe library (libmagicpipe)"
DESCRIPTION = "Simics Magic Pipe library (libmagicpipe)"

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://Makefile;md5=fec19790807db68af67649564324cff0"

FILESEXTRAPATHS_prepend := "${THISDIR}/../../downloads:"

SRC_URI = "file://simics-${PV}.tgz"

SRC_URI[md5sum] = "66cb0a61098fa23c3bc2d6b7ebc7ea98"
SRC_URI[sha256sum] = "6f4a214d1611ccdc7df002d33a2287a96ffc2db0c0026c4a9eca06316fbcb28d"

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
