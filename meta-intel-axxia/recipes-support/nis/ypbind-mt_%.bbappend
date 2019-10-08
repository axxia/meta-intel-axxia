FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

RDEPENDS_${PN}_append = " libnss-nis"

SRC_URI_append = " file://yp.conf"

do_install_append() {
	install -d ${D}${sysconfdir}
	install -m 0644 ${WORKDIR}/yp.conf ${D}${sysconfdir}/yp.conf

	# Fix the path of ypdomainname
	sed -i "s#^YPDOMAINNAME_bin=.*#YPDOMAINNAME_bin=/bin/ypdomainname#g" \
		${D}${sysconfdir}/init.d/ypbind
}
