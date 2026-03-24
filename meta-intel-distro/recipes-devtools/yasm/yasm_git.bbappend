FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', \
		 ' file://0001-bitvect-fix-build-with-gcc-15.patch', '', d)}"
