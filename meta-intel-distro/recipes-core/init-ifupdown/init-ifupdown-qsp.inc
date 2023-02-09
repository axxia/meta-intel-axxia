SRC_URI:append = " file://interfaces-qsp"

do_install:append() {
	install -m 0644 ${WORKDIR}/interfaces-qsp \
		${D}${sysconfdir}/network/interfaces
}
