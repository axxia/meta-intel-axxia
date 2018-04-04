FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += "file://yp.conf"

do_install_append() {
	install -d ${D}${sysconfdir}
	install -m 0644 ${WORKDIR}/yp.conf ${D}${sysconfdir}/yp.conf
}
