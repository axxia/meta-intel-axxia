SUMMARY = "A simple XLSX/CSV reader - to dictionary converter"
DESCRIPTION = "This library has 2 main features: reading a spreadsheet \
files and converting them to array of python dictionaries."
SECTION = "devel/python"
HOMEPAGE = "https://github.com/Pytlicek/sheet2dict"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=ea5fbc50c0963fd7f682cd41346baaad"

inherit pypi python_flit_core

SRC_URI[sha256sum] = "efa356159dedc05a57482b50dd01fe870d8b4ae589ec97253701e526fda3f269"

PYPI_PACKAGE = "sheet2dict"

DEPENDS += "\
	${PYTHON_PN}-openpyxl-native \
	${PYTHON_PN}-setuptools-scm-native \
	"

RDEPENDS:${PN} += "\
	${PYTHON_PN}-openpyxl \
	${PYTHON_PN}-pytest \
	${PYTHON_PN}-pytest-cov \
	"

do_compile:prepend() {
	echo -e '\n__version__ = "${PV}"\n' >> ${S}/${PYPI_PACKAGE}/__init__.py
}
