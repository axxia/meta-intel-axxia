FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " ${@bb.utils.contains('DISTRO_FEATURES', 'gcc9', \
		   'file://0001-Woverride-init-is-not-needed-with-gcc-9.patch', '', d)}"
