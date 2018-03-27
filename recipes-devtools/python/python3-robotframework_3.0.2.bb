inherit setuptools3
require python-robotframework.inc

SRC_URI_append = " file://force-scripts-to-use-python3.patch"
