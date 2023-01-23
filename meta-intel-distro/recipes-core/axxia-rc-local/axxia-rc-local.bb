DESCRIPTION = "Custom init files for INTEL AXXIA images"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://rc.local.etc \
	   file://rc.local.etc.qsp \
           file://rc.local.init "

S = "${WORKDIR}"

inherit update-rc.d

RC_LOCAL = "${@bb.utils.contains('DISTRO_FEATURES', 'qsp', \
            'rc.local.etc.qsp', 'rc.local.etc', d)}"

INITSCRIPT_NAME = "rc.local"
INITSCRIPT_PARAMS = "start 99 2 3 4 5 ."

do_install () {
    install -d ${D}/${sysconfdir}/init.d
    install -m 755 ${S}/rc.local.init ${D}/${sysconfdir}/init.d/rc.local
    install -m 755 ${S}/${RC_LOCAL} ${D}/${sysconfdir}/rc.local
}
