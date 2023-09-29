# Set the version for alternative kernels as virtual/kernel provider
KV = "${@d.getVar('PREFERRED_VERSION_' + d.getVar('PREFERRED_PROVIDER_virtual/kernel', True), True)}"
PREFERRED_VERSION_linux-intel-rt ?= "${KV}"
PREFERRED_VERSION_linux-intel-rt-debug ?= "${KV}"

PREFERRED_VERSION_libxcrypt-compat ?= "4.1.1"

PREFERRED_VERSION_linux-firmware ?= "20210511"

PREFERRED_VERSION_acpica ?= "20230628"

PREFERRED_VERSION_fwts ?= "23.07.00"

VIRTUAL-RUNTIME_syslog ?= "rsyslog"

SAVANNAH_NONGNU_MIRROR = "http://download-mirror.savannah.gnu.org/releases"

FORTRAN:forcevariable = ",fortran"
