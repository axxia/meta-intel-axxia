PREFERRED_PROVIDER_virtual/kernel_genericx86-64 = "linux-yocto"

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

PREFERRED_VERSION_libxcrypt-compat ?= "4.1.1"

PREFERRED_VERSION_linux-firmware ?= "20210511"

PREFERRED_VERSION_acpica ?= "20211217"

PYTHON_VERSION ?= "3.9"
PYTHON_BASEVERSION_forcevariable = "${PYTHON_VERSION}"
PYTHON_ABI_forcevariable = "${@oe.utils.conditional('PYTHON_VERSION', '3.6', 'm', '', d)}"
PREFERRED_VERSION_python3 ?= "${PYTHON_VERSION}%"
PREFERRED_VERSION_python3-native ?= "${PYTHON_VERSION}%"
PREFERRED_VERSION_nativesdk-python3 ?= "${PYTHON_VERSION}%"
PREFERRED_VERSION_gpgme = "${@oe.utils.conditional('PYTHON_VERSION', '3.6', '1.12%', '1.15%', d)}"
PREFERRED_VERSION_gpgme-native = "${PREFERRED_VERSION_gpgme}"
PREFERRED_VERSION_libffi = "${@oe.utils.conditional('PYTHON_VERSION', '3.6', '3.1', '3.3', d)}"

GCC_VERSION = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc9', '9.%', \
                  bb.utils.contains('DISTRO_FEATURES', 'gcc10', '10.%', '11.%', d), d)}"
PREFERRED_VERSION_gcc ?= "${GCC_VERSION}"
PREFERRED_VERSION_gcc-runtime ?= "${GCC_VERSION}"
PREFERRED_VERSION_gcc-sanitizers ?= "${GCC_VERSION}"
PREFERRED_VERSION_gcc-source ?= "${GCC_VERSION}"
PREFERRED_VERSION_gcc-runtime ?= "${GCC_VERSION}"
PREFERRED_VERSION_gcc-cross-${TARGET_ARCH} ?= "${GCC_VERSION}"
PREFERRED_VERSION_gcc-crosssdk-${SDK_SYS} ?= "${GCC_VERSION}"
PREFERRED_VERSION_gcc-cross-canadian-${TRANSLATED_TARGET_ARCH} ?= "${GCC_VERSION}"
PREFERRED_VERSION_libgcc ?= "${GCC_VERSION}"
PREFERRED_VERSION_libgcc-initial ?= "${GCC_VERSION}"
PREFERRED_VERSION_libgfortran ?= "${GCC_VERSION}"
PREFERRED_VERSION_nativesdk-gcc ?= "${GCC_VERSION}"
PREFERRED_VERSION_nativesdk-gcc-runtime ?= "${GCC_VERSION}"
PREFERRED_VERSION_nativesdk-gcc-sanitizers ?= "${GCC_VERSION}"
PREFERRED_VERSION_nativesdk-gcc-source ?= "${GCC_VERSION}"
PREFERRED_VERSION_nativesdk-gcc-runtime ?= "${GCC_VERSION}"
PREFERRED_VERSION_nativesdk-gcc-cross-${TARGET_ARCH} ?= "${GCC_VERSION}"
PREFERRED_VERSION_nativesdk-gcc-crosssdk-${SDK_SYS} ?= "${GCC_VERSION}"
PREFERRED_VERSION_nativesdk-gcc-cross-canadian-${TRANSLATED_TARGET_ARCH} ?= "${GCC_VERSION}"
PREFERRED_VERSION_nativesdk-libgcc ?= "${GCC_VERSION}"
PREFERRED_VERSION_nativesdk-libgcc-initial ?= "${GCC_VERSION}"
PREFERRED_VERSION_nativesdk-libgfortran ?= "${GCC_VERSION}"

FORTRAN_forcevariable = ",fortran"
