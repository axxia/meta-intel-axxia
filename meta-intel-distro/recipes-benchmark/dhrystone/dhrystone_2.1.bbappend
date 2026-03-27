FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

GCC15_PATCHES ?= "file://dhrystone-c89.patch \
		  file://0001-fix-too-many-arguments-error-in-gcc15.patch"

SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', ' ${GCC15_PATCHES}', '', d)}"

CFLAGS += "-Wno-error=implicit-int -Wno-error=implicit-function-declaration"
