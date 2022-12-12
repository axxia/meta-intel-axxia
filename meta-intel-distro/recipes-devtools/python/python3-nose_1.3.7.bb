SUMMARY = "Extends Python unittest to make testing easier"
HOMEPAGE = "http://readthedocs.org/docs/nose/"
DESCRIPTION = "nose extends the test loading and running features of unittest, \
making it easier to write, find and run tests."
SECTION = "devel/python"
LICENSE = "LGPL-2.1-only"
LIC_FILES_CHKSUM = "file://lgpl.txt;md5=a6f89e2100d9b6cdffcea4f398e37343"

SRC_URI[md5sum] = "4d3ad0ff07b61373d2cefc89c5d0b20b"
SRC_URI[sha256sum] = "f1bffef9cbc82628f6e7d7b40d7e255aefaa1adb6a1b1d26c69a8b79e6208a98"

inherit setuptools3 pypi

RDEPENDS:${PN} = "\
  ${PYTHON_PN}-unittest \
  "

FILES:${PN}-doc += "${exec_prefix}/man"

BBCLASSEXTEND = "native nativesdk"
