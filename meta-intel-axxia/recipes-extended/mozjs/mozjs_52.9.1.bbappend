FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " ${@bb.utils.contains('DISTRO_FEATURES', 'gcc8', \
		   '', 'file://format-overflow.patch', d)}"
