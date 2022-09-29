DEPENDS:append = " swig-native"

EXTRA_OECONF:append = " --enable-python-bindings"

inherit python3targetconfig

PACKAGES =+ "python3-${PN}"
FILES:python3-${PN} = "${nonarch_libdir}/python3*"

RDEPENDS:python3-${PN} += "python3-core"
