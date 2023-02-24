SUMMARY = "Trex Stateless library"
SECTION = "devel/python"
HOMEPAGE = "https://github.com/dedie/trex_stl_lib"

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://PKG-INFO;beginline=8;endline=8;md5=38bfc7e0741f16cf42c918b4fbedac9c"

inherit pypi setuptools3

PYPI_PACKAGE = "trex_stl_lib"

SRC_URI[sha256sum] = "2b430f7b76dee39ed0dbaa65ba50afb1f508c2c0f5a3b25d3199fbe153ef746b"

RDEPENDS:${PN} += " \
	${PYTHON_PN}-scapy \
	${PYTHON_PN}-pyzmq \
	${PYTHON_PN}-texttable \
	${PYTHON_PN}-pyyaml \
	"
