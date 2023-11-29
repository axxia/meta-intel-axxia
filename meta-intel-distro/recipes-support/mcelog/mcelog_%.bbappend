FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " file://mcelog.sysvinit"

inherit update-rc.d

INITSCRIPT_NAME = "mcelog"
INITSCRIPT_PARAMS = "start 99 3 5 ."

do_configure_prepend() {
   sed -i "s/#daemon = yes/daemon = yes/g" ${S}/mcelog.conf
}

do_install_append() {
    install -d ${D}${INIT_D_DIR}
    install -m 0755 ${WORKDIR}/mcelog.sysvinit ${D}${INIT_D_DIR}/mcelog
    rm -rf ${D}${sysconfdir}/cron.hourly
}
