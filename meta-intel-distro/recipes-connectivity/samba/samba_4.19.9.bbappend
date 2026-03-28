FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', \
		 ' file://9aa5c43315d83c19514251a11c4fba5a137f2821.patch', '', d)}"
