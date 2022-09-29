FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://nfsroot-resolvconf"

do_install:append() {
    install -m 0755 ${WORKDIR}/nfsroot-resolvconf \
	    ${D}${sysconfdir}/network/if-pre-up.d/nfsroot
}
