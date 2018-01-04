do_install_append () {
	sed -i 's/ttyS3/ttyS3\nttyS4\nttyS5/g' ${D}${sysconfdir}/securetty
}
