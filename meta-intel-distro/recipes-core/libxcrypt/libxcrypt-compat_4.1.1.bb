SUMMARY = "Extended cryptographic library (from glibc) with obsolete APIs"
DESCRIPTION = "Forked code from glibc libary to extract only crypto part.\
This provides libcrypto.so.1 which contains obsolete APIs, needed for uninative in particular."
HOMEPAGE = "https://github.com/besser82/libxcrypt"
SECTION = "libs"
LICENSE = "LGPLv2.1"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/LGPL-2.1-only;md5=1a6d268fd218675ffea8be556788b780"

SRC_URI = "https://repo.almalinux.org/almalinux/8/BaseOS/x86_64/os/Packages/libxcrypt-${PV}-6.el8.x86_64.rpm"

SRC_URI[md5sum] = "c49d5d63f6d740015eb8b27b4a294b4f"
SRC_URI[sha256sum] = "d47f375a7902f3059a8690edc5949bbfd4708d53762c53414ff8747b7b409809"

S = "${WORKDIR}"

do_install () {
	install -d ${D}${libdir}
	cp -P ${S}/lib64/libcrypt.so* ${D}${libdir}
}

INSANE_SKIP:${PN} = "already-stripped"
