SUMMARY = "Utility library for DSA sub-system in the Linux kernel"
DESCRIPTION = "accel-config is a utility library for controlling and \
configuring DSA (Data-Streaming Accelerator) sub-system in the Linux \
kernel. It allows the system administrators to configure groups, \
workqueues and engines. The utility parses the topology and \
capabilities exposed via sysfs and provides a command line interface \
to configure resources."
HOMEPAGE = "https://github.com/intel/idxd-config"
SECTION = "libs"

LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://LICENSE_GPL_2_0;md5=fa69eb765efdca4a83cd19e915db9ab0"

DEPENDS = "asciidoc-native xmlto-native util-linux json-c kmod udev"

RDEPENDS:${PN} = "bash"

SRCREV = "435fa62bca9bd64069f7d816eae44b7bcc63f3bb"
PV = "4.1.1"

SRC_URI = "git://github.com/intel/idxd-config.git;protocol=https;branch=stable"

S = "${WORKDIR}/git"

inherit autotools-brokensep pkgconfig gettext 

EXTRA_OECONF:append = " --enable-test=yes"

do_configure:prepend() {
	(cd ${S}; ./autogen.sh; cd -)
}
