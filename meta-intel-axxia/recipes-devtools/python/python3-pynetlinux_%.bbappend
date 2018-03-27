FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " file://python3-use-absolute-imports.patch"

BBCLASSEXTEND = "native nativesdk"
