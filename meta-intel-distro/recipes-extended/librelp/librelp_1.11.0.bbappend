FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://0001-relp-fix-build-against-upcoming-gcc-14.patch"
