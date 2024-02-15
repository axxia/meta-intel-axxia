FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://nfsroot-resolvconf"

do_install:append() {
    install -m 0755 ${WORKDIR}/nfsroot-resolvconf \
	    ${D}${sysconfdir}/network/if-pre-up.d/nfsroot

    # Use classic network interface naming scheme if no 'pni-names' distro feature
    if ${@bb.utils.contains('DISTRO_FEATURES', 'pni-names', 'false', 'true', d)}; then
        sed -i 's/auto \/eth0/auto eth0/g' ${D}${sysconfdir}/network/interfaces
        sed -i '/^auto \/en\*=eth/d' ${D}${sysconfdir}/network/interfaces
        sed -i '/^iface eth inet dhcp/d' ${D}${sysconfdir}/network/interfaces
    fi
}

require ${@bb.utils.contains('DISTRO_FEATURES', 'qsp', \
	'init-ifupdown-qsp.inc', '', d)}
