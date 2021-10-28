SUMMARY = "Extended cryptographic library (from glibc) with obsolete APIs"
DESCRIPTION = "Forked code from glibc libary to extract only crypto part.\
This provides libcrypto.so.1 which contains obsolete APIs, needed for uninative in particular."
HOMEPAGE = "https://github.com/besser82/libxcrypt"
SECTION = "libs"
LICENSE = "LGPLv2.1"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/LGPL-2.1-only;md5=1a6d268fd218675ffea8be556788b780"

SRC_URI = "https://repo.almalinux.org/almalinux/8/BaseOS/x86_64/os/Packages/libxcrypt-${PV}-4.el8.x86_64.rpm"

SRC_URI[md5sum] = "6df31d89eaa60dadaa7fe9255641946c"
SRC_URI[sha256sum] = "3b7cc56cf93dace67724dcabf7cd9634d1e637f62e898192ea744c1e90997623"

S = "${WORKDIR}"

do_install () {
	install -d ${D}${libdir}
	cp -P ${S}/lib64/libcrypt.so* ${D}${libdir}
}

INSANE_SKIP_${PN} = "already-stripped"
