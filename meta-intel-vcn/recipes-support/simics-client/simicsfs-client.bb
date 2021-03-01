SUMMARY = "SimicsFS client that talks to a simulated device"
DESCRIPTION="SimicsFS gives you access to the file system of your real computer inside the simulated machine. This greatly simplifies the process of importing files into the simulated machine."

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-or-later;md5=fed54355545ffd980b814dab4a3b312c"

SIMICS_VERSION ?= "generic"
PV = "${SIMICS_VERSION}"

FILESEXTRAPATHS_prepend := "${THISDIR}/../../downloads:"

SRC_URI = "file://simics-${PV}.tgz"

DEPENDS = "fuse libmagicpipe"
RDEPENDS_${PN} = "fuse"

S = "${WORKDIR}/simics-${PV}/src/misc/${PN}"

do_compile () {
	oe_runmake
}

do_install () {
	install -d ${D}${bindir} ${D}/host
	install -m 0755 ${S}/simicsfs-client  ${D}${bindir}/simicsfs-client
}

FILES_${PN} = "${bindir}/simicsfs-client /host"
