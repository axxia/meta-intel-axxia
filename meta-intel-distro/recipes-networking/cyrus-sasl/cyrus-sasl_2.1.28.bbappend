FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

GCC15_PATCHES ?= "file://0001-configure-prototypes.patch \
		  file://0002-Fix-incompatible-pointer-types-error-with-gcc-15.patch \
		  file://0003-Add-compatibility-for-gcc-15-869.patch"

SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', ' ${GCC15_PATCHES}', '', d)}"
