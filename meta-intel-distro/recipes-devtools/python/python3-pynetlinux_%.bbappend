FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://python3-use-absolute-imports.patch"

BBCLASSEXTEND = "native nativesdk"
