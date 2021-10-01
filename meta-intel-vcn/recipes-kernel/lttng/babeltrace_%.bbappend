DEPENDS_append = " python3 swig-native"

EXTRA_OECONF_append = " --enable-python-bindings"

inherit python3native

do_configure_prepend_class-target() {
    export _PYTHON_SYSCONFIGDATA_NAME="_sysconfigdata"
}

do_compile_prepend_class-target() {
    export _PYTHON_SYSCONFIGDATA_NAME="_sysconfigdata"
}

do_install_prepend_class-target() {
   export _PYTHON_SYSCONFIGDATA_NAME="_sysconfigdata"
}

PACKAGES =+ "python3-${PN}"
FILES_python3-${PN} = "${nonarch_libdir}/python3*"

RDEPENDS_python3-${PN} += "python3-core"
