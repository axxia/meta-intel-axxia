do_configure_prepend() {
	mkdir -p ${S}
	cp -r ${STAGING_KERNEL_DIR}/include/linux/bits.h ${S}
}

do_compile_prepend() {
	sed -i 's#<linux/bits.h>#"bits.h"#' msr-index.h
}
