do_configure() {
	mkdir -p ${S}
	cp -r ${STAGING_KERNEL_DIR}/arch/x86/include/asm/msr-index.h ${S}
	cp -r ${STAGING_KERNEL_DIR}/arch/x86/include/asm/intel-family.h ${S}
	cp -r ${STAGING_KERNEL_DIR}/tools/power/x86/turbostat/* ${S}
	cp -r ${STAGING_KERNEL_DIR}/tools/include ${S}
	cp -r ${WORKDIR}/COPYING ${S}
}

do_compile() {
	sed -i 's#MSRHEADER#"msr-index.h"#' turbostat.c
	sed -i 's#INTEL_FAMILY_HEADER#"intel-family.h"#' turbostat.c
	sed -i '/^override.*include$/s/$/ -I.\/include/' Makefile
	sed -i 's#\$(CC) \$(CFLAGS) \$< -o \$(BUILD_OUTPUT)/\$@#\$(CC) \$(CFLAGS) \$(LDFLAGS) \$< -o \$(BUILD_OUTPUT)/\$@#' Makefile
	oe_runmake STAGING_KERNEL_DIR=${STAGING_KERNEL_DIR}
}
