# my tweak to sysvinit 

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " file://rcS"

do_install () {
        oe_runmake 'ROOT=${D}' install
        install -d ${D}${sysconfdir} \
                   ${D}${sysconfdir}/default \
                   ${D}${sysconfdir}/init.d
        install -m 0644    ${WORKDIR}/rcS-default       ${D}${sysconfdir}/default/rcS
        install -m 0755    ${WORKDIR}/rc                ${D}${sysconfdir}/init.d
        install -m 0755    ${WORKDIR}/rcS               ${D}${sysconfdir}/init.d
        install -m 0755    ${WORKDIR}/bootlogd.init     ${D}${sysconfdir}/init.d/bootlogd
        install -d ${D}${sysconfdir}/rcS.d
        for level in 2 3 4 5; do
                install -d ${D}${sysconfdir}/rc$level.d
        done
}

