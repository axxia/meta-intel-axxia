do_install_append() {
	ln -sf nsl/libnsl.so.2 ${D}${libdir}/libnsl.so.2
}
