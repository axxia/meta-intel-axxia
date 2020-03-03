FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " ${@bb.utils.contains('DISTRO_FEATURES', 'gcc8', \
		   '', 'file://0001-getcpu01-Rename-getcpu-to-avoid-conflict-with-glibc.patch', d)}"
