# Ignore warnings reported as errors by gcc-14 and newer
# | ../../elfutils-0.191/backends/i386_regs.c:88:11: error: initializer-string for array of 'char' is too long 
# [-Werror=unterminated-string-initialization]
# |    88 |           "ax", "cx", "dx", "bx", "sp", "bp", "si", "di", "ip"
CFLAGS:append:class-target = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', ' -Wno-error=unterminated-string-initialization', '', d)}"
CFLAGS:append:class-nativesdk = "${@bb.utils.contains('DISTRO_FEATURES_NATIVESDK', 'gcc15', ' -Wno-error=unterminated-string-initialization', '', d)}"

# Replace libdir with base_libdir in libelf.pc to fix linker from a multilib SDK
# when searching for libc libraries (libc.so.6 and libc_nonshared.a)
do_install:append() {
	sed -i "s#libdir=${libdir}#libdir=${base_libdir}#g" ${D}${libdir}/pkgconfig/libelf.pc
}
