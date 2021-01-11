do_install_append () {
	# Ensure /var/cache directory can be populated at boot time on read-only rootfs
	if ${@bb.utils.contains('DISTRO_FEATURES','redonly-rootfs','false','true',d)}; then
		echo $'tmpfs                /var/cache           tmpfs      defaults              0  0\n' \
		     >> ${D}${sysconfdir}/fstab
	fi
}
