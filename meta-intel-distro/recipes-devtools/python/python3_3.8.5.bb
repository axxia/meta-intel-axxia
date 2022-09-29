SUMMARY = "The Python Programming Language"
HOMEPAGE = "http://www.python.org"
LICENSE = "PSFv2"
SECTION = "devel/python"

LIC_FILES_CHKSUM = "file://LICENSE;md5=203a6dbc802ee896020a47161e759642"

FILESEXTRAPATHS:prepend := "${THISDIR}/python${PYTHON_MAJMIN}:"

SRC_URI = "http://www.python.org/ftp/python/${PV}/Python-${PV}.tar.xz \
           file://run-ptest \
           file://create_manifest3.py \
           file://get_module_deps3.py \
           file://python3-manifest.json \
           file://check_build_completeness.py \
           file://cgi_py.patch \
           file://0001-Do-not-add-usr-lib-termcap-to-linker-flags-to-avoid-.patch \
           ${@bb.utils.contains('PACKAGECONFIG', 'tk', '', 'file://avoid_warning_about_tkinter.patch', d)} \
           file://0001-Do-not-use-the-shell-version-of-python-config-that-w.patch \
           file://python-config.patch \
           file://0001-Makefile.pre-use-qemu-wrapper-when-gathering-profile.patch \
           file://0001-Do-not-hardcode-lib-as-location-for-site-packages-an.patch \
           file://0001-python3-use-cc_basename-to-replace-CC-for-checking-c.patch \
           file://0001-Lib-sysconfig.py-fix-another-place-where-lib-is-hard.patch \
           file://0001-Makefile-fix-Issue36464-parallel-build-race-problem.patch \
           file://0001-bpo-36852-proper-detection-of-mips-architecture-for-.patch \
           file://crosspythonpath.patch \
           file://reformat_sysconfig.py \
           file://0001-Use-FLAG_REF-always-for-interned-strings.patch \
           file://0001-test_locale.py-correct-the-test-output-format.patch \
           file://0017-setup.py-do-not-report-missing-dependencies-for-disa.patch \
           file://0001-setup.py-pass-missing-libraries-to-Extension-for-mul.patch \
           file://0001-Makefile-do-not-compile-.pyc-in-parallel.patch \
           file://0001-configure.ac-fix-LIBPL.patch \
           file://0001-python3-Do-not-hardcode-lib-for-distutils.patch \
           file://0020-configure.ac-setup.py-do-not-add-a-curses-include-pa.patch \
           "

SRC_URI:append_class-native = " \
           file://0001-distutils-sysconfig-append-STAGING_LIBDIR-python-sys.patch \
           file://12-distutils-prefix-is-inside-staging-area.patch \
           file://0001-Don-t-search-system-for-headers-libraries.patch \
           "

SRC_URI[md5sum] = "35b5a3d0254c1c59be9736373d429db7"
SRC_URI[sha256sum] = "e3003ed57db17e617acb382b0cade29a248c6026b1bd8aad1f976e9af66a83b0"

# exclude pre-releases for both python 2.x and 3.x
UPSTREAM_CHECK_REGEX = "[Pp]ython-(?P<pver>\d+(\.\d+)+).tar"
UPSTREAM_CHECK_URI = "https://www.python.org/downloads/source/"

CVE_PRODUCT = "python"

# This is not exploitable when glibc has CVE-2016-10739 fixed.
CVE_CHECK_WHITELIST += "CVE-2019-18348"

PYTHON_MAJMIN = "3.8"

S = "${WORKDIR}/Python-${PV}"

BBCLASSEXTEND = "native nativesdk"

inherit autotools pkgconfig qemu ptest multilib_header update-alternatives

MULTILIB_SUFFIX = "${@d.getVar('base_libdir',1).split('/')[-1]}"

ALTERNATIVE_${PN}-dev = "python3-config"
ALTERNATIVE_LINK_NAME[python3-config] = "${bindir}/python${PYTHON_MAJMIN}-config"
ALTERNATIVE_TARGET[python3-config] = "${bindir}/python${PYTHON_MAJMIN}-config-${MULTILIB_SUFFIX}"


DEPENDS = "bzip2-replacement-native libffi bzip2 openssl sqlite3 zlib virtual/libintl xz virtual/crypt util-linux libtirpc libnsl2"
DEPENDS:append_class-target = " python3-native"
DEPENDS:append_class-nativesdk = " python3-native"

EXTRA_OECONF = " --without-ensurepip --enable-shared"
EXTRA_OECONF:append_class-native = " --bindir=${bindir}/${PN}"

export CROSSPYTHONPATH="${STAGING_LIBDIR_NATIVE}/python${PYTHON_MAJMIN}/lib-dynload/"

EXTRANATIVEPATH += "python3-native"

CACHED_CONFIGUREVARS = " \
                ac_cv_file__dev_ptmx=yes \
                ac_cv_file__dev_ptc=no \
                ac_cv_working_tzset=yes \
"

def possibly_include_pgo(d):
    # PGO currently causes builds to not be reproducible, so disable it for
    # now. See YOCTO #13407
    if bb.utils.contains('MACHINE_FEATURES', 'qemu-usermode', True, False, d) and d.getVar('BUILD_REPRODUCIBLE_BINARIES') != '1':
        return 'pgo'
    
    return ''

PACKAGECONFIG_class-target ??= "readline ${@possibly_include_pgo(d)} gdbm"
PACKAGECONFIG_class-native ??= "readline gdbm"
PACKAGECONFIG_class-nativesdk ??= "readline gdbm"
PACKAGECONFIG[readline] = ",,readline"
# Use profile guided optimisation by running PyBench inside qemu-user
PACKAGECONFIG[pgo] = "--enable-optimizations,,qemu-native"
PACKAGECONFIG[tk] = ",,tk"
PACKAGECONFIG[gdbm] = ",,gdbm"

do_configure:prepend () {
    mkdir -p ${B}/Modules
    cat > ${B}/Modules/Setup.local << EOF
*disabled*
${@bb.utils.contains('PACKAGECONFIG', 'gdbm', '', '_gdbm _dbm', d)}
${@bb.utils.contains('PACKAGECONFIG', 'readline', '', 'readline', d)}
EOF
}

CPPFLAGS:append = " -I${STAGING_INCDIR}/ncursesw -I${STAGING_INCDIR}/uuid"

EXTRA_OEMAKE = '\
  STAGING_LIBDIR=${STAGING_LIBDIR} \
  STAGING_INCDIR=${STAGING_INCDIR} \
  LIB=${baselib} \
'

do_compile:prepend_class-target() {
       if ${@bb.utils.contains('PACKAGECONFIG', 'pgo', 'true', 'false', d)}; then
                qemu_binary="${@qemu_wrapper_cmdline(d, '${STAGING_DIR_TARGET}', ['${B}', '${STAGING_DIR_TARGET}/${base_libdir}'])}"
                cat >pgo-wrapper <<EOF
#!/bin/sh
cd ${B}
$qemu_binary "\$@"
EOF
                chmod +x pgo-wrapper
        fi
}

do_install:prepend() {
        ${WORKDIR}/check_build_completeness.py ${T}/log.do_compile
}

do_install:append_class-target() {
        oe_multilib_header python${PYTHON_MAJMIN}/pyconfig.h
}

do_install:append_class-native() {
        # Make sure we use /usr/bin/env python
        for PYTHSCRIPT in `grep -rIl ${bindir}/${PN}/python ${D}${bindir}/${PN}`; do
                sed -i -e '1s|^#!.*|#!/usr/bin/env python3|' $PYTHSCRIPT
        done
        # Add a symlink to the native Python so that scripts can just invoke
        # "nativepython" and get the right one without needing absolute paths
        # (these often end up too long for the #! parser in the kernel as the
        # buffer is 128 bytes long).
        ln -s python3-native/python3 ${D}${bindir}/nativepython3
}

do_install:append() {
        mkdir -p ${D}${libdir}/python-sysconfigdata
        sysconfigfile=`find ${D} -name _sysconfig*.py`
        cp $sysconfigfile ${D}${libdir}/python-sysconfigdata/_sysconfigdata.py

        sed -i  \
                -e "s,^ 'LIBDIR'.*, 'LIBDIR': '${STAGING_LIBDIR}'\,,g" \
                -e "s,^ 'INCLUDEDIR'.*, 'INCLUDEDIR': '${STAGING_INCDIR}'\,,g" \
                -e "s,^ 'CONFINCLUDEDIR'.*, 'CONFINCLUDEDIR': '${STAGING_INCDIR}'\,,g" \
                -e "/^ 'INCLDIRSTOMAKE'/{N; s,/usr/include,${STAGING_INCDIR},g}" \
                -e "/^ 'INCLUDEPY'/s,/usr/include,${STAGING_INCDIR},g" \
                ${D}${libdir}/python-sysconfigdata/_sysconfigdata.py
}

do_install:append_class-nativesdk () {
    create_wrapper ${D}${bindir}/python${PYTHON_MAJMIN} TERMINFO_DIRS='${sysconfdir}/terminfo:/etc/terminfo:/usr/share/terminfo:/usr/share/misc/terminfo:/lib/terminfo' PYTHONNOUSERSITE='1'
}

SSTATE_SCAN_FILES += "Makefile _sysconfigdata.py"
PACKAGE_PREPROCESS_FUNCS += "py_package_preprocess"

py_package_preprocess () {
        # Remove references to buildmachine paths in target Makefile and _sysconfigdata
        sed -i -e 's:--sysroot=${STAGING_DIR_TARGET}::g' -e s:'--with-libtool-sysroot=${STAGING_DIR_TARGET}'::g \
                -e 's|${DEBUG_PREFIX_MAP}||g' \
                -e 's:${HOSTTOOLS_DIR}/::g' \
                -e 's:${RECIPE_SYSROOT_NATIVE}::g' \
                -e 's:${RECIPE_SYSROOT}::g' \
                -e 's:${BASE_WORKDIR}/${MULTIMACH_TARGET_SYS}::g' \
                ${PKGD}/${libdir}/python${PYTHON_MAJMIN}/config-${PYTHON_MAJMIN}${PYTHON_ABI}*/Makefile \
                ${PKGD}/${libdir}/python${PYTHON_MAJMIN}/_sysconfigdata*.py \
                ${PKGD}/${bindir}/python${PYTHON_MAJMIN}-config

        # Reformat _sysconfigdata after modifying it so that it remains
        # reproducible
        for c in ${PKGD}/${libdir}/python${PYTHON_MAJMIN}/_sysconfigdata*.py; do
            python3 ${WORKDIR}/reformat_sysconfig.py $c
        done

        # Recompile _sysconfigdata after modifying it
        cd ${PKGD}
        sysconfigfile=`find . -name _sysconfigdata_*.py`
        ${STAGING_BINDIR_NATIVE}/python3-native/python3 \
             -c "from py_compile import compile; compile('$sysconfigfile')"
        ${STAGING_BINDIR_NATIVE}/python3-native/python3 \
             -c "from py_compile import compile; compile('$sysconfigfile', optimize=1)"
        ${STAGING_BINDIR_NATIVE}/python3-native/python3 \
             -c "from py_compile import compile; compile('$sysconfigfile', optimize=2)"
        cd -

        mv ${PKGD}/${bindir}/python${PYTHON_MAJMIN}-config ${PKGD}/${bindir}/python${PYTHON_MAJMIN}-config-${MULTILIB_SUFFIX}
        
        #Remove the unneeded copy of target sysconfig data
        rm -rf ${PKGD}/${libdir}/python-sysconfigdata
}

# We want bytecode precompiled .py files (.pyc's) by default
# but the user may set it on their own conf
INCLUDE_PYCS ?= "1"

python(){
    import collections, json

    filename = os.path.join(d.getVar('THISDIR'), 'python3.8', 'python3-manifest.json')
    # This python changes the datastore based on the contents of a file, so mark
    # that dependency.
    bb.parse.mark_dependency(d, filename)

    with open(filename) as manifest_file:
        manifest_str =  manifest_file.read()
        json_start = manifest_str.find('# EOC') + 6
        manifest_file.seek(json_start)
        manifest_str = manifest_file.read()
        python_manifest = json.loads(manifest_str, object_pairs_hook=collections.OrderedDict)

    # First set RPROVIDES for -native case
    # Hardcoded since it cant be python3-native-foo, should be python3-foo-native
    pn = 'python3'
    rprovides = (d.getVar('RPROVIDES') or "").split()

    # ${PN}-misc-native is not in the manifest
    rprovides.append(pn + '-misc-native')

    for key in python_manifest:
        pypackage = pn + '-' + key + '-native'
        if pypackage not in rprovides:
              rprovides.append(pypackage)

    d.setVar('RPROVIDES_class-native', ' '.join(rprovides))

    # Then work on the target
    include_pycs = d.getVar('INCLUDE_PYCS')

    packages = d.getVar('PACKAGES').split()
    pn = d.getVar('PN')

    newpackages=[]
    for key in python_manifest:
        pypackage = pn + '-' + key

        if pypackage not in packages:
            # We need to prepend, otherwise python-misc gets everything
            # so we use a new variable
            newpackages.append(pypackage)

        # "Build" python's manifest FILES, RDEPENDS and SUMMARY
        d.setVar('FILES:' + pypackage, '')
        for value in python_manifest[key]['files']:
            d.appendVar('FILES:' + pypackage, ' ' + value)

        # Add cached files
        if include_pycs == '1':
            for value in python_manifest[key]['cached']:
                    d.appendVar('FILES:' + pypackage, ' ' + value)

        for value in python_manifest[key]['rdepends']:
            # Make it work with or without $PN
            if '${PN}' in value:
                value=value.split('-', 1)[1]
            d.appendVar('RDEPENDS:' + pypackage, ' ' + pn + '-' + value)

        for value in python_manifest[key].get('rrecommends', ()):
            if '${PN}' in value:
                value=value.split('-', 1)[1]
            d.appendVar('RRECOMMENDS_' + pypackage, ' ' + pn + '-' + value)

        d.setVar('SUMMARY_' + pypackage, python_manifest[key]['summary'])

    # Prepending so to avoid python-misc getting everything
    packages = newpackages + packages
    d.setVar('PACKAGES', ' '.join(packages))
    d.setVar('ALLOW_EMPTY_${PN}-modules', '1')
    d.setVar('ALLOW_EMPTY_${PN}-pkgutil', '1')
}

# Files needed to create a new manifest

do_create_manifest() {
    # This task should be run with every new release of Python.
    # We must ensure that PACKAGECONFIG enables everything when creating
    # a new manifest, this is to base our new manifest on a complete
    # native python build, containing all dependencies, otherwise the task
    # wont be able to find the required files.
    # e.g. BerkeleyDB is an optional build dependency so it may or may not
    # be present, we must ensure it is.

    cd ${WORKDIR}
    # This needs to be executed by python-native and NOT by HOST's python
    nativepython3 create_manifest3.py ${PYTHON_MAJMIN}
    cp python3-manifest.json.new ${THISDIR}/python3/python3-manifest.json
}

# bitbake python -c create_manifest
addtask do_create_manifest

# Make sure we have native python ready when we create a new manifest
do_create_manifest[depends] += "${PN}:do_prepare_recipe_sysroot"
do_create_manifest[depends] += "${PN}:do_patch"

# manual dependency additions
RRECOMMENDS_${PN}-core:append_class-nativesdk = " nativesdk-python3-modules"
RRECOMMENDS_${PN}-crypt:append_class-target = " ${MLPREFIX}openssl ${MLPREFIX}ca-certificates"
RRECOMMENDS_${PN}-crypt:append_class-nativesdk = " ${MLPREFIX}openssl ${MLPREFIX}ca-certificates"

# For historical reasons PN is empty and provided by python3-modules
FILES:${PN} = ""
RPROVIDES_${PN}-modules = "${PN}"

FILES:${PN}-pydoc += "${bindir}/pydoc${PYTHON_MAJMIN} ${bindir}/pydoc3"
FILES:${PN}-idle += "${bindir}/idle3 ${bindir}/idle${PYTHON_MAJMIN}"

# provide python-pyvenv from python3-venv
RPROVIDES_${PN}-venv += "${MLPREFIX}python3-pyvenv"

# package libpython3
PACKAGES =+ "libpython3 libpython3-staticdev"
FILES:libpython3 = "${libdir}/libpython*.so.*"
FILES:libpython3-staticdev += "${libdir}/python${PYTHON_MAJMIN}/config-${PYTHON_MAJMIN}-*/libpython${PYTHON_MAJMIN}.a"
INSANE_SKIP_${PN}-dev += "dev-elf"

# catch all the rest (unsorted)
PACKAGES += "${PN}-misc"
RDEPENDS:${PN}-misc += "\
  ${PN}-core \
  ${PN}-email \
  ${PN}-codecs \
  ${PN}-pydoc \
  ${PN}-pickle \
  ${PN}-audio \
  ${PN}-numbers \
"
RDEPENDS:${PN}-modules:append_class-target = " ${MLPREFIX}python3-misc"
RDEPENDS:${PN}-modules:append_class-nativesdk = " ${MLPREFIX}python3-misc"
FILES:${PN}-misc = "${libdir}/python${PYTHON_MAJMIN} ${libdir}/python${PYTHON_MAJMIN}/lib-dynload"

# catch manpage
PACKAGES += "${PN}-man"
FILES:${PN}-man = "${datadir}/man"

# See https://bugs.python.org/issue18748 and https://bugs.python.org/issue37395
RDEPENDS:libpython3:append_libc-glibc = " libgcc"
RDEPENDS:${PN}-ctypes:append_libc-glibc = " ${MLPREFIX}ldconfig"
RDEPENDS:${PN}-ptest = "${PN}-modules ${PN}-tests unzip bzip2 libgcc tzdata-europe coreutils sed"
RDEPENDS:${PN}-ptest:append_libc-glibc = " locale-base-tr-tr.iso-8859-9"
RDEPENDS:${PN}-tkinter += "${@bb.utils.contains('PACKAGECONFIG', 'tk', 'tk tk-lib', '', d)}"
RDEPENDS:${PN}-idle += "${@bb.utils.contains('PACKAGECONFIG', 'tk', '${PN}-tkinter tcl', '', d)}"
RDEPENDS:${PN}-dev = ""

RDEPENDS:${PN}-tests:append_class-target = " ${MLPREFIX}bash"
RDEPENDS:${PN}-tests:append_class-nativesdk = " ${MLPREFIX}bash"
