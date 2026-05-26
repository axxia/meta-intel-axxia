LOG_LEVEL = "kernel.printk = 4 4 1 7"

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://50-axxia.conf"

do_install:append () {
	sed -i 's/#${LOG_LEVEL}/${LOG_LEVEL}/g' ${D}${sysconfdir}/sysctl.conf
	install -D -m 0644 ${WORKDIR}/50-axxia.conf ${D}${sysconfdir}/sysctl.d/50-axxia.conf
}

FILES:${PN}:append = " ${sysconfdir}/sysctl.d/50-axxia.conf"
