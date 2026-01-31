SUMMARY = "Command-line tools for I3C"
DESCRIPTION = "Set of tools to interact with i3c devices from user space"
HOMEPAGE = "https://github.com/axxia/i3c-tools"
LICENSE = "GPL-2.0-or-later"
LIC_FILES_CHKSUM = "file://i3ctransfer.c;beginline=1;endline=10;md5=56222e61b14f28d4cfd77c5f03ba9ddf"

PV = "1.0+git+${BRANCH}+${@d.getVar('SRCREV')[:10]}"

COMPATIBLE_MACHINE = "(intel-axxia-grr|intel-axxia-pmr)"

I3C_TOOLS_REPO ?= "public"
PUBLIC_REPO = "github.com/axxia/i3c-tools.git"
PRIVATE_REPO = "github.com/intel-sandbox/networking.wireless.transport.rdk.board-support.i3c-tools.git"
REPO = "${@oe.utils.conditional('I3C_TOOLS_REPO', 'private', '${PRIVATE_REPO}', '${PUBLIC_REPO}', d)}"

BRANCH:intel-axxia-pmr = "pmr"
SRCREV:intel-axxia-pmr = "cea4e26e34ff89cbda9adff5f037bd87c0a0f37e"

BRANCH:intel-axxia-grr = "grr"
SRCREV:intel-axxia-grr = "8058809771653797615ab7cc9aaa9414a86ccbba"

SRC_URI = "git://${REPO};branch=${BRANCH};protocol=https"

S = "${WORKDIR}/git"

do_compile[depends] += "virtual/kernel:do_shared_workdir"

do_compile() {
    install -D -m0644 ${STAGING_KERNEL_DIR}/include/uapi/linux/i3c/i3cdev.h \
        ${S}/include/linux/i3c/i3cdev.h
    oe_runmake
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 i3c* ${D}${bindir}
    install -m 0755 ibitest ${D}${bindir} 2>/dev/null || :
    rm -rf ${D}${bindir}/*.c
}

python __anonymous() {
    repo = d.getVar("I3C_TOOLS_REPO")
    if repo != "public":
        d.setVar("SRCREV", "${AUTOREV}")
}
