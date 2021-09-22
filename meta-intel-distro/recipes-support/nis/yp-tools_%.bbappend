FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " file://nisdomainname \
		   file://domainname.service"

do_install_append() {
	install -d ${D}${sysconfdir}
	install -m 0644 ${WORKDIR}/nisdomainname ${D}${sysconfdir}/nisdomainname
}
