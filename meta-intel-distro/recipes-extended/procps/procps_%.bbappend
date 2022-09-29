LOG_LEVEL = "kernel.printk = 4 4 1 7"

do_install:append () {
	sed -i 's/#${LOG_LEVEL}/${LOG_LEVEL}/g' ${D}${sysconfdir}/sysctl.conf
}
