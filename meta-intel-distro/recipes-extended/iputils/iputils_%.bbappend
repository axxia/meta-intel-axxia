# ping requires CAP_NET_RAW to open raw sockets. Set setuid root so
# non-root users can run ping without needing file capability xattr
# support in the filesystem.
do_install:append() {
    if [ -f ${D}${bindir}/ping ]; then
        chmod u+s ${D}${bindir}/ping
    fi
    if [ -f ${D}${bindir}/ping6 ]; then
        chmod u+s ${D}${bindir}/ping6
    fi
}

# Suppress the QA check that warns about setuid binaries in packages
INSANE_SKIP:${PN} += "setuid"
