SUMMARY = "Display or change ethernet card settings"
DESCRIPTION = "A small utility for examining and tuning the settings of your ethernet-based network interfaces."
HOMEPAGE = "http://www.kernel.org/pub/software/network/ethtool/"
SECTION = "console/network"
LICENSE = "GPL-2.0-or-later"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263 \
                    file://ethtool.c;beginline=4;endline=17;md5=c19b30548c582577fc6b443626fc1216"

ETHTOOL_GIT_URI ?= "https://git.kernel.org/pub/scm/network/ethtool/ethtool.git"
ETHTOOL_GIT_BRANCH ?= "master"
ETHTOOL_GIT_SRCREV ?= "${AUTOREV}"
ETHTOOL_EXTRA_PATH ?= ""
ETHTOOL_VERSION_EXTENSION ?= ""

ETHTOOL_GIT_URI_CLEANUP = "${@d.getVar('ETHTOOL_GIT_URI').replace('https://','').replace('git://','')}"
ETHTOOL_GIT_PROTOCOL = "${@'file' if d.getVar('ETHTOOL_GIT_URI').startswith('/') else 'https'}"

FILESEXTRAPATHS:prepend := "${ETHTOOL_EXTRA_PATH}:"

SRC_URI = "git://${ETHTOOL_GIT_URI_CLEANUP};protocol=${ETHTOOL_GIT_PROTOCOL};branch=${ETHTOOL_GIT_BRANCH} \
           file://run-ptest \
	   file://avoid_parallel_tests.patch \
           "

SRCREV = "${ETHTOOL_GIT_SRCREV}"

PV = "git${ETHTOOL_VERSION_EXTENSION}${@'+localpatches' if d.getVar('ETHTOOL_EXTRA_PATH') else ''}"

S = "${WORKDIR}/git"

UPSTREAM_CHECK_URI = "https://www.kernel.org/pub/software/network/ethtool/"

inherit autotools ptest bash-completion pkgconfig

PATCHTOOL = "git"

RDEPENDS:${PN}-ptest += "make bash"

PACKAGECONFIG ?= "netlink"
PACKAGECONFIG[netlink] = "--enable-netlink,--disable-netlink,libmnl,"

FILES:${PN} += "${datadir}/metainfo/org.kernel.software.network.ethtool.metainfo.xml"

# Add in SRC_URI patches from external path (ETHTOOL_EXTRA_PATH) if exists
python __anonymous() {
    import os, bb

    dir = d.getVar('ETHTOOL_EXTRA_PATH', True)

    if dir and os.path.isdir(dir):
        patches = sorted([f for f in os.listdir(dir) if f.endswith('.patch')])

        new_files = []

        for patch in patches:
            new_files.append("file://" + patch)

        if new_files:
            src_uri = d.getVar('SRC_URI', True) or ""
            d.setVar('SRC_URI', src_uri + " " + " ".join(new_files))
}

do_compile_ptest() {
   oe_runmake buildtest-TESTS
}

do_install_ptest () {
   cp ${B}/Makefile                 ${D}${PTEST_PATH}
   install ${B}/test-cmdline        ${D}${PTEST_PATH}
   if ${@bb.utils.contains('PACKAGECONFIG', 'netlink', 'false', 'true', d)}; then
       install ${B}/test-features       ${D}${PTEST_PATH}
   fi
   install ${B}/ethtool             ${D}${PTEST_PATH}/ethtool
   sed -i 's/^Makefile/_Makefile/'  ${D}${PTEST_PATH}/Makefile
}
