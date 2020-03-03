pkg_postinst_ontarget_${PN}-networking_append() {
	# set static ip for lxcbr0 bridge
	LXCBR_IP="iface lxcbr0 inet static\n        address 10.0.3.1\n        netmask 255.255.255.0"
	sed -i "s/iface lxcbr0 inet dhcp/${LXCBR_IP}/g" /etc/network/interfaces

	# remove eth0 interface from lxcbr0 to avoid nfs comunication errors
	sed -i 's/brctl addif lxcbr0 eth0/# brctl addif lxcbr0 eth0/g' /etc/network/if-pre-up.d/lxcbr0
	sed -i 's/ip addr flush eth0/# ip addr flush eth0/g' /etc/network/if-pre-up.d/lxcbr0
	sed -i 's/ifconfig eth0 up/# ifconfig eth0 up/g' /etc/network/if-pre-up.d/lxcbr0
}
