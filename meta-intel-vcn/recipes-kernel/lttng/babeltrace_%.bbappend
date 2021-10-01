DEPENDS_append = " swig-native"

EXTRA_OECONF_append = " --enable-python-bindings"

inherit python3targetconfig

PACKAGES =+ "python3-${PN}"
FILES_python3-${PN} = "${nonarch_libdir}/python3*"

RDEPENDS_python3-${PN} += "python3-core"
