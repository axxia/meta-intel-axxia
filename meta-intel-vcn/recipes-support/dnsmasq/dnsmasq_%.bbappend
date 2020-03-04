do_install_append () {
	# be sure resolv.conf is populated (by dhclient.service) before starting the service
	sed -i 's/After=network.target/After=network.target dhclient.service/g' \
		${D}${systemd_unitdir}/system/dnsmasq.service
}
