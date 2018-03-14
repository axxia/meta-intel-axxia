do_image_clean_deploy () {
	# Remove testdata json files with old stamp before repopulating deploy dir
	rm -f ${DEPLOY_DIR_IMAGE}/${PN}-${MACHINE}*.testdata.json
}

addtask do_image_clean_deploy before do_image_complete
