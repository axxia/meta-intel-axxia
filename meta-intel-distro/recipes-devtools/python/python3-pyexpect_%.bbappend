inherit ptest

do_install_ptest() {
	cp -r ${S}/tests ${D}${PTEST_PATH}/
}

do_install:append() {
	rm -rf ${D}${PYTHON_SITEPACKAGES_DIR}/tests
}

BBCLASSEXTEND:append = " nativesdk"
