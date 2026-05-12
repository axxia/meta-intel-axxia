FILESEXTRAPATHS:prepend := "${THISDIR}/systemd:"

SRC_URI:append = " file://10-eth.link \
	file://20-nac.link \
	file://21-nac.link \
	file://22-nac.link \
	file://23-nac.link \
	file://24-nac.link \
	file://25-nac.link \
	file://26-nac.link \
	file://27-nac.link \
	file://28-nac.link \
	file://29-nac.link \
	file://30-nac.link \
	file://31-nac.link \
	file://32-nac.link \
	file://33-nac.link \
	file://34-nac.link \
	file://35-nac.link \
	file://36-nac.link \
	file://37-nac.link \
	file://38-nac.link \
	file://39-nac.link \
	file://99-default.link"

do_install:append() {
	install -d ${D}${sysconfdir}
	install -m 0644 ${UNPACKDIR}/10-eth.link ${D}${sysconfdir}/systemd/network/10-eth.link
	install -m 0644 ${UNPACKDIR}/20-nac.link ${D}${sysconfdir}/systemd/network/20-nac.link
	install -m 0644 ${UNPACKDIR}/21-nac.link ${D}${sysconfdir}/systemd/network/21-nac.link
	install -m 0644 ${UNPACKDIR}/22-nac.link ${D}${sysconfdir}/systemd/network/22-nac.link
	install -m 0644 ${UNPACKDIR}/23-nac.link ${D}${sysconfdir}/systemd/network/23-nac.link
	install -m 0644 ${UNPACKDIR}/24-nac.link ${D}${sysconfdir}/systemd/network/24-nac.link
	install -m 0644 ${UNPACKDIR}/25-nac.link ${D}${sysconfdir}/systemd/network/25-nac.link
	install -m 0644 ${UNPACKDIR}/26-nac.link ${D}${sysconfdir}/systemd/network/26-nac.link
	install -m 0644 ${UNPACKDIR}/27-nac.link ${D}${sysconfdir}/systemd/network/27-nac.link
	install -m 0644 ${UNPACKDIR}/28-nac.link ${D}${sysconfdir}/systemd/network/28-nac.link
	install -m 0644 ${UNPACKDIR}/29-nac.link ${D}${sysconfdir}/systemd/network/29-nac.link
	install -m 0644 ${UNPACKDIR}/30-nac.link ${D}${sysconfdir}/systemd/network/30-nac.link
	install -m 0644 ${UNPACKDIR}/31-nac.link ${D}${sysconfdir}/systemd/network/31-nac.link
	install -m 0644 ${UNPACKDIR}/32-nac.link ${D}${sysconfdir}/systemd/network/32-nac.link
	install -m 0644 ${UNPACKDIR}/33-nac.link ${D}${sysconfdir}/systemd/network/33-nac.link
	install -m 0644 ${UNPACKDIR}/34-nac.link ${D}${sysconfdir}/systemd/network/34-nac.link
	install -m 0644 ${UNPACKDIR}/35-nac.link ${D}${sysconfdir}/systemd/network/35-nac.link
	install -m 0644 ${UNPACKDIR}/36-nac.link ${D}${sysconfdir}/systemd/network/36-nac.link
	install -m 0644 ${UNPACKDIR}/37-nac.link ${D}${sysconfdir}/systemd/network/37-nac.link
	install -m 0644 ${UNPACKDIR}/38-nac.link ${D}${sysconfdir}/systemd/network/38-nac.link
	install -m 0644 ${UNPACKDIR}/39-nac.link ${D}${sysconfdir}/systemd/network/39-nac.link
	install -m 0644 ${UNPACKDIR}/99-default.link ${D}${sysconfdir}/systemd/network/99-default.link

	# Manually disable resolved service since the use of SYSTEMD_AUTO_ENABLE has no effect
	rm -rf ${D}${sysconfdir}/systemd/system/multi-user.target.wants/systemd-resolved.service
}
