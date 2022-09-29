HOMEPAGE = "https://windriver.com/products/simics"
LICENSE = "CLOSED"

SIMICS_VERSION ?= "generic"
PV = "${SIMICS_VERSION}"

FILESEXTRAPATHS:prepend := "${THISDIR}/../../downloads:"

SRC_URI = "file://simics-${PV}.tgz"

S = "${WORKDIR}/simics-${PV}/src/misc/${PN}"

do_compile () {
	oe_runmake
}
