FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

RDEPENDS:${PN}:append = " libnss-nis"

SRC_URI:append = " file://yp.conf"

do_install:append() {
	install -d ${D}${sysconfdir}
	install -m 0644 ${WORKDIR}/yp.conf ${D}${sysconfdir}/yp.conf

	# Fix the path of ypdomainname
	sed -i "s#^YPDOMAINNAME_bin=.*#YPDOMAINNAME_bin=/bin/ypdomainname#g" \
		${D}${sysconfdir}/init.d/ypbind
}
