SYSTEMD_AUTO_ENABLE_${PN}-client = "enable"

do_install_append() {
	cat << 'EOF' >> ${D}${base_sbindir}/dhclient-systemd-wrapper

# Fix resolv.conf in case one interface is used for nfsroot
if [ $nfsroot -ne 0 ]; then
    if [ -n "$(grep nameserver /proc/net/pnp)" ]; then
       ln -sf /proc/net/pnp $(readlink /etc/resolv.conf)
    fi
fi
EOF
}
