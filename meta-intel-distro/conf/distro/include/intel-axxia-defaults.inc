# Set the version for alternative kernels as virtual/kernel provider
KV = "${@d.getVar('PREFERRED_VERSION_' + d.getVar('PREFERRED_PROVIDER_virtual/kernel', True), True)}"
PREFERRED_VERSION_linux-yocto-debug ?= "${KV}"
PREFERRED_VERSION_linux-intel-debug ?= "${KV}"
PREFERRED_VERSION_linux-intel-private-debug ?= "${KV}"
PREFERRED_VERSION_linux-intel-collab-debug ?= "${KV}"
PREFERRED_VERSION_linux-intel-staging-debug ?= "${KV}"
PREFERRED_VERSION_linux-korg-netnext-debug ?= "${KV}"

ETHTOOL_VERSION ?= "6.19"
PREFERRED_VERSION_ethtool ?= "${ETHTOOL_VERSION}%"

IPROUTE2_VERSION ?= "6.19"
PREFERRED_VERSION_iproute2 ?= "${IPROUTE2_VERSION}%"

# Avoid warnings for recipes with dynamic version
PREFERRED_VERSION_linux-intel-private ??= "dev%"
PREFERRED_VERSION_linux-intel-private-debug ??= "dev%"
PREFERRED_VERSION_linux-intel-collab ??= "%"
PREFERRED_VERSION_linux-intel-collab-debug ??= "%"
PREFERRED_VERSION_linux-korg-netnext ??= "%"
PREFERRED_VERSION_linux-korg-netnext-debug ??= "%"

PREFERRED_VERSION_libxcrypt-compat ?= "4.1.1"

PREFERRED_VERSION_linux-firmware ?= "20210511"

PREFERRED_RPROVIDER_libnss-mdns = "avahi-libnss-mdns"

VIRTUAL-RUNTIME_syslog ?= "rsyslog"

FORTRAN:forcevariable = ",fortran"
