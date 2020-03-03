GCC9_CFLAGS = " -Wno-error=address-of-packed-member \
		-Wno-error=stringop-truncation "

CFLAGS_append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc8', \
				      '', '${GCC9_CFLAGS}', d)}"
