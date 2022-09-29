FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://nisdomainname \
		   file://domainname.service"

do_install:append() {
	install -d ${D}${sysconfdir}
	install -m 0644 ${WORKDIR}/nisdomainname ${D}${sysconfdir}/nisdomainname
}
