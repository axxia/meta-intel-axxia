DESCRIPTION = "Custom init files for INTEL AXXIA images"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://rc.local.etc.snr \
	   file://rc.local.etc.grr \
	   file://rc.local.etc.pmr \
	   file://rc.local.etc.qsp \
           file://rc.local.init "

S = "${WORKDIR}"

inherit update-rc.d

INITSCRIPT_NAME = "rc.local"
INITSCRIPT_PARAMS = "start 99 2 3 4 5 ."

do_install () {
    install -d ${D}/${sysconfdir}/init.d
    install -m 755 ${S}/rc.local.init ${D}/${sysconfdir}/init.d/rc.local
    if [ "${DISTRO_FEATURES}" = "qsp" ]; then
        install -m 755 ${S}/rc.local.etc.qsp ${D}/${sysconfdir}/rc.local
    elif [ "${MACHINE}" = "intel-axxia-snr" ]; then
        install -m 755 ${S}/rc.local.etc.snr ${D}/${sysconfdir}/rc.local
    elif [ "${MACHINE}" = "intel-axxia-grr" ]; then
        install -m 755 ${S}/rc.local.etc.grr ${D}/${sysconfdir}/rc.local
    elif [ "${MACHINE}" = "intel-axxia-pmr" ]; then
        install -m 755 ${S}/rc.local.etc.pmr ${D}/${sysconfdir}/rc.local
    fi
}
