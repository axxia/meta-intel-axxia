PACKAGECONFIG:append:class-target = " tk"
PACKAGECONFIG:append:class-nativesdk = " tk"

do_install:append () {
    ln -s python3 ${D}${bindir}/python
}

PACKAGES += "${PN}-python-symlink"
FILES:${PN}-python-symlink += "${bindir}/python"

RDEPENDS:${PN}-core:append:class-target = " \
    ${PN}-python-symlink"
