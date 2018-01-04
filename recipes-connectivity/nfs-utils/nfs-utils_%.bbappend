FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += "file://exports"

do_install_append () {
	install -m 0644 ${WORKDIR}/exports ${D}/${sysconfdir}/exports
}

FILES_${PN} += "${sysconfdir}/exports"
