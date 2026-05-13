# Set the version for alternative kernels as virtual/kernel provider
KV = "${@d.getVar('PREFERRED_VERSION_' + d.getVar('PREFERRED_PROVIDER_virtual/kernel', True), True)}"
PREFERRED_VERSION_linux-yocto-debug ?= "${KV}"
PREFERRED_VERSION_linux-intel-debug ?= "${KV}"
PREFERRED_VERSION_linux-intel-private-debug ?= "${KV}"
PREFERRED_VERSION_linux-korg-netnext-debug = "${KV}"

# Set the version for iproute2 based on kernel version
IPROUTE2_VERSION ?= "${@bb.utils.contains_any('KV', '6.1% 6.6% 6.12%', '${KV}', '6.19%', d)}"
PREFERRED_VERSION_iproute2 ?= "${IPROUTE2_VERSION}"

# Set the version for ethtool based on kernel version (exception: v6.14 for linux v6.12)
ETHTOOL_VERSION ?= "${@bb.utils.contains('IPROUTE2_VERSION', '6.12%', '6.14%', '${IPROUTE2_VERSION}', d)}"
PREFERRED_VERSION_ethtool ?= "${@d.getVar('ETHTOOL_VERSION').replace('%', '')}%"

# Avoid warnings for recipes with dynamic version
PREFERRED_VERSION_linux-intel-private ??= "dev%"
PREFERRED_VERSION_linux-intel-private-debug ??= "dev%"
PREFERRED_VERSION_linux-korg-netnext ??= "%"
PREFERRED_VERSION_linux-korg-netnext-debug ??= "%"

GCC_VERSION = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', '15.%', \
		  bb.utils.contains('DISTRO_FEATURES', 'gcc11', '11.%', '13.%', d), d)}"
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

# Pass 'gcc15' features to nativesdk class
DISTRO_FEATURES_NATIVESDK:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', ' gcc15', \
				       bb.utils.contains('DISTRO_FEATURES', 'gcc11', ' gcc11', '', d), d)}"

PREFERRED_VERSION_libxcrypt-compat ?= "4.1.1"

PREFERRED_VERSION_linux-firmware ?= "20210511"

# Set lttng-modules version for primary and alternative kernels based on MACHINE
LTTNG_MODULES_VERSION_SNR_GRR ?= "${@bb.utils.contains_any('KV', '6.1% 6.6% 6.12%', '2.13%', '2.14%', d)}"
LTTNG_MODULES_VERSION ?= "${@oe.utils.conditional('MACHINE', 'intel-axxia-pmr', '2.14%', '${LTTNG_MODULES_VERSION_SNR_GRR}', d)}"
PREFERRED_VERSION_lttng-modules = "${LTTNG_MODULES_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-intel-debug = "${LTTNG_MODULES_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-yocto-debug = "${LTTNG_MODULES_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-intel-private-debug = "${LTTNG_MODULES_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-korg-netnext-debug = "${LTTNG_MODULES_VERSION}"

VIRTUAL-RUNTIME_syslog ?= "rsyslog"

SAVANNAH_NONGNU_MIRROR = "http://download-mirror.savannah.gnu.org/releases"

FORTRAN:forcevariable = ",fortran"
