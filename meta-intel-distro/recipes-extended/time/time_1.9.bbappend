FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', \
		 ' file://time-1.9-Fix-compiling-with-GCC15.patch', '', d)}"
