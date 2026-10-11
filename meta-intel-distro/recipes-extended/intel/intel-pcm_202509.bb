DESCRIPTION = "Intel PCM (Performance Counter Monitor)"
HOMEPAGE = "https://github.com/intel/pcm"

LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://LICENSE;md5=a708c4161b707763cc051a9e3ddc863a"

DEPENDS = "openssl"

SRC_URI = " \
	gitsm://github.com/intel/pcm.git;protocol=https;branch=master \
	file://pcm-avoid-strip.patch \
        file://pcm_disable_tests.patch \
	"
SRCREV = "10f6b5e284ac01df11b23a8142ea5607ae501b17"

COMPATIBLE_HOST = '(x86_64).*-linux'
COMPATIBLE_HOST:libc-musl = "null"

do_install:append() {
	mv ${D}${docdir}/PCM ${D}${docdir}/pcm
	rm -fr ${D}${datadir}/licenses
}

FILES:${PN} += "${datadir}/pcm"

inherit cmake
