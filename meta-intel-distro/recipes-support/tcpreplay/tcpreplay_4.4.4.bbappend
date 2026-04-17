FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

GCC15_PATCHES ?= " file://0001-Fix-linker-error-for-TX_RING.patch \
		   file://0002-fix-incompatible-type-assignment-in-txring.c.patch \
		   "

SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', ' ${GCC15_PATCHES}', '', d)}"

