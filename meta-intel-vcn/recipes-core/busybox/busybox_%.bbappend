FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append_axxiax86-64 = " file://enable_tftp_blocksize_feature.cfg \
                               file://axxia-simple.script "

do_install_append() {
    if grep -q "CONFIG_UDHCPC=y" ${B}/.config; then
        install -m 0755 ${WORKDIR}/axxia-simple.script ${D}${sysconfdir}/udhcpc.d/50default
	sed -i "s:/SBIN_DIR/:${base_sbindir}/:" ${D}${sysconfdir}/udhcpc.d/50default
    fi
}
