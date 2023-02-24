SUMMARY = "This plugin produces coverage reports."
SECTION = "devel/python"
HOMEPAGE = "https://github.com/pytest-dev/pytest-cov"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=cbc4e25353c748c817db2daffe605e43"

inherit setuptools3 pypi

PYPI_PACKAGE = "pytest-cov"

SRC_URI[sha256sum] = "996b79efde6433cdbd0088872dbc5fb3ed7fe1578b68cdbba634f14bb8dd0470"

RDEPENDS:${PN} += " \
	${PYTHON_PN}-pytest \
	"
