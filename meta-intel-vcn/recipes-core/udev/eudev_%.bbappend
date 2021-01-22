FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " file://persistent-net.rules"

do_install_append() {
	install -m 0666 ${WORKDIR}/persistent-net.rules ${D}${sysconfdir}/udev/rules.d/70-persistent-net.rules
	install -m 0666 ${WORKDIR}/persistent-net.rules ${D}${nonarch_base_libdir}/udev/rules.d/70-persistent-net.rules
}

# Because qemu usermode is not supported for axxiax86-64 BSP, 
# update_udev_hwdb postinst intercept will fail on do_rootfs.
# Overwhite postinstal function to run only on target.
pkg_postinst_eudev-hwdb () {
	if ! test -n "$D"; then
		udevadm hwdb --update
	fi
}
