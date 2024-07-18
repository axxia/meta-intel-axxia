FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', 'file://dhrystone-c89.patch', '', d)}"

CFLAGS += "-Wno-error=implicit-int -Wno-error=implicit-function-declaration"
