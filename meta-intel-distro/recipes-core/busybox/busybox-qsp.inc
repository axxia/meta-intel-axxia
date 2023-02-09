DEPENDS:append = " update-rc.d-native"

SRC_URI:append = " \
	file://qsp.cfg \
	file://udhcpd.conf  \
	file://testfile.txt \
	file://inetd.conf \
	"

INITSCRIPT_PARAMS:${PN}-udhcpd = "start 80 5 . stop 80 S ."
INITSCRIPT_NAME:inetd-${PN} = "inetd-busybox"
INITSCRIPT_PARAMS:inetd-${PN} = "start 80 5 . stop 80 S ."

do_install:append () {
	install -d ${D}${base_prefix}/tftpboot
	install -m 0644 ${WORKDIR}/testfile.txt ${D}/tftpboot/testfile.txt

	if grep -q "CONFIG_UDHCPD=y" ${B}/.config; then
		install -m 0755 ${WORKDIR}/busybox-udhcpd ${D}${sysconfdir}/init.d/busybox-udhcpd
		install -m 0644 ${WORKDIR}/udhcpd.conf ${D}${sysconfdir}/udhcpd.conf
		update-rc.d -r ${D} busybox-udhcpd start 85 2 3 4 5 .
	fi

	if grep -q "CONFIG_INETD=y" ${B}/.config; then
		update-rc.d -r ${D} inetd.busybox start 80 2 3 4 5 .
	fi
}

FILES:${PN} += "/tftpboot"
FILES:${PN}-udhcpd:remove = "${sysconfdir}/init.d/busybox-udhcpd"
