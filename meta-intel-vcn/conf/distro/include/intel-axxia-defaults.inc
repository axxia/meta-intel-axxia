PREFERRED_VERSION_linux-intel-debug ?= "4.19%"
PREFERRED_VERSION_linux-intel-rt-debug ?= "4.19%"

PREFERRED_RPROVIDER_iasl ?= "iasl"
PREFERRED_RPROVIDER_iasl-native ?= "iasl-native"

PREFERRED_VERSION_autofs ?= "5.1.5"

PREFERRED_VERSION_rpcbind ?= "0.2.3"

PREFERRED_VERSION_mcelog ?= "164"

PREFERRED_VERSION_thrift ?= "0.11.0"
PREFERRED_VERSION_thrift-native ?= "0.11.0"

GLIBC_VERSION = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc8', '2.28', '2.29', d)}"
PREFERRED_VERSION_glibc ?= "${GLIBC_VERSION}"
PREFERRED_VERSION_glibc-scripts ?= "${GLIBC_VERSION}"
PREFERRED_VERSION_glibc-mtrace ?= "${GLIBC_VERSION}"
PREFERRED_VERSION_glibc-locale ?= "${GLIBC_VERSION}"
PREFERRED_VERSION_cross-localedef-native ?= "${GLIBC_VERSION}"
PREFERRED_VERSION_nativesdk-glibc ?= "${GLIBC_VERSION}"
PREFERRED_VERSION_nativesdk-glibc-scripts ?= "${GLIBC_VERSION}"
PREFERRED_VERSION_nativesdk-glibc-mtrace ?= "${GLIBC_VERSION}"
PREFERRED_VERSION_nativesdk-glibc-locale ?= "${GLIBC_VERSION}"
PREFERRED_VERSION_nativesdk-cross-localedef-native ?= "${GLIBC_VERSION}"
