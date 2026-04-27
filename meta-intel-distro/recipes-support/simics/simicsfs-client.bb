SUMMARY = "SimicsFS client that talks to a simulated device"
DESCRIPTION="SimicsFS gives you access to the file system of your real \
computer inside the simulated machine. This greatly simplifies the process \
of importing files into the simulated machine."

require simics.inc

DEPENDS = "fuse fuse3 libmagicpipe"
RDEPENDS:${PN} = "fuse fuse3"

do_install () {
	install -d ${D}${bindir} ${D}/host
	install -m 0755 ${S}/simicsfs-client  ${D}${bindir}
}

FILES:${PN} = "${bindir} /host"
