DESCRIPTION = "Intel PCM (Performance Counter Monitor)"
HOMEPAGE = "https://github.com/intel/pcm"

LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://LICENSE;md5=a708c4161b707763cc051a9e3ddc863a"

SRC_URI = " \
	git://github.com/intel/pcm;protocol=https;branch=master \
	file://pcm-avoid-strip.patch \
	"
SRCREV = "9b3e4a1688869a8a88f0ea17d0be1c5283f0b3bb"

S = "${WORKDIR}/git"

COMPATIBLE_HOST = '(x86_64).*-linux'
COMPATIBLE_HOST:libc-musl = "null"

do_install:append() {
	mv ${D}${docdir}/PCM ${D}${docdir}/pcm
	rm -fr ${D}${datadir}/licenses
}

FILES:${PN} += "${datadir}/pcm"

inherit cmake
