# Set the version for the debug variant of the current kernel provider
python __anonymous() {
    provider = d.getVar('PREFERRED_PROVIDER_virtual/kernel')
    kv = d.getVar('PREFERRED_VERSION_' + provider)
    if kv and not provider.endswith('-debug'):
        d.setVar('PREFERRED_VERSION_' + provider + '-debug', kv)
}

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
