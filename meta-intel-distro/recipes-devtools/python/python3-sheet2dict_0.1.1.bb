SUMMARY = "A simple XLSX/CSV reader - to dictionary converter"
DESCRIPTION = "This library has 2 main features: reading a spreadsheet \
files and converting them to array of python dictionaries."
SECTION = "devel/python"
HOMEPAGE = "https://github.com/Pytlicek/sheet2dict"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=ea5fbc50c0963fd7f682cd41346baaad"

inherit pypi setuptools3

SRC_URI[sha256sum] = "72e8cd0cc128a9007ed71e05efb569ae84d3c82e7f6d2e08e09a2c228548a73e"

PYPI_PACKAGE = "sheet2dict"

DEPENDS += "\
	${PYTHON_PN}-openpyxl-native \
	"

RDEPENDS:${PN} += "\
	${PYTHON_PN}-openpyxl \
	"
