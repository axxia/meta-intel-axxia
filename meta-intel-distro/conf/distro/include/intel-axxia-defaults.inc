PREFERRED_PROVIDER_virtual/kernel:genericx86-64 = "linux-yocto"

PREFERRED_VERSION_linux-intel-debug ?= "5.10%"
PREFERRED_VERSION_linux-intel-rt-debug ?= "5.10%"

PREFERRED_VERSION_linux-yocto ?= "5.10%"
PREFERRED_VERSION_linux-yocto-rt ?= "5.10%"
PREFERRED_VERSION_linux-yocto-debug ?= "5.10%"
PREFERRED_VERSION_linux-yocto-rt-debug ?= "5.10%"

LTTNG_VERSION ?= "2.13%"
PREFERRED_VERSION_lttng-ust ?= "${LTTNG_VERSION}"
PREFERRED_VERSION_lttng-tools ?= "${LTTNG_VERSION}"
PREFERRED_VERSION_lttng-modules ?= "${LTTNG_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-intel ?= "${LTTNG_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-intel-rt ?= "${LTTNG_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-intel-debug ?= "${LTTNG_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-intel-rt-debug ?= "${LTTNG_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-yocto ?= "${LTTNG_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-yocto-rt ?= "${LTTNG_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-yocto-debug ?= "${LTTNG_VERSION}"
PREFERRED_VERSION_lttng-modules-linux-yocto-rt-debug ?= "${LTTNG_VERSION}"

PREFERRED_VERSION_thrift ?= "0.11.0"
PREFERRED_VERSION_thrift-native ?= "0.11.0"

PREFERRED_VERSION_boost ?= "1.70.0"
PREFERRED_VERSION_boost-native ?= "1.70.0"
PREFERRED_VERSION_bjam-native ?= "1.70.0"

PREFERRED_VERSION_libxcrypt-compat ?= "4.1.1"

PREFERRED_VERSION_linux-firmware ?= "20210511"

PREFERRED_VERSION_acpica ?= "20211217"

FORTRAN:forcevariable = ",fortran"
