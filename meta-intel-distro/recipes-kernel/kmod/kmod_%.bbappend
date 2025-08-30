FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://blacklist.conf.${SUFFIX}"

SUFFIX = '${@bb.utils.contains('DISTRO_FEATURES', "qsp", \
	    "qsp", "${@d.getVar('MACHINE').split('-')[2]}", d)}'

do_install:append () {
	install -m 644 ${WORKDIR}/blacklist.conf.${SUFFIX} ${D}${sysconfdir}/modprobe.d/blacklist.conf
}
