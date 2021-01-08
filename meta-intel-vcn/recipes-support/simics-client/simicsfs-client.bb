SUMMARY = "SimicsFS client that talks to a simulated device"
DESCRIPTION="SimicsFS gives you access to the file system of your real computer inside the simulated machine. This greatly simplifies the process of importing files into the simulated machine."

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://Makefile;md5=20958840d6f20430bde553874ab6cc12"

SIMICS_VERSION ?= "generic"
PV = "${SIMICS_VERSION}"

FILESEXTRAPATHS_prepend := "${THISDIR}/../../downloads:"

SRC_URI = "file://simics-${PV}.tgz"

SRC_URI[md5sum] = "c3b69ffff751fa6bdf258bd802c14ac3"
SRC_URI[sha256sum] = "8efbda455b18ffc420eb3ecaa45c3ed546937ee9345ae6c732b0faaae11b8a7a"

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
