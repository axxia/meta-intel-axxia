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

SRC_URI[md5sum] = "e38309855985ffb45f3bf503e90af9a3"
SRC_URI[sha256sum] = "b066ec18e56b6616a3b38086b5747daafbaa8868b226a36127e0451c0cf379c6"

RDEPENDS:${PN} += "\
	${PYTHON_PN}-docopt \
	"
