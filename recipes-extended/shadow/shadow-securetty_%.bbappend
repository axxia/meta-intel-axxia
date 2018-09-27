do_install_append () {
	sed -i 's/ttyS3/ttyS3\nttyS4\nttyS5\nttyS6\nttyS7\nttyS8/g' ${D}${sysconfdir}/securetty
}
