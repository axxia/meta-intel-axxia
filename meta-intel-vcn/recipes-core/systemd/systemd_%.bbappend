FILESEXTRAPATHS_prepend := "${THISDIR}/systemd:"

SRC_URI_append_axxiax86-64 = " file://10-eth.link \
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

do_install_append() {
	install -d ${D}${sysconfdir}
	install -m 0644 ${WORKDIR}/10-eth.link ${D}${sysconfdir}/systemd/network/10-eth.link
	install -m 0644 ${WORKDIR}/20-nac.link ${D}${sysconfdir}/systemd/network/20-nac.link
	install -m 0644 ${WORKDIR}/21-nac.link ${D}${sysconfdir}/systemd/network/21-nac.link
	install -m 0644 ${WORKDIR}/22-nac.link ${D}${sysconfdir}/systemd/network/22-nac.link
	install -m 0644 ${WORKDIR}/23-nac.link ${D}${sysconfdir}/systemd/network/23-nac.link
	install -m 0644 ${WORKDIR}/24-nac.link ${D}${sysconfdir}/systemd/network/24-nac.link
	install -m 0644 ${WORKDIR}/25-nac.link ${D}${sysconfdir}/systemd/network/25-nac.link
	install -m 0644 ${WORKDIR}/26-nac.link ${D}${sysconfdir}/systemd/network/26-nac.link
	install -m 0644 ${WORKDIR}/27-nac.link ${D}${sysconfdir}/systemd/network/27-nac.link
	install -m 0644 ${WORKDIR}/28-nac.link ${D}${sysconfdir}/systemd/network/28-nac.link
	install -m 0644 ${WORKDIR}/29-nac.link ${D}${sysconfdir}/systemd/network/29-nac.link
	install -m 0644 ${WORKDIR}/30-nac.link ${D}${sysconfdir}/systemd/network/30-nac.link
	install -m 0644 ${WORKDIR}/31-nac.link ${D}${sysconfdir}/systemd/network/31-nac.link
	install -m 0644 ${WORKDIR}/32-nac.link ${D}${sysconfdir}/systemd/network/32-nac.link
	install -m 0644 ${WORKDIR}/33-nac.link ${D}${sysconfdir}/systemd/network/33-nac.link
	install -m 0644 ${WORKDIR}/34-nac.link ${D}${sysconfdir}/systemd/network/34-nac.link
	install -m 0644 ${WORKDIR}/35-nac.link ${D}${sysconfdir}/systemd/network/35-nac.link
	install -m 0644 ${WORKDIR}/36-nac.link ${D}${sysconfdir}/systemd/network/36-nac.link
	install -m 0644 ${WORKDIR}/37-nac.link ${D}${sysconfdir}/systemd/network/37-nac.link
	install -m 0644 ${WORKDIR}/38-nac.link ${D}${sysconfdir}/systemd/network/38-nac.link
	install -m 0644 ${WORKDIR}/39-nac.link ${D}${sysconfdir}/systemd/network/39-nac.link
	install -m 0644 ${WORKDIR}/99-default.link ${D}${sysconfdir}/systemd/network/99-default.link

	# Manually disable resolved service since the use of SYSTEMD_AUTO_ENABLE has no effect
	rm -rf ${D}${sysconfdir}/systemd/system/multi-user.target.wants/systemd-resolved.service
}
