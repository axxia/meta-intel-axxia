SUMMARY = "Simics Magic Pipe library (libmagicpipe)"
DESCRIPTION = "Simics Magic Pipe library (libmagicpipe)"

require simics.inc

do_install () {
	install -d ${D}${libdir}
	install -d ${D}${includedir}
	install -m 0644 ${S}/*.a   ${D}${libdir}
	install -m 0644 ${S}/*.h   ${D}${includedir}
}

ALLOW_EMPTY:${PN} = "1"

FILES:${PN}-dev = "${includedir}/*.h"

FILES:${PN}-staticdev = "${libdir}/*.a"

BBCLASSEXTEND = "native nativesdk"
