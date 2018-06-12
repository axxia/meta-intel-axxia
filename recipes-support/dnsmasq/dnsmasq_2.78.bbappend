do_install_append () {
	sed -i 's/After=network.target/After=network.target systemd-resolved.service/g' \
		${D}${systemd_unitdir}/system/dnsmasq.service
}
