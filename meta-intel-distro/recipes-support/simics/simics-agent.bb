SUMMARY = "Simics agent that communicates with the Simics simulator via magic instructions"
DESCRIPTION="The Simics agent is a user-level program that communicates with the Simics \
simulator via magic instructions – this makes it very easy to port to a new system, and \
it can effectively punch through layers of hypervisors and operating systems since it does \
not need to get down to memory-mapped devices in hardware."

require simics.inc

TARGET_CC_ARCH += "${LDFLAGS}"

do_install () {
	install -d ${D}${bindir}
	install -m 0755 ${S}/simics-agent  ${D}${bindir}
}

FILES:${PN} = "${bindir}"
