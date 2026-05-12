# Set the version for alternative kernels as virtual/kernel provider
KV = "${@d.getVar('PREFERRED_VERSION_' + d.getVar('PREFERRED_PROVIDER_virtual/kernel', True), True)}"
PREFERRED_VERSION_linux-yocto-debug ?= "${KV}"
PREFERRED_VERSION_linux-intel-debug ?= "${KV}"
PREFERRED_VERSION_linux-intel-private-debug ?= "${KV}"
PREFERRED_VERSION_linux-korg-netnext-debug = "${KV}"

# Set the version for iproute2 based on kernel version
IPROUTE2_VERSION ?= "${@bb.utils.contains_any('KV', '6.1% 6.6% 6.12%', '${KV}', '6.19%', d)}"
PREFERRED_VERSION_iproute2 ?= "${IPROUTE2_VERSION}"

# Avoid warnings for recipes with dynamic version
PREFERRED_VERSION_linux-intel-private ??= "dev%"
PREFERRED_VERSION_linux-intel-private-debug ??= "dev%"
PREFERRED_VERSION_linux-korg-netnext ??= "%"
PREFERRED_VERSION_linux-korg-netnext-debug ??= "%"

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
