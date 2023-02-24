SUMMARY = "Convert numbers to words in multiple languages"
DESCRIPTION = "num2words is a library that converts numbers like 42 \
to words like forty-two. It supports multiple languages (see the list \
below for full list of languages) and can even generate ordinal numbers \
like forty-second (although this last feature is a bit buggy for some \
languages at the moment)."
SECTION = "devel/python"
HOMEPAGE = "https://github.com/savoirfairelinux/num2words"

LICENSE = "LGPL-2.1-only"
LIC_FILES_CHKSUM = "file://COPYING;md5=f1b68565299e4b2403b8b3a87d0bcacf"

inherit pypi setuptools3

PYPI_PACKAGE = "num2words"

SRC_URI[sha256sum] = "7e7c0b0f080405aa3a1dd9d32b1ca90b3bf03bab17b8e54db05e1b78301a0988"

RDEPENDS:${PN} += "\
	${PYTHON_PN}-docopt \
	"
