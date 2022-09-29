FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://persistent-net.rules"

do_install:append() {
	install -m 0666 ${WORKDIR}/persistent-net.rules ${D}${sysconfdir}/udev/rules.d/70-persistent-net.rules
	install -m 0666 ${WORKDIR}/persistent-net.rules ${D}${nonarch_base_libdir}/udev/rules.d/70-persistent-net.rules
}
