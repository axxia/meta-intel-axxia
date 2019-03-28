FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " file://yp.conf"

do_install_append() {
	install -d ${D}${sysconfdir}
	install -m 0644 ${WORKDIR}/yp.conf ${D}${sysconfdir}/yp.conf
}
