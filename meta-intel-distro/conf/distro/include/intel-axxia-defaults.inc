PREFERRED_VERSION_linux-intel-rt ?= "5.15%"
PREFERRED_VERSION_linux-intel-rt-debug ?= "5.15%"

GCC_VERSION = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc13', '13.%', '11.%', d)}"
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

PREFERRED_VERSION_libxcrypt-compat ?= "4.1.1"

PREFERRED_VERSION_linux-firmware ?= "20210511"

PREFERRED_VERSION_acpica ?= "20211217"

VIRTUAL-RUNTIME_syslog ?= "rsyslog"

SAVANNAH_NONGNU_MIRROR = "http://download-mirror.savannah.gnu.org/releases"

FORTRAN:forcevariable = ",fortran"
