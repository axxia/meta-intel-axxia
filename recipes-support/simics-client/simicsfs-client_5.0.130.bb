SUMMARY = "SimicsFS client that talks to a simulated device"
DESCRIPTION="SimicsFS gives you access to the file system of your real computer inside the simulated machine. This greatly simplifies the process of importing files into the simulated machine."

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://Makefile;md5=075374b44f8665b7a5008a68d58fd22b"

FILESEXTRAPATHS_prepend := "${THISDIR}/../../downloads:"

SRC_URI = "file://simics-${PV}.tgz"

SRC_URI[md5sum] = "66cb0a61098fa23c3bc2d6b7ebc7ea98"
SRC_URI[sha256sum] = "6f4a214d1611ccdc7df002d33a2287a96ffc2db0c0026c4a9eca06316fbcb28d"

DEPENDS = "fuse libmagicpipe"
RDEPENDS_${PN} = "fuse"

S = "${WORKDIR}/simics-${PV}/src/misc/${PN}"

do_compile () {
	oe_runmake
}

do_install () {
	install -d ${D}${bindir}
	install -m 0755 ${S}/simicsfs-client  ${D}${bindir}/simicsfs-client
}

FILES_${PN} = "${bindir}/simicsfs-client"
