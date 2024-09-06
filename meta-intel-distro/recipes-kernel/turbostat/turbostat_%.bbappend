do_configure:append() {
	if [ -f "${STAGING_KERNEL_DIR}/tools/include/linux/build_bug.h" ]; then
		cp -r ${STAGING_KERNEL_DIR}/tools/include/linux/build_bug.h ${S}
	fi
	cp -r ${STAGING_KERNEL_DIR}/tools/include/linux/compiler.h ${S}
	cp -r ${STAGING_KERNEL_DIR}/tools/include/linux/compiler_types.h ${S}
	cp -r ${STAGING_KERNEL_DIR}/tools/include/linux/compiler-gcc.h ${S}
}

do_compile:prepend() {
	sed -i 's#<linux/compiler.h>#"compiler.h"#' build_bug.h
	sed -i 's#<linux/compiler_types.h>#"compiler_types.h"#' compiler.h
	sed -i 's#<linux/compiler-gcc.h>#"compiler-gcc.h"#' compiler_types.h
	echo '#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))' >> msr-index.h
	echo "#define BIT(x) (1 << (x))" > bits.h
	echo "#define BIT_ULL(nr) (1ULL << (nr))" >> bits.h
	echo "#define GENMASK(h, l) (((~0UL) << (l)) & (~0UL >> (sizeof(long) * 8 - 1 - (h))))" >> bits.h
	echo "#define GENMASK_ULL(h, l) (((~0ULL) << (l)) & (~0ULL >> (sizeof(long long) * 8 - 1 - (h))))" >> bits.h

	sed -i 's#BUILD_BUG_HEADER#"build_bug.h"#' turbostat.c
}
