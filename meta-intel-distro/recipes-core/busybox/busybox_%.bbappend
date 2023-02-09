FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://enable_tftp_blocksize_feature.cfg \
                               file://axxia-simple.script "

do_install:append() {
    if grep -q "CONFIG_UDHCPC=y" ${B}/.config; then
        install -m 0755 ${WORKDIR}/axxia-simple.script ${D}${sysconfdir}/udhcpc.d/50default
	sed -i "s:/SBIN_DIR/:${base_sbindir}/:" ${D}${sysconfdir}/udhcpc.d/50default
    fi
}

require ${@bb.utils.contains('DISTRO_FEATURES', 'qsp', 'busybox-qsp.inc', '', d)}
