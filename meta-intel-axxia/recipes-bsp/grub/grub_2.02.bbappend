CFLAGS_append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc8', \
		'', ' -Wno-address-of-packed-member', d)}"
