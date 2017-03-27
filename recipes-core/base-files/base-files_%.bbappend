do_install_prepend () {
	echo "simicsfs             /host                 simicsfs   defaults,noauto      0  0" >> ${WORKDIR}/fstab
}
