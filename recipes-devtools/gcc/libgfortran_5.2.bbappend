FILES_${PN}-dev += "\
	${libdir}/gcc/${TARGET_SYS}/${BINV}/finclude/ieee_exceptions.mod \
	${libdir}/gcc/${TARGET_SYS}/${BINV}/finclude/ieee_features.mod \
	${libdir}/gcc/${TARGET_SYS}/${BINV}/finclude/ieee_arithmetic.mod \
"

do_configure_append() {
	# Correct invalid libgcc symlinks with wrong target path.
	cd ${B}/$target/libgcc
	for d in enable-execute-stack.c gthr-default.h md-unwind-support.h sfp-machine.h unwind.h; do
		if [ ! -e "$d" ]; then
			ln -f -s ./../$(readlink $d) $d
		fi
	done
}
