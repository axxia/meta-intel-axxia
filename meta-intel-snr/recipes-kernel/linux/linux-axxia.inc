kernel_do_deploy_append() {
	install -d ${DEPLOYDIR}
	install -m 0644 ${KBUILD_OUTPUT}/System.map \
		${DEPLOYDIR}/System${KERNEL_IMAGE_BASE_NAME}.map
	cd ${DEPLOYDIR}
	rm -f System.map
	ln -sf System${KERNEL_IMAGE_BASE_NAME}.map System.map
}
