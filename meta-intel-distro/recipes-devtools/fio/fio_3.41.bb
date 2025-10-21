SUMMARY = "Flexible I/O Tester (fio)"
DESCRIPTION = "fio is a tool to benchmark and test I/O performance."
HOMEPAGE = "https://git.kernel.org/pub/scm/linux/kernel/git/axboe/fio.git/"
LICENSE = "GPL-2.0-or-later"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

SRC_URI = "https://brick.kernel.dk/snaps/${BPN}-${PV}.tar.bz2"
SRC_URI[md5sum] = "ec8004ceac6f404b26c414f5e83996d9"
SRC_URI[sha256sum] = "ba95867d541a680b0e743b1ecb385e0874a88e422566a1a27eb15f1edf703a30"

S = "${WORKDIR}/fio-${PV}"

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
