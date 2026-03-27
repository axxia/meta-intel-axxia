FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

DEPENDS += "bison-native flex-native"

SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', \
		 ' file://0001-Fix-declarations-to-allow-build-with-gcc-15.patch', '', d)}"
