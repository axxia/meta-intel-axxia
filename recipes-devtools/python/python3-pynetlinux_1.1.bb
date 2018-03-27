inherit setuptools3
require python-pynetlinux.inc

SRC_URI_append = " file://python3-use-absolute-imports.patch"
