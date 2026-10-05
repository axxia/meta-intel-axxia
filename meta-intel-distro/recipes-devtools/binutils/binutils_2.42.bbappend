FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:" 

SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', \
		 ' file://0001-Fix-32392-Regression-gprofng-fails-to-build-on.patch', '', d)}"

# binutils' configure auto-detects zstd via pkg-config and records a bare
# "-I${STAGING_INCDIR}" in ZSTD_CFLAGS. That variable is pulled into
# AM_CFLAGS_FOR_BUILD, so the native 64-bit CC_FOR_BUILD used for sysinfo.o
# and syslex_wrap.o ends up including the target sysroot's headers. In a
# lib32 sysroot the multilib bits/long-double.h wrapper then selects
# bits/long-double-64.h, which is only shipped by the 64-bit sysroot, and
# do_compile dies with "No such file or directory".
EXTRA_OECONF:append:class-target = " --without-zstd"
