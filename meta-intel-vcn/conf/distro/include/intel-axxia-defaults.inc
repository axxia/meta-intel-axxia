PREFERRED_VERSION_linux-intel-debug ?= "5.10%"
PREFERRED_VERSION_linux-intel-rt-debug ?= "5.10%"

PREFERRED_VERSION_linux-yocto ?= "5.10%"
PREFERRED_VERSION_linux-yocto-rt ?= "5.10%"
PREFERRED_VERSION_linux-yocto-debug ?= "5.10%"
PREFERRED_VERSION_linux-yocto-rt-debug ?= "5.10%"

PREFERRED_VERSION_thrift ?= "0.11.0"
PREFERRED_VERSION_thrift-native ?= "0.11.0"

PREFERRED_VERSION_boost ?= "1.70.0"
PREFERRED_VERSION_boost-native ?= "1.70.0"
PREFERRED_VERSION_bjam-native ?= "1.70.0"

PYTHON_VERSION ?= "3.9"
PYTHON_BASEVERSION_forcevariable = "${PYTHON_VERSION}"
PYTHON_ABI_forcevariable = "${@oe.utils.conditional('PYTHON_VERSION', '3.6', 'm', '', d)}"
PREFERRED_VERSION_python3 ?= "${PYTHON_VERSION}%"
PREFERRED_VERSION_python3-native ?= "${PYTHON_VERSION}%"
PREFERRED_VERSION_nativesdk-python3 ?= "${PYTHON_VERSION}%"
PREFERRED_VERSION_gpgme = "${@oe.utils.conditional('PYTHON_VERSION', '3.6', '1.12%', '1.15%', d)}"
PREFERRED_VERSION_gpgme-native = "${PREFERRED_VERSION_gpgme}"
