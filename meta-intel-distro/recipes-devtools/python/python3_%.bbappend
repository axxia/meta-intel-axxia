PACKAGECONFIG:append:class-target = " tk"
PACKAGECONFIG:append:class-nativesdk = " tk"

do_install_append () {
    ln -s python3 ${D}${bindir}/python
}

PACKAGES += "${PN}-python-symlink"
FILES_${PN}-python-symlink += "${bindir}/python"

RDEPENDS_${PN}-core_append_class-target = " \
    ${PN}-python-symlink"
