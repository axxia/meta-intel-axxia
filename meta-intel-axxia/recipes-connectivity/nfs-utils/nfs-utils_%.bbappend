FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " file://exports"

do_install_append () {
	install -m 0644 ${WORKDIR}/exports ${D}/${sysconfdir}/exports
}

FILES_${PN}_append = " ${sysconfdir}/exports"
