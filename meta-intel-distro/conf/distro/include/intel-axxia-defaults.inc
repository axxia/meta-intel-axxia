# Set the version for alternative kernels as virtual/kernel provider
KV = "${@d.getVar('PREFERRED_VERSION_' + d.getVar('PREFERRED_PROVIDER_virtual/kernel', True), True)}"
PREFERRED_VERSION_linux-yocto-debug ?= "${KV}"
PREFERRED_VERSION_linux-intel-debug ?= "${KV}"
PREFERRED_VERSION_linux-intel-private-debug ?= "${KV}"
PREFERRED_VERSION_linux-korg-netnext-debug ?= "${KV}"

# Avoid warnings for recipes with dynamic version
PREFERRED_VERSION_linux-intel-private ??= "dev%"
PREFERRED_VERSION_linux-intel-private-debug ??= "dev%"
PREFERRED_VERSION_linux-korg-netnext ??= "%"
PREFERRED_VERSION_linux-korg-netnext-debug ??= "%"

PREFERRED_VERSION_libxcrypt-compat ?= "4.1.1"

PREFERRED_VERSION_linux-firmware ?= "20210511"

PREFERRED_RPROVIDER_libnss-mdns = "avahi-libnss-mdns"

VIRTUAL-RUNTIME_syslog ?= "rsyslog"

SAVANNAH_NONGNU_MIRROR = "http://download-mirror.savannah.gnu.org/releases"

FORTRAN:forcevariable = ",fortran"
