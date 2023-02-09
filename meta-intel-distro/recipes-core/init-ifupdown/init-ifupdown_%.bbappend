FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " file://nfsroot-resolvconf"

do_install_append() {
    install -m 0755 ${WORKDIR}/nfsroot-resolvconf \
	    ${D}${sysconfdir}/network/if-pre-up.d/nfsroot
}

require ${@bb.utils.contains('DISTRO_FEATURES', 'qsp', \
	'init-ifupdown-qsp.inc', '', d)}
