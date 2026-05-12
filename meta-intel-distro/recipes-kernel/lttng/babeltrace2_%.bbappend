DEPENDS:append = " python3-setuptools-native swig-native"

EXTRA_OECONF:append = " --enable-python-bindings"

inherit python3targetconfig

PACKAGES =+ "python3-${BPN}"
FILES:python3-${BPN} = "${libdir}/python3*"

RDEPENDS:python3-${BPN} += "python3-core"
