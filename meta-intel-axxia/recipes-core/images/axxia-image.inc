GLIBC_GENERATE_LOCALES = "en_US.UTF-8"
IMAGE_LINGUAS = "en-us"

do_image_clean_deploy () {
	# Remove testdata json files with old stamp before repopulating deploy dir
	rm -f ${DEPLOY_DIR_IMAGE}/${PN}-${MACHINE}*.testdata.json
}

do_rootfs[prefuncs] += "do_image_clean_deploy"
do_clean[prefuncs] += "do_image_clean_deploy"
