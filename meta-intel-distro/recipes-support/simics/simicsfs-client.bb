SUMMARY = "SimicsFS client that talks to a simulated device"
DESCRIPTION="SimicsFS gives you access to the file system of your real \
computer inside the simulated machine. This greatly simplifies the process \
of importing files into the simulated machine."

require simics.inc

DEPENDS = "fuse libmagicpipe"
RDEPENDS_${PN} = "fuse"

do_install () {
	install -d ${D}${bindir} ${D}/host
	install -m 0755 ${S}/simicsfs-client  ${D}${bindir}
}

FILES_${PN} = "${bindir} /host"
