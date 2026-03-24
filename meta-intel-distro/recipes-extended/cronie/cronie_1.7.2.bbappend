FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', \
		 ' file://make_error_func_prototype_complete.patch', '', d)}"
