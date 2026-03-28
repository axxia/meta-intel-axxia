FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:" 

SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', \
		 ' file://0001-Fix-32392-Regression-gprofng-fails-to-build-on.patch', '', d)}"
