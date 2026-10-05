SUMMARY = "Simple Python version management"
HOMEPAGE = "https://github.com/pyenv/pyenv"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=c00080c6a955a9c15eb6e8f3b5e88e45"

SRC_URI = "git://github.com/pyenv/pyenv.git;branch=master;protocol=https"
SRCREV = "07171d013cac53d1cc9248b4c160217f288a2965"

PYENV_ROOT ?= "${datadir}/pyenv"

inherit allarch

do_compile() {
	:
}

do_install() {
    install -d ${D}${PYENV_ROOT}
    cp -r ${S}/completions ${D}${PYENV_ROOT}
    cp -r ${S}/libexec ${D}${PYENV_ROOT}
    cp -r ${S}/plugins ${D}${PYENV_ROOT}
    cp -r ${S}/pyenv.d ${D}${PYENV_ROOT}
    rm -rf ${D}${PYENV_ROOT}/plugins/python-build/test
    find ${D} -type f -name ".gitignore" -exec rm -f {} +

    install -d ${D}${sbindir}
    ln -s ${PYENV_ROOT}/libexec/pyenv ${D}${sbindir}/pyenv

    install -d ${D}${sysconfdir}/profile.d
    cat > ${D}${sysconfdir}/profile.d/pyenv.sh <<EOF
export PYENV_ROOT=${PYENV_ROOT}

eval "\$(pyenv init - || true)"

if [ -f "${PYENV_ROOT}/completions/pyenv.bash" ]; then
    . "${PYENV_ROOT}/completions/pyenv.bash"
fi
EOF
}

FILES:${PN} += "${datadir} ${sbindir} ${sysconfdir}"

RDEPENDS:${PN} += " \
    gcc \
    g++ \
    make \
    patch \
    sqlite3 \
    coreutils \
    findutils \
    curl \
"

RRECOMMENDS:${PN} += " \
    zlib \
    libffi \
    openssl \
    readline \
"
