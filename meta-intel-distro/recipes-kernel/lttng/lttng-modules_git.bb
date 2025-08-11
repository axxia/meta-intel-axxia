SECTION = "devel"
SUMMARY = "Linux Trace Toolkit KERNEL MODULE"
DESCRIPTION = "The lttng-modules 2.0 package contains the kernel tracer modules"
HOMEPAGE = "https://lttng.org/"
LICENSE = "LGPL-2.1-only & GPL-2.0-only & MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=018e002dbdda3306682e394ddd65fa32"

inherit module

include lttng-platforms.inc

SRC_URI = "git://git.lttng.org/lttng-modules.git;branch=master;protocol=https \
           "

SRCREV = "f20fd6cf86c524fc31437add81d3973e76850c56"

BASEVER = "2.14.0"
PV = "${BASEVER}+git+${@d.getVar('SRCREV')[:10]}"

S = "${WORKDIR}/git"

export INSTALL_MOD_DIR = "kernel/lttng-modules"

EXTRA_OEMAKE += "KERNELDIR='${STAGING_KERNEL_DIR}'"

MODULES_MODULE_SYMVERS_LOCATION = "src"

do_install:append() {
	# Delete empty directories to avoid QA failures if no modules were built
	if [ -d ${D}/${nonarch_base_libdir} ]; then
		find ${D}/${nonarch_base_libdir} -depth -type d -empty -exec rmdir {} \;
	fi
}

python do_package:prepend() {
    if not os.path.exists(os.path.join(d.getVar('D'), d.getVar('nonarch_base_libdir')[1:], 'modules')):
        bb.warn("%s: no modules were created; this may be due to CONFIG_TRACEPOINTS not being enabled in your kernel." % d.getVar('PN'))
}
