DESCRIPTION = "Tools to provide a way to get Platform Reliability, Availability and Serviceability (RAS) reports made via the Kernel tracing events"
HOMEPAGE = "http://git.infradead.org/users/mchehab/rasdaemon.git"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d3070efe0afa3dc41608bd82c00bb0dc \
                    file://rasdaemon.c;md5=7421eac9de65162c886eeacd1532e94d"

SRC_URI = "git://git.infradead.org/users/mchehab/rasdaemon.git;branch=master \
	   file://rasdaemon.service \
	   file://init \
	   "
UPSTREAM_CHECK_COMMITS = "1"

SRCREV = "3dca35f17effa102b7140d5554401ef2292425b7"
PV = "0.6.5+git${SRCPV}"

S = "${WORKDIR}/git"

RDEPENDS_${BPN} = "perl libdbi-perl libdbd-sqlite-perl bash"
DEPENDS = " sqlite3 "

inherit autotools pkgconfig update-rc.d systemd

EXTRA_OECONF += "--enable-sqlite3 --enable-mce --enable-extlog --enable-abrt-report --enable-non-standard --enable-aer"

do_configure_prepend () {
        ( cd ${S}; autoreconf -vfi )
}

FILES_${PN} += "${sbindir}/rasdaemon \
                ${sysconfdir}/init.d \
                ${systemd_unitdir}/system/rasdaemon.service \
"

SYSTEMD_SERVICE_${PN} = "rasdaemon.service"
SYSTEMD_AUTO_ENABLE = "enable"

INITSCRIPT_PACKAGES = "${PN}"
INITSCRIPT_NAME_${PN} = "rasdaemon"
INITSCRIPT_PARAMS_${PN} = "defaults 89"

do_install_append() {
   install -d ${D}${sysconfdir}/init.d
   install -m 755 ${WORKDIR}/init ${D}${sysconfdir}/init.d/rasdaemon
   install -d ${D}${systemd_unitdir}/system
   install -m 0644 ${WORKDIR}/rasdaemon.service ${D}${systemd_unitdir}/system

   # install test scripts in rootfs
   install -m 755 ${S}/contrib/* ${D}${sbindir}
}

