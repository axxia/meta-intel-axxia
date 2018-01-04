FILESEXTRAPATHS_prepend := "${THISDIR}/systemd:"

SRC_URI += "file://10-eth.link"
SRC_URI += "file://20-nac.link"
SRC_URI += "file://21-nac.link"
SRC_URI += "file://22-nac.link"
SRC_URI += "file://23-nac.link"
SRC_URI += "file://24-nac.link"
SRC_URI += "file://25-nac.link"
SRC_URI += "file://26-nac.link"
SRC_URI += "file://27-nac.link"
SRC_URI += "file://28-nac.link"
SRC_URI += "file://29-nac.link"
SRC_URI += "file://30-nac.link"
SRC_URI += "file://31-nac.link"
SRC_URI += "file://32-nac.link"
SRC_URI += "file://33-nac.link"
SRC_URI += "file://34-nac.link"
SRC_URI += "file://35-nac.link"
SRC_URI += "file://36-nac.link"
SRC_URI += "file://37-nac.link"
SRC_URI += "file://38-nac.link"
SRC_URI += "file://39-nac.link"
SRC_URI += "file://99-default.link"

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
}
