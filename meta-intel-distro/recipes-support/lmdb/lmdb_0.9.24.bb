# SPDX-FileCopyrightText: 2017-2019 Volker Krause <vkrause@kde.org>
# SPDX-FileCopyrightText: 2019 Hannah Kiekens <hannahkiekens@gmail.com>
#
# SPDX-License-Identifier: MIT

SUMMARY = "Lightning Memory-Mapped Database (LMDB)"
HOMEPAGE = "https://symas.com/lightning-memory-mapped-database/"
LICENSE = "OLDAP-2.8"
LIC_FILES_CHKSUM = "file://LICENSE;md5=153d07ef052c4a37a8fac23bc6031972"

SRC_URI = "git://github.com/LMDB/lmdb.git;protocol=http;nobranch=1"
SRCREV = "LMDB_${PV}"

inherit base

S = "${WORKDIR}/git/libraries/liblmdb"

do_compile() {
    oe_runmake CC="${CC}" SOEXT=".so.${PV}" LDFLAGS="-Wl,-soname,lib${PN}.so.${PV}"
}

do_install() {
    oe_runmake CC="${CC}" DESTDIR="${D}" prefix="${prefix}" libdir="${libdir}" manprefix="${mandir}" SOEXT=".so.${PV}" LDFLAGS="-Wl,-soname,lib${PN}.so.${PV}" install
    cd ${D}/${libdir}
    ln -s liblmdb.so.${PV} liblmdb.so
    rm liblmdb.a
}

INSANE_SKIP += "ldflags"
