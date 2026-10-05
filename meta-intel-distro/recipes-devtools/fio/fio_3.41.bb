SUMMARY = "Flexible I/O Tester (fio)"
DESCRIPTION = "fio is a tool to benchmark and test I/O performance."
HOMEPAGE = "https://git.kernel.org/pub/scm/linux/kernel/git/axboe/fio.git/"
LICENSE = "GPL-2.0-or-later"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

SRC_URI = "https://git.kernel.org/pub/scm/linux/kernel/git/axboe/fio.git/snapshot/${BPN}-${PV}.tar.gz"
SRC_URI[md5sum] = "161958afdea6ad1948edcb6d34e1ae85"
SRC_URI[sha256sum] = "aee29e9dd739b4ffc3939169de0b342988f32302b35b966649c87b2319a9548a"

S = "${UNPACKDIR}/fio-${PV}"

inherit pkgconfig

DEPENDS = "libaio liburing openssl"

RDEPENDS:${PN} = "bash"

do_configure() {
	${S}/configure --prefix=${prefix}
}

do_compile() {
	oe_runmake
}

do_install() {
	oe_runmake install DESTDIR=${D} PREFIX=${prefix}
}

FILES_${PN} += "${bindir} ${mandir}"
