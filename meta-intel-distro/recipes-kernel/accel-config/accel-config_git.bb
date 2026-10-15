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
LIC_FILES_CHKSUM = "file://LICENSE_GPL_2_0;md5=32c20dbc52a150882bfe561e645a2b71"

DEPENDS = "asciidoc-native xmlto-native util-linux json-c kmod udev"

RDEPENDS:${PN} = "bash"

SRCREV = "b78f65f5d342643815124d36a52023fda4a945e3"
PV = "4.1.9"

SRC_URI = "git://github.com/intel/idxd-config.git;protocol=https;branch=stable"

inherit autotools-brokensep pkgconfig gettext

EXTRA_OECONF:append = " --enable-test=yes"

do_configure:prepend() {
	(cd ${S}; ./autogen.sh; cd -)
}
