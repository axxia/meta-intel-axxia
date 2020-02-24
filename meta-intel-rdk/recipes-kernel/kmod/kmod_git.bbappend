FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append_axxiax86-64 = " file://blacklist.conf"

do_install_append () {
	install -m 644 ${WORKDIR}/blacklist.conf ${D}${sysconfdir}/modprobe.d/blacklist.conf
}
