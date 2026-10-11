FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " file://blacklist.conf.rdk"

do_install:append () {
	install -m 0644 ${UNPACKDIR}/blacklist.conf.rdk ${D}${sysconfdir}/modprobe.d/blacklist-rdk.conf
}
