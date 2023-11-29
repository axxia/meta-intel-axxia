FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://mcelog.sysvinit"

inherit update-rc.d

INITSCRIPT_NAME = "mcelog"
INITSCRIPT_PARAMS = "start 99 3 5 ."

do_configure:prepend() {
   sed -i "s/#daemon = yes/daemon = yes/g" ${S}/mcelog.conf
}

do_install:append() {
    install -d ${D}${INIT_D_DIR}
    install -m 0755 ${WORKDIR}/mcelog.sysvinit ${D}${INIT_D_DIR}/mcelog
    rm -rf ${D}${sysconfdir}/cron.hourly
}
