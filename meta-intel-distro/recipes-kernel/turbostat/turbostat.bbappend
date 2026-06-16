do_configure:prepend() {
	mkdir -p ${S}
	cp -r ${STAGING_KERNEL_DIR}/include/linux/compiler-context-analysis.h ${S} 2>/dev/null || true
}

do_compile:prepend() {
	sed -i 's#<linux/compiler-context-analysis.h>#"compiler-context-analysis.h"#' compiler_types.h
}
