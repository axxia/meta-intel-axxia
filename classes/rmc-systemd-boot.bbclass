# rmc-systemd-boot bbclass
# Deploy central RMC database file to ESP

IMAGE_INSTALL_append = " rmc"

inherit systemd-boot

do_bootimg[depends] += "${MLPREFIX}rmc-db:do_deploy"

efi_populate_append() {
	if [ -f ${DEPLOY_DIR_IMAGE}/rmc.db ]; then
        	install -m 0400 ${DEPLOY_DIR_IMAGE}/rmc.db ${DEST}/rmc.db
	else
		echo "Warning: no RMC central database was deployed, skip rmc.db."
	fi
}
