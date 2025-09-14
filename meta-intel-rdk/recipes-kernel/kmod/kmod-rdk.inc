FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " file://blacklist.conf.rdk"

do_install:append () {
	cat ${WORKDIR}/blacklist.conf.rdk >> ${D}${sysconfdir}/modprobe.d/blacklist.conf
}
