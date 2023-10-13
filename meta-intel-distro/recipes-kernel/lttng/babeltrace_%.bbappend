FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://0001-configure.ac-Fix-python-config-path-error.patch"

DEPENDS:append = " swig-native"

EXTRA_OECONF:append = " --enable-python-bindings"

inherit python3targetconfig

PACKAGES =+ "python3-${PN}"
FILES:python3-${PN} = "${nonarch_libdir}/python3*"

RDEPENDS:python3-${PN} += "python3-core"
